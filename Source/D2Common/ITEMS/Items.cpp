#include "D2Common.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Records.h"
#include "D2ItemsWorld.h"
#include "D2LevelTxt.h"
#include "D2GameRecords.h"
#include "D2TxtTables.h"
#include "D2Primitives.h"
#define STAT_ITEM_INDESCTRUCTIBLE 152
#define IFLAG_IDENTIFIED 0x00000010
#define NODEPAGE_STORAGE 1
#define NODEPAGE_EQUIP 3
#define INVPAGE_CUBE 3
#define INVPAGE_NULL 255
#define ITEMTYPE_SCROLL 22
#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))
#define IFLAG_ETHEREAL 0x00400000
#define BODYLOC_NONE 0
#define STATEMASK_CURSE 11
#define UNITFLAGEX_ISSHAPESHIFTED_BIT 3
#define ITEMTYPE_QUEST 39
#define STAT_ITEM_NUMSOCKETS 194
#define IFLAG_ISEAR 0x00010000
#define IFLAG_COMPACTSAVE_LOWQUALITY 0x02200000
#define STAT_QUANTITY 0x46
#define STAT_ITEM_THROWABLE 0x7D
#define BODYLOC_SWRARM 11
#define BODYLOC_SWLARM 12
#define ITEMVERSION 0x60
#define IFLAG_NOSELL 0x00001000
#define ITEMTYPE_SOCKET_FILLER 0x35
#define NUMBER_OF_PLAYERCLASSES 7
#define WEAPONCLASS_HTH 0
#define STAT_DEXTERITY 2
#define STAT_LEVEL 12

struct D2InventoryStrc;
struct D2ItemDataStrc;
struct D2ItemsTxt;
struct D2BooksTxt;
union D2SeedStrc;
struct D2RunesTxt;
struct D2RuneDataTbl;
struct Data00627DF0;
struct Unit00627DF0;
struct Data00627EA0;
struct Unit00627EA0;
struct Data00627EF0;
struct Unit00627EF0;
struct Data00627F20;
struct Unit00627F20;
struct Data00627F50;
struct Unit00627F50;
struct Data00627FB0;
struct Unit00627FB0;
struct Data00627FE0;
struct Unit00627FE0;
struct Data00628040;
struct Unit00628040;
struct Data00628070;
struct Unit00628070;
struct Data006280A0;
struct Unit006280A0;
struct Data00628140;
struct Unit00628140;
struct Data00628250;
struct Unit00628250;
struct D2ItemSaveStrc;
struct Data00629EA0;
struct Unit00629EA0;
struct D2StatesTxt;
struct D2MagicAffixTxt;
struct D2UniqueItemsTxt;
struct D2SetItemsTxt;
struct D2GemsTxt;
struct D2ItemStatCostTxt;
struct D2UnitStrc;
struct D2DataTablesStrc;
struct D2BitBufferStrc;
struct D2ItemTypesTxt;
struct D2WeaponClassCodeStrc;
struct D2StatStrc;




extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

struct D2ItemsTxt
{
    char unk0x00[128];
    unsigned int dwCode;
    unsigned int dwNormCode;
    unsigned int dwUberCode;
    unsigned int dwUltraCode;
    unsigned int dwAlternateGfx;
    char unk0x94[44];
    unsigned int dwWeapClass;
    unsigned int dwWeapClass2Hand;
    unsigned char unk_C8[0x8];
    int dwMaxAc;
    unsigned int dwGambleCost;
    int dwSpeed;
    unsigned int dwBitField1;
    unsigned int dwCost;
    unsigned int dwMinStack;
    unsigned int dwMaxStack;
    unsigned char unk_EC[0x4];
    int dwGemOffset;
    unsigned char unk_F4[0x6];
    unsigned short wMissileType;
    char unk0xFC[1];
    unsigned char nLevel;
    unsigned char nMinDam;
    unsigned char nMaxDam;
    unsigned char nMinMisDam;
    unsigned char nMaxMisDam;
    unsigned char n2HandMinDam;
    unsigned char n2HandMaxDam;
    unsigned char nRangeAdder;
    char unk0x105[1];
    short nStrBonus;
    short nDexBonus;
    unsigned short wReqStr;
    unsigned short wReqDex;
    unsigned char unk_10E[0x1];
    unsigned char nInvWidth;
    unsigned char nInvHeight;
    unsigned char unk_111[0x1];
    unsigned char nDurability;
    unsigned char nNoDurability;
    unsigned char unk_114[0x1];
    unsigned char nComponent;
    char unk0x116[6];
    unsigned char n2Handed;
    unsigned char nUseable;
    short wType[2];
    char unk0x122[7];
    unsigned char nUnique;
    unsigned char nQuest;
    char unk0x12B[7];
    unsigned char nStackable;
    unsigned char unk_133[0x1];
    unsigned char nSpellIcon;
    unsigned char nDurWarning;
    unsigned char nQuantityWarning;
    unsigned char nHasInv;
    unsigned char nGemSockets;
    char unk0x139[3];
    unsigned char nHitClass;
    unsigned char n1or2Handed;
    unsigned char unk_13E[0x3];
    unsigned char nTransform;
    unsigned char nInvTrans;
    unsigned char unk_143[0x65];
};



extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned int gdwBitMasks[32]; // 0x006CE268


int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480
int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit); // 0x00625E00
unsigned int __stdcall ITEMS_GetItemTypeFromItemId(unsigned int dwItemId); // 0x00628700
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
D2BooksTxt* __stdcall DATATBLS_GetBooksTxtRecord(int nIndex); // 0x006374B0
int __fastcall INVENTORY_RemoveItem(D2UnitStrc* pItem); // 0x0063AAF0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0
int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem); // 0x0063E020


struct D2RunesTxt
{
    char unk0x00[0x120];
};


extern D2RuneDataTbl sgtRuneWordsTblDesc; // 0x0096CA98
void __fastcall SEED_InitSeed(D2SeedStrc* pSeed); // 0x00650E30
int __fastcall ITEMS_SerializeItem(D2UnitStrc* pItem, D2BitBufferStrc* pBuffer, int bServer, int bSaveItemInv, int bGamble); // 0x006312B0
int __stdcall sub_00625B70_CheckStatFlag(D2UnitStrc* pUnit, int nState); // 0x00625B70

struct Data00627DF0 { unsigned char bUnknown00[0x10]; unsigned int dwValue10; };

struct Unit00627DF0 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data00627DF0* pData; };

struct Data00627EA0 { unsigned int dwValue00; };

struct Unit00627EA0 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data00627EA0* pData; };

struct Data00627EF0 { unsigned char bUnknown00[0x38]; unsigned short wValues38[1]; };

struct Unit00627EF0 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data00627EF0* pData; };

struct Data00627F20 { unsigned char bUnknown00[0x36]; unsigned short wValue36; };

struct Unit00627F20 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data00627F20* pData; };

struct Data00627F50 { unsigned char bUnknown00[0x36]; unsigned short wValue36; };

struct Unit00627F50 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data00627F50* pData; };

struct Data00627FB0 { unsigned char bUnknown00[0x3E]; unsigned short wValues3E[1]; };

struct Unit00627FB0 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data00627FB0* pData; };

struct Data00627FE0 { unsigned char bUnknown00[0x32]; unsigned short wValue32; };

struct Unit00627FE0 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data00627FE0* pData; };

struct Data00628040 { unsigned char bUnknown00[0x34]; unsigned short wValue34; };

struct Unit00628040 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data00628040* pData; };

struct Data00628070 { unsigned char bUnknown00[0x34]; unsigned short wValue34; };

struct Unit00628070 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data00628070* pData; };

struct Data006280A0 { unsigned char bUnknown00[0x18]; unsigned int dwFlags18; };

struct Unit006280A0 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data006280A0* pData; };

struct Data00628140 { unsigned char bUnknown00[0x14]; unsigned int dwFlags14; };

struct Unit00628140 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data00628140* pData; };

struct Data00628250 { unsigned char bUnknown00[0x45]; char cValue45; };

struct Unit00628250 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data00628250* pData; };


int __stdcall DATATBLS_GetItemIdFromItemCode(unsigned int dwCode); // 0x00633680

struct Data00629EA0 { unsigned char bUnknown00[0x1C]; unsigned int dwValue1C; unsigned int dwValue20; };

struct Unit00629EA0 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data00629EA0* pData; };

int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70





struct D2GemsTxt
{
    char unk0x00[0x2F];
    unsigned char nTransform;
};

int __fastcall sub_00451F60_UnitClassId(D2UnitStrc* pUnit); // 0x00451F60
D2SetItemsTxt* __fastcall sub_00483440_GetSetItemsTxtRecord(int nIndex); // 0x00483440
D2UniqueItemsTxt* __fastcall sub_00483470_GetUniqueItemsTxtRecord(int nIndex); // 0x00483470
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0
unsigned char __stdcall sub_0062BC20(D2UnitStrc* pItem); // 0x0062BC20
D2MagicAffixTxt* __stdcall DATATBLS_GetMagicAffixTxtRecord(int nIndex); // 0x00633EE0
D2GemsTxt* __stdcall DATATBLS_GetGemsTxtRecord(int nGemId); // 0x006372C0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStat, int nLayer); // 0x00625500
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer); // 0x00627260
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem); // 0x006295B0
int __fastcall sub_0062B5B0(D2UnitStrc* pItem, D2UnitStrc* pUnit); // 0x0062B5B0
unsigned int __stdcall ITEMS_GetWeaponClassCode(D2UnitStrc* pItem); // 0x00628500
void __stdcall D2Common_10884_COMPOSIT_unk(D2UnitStrc* pUnit, int nClassId, int nMode, int nUnitType, D2InventoryStrc* pInventory, char* szPath, int* pWeaponClassCode, int a8, int a9); // 0x0064F5B0
int __stdcall DATATBLS_GetAnimDataInfo(char* szPath, int* pOutLength, int* pOutAnimSpeed, int* pOutFirstFrameTagged); // 0x0066AA80
int __stdcall sub_0062AE20(unsigned char* pBitstream, unsigned int nSize, int bCheckForHeader, void* pItemSave, unsigned int dwVersion); // 0x0062AE20
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400
void __stdcall ITEMS_GetAllowedBodyLocations(D2UnitStrc* pItem, unsigned char* pBodyLoc1, unsigned char* pBodyLoc2); // 0x0062EA80
int __stdcall ITEMS_CheckRequirements(D2UnitStrc* pItem, D2UnitStrc* pPlayer, int bEquipping, int* a4, int* a5, int* a6); // 0x0062EAF0
unsigned int* __stdcall D2COMMON_STATES_GetStatFlags_6FDB8A90(D2UnitStrc* pUnit); // 0x00625BB0
unsigned int* __stdcall D2COMMON_STATES_GetListGfxFlags_6FDB8AC0(D2UnitStrc* pUnit); // 0x00625BE0
extern "C" char* __cdecl strcpy(char* pDst, const char* pSrc);
unsigned int __stdcall ITEMS_GetNormalCode(D2UnitStrc* pItem); // 0x006287D0
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640

struct D2ItemStatCostTxt
{
    char unk0x00[0x18];
    unsigned char nValShift;
    unsigned char nSaveBits[2];
    char pad0x1B[0x01];
    int dwSaveAdd[2];
    int dwSaveParamBits[2];
};

