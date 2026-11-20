#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"

#define DAMAGERESULTFLAG_SUCCESSFULHIT 1
#define SKILL_DIMVISION 71
#define UNITFLAG_SKSRVDOFUNC 0x40
#define ITEMSTATCOSTFLAGINDEX_UPDATEANIMRATE 9
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
#define STAT_HITPOINTS 6

struct D2CofDataStrc;
struct SMSGHANDLER_PARAMS;
struct D2UnkNecSkillStrc3;
struct D2StaticPathStrc;
struct D2CurseStrc;
struct D2UnkNecSkillStrc;
struct D2UnkNecSkillStrc2;
struct D2AuraCallbackStrc;
struct D2SkillsTxt;
struct D2WinImageClickRectStrc;
struct D2CofNodeStrc;
struct D2SummonArgStrc;
struct D2DifficultyLevelsTxt;
struct D2MonLvlTxt;
struct D2MonStatsTxt;
union D2SeedStrc;
struct D2MonStatsInitStrc;
struct D2ModeChangeStrc;
struct D2GameStrc;
struct D2UnitStrc;
struct D2DamageStrc;
struct D2DataTablesStrc;
struct Unit;
struct D2CoordStrc;
struct D2ItemStatCostTxt;




struct D2UnkNecSkillStrc3
{
    D2GameStrc* pGame;
    D2UnitStrc* pUnit;
    int nSkillId;
    int nSkillLevel;
    unsigned char nUnitType;
    unsigned char pad0x11;
    unsigned short pad0x12;
    int nUnitGUID;
    int nLength;
};

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
int __stdcall sub_00645680_CanUnitCorpseBeSelected(D2UnitStrc* pUnit); // 0x00645680
void __fastcall sub_6FCBDD30(D2UnitStrc* pUnit, unsigned char nAlignNew, int a3); // 0x005543B0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010
int __fastcall sub_005C31F0_IsValidAttractTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x005C31F0
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0



struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int dwPhysDamage;
    int dwEnDmgPct;
    int dwFireDamage;
    int dwBurnDamage;
    int dwBurnLen;
    int dwLtngDamage;
    int dwMagDamage;
    int dwColdDamage;
    int dwPoisDamage;
    int dwPoisLen;
    int dwColdLen;
    int dwFrzLen;
    int dwLifeLeech;
    int dwManaLeech;
    int dwStamLeech;
    int dwStunLen;
    int dwAbsLife;
    int dwDmgTotal;
    unsigned int unk0x50;
    int dwPiercePct;
    int dwDamageRate;
    unsigned int unk0x5C;
    int dwHitClass;
    unsigned char nHitClassActiveSet;
    signed char nConvType;
    unsigned short unk0x66;
    int dwConvPct;
    int nOverlay;
};

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

struct D2CurseStrc
{
    D2UnitStrc* pUnit;
    D2UnitStrc* pTarget;
    int nSkill;
    int nSkillLevel;
    int nDuration;
    int nStat;
    int nStatValue;
    int nState;
    StatListRemoveCallback pStateRemoveCallback;
};

struct D2UnkNecSkillStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pUnit;
    int unk0x08;
    int bUpdateAnimRate;
    int nSkillId;
    int nSkillLevel;
    int nDuration;
    int nAuraStat[6];
    int nAuraStatCalc[6];
    int nAuraTargetState;
    int nAuraEvent[3];
    int nAuraEventFunc[3];
};

struct D2UnkNecSkillStrc2
{
    D2DamageStrc* pDamage;
    int nX;
    int nY;
    int unk0x0C;
};

struct D2AuraCallbackStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pOwner;
    int nCounter;
    void* pArgs;
};

struct D2SkillsTxt
{
    char unk0x000[0x48];
    short wSrvMissileA;
    unsigned char unk_4A[0xA];
    short wAuraStat[6];
    unsigned int dwAuraLenCalc;
    char unk0x064[0x04];
    unsigned int dwAuraStatCalc[6];
    char unk0x080[0x02];
    short wAuraTargetState;
    char unk0x084[0x38];
    short wSummon;
    unsigned char nPetType;
    unsigned char nSumMode;
    unsigned int dwPetMax;
    unsigned char unk_C4[0x6A];
    unsigned short wResultFlags;
    unsigned int dwHitFlags;
    unsigned int dwHitClass;
    unsigned int dwCalc[4];
    char unk0x148[0x5D];
    unsigned char nSrcDam;
    char unk0x1A6[0x36];
    unsigned char nEType;
    char unk0x1DD[0x5F];
};


extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x006449F0
unsigned short __fastcall SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int nRangeOffset); // 0x0057EC10
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0
void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, unsigned char nFlags); // 0x0057DBF0
int __fastcall sub_005C3D50_IsValidTerrorTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x005C3D50
D2StatListStrc* __fastcall sub_0056E970(D2CurseStrc* pCurse); // 0x0056E970
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150
void __fastcall sub_6FC40280(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int a4); // 0x005B1990
void __fastcall sub_6FD0C2B0(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x005C3DB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __stdcall PATH_ComputeSquaredDistance(int nX1, int nY1, int nX2, int nY2); // 0x006492A0
void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bMissile, D2DamageStrc* pDamage); // 0x0057C6C0
void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x0057CEE0
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040
int __fastcall MISSMODE_CreatePoisonCloudHitSubmissiles(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pOrigin, int nMissileId, int nSkillId, int nSkillLevel, int a7, int a8, int a9); // 0x005A9370

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
int __fastcall sub_6FD15190(D2UnitStrc* pUnit, int nAiSpecialState); // 0x0056E2F0

