
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCScale9Sprite.hpp>
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

cocos2d::extension::CCScale9Sprite::CCScale9Sprite() : cocos2d::extension::CCScale9Sprite(geode::CutoffConstructor, sizeof(cocos2d::extension::CCScale9Sprite)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::extension::CCScale9Sprite::~CCScale9Sprite();

	using FunctionType = void(*)(cocos2d::extension::CCScale9Sprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f3b80, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::extension::CCScale9Sprite::~CCScale9Sprite() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::extension::CCScale9Sprite*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x3f3c70, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::extension::CCScale9Sprite(geode::CutoffConstructor, sizeof(cocos2d::extension::CCScale9Sprite));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::extension::CCScale9Sprite::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f5bc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::extension::CCScale9Sprite::create(char const* pszname) -> decltype(create(pszname)) {
	using FunctionType = decltype(create(pszname))(*)(char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f5710, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(pszname);
}

auto cocos2d::extension::CCScale9Sprite::create(char const* p0, cocos2d::CCRect p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(char const*, cocos2d::CCRect);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f5540, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::extension::CCScale9Sprite::create(cocos2d::CCRect capInsets, char const* filename) -> decltype(create(capInsets, filename)) {
	using FunctionType = decltype(create(capInsets, filename))(*)(cocos2d::CCRect, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f5630, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(capInsets, filename);
}

auto cocos2d::extension::CCScale9Sprite::create(char const* filename, cocos2d::CCRect rect, cocos2d::CCRect capInsets) -> decltype(create(filename, rect, capInsets)) {
	using FunctionType = decltype(create(filename, rect, capInsets))(*)(char const*, cocos2d::CCRect, cocos2d::CCRect);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f5440, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(filename, rect, capInsets);
}

auto cocos2d::extension::CCScale9Sprite::createWithSpriteFrame(cocos2d::CCSpriteFrame* p0) -> decltype(createWithSpriteFrame(p0)) {
	using FunctionType = decltype(createWithSpriteFrame(p0))(*)(cocos2d::CCSpriteFrame*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f58e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::extension::CCScale9Sprite::createWithSpriteFrame(cocos2d::CCSpriteFrame* p0, cocos2d::CCRect p1) -> decltype(createWithSpriteFrame(p0, p1)) {
	using FunctionType = decltype(createWithSpriteFrame(p0, p1))(*)(cocos2d::CCSpriteFrame*, cocos2d::CCRect);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f5800, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::extension::CCScale9Sprite::createWithSpriteFrameName(char const* spriteFrameName) -> decltype(createWithSpriteFrameName(spriteFrameName)) {
	using FunctionType = decltype(createWithSpriteFrameName(spriteFrameName))(*)(char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f5aa0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(spriteFrameName);
}

auto cocos2d::extension::CCScale9Sprite::createWithSpriteFrameName(char const* spriteFrameName, cocos2d::CCRect capInsets) -> decltype(createWithSpriteFrameName(spriteFrameName, capInsets)) {
	using FunctionType = decltype(createWithSpriteFrameName(spriteFrameName, capInsets))(*)(char const*, cocos2d::CCRect);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f59c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(spriteFrameName, capInsets);
}

auto cocos2d::extension::CCScale9Sprite::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCScale9Sprite::init), this);
	using FunctionType = decltype(init())(*)(cocos2d::extension::CCScale9Sprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f3d90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCScale9Sprite::setContentSize(const cocos2d::CCSize& size) -> decltype(setContentSize(size)) {
	auto self = addresser::thunkAdjust(Resolve<const cocos2d::CCSize&>::func(&cocos2d::extension::CCScale9Sprite::setContentSize), this);
	using FunctionType = decltype(setContentSize(size))(*)(cocos2d::extension::CCScale9Sprite*, const cocos2d::CCSize&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f4ec0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, size);
}

auto cocos2d::extension::CCScale9Sprite::visit() -> decltype(visit()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCScale9Sprite::visit), this);
	using FunctionType = decltype(visit())(*)(cocos2d::extension::CCScale9Sprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f6200, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCScale9Sprite::getOpacity() -> decltype(getOpacity()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCScale9Sprite::getOpacity), this);
	using FunctionType = decltype(getOpacity())(*)(cocos2d::extension::CCScale9Sprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f6550, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCScale9Sprite::setOpacity(unsigned char p0) -> decltype(setOpacity(p0)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned char>::func(&cocos2d::extension::CCScale9Sprite::setOpacity), this);
	using FunctionType = decltype(setOpacity(p0))(*)(cocos2d::extension::CCScale9Sprite*, unsigned char);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f63d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCScale9Sprite::updateDisplayedOpacity(unsigned char p0) -> decltype(updateDisplayedOpacity(p0)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned char>::func(&cocos2d::extension::CCScale9Sprite::updateDisplayedOpacity), this);
	using FunctionType = decltype(updateDisplayedOpacity(p0))(*)(cocos2d::extension::CCScale9Sprite*, unsigned char);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f5fd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCScale9Sprite::getColor() -> decltype(getColor()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCScale9Sprite::getColor), this);
	using FunctionType = decltype(getColor())(*)(cocos2d::extension::CCScale9Sprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f63b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCScale9Sprite::setColor(const cocos2d::ccColor3B& color) -> decltype(setColor(color)) {
	auto self = addresser::thunkAdjust(Resolve<const cocos2d::ccColor3B&>::func(&cocos2d::extension::CCScale9Sprite::setColor), this);
	using FunctionType = decltype(setColor(color))(*)(cocos2d::extension::CCScale9Sprite*, const cocos2d::ccColor3B&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f6230, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, color);
}

auto cocos2d::extension::CCScale9Sprite::updateDisplayedColor(const cocos2d::ccColor3B& parentColor) -> decltype(updateDisplayedColor(parentColor)) {
	auto self = addresser::thunkAdjust(Resolve<const cocos2d::ccColor3B&>::func(&cocos2d::extension::CCScale9Sprite::updateDisplayedColor), this);
	using FunctionType = decltype(updateDisplayedColor(parentColor))(*)(cocos2d::extension::CCScale9Sprite*, const cocos2d::ccColor3B&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f6040, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, parentColor);
}

auto cocos2d::extension::CCScale9Sprite::setOpacityModifyRGB(bool bValue) -> decltype(setOpacityModifyRGB(bValue)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::extension::CCScale9Sprite::setOpacityModifyRGB), this);
	using FunctionType = decltype(setOpacityModifyRGB(bValue))(*)(cocos2d::extension::CCScale9Sprite*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f5e50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, bValue);
}

auto cocos2d::extension::CCScale9Sprite::isOpacityModifyRGB() -> decltype(isOpacityModifyRGB()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCScale9Sprite::isOpacityModifyRGB), this);
	using FunctionType = decltype(isOpacityModifyRGB())(*)(cocos2d::extension::CCScale9Sprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f5fb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCScale9Sprite::getPreferredSize() -> decltype(getPreferredSize()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCScale9Sprite::getPreferredSize), this);
	using FunctionType = decltype(getPreferredSize())(*)(cocos2d::extension::CCScale9Sprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f5c50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCScale9Sprite::setPreferredSize(cocos2d::CCSize p0) -> decltype(setPreferredSize(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCSize>::func(&cocos2d::extension::CCScale9Sprite::setPreferredSize), this);
	using FunctionType = decltype(setPreferredSize(p0))(*)(cocos2d::extension::CCScale9Sprite*, cocos2d::CCSize);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f5c20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCScale9Sprite::getCapInsets() -> decltype(getCapInsets()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCScale9Sprite::getCapInsets), this);
	using FunctionType = decltype(getCapInsets())(*)(cocos2d::extension::CCScale9Sprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f5d10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCScale9Sprite::setCapInsets(cocos2d::CCRect p0) -> decltype(setCapInsets(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCRect>::func(&cocos2d::extension::CCScale9Sprite::setCapInsets), this);
	using FunctionType = decltype(setCapInsets(p0))(*)(cocos2d::extension::CCScale9Sprite*, cocos2d::CCRect);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f5c70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCScale9Sprite::getInsetLeft() -> decltype(getInsetLeft()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCScale9Sprite::getInsetLeft), this);
	using FunctionType = decltype(getInsetLeft())(*)(cocos2d::extension::CCScale9Sprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f6140, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCScale9Sprite::setInsetLeft(float p0) -> decltype(setInsetLeft(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::extension::CCScale9Sprite::setInsetLeft), this);
	using FunctionType = decltype(setInsetLeft(p0))(*)(cocos2d::extension::CCScale9Sprite*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f6180, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCScale9Sprite::getInsetTop() -> decltype(getInsetTop()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCScale9Sprite::getInsetTop), this);
	using FunctionType = decltype(getInsetTop())(*)(cocos2d::extension::CCScale9Sprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f6150, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCScale9Sprite::setInsetTop(float p0) -> decltype(setInsetTop(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::extension::CCScale9Sprite::setInsetTop), this);
	using FunctionType = decltype(setInsetTop(p0))(*)(cocos2d::extension::CCScale9Sprite*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f61a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCScale9Sprite::getInsetRight() -> decltype(getInsetRight()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCScale9Sprite::getInsetRight), this);
	using FunctionType = decltype(getInsetRight())(*)(cocos2d::extension::CCScale9Sprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f6160, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCScale9Sprite::setInsetRight(float p0) -> decltype(setInsetRight(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::extension::CCScale9Sprite::setInsetRight), this);
	using FunctionType = decltype(setInsetRight(p0))(*)(cocos2d::extension::CCScale9Sprite*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f61c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCScale9Sprite::getInsetBottom() -> decltype(getInsetBottom()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCScale9Sprite::getInsetBottom), this);
	using FunctionType = decltype(getInsetBottom())(*)(cocos2d::extension::CCScale9Sprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f6170, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCScale9Sprite::setInsetBottom(float p0) -> decltype(setInsetBottom(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::extension::CCScale9Sprite::setInsetBottom), this);
	using FunctionType = decltype(setInsetBottom(p0))(*)(cocos2d::extension::CCScale9Sprite*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f61e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCScale9Sprite::initWithBatchNode(cocos2d::CCSpriteBatchNode* p0, cocos2d::CCRect p1, bool p2, cocos2d::CCRect p3) -> decltype(initWithBatchNode(p0, p1, p2, p3)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCSpriteBatchNode*, cocos2d::CCRect, bool, cocos2d::CCRect>::func(&cocos2d::extension::CCScale9Sprite::initWithBatchNode), this);
	using FunctionType = decltype(initWithBatchNode(p0, p1, p2, p3))(*)(cocos2d::extension::CCScale9Sprite*, cocos2d::CCSpriteBatchNode*, cocos2d::CCRect, bool, cocos2d::CCRect);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f3e50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2, p3);
}

auto cocos2d::extension::CCScale9Sprite::initWithBatchNode(cocos2d::CCSpriteBatchNode* p0, cocos2d::CCRect p1, cocos2d::CCRect p2) -> decltype(initWithBatchNode(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCSpriteBatchNode*, cocos2d::CCRect, cocos2d::CCRect>::func(&cocos2d::extension::CCScale9Sprite::initWithBatchNode), this);
	using FunctionType = decltype(initWithBatchNode(p0, p1, p2))(*)(cocos2d::extension::CCScale9Sprite*, cocos2d::CCSpriteBatchNode*, cocos2d::CCRect, cocos2d::CCRect);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f3df0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}

auto cocos2d::extension::CCScale9Sprite::initWithFile(const char* p0, cocos2d::CCRect p1, cocos2d::CCRect p2) -> decltype(initWithFile(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<const char*, cocos2d::CCRect, cocos2d::CCRect>::func(&cocos2d::extension::CCScale9Sprite::initWithFile), this);
	using FunctionType = decltype(initWithFile(p0, p1, p2))(*)(cocos2d::extension::CCScale9Sprite*, const char*, cocos2d::CCRect, cocos2d::CCRect);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f53d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}

auto cocos2d::extension::CCScale9Sprite::initWithFile(const char* p0, cocos2d::CCRect p1) -> decltype(initWithFile(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<const char*, cocos2d::CCRect>::func(&cocos2d::extension::CCScale9Sprite::initWithFile), this);
	using FunctionType = decltype(initWithFile(p0, p1))(*)(cocos2d::extension::CCScale9Sprite*, const char*, cocos2d::CCRect);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f54e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCScale9Sprite::initWithFile(cocos2d::CCRect p0, const char* p1) -> decltype(initWithFile(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCRect, const char*>::func(&cocos2d::extension::CCScale9Sprite::initWithFile), this);
	using FunctionType = decltype(initWithFile(p0, p1))(*)(cocos2d::extension::CCScale9Sprite*, cocos2d::CCRect, const char*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f55d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCScale9Sprite::initWithFile(const char* p0) -> decltype(initWithFile(p0)) {
	auto self = addresser::thunkAdjust(Resolve<const char*>::func(&cocos2d::extension::CCScale9Sprite::initWithFile), this);
	using FunctionType = decltype(initWithFile(p0))(*)(cocos2d::extension::CCScale9Sprite*, const char*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f56c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCScale9Sprite::initWithSpriteFrame(cocos2d::CCSpriteFrame* p0, cocos2d::CCRect p1) -> decltype(initWithSpriteFrame(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCSpriteFrame*, cocos2d::CCRect>::func(&cocos2d::extension::CCScale9Sprite::initWithSpriteFrame), this);
	using FunctionType = decltype(initWithSpriteFrame(p0, p1))(*)(cocos2d::extension::CCScale9Sprite*, cocos2d::CCSpriteFrame*, cocos2d::CCRect);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f5780, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCScale9Sprite::initWithSpriteFrame(cocos2d::CCSpriteFrame* p0) -> decltype(initWithSpriteFrame(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCSpriteFrame*>::func(&cocos2d::extension::CCScale9Sprite::initWithSpriteFrame), this);
	using FunctionType = decltype(initWithSpriteFrame(p0))(*)(cocos2d::extension::CCScale9Sprite*, cocos2d::CCSpriteFrame*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f5890, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCScale9Sprite::initWithSpriteFrameName(const char* p0, cocos2d::CCRect p1) -> decltype(initWithSpriteFrameName(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<const char*, cocos2d::CCRect>::func(&cocos2d::extension::CCScale9Sprite::initWithSpriteFrameName), this);
	using FunctionType = decltype(initWithSpriteFrameName(p0, p1))(*)(cocos2d::extension::CCScale9Sprite*, const char*, cocos2d::CCRect);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f5950, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCScale9Sprite::initWithSpriteFrameName(const char* p0) -> decltype(initWithSpriteFrameName(p0)) {
	auto self = addresser::thunkAdjust(Resolve<const char*>::func(&cocos2d::extension::CCScale9Sprite::initWithSpriteFrameName), this);
	using FunctionType = decltype(initWithSpriteFrameName(p0))(*)(cocos2d::extension::CCScale9Sprite*, const char*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f5a50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCScale9Sprite::updateWithBatchNode(cocos2d::CCSpriteBatchNode* p0, cocos2d::CCRect p1, bool p2, cocos2d::CCRect p3) -> decltype(updateWithBatchNode(p0, p1, p2, p3)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCSpriteBatchNode*, cocos2d::CCRect, bool, cocos2d::CCRect>::func(&cocos2d::extension::CCScale9Sprite::updateWithBatchNode), this);
	using FunctionType = decltype(updateWithBatchNode(p0, p1, p2, p3))(*)(cocos2d::extension::CCScale9Sprite*, cocos2d::CCSpriteBatchNode*, cocos2d::CCRect, bool, cocos2d::CCRect);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f3ef0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2, p3);
}

auto cocos2d::extension::CCScale9Sprite::setSpriteFrame(cocos2d::CCSpriteFrame* p0) -> decltype(setSpriteFrame(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCSpriteFrame*>::func(&cocos2d::extension::CCScale9Sprite::setSpriteFrame), this);
	using FunctionType = decltype(setSpriteFrame(p0))(*)(cocos2d::extension::CCScale9Sprite*, cocos2d::CCSpriteFrame*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f60b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCScale9Sprite::resizableSpriteWithCapInsets(cocos2d::CCRect p0) -> decltype(resizableSpriteWithCapInsets(p0)) {
	using FunctionType = decltype(resizableSpriteWithCapInsets(p0))(*)(cocos2d::extension::CCScale9Sprite*, cocos2d::CCRect);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f5b10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCScale9Sprite::setBlendAdditive(bool p0) -> decltype(setBlendAdditive(p0)) {
	using FunctionType = decltype(setBlendAdditive(p0))(*)(cocos2d::extension::CCScale9Sprite*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f6570, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCScale9Sprite::updateCapInset() -> decltype(updateCapInset()) {
	using FunctionType = decltype(updateCapInset())(*)(cocos2d::extension::CCScale9Sprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f5d30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::extension::CCScale9Sprite::updatePositions() -> decltype(updatePositions()) {
	using FunctionType = decltype(updatePositions())(*)(cocos2d::extension::CCScale9Sprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f4ee0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
