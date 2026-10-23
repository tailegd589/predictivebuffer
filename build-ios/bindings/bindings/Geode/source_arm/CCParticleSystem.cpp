
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCParticleSystem.hpp>
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

cocos2d::CCParticleSystem::CCParticleSystem() : cocos2d::CCParticleSystem(geode::CutoffConstructor, sizeof(cocos2d::CCParticleSystem)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCParticleSystem::~CCParticleSystem();

	using FunctionType = void(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cba14, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCParticleSystem::~CCParticleSystem() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCParticleSystem*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x6cd8d0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCParticleSystem(geode::CutoffConstructor, sizeof(cocos2d::CCParticleSystem));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCParticleSystem::create(char const* p0) -> decltype(create(p0)) {
	using FunctionType = decltype(create(p0))(*)(char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cbb60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCParticleSystem::createWithTotalParticles(unsigned int p0) -> decltype(createWithTotalParticles(p0)) {
	using FunctionType = decltype(createWithTotalParticles(p0))(*)(unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cbe48, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCParticleSystem::update(float p0) -> decltype(update(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCParticleSystem::update), this);
	using FunctionType = decltype(update(p0))(*)(cocos2d::CCParticleSystem*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6ce94c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::init), this);
	using FunctionType = decltype(init())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cbed4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setScaleX(float p0) -> decltype(setScaleX(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCParticleSystem::setScaleX), this);
	using FunctionType = decltype(setScaleX(p0))(*)(cocos2d::CCParticleSystem*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cfad4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::setScaleY(float p0) -> decltype(setScaleY(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCParticleSystem::setScaleY), this);
	using FunctionType = decltype(setScaleY(p0))(*)(cocos2d::CCParticleSystem*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cfae0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::setScale(float p0) -> decltype(setScale(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCParticleSystem::setScale), this);
	using FunctionType = decltype(setScale(p0))(*)(cocos2d::CCParticleSystem*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cfabc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::setVisible(bool p0) -> decltype(setVisible(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCParticleSystem::setVisible), this);
	using FunctionType = decltype(setVisible(p0))(*)(cocos2d::CCParticleSystem*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf6e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::setRotation(float p0) -> decltype(setRotation(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCParticleSystem::setRotation), this);
	using FunctionType = decltype(setRotation(p0))(*)(cocos2d::CCParticleSystem*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cfac8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getBatchNode() -> decltype(getBatchNode()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getBatchNode), this);
	using FunctionType = decltype(getBatchNode())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cfa24, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setBatchNode(cocos2d::CCParticleBatchNode* p0) -> decltype(setBatchNode(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCParticleBatchNode*>::func(&cocos2d::CCParticleSystem::setBatchNode), this);
	using FunctionType = decltype(setBatchNode(p0))(*)(cocos2d::CCParticleSystem*, cocos2d::CCParticleBatchNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cfa2c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getParticleCount() -> decltype(getParticleCount()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getParticleCount), this);
	using FunctionType = decltype(getParticleCount())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf7ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::getDuration() -> decltype(getDuration()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getDuration), this);
	using FunctionType = decltype(getDuration())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf7f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setDuration(float p0) -> decltype(setDuration(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCParticleSystem::setDuration), this);
	using FunctionType = decltype(setDuration(p0))(*)(cocos2d::CCParticleSystem*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf7fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getSourcePosition() -> decltype(getSourcePosition()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getSourcePosition), this);
	using FunctionType = decltype(getSourcePosition())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf804, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setSourcePosition(cocos2d::CCPoint const& p0) -> decltype(setSourcePosition(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCPoint const&>::func(&cocos2d::CCParticleSystem::setSourcePosition), this);
	using FunctionType = decltype(setSourcePosition(p0))(*)(cocos2d::CCParticleSystem*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf80c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getPosVar() -> decltype(getPosVar()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getPosVar), this);
	using FunctionType = decltype(getPosVar())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf814, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setPosVar(cocos2d::CCPoint const& p0) -> decltype(setPosVar(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCPoint const&>::func(&cocos2d::CCParticleSystem::setPosVar), this);
	using FunctionType = decltype(setPosVar(p0))(*)(cocos2d::CCParticleSystem*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf81c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getLife() -> decltype(getLife()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getLife), this);
	using FunctionType = decltype(getLife())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf824, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setLife(float p0) -> decltype(setLife(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCParticleSystem::setLife), this);
	using FunctionType = decltype(setLife(p0))(*)(cocos2d::CCParticleSystem*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf82c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getLifeVar() -> decltype(getLifeVar()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getLifeVar), this);
	using FunctionType = decltype(getLifeVar())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf834, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setLifeVar(float p0) -> decltype(setLifeVar(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCParticleSystem::setLifeVar), this);
	using FunctionType = decltype(setLifeVar(p0))(*)(cocos2d::CCParticleSystem*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf83c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getAngle() -> decltype(getAngle()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getAngle), this);
	using FunctionType = decltype(getAngle())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf844, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setAngle(float p0) -> decltype(setAngle(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCParticleSystem::setAngle), this);
	using FunctionType = decltype(setAngle(p0))(*)(cocos2d::CCParticleSystem*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf84c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getAngleVar() -> decltype(getAngleVar()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getAngleVar), this);
	using FunctionType = decltype(getAngleVar())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf854, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setAngleVar(float p0) -> decltype(setAngleVar(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCParticleSystem::setAngleVar), this);
	using FunctionType = decltype(setAngleVar(p0))(*)(cocos2d::CCParticleSystem*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf85c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::updateEmissionRate() -> decltype(updateEmissionRate()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::updateEmissionRate), this);
	using FunctionType = decltype(updateEmissionRate())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cd8a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::getGravity() -> decltype(getGravity()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getGravity), this);
	using FunctionType = decltype(getGravity())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf75c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setGravity(cocos2d::CCPoint const& p0) -> decltype(setGravity(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCPoint const&>::func(&cocos2d::CCParticleSystem::setGravity), this);
	using FunctionType = decltype(setGravity(p0))(*)(cocos2d::CCParticleSystem*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf754, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getSpeed() -> decltype(getSpeed()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getSpeed), this);
	using FunctionType = decltype(getSpeed())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf76c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setSpeed(float p0) -> decltype(setSpeed(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCParticleSystem::setSpeed), this);
	using FunctionType = decltype(setSpeed(p0))(*)(cocos2d::CCParticleSystem*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf764, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getSpeedVar() -> decltype(getSpeedVar()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getSpeedVar), this);
	using FunctionType = decltype(getSpeedVar())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf77c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setSpeedVar(float p0) -> decltype(setSpeedVar(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCParticleSystem::setSpeedVar), this);
	using FunctionType = decltype(setSpeedVar(p0))(*)(cocos2d::CCParticleSystem*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf774, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getTangentialAccel() -> decltype(getTangentialAccel()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getTangentialAccel), this);
	using FunctionType = decltype(getTangentialAccel())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf70c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setTangentialAccel(float p0) -> decltype(setTangentialAccel(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCParticleSystem::setTangentialAccel), this);
	using FunctionType = decltype(setTangentialAccel(p0))(*)(cocos2d::CCParticleSystem*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf704, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getTangentialAccelVar() -> decltype(getTangentialAccelVar()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getTangentialAccelVar), this);
	using FunctionType = decltype(getTangentialAccelVar())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf71c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setTangentialAccelVar(float p0) -> decltype(setTangentialAccelVar(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCParticleSystem::setTangentialAccelVar), this);
	using FunctionType = decltype(setTangentialAccelVar(p0))(*)(cocos2d::CCParticleSystem*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf714, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getRadialAccel() -> decltype(getRadialAccel()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getRadialAccel), this);
	using FunctionType = decltype(getRadialAccel())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf72c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setRadialAccel(float p0) -> decltype(setRadialAccel(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCParticleSystem::setRadialAccel), this);
	using FunctionType = decltype(setRadialAccel(p0))(*)(cocos2d::CCParticleSystem*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf724, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getRadialAccelVar() -> decltype(getRadialAccelVar()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getRadialAccelVar), this);
	using FunctionType = decltype(getRadialAccelVar())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf73c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setRadialAccelVar(float p0) -> decltype(setRadialAccelVar(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCParticleSystem::setRadialAccelVar), this);
	using FunctionType = decltype(setRadialAccelVar(p0))(*)(cocos2d::CCParticleSystem*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf734, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getRotationIsDir() -> decltype(getRotationIsDir()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getRotationIsDir), this);
	using FunctionType = decltype(getRotationIsDir())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf74c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setRotationIsDir(bool p0) -> decltype(setRotationIsDir(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCParticleSystem::setRotationIsDir), this);
	using FunctionType = decltype(setRotationIsDir(p0))(*)(cocos2d::CCParticleSystem*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf744, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getStartRadius() -> decltype(getStartRadius()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getStartRadius), this);
	using FunctionType = decltype(getStartRadius())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf78c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setStartRadius(float p0) -> decltype(setStartRadius(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCParticleSystem::setStartRadius), this);
	using FunctionType = decltype(setStartRadius(p0))(*)(cocos2d::CCParticleSystem*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf784, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getStartRadiusVar() -> decltype(getStartRadiusVar()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getStartRadiusVar), this);
	using FunctionType = decltype(getStartRadiusVar())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf79c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setStartRadiusVar(float p0) -> decltype(setStartRadiusVar(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCParticleSystem::setStartRadiusVar), this);
	using FunctionType = decltype(setStartRadiusVar(p0))(*)(cocos2d::CCParticleSystem*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf794, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getEndRadius() -> decltype(getEndRadius()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getEndRadius), this);
	using FunctionType = decltype(getEndRadius())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf7ac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setEndRadius(float p0) -> decltype(setEndRadius(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCParticleSystem::setEndRadius), this);
	using FunctionType = decltype(setEndRadius(p0))(*)(cocos2d::CCParticleSystem*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf7a4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getEndRadiusVar() -> decltype(getEndRadiusVar()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getEndRadiusVar), this);
	using FunctionType = decltype(getEndRadiusVar())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf7bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setEndRadiusVar(float p0) -> decltype(setEndRadiusVar(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCParticleSystem::setEndRadiusVar), this);
	using FunctionType = decltype(setEndRadiusVar(p0))(*)(cocos2d::CCParticleSystem*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf7b4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getRotatePerSecond() -> decltype(getRotatePerSecond()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getRotatePerSecond), this);
	using FunctionType = decltype(getRotatePerSecond())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf7cc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setRotatePerSecond(float p0) -> decltype(setRotatePerSecond(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCParticleSystem::setRotatePerSecond), this);
	using FunctionType = decltype(setRotatePerSecond(p0))(*)(cocos2d::CCParticleSystem*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf7c4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getRotatePerSecondVar() -> decltype(getRotatePerSecondVar()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getRotatePerSecondVar), this);
	using FunctionType = decltype(getRotatePerSecondVar())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf7dc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setRotatePerSecondVar(float p0) -> decltype(setRotatePerSecondVar(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCParticleSystem::setRotatePerSecondVar), this);
	using FunctionType = decltype(setRotatePerSecondVar(p0))(*)(cocos2d::CCParticleSystem*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf7d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::isActive() -> decltype(isActive()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::isActive), this);
	using FunctionType = decltype(isActive())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf7e4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::isBlendAdditive() -> decltype(isBlendAdditive()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::isBlendAdditive), this);
	using FunctionType = decltype(isBlendAdditive())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf6bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setBlendAdditive(bool p0) -> decltype(setBlendAdditive(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCParticleSystem::setBlendAdditive), this);
	using FunctionType = decltype(setBlendAdditive(p0))(*)(cocos2d::CCParticleSystem*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf644, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getStartSize() -> decltype(getStartSize()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getStartSize), this);
	using FunctionType = decltype(getStartSize())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf864, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setStartSize(float p0) -> decltype(setStartSize(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCParticleSystem::setStartSize), this);
	using FunctionType = decltype(setStartSize(p0))(*)(cocos2d::CCParticleSystem*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf86c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getStartSizeVar() -> decltype(getStartSizeVar()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getStartSizeVar), this);
	using FunctionType = decltype(getStartSizeVar())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf874, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setStartSizeVar(float p0) -> decltype(setStartSizeVar(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCParticleSystem::setStartSizeVar), this);
	using FunctionType = decltype(setStartSizeVar(p0))(*)(cocos2d::CCParticleSystem*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf87c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getEndSize() -> decltype(getEndSize()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getEndSize), this);
	using FunctionType = decltype(getEndSize())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf884, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setEndSize(float p0) -> decltype(setEndSize(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCParticleSystem::setEndSize), this);
	using FunctionType = decltype(setEndSize(p0))(*)(cocos2d::CCParticleSystem*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf88c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getEndSizeVar() -> decltype(getEndSizeVar()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getEndSizeVar), this);
	using FunctionType = decltype(getEndSizeVar())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf894, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setEndSizeVar(float p0) -> decltype(setEndSizeVar(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCParticleSystem::setEndSizeVar), this);
	using FunctionType = decltype(setEndSizeVar(p0))(*)(cocos2d::CCParticleSystem*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf89c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getStartColor() -> decltype(getStartColor()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getStartColor), this);
	using FunctionType = decltype(getStartColor())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf8a4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setStartColor(cocos2d::ccColor4F const& p0) -> decltype(setStartColor(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccColor4F const&>::func(&cocos2d::CCParticleSystem::setStartColor), this);
	using FunctionType = decltype(setStartColor(p0))(*)(cocos2d::CCParticleSystem*, cocos2d::ccColor4F const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf8ac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getStartColorVar() -> decltype(getStartColorVar()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getStartColorVar), this);
	using FunctionType = decltype(getStartColorVar())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf8bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setStartColorVar(cocos2d::ccColor4F const& p0) -> decltype(setStartColorVar(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccColor4F const&>::func(&cocos2d::CCParticleSystem::setStartColorVar), this);
	using FunctionType = decltype(setStartColorVar(p0))(*)(cocos2d::CCParticleSystem*, cocos2d::ccColor4F const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf8c4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getEndColor() -> decltype(getEndColor()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getEndColor), this);
	using FunctionType = decltype(getEndColor())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf8d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setEndColor(cocos2d::ccColor4F const& p0) -> decltype(setEndColor(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccColor4F const&>::func(&cocos2d::CCParticleSystem::setEndColor), this);
	using FunctionType = decltype(setEndColor(p0))(*)(cocos2d::CCParticleSystem*, cocos2d::ccColor4F const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf8dc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getEndColorVar() -> decltype(getEndColorVar()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getEndColorVar), this);
	using FunctionType = decltype(getEndColorVar())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf8ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setEndColorVar(cocos2d::ccColor4F const& p0) -> decltype(setEndColorVar(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccColor4F const&>::func(&cocos2d::CCParticleSystem::setEndColorVar), this);
	using FunctionType = decltype(setEndColorVar(p0))(*)(cocos2d::CCParticleSystem*, cocos2d::ccColor4F const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf8f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getStartSpin() -> decltype(getStartSpin()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getStartSpin), this);
	using FunctionType = decltype(getStartSpin())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf904, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setStartSpin(float p0) -> decltype(setStartSpin(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCParticleSystem::setStartSpin), this);
	using FunctionType = decltype(setStartSpin(p0))(*)(cocos2d::CCParticleSystem*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf90c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getStartSpinVar() -> decltype(getStartSpinVar()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getStartSpinVar), this);
	using FunctionType = decltype(getStartSpinVar())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf914, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setStartSpinVar(float p0) -> decltype(setStartSpinVar(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCParticleSystem::setStartSpinVar), this);
	using FunctionType = decltype(setStartSpinVar(p0))(*)(cocos2d::CCParticleSystem*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf91c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getEndSpin() -> decltype(getEndSpin()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getEndSpin), this);
	using FunctionType = decltype(getEndSpin())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf924, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setEndSpin(float p0) -> decltype(setEndSpin(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCParticleSystem::setEndSpin), this);
	using FunctionType = decltype(setEndSpin(p0))(*)(cocos2d::CCParticleSystem*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf92c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getEndSpinVar() -> decltype(getEndSpinVar()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getEndSpinVar), this);
	using FunctionType = decltype(getEndSpinVar())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf934, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setEndSpinVar(float p0) -> decltype(setEndSpinVar(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCParticleSystem::setEndSpinVar), this);
	using FunctionType = decltype(setEndSpinVar(p0))(*)(cocos2d::CCParticleSystem*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf93c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getEmissionRate() -> decltype(getEmissionRate()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getEmissionRate), this);
	using FunctionType = decltype(getEmissionRate())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf944, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setEmissionRate(float p0) -> decltype(setEmissionRate(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCParticleSystem::setEmissionRate), this);
	using FunctionType = decltype(setEmissionRate(p0))(*)(cocos2d::CCParticleSystem*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf94c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getTotalParticles() -> decltype(getTotalParticles()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getTotalParticles), this);
	using FunctionType = decltype(getTotalParticles())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf954, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setTotalParticles(unsigned int p0) -> decltype(setTotalParticles(p0)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned int>::func(&cocos2d::CCParticleSystem::setTotalParticles), this);
	using FunctionType = decltype(setTotalParticles(p0))(*)(cocos2d::CCParticleSystem*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf95c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getOpacityModifyRGB() -> decltype(getOpacityModifyRGB()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getOpacityModifyRGB), this);
	using FunctionType = decltype(getOpacityModifyRGB())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf9e4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setOpacityModifyRGB(bool p0) -> decltype(setOpacityModifyRGB(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCParticleSystem::setOpacityModifyRGB), this);
	using FunctionType = decltype(setOpacityModifyRGB(p0))(*)(cocos2d::CCParticleSystem*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf9ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getPositionType() -> decltype(getPositionType()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getPositionType), this);
	using FunctionType = decltype(getPositionType())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf9f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setPositionType(cocos2d::tCCPositionType p0) -> decltype(setPositionType(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::tCCPositionType>::func(&cocos2d::CCParticleSystem::setPositionType), this);
	using FunctionType = decltype(setPositionType(p0))(*)(cocos2d::CCParticleSystem*, cocos2d::tCCPositionType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf9fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::isAutoRemoveOnFinish() -> decltype(isAutoRemoveOnFinish()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::isAutoRemoveOnFinish), this);
	using FunctionType = decltype(isAutoRemoveOnFinish())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cfa04, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setAutoRemoveOnFinish(bool p0) -> decltype(setAutoRemoveOnFinish(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCParticleSystem::setAutoRemoveOnFinish), this);
	using FunctionType = decltype(setAutoRemoveOnFinish(p0))(*)(cocos2d::CCParticleSystem*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cfa0c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getEmitterMode() -> decltype(getEmitterMode()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getEmitterMode), this);
	using FunctionType = decltype(getEmitterMode())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cfa14, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setEmitterMode(int p0) -> decltype(setEmitterMode(p0)) {
	auto self = addresser::thunkAdjust(Resolve<int>::func(&cocos2d::CCParticleSystem::setEmitterMode), this);
	using FunctionType = decltype(setEmitterMode(p0))(*)(cocos2d::CCParticleSystem*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cfa1c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::initWithTotalParticles(unsigned int p0, bool p1) -> decltype(initWithTotalParticles(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned int, bool>::func(&cocos2d::CCParticleSystem::initWithTotalParticles), this);
	using FunctionType = decltype(initWithTotalParticles(p0, p1))(*)(cocos2d::CCParticleSystem*, unsigned int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cd770, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCParticleSystem::updateQuadWithParticle(cocos2d::sCCParticle* p0, cocos2d::CCPoint const& p1) -> decltype(updateQuadWithParticle(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::sCCParticle*, cocos2d::CCPoint const&>::func(&cocos2d::CCParticleSystem::updateQuadWithParticle), this);
	using FunctionType = decltype(updateQuadWithParticle(p0, p1))(*)(cocos2d::CCParticleSystem*, cocos2d::sCCParticle*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf46c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCParticleSystem::postStep() -> decltype(postStep()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::postStep), this);
	using FunctionType = decltype(postStep())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf4f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::updateWithNoTime() -> decltype(updateWithNoTime()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::updateWithNoTime), this);
	using FunctionType = decltype(updateWithNoTime())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf45c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::updateBlendFunc() -> decltype(updateBlendFunc()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::updateBlendFunc), this);
	using FunctionType = decltype(updateBlendFunc())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf5c4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setBlendFunc(cocos2d::ccBlendFunc p0) -> decltype(setBlendFunc(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccBlendFunc>::func(&cocos2d::CCParticleSystem::setBlendFunc), this);
	using FunctionType = decltype(setBlendFunc(p0))(*)(cocos2d::CCParticleSystem*, cocos2d::ccBlendFunc);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf974, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::getBlendFunc() -> decltype(getBlendFunc()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getBlendFunc), this);
	using FunctionType = decltype(getBlendFunc())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf964, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::getTexture() -> decltype(getTexture()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystem::getTexture), this);
	using FunctionType = decltype(getTexture())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf634, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystem::setTexture(cocos2d::CCTexture2D* p0) -> decltype(setTexture(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTexture2D*>::func(&cocos2d::CCParticleSystem::setTexture), this);
	using FunctionType = decltype(setTexture(p0))(*)(cocos2d::CCParticleSystem*, cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf4f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystem::addParticle() -> decltype(addParticle()) {
	using FunctionType = decltype(addParticle())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cda34, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCParticleSystem::calculateWorldSpace() -> decltype(calculateWorldSpace()) {
	using FunctionType = decltype(calculateWorldSpace())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6ce78c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCParticleSystem::getParticleDrawCost() -> decltype(getParticleDrawCost()) {
	using FunctionType = decltype(getParticleDrawCost())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cf470, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCParticleSystem::getTimeElapsed() -> decltype(getTimeElapsed()) {
	using FunctionType = decltype(getTimeElapsed())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cd8c8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCParticleSystem::initParticle(cocos2d::sCCParticle* p0) -> decltype(initParticle(p0)) {
	using FunctionType = decltype(initParticle(p0))(*)(cocos2d::CCParticleSystem*, cocos2d::sCCParticle*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cdaa0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCParticleSystem::initWithDictionary(cocos2d::CCDictionary* p0, bool p1) -> decltype(initWithDictionary(p0, p1)) {
	using FunctionType = decltype(initWithDictionary(p0, p1))(*)(cocos2d::CCParticleSystem*, cocos2d::CCDictionary*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cd6dc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCParticleSystem::initWithDictionary(cocos2d::CCDictionary* p0, char const* p1, bool p2) -> decltype(initWithDictionary(p0, p1, p2)) {
	using FunctionType = decltype(initWithDictionary(p0, p1, p2))(*)(cocos2d::CCParticleSystem*, cocos2d::CCDictionary*, char const*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cbee8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCParticleSystem::initWithFile(char const* p0, bool p1) -> decltype(initWithFile(p0, p1)) {
	using FunctionType = decltype(initWithFile(p0, p1))(*)(cocos2d::CCParticleSystem*, char const*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cbbe4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCParticleSystem::isFull() -> decltype(isFull()) {
	using FunctionType = decltype(isFull())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cda8c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCParticleSystem::loadDefaults() -> decltype(loadDefaults()) {
	using FunctionType = decltype(loadDefaults())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cfaec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCParticleSystem::loadScaledDefaults(float p0) -> decltype(loadScaledDefaults(p0)) {
	using FunctionType = decltype(loadScaledDefaults(p0))(*)(cocos2d::CCParticleSystem*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cfb68, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCParticleSystem::resetSystem() -> decltype(resetSystem()) {
	using FunctionType = decltype(resetSystem())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6ce7fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCParticleSystem::resumeSystem() -> decltype(resumeSystem()) {
	using FunctionType = decltype(resumeSystem())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6ce7f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCParticleSystem::saveDefaults() -> decltype(saveDefaults()) {
	using FunctionType = decltype(saveDefaults())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cd6ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCParticleSystem::stopSystem() -> decltype(stopSystem()) {
	using FunctionType = decltype(stopSystem())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6ce7dc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCParticleSystem::updateVisible() -> decltype(updateVisible()) {
	using FunctionType = decltype(updateVisible())(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6ce924, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
