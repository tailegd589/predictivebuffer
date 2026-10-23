
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCApplication.hpp>
#include <Geode/cocos/platform/mac/CCFileUtilsMac.h>

using namespace geode;
using namespace geode::modifier;

#if !defined(GEODE_WRAP_FUNCTION)
#define GEODE_WRAP_FUNCTION
template <class F>
static auto wrapFunction(uintptr_t address, tulip::hook::TulipConvention convention) {
	auto wrapped = geode::hook::createWrapper(reinterpret_cast<void*>(address), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(convention),
		.m_abstract = tulip::hook::AbstractFunction::from(F(nullptr)),
	});
	if (wrapped.isErr()) {
		throw std::runtime_error(wrapped.unwrapErr());
	}
	return wrapped.unwrap();
}
#endif

cocos2d::CCApplication::CCApplication() : cocos2d::CCApplication(geode::CutoffConstructor, sizeof(cocos2d::CCApplication)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCApplication::~CCApplication();

	using FunctionType = void(*)(cocos2d::CCApplication*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2b65e8, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCApplication::~CCApplication() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCApplication*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x2b6610, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCApplication(geode::CutoffConstructor, sizeof(cocos2d::CCApplication));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCApplication::sharedApplication() -> decltype(sharedApplication()) {
	using FunctionType = decltype(sharedApplication())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2b66ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCApplication::run() -> decltype(run()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCApplication::run), this);
	using FunctionType = decltype(run())(*)(cocos2d::CCApplication*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2b6684, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCApplication::setAnimationInterval(double p0) -> decltype(setAnimationInterval(p0)) {
	auto self = addresser::thunkAdjust(Resolve<double>::func(&cocos2d::CCApplication::setAnimationInterval), this);
	using FunctionType = decltype(setAnimationInterval(p0))(*)(cocos2d::CCApplication*, double);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2b66b8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCApplication::getCurrentLanguage() -> decltype(getCurrentLanguage()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCApplication::getCurrentLanguage), this);
	using FunctionType = decltype(getCurrentLanguage())(*)(cocos2d::CCApplication*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2b66f8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCApplication::getTargetPlatform() -> decltype(getTargetPlatform()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCApplication::getTargetPlatform), this);
	using FunctionType = decltype(getTargetPlatform())(*)(cocos2d::CCApplication*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2b66e4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCApplication::openURL(char const* p0) -> decltype(openURL(p0)) {
	auto self = addresser::thunkAdjust(Resolve<char const*>::func(&cocos2d::CCApplication::openURL), this);
	using FunctionType = decltype(openURL(p0))(*)(cocos2d::CCApplication*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2b6fb4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCApplication::getResourceRootPath() -> decltype(getResourceRootPath()) {
	using FunctionType = decltype(getResourceRootPath())(*)(cocos2d::CCApplication*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2b6ccc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCApplication::getStartupScriptFilename() -> decltype(getStartupScriptFilename()) {
	using FunctionType = decltype(getStartupScriptFilename())(*)(cocos2d::CCApplication*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2b6fac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCApplication::setResourceRootPath(gd::string const& p0) -> decltype(setResourceRootPath(p0)) {
	using FunctionType = decltype(setResourceRootPath(p0))(*)(cocos2d::CCApplication*, gd::string const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2b691c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCApplication::setStartupScriptFilename(gd::string const& p0) -> decltype(setStartupScriptFilename(p0)) {
	using FunctionType = decltype(setStartupScriptFilename(p0))(*)(cocos2d::CCApplication*, gd::string const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2b6cd4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
