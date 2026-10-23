
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCLayerColor.hpp>
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

cocos2d::CCLayerColor::CCLayerColor() : cocos2d::CCLayerColor(geode::CutoffConstructor, sizeof(cocos2d::CCLayerColor)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCLayerColor::~CCLayerColor();

	using FunctionType = void(*)(cocos2d::CCLayerColor*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b22d0, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCLayerColor::~CCLayerColor() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCLayerColor*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x4b25b0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCLayerColor(geode::CutoffConstructor, sizeof(cocos2d::CCLayerColor));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCLayerColor::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b2930, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCLayerColor::create(cocos2d::ccColor4B const& p0) -> decltype(create(p0)) {
	using FunctionType = decltype(create(p0))(*)(cocos2d::ccColor4B const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b2ce0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCLayerColor::create(cocos2d::ccColor4B const& p0, float p1, float p2) -> decltype(create(p0, p1, p2)) {
	using FunctionType = decltype(create(p0, p1, p2))(*)(cocos2d::ccColor4B const&, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b2b10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::CCLayerColor::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLayerColor::init), this);
	using FunctionType = decltype(init())(*)(cocos2d::CCLayerColor*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b2eb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLayerColor::setContentSize(cocos2d::CCSize const& p0) -> decltype(setContentSize(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCSize const&>::func(&cocos2d::CCLayerColor::setContentSize), this);
	using FunctionType = decltype(setContentSize(p0))(*)(cocos2d::CCLayerColor*, cocos2d::CCSize const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b30a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLayerColor::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLayerColor::draw), this);
	using FunctionType = decltype(draw())(*)(cocos2d::CCLayerColor*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b31e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLayerColor::initWithColor(cocos2d::ccColor4B const& p0, float p1, float p2) -> decltype(initWithColor(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccColor4B const&, float, float>::func(&cocos2d::CCLayerColor::initWithColor), this);
	using FunctionType = decltype(initWithColor(p0, p1, p2))(*)(cocos2d::CCLayerColor*, cocos2d::ccColor4B const&, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b2f00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}

auto cocos2d::CCLayerColor::initWithColor(cocos2d::ccColor4B const& p0) -> decltype(initWithColor(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccColor4B const&>::func(&cocos2d::CCLayerColor::initWithColor), this);
	using FunctionType = decltype(initWithColor(p0))(*)(cocos2d::CCLayerColor*, cocos2d::ccColor4B const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b2ff0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLayerColor::updateColor() -> decltype(updateColor()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLayerColor::updateColor), this);
	using FunctionType = decltype(updateColor())(*)(cocos2d::CCLayerColor*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b3190, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLayerColor::setColor(cocos2d::ccColor3B const& p0) -> decltype(setColor(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccColor3B const&>::func(&cocos2d::CCLayerColor::setColor), this);
	using FunctionType = decltype(setColor(p0))(*)(cocos2d::CCLayerColor*, cocos2d::ccColor3B const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b32b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLayerColor::setOpacity(unsigned char p0) -> decltype(setOpacity(p0)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned char>::func(&cocos2d::CCLayerColor::setOpacity), this);
	using FunctionType = decltype(setOpacity(p0))(*)(cocos2d::CCLayerColor*, unsigned char);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b3430, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLayerColor::setBlendFunc(cocos2d::ccBlendFunc p0) -> decltype(setBlendFunc(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccBlendFunc>::func(&cocos2d::CCLayerColor::setBlendFunc), this);
	using FunctionType = decltype(setBlendFunc(p0))(*)(cocos2d::CCLayerColor*, cocos2d::ccBlendFunc);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b2910, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLayerColor::getBlendFunc() -> decltype(getBlendFunc()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLayerColor::getBlendFunc), this);
	using FunctionType = decltype(getBlendFunc())(*)(cocos2d::CCLayerColor*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b28f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLayerColor::addToVertices(cocos2d::CCPoint p0, cocos2d::CCPoint p1, cocos2d::CCPoint p2) -> decltype(addToVertices(p0, p1, p2)) {
	using FunctionType = decltype(addToVertices(p0, p1, p2))(*)(cocos2d::CCLayerColor*, cocos2d::CCPoint, cocos2d::CCPoint, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b3060, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCLayerColor::changeHeight(float p0) -> decltype(changeHeight(p0)) {
	using FunctionType = decltype(changeHeight(p0))(*)(cocos2d::CCLayerColor*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b3150, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCLayerColor::changeWidth(float p0) -> decltype(changeWidth(p0)) {
	using FunctionType = decltype(changeWidth(p0))(*)(cocos2d::CCLayerColor*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b3110, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCLayerColor::changeWidthAndHeight(float p0, float p1) -> decltype(changeWidthAndHeight(p0, p1)) {
	using FunctionType = decltype(changeWidthAndHeight(p0, p1))(*)(cocos2d::CCLayerColor*, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b30d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCLayerColor::setVertices(cocos2d::CCPoint p0, cocos2d::CCPoint p1, cocos2d::CCPoint p2) -> decltype(setVertices(p0, p1, p2)) {
	using FunctionType = decltype(setVertices(p0, p1, p2))(*)(cocos2d::CCLayerColor*, cocos2d::CCPoint, cocos2d::CCPoint, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b3040, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}