struct D2WinImageClickRectStrc
{
    int nX;
    int nY;
    int nWidth;
    int nHeight;
    int unk0x10;
    int (__stdcall* pCallback)(SMSGHANDLER_PARAMS* pMsg);
};

struct D2CofNodeStrc
{
    int nRefCount;
    unsigned int nMode;
    unsigned int nClass;
    unsigned int dwWeaponClass;
    unsigned int dwCofSize;
    D2CofDataStrc* pCofData;
    D2CofNodeStrc* pNext;
    D2CofNodeStrc* pPrev;
};

extern D2CofNodeStrc* gpCofNodeList_0087E83C; // 0x0087E83C
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

struct Unit
{
    int type;
    int classId;
    void* pool;
    int id;
    unsigned char unk_10[0xB4];
    unsigned flags;
};

extern int __fastcall sub_0046C140_TestMode(int,int);
extern int __fastcall sub_005A0180_TestMonType(Unit*,int);
extern int __fastcall sub_005541B0_IsDead(Unit*);
extern int __fastcall sub_00554200_CheckTarget(Game*,Unit*,Unit*);

struct D2SummonArgStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    int nHcIdx;
    int nAiSpecialState;
    int nMonMode;
    D2CoordStrc pPosition;
    int nPetType;
    int nPetMax;
};

struct D2ItemStatCostTxt
{
    char unk0x00[0x04];
    unsigned char nItemStatFlags[4];
    char unk0x08[0x13C];
};

struct D2DifficultyLevelsTxt
{
    char unk0x00[0x1C];
    int dwAiCurseDiv;
};

extern const unsigned int gdwBitMasks[32]; // 0x006CE268
D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty); // 0x00611D30
int __fastcall sub_6FD0B450(D2UnitStrc* pUnit, void* pArgs); // 0x005C35C0
D2UnitStrc* __fastcall D2GAME_SummonPet_6FD14430(D2GameStrc* pGame, D2SummonArgStrc* pSummonArg); // 0x0056D940
void __fastcall sub_005C50C0_SetSummonStats(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel); // 0x005C50C0
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall sub_6FC3E200(D2ClientStrc* pClient, D2UnitStrc* pUnit); // 0x0053CDF0
void __fastcall D2GAME_UpdateSummonAI_6FC401F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int nNodeIndex); // 0x005B1900
int __stdcall sub_00625480(Unit*,int,unsigned short); // 0x00625480
T005C40D0* __stdcall sub_006251F0(void*,unsigned,unsigned,int,int); // 0x006251F0
void __stdcall sub_00626E10(Unit*,T005C40D0*,int); // 0x00626E10
void __stdcall sub_00627150(T005C40D0*,int,int,int); // 0x00627150

enum D2C_Y09SummonConstants
{
    STAT_LEVEL = 12,
    STAT_TOHIT = 19,
    STAT_ARMORCLASS = 31,
    MONLVL_AC = 0,
    MONLVL_TH = 2,
};
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0
void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4); // 0x0057D4F0
int __fastcall sub_005C4DF0_DetonateCorpse(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005C4DF0

struct D2MonStatsTxt
{
    char unk0x000[0xA0];
    unsigned char nDrain[3];
    char unk0x0A3[0xCD];
    short nSkill;
};

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit); // 0x0063EE90
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
D2MonStatsTxt* __fastcall sub_0055B7E0_GetMonStatsTxtFromUnit(D2UnitStrc* pUnit); // 0x0055B7E0
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3); // 0x00621E40
D2UnitStrc* __fastcall sub_6FC7E8B0(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int a4); // 0x00574EC0
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80
int __fastcall sub_004F4110_GetSkillParam5(int nSkillId); // 0x004F4110

struct D2MonStatsInitStrc
{
    int nMinHP;
    int nMaxHP;
    int unk0x08[12];
};

struct D2ModeChangeStrc
{
    int unk0x00[8];
};
int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit); // 0x00649180
void __stdcall COLLISION_ResetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EC10
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0
void __fastcall MONSTER_UpdateAiCallbackEvent(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00573780
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20
void __fastcall sub_6FD154D0(D2UnitStrc* pUnit); // 0x0056E580
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0
int __fastcall sub_6FCBDFE0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int a6, int a7); // 0x00554EA0
void __fastcall AIGENERAL_SetOwnerData(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOwnerGUID, int nOwnerType, int bSetFlag1, int bSetFlag2); // 0x0058F030
void __fastcall AIUTIL_SetOwnerGUIDAndType(D2UnitStrc* pUnit, D2UnitStrc* pOwner); // 0x005DD330
void __fastcall sub_00573120_ClearMonsterPair(D2UnitStrc* pUnit); // 0x00573120
void __fastcall D2GAME_BOSSES_AssignUMod_6FC6FF10(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique); // 0x005A4850
void __fastcall D2GAME_SetSummonPassiveStats_6FD0C530(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel, int nItemLevel); // 0x005C4470
int __stdcall DATATBLS_CalculateMonsterStatsByLevel(int nMonsterId, int nGameType, int nDifficulty, int nLevel, short nFlags, D2MonStatsInitStrc* pMonStatsInit); // 0x006538A0
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

