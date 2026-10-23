
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJSpecialColorSelect.hpp>
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

auto GJSpecialColorSelect::create(int id, GJSpecialColorSelectDelegate* delegate, ColorSelectType type) -> decltype(create(id, delegate, type)) {
	using FunctionType = decltype(create(id, delegate, type))(*)(int, GJSpecialColorSelectDelegate*, ColorSelectType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x549474, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(id, delegate, type);
}

auto GJSpecialColorSelect::textForColorIdx(int index) -> decltype(textForColorIdx(index)) {
	using FunctionType = decltype(textForColorIdx(index))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x549fc4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(index);
}

auto GJSpecialColorSelect::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJSpecialColorSelect::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(GJSpecialColorSelect*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54a20c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJSpecialColorSelect::getButtonByTag(int tag) -> decltype(getButtonByTag(tag)) {
	using FunctionType = decltype(getButtonByTag(tag))(*)(GJSpecialColorSelect*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54a0c8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, tag);
}

auto GJSpecialColorSelect::highlightSelected(ButtonSprite* sprite) -> decltype(highlightSelected(sprite)) {
	using FunctionType = decltype(highlightSelected(sprite))(*)(GJSpecialColorSelect*, ButtonSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54a158, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sprite);
}

auto GJSpecialColorSelect::init(int id, GJSpecialColorSelectDelegate* delegate, ColorSelectType type) -> decltype(init(id, delegate, type)) {
	using FunctionType = decltype(init(id, delegate, type))(*)(GJSpecialColorSelect*, int, GJSpecialColorSelectDelegate*, ColorSelectType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x549594, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, delegate, type);
}

auto GJSpecialColorSelect::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	using FunctionType = decltype(onClose(sender))(*)(GJSpecialColorSelect*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x549f68, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJSpecialColorSelect::onSelectColor(cocos2d::CCObject* sender) -> decltype(onSelectColor(sender)) {
	using FunctionType = decltype(onSelectColor(sender))(*)(GJSpecialColorSelect*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x549fec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}
