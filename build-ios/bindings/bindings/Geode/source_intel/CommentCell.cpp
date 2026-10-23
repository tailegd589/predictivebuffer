
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/CommentCell.hpp>
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

CommentCell::CommentCell(char const* identifier, float width, float height) : CommentCell(geode::CutoffConstructor, sizeof(CommentCell)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	CommentCell::~CommentCell();

	using FunctionType = void(*)(CommentCell*, char const*, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x254d10, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this, identifier, width, height);
}

CommentCell::~CommentCell() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(CommentCell*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x2549e0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) CommentCell(geode::CutoffConstructor, sizeof(CommentCell));
		geode::DestructorLock::addLock(this);
	}
}

auto CommentCell::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CommentCell::init), this);
	using FunctionType = decltype(init())(*)(CommentCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x254db0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CommentCell::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CommentCell::draw), this);
	using FunctionType = decltype(draw())(*)(CommentCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2550c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CommentCell::likedItem(LikeItemType type, int id, bool liked) -> decltype(likedItem(type, id, liked)) {
	auto self = addresser::thunkAdjust(Resolve<LikeItemType, int, bool>::func(&CommentCell::likedItem), this);
	using FunctionType = decltype(likedItem(type, id, liked))(*)(CommentCell*, LikeItemType, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x255190, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, type, id, liked);
}

auto CommentCell::FLAlert_Clicked(FLAlertLayer* layer, bool btn2) -> decltype(FLAlert_Clicked(layer, btn2)) {
	auto self = addresser::thunkAdjust(Resolve<FLAlertLayer*, bool>::func(&CommentCell::FLAlert_Clicked), this);
	using FunctionType = decltype(FLAlert_Clicked(layer, btn2))(*)(CommentCell*, FLAlertLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x255540, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer, btn2);
}

auto CommentCell::incrementDislikes() -> decltype(incrementDislikes()) {
	using FunctionType = decltype(incrementDislikes())(*)(CommentCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x255330, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CommentCell::incrementLikes() -> decltype(incrementLikes()) {
	using FunctionType = decltype(incrementLikes())(*)(CommentCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x255280, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CommentCell::loadFromComment(GJComment* comment) -> decltype(loadFromComment(comment)) {
	using FunctionType = decltype(loadFromComment(comment))(*)(CommentCell*, GJComment*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2477c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, comment);
}

auto CommentCell::onConfirmDelete(cocos2d::CCObject* sender) -> decltype(onConfirmDelete(sender)) {
	using FunctionType = decltype(onConfirmDelete(sender))(*)(CommentCell*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x254fd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto CommentCell::onDelete() -> decltype(onDelete()) {
	using FunctionType = decltype(onDelete())(*)(CommentCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2554b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CommentCell::onGoToLevel(cocos2d::CCObject* sender) -> decltype(onGoToLevel(sender)) {
	using FunctionType = decltype(onGoToLevel(sender))(*)(CommentCell*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x254e10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto CommentCell::onLike(cocos2d::CCObject* sender) -> decltype(onLike(sender)) {
	using FunctionType = decltype(onLike(sender))(*)(CommentCell*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x254ee0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto CommentCell::onUndelete() -> decltype(onUndelete()) {
	using FunctionType = decltype(onUndelete())(*)(CommentCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x255520, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CommentCell::onUnhide(cocos2d::CCObject* sender) -> decltype(onUnhide(sender)) {
	using FunctionType = decltype(onUnhide(sender))(*)(CommentCell*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x254ec0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto CommentCell::onViewProfile(cocos2d::CCObject* sender) -> decltype(onViewProfile(sender)) {
	using FunctionType = decltype(onViewProfile(sender))(*)(CommentCell*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x254de0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto CommentCell::updateBGColor(int index) -> decltype(updateBGColor(index)) {
	using FunctionType = decltype(updateBGColor(index))(*)(CommentCell*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x249640, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}

auto CommentCell::updateLabelValues() -> decltype(updateLabelValues()) {
	using FunctionType = decltype(updateLabelValues())(*)(CommentCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x255400, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
