#include "D2Game.h"
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
struct Skills;
union D2SeedStrc;
struct D2StaticPathStrc;
struct D2SkillsTxt;

struct Unit { char pad0[0xC4]; unsigned flags; };

struct Skills { char pad0[0xE6]; short overlay; char padE8[0x154]; };

struct Tables { char pad0[0xB98]; Skills* skills; void* linker; int skillCount; char padBA4[0x1C]; int overlayCount; };
int __stdcall sub_006444A0(Skill*); // 0x006444A0
int __stdcall sub_006444D0(Skill*); // 0x006444D0
int __stdcall sub_00644500(Skill*); // 0x00644500
int __stdcall sub_00644530(Skill*); // 0x00644530
Room* __fastcall sub_00463740(Room*,int,int); // 0x00463740
Unit* __fastcall sub_005B2F20(Game*,Room*,int,int,int,int,int,int); // 0x005B2F20
void __stdcall sub_00621CE0(Unit*,Unit*); // 0x00621CE0
void __stdcall sub_00621E40(Unit*,int,int); // 0x00621E40

enum { MINION_FLAGS = 0x4020000 };

union D2SeedStrc
{
    struct
    {
        unsigned int nLowSeed;
        unsigned int nHighSeed;
    };
    unsigned __int64 lSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    unsigned char unk_10[0x10];
    D2SeedStrc pSeed;
    char unk0x28[0x04];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0xC4 - 0x30];
    unsigned int dwFlags;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    unsigned char unk_20[0x4D];
    unsigned char nDifficulty;
    unsigned char unk_6E[0x3A];
    int dwGameFrame;
};

D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0
void __stdcall D2Common_10235_PATH_UpdateRiderPath(D2UnitStrc* pRiderUnit, D2UnitStrc* pMountUnit); // 0x006505E0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList); // 0x006277E0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0

struct D2StaticPathStrc
{
    int unk0x00[3];
    int nXPos;
    int nYPos;
};

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int a7, int a8); // 0x005B2F20
void __fastcall AITACTICS_Idle(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE0F0
void __stdcall UNITS_StoreOwner(D2UnitStrc* pUnit, D2UnitStrc* pOwner); // 0x00621CE0

enum D2C_SkillsTxtFlagIndices
{
    SKILLSFLAGINDEX_PROGRESSIVE = 2,
};

struct D2SkillsTxt
{
    char unk0x000[0x04];
    unsigned char nFlags[8];
    char unk0x00C[0x2C];
    unsigned int dwPrgCalc[3];
    unsigned char nPrgDamage;
    char unk0x045[0xF];
    short wAuraStat[6];
    unsigned int dwAuraLenCalc;
    unsigned int dwAuraRangeCalc;
    unsigned int dwAuraStatCalc[6];
    short nAuraState;
    unsigned char unk_82[0x86];
    short wTgtOverlay;
    char unk0x10A[0x2E];
    unsigned int dwCalc[4];
    unsigned char unk_148[0x5D];
    unsigned char nSrcDam;
    unsigned char unk_1A6[0x36];
    unsigned char nEType;
    char unk0x1DD[0x5F];
};

struct D2DataTablesStrc
{
    char unk0x000[0xC4];
    int nStatesTxtRecordCount;
    unsigned char unk_C8[0xA4];
    short* pProgressiveStates;
    short nProgressiveStates;
    char unk0x172[0xA26];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
    char unk0xBA4[0x1C];
    int nOverlayTxtRecordCount;
    char unk0xBC4[0x10];
    int nItemStatCostTxtRecordCount;
};

extern unsigned int gdwBitMasks[]; // 0x006CE268
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus); // 0x00622C40
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int dwPhysDamage;
    int dwEnDmgPct;
    int unk0x10[8];
    int dwColdLen;
    int dwFrzLen;
    unsigned char unk_38[0x38];
};

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0
void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150
void __stdcall D2COMMON_10476(D2StatListStrc* pStatList, int nExpireFrame); // 0x006260B0
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __stdcall STATES_ToggleGfxStateFlag(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639E30
int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x006449F0
unsigned short __fastcall SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int nRangeOffset); // 0x0057EC10
void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, unsigned char nFlags); // 0x0057DBF0
D2DamageStrc* __fastcall SUNITDMG_GetDamageFromUnits(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x0057D690
void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4); // 0x0057D4F0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3); // 0x00621E40
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
void __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
void __fastcall sub_0056C8E0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nElementalType, int nDamage, int nElementalLength, int* pStatId, int* pElementalType); // 0x0056C8E0
void __stdcall sub_005D3790_ProgressiveLeech(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2DamageStrc* pDamage); // 0x005D3790
void __stdcall sub_005D3880_ProgressiveElemental(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2DamageStrc* pDamage); // 0x005D3880