void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150
unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem); // 0x00628590
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80
extern char* gpszDefaultString; // 0x007446E4
static __declspec(noinline) int sub_0062A2F0_IsPlainQuality(int nQuality);
static void __stdcall ITEMS_SetDefenseOrDamage(D2UnitStrc* pItem, int nStat);

struct D2WeaponClassCodeStrc
{
    unsigned int dwCode;
    int nWeaponClassId;
};

extern D2WeaponClassCodeStrc gWeaponClassTable[]; // 0x007446A0
extern unsigned int gnWeaponClassTableCount; // 0x007446E0
int __stdcall ITEMS_IsNotQuestItemByItemId(int nItemId); // 0x00629D40
int __stdcall INVENTORY_HasSimilarPotionInBelt(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063C560


int __stdcall STATLIST_CopyStats(D2UnitStrc* pUnit, int nStatId, D2StatStrc* pBuffer, int nBufferSize); // 0x006261D0
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820
int __stdcall ITEMS_GetLevelRequirement(D2UnitStrc* pItem, D2UnitStrc* pUnit); // 0x0062BA60

inline int ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag);

// 0x00627C90
void __stdcall ITEMS_AllocItemData(void* pMemPool, D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == 4)
    {
        D2ItemDataStrc* pItemData = (D2ItemDataStrc*)sub_0040B430(pMemPool, sizeof(D2ItemDataStrc), ".\\ITEMS\\Items.cpp", 210, 0);
        D2_ASSERT(pItemData, 213);
        memset(pItemData, 0, sizeof(D2ItemDataStrc));
        pItemData->dwOwnerGUID = -1;
        pItem->pItemData = pItemData;
    }
}

inline D2ItemDataStrc* ITEMS_GetItemData(D2UnitStrc* pItem)
{
    return (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData) ? pItem->pItemData : 0;
}

inline unsigned int ITEMS_TestItemFlag(D2UnitStrc* pItem, unsigned int dwFlag)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return pItem->pItemData->dwItemFlags & dwFlag;
    }

    return 0;
}

inline unsigned char ITEMS_GetInvPage(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return pItem->pItemData->nInvPage;
    }

    return INVPAGE_NULL;
}

// 0x00627D00
void __stdcall ITEMS_FreeItemData(void* pMemPool, D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        INVENTORY_RemoveItem(pItem);
        if (pItem->pItemData)
        {
            FOG_FreeServerMemory(pMemPool, pItem->pItemData, ".\\ITEMS\\Items.cpp", 266, 0);
        }
    }
}

inline D2ItemTypesTxt* DATATBLS_GetItemTypesTxtRecord(int nItemType)
{
    if (nItemType >= 0 && nItemType < sgptDataTables->nItemTypesTxtRecordCount)
    {
        return &sgptDataTables->pItemTypesTxt[nItemType];
    }

    return 0;
}

// 0x00627D40
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->nBodyLoc;
    }

    return BODYLOC_NONE;
}

// 0x00627D70
void __stdcall ITEMS_SetBodyLocation(D2UnitStrc* pItem, unsigned char nBodyLoc)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        pItemData->nBodyLoc = nBodyLoc;
    }
}

// 0x00627D90
D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return &pItemData->pSeed;
    }

    return 0;
}

// 0x00627DC0
void __stdcall ITEMS_InitItemSeed(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        SEED_InitSeed(&pItemData->pSeed);
    }
}

// 0x00627DF0
extern "C" __declspec(dllexport) unsigned int __stdcall sub_00627DF0(Unit00627DF0* pUnit) {
    if (pUnit && pUnit->nType == 4 && pUnit->pData) {
        return pUnit->pData->dwValue10;
    }
    return 0;
}

// 0x00627E20
void __stdcall ITEMS_SetItemStartSeed(D2UnitStrc* pItem, int nSeed)
{
    D2_ASSERT(pItem, 391);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 392);
    D2_ASSERT(pItem->pItemData, 395);
    pItem->pItemData->dwInitSeed = nSeed;
}

// 0x00627E70
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->dwQualityNo;
    }

    return ITEMQUAL_NORMAL;
}

// 0x00627EA0
extern "C" __declspec(dllexport) void __stdcall sub_00627EA0(Unit00627EA0* pUnit, unsigned int dwValue) {
    if (pUnit && pUnit->nType == 4 && pUnit->pData) {
        pUnit->pData->dwValue00 = dwValue;
    }
}

// 0x00627EC0
unsigned short __stdcall ITEMS_GetPrefixId(D2UnitStrc* pItem, int nPrefixNo)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->wMagicPrefix[nPrefixNo];
    }

    return 0;
}

// 0x00627EF0
extern "C" __declspec(dllexport) void __stdcall sub_00627EF0(Unit00627EF0* pUnit, unsigned short wValue, int nIndex) {
    if (pUnit && pUnit->nType == 4 && pUnit->pData) {
        pUnit->pData->wValues38[nIndex] = wValue;
    }
}

// 0x00627F20
extern "C" __declspec(dllexport) unsigned short __stdcall sub_00627F20(Unit00627F20* pUnit) {
    if (pUnit && pUnit->nType == 4 && pUnit->pData) {
        return pUnit->pData->wValue36;
    }
    return 0;
}

// 0x00627F50
extern "C" __declspec(dllexport) void __stdcall sub_00627F50(Unit00627F50* pUnit, unsigned short wValue) {
    if (pUnit && pUnit->nType == 4 && pUnit->pData) {
        pUnit->pData->wValue36 = wValue;
    }
}

// 0x00627F80
unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->wMagicSuffix[nSuffixNo];
    }

    return 0;
}

// 0x00627FB0
extern "C" __declspec(dllexport) void __stdcall sub_00627FB0(Unit00627FB0* pUnit, unsigned short wValue, int nIndex) {
    if (pUnit && pUnit->nType == 4 && pUnit->pData) {
        pUnit->pData->wValues3E[nIndex] = wValue;
    }
}

// 0x00627FE0
extern "C" __declspec(dllexport) unsigned short __stdcall sub_00627FE0(Unit00627FE0* pUnit) {
    if (pUnit && pUnit->nType == 4 && pUnit->pData) {
        return pUnit->pData->wValue32;
    }
    return 0;
}

// 0x00628010
void __stdcall ITEMS_AssignRarePrefix(D2UnitStrc* pItem, unsigned short nPrefix)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        pItemData->wRarePrefix = nPrefix;
    }
}

// 0x00628040
extern "C" __declspec(dllexport) unsigned short __stdcall sub_00628040(Unit00628040* pUnit) {
    if (pUnit && pUnit->nType == 4 && pUnit->pData) {
        return pUnit->pData->wValue34;
    }
    return 0;
}

// 0x00628070
extern "C" __declspec(dllexport) void __stdcall sub_00628070(Unit00628070* pUnit, unsigned short wValue) {
    if (pUnit && pUnit->nType == 4 && pUnit->pData) {
        pUnit->pData->wValue34 = wValue;
    }
}

// 0x006280A0
extern "C" __declspec(dllexport) unsigned int __stdcall sub_006280A0(Unit006280A0* pUnit, unsigned int dwMask, unsigned int dwUnused3, unsigned int dwUnused4) {
    if (pUnit && pUnit->nType == 4 && pUnit->pData) {
        return pUnit->pData->dwFlags18 & dwMask;
    }
    return 0;
}

// 0x006280D0
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        if (bSet)
        {
            pItemData->dwItemFlags |= dwFlag;
        }
        else
        {
            pItemData->dwItemFlags &= ~dwFlag;
        }
    }
}

// 0x00628110
unsigned int __stdcall ITEMS_GetItemFlags(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == 4 && pItem->pItemData)
        return pItem->pItemData->dwItemFlags;
    return 0;
}

// 0x00628140
extern "C" __declspec(dllexport) unsigned int __stdcall sub_00628140(Unit00628140* pUnit, unsigned int dwMask) {
    if (pUnit && pUnit->nType == 4 && pUnit->pData) {
        return pUnit->pData->dwFlags14 & dwMask;
    }
    return 0;
}

// 0x00628170
void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc* pItem, int nFlag, int bSet)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        if (bSet)
        {
            pItemData->dwCommandFlags |= nFlag;
        }
        else
        {
            pItemData->dwCommandFlags &= ~nFlag;
        }
    }
}

// 0x006281B0
unsigned int __stdcall ITEMS_GetItemCMDFlags(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->dwCommandFlags;
    }

    return 0;
}

// 0x006281E0
int __stdcall ITEMS_GetItemLevel(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        if (pItemData->dwItemLevel < 1)
        {
            pItemData->dwItemLevel = 1;
        }
        return pItemData->dwItemLevel;
    }

    return 1;
}

inline D2ItemDataStrc* ITEMS_GetItemDataByType(D2UnitStrc* pItem)
{
    const int nType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    return (nType == UNIT_ITEM && pItem->pItemData) ? pItem->pItemData : 0;
}

inline unsigned int ITEMS_CheckItemFlagInline(D2UnitStrc* pItem, unsigned int dwFlag)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemDataByType(pItem))
        return pItemData->dwItemFlags & dwFlag;

    return 0;
}

// 0x00628220
void __stdcall ITEMS_SetItemLevel(D2UnitStrc* pItem, int nItemLevel)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemDataByType(pItem))
    {
        if (nItemLevel < 1)
            nItemLevel = 1;
        pItemData->dwItemLevel = nItemLevel;
    }
}

// 0x00628250
extern "C" __declspec(dllexport) char __stdcall sub_00628250(Unit00628250* pUnit) {
    if (pUnit && pUnit->nType == 4 && pUnit->pData) {
        return pUnit->pData->cValue45;
    }
    return -1;
}

// 0x00628280
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        pItemData->nInvPage = nPage;
    }
}

// 0x006282D0
void __stdcall ITEMS_SetCellOverlap(D2UnitStrc* pItem, int nCellOverlap)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        pItemData->nCellOverlap = nCellOverlap;
    }
}

// 0x006282F0
unsigned char __stdcall ITEMS_GetItemCell(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->nItemCell;
    }

    return 0xFF;
}

// 0x00628320
void __stdcall ITEMS_SetItemCell(D2UnitStrc* pItem, int nItemCell)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        pItemData->nItemCell = nItemCell;
    }
}

// 0x00628340
char* __stdcall ITEMS_GetEarName(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->szPlayerName;
    }

    return 0;
}

// 0x00628370
void __stdcall ITEMS_SetEarName(D2UnitStrc* pItem, char* szName)
{
    if (!pItem || pItem->dwUnitType != 4)
    {
        return;
    }

    D2ItemDataStrc* pItemData = pItem->pItemData;
    if (!pItemData)
    {
        return;
    }

    strcpy(pItemData->szPlayerName, szName);
}

// 0x006283A0
unsigned char __stdcall ITEMS_GetEarLevel(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->nEarLvl;
    }

    return 1;
}

// 0x006283D0
void __stdcall ITEMS_SetEarLevel(D2UnitStrc* pItem, unsigned char nLevel)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        pItemData->nEarLvl = nLevel;
    }
}

// 0x006283F0
unsigned char __stdcall ITEMS_GetVarGfxIndex(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->nInvGfxIdx;
    }

    return 0;
}

// 0x00628420
void __stdcall ITEMS_SetVarGfxIndex(D2UnitStrc* pItem, unsigned char nIndex)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        pItemData->nInvGfxIdx = nIndex;
    }
}

inline int ITEMS_CheckTypeEquivalenceFromLUT(unsigned int* pEquivalenceLUT, int nItemType)
{
    return pEquivalenceLUT[nItemType >> 5] & gdwBitMasks[nItemType & 0x1F];
}

