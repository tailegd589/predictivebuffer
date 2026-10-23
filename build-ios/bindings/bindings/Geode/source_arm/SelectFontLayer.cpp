
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/SelectFontLayer.hpp>
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

SelectFontLayer::~SelectFontLayer() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(SelectFontLayer*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x239adc, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) SelectFontLayer(geode::CutoffConstructor, sizeof(SelectFontLayer));
		geode::DestructorLock::addLock(this);
	}
}

auto SelectFontLayer::create(LevelEditorLayer* editorLayer) -> decltype(create(editorLayer)) {
	using FunctionType = decltype(create(editorLayer))(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x239cf4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(editorLayer);
}

auto SelectFontLayer::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SelectFontLayer::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(SelectFontLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x23a5a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SelectFontLayer::init(LevelEditorLayer* layer) -> decltype(init(layer)) {
	using FunctionType = decltype(init(layer))(*)(SelectFontLayer*, LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x239df8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, layer);
}

auto SelectFontLayer::onChangeFont(cocos2d::CCObject* sender) -> decltype(onChangeFont(sender)) {
	using FunctionType = decltype(onChangeFont(sender))(*)(SelectFontLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x23a414, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SelectFontLayer::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	using FunctionType = decltype(onClose(sender))(*)(SelectFontLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x23a3d8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SelectFontLayer::updateFontLabel() -> decltype(updateFontLabel()) {
	using FunctionType = decltype(updateFontLabel())(*)(SelectFontLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x23a4a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
