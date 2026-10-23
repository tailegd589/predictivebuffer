
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCDictionary.hpp>
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

cocos2d::CCDictionary::CCDictionary() : cocos2d::CCDictionary(geode::CutoffConstructor, sizeof(cocos2d::CCDictionary)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCDictionary::~CCDictionary();

	using FunctionType = void(*)(cocos2d::CCDictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29cec8, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCDictionary::~CCDictionary() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCDictionary*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x29cef0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCDictionary(geode::CutoffConstructor, sizeof(cocos2d::CCDictionary));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCDictionary::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29f2d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCDictionary::createWithContentsOfFile(char const* p0) -> decltype(createWithContentsOfFile(p0)) {
	using FunctionType = decltype(createWithContentsOfFile(p0))(*)(char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29f47c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCDictionary::createWithContentsOfFileThreadSafe(char const* p0) -> decltype(createWithContentsOfFileThreadSafe(p0)) {
	using FunctionType = decltype(createWithContentsOfFileThreadSafe(p0))(*)(char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29f354, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCDictionary::createWithDictionary(cocos2d::CCDictionary* p0) -> decltype(createWithDictionary(p0)) {
	using FunctionType = decltype(createWithDictionary(p0))(*)(cocos2d::CCDictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29f32c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCDictionary::copyWithZone(cocos2d::CCZone* p0) -> decltype(copyWithZone(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCDictionary::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(p0))(*)(cocos2d::CCDictionary*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29efa4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCDictionary::acceptVisitor(cocos2d::CCDataVisitor& p0) -> decltype(acceptVisitor(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCDataVisitor&>::func(&cocos2d::CCDictionary::acceptVisitor), this);
	using FunctionType = decltype(acceptVisitor(p0))(*)(cocos2d::CCDictionary*, cocos2d::CCDataVisitor&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29f464, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCDictionary::allKeys() -> decltype(allKeys()) {
	using FunctionType = decltype(allKeys())(*)(cocos2d::CCDictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29d100, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDictionary::allKeysForObject(cocos2d::CCObject* p0) -> decltype(allKeysForObject(p0)) {
	using FunctionType = decltype(allKeysForObject(p0))(*)(cocos2d::CCDictionary*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29d298, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCDictionary::charForKey(gd::string const& p0) -> decltype(charForKey(p0)) {
	using FunctionType = decltype(charForKey(p0))(*)(cocos2d::CCDictionary*, gd::string const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29d3f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCDictionary::count() -> decltype(count()) {
	using FunctionType = decltype(count())(*)(cocos2d::CCDictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29d0e4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDictionary::getFirstKey() -> decltype(getFirstKey()) {
	using FunctionType = decltype(getFirstKey())(*)(cocos2d::CCDictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29d230, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDictionary::objectForKey(gd::string const& p0) -> decltype(objectForKey(p0)) {
	using FunctionType = decltype(objectForKey(p0))(*)(cocos2d::CCDictionary*, gd::string const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29d534, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCDictionary::objectForKey(intptr_t p0) -> decltype(objectForKey(p0)) {
	using FunctionType = decltype(objectForKey(p0))(*)(cocos2d::CCDictionary*, intptr_t);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29d8b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCDictionary::randomObject() -> decltype(randomObject()) {
	using FunctionType = decltype(randomObject())(*)(cocos2d::CCDictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29f16c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDictionary::removeAllObjects() -> decltype(removeAllObjects()) {
	using FunctionType = decltype(removeAllObjects())(*)(cocos2d::CCDictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29cf24, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDictionary::removeObjectForElememt(cocos2d::CCDictElement* p0) -> decltype(removeObjectForElememt(p0)) {
	using FunctionType = decltype(removeObjectForElememt(p0))(*)(cocos2d::CCDictionary*, cocos2d::CCDictElement*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29ec08, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCDictionary::removeObjectForKey(gd::string const& p0) -> decltype(removeObjectForKey(p0)) {
	using FunctionType = decltype(removeObjectForKey(p0))(*)(cocos2d::CCDictionary*, gd::string const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29e8a4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCDictionary::removeObjectForKey(intptr_t p0) -> decltype(removeObjectForKey(p0)) {
	using FunctionType = decltype(removeObjectForKey(p0))(*)(cocos2d::CCDictionary*, intptr_t);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29ed3c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCDictionary::removeObjectsForKeys(cocos2d::CCArray* p0) -> decltype(removeObjectsForKeys(p0)) {
	using FunctionType = decltype(removeObjectsForKeys(p0))(*)(cocos2d::CCDictionary*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29ee7c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCDictionary::setObject(cocos2d::CCObject* p0, gd::string const& p1) -> decltype(setObject(p0, p1)) {
	using FunctionType = decltype(setObject(p0, p1))(*)(cocos2d::CCDictionary*, cocos2d::CCObject*, gd::string const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29da88, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCDictionary::setObject(cocos2d::CCObject* p0, intptr_t p1) -> decltype(setObject(p0, p1)) {
	using FunctionType = decltype(setObject(p0, p1))(*)(cocos2d::CCDictionary*, cocos2d::CCObject*, intptr_t);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29e3d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCDictionary::setObjectUnSafe(cocos2d::CCObject* p0, gd::string const& p1) -> decltype(setObjectUnSafe(p0, p1)) {
	using FunctionType = decltype(setObjectUnSafe(p0, p1))(*)(cocos2d::CCDictionary*, cocos2d::CCObject*, gd::string const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29ded4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCDictionary::setObjectUnSafe(cocos2d::CCObject* p0, intptr_t p1) -> decltype(setObjectUnSafe(p0, p1)) {
	using FunctionType = decltype(setObjectUnSafe(p0, p1))(*)(cocos2d::CCDictionary*, cocos2d::CCObject*, intptr_t);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29e564, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCDictionary::valueForKey(gd::string const& p0) -> decltype(valueForKey(p0)) {
	using FunctionType = decltype(valueForKey(p0))(*)(cocos2d::CCDictionary*, gd::string const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29d498, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCDictionary::valueForKey(intptr_t p0) -> decltype(valueForKey(p0)) {
	using FunctionType = decltype(valueForKey(p0))(*)(cocos2d::CCDictionary*, intptr_t);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29d9ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCDictionary::writeToFile(char const* p0) -> decltype(writeToFile(p0)) {
	using FunctionType = decltype(writeToFile(p0))(*)(cocos2d::CCDictionary*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29f4a4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
