
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/OBB2D.hpp>
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

auto OBB2D::create(cocos2d::CCPoint center, float width, float height, float rotationAngle) -> decltype(create(center, width, height, rotationAngle)) {
	using FunctionType = decltype(create(center, width, height, rotationAngle))(*)(cocos2d::CCPoint, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51cafc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(center, width, height, rotationAngle);
}

auto OBB2D::calculateWithCenter(cocos2d::CCPoint center, float width, float height, float rotationAngle) -> decltype(calculateWithCenter(center, width, height, rotationAngle)) {
	using FunctionType = decltype(calculateWithCenter(center, width, height, rotationAngle))(*)(OBB2D*, cocos2d::CCPoint, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51cc80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, center, width, height, rotationAngle);
}

auto OBB2D::computeAxes() -> decltype(computeAxes()) {
	using FunctionType = decltype(computeAxes())(*)(OBB2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51cdf8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto OBB2D::getBoundingRect() -> decltype(getBoundingRect()) {
	using FunctionType = decltype(getBoundingRect())(*)(OBB2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51d418, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto OBB2D::init(cocos2d::CCPoint center, float width, float height, float rotationAngle) -> decltype(init(center, width, height, rotationAngle)) {
	using FunctionType = decltype(init(center, width, height, rotationAngle))(*)(OBB2D*, cocos2d::CCPoint, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51cc00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, center, width, height, rotationAngle);
}

auto OBB2D::orderCorners() -> decltype(orderCorners()) {
	using FunctionType = decltype(orderCorners())(*)(OBB2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51cef8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto OBB2D::overlaps(OBB2D* other) -> decltype(overlaps(other)) {
	using FunctionType = decltype(overlaps(other))(*)(OBB2D*, OBB2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51d28c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, other);
}

auto OBB2D::overlaps1Way(OBB2D* other) -> decltype(overlaps1Way(other)) {
	using FunctionType = decltype(overlaps1Way(other))(*)(OBB2D*, OBB2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51d2c8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, other);
}
