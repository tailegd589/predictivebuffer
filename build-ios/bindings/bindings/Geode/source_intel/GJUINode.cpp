
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJUINode.hpp>
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

auto GJUINode::create(UIButtonConfig& config) -> decltype(create(config)) {
	using FunctionType = decltype(create(config))(*)(UIButtonConfig&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c8350, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(config);
}

auto GJUINode::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJUINode::draw), this);
	using FunctionType = decltype(draw())(*)(GJUINode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4cb6d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJUINode::activeRangeTouchTest(cocos2d::CCPoint position) -> decltype(activeRangeTouchTest(position)) {
	using FunctionType = decltype(activeRangeTouchTest(position))(*)(GJUINode*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4cb580, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, position);
}

auto GJUINode::activeTouchTest(cocos2d::CCPoint position) -> decltype(activeTouchTest(position)) {
	using FunctionType = decltype(activeTouchTest(position))(*)(GJUINode*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ca470, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, position);
}

auto GJUINode::getButtonScale() -> decltype(getButtonScale()) {
	using FunctionType = decltype(getButtonScale())(*)(GJUINode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4cb310, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJUINode::getOpacity() -> decltype(getOpacity()) {
	using FunctionType = decltype(getOpacity())(*)(GJUINode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4cb330, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJUINode::highlightButton(int button) -> decltype(highlightButton(button)) {
	using FunctionType = decltype(highlightButton(button))(*)(GJUINode*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ca4e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, button);
}

auto GJUINode::init(UIButtonConfig& config) -> decltype(init(config)) {
	using FunctionType = decltype(init(config))(*)(GJUINode*, UIButtonConfig&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4caa50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, config);
}

auto GJUINode::loadFromConfig(UIButtonConfig& config) -> decltype(loadFromConfig(config)) {
	using FunctionType = decltype(loadFromConfig(config))(*)(GJUINode*, UIButtonConfig&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c8850, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, config);
}

auto GJUINode::resetState() -> decltype(resetState()) {
	using FunctionType = decltype(resetState())(*)(GJUINode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c8cc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJUINode::saveToConfig(UIButtonConfig& config) -> decltype(saveToConfig(config)) {
	using FunctionType = decltype(saveToConfig(config))(*)(GJUINode*, UIButtonConfig&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4cb260, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, config);
}

auto GJUINode::setOpacity(unsigned char opacity) -> decltype(setOpacity(opacity)) {
	using FunctionType = decltype(setOpacity(opacity))(*)(GJUINode*, unsigned char);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4cb220, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, opacity);
}

auto GJUINode::toggleHighlight(int button, bool highlight) -> decltype(toggleHighlight(button, highlight)) {
	using FunctionType = decltype(toggleHighlight(button, highlight))(*)(GJUINode*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ca410, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, button, highlight);
}

auto GJUINode::toggleModeB(bool modeB) -> decltype(toggleModeB(modeB)) {
	using FunctionType = decltype(toggleModeB(modeB))(*)(GJUINode*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4caff0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, modeB);
}

auto GJUINode::touchEnded() -> decltype(touchEnded()) {
	using FunctionType = decltype(touchEnded())(*)(GJUINode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ca580, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJUINode::touchTest(cocos2d::CCPoint position) -> decltype(touchTest(position)) {
	using FunctionType = decltype(touchTest(position))(*)(GJUINode*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ca2c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, position);
}

auto GJUINode::updateButtonFrames() -> decltype(updateButtonFrames()) {
	using FunctionType = decltype(updateButtonFrames())(*)(GJUINode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4cb350, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJUINode::updateButtonPositions() -> decltype(updateButtonPositions()) {
	using FunctionType = decltype(updateButtonPositions())(*)(GJUINode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4cae00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJUINode::updateButtonScale(float scale) -> decltype(updateButtonScale(scale)) {
	using FunctionType = decltype(updateButtonScale(scale))(*)(GJUINode*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4cb0f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, scale);
}

auto GJUINode::updateDeadzone(int deadzone) -> decltype(updateDeadzone(deadzone)) {
	using FunctionType = decltype(updateDeadzone(deadzone))(*)(GJUINode*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4cafd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, deadzone);
}

auto GJUINode::updateDragRadius(float radius) -> decltype(updateDragRadius(radius)) {
	using FunctionType = decltype(updateDragRadius(radius))(*)(GJUINode*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4caee0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, radius);
}

auto GJUINode::updateHeight(float height) -> decltype(updateHeight(height)) {
	using FunctionType = decltype(updateHeight(height))(*)(GJUINode*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4cb480, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, height);
}

auto GJUINode::updateRangePos(cocos2d::CCPoint position) -> decltype(updateRangePos(position)) {
	using FunctionType = decltype(updateRangePos(position))(*)(GJUINode*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4cb4f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, position);
}

auto GJUINode::updateSize(float width, float height) -> decltype(updateSize(width, height)) {
	using FunctionType = decltype(updateSize(width, height))(*)(GJUINode*, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4cada0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, width, height);
}

auto GJUINode::updateWidth(float width) -> decltype(updateWidth(width)) {
	using FunctionType = decltype(updateWidth(width))(*)(GJUINode*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4cb410, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, width);
}
