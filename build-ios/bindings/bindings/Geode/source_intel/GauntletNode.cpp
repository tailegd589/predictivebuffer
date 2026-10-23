
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GauntletNode.hpp>
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

auto GauntletNode::create(GJMapPack* gauntlet) -> decltype(create(gauntlet)) {
	using FunctionType = decltype(create(gauntlet))(*)(GJMapPack*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5728b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(gauntlet);
}

auto GauntletNode::frameForType(GauntletType type) -> decltype(frameForType(type)) {
	using FunctionType = decltype(frameForType(type))(*)(GauntletType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x575ab0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type);
}

auto GauntletNode::nameForType(GauntletType type) -> decltype(nameForType(type)) {
	using FunctionType = decltype(nameForType(type))(*)(GauntletType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x575a70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type);
}

auto GauntletNode::generateNode() -> decltype(generateNode()) {
	using FunctionType = decltype(generateNode())(*)(GauntletNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x574100, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GauntletNode::init(GJMapPack* gauntlet) -> decltype(init(gauntlet)) {
	using FunctionType = decltype(init(gauntlet))(*)(GauntletNode*, GJMapPack*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5740b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, gauntlet);
}

auto GauntletNode::onClaimReward() -> decltype(onClaimReward()) {
	using FunctionType = decltype(onClaimReward())(*)(GauntletNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x573250, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GauntletNode::onUnlock() -> decltype(onUnlock()) {
	using FunctionType = decltype(onUnlock())(*)(GauntletNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5736f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GauntletNode::showUnlockAnimation() -> decltype(showUnlockAnimation()) {
	using FunctionType = decltype(showUnlockAnimation())(*)(GauntletNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x573850, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
