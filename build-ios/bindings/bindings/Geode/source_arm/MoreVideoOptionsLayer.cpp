
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/MoreVideoOptionsLayer.hpp>
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

MoreVideoOptionsLayer::~MoreVideoOptionsLayer() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(MoreVideoOptionsLayer*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x6a80e8, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) MoreVideoOptionsLayer(geode::CutoffConstructor, sizeof(MoreVideoOptionsLayer));
		geode::DestructorLock::addLock(this);
	}
}

auto MoreVideoOptionsLayer::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6a7c3c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto MoreVideoOptionsLayer::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&MoreVideoOptionsLayer::init), this);
	using FunctionType = decltype(init())(*)(MoreVideoOptionsLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6a8378, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto MoreVideoOptionsLayer::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&MoreVideoOptionsLayer::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(MoreVideoOptionsLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6aa3a4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto MoreVideoOptionsLayer::addToggle(char const* label, char const* key, char const* description) -> decltype(addToggle(label, key, description)) {
	using FunctionType = decltype(addToggle(label, key, description))(*)(MoreVideoOptionsLayer*, char const*, char const*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6a87b4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, label, key, description);
}

auto MoreVideoOptionsLayer::countForPage(int page) -> decltype(countForPage(page)) {
	using FunctionType = decltype(countForPage(page))(*)(MoreVideoOptionsLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6a9fd8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page);
}

auto MoreVideoOptionsLayer::goToPage(int page) -> decltype(goToPage(page)) {
	using FunctionType = decltype(goToPage(page))(*)(MoreVideoOptionsLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6a8d80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page);
}

auto MoreVideoOptionsLayer::incrementCountForPage(int page) -> decltype(incrementCountForPage(page)) {
	using FunctionType = decltype(incrementCountForPage(page))(*)(MoreVideoOptionsLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6a9ae0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page);
}

auto MoreVideoOptionsLayer::infoKey(int index) -> decltype(infoKey(index)) {
	using FunctionType = decltype(infoKey(index))(*)(MoreVideoOptionsLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6a9dd4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}

auto MoreVideoOptionsLayer::layerForPage(int page) -> decltype(layerForPage(page)) {
	using FunctionType = decltype(layerForPage(page))(*)(MoreVideoOptionsLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6a9280, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page);
}

auto MoreVideoOptionsLayer::layerKey(int page) -> decltype(layerKey(page)) {
	using FunctionType = decltype(layerKey(page))(*)(MoreVideoOptionsLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6aa140, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page);
}

auto MoreVideoOptionsLayer::nextPosition(int page) -> decltype(nextPosition(page)) {
	using FunctionType = decltype(nextPosition(page))(*)(MoreVideoOptionsLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6a9190, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page);
}

auto MoreVideoOptionsLayer::objectKey(int page) -> decltype(objectKey(page)) {
	using FunctionType = decltype(objectKey(page))(*)(MoreVideoOptionsLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6aa118, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page);
}

auto MoreVideoOptionsLayer::objectsForPage(int page) -> decltype(objectsForPage(page)) {
	using FunctionType = decltype(objectsForPage(page))(*)(MoreVideoOptionsLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6a9c10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page);
}

auto MoreVideoOptionsLayer::onApplyFPS(cocos2d::CCObject* sender) -> decltype(onApplyFPS(sender)) {
	using FunctionType = decltype(onApplyFPS(sender))(*)(MoreVideoOptionsLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6aa1f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto MoreVideoOptionsLayer::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	using FunctionType = decltype(onClose(sender))(*)(MoreVideoOptionsLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6a8d10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto MoreVideoOptionsLayer::onInfo(cocos2d::CCObject* sender) -> decltype(onInfo(sender)) {
	using FunctionType = decltype(onInfo(sender))(*)(MoreVideoOptionsLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6a9dfc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto MoreVideoOptionsLayer::onNextPage(cocos2d::CCObject* sender) -> decltype(onNextPage(sender)) {
	using FunctionType = decltype(onNextPage(sender))(*)(MoreVideoOptionsLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6a8d74, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto MoreVideoOptionsLayer::onPrevPage(cocos2d::CCObject* sender) -> decltype(onPrevPage(sender)) {
	using FunctionType = decltype(onPrevPage(sender))(*)(MoreVideoOptionsLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6a8d68, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto MoreVideoOptionsLayer::onToggle(cocos2d::CCObject* sender) -> decltype(onToggle(sender)) {
	using FunctionType = decltype(onToggle(sender))(*)(MoreVideoOptionsLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6a9458, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto MoreVideoOptionsLayer::pageKey(int page) -> decltype(pageKey(page)) {
	using FunctionType = decltype(pageKey(page))(*)(MoreVideoOptionsLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6aa0f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page);
}

auto MoreVideoOptionsLayer::updateFPSButtons() -> decltype(updateFPSButtons()) {
	using FunctionType = decltype(updateFPSButtons())(*)(MoreVideoOptionsLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6aa168, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
