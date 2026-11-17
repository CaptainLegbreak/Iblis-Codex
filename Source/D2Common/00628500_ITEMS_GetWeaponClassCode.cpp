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
    char unk0xC8[20];
    unsigned int dwBitField1;
    char unk0xE0[26];
    unsigned short wMissileType;
    char unk0xFC[1];
    unsigned char nLevel;
    char unk0xFE[6];
    unsigned char nRangeAdder;
    char unk0x105[1];
    short nStrBonus;
    short nDexBonus;
    char unk0x10A[5];
    unsigned char nInvWidth;
    unsigned char nInvHeight;
    char unk0x111[4];
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
    char unk0x133[2];
    unsigned char nDurWarning;
    unsigned char nQuantityWarning;
    unsigned char nHasInv;
    unsigned char nGemSockets;
    char unk0x139[3];
    unsigned char nHitClass;
    char unk0x13D[107];
};
struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0

#define UNIT_ITEM 4
#define ITEMTYPE_QUEST 39
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

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
unsigned int __stdcall ITEMS_Get2HandWeaponClassCode(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 1544);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 1545);

    const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 1548);
    return pItemsTxtRecord->dwWeapClass2Hand;
}

// 0x00628590
unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 1562);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 1563);

    const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 1566);
    return pItemsTxtRecord->dwCode;
}

// 0x006285F0
unsigned int __stdcall ITEMS_GetAltGfx(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 1575);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 1576);

    const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
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
unsigned char __stdcall ITEMS_GetComponent(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 1588);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 1589);

    const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
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
unsigned char __stdcall ITEMS_GetItemQlvl(const D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 1686);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 1687);

    const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 1690);
    return pItemsTxtRecord->nLevel;
}

// 0x006287D0
unsigned int __stdcall ITEMS_GetNormalCode(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 1943);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 1944);

    const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
    if (pItemsTxtRecord->dwNormCode)
    {
        return pItemsTxtRecord->dwNormCode;
    }
    else
    {
        return pItemsTxtRecord->dwCode;
    }
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
int __stdcall ITEMS_GetUniqueColumnFromItemsTxt(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 2509);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 2510);

    const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 2513);
    return pItemsTxtRecord->nUnique;
}

// 0x00628CD0
int __stdcall ITEMS_IsQuestItem(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 2522);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 2523);

    const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 2526);
    return pItemsTxtRecord->nQuest;
}

// 0x00629740
int __stdcall ITEMS_CheckBitField1Flag8(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 3485);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 3486);

    const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 3488);
    return pItemsTxtRecord->dwBitField1 & 8;
}

// 0x006297A0
unsigned char __stdcall ITEMS_GetDurWarnCount(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 3523);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 3524);

    const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 3526);
    return pItemsTxtRecord->nDurWarning;
}

// 0x00629800
unsigned char __stdcall ITEMS_GetQtyWarnCount(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 3535);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 3536);

    const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
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