inline unsigned int* ITEMS_TypeEquivalenceLUT(int nItemTypeLUT)
{
    return &sgptDataTables->pItemTypesEquivalenceLUTs[nItemTypeLUT * sgptDataTables->nItemTypesIndex];
}

// 0x00628480
int __stdcall ITEMS_GetQuiverTypeFromItemType(int nItemType)
{
    D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(nItemType);
    if (!pItemTypesTxtRecord)
    {
        return 0;
    }

    return pItemTypesTxtRecord->wQuiver;
}

// 0x006284C0
unsigned int __stdcall ITEMS_GetAutoStackFromItemType(int nItemType)
{
    D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(nItemType);
    if (!pItemTypesTxtRecord)
    {
        return 0;
    }

    return pItemTypesTxtRecord->nAutoStack;
}

// 0x00628500
unsigned int __stdcall ITEMS_GetWeaponClassCode(D2UnitStrc* pItem)
{
    D2ItemsTxt* pItemsTxtRecord = 0;

    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
        if (pItemsTxtRecord)
        {
            return pItemsTxtRecord->dwWeapClass;
        }
    }

    return 0;
}

// 0x00628530
unsigned int __stdcall ITEMS_Get2HandWeaponClassCode(D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 1544);
    D2_ASSERT(hItem->dwUnitType == UNIT_ITEM, 1545);

    const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(hItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 1548);
    return pItemsTxtRecord->dwWeapClass2Hand;
}

// 0x00628590
unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 1562);
    D2_ASSERT(hItem->dwUnitType == UNIT_ITEM, 1563);

    const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(hItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 1566);
    return pItemsTxtRecord->dwCode;
}

// 0x006285F0
unsigned int __stdcall ITEMS_GetAltGfx(D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 1575);
    D2_ASSERT(hItem->dwUnitType == UNIT_ITEM, 1576);

    const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(hItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 1579);
    if (pItemsTxtRecord->dwAlternateGfx)
    {
        return pItemsTxtRecord->dwAlternateGfx;
    }
    else
    {
        return pItemsTxtRecord->dwCode;
    }
}

// 0x00628660
unsigned char __stdcall ITEMS_GetComponent(D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 1588);
    D2_ASSERT(hItem->dwUnitType == UNIT_ITEM, 1589);

    const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(hItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 1592);
    return pItemsTxtRecord->nComponent;
}

// 0x006286C0
void __stdcall ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szFile, int nLine)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        if (D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId))
        {
            *pWidth = pItemsTxtRecord->nInvWidth;
            *pHeight = pItemsTxtRecord->nInvHeight;
        }
    }
}

// 0x00628700
unsigned int __stdcall ITEMS_GetItemTypeFromItemId(unsigned int dwItemId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(dwItemId);

    D2_ASSERT(pItemsTxtRecord, 1677);

    return pItemsTxtRecord->wType[0];
}

// 0x00628740
unsigned char __stdcall ITEMS_GetItemQlvl(const D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 1686);
    D2_ASSERT(hItem->dwUnitType == UNIT_ITEM, 1687);

    const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(hItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 1690);
    return pItemsTxtRecord->nLevel;
}

// 0x006287A0
extern "C" __declspec(dllexport) unsigned int __stdcall sub_006287A0(unsigned int dwA, unsigned int dwB) {
    return dwA & dwB;
}

// 0x006287B0
void __stdcall ITEMS_SetOrRemoveFlag(int* pFlags, int nFlag, int bSet)
{
    if (bSet)
    {
        *pFlags |= nFlag;
    }
    else
    {
        *pFlags &= ~nFlag;
    }
}

// 0x006287D0
unsigned int __stdcall ITEMS_GetNormalCode(D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 1943);
    D2_ASSERT(hItem->dwUnitType == UNIT_ITEM, 1944);

    const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(hItem->dwClassId);
    if (pItemsTxtRecord->dwNormCode)
    {
        return pItemsTxtRecord->dwNormCode;
    }
    else
    {
        return pItemsTxtRecord->dwCode;
    }
}

// 0x00628860
int __stdcall ITEMS_CheckItemTypeIfThrowable(int nItemType)
{
    D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(nItemType);
    if (!pItemTypesTxtRecord)
    {
        return 0;
    }

    return pItemTypesTxtRecord->nThrowable;
}

// 0x006288A0
int __stdcall ITEMS_GetMissileType(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        return DATATBLS_GetItemsTxtRecord(pItem->dwClassId)->wMissileType;
    }

    return -1;
}

// 0x006288D0
unsigned char __stdcall ITEMS_GetMeleeRange(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        return DATATBLS_GetItemsTxtRecord(pItem->dwClassId)->nRangeAdder;
    }

    return 0;
}

// 0x00628900
int __stdcall ITEMS_CheckWeaponClassByItemId(int nItemId, int nWeapClass)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);

    D2_ASSERT(pItemsTxtRecord, 2283);

    return pItemsTxtRecord->dwWeapClass == nWeapClass;
}

// 0x00628950
int __stdcall ITEMS_CheckWeaponClass(D2UnitStrc* pItem, int nWeapClass)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        int nItemId = pItem->dwClassId;
        return ITEMS_CheckWeaponClassByItemId(nItemId, nWeapClass);
    }

    return 0;
}

// 0x00628980
unsigned int __stdcall ITEMS_CheckWeaponIfTwoHandedByItemId(int nItemId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);

    D2_ASSERT(pItemsTxtRecord, 2310);

    return pItemsTxtRecord->n2Handed;
}

// 0x006289C0
unsigned int __stdcall ITEMS_CheckWeaponIfTwoHanded(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        return ITEMS_CheckWeaponIfTwoHandedByItemId(pItem->dwClassId);
    }

    return 0;
}

// 0x006289F0
unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
        D2_ASSERT(pItemsTxtRecord, 2338);
        return pItemsTxtRecord->nStackable;
    }

    return 0;
}

// 0x00628A40
int __stdcall ITEMS_ComparePotionTypes(D2UnitStrc* pItem1, D2UnitStrc* pItem2)
{
    static int s_nHealthPotionCodes_00744684[] = { 0x20317068, 0x20327068, 0x20337068, 0x20347068, 0x20357068 };  // 0x00744684
    extern unsigned int s_nHealthPotionCodeCount_00744698; // 0x00744698
    static int s_nManaPotionCodes_0074466C[] = { 0x2031706D, 0x2032706D, 0x2033706D, 0x2034706D, 0x2035706D };    // 0x0074466C
    extern unsigned int s_nManaPotionCodeCount_00744680; // 0x00744680
    static int s_nRejuvPotionCodes_00744660[] = { 0x206C7672, 0x20737672 };                                       // 0x00744660
    extern unsigned int s_nRejuvPotionCodeCount_00744668; // 0x00744668

    if (pItem1 && pItem2)
    {
        const int nClassId1 = pItem1->dwClassId;
        const int nClassId2 = pItem2->dwClassId;
        if (nClassId1 == nClassId2)
        {
            return 1;
        }

        {
        D2ItemsTxt* pItemsTxtRecord1 = DATATBLS_GetItemsTxtRecord(nClassId1);
        D2ItemsTxt* pItemsTxtRecord2 = DATATBLS_GetItemsTxtRecord(nClassId2);
        int bPotion1;
        int bPotion2;

        bPotion1 = 0;
        bPotion2 = 0;
        for (unsigned int i = 0; i < s_nHealthPotionCodeCount_00744698; ++i)
        {
            if (!bPotion1 && pItemsTxtRecord1->dwCode == s_nHealthPotionCodes_00744684[i])
            {
                bPotion1 = 1;
            }
            if (!bPotion2 && pItemsTxtRecord2->dwCode == s_nHealthPotionCodes_00744684[i])
            {
                bPotion2 = 1;
            }
            if (bPotion1 && bPotion2)
            {
                return 1;
            }
        }

        bPotion1 = 0;
        bPotion2 = 0;
        for (unsigned int i = 0; i < s_nManaPotionCodeCount_00744680; ++i)
        {
            if (!bPotion1 && pItemsTxtRecord1->dwCode == s_nManaPotionCodes_0074466C[i])
            {
                bPotion1 = 1;
            }
            if (!bPotion2 && pItemsTxtRecord2->dwCode == s_nManaPotionCodes_0074466C[i])
            {
                bPotion2 = 1;
            }
            if (bPotion1 && bPotion2)
            {
                return 1;
            }
        }

        bPotion1 = 0;
        bPotion2 = 0;
        for (unsigned int i = 0; i < s_nRejuvPotionCodeCount_00744668; ++i)
        {
            if (!bPotion1 && pItemsTxtRecord1->dwCode == s_nRejuvPotionCodes_00744660[i])
            {
                bPotion1 = 1;
            }
            if (!bPotion2 && pItemsTxtRecord2->dwCode == s_nRejuvPotionCodes_00744660[i])
            {
                bPotion2 = 1;
            }
            if (bPotion1 && bPotion2)
            {
                return 1;
            }
        }
        }
        return 0;
    }

    return 0;
}

// 0x00628C20
int __stdcall ITEMS_CheckIfUseable(D2UnitStrc* pItem)
{
    D2ItemsTxt* pItemsTxtRecord = 0;

    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
        D2_ASSERT(pItemsTxtRecord, 2500);

        return pItemsTxtRecord->nUseable;
    }

    return 0;
}

// 0x00628C70
int __stdcall ITEMS_GetUniqueColumnFromItemsTxt(D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 2509);
    D2_ASSERT(hItem->dwUnitType == UNIT_ITEM, 2510);

    const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(hItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 2513);
    return pItemsTxtRecord->nUnique;
}

// 0x00628CD0
int __stdcall ITEMS_IsQuestItem(D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 2522);
    D2_ASSERT(hItem->dwUnitType == UNIT_ITEM, 2523);

    const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(hItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 2526);
    return pItemsTxtRecord->nQuest;
}

// 0x00629370
static __declspec(noinline) int __stdcall sub_00629370_GetGambleCost(int nLevel, D2UnitStrc* pItem)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(DATATBLS_GetItemIdFromItemCode(ITEMS_GetNormalCode(pItem)));
    D2_ASSERT(pItemsTxtRecord, 2842);

    const unsigned int dwUberCode = pItemsTxtRecord->dwUberCode;
    const unsigned int dwUltraCode = pItemsTxtRecord->dwUltraCode;
    int nUberItemId = 0;
    int nUltraItemId = 0;
    int nUberChance = 0;
    int nUltraChance = 0;
    int nUberCost = 0;
    int nUltraCost = 0;

    if (pItemsTxtRecord->dwCode == ' nir' || pItemsTxtRecord->dwCode == ' uma')
    {
        return pItemsTxtRecord->dwGambleCost;
    }

    const int nStack = pItemsTxtRecord->dwMaxStack + pItemsTxtRecord->dwMinStack;
    int nCount = nStack / 2;
    if (nCount < 1)
    {
        nCount = 1;
    }

    const int nBaseCost = nCount * pItemsTxtRecord->dwCost;
    const int nItemLevel = pItemsTxtRecord->nLevel;

    if (dwUberCode && pItemsTxtRecord->dwUberCode != '   0')
    {
        D2ItemsTxt* pUberItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(dwUberCode, &nUberItemId);
        if (pUberItemsTxtRecord)
        {
            nUberChance = 100 * (nLevel - pUberItemsTxtRecord->nLevel) / 2 + 1;
            if (nUberChance < 0)
            {
                nUberChance = 0;
            }
            nUberCost = pUberItemsTxtRecord->dwCost;
        }
    }

    if (dwUltraCode && pItemsTxtRecord->dwUltraCode != '   0')
    {
        D2ItemsTxt* pUltraItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(dwUltraCode, &nUltraItemId);
        if (pUltraItemsTxtRecord)
        {
            nUltraChance = 100 * (nLevel - pUltraItemsTxtRecord->nLevel) / 4 + 1;
            if (nUltraChance < 0)
            {
                nUltraChance = 0;
            }
            nUltraCost = pUltraItemsTxtRecord->dwCost;
        }
    }

    const int nBase = (nUberChance * nUberCost + nUltraChance * nUltraCost + nBaseCost * (10000 - nUltraChance - nUberChance)) / 10000;
    if (nLevel <= 5)
    {
        nLevel = 5;
    }

    return ((2 * nLevel + 1) / 3 + 20) * (nBase + (250 * (nLevel + ((nItemLevel - 45) < 0 ? 0 : (nItemLevel - 45)) - nItemLevel / 2)) / 3) / 15;
}

