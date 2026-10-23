
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJDifficultySprite.hpp>
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

auto GJDifficultySprite::create(int difficulty, GJDifficultyName name) -> decltype(create(difficulty, name)) {
	using FunctionType = decltype(create(difficulty, name))(*)(int, GJDifficultyName);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2b6a30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(difficulty, name);
}

auto GJDifficultySprite::getDifficultyFrame(int difficulty, GJDifficultyName name) -> decltype(getDifficultyFrame(difficulty, name)) {
	using FunctionType = decltype(getDifficultyFrame(difficulty, name))(*)(int, GJDifficultyName);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2b6b80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(difficulty, name);
}

auto GJDifficultySprite::init(int difficulty, GJDifficultyName name) -> decltype(init(difficulty, name)) {
	using FunctionType = decltype(init(difficulty, name))(*)(GJDifficultySprite*, int, GJDifficultyName);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2b6b10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, difficulty, name);
}

auto GJDifficultySprite::updateDifficultyFrame(int difficulty, GJDifficultyName name) -> decltype(updateDifficultyFrame(difficulty, name)) {
	using FunctionType = decltype(updateDifficultyFrame(difficulty, name))(*)(GJDifficultySprite*, int, GJDifficultyName);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2b6cb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, difficulty, name);
}

auto GJDifficultySprite::updateFeatureState(GJFeatureState state) -> decltype(updateFeatureState(state)) {
	using FunctionType = decltype(updateFeatureState(state))(*)(GJDifficultySprite*, GJFeatureState);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2b6e30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, state);
}

auto GJDifficultySprite::updateFeatureStateFromLevel(GJGameLevel* level) -> decltype(updateFeatureStateFromLevel(level)) {
	using FunctionType = decltype(updateFeatureStateFromLevel(level))(*)(GJDifficultySprite*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2b6de0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}
