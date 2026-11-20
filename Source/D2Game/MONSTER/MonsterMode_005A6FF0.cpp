#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk_20[0x4D];
    unsigned char nDifficulty;
    char unk_6E[6];
    int dwGameType;
    char unk_78[0x78];
    void* pMonsterRegion;
};
struct D2DynamicPathStrc;
struct D2HoverTextStrc;
struct D2UnitStrc;
struct D2ActiveRoomStrc;
struct D2ActiveRoomStrc { char unk_00[0x74]; D2UnitStrc* pUnitFirst; };
struct D2MonStatsTxt
{
    short unk_00;
    short nBaseId;
    char unk_04[0xA];
    unsigned char nFlags;
    char unk_0F[0x199];
};
struct D2ModeChangeStrc
{
    int unk0x00;
    D2UnitStrc* pUnit;
    int unk0x08[3];
    unsigned char nDirection;
};
extern D2DataTablesStrc* sgptDataTables;                                                                     // 0x00744304
void __stdcall CHAT_FreeHoverMsg(void* pMemoryPool, D2HoverTextStrc* pHoverText);                            // 0x006611A0
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit);                                                      // 0x0064C040
void __fastcall AIGENERAL_UpdateMinionList(D2UnitStrc* pUnit);                                               // 0x0058F6C0
void __fastcall TARGETS_RemoveUnitNode(D2GameStrc* pGame, D2UnitStrc* pUnit);                          // 0x005B1A90
void __stdcall D2Common_10469(D2UnitStrc* pUnit);                                                            // 0x00627540
int __stdcall MONSTERS_IsBoss(D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pMonster); // 0x0063E9F0
void __stdcall STATES_UpdateStayDeathFlags(D2UnitStrc* pUnit, int bIsBoss);                                  // 0x00639FB0
int __stdcall STATES_CheckStateMaskHideOnUnit(D2UnitStrc* pUnit);                                            // 0x0063A320
int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag);                                   // 0x004638A0
void __stdcall PATH_SetUnitDeadCollision(D2UnitStrc* pUnit, int bForGameLogic);                              // 0x00649F70
void __stdcall sub_006488A0_SetDirection(D2DynamicPathStrc* pPath, int nDirection);                          // 0x006488A0
void __fastcall sub_005738D0(D2GameStrc* pGame, D2UnitStrc* pMonster);                               // 0x005738D0
void __fastcall SUNIT_SetCombatMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode);                        // 0x00553570
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60

inline D2MonStatsTxt* GetMonStatsTxtRecord(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        const int nId = pUnit->dwClassId;
        if (nId >= 0 && nId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            return &sgptDataTables->pMonStatsTxt[nId];
        }
    }
    return 0;
}

static void __stdcall sub_6FC63E80(int nDirection, D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005A6520
// 0x005A6520
static void __stdcall sub_6FC63E80(int nDirection, D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->pHoverText)
    {
        CHAT_FreeHoverMsg(pGame->pMemoryPool, pUnit->pHoverText);
        pUnit->pHoverText = 0;
        UNITROOM_RefreshUnit(pUnit);
        pUnit->dwFlags |= 0x100;
    }

    AIGENERAL_UpdateMinionList(pUnit);
    D2MonStatsTxt* pMonStatsTxtRecord = GetMonStatsTxtRecord(pUnit);
    TARGETS_RemoveUnitNode(pGame, pUnit);
    if (pUnit)
    {
        pUnit->dwFlags &= 0xFFFF7FF3;
    }

    D2Common_10469(pUnit);
    STATES_UpdateStayDeathFlags(pUnit, MONSTERS_IsBoss(pMonStatsTxtRecord, pUnit));
    if (STATES_CheckStateMaskHideOnUnit(pUnit) && pUnit)
    {
        pUnit->dwFlags &= ~2;
    }

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (!sub_004638A0_CheckMonStats2Flag(pUnit->dwClassId, 0x13))
    {
        PATH_SetUnitDeadCollision(pUnit, 1);
    }

    sub_006488A0_SetDirection(pPath, nDirection);
    sub_005738D0(pGame, pUnit);
}

