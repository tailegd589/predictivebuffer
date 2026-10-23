
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCScheduler.hpp>
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

cocos2d::CCScheduler::CCScheduler() : cocos2d::CCScheduler(geode::CutoffConstructor, sizeof(cocos2d::CCScheduler)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCScheduler::~CCScheduler();

	using FunctionType = void(*)(cocos2d::CCScheduler*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x441f20, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCScheduler::~CCScheduler() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCScheduler*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x441f70, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCScheduler(geode::CutoffConstructor, sizeof(cocos2d::CCScheduler));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCScheduler::update(float p0) -> decltype(update(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCScheduler::update), this);
	using FunctionType = decltype(update(p0))(*)(cocos2d::CCScheduler*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x443db0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCScheduler::appendIn(cocos2d::_listEntry** p0, cocos2d::CCObject* p1, bool p2) -> decltype(appendIn(p0, p1, p2)) {
	using FunctionType = decltype(appendIn(p0, p1, p2))(*)(cocos2d::CCScheduler*, cocos2d::_listEntry**, cocos2d::CCObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x442a50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCScheduler::isTargetPaused(cocos2d::CCObject* p0) -> decltype(isTargetPaused(p0)) {
	using FunctionType = decltype(isTargetPaused(p0))(*)(cocos2d::CCScheduler*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4439b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCScheduler::pauseAllTargets() -> decltype(pauseAllTargets()) {
	using FunctionType = decltype(pauseAllTargets())(*)(cocos2d::CCScheduler*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x443be0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCScheduler::pauseAllTargetsWithMinPriority(int p0) -> decltype(pauseAllTargetsWithMinPriority(p0)) {
	using FunctionType = decltype(pauseAllTargetsWithMinPriority(p0))(*)(cocos2d::CCScheduler*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x443bf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCScheduler::pauseTarget(cocos2d::CCObject* p0) -> decltype(pauseTarget(p0)) {
	using FunctionType = decltype(pauseTarget(p0))(*)(cocos2d::CCScheduler*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x443780, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCScheduler::priorityIn(cocos2d::_listEntry** p0, cocos2d::CCObject* p1, int p2, bool p3) -> decltype(priorityIn(p0, p1, p2, p3)) {
	using FunctionType = decltype(priorityIn(p0, p1, p2, p3))(*)(cocos2d::CCScheduler*, cocos2d::_listEntry**, cocos2d::CCObject*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4426d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto cocos2d::CCScheduler::removeHashElement(cocos2d::_hashSelectorEntry* p0) -> decltype(removeHashElement(p0)) {
	using FunctionType = decltype(removeHashElement(p0))(*)(cocos2d::CCScheduler*, cocos2d::_hashSelectorEntry*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x442070, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCScheduler::removeUpdateFromHash(cocos2d::_listEntry* p0) -> decltype(removeUpdateFromHash(p0)) {
	using FunctionType = decltype(removeUpdateFromHash(p0))(*)(cocos2d::CCScheduler*, cocos2d::_listEntry*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x442ed0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCScheduler::resumeTarget(cocos2d::CCObject* p0) -> decltype(resumeTarget(p0)) {
	using FunctionType = decltype(resumeTarget(p0))(*)(cocos2d::CCScheduler*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x443550, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCScheduler::resumeTargets(cocos2d::CCSet* p0) -> decltype(resumeTargets(p0)) {
	using FunctionType = decltype(resumeTargets(p0))(*)(cocos2d::CCScheduler*, cocos2d::CCSet*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x443d20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCScheduler::scheduleScriptFunc(unsigned int p0, float p1, bool p2) -> decltype(scheduleScriptFunc(p0, p1, p2)) {
	using FunctionType = decltype(scheduleScriptFunc(p0, p1, p2))(*)(cocos2d::CCScheduler*, unsigned int, float, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4434b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCScheduler::scheduleSelector(cocos2d::SEL_SCHEDULE p0, cocos2d::CCObject* p1, float p2, bool p3) -> decltype(scheduleSelector(p0, p1, p2, p3)) {
	using FunctionType = decltype(scheduleSelector(p0, p1, p2, p3))(*)(cocos2d::CCScheduler*, cocos2d::SEL_SCHEDULE, cocos2d::CCObject*, float, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x442180, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto cocos2d::CCScheduler::scheduleSelector(cocos2d::SEL_SCHEDULE p0, cocos2d::CCObject* p1, float p2, unsigned int p3, float p4, bool p5) -> decltype(scheduleSelector(p0, p1, p2, p3, p4, p5)) {
	using FunctionType = decltype(scheduleSelector(p0, p1, p2, p3, p4, p5))(*)(cocos2d::CCScheduler*, cocos2d::SEL_SCHEDULE, cocos2d::CCObject*, float, unsigned int, float, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4421a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5);
}

auto cocos2d::CCScheduler::scheduleUpdateForTarget(cocos2d::CCObject* p0, int p1, bool p2) -> decltype(scheduleUpdateForTarget(p0, p1, p2)) {
	using FunctionType = decltype(scheduleUpdateForTarget(p0, p1, p2))(*)(cocos2d::CCScheduler*, cocos2d::CCObject*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x442d80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCScheduler::unscheduleAll() -> decltype(unscheduleAll()) {
	using FunctionType = decltype(unscheduleAll())(*)(cocos2d::CCScheduler*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x441fc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCScheduler::unscheduleAllForTarget(cocos2d::CCObject* p0) -> decltype(unscheduleAllForTarget(p0)) {
	using FunctionType = decltype(unscheduleAllForTarget(p0))(*)(cocos2d::CCScheduler*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x443320, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCScheduler::unscheduleAllWithMinPriority(int p0) -> decltype(unscheduleAllWithMinPriority(p0)) {
	using FunctionType = decltype(unscheduleAllWithMinPriority(p0))(*)(cocos2d::CCScheduler*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x443230, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCScheduler::unscheduleScriptEntry(unsigned int p0) -> decltype(unscheduleScriptEntry(p0)) {
	using FunctionType = decltype(unscheduleScriptEntry(p0))(*)(cocos2d::CCScheduler*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x443500, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCScheduler::unscheduleSelector(cocos2d::SEL_SCHEDULE p0, cocos2d::CCObject* p1) -> decltype(unscheduleSelector(p0, p1)) {
	using FunctionType = decltype(unscheduleSelector(p0, p1))(*)(cocos2d::CCScheduler*, cocos2d::SEL_SCHEDULE, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x441cb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCScheduler::unscheduleUpdateForTarget(cocos2d::CCObject const* p0) -> decltype(unscheduleUpdateForTarget(p0)) {
	using FunctionType = decltype(unscheduleUpdateForTarget(p0))(*)(cocos2d::CCScheduler*, cocos2d::CCObject const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x443110, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