inline Skills* GetSkills(int skillId)
{
    if(skillId>=0 && skillId<tables->skillCount) return &tables->skills[skillId];
    return 0;
}

// 0x005D2490
int __fastcall sub_005D2490(Game* game,Unit* unit,int skillId,int level)
{
    Skills* record=GetSkills(skillId);
    if(!record) return 0;
    Skill* skill=sub_00620250(unit);
    if(!skill) return 0;
    int monsterId=sub_006444A0(skill);
    int x=sub_006444D0(skill);
    int y=sub_00644500(skill);
    int mode=sub_00644530(skill);
    Room* room=sub_00463740(sub_00620BB0(unit),x,y);
    if(!room) return 0;
    Unit* monster=sub_005B2F20(game,room,x,y,monsterId,mode,-1,0);
    if(!monster) {
        monster=sub_005B2F20(game,room,x,y,monsterId,mode,4,0);
        if(!monster) return 0;
    }
    monster->flags |= MINION_FLAGS;
    sub_00621CE0(monster,unit);
    if(record->overlay>=0 && record->overlay<tables->overlayCount) sub_00621E40(monster,record->overlay,0);
    return 1;
}

// 0x005D2B20
int __fastcall sub_005D2B20(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pUnit);
    if (pOwner)
    {
        D2Common_10235_PATH_UpdateRiderPath(pUnit, pOwner);
    }
    return 1;
}

// 0x005D2B40
static __forceinline void sub_005D2B40_RemoveState114(D2UnitStrc* pUnit)
{
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0x72);
    if (pStatList)
    {
        D2Common_10474(pUnit, pStatList);
        STATLIST_FreeStatList(pStatList);
    }
}

void __stdcall sub_M121_Emit_005D2B40(D2UnitStrc* pUnit) { sub_005D2B40_RemoveState114(pUnit); }

static __forceinline int CLIENTS_GetUnitXForceInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static __forceinline int CLIENTS_GetUnitYForceInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x005D2C20
int __fastcall SKILLS_SrvDo140_BaalTentacle(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!pUnit)
    {
        return 0;
    }

    unsigned __int64 lSeed;
    const int nMinionCount = pGame->nDifficulty + SKILLS_ROLL_SEED(&pUnit->pSeed, lSeed) % 3 + 2;

    int nMinionSpawnMode;
    int nMinionId;
    int nMinionX;
    int nMinionY;
    MONSTERS_GetMinionSpawnInfo(pUnit, &nMinionId, &nMinionX, &nMinionY, &nMinionSpawnMode, pGame->nDifficulty, 0);

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    const int nX = pTarget ? CLIENTS_GetUnitXForceInline(pTarget) : CLIENTS_GetUnitXForceInline(pUnit);
    const int nY = pTarget ? CLIENTS_GetUnitYForceInline(pTarget) : CLIENTS_GetUnitYForceInline(pUnit);

    for (int i = 0; i < nMinionCount; ++i)
    {
        nMinionX = nX + SKILLS_ROLL_SEED(&pUnit->pSeed, lSeed) % 18 - 9;
        nMinionY = nY + SKILLS_ROLL_SEED(&pUnit->pSeed, lSeed) % 18 - 9;

        D2ActiveRoomStrc* pRoom = D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pUnit), nMinionX, nMinionY);
        if (pRoom)
        {
            D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pUnit), nMinionX, nMinionY);
            D2UnitStrc* pMinion = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nMinionX, nMinionY, nMinionId, nMinionSpawnMode, -1, 0);
            if (pMinion)
            {
                pMinion->dwFlags |= 0x4020000;
                AITACTICS_Idle(pGame, pMinion, 15);
                UNITS_StoreOwner(pMinion, pUnit);
            }
        }
    }

    return 1;
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005D32F0
int __fastcall SKILLS_SrvSt23_AssasinChargeStrikes(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTargetUnit = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTargetUnit)
    {
        return 0;
    }

    return UNITS_IsInMeleeRange(pUnit, pTargetUnit, 0);
}

