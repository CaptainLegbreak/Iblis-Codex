#include "D2Client.h"

#define NULL 0
#define BITARRAY_CHECK(pBytes, nBit) ((pBytes)[(nBit) >> 3] & gdwBitMasks[(nBit) & 7])
#define SKILLSFLAGINDEX_LOB 1
#define SKILLSFLAGINDEX_PRGSTACK 7
struct D2SeedStrc;
struct D2MonStats2Txt;
struct D2SkillsTxt;
struct D2MonStatsTxt;
struct D2ClientSkillArgsStrc;
struct D2PathDirectionStrc;
struct D2StaticPathStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2MonStats2Txt
{
    char unk0x00[0x0B];
    char nType;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x0C];
    D2SeedStrc tSeed;
    int dwUnk0x28;
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char pad30[0x8];
    unsigned int frame;
    unsigned char unk_3C[0x24];
    D2InventoryStrc* pInventory;
    unsigned char unk_64[0x60];
    union
    {
        unsigned int flags;
        unsigned int dwFlags;
    };
};

struct D2SkillsTxt
{
    int skillId;
    union
    {
        unsigned char nFlags[8];
        unsigned char flags[8];
    };
    unsigned char nCharClass;
    unsigned char unk_0D[0x3];
    unsigned char animation;
    unsigned char unk_11[0x43];
    short wProgressiveStat;
    char unk0x056[0x2A];
    short wProgressiveState;
    char unk0x082[0x66];
    union
    {
        short wAuraFunc;
        short clientMissile;
        short wCltMissile;
    };
    char unk0x0EA[0x08];
    short wStartFunc;
    short clientDo;
    short wCltPrgFunc[3];
    short wStartSound;
    short wStartSoundClass;
    union
    {
        short sound;
        short wDoSound;
    };
    unsigned char unk_102[0x4];
    short wCastOverlay;
    union
    {
        short targetOverlay;
        short wTgtOverlay;
    };
    union
    {
        short targetSound;
        short wTgtSound;
    };
    unsigned char unk_10C[0x16];
    short wItemStartSound;
    short wItemCastOverlay;
    unsigned char unk_126[0x46];
    short clientDoSecondary;
    unsigned char unk_16E[0x21];
    unsigned char nLineOfSight;
    unsigned int delay;
    char pad194[0xa8];
};

struct D2MonStatsTxt
{
    char unk0x000[0x10];
    unsigned int dwCode;
    char unk0x014[0x1A8 - 0x14];
};

struct D2DataTablesStrc
{
    char unk0x000[0xC4];
    int nStatesTxtRecordCount;
    unsigned char unk_C8[0x9B0];
    D2MonStatsTxt* pMonStatsTxt;
    int unk0xA7C;
    int nMonStatsTxtRecordCount;
    char unk0xA84[0xB98 - 0xA84];
    union
    {
        D2SkillsTxt* pSkillsTxt;
        D2SkillsTxt* skills;
    };
    int unk0xB9C;
    union
    {
        int nSkillsTxtRecordCount;
        int skillCount;
    };
    char unk0xBA4[0x1C];
    int nOverlayTxtRecordCount;
    unsigned char unk_BC4[0x10];
    int nItemStatCostTxtRecordCount;
};

struct D2ClientSkillArgsStrc
{
    int nSkillId;
    int nOwnerGUID;
    int nArg1;
    int nArg2;
    int nSkillLevel;
};

struct D2PathDirectionStrc
{
    unsigned char nDirection;
};

