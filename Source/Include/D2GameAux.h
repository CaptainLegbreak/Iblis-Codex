#pragma once
// Pets, summons, aura callbacks and their argument blocks, player trade, AI path positions and target nodes

#include "D2Check.h"
#include "D2Structs.h"
#include "D2ItemsWorld.h"
#include "D2Path.h"

struct D2GameStrc;
struct D2UnitStrc;
struct D2PlayerPetStrc;
struct D2PetListStrc;
struct D2PetDataStrc;
struct D2SummonArgStrc;
struct D2AuraCallbackStrc;
struct D2PlayerTradeStrc;
struct D2MapAIPathPositionStrc;
struct D2DamageStrc;
struct D2StatListStrc;
struct D2BasicAuraParamStrc;
struct D2DamageAuraParamStrc;
struct D2PetArgStrc;
struct D2TargetNodeStrc;

struct D2PlayerPetStrc
{
    D2PetListStrc* pPetList; // 0x00
};

struct D2PetListStrc
{
    D2PetDataStrc* pPetData; // 0x00
    int nCurrent; // 0x04
    int nMax; // 0x08
};

struct D2PetDataStrc
{
    unsigned int nFlags; // 0x00
    int nUnitGUID; // 0x04
    D2PetInfoStrc petInfo; // 0x08
    D2PetDataStrc* pNext; // 0x14
};

struct D2SummonArgStrc
{
    unsigned int dwFlags; // 0x00
    D2UnitStrc* pOwner; // 0x04
    int nHcIdx; // 0x08
    int nAiSpecialState; // 0x0C
    int nMonMode; // 0x10
    D2CoordStrc pPosition; // 0x14
    int nPetType; // 0x1C
    int nPetMax; // 0x20
};

struct D2AuraCallbackStrc
{
    D2GameStrc* pGame; // 0x00
    D2UnitStrc* pOwner; // 0x04
    int nCounter; // 0x08
    void* pArgs; // 0x0C
};

struct D2PlayerTradeStrc
{
    int nSaveLength; // 0x00
    unsigned char* pSaveData; // 0x04
    void* pItemTrade; // 0x08
    int nGoldInTrade; // 0x0C
    int nGoldInTradeOtherPlayer; // 0x10
    int nNextUpdateTick; // 0x14
};

struct D2MapAIPathPositionStrc
{
    int nMapAIAction; // 0x00
    int nX; // 0x04
    int nY; // 0x08
};

struct D2BasicAuraParamStrc
{
    int nAuraState; // 0x00
    int nSkillId; // 0x04
    int nSkillLevel; // 0x08
    int nDuration; // 0x0C
    int nAuraStat[6]; // 0x10
    int nAuraStatCalcValue[6]; // 0x28
    int unk0x40; // 0x40
    D2StatListStrc* pStatList; // 0x44
    int nPassiveState; // 0x48
    void* pStateRemoveCallback; // 0x4C
};

struct D2DamageAuraParamStrc
{
    int nAuraState; // 0x00
    int nSkillId; // 0x04
    int nSkillLevel; // 0x08
    int nDuration; // 0x0C
    int nAuraStat[6]; // 0x10
    int nAuraStatCalcValue[6]; // 0x28
    int unk0x40; // 0x40
    D2StatListStrc* pStatList; // 0x44
    int nPassiveState; // 0x48
    D2DamageStrc* pDamage; // 0x4C
};

struct D2PetArgStrc
{
    int nPetGUID; // 0x00
    int nUnitGUID; // 0x04
    unsigned short nPetClass; // 0x08
    unsigned short unk0x0A; // 0x0A
    int nPetType; // 0x0C
    int nSeed; // 0x10
    int nName; // 0x14
    int unk0x18; // 0x18
};

struct D2TargetNodeStrc
{
    D2UnitStrc* hUnit; // 0x00
    int nNodeData; // 0x04
    D2TargetNodeStrc* pNext; // 0x08
    D2TargetNodeStrc* pPrevious; // 0x0C
};

D2_CHECK_SIZE(D2PlayerPetStrc, 0x4);
D2_CHECK_SIZE(D2PetListStrc, 0xC);
D2_CHECK_SIZE(D2PetDataStrc, 0x18);
D2_CHECK_SIZE(D2SummonArgStrc, 0x24);
D2_CHECK_SIZE(D2AuraCallbackStrc, 0x10);
D2_CHECK_SIZE(D2PlayerTradeStrc, 0x18);
D2_CHECK_SIZE(D2MapAIPathPositionStrc, 0xC);
D2_CHECK_SIZE(D2BasicAuraParamStrc, 0x50);
D2_CHECK_SIZE(D2DamageAuraParamStrc, 0x50);
D2_CHECK_SIZE(D2PetArgStrc, 0x1C);
D2_CHECK_SIZE(D2TargetNodeStrc, 0x10);
