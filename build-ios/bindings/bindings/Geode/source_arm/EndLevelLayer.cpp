
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/EndLevelLayer.hpp>
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

EndLevelLayer::EndLevelLayer() : EndLevelLayer(geode::CutoffConstructor, sizeof(EndLevelLayer)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	EndLevelLayer::~EndLevelLayer();

	using FunctionType = void(*)(EndLevelLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4234c8, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

EndLevelLayer::~EndLevelLayer() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(EndLevelLayer*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x41fbe8, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) EndLevelLayer(geode::CutoffConstructor, sizeof(EndLevelLayer));
		geode::DestructorLock::addLock(this);
	}
}

auto EndLevelLayer::create(PlayLayer* playLayer) -> decltype(create(playLayer)) {
	using FunctionType = decltype(create(playLayer))(*)(PlayLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x41fb38, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(playLayer);
}

auto EndLevelLayer::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&EndLevelLayer::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(EndLevelLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x422ca8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto EndLevelLayer::keyDown(cocos2d::enumKeyCodes key, double timestamp) -> decltype(keyDown(key, timestamp)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::enumKeyCodes, double>::func(&EndLevelLayer::keyDown), this);
	using FunctionType = decltype(keyDown(key, timestamp))(*)(EndLevelLayer*, cocos2d::enumKeyCodes, double);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x423444, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, key, timestamp);
}

auto EndLevelLayer::customSetup() -> decltype(customSetup()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&EndLevelLayer::customSetup), this);
	using FunctionType = decltype(customSetup())(*)(EndLevelLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x41fe0c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto EndLevelLayer::showLayer(bool instant) -> decltype(showLayer(instant)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&EndLevelLayer::showLayer), this);
	using FunctionType = decltype(showLayer(instant))(*)(EndLevelLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x421f14, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, instant);
}

auto EndLevelLayer::enterAnimFinished() -> decltype(enterAnimFinished()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&EndLevelLayer::enterAnimFinished), this);
	using FunctionType = decltype(enterAnimFinished())(*)(EndLevelLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x422bfc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto EndLevelLayer::keyUp(cocos2d::enumKeyCodes key, double timestamp) -> decltype(keyUp(key, timestamp)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::enumKeyCodes, double>::func(&EndLevelLayer::keyUp), this);
	using FunctionType = decltype(keyUp(key, timestamp))(*)(EndLevelLayer*, cocos2d::enumKeyCodes, double);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4234c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, key, timestamp);
}

auto EndLevelLayer::coinEnterFinished(cocos2d::CCPoint position) -> decltype(coinEnterFinished(position)) {
	using FunctionType = decltype(coinEnterFinished(position))(*)(EndLevelLayer*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x423038, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, position);
}

auto EndLevelLayer::coinEnterFinishedO(cocos2d::CCObject* sender) -> decltype(coinEnterFinishedO(sender)) {
	using FunctionType = decltype(coinEnterFinishedO(sender))(*)(EndLevelLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x422fec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EndLevelLayer::currencyEnterFinished() -> decltype(currencyEnterFinished()) {
	using FunctionType = decltype(currencyEnterFinished())(*)(EndLevelLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x423258, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto EndLevelLayer::diamondEnterFinished() -> decltype(diamondEnterFinished()) {
	using FunctionType = decltype(diamondEnterFinished())(*)(EndLevelLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42334c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto EndLevelLayer::getCoinString() -> decltype(getCoinString()) {
	using FunctionType = decltype(getCoinString())(*)(EndLevelLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x421690, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto EndLevelLayer::getEndText() -> decltype(getEndText()) {
	using FunctionType = decltype(getEndText())(*)(EndLevelLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4218d8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto EndLevelLayer::goEdit() -> decltype(goEdit()) {
	using FunctionType = decltype(goEdit())(*)(EndLevelLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x422c04, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto EndLevelLayer::init(PlayLayer* playLayer) -> decltype(init(playLayer)) {
	using FunctionType = decltype(init(playLayer))(*)(EndLevelLayer*, PlayLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x41fbcc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, playLayer);
}

auto EndLevelLayer::onEdit(cocos2d::CCObject* sender) -> decltype(onEdit(sender)) {
	using FunctionType = decltype(onEdit(sender))(*)(EndLevelLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x421bd4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EndLevelLayer::onEveryplay(cocos2d::CCObject* sender) -> decltype(onEveryplay(sender)) {
	using FunctionType = decltype(onEveryplay(sender))(*)(EndLevelLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x422c00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EndLevelLayer::onHideLayer(cocos2d::CCObject* sender) -> decltype(onHideLayer(sender)) {
	using FunctionType = decltype(onHideLayer(sender))(*)(EndLevelLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x421e28, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EndLevelLayer::onLevelLeaderboard(cocos2d::CCObject* sender) -> decltype(onLevelLeaderboard(sender)) {
	using FunctionType = decltype(onLevelLeaderboard(sender))(*)(EndLevelLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x421dbc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EndLevelLayer::onMenu(cocos2d::CCObject* sender) -> decltype(onMenu(sender)) {
	using FunctionType = decltype(onMenu(sender))(*)(EndLevelLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x421ad0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EndLevelLayer::onReplay(cocos2d::CCObject* sender) -> decltype(onReplay(sender)) {
	using FunctionType = decltype(onReplay(sender))(*)(EndLevelLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4219bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EndLevelLayer::onRestartCheckpoint(cocos2d::CCObject* sender) -> decltype(onRestartCheckpoint(sender)) {
	using FunctionType = decltype(onRestartCheckpoint(sender))(*)(EndLevelLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x421c68, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EndLevelLayer::playCoinEffect(float duration) -> decltype(playCoinEffect(duration)) {
	using FunctionType = decltype(playCoinEffect(duration))(*)(EndLevelLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4223fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, duration);
}

auto EndLevelLayer::playCurrencyEffect(float duration) -> decltype(playCurrencyEffect(duration)) {
	using FunctionType = decltype(playCurrencyEffect(duration))(*)(EndLevelLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42258c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, duration);
}

auto EndLevelLayer::playDiamondEffect(float duration) -> decltype(playDiamondEffect(duration)) {
	using FunctionType = decltype(playDiamondEffect(duration))(*)(EndLevelLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4228c4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, duration);
}

auto EndLevelLayer::playEndEffect() -> decltype(playEndEffect()) {
	using FunctionType = decltype(playEndEffect())(*)(EndLevelLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x422dd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto EndLevelLayer::playStarEffect(float duration) -> decltype(playStarEffect(duration)) {
	using FunctionType = decltype(playStarEffect(duration))(*)(EndLevelLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4220a4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, duration);
}

auto EndLevelLayer::starEnterFinished() -> decltype(starEnterFinished()) {
	using FunctionType = decltype(starEnterFinished())(*)(EndLevelLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x422cb4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto EndLevelLayer::tryShowBanner(float dt) -> decltype(tryShowBanner(dt)) {
	using FunctionType = decltype(tryShowBanner(dt))(*)(EndLevelLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x421ee4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}
