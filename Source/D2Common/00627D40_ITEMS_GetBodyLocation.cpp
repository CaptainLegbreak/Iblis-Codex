struct D2TxtLinkStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2ItemDataStrc
{
    int dwQualityNo;
    D2SeedStrc pSeed;
    int dwOwnerGUID;
    unsigned int dwInitSeed;
    unsigned int dwCommandFlags;
    unsigned int dwItemFlags;
    char unk0x1C[0x0C];
    int dwFileIndex;
    int dwItemLevel;
    unsigned short wItemFormat;
    unsigned short wRarePrefix;
    unsigned short wRareSuffix;
    unsigned short wAutoAffix;
    unsigned short wMagicPrefix[3];
    unsigned short wMagicSuffix[3];
    unsigned char nBodyLoc;
    unsigned char nInvPage;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x04];
    D2ItemDataStrc* pItemData;
    char unk0x18[0xB0];
    unsigned int dwFlagEx;
};

struct D2ItemsTxt
{
    char unk0x00[0x132];
    unsigned char nStackable;
};

struct D2ItemTypesTxt
{
    char szCode[4];
    short nEquiv1;
    short nEquiv2;
    unsigned char nRepair;
    unsigned char nBody;
    unsigned char nBodyLoc1;
    unsigned char nBodyLoc2;
    short wShoots;
    short wQuiver;
    unsigned char nThrowable;
    unsigned char nReload;
    unsigned char nReEquip;
    unsigned char nAutoStack;
    char unk0x14[0xD0];
};

struct D2RunesTxt
{
    char unk0x00[0x120];
};

struct D2RuneDataTbl
{
    int nRunesTxtRecordCount;
    D2RunesTxt* pRunesTxt;
};

struct D2DataTablesStrc
{
    char unk0x00[0xC4];
    int nStatesTxtRecordCount;
    char unk0xC8[0x04];
    unsigned int* fStateMasks[40];
    char unk0x16C[0xA8C];
    D2ItemTypesTxt* pItemTypesTxt;
    int nItemTypesTxtRecordCount;
};

struct D2BitBufferStrc
{
    unsigned char* pBuffer;
    int nBits;
    int nPos;
    int nPosBits;
    int bFull;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern D2RuneDataTbl gRuneDataTables;                                                                       // 0x0096CA98
extern D2TxtLinkStrc* gpItemStatCostLinker;                                                                 // 0x0096C800
extern const unsigned int gdwBitMasks[32];                                                                  // 0x006CE268

void __fastcall SEED_InitSeed(D2SeedStrc* pSeed);                                                           // 0x00650E30
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
unsigned int __stdcall ITEMS_GetItemTypeFromItemId(unsigned int dwItemId);                                  // 0x00628700
void __stdcall BITMANIP_Initialize(D2BitBufferStrc* pBuffer, unsigned char* pBitStream, int nSize);        // 0x00410E40
int __stdcall BITMANIP_GetSize(D2BitBufferStrc* pBuffer);                                                   // 0x00410E90
void __fastcall ITEMS_SerializeItem(D2UnitStrc* pItem, D2BitBufferStrc* pBuffer, int bServer, int bSaveItemInv, int bGamble); // 0x006312B0
int __stdcall FOG_GetRowFromTxt(D2TxtLinkStrc* pLinker, const char* szText, int nColumn);                   // 0x006BD3C0
int __stdcall SStrCmpI(const char* szString1, const char* szString2, int nMaxChars);                        // 0x00413590
int __stdcall sub_00625B70_CheckStatFlag(D2UnitStrc* pUnit, int nState);                                    // 0x00625B70

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_MISSILE 3
#define UNIT_ITEM 4
#define UNIT_INVALID 6
#define ITEMQUAL_NORMAL 2
#define ITEMQUAL_MAGIC 4
#define ITEMQUAL_TEMPERED 9
#define IFLAG_ETHEREAL 0x00400000
#define BODYLOC_NONE 0
#define PCLASS_AMAZON 0
#define PCLASS_SORCERESS 1
#define PCLASS_NECROMANCER 2
#define PCLASS_PALADIN 3
#define PCLASS_BARBARIAN 4
#define PCLASS_DRUID 5
#define PCLASS_ASSASSIN 6
#define STATEMASK_AURA 1
#define STATEMASK_HIDE 2
#define STATEMASK_PGSV 4
#define STATEMASK_CURSE 11
#define UNITFLAGEX_ISSHAPESHIFTED_BIT 3

inline D2ItemDataStrc* ITEMS_GetItemData(D2UnitStrc* pItem)
{
    return (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData) ? pItem->pItemData : 0;
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

// 0x00627DC0
void __stdcall ITEMS_InitItemSeed(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        SEED_InitSeed(&pItemData->pSeed);
    }
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

// 0x00627EC0
unsigned short __stdcall ITEMS_GetPrefixId(D2UnitStrc* pItem, int nPrefixNo)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->wMagicPrefix[nPrefixNo];
    }

    return 0;
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

// 0x00628010
void __stdcall ITEMS_AssignRarePrefix(D2UnitStrc* pItem, unsigned short nPrefix)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        pItemData->wRarePrefix = nPrefix;
    }
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

// 0x00629DA0
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 4208);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 4209);
    D2_ASSERT(pItem->pItemData, 4211);
    return pItem->pItemData->dwFileIndex;
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

// 0x0062A8D0
int __stdcall ITEMS_IsEthereal(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->dwItemFlags & IFLAG_ETHEREAL;
    }

    return 0;
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
    D2_ASSERT(nRunewordId > 0 && nRunewordId < gRuneDataTables.nRunesTxtRecordCount, 2418);
    return &gRuneDataTables.pRunesTxt[nRunewordId];
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
