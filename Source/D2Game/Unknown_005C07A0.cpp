#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"

struct D2MonStats2Txt;
struct D2ModeChangeStrc;
struct D2SeedStrc;

struct D2GameStrc { char unk0x00[0xA8]; int dwGameFrame; };



struct D2MonStats2Txt { char unk0x00[0x10B]; unsigned char nResurrectMode; };

struct D2DataTablesStrc { char unk0x00[0xA80]; int nMonStatsTxtRecordCount; };

struct D2ModeChangeStrc
{
    int nMode;
    D2UnitStrc* pUnit;
    D2UnitStrc* pTargetUnit;
    int nX;
    int nY;
    int unk0x14;
    int unk0x18;
    int unk0x1C;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nType, int nId); // 0x00540E60
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nType, int nExpire, int nId, int nParam); // 0x005417D0
D2AiControlStrc* __fastcall AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit); // 0x00541860
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nType, int nGUID); // 0x00552F60
void __fastcall sub_6FCBDD30(D2UnitStrc* pUnit, unsigned char nAlignNew, int a3); // 0x005543B0
void __fastcall MONSTER_UpdateAiCallbackEvent(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00573780
void __fastcall AIGENERAL_SetOwnerData(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOwnerGUID, int nOwnerType, int nFlag1, int nFlag2); // 0x0058F030
void __fastcall D2GAME_BOSSES_AssignUMod_6FC6FF10(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique); // 0x005A4850
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pMode, int a3); // 0x005A7C20
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pMode); // 0x005A7E60
void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAI, int nSpecialState); // 0x005B0E00
void __fastcall D2GAME_UpdateSummonAI_6FC401F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int nNode); // 0x005B1900
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nMode, int a7, int a8); // 0x005B2F20
void __fastcall AIUTIL_SetOwnerGUIDAndType(D2UnitStrc* pUnit, D2UnitStrc* pOwner); // 0x005DD330
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x00620210
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0
void __stdcall PATH_SetStepNum(D2DynamicPathStrc* pPath, unsigned char nStep); // 0x00649070
int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit); // 0x00649180
void __stdcall COLLISION_ResetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nPattern, int nMask); // 0x0064EC10

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
};

enum D2C_SkillItemConstants
{
    MONTYPEFLAG_UNIQUE_CHAMPION = 12,
    UNITEVENT_13 = 13,
};

typedef int (__fastcall* D2UnitEventCallbackFunction)(D2GameStrc* pGame, int nUnitEvent, D2UnitStrc* pUnit, D2UnitStrc* pEventSourceUnit, D2DamageStrc* pDamage, int nGUID1, int nGUID2);

int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180
int __fastcall sub_005C07A0_UnitEventCallback(D2GameStrc* pGame, int nUnitEvent, D2UnitStrc* pUnit, D2UnitStrc* pEventSourceUnit, D2DamageStrc* pDamage, int nGUID1, int nGUID2); // 0x005C07A0
D2UnitEventStrc* __fastcall SUNITEVENT_Register(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitEvent, int nGUID1, int nGUID2, D2UnitEventCallbackFunction pCallback, unsigned int nQueueNo, int a8); // 0x005C0AD0
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500

inline int UNIT_GetUnitType(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwUnitType : 6;
}

static __forceinline int sub_GetUnitTypeChecked(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwUnitType;
    }
    return 6;
}

static __forceinline int sub_GetUnitGUIDChecked(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwUnitId;
    }
    return -1;
}