// 0x005A7390
int __fastcall sub_005A7390_MONSTERMODE_EndDeath(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    D2UnitStrc* pUnit = pModeChange->pUnit;
    if (pUnit && pUnit->dwAnimMode)
    {
        sub_6FC63E80(pModeChange->nDirection, pGame, pUnit);
    }

    SUNIT_SetCombatMode(pGame, pUnit, 12);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 8, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 9, 0);
    return 1;
}

struct D2DifficultyLevelsTxt { char unk_00[0x3C]; int nMonsterCorpseExplosionDamage; };
struct D2MonStatsInitStrc { int nMinHP; int nMaxHP; int unk_08[12]; };
struct D2DamageStrc { int dwHitFlags; unsigned short wResultFlags; unsigned short unk_06; int dwPhysDamage; int unk_0C[25]; };
extern const unsigned int gdwBitMasks[32]; // 0x006CE268
extern "C" void* __cdecl memset(void*, int, unsigned int);
void __fastcall sub_005A6830(D2GameStrc*, D2ModeChangeStrc*, int); // 0x005A6830
void __fastcall sub_00547E50_RemoveMonster(void*, D2UnitStrc*); // 0x00547E50
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
void __stdcall sub_0061AFA0_RemoveRoomUnit(D2ActiveRoomStrc*, int); // 0x0061AFA0
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc*, D2UnitStrc*); // 0x006416D0
int __stdcall sub_00622B50_IsRayFreeBetweenUnits(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, unsigned int nCollisionMask); // 0x00622B50
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*, int, int); // 0x00625480
int __stdcall STATES_CheckState(D2UnitStrc*, int); // 0x00639DF0
void __fastcall sub_0057C1E0_CalculateDamage(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, D2DamageStrc*); // 0x0057C1E0
void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int, D2DamageStrc*); // 0x0057C6C0
void __fastcall sub_0057CEE0_ApplyDamage(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, D2DamageStrc*); // 0x0057CEE0
void __stdcall sub_6FC64090(D2GameStrc*, D2UnitStrc*); // 0x005A6EB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc*); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc*); // 0x00648900
D2UnitStrc* __fastcall sub_6FD11420(D2GameStrc*, int, D2UnitStrc*, int, int, int, int, int, int, int); // 0x0056ECB0
D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int); // 0x00611D30
int __stdcall DATATBLS_CalculateMonsterStatsByLevel(int, int, int, int, short, D2MonStatsInitStrc*); // 0x006538A0
int __fastcall DATATBLS_ApplyRatio(int, int, int); // 0x00483360
int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc*, int); // 0x0045C3E0
int __fastcall SUNITDMG_SetMissileDamageFlagsForNearbyUnits(D2GameStrc*, D2UnitStrc*, int, int, int, D2DamageStrc*, int, int, void*, int); // 0x0057E090
__declspec(noinline) static void __stdcall sub_6FC63FD0(D2GameStrc* pGame, D2UnitStrc* pUnit);
static void __stdcall sub_6FC63FD0(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005A6DF0

// build: context sub_6FC63FD0
static void __stdcall sub_6FC63FD0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2UnitStrc* pTarget = UNITS_GetRoom(pUnit)->pUnitFirst;
    while (pTarget)
    {
        if (pTarget->dwUnitType == 0 && pTarget->dwAnimMode != 17 && sub_006416D0_UnitEdgeDistance(pUnit, pTarget) <= 2 && !sub_00622B50_IsRayFreeBetweenUnits(pTarget, pUnit, 0x3C01))
        {
            D2DamageStrc damage;
            memset(&damage, 0, sizeof(damage));
            damage.dwPhysDamage = STATLIST_UnitGetStatValue(pTarget, 6, 0) >> 5;
            damage.wResultFlags = 1;
            if (!STATES_CheckState(pTarget, 54)) damage.wResultFlags |= 4;
            sub_0057C1E0_CalculateDamage(pGame, pUnit, pTarget, &damage);
            SUNITDMG_ExecuteEvents(pGame, pUnit, pTarget, 1, &damage);
            sub_0057CEE0_ApplyDamage(pGame, pUnit, pTarget, &damage);
        }
        pTarget = pTarget->ptRoomNext;
    }
}
__forceinline D2MonStatsTxt* GetMonStatsById(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nMonStatsTxtRecordCount) return &sgptDataTables->pMonStatsTxt[nId];
    return 0;
}
__forceinline int GetBaseId(int nId)
{
    D2MonStatsTxt* pRecord = GetMonStatsById(nId);
    return pRecord ? pRecord->nBaseId : nId;
}
static __forceinline int GetUnitType(D2UnitStrc* pUnit)
{
    int nType = 6;
    if (pUnit) nType = pUnit->dwUnitType;
    return nType;
}
__forceinline int GetX(D2UnitStrc* pUnit)
{
    switch(GetUnitType(pUnit)) { case 2: case 4: case 5: return pUnit->pStaticPath->nXPos; }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}
