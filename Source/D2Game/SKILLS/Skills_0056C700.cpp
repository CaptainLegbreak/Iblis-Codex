#include "D2Game.h"

#define STAT_FIRERESIST 39
#define STAT_LIGHTRESIST 41
#define STAT_COLDRESIST 43
#define STAT_POISONRESIST 45
#define STAT_MAGICRESIST 37
#define D2_ASSERT(expr,line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2SkillsTxt;
struct D2SeedStrc;
struct D2StaticPathStrc;
struct D2UnitFindArgStrc;
struct D2CurseStrc;
struct D2StatesTxt;
struct D2MonStatsTxt;
struct D2MonStats2Txt;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    unsigned char unk_14[0xC];
    D2SeedStrc pSeed;
    unsigned char unk_28[0x4];
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
    unsigned char unk_30[0x94];
    unsigned int dwFlags;
};

struct D2SkillsTxt
{
    char unk0x000[4];
    unsigned char nFlags[8];
    signed char nCharClass;
    unsigned char unk_0D[0x1F];
    short wSrvStartFunc;
    char unk0x02E[0x161];
    unsigned char nLineOfSight;
    char unk0x190[0xAC];
};

struct D2DataTablesStrc
{
    char unk_000[0xBC];
    D2StatesTxt* pStatesTxt;
    void* pStatesLinker;
    int nStatesTxtRecordCount;
    char unk_0C8[0x9B0];
    D2MonStatsTxt* pMonStatsTxt;
    void* pMonStatsLinker;
    int nMonStatsTxtRecordCount;
    unsigned char unk_A84[0x114];
    D2SkillsTxt* pSkillsTxt;
    int unk_B9C;
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

struct D2DamageStrc
{
    char unk0x00[0x08];
    int dwPhysDamage;
    int unk0x0C;
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
    char unk0x48[0x18];
    int dwHitClass;
};

enum D2C_ElemTypes
{
    ELEMTYPE_NONE = 0,
    ELEMTYPE_FIRE = 1,
    ELEMTYPE_LTNG = 2,
    ELEMTYPE_MAGIC = 3,
    ELEMTYPE_COLD = 4,
    ELEMTYPE_POIS = 5,
    ELEMTYPE_LIFE = 6,
    ELEMTYPE_MANA = 7,
    ELEMTYPE_STAMINA = 8,
    ELEMTYPE_STUN = 9,
    ELEMTYPE_RAND = 10,
    ELEMTYPE_BURN = 11,
    ELEMTYPE_FREEZE = 12,
};

extern const int gnRandomElemTypes_006E1278[4]; // 0x006E1278

struct D2CoordStrc { int nX; int nY; };

struct D2StaticPathStrc { char unk0x00[0x0C]; D2CoordStrc tGameCoords; };

enum D2C_UnitTypes
{
    UNIT_PLAYER = 0,
    UNIT_MONSTER = 1,
    UNIT_OBJECT = 2,
    UNIT_ITEM = 4,
    UNIT_TILE = 5,
    UNIT_INVALID = 6,
};

struct D2GameStrc
{
    char unk_00[0x1C];
    void* pMemoryPool;
    unsigned char unk_20[0x88];
    int dwGameFrame;
};

struct D2UnitFindArgStrc
{
    int nFlags; int unk_04; D2UnitStrc* pUnit; int nX; int nY; int nSize; int nMaxArrayEntries; int nIndex;
    void* pField; void* pfnUnitTest; int unk_28; int unk_2C; int unk_30; int unk_34;
};

struct D2UnitFindDataStrc
{
    void* pMemPool; D2UnitStrc** pUnitsArray; D2ActiveRoomStrc* pRoom; void* pfnUnitTest; D2UnitFindArgStrc* pUnitFindArg;
    int nFlags; int nIndex; int nMaxArrayEntries; int nX; int nY; int nSize;
};

typedef void (__fastcall* CurseCallbackFunc)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int);

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern "C" void* __cdecl memset(void*, int, unsigned int); // 0x00681EF0
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(void*); // 0x006CC34C
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc*, int, int); // 0x00463740
void __stdcall UNITFINDS_InitializeUnitFindData(void*, D2UnitFindDataStrc*, D2ActiveRoomStrc*, int, int, int, void*, D2UnitFindArgStrc*); // 0x0065A950
void __stdcall UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(D2UnitFindDataStrc*); // 0x0065AC70
void __stdcall UNITFINDS_FreeUnitFindData(D2UnitFindDataStrc*); // 0x0065AA00
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc*, int, D2StatListStrc*);

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

