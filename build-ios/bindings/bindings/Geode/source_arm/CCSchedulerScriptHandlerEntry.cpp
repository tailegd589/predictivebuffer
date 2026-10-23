
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCSchedulerScriptHandlerEntry.hpp>
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

cocos2d::CCSchedulerScriptHandlerEntry::~CCSchedulerScriptHandlerEntry() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCSchedulerScriptHandlerEntry*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x2a9cec, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCSchedulerScriptHandlerEntry(geode::CutoffConstructor, sizeof(cocos2d::CCSchedulerScriptHandlerEntry));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCSchedulerScriptHandlerEntry::create(int p0, float p1, bool p2) -> decltype(create(p0, p1, p2)) {
	using FunctionType = decltype(create(p0, p1, p2))(*)(int, float, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a9b88, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::CCSchedulerScriptHandlerEntry::init(float p0, bool p1) -> decltype(init(p0, p1)) {
	using FunctionType = decltype(init(p0, p1))(*)(cocos2d::CCSchedulerScriptHandlerEntry*, float, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a9c68, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}
