
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCPrettyPrinter.hpp>
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

cocos2d::CCPrettyPrinter::CCPrettyPrinter(int p0) : cocos2d::CCPrettyPrinter(geode::CutoffConstructor, sizeof(cocos2d::CCPrettyPrinter)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCPrettyPrinter::~CCPrettyPrinter();

	using FunctionType = void(*)(cocos2d::CCPrettyPrinter*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b5120, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCPrettyPrinter::clear() -> decltype(clear()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCPrettyPrinter::clear), this);
	using FunctionType = decltype(clear())(*)(cocos2d::CCPrettyPrinter*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b52d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCPrettyPrinter::getResult() -> decltype(getResult()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCPrettyPrinter::getResult), this);
	using FunctionType = decltype(getResult())(*)(cocos2d::CCPrettyPrinter*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b5300, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCPrettyPrinter::visitObject(cocos2d::CCObject const* p0) -> decltype(visitObject(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject const*>::func(&cocos2d::CCPrettyPrinter::visitObject), this);
	using FunctionType = decltype(visitObject(p0))(*)(cocos2d::CCPrettyPrinter*, cocos2d::CCObject const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b5340, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCPrettyPrinter::visit(cocos2d::CCBool const* p0) -> decltype(visit(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCBool const*>::func(&cocos2d::CCPrettyPrinter::visit), this);
	using FunctionType = decltype(visit(p0))(*)(cocos2d::CCPrettyPrinter*, cocos2d::CCBool const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b53c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCPrettyPrinter::visit(cocos2d::CCInteger const* p0) -> decltype(visit(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCInteger const*>::func(&cocos2d::CCPrettyPrinter::visit), this);
	using FunctionType = decltype(visit(p0))(*)(cocos2d::CCPrettyPrinter*, cocos2d::CCInteger const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b5450, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCPrettyPrinter::visit(cocos2d::CCFloat const* p0) -> decltype(visit(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCFloat const*>::func(&cocos2d::CCPrettyPrinter::visit), this);
	using FunctionType = decltype(visit(p0))(*)(cocos2d::CCPrettyPrinter*, cocos2d::CCFloat const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b54d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCPrettyPrinter::visit(cocos2d::CCDouble const* p0) -> decltype(visit(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCDouble const*>::func(&cocos2d::CCPrettyPrinter::visit), this);
	using FunctionType = decltype(visit(p0))(*)(cocos2d::CCPrettyPrinter*, cocos2d::CCDouble const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b5550, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCPrettyPrinter::visit(cocos2d::CCString const* p0) -> decltype(visit(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCString const*>::func(&cocos2d::CCPrettyPrinter::visit), this);
	using FunctionType = decltype(visit(p0))(*)(cocos2d::CCPrettyPrinter*, cocos2d::CCString const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b55d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCPrettyPrinter::visit(cocos2d::CCArray const* p0) -> decltype(visit(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCArray const*>::func(&cocos2d::CCPrettyPrinter::visit), this);
	using FunctionType = decltype(visit(p0))(*)(cocos2d::CCPrettyPrinter*, cocos2d::CCArray const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b5600, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCPrettyPrinter::visit(cocos2d::CCDictionary const* p0) -> decltype(visit(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCDictionary const*>::func(&cocos2d::CCPrettyPrinter::visit), this);
	using FunctionType = decltype(visit(p0))(*)(cocos2d::CCPrettyPrinter*, cocos2d::CCDictionary const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b5b10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCPrettyPrinter::visit(cocos2d::CCSet const* p0) -> decltype(visit(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCSet const*>::func(&cocos2d::CCPrettyPrinter::visit), this);
	using FunctionType = decltype(visit(p0))(*)(cocos2d::CCPrettyPrinter*, cocos2d::CCSet const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b5fb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCPrettyPrinter::setIndentLevel(int p0) -> decltype(setIndentLevel(p0)) {
	using FunctionType = decltype(setIndentLevel(p0))(*)(cocos2d::CCPrettyPrinter*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b51c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