// 0x005D3DA0
int __fastcall SKILLS_EvaluateProgressiveSkillCalc(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (!(pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_PROGRESSIVE >> 3] & gdwBitMasks[SKILLSFLAGINDEX_PROGRESSIVE & 7]))
    {
        return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPrgCalc[0], nSkillId, nSkillLevel);
    }

    if (pSkillsTxtRecord->nAuraState >= 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount)
    {
        if (pSkillsTxtRecord->wAuraStat[0] < 0 || pSkillsTxtRecord->wAuraStat[0] >= sgptDataTables->nItemStatCostTxtRecordCount)
        {
            return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPrgCalc[0], nSkillId, nSkillLevel);
        }

        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
        if (!pStatList)
        {
            return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPrgCalc[0], nSkillId, nSkillLevel);
        }

        int nIndex = STATLIST_GetStatValue(pStatList, pSkillsTxtRecord->wAuraStat[0], 0);
        nIndex = D2_MIN(D2_MAX(nIndex, 1), 3);
        return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPrgCalc[nIndex - 1], nSkillId, nSkillLevel);
    }

    return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPrgCalc[0], nSkillId, nSkillLevel);
}

// 0x005D3310
void __fastcall sub_004C21E0_StatRemoveCallback_ToggleStateOff(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    STATES_ToggleState(pUnit, nState, 0);
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x005D3320
static int __stdcall sub_005D3320_ApplyChargeState(D2GameStrc* pGame, int nSkillId, int nSkillLevel, int nAuraState, int nAuraStat, D2UnitStrc* pUnit)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nLength = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    const int nExpireFrame = pGame->dwGameFrame + nLength;
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nAuraState);
    if (!pStatList)
    {
        pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nExpireFrame, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
        if (!pStatList)
        {
            return 0;
        }

        STATLIST_SetState(pStatList, nAuraState);
        STATLIST_SetStatRemoveCallback(pStatList, SKILLS_StatRemoveCallback_ProgressiveStrike);
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        STATLIST_SetStat(pStatList, 350, nSkillId, 0);
        STATLIST_SetStat(pStatList, 351, nSkillLevel, 0);
    }

    D2COMMON_10476(pStatList, nExpireFrame);
    EVENT_SetEvent(pGame, pUnit, 12, nExpireFrame, 0, 0);

    const int nOldValue = STATLIST_GetStatValue(pStatList, nAuraStat, 0);
    int nNewValue = nOldValue + 1;
    if (nNewValue > 3)
    {
        nNewValue = 3;
    }

    if (nOldValue != nNewValue)
    {
        STATLIST_SetStat(pStatList, nAuraStat, nNewValue, 0);
        const short nAuraStat1 = pSkillsTxtRecord->wAuraStat[1];
        if (nAuraStat1 >= 0 && nAuraStat1 < sgptDataTables->nItemStatCostTxtRecordCount)
        {
            const int nValue = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[1], nSkillId, nSkillLevel);
            STATLIST_AddStat(pStatList, nAuraStat1, nValue, 0);
        }

        STATES_ToggleState(pUnit, nAuraState, 1);
        STATES_ToggleGfxStateFlag(pUnit, nAuraState, 1);
    }

    return 1;
}

int __fastcall SKILLS_SrvDo034_TigerStrike_CobraStrike_RoyalStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    if (pSkillsTxtRecord->wAuraStat[0] < 0 || pSkillsTxtRecord->wAuraStat[0] >= sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return 0;
    }

    D2DamageStrc damage = {};
    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel), 0);

    unsigned char nSrcDam = pSkillsTxtRecord->nSrcDam;
    if (!pSkillsTxtRecord->nSrcDam)
    {
        nSrcDam = 0x80;
    }
    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, nSrcDam);

    D2DamageStrc* pDamage = SUNITDMG_GetDamageFromUnits(pUnit, pTarget);
    if (pDamage && pDamage->wResultFlags & 1)
    {
        sub_005D3320_ApplyChargeState(pGame, nSkillId, nSkillLevel, pSkillsTxtRecord->nAuraState, pSkillsTxtRecord->wAuraStat[0], pUnit);
    }

    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    return 1;
}

inline int SKILLS_GetProgressiveState(int nIndex)
{
    return sgptDataTables->pProgressiveStates[nIndex];
}