struct D2StatesTxt { char unk_00[0x10]; unsigned char nFlags[4]; char unk_14[0x28]; };

struct D2MonStatsTxt { char unk_00[0xC]; unsigned char nFlags[4]; char unk_10[0x198]; };

struct D2MonStats2Txt { char unk_00[4]; unsigned char nFlags[4]; };

extern unsigned int gdwBitMasks[]; // 0x006CE268
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
void __fastcall EVENT_SetEvent(D2GameStrc*, D2UnitStrc*, int, int, int, int); // 0x005417D0
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010
void __fastcall sub_6FD10E50(D2UnitStrc*, int, D2StatListStrc*); // 0x0056E900
D2StatListStrc* __stdcall STATLIST_AllocStatList(void*, unsigned int, unsigned int, int, int); // 0x006251F0
void __stdcall STATLIST_SetState(D2StatListStrc*, int); // 0x006252D0
void __stdcall STATLIST_SetExpireFrame(D2StatListStrc*, int); // 0x00625310
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*, int, int); // 0x00625480
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc*, int); // 0x006256B0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc*, int); // 0x00625760
void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc*, StatListRemoveCallback); // 0x00625CE0
void __stdcall STATLIST_SetSkillId(D2StatListStrc*, int); // 0x006260D0
D2SkillStrc* __stdcall sub_006260E0(D2StatListStrc*); // 0x006260E0
void __stdcall STATLIST_SetSkillLevel(D2StatListStrc*, int); // 0x006260F0
int __stdcall STATLIST_GetSkillLevel(D2StatListStrc*); // 0x00626100
void __stdcall STATLIST_FreeStatList(D2StatListStrc*); // 0x00626CD0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc*, D2StatListStrc*, int); // 0x00626E10
void __stdcall STATLIST_SetStat(D2StatListStrc*, int, int, int); // 0x00627150
void __stdcall D2Common_10474(D2UnitStrc*, D2StatListStrc*); // 0x006277E0
void __stdcall STATES_ToggleState(D2UnitStrc*, int, int); // 0x00639DB0
int __stdcall STATES_CheckState(D2UnitStrc*, int); // 0x00639DF0
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc*); // 0x0064C040

typedef char SkillsRecordSize[sizeof(D2SkillsTxt) == 0x23C ? 1 : -1];

typedef int (__fastcall* SkillStartFunc)(D2GameStrc*, D2UnitStrc*, int, int);

extern SkillStartFunc gpSkillStartHandlers_00732140[]; // 0x00732140
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x00620210
int __fastcall SKILLS_HasManaOrChargesForUsedSkill(D2UnitStrc* pUnit); // 0x0056C160
int __fastcall sub_0056BFE0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x0056BFE0
void __fastcall sub_6FC817D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nMode, int nX, int nY, int a7); // 0x005809D0
int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY); // 0x0056D2C0
int __stdcall D2Common_11026(int nX, int nY, D2UnitStrc* pUnit, int nCollisionMask); // 0x00645950
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60

typedef char H15_CheckSkillsTxtSize[sizeof(D2SkillsTxt) == 0x23C ? 1 : -1];

typedef char H15_CheckUnitFlags[(int)&((D2UnitStrc*)0)->dwFlags == 0xC4 ? 1 : -1];

typedef char H15_CheckSkillsCount[(int)&((D2DataTablesStrc*)0)->nSkillsTxtRecordCount == 0xBA0 ? 1 : -1];

