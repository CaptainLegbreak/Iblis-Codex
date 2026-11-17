// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040

struct D2InventoryStrc;
struct D2BitBufferStrc;
struct D2ItemsTxt;

struct D2UnitStrc
{
    int dwUnitType;
    unsigned int dwClassId;
    int unk0x08;
    int dwUnitId;
    char unk0x10[0x50];
    D2InventoryStrc* pInventory;
};

struct Unicode
{
    unsigned short wChar;

    Unicode();                                                                                              // 0x0042F530
};

extern int gnGlobal_007C0D25;                                                                               // 0x007C0D25
extern int gnGlobal_007C0D29;                                                                               // 0x007C0D29
extern int gnGlobal_007C0D31;                                                                               // 0x007C0D31
extern D2BitBufferStrc* gpQuestFlags_007C0D43;                                                              // 0x007C0D43
extern int gnGlobal_007C0D4B;                                                                               // 0x007C0D4B
extern int gnGlobal_007C0D4F;                                                                               // 0x007C0D4F
extern int gnGlobal_007C0D7F;                                                                               // 0x007C0D7F
extern int gdwGlobal_007C0DB0;                                                                              // 0x007C0DB0
extern char gbGlobal_007C0DE0;                                                                              // 0x007C0DE0
extern int gnGlobal_007C0DE1;                                                                               // 0x007C0DE1
extern int gnGlobal_007C0DE5;                                                                               // 0x007C0DE5
extern int gnGlobal_007C0DF1;                                                                               // 0x007C0DF1
extern int gnGlobal_007C0C6B;                                                                               // 0x007C0C6B
extern "C" const char gszNpcMenuFile_006DA630[];                                                            // 0x006DA630
extern "C" const char gszFormatD_006D57BC[];                                                                // 0x006D57BC

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);            // 0x006CC468
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                         // 0x0062B400
int __stdcall sub_0062E660(D2UnitStrc* pItem);                                                              // 0x0062E660
int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem);                                                       // 0x00629930
int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit);                                         // 0x00625E00
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);                        // 0x00625480
int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem);                                                    // 0x006289F0
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem);                                                    // 0x006295B0
int __stdcall ITEMS_HasUsedCharges(D2UnitStrc* pItem, int* pHasChargedSkills);                              // 0x0062A840
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
D2UnitStrc* __cdecl sub_004B1620_GetInteractNpc();                                                          // 0x004B1620
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
int __stdcall sub_0062A130(D2UnitStrc* pItem);                                                              // 0x0062A130
int __cdecl sub_00489860();                                                                                 // 0x00489860
int __cdecl sub_00489870();                                                                                 // 0x00489870
Unicode* __fastcall sub_004521C0_PrefixLevelText(Unicode* pText, int nDigit);                               // 0x004521C0
unsigned char __cdecl sub_0044DCD0_GetDifficulty();                                                         // 0x0044DCD0
D2UnitStrc* __cdecl sub_00463DE0_GetStoredUnit();                                                           // 0x00463DE0
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
int __stdcall ITEMS_GetTransactionCost(D2UnitStrc* pPlayer, D2UnitStrc* pItem, int nDifficulty, D2BitBufferStrc* pQuestFlags, int nVendorId, int nTransactionType); // 0x0062FDC0
int __stdcall ITEMS_GetAllRepairCosts(void* pGame, D2UnitStrc* pUnit, int nNpcId, int nDifficulty, D2BitBufferStrc* pQuestFlags, void* pfCallback); // 0x0062FE60
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                   // 0x00526F20
void __fastcall sub_00467A70(int nArg);                                                                     // 0x00467A70
void __stdcall sub_004B2650(int nArg1, int nArg2);                                                          // 0x004B2650
void __cdecl sub_004B2F50();                                                                                // 0x004B2F50
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00

static int sub_004B1F80_ItemNeedsRepair(D2UnitStrc* pItem); // 0x004B1F80

// 0x004B1F80
static int sub_004B1F80_ItemNeedsRepair(D2UnitStrc* pItem)
{
    if (ITEMS_GetItemType(pItem) == 4)
        return 0;
    if (!sub_0062E660(pItem))
        return 0;
    if (ITEMS_HasDurability(pItem))
    {
        const int nMaxDurability = STATLIST_GetMaxDurabilityFromUnit(pItem);
        if (nMaxDurability && STATLIST_UnitGetStatValue(pItem, 0x48, 0) < nMaxDurability)
            return 1;
    }
    if (ITEMS_CheckIfStackable(pItem) && STATLIST_UnitGetStatValue(pItem, 0x46, 0) < ITEMS_GetTotalMaxStack(pItem))
        return 1;
    int bHasChargedSkills;
    if (ITEMS_HasUsedCharges(pItem, &bHasChargedSkills) && !bHasChargedSkills)
        return 1;
    return 0;
}

