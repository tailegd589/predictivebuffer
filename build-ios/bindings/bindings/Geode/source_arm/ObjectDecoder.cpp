
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/ObjectDecoder.hpp>
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

auto ObjectDecoder::sharedDecoder() -> decltype(sharedDecoder()) {
	using FunctionType = decltype(sharedDecoder())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69aa80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto ObjectDecoder::getDecodedObject(int objectType, DS_Dictionary* data) -> decltype(getDecodedObject(objectType, data)) {
	using FunctionType = decltype(getDecodedObject(objectType, data))(*)(ObjectDecoder*, int, DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69aaf8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objectType, data);
}

auto ObjectDecoder::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&ObjectDecoder::init), this);
	using FunctionType = decltype(init())(*)(ObjectDecoder*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69aaf4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}