// 0x005D3680
static void __stdcall sub_005D3680_ApplyProgressiveDamage(D2StatListStrc* pStatList, D2DamageStrc* pDamage, D2UnitStrc* pUnit)
{
    const int nSkillId = STATLIST_GetStatValue(pStatList, 350, 0);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    int nSkillLevel = STATLIST_GetStatValue(pStatList, 351, 0);
    const int nMaxLevel = SKILLS_GetSkillLevel(pUnit, SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId), 1);
    if (nMaxLevel > nSkillLevel)
    {
        nSkillLevel = nMaxLevel;
    }

    if (nSkillLevel <= 0)
    {
        return;
    }

    if (pSkillsTxtRecord->wAuraStat[0] < 0 || pSkillsTxtRecord->wAuraStat[0] >= sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return;
    }

    int nValue = STATLIST_GetStatValue(pStatList, pSkillsTxtRecord->wAuraStat[0], 0);
    if (nValue <= 0)
    {
        return;
    }

    nValue *= SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    pDamage->dwEnDmgPct += nValue;

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(SUNIT_GetGameFromUnit(pUnit), pUnit);
    if (pTarget && pSkillsTxtRecord->wTgtOverlay > 0 && pSkillsTxtRecord->wTgtOverlay < sgptDataTables->nOverlayTxtRecordCount)
    {
        UNITS_SetOverlay(pTarget, pSkillsTxtRecord->wTgtOverlay, 0);
    }
}

void __fastcall sub_005D3AC0(D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    if (!pDamage || !(pDamage->wResultFlags & 1))
    {
        return;
    }

    for (int i = 0; i < sgptDataTables->nProgressiveStates; ++i)
    {
        if (STATES_CheckState(pUnit, SKILLS_GetProgressiveState(i)))
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, SKILLS_GetProgressiveState(i));
            if (pStatList)
            {
                const int nSkillId = STATLIST_GetStatValue(pStatList, 350, 0);
                if (nSkillId > 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
                {
                    D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
                    if (pSkillsTxtRecord)
                    {
                        switch (pSkillsTxtRecord->nPrgDamage)
                        {
                        case 1:
                            sub_005D3680_ApplyProgressiveDamage(pStatList, pDamage, pUnit);
                            break;
                        }
                    }
                }
            }
        }
    }
}

// 0x005D3970
static void __stdcall sub_6FCF5BC0(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2DamageStrc* pDamage)
{
    const int nSkillId = STATLIST_GetStatValue(pStatList, 350, 0);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    int nSkillLevel = STATLIST_GetStatValue(pStatList, 351, 0);
    const int nLevel = SKILLS_GetSkillLevel(pUnit, SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId), 1);
    if (nLevel > nSkillLevel)
    {
        nSkillLevel = nLevel;
    }

    if (nSkillLevel <= 0)
    {
        return;
    }

    if (pSkillsTxtRecord->wAuraStat[0] < 0 || pSkillsTxtRecord->wAuraStat[0] >= sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return;
    }

    const int nValue = STATLIST_GetStatValue(pStatList, pSkillsTxtRecord->wAuraStat[0], 0);
    if (nValue <= 0)
    {
        return;
    }

    D2GAME_RollElementalDamage_6FD14DD0(pUnit, pDamage, nSkillId, nSkillLevel);
    if (pSkillsTxtRecord->nEType == 4 && nValue == 3)
    {
        const int nDivisor = sub_004E6C70(nSkillId);
        if (nDivisor)
        {
            pDamage->dwFrzLen += pDamage->dwColdLen / nDivisor;
        }
    }

    pDamage->wResultFlags |= 0x4000;

    int nPercentage = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nPercentage > 0)
    {
        if (nPercentage >= 100)
        {
            nPercentage = 100;
        }

        const int nBaseDamage = pDamage->dwPhysDamage;
        int nDamage = DATATBLS_ApplyRatio(nBaseDamage, nPercentage, 100);
        if (nDamage >= nBaseDamage)
        {
            nDamage = nBaseDamage;
        }

        pDamage->dwPhysDamage = nBaseDamage - nDamage;
        sub_0056C8E0(pUnit, pDamage, pSkillsTxtRecord->nEType, nDamage, 0, 0, 0);
    }
}

void __fastcall sub_6FCF5870(D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    if (!pDamage || !(pDamage->wResultFlags & 1))
    {
        return;
    }

    for (int i = 0; i < sgptDataTables->nProgressiveStates; ++i)
    {
        if (STATES_CheckState(pUnit, SKILLS_GetProgressiveState(i)))
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, SKILLS_GetProgressiveState(i));
            if (pStatList)
            {
                const int nSkillId = STATLIST_GetStatValue(pStatList, 350, 0);
                if (nSkillId > 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
                {
                    D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
                    if (pSkillsTxtRecord)
                    {
                        switch (pSkillsTxtRecord->nPrgDamage)
                        {
                        case 2:
                            sub_005D3790_ProgressiveLeech(pUnit, pStatList, pDamage);
                            break;
                        case 3:
                            sub_005D3880_ProgressiveElemental(pUnit, pStatList, pDamage);
                            break;
                        case 4:
                            sub_6FCF5BC0(pUnit, pStatList, pDamage);
                            break;
                        }
                    }
                }
            }
        }
    }
}
