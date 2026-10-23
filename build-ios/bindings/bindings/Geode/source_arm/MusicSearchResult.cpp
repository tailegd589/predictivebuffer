
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/MusicSearchResult.hpp>
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

MusicSearchResult::~MusicSearchResult() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(MusicSearchResult*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x4e2920, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) MusicSearchResult(geode::CutoffConstructor, sizeof(MusicSearchResult));
		geode::DestructorLock::addLock(this);
	}
}

auto MusicSearchResult::create(GJSongType songType) -> decltype(create(songType)) {
	using FunctionType = decltype(create(songType))(*)(GJSongType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e2a54, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(songType);
}

auto MusicSearchResult::updateObjects(AudioSortType type) -> decltype(updateObjects(type)) {
	auto self = addresser::thunkAdjust(Resolve<AudioSortType>::func(&MusicSearchResult::updateObjects), this);
	using FunctionType = decltype(updateObjects(type))(*)(MusicSearchResult*, AudioSortType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e3438, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, type);
}

auto MusicSearchResult::stateChanged(OptionsObject* object) -> decltype(stateChanged(object)) {
	auto self = addresser::thunkAdjust(Resolve<OptionsObject*>::func(&MusicSearchResult::stateChanged), this);
	using FunctionType = decltype(stateChanged(object))(*)(MusicSearchResult*, OptionsObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e3408, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, object);
}

auto MusicSearchResult::applyArtistFilters(cocos2d::CCArray* objects) -> decltype(applyArtistFilters(objects)) {
	using FunctionType = decltype(applyArtistFilters(objects))(*)(MusicSearchResult*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e2ebc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objects);
}

auto MusicSearchResult::applyTagFilters(cocos2d::CCArray* objects) -> decltype(applyTagFilters(objects)) {
	using FunctionType = decltype(applyTagFilters(objects))(*)(MusicSearchResult*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e2cf4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objects);
}

auto MusicSearchResult::createArtistFilterObjects() -> decltype(createArtistFilterObjects()) {
	using FunctionType = decltype(createArtistFilterObjects())(*)(MusicSearchResult*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e2be4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto MusicSearchResult::createTagFilterObjects() -> decltype(createTagFilterObjects()) {
	using FunctionType = decltype(createTagFilterObjects())(*)(MusicSearchResult*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e2ad4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto MusicSearchResult::getFilesMatchingSearch(cocos2d::CCArray* objects, gd::string query) -> decltype(getFilesMatchingSearch(objects, query)) {
	using FunctionType = decltype(getFilesMatchingSearch(objects, query))(*)(MusicSearchResult*, cocos2d::CCArray*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e36d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objects, query);
}

auto MusicSearchResult::init(GJSongType songType) -> decltype(init(songType)) {
	using FunctionType = decltype(init(songType))(*)(MusicSearchResult*, GJSongType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e2ac8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, songType);
}

auto MusicSearchResult::updateFutureCount(cocos2d::CCArray* objects, cocos2d::CCArray* allObjects) -> decltype(updateFutureCount(objects, allObjects)) {
	using FunctionType = decltype(updateFutureCount(objects, allObjects))(*)(MusicSearchResult*, cocos2d::CCArray*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e3068, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objects, allObjects);
}

auto MusicSearchResult::updateObjects() -> decltype(updateObjects()) {
	using FunctionType = decltype(updateObjects())(*)(MusicSearchResult*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e3428, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