typedef int (__fastcall* CLIENTSKILLSTARTFN)(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern CLIENTSKILLSTARTFN gpfnClientSkillStartFuncs_00727A90[]; // 0x00727A90
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType); // 0x00463990
D2UnitStrc* __fastcall sub_004648F0_GetTargetUnit(D2UnitStrc* pUnit); // 0x004648F0
int __fastcall sub_00464F70_IsTargetBlocked(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00464F70
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
void __fastcall sub_00480E70_SetState(D2UnitStrc* pUnit, int nArg); // 0x00480E70
int __fastcall sub_004AA8B0_GetSkillMaxLevel(int nSkillId); // 0x004AA8B0
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00
int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C52E0
int __fastcall sub_004CA4C0(D2UnitStrc* pUnit, int nArg); // 0x004CA4C0
unsigned int __fastcall sub_004CA500_GetAnimRate(D2UnitStrc* pUnit, unsigned int nDirection); // 0x004CA500
void __fastcall sub_004CB9C0_Request(D2UnitStrc* pUnit, int nId); // 0x004CB9C0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill); // 0x00620210
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit); // 0x006235A0
int __fastcall sub_00623C20(D2UnitStrc* pUnit); // 0x00623C20
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __stdcall sub_0062A4E0_TestItem(D2UnitStrc* pItem); // 0x0062A4E0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
D2SkillStrc* __fastcall SKILLS_GetSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0
int __stdcall sub_00643B00(D2SkillStrc* pSkill, int* pArg2, int* pArg3, int* pSkillLevel, int* pCharges); // 0x00643B00
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
int __stdcall SKILLS_GetSkillModeFromUnit(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x00643860
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0
void __stdcall SKILLS_SetParam4(D2SkillStrc* pSkill, int nValue); // 0x00644620
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue); // 0x00644660
void __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280
void __stdcall D2COMMON_10160_PathUpdateDirection(D2DynamicPathStrc* pDynamicPath, D2PathDirectionStrc tDirection); // 0x00648820
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0

struct D2CoordStrc { int nX; int nY; };

struct D2StaticPathStrc { void* pRoom; int dwClientCoordX; int dwClientCoordY; D2CoordStrc tGameCoords; };

enum D2C_UnitTypes { UNIT_OBJECT = 2, UNIT_ITEM = 4, UNIT_TILE = 5 };

typedef int (__fastcall* ClientSkillDo)(D2UnitStrc*,int,int);

extern int gnClientDoCount; // 0x00727DB0
extern ClientSkillDo gaClientDo[]; // 0x00727BA8
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10
int __fastcall UNITS_GetXPosition(D2UnitStrc*); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20
D2UnitStrc* __fastcall sub_004CDC30(D2UnitStrc*,int,int,int,int,int,int,int,int); // 0x004CDC30
D2UnitStrc* __fastcall sub_004C57B0_FireMissileAtTarget(int,D2UnitStrc*,int,int,int,int,int,int); // 0x004C57B0
void* __stdcall D2Common_10958(D2UnitStrc*,void*); // 0x00643A00
void __fastcall sub_004743D0_ReleaseOverlayResource(void*); // 0x004743D0
int __fastcall sub_004B9A00(int,D2UnitStrc*,int,int,int); // 0x004B9A00
D2UnitStrc* __fastcall sub_004648F0_GetTargetUnit(D2UnitStrc*); // 0x004648F0
void __fastcall sub_00470390_AddOverlay(D2UnitStrc*,int,int,int,int,int,int,int); // 0x00470390
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc*,unsigned int,int,int); // 0x00646CA0
unsigned int __cdecl sub_0044DA90_GetTick(); // 0x0044DA90
void __fastcall sub_0044CE40_SetSkillDelay(int); // 0x0044CE40

typedef int (__fastcall* CLIENTSKILLDOFN)(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);
extern CLIENTSKILLDOFN gpfnClientSkillDoFuncs_00727BA8[]; // 0x00727BA8
void __fastcall sub_004C5420_RequestAtTarget(D2UnitStrc* pUnit, int nMissile, int nSkillId, int nSkillLevel); // 0x004C5420
D2UnitStrc* __fastcall sub_004CDC30(D2UnitStrc* pUnit, int nMissile, int nOffsetX, int nOffsetY, int nTargetX, int nTargetY, int nSkillId, int nSkillLevel, int nRange); // 0x004CDC30
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall sub_006252D0(D2StatListStrc* pStatList, int nState); // 0x006252D0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150

// build: context SKILLCLT_GetSkillsTxtRecord
static __forceinline D2SkillsTxt* SKILLCLT_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return NULL;
}

// build: context SKILLCLT_GetMonStatsTxtRecord
static __forceinline D2MonStatsTxt* SKILLCLT_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return NULL;
}

