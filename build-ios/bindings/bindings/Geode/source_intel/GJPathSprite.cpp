
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJPathSprite.hpp>
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

auto GJPathSprite::create(int path) -> decltype(create(path)) {
	using FunctionType = decltype(create(path))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2fe910, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(path);
}

auto GJPathSprite::addRankLabel(int path) -> decltype(addRankLabel(path)) {
	using FunctionType = decltype(addRankLabel(path))(*)(GJPathSprite*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x302e90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, path);
}

auto GJPathSprite::addShardSprite() -> decltype(addShardSprite()) {
	using FunctionType = decltype(addShardSprite())(*)(GJPathSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x302960, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJPathSprite::changeToLockedArt() -> decltype(changeToLockedArt()) {
	using FunctionType = decltype(changeToLockedArt())(*)(GJPathSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x301910, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJPathSprite::init(int path) -> decltype(init(path)) {
	using FunctionType = decltype(init(path))(*)(GJPathSprite*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x302d70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, path);
}

auto GJPathSprite::updateState() -> decltype(updateState()) {
	using FunctionType = decltype(updateState())(*)(GJPathSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2fe9b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
