
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCImage.hpp>
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

cocos2d::CCImage::CCImage() : cocos2d::CCImage(geode::CutoffConstructor, sizeof(cocos2d::CCImage)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCImage::~CCImage();

	using FunctionType = void(*)(cocos2d::CCImage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3eef84, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCImage::~CCImage() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCImage*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x3eefb0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCImage(geode::CutoffConstructor, sizeof(cocos2d::CCImage));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCImage::_initWithRawData(void* p0, int p1, int p2, int p3, int p4, bool p5) -> decltype(_initWithRawData(p0, p1, p2, p3, p4, p5)) {
	using FunctionType = decltype(_initWithRawData(p0, p1, p2, p3, p4, p5))(*)(cocos2d::CCImage*, void*, int, int, int, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ef8cc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5);
}

auto cocos2d::CCImage::initWithImageData(void* p0, int p1, cocos2d::CCImage::EImageFormat p2, int p3, int p4, int p5, int p6) -> decltype(initWithImageData(p0, p1, p2, p3, p4, p5, p6)) {
	using FunctionType = decltype(initWithImageData(p0, p1, p2, p3, p4, p5, p6))(*)(cocos2d::CCImage*, void*, int, cocos2d::CCImage::EImageFormat, int, int, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ef41c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5, p6);
}

auto cocos2d::CCImage::initWithImageFile(char const* p0, cocos2d::CCImage::EImageFormat p1) -> decltype(initWithImageFile(p0, p1)) {
	using FunctionType = decltype(initWithImageFile(p0, p1))(*)(cocos2d::CCImage*, char const*, cocos2d::CCImage::EImageFormat);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ef070, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCImage::initWithImageFileThreadSafe(char const* p0, cocos2d::CCImage::EImageFormat p1) -> decltype(initWithImageFileThreadSafe(p0, p1)) {
	using FunctionType = decltype(initWithImageFileThreadSafe(p0, p1))(*)(cocos2d::CCImage*, char const*, cocos2d::CCImage::EImageFormat);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ef814, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCImage::initWithString(char const* p0, int p1, int p2, cocos2d::CCImage::ETextAlign p3, char const* p4, int p5) -> decltype(initWithString(p0, p1, p2, p3, p4, p5)) {
	using FunctionType = decltype(initWithString(p0, p1, p2, p3, p4, p5))(*)(cocos2d::CCImage*, char const*, int, int, cocos2d::CCImage::ETextAlign, char const*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ef948, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5);
}