// 0x004FD5A0
static __forceinline int sub_004FD5A0_IsInClickRect(const D2WinImageClickRectStrc* pClickRect, int nX, int nY)
{
    const int nTop = pClickRect->nY;
    if (nX >= pClickRect->nX && nY >= nTop - pClickRect->nHeight && nX < pClickRect->nX + pClickRect->nWidth && nY < nTop)
    {
        return 1;
    }
    return 0;
}

// 0x00503310
static __forceinline D2CofNodeStrc* sub_00503310_FindCofNode(unsigned int nClass, unsigned int nMode, unsigned int dwWeaponClass)
{
    for (D2CofNodeStrc* pNode = gpCofNodeList_0087E83C; pNode; pNode = pNode->pNext)
    {
        if (pNode->nMode == nMode && pNode->nClass == nClass && pNode->dwWeaponClass == dwWeaponClass)
        {
            ++pNode->nRefCount;
            return pNode;
        }
    }
    return 0;
}

// 0x0057B7A0
static __forceinline void sub_0057B7A0_AddDefenseFromStat(D2UnitStrc* pAttacker, D2UnitStrc* pDefender)
{
    const int nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, 0x78, 0);
    if (nValue)
    {
        int nNew = STATLIST_UnitGetStatValue(pDefender, 0x1F, 0) + nValue;
        if (nNew < 0)
        {
            nNew = 0;
        }
        STATLIST_SetUnitStat(pDefender, 0x1F, nNew, 0);
    }
}

// 0x005C3070
int __fastcall SKILLS_SrvSt15_RaiseSkeleton_Mage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)))
    {
        return 0;
    }

    return D2COMMON_11017_CheckUnitIfConsumeable(pTarget, 0);
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x005C30A0
int __fastcall SKILLS_SrvSt16_PoisonDagger(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)))
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel), 0);
    if (damage.wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
    {
        damage.dwEnDmgPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        if (pSkillsTxtRecord->nEType > 0)
        {
            damage.dwConvPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
            if (damage.dwConvPct > 0)
            {
                damage.nConvType = pSkillsTxtRecord->nEType;
            }

            D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
        }
    }

    unsigned char nSrcDam = pSkillsTxtRecord->nSrcDam;
    if (!pSkillsTxtRecord->nSrcDam)
    {
        nSrcDam = 0x80;
    }

    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, nSrcDam);
    return 1;
}

// 0x005C31C0
int __fastcall SKILLS_SrvSt17_Poison_CorpseExplosion(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)))
    {
        return 0;
    }

    return sub_00645680_CanUnitCorpseBeSelected(pTarget);
}

// 0x005C3260
int __fastcall SKILLS_SrvSt18_Attract(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    return 1;
}

// 0x005C3270
int __fastcall SKILLS_SrvSt19_BonePrison(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    return !DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget));
}

static __declspec(noinline) int sub_005C3300_CanReviveTarget(D2UnitStrc* pTarget)
{
    if (!pTarget)
    {
        return 0;
    }
    if (pTarget->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }
    if (!sub_004638A0_CheckMonStats2Flag(pTarget->dwClassId, 8))
    {
        return 0;
    }
    if (!SUNIT_IsDead(pTarget))
    {
        return 0;
    }
    if (!D2COMMON_11017_CheckUnitIfConsumeable(pTarget, 0))
    {
        return 0;
    }
    return sub_6FD15190(pTarget, 7) != 0;
}

// 0x005C3350
int __fastcall SKILLS_SrvSt21_Revive(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }
    return sub_005C3300_CanReviveTarget(pTarget);
}

// 0x005C33D0
int __fastcall sub_005C33D0_GetSkillValue(int nSkillId)
{
    switch (nSkillId)
    {
    case 0x17:
        return 0xA;
    case 0x1B:
        return 0xC;
    case 0x38:
        return 0xB;
    }
    return 0;
}

int __stdcall sub_M118_Emit_004FD5A0(const D2WinImageClickRectStrc* pClickRect, int nX, int nY)
{
    while (pClickRect && pClickRect->pCallback)
    {
        if (sub_004FD5A0_IsInClickRect(pClickRect, nX, nY))
        {
            return 1;
        }
        ++pClickRect;
    }
    return 0;
}

D2CofNodeStrc* __stdcall sub_M118_Emit_00503310(unsigned int nClass, unsigned int nMode, unsigned int dwWeaponClass)
{
    return sub_00503310_FindCofNode(nClass, nMode, dwWeaponClass);
}

void __stdcall sub_M118_Emit_0057B7A0(D2UnitStrc* pAttacker, D2UnitStrc* pDefender)
{
    sub_0057B7A0_AddDefenseFromStat(pAttacker, pDefender);
}

// 0x005C3400
extern "C" __declspec(dllexport) int __fastcall sub_005C3400(int nValue) {
    if (nValue != 0x17) {
        return nValue == 0x38;
    }
    return 1;
}

inline int TestFlag(Unit* unit,unsigned mask)
{
    if (unit) return (unit->flags&mask)!=0;
    return 0;
}

static __forceinline int GetType(Unit* unit)
{
    int type=6;
    if (unit) type=unit->type;
    return type;
}

// 0x005C3420
int __fastcall sub_005C3420_ValidTarget(Game* game,Unit* unit,Unit* target)
{
    if (!target) return 0;
    if (GetType(target)==1) {
        if (!sub_0046C140_TestMode(target->classId,2)) return 0;
        if (sub_005A0180_TestMonType(target,0x20)) return 0;
    }
    if (!TestFlag(target,4)) return 0;
    if (!TestFlag(target,8)) return 0;
    if (!TestFlag(target,2)) return 0;
    if (sub_005541B0_IsDead(target)) return 0;
    return sub_00554200_CheckTarget(game,unit,target)!=0;
}

