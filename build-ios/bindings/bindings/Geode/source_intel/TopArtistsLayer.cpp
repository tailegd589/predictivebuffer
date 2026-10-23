
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/TopArtistsLayer.hpp>
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

TopArtistsLayer::~TopArtistsLayer() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(TopArtistsLayer*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x310280, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) TopArtistsLayer(geode::CutoffConstructor, sizeof(TopArtistsLayer));
		geode::DestructorLock::addLock(this);
	}
}

auto TopArtistsLayer::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x310650, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto TopArtistsLayer::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&TopArtistsLayer::init), this);
	using FunctionType = decltype(init())(*)(TopArtistsLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3107b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto TopArtistsLayer::registerWithTouchDispatcher() -> decltype(registerWithTouchDispatcher()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&TopArtistsLayer::registerWithTouchDispatcher), this);
	using FunctionType = decltype(registerWithTouchDispatcher())(*)(TopArtistsLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x311150, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto TopArtistsLayer::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&TopArtistsLayer::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(TopArtistsLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3110e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto TopArtistsLayer::show() -> decltype(show()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&TopArtistsLayer::show), this);
	using FunctionType = decltype(show())(*)(TopArtistsLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x311c90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto TopArtistsLayer::loadListFinished(cocos2d::CCArray* objects, char const* key) -> decltype(loadListFinished(objects, key)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCArray*, char const*>::func(&TopArtistsLayer::loadListFinished), this);
	using FunctionType = decltype(loadListFinished(objects, key))(*)(TopArtistsLayer*, cocos2d::CCArray*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3111a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, objects, key);
}

auto TopArtistsLayer::loadListFailed(char const* key) -> decltype(loadListFailed(key)) {
	auto self = addresser::thunkAdjust(Resolve<char const*>::func(&TopArtistsLayer::loadListFailed), this);
	using FunctionType = decltype(loadListFailed(key))(*)(TopArtistsLayer*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x311260, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, key);
}

auto TopArtistsLayer::setupPageInfo(gd::string info, char const* key) -> decltype(setupPageInfo(info, key)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string, char const*>::func(&TopArtistsLayer::setupPageInfo), this);
	using FunctionType = decltype(setupPageInfo(info, key))(*)(TopArtistsLayer*, gd::string, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3112a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, info, key);
}

auto TopArtistsLayer::isCorrect(char const* key) -> decltype(isCorrect(key)) {
	using FunctionType = decltype(isCorrect(key))(*)(TopArtistsLayer*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x311190, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto TopArtistsLayer::loadPage(int page) -> decltype(loadPage(page)) {
	using FunctionType = decltype(loadPage(page))(*)(TopArtistsLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3118a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page);
}

auto TopArtistsLayer::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	using FunctionType = decltype(onClose(sender))(*)(TopArtistsLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x310f30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto TopArtistsLayer::onNextPage(cocos2d::CCObject* sender) -> decltype(onNextPage(sender)) {
	using FunctionType = decltype(onNextPage(sender))(*)(TopArtistsLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x310f80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto TopArtistsLayer::onPrevPage(cocos2d::CCObject* sender) -> decltype(onPrevPage(sender)) {
	using FunctionType = decltype(onPrevPage(sender))(*)(TopArtistsLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x310f60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto TopArtistsLayer::setupLeaderboard(cocos2d::CCArray* artists) -> decltype(setupLeaderboard(artists)) {
	using FunctionType = decltype(setupLeaderboard(artists))(*)(TopArtistsLayer*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x310fa0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, artists);
}

auto TopArtistsLayer::updateLevelsLabel() -> decltype(updateLevelsLabel()) {
	using FunctionType = decltype(updateLevelsLabel())(*)(TopArtistsLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x311800, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
