
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCTextFieldTTF.hpp>
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

cocos2d::CCTextFieldTTF::CCTextFieldTTF() : cocos2d::CCTextFieldTTF(geode::CutoffConstructor, sizeof(cocos2d::CCTextFieldTTF)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCTextFieldTTF::~CCTextFieldTTF();

	using FunctionType = void(*)(cocos2d::CCTextFieldTTF*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x21deb8, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCTextFieldTTF::~CCTextFieldTTF() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCTextFieldTTF*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x21df84, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCTextFieldTTF(geode::CutoffConstructor, sizeof(cocos2d::CCTextFieldTTF));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCTextFieldTTF::textFieldWithPlaceHolder(const char* placeholder, const char* fontName, float fontSize) -> decltype(textFieldWithPlaceHolder(placeholder, fontName, fontSize)) {
	using FunctionType = decltype(textFieldWithPlaceHolder(placeholder, fontName, fontSize))(*)(const char*, const char*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x21e25c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(placeholder, fontName, fontSize);
}

auto cocos2d::CCTextFieldTTF::textFieldWithPlaceHolder(const char* placeholder, const cocos2d::CCSize& dimensions, cocos2d::CCTextAlignment alignment, const char* fontName, float fontSize) -> decltype(textFieldWithPlaceHolder(placeholder, dimensions, alignment, fontName, fontSize)) {
	using FunctionType = decltype(textFieldWithPlaceHolder(placeholder, dimensions, alignment, fontName, fontSize))(*)(const char*, const cocos2d::CCSize&, cocos2d::CCTextAlignment, const char*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x21e058, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(placeholder, dimensions, alignment, fontName, fontSize);
}

auto cocos2d::CCTextFieldTTF::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTextFieldTTF::draw), this);
	using FunctionType = decltype(draw())(*)(cocos2d::CCTextFieldTTF*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x21ece4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTextFieldTTF::getColorSpaceHolder() -> decltype(getColorSpaceHolder()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTextFieldTTF::getColorSpaceHolder), this);
	using FunctionType = decltype(getColorSpaceHolder())(*)(cocos2d::CCTextFieldTTF*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x21eda0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTextFieldTTF::setColorSpaceHolder(const cocos2d::ccColor3B& color) -> decltype(setColorSpaceHolder(color)) {
	auto self = addresser::thunkAdjust(Resolve<const cocos2d::ccColor3B&>::func(&cocos2d::CCTextFieldTTF::setColorSpaceHolder), this);
	using FunctionType = decltype(setColorSpaceHolder(color))(*)(cocos2d::CCTextFieldTTF*, const cocos2d::ccColor3B&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x21eda8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, color);
}

auto cocos2d::CCTextFieldTTF::getPlaceHolder() -> decltype(getPlaceHolder()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTextFieldTTF::getPlaceHolder), this);
	using FunctionType = decltype(getPlaceHolder())(*)(cocos2d::CCTextFieldTTF*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x21f1ac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTextFieldTTF::setPlaceHolder(const char* text) -> decltype(setPlaceHolder(text)) {
	auto self = addresser::thunkAdjust(Resolve<const char*>::func(&cocos2d::CCTextFieldTTF::setPlaceHolder), this);
	using FunctionType = decltype(setPlaceHolder(text))(*)(cocos2d::CCTextFieldTTF*, const char*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x21f060, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, text);
}

auto cocos2d::CCTextFieldTTF::setSecureTextEntry(bool value) -> decltype(setSecureTextEntry(value)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCTextFieldTTF::setSecureTextEntry), this);
	using FunctionType = decltype(setSecureTextEntry(value))(*)(cocos2d::CCTextFieldTTF*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x21f1c4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, value);
}

auto cocos2d::CCTextFieldTTF::isSecureTextEntry() -> decltype(isSecureTextEntry()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTextFieldTTF::isSecureTextEntry), this);
	using FunctionType = decltype(isSecureTextEntry())(*)(cocos2d::CCTextFieldTTF*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x21f210, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTextFieldTTF::setString(const char* text) -> decltype(setString(text)) {
	auto self = addresser::thunkAdjust(Resolve<const char*>::func(&cocos2d::CCTextFieldTTF::setString), this);
	using FunctionType = decltype(setString(text))(*)(cocos2d::CCTextFieldTTF*, const char*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x21edbc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, text);
}

auto cocos2d::CCTextFieldTTF::getString() -> decltype(getString()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTextFieldTTF::getString), this);
	using FunctionType = decltype(getString())(*)(cocos2d::CCTextFieldTTF*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x21f030, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTextFieldTTF::attachWithIME() -> decltype(attachWithIME()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTextFieldTTF::attachWithIME), this);
	using FunctionType = decltype(attachWithIME())(*)(cocos2d::CCTextFieldTTF*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x21e444, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTextFieldTTF::detachWithIME() -> decltype(detachWithIME()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTextFieldTTF::detachWithIME), this);
	using FunctionType = decltype(detachWithIME())(*)(cocos2d::CCTextFieldTTF*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x21e4d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTextFieldTTF::canAttachWithIME() -> decltype(canAttachWithIME()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTextFieldTTF::canAttachWithIME), this);
	using FunctionType = decltype(canAttachWithIME())(*)(cocos2d::CCTextFieldTTF*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x21e55c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTextFieldTTF::canDetachWithIME() -> decltype(canDetachWithIME()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTextFieldTTF::canDetachWithIME), this);
	using FunctionType = decltype(canDetachWithIME())(*)(cocos2d::CCTextFieldTTF*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x21e5c8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTextFieldTTF::insertText(const char* text, int len, cocos2d::enumKeyCodes keyCode) -> decltype(insertText(text, len, keyCode)) {
	auto self = addresser::thunkAdjust(Resolve<const char*, int, cocos2d::enumKeyCodes>::func(&cocos2d::CCTextFieldTTF::insertText), this);
	using FunctionType = decltype(insertText(text, len, keyCode))(*)(cocos2d::CCTextFieldTTF*, const char*, int, cocos2d::enumKeyCodes);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x21e634, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, text, len, keyCode);
}

