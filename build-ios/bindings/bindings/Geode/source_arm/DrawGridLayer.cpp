
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/DrawGridLayer.hpp>
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

auto DrawGridLayer::create(cocos2d::CCNode* parent, LevelEditorLayer* layer) -> decltype(create(parent, layer)) {
	using FunctionType = decltype(create(parent, layer))(*)(cocos2d::CCNode*, LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc2e08, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(parent, layer);
}

auto DrawGridLayer::update(float dt) -> decltype(update(dt)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&DrawGridLayer::update), this);
	using FunctionType = decltype(update(dt))(*)(DrawGridLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xdff78, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, dt);
}

auto DrawGridLayer::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&DrawGridLayer::draw), this);
	using FunctionType = decltype(draw())(*)(DrawGridLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xe008c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto DrawGridLayer::addAudioLineObject(AudioLineGuideGameObject* object) -> decltype(addAudioLineObject(object)) {
	using FunctionType = decltype(addAudioLineObject(object))(*)(DrawGridLayer*, AudioLineGuideGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xce4e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto DrawGridLayer::addToEffects(EffectGameObject* object) -> decltype(addToEffects(object)) {
	using FunctionType = decltype(addToEffects(object))(*)(DrawGridLayer*, EffectGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xce330, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto DrawGridLayer::addToGuides(GameObject* object) -> decltype(addToGuides(object)) {
	using FunctionType = decltype(addToGuides(object))(*)(DrawGridLayer*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xce7e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto DrawGridLayer::addToSpeedObjects(EffectGameObject* object) -> decltype(addToSpeedObjects(object)) {
	using FunctionType = decltype(addToSpeedObjects(object))(*)(DrawGridLayer*, EffectGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xce86c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto DrawGridLayer::getPortalMinMax(GameObject* object) -> decltype(getPortalMinMax(object)) {
	using FunctionType = decltype(getPortalMinMax(object))(*)(DrawGridLayer*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xdfeac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto DrawGridLayer::init(cocos2d::CCNode* parent, LevelEditorLayer* layer) -> decltype(init(parent, layer)) {
	using FunctionType = decltype(init(parent, layer))(*)(DrawGridLayer*, cocos2d::CCNode*, LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xdfd40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, parent, layer);
}

auto DrawGridLayer::loadTimeMarkers(gd::string markers) -> decltype(loadTimeMarkers(markers)) {
	using FunctionType = decltype(loadTimeMarkers(markers))(*)(DrawGridLayer*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc4d18, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, markers);
}

auto DrawGridLayer::posForTime(float time) -> decltype(posForTime(time)) {
	using FunctionType = decltype(posForTime(time))(*)(DrawGridLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd3974, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, time);
}

auto DrawGridLayer::postUpdate() -> decltype(postUpdate()) {
	using FunctionType = decltype(postUpdate())(*)(DrawGridLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xdff6c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto DrawGridLayer::removeAudioLineObject(AudioLineGuideGameObject* object) -> decltype(removeAudioLineObject(object)) {
	using FunctionType = decltype(removeAudioLineObject(object))(*)(DrawGridLayer*, AudioLineGuideGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xce7a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto DrawGridLayer::removeFromEffects(EffectGameObject* object) -> decltype(removeFromEffects(object)) {
	using FunctionType = decltype(removeFromEffects(object))(*)(DrawGridLayer*, EffectGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xce778, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto DrawGridLayer::removeFromGuides(GameObject* object) -> decltype(removeFromGuides(object)) {
	using FunctionType = decltype(removeFromGuides(object))(*)(DrawGridLayer*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xce7d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto DrawGridLayer::removeFromSpeedObjects(EffectGameObject* object) -> decltype(removeFromSpeedObjects(object)) {
	using FunctionType = decltype(removeFromSpeedObjects(object))(*)(DrawGridLayer*, EffectGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xce820, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto DrawGridLayer::sortSpeedObjects() -> decltype(sortSpeedObjects()) {
	using FunctionType = decltype(sortSpeedObjects())(*)(DrawGridLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xdfe9c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto DrawGridLayer::timeForPos(cocos2d::CCPoint position, int order, int channel, bool songTriggers, bool ignoreWarp, bool ignoreRotate, int id) -> decltype(timeForPos(position, order, channel, songTriggers, ignoreWarp, ignoreRotate, id)) {
	using FunctionType = decltype(timeForPos(position, order, channel, songTriggers, ignoreWarp, ignoreRotate, id))(*)(DrawGridLayer*, cocos2d::CCPoint, int, int, bool, bool, bool, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd23e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, position, order, channel, songTriggers, ignoreWarp, ignoreRotate, id);
}

auto DrawGridLayer::updateMusicGuideTime(float time) -> decltype(updateMusicGuideTime(time)) {
	using FunctionType = decltype(updateMusicGuideTime(time))(*)(DrawGridLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xe007c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, time);
}

auto DrawGridLayer::updateTimeMarkers() -> decltype(updateTimeMarkers()) {
	using FunctionType = decltype(updateTimeMarkers())(*)(DrawGridLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd2334, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
