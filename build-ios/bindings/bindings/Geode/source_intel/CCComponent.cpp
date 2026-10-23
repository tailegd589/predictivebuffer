
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCComponent.hpp>
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

cocos2d::CCComponent::CCComponent() : cocos2d::CCComponent(geode::CutoffConstructor, sizeof(cocos2d::CCComponent)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCComponent::~CCComponent();

	using FunctionType = void(*)(cocos2d::CCComponent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x9bc40, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCComponent::~CCComponent() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCComponent*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x9bca0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCComponent(geode::CutoffConstructor, sizeof(cocos2d::CCComponent));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCComponent::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x9bdb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCComponent::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCComponent::init), this);
	using FunctionType = decltype(init())(*)(cocos2d::CCComponent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x9bd60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCComponent::onEnter() -> decltype(onEnter()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCComponent::onEnter), this);
	using FunctionType = decltype(onEnter())(*)(cocos2d::CCComponent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x9bd70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCComponent::onExit() -> decltype(onExit()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCComponent::onExit), this);
	using FunctionType = decltype(onExit())(*)(cocos2d::CCComponent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x9bd80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCComponent::update(float p0) -> decltype(update(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCComponent::update), this);
	using FunctionType = decltype(update(p0))(*)(cocos2d::CCComponent*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x9bd90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCComponent::serialize(void* p0) -> decltype(serialize(p0)) {
	auto self = addresser::thunkAdjust(Resolve<void*>::func(&cocos2d::CCComponent::serialize), this);
	using FunctionType = decltype(serialize(p0))(*)(cocos2d::CCComponent*, void*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x9bda0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCComponent::isEnabled() const  -> decltype(isEnabled()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCComponent::isEnabled), this);
	using FunctionType = decltype(isEnabled())(*)(cocos2d::CCComponent const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x9be60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCComponent::setEnabled(bool p0) -> decltype(setEnabled(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCComponent::setEnabled), this);
	using FunctionType = decltype(setEnabled(p0))(*)(cocos2d::CCComponent*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x9be70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCComponent::getName() const  -> decltype(getName()) {
	using FunctionType = decltype(getName())(*)(cocos2d::CCComponent const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x9be10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCComponent::getOwner() const  -> decltype(getOwner()) {
	using FunctionType = decltype(getOwner())(*)(cocos2d::CCComponent const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x9be40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCComponent::setName(char const* p0) -> decltype(setName(p0)) {
	using FunctionType = decltype(setName(p0))(*)(cocos2d::CCComponent*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x9be30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCComponent::setOwner(cocos2d::CCNode* p0) -> decltype(setOwner(p0)) {
	using FunctionType = decltype(setOwner(p0))(*)(cocos2d::CCComponent*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x9be50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
