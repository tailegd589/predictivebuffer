
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCEaseSineInOut.hpp>
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

auto cocos2d::CCEaseSineInOut::create(cocos2d::CCActionInterval* pAction) -> decltype(create(pAction)) {
	using FunctionType = decltype(create(pAction))(*)(cocos2d::CCActionInterval*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x515a40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(pAction);
}

auto cocos2d::CCEaseSineInOut::copyWithZone(cocos2d::CCZone* pZone) -> decltype(copyWithZone(pZone)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCEaseSineInOut::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(pZone))(*)(cocos2d::CCEaseSineInOut*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x515ae0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, pZone);
}

auto cocos2d::CCEaseSineInOut::update(float time) -> decltype(update(time)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCEaseSineInOut::update), this);
	using FunctionType = decltype(update(time))(*)(cocos2d::CCEaseSineInOut*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x515be0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, time);
}

auto cocos2d::CCEaseSineInOut::reverse() -> decltype(reverse()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCEaseSineInOut::reverse), this);
	using FunctionType = decltype(reverse())(*)(cocos2d::CCEaseSineInOut*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x515c20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}
