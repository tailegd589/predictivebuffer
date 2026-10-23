
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCSet.hpp>
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

cocos2d::CCSet::CCSet() : cocos2d::CCSet(geode::CutoffConstructor, sizeof(cocos2d::CCSet)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCSet::~CCSet();

	using FunctionType = void(*)(cocos2d::CCSet*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b94f0, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCSet::~CCSet() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCSet*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x6b9668, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCSet(geode::CutoffConstructor, sizeof(cocos2d::CCSet));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCSet::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b97d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCSet::acceptVisitor(cocos2d::CCDataVisitor& p0) -> decltype(acceptVisitor(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCDataVisitor&>::func(&cocos2d::CCSet::acceptVisitor), this);
	using FunctionType = decltype(acceptVisitor(p0))(*)(cocos2d::CCSet*, cocos2d::CCDataVisitor&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b97bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSet::addObject(cocos2d::CCObject* p0) -> decltype(addObject(p0)) {
	using FunctionType = decltype(addObject(p0))(*)(cocos2d::CCSet*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b98f8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCSet::anyObject() -> decltype(anyObject()) {
	using FunctionType = decltype(anyObject())(*)(cocos2d::CCSet*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b9ae8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCSet::begin() -> decltype(begin()) {
	using FunctionType = decltype(begin())(*)(cocos2d::CCSet*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b9ad0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCSet::containsObject(cocos2d::CCObject* p0) -> decltype(containsObject(p0)) {
	using FunctionType = decltype(containsObject(p0))(*)(cocos2d::CCSet*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b9a84, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCSet::copy() -> decltype(copy()) {
	using FunctionType = decltype(copy())(*)(cocos2d::CCSet*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b985c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCSet::count() -> decltype(count()) {
	using FunctionType = decltype(count())(*)(cocos2d::CCSet*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b98ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCSet::end() -> decltype(end()) {
	using FunctionType = decltype(end())(*)(cocos2d::CCSet*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b9adc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCSet::mutableCopy() -> decltype(mutableCopy()) {
	using FunctionType = decltype(mutableCopy())(*)(cocos2d::CCSet*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b98a4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCSet::removeAllObjects() -> decltype(removeAllObjects()) {
	using FunctionType = decltype(removeAllObjects())(*)(cocos2d::CCSet*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b9724, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCSet::removeObject(cocos2d::CCObject* p0) -> decltype(removeObject(p0)) {
	using FunctionType = decltype(removeObject(p0))(*)(cocos2d::CCSet*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b99b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