inline D2ItemStatCostTxt* SKILLS_GetItemStatCostTxtRecord(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }
    return 0;
}

// 0x005C39C0
void __fastcall sub_6FD0B9F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(SKILL_DIMVISION);
    if (pSkillsTxtRecord)
    {
        int nLength = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, SKILL_DIMVISION, nSkillLevel);

        D2DifficultyLevelsTxt* pDifficultyLevelsTxtRecord = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty);
        if (pDifficultyLevelsTxtRecord && pDifficultyLevelsTxtRecord->dwAiCurseDiv)
        {
            nLength /= pDifficultyLevelsTxtRecord->dwAiCurseDiv;
        }

        D2UnkNecSkillStrc args;
        memset(&args, 0, sizeof(args));
        args.nDuration = nLength;
        args.pGame = pGame;
        args.pUnit = pUnit;
        args.unk0x08 = 1;
        args.nSkillId = SKILL_DIMVISION;
        args.nSkillLevel = nSkillLevel;
        args.bUpdateAnimRate = 0;

        for (int i = 0; i < 6; ++i)
        {
            const short nStatId = pSkillsTxtRecord->wAuraStat[i];
            if (nStatId < 0 || nStatId >= sgptDataTables->nItemStatCostTxtRecordCount)
            {
                args.nAuraStat[i] = -1;
                break;
            }

            D2ItemStatCostTxt* pItemStatCostTxtRecord = SKILLS_GetItemStatCostTxtRecord(nStatId);
            if (!pItemStatCostTxtRecord)
            {
                break;
            }

            if (pItemStatCostTxtRecord->nItemStatFlags[ITEMSTATCOSTFLAGINDEX_UPDATEANIMRATE >> 3] & gdwBitMasks[ITEMSTATCOSTFLAGINDEX_UPDATEANIMRATE & 7])
            {
                args.bUpdateAnimRate = 1;
            }

            args.nAuraStat[i] = nStatId;
            args.nAuraStatCalc[i] = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[i], SKILL_DIMVISION, nSkillLevel);
        }

        args.nAuraTargetState = pSkillsTxtRecord->wAuraTargetState;
        sub_6FD0B450(pTarget, &args);
    }
}

// 0x005C3B00
void __fastcall sub_005C3B00_AttractStateRemove(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    sub_6FCBDD30(pUnit, 0, 1);
    STATES_ToggleState(pUnit, nState, 0);
    sub_005B1A90(SUNIT_GetGameFromUnit(pUnit), pUnit);
}

// 0x005C3B30
int __fastcall sub_6FD0BDA0(D2UnitStrc* pUnit, void* pArg)
{
    D2UnkNecSkillStrc3* pParam = (D2UnkNecSkillStrc3*)pArg;
    if (!sub_005C31F0_IsValidAttractTarget(pParam->pGame, pParam->pUnit, pUnit))
    {
        return 0;
    }

    if (pParam->nUnitType == 0)
    {
        sub_6FC61E30(pUnit, 1, pParam->nUnitGUID);
    }
    else
    {
        sub_6FC61E30(pUnit, 2, pParam->nUnitGUID);
    }

    EVENT_SetEvent(pParam->pGame, pUnit, 0x0A, pParam->pGame->dwGameFrame + pParam->nLength, 0, 0);
    return 1;
}

// 0x005C3DB0
void __fastcall sub_6FD0C2B0(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    sub_6FCBDD30(pUnit, 0, 1);
    STATES_ToggleState(pUnit, nState, 0);
    sub_005B1A90(SUNIT_GetGameFromUnit(pUnit), pUnit);
}

// 0x005C3DE0
int __fastcall sub_6FD0C060(D2UnitStrc* pUnit, D2UnkNecSkillStrc* pArgs)
{
    if (!sub_005C3D50_IsValidTerrorTarget(pArgs->pGame, pArgs->pUnit, pUnit))
    {
        return 0;
    }

    int nStatId = pArgs->nAuraStat[0];
    const int nValue = sub_6FD0B3D0(pUnit, nStatId, pArgs->nAuraStatCalc[0]);
    if (!nValue)
    {
        nStatId = -1;
    }

    D2CurseStrc curse = {};
    curse.pUnit = pArgs->pUnit;
    curse.nSkill = pArgs->nSkillId;
    curse.nSkillLevel = pArgs->nSkillLevel;
    curse.pTarget = pUnit;
    curse.nDuration = pArgs->nDuration;
    curse.nStat = nStatId;
    curse.nStatValue = nValue;
    curse.nState = pArgs->nAuraTargetState;
    curse.pStateRemoveCallback = sub_6FD0C2B0;

    D2StatListStrc* pStatList = sub_0056E970(&curse);
    if (!pStatList)
    {
        return 0;
    }

    for (int i = 1; i < 6; ++i)
    {
        if (pArgs->nAuraStat[i] >= 0 && pArgs->nAuraStat[i] < sgptDataTables->nItemStatCostTxtRecordCount)
        {
            const int nStatValue = sub_6FD0B3D0(pUnit, pArgs->nAuraStat[i], pArgs->nAuraStatCalc[i]);
            if (nStatValue)
            {
                STATLIST_SetStat(pStatList, pArgs->nAuraStat[i], nStatValue, 0);
            }
        }
    }

    if (pArgs->bUpdateAnimRate)
    {
        UnitUpdateAnimRateAndVel(pUnit, ".\\SKILLS\\SkillNec.cpp", 983);
    }

    sub_6FCBDD30(pUnit, 1, 1);
    sub_6FC40280(pArgs->pGame, pUnit, 0, 9);
    sub_6FC61E30(pUnit, 3, 0);
    EVENT_SetEvent(pArgs->pGame, pUnit, EVENTTYPE_AIRESET, pArgs->pGame->dwGameFrame + pArgs->nDuration, 0, 0);
    return 1;
}

