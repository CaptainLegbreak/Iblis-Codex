#include "D2Common.h"
#include "D2Structs.h"
#include "D2Structs.h"
#define STATEMASK_ACTIVE 5
#define STATEMASK_REMHIT 6
#define STATEMASK_DAMBLUE 7
#define STATEMASK_DAMRED 8
#define STATEMASK_ATTBLUE 9
#define STATEMASK_ATTRED 10
#define STATEMASK_ARMBLUE 19
#define STATEMASK_RFBLUE 20
#define STATEMASK_RCBLUE 21
#define STATEMASK_RLBLUE 22
#define STATEMASK_RPBLUE 23
#define STATEMASK_RFRED 26
#define STATEMASK_RCRED 27
#define STATEMASK_RLRED 28
#define STATEMASK_RPRED 29
#define STATEMASK_EXP 30
#define STATEMASK_SHATTER 31
#define STATEMASK_LIFE 32
#define STATEMASK_UDEAD 33
#define STATEMASK_GREEN 34
#define STATEMASK_CURABLE 12
#define STATEMASK_RESTRICT 17
#define STATEMASK_ARMRED 25
#define INVENTORY_SIGNATURE 0x01020304
struct D2InventoryStrc;
struct D2ItemExtraDataStrc;
struct D2ItemDataStrc;
struct D2InventoryPairStrc;
struct D2InventoryGridStrc;

struct D2DataTablesStrc
{
    char unk0x000[0xC4];
    int nStatesTxtRecordCount;
    char unk0x0C8[0x4];
    unsigned int* fStateMasks[40];
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304


unsigned int* __stdcall D2COMMON_STATES_GetStatFlags_6FDB8A90(D2UnitStrc* pUnit); // 0x00625BB0
void __stdcall sub_0063A180_UpdateGfxFlagsWithMask(D2UnitStrc* pUnit, unsigned int* pMask); // 0x0063A180
extern unsigned int gdwBitMasks[]; // 0x006CE268

struct D2ItemExtraDataStrc
{
    D2InventoryStrc* pParentInv;
    D2UnitStrc* pPreviousItem;
    D2UnitStrc* pNextItem;
    signed char nNodePos;
    unsigned char nNodePosOther;
    unsigned char pad0E[2];
    D2UnitStrc* pPreviousGridItem;
    D2UnitStrc* pNextGridItem;
};

struct D2ItemDataStrc
{
    unsigned char pad00[EXTRA_OFFSET];
    D2ItemExtraDataStrc pExtraData;
};

struct D2InventoryPairStrc
{
    D2UnitStrc* pFirstItem;
    D2UnitStrc* pLastItem;
};



extern "C" int __fastcall sub_0045ADF0_GetX(D2UnitStrc* pItem);
extern "C" int __fastcall sub_0045AE20_GetY(D2UnitStrc* pItem);
extern "C" void __stdcall sub_006286C0_GetSize(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szSource, int nLine);
extern "C" void __stdcall sub_00629ED0_SetItemCell(D2UnitStrc* pItem, int nCell);
extern "C" void __stdcall sub_006277F0_RemoveOwnerStat(D2UnitStrc* pOwner, D2UnitStrc* pItem);
extern "C" const char gszInventorySource_006EA918;

// 0x0063A130
static __declspec(noinline) int sub_0063A130_CheckStateMaskOnUnit(D2UnitStrc* pUnit, const unsigned int* pStateMask)
{
    unsigned int* pStatFlags = D2COMMON_STATES_GetStatFlags_6FDB8A90(pUnit);
    if (!pStatFlags)
    {
        return 0;
    }

    for (int i = 0; i < (sgptDataTables->nStatesTxtRecordCount + 31) / 32; ++i)
    {
        if (pStatFlags[i] & pStateMask[i])
        {
            return 1;
        }
    }

    return 0;
}

// 0x0063A250
int __stdcall STATES_CheckStateMaskAuraOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_AURA]);
}

// 0x0063A2B0
int __stdcall STATES_CheckStateMaskPgsvOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_PGSV]);
}

// 0x0063A320
int __stdcall STATES_CheckStateMaskHideOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_HIDE]);
}

// 0x0063A340
int __stdcall STATES_CheckStateMaskActiveOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_ACTIVE]);
}

// 0x0063A360
int __stdcall STATES_CheckStateMaskRemHitOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_REMHIT]);
}

// 0x0063A380
int __stdcall sub_0063A380(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_DAMBLUE]);
}

// 0x0063A3A0
int __stdcall sub_0063A3A0(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_DAMRED]);
}

// 0x0063A3C0
int __stdcall STATES_CheckStateMaskAttBlueOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_ATTBLUE]);
}

// 0x0063A3E0
int __stdcall STATES_CheckStateMaskAttRedOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_ATTRED]);
}

// 0x0063A550
int __stdcall STATES_CheckStateMaskArmBlueOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_ARMBLUE]);
}

