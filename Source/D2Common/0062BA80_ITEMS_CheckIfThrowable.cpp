struct D2ItemTypesTxt
{
    char unk0x00[10];
    unsigned char nBodyLoc1;
    unsigned char nBodyLoc2;
    char unk0x0C[4];
    unsigned char nThrowable;
    char unk0x11[1];
    unsigned char nReEquip;
    char unk0x13[1];
    unsigned char nMagic;
    unsigned char nRare;
    unsigned char nNormal;
    char unk0x17[2];
    unsigned char nBeltable;
    char unk0x1A[5];
    unsigned char nStaffMods;
    char unk0x20[1];
    unsigned char nClass;
    unsigned char nStorePage;
    unsigned char nVarInvGfx;
    char szInvGfx[6][32];
};
struct D2UnitStrc
{
    int dwUnitType;
};
struct D2DataTablesStrc
{
    char unk0x00[3064];
    D2ItemTypesTxt* pItemTypesTxt;
    int nItemTypesTxtRecordCount;
};
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern char* gpszDefaultString;                                                                             // 0x007446E4
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                         // 0x0062B400

#define UNIT_ITEM 4
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

inline D2ItemTypesTxt* DATATBLS_GetItemTypesTxtRecord(int nItemType)
{
    if (nItemType >= 0 && nItemType < sgptDataTables->nItemTypesTxtRecordCount)
    {
        return &sgptDataTables->pItemTypesTxt[nItemType];
    }

    return 0;
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

#include "gen/data/Source/D2Common/0062BA80_ITEMS_CheckIfThrowable.inc"
