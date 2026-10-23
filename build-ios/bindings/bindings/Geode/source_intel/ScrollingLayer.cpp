
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/ScrollingLayer.hpp>
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

ScrollingLayer::ScrollingLayer() : ScrollingLayer(geode::CutoffConstructor, sizeof(ScrollingLayer)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	ScrollingLayer::~ScrollingLayer();

	using FunctionType = void(*)(ScrollingLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x720e50, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

auto ScrollingLayer::create(cocos2d::CCSize size, cocos2d::CCPoint position, float factor) -> decltype(create(size, position, factor)) {
	using FunctionType = decltype(create(size, position, factor))(*)(cocos2d::CCSize, cocos2d::CCPoint, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x720630, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(size, position, factor);
}

auto ScrollingLayer::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&ScrollingLayer::draw), this);
	using FunctionType = decltype(draw())(*)(ScrollingLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7208f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto ScrollingLayer::visit() -> decltype(visit()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&ScrollingLayer::visit), this);
	using FunctionType = decltype(visit())(*)(ScrollingLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7209c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto ScrollingLayer::ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchBegan(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&ScrollingLayer::ccTouchBegan), this);
	using FunctionType = decltype(ccTouchBegan(touch, event))(*)(ScrollingLayer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x720b10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto ScrollingLayer::ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchMoved(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&ScrollingLayer::ccTouchMoved), this);
	using FunctionType = decltype(ccTouchMoved(touch, event))(*)(ScrollingLayer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x720cb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto ScrollingLayer::ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchEnded(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&ScrollingLayer::ccTouchEnded), this);
	using FunctionType = decltype(ccTouchEnded(touch, event))(*)(ScrollingLayer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x720dd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto ScrollingLayer::ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchCancelled(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&ScrollingLayer::ccTouchCancelled), this);
	using FunctionType = decltype(ccTouchCancelled(touch, event))(*)(ScrollingLayer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x720e10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto ScrollingLayer::getViewRect() -> decltype(getViewRect()) {
	using FunctionType = decltype(getViewRect())(*)(ScrollingLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x720800, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto ScrollingLayer::init(cocos2d::CCSize size, cocos2d::CCPoint position, float factor) -> decltype(init(size, position, factor)) {
	using FunctionType = decltype(init(size, position, factor))(*)(ScrollingLayer*, cocos2d::CCSize, cocos2d::CCPoint, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x720740, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, size, position, factor);
}

auto ScrollingLayer::setStartOffset(cocos2d::CCPoint offset) -> decltype(setStartOffset(offset)) {
	using FunctionType = decltype(setStartOffset(offset))(*)(ScrollingLayer*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x720ad0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, offset);
}
