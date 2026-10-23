
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/EditButtonBar.hpp>
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

auto EditButtonBar::create(cocos2d::CCArray* objects, cocos2d::CCPoint position, int tab, bool hasCreateItems, int columns, int rows) -> decltype(create(objects, position, tab, hasCreateItems, columns, rows)) {
	using FunctionType = decltype(create(objects, position, tab, hasCreateItems, columns, rows))(*)(cocos2d::CCArray*, cocos2d::CCPoint, int, bool, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5e1c20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(objects, position, tab, hasCreateItems, columns, rows);
}

auto EditButtonBar::getPage() -> decltype(getPage()) {
	using FunctionType = decltype(getPage())(*)(EditButtonBar*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5e2540, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto EditButtonBar::goToPage(int page) -> decltype(goToPage(page)) {
	using FunctionType = decltype(goToPage(page))(*)(EditButtonBar*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5e2560, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page);
}

auto EditButtonBar::init(cocos2d::CCArray* objects, cocos2d::CCPoint position, int tab, bool hasCreateItems, int columns, int rows) -> decltype(init(objects, position, tab, hasCreateItems, columns, rows)) {
	using FunctionType = decltype(init(objects, position, tab, hasCreateItems, columns, rows))(*)(EditButtonBar*, cocos2d::CCArray*, cocos2d::CCPoint, int, bool, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5e1d10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objects, position, tab, hasCreateItems, columns, rows);
}

auto EditButtonBar::loadFromItems(cocos2d::CCArray* objects, int rows, int columns, bool keepPage) -> decltype(loadFromItems(objects, rows, columns, keepPage)) {
	using FunctionType = decltype(loadFromItems(objects, rows, columns, keepPage))(*)(EditButtonBar*, cocos2d::CCArray*, int, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5e1dc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objects, rows, columns, keepPage);
}

auto EditButtonBar::onLeft(cocos2d::CCObject* sender) -> decltype(onLeft(sender)) {
	using FunctionType = decltype(onLeft(sender))(*)(EditButtonBar*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5e24a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditButtonBar::onRight(cocos2d::CCObject* sender) -> decltype(onRight(sender)) {
	using FunctionType = decltype(onRight(sender))(*)(EditButtonBar*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5e24f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditButtonBar::reloadItems(int rowCount, int columnCount) -> decltype(reloadItems(rowCount, columnCount)) {
	using FunctionType = decltype(reloadItems(rowCount, columnCount))(*)(EditButtonBar*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5e2390, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, rowCount, columnCount);
}
