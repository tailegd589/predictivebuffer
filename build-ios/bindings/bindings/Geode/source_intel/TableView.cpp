
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/TableView.hpp>
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

TableView::TableView(cocos2d::CCRect rect) : TableView(geode::CutoffConstructor, sizeof(TableView)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	TableView::~TableView();

	using FunctionType = void(*)(TableView*, cocos2d::CCRect);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x621820, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this, rect);
}

TableView::~TableView() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(TableView*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x6219a0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) TableView(geode::CutoffConstructor, sizeof(TableView));
		geode::DestructorLock::addLock(this);
	}
}

auto TableView::create(TableViewDelegate* tvd, TableViewDataSource* tvds, TableViewCellDelegate* tvcd, cocos2d::CCRect rect) -> decltype(create(tvd, tvds, tvcd, rect)) {
	using FunctionType = decltype(create(tvd, tvds, tvcd, rect))(*)(TableViewDelegate*, TableViewDataSource*, TableViewCellDelegate*, cocos2d::CCRect);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x621760, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(tvd, tvds, tvcd, rect);
}

auto TableView::onEnter() -> decltype(onEnter()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&TableView::onEnter), this);
	using FunctionType = decltype(onEnter())(*)(TableView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x622af0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto TableView::onExit() -> decltype(onExit()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&TableView::onExit), this);
	using FunctionType = decltype(onExit())(*)(TableView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x622b00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto TableView::ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchBegan(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&TableView::ccTouchBegan), this);
	using FunctionType = decltype(ccTouchBegan(touch, event))(*)(TableView*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x622ca0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto TableView::ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchMoved(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&TableView::ccTouchMoved), this);
	using FunctionType = decltype(ccTouchMoved(touch, event))(*)(TableView*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6237d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto TableView::ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchEnded(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&TableView::ccTouchEnded), this);
	using FunctionType = decltype(ccTouchEnded(touch, event))(*)(TableView*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6235a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto TableView::ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchCancelled(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&TableView::ccTouchCancelled), this);
	using FunctionType = decltype(ccTouchCancelled(touch, event))(*)(TableView*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x623720, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto TableView::registerWithTouchDispatcher() -> decltype(registerWithTouchDispatcher()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&TableView::registerWithTouchDispatcher), this);
	using FunctionType = decltype(registerWithTouchDispatcher())(*)(TableView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x622b10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto TableView::scrollWheel(float y, float x) -> decltype(scrollWheel(y, x)) {
	auto self = addresser::thunkAdjust(Resolve<float, float>::func(&TableView::scrollWheel), this);
	using FunctionType = decltype(scrollWheel(y, x))(*)(TableView*, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6238c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, y, x);
}

auto TableView::scrllViewWillBeginDecelerating(CCScrollLayerExt* layer) -> decltype(scrllViewWillBeginDecelerating(layer)) {
	auto self = addresser::thunkAdjust(Resolve<CCScrollLayerExt*>::func(&TableView::scrllViewWillBeginDecelerating), this);
	using FunctionType = decltype(scrllViewWillBeginDecelerating(layer))(*)(TableView*, CCScrollLayerExt*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6244c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer);
}

auto TableView::scrollViewDidEndDecelerating(CCScrollLayerExt* layer) -> decltype(scrollViewDidEndDecelerating(layer)) {
	auto self = addresser::thunkAdjust(Resolve<CCScrollLayerExt*>::func(&TableView::scrollViewDidEndDecelerating), this);
	using FunctionType = decltype(scrollViewDidEndDecelerating(layer))(*)(TableView*, CCScrollLayerExt*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6244e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer);
}

auto TableView::scrollViewTouchMoving(CCScrollLayerExt* layer) -> decltype(scrollViewTouchMoving(layer)) {
	auto self = addresser::thunkAdjust(Resolve<CCScrollLayerExt*>::func(&TableView::scrollViewTouchMoving), this);
	using FunctionType = decltype(scrollViewTouchMoving(layer))(*)(TableView*, CCScrollLayerExt*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x624500, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer);
}

auto TableView::scrollViewDidEndMoving(CCScrollLayerExt* layer) -> decltype(scrollViewDidEndMoving(layer)) {
	auto self = addresser::thunkAdjust(Resolve<CCScrollLayerExt*>::func(&TableView::scrollViewDidEndMoving), this);
	using FunctionType = decltype(scrollViewDidEndMoving(layer))(*)(TableView*, CCScrollLayerExt*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x624520, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer);
}

auto TableView::cancelAndStoleTouch(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(cancelAndStoleTouch(touch, event)) {
	using FunctionType = decltype(cancelAndStoleTouch(touch, event))(*)(TableView*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x622bc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, touch, event);
}

auto TableView::cellForRowAtIndexPath(CCIndexPath& path) -> decltype(cellForRowAtIndexPath(path)) {
	using FunctionType = decltype(cellForRowAtIndexPath(path))(*)(TableView*, CCIndexPath&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6224b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, path);
}

auto TableView::cellForTouch(cocos2d::CCTouch* touch) -> decltype(cellForTouch(touch)) {
	using FunctionType = decltype(cellForTouch(touch))(*)(TableView*, cocos2d::CCTouch*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x622030, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, touch);
}

auto TableView::checkBoundaryOfCell(TableViewCell* cell) -> decltype(checkBoundaryOfCell(cell)) {
	using FunctionType = decltype(checkBoundaryOfCell(cell))(*)(TableView*, TableViewCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x623900, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, cell);
}

auto TableView::checkBoundaryOfCell(cocos2d::CCPoint& position, float height) -> decltype(checkBoundaryOfCell(position, height)) {
	using FunctionType = decltype(checkBoundaryOfCell(position, height))(*)(TableView*, cocos2d::CCPoint&, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x623a40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, position, height);
}

auto TableView::checkBoundaryOfContent(float dt) -> decltype(checkBoundaryOfContent(dt)) {
	using FunctionType = decltype(checkBoundaryOfContent(dt))(*)(TableView*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x622d60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}

auto TableView::checkFirstCell(TableViewCell* cell) -> decltype(checkFirstCell(cell)) {
	using FunctionType = decltype(checkFirstCell(cell))(*)(TableView*, TableViewCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x624110, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, cell);
}

auto TableView::checkLastCell(TableViewCell* cell) -> decltype(checkLastCell(cell)) {
	using FunctionType = decltype(checkLastCell(cell))(*)(TableView*, TableViewCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x623b60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, cell);
}

auto TableView::claimTouch(cocos2d::CCTouch* touch) -> decltype(claimTouch(touch)) {
	using FunctionType = decltype(claimTouch(touch))(*)(TableView*, cocos2d::CCTouch*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x622b50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, touch);
}

auto TableView::deleteTableViewCell(TableViewCell* cell) -> decltype(deleteTableViewCell(cell)) {
	using FunctionType = decltype(deleteTableViewCell(cell))(*)(TableView*, TableViewCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x622210, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, cell);
}

auto TableView::dequeueReusableCellWithIdentifier(char const* identifier) -> decltype(dequeueReusableCellWithIdentifier(identifier)) {
	using FunctionType = decltype(dequeueReusableCellWithIdentifier(identifier))(*)(TableView*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6224a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, identifier);
}

auto TableView::initTableViewCells() -> decltype(initTableViewCells()) {
	using FunctionType = decltype(initTableViewCells())(*)(TableView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x621cf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto TableView::isDuplicateIndexPath(CCIndexPath& path) -> decltype(isDuplicateIndexPath(path)) {
	using FunctionType = decltype(isDuplicateIndexPath(path))(*)(TableView*, CCIndexPath&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x621bc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, path);
}

auto TableView::isDuplicateInVisibleCellArray(CCIndexPath* path) -> decltype(isDuplicateInVisibleCellArray(path)) {
	using FunctionType = decltype(isDuplicateInVisibleCellArray(path))(*)(TableView*, CCIndexPath*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x621b30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, path);
}

auto TableView::reloadData() -> decltype(reloadData()) {
	using FunctionType = decltype(reloadData())(*)(TableView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x622540, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto TableView::removeIndexPathFromPathAddedArray(CCIndexPath& path) -> decltype(removeIndexPathFromPathAddedArray(path)) {
	using FunctionType = decltype(removeIndexPathFromPathAddedArray(path))(*)(TableView*, CCIndexPath&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x621c50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, path);
}

auto TableView::scrollToIndexPath(CCIndexPath& path) -> decltype(scrollToIndexPath(path)) {
	using FunctionType = decltype(scrollToIndexPath(path))(*)(TableView*, CCIndexPath&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x622530, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, path);
}

auto TableView::touchFinish(cocos2d::CCTouch* touch) -> decltype(touchFinish(touch)) {
	using FunctionType = decltype(touchFinish(touch))(*)(TableView*, cocos2d::CCTouch*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6235f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, touch);
}