auto cocos2d::CCTextFieldTTF::deleteBackward() -> decltype(deleteBackward()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTextFieldTTF::deleteBackward), this);
	using FunctionType = decltype(deleteBackward())(*)(cocos2d::CCTextFieldTTF*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x21e9ac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTextFieldTTF::deleteForward() -> decltype(deleteForward()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTextFieldTTF::deleteForward), this);
	using FunctionType = decltype(deleteForward())(*)(cocos2d::CCTextFieldTTF*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x21e94c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTextFieldTTF::getContentText() -> decltype(getContentText()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTextFieldTTF::getContentText), this);
	using FunctionType = decltype(getContentText())(*)(cocos2d::CCTextFieldTTF*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x21ecb4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTextFieldTTF::initWithPlaceHolder(const char* placeholder, const char* fontName, float fontSize) -> decltype(initWithPlaceHolder(placeholder, fontName, fontSize)) {
	using FunctionType = decltype(initWithPlaceHolder(placeholder, fontName, fontSize))(*)(cocos2d::CCTextFieldTTF*, const char*, const char*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x21e320, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, placeholder, fontName, fontSize);
}

auto cocos2d::CCTextFieldTTF::initWithPlaceHolder(const char* placeholder, const cocos2d::CCSize& dimensions, cocos2d::CCTextAlignment alignment, const char* fontName, float fontSize) -> decltype(initWithPlaceHolder(placeholder, dimensions, alignment, fontName, fontSize)) {
	using FunctionType = decltype(initWithPlaceHolder(placeholder, dimensions, alignment, fontName, fontSize))(*)(cocos2d::CCTextFieldTTF*, const char*, const cocos2d::CCSize&, cocos2d::CCTextAlignment, const char*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x21e120, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, placeholder, dimensions, alignment, fontName, fontSize);
}
