
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJOptionsLayer.hpp>
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

GJOptionsLayer::~GJOptionsLayer() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(GJOptionsLayer*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x29b6d0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) GJOptionsLayer(geode::CutoffConstructor, sizeof(GJOptionsLayer));
		geode::DestructorLock::addLock(this);
	}
}

auto GJOptionsLayer::create(int background) -> decltype(create(background)) {
	using FunctionType = decltype(create(background))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29bb20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(background);
}

auto GJOptionsLayer::setupOptions() -> decltype(setupOptions()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJOptionsLayer::setupOptions), this);
	using FunctionType = decltype(setupOptions())(*)(GJOptionsLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29c570, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJOptionsLayer::addGVToggle(char const* title, char const* variable, char const* description) -> decltype(addGVToggle(title, variable, description)) {
	using FunctionType = decltype(addGVToggle(title, variable, description))(*)(GJOptionsLayer*, char const*, char const*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29c580, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, title, variable, description);
}

auto GJOptionsLayer::addToggle(char const* title, int id, bool initial, char const* description) -> decltype(addToggle(title, id, initial, description)) {
	using FunctionType = decltype(addToggle(title, id, initial, description))(*)(GJOptionsLayer*, char const*, int, bool, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29cbb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, title, id, initial, description);
}

auto GJOptionsLayer::addToggleInternal(char const* title, int id, bool initial, char const* description) -> decltype(addToggleInternal(title, id, initial, description)) {
	using FunctionType = decltype(addToggleInternal(title, id, initial, description))(*)(GJOptionsLayer*, char const*, int, bool, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29c6b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, title, id, initial, description);
}

auto GJOptionsLayer::countForPage(int page) -> decltype(countForPage(page)) {
	using FunctionType = decltype(countForPage(page))(*)(GJOptionsLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29d4f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page);
}

auto GJOptionsLayer::goToPage(int page) -> decltype(goToPage(page)) {
	using FunctionType = decltype(goToPage(page))(*)(GJOptionsLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29c0d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page);
}

auto GJOptionsLayer::incrementCountForPage(int page) -> decltype(incrementCountForPage(page)) {
	using FunctionType = decltype(incrementCountForPage(page))(*)(GJOptionsLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29d000, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page);
}

auto GJOptionsLayer::infoKey(int index) -> decltype(infoKey(index)) {
	using FunctionType = decltype(infoKey(index))(*)(GJOptionsLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29d300, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}

auto GJOptionsLayer::init(int background) -> decltype(init(background)) {
	using FunctionType = decltype(init(background))(*)(GJOptionsLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29bd70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, background);
}

auto GJOptionsLayer::layerForPage(int page) -> decltype(layerForPage(page)) {
	using FunctionType = decltype(layerForPage(page))(*)(GJOptionsLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29ccc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page);
}

auto GJOptionsLayer::layerKey(int page) -> decltype(layerKey(page)) {
	using FunctionType = decltype(layerKey(page))(*)(GJOptionsLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29d630, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page);
}

auto GJOptionsLayer::nextPosition(int page) -> decltype(nextPosition(page)) {
	using FunctionType = decltype(nextPosition(page))(*)(GJOptionsLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29cbc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page);
}

auto GJOptionsLayer::objectKey(int page) -> decltype(objectKey(page)) {
	using FunctionType = decltype(objectKey(page))(*)(GJOptionsLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29d610, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page);
}

auto GJOptionsLayer::objectsForPage(int page) -> decltype(objectsForPage(page)) {
	using FunctionType = decltype(objectsForPage(page))(*)(GJOptionsLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29d120, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page);
}

auto GJOptionsLayer::offsetToNextPage() -> decltype(offsetToNextPage()) {
	using FunctionType = decltype(offsetToNextPage())(*)(GJOptionsLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29c540, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJOptionsLayer::onInfo(cocos2d::CCObject* sender) -> decltype(onInfo(sender)) {
	using FunctionType = decltype(onInfo(sender))(*)(GJOptionsLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29d320, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJOptionsLayer::onNextPage(cocos2d::CCObject* sender) -> decltype(onNextPage(sender)) {
	using FunctionType = decltype(onNextPage(sender))(*)(GJOptionsLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29c0b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJOptionsLayer::onPrevPage(cocos2d::CCObject* sender) -> decltype(onPrevPage(sender)) {
	using FunctionType = decltype(onPrevPage(sender))(*)(GJOptionsLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29c090, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJOptionsLayer::onToggle(cocos2d::CCObject* sender) -> decltype(onToggle(sender)) {
	using FunctionType = decltype(onToggle(sender))(*)(GJOptionsLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29ceb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJOptionsLayer::pageKey(int page) -> decltype(pageKey(page)) {
	using FunctionType = decltype(pageKey(page))(*)(GJOptionsLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29d5f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page);
}
