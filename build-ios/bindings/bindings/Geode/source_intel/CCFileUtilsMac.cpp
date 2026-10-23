
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCFileUtilsMac.hpp>
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

auto cocos2d::CCFileUtilsMac::getWritablePath() -> decltype(getWritablePath()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCFileUtilsMac::getWritablePath), this);
	using FunctionType = decltype(getWritablePath())(*)(cocos2d::CCFileUtilsMac*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x60b960, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCFileUtilsMac::isFileExist(gd::string const& strFilePath) -> decltype(isFileExist(strFilePath)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string const&>::func(&cocos2d::CCFileUtilsMac::isFileExist), this);
	using FunctionType = decltype(isFileExist(strFilePath))(*)(cocos2d::CCFileUtilsMac*, gd::string const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x60ba60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, strFilePath);
}

auto cocos2d::CCFileUtilsMac::isAbsolutePath(gd::string const& strPath) -> decltype(isAbsolutePath(strPath)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string const&>::func(&cocos2d::CCFileUtilsMac::isAbsolutePath), this);
	using FunctionType = decltype(isAbsolutePath(strPath))(*)(cocos2d::CCFileUtilsMac*, gd::string const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x60c0b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, strPath);
}

auto cocos2d::CCFileUtilsMac::getFullPathForDirectoryAndFilename(gd::string const& strDirectory, gd::string const& strFilename) -> decltype(getFullPathForDirectoryAndFilename(strDirectory, strFilename)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string const&, gd::string const&>::func(&cocos2d::CCFileUtilsMac::getFullPathForDirectoryAndFilename), this);
	using FunctionType = decltype(getFullPathForDirectoryAndFilename(strDirectory, strFilename))(*)(cocos2d::CCFileUtilsMac*, gd::string const&, gd::string const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x60bdd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, strDirectory, strFilename);
}

auto cocos2d::CCFileUtilsMac::createCCDictionaryWithContentsOfFile(gd::string const& filename) -> decltype(createCCDictionaryWithContentsOfFile(filename)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string const&>::func(&cocos2d::CCFileUtilsMac::createCCDictionaryWithContentsOfFile), this);
	using FunctionType = decltype(createCCDictionaryWithContentsOfFile(filename))(*)(cocos2d::CCFileUtilsMac*, gd::string const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x60c100, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, filename);
}

auto cocos2d::CCFileUtilsMac::writeToFile(cocos2d::CCDictionary* dict, gd::string const& fullPath) -> decltype(writeToFile(dict, fullPath)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCDictionary*, gd::string const&>::func(&cocos2d::CCFileUtilsMac::writeToFile), this);
	using FunctionType = decltype(writeToFile(dict, fullPath))(*)(cocos2d::CCFileUtilsMac*, cocos2d::CCDictionary*, gd::string const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x60cc60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, dict, fullPath);
}

auto cocos2d::CCFileUtilsMac::createCCArrayWithContentsOfFile(gd::string const& filename) -> decltype(createCCArrayWithContentsOfFile(filename)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string const&>::func(&cocos2d::CCFileUtilsMac::createCCArrayWithContentsOfFile), this);
	using FunctionType = decltype(createCCArrayWithContentsOfFile(filename))(*)(cocos2d::CCFileUtilsMac*, gd::string const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x60ceb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, filename);
}
