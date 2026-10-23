
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/SetupSongTriggerPopup.hpp>
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

auto SetupSongTriggerPopup::create(EffectGameObject* object, cocos2d::CCArray* objects) -> decltype(create(object, objects)) {
	using FunctionType = decltype(create(object, objects))(*)(EffectGameObject*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26ded8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(object, objects);
}

auto SetupSongTriggerPopup::pageChanged() -> decltype(pageChanged()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SetupSongTriggerPopup::pageChanged), this);
	using FunctionType = decltype(pageChanged())(*)(SetupSongTriggerPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26f020, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SetupSongTriggerPopup::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*>::func(&SetupSongTriggerPopup::onClose), this);
	using FunctionType = decltype(onClose(sender))(*)(SetupSongTriggerPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26f0b4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, sender);
}

auto SetupSongTriggerPopup::valueDidChange(int tag, float value) -> decltype(valueDidChange(tag, value)) {
	auto self = addresser::thunkAdjust(Resolve<int, float>::func(&SetupSongTriggerPopup::valueDidChange), this);
	using FunctionType = decltype(valueDidChange(tag, value))(*)(SetupSongTriggerPopup*, int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26ef20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, tag, value);
}

auto SetupSongTriggerPopup::onPlayback(SongInfoObject* object) -> decltype(onPlayback(object)) {
	auto self = addresser::thunkAdjust(Resolve<SongInfoObject*>::func(&SetupSongTriggerPopup::onPlayback), this);
	using FunctionType = decltype(onPlayback(object))(*)(SetupSongTriggerPopup*, SongInfoObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26ed0c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, object);
}

auto SetupSongTriggerPopup::init(EffectGameObject* object, cocos2d::CCArray* objects) -> decltype(init(object, objects)) {
	using FunctionType = decltype(init(object, objects))(*)(SetupSongTriggerPopup*, EffectGameObject*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26e078, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, objects);
}

auto SetupSongTriggerPopup::onResetSongTime(cocos2d::CCObject* sender) -> decltype(onResetSongTime(sender)) {
	using FunctionType = decltype(onResetSongTime(sender))(*)(SetupSongTriggerPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26ef14, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupSongTriggerPopup::onSavePlaybackPos(cocos2d::CCObject* sender) -> decltype(onSavePlaybackPos(sender)) {
	using FunctionType = decltype(onSavePlaybackPos(sender))(*)(SetupSongTriggerPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26eab8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupSongTriggerPopup::updateApplyPrepare(bool hideAll) -> decltype(updateApplyPrepare(hideAll)) {
	using FunctionType = decltype(updateApplyPrepare(hideAll))(*)(SetupSongTriggerPopup*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26ecc8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, hideAll);
}

auto SetupSongTriggerPopup::updateLength() -> decltype(updateLength()) {
	using FunctionType = decltype(updateLength())(*)(SetupSongTriggerPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26ea60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupSongTriggerPopup::updateSongTimeSlider() -> decltype(updateSongTimeSlider()) {
	using FunctionType = decltype(updateSongTimeSlider())(*)(SetupSongTriggerPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26ebec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
