
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/SetupSpawnPopup.hpp>
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

auto SetupSpawnPopup::create(EffectGameObject* object, cocos2d::CCArray* objects) -> decltype(create(object, objects)) {
	using FunctionType = decltype(create(object, objects))(*)(EffectGameObject*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22fa64, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(object, objects);
}

auto SetupSpawnPopup::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*>::func(&SetupSpawnPopup::onClose), this);
	using FunctionType = decltype(onClose(sender))(*)(SetupSpawnPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2311b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, sender);
}

auto SetupSpawnPopup::addRemap(int oldID, int newID) -> decltype(addRemap(oldID, newID)) {
	using FunctionType = decltype(addRemap(oldID, newID))(*)(SetupSpawnPopup*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x230f7c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, oldID, newID);
}

auto SetupSpawnPopup::init(EffectGameObject* object, cocos2d::CCArray* objects) -> decltype(init(object, objects)) {
	using FunctionType = decltype(init(object, objects))(*)(SetupSpawnPopup*, EffectGameObject*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22fbf8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, objects);
}

auto SetupSpawnPopup::onAddRemap(cocos2d::CCObject* sender) -> decltype(onAddRemap(sender)) {
	using FunctionType = decltype(onAddRemap(sender))(*)(SetupSpawnPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2306fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupSpawnPopup::onDeleteRemap(cocos2d::CCObject* sender) -> decltype(onDeleteRemap(sender)) {
	using FunctionType = decltype(onDeleteRemap(sender))(*)(SetupSpawnPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x23074c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupSpawnPopup::onPasteRemap(cocos2d::CCObject* sender) -> decltype(onPasteRemap(sender)) {
	using FunctionType = decltype(onPasteRemap(sender))(*)(SetupSpawnPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x230834, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupSpawnPopup::onSelectRemap(cocos2d::CCObject* sender) -> decltype(onSelectRemap(sender)) {
	using FunctionType = decltype(onSelectRemap(sender))(*)(SetupSpawnPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2310b8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupSpawnPopup::queueUpdateButtons() -> decltype(queueUpdateButtons()) {
	using FunctionType = decltype(queueUpdateButtons())(*)(SetupSpawnPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x231060, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupSpawnPopup::updateRemapButtons(float dt) -> decltype(updateRemapButtons(dt)) {
	using FunctionType = decltype(updateRemapButtons(dt))(*)(SetupSpawnPopup*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x230874, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}
