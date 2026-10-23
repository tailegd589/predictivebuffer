
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCConfiguration.hpp>
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

cocos2d::CCConfiguration::CCConfiguration() : cocos2d::CCConfiguration(geode::CutoffConstructor, sizeof(cocos2d::CCConfiguration)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCConfiguration::~CCConfiguration();

	using FunctionType = void(*)(cocos2d::CCConfiguration*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46f6cc, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCConfiguration::~CCConfiguration() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCConfiguration*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x46f9dc, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCConfiguration(geode::CutoffConstructor, sizeof(cocos2d::CCConfiguration));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCConfiguration::purgeConfiguration() -> decltype(purgeConfiguration()) {
	using FunctionType = decltype(purgeConfiguration())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x470478, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCConfiguration::sharedConfiguration() -> decltype(sharedConfiguration()) {
	using FunctionType = decltype(sharedConfiguration())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4703f8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCConfiguration::checkForGLExtension(gd::string const& p0) const  -> decltype(checkForGLExtension(p0)) {
	using FunctionType = decltype(checkForGLExtension(p0))(*)(cocos2d::CCConfiguration const *, gd::string const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4703c4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCConfiguration::dumpInfo() const  -> decltype(dumpInfo()) {
	using FunctionType = decltype(dumpInfo())(*)(cocos2d::CCConfiguration const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46fa88, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCConfiguration::gatherGPUInfo() -> decltype(gatherGPUInfo()) {
	using FunctionType = decltype(gatherGPUInfo())(*)(cocos2d::CCConfiguration*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46fb28, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCConfiguration::getBool(char const* p0, bool p1) const  -> decltype(getBool(p0, p1)) {
	using FunctionType = decltype(getBool(p0, p1))(*)(cocos2d::CCConfiguration const *, char const*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x470600, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCConfiguration::getCString(char const* p0, char const* p1) const  -> decltype(getCString(p0, p1)) {
	using FunctionType = decltype(getCString(p0, p1))(*)(cocos2d::CCConfiguration const *, char const*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4704e4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCConfiguration::getMaxModelviewStackDepth() const  -> decltype(getMaxModelviewStackDepth()) {
	using FunctionType = decltype(getMaxModelviewStackDepth())(*)(cocos2d::CCConfiguration const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4704ac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCConfiguration::getMaxTextureSize() const  -> decltype(getMaxTextureSize()) {
	using FunctionType = decltype(getMaxTextureSize())(*)(cocos2d::CCConfiguration const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4704a4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCConfiguration::getMaxTextureUnits() const  -> decltype(getMaxTextureUnits()) {
	using FunctionType = decltype(getMaxTextureUnits())(*)(cocos2d::CCConfiguration const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4704b4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCConfiguration::getNumber(char const* p0, double p1) const  -> decltype(getNumber(p0, p1)) {
	using FunctionType = decltype(getNumber(p0, p1))(*)(cocos2d::CCConfiguration const *, char const*, double);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x470740, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCConfiguration::getObject(char const* p0) const  -> decltype(getObject(p0)) {
	using FunctionType = decltype(getObject(p0))(*)(cocos2d::CCConfiguration const *, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4708b8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCConfiguration::init() -> decltype(init()) {
	using FunctionType = decltype(init())(*)(cocos2d::CCConfiguration*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46f72c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCConfiguration::loadConfigFile(char const* p0) -> decltype(loadConfigFile(p0)) {
	using FunctionType = decltype(loadConfigFile(p0))(*)(cocos2d::CCConfiguration*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x470abc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCConfiguration::setObject(char const* p0, cocos2d::CCObject* p1) -> decltype(setObject(p0, p1)) {
	using FunctionType = decltype(setObject(p0, p1))(*)(cocos2d::CCConfiguration*, char const*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4709bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCConfiguration::supportsBGRA8888() const  -> decltype(supportsBGRA8888()) {
	using FunctionType = decltype(supportsBGRA8888())(*)(cocos2d::CCConfiguration const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4704cc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCConfiguration::supportsDiscardFramebuffer() const  -> decltype(supportsDiscardFramebuffer()) {
	using FunctionType = decltype(supportsDiscardFramebuffer())(*)(cocos2d::CCConfiguration const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4704d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCConfiguration::supportsNPOT() const  -> decltype(supportsNPOT()) {
	using FunctionType = decltype(supportsNPOT())(*)(cocos2d::CCConfiguration const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4704bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCConfiguration::supportsPVRTC() const  -> decltype(supportsPVRTC()) {
	using FunctionType = decltype(supportsPVRTC())(*)(cocos2d::CCConfiguration const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4704c4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCConfiguration::supportsShareableVAO() const  -> decltype(supportsShareableVAO()) {
	using FunctionType = decltype(supportsShareableVAO())(*)(cocos2d::CCConfiguration const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4704dc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