// build: context SKILLCLT_RollSeed
static __forceinline unsigned int SKILLCLT_RollSeed(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

// build: context SKILLCLT_GetUnitTypeByte
static __forceinline unsigned char SKILLCLT_GetUnitTypeByte(D2UnitStrc* pUnit)
{
    return pUnit->dwUnitType;
}

// build: context SKILLCLT_GetUnitType
static __forceinline int SKILLCLT_GetUnitType(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwUnitType : 6;
}

// build: context SKILLCLT_SetCastState
static __forceinline void SKILLCLT_SetCastState(D2UnitStrc* pUnit)
{
    if (pUnit && (pUnit->dwUnitType == 0 || pUnit->dwUnitType == 1))
    {
        sub_00480E70_SetState(pUnit, 1);
    }
}

// 0x004C5710
static __declspec(noinline) int sub_004C5710_GetAttackMode(D2UnitStrc* pUnit)
{
    int nMode = 7;
    D2UnitStrc* pTarget = sub_004648F0_GetTargetUnit(pUnit);
    int bRandom = 1;
    if (pTarget && pTarget->dwUnitType == 1)
    {
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pTarget->dwClassId);
        if (pMonStats2TxtRecord->nType == 2)
        {
            nMode = 8;
            bRandom = 0;
        }
        if (pMonStats2TxtRecord->nType == 1)
        {
            bRandom = 0;
        }
    }

    if (COMPOSIT_IsWeaponBowOrXBow(pUnit))
    {
        nMode = 7;
        bRandom = 0;
    }

    D2UnitStrc* pWeapon;
    int nBodyLoc;
    int bIsLeftHand;
    if (!INVENTORY_GetEquippedWeapon(pUnit->pInventory, &pWeapon, &nBodyLoc, &bIsLeftHand))
    {
        return 7;
    }

    if (bRandom)
    {
        const char nRoll = SKILLCLT_RollSeed(&pUnit->tSeed) & 0x3F;
        if (nRoll < 0x20)
        {
            return 8;
        }
    }

    return nMode;
}

// 0x004C58A0
static __declspec(noinline) int sub_004C58A0_CheckTarget(D2UnitStrc* pUnit, int nSkillId)
{
    D2UnitStrc* pTarget = sub_004648F0_GetTargetUnit(pUnit);
    if (!pTarget)
    {
        return 1;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLCLT_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 21))
    {
        const int nType = pTarget->dwUnitType;
        if (nType == 1 && pTarget->dwAnimMode == 12)
        {
            return BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 24) != 0;
        }

        if (nType == 0)
        {
            return 1;
        }
    }

    return 1;
}

