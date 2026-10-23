
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCAnimationFrame.hpp>
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

cocos2d::CCAnimationFrame::CCAnimationFrame() : cocos2d::CCAnimationFrame(geode::CutoffConstructor, sizeof(cocos2d::CCAnimationFrame)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCAnimationFrame::~CCAnimationFrame();

	using FunctionType = void(*)(cocos2d::CCAnimationFrame*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x236760, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCAnimationFrame::~CCAnimationFrame() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCAnimationFrame*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x236824, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCAnimationFrame(geode::CutoffConstructor, sizeof(cocos2d::CCAnimationFrame));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCAnimationFrame::copyWithZone(cocos2d::CCZone* p0) -> decltype(copyWithZone(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCAnimationFrame::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(p0))(*)(cocos2d::CCAnimationFrame*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x236900, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCAnimationFrame::initWithSpriteFrame(cocos2d::CCSpriteFrame* p0, float p1, cocos2d::CCDictionary* p2) -> decltype(initWithSpriteFrame(p0, p1, p2)) {
	using FunctionType = decltype(initWithSpriteFrame(p0, p1, p2))(*)(cocos2d::CCAnimationFrame*, cocos2d::CCSpriteFrame*, float, cocos2d::CCDictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x236794, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}
