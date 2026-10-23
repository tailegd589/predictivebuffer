
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCTableViewCell.hpp>
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

auto cocos2d::extension::CCTableViewCell::setObjectID(unsigned int p0) -> decltype(setObjectID(p0)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned int>::func(&cocos2d::extension::CCTableViewCell::setObjectID), this);
	using FunctionType = decltype(setObjectID(p0))(*)(cocos2d::extension::CCTableViewCell*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x437890, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCTableViewCell::getObjectID() -> decltype(getObjectID()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCTableViewCell::getObjectID), this);
	using FunctionType = decltype(getObjectID())(*)(cocos2d::extension::CCTableViewCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4378b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCTableViewCell::getIdx() -> decltype(getIdx()) {
	using FunctionType = decltype(getIdx())(*)(cocos2d::extension::CCTableViewCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4378d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::extension::CCTableViewCell::reset() -> decltype(reset()) {
	using FunctionType = decltype(reset())(*)(cocos2d::extension::CCTableViewCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x437880, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::extension::CCTableViewCell::setIdx(unsigned int p0) -> decltype(setIdx(p0)) {
	using FunctionType = decltype(setIdx(p0))(*)(cocos2d::extension::CCTableViewCell*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4378e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
