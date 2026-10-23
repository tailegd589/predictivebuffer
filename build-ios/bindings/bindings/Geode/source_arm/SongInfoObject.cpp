
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/SongInfoObject.hpp>
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

auto SongInfoObject::create(cocos2d::CCDictionary* dict) -> decltype(create(dict)) {
	using FunctionType = decltype(create(dict))(*)(cocos2d::CCDictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4d740c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(dict);
}

auto SongInfoObject::create(int songID) -> decltype(create(songID)) {
	using FunctionType = decltype(create(songID))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e0cc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(songID);
}

auto SongInfoObject::create(int songID, gd::string songName, gd::string artistName, int artistID, float filesize, gd::string youtubeVideo, gd::string youtubeChannel, gd::string url, gd::string downloadLinkOverride, int nongType, gd::string extraArtistIDs, bool isNew, int libraryOrder, int priority) -> decltype(create(songID, songName, artistName, artistID, filesize, youtubeVideo, youtubeChannel, url, downloadLinkOverride, nongType, extraArtistIDs, isNew, libraryOrder, priority)) {
	using FunctionType = decltype(create(songID, songName, artistName, artistID, filesize, youtubeVideo, youtubeChannel, url, downloadLinkOverride, nongType, extraArtistIDs, isNew, libraryOrder, priority))(*)(int, gd::string, gd::string, int, float, gd::string, gd::string, gd::string, gd::string, int, gd::string, bool, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ddfe4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(songID, songName, artistName, artistID, filesize, youtubeVideo, youtubeChannel, url, downloadLinkOverride, nongType, extraArtistIDs, isNew, libraryOrder, priority);
}

auto SongInfoObject::createWithCoder(DS_Dictionary* dict) -> decltype(createWithCoder(dict)) {
	using FunctionType = decltype(createWithCoder(dict))(*)(DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e1260, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(dict);
}

auto SongInfoObject::encodeWithCoder(DS_Dictionary* dict) -> decltype(encodeWithCoder(dict)) {
	auto self = addresser::thunkAdjust(Resolve<DS_Dictionary*>::func(&SongInfoObject::encodeWithCoder), this);
	using FunctionType = decltype(encodeWithCoder(dict))(*)(SongInfoObject*, DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e1920, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, dict);
}

auto SongInfoObject::canEncode() -> decltype(canEncode()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SongInfoObject::canEncode), this);
	using FunctionType = decltype(canEncode())(*)(SongInfoObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e1ac0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SongInfoObject::addTags(gd::string tags) -> decltype(addTags(tags)) {
	using FunctionType = decltype(addTags(tags))(*)(SongInfoObject*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4de440, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, tags);
}

auto SongInfoObject::containsTag(int tag) -> decltype(containsTag(tag)) {
	using FunctionType = decltype(containsTag(tag))(*)(SongInfoObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4deb74, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, tag);
}

auto SongInfoObject::copyValues(SongInfoObject* object) -> decltype(copyValues(object)) {
	using FunctionType = decltype(copyValues(object))(*)(SongInfoObject*, SongInfoObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4d8128, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto SongInfoObject::getArtistNames(int unused) -> decltype(getArtistNames(unused)) {
	using FunctionType = decltype(getArtistNames(unused))(*)(SongInfoObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e1ac8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, unused);
}

auto SongInfoObject::getExtraArtistCount() -> decltype(getExtraArtistCount()) {
	using FunctionType = decltype(getExtraArtistCount())(*)(SongInfoObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e20a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SongInfoObject::getTagsString(bool shortTags) -> decltype(getTagsString(shortTags)) {
	using FunctionType = decltype(getTagsString(shortTags))(*)(SongInfoObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e21ac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, shortTags);
}

auto SongInfoObject::init(int songID, gd::string songName, gd::string artistName, int artistID, float filesize, gd::string youtubeVideo, gd::string youtubeChannel, gd::string url, gd::string downloadLinkOverride, int nongType, gd::string extraArtistIDs, bool isNew, int libraryOrder, int priority) -> decltype(init(songID, songName, artistName, artistID, filesize, youtubeVideo, youtubeChannel, url, downloadLinkOverride, nongType, extraArtistIDs, isNew, libraryOrder, priority)) {
	using FunctionType = decltype(init(songID, songName, artistName, artistID, filesize, youtubeVideo, youtubeChannel, url, downloadLinkOverride, nongType, extraArtistIDs, isNew, libraryOrder, priority))(*)(SongInfoObject*, int, gd::string, gd::string, int, float, gd::string, gd::string, gd::string, gd::string, int, gd::string, bool, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e0e50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, songID, songName, artistName, artistID, filesize, youtubeVideo, youtubeChannel, url, downloadLinkOverride, nongType, extraArtistIDs, isNew, libraryOrder, priority);
}

auto SongInfoObject::updateArtists(gd::string artists) -> decltype(updateArtists(artists)) {
	using FunctionType = decltype(updateArtists(artists))(*)(SongInfoObject*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e1090, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, artists);
}
