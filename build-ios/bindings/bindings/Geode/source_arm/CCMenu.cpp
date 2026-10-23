
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCMenu.hpp>
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

auto cocos2d::CCMenu::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69b524, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCMenu::createWithArray(cocos2d::CCArray* p0) -> decltype(createWithArray(p0)) {
	using FunctionType = decltype(createWithArray(p0))(*)(cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69b67c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCMenu::createWithItem(cocos2d::CCMenuItem* p0) -> decltype(createWithItem(p0)) {
	using FunctionType = decltype(createWithItem(p0))(*)(cocos2d::CCMenuItem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69b8c8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCMenu::createWithItems(cocos2d::CCMenuItem* p0, va_list p1) -> decltype(createWithItems(p0, p1)) {
	using FunctionType = decltype(createWithItems(p0, p1))(*)(cocos2d::CCMenuItem*, va_list);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69b570, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCMenu::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCMenu::init), this);
	using FunctionType = decltype(init())(*)(cocos2d::CCMenu*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69b8e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCMenu::addChild(cocos2d::CCNode* p0) -> decltype(addChild(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*>::func(&cocos2d::CCMenu::addChild), this);
	using FunctionType = decltype(addChild(p0))(*)(cocos2d::CCMenu*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69b8f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCMenu::addChild(cocos2d::CCNode* p0, int p1) -> decltype(addChild(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*, int>::func(&cocos2d::CCMenu::addChild), this);
	using FunctionType = decltype(addChild(p0, p1))(*)(cocos2d::CCMenu*, cocos2d::CCNode*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69b8f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCMenu::addChild(cocos2d::CCNode* p0, int p1, int p2) -> decltype(addChild(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*, int, int>::func(&cocos2d::CCMenu::addChild), this);
	using FunctionType = decltype(addChild(p0, p1, p2))(*)(cocos2d::CCMenu*, cocos2d::CCNode*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69b8f8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}

auto cocos2d::CCMenu::removeChild(cocos2d::CCNode* p0, bool p1) -> decltype(removeChild(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*, bool>::func(&cocos2d::CCMenu::removeChild), this);
	using FunctionType = decltype(removeChild(p0, p1))(*)(cocos2d::CCMenu*, cocos2d::CCNode*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69b948, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCMenu::onExit() -> decltype(onExit()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCMenu::onExit), this);
	using FunctionType = decltype(onExit())(*)(cocos2d::CCMenu*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69b8fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCMenu::registerWithTouchDispatcher() -> decltype(registerWithTouchDispatcher()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCMenu::registerWithTouchDispatcher), this);
	using FunctionType = decltype(registerWithTouchDispatcher())(*)(cocos2d::CCMenu*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69baa4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCMenu::ccTouchBegan(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) -> decltype(ccTouchBegan(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&cocos2d::CCMenu::ccTouchBegan), this);
	using FunctionType = decltype(ccTouchBegan(p0, p1))(*)(cocos2d::CCMenu*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69baf4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCMenu::ccTouchMoved(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) -> decltype(ccTouchMoved(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&cocos2d::CCMenu::ccTouchMoved), this);
	using FunctionType = decltype(ccTouchMoved(p0, p1))(*)(cocos2d::CCMenu*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69bdcc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCMenu::ccTouchEnded(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) -> decltype(ccTouchEnded(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&cocos2d::CCMenu::ccTouchEnded), this);
	using FunctionType = decltype(ccTouchEnded(p0, p1))(*)(cocos2d::CCMenu*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69bcdc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCMenu::ccTouchCancelled(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) -> decltype(ccTouchCancelled(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&cocos2d::CCMenu::ccTouchCancelled), this);
	using FunctionType = decltype(ccTouchCancelled(p0, p1))(*)(cocos2d::CCMenu*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69bd64, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCMenu::alignItemsHorizontally() -> decltype(alignItemsHorizontally()) {
	using FunctionType = decltype(alignItemsHorizontally())(*)(cocos2d::CCMenu*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69c100, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCMenu::alignItemsHorizontallyWithPadding(float p0) -> decltype(alignItemsHorizontallyWithPadding(p0)) {
	using FunctionType = decltype(alignItemsHorizontallyWithPadding(p0))(*)(cocos2d::CCMenu*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69c108, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCMenu::alignItemsInColumns(unsigned int p0, va_list p1) -> decltype(alignItemsInColumns(p0, p1)) {
	using FunctionType = decltype(alignItemsInColumns(p0, p1))(*)(cocos2d::CCMenu*, unsigned int, va_list);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69c328, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCMenu::alignItemsInColumnsWithArray(cocos2d::CCArray* p0) -> decltype(alignItemsInColumnsWithArray(p0)) {
	using FunctionType = decltype(alignItemsInColumnsWithArray(p0))(*)(cocos2d::CCMenu*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69c3dc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCMenu::alignItemsInRows(unsigned int p0, va_list p1) -> decltype(alignItemsInRows(p0, p1)) {
	using FunctionType = decltype(alignItemsInRows(p0, p1))(*)(cocos2d::CCMenu*, unsigned int, va_list);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69c838, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCMenu::alignItemsInRowsWithArray(cocos2d::CCArray* p0) -> decltype(alignItemsInRowsWithArray(p0)) {
	using FunctionType = decltype(alignItemsInRowsWithArray(p0))(*)(cocos2d::CCMenu*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69c8ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCMenu::alignItemsVertically() -> decltype(alignItemsVertically()) {
	using FunctionType = decltype(alignItemsVertically())(*)(cocos2d::CCMenu*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69bf00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCMenu::alignItemsVerticallyWithPadding(float p0) -> decltype(alignItemsVerticallyWithPadding(p0)) {
	using FunctionType = decltype(alignItemsVerticallyWithPadding(p0))(*)(cocos2d::CCMenu*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69bf08, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCMenu::giveMenuTouchPriority() -> decltype(giveMenuTouchPriority()) {
	using FunctionType = decltype(giveMenuTouchPriority())(*)(cocos2d::CCMenu*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69b9dc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCMenu::initWithArray(cocos2d::CCArray* p0) -> decltype(initWithArray(p0)) {
	using FunctionType = decltype(initWithArray(p0))(*)(cocos2d::CCMenu*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69b734, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCMenu::itemForTouch(cocos2d::CCTouch* p0) -> decltype(itemForTouch(p0)) {
	using FunctionType = decltype(itemForTouch(p0))(*)(cocos2d::CCMenu*, cocos2d::CCTouch*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69bbc4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCMenu::itemForTouch(cocos2d::CCTouch* p0, bool p1) -> decltype(itemForTouch(p0, p1)) {
	using FunctionType = decltype(itemForTouch(p0, p1))(*)(cocos2d::CCMenu*, cocos2d::CCTouch*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69ce24, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCMenu::setHandlerPriority(int p0) -> decltype(setHandlerPriority(p0)) {
	using FunctionType = decltype(setHandlerPriority(p0))(*)(cocos2d::CCMenu*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69ba6c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
