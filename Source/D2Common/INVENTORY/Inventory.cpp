#include "D2Common.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"

#define STATEMASK_BLUE 18
#define INVENTORY_SIGNATURE 0x01020304
#define NUM_BODYLOC 11
#define WEAPONCLASS_HT1 12
#define COMPOSIT_RIGHTHAND 5
#define STAT_QUANTITY 70
#define ITEMCODE_ISC 0x20637369
#define ITEMCODE_TSC 0x20637374

struct D2InventoryStrc;
struct Inventory;
struct ItemRecord;
struct AppearanceRecord;
struct ItemData;
struct ItemLink;
struct D2Block1;
struct D2ItemExtraDataStrc;
struct D2ItemDataStrc;
struct D2InventoryPairStrc;
struct D2InventoryGridStrc;
struct D2InventoryNodeStrc;
struct D2CorpseStrc;
struct Obj0063CD20;
struct Obj0063CD40;
struct D2SkillsTxt;
struct D2SkillListStrc;
struct Obj0063D650;
struct Obj0063D670;
struct AppearanceSix;
struct CodeEntry;
struct D2ItemsTxt;
struct D2ItemDataTbl;
struct D2InventoryComponentItemTypeStrc;
struct D2InventoryGridInfoStrc;
struct D2UnitStrc;
struct D2DataTablesStrc;
struct D2SkillStrc;
struct D2CoordStrc;
struct D2StaticPathStrc;
struct D2InvRectStrc;
struct D2BeltsTxt;



extern D2DataTablesStrc* sgptDataTables; // 0x00744304
unsigned int* __stdcall D2COMMON_STATES_GetStatFlags_6FDB8A90(D2UnitStrc* pUnit); // 0x00625BB0

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



extern "C" int __fastcall sub_0045ADF0_GetX(D2UnitStrc* pItem); // 0x0045ADF0
extern "C" int __fastcall sub_0045AE20_GetY(D2UnitStrc* pItem); // 0x0045AE20
extern "C" void __stdcall sub_006286C0_GetSize(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szSource, int nLine); // 0x006286C0
extern "C" void __stdcall sub_00629ED0_SetItemCell(D2UnitStrc* pItem, int nCell); // 0x00629ED0
extern "C" void __stdcall sub_006277F0_RemoveOwnerStat(D2UnitStrc* pOwner, D2UnitStrc* pItem); // 0x006277F0
extern "C" const char gszInventorySource_006EA918; // 0x006EA918
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);



