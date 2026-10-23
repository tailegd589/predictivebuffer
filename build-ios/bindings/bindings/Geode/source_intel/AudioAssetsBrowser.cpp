
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/AudioAssetsBrowser.hpp>
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

AudioAssetsBrowser::~AudioAssetsBrowser() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(AudioAssetsBrowser*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x7b3be0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) AudioAssetsBrowser(geode::CutoffConstructor, sizeof(AudioAssetsBrowser));
		geode::DestructorLock::addLock(this);
	}
}

auto AudioAssetsBrowser::create(gd::vector<int>& songIds, gd::vector<int>& sfxIds) -> decltype(create(songIds, sfxIds)) {
	using FunctionType = decltype(create(songIds, sfxIds))(*)(gd::vector<int>&, gd::vector<int>&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7b3d60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(songIds, sfxIds);
}

auto AudioAssetsBrowser::registerWithTouchDispatcher() -> decltype(registerWithTouchDispatcher()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&AudioAssetsBrowser::registerWithTouchDispatcher), this);
	using FunctionType = decltype(registerWithTouchDispatcher())(*)(AudioAssetsBrowser*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7b4f50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto AudioAssetsBrowser::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&AudioAssetsBrowser::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(AudioAssetsBrowser*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7b4ee0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto AudioAssetsBrowser::musicActionFinished(GJMusicAction action) -> decltype(musicActionFinished(action)) {
	auto self = addresser::thunkAdjust(Resolve<GJMusicAction>::func(&AudioAssetsBrowser::musicActionFinished), this);
	using FunctionType = decltype(musicActionFinished(action))(*)(AudioAssetsBrowser*, GJMusicAction);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7b4e00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, action);
}

auto AudioAssetsBrowser::musicActionFailed(GJMusicAction action) -> decltype(musicActionFailed(action)) {
	auto self = addresser::thunkAdjust(Resolve<GJMusicAction>::func(&AudioAssetsBrowser::musicActionFailed), this);
	using FunctionType = decltype(musicActionFailed(action))(*)(AudioAssetsBrowser*, GJMusicAction);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7b4e30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, action);
}

auto AudioAssetsBrowser::cellPerformedAction(TableViewCell* cell, int listType, CellAction action, cocos2d::CCNode* parent) -> decltype(cellPerformedAction(cell, listType, action, parent)) {
	auto self = addresser::thunkAdjust(Resolve<TableViewCell*, int, CellAction, cocos2d::CCNode*>::func(&AudioAssetsBrowser::cellPerformedAction), this);
	using FunctionType = decltype(cellPerformedAction(cell, listType, action, parent))(*)(AudioAssetsBrowser*, TableViewCell*, int, CellAction, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7b4e70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, cell, listType, action, parent);
}

auto AudioAssetsBrowser::getSelectedCellIdx() -> decltype(getSelectedCellIdx()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&AudioAssetsBrowser::getSelectedCellIdx), this);
	using FunctionType = decltype(getSelectedCellIdx())(*)(AudioAssetsBrowser*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7b4e90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto AudioAssetsBrowser::getCellDelegateType() -> decltype(getCellDelegateType()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&AudioAssetsBrowser::getCellDelegateType), this);
	using FunctionType = decltype(getCellDelegateType())(*)(AudioAssetsBrowser*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7b4eb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto AudioAssetsBrowser::init(gd::vector<int>& songIds, gd::vector<int>& sfxIds) -> decltype(init(songIds, sfxIds)) {
	using FunctionType = decltype(init(songIds, sfxIds))(*)(AudioAssetsBrowser*, gd::vector<int>&, gd::vector<int>&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7b3ee0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, songIds, sfxIds);
}

auto AudioAssetsBrowser::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	using FunctionType = decltype(onClose(sender))(*)(AudioAssetsBrowser*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7b4450, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto AudioAssetsBrowser::onInfo(cocos2d::CCObject* sender) -> decltype(onInfo(sender)) {
	using FunctionType = decltype(onInfo(sender))(*)(AudioAssetsBrowser*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7b4480, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto AudioAssetsBrowser::onPage(cocos2d::CCObject* sender) -> decltype(onPage(sender)) {
	using FunctionType = decltype(onPage(sender))(*)(AudioAssetsBrowser*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7b4e60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto AudioAssetsBrowser::setupList() -> decltype(setupList()) {
	using FunctionType = decltype(setupList())(*)(AudioAssetsBrowser*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7b4ba0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto AudioAssetsBrowser::trySetupAudioBrowser() -> decltype(trySetupAudioBrowser()) {
	using FunctionType = decltype(trySetupAudioBrowser())(*)(AudioAssetsBrowser*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7b4d60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto AudioAssetsBrowser::updatePageLabel() -> decltype(updatePageLabel()) {
	using FunctionType = decltype(updatePageLabel())(*)(AudioAssetsBrowser*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7b4ed0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