// build: context GetInteractNpc_Inline
static __forceinline D2UnitStrc* GetInteractNpc_Inline()
{
    if (!gnGlobal_007C0D29)
        return 0;
    return sub_00463990(gnGlobal_007C0D25, 1);
}

// build: context GetUnitIdOrNone
static int GetUnitIdOrNone(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return -1;
    return pUnit->dwUnitId;
}

// build: context GetClassIdOrNone
static int GetClassIdOrNone(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return -1;
    return pUnit->dwClassId;
}

// 0x004B2AD0
int __fastcall sub_004B2AD0_GetTradeCostText(D2UnitStrc* pItem, int bService, int* pCost, Unicode* pText, int nMaxLength)
{
    *pCost = 0;
    if (!pItem)
        return 0;
    if (ITEMS_GetItemType(pItem) == 4)
        return 0;
    int nStringId = 0;
    if (bService)
    {
        const unsigned int nClassId = pItem->dwClassId;
        if (!gnGlobal_007C0D29)
            return 0;
        if (!sub_00463990(gnGlobal_007C0D25, 1))
            return 0;
        D2UnitStrc* pNpc = sub_004B1620_GetInteractNpc();
        const unsigned int nNpcClass = !pNpc ? -1 : pNpc->dwClassId;
        DATATBLS_GetItemsTxtRecord(nClassId);
        switch (nNpcClass)
        {
        case 0xF4:
        case 0xF5:
        case 0x109:
            if (ITEMS_CheckItemFlag(pItem, 0x10, 0x999, gszNpcMenuFile_006DA630) == 1)
            {
                *(int*)pText = 0;
                return 1;
            }
            *pCost = QUESTRECORD_GetQuestState(gpQuestFlags_007C0D43, 4, 0) ? 0 : 100;
            nStringId = 0xD04;
            break;
        case 0x9A:
        case 0xB2:
        case 0xFD:
        case 0x101:
        case 0x1FF:
        {
            if (sub_00489860())
            {
                if (!ITEMS_CheckItemFlag(pItem, 0x10, 0x147B, gszNpcMenuFile_006DA630))
                {
                    sub_00526700(pText, D2LANG_GetStringFromTblIndex(0xFB6));
                    sub_004521C0_PrefixLevelText(pText, 1);
                    return 1;
                }
                if (!sub_004B1F80_ItemNeedsRepair(pItem))
                    return 0;
                D2UnitStrc* pVendor = sub_004B1620_GetInteractNpc();
                *pCost = ITEMS_GetTransactionCost(sub_00463DE0_GetStoredUnit(), pItem, sub_0044DCD0_GetDifficulty(), gpQuestFlags_007C0D43, !pVendor ? -1 : pVendor->dwClassId, 3);
                nStringId = 0xD02;
                break;
            }
        }
        case 0x93:
        case 0x94:
        case 0xB1:
        case 0xC7:
        case 0xCA:
        case 0xF6:
        case 0xFC:
        case 0xFE:
        case 0xFF:
        case 0x195:
        case 0x200:
        case 0x201:
        case 0x202:
        {
            if (!sub_0062A130(pItem))
                return 0;
            D2UnitStrc* pVendor = sub_004B1620_GetInteractNpc();
            *pCost = ITEMS_GetTransactionCost(sub_00463DE0_GetStoredUnit(), pItem, sub_0044DCD0_GetDifficulty(), gpQuestFlags_007C0D43, !pVendor ? -1 : pVendor->dwClassId, 1);
            nStringId = 0xD03;
            break;
        }
        }
    }
    else
    {
        int nType = 0;
        if (gdwGlobal_007C0DB0)
            nType = 2;
        D2UnitStrc* pVendor = GetInteractNpc_Inline();
        const int nVendorId = !pVendor ? -1 : pVendor->dwClassId;
        *pCost = ITEMS_GetTransactionCost(sub_00463DE0_GetStoredUnit(), pItem, sub_0044DCD0_GetDifficulty(), gpQuestFlags_007C0D43, nVendorId, nType);
        nStringId = 0xD01;
    }
    if (!nStringId)
        return 0;
    const Unicode* pString = D2LANG_GetStringFromTblIndex(nStringId);
    if (sub_00526800(pString) + 10 > nMaxLength)
        return 0;
    sub_005267E0(pText, pString);
    Unicode wszCost[20];
    char szCost[20];
    wsprintfA(szCost, gszFormatD_006D57BC, *pCost);
    sub_00526F20_ToUnicode(wszCost, szCost, 19);
    sub_00526700(pText, wszCost);
    return 1;
}