// 0x00629740
int __stdcall ITEMS_CheckBitField1Flag8(D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 3485);
    D2_ASSERT(hItem->dwUnitType == UNIT_ITEM, 3486);

    const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(hItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 3488);
    return pItemsTxtRecord->dwBitField1 & 8;
}

// 0x006297A0
unsigned char __stdcall ITEMS_GetDurWarnCount(D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 3523);
    D2_ASSERT(hItem->dwUnitType == UNIT_ITEM, 3524);

    const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(hItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 3526);
    return pItemsTxtRecord->nDurWarning;
}

// 0x00629800
unsigned char __stdcall ITEMS_GetQtyWarnCount(D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 3535);
    D2_ASSERT(hItem->dwUnitType == UNIT_ITEM, 3536);

    const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(hItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 3538);
    return pItemsTxtRecord->nQuantityWarning;
}

// 0x00629860
short __stdcall ITEMS_GetStrengthBonus(D2UnitStrc* pItem)
{
    D2ItemsTxt* pItemsTxtRecord = 0;

    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
        if (pItemsTxtRecord && pItemsTxtRecord->nStrBonus != 1)
        {
            return pItemsTxtRecord->nStrBonus;
        }
    }

    return 100;
}

// 0x006298A0
short __stdcall ITEMS_GetDexBonus(D2UnitStrc* pItem)
{
    D2ItemsTxt* pItemsTxtRecord = 0;

    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
        if (pItemsTxtRecord && pItemsTxtRecord->nDexBonus != 1)
        {
            return pItemsTxtRecord->nDexBonus;
        }
    }

    return 100;
}

// 0x006298E0
int __stdcall ITEMS_CheckIfSocketableByItemId(int nItemId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    return pItemsTxtRecord->nHasInv;
}

// 0x00629900
int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        return ITEMS_CheckIfSocketableByItemId(pItem->dwClassId);
    }

    return 0;
}

// 0x00629930
int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
        if (pItemsTxtRecord && !pItemsTxtRecord->nNoDurability && pItemsTxtRecord->nDurability > 0 && STATLIST_GetMaxDurabilityFromUnit(pItem))
        {
            return STATLIST_UnitGetStatValue(pItem, STAT_ITEM_INDESCTRUCTIBLE, 0) <= 0;
        }
    }

    return 0;
}

// 0x00629990
unsigned char __stdcall ITEMS_GetAllowedGemSocketsFromItemId(int nItemId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    return pItemsTxtRecord->nGemSockets;
}

// 0x006299B0
int __stdcall ITEMS_GetSockets(D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 0xEA6);
    D2_ASSERT(hItem->dwUnitType == UNIT_ITEM, 0xEA7);
    return STATLIST_UnitGetStatValue(hItem, STAT_ITEM_NUMSOCKETS, 0);
}

// 0x00629A90
int __stdcall ITEMS_CheckItemTypeIdByItemId(int nItemId, int nItemType)
{
    if (nItemType < 0 || nItemType >= sgptDataTables->nItemTypesTxtRecordCount)
    {
        return 0;
    }

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    const int nType = ITEMS_GetItemTypeFromItemId(nItemId);
    if (nType < 0 || nType >= sgptDataTables->nItemTypesTxtRecordCount)
    {
        return 0;
    }

    if (sgptDataTables->pItemTypesEquivalenceLUTs[nType * sgptDataTables->nItemTypesIndex + (nItemType >> 5)] & gdwBitMasks[nItemType & 0x1F])
    {
        return 1;
    }

    const int nType2 = pItemsTxtRecord->wType[1];
    if (nType2 && nType2 < sgptDataTables->nItemTypesTxtRecordCount)
    {
        return sgptDataTables->pItemTypesEquivalenceLUTs[nType2 * sgptDataTables->nItemTypesIndex + (nItemType >> 5)] & gdwBitMasks[nItemType & 0x1F];
    }

    return 0;
}

// 0x00629B50
int __stdcall ITEMS_CheckType(int nItemType1, int nItemType2)
{
    if (nItemType1 >= 0 && nItemType1 < sgptDataTables->nItemTypesTxtRecordCount && nItemType2 >= 0 && nItemType2 < sgptDataTables->nItemTypesTxtRecordCount)
    {
        return ITEMS_CheckTypeEquivalenceFromLUT(ITEMS_TypeEquivalenceLUT(nItemType1), nItemType2);
    }

    return FALSE;
}

// 0x00629BB0
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType)
{
    if (!pItem)
    {
        return 0;
    }

    if (nItemType < 0 || nItemType >= sgptDataTables->nItemTypesTxtRecordCount)
    {
        return 0;
    }

    const int nClassId = pItem->dwClassId;
    const int nType = ITEMS_GetItemTypeFromItemId(nClassId);
    if (sgptDataTables->pItemTypesEquivalenceLUTs[nType * sgptDataTables->nItemTypesIndex + (nItemType >> 5)] & gdwBitMasks[nItemType & 0x1F])
    {
        return 1;
    }

    const int nItemsTxtClassId = pItem->dwClassId;
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemsTxtClassId);
    if (pItemsTxtRecord && pItemsTxtRecord->wType[1] > 0 && pItemsTxtRecord->wType[1] < sgptDataTables->nItemTypesTxtRecordCount)
    {
        return sgptDataTables->pItemTypesEquivalenceLUTs[pItemsTxtRecord->wType[1] * sgptDataTables->nItemTypesIndex + (nItemType >> 5)] & gdwBitMasks[nItemType & 0x1F];
    }

    return 0;
}

// 0x00629C80
int __stdcall ITEMS_CheckBitField1Flag1(int nItemId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);

    D2_ASSERT(pItemsTxtRecord, 4160);

    return pItemsTxtRecord->dwBitField1 & 1;
}

// 0x00629CC0
int __stdcall ITEMS_IsMetalItem(int nItemId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);

    D2_ASSERT(pItemsTxtRecord, 4170);

    return pItemsTxtRecord->dwBitField1 & 2;
}

// 0x00629D00
int __stdcall ITEMS_CheckBitField1Flag4(int nItemId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);

    D2_ASSERT(pItemsTxtRecord, 4180);

    return pItemsTxtRecord->dwBitField1 & 4;
}

// 0x00629D40
int __stdcall ITEMS_IsNotQuestItemByItemId(int nItemId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);

    D2_ASSERT(pItemsTxtRecord, 4190);

    return pItemsTxtRecord->nQuest < 1 && pItemsTxtRecord->wType[0] != ITEMTYPE_QUEST;
}

// 0x00629DA0
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 4208);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 4209);
    D2_ASSERT(pItem->pItemData, 4211);
    return pItem->pItemData->dwFileIndex;
}

// 0x00629DF0
void __stdcall ITEMS_SetFileIndex(D2UnitStrc* pItem, unsigned int dwFileIndex)
{
    D2_ASSERT(pItem, 4220);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 4221);
    D2_ASSERT(pItem->pItemData, 4223);
    pItem->pItemData->dwFileIndex = dwFileIndex;
}

// 0x00629E40
void __stdcall ITEMS_GetRealmData(D2UnitStrc* pItem, int* pRealmData0, int* pRealmData1)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemDataStrc* pItemData = pItem->pItemData;
        if (!pItemData)
        {
            *pRealmData0 = 0;
            *pRealmData1 = 0;
            return;
        }

        *pRealmData0 = pItemData->dwRealmData[0];
        *pRealmData1 = pItemData->dwRealmData[1];
        return;
    }

    *pRealmData0 = 0;
    *pRealmData1 = 0;
}

// 0x00629EA0
extern "C" __declspec(dllexport) void __stdcall sub_00629EA0(Unit00629EA0* pUnit, unsigned int dwFirst, unsigned int dwSecond) {
    if (pUnit && pUnit->nType == 4) {
        Data00629EA0* pData = pUnit->pData;
        if (pData) {
            pData->dwValue1C = dwFirst;
            pData->dwValue20 = dwSecond;
        }
    }
}

// 0x00629ED0
void __stdcall ITEMS_SetOwnerId(D2UnitStrc* pItem, int nOwnerGUID)
{
    D2_ASSERT(pItem, 4284);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 4285);
    D2_ASSERT(pItem->pItemData, 4287);
    pItem->pItemData->dwOwnerGUID = nOwnerGUID;
}

// 0x00629F20
int __stdcall ITEMS_GetOwnerId(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 4295);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 4296);
    D2_ASSERT(pItem->pItemData, 4298);
    return pItem->pItemData->dwOwnerGUID;
}

// 0x00629F70
int __stdcall ITEMS_IsClassValidByItemId(int nItemId)
{
    D2ItemTypesTxt* pItemTypesTxtRecord = 0;

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    D2_ASSERT(pItemsTxtRecord, 1677);

    pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(pItemsTxtRecord->wType[0]);
    if (!pItemTypesTxtRecord)
    {
        return FALSE;
    }

    return pItemTypesTxtRecord->nClass < NUMBER_OF_PLAYERCLASSES;
}

// 0x00629FE0
unsigned short __stdcall ITEMS_GetWeaponClassId(D2UnitStrc* pItem)
{
    int nItemId = 0;
    if (!pItem)
    {
        nItemId = -1;
    }
    else
    {
        nItemId = pItem->dwClassId;
    }

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    D2_ASSERT(pItemsTxtRecord, 4421);

    unsigned int nCounter = 0;
    while (nCounter < gnWeaponClassTableCount)
    {
        if (pItemsTxtRecord->dwWeapClass == gWeaponClassTable[nCounter].dwCode)
        {
            return (unsigned short)gWeaponClassTable[nCounter].nWeaponClassId;
        }

        ++nCounter;
    }

    return WEAPONCLASS_HTH;
}

// 0x0062A0F0
int __stdcall ITEMS_IsMagSetRarUniCrfOrTmp(D2UnitStrc* pItem)
{
    const int nType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_ITEM && pItem->pItemData)
    {
        return pItem->pItemData->dwQualityNo >= ITEMQUAL_MAGIC && pItem->pItemData->dwQualityNo <= ITEMQUAL_TEMPERED;
    }

    return 0;
}