enum
{
    MONMODE_DEAD = 12,
    UNITFLAG_TARGETABLE = 0x00000002,
    PLRMODE_TOWNNEUTRAL = 5,
    SKILLSFLAGINDEX_INTOWN = 8,
    SKILLSFLAGINDEX_TARGETABLEONLY = 20,
    SKILLSFLAGINDEX_TARGETCORPSE = 24,
    SKILLSFLAGINDEX_TARGETALLY = 26,
};

int __fastcall sub_00554200(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00554200
int __fastcall SUNIT_CanPetBeTargetedBySkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pPet, int nSkillId); // 0x005542C0
int __fastcall SUNIT_CanAllyBeTargetedBySkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nSkillId); // 0x00554D20
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit); // 0x00620C10
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0
int __stdcall SKILLS_GetSkillInfo(D2SkillStrc* pSkill, int* pOwnerGUID, int* pSkillId, int* pSkillLevel, int* pCharges); // 0x00643B00

static __forceinline D2SkillsTxt* GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

static __forceinline int GetClassId(D2UnitStrc* pUnit)
{
    int nClassId = -1;
    if (pUnit)
    {
        nClassId = pUnit->dwClassId;
    }
    return nClassId;
}

// 0x0056C700
int __fastcall D2GAME_CheckSkillIfUnitsClassSkill_6FD11B50(D2UnitStrc* pUnit, int nSkillId)
{
    if (pUnit && pUnit->dwUnitType == 0)
    {
        D2SkillsTxt* pSkillsTxtRecord = GetSkillsTxtRecord(nSkillId);
        if (pSkillsTxtRecord)
            return pSkillsTxtRecord->nCharClass == GetClassId(pUnit);
    }
    return 0;
}

inline unsigned int ITEMS_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x0056C8E0
void __fastcall sub_0056C8E0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nElementalType, int nDamage, int nLength, int* pResistStatId, int* pElementalType)
{
    if (nElementalType == ELEMTYPE_RAND)
    {
        nElementalType = gnRandomElemTypes_006E1278[ITEMS_RollRandomNumber(&pUnit->pSeed) & 3];
        if (nLength <= 0)
        {
            nLength = 50;
        }

        if (pElementalType)
        {
            *pElementalType = nElementalType;
        }
    }

    int nResStatId = -1;
    switch (nElementalType)
    {
    case ELEMTYPE_FIRE:
        pDamage->dwFireDamage += nDamage;
        pDamage->dwHitClass = 0x20;
        nResStatId = STAT_FIRERESIST;
        break;

    case ELEMTYPE_LTNG:
        pDamage->dwLtngDamage += nDamage;
        pDamage->dwHitClass = 0x40;
        nResStatId = STAT_LIGHTRESIST;
        break;

    case ELEMTYPE_MAGIC:
        pDamage->dwMagDamage += nDamage;
        nResStatId = STAT_MAGICRESIST;
        break;

    case ELEMTYPE_COLD:
        pDamage->dwColdDamage += nDamage;
        pDamage->dwColdLen = nLength;
        pDamage->dwHitClass = 0x30;
        nResStatId = STAT_COLDRESIST;
        break;

    case ELEMTYPE_POIS:
        pDamage->dwPoisDamage += nDamage;
        pDamage->dwPoisLen = nLength;
        pDamage->dwHitClass = 0x50;
        nResStatId = STAT_POISONRESIST;
        break;

    case ELEMTYPE_LIFE:
        pDamage->dwLifeLeech += nDamage;
        break;

    case ELEMTYPE_MANA:
        pDamage->dwManaLeech += nDamage;
        break;

    case ELEMTYPE_STAMINA:
        pDamage->dwStamLeech += nDamage;
        break;

    case ELEMTYPE_STUN:
        pDamage->dwStunLen += nDamage + nLength;
        pDamage->dwHitClass = 0x60;
        break;

    case ELEMTYPE_BURN:
        pDamage->dwBurnDamage += nDamage;
        pDamage->dwBurnLen = nLength;
        break;

    case ELEMTYPE_FREEZE:
        pDamage->dwColdDamage += nDamage;
        pDamage->dwFrzLen = nLength;
        pDamage->dwHitClass = 0x30;
        nResStatId = STAT_COLDRESIST;
        break;

    default:
        pDamage->dwPhysDamage += nDamage;
        break;
    }

    if (pResistStatId)
    {
        *pResistStatId = nResStatId;
    }
}