int __fastcall INVENTORY_RemoveItem(D2UnitStrc* pItem); // 0x0063AAF0
void __fastcall FOG_FreePool(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

struct Obj0063CD20 {
    unsigned int dwUnknown00;
    unsigned int dwValue04;
};

struct Obj0063CD40 {
    unsigned int dwValue00;
};


struct D2SkillStrc
{
    D2SkillsTxt* pSkillsTxt;
    D2SkillStrc* pNextSkill;
    char unk0x08[0x2C];
    int nOwnerGUID;
};

struct D2SkillListStrc
{
    void* pMemPool;
    D2SkillStrc* pFirstSkill;
};

struct Obj0063D650 { unsigned int dwUnknown00; unsigned int dwUnknown04; unsigned int dwValue08; };

struct Obj0063D670 { unsigned int dwValue00; };

typedef unsigned short u16;

typedef unsigned int u32;

typedef int s32;

struct AppearanceSix
{
    u8 f_0;
    u8 f_1;
    u8 field2;
    u8 field3;
    u8 f_4;
    u8 field5;
};

struct CodeEntry
{
    u32 code;
    s32 type;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern CodeEntry gTable_0096CC68[]; // 0x0096CC68
s32 __fastcall sub_00451F60_ClassId(Unit*); // 0x00451F60
u8 __stdcall sub_00627D40_Page(Unit*); // 0x00627D40
u8 __stdcall sub_00628660_BodySlot(Unit*); // 0x00628660
int __stdcall ITEMS_CheckType(int nItemType1, int nItemType2); // 0x00629B50
s32 __stdcall sub_0062C100_Transform(Unit*, Unit*, u8*, s32); // 0x0062C100
ItemRecord* __stdcall sub_006335F0_ItemRecord(s32); // 0x006335F0
ItemRecord* __stdcall sub_00633640_RecordByCode(u32, s32*); // 0x00633640
Unit* __stdcall sub_0063C050_BodyItem(Inventory*, s32); // 0x0063C050
u32 __stdcall sub_0064F380_WeaponCode(Unit*, Inventory*, s32*, s32, s32); // 0x0064F380
s32 __stdcall COMPOSIT_IsArmorComponent(s32); // 0x0064F420
s32 __stdcall sub_0064F500_AppearanceIndex(s32, AppearanceSix*); // 0x0064F500
AppearanceRecord* __stdcall sub_0065B620_AppearanceRecord(s32); // 0x0065B620


struct D2ItemDataTbl
{
    int nItemsTxtRecordCount;
    D2ItemsTxt* pItemsTxt;
};

struct D2InventoryComponentItemTypeStrc
{
    int dwCode;
    int nItemType;
};

D2ItemDataTbl* __stdcall DATATBLS_GetItemDataTables(); // 0x00633590
int __stdcall ITEMS_CheckType(int nItemType1, int nItemType2); // 0x00629B50
extern D2InventoryComponentItemTypeStrc gComponentItemTypeMap_00744CA8[283]; // 0x00744CA8
int __stdcall ITEMS_GetAmmoType(D2UnitStrc* pItem); // 0x0062E6F0
int __stdcall ITEMS_GetQuiverType(D2UnitStrc* pItem); // 0x0062E740
unsigned int __stdcall ITEMS_CheckWeaponIfTwoHanded(D2UnitStrc* pItem); // 0x006289C0
int __stdcall ITEMS_Is1Or2Handed(D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x0062A1E0
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

typedef int BOOL;

void* __fastcall FOG_ReallocPool(void* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0); // 0x0040B4B0
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, int nInvPage, int bLoD); // 0x00621050
void __stdcall ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szFile, int nLine); // 0x006286C0
BOOL __stdcall INVENTORY_GetFreePosition(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nInventoryRecordId, int* pFreeX, int* pFreeY, unsigned char nPage); // 0x0063B850

struct D2Block1 { int n[6]; };

void __stdcall sub_0065C1F0(int nInventoryRecordId, int nUnused, D2Block1* pInventoryGridInfo); // 0x0065C1F0
extern unsigned char gaByteTable_00745600[256]; // 0x00745600
extern const signed char gaDirectionDeltaX_006EA998[32]; // 0x006EA998
extern const signed char gaDirectionDeltaY_006EA978[32]; // 0x006EA978
static __declspec(noinline) s32 __cdecl sub_0063D900_FindCode(u32 second, u32 first);
static __declspec(noinline) int sub_0063DBC0_PairIsWieldable(D2UnitStrc* pUnit, D2UnitStrc* pItem1, D2UnitStrc* pItem2);
static __declspec(noinline) BOOL __stdcall INVENTORY_CanItemBePlacedInInventory(D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2InventoryStrc* pInventory);



struct D2InvRectStrc
{
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
};

struct D2BeltsTxt
{
    unsigned char nIndex;
    unsigned char pad0x01[3];
    unsigned char nBoxes;
    unsigned char pad0x05[3];
    D2InvRectStrc beltBoxes[16];
};

extern D2InventoryGridInfoStrc gBodyLocInventoryGridInfo; // 0x0074479C
extern D2InventoryGridInfoStrc gBeltInventoryGridInfo; // 0x007447B4
int __stdcall UNITS_GetBeltType(D2UnitStrc* pUnit); // 0x00621ED0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480
unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo); // 0x00627F80
unsigned char __stdcall ITEMS_GetComponent(D2UnitStrc* pUnit); // 0x00628660
int __stdcall ITEMS_ComparePotionTypes(D2UnitStrc* pItem1, D2UnitStrc* pItem2); // 0x00628A40
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem); // 0x006295B0
unsigned short __stdcall ITEMS_GetWeaponClassId(D2UnitStrc* pUnit); // 0x00629FE0
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400
unsigned int __stdcall ITEMS_CheckIfBeltable(D2UnitStrc* pItem); // 0x0062BAD0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
void __stdcall DATATBLS_GetBeltsTxtRecord(int nIndex, int bHigherRes, D2BeltsTxt* pRecord); // 0x00660CB0
int __stdcall ITEMS_AreStackablesEqual(D2UnitStrc* pItem1, D2UnitStrc* pItem2);
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory);
static __declspec(noinline) D2InventoryGridStrc* __stdcall INVENTORY_GetGrid(D2InventoryStrc* inventory, int index, D2InventoryGridInfoStrc* info); // 0x0063ADD0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBeltSlot(D2InventoryStrc* inventory, int slot); // 0x0063C7F0

// 0x0063A110
int __fastcall STATES_GetNumberOfStateFlags()
{
    return (sgptDataTables->nStatesTxtRecordCount + 31) / 32;
}

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

// 0x0063A530
int __stdcall STATES_CheckStateMaskBlueOnUnit(D2UnitStrc* pUnit)
{
    return sub_0063A130_CheckStateMaskOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_BLUE]);
}

static __forceinline D2ItemExtraDataStrc* sub_0063A7E0(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == 4 && pItem->pItemData)
    {
        return &pItem->pItemData->pExtraData;
    }
    return 0;
}

// 0x0063A810
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

// 0x0063A970
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

// 0x0063AAD0
int __fastcall sub_0063AAD0_IsItem(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_ITEM)
    {
        return 1;
    }
    return 0;
}

// @ref 0x0063AAF0
int __fastcall sub_0063AAF0_RemoveItem(D2UnitStrc* pItem)
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
        const int nItemId = pItem->dwUnitId;
        if (pInventory->dwLeftItemGUID == nItemId)
        {
            pInventory->dwLeftItemGUID = -1;
        }
    return 1;
    }
    return 0;
}

// 0x0063AAF0
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

