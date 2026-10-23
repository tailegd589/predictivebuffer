
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCCardinalSplineTo.hpp>
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

cocos2d::CCCardinalSplineTo::CCCardinalSplineTo() : cocos2d::CCCardinalSplineTo(geode::CutoffConstructor, sizeof(cocos2d::CCCardinalSplineTo)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCCardinalSplineTo::~CCCardinalSplineTo();

	using FunctionType = void(*)(cocos2d::CCCardinalSplineTo*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26cbac, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCCardinalSplineTo::~CCCardinalSplineTo() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCCardinalSplineTo*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x26cc68, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCCardinalSplineTo(geode::CutoffConstructor, sizeof(cocos2d::CCCardinalSplineTo));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCCardinalSplineTo::create(float p0, cocos2d::CCPointArray* p1, float p2) -> decltype(create(p0, p1, p2)) {
	using FunctionType = decltype(create(p0, p1, p2))(*)(float, cocos2d::CCPointArray*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26cab4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::CCCardinalSplineTo::copyWithZone(cocos2d::CCZone* p0) -> decltype(copyWithZone(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCCardinalSplineTo::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(p0))(*)(cocos2d::CCCardinalSplineTo*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26cdfc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCCardinalSplineTo::startWithTarget(cocos2d::CCNode* p0) -> decltype(startWithTarget(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*>::func(&cocos2d::CCCardinalSplineTo::startWithTarget), this);
	using FunctionType = decltype(startWithTarget(p0))(*)(cocos2d::CCCardinalSplineTo*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26cd88, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCCardinalSplineTo::update(float p0) -> decltype(update(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCCardinalSplineTo::update), this);
	using FunctionType = decltype(update(p0))(*)(cocos2d::CCCardinalSplineTo*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26cf18, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCCardinalSplineTo::reverse() -> decltype(reverse()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCCardinalSplineTo::reverse), this);
	using FunctionType = decltype(reverse())(*)(cocos2d::CCCardinalSplineTo*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26d1c8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCCardinalSplineTo::updatePosition(cocos2d::CCPoint& p0) -> decltype(updatePosition(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCPoint&>::func(&cocos2d::CCCardinalSplineTo::updatePosition), this);
	using FunctionType = decltype(updatePosition(p0))(*)(cocos2d::CCCardinalSplineTo*, cocos2d::CCPoint&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26d190, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCCardinalSplineTo::initWithDuration(float p0, cocos2d::CCPointArray* p1, float p2) -> decltype(initWithDuration(p0, p1, p2)) {
	using FunctionType = decltype(initWithDuration(p0, p1, p2))(*)(cocos2d::CCCardinalSplineTo*, float, cocos2d::CCPointArray*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26cc08, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}