#include "gen/data/Source/D2Game/SKILLS/Skills_0056C700.inc"

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

// 0x0056D2C0
int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget)
    {
        *pX = UNITS_GetUnitXPosition(pTarget);
        *pY = UNITS_GetUnitYPosition(pTarget);
    }
    else
    {
        D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
        *pX = D2COMMON_10175_PathGetFirstPointX(pDynamicPath);
        *pY = D2COMMON_10176_PathGetFirstPointY(pDynamicPath);
    }

    return *pX && *pY;
}

// 0x0056DBC0
void __fastcall sub_0056DBC0(D2GameStrc* pGame, int nFlags, D2UnitStrc* pUnit, int nSkillLevel, int nRange, CurseCallbackFunc pfCurse)
{
    D2_ASSERT(pfCurse, 0x1047);
    int nX;
    int nY;
    if (D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        D2UnitFindArgStrc findArg = {};
        findArg.nFlags = nFlags;
        findArg.pUnit = pUnit;
        findArg.nX = nX;
        findArg.nY = nY;
        findArg.nSize = nRange;
        D2ActiveRoomStrc* pRoom = D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pUnit), nX, nY);
        if (pRoom)
        {
            D2UnitFindDataStrc findData;
            UNITFINDS_InitializeUnitFindData(pGame->pMemoryPool, &findData, pRoom, nX, nY, nRange, 0, &findArg);
            UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(&findData);
            D2_ASSERT(!IsBadCodePtr((void*)pfCurse), 0x1061);
            for (int i = 0; i < findData.nIndex; ++i)
                pfCurse(pGame, pUnit, findData.pUnitsArray[i], nSkillLevel);
            UNITFINDS_FreeUnitFindData(&findData);
        }
    }
}

inline D2StatesTxt* DATATBLS_GetStatesTxtRecord(int nState)
{
    if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
        return &sgptDataTables->pStatesTxt[nState];
    return 0;
}