// 0x004C6140
static __declspec(noinline) int __stdcall sub_004C6140_StartSkill(int nOwnerGUID, int nSkillLevel, D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLCLT_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nLineOfSight)
    {
        int nX;
        int nY;
        if (sub_004C52E0_GetTargetPosition(pUnit, &nX, &nY))
        {
        int nCollisionMask;
        switch (pSkillsTxtRecord->nLineOfSight)
        {
        case 1:
            nCollisionMask = 4;
            break;
        case 2:
            nCollisionMask = 0x1C09;
            break;
        case 3:
            nCollisionMask = 0x180;
            break;
        case 4:
            nCollisionMask = 0x804;
            break;
        case 5:
            nCollisionMask = 0x805;
            break;
        default:
            return 0;
        }

        if (!sub_00645950_CheckTargetPos(nX, nY, pUnit, nCollisionMask))
        {
            return 0;
        }
        }
    }

    if (!sub_004C58A0_CheckTarget(pUnit, nSkillId))
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill || SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 0x504) != nSkillId)
    {
        pSkill = SKILLS_GetSkill(pUnit, nSkillId, nOwnerGUID);
        if (!pSkill)
        {
            SKILLS_AddSkill(pUnit, nSkillId);
            pSkill = SKILLS_GetSkill(pUnit, nSkillId, nOwnerGUID);
            if (pSkill && pUnit == sub_00463DD0() && nOwnerGUID == -1)
            {
                SKILLS_SetFlags(pSkill, 8);
            }

            const int nMaxLevel = sub_004AA8B0_GetSkillMaxLevel(nSkillId);
            if (nSkillLevel > nMaxLevel)
            {
                SKILLS_AssignSkill(pUnit, nSkillId, nMaxLevel, 0, ".\\SKILLS\\Skills.cpp", 0x513);
                sub_00647AA0_SetSkillBonusLevel(pUnit, nSkillId, nSkillLevel - nMaxLevel);
            }
            else
            {
                SKILLS_AssignSkill(pUnit, nSkillId, nSkillLevel, 0, ".\\SKILLS\\Skills.cpp", 0x518);
            }

            if (!pSkill)
            {
                return 0;
            }
        }

        UNITS_SetUsedSkill(pUnit, pSkill);
    }

    if (nOwnerGUID != -1)
    {
        int nItemOwnerGUID;
        int nItemSkillId;
        int nCharges;
        if (!sub_00643B00(pSkill, &nItemOwnerGUID, &nItemSkillId, &nSkillLevel, &nCharges) || !nCharges)
        {
            return 0;
        }
    }

    if (pUnit != sub_00463DD0())
    {
        const int nMaxLevel = sub_004AA8B0_GetSkillMaxLevel(nSkillId);
        if (nSkillLevel > nMaxLevel)
        {
            SKILLS_AssignSkill(pUnit, nSkillId, nMaxLevel, 0, ".\\SKILLS\\Skills.cpp", 0x53A);
            sub_00647AA0_SetSkillBonusLevel(pUnit, nSkillId, nSkillLevel - nMaxLevel);
        }
        else
        {
            SKILLS_AssignSkill(pUnit, nSkillId, nSkillLevel, 0, ".\\SKILLS\\Skills.cpp", 0x53F);
        }
    }
    else
    {
        nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
    }

    D2UnitStrc* pTarget = sub_004648F0_GetTargetUnit(pUnit);
    if (pTarget && !BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 26) && sub_00464F70_IsTargetBlocked(pUnit, pTarget))
    {
        return 0;
    }

    if (!BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 8) && DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        UNITS_SetUsedSkill(pUnit, NULL);
        int aArgs[7] = {};
        sub_00480C10_UnitEvent(7, pUnit, aArgs, 0);
        if (pUnit == sub_00463DD0())
        {
            sub_004CB9C0_Request(pUnit, 0x18);
        }
        return 0;
    }

    int nMode;
    if (pUnit && !SKILLCLT_GetUnitTypeByte(pUnit) && !nSkillId)
    {
        nMode = sub_004C5710_GetAttackMode(pUnit);
    }
    else
    {
        nMode = SKILLS_GetSkillModeFromUnit(pUnit, pSkill);
    }

    if (nMode)
    {
        sub_00480E70_SetState(pUnit, nMode);
    }
    else if (!STATES_CheckState(pUnit, 12) || !BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 11))
    {
        SKILLCLT_SetCastState(pUnit);
    }

    int nResult = 1;
    const short nStartFunc = pSkillsTxtRecord->wStartFunc;
    if (nStartFunc >= 0 && nStartFunc < gnClientSkillStartFuncs_00727A8C && gpfnClientSkillStartFuncs_00727A90[nStartFunc])
    {
        nResult = gpfnClientSkillStartFuncs_00727A90[nStartFunc](pUnit, nSkillId, nSkillLevel);
        if (!nResult)
        {
            UNITS_SetUsedSkill(pUnit, NULL);
            SKILLCLT_SetCastState(pUnit);
            if (BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 12))
            {
                goto Done;
            }
        }
    }

    short nSound;
    nSound = pSkillsTxtRecord->wStartSound;
    if (nOwnerGUID != -1 && pSkillsTxtRecord->wItemStartSound > 0)
    {
        nSound = pSkillsTxtRecord->wItemStartSound;
    }

    if (nSound > 0)
    {
        if (BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 13))
        {
            const int nDirection = sub_00623C20(pUnit);
            sub_004CA500_GetAnimRate(pUnit, nDirection);
            const int nDelay = sub_004CA500_GetAnimRate(pUnit, nDirection) - 3;
            sub_004B9A00(nSound, pUnit, nDelay, 0, 0);
        }
        else
        {
            sub_004B9A00(nSound, pUnit, 0, 0, 0);
        }
    }

    if (BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 14))
    {
        const int nSoundId = sub_004CA4C0(pUnit, sub_00623C20(pUnit));
        if (nSoundId)
        {
            const int nDirection = sub_00623C20(pUnit);
            sub_004CA500_GetAnimRate(pUnit, nDirection);
            const int nRate = sub_004CA500_GetAnimRate(pUnit, nDirection);
            sub_004B9A00(nSoundId, pUnit, nRate, 0, 0);
        }
    }

    short nClassSound;
    nClassSound = pSkillsTxtRecord->wStartSoundClass;
    if ((nOwnerGUID == -1 || pSkillsTxtRecord->wItemStartSound <= 0) && nClassSound > 0 && (!pUnit ? 6 : pUnit->dwUnitType) == 0 && (!pUnit ? -1 : pUnit->dwClassId) == pSkillsTxtRecord->nCharClass)
    {
        if (BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 13))
        {
            const int nDirection = sub_00623C20(pUnit);
            sub_004CA500_GetAnimRate(pUnit, nDirection);
            const int nDelay = sub_004CA500_GetAnimRate(pUnit, nDirection) - 3;
            sub_004B9A00(nClassSound, pUnit, nDelay, 0, 0);
        }
        else
        {
            sub_004B9A00(nClassSound, pUnit, 0, 0, 0);
        }
    }

    int nOverlay;
    nOverlay = pSkillsTxtRecord->wCastOverlay;
    if (nOwnerGUID != -1 && pSkillsTxtRecord->wItemCastOverlay > 0)
    {
        nOverlay = pSkillsTxtRecord->wItemCastOverlay;
    }

    if (nOverlay > 0 && nOverlay < sgptDataTables->nOverlayTxtRecordCount && !sub_0046E100(pUnit, nOverlay))
    {
        sub_00470390(pUnit, nOverlay, 2, 0, 0, 0, 0, 0);
    }

