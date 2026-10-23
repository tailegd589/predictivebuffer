
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJSearchObject.hpp>
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

auto GJSearchObject::create(SearchType searchType) -> decltype(create(searchType)) {
	using FunctionType = decltype(create(searchType))(*)(SearchType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b00a4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(searchType);
}

auto GJSearchObject::create(SearchType searchType, gd::string searchQuery) -> decltype(create(searchType, searchQuery)) {
	using FunctionType = decltype(create(searchType, searchQuery))(*)(SearchType, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b0110, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(searchType, searchQuery);
}

auto GJSearchObject::create(SearchType searchType, gd::string searchQuery, gd::string difficulty, gd::string length, int page, bool star, bool uncompleted, bool featured, int songID, bool original, bool twoPlayer, bool customSong, bool songFilter, bool noStar, bool coins, bool epic, bool legendary, bool mythic, bool onlyCompleted, int demonFilter, int folder, int searchMode) -> decltype(create(searchType, searchQuery, difficulty, length, page, star, uncompleted, featured, songID, original, twoPlayer, customSong, songFilter, noStar, coins, epic, legendary, mythic, onlyCompleted, demonFilter, folder, searchMode)) {
	using FunctionType = decltype(create(searchType, searchQuery, difficulty, length, page, star, uncompleted, featured, songID, original, twoPlayer, customSong, songFilter, noStar, coins, epic, legendary, mythic, onlyCompleted, demonFilter, folder, searchMode))(*)(SearchType, gd::string, gd::string, gd::string, int, bool, bool, bool, int, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, int, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4afdfc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(searchType, searchQuery, difficulty, length, page, star, uncompleted, featured, songID, original, twoPlayer, customSong, songFilter, noStar, coins, epic, legendary, mythic, onlyCompleted, demonFilter, folder, searchMode);
}

auto GJSearchObject::createFromKey(char const* key) -> decltype(createFromKey(key)) {
	using FunctionType = decltype(createFromKey(key))(*)(char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x48bd08, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(key);
}

auto GJSearchObject::getSearchKey(SearchType searchType, gd::string searchQuery, gd::string difficulty, gd::string length, int page, bool star, bool uncompleted, bool featured, int songID, bool original, bool twoPlayer, bool customSong, bool songFilter, bool noStar, bool coins, bool epic, bool legendary, bool mythic, bool onlyCompleted, int demonFilter, int folder, int searchMode) -> decltype(getSearchKey(searchType, searchQuery, difficulty, length, page, star, uncompleted, featured, songID, original, twoPlayer, customSong, songFilter, noStar, coins, epic, legendary, mythic, onlyCompleted, demonFilter, folder, searchMode)) {
	using FunctionType = decltype(getSearchKey(searchType, searchQuery, difficulty, length, page, star, uncompleted, featured, songID, original, twoPlayer, customSong, songFilter, noStar, coins, epic, legendary, mythic, onlyCompleted, demonFilter, folder, searchMode))(*)(SearchType, gd::string, gd::string, gd::string, int, bool, bool, bool, int, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, int, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b0338, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(searchType, searchQuery, difficulty, length, page, star, uncompleted, featured, songID, original, twoPlayer, customSong, songFilter, noStar, coins, epic, legendary, mythic, onlyCompleted, demonFilter, folder, searchMode);
}

auto GJSearchObject::getKey() -> decltype(getKey()) {
	using FunctionType = decltype(getKey())(*)(GJSearchObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x49286c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJSearchObject::getNextPageKey() -> decltype(getNextPageKey()) {
	using FunctionType = decltype(getNextPageKey())(*)(GJSearchObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b0430, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJSearchObject::getNextPageObject() -> decltype(getNextPageObject()) {
	using FunctionType = decltype(getNextPageObject())(*)(GJSearchObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b06a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJSearchObject::getPageObject(int page) -> decltype(getPageObject(page)) {
	using FunctionType = decltype(getPageObject(page))(*)(GJSearchObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b06ac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page);
}

auto GJSearchObject::getPrevPageObject() -> decltype(getPrevPageObject()) {
	using FunctionType = decltype(getPrevPageObject())(*)(GJSearchObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b08a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJSearchObject::init(SearchType searchType, gd::string searchQuery, gd::string difficulty, gd::string length, int page, bool star, bool uncompleted, bool featured, int songID, bool original, bool twoPlayer, bool customSong, bool songFilter, bool noStar, bool coins, bool epic, bool legendary, bool mythic, bool onlyCompleted, int demonFilter, int folder, int searchMode) -> decltype(init(searchType, searchQuery, difficulty, length, page, star, uncompleted, featured, songID, original, twoPlayer, customSong, songFilter, noStar, coins, epic, legendary, mythic, onlyCompleted, demonFilter, folder, searchMode)) {
	using FunctionType = decltype(init(searchType, searchQuery, difficulty, length, page, star, uncompleted, featured, songID, original, twoPlayer, customSong, songFilter, noStar, coins, epic, legendary, mythic, onlyCompleted, demonFilter, folder, searchMode))(*)(GJSearchObject*, SearchType, gd::string, gd::string, gd::string, int, bool, bool, bool, int, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, int, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b01f8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, searchType, searchQuery, difficulty, length, page, star, uncompleted, featured, songID, original, twoPlayer, customSong, songFilter, noStar, coins, epic, legendary, mythic, onlyCompleted, demonFilter, folder, searchMode);
}

auto GJSearchObject::isLevelSearchObject() -> decltype(isLevelSearchObject()) {
	using FunctionType = decltype(isLevelSearchObject())(*)(GJSearchObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b08b4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
