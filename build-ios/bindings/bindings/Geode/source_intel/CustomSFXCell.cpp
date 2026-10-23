
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/CustomSFXCell.hpp>
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

CustomSFXCell::CustomSFXCell(char const* identifier, float width, float height) : CustomSFXCell(geode::CutoffConstructor, sizeof(CustomSFXCell)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	CustomSFXCell::~CustomSFXCell();

	using FunctionType = void(*)(CustomSFXCell*, char const*, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x254160, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this, identifier, width, height);
}

auto CustomSFXCell::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CustomSFXCell::init), this);
	using FunctionType = decltype(init())(*)(CustomSFXCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2541f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CustomSFXCell::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CustomSFXCell::draw), this);
	using FunctionType = decltype(draw())(*)(CustomSFXCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2542f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CustomSFXCell::sfxObjectSelected(SFXInfoObject* object) -> decltype(sfxObjectSelected(object)) {
	auto self = addresser::thunkAdjust(Resolve<SFXInfoObject*>::func(&CustomSFXCell::sfxObjectSelected), this);
	using FunctionType = decltype(sfxObjectSelected(object))(*)(CustomSFXCell*, SFXInfoObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x254210, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, object);
}

auto CustomSFXCell::getActiveSFXID() -> decltype(getActiveSFXID()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CustomSFXCell::getActiveSFXID), this);
	using FunctionType = decltype(getActiveSFXID())(*)(CustomSFXCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x254290, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CustomSFXCell::loadFromObject(SFXInfoObject* object) -> decltype(loadFromObject(object)) {
	using FunctionType = decltype(loadFromObject(object))(*)(CustomSFXCell*, SFXInfoObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2445a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto CustomSFXCell::shouldReload() -> decltype(shouldReload()) {
	using FunctionType = decltype(shouldReload())(*)(CustomSFXCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x24e7f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CustomSFXCell::updateBGColor(int index) -> decltype(updateBGColor(index)) {
	using FunctionType = decltype(updateBGColor(index))(*)(CustomSFXCell*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x244680, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}
