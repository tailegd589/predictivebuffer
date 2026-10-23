
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/BoomScrollLayer.hpp>
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

BoomScrollLayer::BoomScrollLayer() : BoomScrollLayer(geode::CutoffConstructor, sizeof(BoomScrollLayer)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	BoomScrollLayer::~BoomScrollLayer();

	using FunctionType = void(*)(BoomScrollLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32bce4, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

BoomScrollLayer::~BoomScrollLayer() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(BoomScrollLayer*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x32a7dc, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) BoomScrollLayer(geode::CutoffConstructor, sizeof(BoomScrollLayer));
		geode::DestructorLock::addLock(this);
	}
}

auto BoomScrollLayer::create(cocos2d::CCArray* pages, int offset, bool looped) -> decltype(create(pages, offset, looped)) {
	using FunctionType = decltype(create(pages, offset, looped))(*)(cocos2d::CCArray*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3298e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(pages, offset, looped);
}

auto BoomScrollLayer::create(cocos2d::CCArray* pages, int offset, bool looped, cocos2d::CCArray* dynamicObjects, DynamicScrollDelegate* delegate) -> decltype(create(pages, offset, looped, dynamicObjects, delegate)) {
	using FunctionType = decltype(create(pages, offset, looped, dynamicObjects, delegate))(*)(cocos2d::CCArray*, int, bool, cocos2d::CCArray*, DynamicScrollDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32951c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(pages, offset, looped, dynamicObjects, delegate);
}

auto BoomScrollLayer::visit() -> decltype(visit()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&BoomScrollLayer::visit), this);
	using FunctionType = decltype(visit())(*)(BoomScrollLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32ab78, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto BoomScrollLayer::ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchBegan(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&BoomScrollLayer::ccTouchBegan), this);
	using FunctionType = decltype(ccTouchBegan(touch, event))(*)(BoomScrollLayer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32b680, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto BoomScrollLayer::ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchMoved(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&BoomScrollLayer::ccTouchMoved), this);
	using FunctionType = decltype(ccTouchMoved(touch, event))(*)(BoomScrollLayer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32b75c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto BoomScrollLayer::ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchEnded(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&BoomScrollLayer::ccTouchEnded), this);
	using FunctionType = decltype(ccTouchEnded(touch, event))(*)(BoomScrollLayer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32ba28, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto BoomScrollLayer::ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchCancelled(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&BoomScrollLayer::ccTouchCancelled), this);
	using FunctionType = decltype(ccTouchCancelled(touch, event))(*)(BoomScrollLayer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32b4c4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto BoomScrollLayer::registerWithTouchDispatcher() -> decltype(registerWithTouchDispatcher()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&BoomScrollLayer::registerWithTouchDispatcher), this);
	using FunctionType = decltype(registerWithTouchDispatcher())(*)(BoomScrollLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32b34c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto BoomScrollLayer::addPage(cocos2d::CCLayer* page) -> decltype(addPage(page)) {
	using FunctionType = decltype(addPage(page))(*)(BoomScrollLayer*, cocos2d::CCLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32b118, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page);
}

auto BoomScrollLayer::addPage(cocos2d::CCLayer* page, int index) -> decltype(addPage(page, index)) {
	using FunctionType = decltype(addPage(page, index))(*)(BoomScrollLayer*, cocos2d::CCLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32b188, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page, index);
}

auto BoomScrollLayer::cancelAndStoleTouch(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(cancelAndStoleTouch(touch, event)) {
	using FunctionType = decltype(cancelAndStoleTouch(touch, event))(*)(BoomScrollLayer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32b3e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, touch, event);
}

auto BoomScrollLayer::claimTouch(cocos2d::CCTouch* touch) -> decltype(claimTouch(touch)) {
	using FunctionType = decltype(claimTouch(touch))(*)(BoomScrollLayer*, cocos2d::CCTouch*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32b384, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, touch);
}

auto BoomScrollLayer::getPage(int page) -> decltype(getPage(page)) {
	using FunctionType = decltype(getPage(page))(*)(BoomScrollLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32a774, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page);
}

auto BoomScrollLayer::getRelativePageForNum(int page) -> decltype(getRelativePageForNum(page)) {
	using FunctionType = decltype(getRelativePageForNum(page))(*)(BoomScrollLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32aaa4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page);
}

auto BoomScrollLayer::getRelativePosForPage(int page) -> decltype(getRelativePosForPage(page)) {
	using FunctionType = decltype(getRelativePosForPage(page))(*)(BoomScrollLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32a724, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page);
}

auto BoomScrollLayer::getTotalPages() -> decltype(getTotalPages()) {
	using FunctionType = decltype(getTotalPages())(*)(BoomScrollLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32a414, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto BoomScrollLayer::init(cocos2d::CCArray* pages, int offset, bool looped, cocos2d::CCArray* dynamicObjects, DynamicScrollDelegate* delegate) -> decltype(init(pages, offset, looped, dynamicObjects, delegate)) {
	using FunctionType = decltype(init(pages, offset, looped, dynamicObjects, delegate))(*)(BoomScrollLayer*, cocos2d::CCArray*, int, bool, cocos2d::CCArray*, DynamicScrollDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3295d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, pages, offset, looped, dynamicObjects, delegate);
}

auto BoomScrollLayer::instantMoveToPage(int page) -> decltype(instantMoveToPage(page)) {
	using FunctionType = decltype(instantMoveToPage(page))(*)(BoomScrollLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32ad8c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page);
}

auto BoomScrollLayer::moveToPage(int page) -> decltype(moveToPage(page)) {
	using FunctionType = decltype(moveToPage(page))(*)(BoomScrollLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32ae64, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page);
}

auto BoomScrollLayer::moveToPageEnded() -> decltype(moveToPageEnded()) {
	using FunctionType = decltype(moveToPageEnded())(*)(BoomScrollLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32abfc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto BoomScrollLayer::pageNumberForPosition(cocos2d::CCPoint position) -> decltype(pageNumberForPosition(position)) {
	using FunctionType = decltype(pageNumberForPosition(position))(*)(BoomScrollLayer*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32a9cc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, position);
}

auto BoomScrollLayer::positionForPageWithNumber(int page) -> decltype(positionForPageWithNumber(page)) {
	using FunctionType = decltype(positionForPageWithNumber(page))(*)(BoomScrollLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32ad38, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page);
}

auto BoomScrollLayer::quickUpdate() -> decltype(quickUpdate()) {
	using FunctionType = decltype(quickUpdate())(*)(BoomScrollLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32b0c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto BoomScrollLayer::removePage(cocos2d::CCLayer* page) -> decltype(removePage(page)) {
	using FunctionType = decltype(removePage(page))(*)(BoomScrollLayer*, cocos2d::CCLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32b1f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page);
}

auto BoomScrollLayer::removePageWithNumber(int page) -> decltype(removePageWithNumber(page)) {
	using FunctionType = decltype(removePageWithNumber(page))(*)(BoomScrollLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32b284, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page);
}

auto BoomScrollLayer::repositionPagesLooped() -> decltype(repositionPagesLooped()) {
	using FunctionType = decltype(repositionPagesLooped())(*)(BoomScrollLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x329b7c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto BoomScrollLayer::selectPage(int page) -> decltype(selectPage(page)) {
	using FunctionType = decltype(selectPage(page))(*)(BoomScrollLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32b008, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page);
}

auto BoomScrollLayer::setDotScale(float scale) -> decltype(setDotScale(scale)) {
	using FunctionType = decltype(setDotScale(scale))(*)(BoomScrollLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32a6bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, scale);
}

auto BoomScrollLayer::setPagesIndicatorPosition(cocos2d::CCPoint pos) -> decltype(setPagesIndicatorPosition(pos)) {
	using FunctionType = decltype(setPagesIndicatorPosition(pos))(*)(BoomScrollLayer*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x329a34, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, pos);
}

auto BoomScrollLayer::setupDynamicScrolling(cocos2d::CCArray* dynamicObjects, DynamicScrollDelegate* delegate) -> decltype(setupDynamicScrolling(dynamicObjects, delegate)) {
	using FunctionType = decltype(setupDynamicScrolling(dynamicObjects, delegate))(*)(BoomScrollLayer*, cocos2d::CCArray*, DynamicScrollDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32a1cc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dynamicObjects, delegate);
}

auto BoomScrollLayer::togglePageIndicators(bool visible) -> decltype(togglePageIndicators(visible)) {
	using FunctionType = decltype(togglePageIndicators(visible))(*)(BoomScrollLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32ab0c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, visible);
}

auto BoomScrollLayer::updateDots(float dt) -> decltype(updateDots(dt)) {
	using FunctionType = decltype(updateDots(dt))(*)(BoomScrollLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32a430, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}

auto BoomScrollLayer::updatePages() -> decltype(updatePages()) {
	using FunctionType = decltype(updatePages())(*)(BoomScrollLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x329a5c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
