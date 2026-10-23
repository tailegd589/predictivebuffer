#pragma once
#include <Geode/platform/platform.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>

#include <Geode/binding/CAState.hpp>
#include <Geode/binding/PulseEffectAction.hpp>
#include <Geode/binding/CountTriggerAction.hpp>
#include <Geode/binding/OpacityEffectAction.hpp>
#include <Geode/binding/TouchToggleAction.hpp>
#include <Geode/binding/CollisionTriggerAction.hpp>
#include <Geode/binding/ToggleTriggerAction.hpp>
#include <Geode/binding/SpawnTriggerAction.hpp>
#include <Geode/binding/GroupCommandObject2.hpp>
#include <Geode/binding/TimerItem.hpp>
#include <Geode/binding/TimerTriggerAction.hpp>
#include <Geode/mapping/unordered_map.hpp>
#include <Geode/mapping/unordered_set.hpp>
#include <Geode/mapping/vector.hpp>

class EffectManagerState {
public:
    static constexpr auto CLASS_NAME = "EffectManagerState";
    gd::vector<CAState> m_unkVecCAState;
    gd::vector<PulseEffectAction> m_unkVecPulseEffectAction;
    gd::unordered_map<int,gd::vector<PulseEffectAction>> m_unorderedMapInt_vectorPulseEffectAction;
    gd::unordered_map<int,gd::vector<CountTriggerAction>> m_unorderedMapInt_vectorCountTriggerAction;
    gd::unordered_set<int> m_unorderedSet_int1;
    gd::map<int,int> m_mapInt_Int;
    gd::unordered_map<int,OpacityEffectAction> m_unorderedMapInt_OpacityEffectAction;
    gd::vector<TouchToggleAction> m_vectorTouchToggleAction;
    gd::vector<CollisionTriggerAction> m_vectorCollisionTriggerAction;
    gd::vector<ToggleTriggerAction> m_vectorToggleTriggerAction;
    gd::vector<SpawnTriggerAction> m_vectorSpawnTriggerAction;
    gd::unordered_map<int,int> m_itemCountMap;
    gd::unordered_map<int,bool> m_unorderedMapInt_bool;
    gd::vector<GroupCommandObject2> m_vectorGroupCommandObject2;
    gd::unordered_map<int,std::pair<double,double>> m_unorderedMapInt_pair_double_double;
    gd::unordered_set<int> m_unorderedSet_int2;
    gd::unordered_map<int,TimerItem> m_timerItemMap;
    gd::unordered_map<int,gd::vector<TimerTriggerAction>> m_unorderedMapInt_vectorTimerTriggerAction;
};
