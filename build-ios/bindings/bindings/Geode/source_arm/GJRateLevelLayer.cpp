
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJRateLevelLayer.hpp>
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

GJRateLevelLayer::GJRateLevelLayer() : GJRateLevelLayer(geode::CutoffConstructor, sizeof(GJRateLevelLayer)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	GJRateLevelLayer::~GJRateLevelLayer();

	using FunctionType = void(*)(GJRateLevelLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45fcbc, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

GJRateLevelLayer::~GJRateLevelLayer() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(GJRateLevelLayer*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x45d134, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) GJRateLevelLayer(geode::CutoffConstructor, sizeof(GJRateLevelLayer));
		geode::DestructorLock::addLock(this);
	}
}

auto GJRateLevelLayer::create(GJGameLevel* level) -> decltype(create(level)) {
	using FunctionType = decltype(create(level))(*)(GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45d26c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(level);
}

auto GJRateLevelLayer::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJRateLevelLayer::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(GJRateLevelLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45fc98, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJRateLevelLayer::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*>::func(&GJRateLevelLayer::onClose), this);
	using FunctionType = decltype(onClose(sender))(*)(GJRateLevelLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45fc94, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, sender);
}

auto GJRateLevelLayer::onCustomButton(cocos2d::CCObject* sender) -> decltype(onCustomButton(sender)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*>::func(&GJRateLevelLayer::onCustomButton), this);
	using FunctionType = decltype(onCustomButton(sender))(*)(GJRateLevelLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45e33c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, sender);
}

auto GJRateLevelLayer::uploadActionFinished(int id, int response) -> decltype(uploadActionFinished(id, response)) {
	auto self = addresser::thunkAdjust(Resolve<int, int>::func(&GJRateLevelLayer::uploadActionFinished), this);
	using FunctionType = decltype(uploadActionFinished(id, response))(*)(GJRateLevelLayer*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45f924, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, id, response);
}

auto GJRateLevelLayer::uploadActionFailed(int id, int response) -> decltype(uploadActionFailed(id, response)) {
	auto self = addresser::thunkAdjust(Resolve<int, int>::func(&GJRateLevelLayer::uploadActionFailed), this);
	using FunctionType = decltype(uploadActionFailed(id, response))(*)(GJRateLevelLayer*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45fa7c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, id, response);
}

auto GJRateLevelLayer::onClosePopup(UploadActionPopup* popup) -> decltype(onClosePopup(popup)) {
	auto self = addresser::thunkAdjust(Resolve<UploadActionPopup*>::func(&GJRateLevelLayer::onClosePopup), this);
	using FunctionType = decltype(onClosePopup(popup))(*)(GJRateLevelLayer*, UploadActionPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45fbf4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, popup);
}

auto GJRateLevelLayer::rateInfoFinished(int id, gd::string info) -> decltype(rateInfoFinished(id, info)) {
	auto self = addresser::thunkAdjust(Resolve<int, gd::string>::func(&GJRateLevelLayer::rateInfoFinished), this);
	using FunctionType = decltype(rateInfoFinished(id, info))(*)(GJRateLevelLayer*, int, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45f7f8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, id, info);
}

auto GJRateLevelLayer::rateInfoFailed(int id, int response) -> decltype(rateInfoFailed(id, response)) {
	auto self = addresser::thunkAdjust(Resolve<int, int>::func(&GJRateLevelLayer::rateInfoFailed), this);
	using FunctionType = decltype(rateInfoFailed(id, response))(*)(GJRateLevelLayer*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45f8c4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, id, response);
}

auto GJRateLevelLayer::FLAlert_Clicked(FLAlertLayer* layer, bool btn2) -> decltype(FLAlert_Clicked(layer, btn2)) {
	auto self = addresser::thunkAdjust(Resolve<FLAlertLayer*, bool>::func(&GJRateLevelLayer::FLAlert_Clicked), this);
	using FunctionType = decltype(FLAlert_Clicked(layer, btn2))(*)(GJRateLevelLayer*, FLAlertLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45e508, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer, btn2);
}

auto GJRateLevelLayer::createStatPillar(int width, int height, int count, cocos2d::ccColor3B innerColor, cocos2d::ccColor3B outerColor, cocos2d::CCPoint position, gd::string text) -> decltype(createStatPillar(width, height, count, innerColor, outerColor, position, text)) {
	using FunctionType = decltype(createStatPillar(width, height, count, innerColor, outerColor, position, text))(*)(GJRateLevelLayer*, int, int, int, cocos2d::ccColor3B, cocos2d::ccColor3B, cocos2d::CCPoint, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45f4c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, width, height, count, innerColor, outerColor, position, text);
}

auto GJRateLevelLayer::getStarsButton(int stars, cocos2d::SEL_MenuHandler selector, cocos2d::CCMenu* menu, float scale) -> decltype(getStarsButton(stars, selector, menu, scale)) {
	using FunctionType = decltype(getStarsButton(stars, selector, menu, scale))(*)(GJRateLevelLayer*, int, cocos2d::SEL_MenuHandler, cocos2d::CCMenu*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45dfd4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, stars, selector, menu, scale);
}

auto GJRateLevelLayer::init(GJGameLevel* level) -> decltype(init(level)) {
	using FunctionType = decltype(init(level))(*)(GJRateLevelLayer*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45d2ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}

auto GJRateLevelLayer::onFeature(cocos2d::CCObject* sender) -> decltype(onFeature(sender)) {
	using FunctionType = decltype(onFeature(sender))(*)(GJRateLevelLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45e210, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJRateLevelLayer::onRate(cocos2d::CCObject* sender) -> decltype(onRate(sender)) {
	using FunctionType = decltype(onRate(sender))(*)(GJRateLevelLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45e260, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJRateLevelLayer::onToggleCoins(cocos2d::CCObject* sender) -> decltype(onToggleCoins(sender)) {
	using FunctionType = decltype(onToggleCoins(sender))(*)(GJRateLevelLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45df7c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJRateLevelLayer::selectRating(cocos2d::CCObject* sender) -> decltype(selectRating(sender)) {
	using FunctionType = decltype(selectRating(sender))(*)(GJRateLevelLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45e09c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJRateLevelLayer::setupRateInfo(gd::string info) -> decltype(setupRateInfo(info)) {
	using FunctionType = decltype(setupRateInfo(info))(*)(GJRateLevelLayer*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45e5f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, info);
}
