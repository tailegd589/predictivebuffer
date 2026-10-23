
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/SmartTemplateCell.hpp>
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

SmartTemplateCell::SmartTemplateCell(char const* identifier, float width, float height) : SmartTemplateCell(geode::CutoffConstructor, sizeof(SmartTemplateCell)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	SmartTemplateCell::~SmartTemplateCell();

	using FunctionType = void(*)(SmartTemplateCell*, char const*, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1fe30c, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this, identifier, width, height);
}

auto SmartTemplateCell::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SmartTemplateCell::init), this);
	using FunctionType = decltype(init())(*)(SmartTemplateCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1fe350, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SmartTemplateCell::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SmartTemplateCell::draw), this);
	using FunctionType = decltype(draw())(*)(SmartTemplateCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1fe40c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SmartTemplateCell::loadFromObject(GJSmartTemplate* smartTemplate) -> decltype(loadFromObject(smartTemplate)) {
	using FunctionType = decltype(loadFromObject(smartTemplate))(*)(SmartTemplateCell*, GJSmartTemplate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1f3ff0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, smartTemplate);
}

auto SmartTemplateCell::onClick(cocos2d::CCObject* sender) -> decltype(onClick(sender)) {
	using FunctionType = decltype(onClick(sender))(*)(SmartTemplateCell*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1fe35c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SmartTemplateCell::updateBGColor(int index) -> decltype(updateBGColor(index)) {
	using FunctionType = decltype(updateBGColor(index))(*)(SmartTemplateCell*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1f4304, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}
