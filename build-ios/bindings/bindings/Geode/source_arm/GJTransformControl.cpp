
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJTransformControl.hpp>
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

GJTransformControl::GJTransformControl() : GJTransformControl(geode::CutoffConstructor, sizeof(GJTransformControl)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	GJTransformControl::~GJTransformControl();

	using FunctionType = void(*)(GJTransformControl*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x493ec, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

GJTransformControl::~GJTransformControl() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(GJTransformControl*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x47ac0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) GJTransformControl(geode::CutoffConstructor, sizeof(GJTransformControl));
		geode::DestructorLock::addLock(this);
	}
}

auto GJTransformControl::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0xa5e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto GJTransformControl::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJTransformControl::init), this);
	using FunctionType = decltype(init())(*)(GJTransformControl*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x47cd8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJTransformControl::ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchBegan(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&GJTransformControl::ccTouchBegan), this);
	using FunctionType = decltype(ccTouchBegan(touch, event))(*)(GJTransformControl*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x48158, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto GJTransformControl::ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchMoved(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&GJTransformControl::ccTouchMoved), this);
	using FunctionType = decltype(ccTouchMoved(touch, event))(*)(GJTransformControl*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x48544, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto GJTransformControl::ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchEnded(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&GJTransformControl::ccTouchEnded), this);
	using FunctionType = decltype(ccTouchEnded(touch, event))(*)(GJTransformControl*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x48a78, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto GJTransformControl::ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchCancelled(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&GJTransformControl::ccTouchCancelled), this);
	using FunctionType = decltype(ccTouchCancelled(touch, event))(*)(GJTransformControl*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x48c50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto GJTransformControl::applyRotation(float rotation) -> decltype(applyRotation(rotation)) {
	using FunctionType = decltype(applyRotation(rotation))(*)(GJTransformControl*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38cd4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, rotation);
}

auto GJTransformControl::calculateRotationOffset() -> decltype(calculateRotationOffset()) {
	using FunctionType = decltype(calculateRotationOffset())(*)(GJTransformControl*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4810c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJTransformControl::finishTouch() -> decltype(finishTouch()) {
	using FunctionType = decltype(finishTouch())(*)(GJTransformControl*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3846c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJTransformControl::loadFromState(GJTransformState& state) -> decltype(loadFromState(state)) {
	using FunctionType = decltype(loadFromState(state))(*)(GJTransformControl*, GJTransformState&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x48060, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, state);
}

auto GJTransformControl::loadValues(GameObject* object, cocos2d::CCArray* objects, gd::unordered_map<int, GameObjectEditorState>& states) -> decltype(loadValues(object, objects, states)) {
	using FunctionType = decltype(loadValues(object, objects, states))(*)(GJTransformControl*, GameObject*, cocos2d::CCArray*, gd::unordered_map<int, GameObjectEditorState>&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38b74, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, objects, states);
}

auto GJTransformControl::logCurrentZeroPos() -> decltype(logCurrentZeroPos()) {
	using FunctionType = decltype(logCurrentZeroPos())(*)(GJTransformControl*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x48c6c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJTransformControl::onToggleLockScale(cocos2d::CCObject* sender) -> decltype(onToggleLockScale(sender)) {
	using FunctionType = decltype(onToggleLockScale(sender))(*)(GJTransformControl*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x47fe4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJTransformControl::refreshControl() -> decltype(refreshControl()) {
	using FunctionType = decltype(refreshControl())(*)(GJTransformControl*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40c3c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJTransformControl::saveToState(GJTransformState& state) -> decltype(saveToState(state)) {
	using FunctionType = decltype(saveToState(state))(*)(GJTransformControl*, GJTransformState&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38d58, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, state);
}

auto GJTransformControl::scaleButtons(float scale) -> decltype(scaleButtons(scale)) {
	using FunctionType = decltype(scaleButtons(scale))(*)(GJTransformControl*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x35fa0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, scale);
}

auto GJTransformControl::spriteByTag(int tag) -> decltype(spriteByTag(tag)) {
	using FunctionType = decltype(spriteByTag(tag))(*)(GJTransformControl*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x48054, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, tag);
}

auto GJTransformControl::updateAnchorSprite(cocos2d::CCPoint position) -> decltype(updateAnchorSprite(position)) {
	using FunctionType = decltype(updateAnchorSprite(position))(*)(GJTransformControl*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38414, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, position);
}

auto GJTransformControl::updateButtons(bool transform, bool skew) -> decltype(updateButtons(transform, skew)) {
	using FunctionType = decltype(updateButtons(transform, skew))(*)(GJTransformControl*, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x411f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, transform, skew);
}

auto GJTransformControl::updateMinMaxPositions() -> decltype(updateMinMaxPositions()) {
	using FunctionType = decltype(updateMinMaxPositions())(*)(GJTransformControl*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x48c70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