// 0x0062A130
int __stdcall ITEMS_IsNotQuestItem(D2UnitStrc* pItem)
{
    if (!pItem || !ITEMS_CheckItemFlag(pItem, IFLAG_NOSELL))
    {
        if (ITEMS_IsNotQuestItemByItemId(!pItem ? -1 : pItem->dwClassId))
        {
            return TRUE;
        }
    }

    return FALSE;
}

// 0x0062A180
unsigned char __stdcall ITEMS_GetHitClassFromItem(D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 0x118F);
    D2_ASSERT(hItem->dwUnitType == 4, 0x1190);

    const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(hItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 0x1192);
    return pItemsTxtRecord->nHitClass;
}

// 0x0062A1E0
int __stdcall ITEMS_Is1Or2Handed(D2UnitStrc* hPlayer, D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 4507);
    D2_ASSERT(hPlayer, 4509);

    if (hPlayer->dwUnitType == UNIT_PLAYER && hPlayer->dwClassId == PCLASS_BARBARIAN)
    {
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(hItem->dwClassId);
        D2_ASSERT(pItemsTxtRecord, 4517);

        if (pItemsTxtRecord->n1or2Handed)
        {
            return TRUE;
        }
    }

    return FALSE;
}

int __stdcall sub_M88_Emit_0062A2F0(D2UnitStrc* pItem1, D2UnitStrc* pItem2)
{
    if (!sub_0062A2F0_IsPlainQuality(ITEMS_GetItemQuality(pItem1)))
        return 0;
    if (!sub_0062A2F0_IsPlainQuality(ITEMS_GetItemQuality(pItem2)))
        return 0;
    return 1;
}

inline int ITEMS_CheckIfSocketable_Inl(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == 4)
    {
        if (D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId))
        {
            return pItemsTxtRecord->nHasInv;
        }
    }

    return 0;
}

inline unsigned int ITEMS_CheckItemFlag_Inl(D2UnitStrc* pItem, unsigned int dwFlag)
{
    if (pItem->dwUnitType == 4 && pItem->pItemData)
    {
        return pItem->pItemData->dwItemFlags & dwFlag;
    }

    return 0;
}

inline D2ItemDataStrc* ITEMS_GetItemData_Inl(D2UnitStrc* pItem)
{
    return (pItem && pItem->dwUnitType == 4 && pItem->pItemData) ? pItem->pItemData : 0;
}

inline int ITEMS_GetItemQuality_Inl(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData_Inl(pItem))
    {
        return pItemData->dwQualityNo;
    }

    return 2;
}

inline unsigned short ITEMS_GetPrefixId_Inl(D2UnitStrc* pItem, int nIndex)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData_Inl(pItem))
    {
        return pItemData->wMagicPrefix[nIndex];
    }

    return 0;
}

inline unsigned short ITEMS_GetSuffixId_Inl(D2UnitStrc* pItem, int nIndex)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData_Inl(pItem))
    {
        return pItemData->wMagicSuffix[nIndex];
    }

    return 0;
}

inline unsigned short ITEMS_GetAutoAffix_Inl(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData_Inl(pItem))
    {
        return pItemData->wAutoAffix;
    }

    return 0;
}

inline D2StatesTxt* DATATBLS_GetStatesTxtRecord_Inl(int nState)
{
    if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
    {
        return &sgptDataTables->pStatesTxt[nState];
    }

    return 0;
}

// 0x0062A250
static unsigned char sub_0062A250(int nTransform, int nColor)
{
    if (nTransform <= 0 || nTransform >= 9 || nColor < 0 || nColor >= 0x15)
    {
        return 0;
    }

    unsigned char nPacked = nColor & 0x1F;
    nPacked += nTransform << 5;
    return nPacked;
}

// 0x0062A2F0
static __declspec(noinline) int sub_0062A2F0_IsPlainQuality(int nQuality)
{
    switch (nQuality)
    {
    case 0:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        return 0;
    }
    return 1;
}

unsigned char* __stdcall ITEMS_GetColor(D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned char* pColor, int nTransType)
{
    if (pItem)
    {
        if (pPlayer)
        {
            for (int i = 0; i < sgptDataTables->nColourStates; ++i)
            {
                const short nState = sgptDataTables->pColourStates[i];
                if (STATES_CheckState(pPlayer, nState))
                {
                    D2StatesTxt* pStatesTxtRecord = DATATBLS_GetStatesTxtRecord_Inl(nState);
                    if (pStatesTxtRecord && pStatesTxtRecord->nItemTrans < 0x15 && ITEMSIsA(pItem, pStatesTxtRecord->wItemType))
                    {
                        if (D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(sub_00451F60_UnitClassId(pItem)))
                        {
                            return sub_00600C20(pItemsTxtRecord->nTransform, pStatesTxtRecord->nItemTrans);
                        }
                    }
                }
            }
        }

        switch (ITEMS_GetItemQuality_Inl(pItem))
        {
        case 4:
        case 6:
        {
            int i = 0;
            do
            {
                D2MagicAffixTxt* pMagicAffixTxtRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetSuffixId_Inl(pItem, i));
                if (pMagicAffixTxtRecord && pMagicAffixTxtRecord->nTransformColor != 0xFF)
                {
                    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
                    *pColor = sub_0062A250(pItemsTxtRecord->nTransform, pMagicAffixTxtRecord->nTransformColor);
                    if (nTransType)
                    {
                        return sub_00600C20(pItemsTxtRecord->nInvTrans, pMagicAffixTxtRecord->nTransformColor);
                    }

                    return sub_00600C20(pItemsTxtRecord->nTransform, pMagicAffixTxtRecord->nTransformColor);
                }
                ++i;
            }
            while (i < 3);

            i = 0;
            do
            {
                D2MagicAffixTxt* pMagicAffixTxtRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetPrefixId_Inl(pItem, i));
                if (pMagicAffixTxtRecord && pMagicAffixTxtRecord->nTransformColor != 0xFF)
                {
                    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
                    *pColor = sub_0062A250(pItemsTxtRecord->nTransform, pMagicAffixTxtRecord->nTransformColor);
                    if (nTransType)
                    {
                        return sub_00600C20(pItemsTxtRecord->nInvTrans, pMagicAffixTxtRecord->nTransformColor);
                    }

                    return sub_00600C20(pItemsTxtRecord->nTransform, pMagicAffixTxtRecord->nTransformColor);
                }
                ++i;
            }
            while (i < 3);
            break;
        }
        case 7:
        {
            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
            if (!pItemsTxtRecord)
            {
                return 0;
            }

            if (ITEMS_GetFileIndex(pItem) < 0)
            {
                return 0;
            }

            D2UniqueItemsTxt* pUniqueItemsTxtRecord = sub_00483470_GetUniqueItemsTxtRecord(ITEMS_GetFileIndex(pItem));
            if (!pUniqueItemsTxtRecord)
            {
                return 0;
            }

            if (nTransType)
            {
                if (pUniqueItemsTxtRecord->nInvTransform < 0)
                {
                    return 0;
                }

                *pColor = sub_0062A250(pItemsTxtRecord->nTransform, pUniqueItemsTxtRecord->nChrTransform);
                return sub_00600C20(pItemsTxtRecord->nInvTrans, pUniqueItemsTxtRecord->nInvTransform);
            }

            if (pUniqueItemsTxtRecord->nChrTransform < 0)
            {
                return 0;
            }

            *pColor = sub_0062A250(pItemsTxtRecord->nTransform, pUniqueItemsTxtRecord->nChrTransform);
            return sub_00600C20(pItemsTxtRecord->nTransform, pUniqueItemsTxtRecord->nChrTransform);
        }
        case 5:
        {
            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
            if (!pItemsTxtRecord)
            {
                return 0;
            }

            D2SetItemsTxt* pSetItemsTxtRecord = sub_00483440_GetSetItemsTxtRecord(ITEMS_GetFileIndex(pItem));
            if (!pSetItemsTxtRecord)
            {
                return 0;
            }

            if (nTransType)
            {
                if (pSetItemsTxtRecord->nInvTransform < 0)
                {
                    return 0;
                }

                *pColor = sub_0062A250(pItemsTxtRecord->nTransform, pSetItemsTxtRecord->nChrTransform);
                return sub_00600C20(pItemsTxtRecord->nInvTrans, pSetItemsTxtRecord->nInvTransform);
            }

            if (pSetItemsTxtRecord->nChrTransform < 0)
            {
                return 0;
            }

            *pColor = sub_0062A250(pItemsTxtRecord->nTransform, pSetItemsTxtRecord->nChrTransform);
            return sub_00600C20(pItemsTxtRecord->nTransform, pSetItemsTxtRecord->nChrTransform);
        }
        default:
            if (ITEMS_CheckIfSocketable_Inl(pItem) && sub_0062BC20(pItem) > 0 && ITEMS_CheckItemFlag_Inl(pItem, 0x800))
            {
                D2UnitStrc* pInventoryItem = INVENTORY_GetFirstItem(pItem->pInventory);
                if (pInventoryItem)
                {
                    pInventoryItem = INVENTORY_UnitIsItem(pInventoryItem);
                    if (pInventoryItem && ITEMSIsA(pInventoryItem, 0x14))
                    {
                        D2ItemsTxt* pGemItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pInventoryItem->dwClassId);
                        D2_ASSERT(pGemItemsTxtRecord, 0x1271);

                        D2GemsTxt* pGemsTxtRecord = DATATBLS_GetGemsTxtRecord(pGemItemsTxtRecord->dwGemOffset);
                        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
                        *pColor = sub_0062A250(pItemsTxtRecord->nTransform, pGemsTxtRecord->nTransform);
                        if (nTransType)
                        {
                            return sub_00600C20(pItemsTxtRecord->nInvTrans, pGemsTxtRecord->nTransform);
                        }

                        return sub_00600C20(pItemsTxtRecord->nTransform, pGemsTxtRecord->nTransform);
                    }
                }
            }
            break;
        }

        D2MagicAffixTxt* pMagicAffixTxtRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetAutoAffix_Inl(pItem));
        if (pMagicAffixTxtRecord && pMagicAffixTxtRecord->nTransformColor != 0xFF)
        {
            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
            *pColor = sub_0062A250(pItemsTxtRecord->nTransform, pMagicAffixTxtRecord->nTransformColor);
            if (nTransType)
            {
                return sub_00600C20(pItemsTxtRecord->nInvTrans, pMagicAffixTxtRecord->nTransformColor);
            }

            return sub_00600C20(pItemsTxtRecord->nTransform, pMagicAffixTxtRecord->nTransformColor);
        }
    }

    return 0;
}

inline int ITEMS_GetItemQualityInline(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->dwQualityNo;
    }

    return 2;
}

// 0x0062A310
int __stdcall ITEMS_CanItemBeUsedForThrowSkill(D2UnitStrc* pItem)
{
    if (pItem)
    {
        if (STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0) > 0)
        {
            return TRUE;
        }

        if (STATLIST_UnitGetItemStatOrSkillStatValue(pItem, STAT_ITEM_THROWABLE, 0))
        {
            STATLIST_SetUnitStat(pItem, STAT_QUANTITY, 0, 0);
            return TRUE;
        }

        if (ITEMS_GetTotalMaxStack(pItem) <= 0)
        {
            return TRUE;
        }
    }

    return FALSE;
}

// 0x0062A4E0
int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem)
{
    if (pItem)
        return !ITEMS_CheckItemFlagInline(pItem, IFLAG_BROKEN) && !ITEMS_CheckItemFlagInline(pItem, IFLAG_NOEQUIP);

    return FALSE;
}

