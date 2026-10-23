
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/EndPortalObject.hpp>
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

auto EndPortalObject::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3218d8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto EndPortalObject::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&EndPortalObject::init), this);
	using FunctionType = decltype(init())(*)(EndPortalObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x321974, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto EndPortalObject::setPosition(cocos2d::CCPoint const& position) -> decltype(setPosition(position)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCPoint const&>::func(&EndPortalObject::setPosition), this);
	using FunctionType = decltype(setPosition(position))(*)(EndPortalObject*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x321de4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, position);
}

auto EndPortalObject::setVisible(bool visible) -> decltype(setVisible(visible)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&EndPortalObject::setVisible), this);
	using FunctionType = decltype(setVisible(visible))(*)(EndPortalObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x321edc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, visible);
}

auto EndPortalObject::getSpawnPos() -> decltype(getSpawnPos()) {
	using FunctionType = decltype(getSpawnPos())(*)(EndPortalObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x321d80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto EndPortalObject::triggerObject(GJBaseGameLayer* layer) -> decltype(triggerObject(layer)) {
	using FunctionType = decltype(triggerObject(layer))(*)(EndPortalObject*, GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x321d10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, layer);
}

auto EndPortalObject::updateColors(cocos2d::ccColor3B color) -> decltype(updateColors(color)) {
	using FunctionType = decltype(updateColors(color))(*)(EndPortalObject*, cocos2d::ccColor3B);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x321c44, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, color);
}

auto EndPortalObject::updateEndPos(bool updateParticle) -> decltype(updateEndPos(updateParticle)) {
	using FunctionType = decltype(updateEndPos(updateParticle))(*)(EndPortalObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x321f40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, updateParticle);
}
