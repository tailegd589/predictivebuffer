
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCComponentContainer.hpp>
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

cocos2d::CCComponentContainer::CCComponentContainer(cocos2d::CCNode* p0) {
	using FunctionType = void(*)(cocos2d::CCComponentContainer*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2c4f90, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this, p0);
}

cocos2d::CCComponentContainer::~CCComponentContainer() {
	// basically we destruct it once by calling the gd function,
	// then we release the lock because there are no other destructors after this
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCComponentContainer*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x2c4fb0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);
	}
	else {
		geode::DestructorLock::removeLock(this);
	}
}

auto cocos2d::CCComponentContainer::get(char const* p0) const  -> decltype(get(p0)) {
	auto self = addresser::thunkAdjust(Resolve<char const*>::func(&cocos2d::CCComponentContainer::get), this);
	using FunctionType = decltype(get(p0))(*)(cocos2d::CCComponentContainer const *, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2c5050, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCComponentContainer::add(cocos2d::CCComponent* p0) -> decltype(add(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCComponent*>::func(&cocos2d::CCComponentContainer::add), this);
	using FunctionType = decltype(add(p0))(*)(cocos2d::CCComponentContainer*, cocos2d::CCComponent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2c5170, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCComponentContainer::remove(char const* p0) -> decltype(remove(p0)) {
	auto self = addresser::thunkAdjust(Resolve<char const*>::func(&cocos2d::CCComponentContainer::remove), this);
	using FunctionType = decltype(remove(p0))(*)(cocos2d::CCComponentContainer*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2c5390, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCComponentContainer::remove(cocos2d::CCComponent* p0) -> decltype(remove(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCComponent*>::func(&cocos2d::CCComponentContainer::remove), this);
	using FunctionType = decltype(remove(p0))(*)(cocos2d::CCComponentContainer*, cocos2d::CCComponent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2c5660, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCComponentContainer::removeAll() -> decltype(removeAll()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCComponentContainer::removeAll), this);
	using FunctionType = decltype(removeAll())(*)(cocos2d::CCComponentContainer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2c5800, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCComponentContainer::visit(float p0) -> decltype(visit(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCComponentContainer::visit), this);
	using FunctionType = decltype(visit(p0))(*)(cocos2d::CCComponentContainer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2c59f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCComponentContainer::alloc() -> decltype(alloc()) {
	using FunctionType = decltype(alloc())(*)(cocos2d::CCComponentContainer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2c59d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCComponentContainer::isEmpty() const  -> decltype(isEmpty()) {
	using FunctionType = decltype(isEmpty())(*)(cocos2d::CCComponentContainer const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2c5a40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