// 0x0056E970
D2StatListStrc* __fastcall sub_0056E970(D2CurseStrc* pCurse)
{
    D2UnitStrc* pTarget = pCurse->pTarget;
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pTarget);
    const int nState = pCurse->nState;
    D2StatesTxt* pStatesTxtRecord = DATATBLS_GetStatesTxtRecord(nState);
    if (!pStatesTxtRecord)
        return 0;
    if (pTarget && pTarget->dwUnitType == 1)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = 0;
        if (pTarget->dwClassId >= 0 && pTarget->dwClassId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            pMonStatsTxtRecord = &sgptDataTables->pMonStatsTxt[pTarget->dwClassId];
        }
        if (!pMonStatsTxtRecord || (pMonStatsTxtRecord->nFlags[1] & (unsigned char)gdwBitMasks[0]))
            return 0;
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pTarget->dwClassId);
        if (!pMonStats2TxtRecord || !(pMonStats2TxtRecord->nFlags[1] & (unsigned char)gdwBitMasks[1]))
            return 0;
    }
    const int bCurse = STATES_CheckStateMaskCurseByStateId(nState);
    if (bCurse)
    {
        const int nResistance = STATLIST_UnitGetStatValue(pTarget, 109, 0);
        if (nResistance >= 100)
            return 0;
        if (nResistance)
        {
            const int nDuration = pCurse->nDuration;
            pCurse->nDuration = nDuration - DATATBLS_ApplyRatio(nDuration, nResistance, 100);
        }
        if (STATES_CheckState(pTarget, 57))
            return 0;
    }
    unsigned int nFlags = 0;
    D2StatListStrc* pStatList;
    if (bCurse)
    {
        nFlags = 0x20;
        pStatList = STATLIST_GetStatListFromUnitAndFlag(pTarget, 0x20);
    }
    else
        pStatList = STATLIST_GetStatListFromUnitAndState(pTarget, nState);
    if (pStatList)
    {
        if (STATLIST_GetState(pStatList) == pCurse->nState && pCurse->nSkill == (int)sub_006260E0(pStatList))
        {
            const int nSkillLevel = STATLIST_GetSkillLevel(pStatList);
            if (pCurse->nSkillLevel == nSkillLevel)
            {
                if (pCurse->nDuration)
                {
                    const int nExpireFrame = pGame->dwGameFrame + pCurse->nDuration;
                    STATLIST_SetExpireFrame(pStatList, nExpireFrame);
                    EVENT_SetEvent(pGame, pTarget, 12, nExpireFrame, 0, 0);
                }
                return pStatList;
            }
            if (pCurse->nSkillLevel < nSkillLevel)
                return 0;
        }
        D2Common_10474(pTarget, pStatList);
        STATLIST_FreeStatList(pStatList);
    }
    UNITROOM_RefreshUnit(pTarget);
    STATES_ToggleState(pTarget, nState, 1);
    int nExpireFrame = 0;
    if (pCurse->nDuration)
    {
        nExpireFrame = pGame->dwGameFrame + pCurse->nDuration;
        nFlags |= 2;
        EVENT_SetEvent(pGame, pCurse->pTarget, 12, nExpireFrame, 0, 0);
    }
    if (STATES_CheckStateMaskExpByStateId(nState))
        nFlags |= 0x800;
    if (pStatesTxtRecord->nFlags[0] & (unsigned char)gdwBitMasks[1])
        nFlags |= 8;
    pStatList = STATLIST_AllocStatList(!pTarget ? 0 : pTarget->pMemoryPool, nFlags, nExpireFrame, !pCurse->pUnit ? 6 : pCurse->pUnit->dwUnitType, !pCurse->pUnit ? -1 : pCurse->pUnit->dwUnitId);
    STATLIST_SetState(pStatList, nState);
    STATLIST_SetSkillId(pStatList, pCurse->nSkill);
    STATLIST_SetSkillLevel(pStatList, pCurse->nSkillLevel);
    if (pCurse->nStat != -1)
        STATLIST_SetStat(pStatList, pCurse->nStat, pCurse->nStatValue, 0);
    D2COMMON_10475_PostStatToStatList(pTarget, pStatList, 1);
    if (!pCurse->pStateRemoveCallback)
    {
        STATLIST_SetStatRemoveCallback(pStatList, sub_6FD10E50);
        return pStatList;
    }
    STATLIST_SetStatRemoveCallback(pStatList, pCurse->pStateRemoveCallback);
    return pStatList;
}

static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

// 0x0056F640
int __fastcall sub_0056F640_StartSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bSkipMana)
{
    if (!pGame || !pUnit || !UNITS_GetRoom(pUnit))
        return 0;
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
        return 0;
    if (!bSkipMana && !SKILLS_HasManaOrChargesForUsedSkill(pUnit))
        return 0;
    if (!(pSkillsTxtRecord->nFlags[1] & gdwBitMasks[0]))
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        if (!pRoom || DUNGEON_IsRoomInTown(pRoom))
        {
            UNITS_SetUsedSkill(pUnit, 0);
            if ((!pUnit ? 6 : pUnit->dwUnitType) == 0)
                sub_6FC817D0(pGame, pUnit, 0, 5, 0, 0, 1);
            return 0;
        }
    }
    int nX;
    int nY;
    if (pSkillsTxtRecord->nLineOfSight && D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        int nCollisionMask;
        switch (pSkillsTxtRecord->nLineOfSight)
        {
        case 1: nCollisionMask = 4; break;
        case 2: nCollisionMask = 0x1C09; break;
        case 3: nCollisionMask = 0x180; break;
        case 4: nCollisionMask = 0x804; break;
        case 5: nCollisionMask = 0x805; break;
        default: return 0;
        }
        if (!D2Common_11026(nX, nY, pUnit, nCollisionMask))
            return 0;
    }
    if (pSkillsTxtRecord->wSrvStartFunc < 0 || pSkillsTxtRecord->wSrvStartFunc >= 91)
        return 0;
    SkillStartFunc pStart = gpSkillStartHandlers_00732140[pSkillsTxtRecord->wSrvStartFunc];
    int nResult;
    if (!pStart)
    {
        nResult = 1;
    }
    else
    {
        nResult = pStart(pGame, pUnit, nSkillId, nSkillLevel);
        if (nResult && !(pSkillsTxtRecord->nFlags[4] & gdwBitMasks[5]) && !bSkipMana)
            sub_0056BFE0(pGame, pUnit, nSkillId, nSkillLevel);
    }
    if (nResult && (pSkillsTxtRecord->nFlags[0] & gdwBitMasks[6]))
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 8, 0);
    return nResult;
}