// 0x0062A530
int __stdcall ITEMS_GetNoOfUnidItems(D2UnitStrc* pUnit)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    int nUnidItems = 0;
    for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory); pItem; pItem = INVENTORY_GetNextItem(pItem))
    {
        D2UnitStrc* pInventoryItem = INVENTORY_UnitIsItem(pItem);
        if (ITEMS_TestItemFlag(pInventoryItem, IFLAG_IDENTIFIED))
        {
            continue;
        }

        const int nNodePage = INVENTORY_GetItemNodePage(pItem);
        if (nNodePage == NODEPAGE_STORAGE)
        {
            if (ITEMS_GetInvPage(pInventoryItem) == INVPAGE_INVENTORY || ITEMS_GetInvPage(pInventoryItem) == INVPAGE_CUBE)
            {
                ++nUnidItems;
            }
        }
        else if (nNodePage == NODEPAGE_EQUIP)
        {
            ++nUnidItems;
        }
    }

    return nUnidItems;
}

// 0x0062A5D0
int __stdcall ITEMS_GetBonusLifeBasedOnClass(D2UnitStrc* pPlayer, int nValue)
{
    int nResult = nValue;

    if (!pPlayer || pPlayer->dwUnitType != UNIT_PLAYER)
    {
        nResult = 2 * nValue;
    }
    else
    {
        switch (pPlayer->dwClassId)
        {
        case PCLASS_AMAZON:
        case PCLASS_PALADIN:
        case PCLASS_ASSASSIN:
            nResult = nValue + (nValue >> 1);
            break;
        case PCLASS_BARBARIAN:
            nResult = 2 * nValue;
            break;
        }
    }

    return nResult;
}

// 0x0062A670
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 5380);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 5381);
    D2_ASSERT(pItem->pItemData, 5383);
    return pItem->pItemData->wItemFormat;
}

// 0x0062A6C0
void __stdcall ITEMS_SetItemFormat(D2UnitStrc* pItem, unsigned short nItemFormat)
{
    D2_ASSERT(pItem, 5391);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 5392);
    D2_ASSERT(pItem->pItemData, 5394);
    pItem->pItemData->wItemFormat = nItemFormat;
}

// 0x0062A710
int __stdcall ITEMS_GetWeaponAttackSpeed(D2UnitStrc* pUnit, D2UnitStrc* hItem)
{
    D2_ASSERT((hItem ? hItem->dwUnitType : 6) == UNIT_ITEM, 0x151D);
    D2_ASSERT(ITEMSIsA(hItem, 0x2D), 0x151E);
    D2_ASSERT(pUnit, 0x151F);

    char szPath[8];
    int nLength = 0;
    int nAnimSpeed = 0;
    int nFirstFrame = 0;
    int nWeaponClassCode = ITEMS_GetWeaponClassCode(hItem);

    D2Common_10884_COMPOSIT_unk(pUnit, !pUnit ? -1 : pUnit->dwClassId, 7, !pUnit ? 6 : pUnit->dwUnitType, pUnit->pInventory, szPath, &nWeaponClassCode, 0, 0);
    if (!DATATBLS_GetAnimDataInfo(szPath, &nLength, &nAnimSpeed, &nFirstFrame))
    {
        return 0x2D;
    }

    D2_ASSERT(nLength, 0x1538);

    int nSpeed = STATLIST_UnitGetItemStatOrSkillStatValue(hItem, 0x5D, 0) + 100;
    nSpeed += STATLIST_UnitGetStatValue(hItem, 0x44, 0);
    return (nLength << 8) / (nAnimSpeed * nSpeed / 100);
}

#include "gen/data/Source/D2Common/ITEMS/Items.inc"

inline D2SetItemsTxt* ITEMS_GetSetItemsTxtRecordFromItem(D2UnitStrc* pItem)
{
    const int nUnitType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_ITEM && ITEMS_GetItemQualityInline(pItem) == ITEMQUAL_SET)
    {
        const int nFileIndex = ITEMS_GetFileIndex(pItem);
        if (nFileIndex >= 0 && nFileIndex < sgptDataTables->nSetItemsTxtRecordCount)
        {
            return &sgptDataTables->pSetItemsTxt[nFileIndex];
        }
    }

    return 0;
}

// 0x0062A840
int __stdcall ITEMS_HasUsedCharges(D2UnitStrc* pItem, int* pHasChargedSkills)
{
    D2StatStrc pStat[64];

    if (pHasChargedSkills)
    {
        *pHasChargedSkills = 1;
    }

    int bResult = 0;
    const int nStats = STATLIST_CopyStats(pItem, STAT_ITEM_CHARGED_SKILL, pStat, 64);
    if (nStats > 0)
    {
        bResult = 1;

        if (pHasChargedSkills)
        {
            for (int i = 0; i < nStats; ++i)
            {
                if ((pStat[i].nValue & 0xFF) < (pStat[i].nValue >> 8))
                {
                    *pHasChargedSkills = 0;
                    break;
                }
            }
        }
    }

    return bResult;
}

// 0x0062A8D0
int __stdcall ITEMS_IsEthereal(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->dwItemFlags & IFLAG_ETHEREAL;
    }

    return 0;
}

// 0x0062A960
static __forceinline unsigned int sub_0062A960_ReadBits(D2BitBufferStrc* pBuffer, int nBits)
{
    return sub_00411020_ReadBits(pBuffer, nBits);
}

int __stdcall sub_M231_Emit_00629370(D2UnitStrc* pPlayer, D2UnitStrc* pItem)
{
    return sub_00629370_GetGambleCost(STATLIST_UnitGetStatValue(pPlayer, 12, 0), pItem);
}

// 0x0062AC80
static void __stdcall ITEMS_ReadStatFromItemBitstream(D2BitBufferStrc* pBuffer, D2StatListStrc* pStatList, D2ItemStatCostTxt* pItemStatCostTxtRecord, int nStatId, unsigned int dwVersion, int n109)
{
    int nParamBits = pItemStatCostTxtRecord->dwSaveParamBits[n109];
    int nSaveBits = pItemStatCostTxtRecord->nSaveBits[n109];
    int nSaveAdd = pItemStatCostTxtRecord->dwSaveAdd[n109];
    int nParam = 0;

    switch (nStatId)
    {
    case 23:
        if (dwVersion <= 89)
            nSaveBits = 5;
        break;
    case 24:
        if (dwVersion <= 89)
            nSaveBits = 6;
        break;
    case 74:
        if (dwVersion <= 89)
        {
            nSaveBits = 5;
            nSaveAdd = 10;
        }
        break;
    case 79:
        if (dwVersion <= 89)
        {
            nSaveBits = 8;
            nSaveAdd = 20;
        }
        break;
    case 80:
        if (dwVersion <= 89)
        {
            nSaveBits = 7;
            nSaveAdd = 20;
        }
        break;
    case 93:
    case 96:
    case 99:
    case 102:
    case 105:
        if (dwVersion <= 87)
            nSaveBits = 6;
        break;
    case 92:
    case 94:
        if (dwVersion < 93)
            nStatId = 93;
        break;
    case 95:
    case 97:
        if (dwVersion < 93)
            nStatId = 96;
        break;
    case 98:
    case 100:
        if (dwVersion < 93)
            nStatId = 99;
        break;
    case 101:
    case 103:
        if (dwVersion < 93)
            nStatId = 102;
        break;
    case 104:
    case 106:
        if (dwVersion < 93)
            nStatId = 105;
        break;
    default:
        break;
    }

    if (nParamBits > 0)
        nParam = (unsigned short)sub_00411020_ReadBits(pBuffer, nParamBits);

    const unsigned int nValue = sub_00411020_ReadBits(pBuffer, nSaveBits);
    STATLIST_SetStat(pStatList, nStatId, (nValue - nSaveAdd) << pItemStatCostTxtRecord->nValShift, nParam);
}

// 0x0062AE20
int __stdcall ITEMS_GetCompactItemDataFromBitstream(unsigned char* pBitstream, unsigned int nSize, int bCheckForHeader, D2ItemSaveStrc* pItemSave, int dwVersion)
{
    D2BitBufferStrc pBuffer;
    BITMANIP_Initialize(&pBuffer, pBitstream, nSize);

    if (bCheckForHeader && BITMANIP_ReadSigned(&pBuffer, 16) != 'MJ')
        return 0;

    unsigned int dwFlags = sub_00411020_ReadBits(&pBuffer, 32);
    pItemSave->dwFlags = dwFlags;
    sub_00411020_ReadBits(&pBuffer, 10);
    pItemSave->bMode = (unsigned char)sub_00411020_ReadBits(&pBuffer, 3);
    if (pItemSave->bMode == IMODE_ONGROUND || pItemSave->bMode == IMODE_DROPPING)
    {
        pItemSave->nX = (unsigned short)sub_00411020_ReadBits(&pBuffer, 16);
        pItemSave->nY = (unsigned short)sub_00411020_ReadBits(&pBuffer, 16);
    }
    else
    {
        pItemSave->nBodyloc = (unsigned char)sub_00411020_ReadBits(&pBuffer, 4);
        pItemSave->nX = (unsigned short)sub_00411020_ReadBits(&pBuffer, 4);
        pItemSave->nY = (unsigned short)sub_00411020_ReadBits(&pBuffer, 4);
        pItemSave->nStorePage = (unsigned char)sub_00411020_ReadBits(&pBuffer, 3) - 1;
    }

    if (dwFlags & IFLAG_ISEAR)
    {
        pItemSave->nClassId = DATATBLS_GetItemIdFromItemCode(' rae');
    }
    else
    {
        unsigned int dwCode = sub_00411020_ReadBits(&pBuffer, 32);
        if (dwVersion <= 0x5C && dwCode == ' cen')
            dwCode = ' gen';
        pItemSave->nClassId = DATATBLS_GetItemIdFromItemCode(dwCode);
    }

    int nItemFileIndex = 0;
    if (!(dwFlags & IFLAG_COMPACTSAVE_LOWQUALITY))
        nItemFileIndex = sub_00411020_ReadBits(&pBuffer, 3);
    pItemSave->nItemFileIndex = nItemFileIndex;

    return 1;
}

// 0x0062AF50
void __fastcall ITEMS_WriteBitsToBitstream(int nBits, unsigned int nData, D2BitBufferStrc* pBuffer)
{
    if (nBits != 32)
    {
        nData = D2_MIN(D2_MAX(nData, 0u), (1u << nBits) - 1);
    }

    BITMANIP_Write(pBuffer, nData, nBits);
}

// 0x0062B3A0
int __stdcall ITEMS_GetNoOfSetItemsFromItem(D2UnitStrc* pItem)
{
    if (D2SetItemsTxt* pSetItemsTxtRecord = ITEMS_GetSetItemsTxtRecordFromItem(pItem))
    {
        return pSetItemsTxtRecord->nSetItems;
    }

    return -1;
}

// 0x0062B400
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 1661);

    if (pItem->dwUnitType != UNIT_ITEM)
    {
        return 0;
    }

    return ITEMS_GetItemTypeFromItemId(pItem->dwClassId);
}

inline int ITEMS_CheckIfSocketableByItemIdInl(int nItemId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    if (pItemsTxtRecord)
    {
        return pItemsTxtRecord->nHasInv;
    }
    return 0;
}

inline D2ItemDataStrc* ITEMS_GetItemDataInl(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        return pItem->pItemData;
    }
    return 0;
}

