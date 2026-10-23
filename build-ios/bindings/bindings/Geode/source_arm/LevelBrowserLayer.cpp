
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/LevelBrowserLayer.hpp>
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

LevelBrowserLayer::~LevelBrowserLayer() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(LevelBrowserLayer*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x3f01d8, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) LevelBrowserLayer(geode::CutoffConstructor, sizeof(LevelBrowserLayer));
		geode::DestructorLock::addLock(this);
	}
}

auto LevelBrowserLayer::create(GJSearchObject* object) -> decltype(create(object)) {
	using FunctionType = decltype(create(object))(*)(GJSearchObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f0374, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(object);
}

auto LevelBrowserLayer::scene(GJSearchObject* object) -> decltype(scene(object)) {
	using FunctionType = decltype(scene(object))(*)(GJSearchObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f0328, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(object);
}

auto LevelBrowserLayer::onEnter() -> decltype(onEnter()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&LevelBrowserLayer::onEnter), this);
	using FunctionType = decltype(onEnter())(*)(LevelBrowserLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f6b74, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto LevelBrowserLayer::onEnterTransitionDidFinish() -> decltype(onEnterTransitionDidFinish()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&LevelBrowserLayer::onEnterTransitionDidFinish), this);
	using FunctionType = decltype(onEnterTransitionDidFinish())(*)(LevelBrowserLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f6d64, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto LevelBrowserLayer::ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchBegan(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&LevelBrowserLayer::ccTouchBegan), this);
	using FunctionType = decltype(ccTouchBegan(touch, event))(*)(LevelBrowserLayer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f6e34, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto LevelBrowserLayer::ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchMoved(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&LevelBrowserLayer::ccTouchMoved), this);
	using FunctionType = decltype(ccTouchMoved(touch, event))(*)(LevelBrowserLayer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f6e54, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto LevelBrowserLayer::ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchEnded(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&LevelBrowserLayer::ccTouchEnded), this);
	using FunctionType = decltype(ccTouchEnded(touch, event))(*)(LevelBrowserLayer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f6e44, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto LevelBrowserLayer::ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchCancelled(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&LevelBrowserLayer::ccTouchCancelled), this);
	using FunctionType = decltype(ccTouchCancelled(touch, event))(*)(LevelBrowserLayer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f6e4c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto LevelBrowserLayer::registerWithTouchDispatcher() -> decltype(registerWithTouchDispatcher()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&LevelBrowserLayer::registerWithTouchDispatcher), this);
	using FunctionType = decltype(registerWithTouchDispatcher())(*)(LevelBrowserLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f6d68, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto LevelBrowserLayer::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&LevelBrowserLayer::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(LevelBrowserLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f6118, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto LevelBrowserLayer::keyDown(cocos2d::enumKeyCodes key, double timestamp) -> decltype(keyDown(key, timestamp)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::enumKeyCodes, double>::func(&LevelBrowserLayer::keyDown), this);
	using FunctionType = decltype(keyDown(key, timestamp))(*)(LevelBrowserLayer*, cocos2d::enumKeyCodes, double);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f613c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, key, timestamp);
}

auto LevelBrowserLayer::loadLevelsFinished(cocos2d::CCArray* levels, char const* key, int type) -> decltype(loadLevelsFinished(levels, key, type)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCArray*, char const*, int>::func(&LevelBrowserLayer::loadLevelsFinished), this);
	using FunctionType = decltype(loadLevelsFinished(levels, key, type))(*)(LevelBrowserLayer*, cocos2d::CCArray*, char const*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f5654, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, levels, key, type);
}

auto LevelBrowserLayer::loadLevelsFailed(char const* key, int type) -> decltype(loadLevelsFailed(key, type)) {
	auto self = addresser::thunkAdjust(Resolve<char const*, int>::func(&LevelBrowserLayer::loadLevelsFailed), this);
	using FunctionType = decltype(loadLevelsFailed(key, type))(*)(LevelBrowserLayer*, char const*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f577c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, key, type);
}

