
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/LevelListCell.hpp>
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

LevelListCell::LevelListCell(char const* identifier, float width, float height) : LevelListCell(geode::CutoffConstructor, sizeof(LevelListCell)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	LevelListCell::~LevelListCell();

	using FunctionType = void(*)(LevelListCell*, char const*, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1fe728, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this, identifier, width, height);
}

LevelListCell::~LevelListCell() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(LevelListCell*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x1fe4b8, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) LevelListCell(geode::CutoffConstructor, sizeof(LevelListCell));
		geode::DestructorLock::addLock(this);
	}
}

auto LevelListCell::create(float width, float height) -> decltype(create(width, height)) {
	using FunctionType = decltype(create(width, height))(*)(float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1fe68c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(width, height);
}

auto LevelListCell::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&LevelListCell::init), this);
	using FunctionType = decltype(init())(*)(LevelListCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1fe770, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto LevelListCell::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&LevelListCell::draw), this);
	using FunctionType = decltype(draw())(*)(LevelListCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1fe888, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto LevelListCell::loadFromList(GJLevelList* list) -> decltype(loadFromList(list)) {
	using FunctionType = decltype(loadFromList(list))(*)(LevelListCell*, GJLevelList*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1ec324, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, list);
}

auto LevelListCell::onClick(cocos2d::CCObject* sender) -> decltype(onClick(sender)) {
	using FunctionType = decltype(onClick(sender))(*)(LevelListCell*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1fe778, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelListCell::onListInfo(cocos2d::CCObject* sender) -> decltype(onListInfo(sender)) {
	using FunctionType = decltype(onListInfo(sender))(*)(LevelListCell*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1fe878, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelListCell::onViewProfile(cocos2d::CCObject* sender) -> decltype(onViewProfile(sender)) {
	using FunctionType = decltype(onViewProfile(sender))(*)(LevelListCell*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1fe844, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelListCell::updateBGColor(int index) -> decltype(updateBGColor(index)) {
	using FunctionType = decltype(updateBGColor(index))(*)(LevelListCell*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1ed87c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}
