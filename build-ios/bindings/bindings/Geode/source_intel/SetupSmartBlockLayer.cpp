
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/SetupSmartBlockLayer.hpp>
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

auto SetupSmartBlockLayer::create(SmartGameObject* object, cocos2d::CCArray* objects) -> decltype(create(object, objects)) {
	using FunctionType = decltype(create(object, objects))(*)(SmartGameObject*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e5c20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(object, objects);
}

auto SetupSmartBlockLayer::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SetupSmartBlockLayer::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(SetupSmartBlockLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e7620, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SetupSmartBlockLayer::show() -> decltype(show()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SetupSmartBlockLayer::show), this);
	using FunctionType = decltype(show())(*)(SetupSmartBlockLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e7590, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SetupSmartBlockLayer::selectArtClosed(SelectArtLayer* layer) -> decltype(selectArtClosed(layer)) {
	auto self = addresser::thunkAdjust(Resolve<SelectArtLayer*>::func(&SetupSmartBlockLayer::selectArtClosed), this);
	using FunctionType = decltype(selectArtClosed(layer))(*)(SetupSmartBlockLayer*, SelectArtLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e75f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer);
}

auto SetupSmartBlockLayer::determineStartValues() -> decltype(determineStartValues()) {
	using FunctionType = decltype(determineStartValues())(*)(SetupSmartBlockLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e6b30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupSmartBlockLayer::init(SmartGameObject* object, cocos2d::CCArray* objects) -> decltype(init(object, objects)) {
	using FunctionType = decltype(init(object, objects))(*)(SetupSmartBlockLayer*, SmartGameObject*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e5da0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, objects);
}

auto SetupSmartBlockLayer::onAllowFlipping(cocos2d::CCObject* sender) -> decltype(onAllowFlipping(sender)) {
	using FunctionType = decltype(onAllowFlipping(sender))(*)(SetupSmartBlockLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e7450, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupSmartBlockLayer::onAllowRotation(cocos2d::CCObject* sender) -> decltype(onAllowRotation(sender)) {
	using FunctionType = decltype(onAllowRotation(sender))(*)(SetupSmartBlockLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e7410, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupSmartBlockLayer::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	using FunctionType = decltype(onClose(sender))(*)(SetupSmartBlockLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e6c30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupSmartBlockLayer::onCreate(cocos2d::CCObject* sender) -> decltype(onCreate(sender)) {
	using FunctionType = decltype(onCreate(sender))(*)(SetupSmartBlockLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e6ce0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupSmartBlockLayer::onCreateAll(cocos2d::CCObject* sender) -> decltype(onCreateAll(sender)) {
	using FunctionType = decltype(onCreateAll(sender))(*)(SetupSmartBlockLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e7130, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupSmartBlockLayer::onCreateTemplate(cocos2d::CCObject* sender) -> decltype(onCreateTemplate(sender)) {
	using FunctionType = decltype(onCreateTemplate(sender))(*)(SetupSmartBlockLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e6df0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupSmartBlockLayer::onDontDelete(cocos2d::CCObject* sender) -> decltype(onDontDelete(sender)) {
	using FunctionType = decltype(onDontDelete(sender))(*)(SetupSmartBlockLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e7550, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupSmartBlockLayer::onIgnoreCorners(cocos2d::CCObject* sender) -> decltype(onIgnoreCorners(sender)) {
	using FunctionType = decltype(onIgnoreCorners(sender))(*)(SetupSmartBlockLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e74d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupSmartBlockLayer::onNearbyReference(cocos2d::CCObject* sender) -> decltype(onNearbyReference(sender)) {
	using FunctionType = decltype(onNearbyReference(sender))(*)(SetupSmartBlockLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e7510, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupSmartBlockLayer::onPasteTemplate(cocos2d::CCObject* sender) -> decltype(onPasteTemplate(sender)) {
	using FunctionType = decltype(onPasteTemplate(sender))(*)(SetupSmartBlockLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e6ef0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupSmartBlockLayer::onReferenceOnly(cocos2d::CCObject* sender) -> decltype(onReferenceOnly(sender)) {
	using FunctionType = decltype(onReferenceOnly(sender))(*)(SetupSmartBlockLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e7380, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupSmartBlockLayer::onSelectPremade(cocos2d::CCObject* sender) -> decltype(onSelectPremade(sender)) {
	using FunctionType = decltype(onSelectPremade(sender))(*)(SetupSmartBlockLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e6e70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupSmartBlockLayer::onSelectTemplate(cocos2d::CCObject* sender) -> decltype(onSelectTemplate(sender)) {
	using FunctionType = decltype(onSelectTemplate(sender))(*)(SetupSmartBlockLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e6ec0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}