Done:
    if (nResult && pSkillsTxtRecord->wAuraFunc > 0)
    {
        sub_004C5680_StartAura(pUnit, pSkillsTxtRecord->wAuraFunc);
    }

    return nResult;
}

// build: context sub_004C6660_StartSkillWrapper
int __fastcall sub_004C6660_StartSkillWrapper(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nOwnerGUID)
{
    return sub_004C6140_StartSkill(nOwnerGUID, nSkillLevel, pUnit, nSkillId);
}

// 0x004C6DE0
static __declspec(noinline) void __stdcall sub_004C6DE0_SwapDualWieldSkill(D2ClientSkillArgsStrc* pArgs, D2UnitStrc* pUnit)
{
    if (pArgs->nSkillId != 0)
    {
        return;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pRightHand = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
    if (pRightHand && (!sub_0062A4E0_TestItem(pRightHand) || ITEMS_GetItemType(pRightHand) == 0x26))
    {
        pRightHand = NULL;
    }

    D2UnitStrc* pLeftHand = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
    if (pLeftHand && (!sub_0062A4E0_TestItem(pLeftHand) || ITEMS_GetItemType(pLeftHand) == 0x26))
    {
        pLeftHand = NULL;
    }

    if (ITEMS_CheckItemTypeId(pRightHand, 0x2D) && ITEMS_CheckItemTypeId(pLeftHand, 0x2D))
    {
        D2SkillStrc* pSkill = SKILLS_GetSkill(pUnit, 0, -1);
        if (!SKILLS_GetParam4(pSkill))
        {
            pArgs->nSkillId = 5;
            SKILLS_SetParam4(pSkill, 5);
            pSkill = SKILLS_GetSkill(pUnit, 5, -1);
        }
        else
        {
            SKILLS_SetParam4(pSkill, 0);
        }

        UNITS_SetUsedSkill(pUnit, pSkill);
    }
}

// 0x004C6EB0
int __fastcall sub_004C6EB0_StartSkillOnUnit(D2UnitStrc* pUnit, D2ClientSkillArgsStrc* pArgs)
{
    if (UNITS_CanDualWield(pUnit) && (!pUnit || pUnit->dwUnitType != 1))
    {
        sub_004C6DE0_SwapDualWieldSkill(pArgs, pUnit);
    }

    D2UnitStrc* pTarget = sub_00463990(pArgs->nArg2, pArgs->nArg1);
    if (pTarget)
    {
        UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
        sub_00465BF0(pUnit, 0);
        return sub_004C6140_StartSkill(pArgs->nOwnerGUID, pArgs->nSkillLevel, pUnit, pArgs->nSkillId);
    }

    sub_00480C10_UnitEvent(7, pUnit, NULL, 0);
    sub_006248E0_Log(1, 2, 4, 0x40, ".\\SKILLS\\Skills.cpp", 0x7C2, "StartsStartSkillID - Invalid Target");
    return 0;
}

// build: context sub_004C6F40_StartSkillAtPos
int __fastcall sub_004C6F40_StartSkillAtPos(D2UnitStrc* pUnit, D2ClientSkillArgsStrc* pArgs)
{
    const int nX = pArgs->nArg1;
    const int nY = pArgs->nArg2;
    if (UNITS_CanDualWield(pUnit))
    {
        sub_004C6DE0_SwapDualWieldSkill(pArgs, pUnit);
    }

    D2COMMON_10170_PathSetTargetPos(pUnit->pDynamicPath, nX, nY);
    sub_00621C00_SetTargetPos(pUnit, nX, nY);
    if (pUnit->dwUnitType == 1)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = SKILLCLT_GetMonStatsTxtRecord(pUnit->dwClassId);
        if (pMonStatsTxtRecord && pMonStatsTxtRecord->dwCode == 0x20204250)
        {
            D2PathDirectionStrc tDirection;
            tDirection.nDirection = (PATH_GetNewDirection(pUnit->pDynamicPath) + 0x38) % 64;
            D2COMMON_10160_PathUpdateDirection(pUnit->pDynamicPath, tDirection);
        }
    }

    UNITS_SetTargetUnitForDynamicUnit(pUnit, NULL);
    return sub_004C6140_StartSkill(pArgs->nOwnerGUID, pArgs->nSkillLevel, pUnit, pArgs->nSkillId);
}

