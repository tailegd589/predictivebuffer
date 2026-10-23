
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/InheritanceNode.hpp>
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

auto InheritanceNode::create(int colorID, InheritanceNode* node) -> decltype(create(colorID, node)) {
	using FunctionType = decltype(create(colorID, node))(*)(int, InheritanceNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2737d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(colorID, node);
}

auto InheritanceNode::init(int colorID, InheritanceNode* node) -> decltype(init(colorID, node)) {
	using FunctionType = decltype(init(colorID, node))(*)(InheritanceNode*, int, InheritanceNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x273848, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, colorID, node);
}
