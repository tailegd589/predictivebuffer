
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/OptionsScrollLayer.hpp>
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

auto OptionsScrollLayer::create(cocos2d::CCArray* objects, bool recreate, int minimum) -> decltype(create(objects, recreate, minimum)) {
	using FunctionType = decltype(create(objects, recreate, minimum))(*)(cocos2d::CCArray*, bool, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x60fd80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(objects, recreate, minimum);
}

auto OptionsScrollLayer::registerWithTouchDispatcher() -> decltype(registerWithTouchDispatcher()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&OptionsScrollLayer::registerWithTouchDispatcher), this);
	using FunctionType = decltype(registerWithTouchDispatcher())(*)(OptionsScrollLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6109c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto OptionsScrollLayer::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&OptionsScrollLayer::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(OptionsScrollLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x610890, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto OptionsScrollLayer::cellPerformedAction(TableViewCell* cell, int listType, CellAction action, cocos2d::CCNode* parent) -> decltype(cellPerformedAction(cell, listType, action, parent)) {
	auto self = addresser::thunkAdjust(Resolve<TableViewCell*, int, CellAction, cocos2d::CCNode*>::func(&OptionsScrollLayer::cellPerformedAction), this);
	using FunctionType = decltype(cellPerformedAction(cell, listType, action, parent))(*)(OptionsScrollLayer*, TableViewCell*, int, CellAction, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x610a00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, cell, listType, action, parent);
}

auto OptionsScrollLayer::getRelevantObjects(cocos2d::CCArray* objects) -> decltype(getRelevantObjects(objects)) {
	using FunctionType = decltype(getRelevantObjects(objects))(*)(OptionsScrollLayer*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x610810, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objects);
}

auto OptionsScrollLayer::init(cocos2d::CCArray* objects, bool recreate, int minimum) -> decltype(init(objects, recreate, minimum)) {
	using FunctionType = decltype(init(objects, recreate, minimum))(*)(OptionsScrollLayer*, cocos2d::CCArray*, bool, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x610470, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objects, recreate, minimum);
}

auto OptionsScrollLayer::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	using FunctionType = decltype(onClose(sender))(*)(OptionsScrollLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6105e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto OptionsScrollLayer::setupList(cocos2d::CCArray* objects) -> decltype(setupList(objects)) {
	using FunctionType = decltype(setupList(objects))(*)(OptionsScrollLayer*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x610670, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objects);
}
