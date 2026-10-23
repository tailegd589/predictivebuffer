
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/BoomListView.hpp>
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

BoomListView::~BoomListView() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(BoomListView*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x30c2f0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) BoomListView(geode::CutoffConstructor, sizeof(BoomListView));
		geode::DestructorLock::addLock(this);
	}
}

auto BoomListView::create(cocos2d::CCArray* entries, TableViewCellDelegate* delegate, float height, float width, int page, BoomListType type, float y) -> decltype(create(entries, delegate, height, width, page, type, y)) {
	using FunctionType = decltype(create(entries, delegate, height, width, page, type, y))(*)(cocos2d::CCArray*, TableViewCellDelegate*, float, float, int, BoomListType, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30c610, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(entries, delegate, height, width, page, type, y);
}

auto BoomListView::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&BoomListView::draw), this);
	using FunctionType = decltype(draw())(*)(BoomListView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30d2b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto BoomListView::setupList(float yOffset) -> decltype(setupList(yOffset)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&BoomListView::setupList), this);
	using FunctionType = decltype(setupList(yOffset))(*)(BoomListView*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30c970, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, yOffset);
}

auto BoomListView::TableViewWillDisplayCellForRowAtIndexPath(CCIndexPath& indexPath, TableViewCell* cell, TableView* tableView) -> decltype(TableViewWillDisplayCellForRowAtIndexPath(indexPath, cell, tableView)) {
	auto self = addresser::thunkAdjust(Resolve<CCIndexPath&, TableViewCell*, TableView*>::func(&BoomListView::TableViewWillDisplayCellForRowAtIndexPath), this);
	using FunctionType = decltype(TableViewWillDisplayCellForRowAtIndexPath(indexPath, cell, tableView))(*)(BoomListView*, CCIndexPath&, TableViewCell*, TableView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30ca10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, indexPath, cell, tableView);
}

auto BoomListView::cellHeightForRowAtIndexPath(CCIndexPath& indexPath, TableView* tableView) -> decltype(cellHeightForRowAtIndexPath(indexPath, tableView)) {
	auto self = addresser::thunkAdjust(Resolve<CCIndexPath&, TableView*>::func(&BoomListView::cellHeightForRowAtIndexPath), this);
	using FunctionType = decltype(cellHeightForRowAtIndexPath(indexPath, tableView))(*)(BoomListView*, CCIndexPath&, TableView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30ca50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, indexPath, tableView);
}

auto BoomListView::didSelectRowAtIndexPath(CCIndexPath& indexPath, TableView* tableView) -> decltype(didSelectRowAtIndexPath(indexPath, tableView)) {
	auto self = addresser::thunkAdjust(Resolve<CCIndexPath&, TableView*>::func(&BoomListView::didSelectRowAtIndexPath), this);
	using FunctionType = decltype(didSelectRowAtIndexPath(indexPath, tableView))(*)(BoomListView*, CCIndexPath&, TableView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30ca70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, indexPath, tableView);
}

auto BoomListView::numberOfRowsInSection(unsigned int section, TableView* tableView) -> decltype(numberOfRowsInSection(section, tableView)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned int, TableView*>::func(&BoomListView::numberOfRowsInSection), this);
	using FunctionType = decltype(numberOfRowsInSection(section, tableView))(*)(BoomListView*, unsigned int, TableView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30ca90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, section, tableView);
}

auto BoomListView::numberOfSectionsInTableView(TableView* tableView) -> decltype(numberOfSectionsInTableView(tableView)) {
	auto self = addresser::thunkAdjust(Resolve<TableView*>::func(&BoomListView::numberOfSectionsInTableView), this);
	using FunctionType = decltype(numberOfSectionsInTableView(tableView))(*)(BoomListView*, TableView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30cac0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, tableView);
}

auto BoomListView::cellForRowAtIndexPath(CCIndexPath& indexPath, TableView* tableView) -> decltype(cellForRowAtIndexPath(indexPath, tableView)) {
	auto self = addresser::thunkAdjust(Resolve<CCIndexPath&, TableView*>::func(&BoomListView::cellForRowAtIndexPath), this);
	using FunctionType = decltype(cellForRowAtIndexPath(indexPath, tableView))(*)(BoomListView*, CCIndexPath&, TableView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30cae0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, indexPath, tableView);
}

auto BoomListView::TableViewCommitCellEditingStyleForRowAtIndexPath(TableView* tableView, TableViewCellEditingStyle style, CCIndexPath& indexPath) -> decltype(TableViewCommitCellEditingStyleForRowAtIndexPath(tableView, style, indexPath)) {
	auto self = addresser::thunkAdjust(Resolve<TableView*, TableViewCellEditingStyle, CCIndexPath&>::func(&BoomListView::TableViewCommitCellEditingStyleForRowAtIndexPath), this);
	using FunctionType = decltype(TableViewCommitCellEditingStyleForRowAtIndexPath(tableView, style, indexPath))(*)(BoomListView*, TableView*, TableViewCellEditingStyle, CCIndexPath&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30d290, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, tableView, style, indexPath);
}

auto BoomListView::TableViewWillReloadCellForRowAtIndexPath(CCIndexPath& indexPath, TableViewCell* cell, TableView* tableView) -> decltype(TableViewWillReloadCellForRowAtIndexPath(indexPath, cell, tableView)) {
	auto self = addresser::thunkAdjust(Resolve<CCIndexPath&, TableViewCell*, TableView*>::func(&BoomListView::TableViewWillReloadCellForRowAtIndexPath), this);
	using FunctionType = decltype(TableViewWillReloadCellForRowAtIndexPath(indexPath, cell, tableView))(*)(BoomListView*, CCIndexPath&, TableViewCell*, TableView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30ca30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, indexPath, cell, tableView);
}

auto BoomListView::getListCell(char const* identifier) -> decltype(getListCell(identifier)) {
	auto self = addresser::thunkAdjust(Resolve<char const*>::func(&BoomListView::getListCell), this);
	using FunctionType = decltype(getListCell(identifier))(*)(BoomListView*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30cc00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, identifier);
}

auto BoomListView::loadCell(TableViewCell* cell, int index) -> decltype(loadCell(cell, index)) {
	auto self = addresser::thunkAdjust(Resolve<TableViewCell*, int>::func(&BoomListView::loadCell), this);
	using FunctionType = decltype(loadCell(cell, index))(*)(BoomListView*, TableViewCell*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30ce40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, cell, index);
}

auto BoomListView::addObjectToList(cocos2d::CCNode* node) -> decltype(addObjectToList(node)) {
	using FunctionType = decltype(addObjectToList(node))(*)(BoomListView*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30c950, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, node);
}

auto BoomListView::init(cocos2d::CCArray* entries, TableViewCellDelegate* delegate, float height, float width, int page, BoomListType type, float y) -> decltype(init(entries, delegate, height, width, page, type, y)) {
	using FunctionType = decltype(init(entries, delegate, height, width, page, type, y))(*)(BoomListView*, cocos2d::CCArray*, TableViewCellDelegate*, float, float, int, BoomListType, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30c740, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, entries, delegate, height, width, page, type, y);
}

auto BoomListView::lockList(bool locked) -> decltype(lockList(locked)) {
	using FunctionType = decltype(lockList(locked))(*)(BoomListView*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30c8f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, locked);
}
