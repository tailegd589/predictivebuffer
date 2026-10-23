
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJLocalLevelScoreCell.hpp>
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

GJLocalLevelScoreCell::GJLocalLevelScoreCell(char const* identifier, float width, float height) : GJLocalLevelScoreCell(geode::CutoffConstructor, sizeof(GJLocalLevelScoreCell)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	GJLocalLevelScoreCell::~GJLocalLevelScoreCell();

	using FunctionType = void(*)(GJLocalLevelScoreCell*, char const*, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x255bd0, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this, identifier, width, height);
}

auto GJLocalLevelScoreCell::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJLocalLevelScoreCell::init), this);
	using FunctionType = decltype(init())(*)(GJLocalLevelScoreCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x255c40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJLocalLevelScoreCell::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJLocalLevelScoreCell::draw), this);
	using FunctionType = decltype(draw())(*)(GJLocalLevelScoreCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x255c60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJLocalLevelScoreCell::loadFromScore(GJLocalScore* score) -> decltype(loadFromScore(score)) {
	using FunctionType = decltype(loadFromScore(score))(*)(GJLocalLevelScoreCell*, GJLocalScore*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x24b700, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, score);
}

auto GJLocalLevelScoreCell::updateBGColor(int index) -> decltype(updateBGColor(index)) {
	using FunctionType = decltype(updateBGColor(index))(*)(GJLocalLevelScoreCell*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x24b930, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}
