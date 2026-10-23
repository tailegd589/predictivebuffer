
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCGridBase.hpp>
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

cocos2d::CCGridBase::~CCGridBase() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCGridBase*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x4e3840, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCGridBase(geode::CutoffConstructor, sizeof(cocos2d::CCGridBase));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCGridBase::create(cocos2d::CCSize const& p0) -> decltype(create(p0)) {
	using FunctionType = decltype(create(p0))(*)(cocos2d::CCSize const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e3500, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCGridBase::create(cocos2d::CCSize const& p0, cocos2d::CCTexture2D* p1, bool p2) -> decltype(create(p0, p1, p2)) {
	using FunctionType = decltype(create(p0, p1, p2))(*)(cocos2d::CCSize const&, cocos2d::CCTexture2D*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e36b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::CCGridBase::blit() -> decltype(blit()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCGridBase::blit), this);
	using FunctionType = decltype(blit())(*)(cocos2d::CCGridBase*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e3b00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCGridBase::reuse() -> decltype(reuse()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCGridBase::reuse), this);
	using FunctionType = decltype(reuse())(*)(cocos2d::CCGridBase*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e3b10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCGridBase::calculateVertexPoints() -> decltype(calculateVertexPoints()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCGridBase::calculateVertexPoints), this);
	using FunctionType = decltype(calculateVertexPoints())(*)(cocos2d::CCGridBase*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e3b20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCGridBase::afterDraw(cocos2d::CCNode* p0) -> decltype(afterDraw(p0)) {
	using FunctionType = decltype(afterDraw(p0))(*)(cocos2d::CCGridBase*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e3a40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCGridBase::beforeDraw() -> decltype(beforeDraw()) {
	using FunctionType = decltype(beforeDraw())(*)(cocos2d::CCGridBase*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e3a10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCGridBase::initWithSize(cocos2d::CCSize const& p0) -> decltype(initWithSize(p0)) {
	using FunctionType = decltype(initWithSize(p0))(*)(cocos2d::CCGridBase*, cocos2d::CCSize const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e35c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCGridBase::initWithSize(cocos2d::CCSize const& p0, cocos2d::CCTexture2D* p1, bool p2) -> decltype(initWithSize(p0, p1, p2)) {
	using FunctionType = decltype(initWithSize(p0, p1, p2))(*)(cocos2d::CCGridBase*, cocos2d::CCSize const&, cocos2d::CCTexture2D*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e3780, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCGridBase::set2DProjection() -> decltype(set2DProjection()) {
	using FunctionType = decltype(set2DProjection())(*)(cocos2d::CCGridBase*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e3980, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCGridBase::setActive(bool p0) -> decltype(setActive(p0)) {
	using FunctionType = decltype(setActive(p0))(*)(cocos2d::CCGridBase*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e3930, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCGridBase::setTextureFlipped(bool p0) -> decltype(setTextureFlipped(p0)) {
	using FunctionType = decltype(setTextureFlipped(p0))(*)(cocos2d::CCGridBase*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e3960, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
