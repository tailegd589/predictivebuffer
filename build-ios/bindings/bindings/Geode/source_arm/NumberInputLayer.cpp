
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/NumberInputLayer.hpp>
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

auto NumberInputLayer::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f7134, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto NumberInputLayer::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&NumberInputLayer::init), this);
	using FunctionType = decltype(init())(*)(NumberInputLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f7238, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto NumberInputLayer::registerWithTouchDispatcher() -> decltype(registerWithTouchDispatcher()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&NumberInputLayer::registerWithTouchDispatcher), this);
	using FunctionType = decltype(registerWithTouchDispatcher())(*)(NumberInputLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f80d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto NumberInputLayer::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&NumberInputLayer::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(NumberInputLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f8058, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto NumberInputLayer::deleteLast() -> decltype(deleteLast()) {
	using FunctionType = decltype(deleteLast())(*)(NumberInputLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f7d24, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto NumberInputLayer::inputNumber(int num) -> decltype(inputNumber(num)) {
	using FunctionType = decltype(inputNumber(num))(*)(NumberInputLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f7f40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, num);
}

auto NumberInputLayer::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	using FunctionType = decltype(onClose(sender))(*)(NumberInputLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f7b98, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto NumberInputLayer::onDone(cocos2d::CCObject* sender) -> decltype(onDone(sender)) {
	using FunctionType = decltype(onDone(sender))(*)(NumberInputLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f7ee8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto NumberInputLayer::onNumber(cocos2d::CCObject* sender) -> decltype(onNumber(sender)) {
	using FunctionType = decltype(onNumber(sender))(*)(NumberInputLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f7bd4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto NumberInputLayer::updateNumberState() -> decltype(updateNumberState()) {
	using FunctionType = decltype(updateNumberState())(*)(NumberInputLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f7c6c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
