
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/LevelSearchLayer.hpp>
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

LevelSearchLayer::~LevelSearchLayer() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(LevelSearchLayer*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x6274d0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) LevelSearchLayer(geode::CutoffConstructor, sizeof(LevelSearchLayer));
		geode::DestructorLock::addLock(this);
	}
}

auto LevelSearchLayer::create(int type) -> decltype(create(type)) {
	using FunctionType = decltype(create(type))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x627970, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type);
}

auto LevelSearchLayer::scene(int type) -> decltype(scene(type)) {
	using FunctionType = decltype(scene(type))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x627830, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type);
}

auto LevelSearchLayer::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&LevelSearchLayer::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(LevelSearchLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62c9b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto LevelSearchLayer::textInputOpened(CCTextInputNode* node) -> decltype(textInputOpened(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&LevelSearchLayer::textInputOpened), this);
	using FunctionType = decltype(textInputOpened(node))(*)(LevelSearchLayer*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62bf90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto LevelSearchLayer::textInputClosed(CCTextInputNode* node) -> decltype(textInputClosed(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&LevelSearchLayer::textInputClosed), this);
	using FunctionType = decltype(textInputClosed(node))(*)(LevelSearchLayer*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62c060, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto LevelSearchLayer::textChanged(CCTextInputNode* node) -> decltype(textChanged(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&LevelSearchLayer::textChanged), this);
	using FunctionType = decltype(textChanged(node))(*)(LevelSearchLayer*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62c130, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto LevelSearchLayer::FLAlert_Clicked(FLAlertLayer* layer, bool btn2) -> decltype(FLAlert_Clicked(layer, btn2)) {
	auto self = addresser::thunkAdjust(Resolve<FLAlertLayer*, bool>::func(&LevelSearchLayer::FLAlert_Clicked), this);
	using FunctionType = decltype(FLAlert_Clicked(layer, btn2))(*)(LevelSearchLayer*, FLAlertLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62bf10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer, btn2);
}

auto LevelSearchLayer::demonFilterSelectClosed(int filter) -> decltype(demonFilterSelectClosed(filter)) {
	auto self = addresser::thunkAdjust(Resolve<int>::func(&LevelSearchLayer::demonFilterSelectClosed), this);
	using FunctionType = decltype(demonFilterSelectClosed(filter))(*)(LevelSearchLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62ba00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, filter);
}

auto LevelSearchLayer::checkDiff(int diff) -> decltype(checkDiff(diff)) {
	using FunctionType = decltype(checkDiff(diff))(*)(LevelSearchLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62c790, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, diff);
}

auto LevelSearchLayer::checkTime(int time) -> decltype(checkTime(time)) {
	using FunctionType = decltype(checkTime(time))(*)(LevelSearchLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62c890, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, time);
}

auto LevelSearchLayer::clearFilters() -> decltype(clearFilters()) {
	using FunctionType = decltype(clearFilters())(*)(LevelSearchLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62bc40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelSearchLayer::confirmClearFilters(cocos2d::CCObject* sender) -> decltype(confirmClearFilters(sender)) {
	using FunctionType = decltype(confirmClearFilters(sender))(*)(LevelSearchLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62a120, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelSearchLayer::getDiffKey(int diff) -> decltype(getDiffKey(diff)) {
	using FunctionType = decltype(getDiffKey(diff))(*)(LevelSearchLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62b890, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, diff);
}

auto LevelSearchLayer::getLevelLenKey() -> decltype(getLevelLenKey()) {
	using FunctionType = decltype(getLevelLenKey())(*)(LevelSearchLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62c6d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelSearchLayer::getSearchDiffKey() -> decltype(getSearchDiffKey()) {
	using FunctionType = decltype(getSearchDiffKey())(*)(LevelSearchLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62c5e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelSearchLayer::getSearchObject(SearchType type, gd::string query) -> decltype(getSearchObject(type, query)) {
	using FunctionType = decltype(getSearchObject(type, query))(*)(LevelSearchLayer*, SearchType, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62c220, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type, query);
}

auto LevelSearchLayer::getTimeKey(int time) -> decltype(getTimeKey(time)) {
	using FunctionType = decltype(getTimeKey(time))(*)(LevelSearchLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62c990, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, time);
}

auto LevelSearchLayer::init(int type) -> decltype(init(type)) {
	using FunctionType = decltype(init(type))(*)(LevelSearchLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x627a80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type);
}

auto LevelSearchLayer::onBack(cocos2d::CCObject* sender) -> decltype(onBack(sender)) {
	using FunctionType = decltype(onBack(sender))(*)(LevelSearchLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62b530, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelSearchLayer::onClearFreeSearch(cocos2d::CCObject* sender) -> decltype(onClearFreeSearch(sender)) {
	using FunctionType = decltype(onClearFreeSearch(sender))(*)(LevelSearchLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62a890, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelSearchLayer::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	using FunctionType = decltype(onClose(sender))(*)(LevelSearchLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62c200, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelSearchLayer::onFollowed(cocos2d::CCObject* sender) -> decltype(onFollowed(sender)) {
	using FunctionType = decltype(onFollowed(sender))(*)(LevelSearchLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62acb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelSearchLayer::onFriends(cocos2d::CCObject* sender) -> decltype(onFriends(sender)) {
	using FunctionType = decltype(onFriends(sender))(*)(LevelSearchLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62ad20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelSearchLayer::onLatestStars(cocos2d::CCObject* sender) -> decltype(onLatestStars(sender)) {
	using FunctionType = decltype(onLatestStars(sender))(*)(LevelSearchLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62ac40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelSearchLayer::onMagic(cocos2d::CCObject* sender) -> decltype(onMagic(sender)) {
	using FunctionType = decltype(onMagic(sender))(*)(LevelSearchLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62abd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelSearchLayer::onMoreOptions(cocos2d::CCObject* sender) -> decltype(onMoreOptions(sender)) {
	using FunctionType = decltype(onMoreOptions(sender))(*)(LevelSearchLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62a200, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelSearchLayer::onMostDownloaded(cocos2d::CCObject* sender) -> decltype(onMostDownloaded(sender)) {
	using FunctionType = decltype(onMostDownloaded(sender))(*)(LevelSearchLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62a9a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelSearchLayer::onMostLikes(cocos2d::CCObject* sender) -> decltype(onMostLikes(sender)) {
	using FunctionType = decltype(onMostLikes(sender))(*)(LevelSearchLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62aa10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelSearchLayer::onMostRecent(cocos2d::CCObject* sender) -> decltype(onMostRecent(sender)) {
	using FunctionType = decltype(onMostRecent(sender))(*)(LevelSearchLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62ab60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelSearchLayer::onSearch(cocos2d::CCObject* sender) -> decltype(onSearch(sender)) {
	using FunctionType = decltype(onSearch(sender))(*)(LevelSearchLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62a5f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelSearchLayer::onSearchMode(cocos2d::CCObject* sender) -> decltype(onSearchMode(sender)) {
	using FunctionType = decltype(onSearchMode(sender))(*)(LevelSearchLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62a220, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelSearchLayer::onSearchUser(cocos2d::CCObject* sender) -> decltype(onSearchUser(sender)) {
	using FunctionType = decltype(onSearchUser(sender))(*)(LevelSearchLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62a760, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelSearchLayer::onSpecialDemon(cocos2d::CCObject* sender) -> decltype(onSpecialDemon(sender)) {
	using FunctionType = decltype(onSpecialDemon(sender))(*)(LevelSearchLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62b2e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelSearchLayer::onStarAward(cocos2d::CCObject* sender) -> decltype(onStarAward(sender)) {
	using FunctionType = decltype(onStarAward(sender))(*)(LevelSearchLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62ad90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelSearchLayer::onSuggested(cocos2d::CCObject* sender) -> decltype(onSuggested(sender)) {
	using FunctionType = decltype(onSuggested(sender))(*)(LevelSearchLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62aa80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelSearchLayer::onTrending(cocos2d::CCObject* sender) -> decltype(onTrending(sender)) {
	using FunctionType = decltype(onTrending(sender))(*)(LevelSearchLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62aaf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelSearchLayer::toggleDifficulty(cocos2d::CCObject* sender) -> decltype(toggleDifficulty(sender)) {
	using FunctionType = decltype(toggleDifficulty(sender))(*)(LevelSearchLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62ae00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelSearchLayer::toggleDifficultyNum(int diff, bool enabled) -> decltype(toggleDifficultyNum(diff, enabled)) {
	using FunctionType = decltype(toggleDifficultyNum(diff, enabled))(*)(LevelSearchLayer*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62b580, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, diff, enabled);
}

auto LevelSearchLayer::toggleStar(cocos2d::CCObject* sender) -> decltype(toggleStar(sender)) {
	using FunctionType = decltype(toggleStar(sender))(*)(LevelSearchLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62b4b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelSearchLayer::toggleTime(cocos2d::CCObject* sender) -> decltype(toggleTime(sender)) {
	using FunctionType = decltype(toggleTime(sender))(*)(LevelSearchLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62b320, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelSearchLayer::toggleTimeNum(int time, bool enabled) -> decltype(toggleTimeNum(time, enabled)) {
	using FunctionType = decltype(toggleTimeNum(time, enabled))(*)(LevelSearchLayer*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62b700, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, time, enabled);
}

auto LevelSearchLayer::updateSearchLabel(char const* label) -> decltype(updateSearchLabel(label)) {
	using FunctionType = decltype(updateSearchLabel(label))(*)(LevelSearchLayer*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x62a270, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, label);
}
