
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GameLevelOptionsLayer.hpp>
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

auto GameLevelOptionsLayer::create(GJGameLevel* level) -> decltype(create(level)) {
	using FunctionType = decltype(create(level))(*)(GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x250308, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(level);
}

auto GameLevelOptionsLayer::setupOptions() -> decltype(setupOptions()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GameLevelOptionsLayer::setupOptions), this);
	using FunctionType = decltype(setupOptions())(*)(GameLevelOptionsLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x25052c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GameLevelOptionsLayer::didToggle(int tag) -> decltype(didToggle(tag)) {
	auto self = addresser::thunkAdjust(Resolve<int>::func(&GameLevelOptionsLayer::didToggle), this);
	using FunctionType = decltype(didToggle(tag))(*)(GameLevelOptionsLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x250590, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, tag);
}

auto GameLevelOptionsLayer::init(GJGameLevel* level) -> decltype(init(level)) {
	using FunctionType = decltype(init(level))(*)(GameLevelOptionsLayer*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2504c4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}
