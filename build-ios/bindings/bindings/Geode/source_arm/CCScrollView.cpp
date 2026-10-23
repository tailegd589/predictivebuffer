
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCScrollView.hpp>
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

cocos2d::extension::CCScrollView::CCScrollView() : cocos2d::extension::CCScrollView(geode::CutoffConstructor, sizeof(cocos2d::extension::CCScrollView)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::extension::CCScrollView::~CCScrollView();

	using FunctionType = void(*)(cocos2d::extension::CCScrollView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x36fcb0, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::extension::CCScrollView::~CCScrollView() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::extension::CCScrollView*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x36fd9c, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::extension::CCScrollView(geode::CutoffConstructor, sizeof(cocos2d::extension::CCScrollView));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::extension::CCScrollView::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x370258, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::extension::CCScrollView::create(cocos2d::CCSize p0, cocos2d::CCNode* p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(cocos2d::CCSize, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x370048, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::extension::CCScrollView::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCScrollView::init), this);
	using FunctionType = decltype(init())(*)(cocos2d::extension::CCScrollView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x370308, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCScrollView::registerWithTouchDispatcher() -> decltype(registerWithTouchDispatcher()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCScrollView::registerWithTouchDispatcher), this);
	using FunctionType = decltype(registerWithTouchDispatcher())(*)(cocos2d::extension::CCScrollView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x370350, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCScrollView::ccTouchBegan(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) -> decltype(ccTouchBegan(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&cocos2d::extension::CCScrollView::ccTouchBegan), this);
	using FunctionType = decltype(ccTouchBegan(p0, p1))(*)(cocos2d::extension::CCScrollView*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3717f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCScrollView::ccTouchMoved(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) -> decltype(ccTouchMoved(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&cocos2d::extension::CCScrollView::ccTouchMoved), this);
	using FunctionType = decltype(ccTouchMoved(p0, p1))(*)(cocos2d::extension::CCScrollView*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x371a50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCScrollView::ccTouchEnded(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) -> decltype(ccTouchEnded(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&cocos2d::extension::CCScrollView::ccTouchEnded), this);
	using FunctionType = decltype(ccTouchEnded(p0, p1))(*)(cocos2d::extension::CCScrollView*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x371d7c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCScrollView::ccTouchCancelled(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) -> decltype(ccTouchCancelled(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&cocos2d::extension::CCScrollView::ccTouchCancelled), this);
	using FunctionType = decltype(ccTouchCancelled(p0, p1))(*)(cocos2d::extension::CCScrollView*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x371e2c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCScrollView::setContentSize(cocos2d::CCSize const& p0) -> decltype(setContentSize(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCSize const&>::func(&cocos2d::extension::CCScrollView::setContentSize), this);
	using FunctionType = decltype(setContentSize(p0))(*)(cocos2d::extension::CCScrollView*, cocos2d::CCSize const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3710e4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCScrollView::getContentSize() const  -> decltype(getContentSize()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCScrollView::getContentSize), this);
	using FunctionType = decltype(getContentSize())(*)(cocos2d::extension::CCScrollView const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3710d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCScrollView::visit() -> decltype(visit()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCScrollView::visit), this);
	using FunctionType = decltype(visit())(*)(cocos2d::extension::CCScrollView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x371654, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCScrollView::addChild(cocos2d::CCNode* p0, int p1, int p2) -> decltype(addChild(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*, int, int>::func(&cocos2d::extension::CCScrollView::addChild), this);
	using FunctionType = decltype(addChild(p0, p1, p2))(*)(cocos2d::extension::CCScrollView*, cocos2d::CCNode*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x371250, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}

auto cocos2d::extension::CCScrollView::addChild(cocos2d::CCNode* p0, int p1) -> decltype(addChild(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*, int>::func(&cocos2d::extension::CCScrollView::addChild), this);
	using FunctionType = decltype(addChild(p0, p1))(*)(cocos2d::extension::CCScrollView*, cocos2d::CCNode*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37130c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCScrollView::addChild(cocos2d::CCNode* p0) -> decltype(addChild(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*>::func(&cocos2d::extension::CCScrollView::addChild), this);
	using FunctionType = decltype(addChild(p0))(*)(cocos2d::extension::CCScrollView*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x371360, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCScrollView::setTouchEnabled(bool p0) -> decltype(setTouchEnabled(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::extension::CCScrollView::setTouchEnabled), this);
	using FunctionType = decltype(setTouchEnabled(p0))(*)(cocos2d::extension::CCScrollView*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x370570, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCScrollView::afterDraw() -> decltype(afterDraw()) {
	using FunctionType = decltype(afterDraw())(*)(cocos2d::extension::CCScrollView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3715f8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::extension::CCScrollView::beforeDraw() -> decltype(beforeDraw()) {
	using FunctionType = decltype(beforeDraw())(*)(cocos2d::extension::CCScrollView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3713c4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::extension::CCScrollView::deaccelerateScrolling(float p0) -> decltype(deaccelerateScrolling(p0)) {
	using FunctionType = decltype(deaccelerateScrolling(p0))(*)(cocos2d::extension::CCScrollView*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x370dbc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCScrollView::getContainer() -> decltype(getContainer()) {
	using FunctionType = decltype(getContainer())(*)(cocos2d::extension::CCScrollView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x370b6c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::extension::CCScrollView::getContentOffset() -> decltype(getContentOffset()) {
	using FunctionType = decltype(getContentOffset())(*)(cocos2d::extension::CCScrollView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x370458, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::extension::CCScrollView::getScriptHandler(int p0) -> decltype(getScriptHandler(p0)) {
	using FunctionType = decltype(getScriptHandler(p0))(*)(cocos2d::extension::CCScrollView*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37205c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCScrollView::getViewRect() -> decltype(getViewRect()) {
	using FunctionType = decltype(getViewRect())(*)(cocos2d::extension::CCScrollView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3714e4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::extension::CCScrollView::getZoomScale() -> decltype(getZoomScale()) {
	using FunctionType = decltype(getZoomScale())(*)(cocos2d::extension::CCScrollView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37048c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::extension::CCScrollView::initWithViewSize(cocos2d::CCSize p0, cocos2d::CCNode* p1) -> decltype(initWithViewSize(p0, p1)) {
	using FunctionType = decltype(initWithViewSize(p0, p1))(*)(cocos2d::extension::CCScrollView*, cocos2d::CCSize, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3700f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::extension::CCScrollView::isNodeVisible(cocos2d::CCNode* p0) -> decltype(isNodeVisible(p0)) {
	using FunctionType = decltype(isNodeVisible(p0))(*)(cocos2d::extension::CCScrollView*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x370398, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCScrollView::maxContainerOffset() -> decltype(maxContainerOffset()) {
	using FunctionType = decltype(maxContainerOffset())(*)(cocos2d::extension::CCScrollView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x370828, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::extension::CCScrollView::minContainerOffset() -> decltype(minContainerOffset()) {
	using FunctionType = decltype(minContainerOffset())(*)(cocos2d::extension::CCScrollView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x370798, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::extension::CCScrollView::pause(cocos2d::CCObject* p0) -> decltype(pause(p0)) {
	using FunctionType = decltype(pause(p0))(*)(cocos2d::extension::CCScrollView*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37049c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCScrollView::performedAnimatedScroll(float p0) -> decltype(performedAnimatedScroll(p0)) {
	using FunctionType = decltype(performedAnimatedScroll(p0))(*)(cocos2d::extension::CCScrollView*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x370884, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCScrollView::registerScriptHandler(int p0, int p1) -> decltype(registerScriptHandler(p0, p1)) {
	using FunctionType = decltype(registerScriptHandler(p0, p1))(*)(cocos2d::extension::CCScrollView*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x371ef0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::extension::CCScrollView::relocateContainer(bool p0) -> decltype(relocateContainer(p0)) {
	using FunctionType = decltype(relocateContainer(p0))(*)(cocos2d::extension::CCScrollView*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x370c28, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCScrollView::resume(cocos2d::CCObject* p0) -> decltype(resume(p0)) {
	using FunctionType = decltype(resume(p0))(*)(cocos2d::extension::CCScrollView*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x370504, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCScrollView::setContainer(cocos2d::CCNode* p0) -> decltype(setContainer(p0)) {
	using FunctionType = decltype(setContainer(p0))(*)(cocos2d::extension::CCScrollView*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x370b74, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCScrollView::setContentOffset(cocos2d::CCPoint p0, bool p1) -> decltype(setContentOffset(p0, p1)) {
	using FunctionType = decltype(setContentOffset(p0, p1))(*)(cocos2d::extension::CCScrollView*, cocos2d::CCPoint, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3705b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::extension::CCScrollView::setContentOffsetInDuration(cocos2d::CCPoint p0, float p1) -> decltype(setContentOffsetInDuration(p0, p1)) {
	using FunctionType = decltype(setContentOffsetInDuration(p0, p1))(*)(cocos2d::extension::CCScrollView*, cocos2d::CCPoint, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x370720, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::extension::CCScrollView::setViewSize(cocos2d::CCSize p0) -> decltype(setViewSize(p0)) {
	using FunctionType = decltype(setViewSize(p0))(*)(cocos2d::extension::CCScrollView*, cocos2d::CCSize);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3702d8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCScrollView::setZoomScale(float p0) -> decltype(setZoomScale(p0)) {
	using FunctionType = decltype(setZoomScale(p0))(*)(cocos2d::extension::CCScrollView*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3708bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCScrollView::setZoomScale(float p0, bool p1) -> decltype(setZoomScale(p0, p1)) {
	using FunctionType = decltype(setZoomScale(p0, p1))(*)(cocos2d::extension::CCScrollView*, float, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x370a2c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::extension::CCScrollView::setZoomScaleInDuration(float p0, float p1) -> decltype(setZoomScaleInDuration(p0, p1)) {
	using FunctionType = decltype(setZoomScaleInDuration(p0, p1))(*)(cocos2d::extension::CCScrollView*, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x370acc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::extension::CCScrollView::stoppedAnimatedScroll(cocos2d::CCNode* p0) -> decltype(stoppedAnimatedScroll(p0)) {
	using FunctionType = decltype(stoppedAnimatedScroll(p0))(*)(cocos2d::extension::CCScrollView*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x370838, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCScrollView::unregisterScriptHandler(int p0) -> decltype(unregisterScriptHandler(p0)) {
	using FunctionType = decltype(unregisterScriptHandler(p0))(*)(cocos2d::extension::CCScrollView*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x36ff50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCScrollView::updateInset() -> decltype(updateInset()) {
	using FunctionType = decltype(updateInset())(*)(cocos2d::extension::CCScrollView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x371124, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
