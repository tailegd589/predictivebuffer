
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/SecretGame01Layer.hpp>
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

auto SecretGame01Layer::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e536c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto SecretGame01Layer::update(float dt) -> decltype(update(dt)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&SecretGame01Layer::update), this);
	using FunctionType = decltype(update(dt))(*)(SecretGame01Layer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e6b54, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, dt);
}

auto SecretGame01Layer::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SecretGame01Layer::init), this);
	using FunctionType = decltype(init())(*)(SecretGame01Layer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e5da0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SecretGame01Layer::didSelectCorrectObject(CCMenuItemSpriteExtra* button) -> decltype(didSelectCorrectObject(button)) {
	using FunctionType = decltype(didSelectCorrectObject(button))(*)(SecretGame01Layer*, CCMenuItemSpriteExtra*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e697c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, button);
}

auto SecretGame01Layer::gameStep01() -> decltype(gameStep01()) {
	using FunctionType = decltype(gameStep01())(*)(SecretGame01Layer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e618c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretGame01Layer::gameStep02() -> decltype(gameStep02()) {
	using FunctionType = decltype(gameStep02())(*)(SecretGame01Layer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e63fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretGame01Layer::getCountForDifficulty(int difficulty) -> decltype(getCountForDifficulty(difficulty)) {
	using FunctionType = decltype(getCountForDifficulty(difficulty))(*)(SecretGame01Layer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e5f84, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, difficulty);
}

auto SecretGame01Layer::getFrameForDifficulty(int difficulty) -> decltype(getFrameForDifficulty(difficulty)) {
	using FunctionType = decltype(getFrameForDifficulty(difficulty))(*)(SecretGame01Layer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e5fac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, difficulty);
}

auto SecretGame01Layer::getRowsForDifficulty(int difficulty) -> decltype(getRowsForDifficulty(difficulty)) {
	using FunctionType = decltype(getRowsForDifficulty(difficulty))(*)(SecretGame01Layer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e5f60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, difficulty);
}

auto SecretGame01Layer::getTimeForDifficulty(int difficulty) -> decltype(getTimeForDifficulty(difficulty)) {
	using FunctionType = decltype(getTimeForDifficulty(difficulty))(*)(SecretGame01Layer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e6080, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, difficulty);
}

auto SecretGame01Layer::onSelectButton(cocos2d::CCObject* sender) -> decltype(onSelectButton(sender)) {
	using FunctionType = decltype(onSelectButton(sender))(*)(SecretGame01Layer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e60a4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SecretGame01Layer::resetGame() -> decltype(resetGame()) {
	using FunctionType = decltype(resetGame())(*)(SecretGame01Layer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e548c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretGame01Layer::resetGameTimer() -> decltype(resetGameTimer()) {
	using FunctionType = decltype(resetGameTimer())(*)(SecretGame01Layer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e6544, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretGame01Layer::scaleOutGame(bool won) -> decltype(scaleOutGame(won)) {
	using FunctionType = decltype(scaleOutGame(won))(*)(SecretGame01Layer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e65bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, won);
}

auto SecretGame01Layer::showGameOver() -> decltype(showGameOver()) {
	using FunctionType = decltype(showGameOver())(*)(SecretGame01Layer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e65b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretGame01Layer::showGameWon() -> decltype(showGameWon()) {
	using FunctionType = decltype(showGameWon())(*)(SecretGame01Layer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e6968, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
