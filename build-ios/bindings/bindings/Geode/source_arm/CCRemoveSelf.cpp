
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCRemoveSelf.hpp>
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

auto cocos2d::CCRemoveSelf::create(bool isNeedCleanUp) -> decltype(create(isNeedCleanUp)) {
	using FunctionType = decltype(create(isNeedCleanUp))(*)(bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b30a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(isNeedCleanUp);
}

auto cocos2d::CCRemoveSelf::copyWithZone(cocos2d::CCZone* pZone) -> decltype(copyWithZone(pZone)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCRemoveSelf::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(pZone))(*)(cocos2d::CCRemoveSelf*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b318c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, pZone);
}

auto cocos2d::CCRemoveSelf::update(float time) -> decltype(update(time)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCRemoveSelf::update), this);
	using FunctionType = decltype(update(time))(*)(cocos2d::CCRemoveSelf*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b3114, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, time);
}

auto cocos2d::CCRemoveSelf::reverse() -> decltype(reverse()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCRemoveSelf::reverse), this);
	using FunctionType = decltype(reverse())(*)(cocos2d::CCRemoveSelf*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b312c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCRemoveSelf::init(bool isNeedCleanUp) -> decltype(init(isNeedCleanUp)) {
	using FunctionType = decltype(init(isNeedCleanUp))(*)(cocos2d::CCRemoveSelf*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b3108, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, isNeedCleanUp);
}
