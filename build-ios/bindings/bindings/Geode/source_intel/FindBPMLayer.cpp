
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/FindBPMLayer.hpp>
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

auto FindBPMLayer::create(int songID) -> decltype(create(songID)) {
	using FunctionType = decltype(create(songID))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50d520, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(songID);
}

auto FindBPMLayer::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*>::func(&FindBPMLayer::onClose), this);
	using FunctionType = decltype(onClose(sender))(*)(FindBPMLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50da80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, sender);
}

auto FindBPMLayer::playMusic() -> decltype(playMusic()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&FindBPMLayer::playMusic), this);
	using FunctionType = decltype(playMusic())(*)(FindBPMLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50d8f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto FindBPMLayer::registerTouch() -> decltype(registerTouch()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&FindBPMLayer::registerTouch), this);
	using FunctionType = decltype(registerTouch())(*)(FindBPMLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50d980, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto FindBPMLayer::onInfo(cocos2d::CCObject* sender) -> decltype(onInfo(sender)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*>::func(&FindBPMLayer::onInfo), this);
	using FunctionType = decltype(onInfo(sender))(*)(FindBPMLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50da70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, sender);
}

auto FindBPMLayer::onRecord(cocos2d::CCObject* sender) -> decltype(onRecord(sender)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*>::func(&FindBPMLayer::onRecord), this);
	using FunctionType = decltype(onRecord(sender))(*)(FindBPMLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50d7e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, sender);
}

auto FindBPMLayer::recordingDidStop() -> decltype(recordingDidStop()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&FindBPMLayer::recordingDidStop), this);
	using FunctionType = decltype(recordingDidStop())(*)(FindBPMLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50d820, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto FindBPMLayer::calculateBPM() -> decltype(calculateBPM()) {
	using FunctionType = decltype(calculateBPM())(*)(FindBPMLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50d890, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto FindBPMLayer::init(int songID) -> decltype(init(songID)) {
	using FunctionType = decltype(init(songID))(*)(FindBPMLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50d6b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, songID);
}