// 0x005C40D0
void __fastcall sub_005C40D0(Unit* unit,Unit* pet)
{
    int resist=sub_00625480(unit,349,0);
    if (!resist) return;
    T005C40D0* list=sub_006251F0(!pet ? 0 : pet->pool,0,0,!pet ? 6 : pet->type,!pet ? -1 : pet->id);
    if (!list) return;
    sub_00626E10(pet,list,1);
    if(sub_00625480(pet,142,0)<=0) sub_00627150(list,39,resist,0);
    if(sub_00625480(pet,144,0)<=0) sub_00627150(list,41,resist,0);
    if(sub_00625480(pet,148,0)<=0) sub_00627150(list,43,resist,0);
    sub_00627150(list,45,resist,0);
}

inline D2MonLvlTxt* DATATBLS_GetMonLvlTxtRecord(int nLevel)
{
    if (nLevel >= 0 && nLevel < sgptDataTables->nMonLvlTxtRecordCount)
    {
        return &sgptDataTables->pMonLvlTxt[nLevel];
    }

    return 0;
}

// 0x005C49E0
int __fastcall D2GAME_SKILLS_SetSummonBaseStats_6FD0CB10(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nPetLevelArg, int nSkillLevel)
{
    int nPetLevel = nPetLevelArg;
    if (nPetLevelArg <= 0)
    {
        const int nUnitLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
        nPetLevel = nSkillLevel + 3 * nUnitLevel / 4;
        nPetLevel = D2_MIN(D2_MAX(nPetLevel, 1), nUnitLevel);
    }

    if (nPetLevel)
    {
        STATLIST_SetUnitStat(pPet, STAT_LEVEL, nPetLevel, 0);
    }

    if (nPetLevel >= sgptDataTables->nMonLvlTxtRecordCount - 1)
    {
        nPetLevel = sgptDataTables->nMonLvlTxtRecordCount - 1;
    }

    D2MonLvlTxt* pMonLvlTxtRecord = DATATBLS_GetMonLvlTxtRecord(nPetLevel);
    if (!pMonLvlTxtRecord)
    {
        return 0;
    }

    const int nDifficulty = D2_MIN(D2_MAX(pGame->nDifficulty, 0), 2);
    const int nGameType = pGame->nGameType || pGame->dwGameType;
    STATLIST_AddUnitStat(pPet, STAT_ARMORCLASS, pMonLvlTxtRecord->nValues[MONLVL_AC + nGameType][nDifficulty], 0);
    STATLIST_AddUnitStat(pPet, STAT_TOHIT, pMonLvlTxtRecord->nValues[MONLVL_TH + nGameType][nDifficulty], 0);
    return 1;
}

// 0x005C4CD0
int __fastcall SKILLS_SrvDo032_PoisonDagger(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    return 1;
}

// 0x005C4D10
int __fastcall sub_6FD0D000(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    D2UnkNecSkillStrc2* pArg = (D2UnkNecSkillStrc2*)pAuraCallback->pArgs;
    if (!pArg)
    {
        return 0;
    }

    D2DamageStrc damage = *pArg->pDamage;
    if (pArg->unk0x0C < PATH_ComputeSquaredDistance(pArg->nX, pArg->nY, CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit)))
    {
        damage.dwPhysDamage = 0;
    }

    SUNITDMG_ExecuteEvents(pAuraCallback->pGame, pAuraCallback->pOwner, pUnit, 1, &damage);
    SUNITDMG_ExecuteMissileDamage(pAuraCallback->pGame, pAuraCallback->pOwner, pUnit, &damage);
    return 1;
}

// 0x005C50B0
int __fastcall SKILLS_SrvDo055_CorpseExplosion(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    return sub_005C4DF0_DetonateCorpse(pGame, pUnit, nSkillId, nSkillLevel);
}

// 0x005C5100
int __fastcall SKILLS_SrvDo056_Golem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!nSkillId || pSkillsTxtRecord->wSummon < 0 || pSkillsTxtRecord->wSummon >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return 0;
    }

    unsigned char nPetType = pSkillsTxtRecord->nPetType;
    if (nPetType >= sgptDataTables->nPetTypeTxtRecordCount)
    {
        nPetType = 0;
    }

    unsigned char nSumMode = pSkillsTxtRecord->nSumMode;
    if (pSkillsTxtRecord->nSumMode >= 16)
    {
        nSumMode = 1;
    }

    D2SummonArgStrc summonArg = {};
    summonArg.dwFlags = 0;
    summonArg.pOwner = pUnit;
    summonArg.nHcIdx = pSkillsTxtRecord->wSummon;
    summonArg.nAiSpecialState = 0;
    summonArg.nMonMode = nSumMode;
    summonArg.nPetType = nPetType;
    summonArg.nPetMax = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPetMax, nSkillId, nSkillLevel);

    D2UnitStrc* pPet = D2GAME_SummonPet_6FD14430(pGame, &summonArg);
    if (!pPet)
    {
        return 0;
    }

    sub_005C50C0_SetSummonStats(pGame, pUnit, pPet, nSkillId, nSkillLevel);
    sub_6FC3E200(UnitGetClient(pUnit, ".\\SKILLS\\SkillNec.cpp", 1787), pPet);
    D2GAME_UpdateSummonAI_6FC401F0(pGame, pPet, 0, pUnit->dwNodeIndex);
    return 1;
}

