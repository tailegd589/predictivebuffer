
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/AccountRegisterLayer.hpp>
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

AccountRegisterLayer::~AccountRegisterLayer() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(AccountRegisterLayer*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x3f9a48, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) AccountRegisterLayer(geode::CutoffConstructor, sizeof(AccountRegisterLayer));
		geode::DestructorLock::addLock(this);
	}
}

auto AccountRegisterLayer::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f9d04, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto AccountRegisterLayer::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&AccountRegisterLayer::init), this);
	using FunctionType = decltype(init())(*)(AccountRegisterLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f9e24, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto AccountRegisterLayer::registerWithTouchDispatcher() -> decltype(registerWithTouchDispatcher()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&AccountRegisterLayer::registerWithTouchDispatcher), this);
	using FunctionType = decltype(registerWithTouchDispatcher())(*)(AccountRegisterLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3fc564, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto AccountRegisterLayer::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&AccountRegisterLayer::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(AccountRegisterLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3fc360, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto AccountRegisterLayer::FLAlert_Clicked(FLAlertLayer* layer, bool btn2) -> decltype(FLAlert_Clicked(layer, btn2)) {
	auto self = addresser::thunkAdjust(Resolve<FLAlertLayer*, bool>::func(&AccountRegisterLayer::FLAlert_Clicked), this);
	using FunctionType = decltype(FLAlert_Clicked(layer, btn2))(*)(AccountRegisterLayer*, FLAlertLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3fbf18, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer, btn2);
}

auto AccountRegisterLayer::textInputOpened(CCTextInputNode* node) -> decltype(textInputOpened(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&AccountRegisterLayer::textInputOpened), this);
	using FunctionType = decltype(textInputOpened(node))(*)(AccountRegisterLayer*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3fcd24, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto AccountRegisterLayer::textInputClosed(CCTextInputNode* node) -> decltype(textInputClosed(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&AccountRegisterLayer::textInputClosed), this);
	using FunctionType = decltype(textInputClosed(node))(*)(AccountRegisterLayer*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3fc59c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto AccountRegisterLayer::textChanged(CCTextInputNode* node) -> decltype(textChanged(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&AccountRegisterLayer::textChanged), this);
	using FunctionType = decltype(textChanged(node))(*)(AccountRegisterLayer*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3fcd2c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto AccountRegisterLayer::textInputShouldOffset(CCTextInputNode* node, float yOffset) -> decltype(textInputShouldOffset(node, yOffset)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*, float>::func(&AccountRegisterLayer::textInputShouldOffset), this);
	using FunctionType = decltype(textInputShouldOffset(node, yOffset))(*)(AccountRegisterLayer*, CCTextInputNode*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3fcd34, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node, yOffset);
}

auto AccountRegisterLayer::textInputReturn(CCTextInputNode* node) -> decltype(textInputReturn(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&AccountRegisterLayer::textInputReturn), this);
	using FunctionType = decltype(textInputReturn(node))(*)(AccountRegisterLayer*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3fce04, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto AccountRegisterLayer::allowTextInput(CCTextInputNode* node) -> decltype(allowTextInput(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&AccountRegisterLayer::allowTextInput), this);
	using FunctionType = decltype(allowTextInput(node))(*)(AccountRegisterLayer*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3fcebc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto AccountRegisterLayer::registerAccountFinished() -> decltype(registerAccountFinished()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&AccountRegisterLayer::registerAccountFinished), this);
	using FunctionType = decltype(registerAccountFinished())(*)(AccountRegisterLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3fb77c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto AccountRegisterLayer::registerAccountFailed(AccountError errorType) -> decltype(registerAccountFailed(errorType)) {
	auto self = addresser::thunkAdjust(Resolve<AccountError>::func(&AccountRegisterLayer::registerAccountFailed), this);
	using FunctionType = decltype(registerAccountFailed(errorType))(*)(AccountRegisterLayer*, AccountError);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3fb914, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, errorType);
}

auto AccountRegisterLayer::createTextBackground(cocos2d::CCPoint position, cocos2d::CCSize size) -> decltype(createTextBackground(position, size)) {
	using FunctionType = decltype(createTextBackground(position, size))(*)(AccountRegisterLayer*, cocos2d::CCPoint, cocos2d::CCSize);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3fb4c4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, position, size);
}

auto AccountRegisterLayer::createTextInput(cocos2d::CCPoint position, cocos2d::CCSize size, gd::string text, int tag) -> decltype(createTextInput(position, size, text, tag)) {
	using FunctionType = decltype(createTextInput(position, size, text, tag))(*)(AccountRegisterLayer*, cocos2d::CCPoint, cocos2d::CCSize, gd::string, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3fb67c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, position, size, text, tag);
}

auto AccountRegisterLayer::createTextLabel(cocos2d::CCPoint position, gd::string text, cocos2d::CCSize size) -> decltype(createTextLabel(position, text, size)) {
	using FunctionType = decltype(createTextLabel(position, text, size))(*)(AccountRegisterLayer*, cocos2d::CCPoint, gd::string, cocos2d::CCSize);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3fb588, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, position, text, size);
}

auto AccountRegisterLayer::disableNodes() -> decltype(disableNodes()) {
	using FunctionType = decltype(disableNodes())(*)(AccountRegisterLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3fc0ac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto AccountRegisterLayer::hideLoadingUI() -> decltype(hideLoadingUI()) {
	using FunctionType = decltype(hideLoadingUI())(*)(AccountRegisterLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3fbc28, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto AccountRegisterLayer::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	using FunctionType = decltype(onClose(sender))(*)(AccountRegisterLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3facc8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto AccountRegisterLayer::onSubmit(cocos2d::CCObject* sender) -> decltype(onSubmit(sender)) {
	using FunctionType = decltype(onSubmit(sender))(*)(AccountRegisterLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3fad6c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto AccountRegisterLayer::resetLabel(int tag) -> decltype(resetLabel(tag)) {
	using FunctionType = decltype(resetLabel(tag))(*)(AccountRegisterLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3fbe2c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, tag);
}

auto AccountRegisterLayer::resetLabels() -> decltype(resetLabels()) {
	using FunctionType = decltype(resetLabels())(*)(AccountRegisterLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3fbcfc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto AccountRegisterLayer::showLoadingUI() -> decltype(showLoadingUI()) {
	using FunctionType = decltype(showLoadingUI())(*)(AccountRegisterLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3fc230, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto AccountRegisterLayer::toggleUI(bool enable) -> decltype(toggleUI(enable)) {
	using FunctionType = decltype(toggleUI(enable))(*)(AccountRegisterLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3fc4ac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, enable);
}

auto AccountRegisterLayer::updateLabel(AccountError type) -> decltype(updateLabel(type)) {
	using FunctionType = decltype(updateLabel(type))(*)(AccountRegisterLayer*, AccountError);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3fbaf8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type);
}

auto AccountRegisterLayer::validEmail(gd::string email) -> decltype(validEmail(email)) {
	using FunctionType = decltype(validEmail(email))(*)(AccountRegisterLayer*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3fc170, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, email);
}

auto AccountRegisterLayer::validPassword(gd::string password) -> decltype(validPassword(password)) {
	using FunctionType = decltype(validPassword(password))(*)(AccountRegisterLayer*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3fc14c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, password);
}

auto AccountRegisterLayer::validUser(gd::string username) -> decltype(validUser(username)) {
	using FunctionType = decltype(validUser(username))(*)(AccountRegisterLayer*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3fc128, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, username);
}
