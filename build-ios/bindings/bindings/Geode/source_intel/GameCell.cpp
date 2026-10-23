
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GameCell.hpp>
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

GameCell::GameCell(char const* identifier, float width, float height) : GameCell(geode::CutoffConstructor, sizeof(GameCell)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	GameCell::~GameCell();

	using FunctionType = void(*)(GameCell*, char const*, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30d3f0, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this, identifier, width, height);
}

auto GameCell::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GameCell::init), this);
	using FunctionType = decltype(init())(*)(GameCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30d470, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GameCell::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GameCell::draw), this);
	using FunctionType = decltype(draw())(*)(GameCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30d530, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GameCell::loadFromString(gd::string str) -> decltype(loadFromString(str)) {
	using FunctionType = decltype(loadFromString(str))(*)(GameCell*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30cf40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, str);
}

auto GameCell::onTouch(cocos2d::CCObject* sender) -> decltype(onTouch(sender)) {
	using FunctionType = decltype(onTouch(sender))(*)(GameCell*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30d490, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GameCell::updateBGColor(int index) -> decltype(updateBGColor(index)) {
	using FunctionType = decltype(updateBGColor(index))(*)(GameCell*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30d4d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}
