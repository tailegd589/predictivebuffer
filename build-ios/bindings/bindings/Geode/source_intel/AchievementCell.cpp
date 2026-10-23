
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/AchievementCell.hpp>
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

AchievementCell::AchievementCell(char const* identifier, float width, float height) : AchievementCell(geode::CutoffConstructor, sizeof(AchievementCell)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	AchievementCell::~AchievementCell();

	using FunctionType = void(*)(AchievementCell*, char const*, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x24e870, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this, identifier, width, height);
}

auto AchievementCell::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&AchievementCell::init), this);
	using FunctionType = decltype(init())(*)(AchievementCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x24e8e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto AchievementCell::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&AchievementCell::draw), this);
	using FunctionType = decltype(draw())(*)(AchievementCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x24e8f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto AchievementCell::loadFromDict(cocos2d::CCDictionary* dict) -> decltype(loadFromDict(dict)) {
	using FunctionType = decltype(loadFromDict(dict))(*)(AchievementCell*, cocos2d::CCDictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x242970, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dict);
}

auto AchievementCell::updateBGColor(int index) -> decltype(updateBGColor(index)) {
	using FunctionType = decltype(updateBGColor(index))(*)(AchievementCell*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x243dc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}