inline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

inline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x005C5430
static int __stdcall sub_005C5430_MoveRevivedTarget(D2GameStrc* pGame, D2UnitStrc* pTarget)
{
    COLLISION_ResetMaskWithPattern(UNITS_GetRoom(pTarget), UNITS_GetUnitXPosition(pTarget), UNITS_GetUnitYPosition(pTarget), PATH_GetUnitCollisionPattern(pTarget), 0x8000);
    D2CoordStrc tCoords;
    tCoords.nX = UNITS_GetUnitXPosition(pTarget);
    tCoords.nY = UNITS_GetUnitYPosition(pTarget);
    D2ActiveRoomStrc* pRoom = COLLISION_GetFreeCoordinates(UNITS_GetRoom(pTarget), &tCoords, UNITS_GetUnitSizeX(pTarget), 0x3C01, 1);
    if (!pRoom)
    {
        return 0;
    }
    pTarget->dwFlags |= 0x402000E;
    MONSTER_UpdateAiCallbackEvent(pGame, pTarget);
    D2ModeChangeStrc tModeChange = {};
    MONSTERMODE_GetModeChangeInfo(pTarget, 1, &tModeChange);
    D2GAME_ModeChange_6FC65220(pGame, &tModeChange, 1);
    sub_6FD154D0(pTarget);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pTarget, 8, 0);
    if (UNITS_GetRightSkill(pTarget))
    {
        SKILLS_SetRightActiveSkill(pTarget, 0, -1);
    }
    return sub_6FCBDFE0(pGame, pTarget, pRoom, tCoords.nX, tCoords.nY, 0, 0);
}

// 0x005C55C0
static void __stdcall sub_005C55C0_InitializeRevivedMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pMonster, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (nSkillId)
    {
        AIGENERAL_SetOwnerData(pGame, pMonster, !pUnit ? -1 : pUnit->dwUnitId, !pUnit ? UNIT_INVALID : pUnit->dwUnitType, 0, 0);
        AIUTIL_SetOwnerGUIDAndType(pMonster, pUnit);
        D2GAME_EVENTS_Delete_6FC34840(pGame, pMonster, 2, 0);
        EVENT_SetEvent(pGame, pMonster, 2, pGame->dwGameFrame + 15, 0, 0);
        sub_6FCBDD30(pMonster, 2, 0);
        sub_00573120_ClearMonsterPair(pMonster);

        if (pMonster)
        {
            pMonster->dwFlags |= 0x80000000;
        }

        STATES_ToggleState(pMonster, 0x60, 1);

        const int nDuration = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
        if (nDuration > 0)
        {
            D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pMonster, 0x15, 0);
            EVENT_SetEvent(pGame, pMonster, 7, nDuration + pGame->dwGameFrame, 0, 0);
        }
    }
}

// 0x005C56C0
int __fastcall SKILLS_SrvDo058_Revive(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!nSkillId)
    {
        return 0;
    }
    unsigned char nPetType = pSkillsTxtRecord->nPetType;
    if (nPetType >= sgptDataTables->nPetTypeTxtRecordCount)
    {
        nPetType = 0;
    }
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }
    if (!sub_005C3300_CanReviveTarget(pTarget))
    {
        return 0;
    }
    sub_005C2FF0_DamagePaladinCaster(pGame, pUnit, nSkillId, nSkillLevel);
    sub_005C5430_MoveRevivedTarget(pGame, pTarget);
    const int bExpansion = pGame->nGameType || pGame->dwGameType;
    D2MonStatsInitStrc tMonStatsInit;
    memset(&tMonStatsInit, 0, sizeof(tMonStatsInit));
    const int nClassId = pTarget->dwClassId;
    DATATBLS_CalculateMonsterStatsByLevel(nClassId, bExpansion, pGame->nDifficulty, STATLIST_UnitGetStatValue(pTarget, 12, 0), 1, &tMonStatsInit);
    const int nNewHp = (ITEMS_RollLimitedRandomNumber(&pTarget->pSeed, tMonStatsInit.nMaxHP - tMonStatsInit.nMinHP + 1) + tMonStatsInit.nMinHP) << 8;
    STATLIST_SetUnitStat(pTarget, 7, nNewHp, 0);
    STATLIST_SetUnitStat(pTarget, 6, nNewHp, 0);
    const int nUnitLevel = STATLIST_UnitGetStatValue(pUnit, 12, 0);
    const int nTargetLevel = STATLIST_UnitGetStatValue(pTarget, 12, 0);
    if (nTargetLevel && nUnitLevel < nTargetLevel)
    {
        int nHitpoints = DATATBLS_ApplyRatio(nNewHp, nUnitLevel, nTargetLevel);
        if (nHitpoints < 1)
        {
            nHitpoints = 1;
        }
        STATLIST_SetUnitStat(pTarget, 7, nHitpoints, 0);
        STATLIST_SetUnitStat(pTarget, 6, nHitpoints, 0);
        STATLIST_SetUnitStat(pTarget, 12, nUnitLevel, 0);
    }
    D2GAME_SetSummonPassiveStats_6FD0C530(pGame, pUnit, pTarget, nSkillId, nSkillLevel, 0);
    sub_005C55C0_InitializeRevivedMonster(pGame, pUnit, pTarget, nSkillId, nSkillLevel);
    sub_6FC7D7A0(pGame, pUnit, pTarget, nPetType, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPetMax, nSkillId, nSkillLevel));
    D2GAME_UpdateSummonAI_6FC401F0(pGame, pTarget, 0, pUnit->dwNodeIndex);
    D2Common_10214(pTarget);
    return 1;
}