// 0x0063A570
int __stdcall STATES_CheckStateMaskRFBlueOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_RFBLUE]);
}

// 0x0063A590
int __stdcall STATES_CheckStateMaskRCBlueOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_RCBLUE]);
}

// 0x0063A5B0
int __stdcall STATES_CheckStateMaskRLBlueOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_RLBLUE]);
}

// 0x0063A5D0
int __stdcall STATES_CheckStateMaskRPBlueOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_RPBLUE]);
}

// 0x0063A610
int __stdcall STATES_CheckStateMaskRFRedOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_RFRED]);
}

// 0x0063A630
int __stdcall STATES_CheckStateMaskRCRedOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_RCRED]);
}

// 0x0063A650
int __stdcall STATES_CheckStateMaskRLRedOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_RLRED]);
}

// 0x0063A670
int __stdcall STATES_CheckStateMaskRPRedOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_RPRED]);
}

// 0x0063A690
int __stdcall STATES_CheckStateMaskExpOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_EXP]);
}

// 0x0063A6F0
int __stdcall STATES_CheckStateMaskShatterOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_SHATTER]);
}

// 0x0063A750
int __stdcall STATES_CheckStateMaskLifeOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_LIFE]);
}

// 0x0063A770
int __stdcall STATES_CheckStateMaskUdeadOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_UDEAD]);
}

// 0x0063A790
int __stdcall STATES_CheckStateMaskGreenOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_GREEN]);
}

// 0x0063A7B0
int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask)
{
    if (pUnit && nStateMask >= 0 && nStateMask < 40)
    {
        return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[nStateMask]);
    }

    return 0;
}

// 0x0063A2D0
void __stdcall STATES_UpdatePgsvFlags(D2UnitStrc* pUnit)
{
    sub_0063A180_UpdateGfxFlagsWithMask(pUnit, sgptDataTables->fStateMasks[STATEMASK_PGSV]);
}

__forceinline int __fastcall STATES_CheckStateMaskByStateId(int nState, int nStateMask)
{
    if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
    {
        return sgptDataTables->fStateMasks[nStateMask][nState >> 5] & gdwBitMasks[nState & 31];
    }

    return 0;
}

// 0x0063A460
int __stdcall STATES_CheckStateMaskCurableByStateId(int nState)
{
    return STATES_CheckStateMaskByStateId(nState, STATEMASK_CURABLE);
}

// 0x0063A6B0
int __stdcall STATES_CheckStateMaskExpByStateId(int nState)
{
    return STATES_CheckStateMaskByStateId(nState, STATEMASK_EXP);
}

// 0x0063A710
int __stdcall STATES_CheckStateMaskShatterByStateId(int nState)
{
    return STATES_CheckStateMaskByStateId(nState, STATEMASK_SHATTER);
}

// 0x0063A4A0
int __stdcall STATES_CheckStateMaskStayDeathOnUnitByStateId(D2UnitStrc* pUnit, int nState)
{
    if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
    {
        const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
        if (nUnitType == UNIT_MONSTER)
        {
            return sgptDataTables->fStateMasks[STATEMASK_MONSTAYDEATH][nState >> 5] & gdwBitMasks[nState & 31];
        }
        else
        {
            return sgptDataTables->fStateMasks[STATEMASK_PLRSTAYDEATH][nState >> 5] & gdwBitMasks[nState & 31];
        }
    }

    return 0;
}

// 0x0063A510
int __fastcall STATES_CheckStateMaskRestrictOnUnit(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_RESTRICT]);
}

// 0x0063A5F0
int __stdcall STATES_CheckStateMaskArmRedOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_ARMRED]);
}

// 0x0063A7E0
static __forceinline D2ItemExtraDataStrc* sub_0063A7E0(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == 4 && pItem->pItemData)
    {
        return &pItem->pItemData->pExtraData;
    }
    return 0;
}

static __declspec(noinline) void __cdecl sub_0063A810_UnlinkPair(D2InventoryPairStrc* pPair, D2UnitStrc* pItem)
{
    const int nType = pItem ? pItem->dwUnitType : -1;
    if (nType != 4)
    {
        return;
    }
    D2ItemExtraDataStrc* pExtra = sub_0063A7E0(pItem);
    if (!pExtra)
    {
        return;
    }
    if (!pExtra->pPreviousItem)
    {
        if (pPair->pFirstItem == pItem)
        {
            pPair->pFirstItem = pExtra->pNextItem;
        }
    }
    else
    {
        D2ItemExtraDataStrc* pPrevious = sub_0063A7E0(pExtra->pPreviousItem);
        if (pPrevious)
        {
            pPrevious->pNextItem = pExtra->pNextItem;
        }
    }
    if (!pExtra->pNextItem)
    {
        if (pPair->pLastItem == pItem)
        {
            pPair->pLastItem = pExtra->pPreviousItem;
        }
    }
    else
    {
        D2ItemExtraDataStrc* pNext = sub_0063A7E0(pExtra->pNextItem);
        if (pNext)
        {
            pNext->pPreviousItem = pExtra->pPreviousItem;
        }
    }
    pExtra->pNextItem = 0;
    pExtra->pPreviousItem = 0;
}

