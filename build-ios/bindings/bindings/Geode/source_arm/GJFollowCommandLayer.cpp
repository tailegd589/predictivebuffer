
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJFollowCommandLayer.hpp>
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

auto GJFollowCommandLayer::create(EffectGameObject* object, cocos2d::CCArray* objects) -> decltype(create(object, objects)) {
	using FunctionType = decltype(create(object, objects))(*)(EffectGameObject*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26fcf4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(object, objects);
}

auto GJFollowCommandLayer::determineStartValues() -> decltype(determineStartValues()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJFollowCommandLayer::determineStartValues), this);
	using FunctionType = decltype(determineStartValues())(*)(GJFollowCommandLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x27178c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJFollowCommandLayer::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*>::func(&GJFollowCommandLayer::onClose), this);
	using FunctionType = decltype(onClose(sender))(*)(GJFollowCommandLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2720fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, sender);
}

auto GJFollowCommandLayer::textChanged(CCTextInputNode* node) -> decltype(textChanged(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&GJFollowCommandLayer::textChanged), this);
	using FunctionType = decltype(textChanged(node))(*)(GJFollowCommandLayer*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x271ce4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto GJFollowCommandLayer::init(EffectGameObject* object, cocos2d::CCArray* objects) -> decltype(init(object, objects)) {
	using FunctionType = decltype(init(object, objects))(*)(GJFollowCommandLayer*, EffectGameObject*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26fe84, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, objects);
}

auto GJFollowCommandLayer::onUpdateGroupID(cocos2d::CCObject* sender) -> decltype(onUpdateGroupID(sender)) {
	using FunctionType = decltype(onUpdateGroupID(sender))(*)(GJFollowCommandLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x271170, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJFollowCommandLayer::onUpdateGroupID2(cocos2d::CCObject* sender) -> decltype(onUpdateGroupID2(sender)) {
	using FunctionType = decltype(onUpdateGroupID2(sender))(*)(GJFollowCommandLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x27122c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJFollowCommandLayer::sliderChanged(cocos2d::CCObject* sender) -> decltype(sliderChanged(sender)) {
	using FunctionType = decltype(sliderChanged(sender))(*)(GJFollowCommandLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x270e5c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJFollowCommandLayer::sliderXModChanged(cocos2d::CCObject* sender) -> decltype(sliderXModChanged(sender)) {
	using FunctionType = decltype(sliderXModChanged(sender))(*)(GJFollowCommandLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x271050, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJFollowCommandLayer::sliderYModChanged(cocos2d::CCObject* sender) -> decltype(sliderYModChanged(sender)) {
	using FunctionType = decltype(sliderYModChanged(sender))(*)(GJFollowCommandLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2710e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJFollowCommandLayer::updateDuration() -> decltype(updateDuration()) {
	using FunctionType = decltype(updateDuration())(*)(GJFollowCommandLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x271a94, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJFollowCommandLayer::updateDurLabel(bool decimals) -> decltype(updateDurLabel(decimals)) {
	using FunctionType = decltype(updateDurLabel(decimals))(*)(GJFollowCommandLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x270eec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, decimals);
}

auto GJFollowCommandLayer::updateTargetGroupID() -> decltype(updateTargetGroupID()) {
	using FunctionType = decltype(updateTargetGroupID())(*)(GJFollowCommandLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x271be4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJFollowCommandLayer::updateTargetGroupID2() -> decltype(updateTargetGroupID2()) {
	using FunctionType = decltype(updateTargetGroupID2())(*)(GJFollowCommandLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x271c64, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJFollowCommandLayer::updateTextInputLabel() -> decltype(updateTextInputLabel()) {
	using FunctionType = decltype(updateTextInputLabel())(*)(GJFollowCommandLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2712d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJFollowCommandLayer::updateTextInputLabel2() -> decltype(updateTextInputLabel2()) {
	using FunctionType = decltype(updateTextInputLabel2())(*)(GJFollowCommandLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2713f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJFollowCommandLayer::updateXMod() -> decltype(updateXMod()) {
	using FunctionType = decltype(updateXMod())(*)(GJFollowCommandLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x271b04, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJFollowCommandLayer::updateXModLabel() -> decltype(updateXModLabel()) {
	using FunctionType = decltype(updateXModLabel())(*)(GJFollowCommandLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x271514, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJFollowCommandLayer::updateYMod() -> decltype(updateYMod()) {
	using FunctionType = decltype(updateYMod())(*)(GJFollowCommandLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x271b74, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJFollowCommandLayer::updateYModLabel() -> decltype(updateYModLabel()) {
	using FunctionType = decltype(updateYModLabel())(*)(GJFollowCommandLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x271650, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
