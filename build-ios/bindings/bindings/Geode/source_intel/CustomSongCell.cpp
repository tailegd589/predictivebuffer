
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/CustomSongCell.hpp>
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

CustomSongCell::CustomSongCell(char const* identifier, float width, float height) : CustomSongCell(geode::CutoffConstructor, sizeof(CustomSongCell)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	CustomSongCell::~CustomSongCell();

	using FunctionType = void(*)(CustomSongCell*, char const*, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x253d70, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this, identifier, width, height);
}

auto CustomSongCell::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CustomSongCell::init), this);
	using FunctionType = decltype(init())(*)(CustomSongCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x253df0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CustomSongCell::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CustomSongCell::draw), this);
	using FunctionType = decltype(draw())(*)(CustomSongCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x254000, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CustomSongCell::songIDChanged(int id) -> decltype(songIDChanged(id)) {
	auto self = addresser::thunkAdjust(Resolve<int>::func(&CustomSongCell::songIDChanged), this);
	using FunctionType = decltype(songIDChanged(id))(*)(CustomSongCell*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x253ee0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, id);
}

auto CustomSongCell::getActiveSongID() -> decltype(getActiveSongID()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CustomSongCell::getActiveSongID), this);
	using FunctionType = decltype(getActiveSongID())(*)(CustomSongCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x253f60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CustomSongCell::getSongFileName() -> decltype(getSongFileName()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CustomSongCell::getSongFileName), this);
	using FunctionType = decltype(getSongFileName())(*)(CustomSongCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x253fc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CustomSongCell::getLevelSettings() -> decltype(getLevelSettings()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CustomSongCell::getLevelSettings), this);
	using FunctionType = decltype(getLevelSettings())(*)(CustomSongCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x253fe0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CustomSongCell::loadFromObject(SongInfoObject* object) -> decltype(loadFromObject(object)) {
	using FunctionType = decltype(loadFromObject(object))(*)(CustomSongCell*, SongInfoObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x243e10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto CustomSongCell::onDelete(cocos2d::CCObject* sender) -> decltype(onDelete(sender)) {
	using FunctionType = decltype(onDelete(sender))(*)(CustomSongCell*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x253e10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto CustomSongCell::shouldReload() -> decltype(shouldReload()) {
	using FunctionType = decltype(shouldReload())(*)(CustomSongCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x24e830, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CustomSongCell::updateBGColor(int index) -> decltype(updateBGColor(index)) {
	using FunctionType = decltype(updateBGColor(index))(*)(CustomSongCell*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x243fb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}