// 0x0063ABD0
D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void* pMemPool, D2UnitStrc* pOwner)
{
    if (!pMemPool && pOwner)
    {
        pMemPool = pOwner->pMemoryPool;
    }
    D2InventoryStrc* pInventory = (D2InventoryStrc*)FOG_AllocPool(pMemPool, sizeof(D2InventoryStrc), ".\\INVENTORY\\Inventory.cpp", 0x22D, 0);
    if (!pInventory)
    {
        return 0;
    }
    memset(pInventory, 0, sizeof(D2InventoryStrc));
    pInventory->dwSignature = 0x1020304;
    pInventory->pMemPool = pMemPool;
    pInventory->pOwner = pOwner;
    if (pOwner)
    {
        pOwner->pInventory = pInventory;
        pInventory->dwOwnerGuid = !pOwner ? -1 : pOwner->dwUnitId;
    }
    return pInventory;
}

inline D2InventoryStrc* INVENTORY_GetPtrIfValid(D2InventoryStrc* pInventory)
{
    return (pInventory && pInventory->dwSignature == 0x01020304) ? pInventory : 0;
}

// 0x0063AC40
void __stdcall INVENTORY_FreeInventory(D2InventoryStrc* pInventory)
{
    if (INVENTORY_GetPtrIfValid(pInventory))
    {
        if (pInventory->pCursorItem)
        {
            INVENTORY_RemoveItem(pInventory->pCursorItem);
        }

        for (D2UnitStrc* pItem = pInventory->pFirstItem; pItem; pItem = pInventory->pFirstItem)
        {
            INVENTORY_RemoveItem(pItem);
        }

        for (int i = 0; i < pInventory->nGridCount; ++i)
        {
            D2InventoryGridStrc* pGrid = &pInventory->pGrids[i];
            if (pGrid->ppItems)
            {
                FOG_FreePool(pInventory->pMemPool, pGrid->ppItems, gszInventorySourceFile_006EA918, 0x261, 0);
            }
        }

        if (pInventory->pGrids)
        {
            FOG_FreePool(pInventory->pMemPool, pInventory->pGrids, gszInventorySourceFile_006EA918, 0x267, 0);
        }

        if (pInventory->pOwner)
        {
            pInventory->pOwner->pInventory = 0;
        }

        D2InventoryNodeStrc* pNextNode = 0;
        for (D2InventoryNodeStrc* pNode = pInventory->pFirstNode; pNode; pNode = pNextNode)
        {
            pNextNode = pNode->pNext;
            FOG_FreePool(pInventory->pMemPool, pNode, gszInventorySourceFile_006EA918, 0x273, 0);
        }

        D2CorpseStrc* pNextCorpse = 0;
        for (D2CorpseStrc* pCorpse = pInventory->pFirstCorpse; pCorpse; pCorpse = pNextCorpse)
        {
            pNextCorpse = pCorpse->pNextCorpse;
            FOG_FreePool(pInventory->pMemPool, pCorpse, gszInventorySourceFile_006EA918, 0x27B, 0);
        }

        FOG_FreePool(pInventory->pMemPool, pInventory, gszInventorySourceFile_006EA918, 0x27F, 0);
    }
}

int __fastcall sub_G08_Emit_0063DBC0(D2UnitStrc* pItem2, D2UnitStrc* pItem1, D2UnitStrc* pUnit)
{
    return sub_0063DBC0_PairIsWieldable(pUnit, pItem1, pItem2);
}

// build: symbol ?INVENTORY_GetGrid@@YGPAUD2InventoryGridStrc@@PAUD2InventoryStrc@@HPAUD2InventoryGridInfoStrc@@@Z 0x0063ADD0
static __declspec(noinline) D2InventoryGridStrc* __stdcall INVENTORY_GetGrid(D2InventoryStrc* pInventory, int nInventoryGrid, D2InventoryGridInfoStrc* pInventoryGridInfo)
{
    D2InventoryGridStrc* pInventoryGrid;
    if (nInventoryGrid < pInventory->nGridCount)
    {
        pInventoryGrid = &pInventory->pGrids[nInventoryGrid];
        if (!pInventoryGridInfo)
        {
            if (!pInventoryGrid->ppItems)
            {
                return 0;
            }

            return pInventoryGrid;
        }

        if (!pInventoryGrid->ppItems)
        {
            pInventoryGrid->nGridWidth = pInventoryGridInfo->nGridX;
            pInventoryGrid->nGridHeight = pInventoryGridInfo->nGridY;
            pInventoryGrid->ppItems = (D2UnitStrc**)FOG_AllocPool(pInventory->pMemPool, sizeof(D2UnitStrc*) * pInventoryGrid->nGridWidth * pInventoryGrid->nGridHeight, gszInventorySourceFile_006EA918, 721, 0);
            memset(pInventoryGrid->ppItems, 0, sizeof(D2UnitStrc*) * pInventoryGrid->nGridWidth * pInventoryGrid->nGridHeight);
        }

        if (pInventoryGrid->nGridWidth != pInventoryGridInfo->nGridX || pInventoryGrid->nGridHeight != pInventoryGridInfo->nGridY)
        {
            return 0;
        }

        return pInventoryGrid;
    }

    if (!pInventoryGridInfo)
    {
        return 0;
    }

    pInventory->pGrids = (D2InventoryGridStrc*)FOG_ReallocPool(pInventory->pMemPool, pInventory->pGrids, sizeof(D2InventoryGridStrc) * (nInventoryGrid + 1), gszInventorySourceFile_006EA918, 740, 0);
    memset(&pInventory->pGrids[pInventory->nGridCount], 0, sizeof(D2InventoryGridStrc) * (nInventoryGrid - pInventory->nGridCount + 1));
    pInventory->nGridCount = nInventoryGrid + 1;

    pInventoryGrid = &pInventory->pGrids[nInventoryGrid];
    pInventoryGrid->nGridWidth = pInventoryGridInfo->nGridX;
    pInventoryGrid->nGridHeight = pInventoryGridInfo->nGridY;
    pInventoryGrid->ppItems = (D2UnitStrc**)FOG_AllocPool(pInventory->pMemPool, sizeof(D2UnitStrc*) * pInventoryGrid->nGridWidth * pInventoryGrid->nGridHeight, gszInventorySourceFile_006EA918, 747, 0);
    memset(pInventoryGrid->ppItems, 0, sizeof(D2UnitStrc*) * pInventoryGrid->nGridWidth * pInventoryGrid->nGridHeight);
    return pInventoryGrid;
}

