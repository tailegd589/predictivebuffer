
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/CCScrollLayerExt.hpp>
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

CCScrollLayerExt::CCScrollLayerExt(cocos2d::CCRect rect) : CCScrollLayerExt(geode::CutoffConstructor, sizeof(CCScrollLayerExt)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	CCScrollLayerExt::~CCScrollLayerExt();

	using FunctionType = void(*)(CCScrollLayerExt*, cocos2d::CCRect);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42de60, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this, rect);
}

CCScrollLayerExt::~CCScrollLayerExt() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(CCScrollLayerExt*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x42e610, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) CCScrollLayerExt(geode::CutoffConstructor, sizeof(CCScrollLayerExt));
		geode::DestructorLock::addLock(this);
	}
}

auto CCScrollLayerExt::visit() -> decltype(visit()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CCScrollLayerExt::visit), this);
	using FunctionType = decltype(visit())(*)(CCScrollLayerExt*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42f1f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CCScrollLayerExt::ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchBegan(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&CCScrollLayerExt::ccTouchBegan), this);
	using FunctionType = decltype(ccTouchBegan(touch, event))(*)(CCScrollLayerExt*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42eb90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto CCScrollLayerExt::ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchMoved(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&CCScrollLayerExt::ccTouchMoved), this);
	using FunctionType = decltype(ccTouchMoved(touch, event))(*)(CCScrollLayerExt*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42efb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto CCScrollLayerExt::ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchEnded(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&CCScrollLayerExt::ccTouchEnded), this);
	using FunctionType = decltype(ccTouchEnded(touch, event))(*)(CCScrollLayerExt*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42ecb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto CCScrollLayerExt::ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchCancelled(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&CCScrollLayerExt::ccTouchCancelled), this);
	using FunctionType = decltype(ccTouchCancelled(touch, event))(*)(CCScrollLayerExt*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42ef50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto CCScrollLayerExt::registerWithTouchDispatcher() -> decltype(registerWithTouchDispatcher()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CCScrollLayerExt::registerWithTouchDispatcher), this);
	using FunctionType = decltype(registerWithTouchDispatcher())(*)(CCScrollLayerExt*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42eb50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CCScrollLayerExt::preVisitWithClippingRect(cocos2d::CCRect rect) -> decltype(preVisitWithClippingRect(rect)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCRect>::func(&CCScrollLayerExt::preVisitWithClippingRect), this);
	using FunctionType = decltype(preVisitWithClippingRect(rect))(*)(CCScrollLayerExt*, cocos2d::CCRect);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42f2f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, rect);
}

auto CCScrollLayerExt::postVisit() -> decltype(postVisit()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CCScrollLayerExt::postVisit), this);
	using FunctionType = decltype(postVisit())(*)(CCScrollLayerExt*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42f370, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CCScrollLayerExt::constraintContent() -> decltype(constraintContent()) {
	using FunctionType = decltype(constraintContent())(*)(CCScrollLayerExt*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42e8a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CCScrollLayerExt::doConstraintContent(bool instant) -> decltype(doConstraintContent(instant)) {
	using FunctionType = decltype(doConstraintContent(instant))(*)(CCScrollLayerExt*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42e8b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, instant);
}

auto CCScrollLayerExt::getMaxY() -> decltype(getMaxY()) {
	using FunctionType = decltype(getMaxY())(*)(CCScrollLayerExt*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42e480, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CCScrollLayerExt::getMinY() -> decltype(getMinY()) {
	using FunctionType = decltype(getMinY())(*)(CCScrollLayerExt*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42e490, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CCScrollLayerExt::moveToTop() -> decltype(moveToTop()) {
	using FunctionType = decltype(moveToTop())(*)(CCScrollLayerExt*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42e580, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CCScrollLayerExt::moveToTopWithOffset(float offset) -> decltype(moveToTopWithOffset(offset)) {
	using FunctionType = decltype(moveToTopWithOffset(offset))(*)(CCScrollLayerExt*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42e4e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, offset);
}

auto CCScrollLayerExt::scrollingEnd() -> decltype(scrollingEnd()) {
	using FunctionType = decltype(scrollingEnd())(*)(CCScrollLayerExt*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42ea50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CCScrollLayerExt::scrollLayer(float offset) -> decltype(scrollLayer(offset)) {
	using FunctionType = decltype(scrollLayer(offset))(*)(CCScrollLayerExt*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42f130, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, offset);
}

auto CCScrollLayerExt::setContentLayerSize(cocos2d::CCSize size) -> decltype(setContentLayerSize(size)) {
	using FunctionType = decltype(setContentLayerSize(size))(*)(CCScrollLayerExt*, cocos2d::CCSize);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42eaa0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, size);
}

auto CCScrollLayerExt::setContentOffset(cocos2d::CCPoint offset, bool animate) -> decltype(setContentOffset(offset, animate)) {
	using FunctionType = decltype(setContentOffset(offset, animate))(*)(CCScrollLayerExt*, cocos2d::CCPoint, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42eac0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, offset, animate);
}

auto CCScrollLayerExt::updateIndicators(float dt) -> decltype(updateIndicators(dt)) {
	using FunctionType = decltype(updateIndicators(dt))(*)(CCScrollLayerExt*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42e220, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}
