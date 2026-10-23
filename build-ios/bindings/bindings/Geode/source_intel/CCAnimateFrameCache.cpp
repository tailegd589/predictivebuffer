
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/CCAnimateFrameCache.hpp>
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

auto CCAnimateFrameCache::sharedSpriteFrameCache() -> decltype(sharedSpriteFrameCache()) {
	using FunctionType = decltype(sharedSpriteFrameCache())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x56add0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto CCAnimateFrameCache::addCustomSpriteFramesWithFile(char const* filename) -> decltype(addCustomSpriteFramesWithFile(filename)) {
	using FunctionType = decltype(addCustomSpriteFramesWithFile(filename))(*)(CCAnimateFrameCache*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x56b010, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, filename);
}

auto CCAnimateFrameCache::addDict(DS_Dictionary* dict, char const* filename) -> decltype(addDict(dict, filename)) {
	using FunctionType = decltype(addDict(dict, filename))(*)(CCAnimateFrameCache*, DS_Dictionary*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x56c330, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dict, filename);
}

auto CCAnimateFrameCache::addDict(cocos2d::CCDictionary* dict, char const* filename) -> decltype(addDict(dict, filename)) {
	using FunctionType = decltype(addDict(dict, filename))(*)(CCAnimateFrameCache*, cocos2d::CCDictionary*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x56bc80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dict, filename);
}

auto CCAnimateFrameCache::addSpriteFramesWithFile(char const* filename) -> decltype(addSpriteFramesWithFile(filename)) {
	using FunctionType = decltype(addSpriteFramesWithFile(filename))(*)(CCAnimateFrameCache*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x56c0d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, filename);
}

auto CCAnimateFrameCache::init() -> decltype(init()) {
	using FunctionType = decltype(init())(*)(CCAnimateFrameCache*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x56ae70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CCAnimateFrameCache::purgeSharedSpriteFrameCache() -> decltype(purgeSharedSpriteFrameCache()) {
	using FunctionType = decltype(purgeSharedSpriteFrameCache())(*)(CCAnimateFrameCache*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x56aec0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CCAnimateFrameCache::removeSpriteFrames() -> decltype(removeSpriteFrames()) {
	using FunctionType = decltype(removeSpriteFrames())(*)(CCAnimateFrameCache*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x56caa0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CCAnimateFrameCache::spriteFrameByName(char const* name) -> decltype(spriteFrameByName(name)) {
	using FunctionType = decltype(spriteFrameByName(name))(*)(CCAnimateFrameCache*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x56cad0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, name);
}
