
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCContentManager.hpp>
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

auto CCContentManager::sharedManager() -> decltype(sharedManager()) {
	using FunctionType = decltype(sharedManager())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1491c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto CCContentManager::addDict(char const* p0, bool p1) -> decltype(addDict(p0, p1)) {
	using FunctionType = decltype(addDict(p0, p1))(*)(CCContentManager*, char const*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x149324, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto CCContentManager::addDictDS(char const* p0) -> decltype(addDictDS(p0)) {
	using FunctionType = decltype(addDictDS(p0))(*)(CCContentManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1494d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto CCContentManager::clearCache() -> decltype(clearCache()) {
	using FunctionType = decltype(clearCache())(*)(CCContentManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1496c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CCContentManager::init() -> decltype(init()) {
	using FunctionType = decltype(init())(*)(CCContentManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x149240, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