// 0x0063B9C0
void __cdecl sub_0063B9C0_Nop()
{
}

// 0x0063BCB0
int __stdcall sub_0063BCB0_AlwaysOne(int nUnused1, int nUnused2, int nUnused3, int nUnused4)
{
    return 1;
}

int __stdcall sub_M421_Emit_0063E1C0(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, D2UnitStrc* pItem)
{
    return INVENTORY_CanItemBePlacedInInventory(pPlayer, pItem, pInventory) + 0x2B;
}

inline D2UnitStrc* INVENTORY_UnitIsItem(D2UnitStrc* pItem)
{
    return (pItem && pItem->dwUnitType == UNIT_ITEM) ? pItem : 0;
}

// 0x0063BD00
void __stdcall sub_0063BD00_Return(int nUnused)
{
}

#include "gen/data/Source/D2Common/INVENTORY/Inventory.inc"

inline D2ItemExtraDataStrc* INVENTORY_GetItemExtraInline(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return &pItem->pItemData->pExtraData;
    }

    return 0;
}

inline D2UnitStrc* INVENTORY_GetNextGridItemInline(D2UnitStrc* pItem)
{
    if (D2ItemExtraDataStrc* pItemExtraData = INVENTORY_GetItemExtraInline(pItem))
    {
        return pItemExtraData->pNextGridItem;
    }

    return 0;
}

static __forceinline unsigned int INVENTORY_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->tGameCoords.nX;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x0063BDE0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc)
{
    if (!pInventory)
    {
        return 0;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return 0;
    }

    if ((unsigned int)nBodyLoc > 12)
    {
        return 0;
    }

    D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_BODYLOC, &gBodyLocInventoryGridInfo);
    if (!pInventoryGrid)
    {
        return 0;
    }

    return pInventoryGrid->ppItems[nBodyLoc];
}

// 0x0063BE30
void __stdcall sub_0063BE30_Return(int nUnused1, int nUnused2)
{
}

D2InventoryGridStrc* __stdcall EmitInventoryGridCaller(D2InventoryStrc* inventory, int index, D2InventoryGridInfoStrc* info)
{
    return INVENTORY_GetGrid(inventory, index, info);
}

static __forceinline D2UnitStrc* GetBodyItem(D2InventoryStrc* pInventory, int nBodyLoc)
{
    if (INVENTORY_GetPtrIfValid(pInventory) && (unsigned int)nBodyLoc <= 12)
    {
        D2InventoryGridStrc* pGrid = INVENTORY_GetGrid(pInventory, INVGRID_BODYLOC, &gBodyLocInventoryGridInfo);
        if (pGrid)
        {
            return pGrid->ppItems[nBodyLoc];
        }
    }
    return 0;
}

// 0x0063BF90
D2UnitStrc* __stdcall sub_0063BF90_GetSecondaryWeapon(D2InventoryStrc* pInventory)
{
    if (!pInventory)
        return 0;
    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
        return 0;
    if (pInventory->dwLeftItemGUID == -1)
        return 0;

    D2UnitStrc* pItem = GetBodyItem(pInventory, BODYLOC_LARM);
    D2UnitStrc* pLeftItem;
    if (pItem)
    {
        pLeftItem = pItem;
        if (!sub_00629BB0_CheckItemType(pItem, 45))
            pLeftItem = 0;
    }
    else
    {
        pLeftItem = 0;
    }

    D2UnitStrc* pRightItem = GetBodyItem(pInventory, BODYLOC_RARM);
    if (!pRightItem || !sub_00629BB0_CheckItemType(pRightItem, 45))
        pRightItem = 0;

    if (pLeftItem && (!pLeftItem ? -1 : pLeftItem->dwUnitId) == pInventory->dwLeftItemGUID)
        return pRightItem;
    if (pRightItem && (!pRightItem ? -1 : pRightItem->dwUnitId) == pInventory->dwLeftItemGUID)
        return pLeftItem;
    return 0;
}

