
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJDropDownLayer.hpp>
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

GJDropDownLayer::~GJDropDownLayer() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(GJDropDownLayer*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x512178, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) GJDropDownLayer(geode::CutoffConstructor, sizeof(GJDropDownLayer));
		geode::DestructorLock::addLock(this);
	}
}

auto GJDropDownLayer::create(const char* title) -> decltype(create(title)) {
	using FunctionType = decltype(create(title))(*)(const char*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5128f8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(title);
}

auto GJDropDownLayer::create(const char* title, float height, bool noBack) -> decltype(create(title, height, noBack)) {
	using FunctionType = decltype(create(title, height, noBack))(*)(const char*, float, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5123d8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(title, height, noBack);
}

auto GJDropDownLayer::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJDropDownLayer::draw), this);
	using FunctionType = decltype(draw())(*)(GJDropDownLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x512c94, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJDropDownLayer::ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchBegan(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&GJDropDownLayer::ccTouchBegan), this);
	using FunctionType = decltype(ccTouchBegan(touch, event))(*)(GJDropDownLayer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x512cd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto GJDropDownLayer::ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchMoved(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&GJDropDownLayer::ccTouchMoved), this);
	using FunctionType = decltype(ccTouchMoved(touch, event))(*)(GJDropDownLayer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x512cf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto GJDropDownLayer::ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchEnded(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&GJDropDownLayer::ccTouchEnded), this);
	using FunctionType = decltype(ccTouchEnded(touch, event))(*)(GJDropDownLayer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x512ce0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto GJDropDownLayer::ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchCancelled(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&GJDropDownLayer::ccTouchCancelled), this);
	using FunctionType = decltype(ccTouchCancelled(touch, event))(*)(GJDropDownLayer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x512ce8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto GJDropDownLayer::registerWithTouchDispatcher() -> decltype(registerWithTouchDispatcher()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJDropDownLayer::registerWithTouchDispatcher), this);
	using FunctionType = decltype(registerWithTouchDispatcher())(*)(GJDropDownLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51297c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJDropDownLayer::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJDropDownLayer::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(GJDropDownLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5129b4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJDropDownLayer::customSetup() -> decltype(customSetup()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJDropDownLayer::customSetup), this);
	using FunctionType = decltype(customSetup())(*)(GJDropDownLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x512918, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJDropDownLayer::enterLayer() -> decltype(enterLayer()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJDropDownLayer::enterLayer), this);
	using FunctionType = decltype(enterLayer())(*)(GJDropDownLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x512944, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJDropDownLayer::exitLayer(cocos2d::CCObject* sender) -> decltype(exitLayer(sender)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*>::func(&GJDropDownLayer::exitLayer), this);
	using FunctionType = decltype(exitLayer(sender))(*)(GJDropDownLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5129d8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, sender);
}

auto GJDropDownLayer::showLayer(bool instant) -> decltype(showLayer(instant)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&GJDropDownLayer::showLayer), this);
	using FunctionType = decltype(showLayer(instant))(*)(GJDropDownLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x512a24, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, instant);
}

auto GJDropDownLayer::hideLayer(bool instant) -> decltype(hideLayer(instant)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&GJDropDownLayer::hideLayer), this);
	using FunctionType = decltype(hideLayer(instant))(*)(GJDropDownLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x512b28, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, instant);
}

auto GJDropDownLayer::layerVisible() -> decltype(layerVisible()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJDropDownLayer::layerVisible), this);
	using FunctionType = decltype(layerVisible())(*)(GJDropDownLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x512c30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJDropDownLayer::layerHidden() -> decltype(layerHidden()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJDropDownLayer::layerHidden), this);
	using FunctionType = decltype(layerHidden())(*)(GJDropDownLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x512c40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJDropDownLayer::enterAnimFinished() -> decltype(enterAnimFinished()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJDropDownLayer::enterAnimFinished), this);
	using FunctionType = decltype(enterAnimFinished())(*)(GJDropDownLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x512c2c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJDropDownLayer::disableUI() -> decltype(disableUI()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJDropDownLayer::disableUI), this);
	using FunctionType = decltype(disableUI())(*)(GJDropDownLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51291c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJDropDownLayer::enableUI() -> decltype(enableUI()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJDropDownLayer::enableUI), this);
	using FunctionType = decltype(enableUI())(*)(GJDropDownLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x512930, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJDropDownLayer::init(char const* title) -> decltype(init(title)) {
	using FunctionType = decltype(init(title))(*)(GJDropDownLayer*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x512908, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, title);
}

auto GJDropDownLayer::init(char const* title, float height, bool noBack) -> decltype(init(title, height, noBack)) {
	using FunctionType = decltype(init(title, height, noBack))(*)(GJDropDownLayer*, char const*, float, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5124fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, title, height, noBack);
}
