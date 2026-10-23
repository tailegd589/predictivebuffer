
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/ArtistCell.hpp>
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

ArtistCell::ArtistCell(char const* identifier, float width, float height) : ArtistCell(geode::CutoffConstructor, sizeof(ArtistCell)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	ArtistCell::~ArtistCell();

	using FunctionType = void(*)(ArtistCell*, char const*, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2546e0, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this, identifier, width, height);
}

auto ArtistCell::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&ArtistCell::init), this);
	using FunctionType = decltype(init())(*)(ArtistCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x254750, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto ArtistCell::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&ArtistCell::draw), this);
	using FunctionType = decltype(draw())(*)(ArtistCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x254910, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto ArtistCell::loadFromObject(SongInfoObject* object) -> decltype(loadFromObject(object)) {
	using FunctionType = decltype(loadFromObject(object))(*)(ArtistCell*, SongInfoObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2471e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto ArtistCell::onNewgrounds(cocos2d::CCObject* sender) -> decltype(onNewgrounds(sender)) {
	using FunctionType = decltype(onNewgrounds(sender))(*)(ArtistCell*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x254770, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto ArtistCell::onYouTube(cocos2d::CCObject* sender) -> decltype(onYouTube(sender)) {
	using FunctionType = decltype(onYouTube(sender))(*)(ArtistCell*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x254840, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto ArtistCell::updateBGColor(int index) -> decltype(updateBGColor(index)) {
	using FunctionType = decltype(updateBGColor(index))(*)(ArtistCell*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x247530, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}