// 0x004C51E0
void __fastcall sub_004C51E0_GetAdjacentPosition(D2UnitStrc* pUnit, int* pX, int* pY)
{
    const int nDirection = UNITS_GetDirection(pUnit) >> 3;
    int aOffsetX[8] = { 0, -1, -2, -1, 0, 1, 2, 1 };
    int aOffsetY[8] = { 2, 1, 0, -1, -2, -1, 0, 1 };

    int nX;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nX = pUnit->pStaticPath->tGameCoords.nX;
        break;

    default:
        if (pUnit->pDynamicPath)
        {
            nX = PATH_GetXPosition(pUnit->pDynamicPath);
        }
        else
        {
            nX = 0;
        }
        break;
    }
    *pX = aOffsetX[nDirection] + nX;

    int nY;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nY = pUnit->pStaticPath->tGameCoords.nY;
        break;

    default:
        if (pUnit->pDynamicPath)
        {
            nY = PATH_GetYPosition(pUnit->pDynamicPath);
        }
        else
        {
            nY = 0;
        }
        break;
    }
    *pY = aOffsetY[nDirection] + nY;
}

// 0x004C52E0
int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY)
{
    int nY;
    D2UnitStrc* pTarget = sub_004648F0_GetTargetUnit(pUnit);
    if (pTarget)
    {
        int nX;
        switch (pTarget->dwUnitType)
        {
        case UNIT_OBJECT:
        case UNIT_ITEM:
        case UNIT_TILE:
            nX = pTarget->pStaticPath->tGameCoords.nX;
            break;

        default:
            if (pTarget->pDynamicPath)
            {
                nX = PATH_GetXPosition(pTarget->pDynamicPath);
            }
            else
            {
                nX = 0;
            }
            break;
        }
        *pX = nX;

        switch (pTarget->dwUnitType)
        {
        case UNIT_OBJECT:
        case UNIT_ITEM:
        case UNIT_TILE:
            nY = pTarget->pStaticPath->tGameCoords.nY;
            break;

        default:
            if (pTarget->pDynamicPath)
            {
                nY = PATH_GetYPosition(pTarget->pDynamicPath);
            }
            else
            {
                nY = 0;
            }
            break;
        }
    }
    else
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        *pX = D2COMMON_10175_PathGetFirstPointX(pPath);
        nY = D2COMMON_10176_PathGetFirstPointY(pPath);
    }
    *pY = nY;

    if (!*pX || !nY)
    {
        sub_004C51E0_GetAdjacentPosition(pUnit, pX, pY);
    }
    return 1;
}

