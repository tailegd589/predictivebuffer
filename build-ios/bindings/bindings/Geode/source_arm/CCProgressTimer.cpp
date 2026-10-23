
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCProgressTimer.hpp>
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

cocos2d::CCProgressTimer::CCProgressTimer() : cocos2d::CCProgressTimer(geode::CutoffConstructor, sizeof(cocos2d::CCProgressTimer)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCProgressTimer::~CCProgressTimer();

	using FunctionType = void(*)(cocos2d::CCProgressTimer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52b304, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCProgressTimer::~CCProgressTimer() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCProgressTimer*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x52b71c, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCProgressTimer(geode::CutoffConstructor, sizeof(cocos2d::CCProgressTimer));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCProgressTimer::create(cocos2d::CCSprite* p0) -> decltype(create(p0)) {
	using FunctionType = decltype(create(p0))(*)(cocos2d::CCSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52b40c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCProgressTimer::getColor() const  -> decltype(getColor()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCProgressTimer::getColor), this);
	using FunctionType = decltype(getColor())(*)(cocos2d::CCProgressTimer const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52b9f8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCProgressTimer::getOpacity() const  -> decltype(getOpacity()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCProgressTimer::getOpacity), this);
	using FunctionType = decltype(getOpacity())(*)(cocos2d::CCProgressTimer const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52bae8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCProgressTimer::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCProgressTimer::draw), this);
	using FunctionType = decltype(draw())(*)(cocos2d::CCProgressTimer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52d0c4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCProgressTimer::getMidpoint() -> decltype(getMidpoint()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCProgressTimer::getMidpoint), this);
	using FunctionType = decltype(getMidpoint())(*)(cocos2d::CCProgressTimer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52cfdc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCProgressTimer::setMidpoint(cocos2d::CCPoint p0) -> decltype(setMidpoint(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCPoint>::func(&cocos2d::CCProgressTimer::setMidpoint), this);
	using FunctionType = decltype(setMidpoint(p0))(*)(cocos2d::CCProgressTimer*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52cfe8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCProgressTimer::setColor(cocos2d::ccColor3B const& p0) -> decltype(setColor(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccColor3B const&>::func(&cocos2d::CCProgressTimer::setColor), this);
	using FunctionType = decltype(setColor(p0))(*)(cocos2d::CCProgressTimer*, cocos2d::ccColor3B const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52b8d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCProgressTimer::setOpacity(unsigned char p0) -> decltype(setOpacity(p0)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned char>::func(&cocos2d::CCProgressTimer::setOpacity), this);
	using FunctionType = decltype(setOpacity(p0))(*)(cocos2d::CCProgressTimer*, unsigned char);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52ba08, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCProgressTimer::boundaryTexCoord(char p0) -> decltype(boundaryTexCoord(p0)) {
	using FunctionType = decltype(boundaryTexCoord(p0))(*)(cocos2d::CCProgressTimer*, char);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52d044, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCProgressTimer::initWithSprite(cocos2d::CCSprite* p0) -> decltype(initWithSprite(p0)) {
	using FunctionType = decltype(initWithSprite(p0))(*)(cocos2d::CCProgressTimer*, cocos2d::CCSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52b4c8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCProgressTimer::setAnchorPoint(cocos2d::CCPoint p0) -> decltype(setAnchorPoint(p0)) {
	using FunctionType = decltype(setAnchorPoint(p0))(*)(cocos2d::CCProgressTimer*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52b698, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCProgressTimer::setPercentage(float p0) -> decltype(setPercentage(p0)) {
	using FunctionType = decltype(setPercentage(p0))(*)(cocos2d::CCProgressTimer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52b62c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCProgressTimer::setReverseProgress(bool p0) -> decltype(setReverseProgress(p0)) {
	using FunctionType = decltype(setReverseProgress(p0))(*)(cocos2d::CCProgressTimer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52b888, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCProgressTimer::setSprite(cocos2d::CCSprite* p0) -> decltype(setSprite(p0)) {
	using FunctionType = decltype(setSprite(p0))(*)(cocos2d::CCProgressTimer*, cocos2d::CCSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52b69c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCProgressTimer::setType(cocos2d::CCProgressTimerType type) -> decltype(setType(type)) {
	using FunctionType = decltype(setType(type))(*)(cocos2d::CCProgressTimer*, cocos2d::CCProgressTimerType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52b838, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type);
}

auto cocos2d::CCProgressTimer::textureCoordFromAlphaPoint(cocos2d::CCPoint p0) -> decltype(textureCoordFromAlphaPoint(p0)) {
	using FunctionType = decltype(textureCoordFromAlphaPoint(p0))(*)(cocos2d::CCProgressTimer*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52baf8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCProgressTimer::updateBar() -> decltype(updateBar()) {
	using FunctionType = decltype(updateBar())(*)(cocos2d::CCProgressTimer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52c398, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCProgressTimer::updateColor() -> decltype(updateColor()) {
	using FunctionType = decltype(updateColor())(*)(cocos2d::CCProgressTimer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52b940, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCProgressTimer::updateProgress() -> decltype(updateProgress()) {
	using FunctionType = decltype(updateProgress())(*)(cocos2d::CCProgressTimer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52b81c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCProgressTimer::updateRadial() -> decltype(updateRadial()) {
	using FunctionType = decltype(updateRadial())(*)(cocos2d::CCProgressTimer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52bc1c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCProgressTimer::vertexFromAlphaPoint(cocos2d::CCPoint p0) -> decltype(vertexFromAlphaPoint(p0)) {
	using FunctionType = decltype(vertexFromAlphaPoint(p0))(*)(cocos2d::CCProgressTimer*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52bb98, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
