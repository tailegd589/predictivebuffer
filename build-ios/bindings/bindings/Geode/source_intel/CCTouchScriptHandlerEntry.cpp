
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCTouchScriptHandlerEntry.hpp>
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

cocos2d::CCTouchScriptHandlerEntry::~CCTouchScriptHandlerEntry() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCTouchScriptHandlerEntry*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x31bdb0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCTouchScriptHandlerEntry(geode::CutoffConstructor, sizeof(cocos2d::CCTouchScriptHandlerEntry));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCTouchScriptHandlerEntry::create(int p0, bool p1, int p2, bool p3) -> decltype(create(p0, p1, p2, p3)) {
	using FunctionType = decltype(create(p0, p1, p2, p3))(*)(int, bool, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x31bd00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

auto cocos2d::CCTouchScriptHandlerEntry::init(bool p0, int p1, bool p2) -> decltype(init(p0, p1, p2)) {
	using FunctionType = decltype(init(p0, p1, p2))(*)(cocos2d::CCTouchScriptHandlerEntry*, bool, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x31bd90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}