static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord_H15(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static __forceinline int UNIT_HasFlag_H15(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }
    return 0;
}

// 0x0056CC60
static int __stdcall sub_0056CC60_CheckUsedSkillTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 1;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord_H15(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_TARGETABLEONLY >> 3] & gdwBitMasks[SKILLSFLAGINDEX_TARGETABLEONLY & 7])
    {
        if (!sub_00554200(pGame, pUnit, pTarget) && !SUNIT_CanPetBeTargetedBySkill(pGame, pUnit, pTarget, nSkillId) && !SUNIT_CanAllyBeTargetedBySkill(pGame, pUnit, pTarget, nSkillId))
        {
            return 0;
        }
    }

    if (!UNIT_HasFlag_H15(pTarget, UNITFLAG_TARGETABLE))
    {
        UNITS_SetTargetUnitForDynamicUnit(pUnit, 0);
    }
    else
    {
        if (pTarget->dwUnitType == UNIT_MONSTER && pTarget->dwAnimMode == MONMODE_DEAD)
        {
            if (!(pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_TARGETCORPSE >> 3] & gdwBitMasks[SKILLSFLAGINDEX_TARGETCORPSE & 7]))
            {
                UNITS_SetTargetUnitForDynamicUnit(pUnit, 0);
            }
        }
        else
        {
            if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_TARGETCORPSE >> 3] & gdwBitMasks[SKILLSFLAGINDEX_TARGETCORPSE & 7])
            {
                UNITS_SetTargetUnitForDynamicUnit(pUnit, 0);
            }
        }
    }

    return 1;
}

// 0x0056FAF0
int __fastcall SKILLS_StartUsedSkill(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 0xBFF);
    if (!sub_0056CC60_CheckUsedSkillTarget(pGame, pUnit, nSkillId))
    {
        if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
        {
            sub_6FC817D0(pGame, pUnit, 0, PLRMODE_TOWNNEUTRAL, 0, 0, 1);
        }
        return 0;
    }

    int nOwnerGUID;
    int nInfoSkillId;
    int nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
    int nCharges;
    if (SKILLS_GetSkillInfo(pSkill, &nOwnerGUID, &nInfoSkillId, &nSkillLevel, &nCharges) && !nCharges)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord_H15(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTargetUnit = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTargetUnit && !(pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_TARGETALLY >> 3] & gdwBitMasks[SKILLSFLAGINDEX_TARGETALLY & 7]) && SUNIT_CanAllyBeTargetedBySkill(pGame, pUnit, pTargetUnit, nSkillId))
    {
        return 0;
    }

    if (!(pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_INTOWN >> 3] & gdwBitMasks[SKILLSFLAGINDEX_INTOWN & 7]))
    {
        if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
        {
            UNITS_SetUsedSkill(pUnit, 0);
            int nType = UNIT_INVALID;
            if (pUnit)
            {
                nType = pUnit->dwUnitType;
            }
            switch (nType)
            {
            case UNIT_PLAYER:
                sub_6FC817D0(pGame, pUnit, 0, PLRMODE_TOWNNEUTRAL, 0, 0, 1);
                break;
            case UNIT_MONSTER:
                return 0;
            }
            return 0;
        }
    }

    const int nResult = sub_6FD12950(pGame, pUnit, nSkillId, nSkillLevel, 0);
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && !nResult)
    {
        sub_6FC817D0(pGame, pUnit, 0, PLRMODE_TOWNNEUTRAL, 0, 0, 1);
    }
    return nResult;
}