// 0x0063C110
int __stdcall INVENTORY_GetBodyLocFromEquippedItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem)
{
    if (INVENTORY_GetPtrIfValid(pInventory) && INVENTORY_UnitIsItem(pItem))
    {
        const int nBodyLoc = UNITS_GetXPosition(pItem);
        return nBodyLoc < NUM_BODYLOC ? nBodyLoc : 0;
    }

    return 0;
}

// 0x0063C150
int __stdcall INVENTORY_GetItemsXPosition(D2InventoryStrc* pInventory, D2UnitStrc* pItem)
{
    if (INVENTORY_GetPtrIfValid(pInventory) && INVENTORY_UnitIsItem(pItem))
    {
        return UNITS_GetXPosition(pItem);
    }

    return 0;
}

// 0x0063C4B0
int __stdcall sub_00646000_AlwaysZero(int nUnused)
{
    return 0;
}

// 0x0063C550
void __stdcall sub_0063C550_Return(int nUnused1, int nUnused2)
{
}

// 0x0063C830
int __stdcall sub_0063C830_CheckBeltItem(D2InventoryStrc* inventory, D2UnitStrc* item, int slot, D2UnitStrc** previous)
{
    if (!inventory)
        return 0;
    if (inventory->dwSignature != 0x01020304)
        return 0;
    D2InventoryGridStrc* grid = INVENTORY_GetGrid(inventory, 1, &gBeltInventoryGridInfo);
    if (!grid)
        return 0;
    if (!item || item->dwUnitType != 4 || !ITEMS_CheckIfBeltable(item))
        return 0;
    unsigned char width;
    unsigned char height;
    ITEMS_GetDimensions(item, &width, &height, gszInventorySourceFile_006EA918, 0xBC9);
    if (width != 1 || height != 1)
        return 0;
    D2ItemsTxt* record = DATATBLS_GetItemsTxtRecord(!item ? -1 : item->dwClassId);
    if (!record || record->bFlag0x11D != 1 || record->nBelt != 1)
        return 0;
    *previous = INVENTORY_GetItemFromBeltSlot(inventory, slot);
    return 1;
}

void __stdcall sub_00646010_Empty(int nUnused1, int nUnused2, int nUnused3)
{
}

void __stdcall sub_006460C0_Empty(int nUnused)
{
}

void __stdcall sub_006460D0_Empty(int nUnused1, int nUnused2, int nUnused3)
{
}

void __stdcall sub_006460E0_Empty(int nUnused)
{
}

// 0x0063CD20
extern "C" __declspec(dllexport) unsigned int __stdcall sub_0063CD20(Obj0063CD20* pObj) {
    if (!pObj) {
        return 0;
    }
    return pObj->dwValue04;
}

// 0x0063CD40
extern "C" __declspec(dllexport) unsigned int __stdcall sub_0063CD40(Obj0063CD40* pObj) {
    if (!pObj) {
        return 0;
    }
    return pObj->dwValue00;
}

// 0x0063D610
D2CorpseStrc* __stdcall INVENTORY_GetNextCorpse(D2CorpseStrc* pCorpse)
{
    if (!pCorpse)
    {
        return pCorpse;
    }

    return pCorpse->pNextCorpse;
}

D2SkillStrc* __stdcall SKILLS_GetNextSkill(D2SkillStrc* pSkill)
{
    if (!pSkill)
        return 0;
    return pSkill->pNextSkill;
}

// 0x0063D630
D2SkillStrc* __stdcall SKILLS_GetFirstSkillFromSkillList(D2SkillListStrc* pSkillList)
{
    if (!pSkillList)
        return 0;
    return pSkillList->pFirstSkill;
}

D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID)
{
    if (!pUnit->pSkills)
        return 0;
    D2SkillStrc* pSkill = pUnit->pSkills->pFirstSkill;
    if (!pSkill)
        return 0;
    while (pSkill)
    {
        if (pSkill->pSkillsTxt->nSkillId == nSkillId && pSkill->nOwnerGUID == nOwnerGUID)
            break;
        pSkill = pSkill->pNextSkill;
    }
    return pSkill;
}

// 0x0063D650
extern "C" __declspec(dllexport) unsigned int __stdcall sub_0063D650(Obj0063D650* pObj) {
    if (!pObj) {
        return 0;
    }
    return pObj->dwValue08;
}

// 0x0063D670
extern "C" __declspec(dllexport) unsigned int __stdcall sub_0063D670(Obj0063D670* pObj) {
    if (!pObj) {
        return 0;
    }
    return pObj->dwValue00;
}

// 0x0063D690
static __declspec(noinline) void __cdecl sub_0063D690_CopySix(AppearanceSix* output, Unit* item)
{
    if (item)
    {
        ItemRecord* record = sub_006335F0_ItemRecord(FIELD(s32, item, 4));
        D2_ASSERT(record, 0x121E);
        output->f_0 = FIELD(u8, record, 0x116);
        output->f_1 = FIELD(u8, record, 0x117);
        output->field2 = FIELD(u8, record, 0x118);
        output->field3 = FIELD(u8, record, 0x119);
        output->f_4 = FIELD(u8, record, 0x11A);
        output->field5 = FIELD(u8, record, 0x11B);
    }
    else
    {
        memset(output, 0, sizeof(AppearanceSix));
    }
}

