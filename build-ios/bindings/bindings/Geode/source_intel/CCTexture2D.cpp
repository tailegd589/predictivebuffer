
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCTexture2D.hpp>
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

cocos2d::CCTexture2D::CCTexture2D() : cocos2d::CCTexture2D(geode::CutoffConstructor, sizeof(cocos2d::CCTexture2D)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCTexture2D::~CCTexture2D();

	using FunctionType = void(*)(cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x477f60, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCTexture2D::~CCTexture2D() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCTexture2D*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x478020, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCTexture2D(geode::CutoffConstructor, sizeof(cocos2d::CCTexture2D));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCTexture2D::defaultAlphaPixelFormat() -> decltype(defaultAlphaPixelFormat()) {
	using FunctionType = decltype(defaultAlphaPixelFormat())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x479660, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCTexture2D::PVRImagesHavePremultipliedAlpha(bool p0) -> decltype(PVRImagesHavePremultipliedAlpha(p0)) {
	using FunctionType = decltype(PVRImagesHavePremultipliedAlpha(p0))(*)(bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x479490, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCTexture2D::setDefaultAlphaPixelFormat(cocos2d::CCTexture2DPixelFormat p0) -> decltype(setDefaultAlphaPixelFormat(p0)) {
	using FunctionType = decltype(setDefaultAlphaPixelFormat(p0))(*)(cocos2d::CCTexture2DPixelFormat);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x479650, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCTexture2D::getPixelFormat() -> decltype(getPixelFormat()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTexture2D::getPixelFormat), this);
	using FunctionType = decltype(getPixelFormat())(*)(cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x478110, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTexture2D::getPixelsWide() -> decltype(getPixelsWide()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTexture2D::getPixelsWide), this);
	using FunctionType = decltype(getPixelsWide())(*)(cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x478120, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTexture2D::getPixelsHigh() -> decltype(getPixelsHigh()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTexture2D::getPixelsHigh), this);
	using FunctionType = decltype(getPixelsHigh())(*)(cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x478130, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTexture2D::getName() -> decltype(getName()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTexture2D::getName), this);
	using FunctionType = decltype(getName())(*)(cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x478140, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTexture2D::getMaxS() -> decltype(getMaxS()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTexture2D::getMaxS), this);
	using FunctionType = decltype(getMaxS())(*)(cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4781d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTexture2D::setMaxS(float p0) -> decltype(setMaxS(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCTexture2D::setMaxS), this);
	using FunctionType = decltype(setMaxS(p0))(*)(cocos2d::CCTexture2D*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4781e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCTexture2D::getMaxT() -> decltype(getMaxT()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTexture2D::getMaxT), this);
	using FunctionType = decltype(getMaxT())(*)(cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4781f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTexture2D::setMaxT(float p0) -> decltype(setMaxT(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCTexture2D::setMaxT), this);
	using FunctionType = decltype(setMaxT(p0))(*)(cocos2d::CCTexture2D*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x478200, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCTexture2D::getContentSize() -> decltype(getContentSize()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTexture2D::getContentSize), this);
	using FunctionType = decltype(getContentSize())(*)(cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x478150, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTexture2D::getShaderProgram() -> decltype(getShaderProgram()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTexture2D::getShaderProgram), this);
	using FunctionType = decltype(getShaderProgram())(*)(cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x478210, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTexture2D::setShaderProgram(cocos2d::CCGLProgram* p0) -> decltype(setShaderProgram(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCGLProgram*>::func(&cocos2d::CCTexture2D::setShaderProgram), this);
	using FunctionType = decltype(setShaderProgram(p0))(*)(cocos2d::CCTexture2D*, cocos2d::CCGLProgram*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x478220, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCTexture2D::bitsPerPixelForFormat() -> decltype(bitsPerPixelForFormat()) {
	using FunctionType = decltype(bitsPerPixelForFormat())(*)(cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x479670, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTexture2D::bitsPerPixelForFormat(cocos2d::CCTexture2DPixelFormat p0) -> decltype(bitsPerPixelForFormat(p0)) {
	using FunctionType = decltype(bitsPerPixelForFormat(p0))(*)(cocos2d::CCTexture2D*, cocos2d::CCTexture2DPixelFormat);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4785c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTexture2D::description() -> decltype(description()) {
	using FunctionType = decltype(description())(*)(cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4785e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTexture2D::drawAtPoint(cocos2d::CCPoint const& p0) -> decltype(drawAtPoint(p0)) {
	using FunctionType = decltype(drawAtPoint(p0))(*)(cocos2d::CCTexture2D*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4790e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTexture2D::drawInRect(cocos2d::CCRect const& p0) -> decltype(drawInRect(p0)) {
	using FunctionType = decltype(drawInRect(p0))(*)(cocos2d::CCTexture2D*, cocos2d::CCRect const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4791f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTexture2D::generateMipmap() -> decltype(generateMipmap()) {
	using FunctionType = decltype(generateMipmap())(*)(cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4794a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTexture2D::getContentSizeInPixels() -> decltype(getContentSizeInPixels()) {
	using FunctionType = decltype(getContentSizeInPixels())(*)(cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4781c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTexture2D::hasMipmaps() -> decltype(hasMipmaps()) {
	using FunctionType = decltype(hasMipmaps())(*)(cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4794e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTexture2D::hasPremultipliedAlpha() -> decltype(hasPremultipliedAlpha()) {
	using FunctionType = decltype(hasPremultipliedAlpha())(*)(cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4782b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTexture2D::initPremultipliedATextureWithImage(cocos2d::CCImage* p0, unsigned int p1, unsigned int p2) -> decltype(initPremultipliedATextureWithImage(p0, p1, p2)) {
	using FunctionType = decltype(initPremultipliedATextureWithImage(p0, p1, p2))(*)(cocos2d::CCTexture2D*, cocos2d::CCImage*, unsigned int, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x478680, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCTexture2D::initWithData(void const* p0, cocos2d::CCTexture2DPixelFormat p1, unsigned int p2, unsigned int p3, cocos2d::CCSize const& p4) -> decltype(initWithData(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(initWithData(p0, p1, p2, p3, p4))(*)(cocos2d::CCTexture2D*, void const*, cocos2d::CCTexture2DPixelFormat, unsigned int, unsigned int, cocos2d::CCSize const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4782c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4);
}

auto cocos2d::CCTexture2D::initWithETCFile(char const* p0) -> decltype(initWithETCFile(p0)) {
	using FunctionType = decltype(initWithETCFile(p0))(*)(cocos2d::CCTexture2D*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4793c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTexture2D::initWithImage(cocos2d::CCImage* p0) -> decltype(initWithImage(p0)) {
	using FunctionType = decltype(initWithImage(p0))(*)(cocos2d::CCTexture2D*, cocos2d::CCImage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x478620, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTexture2D::initWithPVRFile(char const* p0) -> decltype(initWithPVRFile(p0)) {
	using FunctionType = decltype(initWithPVRFile(p0))(*)(cocos2d::CCTexture2D*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4792e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTexture2D::initWithString(char const* p0, cocos2d::ccFontDefinition* p1) -> decltype(initWithString(p0, p1)) {
	using FunctionType = decltype(initWithString(p0, p1))(*)(cocos2d::CCTexture2D*, char const*, cocos2d::ccFontDefinition*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4790d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCTexture2D::initWithString(char const* p0, char const* p1, float p2) -> decltype(initWithString(p0, p1, p2)) {
	using FunctionType = decltype(initWithString(p0, p1, p2))(*)(cocos2d::CCTexture2D*, char const*, char const*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x478f30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCTexture2D::initWithString(char const* p0, char const* p1, float p2, cocos2d::CCSize const& p3, cocos2d::CCTextAlignment p4, cocos2d::CCVerticalTextAlignment p5) -> decltype(initWithString(p0, p1, p2, p3, p4, p5)) {
	using FunctionType = decltype(initWithString(p0, p1, p2, p3, p4, p5))(*)(cocos2d::CCTexture2D*, char const*, char const*, float, cocos2d::CCSize const&, cocos2d::CCTextAlignment, cocos2d::CCVerticalTextAlignment);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x478f90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5);
}

auto cocos2d::CCTexture2D::keepData(void* p0, unsigned int p1) -> decltype(keepData(p0, p1)) {
	using FunctionType = decltype(keepData(p0, p1))(*)(cocos2d::CCTexture2D*, void*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4782a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCTexture2D::releaseData(void* p0) -> decltype(releaseData(p0)) {
	using FunctionType = decltype(releaseData(p0))(*)(cocos2d::CCTexture2D*, void*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x478290, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTexture2D::releaseGLTexture() -> decltype(releaseGLTexture()) {
	using FunctionType = decltype(releaseGLTexture())(*)(cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x478260, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTexture2D::setAliasTexParameters() -> decltype(setAliasTexParameters()) {
	using FunctionType = decltype(setAliasTexParameters())(*)(cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x479580, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTexture2D::setAntiAliasTexParameters() -> decltype(setAntiAliasTexParameters()) {
	using FunctionType = decltype(setAntiAliasTexParameters())(*)(cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4795d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTexture2D::setTexParameters(cocos2d::ccTexParams* p0) -> decltype(setTexParameters(p0)) {
	using FunctionType = decltype(setTexParameters(p0))(*)(cocos2d::CCTexture2D*, cocos2d::ccTexParams*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4794f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTexture2D::stringForFormat() -> decltype(stringForFormat()) {
	using FunctionType = decltype(stringForFormat())(*)(cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x479620, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
