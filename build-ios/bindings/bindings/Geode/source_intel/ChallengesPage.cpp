
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/ChallengesPage.hpp>
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

ChallengesPage::~ChallengesPage() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(ChallengesPage*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x39cdc0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) ChallengesPage(geode::CutoffConstructor, sizeof(ChallengesPage));
		geode::DestructorLock::addLock(this);
	}
}

auto ChallengesPage::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39cf60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto ChallengesPage::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&ChallengesPage::init), this);
	using FunctionType = decltype(init())(*)(ChallengesPage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39d0d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto ChallengesPage::registerWithTouchDispatcher() -> decltype(registerWithTouchDispatcher()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&ChallengesPage::registerWithTouchDispatcher), this);
	using FunctionType = decltype(registerWithTouchDispatcher())(*)(ChallengesPage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39e770, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto ChallengesPage::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&ChallengesPage::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(ChallengesPage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39e6e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto ChallengesPage::show() -> decltype(show()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&ChallengesPage::show), this);
	using FunctionType = decltype(show())(*)(ChallengesPage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39e540, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto ChallengesPage::FLAlert_Clicked(FLAlertLayer* layer, bool btn2) -> decltype(FLAlert_Clicked(layer, btn2)) {
	auto self = addresser::thunkAdjust(Resolve<FLAlertLayer*, bool>::func(&ChallengesPage::FLAlert_Clicked), this);
	using FunctionType = decltype(FLAlert_Clicked(layer, btn2))(*)(ChallengesPage*, FLAlertLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39e6c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer, btn2);
}

auto ChallengesPage::challengeStatusFinished() -> decltype(challengeStatusFinished()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&ChallengesPage::challengeStatusFinished), this);
	using FunctionType = decltype(challengeStatusFinished())(*)(ChallengesPage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39e040, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto ChallengesPage::challengeStatusFailed() -> decltype(challengeStatusFailed()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&ChallengesPage::challengeStatusFailed), this);
	using FunctionType = decltype(challengeStatusFailed())(*)(ChallengesPage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39e340, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto ChallengesPage::currencyWillExit(CurrencyRewardLayer* layer) -> decltype(currencyWillExit(layer)) {
	auto self = addresser::thunkAdjust(Resolve<CurrencyRewardLayer*>::func(&ChallengesPage::currencyWillExit), this);
	using FunctionType = decltype(currencyWillExit(layer))(*)(ChallengesPage*, CurrencyRewardLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39e8d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer);
}

auto ChallengesPage::claimItem(ChallengeNode* node, GJChallengeItem* item, cocos2d::CCPoint position) -> decltype(claimItem(node, item, position)) {
	using FunctionType = decltype(claimItem(node, item, position))(*)(ChallengesPage*, ChallengeNode*, GJChallengeItem*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39e7b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, node, item, position);
}

auto ChallengesPage::createChallengeNode(int number, bool skipAnimation, float animLength, bool isNew) -> decltype(createChallengeNode(number, skipAnimation, animLength, isNew)) {
	using FunctionType = decltype(createChallengeNode(number, skipAnimation, animLength, isNew))(*)(ChallengesPage*, int, bool, float, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39dd80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, number, skipAnimation, animLength, isNew);
}

auto ChallengesPage::exitNodeAtSlot(int position, float delay) -> decltype(exitNodeAtSlot(position, delay)) {
	using FunctionType = decltype(exitNodeAtSlot(position, delay))(*)(ChallengesPage*, int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39e240, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, position, delay);
}

auto ChallengesPage::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	using FunctionType = decltype(onClose(sender))(*)(ChallengesPage*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39dae0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto ChallengesPage::tryGetChallenges() -> decltype(tryGetChallenges()) {
	using FunctionType = decltype(tryGetChallenges())(*)(ChallengesPage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39e3d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto ChallengesPage::updateDots() -> decltype(updateDots()) {
	using FunctionType = decltype(updateDots())(*)(ChallengesPage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39df70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto ChallengesPage::updateTimers(float dt) -> decltype(updateTimers(dt)) {
	using FunctionType = decltype(updateTimers(dt))(*)(ChallengesPage*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39db20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}
