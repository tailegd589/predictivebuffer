
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/ZipUtils.hpp>
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

auto cocos2d::ZipUtils::base64DecodeEnc(gd::string const& p0, gd::string p1) -> decltype(base64DecodeEnc(p0, p1)) {
	using FunctionType = decltype(base64DecodeEnc(p0, p1))(*)(gd::string const&, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x205880, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::ZipUtils::base64EncodeEnc(gd::string const& p0, gd::string p1) -> decltype(base64EncodeEnc(p0, p1)) {
	using FunctionType = decltype(base64EncodeEnc(p0, p1))(*)(gd::string const&, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x205ac0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::ZipUtils::base64URLDecode(gd::string const& p0) -> decltype(base64URLDecode(p0)) {
	using FunctionType = decltype(base64URLDecode(p0))(*)(gd::string const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x205d00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::ZipUtils::base64URLEncode(gd::string const& p0) -> decltype(base64URLEncode(p0)) {
	using FunctionType = decltype(base64URLEncode(p0))(*)(gd::string const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x205de0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::ZipUtils::ccDeflateMemory(unsigned char* data, unsigned int size, unsigned char** out) -> decltype(ccDeflateMemory(data, size, out)) {
	using FunctionType = decltype(ccDeflateMemory(data, size, out))(*)(unsigned char*, unsigned int, unsigned char**);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2051c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(data, size, out);
}

auto cocos2d::ZipUtils::compressString(gd::string const& data, bool encrypt, int encryptionKey) -> decltype(compressString(data, encrypt, encryptionKey)) {
	using FunctionType = decltype(compressString(data, encrypt, encryptionKey))(*)(gd::string const&, bool, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x204f50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(data, encrypt, encryptionKey);
}

auto cocos2d::ZipUtils::decompressString(gd::string const& data, bool encrypt, int encryptionKey) -> decltype(decompressString(data, encrypt, encryptionKey)) {
	using FunctionType = decltype(decompressString(data, encrypt, encryptionKey))(*)(gd::string const&, bool, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x205600, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(data, encrypt, encryptionKey);
}

auto cocos2d::ZipUtils::decompressString2(unsigned char* data, bool encrypt, int size, int encryptionKey) -> decltype(decompressString2(data, encrypt, size, encryptionKey)) {
	using FunctionType = decltype(decompressString2(data, encrypt, size, encryptionKey))(*)(unsigned char*, bool, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2052e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(data, encrypt, size, encryptionKey);
}

auto cocos2d::ZipUtils::hexToChar(gd::string const& p0) -> decltype(hexToChar(p0)) {
	using FunctionType = decltype(hexToChar(p0))(*)(gd::string const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x206250, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::ZipUtils::urlDecode(gd::string const& p0) -> decltype(urlDecode(p0)) {
	using FunctionType = decltype(urlDecode(p0))(*)(gd::string const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x205ec0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}
