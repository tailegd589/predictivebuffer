
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/UploadListPopup.hpp>
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

UploadListPopup::~UploadListPopup() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(UploadListPopup*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x2ee4c0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) UploadListPopup(geode::CutoffConstructor, sizeof(UploadListPopup));
		geode::DestructorLock::addLock(this);
	}
}

auto UploadListPopup::create(GJLevelList* list) -> decltype(create(list)) {
	using FunctionType = decltype(create(list))(*)(GJLevelList*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2ee33c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(list);
}

auto UploadListPopup::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&UploadListPopup::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(UploadListPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2ef160, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto UploadListPopup::show() -> decltype(show()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&UploadListPopup::show), this);
	using FunctionType = decltype(show())(*)(UploadListPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2ef100, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto UploadListPopup::listUploadFinished(GJLevelList* list) -> decltype(listUploadFinished(list)) {
	auto self = addresser::thunkAdjust(Resolve<GJLevelList*>::func(&UploadListPopup::listUploadFinished), this);
	using FunctionType = decltype(listUploadFinished(list))(*)(UploadListPopup*, GJLevelList*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2eec04, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, list);
}

auto UploadListPopup::listUploadFailed(GJLevelList* list, int response) -> decltype(listUploadFailed(list, response)) {
	auto self = addresser::thunkAdjust(Resolve<GJLevelList*, int>::func(&UploadListPopup::listUploadFailed), this);
	using FunctionType = decltype(listUploadFailed(list, response))(*)(UploadListPopup*, GJLevelList*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2eee08, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, list, response);
}

auto UploadListPopup::init(GJLevelList* list) -> decltype(init(list)) {
	using FunctionType = decltype(init(list))(*)(UploadListPopup*, GJLevelList*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2ee754, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, list);
}

auto UploadListPopup::onBack(cocos2d::CCObject* sender) -> decltype(onBack(sender)) {
	using FunctionType = decltype(onBack(sender))(*)(UploadListPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2eebb8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto UploadListPopup::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	using FunctionType = decltype(onClose(sender))(*)(UploadListPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2ef0bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto UploadListPopup::onReturnToList(cocos2d::CCObject* sender) -> decltype(onReturnToList(sender)) {
	using FunctionType = decltype(onReturnToList(sender))(*)(UploadListPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2eedb4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}
