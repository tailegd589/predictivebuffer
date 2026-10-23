
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCTableView.hpp>
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

cocos2d::extension::CCTableView::CCTableView() : cocos2d::extension::CCTableView(geode::CutoffConstructor, sizeof(cocos2d::extension::CCTableView)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::extension::CCTableView::~CCTableView();

	using FunctionType = void(*)(cocos2d::extension::CCTableView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42c6a0, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::extension::CCTableView::~CCTableView() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::extension::CCTableView*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x42c750, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::extension::CCTableView(geode::CutoffConstructor, sizeof(cocos2d::extension::CCTableView));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::extension::CCTableView::create(cocos2d::extension::CCTableViewDataSource* p0, cocos2d::CCSize p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(cocos2d::extension::CCTableViewDataSource*, cocos2d::CCSize);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42c1b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::extension::CCTableView::create(cocos2d::extension::CCTableViewDataSource* p0, cocos2d::CCSize p1, cocos2d::CCNode* p2) -> decltype(create(p0, p1, p2)) {
	using FunctionType = decltype(create(p0, p1, p2))(*)(cocos2d::extension::CCTableViewDataSource*, cocos2d::CCSize, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42c1e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::extension::CCTableView::scrollViewDidScroll(cocos2d::extension::CCScrollView* p0) -> decltype(scrollViewDidScroll(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::extension::CCScrollView*>::func(&cocos2d::extension::CCTableView::scrollViewDidScroll), this);
	using FunctionType = decltype(scrollViewDidScroll(p0))(*)(cocos2d::extension::CCTableView*, cocos2d::extension::CCScrollView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42d730, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCTableView::ccTouchBegan(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) -> decltype(ccTouchBegan(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&cocos2d::extension::CCTableView::ccTouchBegan), this);
	using FunctionType = decltype(ccTouchBegan(p0, p1))(*)(cocos2d::extension::CCTableView*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42db00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCTableView::ccTouchMoved(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) -> decltype(ccTouchMoved(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&cocos2d::extension::CCTableView::ccTouchMoved), this);
	using FunctionType = decltype(ccTouchMoved(p0, p1))(*)(cocos2d::extension::CCTableView*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42dc80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCTableView::ccTouchEnded(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) -> decltype(ccTouchEnded(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&cocos2d::extension::CCTableView::ccTouchEnded), this);
	using FunctionType = decltype(ccTouchEnded(p0, p1))(*)(cocos2d::extension::CCTableView*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42da00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCTableView::ccTouchCancelled(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) -> decltype(ccTouchCancelled(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&cocos2d::extension::CCTableView::ccTouchCancelled), this);
	using FunctionType = decltype(ccTouchCancelled(p0, p1))(*)(cocos2d::extension::CCTableView*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42dd30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCTableView::__indexFromOffset(cocos2d::CCPoint p0) -> decltype(__indexFromOffset(p0)) {
	using FunctionType = decltype(__indexFromOffset(p0))(*)(cocos2d::extension::CCTableView*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42d690, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCTableView::__offsetFromIndex(unsigned int p0) -> decltype(__offsetFromIndex(p0)) {
	using FunctionType = decltype(__offsetFromIndex(p0))(*)(cocos2d::extension::CCTableView*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42d4f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCTableView::_addCellIfNecessary(cocos2d::extension::CCTableViewCell* p0) -> decltype(_addCellIfNecessary(p0)) {
	using FunctionType = decltype(_addCellIfNecessary(p0))(*)(cocos2d::extension::CCTableView*, cocos2d::extension::CCTableViewCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42cf20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCTableView::_indexFromOffset(cocos2d::CCPoint p0) -> decltype(_indexFromOffset(p0)) {
	using FunctionType = decltype(_indexFromOffset(p0))(*)(cocos2d::extension::CCTableView*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42d570, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCTableView::_moveCellOutOfSight(cocos2d::extension::CCTableViewCell* p0) -> decltype(_moveCellOutOfSight(p0)) {
	using FunctionType = decltype(_moveCellOutOfSight(p0))(*)(cocos2d::extension::CCTableView*, cocos2d::extension::CCTableViewCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42cd70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCTableView::_offsetFromIndex(unsigned int p0) -> decltype(_offsetFromIndex(p0)) {
	using FunctionType = decltype(_offsetFromIndex(p0))(*)(cocos2d::extension::CCTableView*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42d420, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCTableView::_setIndexForCell(unsigned int p0, cocos2d::extension::CCTableViewCell* p1) -> decltype(_setIndexForCell(p0, p1)) {
	using FunctionType = decltype(_setIndexForCell(p0, p1))(*)(cocos2d::extension::CCTableView*, unsigned int, cocos2d::extension::CCTableViewCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42ceb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::extension::CCTableView::_updateCellPositions() -> decltype(_updateCellPositions()) {
	using FunctionType = decltype(_updateCellPositions())(*)(cocos2d::extension::CCTableView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42c4a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::extension::CCTableView::_updateContentSize() -> decltype(_updateContentSize()) {
	using FunctionType = decltype(_updateContentSize())(*)(cocos2d::extension::CCTableView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42c5b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::extension::CCTableView::cellAtIndex(unsigned int p0) -> decltype(cellAtIndex(p0)) {
	using FunctionType = decltype(cellAtIndex(p0))(*)(cocos2d::extension::CCTableView*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42cbe0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCTableView::dequeueCell() -> decltype(dequeueCell()) {
	using FunctionType = decltype(dequeueCell())(*)(cocos2d::extension::CCTableView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42d3c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::extension::CCTableView::getVerticalFillOrder() -> decltype(getVerticalFillOrder()) {
	using FunctionType = decltype(getVerticalFillOrder())(*)(cocos2d::extension::CCTableView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42cbd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::extension::CCTableView::initWithViewSize(cocos2d::CCSize p0, cocos2d::CCNode* p1) -> decltype(initWithViewSize(p0, p1)) {
	using FunctionType = decltype(initWithViewSize(p0, p1))(*)(cocos2d::extension::CCTableView*, cocos2d::CCSize, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42c3b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::extension::CCTableView::insertCellAtIndex(unsigned int p0) -> decltype(insertCellAtIndex(p0)) {
	using FunctionType = decltype(insertCellAtIndex(p0))(*)(cocos2d::extension::CCTableView*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42d010, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCTableView::reloadData() -> decltype(reloadData()) {
	using FunctionType = decltype(reloadData())(*)(cocos2d::extension::CCTableView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42ca40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::extension::CCTableView::removeCellAtIndex(unsigned int p0) -> decltype(removeCellAtIndex(p0)) {
	using FunctionType = decltype(removeCellAtIndex(p0))(*)(cocos2d::extension::CCTableView*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42d1b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCTableView::setVerticalFillOrder(cocos2d::extension::CCTableViewVerticalFillOrder p0) -> decltype(setVerticalFillOrder(p0)) {
	using FunctionType = decltype(setVerticalFillOrder(p0))(*)(cocos2d::extension::CCTableView*, cocos2d::extension::CCTableViewVerticalFillOrder);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42ca00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCTableView::unregisterAllScriptHandler() -> decltype(unregisterAllScriptHandler()) {
	using FunctionType = decltype(unregisterAllScriptHandler())(*)(cocos2d::extension::CCTableView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42c8b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::extension::CCTableView::updateCellAtIndex(unsigned int p0) -> decltype(updateCellAtIndex(p0)) {
	using FunctionType = decltype(updateCellAtIndex(p0))(*)(cocos2d::extension::CCTableView*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42cc50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
