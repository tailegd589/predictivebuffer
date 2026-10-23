
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCTurnOffTiles.hpp>
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

cocos2d::CCTurnOffTiles::~CCTurnOffTiles() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCTurnOffTiles*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x6bcef0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCTurnOffTiles(geode::CutoffConstructor, sizeof(cocos2d::CCTurnOffTiles));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCTurnOffTiles::create(float p0, cocos2d::CCSize const& p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(float, cocos2d::CCSize const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6bcbc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCTurnOffTiles::create(float p0, cocos2d::CCSize const& p1, unsigned int p2) -> decltype(create(p0, p1, p2)) {
	using FunctionType = decltype(create(p0, p1, p2))(*)(float, cocos2d::CCSize const&, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6bccac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::CCTurnOffTiles::copyWithZone(cocos2d::CCZone* p0) -> decltype(copyWithZone(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCTurnOffTiles::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(p0))(*)(cocos2d::CCTurnOffTiles*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6bcdd8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCTurnOffTiles::update(float p0) -> decltype(update(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCTurnOffTiles::update), this);
	using FunctionType = decltype(update(p0))(*)(cocos2d::CCTurnOffTiles*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6bd1cc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCTurnOffTiles::startWithTarget(cocos2d::CCNode* p0) -> decltype(startWithTarget(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*>::func(&cocos2d::CCTurnOffTiles::startWithTarget), this);
	using FunctionType = decltype(startWithTarget(p0))(*)(cocos2d::CCTurnOffTiles*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6bd07c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCTurnOffTiles::initWithDuration(float p0, cocos2d::CCSize const& p1, unsigned int p2) -> decltype(initWithDuration(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<float, cocos2d::CCSize const&, unsigned int>::func(&cocos2d::CCTurnOffTiles::initWithDuration), this);
	using FunctionType = decltype(initWithDuration(p0, p1, p2))(*)(cocos2d::CCTurnOffTiles*, float, cocos2d::CCSize const&, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6bcda8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}

auto cocos2d::CCTurnOffTiles::shuffle(unsigned int* p0, unsigned int p1) -> decltype(shuffle(p0, p1)) {
	using FunctionType = decltype(shuffle(p0, p1))(*)(cocos2d::CCTurnOffTiles*, unsigned int*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6bcfb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCTurnOffTiles::turnOffTile(cocos2d::CCPoint const& p0) -> decltype(turnOffTile(p0)) {
	using FunctionType = decltype(turnOffTile(p0))(*)(cocos2d::CCTurnOffTiles*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6bd050, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTurnOffTiles::turnOnTile(cocos2d::CCPoint const& p0) -> decltype(turnOnTile(p0)) {
	using FunctionType = decltype(turnOnTile(p0))(*)(cocos2d::CCTurnOffTiles*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6bd010, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
