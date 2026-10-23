
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/StatsCell.hpp>
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

StatsCell::StatsCell(char const* identifier, float width, float height) : StatsCell(geode::CutoffConstructor, sizeof(StatsCell)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	StatsCell::~StatsCell();

	using FunctionType = void(*)(StatsCell*, char const*, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x252e40, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this, identifier, width, height);
}

auto StatsCell::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&StatsCell::init), this);
	using FunctionType = decltype(init())(*)(StatsCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x252eb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto StatsCell::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&StatsCell::draw), this);
	using FunctionType = decltype(draw())(*)(StatsCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x253980, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto StatsCell::getTitleFromKey(char const* key) -> decltype(getTitleFromKey(key)) {
	using FunctionType = decltype(getTitleFromKey(key))(*)(StatsCell*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x252ec0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto StatsCell::loadFromObject(StatsObject* object) -> decltype(loadFromObject(object)) {
	using FunctionType = decltype(loadFromObject(object))(*)(StatsCell*, StatsObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x246aa0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto StatsCell::updateBGColor(int index) -> decltype(updateBGColor(index)) {
	using FunctionType = decltype(updateBGColor(index))(*)(StatsCell*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x246d50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}
