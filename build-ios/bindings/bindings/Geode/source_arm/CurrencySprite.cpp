
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/CurrencySprite.hpp>
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

CurrencySprite::~CurrencySprite() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(CurrencySprite*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x6b0814, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) CurrencySprite(geode::CutoffConstructor, sizeof(CurrencySprite));
		geode::DestructorLock::addLock(this);
	}
}

auto CurrencySprite::create(CurrencySpriteType type, bool burst) -> decltype(create(type, burst)) {
	using FunctionType = decltype(create(type, burst))(*)(CurrencySpriteType, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6aeb34, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type, burst);
}

auto CurrencySprite::createWithSprite(cocos2d::CCSprite* sprite) -> decltype(createWithSprite(sprite)) {
	using FunctionType = decltype(createWithSprite(sprite))(*)(cocos2d::CCSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6af81c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(sprite);
}

auto CurrencySprite::rewardToSpriteType(int rewardType) -> decltype(rewardToSpriteType(rewardType)) {
	using FunctionType = decltype(rewardToSpriteType(rewardType))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b1374, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(rewardType);
}

auto CurrencySprite::spriteTypeToStat(CurrencySpriteType type) -> decltype(spriteTypeToStat(type)) {
	using FunctionType = decltype(spriteTypeToStat(type))(*)(CurrencySpriteType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6ae990, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type);
}

auto CurrencySprite::init(CurrencySpriteType type, bool burst) -> decltype(init(type, burst)) {
	using FunctionType = decltype(init(type, burst))(*)(CurrencySprite*, CurrencySpriteType, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b08fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type, burst);
}

auto CurrencySprite::initWithSprite(cocos2d::CCSprite* sprite) -> decltype(initWithSprite(sprite)) {
	using FunctionType = decltype(initWithSprite(sprite))(*)(CurrencySprite*, cocos2d::CCSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b11c4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sprite);
}
