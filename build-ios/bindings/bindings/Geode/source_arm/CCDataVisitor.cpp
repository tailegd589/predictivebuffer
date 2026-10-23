
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCDataVisitor.hpp>
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

auto cocos2d::CCDataVisitor::visit(cocos2d::CCBool const* p0) -> decltype(visit(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCBool const*>::func(&cocos2d::CCDataVisitor::visit), this);
	using FunctionType = decltype(visit(p0))(*)(cocos2d::CCDataVisitor*, cocos2d::CCBool const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x416300, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCDataVisitor::visit(cocos2d::CCInteger const* p0) -> decltype(visit(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCInteger const*>::func(&cocos2d::CCDataVisitor::visit), this);
	using FunctionType = decltype(visit(p0))(*)(cocos2d::CCDataVisitor*, cocos2d::CCInteger const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x41630c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCDataVisitor::visit(cocos2d::CCFloat const* p0) -> decltype(visit(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCFloat const*>::func(&cocos2d::CCDataVisitor::visit), this);
	using FunctionType = decltype(visit(p0))(*)(cocos2d::CCDataVisitor*, cocos2d::CCFloat const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x416318, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCDataVisitor::visit(cocos2d::CCDouble const* p0) -> decltype(visit(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCDouble const*>::func(&cocos2d::CCDataVisitor::visit), this);
	using FunctionType = decltype(visit(p0))(*)(cocos2d::CCDataVisitor*, cocos2d::CCDouble const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x416324, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCDataVisitor::visit(cocos2d::CCString const* p0) -> decltype(visit(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCString const*>::func(&cocos2d::CCDataVisitor::visit), this);
	using FunctionType = decltype(visit(p0))(*)(cocos2d::CCDataVisitor*, cocos2d::CCString const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x416330, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCDataVisitor::visit(cocos2d::CCArray const* p0) -> decltype(visit(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCArray const*>::func(&cocos2d::CCDataVisitor::visit), this);
	using FunctionType = decltype(visit(p0))(*)(cocos2d::CCDataVisitor*, cocos2d::CCArray const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x41633c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCDataVisitor::visit(cocos2d::CCDictionary const* p0) -> decltype(visit(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCDictionary const*>::func(&cocos2d::CCDataVisitor::visit), this);
	using FunctionType = decltype(visit(p0))(*)(cocos2d::CCDataVisitor*, cocos2d::CCDictionary const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x416348, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCDataVisitor::visit(cocos2d::CCSet const* p0) -> decltype(visit(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCSet const*>::func(&cocos2d::CCDataVisitor::visit), this);
	using FunctionType = decltype(visit(p0))(*)(cocos2d::CCDataVisitor*, cocos2d::CCSet const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x416354, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}
