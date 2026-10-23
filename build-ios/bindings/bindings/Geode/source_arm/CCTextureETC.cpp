
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCTextureETC.hpp>
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

cocos2d::CCTextureETC::CCTextureETC() : cocos2d::CCTextureETC(geode::CutoffConstructor, sizeof(cocos2d::CCTextureETC)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCTextureETC::~CCTextureETC();

	using FunctionType = void(*)(cocos2d::CCTextureETC*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b5cdc, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCTextureETC::~CCTextureETC() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCTextureETC*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x1b5d04, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCTextureETC(geode::CutoffConstructor, sizeof(cocos2d::CCTextureETC));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCTextureETC::getHeight() const  -> decltype(getHeight()) {
	using FunctionType = decltype(getHeight())(*)(cocos2d::CCTextureETC const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b5d38, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTextureETC::getName() const  -> decltype(getName()) {
	using FunctionType = decltype(getName())(*)(cocos2d::CCTextureETC const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b5d28, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTextureETC::getWidth() const  -> decltype(getWidth()) {
	using FunctionType = decltype(getWidth())(*)(cocos2d::CCTextureETC const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b5d30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTextureETC::initWithFile(char const* p0) -> decltype(initWithFile(p0)) {
	using FunctionType = decltype(initWithFile(p0))(*)(cocos2d::CCTextureETC*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b5d20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTextureETC::loadTexture(char const* p0) -> decltype(loadTexture(p0)) {
	using FunctionType = decltype(loadTexture(p0))(*)(cocos2d::CCTextureETC*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b5d40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
