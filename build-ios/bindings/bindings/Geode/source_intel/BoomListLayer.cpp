
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/BoomListLayer.hpp>
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

auto BoomListLayer::create(BoomListView* listView, char const* title) -> decltype(create(listView, title)) {
	using FunctionType = decltype(create(listView, title))(*)(BoomListView*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46def0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(listView, title);
}

auto BoomListLayer::init(BoomListView* listView, char const* title) -> decltype(init(listView, title)) {
	using FunctionType = decltype(init(listView, title))(*)(BoomListLayer*, BoomListView*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46dfe0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, listView, title);
}
