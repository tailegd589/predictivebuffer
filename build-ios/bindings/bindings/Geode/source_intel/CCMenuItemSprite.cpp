
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCMenuItemSprite.hpp>
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

auto cocos2d::CCMenuItemSprite::create(cocos2d::CCNode* p0, cocos2d::CCNode* p1, cocos2d::CCNode* p2) -> decltype(create(p0, p1, p2)) {
	using FunctionType = decltype(create(p0, p1, p2))(*)(cocos2d::CCNode*, cocos2d::CCNode*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3bfd90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::CCMenuItemSprite::create(cocos2d::CCNode* p0, cocos2d::CCNode* p1, cocos2d::CCObject* p2, cocos2d::SEL_MenuHandler p3) -> decltype(create(p0, p1, p2, p3)) {
	using FunctionType = decltype(create(p0, p1, p2, p3))(*)(cocos2d::CCNode*, cocos2d::CCNode*, cocos2d::CCObject*, cocos2d::SEL_MenuHandler);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3bff20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

auto cocos2d::CCMenuItemSprite::create(cocos2d::CCNode* p0, cocos2d::CCNode* p1, cocos2d::CCNode* p2, cocos2d::CCObject* p3, cocos2d::SEL_MenuHandler p4) -> decltype(create(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(create(p0, p1, p2, p3, p4))(*)(cocos2d::CCNode*, cocos2d::CCNode*, cocos2d::CCNode*, cocos2d::CCObject*, cocos2d::SEL_MenuHandler);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3bfdb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3, p4);
}

auto cocos2d::CCMenuItemSprite::selected() -> decltype(selected()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCMenuItemSprite::selected), this);
	using FunctionType = decltype(selected())(*)(cocos2d::CCMenuItemSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c0030, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCMenuItemSprite::unselected() -> decltype(unselected()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCMenuItemSprite::unselected), this);
	using FunctionType = decltype(unselected())(*)(cocos2d::CCMenuItemSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c00d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCMenuItemSprite::setEnabled(bool p0) -> decltype(setEnabled(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCMenuItemSprite::setEnabled), this);
	using FunctionType = decltype(setEnabled(p0))(*)(cocos2d::CCMenuItemSprite*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c0150, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCMenuItemSprite::getNormalImage() -> decltype(getNormalImage()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCMenuItemSprite::getNormalImage), this);
	using FunctionType = decltype(getNormalImage())(*)(cocos2d::CCMenuItemSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3bfb60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCMenuItemSprite::setNormalImage(cocos2d::CCNode* p0) -> decltype(setNormalImage(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*>::func(&cocos2d::CCMenuItemSprite::setNormalImage), this);
	using FunctionType = decltype(setNormalImage(p0))(*)(cocos2d::CCMenuItemSprite*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3bfb70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCMenuItemSprite::getSelectedImage() -> decltype(getSelectedImage()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCMenuItemSprite::getSelectedImage), this);
	using FunctionType = decltype(getSelectedImage())(*)(cocos2d::CCMenuItemSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3bfc30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCMenuItemSprite::setSelectedImage(cocos2d::CCNode* p0) -> decltype(setSelectedImage(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*>::func(&cocos2d::CCMenuItemSprite::setSelectedImage), this);
	using FunctionType = decltype(setSelectedImage(p0))(*)(cocos2d::CCMenuItemSprite*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3bfc40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCMenuItemSprite::getDisabledImage() -> decltype(getDisabledImage()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCMenuItemSprite::getDisabledImage), this);
	using FunctionType = decltype(getDisabledImage())(*)(cocos2d::CCMenuItemSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3bfce0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCMenuItemSprite::setDisabledImage(cocos2d::CCNode* p0) -> decltype(setDisabledImage(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*>::func(&cocos2d::CCMenuItemSprite::setDisabledImage), this);
	using FunctionType = decltype(setDisabledImage(p0))(*)(cocos2d::CCMenuItemSprite*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3bfcf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCMenuItemSprite::updateImagesVisibility() -> decltype(updateImagesVisibility()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCMenuItemSprite::updateImagesVisibility), this);
	using FunctionType = decltype(updateImagesVisibility())(*)(cocos2d::CCMenuItemSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c0170, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCMenuItemSprite::initWithNormalSprite(cocos2d::CCNode* p0, cocos2d::CCNode* p1, cocos2d::CCNode* p2, cocos2d::CCObject* p3, cocos2d::SEL_MenuHandler p4) -> decltype(initWithNormalSprite(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(initWithNormalSprite(p0, p1, p2, p3, p4))(*)(cocos2d::CCMenuItemSprite*, cocos2d::CCNode*, cocos2d::CCNode*, cocos2d::CCNode*, cocos2d::CCObject*, cocos2d::SEL_MenuHandler);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3bff40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4);
}
