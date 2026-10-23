
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/cocos2d.hpp>
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

auto cocos2d::__CCAffineTransformMake(float p0, float p1, float p2, float p3, float p4, float p5) -> decltype(__CCAffineTransformMake(p0, p1, p2, p3, p4, p5)) {
	using FunctionType = decltype(__CCAffineTransformMake(p0, p1, p2, p3, p4, p5))(*)(float, float, float, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e7948, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3, p4, p5);
}

auto cocos2d::__CCPointApplyAffineTransform(cocos2d::CCPoint const& p0, cocos2d::CCAffineTransform const& p1) -> decltype(__CCPointApplyAffineTransform(p0, p1)) {
	using FunctionType = decltype(__CCPointApplyAffineTransform(p0, p1))(*)(cocos2d::CCPoint const&, cocos2d::CCAffineTransform const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e7958, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::__CCSizeApplyAffineTransform(cocos2d::CCSize const& p0, cocos2d::CCAffineTransform const& p1) -> decltype(__CCSizeApplyAffineTransform(p0, p1)) {
	using FunctionType = decltype(__CCSizeApplyAffineTransform(p0, p1))(*)(cocos2d::CCSize const&, cocos2d::CCAffineTransform const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e79b4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::cc_utf16_to_utf8(unsigned short const* p0, long p1, long* p2, long* p3) -> decltype(cc_utf16_to_utf8(p0, p1, p2, p3)) {
	using FunctionType = decltype(cc_utf16_to_utf8(p0, p1, p2, p3))(*)(unsigned short const*, long, long*, long*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x580578, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

auto cocos2d::cc_utf16_vec_from_utf16_str(unsigned short const* p0) -> decltype(cc_utf16_vec_from_utf16_str(p0)) {
	using FunctionType = decltype(cc_utf16_vec_from_utf16_str(p0))(*)(unsigned short const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58024c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::cc_utf8_find_last_not_char(gd::vector<unsigned short> p0, unsigned short p1) -> decltype(cc_utf8_find_last_not_char(p0, p1)) {
	using FunctionType = decltype(cc_utf8_find_last_not_char(p0, p1))(*)(gd::vector<unsigned short>, unsigned short);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x57fe34, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::cc_utf8_strlen(char const* p0, int p1) -> decltype(cc_utf8_strlen(p0, p1)) {
	using FunctionType = decltype(cc_utf8_strlen(p0, p1))(*)(char const*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58016c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::cc_utf8_to_utf16(char const* p0, int* p1) -> decltype(cc_utf8_to_utf16(p0, p1)) {
	using FunctionType = decltype(cc_utf8_to_utf16(p0, p1))(*)(char const*, int*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5803bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::cc_utf8_trim_ws(gd::vector<unsigned short>* p0) -> decltype(cc_utf8_trim_ws(p0)) {
	using FunctionType = decltype(cc_utf8_trim_ws(p0))(*)(gd::vector<unsigned short>*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x57ff70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::cc_wcslen(unsigned short const* p0) -> decltype(cc_wcslen(p0)) {
	using FunctionType = decltype(cc_wcslen(p0))(*)(unsigned short const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x580140, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCAffineTransformConcat(cocos2d::CCAffineTransform const& p0, cocos2d::CCAffineTransform const& p1) -> decltype(CCAffineTransformConcat(p0, p1)) {
	using FunctionType = decltype(CCAffineTransformConcat(p0, p1))(*)(cocos2d::CCAffineTransform const&, cocos2d::CCAffineTransform const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e7cc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCAffineTransformEqualToTransform(cocos2d::CCAffineTransform const& p0, cocos2d::CCAffineTransform const& p1) -> decltype(CCAffineTransformEqualToTransform(p0, p1)) {
	using FunctionType = decltype(CCAffineTransformEqualToTransform(p0, p1))(*)(cocos2d::CCAffineTransform const&, cocos2d::CCAffineTransform const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e7d18, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCAffineTransformInvert(cocos2d::CCAffineTransform const& p0) -> decltype(CCAffineTransformInvert(p0)) {
	using FunctionType = decltype(CCAffineTransformInvert(p0))(*)(cocos2d::CCAffineTransform const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e7d84, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCAffineTransformMakeIdentity() -> decltype(CCAffineTransformMakeIdentity()) {
	using FunctionType = decltype(CCAffineTransformMakeIdentity())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e7a04, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCAffineTransformRotate(cocos2d::CCAffineTransform const& p0, float p1) -> decltype(CCAffineTransformRotate(p0, p1)) {
	using FunctionType = decltype(CCAffineTransformRotate(p0, p1))(*)(cocos2d::CCAffineTransform const&, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e7c7c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCAffineTransformScale(cocos2d::CCAffineTransform const& p0, float p1, float p2) -> decltype(CCAffineTransformScale(p0, p1, p2)) {
	using FunctionType = decltype(CCAffineTransformScale(p0, p1, p2))(*)(cocos2d::CCAffineTransform const&, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e7c5c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::CCAffineTransformTranslate(cocos2d::CCAffineTransform const& p0, float p1, float p2) -> decltype(CCAffineTransformTranslate(p0, p1, p2)) {
	using FunctionType = decltype(CCAffineTransformTranslate(p0, p1, p2))(*)(cocos2d::CCAffineTransform const&, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e7c30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::ccCardinalSplineAt(cocos2d::CCPoint& p0, cocos2d::CCPoint& p1, cocos2d::CCPoint& p2, cocos2d::CCPoint& p3, float p4, float p5) -> decltype(ccCardinalSplineAt(p0, p1, p2, p3, p4, p5)) {
	using FunctionType = decltype(ccCardinalSplineAt(p0, p1, p2, p3, p4, p5))(*)(cocos2d::CCPoint&, cocos2d::CCPoint&, cocos2d::CCPoint&, cocos2d::CCPoint&, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26ca20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3, p4, p5);
}

auto cocos2d::ccDrawCardinalSpline(cocos2d::CCPointArray* p0, float p1, unsigned int p2) -> decltype(ccDrawCardinalSpline(p0, p1, p2)) {
	using FunctionType = decltype(ccDrawCardinalSpline(p0, p1, p2))(*)(cocos2d::CCPointArray*, float, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b57a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::ccDrawCatmullRom(cocos2d::CCPointArray* p0, unsigned int p1) -> decltype(ccDrawCatmullRom(p0, p1)) {
	using FunctionType = decltype(ccDrawCatmullRom(p0, p1))(*)(cocos2d::CCPointArray*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b57a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::ccDrawCircle(cocos2d::CCPoint const& p0, float p1, float p2, unsigned int p3, bool p4) -> decltype(ccDrawCircle(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(ccDrawCircle(p0, p1, p2, p3, p4))(*)(cocos2d::CCPoint const&, float, float, unsigned int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b4f7c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3, p4);
}

auto cocos2d::ccDrawCircle(cocos2d::CCPoint const& p0, float p1, float p2, unsigned int p3, bool p4, float p5, float p6) -> decltype(ccDrawCircle(p0, p1, p2, p3, p4, p5, p6)) {
	using FunctionType = decltype(ccDrawCircle(p0, p1, p2, p3, p4, p5, p6))(*)(cocos2d::CCPoint const&, float, float, unsigned int, bool, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b4c1c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3, p4, p5, p6);
}

auto cocos2d::ccDrawCircleSegment(cocos2d::CCPoint const& p0, float p1, float p2, float p3, unsigned int p4, bool p5, float p6, float p7) -> decltype(ccDrawCircleSegment(p0, p1, p2, p3, p4, p5, p6, p7)) {
	using FunctionType = decltype(ccDrawCircleSegment(p0, p1, p2, p3, p4, p5, p6, p7))(*)(cocos2d::CCPoint const&, float, float, float, unsigned int, bool, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b4f88, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3, p4, p5, p6, p7);
}

auto cocos2d::ccDrawColor4B(unsigned char p0, unsigned char p1, unsigned char p2, unsigned char p3) -> decltype(ccDrawColor4B(p0, p1, p2, p3)) {
	using FunctionType = decltype(ccDrawColor4B(p0, p1, p2, p3))(*)(unsigned char, unsigned char, unsigned char, unsigned char);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b5c20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

auto cocos2d::ccDrawColor4F(float p0, float p1, float p2, float p3) -> decltype(ccDrawColor4F(p0, p1, p2, p3)) {
	using FunctionType = decltype(ccDrawColor4F(p0, p1, p2, p3))(*)(float, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b5bdc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

auto cocos2d::ccDrawCubicBezier(cocos2d::CCPoint const& p0, cocos2d::CCPoint const& p1, cocos2d::CCPoint const& p2, cocos2d::CCPoint const& p3, unsigned int p4) -> decltype(ccDrawCubicBezier(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(ccDrawCubicBezier(p0, p1, p2, p3, p4))(*)(cocos2d::CCPoint const&, cocos2d::CCPoint const&, cocos2d::CCPoint const&, cocos2d::CCPoint const&, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b59cc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3, p4);
}

auto cocos2d::ccDrawFilledCircle(cocos2d::CCPoint const& p0, float p1, float p2, unsigned int p3) -> decltype(ccDrawFilledCircle(p0, p1, p2, p3)) {
	using FunctionType = decltype(ccDrawFilledCircle(p0, p1, p2, p3))(*)(cocos2d::CCPoint const&, float, float, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b52e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

auto cocos2d::ccDrawFree() -> decltype(ccDrawFree()) {
	using FunctionType = decltype(ccDrawFree())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b438c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::ccDrawInit() -> decltype(ccDrawInit()) {
	using FunctionType = decltype(ccDrawInit())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b4308, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::ccDrawLine(cocos2d::CCPoint const& p0, cocos2d::CCPoint const& p1) -> decltype(ccDrawLine(p0, p1)) {
	using FunctionType = decltype(ccDrawLine(p0, p1))(*)(cocos2d::CCPoint const&, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b4708, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::ccDrawLines(cocos2d::CCPoint const* p0, unsigned int p1) -> decltype(ccDrawLines(p0, p1)) {
	using FunctionType = decltype(ccDrawLines(p0, p1))(*)(cocos2d::CCPoint const*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b45f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::ccDrawPoint(cocos2d::CCPoint const& p0) -> decltype(ccDrawPoint(p0)) {
	using FunctionType = decltype(ccDrawPoint(p0))(*)(cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b43c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::ccDrawPoints(cocos2d::CCPoint const* p0, unsigned int p1) -> decltype(ccDrawPoints(p0, p1)) {
	using FunctionType = decltype(ccDrawPoints(p0, p1))(*)(cocos2d::CCPoint const*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b44e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::ccDrawPoly(cocos2d::CCPoint const* p0, unsigned int p1, bool p2) -> decltype(ccDrawPoly(p0, p1, p2)) {
	using FunctionType = decltype(ccDrawPoly(p0, p1, p2))(*)(cocos2d::CCPoint const*, unsigned int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b4b04, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::ccDrawQuadBezier(cocos2d::CCPoint const& p0, cocos2d::CCPoint const& p1, cocos2d::CCPoint const& p2, unsigned int p3) -> decltype(ccDrawQuadBezier(p0, p1, p2, p3)) {
	using FunctionType = decltype(ccDrawQuadBezier(p0, p1, p2, p3))(*)(cocos2d::CCPoint const&, cocos2d::CCPoint const&, cocos2d::CCPoint const&, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b55f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

auto cocos2d::ccDrawRect(cocos2d::CCPoint p0, cocos2d::CCPoint p1) -> decltype(ccDrawRect(p0, p1)) {
	using FunctionType = decltype(ccDrawRect(p0, p1))(*)(cocos2d::CCPoint, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b4850, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::ccDrawSolidPoly(cocos2d::CCPoint const* p0, unsigned int p1, cocos2d::ccColor4F p2) -> decltype(ccDrawSolidPoly(p0, p1, p2)) {
	using FunctionType = decltype(ccDrawSolidPoly(p0, p1, p2))(*)(cocos2d::CCPoint const*, unsigned int, cocos2d::ccColor4F);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b49ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::ccDrawSolidRect(cocos2d::CCPoint origin, cocos2d::CCPoint destination, cocos2d::ccColor4F color) -> decltype(ccDrawSolidRect(origin, destination, color)) {
	using FunctionType = decltype(ccDrawSolidRect(origin, destination, color))(*)(cocos2d::CCPoint, cocos2d::CCPoint, cocos2d::ccColor4F);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b4918, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(origin, destination, color);
}

auto cocos2d::ccGLBindTexture2D(unsigned int p0) -> decltype(ccGLBindTexture2D(p0)) {
	using FunctionType = decltype(ccGLBindTexture2D(p0))(*)(unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e6d0c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::ccGLBindTexture2DN(unsigned int p0, unsigned int p1) -> decltype(ccGLBindTexture2DN(p0, p1)) {
	using FunctionType = decltype(ccGLBindTexture2DN(p0, p1))(*)(unsigned int, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e6d50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::ccGLBindVAO(unsigned int p0) -> decltype(ccGLBindVAO(p0)) {
	using FunctionType = decltype(ccGLBindVAO(p0))(*)(unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e6e38, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::ccGLBlendFunc(unsigned int p0, unsigned int p1) -> decltype(ccGLBlendFunc(p0, p1)) {
	using FunctionType = decltype(ccGLBlendFunc(p0, p1))(*)(unsigned int, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e6c54, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::ccGLBlendResetToCache() -> decltype(ccGLBlendResetToCache()) {
	using FunctionType = decltype(ccGLBlendResetToCache())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e6cb8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::ccGLDeleteProgram(unsigned int p0) -> decltype(ccGLDeleteProgram(p0)) {
	using FunctionType = decltype(ccGLDeleteProgram(p0))(*)(unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e6c1c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::ccGLDeleteTexture(unsigned int p0) -> decltype(ccGLDeleteTexture(p0)) {
	using FunctionType = decltype(ccGLDeleteTexture(p0))(*)(unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e6da8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::ccGLDeleteTextureN(unsigned int p0, unsigned int p1) -> decltype(ccGLDeleteTextureN(p0, p1)) {
	using FunctionType = decltype(ccGLDeleteTextureN(p0, p1))(*)(unsigned int, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e6de8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::ccGLEnable(cocos2d::ccGLServerState p0) -> decltype(ccGLEnable(p0)) {
	using FunctionType = decltype(ccGLEnable(p0))(*)(cocos2d::ccGLServerState);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e6e54, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::ccGLEnableVertexAttribs(unsigned int p0) -> decltype(ccGLEnableVertexAttribs(p0)) {
	using FunctionType = decltype(ccGLEnableVertexAttribs(p0))(*)(unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e6e58, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::ccGLInvalidateStateCache() -> decltype(ccGLInvalidateStateCache()) {
	using FunctionType = decltype(ccGLInvalidateStateCache())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e6bc8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::ccGLUseProgram(unsigned int p0) -> decltype(ccGLUseProgram(p0)) {
	using FunctionType = decltype(ccGLUseProgram(p0))(*)(unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e6c38, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCLuaLog(char const* p0) -> decltype(CCLuaLog(p0)) {
	using FunctionType = decltype(CCLuaLog(p0))(*)(char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x13c148, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCMessageBox(char const* p0, char const* p1) -> decltype(CCMessageBox(p0, p1)) {
	using FunctionType = decltype(CCMessageBox(p0, p1))(*)(char const*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x13c14c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::ccpAngle(cocos2d::CCPoint const& p0, cocos2d::CCPoint const& p1) -> decltype(ccpAngle(p0, p1)) {
	using FunctionType = decltype(ccpAngle(p0, p1))(*)(cocos2d::CCPoint const&, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e2948, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::ccpAngleSigned(cocos2d::CCPoint const& p0, cocos2d::CCPoint const& p1) -> decltype(ccpAngleSigned(p0, p1)) {
	using FunctionType = decltype(ccpAngleSigned(p0, p1))(*)(cocos2d::CCPoint const&, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e2688, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::ccpClamp(cocos2d::CCPoint const& p0, cocos2d::CCPoint const& p1, cocos2d::CCPoint const& p2) -> decltype(ccpClamp(p0, p1, p2)) {
	using FunctionType = decltype(ccpClamp(p0, p1, p2))(*)(cocos2d::CCPoint const&, cocos2d::CCPoint const&, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e25c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::ccpCompMult(cocos2d::CCPoint const& p0, cocos2d::CCPoint const& p1) -> decltype(ccpCompMult(p0, p1)) {
	using FunctionType = decltype(ccpCompMult(p0, p1))(*)(cocos2d::CCPoint const&, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e2670, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::ccpDistance(cocos2d::CCPoint const& p0, cocos2d::CCPoint const& p1) -> decltype(ccpDistance(p0, p1)) {
	using FunctionType = decltype(ccpDistance(p0, p1))(*)(cocos2d::CCPoint const&, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e24a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::ccpForAngle(float p0) -> decltype(ccpForAngle(p0)) {
	using FunctionType = decltype(ccpForAngle(p0))(*)(float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e2504, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::ccpFromSize(cocos2d::CCSize const& size) -> decltype(ccpFromSize(size)) {
	using FunctionType = decltype(ccpFromSize(size))(*)(cocos2d::CCSize const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e260c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(size);
}

auto cocos2d::ccpFuzzyEqual(cocos2d::CCPoint const& p0, cocos2d::CCPoint const& p1, float p2) -> decltype(ccpFuzzyEqual(p0, p1, p2)) {
	using FunctionType = decltype(ccpFuzzyEqual(p0, p1, p2))(*)(cocos2d::CCPoint const&, cocos2d::CCPoint const&, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e266c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::ccpIntersectPoint(cocos2d::CCPoint const& p0, cocos2d::CCPoint const& p1, cocos2d::CCPoint const& p2, cocos2d::CCPoint const& p3) -> decltype(ccpIntersectPoint(p0, p1, p2, p3)) {
	using FunctionType = decltype(ccpIntersectPoint(p0, p1, p2, p3))(*)(cocos2d::CCPoint const&, cocos2d::CCPoint const&, cocos2d::CCPoint const&, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e2840, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

auto cocos2d::ccpLength(cocos2d::CCPoint const& p0) -> decltype(ccpLength(p0)) {
	using FunctionType = decltype(ccpLength(p0))(*)(cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e2494, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::ccpLerp(cocos2d::CCPoint const& p0, cocos2d::CCPoint const& p1, float p2) -> decltype(ccpLerp(p0, p1, p2)) {
	using FunctionType = decltype(ccpLerp(p0, p1, p2))(*)(cocos2d::CCPoint const&, cocos2d::CCPoint const&, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e253c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::ccpLineIntersect(cocos2d::CCPoint const& p0, cocos2d::CCPoint const& p1, cocos2d::CCPoint const& p2, cocos2d::CCPoint const& p3, float* p4, float* p5) -> decltype(ccpLineIntersect(p0, p1, p2, p3, p4, p5)) {
	using FunctionType = decltype(ccpLineIntersect(p0, p1, p2, p3, p4, p5))(*)(cocos2d::CCPoint const&, cocos2d::CCPoint const&, cocos2d::CCPoint const&, cocos2d::CCPoint const&, float*, float*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e276c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3, p4, p5);
}

auto cocos2d::ccpNormalize(cocos2d::CCPoint const& p0) -> decltype(ccpNormalize(p0)) {
	using FunctionType = decltype(ccpNormalize(p0))(*)(cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e24d8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCPointFromString(char const* p0) -> decltype(CCPointFromString(p0)) {
	using FunctionType = decltype(CCPointFromString(p0))(*)(char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b5f48, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::ccPointSize(float p0) -> decltype(ccPointSize(p0)) {
	using FunctionType = decltype(ccPointSize(p0))(*)(float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b5bf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCProfilingBeginTimingBlock(char const* p0) -> decltype(CCProfilingBeginTimingBlock(p0)) {
	using FunctionType = decltype(CCProfilingBeginTimingBlock(p0))(*)(char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x446b54, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCProfilingEndTimingBlock(char const* p0) -> decltype(CCProfilingEndTimingBlock(p0)) {
	using FunctionType = decltype(CCProfilingEndTimingBlock(p0))(*)(char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x446cd8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCProfilingResetTimingBlock(char const* p0) -> decltype(CCProfilingResetTimingBlock(p0)) {
	using FunctionType = decltype(CCProfilingResetTimingBlock(p0))(*)(char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x446e9c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::ccpRotateByAngle(cocos2d::CCPoint const& p0, cocos2d::CCPoint const& p1, float p2) -> decltype(ccpRotateByAngle(p0, p1, p2)) {
	using FunctionType = decltype(ccpRotateByAngle(p0, p1, p2))(*)(cocos2d::CCPoint const&, cocos2d::CCPoint const&, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e268c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::ccpSegmentIntersect(cocos2d::CCPoint const& p0, cocos2d::CCPoint const& p1, cocos2d::CCPoint const& p2, cocos2d::CCPoint const& p3) -> decltype(ccpSegmentIntersect(p0, p1, p2, p3)) {
	using FunctionType = decltype(ccpSegmentIntersect(p0, p1, p2, p3))(*)(cocos2d::CCPoint const&, cocos2d::CCPoint const&, cocos2d::CCPoint const&, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e2690, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

auto cocos2d::ccpToAngle(cocos2d::CCPoint const& point) -> decltype(ccpToAngle(point)) {
	using FunctionType = decltype(ccpToAngle(point))(*)(cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e2534, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(point);
}

auto cocos2d::CCRectApplyAffineTransform(cocos2d::CCRect const& p0, cocos2d::CCAffineTransform const& p1) -> decltype(CCRectApplyAffineTransform(p0, p1)) {
	using FunctionType = decltype(CCRectApplyAffineTransform(p0, p1))(*)(cocos2d::CCRect const&, cocos2d::CCAffineTransform const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e7a18, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCRectFromString(char const* p0) -> decltype(CCRectFromString(p0)) {
	using FunctionType = decltype(CCRectFromString(p0))(*)(char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b5358, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::ccSetProjectionMatrixDirty() -> decltype(ccSetProjectionMatrixDirty()) {
	using FunctionType = decltype(ccSetProjectionMatrixDirty())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e6f6c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCSizeFromString(char const* p0) -> decltype(CCSizeFromString(p0)) {
	using FunctionType = decltype(CCSizeFromString(p0))(*)(char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b6074, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::ccVertexLineIntersect(float p0, float p1, float p2, float p3, float p4, float p5, float p6, float p7, float* p8) -> decltype(ccVertexLineIntersect(p0, p1, p2, p3, p4, p5, p6, p7, p8)) {
	using FunctionType = decltype(ccVertexLineIntersect(p0, p1, p2, p3, p4, p5, p6, p7, p8))(*)(float, float, float, float, float, float, float, float, float*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32d7bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3, p4, p5, p6, p7, p8);
}

auto cocos2d::ccVertexLineToPolygon(cocos2d::CCPoint* p0, float p1, cocos2d::ccVertex2F* p2, unsigned int p3, unsigned int p4) -> decltype(ccVertexLineToPolygon(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(ccVertexLineToPolygon(p0, p1, p2, p3, p4))(*)(cocos2d::CCPoint*, float, cocos2d::ccVertex2F*, unsigned int, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32d468, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3, p4);
}

auto cocos2d::clampf(float p0, float p1, float p2) -> decltype(clampf(p0, p1, p2)) {
	using FunctionType = decltype(clampf(p0, p1, p2))(*)(float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e25a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::cocos2dVersion() -> decltype(cocos2dVersion()) {
	using FunctionType = decltype(cocos2dVersion())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e1c3c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::FNTConfigLoadFile(char const* p0) -> decltype(FNTConfigLoadFile(p0)) {
	using FunctionType = decltype(FNTConfigLoadFile(p0))(*)(char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x500b70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::FNTConfigRemoveCache() -> decltype(FNTConfigRemoveCache()) {
	using FunctionType = decltype(FNTConfigRemoveCache())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x500e3c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::isspace_unicode(unsigned short p0) -> decltype(isspace_unicode(p0)) {
	using FunctionType = decltype(isspace_unicode(p0))(*)(unsigned short);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x57fe74, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}
