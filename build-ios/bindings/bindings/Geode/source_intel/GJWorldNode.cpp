
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJWorldNode.hpp>
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

auto GJWorldNode::create(int type, WorldSelectLayer* layer) -> decltype(create(type, layer)) {
	using FunctionType = decltype(create(type, layer))(*)(int, WorldSelectLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c3680, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type, layer);
}

auto GJWorldNode::addDotsToLevel(int levelID, bool animate) -> decltype(addDotsToLevel(levelID, animate)) {
	using FunctionType = decltype(addDotsToLevel(levelID, animate))(*)(GJWorldNode*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c4880, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, levelID, animate);
}

auto GJWorldNode::dotPositionForLevel(int levelID, int index) -> decltype(dotPositionForLevel(levelID, index)) {
	using FunctionType = decltype(dotPositionForLevel(levelID, index))(*)(GJWorldNode*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c4ed0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, levelID, index);
}

auto GJWorldNode::init(int type, WorldSelectLayer* layer) -> decltype(init(type, layer)) {
	using FunctionType = decltype(init(type, layer))(*)(GJWorldNode*, int, WorldSelectLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c3dd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type, layer);
}

auto GJWorldNode::onLevel(cocos2d::CCObject* sender) -> decltype(onLevel(sender)) {
	using FunctionType = decltype(onLevel(sender))(*)(GJWorldNode*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c4800, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJWorldNode::playStep1() -> decltype(playStep1()) {
	using FunctionType = decltype(playStep1())(*)(GJWorldNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c4c40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJWorldNode::playStep2() -> decltype(playStep2()) {
	using FunctionType = decltype(playStep2())(*)(GJWorldNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c4d40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJWorldNode::playStep3() -> decltype(playStep3()) {
	using FunctionType = decltype(playStep3())(*)(GJWorldNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c4e00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJWorldNode::positionForLevelButton(int levelID) -> decltype(positionForLevelButton(levelID)) {
	using FunctionType = decltype(positionForLevelButton(levelID))(*)(GJWorldNode*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c46e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, levelID);
}

auto GJWorldNode::unlockActiveItem() -> decltype(unlockActiveItem()) {
	using FunctionType = decltype(unlockActiveItem())(*)(GJWorldNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c3020, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
