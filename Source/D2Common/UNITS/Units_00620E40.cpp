#include "D2Common.h"
#include "D2Structs.h"
#define UNITFLAGEX_HASINV 0x1
#define UNITFLAGEX_UPDATEINV 0x2
#define UNITFLAGEX_STORELASTATTACKER 0x20000
#define MONSTATS2_SOFT 12
#define STAT_TOHIT 19
struct D2SkillListStrc;
struct D2InventoryStrc;
struct D2GfxLightStrc;
struct D2ShrinesTxt;
struct D2StaticPathStrc;
struct D2ObjectsTxt;
struct D2ObjectDataStrc;
struct D2ItemsTxt;
struct D2CharStatsTxt;
struct D2MonStatsTxt;

struct D2StaticPathStrc
{
    char unk0x00[29];
    unsigned char bRoomNeedsUpdate;
};

struct D2ObjectsTxt
{
    char unk0x00[216];
    int dwFrameCnt[8];
    char unk0xF8[66];
    unsigned char nIsDoor;
    char unk0x13B;
    unsigned char nOrientation;
};

struct D2ObjectDataStrc
{
    D2ObjectsTxt* pObjectTxt;
    char unk0x04[4];
    D2ShrinesTxt* pShrineTxt;
};

struct D2ItemsTxt
{
    char unk0x00[304];
    unsigned char nBelt;
};

struct D2CharStatsTxt
{
    char unk0x00[0x3C];
    int dwToHitFactor;
    unsigned char nWalkSpeed;
    unsigned char nRunSpeed;
    unsigned char unk_42[0x7];
    unsigned char nBlockFactor;
    char unk0x4A[0x7A];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0x04];
    int nMonStatsTxtRecordCount;
    char unk0xA84[0x140];
    D2CharStatsTxt* pCharStatsTxt;
    int nCharStatsTxtRecordCount;
};


extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2AnimDataRecordStrc* __fastcall DATATBLS_GetAnimDataRecord(D2UnitStrc* pUnit, int nClassId, int nMode, int nUnitType, D2InventoryStrc* pInventory); // 0x0066A9B0
int __stdcall PATH_IsCurrentRoomInvalid(D2DynamicPathStrc* pPath); // 0x00648B30
void __stdcall PATH_SetCurrentRoomInvalid(D2DynamicPathStrc* pPath, int a2); // 0x00648B40
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040
void __stdcall D2Common_10216(D2DynamicPathStrc* pPath, int nX, int nY, int a4); // 0x00649EF0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480

struct D2MonStatsTxt
{
    char unk0x00[0x0C];
    unsigned char nMonStatsFlags[4];
    char unk0x10[0x198];
};

enum
{
    UNIT_TYPES = 6,
    STAT_DEXTERITY = 2,
    STAT_LEVEL = 12,
    STAT_TOBLOCK = 20,
    MONSTATSFLAGINDEX_NOSHLDBLOCK = 26,
};

extern const unsigned int gdwBitMasks[32]; // 0x006CE268
int __fastcall sub_006225F0_MonsterCanBlock(D2UnitStrc* pUnit); // 0x006225F0
int __stdcall INVENTORY_GetEquippedShield(D2InventoryStrc* pInventory, D2UnitStrc** ppItem); // 0x0063C8F0

inline D2AnimSeqTxt* UNITS_GetAnimSeq(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == UNIT_PLAYER || pUnit->dwUnitType == UNIT_MONSTER)
    {
        return pUnit->pAnimSeq;
    }

    return 0;
}

// 0x00620E40
void __stdcall UNITS_GetRunAndWalkSpeedForPlayer(int nUnused, int nCharId, int* pWalkSpeed, int* pRunSpeed)
{
    D2CharStatsTxt* pCharStatsTxtRecord = (nCharId >= 0 && nCharId < sgptDataTables->nCharStatsTxtRecordCount) ? &sgptDataTables->pCharStatsTxt[nCharId] : 0;
    *pWalkSpeed = pCharStatsTxtRecord->nWalkSpeed;
    *pRunSpeed = pCharStatsTxtRecord->nRunSpeed;
}

// 0x00620F00
void __stdcall UNITS_SetAnimData(D2UnitStrc* pUnit, int nUnitType, int nClassId, int nMode)
{
    D2_ASSERT(pUnit, 2358);
    pUnit->pAnimData = DATATBLS_GetAnimDataRecord(pUnit, nClassId, nMode, nUnitType, pUnit->pInventory);
}

