
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>

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

int const kmAABBContainsPoint(kmVec3 const* p0, kmAABB const* p1) {
	using FunctionType = decltype(kmAABBContainsPoint(p0, p1))(*)(kmVec3 const*, kmAABB const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f6700, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmAABB* const kmAABBAssign(kmAABB* p0, kmAABB const* p1) {
	using FunctionType = decltype(kmAABBAssign(p0, p1))(*)(kmAABB*, kmAABB const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f6750, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmAABB* const kmAABBScale(kmAABB* p0, kmAABB const* p1, float p2) {
	using FunctionType = decltype(kmAABBScale(p0, p1, p2))(*)(kmAABB*, kmAABB const*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f6780, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

kmMat3* const kmMat3Fill(kmMat3* p0, float const* p1) {
	using FunctionType = decltype(kmMat3Fill(p0, p1))(*)(kmMat3*, float const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7ab7b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmMat3* const kmMat3Adjugate(kmMat3* p0, kmMat3 const* p1) {
	using FunctionType = decltype(kmMat3Adjugate(p0, p1))(*)(kmMat3*, kmMat3 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7ab880, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmMat3* const kmMat3Identity(kmMat3* p0) {
	using FunctionType = decltype(kmMat3Identity(p0))(*)(kmMat3*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7ab7d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

kmMat3* const kmMat3Inverse(kmMat3* p0, float const p1, kmMat3 const* p2) {
	using FunctionType = decltype(kmMat3Inverse(p0, p1, p2))(*)(kmMat3*, float const, kmMat3 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7ab970, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

int const kmMat3IsIdentity(kmMat3 const* p0) {
	using FunctionType = decltype(kmMat3IsIdentity(p0))(*)(kmMat3 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7abad0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

kmMat3* const kmMat3Transpose(kmMat3* p0, kmMat3 const* p1) {
	using FunctionType = decltype(kmMat3Transpose(p0, p1))(*)(kmMat3*, kmMat3 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7abb00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

float const kmMat3Determinant(kmMat3 const* p0) {
	using FunctionType = decltype(kmMat3Determinant(p0))(*)(kmMat3 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7ab800, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

kmMat3* const kmMat3Multiply(kmMat3* p0, kmMat3 const* p1, kmMat3 const* p2) {
	using FunctionType = decltype(kmMat3Multiply(p0, p1, p2))(*)(kmMat3*, kmMat3 const*, kmMat3 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7abb70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

kmMat3* const kmMat3ScalarMultiply(kmMat3* p0, kmMat3 const* p1, float const p2) {
	using FunctionType = decltype(kmMat3ScalarMultiply(p0, p1, p2))(*)(kmMat3*, kmMat3 const*, float const);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7abaa0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

kmMat3* const kmMat3RotationAxisAngle(kmMat3* p0, kmVec3 const* p1, float p2) {
	using FunctionType = decltype(kmMat3RotationAxisAngle(p0, p1, p2))(*)(kmMat3*, kmVec3 const*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7ac120, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

kmVec3* const kmMat3RotationToAxisAngle(kmVec3* p0, float* p1, kmMat3 const* p2) {
	using FunctionType = decltype(kmMat3RotationToAxisAngle(p0, p1, p2))(*)(kmVec3*, float*, kmMat3 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7ac260, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

kmMat3* const kmMat3Assign(kmMat3* p0, kmMat3 const* p1) {
	using FunctionType = decltype(kmMat3Assign(p0, p1))(*)(kmMat3*, kmMat3 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7abcc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

int const kmMat3AreEqual(kmMat3 const* p0, kmMat3 const* p1) {
	using FunctionType = decltype(kmMat3AreEqual(p0, p1))(*)(kmMat3 const*, kmMat3 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7abcf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmMat3* const kmMat3RotationX(kmMat3* p0, float const p1) {
	using FunctionType = decltype(kmMat3RotationX(p0, p1))(*)(kmMat3*, float const);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7ac2a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmMat3* const kmMat3RotationY(kmMat3* p0, float const p1) {
	using FunctionType = decltype(kmMat3RotationY(p0, p1))(*)(kmMat3*, float const);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7ac2f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmMat3* const kmMat3RotationZ(kmMat3* p0, float const p1) {
	using FunctionType = decltype(kmMat3RotationZ(p0, p1))(*)(kmMat3*, float const);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7ac350, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmMat3* const kmMat3Rotation(kmMat3* p0, float const p1) {
	using FunctionType = decltype(kmMat3Rotation(p0, p1))(*)(kmMat3*, float const);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7abf00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmMat3* const kmMat3Scaling(kmMat3* p0, float const p1, float const p2) {
	using FunctionType = decltype(kmMat3Scaling(p0, p1, p2))(*)(kmMat3*, float const, float const);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7abf50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

kmMat3* const kmMat3Translation(kmMat3* p0, float const p1, float const p2) {
	using FunctionType = decltype(kmMat3Translation(p0, p1, p2))(*)(kmMat3*, float const, float const);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7abf80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

kmMat3* const kmMat3RotationQuaternion(kmMat3* p0, kmQuaternion const* p1) {
	using FunctionType = decltype(kmMat3RotationQuaternion(p0, p1))(*)(kmMat3*, kmQuaternion const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7abfc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmMat4* const kmMat4Fill(kmMat4* p0, float const* p1) {
	using FunctionType = decltype(kmMat4Fill(p0, p1))(*)(kmMat4*, float const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3d2670, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmMat4* const kmMat4Identity(kmMat4* p0) {
	using FunctionType = decltype(kmMat4Identity(p0))(*)(kmMat4*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3d26a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

kmMat4* const kmMat4Inverse(kmMat4* p0, kmMat4 const* p1) {
	using FunctionType = decltype(kmMat4Inverse(p0, p1))(*)(kmMat4*, kmMat4 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3d3140, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

int const kmMat4IsIdentity(kmMat4 const* p0) {
	using FunctionType = decltype(kmMat4IsIdentity(p0))(*)(kmMat4 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3d3220, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

kmMat4* const kmMat4Transpose(kmMat4* p0, kmMat4 const* p1) {
	using FunctionType = decltype(kmMat4Transpose(p0, p1))(*)(kmMat4*, kmMat4 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3d3250, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmMat4* const kmMat4Multiply(kmMat4* p0, kmMat4 const* p1, kmMat4 const* p2) {
	using FunctionType = decltype(kmMat4Multiply(p0, p1, p2))(*)(kmMat4*, kmMat4 const*, kmMat4 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3d3300, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

kmMat4* const kmMat4Assign(kmMat4* p0, kmMat4 const* p1) {
	using FunctionType = decltype(kmMat4Assign(p0, p1))(*)(kmMat4*, kmMat4 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3d31f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

int const kmMat4AreEqual(kmMat4 const* p0, kmMat4 const* p1) {
	using FunctionType = decltype(kmMat4AreEqual(p0, p1))(*)(kmMat4 const*, kmMat4 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3d3410, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmMat4* const kmMat4RotationX(kmMat4* p0, float const p1) {
	using FunctionType = decltype(kmMat4RotationX(p0, p1))(*)(kmMat4*, float const);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3d3920, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmMat4* const kmMat4RotationY(kmMat4* p0, float const p1) {
	using FunctionType = decltype(kmMat4RotationY(p0, p1))(*)(kmMat4*, float const);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3d3980, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmMat4* const kmMat4RotationZ(kmMat4* p0, float const p1) {
	using FunctionType = decltype(kmMat4RotationZ(p0, p1))(*)(kmMat4*, float const);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3d39f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmMat4* const kmMat4RotationPitchYawRoll(kmMat4* p0, float const p1, float const p2, float const p3) {
	using FunctionType = decltype(kmMat4RotationPitchYawRoll(p0, p1, p2, p3))(*)(kmMat4*, float const, float const, float const);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3d3a50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

kmMat4* const kmMat4RotationQuaternion(kmMat4* p0, kmQuaternion const* p1) {
	using FunctionType = decltype(kmMat4RotationQuaternion(p0, p1))(*)(kmMat4*, kmQuaternion const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3d3b90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmMat4* const kmMat4RotationTranslation(kmMat4* p0, kmMat3 const* p1, kmVec3 const* p2) {
	using FunctionType = decltype(kmMat4RotationTranslation(p0, p1, p2))(*)(kmMat4*, kmMat3 const*, kmVec3 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3d4230, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

kmMat4* const kmMat4Scaling(kmMat4* p0, float const p1, float const p2, float const p3) {
	using FunctionType = decltype(kmMat4Scaling(p0, p1, p2, p3))(*)(kmMat4*, float const, float const, float const);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3d3cf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

kmMat4* const kmMat4Translation(kmMat4* p0, float const p1, float const p2, float const p3) {
	using FunctionType = decltype(kmMat4Translation(p0, p1, p2, p3))(*)(kmMat4*, float const, float const, float const);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3d3d20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

kmVec3* const kmMat4GetUpVec3(kmVec3* p0, kmMat4 const* p1) {
	using FunctionType = decltype(kmMat4GetUpVec3(p0, p1))(*)(kmVec3*, kmMat4 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3d3d70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmVec3* const kmMat4GetRightVec3(kmVec3* p0, kmMat4 const* p1) {
	using FunctionType = decltype(kmMat4GetRightVec3(p0, p1))(*)(kmVec3*, kmMat4 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3d3db0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmVec3* const kmMat4GetForwardVec3(kmVec3* p0, kmMat4 const* p1) {
	using FunctionType = decltype(kmMat4GetForwardVec3(p0, p1))(*)(kmVec3*, kmMat4 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3d3df0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmMat4* const kmMat4PerspectiveProjection(kmMat4* p0, float p1, float p2, float p3, float p4) {
	using FunctionType = decltype(kmMat4PerspectiveProjection(p0, p1, p2, p3, p4))(*)(kmMat4*, float, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3d3e30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3, p4);
}

kmMat4* const kmMat4OrthographicProjection(kmMat4* p0, float p1, float p2, float p3, float p4, float p5, float p6) {
	using FunctionType = decltype(kmMat4OrthographicProjection(p0, p1, p2, p3, p4, p5, p6))(*)(kmMat4*, float, float, float, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3d3f30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3, p4, p5, p6);
}

kmMat4* const kmMat4LookAt(kmMat4* p0, kmVec3 const* p1, kmVec3 const* p2, kmVec3 const* p3) {
	using FunctionType = decltype(kmMat4LookAt(p0, p1, p2, p3))(*)(kmMat4*, kmVec3 const*, kmVec3 const*, kmVec3 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3d3fc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

kmMat4* const kmMat4RotationAxisAngle(kmMat4* p0, kmVec3 const* p1, float p2) {
	using FunctionType = decltype(kmMat4RotationAxisAngle(p0, p1, p2))(*)(kmMat4*, kmVec3 const*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3d37c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

kmMat3* const kmMat4ExtractRotation(kmMat3* p0, kmMat4 const* p1) {
	using FunctionType = decltype(kmMat4ExtractRotation(p0, p1))(*)(kmMat3*, kmMat4 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3d4140, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmPlane* const kmMat4ExtractPlane(kmPlane* p0, kmMat4 const* p1, unsigned int const p2) {
	using FunctionType = decltype(kmMat4ExtractPlane(p0, p1, p2))(*)(kmPlane*, kmMat4 const*, unsigned int const);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3d42d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

kmVec3* const kmMat4RotationToAxisAngle(kmVec3* p0, float* p1, kmMat4 const* p2) {
	using FunctionType = decltype(kmMat4RotationToAxisAngle(p0, p1, p2))(*)(kmVec3*, float*, kmMat4 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3d41b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

float const kmPlaneDot(kmPlane const* p0, kmVec4 const* p1) {
	using FunctionType = decltype(kmPlaneDot(p0, p1))(*)(kmPlane const*, kmVec4 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4893c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

float const kmPlaneDotCoord(kmPlane const* p0, kmVec3 const* p1) {
	using FunctionType = decltype(kmPlaneDotCoord(p0, p1))(*)(kmPlane const*, kmVec3 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x489400, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

float const kmPlaneDotNormal(kmPlane const* p0, kmVec3 const* p1) {
	using FunctionType = decltype(kmPlaneDotNormal(p0, p1))(*)(kmPlane const*, kmVec3 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x489430, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmPlane* const kmPlaneFromPointNormal(kmPlane* p0, kmVec3 const* p1, kmVec3 const* p2) {
	using FunctionType = decltype(kmPlaneFromPointNormal(p0, p1, p2))(*)(kmPlane*, kmVec3 const*, kmVec3 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x489460, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

kmPlane* const kmPlaneFromPoints(kmPlane* p0, kmVec3 const* p1, kmVec3 const* p2, kmVec3 const* p3) {
	using FunctionType = decltype(kmPlaneFromPoints(p0, p1, p2, p3))(*)(kmPlane*, kmVec3 const*, kmVec3 const*, kmVec3 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4894a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

kmVec3* const kmPlaneIntersectLine(kmVec3* p0, kmPlane const* p1, kmVec3 const* p2, kmVec3 const* p3) {
	using FunctionType = decltype(kmPlaneIntersectLine(p0, p1, p2, p3))(*)(kmVec3*, kmPlane const*, kmVec3 const*, kmVec3 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x489550, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

kmPlane* const kmPlaneNormalize(kmPlane* p0, kmPlane const* p1) {
	using FunctionType = decltype(kmPlaneNormalize(p0, p1))(*)(kmPlane*, kmPlane const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x489580, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmPlane* const kmPlaneScale(kmPlane* p0, kmPlane const* p1, float p2) {
	using FunctionType = decltype(kmPlaneScale(p0, p1, p2))(*)(kmPlane*, kmPlane const*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x489610, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

POINT_CLASSIFICATION const kmPlaneClassifyPoint(kmPlane const* p0, kmVec3 const* p1) {
	using FunctionType = decltype(kmPlaneClassifyPoint(p0, p1))(*)(kmPlane const*, kmVec3 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x489640, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmQuaternion* const kmQuaternionConjugate(kmQuaternion* p0, kmQuaternion const* p1) {
	using FunctionType = decltype(kmQuaternionConjugate(p0, p1))(*)(kmQuaternion*, kmQuaternion const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50ed10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

float const kmQuaternionDot(kmQuaternion const* p0, kmQuaternion const* p1) {
	using FunctionType = decltype(kmQuaternionDot(p0, p1))(*)(kmQuaternion const*, kmQuaternion const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50ed50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmQuaternion* kmQuaternionExp(kmQuaternion* p0, kmQuaternion const* p1) {
	using FunctionType = decltype(kmQuaternionExp(p0, p1))(*)(kmQuaternion*, kmQuaternion const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50ed90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmQuaternion* kmQuaternionIdentity(kmQuaternion* p0) {
	using FunctionType = decltype(kmQuaternionIdentity(p0))(*)(kmQuaternion*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50edc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

kmQuaternion* kmQuaternionInverse(kmQuaternion* p0, kmQuaternion const* p1) {
	using FunctionType = decltype(kmQuaternionInverse(p0, p1))(*)(kmQuaternion*, kmQuaternion const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50ede0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

int kmQuaternionIsIdentity(kmQuaternion const* p0) {
	using FunctionType = decltype(kmQuaternionIsIdentity(p0))(*)(kmQuaternion const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50eed0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

float kmQuaternionLength(kmQuaternion const* p0) {
	using FunctionType = decltype(kmQuaternionLength(p0))(*)(kmQuaternion const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50ee70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

float kmQuaternionLengthSq(kmQuaternion const* p0) {
	using FunctionType = decltype(kmQuaternionLengthSq(p0))(*)(kmQuaternion const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50ef20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

kmQuaternion* kmQuaternionLn(kmQuaternion* p0, kmQuaternion const* p1) {
	using FunctionType = decltype(kmQuaternionLn(p0, p1))(*)(kmQuaternion*, kmQuaternion const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50ef60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmQuaternion* kmQuaternionMultiply(kmQuaternion* p0, kmQuaternion const* p1, kmQuaternion const* p2) {
	using FunctionType = decltype(kmQuaternionMultiply(p0, p1, p2))(*)(kmQuaternion*, kmQuaternion const*, kmQuaternion const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50ef90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

kmQuaternion* kmQuaternionNormalize(kmQuaternion* p0, kmQuaternion const* p1) {
	using FunctionType = decltype(kmQuaternionNormalize(p0, p1))(*)(kmQuaternion*, kmQuaternion const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50f070, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmQuaternion* kmQuaternionRotationAxis(kmQuaternion* p0, kmVec3 const* p1, float p2) {
	using FunctionType = decltype(kmQuaternionRotationAxis(p0, p1, p2))(*)(kmQuaternion*, kmVec3 const*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50f0f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

kmQuaternion* kmQuaternionRotationMatrix(kmQuaternion* p0, kmMat3 const* p1) {
	using FunctionType = decltype(kmQuaternionRotationMatrix(p0, p1))(*)(kmQuaternion*, kmMat3 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50f140, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmQuaternion* kmQuaternionRotationYawPitchRoll(kmQuaternion* p0, float p1, float p2, float p3) {
	using FunctionType = decltype(kmQuaternionRotationYawPitchRoll(p0, p1, p2, p3))(*)(kmQuaternion*, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50f2e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

kmQuaternion* kmQuaternionSlerp(kmQuaternion* p0, kmQuaternion const* p1, kmQuaternion const* p2, float p3) {
	using FunctionType = decltype(kmQuaternionSlerp(p0, p1, p2, p3))(*)(kmQuaternion*, kmQuaternion const*, kmQuaternion const*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50f470, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

void kmQuaternionToAxisAngle(kmQuaternion const* p0, kmVec3* p1, float* p2) {
	using FunctionType = decltype(kmQuaternionToAxisAngle(p0, p1, p2))(*)(kmQuaternion const*, kmVec3*, float*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50f620, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

kmQuaternion* kmQuaternionScale(kmQuaternion* p0, kmQuaternion const* p1, float p2) {
	using FunctionType = decltype(kmQuaternionScale(p0, p1, p2))(*)(kmQuaternion*, kmQuaternion const*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50eeb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

kmQuaternion* kmQuaternionAssign(kmQuaternion* p0, kmQuaternion const* p1) {
	using FunctionType = decltype(kmQuaternionAssign(p0, p1))(*)(kmQuaternion*, kmQuaternion const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50f720, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmQuaternion* kmQuaternionAdd(kmQuaternion* p0, kmQuaternion const* p1, kmQuaternion const* p2) {
	using FunctionType = decltype(kmQuaternionAdd(p0, p1, p2))(*)(kmQuaternion*, kmQuaternion const*, kmQuaternion const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50f600, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

kmQuaternion* kmQuaternionRotationBetweenVec3(kmQuaternion* p0, kmVec3 const* p1, kmVec3 const* p2, kmVec3 const* p3) {
	using FunctionType = decltype(kmQuaternionRotationBetweenVec3(p0, p1, p2, p3))(*)(kmQuaternion*, kmVec3 const*, kmVec3 const*, kmVec3 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50f730, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

kmVec3* kmQuaternionMultiplyVec3(kmVec3* p0, kmQuaternion const* p1, kmVec3 const* p2) {
	using FunctionType = decltype(kmQuaternionMultiplyVec3(p0, p1, p2))(*)(kmVec3*, kmQuaternion const*, kmVec3 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50f990, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

void kmRay2Fill(kmRay2* p0, float p1, float p2, float p3, float p4) {
	using FunctionType = decltype(kmRay2Fill(p0, p1, p2, p3, p4))(*)(kmRay2*, float, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4d1430, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3, p4);
}

unsigned char kmRay2IntersectLineSegment(kmRay2 const* p0, kmVec2 const* p1, kmVec2 const* p2, kmVec2* p3) {
	using FunctionType = decltype(kmRay2IntersectLineSegment(p0, p1, p2, p3))(*)(kmRay2 const*, kmVec2 const*, kmVec2 const*, kmVec2*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4d1450, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

unsigned char kmRay2IntersectTriangle(kmRay2 const* p0, kmVec2 const* p1, kmVec2 const* p2, kmVec2 const* p3, kmVec2* p4, kmVec2* p5) {
	using FunctionType = decltype(kmRay2IntersectTriangle(p0, p1, p2, p3, p4, p5))(*)(kmRay2 const*, kmVec2 const*, kmVec2 const*, kmVec2 const*, kmVec2*, kmVec2*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4d16d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3, p4, p5);
}

unsigned char kmRay2IntersectCircle(kmRay2 const* p0, kmVec2 const p1, float const p2, kmVec2* p3) {
	using FunctionType = decltype(kmRay2IntersectCircle(p0, p1, p2, p3))(*)(kmRay2 const*, kmVec2 const, float const, kmVec2*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4d1940, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

float kmSQR(float p0) {
	using FunctionType = decltype(kmSQR(p0))(*)(float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x799ef0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

float kmDegreesToRadians(float p0) {
	using FunctionType = decltype(kmDegreesToRadians(p0))(*)(float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x799f00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

float kmRadiansToDegrees(float p0) {
	using FunctionType = decltype(kmRadiansToDegrees(p0))(*)(float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x799f10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

float kmMin(float p0, float p1) {
	using FunctionType = decltype(kmMin(p0, p1))(*)(float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x799f20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

float kmMax(float p0, float p1) {
	using FunctionType = decltype(kmMax(p0, p1))(*)(float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x799f30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

unsigned char kmAlmostEqual(float p0, float p1) {
	using FunctionType = decltype(kmAlmostEqual(p0, p1))(*)(float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x799f40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmVec2* kmVec2Fill(kmVec2* p0, float p1, float p2) {
	using FunctionType = decltype(kmVec2Fill(p0, p1, p2))(*)(kmVec2*, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32b3e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

float kmVec2Length(kmVec2 const* p0) {
	using FunctionType = decltype(kmVec2Length(p0))(*)(kmVec2 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32b400, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

float kmVec2LengthSq(kmVec2 const* p0) {
	using FunctionType = decltype(kmVec2LengthSq(p0))(*)(kmVec2 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32b440, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

kmVec2* kmVec2Normalize(kmVec2* p0, kmVec2 const* p1) {
	using FunctionType = decltype(kmVec2Normalize(p0, p1))(*)(kmVec2*, kmVec2 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32b470, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmVec2* kmVec2Add(kmVec2* p0, kmVec2 const* p1, kmVec2 const* p2) {
	using FunctionType = decltype(kmVec2Add(p0, p1, p2))(*)(kmVec2*, kmVec2 const*, kmVec2 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32b4d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

float kmVec2Dot(kmVec2 const* p0, kmVec2 const* p1) {
	using FunctionType = decltype(kmVec2Dot(p0, p1))(*)(kmVec2 const*, kmVec2 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32b4f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmVec2* kmVec2Subtract(kmVec2* p0, kmVec2 const* p1, kmVec2 const* p2) {
	using FunctionType = decltype(kmVec2Subtract(p0, p1, p2))(*)(kmVec2*, kmVec2 const*, kmVec2 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32b510, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

kmVec2* kmVec2Transform(kmVec2* p0, kmVec2 const* p1, kmMat3 const* p2) {
	using FunctionType = decltype(kmVec2Transform(p0, p1, p2))(*)(kmVec2*, kmVec2 const*, kmMat3 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32b530, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

kmVec2* kmVec2TransformCoord(kmVec2* p0, kmVec2 const* p1, kmMat3 const* p2) {
	using FunctionType = decltype(kmVec2TransformCoord(p0, p1, p2))(*)(kmVec2*, kmVec2 const*, kmMat3 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32b570, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

kmVec2* kmVec2Scale(kmVec2* p0, kmVec2 const* p1, float const p2) {
	using FunctionType = decltype(kmVec2Scale(p0, p1, p2))(*)(kmVec2*, kmVec2 const*, float const);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32b5a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

int kmVec2AreEqual(kmVec2 const* p0, kmVec2 const* p1) {
	using FunctionType = decltype(kmVec2AreEqual(p0, p1))(*)(kmVec2 const*, kmVec2 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32b5c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmVec3* kmVec3Fill(kmVec3* p0, float p1, float p2, float p3) {
	using FunctionType = decltype(kmVec3Fill(p0, p1, p2, p3))(*)(kmVec3*, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x608fe0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

float kmVec3Length(kmVec3 const* p0) {
	using FunctionType = decltype(kmVec3Length(p0))(*)(kmVec3 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x609000, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

float kmVec3LengthSq(kmVec3 const* p0) {
	using FunctionType = decltype(kmVec3LengthSq(p0))(*)(kmVec3 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x609050, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

kmVec3* kmVec3Normalize(kmVec3* p0, kmVec3 const* p1) {
	using FunctionType = decltype(kmVec3Normalize(p0, p1))(*)(kmVec3*, kmVec3 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6090a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmVec3* kmVec3Cross(kmVec3* p0, kmVec3 const* p1, kmVec3 const* p2) {
	using FunctionType = decltype(kmVec3Cross(p0, p1, p2))(*)(kmVec3*, kmVec3 const*, kmVec3 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x609120, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

float kmVec3Dot(kmVec3 const* p0, kmVec3 const* p1) {
	using FunctionType = decltype(kmVec3Dot(p0, p1))(*)(kmVec3 const*, kmVec3 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x609170, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmVec3* kmVec3Add(kmVec3* p0, kmVec3 const* p1, kmVec3 const* p2) {
	using FunctionType = decltype(kmVec3Add(p0, p1, p2))(*)(kmVec3*, kmVec3 const*, kmVec3 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6091a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

kmVec3* kmVec3Subtract(kmVec3* p0, kmVec3 const* p1, kmVec3 const* p2) {
	using FunctionType = decltype(kmVec3Subtract(p0, p1, p2))(*)(kmVec3*, kmVec3 const*, kmVec3 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6091d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

kmVec3* kmVec3Transform(kmVec3* p0, kmVec3 const* p1, kmMat4 const* p2) {
	using FunctionType = decltype(kmVec3Transform(p0, p1, p2))(*)(kmVec3*, kmVec3 const*, kmMat4 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x609200, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

kmVec3* kmVec3TransformNormal(kmVec3* p0, kmVec3 const* p1, kmMat4 const* p2) {
	using FunctionType = decltype(kmVec3TransformNormal(p0, p1, p2))(*)(kmVec3*, kmVec3 const*, kmMat4 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x609400, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

kmVec3* kmVec3TransformCoord(kmVec3* p0, kmVec3 const* p1, kmMat4 const* p2) {
	using FunctionType = decltype(kmVec3TransformCoord(p0, p1, p2))(*)(kmVec3*, kmVec3 const*, kmMat4 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x609380, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

kmVec3* kmVec3Scale(kmVec3* p0, kmVec3 const* p1, float const p2) {
	using FunctionType = decltype(kmVec3Scale(p0, p1, p2))(*)(kmVec3*, kmVec3 const*, float const);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x609460, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

int kmVec3AreEqual(kmVec3 const* p0, kmVec3 const* p1) {
	using FunctionType = decltype(kmVec3AreEqual(p0, p1))(*)(kmVec3 const*, kmVec3 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x609490, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmVec3* kmVec3InverseTransform(kmVec3* p0, kmVec3 const* p1, kmMat4 const* p2) {
	using FunctionType = decltype(kmVec3InverseTransform(p0, p1, p2))(*)(kmVec3*, kmVec3 const*, kmMat4 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x609300, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

kmVec3* kmVec3InverseTransformNormal(kmVec3* p0, kmVec3 const* p1, kmMat4 const* p2) {
	using FunctionType = decltype(kmVec3InverseTransformNormal(p0, p1, p2))(*)(kmVec3*, kmVec3 const*, kmMat4 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x609270, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

kmVec3* kmVec3Assign(kmVec3* p0, kmVec3 const* p1) {
	using FunctionType = decltype(kmVec3Assign(p0, p1))(*)(kmVec3*, kmVec3 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x609540, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

kmVec3* kmVec3Zero(kmVec3* p0) {
	using FunctionType = decltype(kmVec3Zero(p0))(*)(kmVec3*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x609560, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

void kmGLFreeAll() {
	using FunctionType = decltype(kmGLFreeAll())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x207ef0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

void kmGLPushMatrix() {
	using FunctionType = decltype(kmGLPushMatrix())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x207e70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

void kmGLPopMatrix() {
	using FunctionType = decltype(kmGLPopMatrix())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x207eb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

void kmGLMatrixMode(unsigned int p0) {
	using FunctionType = decltype(kmGLMatrixMode(p0))(*)(unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x207e30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

void kmGLLoadIdentity() {
	using FunctionType = decltype(kmGLLoadIdentity())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x207ed0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

void kmGLLoadMatrix(kmMat4 const* p0) {
	using FunctionType = decltype(kmGLLoadMatrix(p0))(*)(kmMat4 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x207f60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

void kmGLMultMatrix(kmMat4 const* p0) {
	using FunctionType = decltype(kmGLMultMatrix(p0))(*)(kmMat4 const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x207f30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

void kmGLTranslatef(float p0, float p1, float p2) {
	using FunctionType = decltype(kmGLTranslatef(p0, p1, p2))(*)(float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x207fe0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

void kmGLRotatef(float p0, float p1, float p2, float p3) {
	using FunctionType = decltype(kmGLRotatef(p0, p1, p2, p3))(*)(float, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x208020, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

void kmGLScalef(float p0, float p1, float p2) {
	using FunctionType = decltype(kmGLScalef(p0, p1, p2))(*)(float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x208080, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

void kmGLGetMatrix(unsigned int p0, kmMat4* p1) {
	using FunctionType = decltype(kmGLGetMatrix(p0, p1))(*)(unsigned int, kmMat4*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x207f90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}
