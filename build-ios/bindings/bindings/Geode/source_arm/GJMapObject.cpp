
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJMapObject.hpp>
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

auto GJMapObject::create(cocos2d::CCNode* parent) -> decltype(create(parent)) {
	using FunctionType = decltype(create(parent))(*)(cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x20a554, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(parent);
}

auto GJMapObject::createMonster(int objectID) -> decltype(createMonster(objectID)) {
	using FunctionType = decltype(createMonster(objectID))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x20a720, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(objectID);
}

auto GJMapObject::init(cocos2d::CCNode* parent) -> decltype(init(parent)) {
	using FunctionType = decltype(init(parent))(*)(GJMapObject*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x20a620, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, parent);
}

auto GJMapObject::monsterIdle() -> decltype(monsterIdle()) {
	using FunctionType = decltype(monsterIdle())(*)(GJMapObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x20b260, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJMapObject::monsterJump() -> decltype(monsterJump()) {
	using FunctionType = decltype(monsterJump())(*)(GJMapObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x20b060, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJMapObject::moveFinished() -> decltype(moveFinished()) {
	using FunctionType = decltype(moveFinished())(*)(GJMapObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x20afe0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJMapObject::moveMonster() -> decltype(moveMonster()) {
	using FunctionType = decltype(moveMonster())(*)(GJMapObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x20ae54, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJMapObject::moveMonster(cocos2d::CCPoint position, float offset) -> decltype(moveMonster(position, offset)) {
	using FunctionType = decltype(moveMonster(position, offset))(*)(GJMapObject*, cocos2d::CCPoint, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x20ae94, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, position, offset);
}

auto GJMapObject::playerJump() -> decltype(playerJump()) {
	using FunctionType = decltype(playerJump())(*)(GJMapObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x20abd8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJMapObject::setObjectOrigin(cocos2d::CCPoint position, float offset) -> decltype(setObjectOrigin(position, offset)) {
	using FunctionType = decltype(setObjectOrigin(position, offset))(*)(GJMapObject*, cocos2d::CCPoint, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x20ae18, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, position, offset);
}

auto GJMapObject::startMonsterJumpLoop() -> decltype(startMonsterJumpLoop()) {
	using FunctionType = decltype(startMonsterJumpLoop())(*)(GJMapObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x20aa1c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJMapObject::startPlayerJumpLoop() -> decltype(startPlayerJumpLoop()) {
	using FunctionType = decltype(startPlayerJumpLoop())(*)(GJMapObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x20ab80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJMapObject::touchMonster() -> decltype(touchMonster()) {
	using FunctionType = decltype(touchMonster())(*)(GJMapObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x20b4c4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJMapObject::updateShadow(float scaleX, float scaleY, cocos2d::CCPoint position) -> decltype(updateShadow(scaleX, scaleY, position)) {
	using FunctionType = decltype(updateShadow(scaleX, scaleY, position))(*)(GJMapObject*, float, float, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x20a9bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, scaleX, scaleY, position);
}