static __declspec(noinline) void __stdcall sub_0063D930_WeaponSlots(u8* firstOutput, u8* secondOutput, Unit* item, Unit* unit)
{
    D2_ASSERT(unit, 0x13B3);
    D2_ASSERT(item, 0x13B4);
    const u8 page = sub_00627D40_Page(item);
    if (page == 4 || page == 5)
    {
        Inventory* inventory = FIELD(Inventory*, unit, 0x60);
        s32 mode;
        const u32 weapon = sub_0064F380_WeaponCode(unit, inventory, &mode, -1, 1);
        const u8 slot = sub_00628660_BodySlot(item);
        if (weapon == 0x20776278)
        {
            if (slot == 5 || slot == 6)
            {
                if (inventory)
                {
                    Unit* equipped = sub_0063C050_BodyItem(inventory, 5);
                    if (equipped)
                    {
                        ItemRecord* record = sub_006335F0_ItemRecord(FIELD(s32, equipped, 4));
                        D2_ASSERT(record, 0x13CF);
                        const s32 code = sub_0063D900_FindCode(FIELD(u32, record, 0x80), FIELD(u32, record, 0x90));
                        if (code <= 0)
                        {
                            firstOutput[6] = 0xFF;
                            secondOutput[6] = 0xFF;
                        }
                        else
                        {
                            firstOutput[6] = (u8)code;
                        }
                    }
                }
            }
        }
        else if (weapon == 0x20776F62)
        {
            if (slot == 6)
            {
                s32 recordIndex;
                ItemRecord* record = sub_00633640_RecordByCode(0x2074696C, &recordIndex);
                if (record)
                {
                    const s32 code = sub_0063D900_FindCode(FIELD(u32, record, 0x80), FIELD(u32, record, 0x90));
                    if (!code)
                    {
                        firstOutput[5] = 0xFF;
                        secondOutput[5] = 0xFF;
                    }
                    else
                    {
                        firstOutput[5] = (u8)code;
                    }
                }
            }
        }
    }
}

static __declspec(noinline) void __stdcall sub_0063DA70_ItemSlots(Unit* unit, u8* firstOutput, u8* secondOutput, Unit* item)
{
    Inventory* inventory = FIELD(Inventory*, unit, 0x60);
    if (inventory)
    {
        Unit* firstHand = sub_0063C050_BodyItem(inventory, 5);
        Unit* secondHand = sub_0063C050_BodyItem(inventory, 6);
        ItemRecord* record = sub_006335F0_ItemRecord(item ? FIELD(s32, item, 4) : -1);
        D2_ASSERT(record, 0x140C);
        u8 slot = sub_00628660_BodySlot(item);
        const s32 code = sub_0063D900_FindCode(FIELD(u32, record, 0x80), FIELD(u32, record, 0x90));
        if (!code)
        {
            if (slot < 0x10)
            {
                firstOutput[slot] = 0xFF;
                secondOutput[slot] = 0xFF;
            }
        }
        else
        {
            if (item == firstHand)
            {
                slot = 5;
            }
            else if (item == secondHand)
            {
                slot = 6;
            }
            else if (slot >= 0x10)
            {
                return;
            }
            firstOutput[slot] = (u8)code;
            sub_0063D930_WeaponSlots(firstOutput, secondOutput, item, unit);
            if (!sub_0062C100_Transform(unit, item, &secondOutput[slot], 0))
            {
                secondOutput[slot] = 0xFF;
            }
            else
            {
                ++secondOutput[slot];
            }
        }
    }
}

void __stdcall sub_0063E510_InventoryAppearance(Unit* unit, u8* firstOutput, u8* secondOutput)
{
    Inventory* inventory = FIELD(Inventory*, unit, 0x60);
    if (inventory && FIELD(u32, inventory, 0) == 0x01020304)
    {
        Unit* item = FIELD(Unit*, inventory, 0x0C);
        while (item)
        {
            if (FIELD(u32, item, 0) == 4 && FIELD(s32, item, 0x10) == 1)
            {
                ItemRecord* record = sub_006335F0_ItemRecord(FIELD(s32, item, 4));
                D2_ASSERT(record, 0x1446);
                const u8 page = sub_00627D40_Page(item);
                if (page != 1 && page != 4 && page != 5)
                {
                    if (page == 3)
                    {
                        AppearanceSix appearance;
                        sub_0063D690_CopySix(&appearance, item);
                        for (u32 slot = 0; slot < 0x10; ++slot)
                        {
                            if (COMPOSIT_IsArmorComponent(slot))
                            {
                                AppearanceRecord* appearanceRecord = sub_0065B620_AppearanceRecord(sub_0064F500_AppearanceIndex(slot, &appearance));
                                if (sub_00451F60_ClassId(item) > 0)
                                {
                                    const u32 appearanceCode = FIELD(u32, appearanceRecord, 0x20);
                                    const s32 code = sub_0063D900_FindCode(appearanceCode, appearanceCode);
                                    if (code)
                                    {
                                        if (slot < 0x10)
                                        {
                                            firstOutput[slot] = (u8)code;
                                            if (!sub_0062C100_Transform(unit, item, &secondOutput[slot], 0))
                                            {
                                                secondOutput[slot] = 0xFF;
                                            }
                                            else
                                            {
                                                ++secondOutput[slot];
                                            }
                                        }
                                        continue;
                                    }
                                }
                                if (slot < 0x10)
                                {
                                    firstOutput[slot] = 0xFF;
                                    secondOutput[slot] = 0xFF;
                                }
                            }
                        }
                    }
                }
                else
                {
                    if (!ITEMS_CheckType(FIELD(short, record, 0x11E), 0x4B))
                    {
                        sub_0063DA70_ItemSlots(unit, firstOutput, secondOutput, item);
                    }
                }
            }
            if (FIELD(u32, item, 0) != 4)
            {
                break;
            }
            ItemData* data = FIELD(ItemData*, item, 0x14);
            if (!data)
            {
                break;
            }
            ItemLink* link = (ItemLink*)((u8*)data + 0x5C);
            if (!link)
            {
                break;
            }
            item = FIELD(Unit*, link, 8);
        }
    }
}

