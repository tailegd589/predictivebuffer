
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/AchievementBar.hpp>
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

auto AchievementBar::create(char const* title, char const* desc, char const* icon, bool quest) -> decltype(create(title, desc, icon, quest)) {
	using FunctionType = decltype(create(title, desc, icon, quest))(*)(char const*, char const*, char const*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x53cf08, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(title, desc, icon, quest);
}

auto AchievementBar::setOpacity(unsigned char opacity) -> decltype(setOpacity(opacity)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned char>::func(&AchievementBar::setOpacity), this);
	using FunctionType = decltype(setOpacity(opacity))(*)(AchievementBar*, unsigned char);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x53e7d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, opacity);
}

auto AchievementBar::init(char const* title, char const* desc, char const* icon, bool quest) -> decltype(init(title, desc, icon, quest)) {
	using FunctionType = decltype(init(title, desc, icon, quest))(*)(AchievementBar*, char const*, char const*, char const*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x53cfd8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, title, desc, icon, quest);
}

auto AchievementBar::show() -> decltype(show()) {
	using FunctionType = decltype(show())(*)(AchievementBar*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x53e590, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