__forceinline int GetY(D2UnitStrc* pUnit)
{
    switch(GetUnitType(pUnit)) { case 2: case 4: case 5: return pUnit->pStaticPath->nYPos; }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}
static __forceinline int HasCorpseExplosion(D2MonStatsTxt* pRecord)
{
    if (pRecord) return pRecord->nFlags & gdwBitMasks[4];
    return 0;
}
static __forceinline int GetValidBaseId(D2UnitStrc* pUnit)
{
    if (pUnit && GetUnitType(pUnit) == 1 && pUnit->dwClassId >= 0)
    {
        int nBaseId = GetBaseId(pUnit->dwClassId);
        if (nBaseId >= 0 && nBaseId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            return nBaseId;
        }
    }
    return -1;
}
// 0x005A6FF0
int __fastcall sub_005A6FF0_MonsterDeath(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    D2UnitStrc* pUnit = pModeChange->pUnit;
    SUNIT_SetCombatMode(pGame, pUnit, 0);
    sub_6FC63E80(pModeChange->nDirection, pGame, pUnit);
    sub_005A6830(pGame, pModeChange, 0);
    sub_00547E50_RemoveMonster(&pGame->pMonsterRegion, pUnit);
    int nUnitId;
    if (!pUnit) nUnitId = -1;
    else nUnitId = pUnit->dwUnitId;
    sub_0061AFA0_RemoveRoomUnit(UNITS_GetRoom(pUnit), nUnitId);
    D2MonStatsTxt* pMonStats = GetMonStatsTxtRecord(pUnit);
    if (!HasCorpseExplosion(pMonStats))
    {
        return 1;
    }

    switch (GetValidBaseId(pUnit))
    {
    default:
        sub_6FC63FD0(pGame, pUnit);
        return 1;
    case 441:
        sub_6FC64090(pGame, pUnit);
        return 1;
    case 212:
    {
        int nX = GetX(pUnit);
        int nY = GetY(pUnit);
        D2UnitStrc* pMissile = sub_6FD11420(pGame, 117, pUnit, 0, 1, 0, 0, nX, nY, 1);
        if (!pMissile) return 1;
        D2DifficultyLevelsTxt* pDifficulty = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty);
        if (!pDifficulty) return 1;
        D2MonStatsInitStrc stats;
        memset(&stats, 0, sizeof(stats));
        int nClassId = pUnit->dwClassId;
        DATATBLS_CalculateMonsterStatsByLevel(nClassId, pGame->dwGameType, pGame->nDifficulty, STATLIST_UnitGetStatValue(pUnit, 12, 0), 1, &stats);
        int nMaxDamage = DATATBLS_ApplyRatio(stats.nMaxHP, pDifficulty->nMonsterCorpseExplosionDamage, 100);
        int nMinDamage;
        if (nMaxDamage > 0x100000)
        {
            if ((nMaxDamage & -16) < 1600) nMinDamage = (int)((__int64)nMaxDamage * 60 / 100);
            else nMinDamage = 60 * (nMaxDamage / 100);
        }
        else nMinDamage = 60 * nMaxDamage / 100;
        D2DamageStrc damage;
        memset(&damage, 0, sizeof(damage));
        damage.dwPhysDamage = (ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nMaxDamage - nMinDamage) + nMinDamage) << 7;
        SUNITDMG_SetMissileDamageFlagsForNearbyUnits(pGame, pMissile, nX, nY, 5, &damage, 0, 0, 0, 0x581);
        break;
    }
    }
    return 1;
}
