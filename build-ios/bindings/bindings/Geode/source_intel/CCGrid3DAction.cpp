
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCGrid3DAction.hpp>
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

auto cocos2d::CCGrid3DAction::getGrid() -> decltype(getGrid()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCGrid3DAction::getGrid), this);
	using FunctionType = decltype(getGrid())(*)(cocos2d::CCGrid3DAction*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x20a270, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCGrid3DAction::originalVertex(cocos2d::CCPoint const& p0) -> decltype(originalVertex(p0)) {
	using FunctionType = decltype(originalVertex(p0))(*)(cocos2d::CCGrid3DAction*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x20a2b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCGrid3DAction::setVertex(cocos2d::CCPoint const& p0, cocos2d::ccVertex3F const& p1) -> decltype(setVertex(p0, p1)) {
	using FunctionType = decltype(setVertex(p0, p1))(*)(cocos2d::CCGrid3DAction*, cocos2d::CCPoint const&, cocos2d::ccVertex3F const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x20a2e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCGrid3DAction::vertex(cocos2d::CCPoint const& p0) -> decltype(vertex(p0)) {
	using FunctionType = decltype(vertex(p0))(*)(cocos2d::CCGrid3DAction*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x20a280, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
