
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCLabelBMFont.hpp>
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

cocos2d::CCLabelBMFont::CCLabelBMFont() : cocos2d::CCLabelBMFont(geode::CutoffConstructor, sizeof(cocos2d::CCLabelBMFont)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCLabelBMFont::~CCLabelBMFont();

	using FunctionType = void(*)(cocos2d::CCLabelBMFont*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x504818, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCLabelBMFont::~CCLabelBMFont() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCLabelBMFont*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x5048f4, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCLabelBMFont(geode::CutoffConstructor, sizeof(cocos2d::CCLabelBMFont));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCLabelBMFont::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5040c4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCLabelBMFont::create(char const* p0, char const* p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(char const*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50438c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCLabelBMFont::create(char const* str, char const* fntFile, float width) -> decltype(create(str, fntFile, width)) {
	using FunctionType = decltype(create(str, fntFile, width))(*)(char const*, char const*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5042cc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(str, fntFile, width);
}

auto cocos2d::CCLabelBMFont::create(char const* str, char const* fntFile, float width, cocos2d::CCTextAlignment alignment) -> decltype(create(str, fntFile, width, alignment)) {
	using FunctionType = decltype(create(str, fntFile, width, alignment))(*)(char const*, char const*, float, cocos2d::CCTextAlignment);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x504148, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(str, fntFile, width, alignment);
}

auto cocos2d::CCLabelBMFont::create(char const* p0, char const* p1, float p2, cocos2d::CCTextAlignment p3, cocos2d::CCPoint p4) -> decltype(create(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(create(p0, p1, p2, p3, p4))(*)(char const*, char const*, float, cocos2d::CCTextAlignment, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50420c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3, p4);
}

auto cocos2d::CCLabelBMFont::createBatched(char const* p0, char const* p1, cocos2d::CCArray* p2, int p3) -> decltype(createBatched(p0, p1, p2, p3)) {
	using FunctionType = decltype(createBatched(p0, p1, p2, p3))(*)(char const*, char const*, cocos2d::CCArray*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x504700, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

auto cocos2d::CCLabelBMFont::purgeCachedData() -> decltype(purgeCachedData()) {
	using FunctionType = decltype(purgeCachedData())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50408c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCLabelBMFont::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLabelBMFont::init), this);
	using FunctionType = decltype(init())(*)(cocos2d::CCLabelBMFont*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5047c8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLabelBMFont::setScaleX(float p0) -> decltype(setScaleX(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCLabelBMFont::setScaleX), this);
	using FunctionType = decltype(setScaleX(p0))(*)(cocos2d::CCLabelBMFont*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x506b4c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLabelBMFont::setScaleY(float p0) -> decltype(setScaleY(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCLabelBMFont::setScaleY), this);
	using FunctionType = decltype(setScaleY(p0))(*)(cocos2d::CCLabelBMFont*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x506b78, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLabelBMFont::setScale(float p0) -> decltype(setScale(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCLabelBMFont::setScale), this);
	using FunctionType = decltype(setScale(p0))(*)(cocos2d::CCLabelBMFont*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x506b20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLabelBMFont::setAnchorPoint(cocos2d::CCPoint const& p0) -> decltype(setAnchorPoint(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCPoint const&>::func(&cocos2d::CCLabelBMFont::setAnchorPoint), this);
	using FunctionType = decltype(setAnchorPoint(p0))(*)(cocos2d::CCLabelBMFont*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x505d34, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLabelBMFont::setString(char const* p0) -> decltype(setString(p0)) {
	auto self = addresser::thunkAdjust(Resolve<char const*>::func(&cocos2d::CCLabelBMFont::setString), this);
	using FunctionType = decltype(setString(p0))(*)(cocos2d::CCLabelBMFont*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x505308, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLabelBMFont::setString(char const* p0, bool p1) -> decltype(setString(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<char const*, bool>::func(&cocos2d::CCLabelBMFont::setString), this);
	using FunctionType = decltype(setString(p0, p1))(*)(cocos2d::CCLabelBMFont*, char const*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50532c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCLabelBMFont::getString() -> decltype(getString()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLabelBMFont::getString), this);
	using FunctionType = decltype(getString())(*)(cocos2d::CCLabelBMFont*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x505554, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLabelBMFont::setCString(char const* p0) -> decltype(setCString(p0)) {
	auto self = addresser::thunkAdjust(Resolve<char const*>::func(&cocos2d::CCLabelBMFont::setCString), this);
	using FunctionType = decltype(setCString(p0))(*)(cocos2d::CCLabelBMFont*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50558c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLabelBMFont::updateLabel() -> decltype(updateLabel()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLabelBMFont::updateLabel), this);
	using FunctionType = decltype(updateLabel())(*)(cocos2d::CCLabelBMFont*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x505d88, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLabelBMFont::setAlignment(cocos2d::CCTextAlignment p0) -> decltype(setAlignment(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTextAlignment>::func(&cocos2d::CCLabelBMFont::setAlignment), this);
	using FunctionType = decltype(setAlignment(p0))(*)(cocos2d::CCLabelBMFont*, cocos2d::CCTextAlignment);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x506af0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLabelBMFont::setWidth(float p0) -> decltype(setWidth(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCLabelBMFont::setWidth), this);
	using FunctionType = decltype(setWidth(p0))(*)(cocos2d::CCLabelBMFont*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x506b00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLabelBMFont::setLineBreakWithoutSpace(bool p0) -> decltype(setLineBreakWithoutSpace(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCLabelBMFont::setLineBreakWithoutSpace), this);
	using FunctionType = decltype(setLineBreakWithoutSpace(p0))(*)(cocos2d::CCLabelBMFont*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x506b10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLabelBMFont::setString(unsigned short* p0, bool p1) -> decltype(setString(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned short*, bool>::func(&cocos2d::CCLabelBMFont::setString), this);
	using FunctionType = decltype(setString(p0, p1))(*)(cocos2d::CCLabelBMFont*, unsigned short*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5053b4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCLabelBMFont::setColor(cocos2d::ccColor3B const& p0) -> decltype(setColor(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccColor3B const&>::func(&cocos2d::CCLabelBMFont::setColor), this);
	using FunctionType = decltype(setColor(p0))(*)(cocos2d::CCLabelBMFont*, cocos2d::ccColor3B const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5055b8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLabelBMFont::getColor() -> decltype(getColor()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLabelBMFont::getColor), this);
	using FunctionType = decltype(getColor())(*)(cocos2d::CCLabelBMFont*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x505598, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLabelBMFont::getDisplayedColor() -> decltype(getDisplayedColor()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLabelBMFont::getDisplayedColor), this);
	using FunctionType = decltype(getDisplayedColor())(*)(cocos2d::CCLabelBMFont*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5055a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLabelBMFont::getDisplayedOpacity() -> decltype(getDisplayedOpacity()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLabelBMFont::getDisplayedOpacity), this);
	using FunctionType = decltype(getDisplayedOpacity())(*)(cocos2d::CCLabelBMFont*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50575c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLabelBMFont::getOpacity() -> decltype(getOpacity()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLabelBMFont::getOpacity), this);
	using FunctionType = decltype(getOpacity())(*)(cocos2d::CCLabelBMFont*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50574c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLabelBMFont::setOpacity(unsigned char p0) -> decltype(setOpacity(p0)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned char>::func(&cocos2d::CCLabelBMFont::setOpacity), this);
	using FunctionType = decltype(setOpacity(p0))(*)(cocos2d::CCLabelBMFont*, unsigned char);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50576c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLabelBMFont::setOpacityModifyRGB(bool p0) -> decltype(setOpacityModifyRGB(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCLabelBMFont::setOpacityModifyRGB), this);
	using FunctionType = decltype(setOpacityModifyRGB(p0))(*)(cocos2d::CCLabelBMFont*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5058d8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLabelBMFont::isOpacityModifyRGB() -> decltype(isOpacityModifyRGB()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLabelBMFont::isOpacityModifyRGB), this);
	using FunctionType = decltype(isOpacityModifyRGB())(*)(cocos2d::CCLabelBMFont*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x505a38, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLabelBMFont::isCascadeColorEnabled() -> decltype(isCascadeColorEnabled()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLabelBMFont::isCascadeColorEnabled), this);
	using FunctionType = decltype(isCascadeColorEnabled())(*)(cocos2d::CCLabelBMFont*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x505cf4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLabelBMFont::setCascadeColorEnabled(bool p0) -> decltype(setCascadeColorEnabled(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCLabelBMFont::setCascadeColorEnabled), this);
	using FunctionType = decltype(setCascadeColorEnabled(p0))(*)(cocos2d::CCLabelBMFont*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x505d04, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLabelBMFont::updateDisplayedColor(cocos2d::ccColor3B const& p0) -> decltype(updateDisplayedColor(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccColor3B const&>::func(&cocos2d::CCLabelBMFont::updateDisplayedColor), this);
	using FunctionType = decltype(updateDisplayedColor(p0))(*)(cocos2d::CCLabelBMFont*, cocos2d::ccColor3B const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x505b60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLabelBMFont::isCascadeOpacityEnabled() -> decltype(isCascadeOpacityEnabled()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLabelBMFont::isCascadeOpacityEnabled), this);
	using FunctionType = decltype(isCascadeOpacityEnabled())(*)(cocos2d::CCLabelBMFont*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x505d14, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLabelBMFont::setCascadeOpacityEnabled(bool p0) -> decltype(setCascadeOpacityEnabled(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCLabelBMFont::setCascadeOpacityEnabled), this);
	using FunctionType = decltype(setCascadeOpacityEnabled(p0))(*)(cocos2d::CCLabelBMFont*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x505d24, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLabelBMFont::updateDisplayedOpacity(unsigned char p0) -> decltype(updateDisplayedOpacity(p0)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned char>::func(&cocos2d::CCLabelBMFont::updateDisplayedOpacity), this);
	using FunctionType = decltype(updateDisplayedOpacity(p0))(*)(cocos2d::CCLabelBMFont*, unsigned char);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x505a48, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLabelBMFont::createFontChars() -> decltype(createFontChars()) {
	using FunctionType = decltype(createFontChars())(*)(cocos2d::CCLabelBMFont*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x504ae0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCLabelBMFont::getFntFile() -> decltype(getFntFile()) {
	using FunctionType = decltype(getFntFile())(*)(cocos2d::CCLabelBMFont*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x506c78, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCLabelBMFont::getLetterPosXLeft(cocos2d::CCSprite* p0, float p1, bool p2) -> decltype(getLetterPosXLeft(p0, p1, p2)) {
	using FunctionType = decltype(getLetterPosXLeft(p0, p1, p2))(*)(cocos2d::CCLabelBMFont*, cocos2d::CCSprite*, float, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5069a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCLabelBMFont::getLetterPosXRight(cocos2d::CCSprite* p0, float p1, bool p2) -> decltype(getLetterPosXRight(p0, p1, p2)) {
	using FunctionType = decltype(getLetterPosXRight(p0, p1, p2))(*)(cocos2d::CCLabelBMFont*, cocos2d::CCSprite*, float, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x506a4c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCLabelBMFont::initWithString(char const* p0, char const* p1, float p2, cocos2d::CCTextAlignment p3, cocos2d::CCPoint p4) -> decltype(initWithString(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(initWithString(p0, p1, p2, p3, p4))(*)(cocos2d::CCLabelBMFont*, char const*, char const*, float, cocos2d::CCTextAlignment, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x504454, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4);
}

auto cocos2d::CCLabelBMFont::kerningAmountForFirst(unsigned short p0, unsigned short p1) -> decltype(kerningAmountForFirst(p0, p1)) {
	using FunctionType = decltype(kerningAmountForFirst(p0, p1))(*)(cocos2d::CCLabelBMFont*, unsigned short, unsigned short);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5049c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCLabelBMFont::limitLabelWidth(float p0, float p1, float p2) -> decltype(limitLabelWidth(p0, p1, p2)) {
	using FunctionType = decltype(limitLabelWidth(p0, p1, p2))(*)(cocos2d::CCLabelBMFont*, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x506c9c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCLabelBMFont::setFntFile(char const* filename) -> decltype(setFntFile(filename)) {
	using FunctionType = decltype(setFntFile(filename))(*)(cocos2d::CCLabelBMFont*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x506ba4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, filename);
}
