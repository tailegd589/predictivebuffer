
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/LevelOptionsLayer2.hpp>
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

auto LevelOptionsLayer2::create(LevelSettingsObject* object) -> decltype(create(object)) {
	using FunctionType = decltype(create(object))(*)(LevelSettingsObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x271930, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(object);
}

auto LevelOptionsLayer2::setupOptions() -> decltype(setupOptions()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&LevelOptionsLayer2::setupOptions), this);
	using FunctionType = decltype(setupOptions())(*)(LevelOptionsLayer2*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x271ea0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto LevelOptionsLayer2::init(LevelSettingsObject* object) -> decltype(init(object)) {
	using FunctionType = decltype(init(object))(*)(LevelOptionsLayer2*, LevelSettingsObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x271da0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}