auto LevelBrowserLayer::setupPageInfo(gd::string info, char const* key) -> decltype(setupPageInfo(info, key)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string, char const*>::func(&LevelBrowserLayer::setupPageInfo), this);
	using FunctionType = decltype(setupPageInfo(info, key))(*)(LevelBrowserLayer*, gd::string, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f5868, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, info, key);
}

auto LevelBrowserLayer::onBack(cocos2d::CCObject* sender) -> decltype(onBack(sender)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*>::func(&LevelBrowserLayer::onBack), this);
	using FunctionType = decltype(onBack(sender))(*)(LevelBrowserLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f6064, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, sender);
}

auto LevelBrowserLayer::shareCommentClosed(gd::string text, ShareCommentLayer* layer) -> decltype(shareCommentClosed(text, layer)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string, ShareCommentLayer*>::func(&LevelBrowserLayer::shareCommentClosed), this);
	using FunctionType = decltype(shareCommentClosed(text, layer))(*)(LevelBrowserLayer*, gd::string, ShareCommentLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f646c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, text, layer);
}

auto LevelBrowserLayer::setTextPopupClosed(SetTextPopup* popup, gd::string text) -> decltype(setTextPopupClosed(popup, text)) {
	auto self = addresser::thunkAdjust(Resolve<SetTextPopup*, gd::string>::func(&LevelBrowserLayer::setTextPopupClosed), this);
	using FunctionType = decltype(setTextPopupClosed(popup, text))(*)(LevelBrowserLayer*, SetTextPopup*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f6538, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, popup, text);
}

auto LevelBrowserLayer::FLAlert_Clicked(FLAlertLayer* layer, bool btn2) -> decltype(FLAlert_Clicked(layer, btn2)) {
	auto self = addresser::thunkAdjust(Resolve<FLAlertLayer*, bool>::func(&LevelBrowserLayer::FLAlert_Clicked), this);
	using FunctionType = decltype(FLAlert_Clicked(layer, btn2))(*)(LevelBrowserLayer*, FLAlertLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f66dc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer, btn2);
}

auto LevelBrowserLayer::setIDPopupClosed(SetIDPopup* popup, int value) -> decltype(setIDPopupClosed(popup, value)) {
	auto self = addresser::thunkAdjust(Resolve<SetIDPopup*, int>::func(&LevelBrowserLayer::setIDPopupClosed), this);
	using FunctionType = decltype(setIDPopupClosed(popup, value))(*)(LevelBrowserLayer*, SetIDPopup*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f5f54, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, popup, value);
}

auto LevelBrowserLayer::updateResultArray(cocos2d::CCArray* results) -> decltype(updateResultArray(results)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCArray*>::func(&LevelBrowserLayer::updateResultArray), this);
	using FunctionType = decltype(updateResultArray(results))(*)(LevelBrowserLayer*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f6e5c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, results);
}

auto LevelBrowserLayer::cellPerformedAction(TableViewCell* cell, int listType, CellAction action, cocos2d::CCNode* parent) -> decltype(cellPerformedAction(cell, listType, action, parent)) {
	auto self = addresser::thunkAdjust(Resolve<TableViewCell*, int, CellAction, cocos2d::CCNode*>::func(&LevelBrowserLayer::cellPerformedAction), this);
	using FunctionType = decltype(cellPerformedAction(cell, listType, action, parent))(*)(LevelBrowserLayer*, TableViewCell*, int, CellAction, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f6c24, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, cell, listType, action, parent);
}