static __forceinline D2SkillsTxt* GetSkillRecord(int id)
{if(id>=0 && id<sgptDataTables->skillCount)return &sgptDataTables->skills[id];return 0;}

// 0x004C6680
int __fastcall sub_004C6680_SkillDo(D2UnitStrc* unit,int skillId,int skillLevel,int mode)
{
 D2SkillsTxt* skill=GetSkillRecord(skillId);
 if(!skill)return 0;
 if(skill->clientDo<0 || skill->clientDo>=gnClientDoCount)return 0;
 int result=0;
 if(skill->clientMissile>0){
  int x=0,y=0,targetX=0,targetY=0;
  if(mode){
   sub_004C52E0_GetTargetPosition(unit,&x,&y);
   if(x && y){
    targetX=x;targetY=y;
    x-=UNITS_GetXPosition(unit);
    y-=CLIENTS_GetUnitY(unit);
    targetX+=x;targetY+=y;
   }
  }
  D2UnitStrc* missile;
  if(skill->flags[0] & (unsigned char)gdwBitMasks[1])
   missile=sub_004CDC30(unit,skill->clientMissile,x,y,targetX,targetY,skillId,skillLevel,0);
  else missile=sub_004C57B0_FireMissileAtTarget(skill->clientMissile,unit,skillId,skillLevel,x,y,targetX,targetY);
  if(missile)result=1;
  if(unit)unit->flags|=0x40;
 }
 int index=skill->clientDo;
 if(mode && skill->clientDoSecondary>1)index=skill->clientDoSecondary;
 if(index>=0 && index<gnClientDoCount && gaClientDo[index]){
  if(gaClientDo[index](unit,skillId,skillLevel))result=1;
 }else{
  if(unit)unit->flags|=0x40;
  result=1;
 }
 void* resource=D2Common_10958(unit,0);
 if(resource)sub_004743D0_ReleaseOverlayResource(resource);
 if(!result)return 0;
 if(skill->sound>0)sub_004B9A00(skill->sound,unit,0,0,0);
 if(skill->targetSound>0){
  D2UnitStrc* target=sub_004648F0_GetTargetUnit(unit);
  if(target)sub_004B9A00(skill->targetSound,target,0,0,0);
 }
 if(skill->targetOverlay>0){
  D2UnitStrc* target=sub_004648F0_GetTargetUnit(unit);
  if(target)sub_00470390_AddOverlay(target,skill->targetOverlay,2,0,0,0,0,0);
 }
 int delay=SKILLS_EvaluateSkillFormula(unit,skill->delay,skillId,skillLevel);
 if(delay>0 && sub_00463DD0()==unit){
  if(delay>12)delay=12;
  if(skill->animation!=18 || !(unit->frame & 0xffffff00))
   sub_0044CE40_SetSkillDelay(sub_0044DA90_GetTick()+delay);
 }
 return 1;
}