// 0x005C5E60
int __fastcall SKILLS_SrvDo063_PoisonExplosion(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!nSkillId)
    {
        return 0;
    }

    const short nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
        if (!pTarget || !sub_00645680_CanUnitCorpseBeSelected(pTarget))
        {
            return 0;
        }

        STATES_ToggleState(pTarget, STATE_CORPSE_NOSELECT, 1);
        UNITROOM_RefreshUnit(pTarget);
        MISSMODE_CreatePoisonCloudHitSubmissiles(pGame, pUnit, pTarget, pSkillsTxtRecord->wSrvMissileA, nSkillId, nSkillLevel, 0, 2, 0);
    }

    return 1;
}

// 0x005C5F10
static int sub_005C5F10_AddLifeAndGetGain(D2UnitStrc* pUnit, int nValue)
{
    if (nValue <= 0)
    {
        return 0;
    }

    int nNewHp = STATLIST_UnitGetStatValue(pUnit, 6, 0);
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit);
    nNewHp += nValue;
    if (nNewHp > nMaxHp)
    {
        nValue += (nMaxHp - nNewHp);
        nNewHp = nMaxHp;
    }

    STATLIST_SetUnitStat(pUnit, 6, nNewHp, 0);
    return nValue;
}

int __fastcall SKILLS_EventFunc04_ReflectPhysicalDamage(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pUnit || !pAttacker || !(pAttacker->dwUnitType == UNIT_PLAYER || pAttacker->dwUnitType == UNIT_MONSTER) || SUNIT_IsDead(pAttacker) || !pDamage || pDamage->dwPhysDamage <= 0)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nSkillLevel < 0)
    {
        nSkillLevel = 1;
    }

    if (pSkillsTxtRecord->wAuraTargetState < 0 || pSkillsTxtRecord->wAuraTargetState >= sgptDataTables->nStatesTxtRecordCount || !STATES_CheckState(pAttacker, pSkillsTxtRecord->wAuraTargetState))
    {
        return 0;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pAttacker, pSkillsTxtRecord->wAuraTargetState);
    if (!pStatList)
    {
        return 0;
    }

    D2UnitStrc* pStatListOwner = SUNIT_GetServerUnit(pGame, STATLIST_GetOwnerType(pStatList), STATLIST_GetOwnerGUID(pStatList));
    int nDamagePercent = 0;
    if (pAttacker->dwUnitType == UNIT_PLAYER || MONSTERS_GetHirelingTypeId(pAttacker))
    {
        if (pUnit->dwUnitType == UNIT_PLAYER)
        {
            nDamagePercent = SKILLS_EvaluateSkillFormula(pStatListOwner, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
        }
        else
        {
            nDamagePercent = SKILLS_EvaluateSkillFormula(pStatListOwner, pSkillsTxtRecord->dwCalc[2], nSkillId, nSkillLevel);
        }
    }
    else
    {
        nDamagePercent = SKILLS_EvaluateSkillFormula(pStatListOwner, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    }

    D2DamageStrc damage = {};
    damage.dwPhysDamage = DATATBLS_ApplyRatio(pDamage->dwPhysDamage, nDamagePercent, 100);
    damage.wResultFlags |= pSkillsTxtRecord->wResultFlags | 0x20;
    damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
    damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
    SUNITDMG_ExecuteEvents(pGame, pUnit, pAttacker, 1, &damage);
    SUNITDMG_ExecuteMissileDamage(pGame, pUnit, pAttacker, &damage);

    if (pUnit->dwUnitType != UNIT_MONSTER || pUnit->dwClassId != 0x122)
    {
        return 1;
    }

    unsigned char nDrain = 100;
    if (pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = sub_0055B7E0_GetMonStatsTxtFromUnit(pUnit);
        if (!pMonStatsTxtRecord)
        {
            return 1;
        }

        nDrain = pMonStatsTxtRecord->nDrain[pGame->nDifficulty];
        if (nDrain <= 0)
        {
            return 1;
        }
    }

    if (STATLIST_GetUnitAlignment(pUnit))
    {
        return 1;
    }

    int nBaseDamage = damage.dwPhysDamage;
    if (nDrain != 100)
    {
        nBaseDamage = DATATBLS_ApplyRatio(damage.dwPhysDamage, nDrain, 100);
    }

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pAttacker);
    if (pOwner && SUNIT_IsDead(pOwner) || SUNIT_IsDead(pAttacker))
    {
        return 1;
    }

    int nDamage = DATATBLS_ApplyRatio(nBaseDamage, 20, 100);
    if (nDamage <= 0)
    {
        return 1;
    }

    if (pOwner)
    {
        nDamage -= sub_005C5F10_AddLifeAndGetGain(pOwner, DATATBLS_ApplyRatio(nDamage, 50, 100));
    }

    nDamage -= sub_005C5F10_AddLifeAndGetGain(pAttacker, nDamage);
    if (pOwner && nDamage > 0)
    {
        sub_005C5F10_AddLifeAndGetGain(pOwner, nDamage);
    }

    UNITS_SetOverlay(pAttacker, 0x97, 0);
    if (pOwner)
    {
        UNITS_SetOverlay(pOwner, 0x97, 0);
    }

    return 1;
}

