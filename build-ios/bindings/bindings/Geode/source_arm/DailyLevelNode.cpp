
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/DailyLevelNode.hpp>
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

DailyLevelNode::~DailyLevelNode() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(DailyLevelNode*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x1dc0dc, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) DailyLevelNode(geode::CutoffConstructor, sizeof(DailyLevelNode));
		geode::DestructorLock::addLock(this);
	}
}

auto DailyLevelNode::create(GJGameLevel* level, DailyLevelPage* page, bool isNew) -> decltype(create(level, page, isNew)) {
	using FunctionType = decltype(create(level, page, isNew))(*)(GJGameLevel*, DailyLevelPage*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1dba00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(level, page, isNew);
}

auto DailyLevelNode::FLAlert_Clicked(FLAlertLayer* layer, bool btn2) -> decltype(FLAlert_Clicked(layer, btn2)) {
	auto self = addresser::thunkAdjust(Resolve<FLAlertLayer*, bool>::func(&DailyLevelNode::FLAlert_Clicked), this);
	using FunctionType = decltype(FLAlert_Clicked(layer, btn2))(*)(DailyLevelNode*, FLAlertLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1dd0d8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer, btn2);
}

auto DailyLevelNode::init(GJGameLevel* level, DailyLevelPage* page, bool isNew) -> decltype(init(level, page, isNew)) {
	using FunctionType = decltype(init(level, page, isNew))(*)(DailyLevelNode*, GJGameLevel*, DailyLevelPage*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1dc1f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level, page, isNew);
}

auto DailyLevelNode::onClaimReward(cocos2d::CCObject* sender) -> decltype(onClaimReward(sender)) {
	using FunctionType = decltype(onClaimReward(sender))(*)(DailyLevelNode*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1dcdec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto DailyLevelNode::onSkipLevel(cocos2d::CCObject* sender) -> decltype(onSkipLevel(sender)) {
	using FunctionType = decltype(onSkipLevel(sender))(*)(DailyLevelNode*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1dcef0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto DailyLevelNode::showSkipButton() -> decltype(showSkipButton()) {
	using FunctionType = decltype(showSkipButton())(*)(DailyLevelNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1db564, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto DailyLevelNode::updateTimeLabel(gd::string text) -> decltype(updateTimeLabel(text)) {
	using FunctionType = decltype(updateTimeLabel(text))(*)(DailyLevelNode*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1db408, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, text);
}
