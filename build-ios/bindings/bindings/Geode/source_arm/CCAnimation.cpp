
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCAnimation.hpp>
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

cocos2d::CCAnimation::CCAnimation() : cocos2d::CCAnimation(geode::CutoffConstructor, sizeof(cocos2d::CCAnimation)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCAnimation::~CCAnimation();

	using FunctionType = void(*)(cocos2d::CCAnimation*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x236f04, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCAnimation::~CCAnimation() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCAnimation*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x236f38, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCAnimation(geode::CutoffConstructor, sizeof(cocos2d::CCAnimation));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCAnimation::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x236a50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCAnimation::create(cocos2d::CCArray* p0, float p1, unsigned int p2) -> decltype(create(p0, p1, p2)) {
	using FunctionType = decltype(create(p0, p1, p2))(*)(cocos2d::CCArray*, float, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x236d54, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::CCAnimation::createWithSpriteFrames(cocos2d::CCArray* p0, float p1) -> decltype(createWithSpriteFrames(p0, p1)) {
	using FunctionType = decltype(createWithSpriteFrames(p0, p1))(*)(cocos2d::CCArray*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x236b7c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCAnimation::copyWithZone(cocos2d::CCZone* p0) -> decltype(copyWithZone(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCAnimation::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(p0))(*)(cocos2d::CCAnimation*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x23718c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCAnimation::getDuration() -> decltype(getDuration()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCAnimation::getDuration), this);
	using FunctionType = decltype(getDuration())(*)(cocos2d::CCAnimation*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x237180, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCAnimation::addSpriteFrame(cocos2d::CCSpriteFrame* p0) -> decltype(addSpriteFrame(p0)) {
	using FunctionType = decltype(addSpriteFrame(p0))(*)(cocos2d::CCAnimation*, cocos2d::CCSpriteFrame*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x236ff0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCAnimation::addSpriteFrameWithFileName(char const* p0) -> decltype(addSpriteFrameWithFileName(p0)) {
	using FunctionType = decltype(addSpriteFrameWithFileName(p0))(*)(cocos2d::CCAnimation*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2370c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCAnimation::addSpriteFrameWithTexture(cocos2d::CCTexture2D* p0, cocos2d::CCRect const& p1) -> decltype(addSpriteFrameWithTexture(p0, p1)) {
	using FunctionType = decltype(addSpriteFrameWithTexture(p0, p1))(*)(cocos2d::CCAnimation*, cocos2d::CCTexture2D*, cocos2d::CCRect const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x237150, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCAnimation::init() -> decltype(init()) {
	using FunctionType = decltype(init())(*)(cocos2d::CCAnimation*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x236b20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCAnimation::initWithAnimationFrames(cocos2d::CCArray* p0, float p1, unsigned int p2) -> decltype(initWithAnimationFrames(p0, p1, p2)) {
	using FunctionType = decltype(initWithAnimationFrames(p0, p1, p2))(*)(cocos2d::CCAnimation*, cocos2d::CCArray*, float, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x236e5c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCAnimation::initWithSpriteFrames(cocos2d::CCArray* p0, float p1) -> decltype(initWithSpriteFrames(p0, p1)) {
	using FunctionType = decltype(initWithSpriteFrames(p0, p1))(*)(cocos2d::CCAnimation*, cocos2d::CCArray*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x236c04, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}
