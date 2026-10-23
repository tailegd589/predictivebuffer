
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/TextArea.hpp>
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

auto TextArea::create(gd::string str, char const* font, float scale, float width, cocos2d::CCPoint anchor, float lineHeight, bool disableColor) -> decltype(create(str, font, scale, width, anchor, lineHeight, disableColor)) {
	using FunctionType = decltype(create(str, font, scale, width, anchor, lineHeight, disableColor))(*)(gd::string, char const*, float, float, cocos2d::CCPoint, float, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3219a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(str, font, scale, width, anchor, lineHeight, disableColor);
}

auto TextArea::update(float dt) -> decltype(update(dt)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&TextArea::update), this);
	using FunctionType = decltype(update(dt))(*)(TextArea*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x322660, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, dt);
}

auto TextArea::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&TextArea::draw), this);
	using FunctionType = decltype(draw())(*)(TextArea*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x322650, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto TextArea::setOpacity(unsigned char opacity) -> decltype(setOpacity(opacity)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned char>::func(&TextArea::setOpacity), this);
	using FunctionType = decltype(setOpacity(opacity))(*)(TextArea*, unsigned char);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3224b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, opacity);
}

auto TextArea::colorAllCharactersTo(cocos2d::ccColor3B color) -> decltype(colorAllCharactersTo(color)) {
	using FunctionType = decltype(colorAllCharactersTo(color))(*)(TextArea*, cocos2d::ccColor3B);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x322520, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, color);
}

auto TextArea::colorAllLabels(cocos2d::ccColor3B color) -> decltype(colorAllLabels(color)) {
	using FunctionType = decltype(colorAllLabels(color))(*)(TextArea*, cocos2d::ccColor3B);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3225d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, color);
}

auto TextArea::fadeIn(float duration, bool unused) -> decltype(fadeIn(duration, unused)) {
	using FunctionType = decltype(fadeIn(duration, unused))(*)(TextArea*, float, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3221f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, duration, unused);
}

auto TextArea::fadeInCharacters(float duration, float charDuration, bool fadeOut, TextFadeInStyle style) -> decltype(fadeInCharacters(duration, charDuration, fadeOut, style)) {
	using FunctionType = decltype(fadeInCharacters(duration, charDuration, fadeOut, style))(*)(TextArea*, float, float, bool, TextFadeInStyle);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x322800, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, duration, charDuration, fadeOut, style);
}

auto TextArea::fadeOut(float duration) -> decltype(fadeOut(duration)) {
	using FunctionType = decltype(fadeOut(duration))(*)(TextArea*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3223b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, duration);
}

auto TextArea::fadeOutAndRemove() -> decltype(fadeOutAndRemove()) {
	using FunctionType = decltype(fadeOutAndRemove())(*)(TextArea*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x322350, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto TextArea::finishFade() -> decltype(finishFade()) {
	using FunctionType = decltype(finishFade())(*)(TextArea*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x322320, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto TextArea::hideAll() -> decltype(hideAll()) {
	using FunctionType = decltype(hideAll())(*)(TextArea*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x321f80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto TextArea::init(gd::string str, char const* font, float scale, float width, cocos2d::CCPoint anchor, float lineHeight, bool disableColor) -> decltype(init(str, font, scale, width, anchor, lineHeight, disableColor)) {
	using FunctionType = decltype(init(str, font, scale, width, anchor, lineHeight, disableColor))(*)(TextArea*, gd::string, char const*, float, float, cocos2d::CCPoint, float, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x321b50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, str, font, scale, width, anchor, lineHeight, disableColor);
}

auto TextArea::setIgnoreColorCode(bool ignore) -> decltype(setIgnoreColorCode(ignore)) {
	using FunctionType = decltype(setIgnoreColorCode(ignore))(*)(TextArea*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x321f60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, ignore);
}

auto TextArea::setString(gd::string text) -> decltype(setString(text)) {
	using FunctionType = decltype(setString(text))(*)(TextArea*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x321c50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, text);
}

auto TextArea::showAll() -> decltype(showAll()) {
	using FunctionType = decltype(showAll())(*)(TextArea*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x322110, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto TextArea::stopAllCharacterActions() -> decltype(stopAllCharacterActions()) {
	using FunctionType = decltype(stopAllCharacterActions())(*)(TextArea*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x322050, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