static D2InventoryComponentItemTypeStrc gTxtComponentItemTypeMap_0096CC68[255]; // 0x0096CC68

static int gnComponentArrayRecordCount_0096D460; // 0x0096D460

static int gbComponentArrayInitialized_0096D464; // 0x0096D464

// 0x0063D710
void __fastcall INVENTORY_InitializeComponentArray()
{
    if (!gbComponentArrayInitialized_0096D464)
    {
        gbComponentArrayInitialized_0096D464 = 1;

        memset(gTxtComponentItemTypeMap_0096CC68, 0, sizeof(gTxtComponentItemTypeMap_0096CC68));

        D2ItemDataTbl* pItemDataTbl = DATATBLS_GetItemDataTables();

        gTxtComponentItemTypeMap_0096CC68[1].dwCode = 0x2074696C;
        gTxtComponentItemTypeMap_0096CC68[1].nItemType = 3;
        gTxtComponentItemTypeMap_0096CC68[2].dwCode = 0x2064656D;
        gTxtComponentItemTypeMap_0096CC68[2].nItemType = 3;
        gTxtComponentItemTypeMap_0096CC68[3].dwCode = 0x20797668;
        gTxtComponentItemTypeMap_0096CC68[3].nItemType = 3;

        int nCurrentTableEntries = 4;

        for (int i = 0; i < pItemDataTbl->nItemsTxtRecordCount; ++i)
        {
            D2ItemsTxt* pItemsTxtRecord = &pItemDataTbl->pItemsTxt[i];

            int dwCode = 0;
            if (pItemsTxtRecord->dwAltCode2)
            {
                dwCode = pItemsTxtRecord->dwAltCode2;
            }
            else
            {
                dwCode = pItemsTxtRecord->dwCode;
            }

            int bNeedsToBeAdded = 1;
            if (!(ITEMS_CheckType(pItemsTxtRecord->wType[0], 0x2D)
                || ITEMS_CheckType(pItemsTxtRecord->wType[0], 3)
                || ITEMS_CheckType(pItemsTxtRecord->wType[0], 0x33)
                || ITEMS_CheckType(pItemsTxtRecord->wType[0], 0x25))
                || ITEMS_CheckType(pItemsTxtRecord->wType[0], 0x4B))
            {
                bNeedsToBeAdded = 0;
            }

            int bFound = 0;
            for (int nCounter = 0; nCounter < nCurrentTableEntries; ++nCounter)
            {
                if (gTxtComponentItemTypeMap_0096CC68[nCounter].dwCode == dwCode)
                {
                    bFound = 1;
                    break;
                }
            }

            if (!bFound && bNeedsToBeAdded == 1)
            {
                int nIndex = nCurrentTableEntries;

                while (ITEMS_CheckType(gComponentItemTypeMap_00744CA8[nIndex].nItemType, 0x2D) && ITEMS_CheckType(pItemsTxtRecord->wType[0], 0x2D)
                       || ITEMS_CheckType(gComponentItemTypeMap_00744CA8[nIndex].nItemType, 0x32) && ITEMS_CheckType(pItemsTxtRecord->wType[0], 0x32)
                       || gTxtComponentItemTypeMap_0096CC68[nIndex].dwCode)
                {
                    ++nIndex;
                }

                if (nIndex >= 255)
                {
                    nIndex = nCurrentTableEntries;
                }

                gTxtComponentItemTypeMap_0096CC68[nIndex].dwCode = dwCode;
                gTxtComponentItemTypeMap_0096CC68[nIndex].nItemType = pItemsTxtRecord->wType[0];

                if (nCurrentTableEntries == nIndex)
                {
                    ++nCurrentTableEntries;
                }
            }
        }

        gnComponentArrayRecordCount_0096D460 = 255;
    }
}

// 0x0063D900
static __declspec(noinline) s32 __cdecl sub_0063D900_FindCode(u32 second, u32 first)
{
    sub_0063D710_InitCodes();
    for (u32 index = 1; index < 0xFF; ++index)
    {
        const u32 code = gTable_0096CC68[index].code;
        if (code == first || code == second)
        {
            return index;
        }
    }
    return 0;
}

