extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

#define NULL 0

struct D2DynamicPathStrc;
struct D2InventoryStrc;
struct D2ActiveRoomStrc;
struct D2SkillStrc;

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
    int unk0x28;
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0x30];
    D2InventoryStrc* pInventory;
};

struct D2SkillsTxt
{
    char unk0x000[0x04];
    unsigned char nFlags[8];
    unsigned char nCharClass;
    char unk0x00D[0xE8 - 0x0D];
    short wAuraFunc;
    char unk0x0EA[0x08];
    short wStartFunc;
    char unk0x0F4[0x08];
    short wStartSound;
    short wStartSoundClass;
    char unk0x100[0x06];
    short wCastOverlay;
    char unk0x108[0x1A];
    short wItemStartSound;
    short wItemCastOverlay;
    char unk0x126[0x69];
    unsigned char nLineOfSight;
    char unk0x190[0x23C - 0x190];
};

struct D2MonStatsTxt
{
    char unk0x000[0x10];
    unsigned int dwCode;
    char unk0x014[0x1A8 - 0x14];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    int unk0xA7C;
    int nMonStatsTxtRecordCount;
    char unk0xA84[0xB98 - 0xA84];
    D2SkillsTxt* pSkillsTxt;
    int unk0xB9C;
    int nSkillsTxtRecordCount;
    char unk0xBA4[0x1C];
    int nOverlayTxtRecordCount;
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

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern int gnClientSkillStartFuncs_00727A8C;                                                                // 0x00727A8C
extern CLIENTSKILLSTARTFN gpfnClientSkillStartFuncs_00727A90[];                                             // 0x00727A90

D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId);                                    // 0x00451FE0
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
D2UnitStrc* __fastcall sub_004648F0_GetTargetUnit(D2UnitStrc* pUnit);                                       // 0x004648F0
int __fastcall sub_00464F70_IsTargetBlocked(D2UnitStrc* pUnit, D2UnitStrc* pTarget);                        // 0x00464F70
void __fastcall sub_00465BF0(D2UnitStrc* pUnit, int nArg);                                                  // 0x00465BF0
int __fastcall sub_0046E100(D2UnitStrc* pUnit, int nOverlay);                                               // 0x0046E100
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
int __fastcall sub_00480C10_UnitEvent(int nEvent, D2UnitStrc* pUnit, int* pArgs, int nFlag);                // 0x00480C10
void __fastcall sub_00480E70_SetState(D2UnitStrc* pUnit, int nArg);                                         // 0x00480E70
int __fastcall sub_004AA8B0_GetSkillMaxLevel(int nSkillId);                                                 // 0x004AA8B0
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);          // 0x004B9A00
int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY);                         // 0x004C52E0
void __fastcall sub_004C5680_StartAura(D2UnitStrc* pUnit, int nAuraFunc);                                   // 0x004C5680
int __fastcall sub_004CA4C0(D2UnitStrc* pUnit, int nArg);                                                   // 0x004CA4C0
unsigned int __fastcall sub_004CA500_GetAnimRate(D2UnitStrc* pUnit, unsigned int nDirection);               // 0x004CA500
void __fastcall sub_004CB9C0_Request(D2UnitStrc* pUnit, int nId);                                           // 0x004CB9C0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill);                              // 0x00620210
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit);               // 0x00620C10
void __stdcall sub_00621C00_SetTargetPos(D2UnitStrc* pUnit, int nX, int nY);                                // 0x00621C00
int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit);                                                        // 0x006235A0
int __fastcall sub_00623C20(D2UnitStrc* pUnit);                                                             // 0x00623C20
void __cdecl sub_006248E0_Log(int nA, int nB, int nC, int nFlags, const char* szFile, int nLine, const char* szFormat, ...); // 0x006248E0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
int __stdcall sub_0062A4E0_TestItem(D2UnitStrc* pItem);                                                     // 0x0062A4E0
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                         // 0x0062B400
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063BDE0
int __stdcall INVENTORY_GetEquippedWeapon(D2InventoryStrc* pInventory, D2UnitStrc** ppItem, int* pBodyLoc, int* pIsLeftHand); // 0x0063C9B0
D2SkillStrc* __fastcall SKILLS_GetSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                   // 0x006439B0
int __stdcall sub_00643B00(D2SkillStrc* pSkill, int* pArg2, int* pArg3, int* pSkillLevel, int* pCharges); // 0x00643B00
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
int __stdcall SKILLS_GetSkillModeFromUnit(D2UnitStrc* pUnit, D2SkillStrc* pSkill);                          // 0x00643860
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0
int __stdcall SKILLS_GetParam4(D2SkillStrc* pSkill);                                                        // 0x00644530
void __stdcall SKILLS_SetParam4(D2SkillStrc* pSkill, int nValue);                                           // 0x00644620
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue);                                            // 0x00644660
int __stdcall sub_00645950_CheckTargetPos(int nX, int nY, D2UnitStrc* pUnit, int nCollisionMask);           // 0x00645950
D2SkillStrc* __stdcall SKILLS_AddSkill(D2UnitStrc* pUnit, int nSkillId);                                    // 0x00647110
void __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280
void __stdcall sub_00647AA0_SetSkillBonusLevel(D2UnitStrc* pUnit, int nSkillId, int nBonus);                // 0x00647AA0
unsigned char __stdcall PATH_GetNewDirection(D2DynamicPathStrc* pDynamicPath);                              // 0x00648810
void __stdcall D2COMMON_10160_PathUpdateDirection(D2DynamicPathStrc* pDynamicPath, D2PathDirectionStrc tDirection); // 0x00648820
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY);                   // 0x00648AD0
int __stdcall COMPOSIT_IsWeaponBowOrXBow(D2UnitStrc* pUnit);                                                // 0x0064F460

