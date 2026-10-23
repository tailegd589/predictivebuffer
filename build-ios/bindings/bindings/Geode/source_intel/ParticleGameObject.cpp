
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/ParticleGameObject.hpp>
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

auto ParticleGameObject::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b1580, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto ParticleGameObject::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&ParticleGameObject::init), this);
	using FunctionType = decltype(init())(*)(ParticleGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b1760, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto ParticleGameObject::setScaleX(float scaleX) -> decltype(setScaleX(scaleX)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&ParticleGameObject::setScaleX), this);
	using FunctionType = decltype(setScaleX(scaleX))(*)(ParticleGameObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b27c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, scaleX);
}

auto ParticleGameObject::setScaleY(float scaleY) -> decltype(setScaleY(scaleY)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&ParticleGameObject::setScaleY), this);
	using FunctionType = decltype(setScaleY(scaleY))(*)(ParticleGameObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b2830, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, scaleY);
}

auto ParticleGameObject::setScale(float scale) -> decltype(setScale(scale)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&ParticleGameObject::setScale), this);
	using FunctionType = decltype(setScale(scale))(*)(ParticleGameObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b28a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, scale);
}

auto ParticleGameObject::setRotation(float rotation) -> decltype(setRotation(rotation)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&ParticleGameObject::setRotation), this);
	using FunctionType = decltype(setRotation(rotation))(*)(ParticleGameObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b2700, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, rotation);
}

auto ParticleGameObject::setRotationX(float rotationX) -> decltype(setRotationX(rotationX)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&ParticleGameObject::setRotationX), this);
	using FunctionType = decltype(setRotationX(rotationX))(*)(ParticleGameObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b2740, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, rotationX);
}

auto ParticleGameObject::setRotationY(float rotationY) -> decltype(setRotationY(rotationY)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&ParticleGameObject::setRotationY), this);
	using FunctionType = decltype(setRotationY(rotationY))(*)(ParticleGameObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b2780, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, rotationY);
}

auto ParticleGameObject::setChildColor(cocos2d::ccColor3B const& color) -> decltype(setChildColor(color)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccColor3B const&>::func(&ParticleGameObject::setChildColor), this);
	using FunctionType = decltype(setChildColor(color))(*)(ParticleGameObject*, cocos2d::ccColor3B const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b2a00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, color);
}

auto ParticleGameObject::customSetup() -> decltype(customSetup()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&ParticleGameObject::customSetup), this);
	using FunctionType = decltype(customSetup())(*)(ParticleGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b1a30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto ParticleGameObject::addMainSpriteToParent(bool reorder) -> decltype(addMainSpriteToParent(reorder)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&ParticleGameObject::addMainSpriteToParent), this);
	using FunctionType = decltype(addMainSpriteToParent(reorder))(*)(ParticleGameObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b1b00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, reorder);
}

auto ParticleGameObject::resetObject() -> decltype(resetObject()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&ParticleGameObject::resetObject), this);
	using FunctionType = decltype(resetObject())(*)(ParticleGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b2bd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto ParticleGameObject::deactivateObject(bool deactivate) -> decltype(deactivateObject(deactivate)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&ParticleGameObject::deactivateObject), this);
	using FunctionType = decltype(deactivateObject(deactivate))(*)(ParticleGameObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b2b90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, deactivate);
}

auto ParticleGameObject::customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists) -> decltype(customObjectSetup(values, exists)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&ParticleGameObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(values, exists))(*)(ParticleGameObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b1790, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, values, exists);
}

auto ParticleGameObject::getSaveString(GJBaseGameLayer* layer) -> decltype(getSaveString(layer)) {
	auto self = addresser::thunkAdjust(Resolve<GJBaseGameLayer*>::func(&ParticleGameObject::getSaveString), this);
	using FunctionType = decltype(getSaveString(layer))(*)(ParticleGameObject*, GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b2dd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer);
}

auto ParticleGameObject::claimParticle() -> decltype(claimParticle()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&ParticleGameObject::claimParticle), this);
	using FunctionType = decltype(claimParticle())(*)(ParticleGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b1be0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto ParticleGameObject::unclaimParticle() -> decltype(unclaimParticle()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&ParticleGameObject::unclaimParticle), this);
	using FunctionType = decltype(unclaimParticle())(*)(ParticleGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b2150, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto ParticleGameObject::particleWasActivated() -> decltype(particleWasActivated()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&ParticleGameObject::particleWasActivated), this);
	using FunctionType = decltype(particleWasActivated())(*)(ParticleGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b21d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto ParticleGameObject::setObjectColor(cocos2d::ccColor3B const& color) -> decltype(setObjectColor(color)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccColor3B const&>::func(&ParticleGameObject::setObjectColor), this);
	using FunctionType = decltype(setObjectColor(color))(*)(ParticleGameObject*, cocos2d::ccColor3B const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b2910, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, color);
}