inline int ITEMS_CheckItemFlagInl(D2UnitStrc* pItem, unsigned int nFlag)
{
    D2ItemDataStrc* pItemData = ITEMS_GetItemDataInl(pItem);
    if (pItemData)
    {
        return pItemData->dwItemFlags & nFlag;
    }
    return 0;
}

// 0x0062B450
static void __stdcall sub_0062B450_GetSocketedStatBonus(int nStatId, int* pValue, D2UnitStrc* pItem)
{
    *pValue = 0;
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        if (ITEMS_CheckIfSocketableByItemIdInl(pItem->dwClassId))
        {
                D2InventoryStrc* pInventory = pItem->pInventory;
            for (D2UnitStrc* i = INVENTORY_GetFirstItem(pInventory); i; i = INVENTORY_GetNextItem(i))
            {
                D2UnitStrc* pSocketed = INVENTORY_UnitIsItem(i);
                if (sub_00451F70_GetUnitMode(pItem) == IMODE_EQUIP)
                {
                    *pValue += STATLIST_UnitGetStatValue(pSocketed, nStatId, 0);
                }
            }
        }
    }
}

// 0x0062BA60
int __stdcall ITEMS_GetLevelRequirement(D2UnitStrc* pItem, D2UnitStrc* pUnit)
{
    return sub_0062B5B0(pItem, pUnit);
}

// calling-convention shim (not game code)
void __stdcall sub_K14_EmitSetDefenseOrDamage(D2UnitStrc* pItem, int nOther)
{
    ITEMS_SetDefenseOrDamage(pItem, 17);
    STATLIST_SetUnitStat(pItem, nOther, 0, 0);
    ITEMS_SetDefenseOrDamage(pItem, 18);
}

// 0x0062BA80
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (pItemTypesTxtRecord)
        {
            return pItemTypesTxtRecord->nThrowable;
        }
    }

    return 0;
}

// 0x0062BAD0
unsigned int __stdcall ITEMS_CheckIfBeltable(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (pItemTypesTxtRecord)
        {
            return pItemTypesTxtRecord->nBeltable;
        }
    }

    return 0;
}

// 0x0062BB20
int __stdcall ITEMS_GetSpellIcon(D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 3500);
    const int nType = hItem ? hItem->dwUnitType : UNIT_INVALID;
    D2_ASSERT(nType == UNIT_ITEM, 3501);

    unsigned char nSpellIcon = 0;
    if (ITEMSIsA(hItem, ITEMTYPE_SCROLL) || ITEMSIsA(hItem, ITEMTYPE_BOOK))
    {
        unsigned short wBookId = 0;
        if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(hItem))
        {
            wBookId = pItemData->wMagicSuffix[0];
        }
        else
        {
            wBookId = 0;
        }

        D2BooksTxt* pBooksTxtRecord = DATATBLS_GetBooksTxtRecord(wBookId);
        if (!pBooksTxtRecord)
        {
            return -1;
        }

        nSpellIcon = pBooksTxtRecord->nSpellIcon;
    }
    else
    {
        const int nClassId = hItem->dwClassId;
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
        D2_ASSERT(pItemsTxtRecord, 3512);
        nSpellIcon = pItemsTxtRecord->nSpellIcon;
    }

    return nSpellIcon;
}

// 0x0062BBD0
int __stdcall ITEMS_GetStaffMods(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (pItemTypesTxtRecord)
        {
            return pItemTypesTxtRecord->nStaffMods;
        }
    }

    return 7;
}

// 0x0062BEB0
int __stdcall ITEMS_IsSocketFiller(D2UnitStrc* pItem)
{
    return ITEMSIsA(pItem, ITEMTYPE_SOCKET_FILLER);
}

// 0x0062C060
int __stdcall ITEMS_IsClassValid(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (pItemTypesTxtRecord)
        {
            return pItemTypesTxtRecord->nClass < 7;
        }
    }

    return 0;
}

// 0x0062C0B0
int __stdcall ITEMS_GetClassOfClassSpecificItem(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (pItemTypesTxtRecord && pItemTypesTxtRecord->nClass < 7)
        {
            return pItemTypesTxtRecord->nClass;
        }
    }

    return 7;
}

// calling-convention shim (not game code)
void __stdcall sub_K14_EmitReadStat(D2BitBufferStrc* pBuffer, D2StatListStrc* pStatList, int nStatId, D2ItemStatCostTxt* pItemStatCostTxtRecord, int n109, unsigned int dwVersion)
{
    ITEMS_ReadStatFromItemBitstream(pBuffer, pStatList, pItemStatCostTxtRecord, nStatId, dwVersion, n109);
}

// 0x0062C9F0
static void __stdcall ITEMS_SetDefenseOrDamage(D2UnitStrc* pItem, int nStat)
{
    int nItemId;
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(ITEMS_GetBaseCode(pItem), &nItemId);
    if (!pItemsTxtRecord)
        return;

    switch (nStat)
    {
    case 16:
    case 31:
        if (ITEMSIsA(pItem, 50) && pItemsTxtRecord->dwMaxAc)
        {
            int nArmor = STATLIST_GetUnitBaseStat(pItem, 31, 0) + 1;
            if (nArmor <= pItemsTxtRecord->dwMaxAc)
                nArmor = pItemsTxtRecord->dwMaxAc + 1;
            STATLIST_SetUnitStat(pItem, 31, nArmor, 0);
        }
        break;
    case 17:
    case 22:
        if (ITEMSIsA(pItem, 45))
        {
            const int nMax = STATLIST_GetUnitBaseStat(pItem, 22, 0);
            if (pItemsTxtRecord->nMaxDam && nMax < pItemsTxtRecord->nMaxDam)
                STATLIST_SetUnitStat(pItem, 22, pItemsTxtRecord->nMaxDam, 0);
            const int nMax2 = STATLIST_GetUnitBaseStat(pItem, 24, 0);
            if (pItemsTxtRecord->n2HandMaxDam && nMax2 < pItemsTxtRecord->n2HandMaxDam)
                STATLIST_SetUnitStat(pItem, 24, pItemsTxtRecord->n2HandMaxDam, 0);
            const int nMaxMis = STATLIST_GetUnitBaseStat(pItem, 160, 0);
            if (ITEMS_CheckIfThrowable(pItem) && pItemsTxtRecord->nMaxMisDam && nMaxMis < pItemsTxtRecord->nMaxMisDam)
                STATLIST_SetUnitStat(pItem, 160, pItemsTxtRecord->nMaxMisDam, 0);
        }
        break;
    case 18:
    case 21:
        if (ITEMSIsA(pItem, 45))
        {
            const int nMin = STATLIST_GetUnitBaseStat(pItem, 21, 0);
            if (pItemsTxtRecord->nMinDam && nMin < pItemsTxtRecord->nMinDam)
                STATLIST_SetUnitStat(pItem, 21, pItemsTxtRecord->nMinDam, 0);
            const int nMin2 = STATLIST_GetUnitBaseStat(pItem, 23, 0);
            if (pItemsTxtRecord->n2HandMinDam && nMin2 < pItemsTxtRecord->n2HandMinDam)
                STATLIST_SetUnitStat(pItem, 23, pItemsTxtRecord->n2HandMinDam, 0);
            const int nMinMis = STATLIST_GetUnitBaseStat(pItem, 159, 0);
            if (ITEMS_CheckIfThrowable(pItem) && pItemsTxtRecord->nMinMisDam && nMinMis < pItemsTxtRecord->nMinMisDam)
                STATLIST_SetUnitStat(pItem, 159, pItemsTxtRecord->nMinMisDam, 0);
        }
        break;
    default:
        break;
    }
}

unsigned int __fastcall sub_M111_Emit_0062A960(D2BitBufferStrc* pBuffer, int nBits)
{
    return sub_0062A960_ReadBits(pBuffer, nBits) + 1;
}

inline int ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->dwItemFlags & dwFlag;
    }

    return 0;
}

// 0x0062E410
int __stdcall sub_0062E410(unsigned char* pBitstream, unsigned int nSize, int bCheckForHeader, void* pItemSave)
{
    return sub_0062AE20(pBitstream, nSize, bCheckForHeader, pItemSave, ITEMVERSION);
}

// 0x0062E6F0
int __stdcall ITEMS_GetAmmoType(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        if (D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem)))
        {
            return pItemTypesTxtRecord->wShoots;
        }
    }

    return 0;
}

// 0x0062E740
int __stdcall ITEMS_GetQuiverType(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        if (D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem)))
        {
            return pItemTypesTxtRecord->wQuiver;
        }
    }

    return 0;
}

// 0x0062E790
unsigned int __stdcall ITEMS_GetAutoStack(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        if (D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem)))
        {
            return pItemTypesTxtRecord->nAutoStack;
        }
    }

    return 0;
}

// 0x0062E7E0
unsigned int __stdcall ITEMS_GetReload(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        if (D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem)))
        {
            return pItemTypesTxtRecord->nReload;
        }
    }

    return 0;
}

// 0x0062E830
unsigned int __stdcall ITEMS_GetReEquip(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (pItemTypesTxtRecord)
        {
            return pItemTypesTxtRecord->nReEquip;
        }
    }

    return 0;
}

// 0x0062E880
unsigned char __stdcall ITEMS_GetStorePage(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (pItemTypesTxtRecord && pItemTypesTxtRecord->nStorePage != 0xFF)
        {
            return pItemTypesTxtRecord->nStorePage;
        }
    }

    return 0xFF;
}

// 0x0062E8D0
unsigned char __stdcall ITEMS_GetVarInvGfxCount(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (pItemTypesTxtRecord)
        {
            return pItemTypesTxtRecord->nVarInvGfx;
        }
    }

    return 0;
}

// 0x0062E920
char* __stdcall ITEMS_GetVarInvGfxString(D2UnitStrc* pItem, int nId)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (pItemTypesTxtRecord)
        {
            nId = D2_MIN(D2_MAX(nId, 0), pItemTypesTxtRecord->nVarInvGfx - 1);

            return pItemTypesTxtRecord->szInvGfx[nId];
        }
    }

    return gpszDefaultString;
}

// 0x0062E990
int __stdcall ITEMS_CanBeRare(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (pItemTypesTxtRecord)
        {
            return pItemTypesTxtRecord->nRare;
        }
    }

    return 0;
}

// 0x0062E9E0
int __stdcall ITEMS_CanBeMagic(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (pItemTypesTxtRecord)
        {
            return pItemTypesTxtRecord->nMagic;
        }
    }

    return 0;
}

// 0x0062EA30
int __stdcall ITEMS_CanBeNormal(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (pItemTypesTxtRecord)
        {
            return pItemTypesTxtRecord->nNormal;
        }
    }

    return 1;
}

// 0x0062EA80
void __stdcall ITEMS_GetAllowedBodyLocations(D2UnitStrc* pItem, unsigned char* pBodyLoc1, unsigned char* pBodyLoc2)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (!pItemTypesTxtRecord)
        {
            *pBodyLoc1 = 0;
            *pBodyLoc2 = 0;
            return;
        }

        *pBodyLoc1 = pItemTypesTxtRecord->nBodyLoc1;
        *pBodyLoc2 = pItemTypesTxtRecord->nBodyLoc2;
        return;
    }

    *pBodyLoc1 = 0;
    *pBodyLoc2 = 0;
}