// 0x0063DB90
static int __stdcall sub_0063DB90_SelectValue(int a, int b)
{
    if (b)
        return a ? 5 : 1;
    return a ? 3 : 0;
}

int __stdcall sub_K15_Emit5(int* p, int n)
{
    return sub_0063DB90_SelectValue(p[0], n) + sub_0063DB90_SelectValue(p[n], p[3]);
}

// 0x0063DBC0
static __declspec(noinline) int sub_0063DBC0_PairIsWieldable(D2UnitStrc* pUnit, D2UnitStrc* pItem1, D2UnitStrc* pItem2)
{
    if (!pItem1 || !pItem2
        || ITEMS_GetAmmoType(pItem1) && ITEMSIsA(pItem2, ITEMS_GetAmmoType(pItem1))
        || ITEMS_GetAmmoType(pItem2) && ITEMSIsA(pItem1, ITEMS_GetAmmoType(pItem2)))
    {
        return 1;
    }

    if (ITEMS_GetQuiverType(pItem1) || ITEMS_GetQuiverType(pItem2))
    {
        return 0;
    }

    if (ITEMS_CheckWeaponIfTwoHanded(pItem1) && !ITEMS_Is1Or2Handed(pUnit, pItem1))
    {
        return 0;
    }

    if (ITEMS_CheckWeaponIfTwoHanded(pItem2) && !ITEMS_Is1Or2Handed(pUnit, pItem2))
    {
        return 0;
    }

    if (ITEMSIsA(pItem1, 0x2D) && ITEMSIsA(pItem2, 0x2D))
    {
        if (!pUnit)
        {
            return 0;
        }

        if (pUnit->dwUnitType == 1)
        {
            switch (MONSTERS_GetBaseIdFromMonsterId(pUnit->dwClassId))
            {
            case 0x1A1:
            case 0x1A2:
                return ITEMSIsA(pItem1, 0x43) && ITEMSIsA(pItem2, 0x43);

            case 0x21C:
            case 0x21D:
            case 0x21E:
                return 1;

            default:
                return 0;
            }
        }

        if (pUnit->dwUnitType != 0)
        {
            return 0;
        }

        if (pUnit->dwClassId == 4)
        {
            return 1;
        }

        if (pUnit->dwClassId != 6 || !ITEMSIsA(pItem1, 0x43))
        {
            return 0;
        }

        if (!ITEMSIsA(pItem2, 0x43))
        {
            return 0;
        }
    }
    else
    {
        if (ITEMSIsA(pItem1, 0x2D))
        {
            return 1;
        }

        if (!ITEMSIsA(pItem2, 0x2D))
        {
            return 0;
        }
    }

    return 1;
}

static __forceinline BOOL INVENTORY_TryPlaceInFreePosition(D2InventoryStrc* pInventory, D2InventoryGridStrc* pInventoryGrid, D2UnitStrc* pItem, int nInventoryRecordId, unsigned char* pHeight)
{
    int nX;
    int nY;
    unsigned char nWidth;
    if (pInventoryGrid && INVENTORY_GetFreePosition(pInventory, pItem, nInventoryRecordId, &nX, &nY, 0))
    {
        ITEMS_GetDimensions(pItem, &nWidth, pHeight, gszInventorySourceFile_006EA918, 0x16D5);

        if (nWidth && *pHeight)
        {
            const int nPosX = nX;
            if (nPosX >= 0 && nPosX + nWidth <= pInventoryGrid->nGridWidth && nY >= 0 && nY + *pHeight <= pInventoryGrid->nGridHeight)
            {
                for (int y = nY; y < nY + *pHeight; ++y)
                {
                    for (int x = nPosX; x < nPosX + nWidth; ++x)
                    {
                        pInventoryGrid->ppItems[x + y * pInventoryGrid->nGridWidth] = (D2UnitStrc*)-1;
                    }
                }

                return TRUE;
            }
        }
    }

    return FALSE;
}

// 0x0063E1C0
static __declspec(noinline) BOOL __stdcall INVENTORY_CanItemBePlacedInInventory(D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2InventoryStrc* pInventory)
{
    unsigned char nHeight;
    if (!pInventory)
    {
        return FALSE;
    }

    if (pInventory->dwSignature != 0x1020304)
    {
        return FALSE;
    }

    const int nInventoryRecordId = UNITS_GetInventoryRecordId(pPlayer, 0, TRUE);
    D2InventoryGridInfoStrc tInventoryGridInfo;
    sub_0065C1F0(nInventoryRecordId, 0, (D2Block1*)&tInventoryGridInfo);

    D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, 2, &tInventoryGridInfo);
    return INVENTORY_TryPlaceInFreePosition(pInventory, pInventoryGrid, pItem, nInventoryRecordId, &nHeight);
}

// 0x0063E7A0
unsigned char __stdcall sub_0063E7A0_GetByteTableEntry(unsigned char nIndex)
{
    return gaByteTable_00745600[nIndex];
}

// 0x0063E7E0
void __stdcall sub_0063E7E0_GetDirectionDelta(unsigned char nDirection, int* pX, int* pY)
{
    *pX = gaDirectionDeltaX_006EA998[nDirection];
    *pY = gaDirectionDeltaY_006EA978[nDirection];
}
