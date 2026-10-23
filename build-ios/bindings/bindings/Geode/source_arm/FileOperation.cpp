
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/FileOperation.hpp>
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

auto FileOperation::getFilePath() -> decltype(getFilePath()) {
	using FunctionType = decltype(getFilePath())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x549120, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto FileOperation::readFile() -> decltype(readFile()) {
	using FunctionType = decltype(readFile())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54912c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto FileOperation::saveFile() -> decltype(saveFile()) {
	using FunctionType = decltype(saveFile())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54908c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}
