
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJGroundLayer.hpp>
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

auto GJGroundLayer::create(int groundID, int lineType) -> decltype(create(groundID, lineType)) {
	using FunctionType = decltype(create(groundID, lineType))(*)(int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5ea980, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(groundID, lineType);
}

auto GJGroundLayer::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJGroundLayer::draw), this);
	using FunctionType = decltype(draw())(*)(GJGroundLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5ebab0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJGroundLayer::showGround() -> decltype(showGround()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJGroundLayer::showGround), this);
	using FunctionType = decltype(showGround())(*)(GJGroundLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5eb8d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJGroundLayer::fadeInGround(float duration) -> decltype(fadeInGround(duration)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&GJGroundLayer::fadeInGround), this);
	using FunctionType = decltype(fadeInGround(duration))(*)(GJGroundLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5eb8e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, duration);
}

auto GJGroundLayer::fadeOutGround(float duration) -> decltype(fadeOutGround(duration)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&GJGroundLayer::fadeOutGround), this);
	using FunctionType = decltype(fadeOutGround(duration))(*)(GJGroundLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5eba80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, duration);
}

auto GJGroundLayer::createLine(int lineType) -> decltype(createLine(lineType)) {
	using FunctionType = decltype(createLine(lineType))(*)(GJGroundLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5eaf70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, lineType);
}

auto GJGroundLayer::deactivateGround() -> decltype(deactivateGround()) {
	using FunctionType = decltype(deactivateGround())(*)(GJGroundLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5eba90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJGroundLayer::fadeInFinished() -> decltype(fadeInFinished()) {
	using FunctionType = decltype(fadeInFinished())(*)(GJGroundLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5eb950, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJGroundLayer::getGroundY() -> decltype(getGroundY()) {
	using FunctionType = decltype(getGroundY())(*)(GJGroundLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5ebb00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJGroundLayer::hideShadows() -> decltype(hideShadows()) {
	using FunctionType = decltype(hideShadows())(*)(GJGroundLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5eb960, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJGroundLayer::init(int groundID, int lineType) -> decltype(init(groundID, lineType)) {
	using FunctionType = decltype(init(groundID, lineType))(*)(GJGroundLayer*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5eaa90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, groundID, lineType);
}

auto GJGroundLayer::loadGroundSprites(int count, bool ground1) -> decltype(loadGroundSprites(count, ground1)) {
	using FunctionType = decltype(loadGroundSprites(count, ground1))(*)(GJGroundLayer*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5eb130, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, count, ground1);
}

auto GJGroundLayer::positionGround(float y) -> decltype(positionGround(y)) {
	using FunctionType = decltype(positionGround(y))(*)(GJGroundLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5ebac0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, y);
}

auto GJGroundLayer::scaleGround(float scale) -> decltype(scaleGround(scale)) {
	using FunctionType = decltype(scaleGround(scale))(*)(GJGroundLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5eb560, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, scale);
}

auto GJGroundLayer::toggleVisible01(bool visible) -> decltype(toggleVisible01(visible)) {
	using FunctionType = decltype(toggleVisible01(visible))(*)(GJGroundLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5eb410, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, visible);
}

auto GJGroundLayer::toggleVisible02(bool visible) -> decltype(toggleVisible02(visible)) {
	using FunctionType = decltype(toggleVisible02(visible))(*)(GJGroundLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5eb450, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, visible);
}

auto GJGroundLayer::updateGround01Color(cocos2d::ccColor3B color) -> decltype(updateGround01Color(color)) {
	using FunctionType = decltype(updateGround01Color(color))(*)(GJGroundLayer*, cocos2d::ccColor3B);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5eb390, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, color);
}

auto GJGroundLayer::updateGround02Color(cocos2d::ccColor3B color) -> decltype(updateGround02Color(color)) {
	using FunctionType = decltype(updateGround02Color(color))(*)(GJGroundLayer*, cocos2d::ccColor3B);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5eb4d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, color);
}

auto GJGroundLayer::updateGroundPos(cocos2d::CCPoint pos) -> decltype(updateGroundPos(pos)) {
	using FunctionType = decltype(updateGroundPos(pos))(*)(GJGroundLayer*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5eb480, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, pos);
}

auto GJGroundLayer::updateGroundWidth(bool useThis) -> decltype(updateGroundWidth(useThis)) {
	using FunctionType = decltype(updateGroundWidth(useThis))(*)(GJGroundLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5eb670, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, useThis);
}

auto GJGroundLayer::updateLineBlend(bool blend) -> decltype(updateLineBlend(blend)) {
	using FunctionType = decltype(updateLineBlend(blend))(*)(GJGroundLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5eb880, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, blend);
}

auto GJGroundLayer::updateShadows() -> decltype(updateShadows()) {
	using FunctionType = decltype(updateShadows())(*)(GJGroundLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5eb7f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJGroundLayer::updateShadowXPos(float leftX, float rightX) -> decltype(updateShadowXPos(leftX, rightX)) {
	using FunctionType = decltype(updateShadowXPos(leftX, rightX))(*)(GJGroundLayer*, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5eb9c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, leftX, rightX);
}
