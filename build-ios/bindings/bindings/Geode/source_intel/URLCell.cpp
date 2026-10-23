
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/URLCell.hpp>
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

URLCell::URLCell(char const* identifier, float width, float height) : URLCell(geode::CutoffConstructor, sizeof(URLCell)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	URLCell::~URLCell();

	using FunctionType = void(*)(URLCell*, char const*, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x259680, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this, identifier, width, height);
}

auto URLCell::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&URLCell::init), this);
	using FunctionType = decltype(init())(*)(URLCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2596f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto URLCell::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&URLCell::draw), this);
	using FunctionType = decltype(draw())(*)(URLCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x259760, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto URLCell::loadFromObject(CCURLObject* object) -> decltype(loadFromObject(object)) {
	using FunctionType = decltype(loadFromObject(object))(*)(URLCell*, CCURLObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x247590, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto URLCell::onURL(cocos2d::CCObject* sender) -> decltype(onURL(sender)) {
	using FunctionType = decltype(onURL(sender))(*)(URLCell*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x259710, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto URLCell::updateBGColor(int index) -> decltype(updateBGColor(index)) {
	using FunctionType = decltype(updateBGColor(index))(*)(URLCell*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x247760, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}
