
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCLabelTTF.hpp>
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

cocos2d::CCLabelTTF::CCLabelTTF() : cocos2d::CCLabelTTF(geode::CutoffConstructor, sizeof(cocos2d::CCLabelTTF)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCLabelTTF::~CCLabelTTF();

	using FunctionType = void(*)(cocos2d::CCLabelTTF*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3bd080, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCLabelTTF::~CCLabelTTF() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCLabelTTF*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x3bd240, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCLabelTTF(geode::CutoffConstructor, sizeof(cocos2d::CCLabelTTF));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCLabelTTF::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3bd400, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCLabelTTF::create(char const* string, char const* fontName, float fontSize) -> decltype(create(string, fontName, fontSize)) {
	using FunctionType = decltype(create(string, fontName, fontSize))(*)(char const*, char const*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3bd520, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(string, fontName, fontSize);
}

auto cocos2d::CCLabelTTF::create(char const* string, char const* fontName, float fontSize, cocos2d::CCSize const& dimensions, cocos2d::CCTextAlignment hAlignment) -> decltype(create(string, fontName, fontSize, dimensions, hAlignment)) {
	using FunctionType = decltype(create(string, fontName, fontSize, dimensions, hAlignment))(*)(char const*, char const*, float, cocos2d::CCSize const&, cocos2d::CCTextAlignment);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3bd6a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(string, fontName, fontSize, dimensions, hAlignment);
}

auto cocos2d::CCLabelTTF::create(char const* string, char const* fontName, float fontSize, cocos2d::CCSize const& dimensions, cocos2d::CCTextAlignment hAlignment, cocos2d::CCVerticalTextAlignment vAlignment) -> decltype(create(string, fontName, fontSize, dimensions, hAlignment, vAlignment)) {
	using FunctionType = decltype(create(string, fontName, fontSize, dimensions, hAlignment, vAlignment))(*)(char const*, char const*, float, cocos2d::CCSize const&, cocos2d::CCTextAlignment, cocos2d::CCVerticalTextAlignment);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3bd540, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(string, fontName, fontSize, dimensions, hAlignment, vAlignment);
}

auto cocos2d::CCLabelTTF::createWithFontDefinition(char const* p0, cocos2d::ccFontDefinition& p1) -> decltype(createWithFontDefinition(p0, p1)) {
	using FunctionType = decltype(createWithFontDefinition(p0, p1))(*)(char const*, cocos2d::ccFontDefinition&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3bd820, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCLabelTTF::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLabelTTF::init), this);
	using FunctionType = decltype(init())(*)(cocos2d::CCLabelTTF*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3bda00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLabelTTF::setString(char const* p0) -> decltype(setString(p0)) {
	auto self = addresser::thunkAdjust(Resolve<char const*>::func(&cocos2d::CCLabelTTF::setString), this);
	using FunctionType = decltype(setString(p0))(*)(cocos2d::CCLabelTTF*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3bdb30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLabelTTF::getString() -> decltype(getString()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLabelTTF::getString), this);
	using FunctionType = decltype(getString())(*)(cocos2d::CCLabelTTF*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3bdd60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLabelTTF::_prepareTextDefinition(bool p0) -> decltype(_prepareTextDefinition(p0)) {
	using FunctionType = decltype(_prepareTextDefinition(p0))(*)(cocos2d::CCLabelTTF*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3be2a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCLabelTTF::_updateWithTextDefinition(cocos2d::ccFontDefinition& p0, bool p1) -> decltype(_updateWithTextDefinition(p0, p1)) {
	using FunctionType = decltype(_updateWithTextDefinition(p0, p1))(*)(cocos2d::CCLabelTTF*, cocos2d::ccFontDefinition&, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3bda60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCLabelTTF::description() -> decltype(description()) {
	using FunctionType = decltype(description())(*)(cocos2d::CCLabelTTF*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3bddb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCLabelTTF::disableShadow(bool p0) -> decltype(disableShadow(p0)) {
	using FunctionType = decltype(disableShadow(p0))(*)(cocos2d::CCLabelTTF*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3be0f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCLabelTTF::disableStroke(bool p0) -> decltype(disableStroke(p0)) {
	using FunctionType = decltype(disableStroke(p0))(*)(cocos2d::CCLabelTTF*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3be110, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCLabelTTF::enableShadow(cocos2d::CCSize const& p0, float p1, float p2, bool p3) -> decltype(enableShadow(p0, p1, p2, p3)) {
	using FunctionType = decltype(enableShadow(p0, p1, p2, p3))(*)(cocos2d::CCLabelTTF*, cocos2d::CCSize const&, float, float, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3be0e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto cocos2d::CCLabelTTF::enableStroke(cocos2d::ccColor3B const& p0, float p1, bool p2) -> decltype(enableStroke(p0, p1, p2)) {
	using FunctionType = decltype(enableStroke(p0, p1, p2))(*)(cocos2d::CCLabelTTF*, cocos2d::ccColor3B const&, float, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3be100, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCLabelTTF::getFontName() -> decltype(getFontName()) {
	using FunctionType = decltype(getFontName())(*)(cocos2d::CCLabelTTF*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3bdf80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCLabelTTF::getTextDefinition() -> decltype(getTextDefinition()) {
	using FunctionType = decltype(getTextDefinition())(*)(cocos2d::CCLabelTTF*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3be150, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCLabelTTF::initWithString(char const* label, char const* fontName, float fontSize) -> decltype(initWithString(label, fontName, fontSize)) {
	using FunctionType = decltype(initWithString(label, fontName, fontSize))(*)(cocos2d::CCLabelTTF*, char const*, char const*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3bda30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, label, fontName, fontSize);
}

auto cocos2d::CCLabelTTF::initWithString(char const* label, char const* fontName, float fontSize, cocos2d::CCSize const& dimensions, cocos2d::CCTextAlignment alignment) -> decltype(initWithString(label, fontName, fontSize, dimensions, alignment)) {
	using FunctionType = decltype(initWithString(label, fontName, fontSize, dimensions, alignment))(*)(cocos2d::CCLabelTTF*, char const*, char const*, float, cocos2d::CCSize const&, cocos2d::CCTextAlignment);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3bda50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, label, fontName, fontSize, dimensions, alignment);
}

auto cocos2d::CCLabelTTF::initWithString(char const* p0, char const* p1, float p2, cocos2d::CCSize const& p3, cocos2d::CCTextAlignment p4, cocos2d::CCVerticalTextAlignment p5) -> decltype(initWithString(p0, p1, p2, p3, p4, p5)) {
	using FunctionType = decltype(initWithString(p0, p1, p2, p3, p4, p5))(*)(cocos2d::CCLabelTTF*, char const*, char const*, float, cocos2d::CCSize const&, cocos2d::CCTextAlignment, cocos2d::CCVerticalTextAlignment);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3bd6b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5);
}

auto cocos2d::CCLabelTTF::initWithStringAndTextDefinition(char const* p0, cocos2d::ccFontDefinition& p1) -> decltype(initWithStringAndTextDefinition(p0, p1)) {
	using FunctionType = decltype(initWithStringAndTextDefinition(p0, p1))(*)(cocos2d::CCLabelTTF*, char const*, cocos2d::ccFontDefinition&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3bd990, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCLabelTTF::setFontFillColor(cocos2d::ccColor3B const& p0, bool p1) -> decltype(setFontFillColor(p0, p1)) {
	using FunctionType = decltype(setFontFillColor(p0, p1))(*)(cocos2d::CCLabelTTF*, cocos2d::ccColor3B const&, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3be120, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCLabelTTF::setFontName(char const* p0) -> decltype(setFontName(p0)) {
	using FunctionType = decltype(setFontName(p0))(*)(cocos2d::CCLabelTTF*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3bdfa0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCLabelTTF::setTextDefinition(cocos2d::ccFontDefinition* p0) -> decltype(setTextDefinition(p0)) {
	using FunctionType = decltype(setTextDefinition(p0))(*)(cocos2d::CCLabelTTF*, cocos2d::ccFontDefinition*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3be130, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCLabelTTF::updateTexture() -> decltype(updateTexture()) {
	using FunctionType = decltype(updateTexture())(*)(cocos2d::CCLabelTTF*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3bdb80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