#define BITARRAY_CHECK(pBytes, nBit) ((pBytes)[(nBit) >> 3] & gdwBitMasks[(nBit) & 7])

static __forceinline D2SkillsTxt* SKILLCLT_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return NULL;
}

static __forceinline D2MonStatsTxt* SKILLCLT_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return NULL;
}

static __forceinline unsigned int SKILLCLT_RollSeed(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

static __forceinline unsigned char SKILLCLT_GetUnitTypeByte(D2UnitStrc* pUnit)
{
    return pUnit->dwUnitType;
}

static __forceinline int SKILLCLT_GetUnitType(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwUnitType : 6;
}

static __forceinline void SKILLCLT_SetCastState(D2UnitStrc* pUnit)
{
    if (pUnit && (pUnit->dwUnitType == 0 || pUnit->dwUnitType == 1))
    {
        sub_00480E70_SetState(pUnit, 1);
    }
}

static __declspec(noinline) int sub_004C5710_GetAttackMode(D2UnitStrc* pUnit)
{
    int nMode = 7;
    D2UnitStrc* pTarget = sub_004648F0_GetTargetUnit(pUnit);
    int bRandom = 1;
    if (pTarget && pTarget->dwUnitType == 1)
    {
        const char nType = UNITS_GetMonStats2TxtRecordFromMonsterId(pTarget->dwClassId)->nType;
        if (nType == 2)
        {
            bRandom = 0;
            nMode = 8;
        }
        if (nType == 1)
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

    if (BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 21) && SKILLCLT_GetUnitType(pTarget) == 1 && pTarget->dwAnimMode == 12)
    {
        return BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 24) != 0;
    }

    return 1;
}

static __declspec(noinline) int __stdcall sub_004C6140_StartSkill(int nOwnerGUID, int nSkillLevel, D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLCLT_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nX;
    int nY;
    int nItemSkillArg;
    if (pSkillsTxtRecord->nLineOfSight && sub_004C52E0_GetTargetPosition(pUnit, &nX, &nY))
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
        if (!sub_00643B00(pSkill, &nItemSkillArg, &nY, &nSkillLevel, &nX) || !nX)
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
        int aArgs[7] = { 0, 0, 0, 0, 0, 0, 0 };
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

    nY = 1;
    const short nStartFunc = pSkillsTxtRecord->wStartFunc;
    if (nStartFunc >= 0 && nStartFunc < gnClientSkillStartFuncs_00727A8C && gpfnClientSkillStartFuncs_00727A90[nStartFunc])
    {
        nY = gpfnClientSkillStartFuncs_00727A90[nStartFunc](pUnit, nSkillId, nSkillLevel);
        if (!nY)
        {
            UNITS_SetUsedSkill(pUnit, NULL);
            SKILLCLT_SetCastState(pUnit);
            if (BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 12))
            {
                return nY;
            }
        }
    }

    short nSound = pSkillsTxtRecord->wStartSound;
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

    const short nClassSound = pSkillsTxtRecord->wStartSoundClass;
    if ((nOwnerGUID == -1 || pSkillsTxtRecord->wItemStartSound <= 0) && nClassSound > 0 && pUnit && pUnit->dwUnitType == 0 && pUnit->dwClassId == pSkillsTxtRecord->nCharClass)
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

    int nOverlay = pSkillsTxtRecord->wCastOverlay;
    if (nOwnerGUID != -1 && pSkillsTxtRecord->wItemCastOverlay > 0)
    {
        nOverlay = pSkillsTxtRecord->wItemCastOverlay;
    }

    if (nOverlay > 0 && nOverlay < sgptDataTables->nOverlayTxtRecordCount && !sub_0046E100(pUnit, nOverlay))
    {
        sub_00470390(pUnit, nOverlay, 2, 0, 0, 0, 0, 0);
    }

    if (nY && pSkillsTxtRecord->wAuraFunc > 0)
    {
        sub_004C5680_StartAura(pUnit, pSkillsTxtRecord->wAuraFunc);
    }

    return nY;
}

// 0x004C6660
int __fastcall sub_004C6660_StartSkillWrapper(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nOwnerGUID)
{
    return sub_004C6140_StartSkill(nOwnerGUID, nSkillLevel, pUnit, nSkillId);
}

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
            UNITS_SetUsedSkill(pUnit, pSkill);
        }
        else
        {
            SKILLS_SetParam4(pSkill, 0);
            UNITS_SetUsedSkill(pUnit, pSkill);
        }
    }
}

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