// 0x004B3870
int __fastcall sub_004B3870_HandleTradeClick(D2UnitStrc* pPlayer, D2UnitStrc* pItem, int nMode, int nX, int nY, int nArg, int bCheckTick, int bRepairAll)
{
    D2UnitStrc* pNpc = GetInteractNpc_Inline();
    if (!pNpc)
        return 0;
    const int nNpcClass = pNpc->dwClassId;
    if (bRepairAll)
    {
        switch (nNpcClass)
        {
        case 0x9A:
        case 0xB2:
        case 0xFD:
        case 0x101:
        case 0x1FF:
            break;
        default:
            return 0;
        }
        if (!sub_00489870())
            return 1;
        gnGlobal_007C0D7F = ITEMS_GetAllRepairCosts(0, pPlayer, nNpcClass, sub_0044DCD0_GetDifficulty(), gpQuestFlags_007C0D43, 0);
        gnGlobal_007C0D31 = 3;
        gbGlobal_007C0DE0 = 1;
        gnGlobal_007C0DE5 = 0;
        sub_00467A70(0);
        gnGlobal_007C0D4B = nX;
        gnGlobal_007C0D4F = nY;
    }
    else
    {
        if (ITEMS_GetItemType(pItem) == 4)
            return 0;
        if (bCheckTick && GetTickCount() - gnGlobal_007C0DF1 < 0x1F4)
            return 0;
        gnGlobal_007C0D4B = nX;
        gnGlobal_007C0D4F = nY;
        if (nMode == 1)
        {
            switch (nNpcClass)
            {
            case 0x9A:
            case 0xB2:
            case 0xFD:
            case 0x101:
            case 0x1FF:
                if (sub_00489860())
                {
                    if (!sub_004B1F80_ItemNeedsRepair(pItem))
                        return 0;
                    gnGlobal_007C0D31 = 3;
                    gnGlobal_007C0D7F = ITEMS_GetTransactionCost(sub_00463DE0_GetStoredUnit(), pItem, sub_0044DCD0_GetDifficulty(), gpQuestFlags_007C0D43, nNpcClass, 3);
                    break;
                }
                gnGlobal_007C0D7F = ITEMS_GetTransactionCost(sub_00463DE0_GetStoredUnit(), pItem, sub_0044DCD0_GetDifficulty(), gpQuestFlags_007C0D43, nNpcClass, 1);
                if (!sub_0062A130(pItem))
                    return 0;
                gnGlobal_007C0D31 = 2;
                break;
            case 0x93:
            case 0x94:
            case 0xB1:
            case 0xC7:
            case 0xCA:
            case 0xFC:
            case 0xFE:
            case 0xFF:
            case 0x195:
            case 0x200:
            case 0x201:
            case 0x202:
                gnGlobal_007C0D7F = ITEMS_GetTransactionCost(sub_00463DE0_GetStoredUnit(), pItem, sub_0044DCD0_GetDifficulty(), gpQuestFlags_007C0D43, nNpcClass, 1);
                if (!sub_0062A130(pItem))
                    return 0;
                gnGlobal_007C0D31 = 2;
                break;
            case 0xF4:
            case 0xF5:
            case 0xF6:
            case 0x109:
            case 0x208:
                if (ITEMS_CheckItemFlag(pItem, 0x10, 0x999, gszNpcMenuFile_006DA630) == 1)
                    return 0;
                gnGlobal_007C0D31 = 4;
                break;
            default:
                return 0;
            }
        }
        else
        {
            D2InventoryStrc* pInventory = sub_00463DD0()->pInventory;
            if (INVENTORY_GetCursorItem(pInventory))
                return 0;
            gnGlobal_007C0D31 = 1;
            int nType = 0;
            if (gdwGlobal_007C0DB0)
                nType = 2;
            gnGlobal_007C0D7F = ITEMS_GetTransactionCost(sub_00463DE0_GetStoredUnit(), pItem, sub_0044DCD0_GetDifficulty(), gpQuestFlags_007C0D43, nNpcClass, nType);
        }
        gbGlobal_007C0DE0 = 1;
        gnGlobal_007C0DE5 = GetUnitIdOrNone(pItem);
        gnGlobal_007C0DE1 = GetClassIdOrNone(pItem);
        sub_00467A70(0);
        if (!((gnGlobal_007C0D31 == 2 && bCheckTick) || (gnGlobal_007C0D31 == 1 && bCheckTick)))
        {
            sub_004B9A00(1, 0, 0, 0, 0);
            gnGlobal_007C0C6B = 4;
            sub_004B2F50();
            return 1;
        }
    }
    sub_004B2650(1, nArg);
    return 1;
}
