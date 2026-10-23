
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/SetupRandAdvTriggerPopup.hpp>
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

auto SetupRandAdvTriggerPopup::create(RandTriggerGameObject* object, cocos2d::CCArray* objects) -> decltype(create(object, objects)) {
	using FunctionType = decltype(create(object, objects))(*)(RandTriggerGameObject*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x31453c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(object, objects);
}

auto SetupRandAdvTriggerPopup::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*>::func(&SetupRandAdvTriggerPopup::onClose), this);
	using FunctionType = decltype(onClose(sender))(*)(SetupRandAdvTriggerPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x315954, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, sender);
}

auto SetupRandAdvTriggerPopup::textChanged(CCTextInputNode* node) -> decltype(textChanged(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&SetupRandAdvTriggerPopup::textChanged), this);
	using FunctionType = decltype(textChanged(node))(*)(SetupRandAdvTriggerPopup*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x31594c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto SetupRandAdvTriggerPopup::addChance(int id, int chance) -> decltype(addChance(id, chance)) {
	using FunctionType = decltype(addChance(id, chance))(*)(SetupRandAdvTriggerPopup*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3159c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, chance);
}

auto SetupRandAdvTriggerPopup::addChanceToObject(RandTriggerGameObject* object, int id, int chance) -> decltype(addChanceToObject(object, id, chance)) {
	using FunctionType = decltype(addChanceToObject(object, id, chance))(*)(SetupRandAdvTriggerPopup*, RandTriggerGameObject*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x315a60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, id, chance);
}

auto SetupRandAdvTriggerPopup::callRemoveFromGroup(float dt) -> decltype(callRemoveFromGroup(dt)) {
	using FunctionType = decltype(callRemoveFromGroup(dt))(*)(SetupRandAdvTriggerPopup*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x315e5c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}

auto SetupRandAdvTriggerPopup::init(RandTriggerGameObject* object, cocos2d::CCArray* objects) -> decltype(init(object, objects)) {
	using FunctionType = decltype(init(object, objects))(*)(SetupRandAdvTriggerPopup*, RandTriggerGameObject*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3146d8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, objects);
}

auto SetupRandAdvTriggerPopup::onAddChance(cocos2d::CCObject* sender) -> decltype(onAddChance(sender)) {
	using FunctionType = decltype(onAddChance(sender))(*)(SetupRandAdvTriggerPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x314fe0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupRandAdvTriggerPopup::onRemoveFromGroup(cocos2d::CCObject* sender) -> decltype(onRemoveFromGroup(sender)) {
	using FunctionType = decltype(onRemoveFromGroup(sender))(*)(SetupRandAdvTriggerPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x315d9c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupRandAdvTriggerPopup::removeGroupID(int id) -> decltype(removeGroupID(id)) {
	using FunctionType = decltype(removeGroupID(id))(*)(SetupRandAdvTriggerPopup*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x315bac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto SetupRandAdvTriggerPopup::removeGroupIDFromObject(RandTriggerGameObject* object, int id) -> decltype(removeGroupIDFromObject(object, id)) {
	using FunctionType = decltype(removeGroupIDFromObject(object, id))(*)(SetupRandAdvTriggerPopup*, RandTriggerGameObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x315d04, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, id);
}

auto SetupRandAdvTriggerPopup::updateGroupIDButtons() -> decltype(updateGroupIDButtons()) {
	using FunctionType = decltype(updateGroupIDButtons())(*)(SetupRandAdvTriggerPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3150d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