static D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x004C6AC0
void __fastcall sub_004C6AC0_DoSkill(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel, int nX, int nY, int nCharges)
{
    if (!pUnit)
    {
        return;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    if (pSkillsTxtRecord->wProgressiveState < 0 || pSkillsTxtRecord->wProgressiveState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return;
    }

    if (pSkillsTxtRecord->wProgressiveStat < 0 || pSkillsTxtRecord->wProgressiveStat >= sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->wProgressiveState);
    if (!pStatList)
    {
        pStatList = STATLIST_AllocStatList(0, 0, 0, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
        if (!pStatList)
        {
            return;
        }

        sub_006252D0(pStatList, pSkillsTxtRecord->wProgressiveState);
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        STATLIST_SetStatIfListIsValid(pStatList, pSkillsTxtRecord->wProgressiveStat, nCharges, 0);
    }

    int nTargetX;
    int nTargetY;
    const int bHasTargetPos = sub_004C52E0_GetTargetPosition(pUnit, &nTargetX, &nTargetY);
    D2UnitStrc* pOldTarget = sub_004648F0_GetTargetUnit(pUnit);

    if (pTarget)
    {
        UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
    }
    else if (nX && nY)
    {
        D2COMMON_10170_PathSetTargetPos(pUnit->pDynamicPath, nX, nY);
    }

    const int nOldValue = pUnit->dwUnk0x28;
    if (nX && !nY)
    {
        pUnit->dwUnk0x28 = nX;
    }

    --nCharges;
    if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_PRGSTACK >> 3] & gdwBitMasks[SKILLSFLAGINDEX_PRGSTACK & 7])
    {
        for (int i = 0; i < nCharges; ++i)
        {
            if (gpfnClientSkillDoFuncs_00727BA8[pSkillsTxtRecord->wCltPrgFunc[i]])
            {
                STATLIST_SetStatIfListIsValid(pStatList, pSkillsTxtRecord->wProgressiveStat, i + 1, 0);
                gpfnClientSkillDoFuncs_00727BA8[pSkillsTxtRecord->wCltPrgFunc[i]](pUnit, nSkillId, nSkillLevel);
            }
        }

        STATLIST_SetStatIfListIsValid(pStatList, pSkillsTxtRecord->wProgressiveStat, nCharges + 1, 0);
    }

    const short nFunc = pSkillsTxtRecord->wCltPrgFunc[nCharges];
    if (nFunc >= 0 && nFunc < gnClientSkillDoFuncs_00727DB0)
    {
        if (pSkillsTxtRecord->wCltMissile > 0)
        {
            if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_LOB >> 3] & gdwBitMasks[SKILLSFLAGINDEX_LOB & 7])
            {
                int nMissileX;
                int nMissileY;
                sub_004C52E0_GetTargetPosition(pUnit, &nMissileX, &nMissileY);
                sub_004CDC30(pUnit, pSkillsTxtRecord->wCltMissile, 0, 0, nMissileX, nMissileY, nSkillId, nSkillLevel, 0);
            }
            else
            {
                sub_004C5420_RequestAtTarget(pUnit, pSkillsTxtRecord->wCltMissile, nSkillId, nSkillLevel);
            }

            pUnit->dwFlags |= 0x40;
        }

        if (gpfnClientSkillDoFuncs_00727BA8[pSkillsTxtRecord->wCltPrgFunc[nCharges]])
        {
            if (gpfnClientSkillDoFuncs_00727BA8[pSkillsTxtRecord->wCltPrgFunc[nCharges]](pUnit, nSkillId, nSkillLevel))
            {
                if (pSkillsTxtRecord->wDoSound > 0)
                {
                    sub_004B9A00(pSkillsTxtRecord->wDoSound, pUnit, 0, 0, 0);
                }

                if (pSkillsTxtRecord->wTgtSound > 0)
                {
                    D2UnitStrc* pCurrentTarget = sub_004648F0_GetTargetUnit(pUnit);
                    if (pCurrentTarget)
                    {
                        sub_004B9A00(pSkillsTxtRecord->wTgtSound, pCurrentTarget, 0, 0, 0);
                    }
                }

                if (pSkillsTxtRecord->wTgtOverlay > 0)
                {
                    D2UnitStrc* pCurrentTarget = sub_004648F0_GetTargetUnit(pUnit);
                    if (pCurrentTarget)
                    {
                        sub_00470390(pCurrentTarget, pSkillsTxtRecord->wTgtOverlay, 2, 0, 0, 0, 0, 0);
                    }
                }
            }
        }
        else
        {
            pUnit->dwFlags |= 0x40;
        }
    }

    UNITS_SetTargetUnitForDynamicUnit(pUnit, pOldTarget);
    if (bHasTargetPos)
    {
        D2COMMON_10170_PathSetTargetPos(pUnit->pDynamicPath, nTargetX, nTargetY);
    }

    if (nX && !nY)
    {
        pUnit->dwUnk0x28 = nOldValue;
    }
}

#include "gen/data/Source/D2Client/SKILLS/Skills_004C6140.inc"