static __declspec(noinline) void __stdcall sub_0063A970_UnlinkGrid(D2InventoryGridStrc* pGrid, int bMultiCell, D2UnitStrc* pItem)
{
    const int nType = pItem ? pItem->dwUnitType : -1;
    if (nType != 4)
    {
        return;
    }
    D2ItemExtraDataStrc* pExtra = sub_0063A7E0(pItem);
    if (!pExtra)
    {
        return;
    }
    if (!pExtra->pPreviousGridItem)
    {
        if (pGrid->pItem == pItem)
        {
            pGrid->pItem = pExtra->pNextGridItem;
        }
    }
    else
    {
        D2ItemExtraDataStrc* pPrevious = sub_0063A7E0(pExtra->pPreviousGridItem);
        if (pPrevious)
        {
            pPrevious->pNextGridItem = pExtra->pNextGridItem;
        }
    }
    if (!pExtra->pNextGridItem)
    {
        if (pGrid->pLastItem == pItem)
        {
            pGrid->pLastItem = pExtra->pPreviousGridItem;
        }
    }
    else
    {
        D2ItemExtraDataStrc* pNext = sub_0063A7E0(pExtra->pNextGridItem);
        if (pNext)
        {
            pNext->pPreviousGridItem = pExtra->pPreviousGridItem;
        }
    }
    if (pGrid->ppItems)
    {
        if (bMultiCell)
        {
            const int nX = sub_0045ADF0_GetX(pItem);
            const int nY = sub_0045AE20_GetY(pItem);
            unsigned char nWidth;
            unsigned char nHeight;
            sub_006286C0_GetSize(pItem, &nWidth, &nHeight, &gszInventorySource_006EA918, SIZE_LINE);
            for (int nRow = nY; nRow < nY + nHeight; ++nRow)
            {
                D2UnitStrc** ppRow = pGrid->ppItems + nRow * pGrid->nGridWidth;
                for (int nColumn = nX; nColumn < nX + nWidth; ++nColumn)
                {
                    ppRow[nColumn] = 0;
                }
            }
        }
        else
        {
            const int nX = sub_0045ADF0_GetX(pItem);
            const int nY = sub_0045AE20_GetY(pItem);
            pGrid->ppItems[nX + nY * pGrid->nGridWidth] = 0;
        }
    }
    pExtra->pNextGridItem = 0;
    pExtra->pPreviousGridItem = 0;
    pExtra->nNodePos = 0;
}

int __fastcall INVENTORY_RemoveItem(D2UnitStrc* pItem)
{
    const int nType = pItem ? pItem->dwUnitType : -1;
    if (nType == 4)
    {
        D2ItemExtraDataStrc* pExtra = sub_0063A7E0(pItem);
        if (!pExtra)
        {
            return 0;
        }
        D2InventoryStrc* pInventory = pExtra->pParentInv;
        if (!pInventory)
        {
            return 0;
        }
        if (pInventory->dwSignature != INVENTORY_SIGNATURE)
        {
            return 0;
        }
        if (pExtra->nNodePos > 0)
        {
            const int nGrid = pExtra->nNodePos - 1;
            if (pInventory->nGridCount > nGrid)
            {
                sub_0063A970_UnlinkGrid(&pInventory->pGrids[nGrid], nGrid >= 1, pItem);
            }
        }
        if (pInventory->pCursorItem == pItem)
        {
            pInventory->pCursorItem = 0;
        }
        else
        {
            sub_0063A810_UnlinkPair((D2InventoryPairStrc*)&pInventory->pFirstItem, pItem);
            --pInventory->dwItemCount;
        }
        pExtra->pParentInv = 0;
        pExtra->nNodePos = 0;
        pExtra->nNodePosOther = 0;
        sub_00629ED0_SetItemCell(pItem, -1);
        if (pInventory->pOwner)
        {
            sub_006277F0_RemoveOwnerStat(pInventory->pOwner, pItem);
        }
        if (pInventory->dwLeftItemGUID == (!pItem ? -1 : pItem->dwUnitId))
        {
            pInventory->dwLeftItemGUID = -1;
        }
    return 1;
    }
    return 0;
}

// 0x00405A50
void __cdecl sub_00405A50_Nop()
{
}

// 0x00405A60
void __cdecl sub_00405A60_Nop()
{
}

// 0x0063A800
void __cdecl sub_0063A800_Nop()
{
}

// 0x004DF920
void __cdecl sub_004DF920_Nop()
{
}

// 0x004DF930
void __cdecl sub_004DF930_Nop()
{
}

// 0x00587830
void __cdecl sub_00587830_Nop()
{
}
