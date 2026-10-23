
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJMGLayer.hpp>
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

auto GJMGLayer::create(int index) -> decltype(create(index)) {
	using FunctionType = decltype(create(index))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5ebc50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(index);
}

auto GJMGLayer::defaultYOffsetForBG2(int index) -> decltype(defaultYOffsetForBG2(index)) {
	using FunctionType = decltype(defaultYOffsetForBG2(index))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5ebc30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(index);
}

auto GJMGLayer::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJMGLayer::draw), this);
	using FunctionType = decltype(draw())(*)(GJMGLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5ec700, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJMGLayer::showGround() -> decltype(showGround()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJMGLayer::showGround), this);
	using FunctionType = decltype(showGround())(*)(GJMGLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5ec6d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJMGLayer::deactivateGround() -> decltype(deactivateGround()) {
	using FunctionType = decltype(deactivateGround())(*)(GJMGLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5ec6e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJMGLayer::init(int index) -> decltype(init(index)) {
	using FunctionType = decltype(init(index))(*)(GJMGLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5ebd60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}

auto GJMGLayer::loadGroundSprites(int count, bool ground1) -> decltype(loadGroundSprites(count, ground1)) {
	using FunctionType = decltype(loadGroundSprites(count, ground1))(*)(GJMGLayer*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5ec1f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, count, ground1);
}

auto GJMGLayer::scaleGround(float scale) -> decltype(scaleGround(scale)) {
	using FunctionType = decltype(scaleGround(scale))(*)(GJMGLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5ec560, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, scale);
}

auto GJMGLayer::toggleVisible01(bool visible) -> decltype(toggleVisible01(visible)) {
	using FunctionType = decltype(toggleVisible01(visible))(*)(GJMGLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5ec420, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, visible);
}

auto GJMGLayer::toggleVisible02(bool visible) -> decltype(toggleVisible02(visible)) {
	using FunctionType = decltype(toggleVisible02(visible))(*)(GJMGLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5ec460, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, visible);
}

auto GJMGLayer::updateGroundColor(cocos2d::ccColor3B color, bool ground1) -> decltype(updateGroundColor(color, ground1)) {
	using FunctionType = decltype(updateGroundColor(color, ground1))(*)(GJMGLayer*, cocos2d::ccColor3B, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5ec390, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, color, ground1);
}

auto GJMGLayer::updateGroundOpacity(unsigned char opacity, bool ground1) -> decltype(updateGroundOpacity(opacity, ground1)) {
	using FunctionType = decltype(updateGroundOpacity(opacity, ground1))(*)(GJMGLayer*, unsigned char, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5ec4e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, opacity, ground1);
}

auto GJMGLayer::updateGroundPos(cocos2d::CCPoint pos) -> decltype(updateGroundPos(pos)) {
	using FunctionType = decltype(updateGroundPos(pos))(*)(GJMGLayer*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5ec490, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, pos);
}

auto GJMGLayer::updateGroundWidth(bool useThis) -> decltype(updateGroundWidth(useThis)) {
	using FunctionType = decltype(updateGroundWidth(useThis))(*)(GJMGLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5ec5f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, useThis);
}

auto GJMGLayer::updateMG01Blend(bool blend) -> decltype(updateMG01Blend(blend)) {
	using FunctionType = decltype(updateMG01Blend(blend))(*)(GJMGLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5ec710, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, blend);
}

auto GJMGLayer::updateMG02Blend(bool blend) -> decltype(updateMG02Blend(blend)) {
	using FunctionType = decltype(updateMG02Blend(blend))(*)(GJMGLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5ec760, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, blend);
}
