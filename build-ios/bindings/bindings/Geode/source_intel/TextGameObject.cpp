
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/TextGameObject.hpp>
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

auto TextGameObject::create(cocos2d::CCTexture2D* texture) -> decltype(create(texture)) {
	using FunctionType = decltype(create(texture))(*)(cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5a1df0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(texture);
}

auto TextGameObject::customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists) -> decltype(customObjectSetup(values, exists)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&TextGameObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(values, exists))(*)(TextGameObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5d1a50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, values, exists);
}

auto TextGameObject::getSaveString(GJBaseGameLayer* layer) -> decltype(getSaveString(layer)) {
	auto self = addresser::thunkAdjust(Resolve<GJBaseGameLayer*>::func(&TextGameObject::getSaveString), this);
	using FunctionType = decltype(getSaveString(layer))(*)(TextGameObject*, GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5d1b80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer);
}

auto TextGameObject::updateTextKerning(int kerning) -> decltype(updateTextKerning(kerning)) {
	auto self = addresser::thunkAdjust(Resolve<int>::func(&TextGameObject::updateTextKerning), this);
	using FunctionType = decltype(updateTextKerning(kerning))(*)(TextGameObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5d17d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, kerning);
}

auto TextGameObject::getTextKerning() -> decltype(getTextKerning()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&TextGameObject::getTextKerning), this);
	using FunctionType = decltype(getTextKerning())(*)(TextGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5d2570, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto TextGameObject::init(cocos2d::CCTexture2D* texture) -> decltype(init(texture)) {
	using FunctionType = decltype(init(texture))(*)(TextGameObject*, cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5d17a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, texture);
}

auto TextGameObject::updateTextObject(gd::string text, bool defaultFont) -> decltype(updateTextObject(text, defaultFont)) {
	using FunctionType = decltype(updateTextObject(text, defaultFont))(*)(TextGameObject*, gd::string, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5d17e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, text, defaultFont);
}