auto ParticleGameObject::blendModeChanged() -> decltype(blendModeChanged()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&ParticleGameObject::blendModeChanged), this);
	using FunctionType = decltype(blendModeChanged())(*)(ParticleGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b1ac0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto ParticleGameObject::updateMainParticleOpacity(unsigned char opacity) -> decltype(updateMainParticleOpacity(opacity)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned char>::func(&ParticleGameObject::updateMainParticleOpacity), this);
	using FunctionType = decltype(updateMainParticleOpacity(opacity))(*)(ParticleGameObject*, unsigned char);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b2af0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, opacity);
}

auto ParticleGameObject::updateSecondaryParticleOpacity(unsigned char opacity) -> decltype(updateSecondaryParticleOpacity(opacity)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned char>::func(&ParticleGameObject::updateSecondaryParticleOpacity), this);
	using FunctionType = decltype(updateSecondaryParticleOpacity(opacity))(*)(ParticleGameObject*, unsigned char);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b2b40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, opacity);
}

auto ParticleGameObject::updateSyncedAnimation(float totalTime, int frameIndex) -> decltype(updateSyncedAnimation(totalTime, frameIndex)) {
	auto self = addresser::thunkAdjust(Resolve<float, int>::func(&ParticleGameObject::updateSyncedAnimation), this);
	using FunctionType = decltype(updateSyncedAnimation(totalTime, frameIndex))(*)(ParticleGameObject*, float, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b2c30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, totalTime, frameIndex);
}

auto ParticleGameObject::updateAnimateOnTrigger(bool animate) -> decltype(updateAnimateOnTrigger(animate)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&ParticleGameObject::updateAnimateOnTrigger), this);
	using FunctionType = decltype(updateAnimateOnTrigger(animate))(*)(ParticleGameObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b2d80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, animate);
}

auto ParticleGameObject::applyParticleSettings(cocos2d::CCParticleSystemQuad* particle) -> decltype(applyParticleSettings(particle)) {
	using FunctionType = decltype(applyParticleSettings(particle))(*)(ParticleGameObject*, cocos2d::CCParticleSystemQuad*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b1d60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, particle);
}

auto ParticleGameObject::createAndAddCustomParticle() -> decltype(createAndAddCustomParticle()) {
	using FunctionType = decltype(createAndAddCustomParticle())(*)(ParticleGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b19c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto ParticleGameObject::createParticlePreviewArt() -> decltype(createParticlePreviewArt()) {
	using FunctionType = decltype(createParticlePreviewArt())(*)(ParticleGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b2520, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto ParticleGameObject::setParticleString(gd::string str) -> decltype(setParticleString(str)) {
	using FunctionType = decltype(setParticleString(str))(*)(ParticleGameObject*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b2310, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, str);
}

auto ParticleGameObject::updateParticle() -> decltype(updateParticle()) {
	using FunctionType = decltype(updateParticle())(*)(ParticleGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b23a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto ParticleGameObject::updateParticleAngle(float angle, cocos2d::CCParticleSystemQuad* particle) -> decltype(updateParticleAngle(angle, particle)) {
	using FunctionType = decltype(updateParticleAngle(angle, particle))(*)(ParticleGameObject*, float, cocos2d::CCParticleSystemQuad*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b2040, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, angle, particle);
}

auto ParticleGameObject::updateParticlePreviewArtOpacity(float opacity) -> decltype(updateParticlePreviewArtOpacity(opacity)) {
	using FunctionType = decltype(updateParticlePreviewArtOpacity(opacity))(*)(ParticleGameObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b2680, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, opacity);
}

auto ParticleGameObject::updateParticleScale(float scale) -> decltype(updateParticleScale(scale)) {
	using FunctionType = decltype(updateParticleScale(scale))(*)(ParticleGameObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b24d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, scale);
}

auto ParticleGameObject::updateParticleStruct() -> decltype(updateParticleStruct()) {
	using FunctionType = decltype(updateParticleStruct())(*)(ParticleGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b1bb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
