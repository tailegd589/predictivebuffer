
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCTextureAtlas.hpp>
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

cocos2d::CCTextureAtlas::CCTextureAtlas() : cocos2d::CCTextureAtlas(geode::CutoffConstructor, sizeof(cocos2d::CCTextureAtlas)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCTextureAtlas::~CCTextureAtlas();

	using FunctionType = void(*)(cocos2d::CCTextureAtlas*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4accb0, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCTextureAtlas::~CCTextureAtlas() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCTextureAtlas*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x4accf0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCTextureAtlas(geode::CutoffConstructor, sizeof(cocos2d::CCTextureAtlas));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCTextureAtlas::create(char const* p0, unsigned int p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(char const*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ace40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCTextureAtlas::createWithTexture(cocos2d::CCTexture2D* p0, unsigned int p1) -> decltype(createWithTexture(p0, p1)) {
	using FunctionType = decltype(createWithTexture(p0, p1))(*)(cocos2d::CCTexture2D*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4acf40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCTextureAtlas::getTotalQuads() -> decltype(getTotalQuads()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTextureAtlas::getTotalQuads), this);
	using FunctionType = decltype(getTotalQuads())(*)(cocos2d::CCTextureAtlas*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4acdb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTextureAtlas::getCapacity() -> decltype(getCapacity()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTextureAtlas::getCapacity), this);
	using FunctionType = decltype(getCapacity())(*)(cocos2d::CCTextureAtlas*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4acdc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTextureAtlas::getTexture() -> decltype(getTexture()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTextureAtlas::getTexture), this);
	using FunctionType = decltype(getTexture())(*)(cocos2d::CCTextureAtlas*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4acdd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTextureAtlas::setTexture(cocos2d::CCTexture2D* p0) -> decltype(setTexture(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTexture2D*>::func(&cocos2d::CCTextureAtlas::setTexture), this);
	using FunctionType = decltype(setTexture(p0))(*)(cocos2d::CCTextureAtlas*, cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4acde0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCTextureAtlas::getQuads() -> decltype(getQuads()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTextureAtlas::getQuads), this);
	using FunctionType = decltype(getQuads())(*)(cocos2d::CCTextureAtlas*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ace20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTextureAtlas::setQuads(cocos2d::ccV3F_C4B_T2F_Quad* p0) -> decltype(setQuads(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccV3F_C4B_T2F_Quad*>::func(&cocos2d::CCTextureAtlas::setQuads), this);
	using FunctionType = decltype(setQuads(p0))(*)(cocos2d::CCTextureAtlas*, cocos2d::ccV3F_C4B_T2F_Quad*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ace30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCTextureAtlas::description() -> decltype(description()) {
	using FunctionType = decltype(description())(*)(cocos2d::CCTextureAtlas*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ad860, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTextureAtlas::drawNumberOfQuads(unsigned int p0) -> decltype(drawNumberOfQuads(p0)) {
	using FunctionType = decltype(drawNumberOfQuads(p0))(*)(cocos2d::CCTextureAtlas*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ae680, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTextureAtlas::drawNumberOfQuads(unsigned int p0, unsigned int p1) -> decltype(drawNumberOfQuads(p0, p1)) {
	using FunctionType = decltype(drawNumberOfQuads(p0, p1))(*)(cocos2d::CCTextureAtlas*, unsigned int, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ae5a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCTextureAtlas::drawQuads() -> decltype(drawQuads()) {
	using FunctionType = decltype(drawQuads())(*)(cocos2d::CCTextureAtlas*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ae590, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTextureAtlas::fillWithEmptyQuadsFromIndex(unsigned int p0, unsigned int p1) -> decltype(fillWithEmptyQuadsFromIndex(p0, p1)) {
	using FunctionType = decltype(fillWithEmptyQuadsFromIndex(p0, p1))(*)(cocos2d::CCTextureAtlas*, unsigned int, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ae420, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCTextureAtlas::increaseTotalQuadsWith(unsigned int p0) -> decltype(increaseTotalQuadsWith(p0)) {
	using FunctionType = decltype(increaseTotalQuadsWith(p0))(*)(cocos2d::CCTextureAtlas*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ae2b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTextureAtlas::initWithFile(char const* p0, unsigned int p1) -> decltype(initWithFile(p0, p1)) {
	using FunctionType = decltype(initWithFile(p0, p1))(*)(cocos2d::CCTextureAtlas*, char const*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4acef0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCTextureAtlas::initWithTexture(cocos2d::CCTexture2D* p0, unsigned int p1) -> decltype(initWithTexture(p0, p1)) {
	using FunctionType = decltype(initWithTexture(p0, p1))(*)(cocos2d::CCTextureAtlas*, cocos2d::CCTexture2D*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4acfe0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCTextureAtlas::insertQuad(cocos2d::ccV3F_C4B_T2F_Quad* p0, unsigned int p1) -> decltype(insertQuad(p0, p1)) {
	using FunctionType = decltype(insertQuad(p0, p1))(*)(cocos2d::CCTextureAtlas*, cocos2d::ccV3F_C4B_T2F_Quad*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ad970, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCTextureAtlas::insertQuadFromIndex(unsigned int p0, unsigned int p1) -> decltype(insertQuadFromIndex(p0, p1)) {
	using FunctionType = decltype(insertQuadFromIndex(p0, p1))(*)(cocos2d::CCTextureAtlas*, unsigned int, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4adc00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCTextureAtlas::insertQuads(cocos2d::ccV3F_C4B_T2F_Quad* p0, unsigned int p1, unsigned int p2) -> decltype(insertQuads(p0, p1, p2)) {
	using FunctionType = decltype(insertQuads(p0, p1, p2))(*)(cocos2d::CCTextureAtlas*, cocos2d::ccV3F_C4B_T2F_Quad*, unsigned int, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ada20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCTextureAtlas::listenBackToForeground(cocos2d::CCObject* p0) -> decltype(listenBackToForeground(p0)) {
	using FunctionType = decltype(listenBackToForeground(p0))(*)(cocos2d::CCTextureAtlas*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ad840, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTextureAtlas::mapBuffers() -> decltype(mapBuffers()) {
	using FunctionType = decltype(mapBuffers())(*)(cocos2d::CCTextureAtlas*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ad880, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTextureAtlas::moveQuadsFromIndex(unsigned int p0, unsigned int p1) -> decltype(moveQuadsFromIndex(p0, p1)) {
	using FunctionType = decltype(moveQuadsFromIndex(p0, p1))(*)(cocos2d::CCTextureAtlas*, unsigned int, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ae3e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCTextureAtlas::moveQuadsFromIndex(unsigned int p0, unsigned int p1, unsigned int p2) -> decltype(moveQuadsFromIndex(p0, p1, p2)) {
	using FunctionType = decltype(moveQuadsFromIndex(p0, p1, p2))(*)(cocos2d::CCTextureAtlas*, unsigned int, unsigned int, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ae2d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCTextureAtlas::removeAllQuads() -> decltype(removeAllQuads()) {
	using FunctionType = decltype(removeAllQuads())(*)(cocos2d::CCTextureAtlas*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4adda0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTextureAtlas::removeQuadAtIndex(unsigned int p0) -> decltype(removeQuadAtIndex(p0)) {
	using FunctionType = decltype(removeQuadAtIndex(p0))(*)(cocos2d::CCTextureAtlas*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4adcf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTextureAtlas::removeQuadsAtIndex(unsigned int p0, unsigned int p1) -> decltype(removeQuadsAtIndex(p0, p1)) {
	using FunctionType = decltype(removeQuadsAtIndex(p0, p1))(*)(cocos2d::CCTextureAtlas*, unsigned int, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4add50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCTextureAtlas::resizeCapacity(unsigned int p0) -> decltype(resizeCapacity(p0)) {
	using FunctionType = decltype(resizeCapacity(p0))(*)(cocos2d::CCTextureAtlas*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4addb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTextureAtlas::setupIndices() -> decltype(setupIndices()) {
	using FunctionType = decltype(setupIndices())(*)(cocos2d::CCTextureAtlas*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ad420, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTextureAtlas::setupVBOandVAO() -> decltype(setupVBOandVAO()) {
	using FunctionType = decltype(setupVBOandVAO())(*)(cocos2d::CCTextureAtlas*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ad710, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTextureAtlas::updateQuad(cocos2d::ccV3F_C4B_T2F_Quad* p0, unsigned int p1) -> decltype(updateQuad(p0, p1)) {
	using FunctionType = decltype(updateQuad(p0, p1))(*)(cocos2d::CCTextureAtlas*, cocos2d::ccV3F_C4B_T2F_Quad*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ad910, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}
