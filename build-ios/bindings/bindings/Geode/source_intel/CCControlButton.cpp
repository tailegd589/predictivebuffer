
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCControlButton.hpp>
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

cocos2d::extension::CCControlButton::CCControlButton() : cocos2d::extension::CCControlButton(geode::CutoffConstructor, sizeof(cocos2d::extension::CCControlButton)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::extension::CCControlButton::~CCControlButton();

	using FunctionType = void(*)(cocos2d::extension::CCControlButton*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x353260, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::extension::CCControlButton::~CCControlButton() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::extension::CCControlButton*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x353440, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::extension::CCControlButton(geode::CutoffConstructor, sizeof(cocos2d::extension::CCControlButton));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::extension::CCControlButton::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3554d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::extension::CCControlButton::create(cocos2d::extension::CCScale9Sprite* p0) -> decltype(create(p0)) {
	using FunctionType = decltype(create(p0))(*)(cocos2d::extension::CCScale9Sprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x353dd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::extension::CCControlButton::create(cocos2d::CCNode* p0, cocos2d::extension::CCScale9Sprite* p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(cocos2d::CCNode*, cocos2d::extension::CCScale9Sprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x353a50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::extension::CCControlButton::create(gd::string p0, char const* p1, float p2) -> decltype(create(p0, p1, p2)) {
	using FunctionType = decltype(create(p0, p1, p2))(*)(gd::string, char const*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x353bf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::extension::CCControlButton::needsLayout() -> decltype(needsLayout()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCControlButton::needsLayout), this);
	using FunctionType = decltype(needsLayout())(*)(cocos2d::extension::CCControlButton*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3549c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCControlButton::setEnabled(bool p0) -> decltype(setEnabled(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::extension::CCControlButton::setEnabled), this);
	using FunctionType = decltype(setEnabled(p0))(*)(cocos2d::extension::CCControlButton*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x353f30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCControlButton::setSelected(bool p0) -> decltype(setSelected(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::extension::CCControlButton::setSelected), this);
	using FunctionType = decltype(setSelected(p0))(*)(cocos2d::extension::CCControlButton*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x353f50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCControlButton::setHighlighted(bool p0) -> decltype(setHighlighted(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::extension::CCControlButton::setHighlighted), this);
	using FunctionType = decltype(setHighlighted(p0))(*)(cocos2d::extension::CCControlButton*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x353f70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCControlButton::getPreferredSize() -> decltype(getPreferredSize()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCControlButton::getPreferredSize), this);
	using FunctionType = decltype(getPreferredSize())(*)(cocos2d::extension::CCControlButton*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x354120, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCControlButton::setPreferredSize(cocos2d::CCSize p0) -> decltype(setPreferredSize(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCSize>::func(&cocos2d::extension::CCControlButton::setPreferredSize), this);
	using FunctionType = decltype(setPreferredSize(p0))(*)(cocos2d::extension::CCControlButton*, cocos2d::CCSize);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x354060, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCControlButton::getZoomOnTouchDown() -> decltype(getZoomOnTouchDown()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCControlButton::getZoomOnTouchDown), this);
	using FunctionType = decltype(getZoomOnTouchDown())(*)(cocos2d::extension::CCControlButton*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x354050, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCControlButton::setZoomOnTouchDown(bool p0) -> decltype(setZoomOnTouchDown(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::extension::CCControlButton::setZoomOnTouchDown), this);
	using FunctionType = decltype(setZoomOnTouchDown(p0))(*)(cocos2d::extension::CCControlButton*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x354040, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCControlButton::getLabelAnchorPoint() -> decltype(getLabelAnchorPoint()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCControlButton::getLabelAnchorPoint), this);
	using FunctionType = decltype(getLabelAnchorPoint())(*)(cocos2d::extension::CCControlButton*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x354150, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCControlButton::setLabelAnchorPoint(cocos2d::CCPoint p0) -> decltype(setLabelAnchorPoint(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCPoint>::func(&cocos2d::extension::CCControlButton::setLabelAnchorPoint), this);
	using FunctionType = decltype(setLabelAnchorPoint(p0))(*)(cocos2d::extension::CCControlButton*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x354170, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCControlButton::getOpacity() -> decltype(getOpacity()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCControlButton::getOpacity), this);
	using FunctionType = decltype(getOpacity())(*)(cocos2d::extension::CCControlButton*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x355340, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCControlButton::setOpacity(unsigned char p0) -> decltype(setOpacity(p0)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned char>::func(&cocos2d::extension::CCControlButton::setOpacity), this);
	using FunctionType = decltype(setOpacity(p0))(*)(cocos2d::extension::CCControlButton*, unsigned char);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x355280, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCControlButton::getColor() -> decltype(getColor()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCControlButton::getColor), this);
	using FunctionType = decltype(getColor())(*)(cocos2d::extension::CCControlButton*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x355420, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCControlButton::setColor(cocos2d::ccColor3B const& p0) -> decltype(setColor(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccColor3B const&>::func(&cocos2d::extension::CCControlButton::setColor), this);
	using FunctionType = decltype(setColor(p0))(*)(cocos2d::extension::CCControlButton*, cocos2d::ccColor3B const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x355360, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCControlButton::setMargins(int p0, int p1) -> decltype(setMargins(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<int, int>::func(&cocos2d::extension::CCControlButton::setMargins), this);
	using FunctionType = decltype(setMargins(p0, p1))(*)(cocos2d::extension::CCControlButton*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x353f10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCControlButton::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCControlButton::init), this);
	using FunctionType = decltype(init())(*)(cocos2d::extension::CCControlButton*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3535c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCControlButton::initWithLabelAndBackgroundSprite(cocos2d::CCNode* p0, cocos2d::extension::CCScale9Sprite* p1) -> decltype(initWithLabelAndBackgroundSprite(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*, cocos2d::extension::CCScale9Sprite*>::func(&cocos2d::extension::CCControlButton::initWithLabelAndBackgroundSprite), this);
	using FunctionType = decltype(initWithLabelAndBackgroundSprite(p0, p1))(*)(cocos2d::extension::CCControlButton*, cocos2d::CCNode*, cocos2d::extension::CCScale9Sprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x353610, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCControlButton::initWithTitleAndFontNameAndFontSize(gd::string p0, char const* p1, float p2) -> decltype(initWithTitleAndFontNameAndFontSize(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string, char const*, float>::func(&cocos2d::extension::CCControlButton::initWithTitleAndFontNameAndFontSize), this);
	using FunctionType = decltype(initWithTitleAndFontNameAndFontSize(p0, p1, p2))(*)(cocos2d::extension::CCControlButton*, gd::string, char const*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x353ba0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}

auto cocos2d::extension::CCControlButton::initWithBackgroundSprite(cocos2d::extension::CCScale9Sprite* p0) -> decltype(initWithBackgroundSprite(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::extension::CCScale9Sprite*>::func(&cocos2d::extension::CCControlButton::initWithBackgroundSprite), this);
	using FunctionType = decltype(initWithBackgroundSprite(p0))(*)(cocos2d::extension::CCControlButton*, cocos2d::extension::CCScale9Sprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x353d80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCControlButton::ccTouchBegan(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) -> decltype(ccTouchBegan(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&cocos2d::extension::CCControlButton::ccTouchBegan), this);
	using FunctionType = decltype(ccTouchBegan(p0, p1))(*)(cocos2d::extension::CCControlButton*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x354ee0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCControlButton::ccTouchMoved(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) -> decltype(ccTouchMoved(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&cocos2d::extension::CCControlButton::ccTouchMoved), this);
	using FunctionType = decltype(ccTouchMoved(p0, p1))(*)(cocos2d::extension::CCControlButton*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x355080, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCControlButton::ccTouchEnded(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) -> decltype(ccTouchEnded(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&cocos2d::extension::CCControlButton::ccTouchEnded), this);
	using FunctionType = decltype(ccTouchEnded(p0, p1))(*)(cocos2d::extension::CCControlButton*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3551c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCControlButton::ccTouchCancelled(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) -> decltype(ccTouchCancelled(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&cocos2d::extension::CCControlButton::ccTouchCancelled), this);
	using FunctionType = decltype(ccTouchCancelled(p0, p1))(*)(cocos2d::extension::CCControlButton*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x355440, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCControlButton::getTitleForState(unsigned int p0) -> decltype(getTitleForState(p0)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned int>::func(&cocos2d::extension::CCControlButton::getTitleForState), this);
	using FunctionType = decltype(getTitleForState(p0))(*)(cocos2d::extension::CCControlButton*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3541b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCControlButton::setTitleForState(cocos2d::CCString* p0, unsigned int p1) -> decltype(setTitleForState(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCString*, unsigned int>::func(&cocos2d::extension::CCControlButton::setTitleForState), this);
	using FunctionType = decltype(setTitleForState(p0, p1))(*)(cocos2d::extension::CCControlButton*, cocos2d::CCString*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x354240, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCControlButton::getTitleColorForState(unsigned int p0) -> decltype(getTitleColorForState(p0)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned int>::func(&cocos2d::extension::CCControlButton::getTitleColorForState), this);
	using FunctionType = decltype(getTitleColorForState(p0))(*)(cocos2d::extension::CCControlButton*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3542b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCControlButton::setTitleColorForState(cocos2d::ccColor3B p0, unsigned int p1) -> decltype(setTitleColorForState(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccColor3B, unsigned int>::func(&cocos2d::extension::CCControlButton::setTitleColorForState), this);
	using FunctionType = decltype(setTitleColorForState(p0, p1))(*)(cocos2d::extension::CCControlButton*, cocos2d::ccColor3B, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x354310, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCControlButton::getTitleLabelForState(unsigned int p0) -> decltype(getTitleLabelForState(p0)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned int>::func(&cocos2d::extension::CCControlButton::getTitleLabelForState), this);
	using FunctionType = decltype(getTitleLabelForState(p0))(*)(cocos2d::extension::CCControlButton*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3543d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCControlButton::setTitleLabelForState(cocos2d::CCNode* p0, unsigned int p1) -> decltype(setTitleLabelForState(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*, unsigned int>::func(&cocos2d::extension::CCControlButton::setTitleLabelForState), this);
	using FunctionType = decltype(setTitleLabelForState(p0, p1))(*)(cocos2d::extension::CCControlButton*, cocos2d::CCNode*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x354410, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCControlButton::setTitleTTFForState(char const* p0, unsigned int p1) -> decltype(setTitleTTFForState(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<char const*, unsigned int>::func(&cocos2d::extension::CCControlButton::setTitleTTFForState), this);
	using FunctionType = decltype(setTitleTTFForState(p0, p1))(*)(cocos2d::extension::CCControlButton*, char const*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3544e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCControlButton::getTitleTTFForState(unsigned int p0) -> decltype(getTitleTTFForState(p0)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned int>::func(&cocos2d::extension::CCControlButton::getTitleTTFForState), this);
	using FunctionType = decltype(getTitleTTFForState(p0))(*)(cocos2d::extension::CCControlButton*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x354580, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCControlButton::setTitleTTFSizeForState(float p0, unsigned int p1) -> decltype(setTitleTTFSizeForState(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<float, unsigned int>::func(&cocos2d::extension::CCControlButton::setTitleTTFSizeForState), this);
	using FunctionType = decltype(setTitleTTFSizeForState(p0, p1))(*)(cocos2d::extension::CCControlButton*, float, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3545f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCControlButton::getTitleTTFSizeForState(unsigned int p0) -> decltype(getTitleTTFSizeForState(p0)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned int>::func(&cocos2d::extension::CCControlButton::getTitleTTFSizeForState), this);
	using FunctionType = decltype(getTitleTTFSizeForState(p0))(*)(cocos2d::extension::CCControlButton*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x354670, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCControlButton::setTitleBMFontForState(char const* p0, unsigned int p1) -> decltype(setTitleBMFontForState(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<char const*, unsigned int>::func(&cocos2d::extension::CCControlButton::setTitleBMFontForState), this);
	using FunctionType = decltype(setTitleBMFontForState(p0, p1))(*)(cocos2d::extension::CCControlButton*, char const*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3546e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCControlButton::getTitleBMFontForState(unsigned int p0) -> decltype(getTitleBMFontForState(p0)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned int>::func(&cocos2d::extension::CCControlButton::getTitleBMFontForState), this);
	using FunctionType = decltype(getTitleBMFontForState(p0))(*)(cocos2d::extension::CCControlButton*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x354780, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCControlButton::getBackgroundSpriteForState(unsigned int p0) -> decltype(getBackgroundSpriteForState(p0)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned int>::func(&cocos2d::extension::CCControlButton::getBackgroundSpriteForState), this);
	using FunctionType = decltype(getBackgroundSpriteForState(p0))(*)(cocos2d::extension::CCControlButton*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3547f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCControlButton::setBackgroundSpriteForState(cocos2d::extension::CCScale9Sprite* p0, unsigned int p1) -> decltype(setBackgroundSpriteForState(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::extension::CCScale9Sprite*, unsigned int>::func(&cocos2d::extension::CCControlButton::setBackgroundSpriteForState), this);
	using FunctionType = decltype(setBackgroundSpriteForState(p0, p1))(*)(cocos2d::extension::CCControlButton*, cocos2d::extension::CCScale9Sprite*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x354830, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCControlButton::setBackgroundSpriteFrameForState(cocos2d::CCSpriteFrame* p0, unsigned int p1) -> decltype(setBackgroundSpriteFrameForState(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCSpriteFrame*, unsigned int>::func(&cocos2d::extension::CCControlButton::setBackgroundSpriteFrameForState), this);
	using FunctionType = decltype(setBackgroundSpriteFrameForState(p0, p1))(*)(cocos2d::extension::CCControlButton*, cocos2d::CCSpriteFrame*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x354990, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCControlButton::doesAdjustBackgroundImage() -> decltype(doesAdjustBackgroundImage()) {
	using FunctionType = decltype(doesAdjustBackgroundImage())(*)(cocos2d::extension::CCControlButton*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x354140, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::extension::CCControlButton::setAdjustBackgroundImage(bool p0) -> decltype(setAdjustBackgroundImage(p0)) {
	using FunctionType = decltype(setAdjustBackgroundImage(p0))(*)(cocos2d::extension::CCControlButton*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x353a30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
