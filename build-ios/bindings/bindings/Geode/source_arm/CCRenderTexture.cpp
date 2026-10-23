
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCRenderTexture.hpp>
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

cocos2d::CCRenderTexture::CCRenderTexture() : cocos2d::CCRenderTexture(geode::CutoffConstructor, sizeof(cocos2d::CCRenderTexture)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCRenderTexture::~CCRenderTexture();

	using FunctionType = void(*)(cocos2d::CCRenderTexture*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51e368, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCRenderTexture::~CCRenderTexture() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCRenderTexture*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x51e400, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCRenderTexture(geode::CutoffConstructor, sizeof(cocos2d::CCRenderTexture));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCRenderTexture::create(int p0, int p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51ea64, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCRenderTexture::create(int p0, int p1, cocos2d::CCTexture2DPixelFormat p2) -> decltype(create(p0, p1, p2)) {
	using FunctionType = decltype(create(p0, p1, p2))(*)(int, int, cocos2d::CCTexture2DPixelFormat);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51e548, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::CCRenderTexture::create(int p0, int p1, cocos2d::CCTexture2DPixelFormat p2, unsigned int p3) -> decltype(create(p0, p1, p2, p3)) {
	using FunctionType = decltype(create(p0, p1, p2, p3))(*)(int, int, cocos2d::CCTexture2DPixelFormat, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51e628, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

auto cocos2d::CCRenderTexture::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCRenderTexture::draw), this);
	using FunctionType = decltype(draw())(*)(cocos2d::CCRenderTexture*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51f2ac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCRenderTexture::visit() -> decltype(visit()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCRenderTexture::visit), this);
	using FunctionType = decltype(visit())(*)(cocos2d::CCRenderTexture*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51f214, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCRenderTexture::getSprite() -> decltype(getSprite()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCRenderTexture::getSprite), this);
	using FunctionType = decltype(getSprite())(*)(cocos2d::CCRenderTexture*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51e4a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCRenderTexture::setSprite(cocos2d::CCSprite* p0) -> decltype(setSprite(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCSprite*>::func(&cocos2d::CCRenderTexture::setSprite), this);
	using FunctionType = decltype(setSprite(p0))(*)(cocos2d::CCRenderTexture*, cocos2d::CCSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51e4a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCRenderTexture::begin() -> decltype(begin()) {
	using FunctionType = decltype(begin())(*)(cocos2d::CCRenderTexture*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51eb5c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCRenderTexture::beginWithClear(float p0, float p1, float p2, float p3) -> decltype(beginWithClear(p0, p1, p2, p3)) {
	using FunctionType = decltype(beginWithClear(p0, p1, p2, p3))(*)(cocos2d::CCRenderTexture*, float, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51ed50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto cocos2d::CCRenderTexture::beginWithClear(float p0, float p1, float p2, float p3, float p4) -> decltype(beginWithClear(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(beginWithClear(p0, p1, p2, p3, p4))(*)(cocos2d::CCRenderTexture*, float, float, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51ef38, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4);
}

auto cocos2d::CCRenderTexture::beginWithClear(float p0, float p1, float p2, float p3, float p4, int p5) -> decltype(beginWithClear(p0, p1, p2, p3, p4, p5)) {
	using FunctionType = decltype(beginWithClear(p0, p1, p2, p3, p4, p5))(*)(cocos2d::CCRenderTexture*, float, float, float, float, float, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51f008, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5);
}

auto cocos2d::CCRenderTexture::beginWithClear(float p0, float p1, float p2, float p3, float p4, int p5, unsigned int p6) -> decltype(beginWithClear(p0, p1, p2, p3, p4, p5, p6)) {
	using FunctionType = decltype(beginWithClear(p0, p1, p2, p3, p4, p5, p6))(*)(cocos2d::CCRenderTexture*, float, float, float, float, float, int, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51edf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5, p6);
}

auto cocos2d::CCRenderTexture::clear(float p0, float p1, float p2, float p3) -> decltype(clear(p0, p1, p2, p3)) {
	using FunctionType = decltype(clear(p0, p1, p2, p3))(*)(cocos2d::CCRenderTexture*, float, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51f05c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto cocos2d::CCRenderTexture::clearDepth(float p0) -> decltype(clearDepth(p0)) {
	using FunctionType = decltype(clearDepth(p0))(*)(cocos2d::CCRenderTexture*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51f13c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCRenderTexture::clearStencil(int p0) -> decltype(clearStencil(p0)) {
	using FunctionType = decltype(clearStencil(p0))(*)(cocos2d::CCRenderTexture*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51f1cc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCRenderTexture::end() -> decltype(end()) {
	using FunctionType = decltype(end())(*)(cocos2d::CCRenderTexture*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51f010, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCRenderTexture::getClearColor() const  -> decltype(getClearColor()) {
	using FunctionType = decltype(getClearColor())(*)(cocos2d::CCRenderTexture const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51e4fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCRenderTexture::getClearDepth() const  -> decltype(getClearDepth()) {
	using FunctionType = decltype(getClearDepth())(*)(cocos2d::CCRenderTexture const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51e514, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCRenderTexture::getClearFlags() const  -> decltype(getClearFlags()) {
	using FunctionType = decltype(getClearFlags())(*)(cocos2d::CCRenderTexture const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51e4ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCRenderTexture::getClearStencil() const  -> decltype(getClearStencil()) {
	using FunctionType = decltype(getClearStencil())(*)(cocos2d::CCRenderTexture const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51e524, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCRenderTexture::initWithWidthAndHeight(int p0, int p1, cocos2d::CCTexture2DPixelFormat p2) -> decltype(initWithWidthAndHeight(p0, p1, p2)) {
	using FunctionType = decltype(initWithWidthAndHeight(p0, p1, p2))(*)(cocos2d::CCRenderTexture*, int, int, cocos2d::CCTexture2DPixelFormat);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51e620, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCRenderTexture::initWithWidthAndHeight(int p0, int p1, cocos2d::CCTexture2DPixelFormat p2, unsigned int p3) -> decltype(initWithWidthAndHeight(p0, p1, p2, p3)) {
	using FunctionType = decltype(initWithWidthAndHeight(p0, p1, p2, p3))(*)(cocos2d::CCRenderTexture*, int, int, cocos2d::CCTexture2DPixelFormat, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51e710, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto cocos2d::CCRenderTexture::isAutoDraw() const  -> decltype(isAutoDraw()) {
	using FunctionType = decltype(isAutoDraw())(*)(cocos2d::CCRenderTexture const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51e538, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCRenderTexture::listenToBackground(cocos2d::CCObject* p0) -> decltype(listenToBackground(p0)) {
	using FunctionType = decltype(listenToBackground(p0))(*)(cocos2d::CCRenderTexture*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51e498, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCRenderTexture::listenToForeground(cocos2d::CCObject* p0) -> decltype(listenToForeground(p0)) {
	using FunctionType = decltype(listenToForeground(p0))(*)(cocos2d::CCRenderTexture*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51e49c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCRenderTexture::newCCImage(bool flipImage) -> decltype(newCCImage(flipImage)) {
	using FunctionType = decltype(newCCImage(flipImage))(*)(cocos2d::CCRenderTexture*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51f4cc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, flipImage);
}

auto cocos2d::CCRenderTexture::setAutoDraw(bool p0) -> decltype(setAutoDraw(p0)) {
	using FunctionType = decltype(setAutoDraw(p0))(*)(cocos2d::CCRenderTexture*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51e540, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCRenderTexture::setClearColor(cocos2d::ccColor4F const& p0) -> decltype(setClearColor(p0)) {
	using FunctionType = decltype(setClearColor(p0))(*)(cocos2d::CCRenderTexture*, cocos2d::ccColor4F const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51e504, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCRenderTexture::setClearDepth(float p0) -> decltype(setClearDepth(p0)) {
	using FunctionType = decltype(setClearDepth(p0))(*)(cocos2d::CCRenderTexture*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51e51c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCRenderTexture::setClearFlags(unsigned int p0) -> decltype(setClearFlags(p0)) {
	using FunctionType = decltype(setClearFlags(p0))(*)(cocos2d::CCRenderTexture*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51e4f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCRenderTexture::setClearStencil(float p0) -> decltype(setClearStencil(p0)) {
	using FunctionType = decltype(setClearStencil(p0))(*)(cocos2d::CCRenderTexture*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51e52c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCRenderTexture::updateInternalScale(float p0, float p1) -> decltype(updateInternalScale(p0, p1)) {
	using FunctionType = decltype(updateInternalScale(p0, p1))(*)(cocos2d::CCRenderTexture*, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51eb38, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}
