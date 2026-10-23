
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCObject.hpp>
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

cocos2d::CCObject::CCObject() {
	using FunctionType = void(*)(cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3efe64, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCObject::~CCObject() {
	// basically we destruct it once by calling the gd function,
	// then we release the lock because there are no other destructors after this
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCObject*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x3efef4, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);
	}
	else {
		geode::DestructorLock::removeLock(this);
	}
}

auto cocos2d::CCObject::createWithCoder(DS_Dictionary* p0) -> decltype(createWithCoder(p0)) {
	using FunctionType = decltype(createWithCoder(p0))(*)(DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f0170, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCObject::getTag() const  -> decltype(getTag()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCObject::getTag), this);
	using FunctionType = decltype(getTag())(*)(cocos2d::CCObject const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f015c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCObject::isEqual(cocos2d::CCObject const* p0) -> decltype(isEqual(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject const*>::func(&cocos2d::CCObject::isEqual), this);
	using FunctionType = decltype(isEqual(p0))(*)(cocos2d::CCObject*, cocos2d::CCObject const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f0138, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCObject::acceptVisitor(cocos2d::CCDataVisitor& p0) -> decltype(acceptVisitor(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCDataVisitor&>::func(&cocos2d::CCObject::acceptVisitor), this);
	using FunctionType = decltype(acceptVisitor(p0))(*)(cocos2d::CCObject*, cocos2d::CCDataVisitor&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f0144, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCObject::encodeWithCoder(DS_Dictionary* p0) -> decltype(encodeWithCoder(p0)) {
	auto self = addresser::thunkAdjust(Resolve<DS_Dictionary*>::func(&cocos2d::CCObject::encodeWithCoder), this);
	using FunctionType = decltype(encodeWithCoder(p0))(*)(cocos2d::CCObject*, DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f016c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCObject::canEncode() -> decltype(canEncode()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCObject::canEncode), this);
	using FunctionType = decltype(canEncode())(*)(cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f0178, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCObject::setTag(int p0) -> decltype(setTag(p0)) {
	auto self = addresser::thunkAdjust(Resolve<int>::func(&cocos2d::CCObject::setTag), this);
	using FunctionType = decltype(setTag(p0))(*)(cocos2d::CCObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f0164, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCObject::autorelease() -> decltype(autorelease()) {
	using FunctionType = decltype(autorelease())(*)(cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f00f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCObject::isSingleReference() const  -> decltype(isSingleReference()) {
	using FunctionType = decltype(isSingleReference())(*)(cocos2d::CCObject const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f0120, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCObject::release() -> decltype(release()) {
	using FunctionType = decltype(release())(*)(cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f00c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCObject::retain() -> decltype(retain()) {
	using FunctionType = decltype(retain())(*)(cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f00e4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
