
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/ChallengeNode.hpp>
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

ChallengeNode::~ChallengeNode() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(ChallengeNode*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x39e930, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) ChallengeNode(geode::CutoffConstructor, sizeof(ChallengeNode));
		geode::DestructorLock::addLock(this);
	}
}

auto ChallengeNode::create(GJChallengeItem* challengeItem, ChallengesPage* challengesPage, bool isNew) -> decltype(create(challengeItem, challengesPage, isNew)) {
	using FunctionType = decltype(create(challengeItem, challengesPage, isNew))(*)(GJChallengeItem*, ChallengesPage*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39e430, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(challengeItem, challengesPage, isNew);
}

auto ChallengeNode::init(GJChallengeItem* challengeItem, ChallengesPage* challengesPage, bool isNew) -> decltype(init(challengeItem, challengesPage, isNew)) {
	using FunctionType = decltype(init(challengeItem, challengesPage, isNew))(*)(ChallengeNode*, GJChallengeItem*, ChallengesPage*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39ea00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, challengeItem, challengesPage, isNew);
}

auto ChallengeNode::onClaimReward(cocos2d::CCObject* sender) -> decltype(onClaimReward(sender)) {
	using FunctionType = decltype(onClaimReward(sender))(*)(ChallengeNode*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39f600, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto ChallengeNode::updateTimeLabel(gd::string text) -> decltype(updateTimeLabel(text)) {
	using FunctionType = decltype(updateTimeLabel(text))(*)(ChallengeNode*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39e500, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, text);
}