// 0x0062ED50
int __stdcall ITEMS_CheckBodyLocation(D2UnitStrc* pItem, int nBodyLoc)
{
    const int nType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_ITEM)
    {
        unsigned char nBodyLoc1 = 0;
        unsigned char nBodyLoc2 = 0;
        ITEMS_GetAllowedBodyLocations(pItem, &nBodyLoc1, &nBodyLoc2);

        if (nBodyLoc1 == nBodyLoc || nBodyLoc2 == nBodyLoc
            || (nBodyLoc == BODYLOC_SWRARM || nBodyLoc == BODYLOC_SWLARM) && (nBodyLoc1 == BODYLOC_RARM || nBodyLoc2 == BODYLOC_RARM || nBodyLoc1 == BODYLOC_LARM || nBodyLoc2 == BODYLOC_LARM))
        {
            return 1;
        }
    }

    return 0;
}

// 0x0062FDC0
int __stdcall sub_0062FDC0_GetRepairCost(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nDifficulty, D2BitBufferStrc* pQuestFlags, int nNpcId, int nMode)
{
    return sub_0062EFB0_GetRepairCost(pUnit, pItem, nDifficulty, pQuestFlags, nNpcId, nMode);
}

// 0x0062FDF0
int __stdcall ITEMS_IsBodyItem(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        unsigned char nBodyLoc1 = 0;
        unsigned char nBodyLoc2 = 0;
        ITEMS_GetAllowedBodyLocations(pItem, &nBodyLoc1, &nBodyLoc2);

        if (nBodyLoc1 || nBodyLoc2)
        {
            D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
            if (pItemTypesTxtRecord)
            {
                return pItemTypesTxtRecord->nBody;
            }
        }
    }

    return FALSE;
}

// 0x006313E0
int __stdcall ITEMS_SerializeItemToBitstream(D2UnitStrc* pItem, unsigned char* pBitstream, int nSize, int bServer, int bSaveItemInv, int bGamble)
{
    D2BitBufferStrc pBuffer;

    BITMANIP_Initialize(&pBuffer, pBitstream, nSize);

    ITEMS_SerializeItem(pItem, &pBuffer, bServer, bSaveItemInv, bGamble);

    if (pBuffer.bFull)
    {
        return 0;
    }
    else
    {
        return BITMANIP_GetSize(&pBuffer);
    }
}

// 0x006314A0
int __fastcall sub_6FD55150(char* szText, int* a2, int a3, int nKeywordNumber)
{
    int nRow = 0;

    if (a3 == 1 && nKeywordNumber == 3)
    {
        if (gpItemStatCostLinker)
        {
            nRow = FOG_GetRowFromTxt(gpItemStatCostLinker, szText, 0);
            if (nRow >= 0)
            {
                *a2 = 1;
                return nRow;
            }
        }

        if (!SStrCmpI(szText, "base", 32))
        {
            *a2 = 0;
            return 1;
        }

        if (!SStrCmpI(szText, "mod", 32))
        {
            *a2 = 0;
            return 2;
        }

        SStrCmpI(szText, "accr", 32);
        *a2 = 0;
    }

    return 0;
}

// 0x00639D60
D2RunesTxt* __stdcall DATATBLS_GetRunesTxtRecord(int nRunewordId)
{
    D2_ASSERT(nRunewordId > 0 && nRunewordId < sgtRuneWordsTblDesc.nRunesTxtRecordCount, 2418);
    return &sgtRuneWordsTblDesc.pRunesTxt[nRunewordId];
}

// 0x00639DF0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState)
{
    if (pUnit)
    {
        switch (pUnit->dwUnitType)
        {
        case UNIT_PLAYER:
        case UNIT_MONSTER:
        case UNIT_MISSILE:
            if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
            {
                return sub_00625B70_CheckStatFlag(pUnit, nState);
            }
            break;
        }
    }

    return 0;
}

// 0x00639E90
int __stdcall STATES_CheckGfxStateFlag(D2UnitStrc* pUnit, int nState)
{
    unsigned int* pGfxFlags = 0;

    if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
    {
        pGfxFlags = D2COMMON_STATES_GetListGfxFlags_6FDB8AC0(pUnit);
        if (pGfxFlags)
        {
            return pGfxFlags[nState >> 5] & gdwBitMasks[nState & 31];
        }
    }

    return 0;
}

// 0x00639EE0
void __stdcall STATES_ClearGfxStateFlags(D2UnitStrc* pUnit)
{
    unsigned int* pGfxFlags = D2COMMON_STATES_GetListGfxFlags_6FDB8AC0(pUnit);

    if (pGfxFlags)
    {
        memset(pGfxFlags, 0x00, sizeof(unsigned int) * ((sgptDataTables->nStatesTxtRecordCount + 31) / 32));
    }
}

// 0x00639F20
int __stdcall STATES_IsAnyGfxStateFlagSet(D2UnitStrc* pUnit)
{
    unsigned int* pGfxFlags = D2COMMON_STATES_GetListGfxFlags_6FDB8AC0(pUnit);

    if (pGfxFlags)
    {
        for (int i = 0; i < (sgptDataTables->nStatesTxtRecordCount + 31) / 32; ++i)
        {
            if (pGfxFlags[i])
            {
                return 1;
            }
        }
    }

    return 0;
}

// 0x00639F70
unsigned int* __stdcall STATES_GetGfxStateFlags(D2UnitStrc* hUnit)
{
    D2_ASSERT(hUnit, 153);

    return D2COMMON_STATES_GetListGfxFlags_6FDB8AC0(hUnit);
}

// 0x0063A100
unsigned int* __stdcall D2COMMON_10494_STATES_GetStatFlags(D2UnitStrc* pUnit)
{
    return D2COMMON_STATES_GetStatFlags_6FDB8A90(pUnit);
}

// 0x0063A210
int __stdcall STATES_CheckStateMaskAuraByStateId(int nState)
{
    if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
    {
        return sgptDataTables->fStateMasks[STATEMASK_AURA][nState >> 5] & gdwBitMasks[nState & 31];
    }

    return 0;
}

// 0x0063A270
int __stdcall STATES_CheckStateMaskPgsvByStateId(int nState)
{
    if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
    {
        return sgptDataTables->fStateMasks[STATEMASK_PGSV][nState >> 5] & gdwBitMasks[nState & 31];
    }

    return 0;
}

// 0x0063A2F0
int __stdcall STATES_CheckStateMaskHideByStateId(int nState)
{
    return sgptDataTables->fStateMasks[STATEMASK_HIDE][nState >> 5] & gdwBitMasks[nState & 31];
}

// 0x0063A400
int __stdcall STATES_IsUnitShapeShifted(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlagEx >> UNITFLAGEX_ISSHAPESHIFTED_BIT) & 1;
}

// 0x0063A420
int __stdcall STATES_CheckStateMaskCurseByStateId(int nState)
{
    if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
    {
        return sgptDataTables->fStateMasks[STATEMASK_CURSE][nState >> 5] & gdwBitMasks[nState & 31];
    }

    return 0;
}

int __stdcall ITEMS_CheckRequirements(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bEquipping, int* pStrength, int* pDexterity, int* pLevel)
{
    if (pStrength)
    {
        *pStrength = FALSE;
    }
    if (pDexterity)
    {
        *pDexterity = 0;
    }
    if (pLevel)
    {
        *pLevel = 0;
    }

    const int nType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    D2ItemsTxt* pItemsTxtRecord = nType == UNIT_ITEM ? DATATBLS_GetItemsTxtRecord(pItem->dwClassId) : 0;
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    int bStrReqMet = TRUE;
    int bDexReqMet = TRUE;
    int bLevelReqMet = TRUE;
    const int bIdentified = ITEMS_CheckItemFlagInl(pItem, IFLAG_IDENTIFIED);
    const int nBaseReqStr = pItemsTxtRecord->wReqStr;
    const int nBaseReqDex = pItemsTxtRecord->wReqDex;

    int nReqStrBonus = 0;
    int nReqDexBonus = 0;
    if (const int nReqPctBonus = STATLIST_UnitGetItemStatOrSkillStatValue(pItem, STAT_ITEM_REQ_PERCENT, 0))
    {
        nReqStrBonus = DATATBLS_ApplyRatio(nBaseReqStr, nReqPctBonus, 100);
        nReqDexBonus = DATATBLS_ApplyRatio(nBaseReqDex, nReqPctBonus, 100);
    }

    if (ITEMS_CheckItemFlagInl(pItem, IFLAG_ETHEREAL))
    {
        nReqStrBonus -= 10;
        nReqDexBonus -= 10;
    }

    const int nStrength = STATLIST_UnitGetStatValue(pUnit, STAT_STRENGTH, 0);
    if (nStrength <= 0)
    {
        bStrReqMet = 0;
    }
    else
    {
        const int nReqStr = nBaseReqStr + nReqStrBonus;
        if (nStrength < nReqStr)
        {
            bStrReqMet = 0;
        }
        else if (bEquipping && STATLIST_GetOwner(pItem, 0))
        {
            int nSocketBonus = 0;
            sub_0062B450_GetSocketedStatBonus(STAT_STRENGTH, &nSocketBonus, pItem);
            const int nAdjusted = nStrength - nSocketBonus;
            if (nAdjusted <= 0)
            {
                bStrReqMet = 0;
            }
            else if (nAdjusted < nReqStr)
            {
                bStrReqMet = 0;
            }
        }
    }

    const int nDexterity = STATLIST_UnitGetStatValue(pUnit, STAT_DEXTERITY, 0);
    if (nDexterity <= 0)
    {
        bDexReqMet = 0;
    }
    else
    {
        const int nReqDex = nBaseReqDex + nReqDexBonus;
        if (nDexterity < nReqDex)
        {
            bDexReqMet = 0;
        }
        else if (bEquipping)
        {
            int nSocketBonus = 0;
            sub_0062B450_GetSocketedStatBonus(STAT_DEXTERITY, &nSocketBonus, pItem);
            const int nAdjusted = nDexterity - nSocketBonus;
            if (nAdjusted <= 0)
            {
                bDexReqMet = 0;
            }
            if (nAdjusted < nReqDex)
            {
                bDexReqMet = 0;
            }
        }
    }

    const int nLevelReq = ITEMS_GetLevelRequirement(pItem, pUnit);
    if (nLevelReq != -1 && STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0) < nLevelReq)
    {
        bLevelReqMet = 0;
    }

    if (pStrength)
    {
        *pStrength = bStrReqMet;
    }
    if (pDexterity)
    {
        *pDexterity = bDexReqMet;
    }
    if (pLevel)
    {
        *pLevel = bLevelReqMet;
    }

    if (bStrReqMet && bDexReqMet && bLevelReqMet && bIdentified)
    {
        if (ITEMS_GetItemType(pItem) == ITEMTYPE_BOOK && STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0) <= 0)
        {
            return 0;
        }

        const int nClass = sub_0062C0B0_GetItemTypeClass(pItem);
        if (nClass == PCLASS_INVALID)
        {
            return 1;
        }

        if (!pUnit)
        {
            return 0;
        }

        const int nUnitType = pUnit->dwUnitType;
        if (nUnitType == UNIT_MONSTER && nClass == PCLASS_BARBARIAN)
        {
            const int nMonsterId = MONSTERS_GetBaseIdFromMonsterId(pUnit->dwClassId);
            if (nMonsterId >= MONSTER_ACT5HIRE1 && nMonsterId <= MONSTER_ACT5HIRE2)
            {
                return 1;
            }
        }

        if (nUnitType == UNIT_PLAYER && nClass == pUnit->dwClassId)
        {
            return 1;
        }
    }

    return 0;
}
