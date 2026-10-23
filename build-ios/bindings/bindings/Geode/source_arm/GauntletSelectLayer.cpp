
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GauntletSelectLayer.hpp>
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

GauntletSelectLayer::~GauntletSelectLayer() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(GauntletSelectLayer*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x4bee48, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) GauntletSelectLayer(geode::CutoffConstructor, sizeof(GauntletSelectLayer));
		geode::DestructorLock::addLock(this);
	}
}

auto GauntletSelectLayer::create(int unused) -> decltype(create(unused)) {
	using FunctionType = decltype(create(unused))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4bef7c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(unused);
}

auto GauntletSelectLayer::scene(int unused) -> decltype(scene(unused)) {
	using FunctionType = decltype(scene(unused))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4bef30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(unused);
}

auto GauntletSelectLayer::onExit() -> decltype(onExit()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GauntletSelectLayer::onExit), this);
	using FunctionType = decltype(onExit())(*)(GauntletSelectLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c1388, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GauntletSelectLayer::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GauntletSelectLayer::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(GauntletSelectLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c0c7c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GauntletSelectLayer::rewardedVideoFinished() -> decltype(rewardedVideoFinished()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GauntletSelectLayer::rewardedVideoFinished), this);
	using FunctionType = decltype(rewardedVideoFinished())(*)(GauntletSelectLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c0da8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GauntletSelectLayer::scrollLayerWillScrollToPage(BoomScrollLayer* layer, int page) -> decltype(scrollLayerWillScrollToPage(layer, page)) {
	auto self = addresser::thunkAdjust(Resolve<BoomScrollLayer*, int>::func(&GauntletSelectLayer::scrollLayerWillScrollToPage), this);
	using FunctionType = decltype(scrollLayerWillScrollToPage(layer, page))(*)(GauntletSelectLayer*, BoomScrollLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c0bdc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer, page);
}

auto GauntletSelectLayer::scrollLayerScrolledToPage(BoomScrollLayer* layer, int page) -> decltype(scrollLayerScrolledToPage(layer, page)) {
	auto self = addresser::thunkAdjust(Resolve<BoomScrollLayer*, int>::func(&GauntletSelectLayer::scrollLayerScrolledToPage), this);
	using FunctionType = decltype(scrollLayerScrolledToPage(layer, page))(*)(GauntletSelectLayer*, BoomScrollLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c0b3c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer, page);
}

auto GauntletSelectLayer::loadLevelsFinished(cocos2d::CCArray* gauntlets, char const* key, int type) -> decltype(loadLevelsFinished(gauntlets, key, type)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCArray*, char const*, int>::func(&GauntletSelectLayer::loadLevelsFinished), this);
	using FunctionType = decltype(loadLevelsFinished(gauntlets, key, type))(*)(GauntletSelectLayer*, cocos2d::CCArray*, char const*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c010c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, gauntlets, key, type);
}

auto GauntletSelectLayer::loadLevelsFailed(char const* key, int type) -> decltype(loadLevelsFailed(key, type)) {
	auto self = addresser::thunkAdjust(Resolve<char const*, int>::func(&GauntletSelectLayer::loadLevelsFailed), this);
	using FunctionType = decltype(loadLevelsFailed(key, type))(*)(GauntletSelectLayer*, char const*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c02b4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, key, type);
}

auto GauntletSelectLayer::goToPage(int page, bool instant) -> decltype(goToPage(page, instant)) {
	using FunctionType = decltype(goToPage(page, instant))(*)(GauntletSelectLayer*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c0a40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page, instant);
}

auto GauntletSelectLayer::init(int unused) -> decltype(init(unused)) {
	using FunctionType = decltype(init(unused))(*)(GauntletSelectLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4bf054, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, unused);
}

auto GauntletSelectLayer::onBack(cocos2d::CCObject* sender) -> decltype(onBack(sender)) {
	using FunctionType = decltype(onBack(sender))(*)(GauntletSelectLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4bfa8c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GauntletSelectLayer::onInfo(cocos2d::CCObject* sender) -> decltype(onInfo(sender)) {
	using FunctionType = decltype(onInfo(sender))(*)(GauntletSelectLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4bfb00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GauntletSelectLayer::onNext(cocos2d::CCObject* sender) -> decltype(onNext(sender)) {
	using FunctionType = decltype(onNext(sender))(*)(GauntletSelectLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4bfa78, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GauntletSelectLayer::onPlay(cocos2d::CCObject* sender) -> decltype(onPlay(sender)) {
	using FunctionType = decltype(onPlay(sender))(*)(GauntletSelectLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c04d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GauntletSelectLayer::onPrev(cocos2d::CCObject* sender) -> decltype(onPrev(sender)) {
	using FunctionType = decltype(onPrev(sender))(*)(GauntletSelectLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4bfa64, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GauntletSelectLayer::onRefresh(cocos2d::CCObject* sender) -> decltype(onRefresh(sender)) {
	using FunctionType = decltype(onRefresh(sender))(*)(GauntletSelectLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4bfbbc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GauntletSelectLayer::playUnlockAnimation() -> decltype(playUnlockAnimation()) {
	using FunctionType = decltype(playUnlockAnimation())(*)(GauntletSelectLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c0e1c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GauntletSelectLayer::setupGauntlets() -> decltype(setupGauntlets()) {
	using FunctionType = decltype(setupGauntlets())(*)(GauntletSelectLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4bfc64, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GauntletSelectLayer::showUnlockGauntlet() -> decltype(showUnlockGauntlet()) {
	using FunctionType = decltype(showUnlockGauntlet())(*)(GauntletSelectLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c1250, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GauntletSelectLayer::unblockPlay() -> decltype(unblockPlay()) {
	using FunctionType = decltype(unblockPlay())(*)(GauntletSelectLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c0b34, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GauntletSelectLayer::unlockAnimationFinished() -> decltype(unlockAnimationFinished()) {
	using FunctionType = decltype(unlockAnimationFinished())(*)(GauntletSelectLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c17ac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GauntletSelectLayer::unlockAnimationStep2() -> decltype(unlockAnimationStep2()) {
	using FunctionType = decltype(unlockAnimationStep2())(*)(GauntletSelectLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c14c8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GauntletSelectLayer::unlockAnimationStep3() -> decltype(unlockAnimationStep3()) {
	using FunctionType = decltype(unlockAnimationStep3())(*)(GauntletSelectLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c17e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GauntletSelectLayer::updateArrows() -> decltype(updateArrows()) {
	using FunctionType = decltype(updateArrows())(*)(GauntletSelectLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c00bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
