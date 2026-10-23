
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCDirector.hpp>
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

cocos2d::CCDirector::CCDirector() : cocos2d::CCDirector(geode::CutoffConstructor, sizeof(cocos2d::CCDirector)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCDirector::~CCDirector();

	using FunctionType = void(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e8550, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCDirector::~CCDirector() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCDirector*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x3e8964, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCDirector(geode::CutoffConstructor, sizeof(cocos2d::CCDirector));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCDirector::sharedDirector() -> decltype(sharedDirector()) {
	using FunctionType = decltype(sharedDirector())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e8490, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCDirector::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCDirector::init), this);
	using FunctionType = decltype(init())(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e85b4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCDirector::getScheduler() -> decltype(getScheduler()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCDirector::getScheduler), this);
	using FunctionType = decltype(getScheduler())(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ea638, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCDirector::setScheduler(cocos2d::CCScheduler* p0) -> decltype(setScheduler(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCScheduler*>::func(&cocos2d::CCDirector::setScheduler), this);
	using FunctionType = decltype(setScheduler(p0))(*)(cocos2d::CCDirector*, cocos2d::CCScheduler*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ea5f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCDirector::getActionManager() -> decltype(getActionManager()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCDirector::getActionManager), this);
	using FunctionType = decltype(getActionManager())(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ea688, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCDirector::setActionManager(cocos2d::CCActionManager* p0) -> decltype(setActionManager(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCActionManager*>::func(&cocos2d::CCDirector::setActionManager), this);
	using FunctionType = decltype(setActionManager(p0))(*)(cocos2d::CCDirector*, cocos2d::CCActionManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ea640, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCDirector::getTouchDispatcher() -> decltype(getTouchDispatcher()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCDirector::getTouchDispatcher), this);
	using FunctionType = decltype(getTouchDispatcher())(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ea6d8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCDirector::setTouchDispatcher(cocos2d::CCTouchDispatcher* p0) -> decltype(setTouchDispatcher(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouchDispatcher*>::func(&cocos2d::CCDirector::setTouchDispatcher), this);
	using FunctionType = decltype(setTouchDispatcher(p0))(*)(cocos2d::CCDirector*, cocos2d::CCTouchDispatcher*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ea690, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCDirector::getKeypadDispatcher() -> decltype(getKeypadDispatcher()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCDirector::getKeypadDispatcher), this);
	using FunctionType = decltype(getKeypadDispatcher())(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ea7a4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCDirector::setKeypadDispatcher(cocos2d::CCKeypadDispatcher* p0) -> decltype(setKeypadDispatcher(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCKeypadDispatcher*>::func(&cocos2d::CCDirector::setKeypadDispatcher), this);
	using FunctionType = decltype(setKeypadDispatcher(p0))(*)(cocos2d::CCDirector*, cocos2d::CCKeypadDispatcher*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ea768, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCDirector::getKeyboardDispatcher() -> decltype(getKeyboardDispatcher()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCDirector::getKeyboardDispatcher), this);
	using FunctionType = decltype(getKeyboardDispatcher())(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ea71c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCDirector::setKeyboardDispatcher(cocos2d::CCKeyboardDispatcher* p0) -> decltype(setKeyboardDispatcher(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCKeyboardDispatcher*>::func(&cocos2d::CCDirector::setKeyboardDispatcher), this);
	using FunctionType = decltype(setKeyboardDispatcher(p0))(*)(cocos2d::CCDirector*, cocos2d::CCKeyboardDispatcher*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ea6e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCDirector::getMouseDispatcher() -> decltype(getMouseDispatcher()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCDirector::getMouseDispatcher), this);
	using FunctionType = decltype(getMouseDispatcher())(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ea760, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCDirector::setMouseDispatcher(cocos2d::CCMouseDispatcher* p0) -> decltype(setMouseDispatcher(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCMouseDispatcher*>::func(&cocos2d::CCDirector::setMouseDispatcher), this);
	using FunctionType = decltype(setMouseDispatcher(p0))(*)(cocos2d::CCDirector*, cocos2d::CCMouseDispatcher*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ea724, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCDirector::getAccelerometer() -> decltype(getAccelerometer()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCDirector::getAccelerometer), this);
	using FunctionType = decltype(getAccelerometer())(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ea7e4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCDirector::setAccelerometer(cocos2d::CCAccelerometer* p0) -> decltype(setAccelerometer(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCAccelerometer*>::func(&cocos2d::CCDirector::setAccelerometer), this);
	using FunctionType = decltype(setAccelerometer(p0))(*)(cocos2d::CCDirector*, cocos2d::CCAccelerometer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ea7ac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCDirector::getDeltaTime() -> decltype(getDeltaTime()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCDirector::getDeltaTime), this);
	using FunctionType = decltype(getDeltaTime())(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e9480, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCDirector::applySmoothFix() -> decltype(applySmoothFix()) {
	using FunctionType = decltype(applySmoothFix())(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e93fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDirector::calculateDeltaTime() -> decltype(calculateDeltaTime()) {
	using FunctionType = decltype(calculateDeltaTime())(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e8fe4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDirector::calculateMPF() -> decltype(calculateMPF()) {
	using FunctionType = decltype(calculateMPF())(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e9388, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDirector::checkSceneReference() -> decltype(checkSceneReference()) {
	using FunctionType = decltype(checkSceneReference())(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e9fe8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDirector::convertToGL(cocos2d::CCPoint const& p0) -> decltype(convertToGL(p0)) {
	using FunctionType = decltype(convertToGL(p0))(*)(cocos2d::CCDirector*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e9b00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCDirector::convertToUI(cocos2d::CCPoint const& p0) -> decltype(convertToUI(p0)) {
	using FunctionType = decltype(convertToUI(p0))(*)(cocos2d::CCDirector*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e9bdc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCDirector::createStatsLabel() -> decltype(createStatsLabel()) {
	using FunctionType = decltype(createStatsLabel())(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e9564, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDirector::drawScene() -> decltype(drawScene()) {
	using FunctionType = decltype(drawScene())(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e8cac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDirector::end() -> decltype(end()) {
	using FunctionType = decltype(end())(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ea0a4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDirector::getDelegate() const  -> decltype(getDelegate()) {
	using FunctionType = decltype(getDelegate())(*)(cocos2d::CCDirector const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ea5e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDirector::getFPSImageData(unsigned char** p0, unsigned int* p1) -> decltype(getFPSImageData(p0, p1)) {
	using FunctionType = decltype(getFPSImageData(p0, p1))(*)(cocos2d::CCDirector*, unsigned char**, unsigned int*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ea4cc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCDirector::getNotificationNode() -> decltype(getNotificationNode()) {
	using FunctionType = decltype(getNotificationNode())(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ea594, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDirector::getVisibleOrigin() -> decltype(getVisibleOrigin()) {
	using FunctionType = decltype(getVisibleOrigin())(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e9cf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDirector::getVisibleSize() -> decltype(getVisibleSize()) {
	using FunctionType = decltype(getVisibleSize())(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e9ccc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDirector::getWinSize() -> decltype(getWinSize()) {
	using FunctionType = decltype(getWinSize())(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e9668, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDirector::getWinSizeInPixels() -> decltype(getWinSizeInPixels()) {
	using FunctionType = decltype(getWinSizeInPixels())(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e9cb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDirector::getZEye() -> decltype(getZEye()) {
	using FunctionType = decltype(getZEye())(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e9a88, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDirector::levelForSceneInStack(cocos2d::CCScene* p0) -> decltype(levelForSceneInStack(p0)) {
	using FunctionType = decltype(levelForSceneInStack(p0))(*)(cocos2d::CCDirector*, cocos2d::CCScene*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ea29c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCDirector::pause() -> decltype(pause()) {
	using FunctionType = decltype(pause())(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ea43c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDirector::popScene() -> decltype(popScene()) {
	using FunctionType = decltype(popScene())(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ea024, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDirector::popSceneWithTransition(float p0, cocos2d::PopTransition p1) -> decltype(popSceneWithTransition(p0, p1)) {
	using FunctionType = decltype(popSceneWithTransition(p0, p1))(*)(cocos2d::CCDirector*, float, cocos2d::PopTransition);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ea0b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCDirector::popToRootScene() -> decltype(popToRootScene()) {
	using FunctionType = decltype(popToRootScene())(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ea180, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDirector::popToSceneInStack(cocos2d::CCScene* p0) -> decltype(popToSceneInStack(p0)) {
	using FunctionType = decltype(popToSceneInStack(p0))(*)(cocos2d::CCDirector*, cocos2d::CCScene*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ea2e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCDirector::popToSceneStackLevel(int p0) -> decltype(popToSceneStackLevel(p0)) {
	using FunctionType = decltype(popToSceneStackLevel(p0))(*)(cocos2d::CCDirector*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ea188, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCDirector::purgeCachedData() -> decltype(purgeCachedData()) {
	using FunctionType = decltype(purgeCachedData())(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e9aa0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDirector::purgeDirector() -> decltype(purgeDirector()) {
	using FunctionType = decltype(purgeDirector())(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ea338, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDirector::pushScene(cocos2d::CCScene* p0) -> decltype(pushScene(p0)) {
	using FunctionType = decltype(pushScene(p0))(*)(cocos2d::CCDirector*, cocos2d::CCScene*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e9e18, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCDirector::removeStatsLabel() -> decltype(removeStatsLabel()) {
	using FunctionType = decltype(removeStatsLabel())(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ea4fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDirector::replaceScene(cocos2d::CCScene* p0) -> decltype(replaceScene(p0)) {
	using FunctionType = decltype(replaceScene(p0))(*)(cocos2d::CCDirector*, cocos2d::CCScene*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e9ec4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCDirector::resetSmoothFixCounter() -> decltype(resetSmoothFixCounter()) {
	using FunctionType = decltype(resetSmoothFixCounter())(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e9474, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDirector::reshapeProjection(cocos2d::CCSize const& p0) -> decltype(reshapeProjection(p0)) {
	using FunctionType = decltype(reshapeProjection(p0))(*)(cocos2d::CCDirector*, cocos2d::CCSize const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e9aa4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCDirector::resume() -> decltype(resume()) {
	using FunctionType = decltype(resume())(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ea480, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDirector::runWithScene(cocos2d::CCScene* p0) -> decltype(runWithScene(p0)) {
	using FunctionType = decltype(runWithScene(p0))(*)(cocos2d::CCDirector*, cocos2d::CCScene*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e9d6c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCDirector::sceneCount() -> decltype(sceneCount()) {
	using FunctionType = decltype(sceneCount())(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ea294, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDirector::setAlphaBlending(bool p0) -> decltype(setAlphaBlending(p0)) {
	using FunctionType = decltype(setAlphaBlending(p0))(*)(cocos2d::CCDirector*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e8ac0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCDirector::setContentScaleFactor(float p0) -> decltype(setContentScaleFactor(p0)) {
	using FunctionType = decltype(setContentScaleFactor(p0))(*)(cocos2d::CCDirector*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e9a18, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCDirector::setDefaultValues() -> decltype(setDefaultValues()) {
	using FunctionType = decltype(setDefaultValues())(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e8814, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDirector::setDelegate(cocos2d::CCDirectorDelegate* p0) -> decltype(setDelegate(p0)) {
	using FunctionType = decltype(setDelegate(p0))(*)(cocos2d::CCDirector*, cocos2d::CCDirectorDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ea5e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCDirector::setDeltaTime(float p0) -> decltype(setDeltaTime(p0)) {
	using FunctionType = decltype(setDeltaTime(p0))(*)(cocos2d::CCDirector*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e93f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCDirector::setDepthTest(bool p0) -> decltype(setDepthTest(p0)) {
	using FunctionType = decltype(setDepthTest(p0))(*)(cocos2d::CCDirector*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e8ad4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCDirector::setGLDefaultValues() -> decltype(setGLDefaultValues()) {
	using FunctionType = decltype(setGLDefaultValues())(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e8a74, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDirector::setNextDeltaTimeZero(bool p0) -> decltype(setNextDeltaTimeZero(p0)) {
	using FunctionType = decltype(setNextDeltaTimeZero(p0))(*)(cocos2d::CCDirector*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e9a80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCDirector::setNextScene() -> decltype(setNextScene()) {
	using FunctionType = decltype(setNextScene())(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e9110, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDirector::setOpenGLView(cocos2d::CCEGLView* p0) -> decltype(setOpenGLView(p0)) {
	using FunctionType = decltype(setOpenGLView(p0))(*)(cocos2d::CCDirector*, cocos2d::CCEGLView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e9488, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCDirector::setProjection(cocos2d::ccDirectorProjection p0) -> decltype(setProjection(p0)) {
	using FunctionType = decltype(setProjection(p0))(*)(cocos2d::CCDirector*, cocos2d::ccDirectorProjection);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e8b04, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCDirector::setupScreenScale(cocos2d::CCSize p0, cocos2d::CCSize p1, cocos2d::TextureQuality p2) -> decltype(setupScreenScale(p0, p1, p2)) {
	using FunctionType = decltype(setupScreenScale(p0, p1, p2))(*)(cocos2d::CCDirector*, cocos2d::CCSize, cocos2d::CCSize, cocos2d::TextureQuality);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e9674, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCDirector::setViewport() -> decltype(setViewport()) {
	using FunctionType = decltype(setViewport())(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e9a2c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDirector::showFPSLabel() -> decltype(showFPSLabel()) {
	using FunctionType = decltype(showFPSLabel())(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e92d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDirector::showStats() -> decltype(showStats()) {
	using FunctionType = decltype(showStats())(*)(cocos2d::CCDirector*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e9230, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDirector::toggleShowFPS(bool p0, gd::string p1, cocos2d::CCPoint p2) -> decltype(toggleShowFPS(p0, p1, p2)) {
	using FunctionType = decltype(toggleShowFPS(p0, p1, p2))(*)(cocos2d::CCDirector*, bool, gd::string, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e9568, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCDirector::updateContentScale(cocos2d::TextureQuality p0) -> decltype(updateContentScale(p0)) {
	using FunctionType = decltype(updateContentScale(p0))(*)(cocos2d::CCDirector*, cocos2d::TextureQuality);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e9914, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCDirector::updateScreenScale(cocos2d::CCSize p0) -> decltype(updateScreenScale(p0)) {
	using FunctionType = decltype(updateScreenScale(p0))(*)(cocos2d::CCDirector*, cocos2d::CCSize);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e9864, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCDirector::willSwitchToScene(cocos2d::CCScene* p0) -> decltype(willSwitchToScene(p0)) {
	using FunctionType = decltype(willSwitchToScene(p0))(*)(cocos2d::CCDirector*, cocos2d::CCScene*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e9d14, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