// 0x005C07A0
int __fastcall sub_005C07A0_ReanimateMonster(D2GameStrc* pGame, int nUnusedRegister, D2UnitStrc* pCorpse, int nUnused1, int nUnused2, int nMonsterId, int nOwnerGUID)
{
    D2UnitStrc* pOwner = 0;
    if (UNIT_GetUnitType(pCorpse) == 1)
    {
        pOwner = SUNIT_GetServerUnit(pGame, 0, nOwnerGUID);
    }

    if (!pOwner)
    {
        return 0;
    }

    if (!D2COMMON_11017_CheckUnitIfConsumeable(pCorpse, 0) || nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return 0;
    }

    const int nX = CLIENTS_GetUnitX(pCorpse);
    const int nY = CLIENTS_GetUnitY(pCorpse);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pCorpse);
    pRoom = D2GAME_GetRoom_6FC52070(pRoom, nX, nY);
    if (!pRoom)
        return 0;
    D2MonStats2Txt* pMonStats2 = UNITS_GetMonStats2TxtRecordFromMonsterId(nMonsterId);
    if (!pMonStats2)
        return 0;
    COLLISION_ResetMaskWithPattern(UNITS_GetRoom(pCorpse), CLIENTS_GetUnitX(pCorpse), CLIENTS_GetUnitY(pCorpse), PATH_GetUnitCollisionPattern(pCorpse), 0x8000);
    D2UnitStrc* pPet = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nMonsterId, 1, -1, 74);
    if (!pPet)
        return 0;
    pPet->dwFlags |= 0x0402000E;
    AITHINK_ExecuteAiFn(pGame, pPet, AIGENERAL_GetAiControlFromUnit(pPet), 0);
    MONSTER_UpdateAiCallbackEvent(pGame, pPet);
    AIGENERAL_SetOwnerData(pGame, pPet, sub_GetUnitGUIDChecked(pOwner), sub_GetUnitTypeChecked(pOwner), 0, 0);
    AIUTIL_SetOwnerGUIDAndType(pPet, pOwner);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pPet, 2, 0);
    EVENT_SetEvent(pGame, pPet, 2, pGame->dwGameFrame + 25, 0, 0);
    sub_6FCBDD30(pPet, 2, 0);
    pPet->dwFlags |= 0x80000000;
    STATES_ToggleState(pPet, 96, 1);
    D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pPet, 21, 0);
    EVENT_SetEvent(pGame, pPet, 7, pGame->dwGameFrame + 1500, 0, 0);
    D2GAME_UpdateSummonAI_6FC401F0(pGame, pPet, 0, pOwner->dwNodeIndex);
    D2Common_10214(pPet);
    if (pMonStats2->nResurrectMode == 14)
    {
        D2ModeChangeStrc modeChange;
        MONSTERMODE_GetModeChangeInfo(pPet, 14, &modeChange);
        UNITS_SetUsedSkill(pPet, SKILLS_GetSkillById(pPet, 158, -1));
        PATH_SetStepNum(pPet->pDynamicPath, 1);
        modeChange.pTargetUnit = 0;
        modeChange.nX = nX;
        modeChange.nY = nY;
        D2GAME_ModeChange_6FC65220(pGame, &modeChange, 0);
    }
    STATES_ToggleState(pPet, 118, 1);
    STATES_ToggleState(pCorpse, 173, 1);
    return 1;
}

static inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return UNIT_INVALID;
    }

    return pUnit->dwUnitType;
}

// 0x005C09E0
int __fastcall sub_005C09E0_SkillItemEventFunc_Reanimate(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit || sub_0044BE50(pUnit) != UNIT_MONSTER)
    {
        return 0;
    }

    if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_UNIQUE_CHAMPION))
    {
        return 0;
    }

    const int nChance = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nChance <= 0)
    {
        return 0;
    }

    if (ITEMS_RollLimitedRandomNumber(&pAttacker->pSeed, 100) >= nChance)
    {
        return 0;
    }

    while (pAttacker)
    {
        if (sub_0044BE50(pAttacker) == UNIT_PLAYER)
        {
            const int nOwnerId = pAttacker->dwUnitId;
            D2UnitStrc* pEventUnit = static_cast<D2UnitStrc* const volatile&>(pUnit);
            D2GameStrc* pOwnerGame = static_cast<D2GameStrc* const volatile&>(pGame);
            SUNITEVENT_Register(pOwnerGame, pEventUnit, UNITEVENT_13, static_cast<unsigned short>(nSkillId), nOwnerId, sub_005C07A0_UnitEventCallback, 0, nOwnerId);
            return 1;
        }

        pAttacker = AIGENERAL_GetMinionOwner(pAttacker);
    }

    return 0;
}