// 0x00620F50
int __stdcall UNITS_IsCurrentRoomInvalid(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 2540);

    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
        return pUnit->pStaticPath->bRoomNeedsUpdate;

    default:
        return PATH_IsCurrentRoomInvalid(pUnit->pDynamicPath);
    }
}

// 0x00620FA0
void __stdcall UNITS_SetCurrentRoomInvalid(D2UnitStrc* pUnit, int a2)
{
    D2_ASSERT(pUnit, 2558);

    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        pUnit->pStaticPath->bRoomNeedsUpdate = a2 != 0;
        return;

    default:
        PATH_SetCurrentRoomInvalid(pUnit->pDynamicPath, a2);
        return;
    }
}

// 0x00621000
void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag)
{
    if (bSetFlag)
    {
        UNITROOM_RefreshUnit(pUnit);
    }

    if (pUnit)
    {
        if (bSetFlag)
        {
            pUnit->dwFlagEx |= UNITFLAGEX_HASINV;
        }
        else
        {
            pUnit->dwFlagEx &= ~UNITFLAGEX_HASINV;
            return;
        }
    }

    if (bSetFlag && pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        pUnit->dwFlagEx |= UNITFLAGEX_UPDATEINV;
    }
}

// 0x00621150
D2GfxLightStrc* __stdcall UNITS_ResetLightMap(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 2669);

    D2GfxLightStrc* pLight = pUnit->pLight;
    pUnit->pLight = 0;

    return pLight;
}

// 0x006211C0
void __stdcall UNITS_SetAnimOrSeqMode(D2UnitStrc* pUnit, int nAnimMode)
{
    D2_ASSERT(pUnit, 2706);

    if (UNITS_GetAnimSeq(pUnit))
    {
        pUnit->dwSeqMode = nAnimMode;
    }
    else
    {
        pUnit->dwAnimMode = nAnimMode;
    }
}

// 0x006212C0
void __stdcall UNITS_SetAnimationFrame(D2UnitStrc* pUnit, int nFrame)
{
    D2_ASSERT(pUnit, 2766);

    pUnit->dwSeqFrame = (nFrame << 8) + (pUnit->dwSeqFrame & 0xFF);
}

// 0x00621310
void __stdcall UNITS_UpdateFrame(D2UnitStrc* pUnit)
{
    pUnit->nSeqCurrentFramePrecise += pUnit->wAnimSpeed;

    if (pUnit->nSeqCurrentFramePrecise >= pUnit->dwFrameCountPrecise)
    {
        pUnit->nSeqCurrentFramePrecise -= pUnit->dwFrameCountPrecise;
    }
}

// 0x00621810
void __stdcall UNITS_GetShiftedFrameMetrics(D2UnitStrc* pUnit, int* pFrameNo, int* pFrameCount)
{
    D2_ASSERT(pUnit, 3471);

    if (pUnit->dwUnitType == UNIT_OBJECT)
    {
        *pFrameNo = pUnit->nSeqCurrentFramePrecise >> 8;
        *pFrameCount = pUnit->pObjectData->pObjectTxt->dwFrameCnt[pUnit->dwAnimMode];
    }
    else
    {
        *pFrameNo = pUnit->nSeqCurrentFramePrecise >> 8;
        *pFrameCount = pUnit->dwFrameCountPrecise >> 8;
    }
}

// 0x00621A70
int __stdcall UNITS_IsDoor(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 3600);

    if (pUnit->dwUnitType == UNIT_OBJECT)
    {
        return pUnit->pObjectData->pObjectTxt->nIsDoor;
    }

    return FALSE;
}

// 0x00621AC0
bool __fastcall UNITS_CheckIfObjectOrientationIs1(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit->dwUnitType == UNIT_OBJECT, 3614);

    return pUnit->pObjectData->pObjectTxt->nOrientation == 1;
}

// 0x00621B30
D2ObjectsTxt* __stdcall UNITS_GetObjectTxtRecordFromObject(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 3644);

    if (pUnit->dwUnitType == UNIT_OBJECT)
    {
        return pUnit->pObjectData->pObjectTxt;
    }

    sub_00408A60(&gszEmptyAssertText, sub_00408090(), 3651);
    exit(-1);
}

// 0x00621B70
D2ShrinesTxt* __stdcall UNITS_GetShrineTxtRecordFromObject(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 3662);

    if (pUnit->dwUnitType == UNIT_OBJECT)
    {
        return pUnit->pObjectData->pShrineTxt;
    }

    sub_00408A60(&gszEmptyAssertText, sub_00408090(), 3669);
    exit(-1);
}

