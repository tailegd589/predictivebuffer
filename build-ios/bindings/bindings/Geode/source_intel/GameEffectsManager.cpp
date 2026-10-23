
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GameEffectsManager.hpp>
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

auto GameEffectsManager::create(PlayLayer* playLayer) -> decltype(create(playLayer)) {
	using FunctionType = decltype(create(playLayer))(*)(PlayLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x201f00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(playLayer);
}

auto GameEffectsManager::addParticleEffect(cocos2d::CCParticleSystemQuad* particle, int unused) -> decltype(addParticleEffect(particle, unused)) {
	using FunctionType = decltype(addParticleEffect(particle, unused))(*)(GameEffectsManager*, cocos2d::CCParticleSystemQuad*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2020b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, particle, unused);
}

auto GameEffectsManager::init(PlayLayer* playLayer) -> decltype(init(playLayer)) {
	using FunctionType = decltype(init(playLayer))(*)(GameEffectsManager*, PlayLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x201f60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, playLayer);
}

auto GameEffectsManager::scaleParticle(cocos2d::CCParticleSystemQuad* particle, float scale) -> decltype(scaleParticle(particle, scale)) {
	using FunctionType = decltype(scaleParticle(particle, scale))(*)(GameEffectsManager*, cocos2d::CCParticleSystemQuad*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x201f70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, particle, scale);
}
