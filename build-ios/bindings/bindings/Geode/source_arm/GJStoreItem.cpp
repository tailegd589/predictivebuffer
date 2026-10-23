
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJStoreItem.hpp>
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

auto GJStoreItem::create(int index, int typeID, int unlockType, int price, ShopType shopType) -> decltype(create(index, typeID, unlockType, price, shopType)) {
	using FunctionType = decltype(create(index, typeID, unlockType, price, shopType))(*)(int, int, int, int, ShopType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5875c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(index, typeID, unlockType, price, shopType);
}

auto GJStoreItem::getCurrencyKey() -> decltype(getCurrencyKey()) {
	using FunctionType = decltype(getCurrencyKey())(*)(GJStoreItem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58b40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJStoreItem::init(int index, int typeID, int unlockType, int price, ShopType shopType) -> decltype(init(index, typeID, unlockType, price, shopType)) {
	using FunctionType = decltype(init(index, typeID, unlockType, price, shopType))(*)(GJStoreItem*, int, int, int, int, ShopType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x811b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index, typeID, unlockType, price, shopType);
}
