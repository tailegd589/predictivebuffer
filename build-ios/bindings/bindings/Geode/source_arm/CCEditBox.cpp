
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCEditBox.hpp>
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

cocos2d::extension::CCEditBox::CCEditBox() : cocos2d::extension::CCEditBox(geode::CutoffConstructor, sizeof(cocos2d::extension::CCEditBox)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::extension::CCEditBox::~CCEditBox();

	using FunctionType = void(*)(cocos2d::extension::CCEditBox*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40d318, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::extension::CCEditBox::~CCEditBox() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::extension::CCEditBox*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x40d3e0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::extension::CCEditBox(geode::CutoffConstructor, sizeof(cocos2d::extension::CCEditBox));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::extension::CCEditBox::create(cocos2d::CCSize const& p0, cocos2d::extension::CCScale9Sprite* p1, cocos2d::extension::CCScale9Sprite* p2, cocos2d::extension::CCScale9Sprite* p3) -> decltype(create(p0, p1, p2, p3)) {
	using FunctionType = decltype(create(p0, p1, p2, p3))(*)(cocos2d::CCSize const&, cocos2d::extension::CCScale9Sprite*, cocos2d::extension::CCScale9Sprite*, cocos2d::extension::CCScale9Sprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40d59c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

auto cocos2d::extension::CCEditBox::setPosition(cocos2d::CCPoint const& p0) -> decltype(setPosition(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCPoint const&>::func(&cocos2d::extension::CCEditBox::setPosition), this);
	using FunctionType = decltype(setPosition(p0))(*)(cocos2d::extension::CCEditBox*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40dbd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCEditBox::setVisible(bool p0) -> decltype(setVisible(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::extension::CCEditBox::setVisible), this);
	using FunctionType = decltype(setVisible(p0))(*)(cocos2d::extension::CCEditBox*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40dc14, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCEditBox::setContentSize(cocos2d::CCSize const& p0) -> decltype(setContentSize(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCSize const&>::func(&cocos2d::extension::CCEditBox::setContentSize), this);
	using FunctionType = decltype(setContentSize(p0))(*)(cocos2d::extension::CCEditBox*, cocos2d::CCSize const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40dc58, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCEditBox::setAnchorPoint(cocos2d::CCPoint const& p0) -> decltype(setAnchorPoint(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCPoint const&>::func(&cocos2d::extension::CCEditBox::setAnchorPoint), this);
	using FunctionType = decltype(setAnchorPoint(p0))(*)(cocos2d::extension::CCEditBox*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40dc9c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCEditBox::visit() -> decltype(visit()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCEditBox::visit), this);
	using FunctionType = decltype(visit())(*)(cocos2d::extension::CCEditBox*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40dce0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCEditBox::onEnter() -> decltype(onEnter()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCEditBox::onEnter), this);
	using FunctionType = decltype(onEnter())(*)(cocos2d::extension::CCEditBox*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40dd1c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCEditBox::onExit() -> decltype(onExit()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCEditBox::onExit), this);
	using FunctionType = decltype(onExit())(*)(cocos2d::extension::CCEditBox*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40dd58, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCEditBox::keyboardWillShow(cocos2d::CCIMEKeyboardNotificationInfo& p0) -> decltype(keyboardWillShow(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCIMEKeyboardNotificationInfo&>::func(&cocos2d::extension::CCEditBox::keyboardWillShow), this);
	using FunctionType = decltype(keyboardWillShow(p0))(*)(cocos2d::extension::CCEditBox*, cocos2d::CCIMEKeyboardNotificationInfo&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40dd94, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCEditBox::keyboardDidShow(cocos2d::CCIMEKeyboardNotificationInfo& p0) -> decltype(keyboardDidShow(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCIMEKeyboardNotificationInfo&>::func(&cocos2d::extension::CCEditBox::keyboardDidShow), this);
	using FunctionType = decltype(keyboardDidShow(p0))(*)(cocos2d::extension::CCEditBox*, cocos2d::CCIMEKeyboardNotificationInfo&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40de70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCEditBox::keyboardWillHide(cocos2d::CCIMEKeyboardNotificationInfo& p0) -> decltype(keyboardWillHide(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCIMEKeyboardNotificationInfo&>::func(&cocos2d::extension::CCEditBox::keyboardWillHide), this);
	using FunctionType = decltype(keyboardWillHide(p0))(*)(cocos2d::extension::CCEditBox*, cocos2d::CCIMEKeyboardNotificationInfo&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40de78, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCEditBox::keyboardDidHide(cocos2d::CCIMEKeyboardNotificationInfo& p0) -> decltype(keyboardDidHide(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCIMEKeyboardNotificationInfo&>::func(&cocos2d::extension::CCEditBox::keyboardDidHide), this);
	using FunctionType = decltype(keyboardDidHide(p0))(*)(cocos2d::extension::CCEditBox*, cocos2d::CCIMEKeyboardNotificationInfo&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40dec8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCEditBox::getDelegate() -> decltype(getDelegate()) {
	using FunctionType = decltype(getDelegate())(*)(cocos2d::extension::CCEditBox*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40d80c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::extension::CCEditBox::getMaxLength() -> decltype(getMaxLength()) {
	using FunctionType = decltype(getMaxLength())(*)(cocos2d::extension::CCEditBox*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40db94, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::extension::CCEditBox::getPlaceHolder() -> decltype(getPlaceHolder()) {
	using FunctionType = decltype(getPlaceHolder())(*)(cocos2d::extension::CCEditBox*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40db40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::extension::CCEditBox::getText() -> decltype(getText()) {
	using FunctionType = decltype(getText())(*)(cocos2d::extension::CCEditBox*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40d860, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::extension::CCEditBox::initWithSizeAndBackgroundSprite(cocos2d::CCSize const& p0, cocos2d::extension::CCScale9Sprite* p1) -> decltype(initWithSizeAndBackgroundSprite(p0, p1)) {
	using FunctionType = decltype(initWithSizeAndBackgroundSprite(p0, p1))(*)(cocos2d::extension::CCEditBox*, cocos2d::CCSize const&, cocos2d::extension::CCScale9Sprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40d724, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::extension::CCEditBox::registerScriptEditBoxHandler(int p0) -> decltype(registerScriptEditBoxHandler(p0)) {
	using FunctionType = decltype(registerScriptEditBoxHandler(p0))(*)(cocos2d::extension::CCEditBox*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40ded0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCEditBox::setDelegate(cocos2d::extension::CCEditBoxDelegate* p0) -> decltype(setDelegate(p0)) {
	using FunctionType = decltype(setDelegate(p0))(*)(cocos2d::extension::CCEditBox*, cocos2d::extension::CCEditBoxDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40d7f8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCEditBox::setFont(char const* p0, int p1) -> decltype(setFont(p0, p1)) {
	using FunctionType = decltype(setFont(p0, p1))(*)(cocos2d::extension::CCEditBox*, char const*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40d894, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::extension::CCEditBox::setFontColor(cocos2d::ccColor3B const& p0) -> decltype(setFontColor(p0)) {
	using FunctionType = decltype(setFontColor(p0))(*)(cocos2d::extension::CCEditBox*, cocos2d::ccColor3B const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40d998, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCEditBox::setFontName(char const* p0) -> decltype(setFontName(p0)) {
	using FunctionType = decltype(setFontName(p0))(*)(cocos2d::extension::CCEditBox*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40d8f8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCEditBox::setFontSize(int p0) -> decltype(setFontSize(p0)) {
	using FunctionType = decltype(setFontSize(p0))(*)(cocos2d::extension::CCEditBox*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40d94c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCEditBox::setInputFlag(cocos2d::extension::EditBoxInputFlag p0) -> decltype(setInputFlag(p0)) {
	using FunctionType = decltype(setInputFlag(p0))(*)(cocos2d::extension::CCEditBox*, cocos2d::extension::EditBoxInputFlag);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40db9c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCEditBox::setInputMode(cocos2d::extension::EditBoxInputMode p0) -> decltype(setInputMode(p0)) {
	using FunctionType = decltype(setInputMode(p0))(*)(cocos2d::extension::CCEditBox*, cocos2d::extension::EditBoxInputMode);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40db5c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCEditBox::setMaxLength(int p0) -> decltype(setMaxLength(p0)) {
	using FunctionType = decltype(setMaxLength(p0))(*)(cocos2d::extension::CCEditBox*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40db78, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCEditBox::setPlaceHolder(char const* p0) -> decltype(setPlaceHolder(p0)) {
	using FunctionType = decltype(setPlaceHolder(p0))(*)(cocos2d::extension::CCEditBox*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40daf4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCEditBox::setPlaceholderFont(char const* p0, int p1) -> decltype(setPlaceholderFont(p0, p1)) {
	using FunctionType = decltype(setPlaceholderFont(p0, p1))(*)(cocos2d::extension::CCEditBox*, char const*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40d9c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::extension::CCEditBox::setPlaceholderFontColor(cocos2d::ccColor3B const& p0) -> decltype(setPlaceholderFontColor(p0)) {
	using FunctionType = decltype(setPlaceholderFontColor(p0))(*)(cocos2d::extension::CCEditBox*, cocos2d::ccColor3B const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40dacc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCEditBox::setPlaceholderFontName(char const* p0) -> decltype(setPlaceholderFontName(p0)) {
	using FunctionType = decltype(setPlaceholderFontName(p0))(*)(cocos2d::extension::CCEditBox*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40da24, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCEditBox::setPlaceholderFontSize(int p0) -> decltype(setPlaceholderFontSize(p0)) {
	using FunctionType = decltype(setPlaceholderFontSize(p0))(*)(cocos2d::extension::CCEditBox*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40da7c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCEditBox::setReturnType(cocos2d::extension::KeyboardReturnType p0) -> decltype(setReturnType(p0)) {
	using FunctionType = decltype(setReturnType(p0))(*)(cocos2d::extension::CCEditBox*, cocos2d::extension::KeyboardReturnType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40dbb8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCEditBox::setText(char const* p0) -> decltype(setText(p0)) {
	using FunctionType = decltype(setText(p0))(*)(cocos2d::extension::CCEditBox*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40d814, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCEditBox::touchDownAction(cocos2d::CCObject* p0, cocos2d::extension::CCControlEvent p1) -> decltype(touchDownAction(p0, p1)) {
	using FunctionType = decltype(touchDownAction(p0, p1))(*)(cocos2d::extension::CCEditBox*, cocos2d::CCObject*, cocos2d::extension::CCControlEvent);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40d58c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::extension::CCEditBox::unregisterScriptEditBoxHandler() -> decltype(unregisterScriptEditBoxHandler()) {
	using FunctionType = decltype(unregisterScriptEditBoxHandler())(*)(cocos2d::extension::CCEditBox*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40d4f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
