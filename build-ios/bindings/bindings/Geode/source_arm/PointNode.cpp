
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/PointNode.hpp>
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

auto PointNode::create(cocos2d::CCPoint point) -> decltype(create(point)) {
	using FunctionType = decltype(create(point))(*)(cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8e2fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(point);
}

auto PointNode::init(cocos2d::CCPoint point) -> decltype(init(point)) {
	using FunctionType = decltype(init(point))(*)(PointNode*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8e638, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, point);
}
