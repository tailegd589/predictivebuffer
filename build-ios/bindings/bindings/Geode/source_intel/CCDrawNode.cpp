
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCDrawNode.hpp>
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

cocos2d::CCDrawNode::CCDrawNode() : cocos2d::CCDrawNode(geode::CutoffConstructor, sizeof(cocos2d::CCDrawNode)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCDrawNode::~CCDrawNode();

	using FunctionType = void(*)(cocos2d::CCDrawNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x610b00, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCDrawNode::~CCDrawNode() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCDrawNode*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x610c00, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCDrawNode(geode::CutoffConstructor, sizeof(cocos2d::CCDrawNode));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCDrawNode::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x610dc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCDrawNode::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCDrawNode::init), this);
	using FunctionType = decltype(init())(*)(cocos2d::CCDrawNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x610ee0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCDrawNode::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCDrawNode::draw), this);
	using FunctionType = decltype(draw())(*)(cocos2d::CCDrawNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6110d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCDrawNode::clear() -> decltype(clear()) {
	using FunctionType = decltype(clear())(*)(cocos2d::CCDrawNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x613050, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDrawNode::disableDrawArea() -> decltype(disableDrawArea()) {
	using FunctionType = decltype(disableDrawArea())(*)(cocos2d::CCDrawNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x611220, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDrawNode::drawArchLikeHalfCircle(cocos2d::CCPoint const& p0, cocos2d::CCPoint const& p1, float p2, unsigned int p3, cocos2d::_ccColor4F const& p4, float p5) -> decltype(drawArchLikeHalfCircle(p0, p1, p2, p3, p4, p5)) {
	using FunctionType = decltype(drawArchLikeHalfCircle(p0, p1, p2, p3, p4, p5))(*)(cocos2d::CCDrawNode*, cocos2d::CCPoint const&, cocos2d::CCPoint const&, float, unsigned int, cocos2d::_ccColor4F const&, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x611490, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5);
}

auto cocos2d::CCDrawNode::drawCircle(cocos2d::CCPoint const& p0, float p1, cocos2d::ccColor4F const& p2, float p3, cocos2d::ccColor4F const& p4, unsigned int p5) -> decltype(drawCircle(p0, p1, p2, p3, p4, p5)) {
	using FunctionType = decltype(drawCircle(p0, p1, p2, p3, p4, p5))(*)(cocos2d::CCDrawNode*, cocos2d::CCPoint const&, float, cocos2d::ccColor4F const&, float, cocos2d::ccColor4F const&, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x612ea0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5);
}

auto cocos2d::CCDrawNode::drawCubicBezier(cocos2d::CCPoint const& p0, cocos2d::CCPoint const& p1, cocos2d::CCPoint const& p2, cocos2d::CCPoint const& p3, unsigned int p4, cocos2d::ccColor4F const& p5, float p6) -> decltype(drawCubicBezier(p0, p1, p2, p3, p4, p5, p6)) {
	using FunctionType = decltype(drawCubicBezier(p0, p1, p2, p3, p4, p5, p6))(*)(cocos2d::CCDrawNode*, cocos2d::CCPoint const&, cocos2d::CCPoint const&, cocos2d::CCPoint const&, cocos2d::CCPoint const&, unsigned int, cocos2d::ccColor4F const&, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x611b50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5, p6);
}

auto cocos2d::CCDrawNode::drawCubicBezierDashed(cocos2d::CCPoint const& p0, cocos2d::CCPoint const& p1, cocos2d::CCPoint const& p2, cocos2d::CCPoint const& p3, unsigned int p4, cocos2d::ccColor4F const& p5, float p6, unsigned int p7, unsigned int p8) -> decltype(drawCubicBezierDashed(p0, p1, p2, p3, p4, p5, p6, p7, p8)) {
	using FunctionType = decltype(drawCubicBezierDashed(p0, p1, p2, p3, p4, p5, p6, p7, p8))(*)(cocos2d::CCDrawNode*, cocos2d::CCPoint const&, cocos2d::CCPoint const&, cocos2d::CCPoint const&, cocos2d::CCPoint const&, unsigned int, cocos2d::ccColor4F const&, float, unsigned int, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x611660, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5, p6, p7, p8);
}

auto cocos2d::CCDrawNode::drawDot(cocos2d::CCPoint const& pos, float radius, cocos2d::ccColor4F const& color) -> decltype(drawDot(pos, radius, color)) {
	using FunctionType = decltype(drawDot(pos, radius, color))(*)(cocos2d::CCDrawNode*, cocos2d::CCPoint const&, float, cocos2d::ccColor4F const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6112a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, pos, radius, color);
}

auto cocos2d::CCDrawNode::drawLines(cocos2d::CCPoint* p0, unsigned int p1, float p2, cocos2d::ccColor4F const& p3) -> decltype(drawLines(p0, p1, p2, p3)) {
	using FunctionType = decltype(drawLines(p0, p1, p2, p3))(*)(cocos2d::CCDrawNode*, cocos2d::CCPoint*, unsigned int, float, cocos2d::ccColor4F const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x612e20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto cocos2d::CCDrawNode::drawPolygon(cocos2d::CCPoint* p0, unsigned int p1, cocos2d::ccColor4F const& p2, float p3, cocos2d::ccColor4F const& p4, cocos2d::BorderAlignment p5) -> decltype(drawPolygon(p0, p1, p2, p3, p4, p5)) {
	using FunctionType = decltype(drawPolygon(p0, p1, p2, p3, p4, p5))(*)(cocos2d::CCDrawNode*, cocos2d::CCPoint*, unsigned int, cocos2d::ccColor4F const&, float, cocos2d::ccColor4F const&, cocos2d::BorderAlignment);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6124d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5);
}

auto cocos2d::CCDrawNode::drawPreciseCubicBezier(cocos2d::CCPoint const& p0, cocos2d::CCPoint const& p1, cocos2d::CCPoint const& p2, cocos2d::CCPoint const& p3, unsigned int p4, cocos2d::ccColor4F const& p5, float p6) -> decltype(drawPreciseCubicBezier(p0, p1, p2, p3, p4, p5, p6)) {
	using FunctionType = decltype(drawPreciseCubicBezier(p0, p1, p2, p3, p4, p5, p6))(*)(cocos2d::CCDrawNode*, cocos2d::CCPoint const&, cocos2d::CCPoint const&, cocos2d::CCPoint const&, cocos2d::CCPoint const&, unsigned int, cocos2d::ccColor4F const&, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x611870, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5, p6);
}

auto cocos2d::CCDrawNode::drawRect(cocos2d::CCRect const& p0, cocos2d::ccColor4F const& p1, float p2, cocos2d::ccColor4F const& p3, cocos2d::BorderAlignment p4) -> decltype(drawRect(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(drawRect(p0, p1, p2, p3, p4))(*)(cocos2d::CCDrawNode*, cocos2d::CCRect const&, cocos2d::ccColor4F const&, float, cocos2d::ccColor4F const&, cocos2d::BorderAlignment);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x612c60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4);
}

auto cocos2d::CCDrawNode::drawRect(cocos2d::CCPoint const& p0, cocos2d::CCPoint const& p1, cocos2d::ccColor4F const& p2, float p3, cocos2d::ccColor4F const& p4, cocos2d::BorderAlignment p5) -> decltype(drawRect(p0, p1, p2, p3, p4, p5)) {
	using FunctionType = decltype(drawRect(p0, p1, p2, p3, p4, p5))(*)(cocos2d::CCDrawNode*, cocos2d::CCPoint const&, cocos2d::CCPoint const&, cocos2d::ccColor4F const&, float, cocos2d::ccColor4F const&, cocos2d::BorderAlignment);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x612cf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5);
}

auto cocos2d::CCDrawNode::drawSegment(cocos2d::CCPoint const& p0, cocos2d::CCPoint const& p1, float p2, cocos2d::ccColor4F const& p3) -> decltype(drawSegment(p0, p1, p2, p3)) {
	using FunctionType = decltype(drawSegment(p0, p1, p2, p3))(*)(cocos2d::CCDrawNode*, cocos2d::CCPoint const&, cocos2d::CCPoint const&, float, cocos2d::ccColor4F const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6124b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto cocos2d::CCDrawNode::drawSegmentEx(cocos2d::CCPoint const& p0, cocos2d::CCPoint const& p1, float p2, cocos2d::ccColor4F const& p3, bool p4, bool p5) -> decltype(drawSegmentEx(p0, p1, p2, p3, p4, p5)) {
	using FunctionType = decltype(drawSegmentEx(p0, p1, p2, p3, p4, p5))(*)(cocos2d::CCDrawNode*, cocos2d::CCPoint const&, cocos2d::CCPoint const&, float, cocos2d::ccColor4F const&, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x611de0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5);
}

auto cocos2d::CCDrawNode::enableDrawArea(cocos2d::CCRect& p0) -> decltype(enableDrawArea(p0)) {
	using FunctionType = decltype(enableDrawArea(p0))(*)(cocos2d::CCDrawNode*, cocos2d::CCRect&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6111b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCDrawNode::ensureCapacity(unsigned int p0) -> decltype(ensureCapacity(p0)) {
	using FunctionType = decltype(ensureCapacity(p0))(*)(cocos2d::CCDrawNode*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x610e90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCDrawNode::getBlendFunc() const  -> decltype(getBlendFunc()) {
	using FunctionType = decltype(getBlendFunc())(*)(cocos2d::CCDrawNode const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x613070, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDrawNode::is_circle_on_screen(cocos2d::CCRect const& p0, cocos2d::CCPoint const& p1, float p2) -> decltype(is_circle_on_screen(p0, p1, p2)) {
	using FunctionType = decltype(is_circle_on_screen(p0, p1, p2))(*)(cocos2d::CCDrawNode*, cocos2d::CCRect const&, cocos2d::CCPoint const&, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x611230, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCDrawNode::is_segment_on_screen(cocos2d::CCRect const& p0, cocos2d::CCPoint const& p1, cocos2d::CCPoint const& p2) -> decltype(is_segment_on_screen(p0, p1, p2)) {
	using FunctionType = decltype(is_segment_on_screen(p0, p1, p2))(*)(cocos2d::CCDrawNode*, cocos2d::CCRect const&, cocos2d::CCPoint const&, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x612400, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCDrawNode::listenBackToForeground(cocos2d::CCObject* p0) -> decltype(listenBackToForeground(p0)) {
	using FunctionType = decltype(listenBackToForeground(p0))(*)(cocos2d::CCDrawNode*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x613090, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCDrawNode::render() -> decltype(render()) {
	using FunctionType = decltype(render())(*)(cocos2d::CCDrawNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x611040, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCDrawNode::setBlendFunc(cocos2d::ccBlendFunc const& p0) -> decltype(setBlendFunc(p0)) {
	using FunctionType = decltype(setBlendFunc(p0))(*)(cocos2d::CCDrawNode*, cocos2d::ccBlendFunc const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x613080, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
