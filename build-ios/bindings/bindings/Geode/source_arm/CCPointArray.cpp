
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCPointArray.hpp>
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

cocos2d::CCPointArray::CCPointArray() : cocos2d::CCPointArray(geode::CutoffConstructor, sizeof(cocos2d::CCPointArray)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCPointArray::~CCPointArray();

	using FunctionType = void(*)(cocos2d::CCPointArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26c2d0, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCPointArray::~CCPointArray() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCPointArray*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x26c128, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCPointArray(geode::CutoffConstructor, sizeof(cocos2d::CCPointArray));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCPointArray::create(unsigned int p0) -> decltype(create(p0)) {
	using FunctionType = decltype(create(p0))(*)(unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26be2c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCPointArray::copyWithZone(cocos2d::CCZone* p0) -> decltype(copyWithZone(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCPointArray::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(p0))(*)(cocos2d::CCPointArray*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26bef0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCPointArray::addControlPoint(cocos2d::CCPoint p0) -> decltype(addControlPoint(p0)) {
	using FunctionType = decltype(addControlPoint(p0))(*)(cocos2d::CCPointArray*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26c2fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCPointArray::count() -> decltype(count()) {
	using FunctionType = decltype(count())(*)(cocos2d::CCPointArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26c784, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCPointArray::getControlPointAtIndex(unsigned int p0) -> decltype(getControlPointAtIndex(p0)) {
	using FunctionType = decltype(getControlPointAtIndex(p0))(*)(cocos2d::CCPointArray*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26c6a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCPointArray::getControlPoints() -> decltype(getControlPoints()) {
	using FunctionType = decltype(getControlPoints())(*)(cocos2d::CCPointArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26c2f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCPointArray::initWithCapacity(unsigned int p0) -> decltype(initWithCapacity(p0)) {
	using FunctionType = decltype(initWithCapacity(p0))(*)(cocos2d::CCPointArray*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26bebc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCPointArray::insertControlPoint(cocos2d::CCPoint& p0, unsigned int p1) -> decltype(insertControlPoint(p0, p1)) {
	using FunctionType = decltype(insertControlPoint(p0, p1))(*)(cocos2d::CCPointArray*, cocos2d::CCPoint&, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26c404, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCPointArray::removeControlPointAtIndex(unsigned int p0) -> decltype(removeControlPointAtIndex(p0)) {
	using FunctionType = decltype(removeControlPointAtIndex(p0))(*)(cocos2d::CCPointArray*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26c71c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCPointArray::replaceControlPoint(cocos2d::CCPoint& p0, unsigned int p1) -> decltype(replaceControlPoint(p0, p1)) {
	using FunctionType = decltype(replaceControlPoint(p0, p1))(*)(cocos2d::CCPointArray*, cocos2d::CCPoint&, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26c6e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCPointArray::reverse() -> decltype(reverse()) {
	using FunctionType = decltype(reverse())(*)(cocos2d::CCPointArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26c798, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCPointArray::reverseInline() -> decltype(reverseInline()) {
	using FunctionType = decltype(reverseInline())(*)(cocos2d::CCPointArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26c9a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCPointArray::setControlPoints(gd::vector<cocos2d::CCPoint*>* p0) -> decltype(setControlPoints(p0)) {
	using FunctionType = decltype(setControlPoints(p0))(*)(cocos2d::CCPointArray*, gd::vector<cocos2d::CCPoint*>*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26c0a4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
