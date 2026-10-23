
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCArrayForObjectSorting.hpp>
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

auto cocos2d::extension::CCArrayForObjectSorting::indexOfSortedObject(cocos2d::extension::CCSortableObject* p0) -> decltype(indexOfSortedObject(p0)) {
	using FunctionType = decltype(indexOfSortedObject(p0))(*)(cocos2d::extension::CCArrayForObjectSorting*, cocos2d::extension::CCSortableObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39c9d8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCArrayForObjectSorting::insertSortedObject(cocos2d::extension::CCSortableObject* p0) -> decltype(insertSortedObject(p0)) {
	using FunctionType = decltype(insertSortedObject(p0))(*)(cocos2d::extension::CCArrayForObjectSorting*, cocos2d::extension::CCSortableObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39c8b8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCArrayForObjectSorting::objectWithObjectID(unsigned int p0) -> decltype(objectWithObjectID(p0)) {
	using FunctionType = decltype(objectWithObjectID(p0))(*)(cocos2d::extension::CCArrayForObjectSorting*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39cf50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCArrayForObjectSorting::removeSortedObject(cocos2d::extension::CCSortableObject* p0) -> decltype(removeSortedObject(p0)) {
	using FunctionType = decltype(removeSortedObject(p0))(*)(cocos2d::extension::CCArrayForObjectSorting*, cocos2d::extension::CCSortableObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39cac0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCArrayForObjectSorting::setObjectID_ofSortedObject(unsigned int p0, cocos2d::extension::CCSortableObject* p1) -> decltype(setObjectID_ofSortedObject(p0, p1)) {
	using FunctionType = decltype(setObjectID_ofSortedObject(p0, p1))(*)(cocos2d::extension::CCArrayForObjectSorting*, unsigned int, cocos2d::extension::CCSortableObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39cc68, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}
