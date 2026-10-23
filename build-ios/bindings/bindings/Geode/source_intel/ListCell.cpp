
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/ListCell.hpp>
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

ListCell::ListCell(char const* identifier, float width, float height) : ListCell(geode::CutoffConstructor, sizeof(ListCell)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	ListCell::~ListCell();

	using FunctionType = void(*)(ListCell*, char const*, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30d2d0, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this, identifier, width, height);
}

auto ListCell::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&ListCell::init), this);
	using FunctionType = decltype(init())(*)(ListCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30d2c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto ListCell::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&ListCell::draw), this);
	using FunctionType = decltype(draw())(*)(ListCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30d350, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto ListCell::loadFromObject(cocos2d::CCObject* object, int id, int page, int index) -> decltype(loadFromObject(object, id, page, index)) {
	using FunctionType = decltype(loadFromObject(object, id, page, index))(*)(ListCell*, cocos2d::CCObject*, int, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30d280, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, id, page, index);
}

auto ListCell::updateBGColor(int index) -> decltype(updateBGColor(index)) {
	using FunctionType = decltype(updateBGColor(index))(*)(ListCell*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30d340, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}
