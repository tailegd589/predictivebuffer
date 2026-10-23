
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/SelectListIconLayer.hpp>
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

SelectListIconLayer::~SelectListIconLayer() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(SelectListIconLayer*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x2ec2c8, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) SelectListIconLayer(geode::CutoffConstructor, sizeof(SelectListIconLayer));
		geode::DestructorLock::addLock(this);
	}
}

auto SelectListIconLayer::create(int difficulty) -> decltype(create(difficulty)) {
	using FunctionType = decltype(create(difficulty))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2eb698, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(difficulty);
}

auto SelectListIconLayer::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SelectListIconLayer::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(SelectListIconLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2ecb84, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SelectListIconLayer::init(int difficulty) -> decltype(init(difficulty)) {
	using FunctionType = decltype(init(difficulty))(*)(SelectListIconLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2ec4ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, difficulty);
}

auto SelectListIconLayer::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	using FunctionType = decltype(onClose(sender))(*)(SelectListIconLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2ecb2c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SelectListIconLayer::onSelect(cocos2d::CCObject* sender) -> decltype(onSelect(sender)) {
	using FunctionType = decltype(onSelect(sender))(*)(SelectListIconLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2eca34, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}
