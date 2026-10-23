
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/UploadPopup.hpp>
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

UploadPopup::~UploadPopup() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(UploadPopup*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x281940, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) UploadPopup(geode::CutoffConstructor, sizeof(UploadPopup));
		geode::DestructorLock::addLock(this);
	}
}

auto UploadPopup::create(GJGameLevel* level) -> decltype(create(level)) {
	using FunctionType = decltype(create(level))(*)(GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x281780, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(level);
}

auto UploadPopup::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&UploadPopup::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(UploadPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x282500, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto UploadPopup::show() -> decltype(show()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&UploadPopup::show), this);
	using FunctionType = decltype(show())(*)(UploadPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x282490, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto UploadPopup::levelUploadFinished(GJGameLevel* level) -> decltype(levelUploadFinished(level)) {
	auto self = addresser::thunkAdjust(Resolve<GJGameLevel*>::func(&UploadPopup::levelUploadFinished), this);
	using FunctionType = decltype(levelUploadFinished(level))(*)(UploadPopup*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x282030, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, level);
}

auto UploadPopup::levelUploadFailed(GJGameLevel* level) -> decltype(levelUploadFailed(level)) {
	auto self = addresser::thunkAdjust(Resolve<GJGameLevel*>::func(&UploadPopup::levelUploadFailed), this);
	using FunctionType = decltype(levelUploadFailed(level))(*)(UploadPopup*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x282280, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, level);
}

auto UploadPopup::init(GJGameLevel* level) -> decltype(init(level)) {
	using FunctionType = decltype(init(level))(*)(UploadPopup*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x281aa0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}

auto UploadPopup::onBack(cocos2d::CCObject* sender) -> decltype(onBack(sender)) {
	using FunctionType = decltype(onBack(sender))(*)(UploadPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x281fe0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto UploadPopup::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	using FunctionType = decltype(onClose(sender))(*)(UploadPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x282440, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto UploadPopup::onReturnToLevel(cocos2d::CCObject* sender) -> decltype(onReturnToLevel(sender)) {
	using FunctionType = decltype(onReturnToLevel(sender))(*)(UploadPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2821e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}