int __fastcall sub_005C6870_FeedBloodGolem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nValue)
{
    if (!pUnit)
    {
        return nValue;
    }

    D2UnitStrc* pGolem = sub_6FC7E8B0(pGame, pUnit, 3, 0);
    if (!pGolem)
    {
        return nValue;
    }
    if (pGolem->dwUnitType != UNIT_MONSTER)
    {
        return nValue;
    }
    const int nClassId = pGolem->dwClassId;
    if (nClassId != 0x122)
    {
        return nValue;
    }

    if (nValue)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nClassId);
        if (pMonStatsTxtRecord && pMonStatsTxtRecord->nSkill >= 0)
        {
            nValue -= sub_005C5F10_AddLifeAndGetGain(pGolem, sub_004F4110_GetSkillParam5(pMonStatsTxtRecord->nSkill) * nValue / 100);
        }
    }
    else
    {
        STATLIST_SetUnitStat(pGolem, 6, STATLIST_GetMaxLifeFromUnit(pGolem), 0);
    }

    return nValue;
}

// 0x005C6530
int __fastcall D2GAME_EventFunc23_6FD0F1F0(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit || !pDamage)
    {
        return 0;
    }

    if (pUnit->dwUnitType != UNIT_PLAYER)
    {
        if (pUnit->dwUnitType != UNIT_MONSTER)
        {
            return 0;
        }
    }

    unsigned char nDrain = 100;
    if (pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = sub_0055B7E0_GetMonStatsTxtFromUnit(pUnit);
        if (!pMonStatsTxtRecord)
        {
            return 0;
        }

        nDrain = pMonStatsTxtRecord->nDrain[pGame->nDifficulty];
        if (nDrain <= 0)
        {
            return 0;
        }
    }

    if (STATLIST_GetUnitAlignment(pUnit))
    {
        return 0;
    }

    int nDamage = pDamage->dwPhysDamage;
    if (nDrain != 100)
    {
        nDamage = DATATBLS_ApplyRatio(nDamage, nDrain, 100);
    }

    if (nDamage >= STATLIST_UnitGetStatValue(pUnit, 6, 0))
    {
        nDamage = STATLIST_UnitGetStatValue(pUnit, 6, 0);
    }

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pAttacker);
    if (pOwner && SUNIT_IsDead(pOwner) || SUNIT_IsDead(pAttacker))
    {
        return 0;
    }

    const int nPercentage = D2Common_11034(nSkillLevel, nSkillId);
    if (nPercentage <= 0)
    {
        return 0;
    }

    int nBaseDamage = DATATBLS_ApplyRatio(nDamage, nPercentage, 100);
    if (nBaseDamage <= 0)
    {
        return 0;
    }

    const int nParam = sub_004EFC50_GetSkillParam3(nSkillId);
    if (pOwner && nParam > 0)
    {
        nBaseDamage -= sub_005C5F10_AddLifeAndGetGain(pOwner, DATATBLS_ApplyRatio(nBaseDamage, nParam, 100));
    }

    const int nFinalDamage = nBaseDamage - sub_005C5F10_AddLifeAndGetGain(pAttacker, nBaseDamage);
    if (pOwner && nFinalDamage > 0)
    {
        sub_005C5F10_AddLifeAndGetGain(pOwner, nFinalDamage);
    }

    UNITS_SetOverlay(pAttacker, 0x97, 0);

    if (nParam > 0 && pOwner)
    {
        UNITS_SetOverlay(pOwner, 0x97, 0);
    }

    return 1;
}

// 0x005C6690
int __fastcall sub_005C6690_ShareDamageWithOwner(D2GameStrc* pGame, int nEvent, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pUnit || !pDamage)
    {
        return 0;
    }

    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return 0;
    }

    if (pDamage->dwDmgTotal <= 0)
    {
        return 0;
    }

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner)
    {
        return 0;
    }

    if (SUNIT_IsDead(pOwner))
    {
        return 0;
    }

    int nLife = STATLIST_UnitGetStatValue(pOwner, STAT_HITPOINTS, 0);
    if (nLife < 0x100)
    {
        return 0;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId);
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    if (pMonStatsTxtRecord->nSkill >= 0)
    {
        const int nDamage = DATATBLS_ApplyRatio(pDamage->dwDmgTotal, sub_004E6C70(pMonStatsTxtRecord->nSkill), 100);
        nLife -= nDamage;
        if (nLife < 0x100)
        {
            nLife = 0x100;
        }

        STATLIST_SetUnitStat(pOwner, STAT_HITPOINTS, nLife, 0);
        pDamage->dwDmgTotal -= nDamage;
        pDamage->dwDmgTotal = pDamage->dwDmgTotal > 0 ? pDamage->dwDmgTotal : 0;
        return 1;
    }

    return 0;
}