// 0x00621BB0
void __stdcall UNITS_SetShrineTxtRecordInObjectData(D2UnitStrc* pUnit, D2ShrinesTxt* pShrinesTxtRecord)
{
    D2_ASSERT(pUnit, 3680);

    if (pUnit->dwUnitType == UNIT_OBJECT)
    {
        pUnit->pObjectData->pShrineTxt = pShrinesTxtRecord;
        return;
    }

    sub_00408A60(&gszEmptyAssertText, sub_00408090(), 3687);
    exit(-1);
}

// 0x00621C00
void __stdcall UNITS_UpdateDirectionAndSpeed(D2UnitStrc* pUnit, int nX, int nY)
{
    if (pUnit->pDynamicPath)
    {
        D2Common_10216(pUnit->pDynamicPath, nX, nY, 0);
    }
}

// 0x00621D50
void __stdcall UNITS_StoreLastAttacker(D2UnitStrc* pUnit, D2UnitStrc* pKiller)
{
    D2_ASSERT(pUnit, 3815);

    if (pKiller)
    {
        pUnit->dwKillerType = pKiller->dwUnitType;
        pUnit->dwKillerGUID = pKiller->dwUnitId;
        pUnit->dwFlagEx |= UNITFLAGEX_STORELASTATTACKER;
    }
    else
    {
        pUnit->dwKillerType = 0;
        pUnit->dwKillerGUID = 0;
        pUnit->dwFlagEx &= ~UNITFLAGEX_STORELASTATTACKER;
    }
}

static __forceinline D2CharStatsTxt* DATATBLS_GetCharStatsTxtRecord_Inl(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }

    return 0;
}

// 0x00622520
static __forceinline int sub_00622520_GetToHitFactor(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : 6;
    if (nType != UNIT_PLAYER)
    {
        return 0;
    }

    D2CharStatsTxt* pCharStatsTxtRecord = DATATBLS_GetCharStatsTxtRecord_Inl(pUnit->dwClassId);
    if (!pCharStatsTxtRecord)
    {
        return 0;
    }

    return pCharStatsTxtRecord->dwToHitFactor;
}

int __stdcall UNITS_GetAttackRate(D2UnitStrc* pAttacker)
{
    D2_ASSERT((pAttacker ? pAttacker->dwUnitType : 6) == UNIT_PLAYER, 4223);

    int nToHit = STATLIST_UnitGetStatValue(pAttacker, STAT_TOHIT, 0);
    int nDexterity = STATLIST_UnitGetStatValue(pAttacker, STAT_DEXTERITY, 0);
    int nAttackRate = nToHit + 5 * (nDexterity - 7);
    return nAttackRate + sub_00622520_GetToHitFactor(pAttacker);
}

static __forceinline int UNITS_GetUnitTypeInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return UNIT_TYPES;
    }
    return pUnit->dwUnitType;
}

static __forceinline int UNITS_GetClassIdInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwClassId;
}

static __forceinline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static __forceinline int MONSTERS_HasNoShieldBlockFlagInline(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInline(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }
    return pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_NOSHLDBLOCK >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_NOSHLDBLOCK & 7];
}

static __forceinline D2CharStatsTxt* DATATBLS_GetCharStatsTxtRecordInline(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }
    return 0;
}

// 0x00622720
int __stdcall UNITS_GetBlockRate(D2UnitStrc* pUnit, int bExpansion)
{
    int nBlockChance = 0;

    switch (UNITS_GetUnitTypeInline(pUnit))
    {
    case UNIT_PLAYER:
        if (INVENTORY_GetEquippedShield(pUnit->pInventory, 0))
        {
            nBlockChance = STATLIST_UnitGetStatValue(pUnit, STAT_TOBLOCK, 0);
            nBlockChance += DATATBLS_GetCharStatsTxtRecordInline(pUnit->dwClassId)->nBlockFactor;
            if (bExpansion)
            {
                const int nDexterity = STATLIST_UnitGetStatValue(pUnit, STAT_DEXTERITY, 0);
                int nLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
                if (nLevel <= 1)
                {
                    nLevel = 1;
                }
                nBlockChance = nBlockChance * (nDexterity - 15) / (2 * nLevel);
            }
        }
        break;

    case UNIT_MONSTER:
        if (MONSTERS_HasNoShieldBlockFlagInline(UNITS_GetClassIdInline(pUnit)) || sub_006225F0_MonsterCanBlock(pUnit))
        {
            nBlockChance = STATLIST_UnitGetStatValue(pUnit, STAT_TOBLOCK, 0);
        }
        break;
    }

    if (nBlockChance < 75)
    {
        return nBlockChance;
    }
    return 75;
}
