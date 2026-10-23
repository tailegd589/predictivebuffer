
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/ParticlePreviewLayer.hpp>
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

auto ParticlePreviewLayer::create(cocos2d::CCParticleSystemQuad* particleSystem) -> decltype(create(particleSystem)) {
	using FunctionType = decltype(create(particleSystem))(*)(cocos2d::CCParticleSystemQuad*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3da404, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(particleSystem);
}

auto ParticlePreviewLayer::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&ParticlePreviewLayer::draw), this);
	using FunctionType = decltype(draw())(*)(ParticlePreviewLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3de758, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto ParticlePreviewLayer::visit() -> decltype(visit()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&ParticlePreviewLayer::visit), this);
	using FunctionType = decltype(visit())(*)(ParticlePreviewLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3de5d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto ParticlePreviewLayer::init(cocos2d::CCParticleSystemQuad* particleSystem) -> decltype(init(particleSystem)) {
	using FunctionType = decltype(init(particleSystem))(*)(ParticlePreviewLayer*, cocos2d::CCParticleSystemQuad*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3de558, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, particleSystem);
}

auto ParticlePreviewLayer::postVisit() -> decltype(postVisit()) {
	using FunctionType = decltype(postVisit())(*)(ParticlePreviewLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3de750, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto ParticlePreviewLayer::preVisitWithClippingRect(cocos2d::CCRect rect) -> decltype(preVisitWithClippingRect(rect)) {
	using FunctionType = decltype(preVisitWithClippingRect(rect))(*)(ParticlePreviewLayer*, cocos2d::CCRect);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3de6b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, rect);
}
