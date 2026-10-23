
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCHttpClient.hpp>
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

cocos2d::extension::CCHttpClient::CCHttpClient() : cocos2d::extension::CCHttpClient(geode::CutoffConstructor, sizeof(cocos2d::extension::CCHttpClient)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::extension::CCHttpClient::~CCHttpClient();

	using FunctionType = void(*)(cocos2d::extension::CCHttpClient*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x438580, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::extension::CCHttpClient::~CCHttpClient() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::extension::CCHttpClient*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x438750, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::extension::CCHttpClient(geode::CutoffConstructor, sizeof(cocos2d::extension::CCHttpClient));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::extension::CCHttpClient::destroyInstance() -> decltype(destroyInstance()) {
	using FunctionType = decltype(destroyInstance())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4388d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::extension::CCHttpClient::getInstance() -> decltype(getInstance()) {
	using FunctionType = decltype(getInstance())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x438880, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::extension::CCHttpClient::availableThreadCount() -> decltype(availableThreadCount()) {
	using FunctionType = decltype(availableThreadCount())(*)(cocos2d::extension::CCHttpClient*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4389c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::extension::CCHttpClient::dispatchResponseCallbacks(float p0) -> decltype(dispatchResponseCallbacks(p0)) {
	using FunctionType = decltype(dispatchResponseCallbacks(p0))(*)(cocos2d::extension::CCHttpClient*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x438650, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCHttpClient::send(cocos2d::extension::CCHttpRequest* request) -> decltype(send(request)) {
	using FunctionType = decltype(send(request))(*)(cocos2d::extension::CCHttpClient*, cocos2d::extension::CCHttpRequest*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x438900, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, request);
}
