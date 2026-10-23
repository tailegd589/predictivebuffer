
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCTexturePVR.hpp>
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

cocos2d::CCTexturePVR::CCTexturePVR() : cocos2d::CCTexturePVR(geode::CutoffConstructor, sizeof(cocos2d::CCTexturePVR)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCTexturePVR::~CCTexturePVR();

	using FunctionType = void(*)(cocos2d::CCTexturePVR*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x226608, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCTexturePVR::~CCTexturePVR() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCTexturePVR*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x226634, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCTexturePVR(geode::CutoffConstructor, sizeof(cocos2d::CCTexturePVR));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCTexturePVR::create(char const* p0) -> decltype(create(p0)) {
	using FunctionType = decltype(create(p0))(*)(char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x227150, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCTexturePVR::createGLTexture() -> decltype(createGLTexture()) {
	using FunctionType = decltype(createGLTexture())(*)(cocos2d::CCTexturePVR*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x226b7c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTexturePVR::initWithContentsOfFile(char const* p0) -> decltype(initWithContentsOfFile(p0)) {
	using FunctionType = decltype(initWithContentsOfFile(p0))(*)(cocos2d::CCTexturePVR*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x226e3c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTexturePVR::unpackPVRv2Data(unsigned char* p0, unsigned int p1) -> decltype(unpackPVRv2Data(p0, p1)) {
	using FunctionType = decltype(unpackPVRv2Data(p0, p1))(*)(cocos2d::CCTexturePVR*, unsigned char*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x226704, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCTexturePVR::unpackPVRv3Data(unsigned char* p0, unsigned int p1) -> decltype(unpackPVRv3Data(p0, p1)) {
	using FunctionType = decltype(unpackPVRv3Data(p0, p1))(*)(cocos2d::CCTexturePVR*, unsigned char*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x226924, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}
