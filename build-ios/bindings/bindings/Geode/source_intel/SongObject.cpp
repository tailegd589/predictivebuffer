
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/SongObject.hpp>
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

auto SongObject::create(int audioID) -> decltype(create(audioID)) {
	using FunctionType = decltype(create(audioID))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x253a50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(audioID);
}

auto SongObject::init(int audioID) -> decltype(init(audioID)) {
	using FunctionType = decltype(init(audioID))(*)(SongObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x253ac0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, audioID);
}