auto LevelBrowserLayer::createNewLevel(cocos2d::CCObject* sender) -> decltype(createNewLevel(sender)) {
	using FunctionType = decltype(createNewLevel(sender))(*)(LevelBrowserLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f63f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelBrowserLayer::createNewList(cocos2d::CCObject* sender) -> decltype(createNewList(sender)) {
	using FunctionType = decltype(createNewList(sender))(*)(LevelBrowserLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f6280, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelBrowserLayer::createNewSmartTemplate(cocos2d::CCObject* sender) -> decltype(createNewSmartTemplate(sender)) {
	using FunctionType = decltype(createNewSmartTemplate(sender))(*)(LevelBrowserLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f6218, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelBrowserLayer::deleteSelected() -> decltype(deleteSelected()) {
	using FunctionType = decltype(deleteSelected())(*)(LevelBrowserLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f65dc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelBrowserLayer::exitLayer(cocos2d::CCObject* sender) -> decltype(exitLayer(sender)) {
	using FunctionType = decltype(exitLayer(sender))(*)(LevelBrowserLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f60d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelBrowserLayer::getItemsMatchingSearch(cocos2d::CCArray* items, gd::string query, GJSearchObject* object) -> decltype(getItemsMatchingSearch(items, query, object)) {
	using FunctionType = decltype(getItemsMatchingSearch(items, query, object))(*)(LevelBrowserLayer*, cocos2d::CCArray*, gd::string, GJSearchObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f4a48, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, items, query, object);
}

auto LevelBrowserLayer::getSearchTitle() -> decltype(getSearchTitle()) {
	using FunctionType = decltype(getSearchTitle())(*)(LevelBrowserLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f50a4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelBrowserLayer::init(GJSearchObject* object) -> decltype(init(object)) {
	using FunctionType = decltype(init(object))(*)(LevelBrowserLayer*, GJSearchObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f04ac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto LevelBrowserLayer::isCorrect(char const* key) -> decltype(isCorrect(key)) {
	using FunctionType = decltype(isCorrect(key))(*)(LevelBrowserLayer*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f4890, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto LevelBrowserLayer::loadPage(GJSearchObject* object) -> decltype(loadPage(object)) {
	using FunctionType = decltype(loadPage(object))(*)(LevelBrowserLayer*, GJSearchObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f38b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto LevelBrowserLayer::onClearSearch(cocos2d::CCObject* sender) -> decltype(onClearSearch(sender)) {
	using FunctionType = decltype(onClearSearch(sender))(*)(LevelBrowserLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f3834, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelBrowserLayer::onDeleteAll(cocos2d::CCObject* sender) -> decltype(onDeleteAll(sender)) {
	using FunctionType = decltype(onDeleteAll(sender))(*)(LevelBrowserLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f2b2c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelBrowserLayer::onDeleteSelected(cocos2d::CCObject* sender) -> decltype(onDeleteSelected(sender)) {
	using FunctionType = decltype(onDeleteSelected(sender))(*)(LevelBrowserLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f21c4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelBrowserLayer::onFavorites(cocos2d::CCObject* sender) -> decltype(onFavorites(sender)) {
	using FunctionType = decltype(onFavorites(sender))(*)(LevelBrowserLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f2e14, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelBrowserLayer::onGoToFolder(cocos2d::CCObject* sender) -> decltype(onGoToFolder(sender)) {
	using FunctionType = decltype(onGoToFolder(sender))(*)(LevelBrowserLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f3478, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelBrowserLayer::onGoToLastPage(cocos2d::CCObject* sender) -> decltype(onGoToLastPage(sender)) {
	using FunctionType = decltype(onGoToLastPage(sender))(*)(LevelBrowserLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f3540, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelBrowserLayer::onGoToPage(cocos2d::CCObject* sender) -> decltype(onGoToPage(sender)) {
	using FunctionType = decltype(onGoToPage(sender))(*)(LevelBrowserLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f2094, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelBrowserLayer::onHelp(cocos2d::CCObject* sender) -> decltype(onHelp(sender)) {
	using FunctionType = decltype(onHelp(sender))(*)(LevelBrowserLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f6214, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelBrowserLayer::onInfo(cocos2d::CCObject* sender) -> decltype(onInfo(sender)) {
	using FunctionType = decltype(onInfo(sender))(*)(LevelBrowserLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f3060, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelBrowserLayer::onLocalMode(cocos2d::CCObject* sender) -> decltype(onLocalMode(sender)) {
	using FunctionType = decltype(onLocalMode(sender))(*)(LevelBrowserLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f28f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelBrowserLayer::onMyOnlineLevels(cocos2d::CCObject* sender) -> decltype(onMyOnlineLevels(sender)) {
	using FunctionType = decltype(onMyOnlineLevels(sender))(*)(LevelBrowserLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f2638, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelBrowserLayer::onNew(cocos2d::CCObject* sender) -> decltype(onNew(sender)) {
	using FunctionType = decltype(onNew(sender))(*)(LevelBrowserLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f253c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelBrowserLayer::onNextPage(cocos2d::CCObject* sender) -> decltype(onNextPage(sender)) {
	using FunctionType = decltype(onNextPage(sender))(*)(LevelBrowserLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f1f54, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelBrowserLayer::onPrevPage(cocos2d::CCObject* sender) -> decltype(onPrevPage(sender)) {
	using FunctionType = decltype(onPrevPage(sender))(*)(LevelBrowserLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f1f20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelBrowserLayer::onRefresh(cocos2d::CCObject* sender) -> decltype(onRefresh(sender)) {
	using FunctionType = decltype(onRefresh(sender))(*)(LevelBrowserLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f2f2c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelBrowserLayer::onRemoveAllFavorites(cocos2d::CCObject* sender) -> decltype(onRemoveAllFavorites(sender)) {
	using FunctionType = decltype(onRemoveAllFavorites(sender))(*)(LevelBrowserLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f29cc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelBrowserLayer::onSaved(cocos2d::CCObject* sender) -> decltype(onSaved(sender)) {
	using FunctionType = decltype(onSaved(sender))(*)(LevelBrowserLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f2cfc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelBrowserLayer::onSavedMode(cocos2d::CCObject* sender) -> decltype(onSavedMode(sender)) {
	using FunctionType = decltype(onSavedMode(sender))(*)(LevelBrowserLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f2c24, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelBrowserLayer::onSearch(cocos2d::CCObject* sender) -> decltype(onSearch(sender)) {
	using FunctionType = decltype(onSearch(sender))(*)(LevelBrowserLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f3578, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelBrowserLayer::onToggleAllObjects(cocos2d::CCObject* sender) -> decltype(onToggleAllObjects(sender)) {
	using FunctionType = decltype(onToggleAllObjects(sender))(*)(LevelBrowserLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f24b4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelBrowserLayer::reloadAllObjects() -> decltype(reloadAllObjects()) {
	using FunctionType = decltype(reloadAllObjects())(*)(LevelBrowserLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f66d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelBrowserLayer::setSearchObject(GJSearchObject* object) -> decltype(setSearchObject(object)) {
	using FunctionType = decltype(setSearchObject(object))(*)(LevelBrowserLayer*, GJSearchObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f1ed8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto LevelBrowserLayer::setupLevelBrowser(cocos2d::CCArray* items) -> decltype(setupLevelBrowser(items)) {
	using FunctionType = decltype(setupLevelBrowser(items))(*)(LevelBrowserLayer*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f4e04, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, items);
}

auto LevelBrowserLayer::show() -> decltype(show()) {
	using FunctionType = decltype(show())(*)(LevelBrowserLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f6db0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelBrowserLayer::updateLevelsLabel() -> decltype(updateLevelsLabel()) {
	using FunctionType = decltype(updateLevelsLabel())(*)(LevelBrowserLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f5ebc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelBrowserLayer::updatePageLabel() -> decltype(updatePageLabel()) {
	using FunctionType = decltype(updatePageLabel())(*)(LevelBrowserLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f1f88, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
