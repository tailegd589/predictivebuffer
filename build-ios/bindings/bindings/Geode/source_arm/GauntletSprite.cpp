
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GauntletSprite.hpp>
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

auto GauntletSprite::create(GauntletType type, bool locked) -> decltype(create(type, locked)) {
	using FunctionType = decltype(create(type, locked))(*)(GauntletType, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x31a5a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type, locked);
}

auto GauntletSprite::addLockedSprite() -> decltype(addLockedSprite()) {
	using FunctionType = decltype(addLockedSprite())(*)(GauntletSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x31afb8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GauntletSprite::addNormalSprite() -> decltype(addNormalSprite()) {
	using FunctionType = decltype(addNormalSprite())(*)(GauntletSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x31aebc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GauntletSprite::colorForType(GauntletType type) -> decltype(colorForType(type)) {
	using FunctionType = decltype(colorForType(type))(*)(GauntletSprite*, GauntletType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x31b284, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type);
}

auto GauntletSprite::init(GauntletType type, bool locked) -> decltype(init(type, locked)) {
	using FunctionType = decltype(init(type, locked))(*)(GauntletSprite*, GauntletType, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x31ae28, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type, locked);
}

auto GauntletSprite::luminanceForType(GauntletType type) -> decltype(luminanceForType(type)) {
	using FunctionType = decltype(luminanceForType(type))(*)(GauntletSprite*, GauntletType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x31b264, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type);
}

auto GauntletSprite::toggleLockedSprite(bool locked) -> decltype(toggleLockedSprite(locked)) {
	using FunctionType = decltype(toggleLockedSprite(locked))(*)(GauntletSprite*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x31ad54, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, locked);
}
