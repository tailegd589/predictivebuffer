
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/LevelCell.hpp>
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

LevelCell::LevelCell(char const* identifier, float width, float height) : LevelCell(geode::CutoffConstructor, sizeof(LevelCell)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	LevelCell::~LevelCell();

	using FunctionType = void(*)(LevelCell*, char const*, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1f53dc, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this, identifier, width, height);
}

auto LevelCell::create(float width, float height) -> decltype(create(width, height)) {
	using FunctionType = decltype(create(width, height))(*)(float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1f52d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(width, height);
}

auto LevelCell::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&LevelCell::init), this);
	using FunctionType = decltype(init())(*)(LevelCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1f5460, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto LevelCell::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&LevelCell::draw), this);
	using FunctionType = decltype(draw())(*)(LevelCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1f87dc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto LevelCell::loadCustomLevelCell() -> decltype(loadCustomLevelCell()) {
	using FunctionType = decltype(loadCustomLevelCell())(*)(LevelCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1f5dbc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelCell::loadFromLevel(GJGameLevel* level) -> decltype(loadFromLevel(level)) {
	using FunctionType = decltype(loadFromLevel(level))(*)(LevelCell*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1eb578, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}

auto LevelCell::loadLocalLevelCell() -> decltype(loadLocalLevelCell()) {
	using FunctionType = decltype(loadLocalLevelCell())(*)(LevelCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1f547c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelCell::onClick(cocos2d::CCObject* sender) -> decltype(onClick(sender)) {
	using FunctionType = decltype(onClick(sender))(*)(LevelCell*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1f8638, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelCell::onToggle(cocos2d::CCObject* sender) -> decltype(onToggle(sender)) {
	using FunctionType = decltype(onToggle(sender))(*)(LevelCell*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1f8620, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelCell::onViewProfile(cocos2d::CCObject* sender) -> decltype(onViewProfile(sender)) {
	using FunctionType = decltype(onViewProfile(sender))(*)(LevelCell*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1f87a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelCell::updateBGColor(int index) -> decltype(updateBGColor(index)) {
	using FunctionType = decltype(updateBGColor(index))(*)(LevelCell*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1eb738, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}

auto LevelCell::updateCellMode(int mode) -> decltype(updateCellMode(mode)) {
	using FunctionType = decltype(updateCellMode(mode))(*)(LevelCell*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1f4f6c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, mode);
}

auto LevelCell::updateToggle() -> decltype(updateToggle()) {
	using FunctionType = decltype(updateToggle())(*)(LevelCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1f4f50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
