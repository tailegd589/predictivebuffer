
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
		static auto func = wrapFunction<FunctionType>(base::get() + 0x223818, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) UploadPopup(geode::CutoffConstructor, sizeof(UploadPopup));
		geode::DestructorLock::addLock(this);
	}
}

auto UploadPopup::create(GJGameLevel* level) -> decltype(create(level)) {
	using FunctionType = decltype(create(level))(*)(GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x223694, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(level);
}

auto UploadPopup::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&UploadPopup::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(UploadPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2242b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto UploadPopup::show() -> decltype(show()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&UploadPopup::show), this);
	using FunctionType = decltype(show())(*)(UploadPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x224250, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto UploadPopup::levelUploadFinished(GJGameLevel* level) -> decltype(levelUploadFinished(level)) {
	auto self = addresser::thunkAdjust(Resolve<GJGameLevel*>::func(&UploadPopup::levelUploadFinished), this);
	using FunctionType = decltype(levelUploadFinished(level))(*)(UploadPopup*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x223e20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, level);
}

auto UploadPopup::levelUploadFailed(GJGameLevel* level) -> decltype(levelUploadFailed(level)) {
	auto self = addresser::thunkAdjust(Resolve<GJGameLevel*>::func(&UploadPopup::levelUploadFailed), this);
	using FunctionType = decltype(levelUploadFailed(level))(*)(UploadPopup*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x224058, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, level);
}

auto UploadPopup::init(GJGameLevel* level) -> decltype(init(level)) {
	using FunctionType = decltype(init(level))(*)(UploadPopup*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2238fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}

auto UploadPopup::onBack(cocos2d::CCObject* sender) -> decltype(onBack(sender)) {
	using FunctionType = decltype(onBack(sender))(*)(UploadPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x223dd4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto UploadPopup::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	using FunctionType = decltype(onClose(sender))(*)(UploadPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22420c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto UploadPopup::onReturnToLevel(cocos2d::CCObject* sender) -> decltype(onReturnToLevel(sender)) {
	using FunctionType = decltype(onReturnToLevel(sender))(*)(UploadPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x223fd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}
