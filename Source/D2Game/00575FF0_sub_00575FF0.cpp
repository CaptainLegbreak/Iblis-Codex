struct D2InventoryStrc;
struct D2StatListStrc;

struct D2GameStrc
{
    char unk0x00[0x70];
    int nGameType;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x08];
    int dwUnitId;
    char unk0x10[0x50];
    D2InventoryStrc* pInventory;
};

struct D2HirelingTxt
{
    char unk0x000[0x08];
    int dwClass;
    char unk0x00C[0x108];
    unsigned short wNameFirst;
    unsigned short wNameLast;
};

struct D2NpcGambleStrc
{
    D2InventoryStrc* pInventory;
    int dwGUID;
    D2NpcGambleStrc* pNext;
};

struct D2NpcRecordStrc
{
    char unk0x00[0x08];
    D2NpcGambleStrc* pGamble;
    int bGambleInit;
};

struct D2DataTablesStrc
{
    char unk0x00[0xC4];
    int nStatesTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2HirelingTxt* __stdcall sub_006564D0_GetHirelingTxtRecord(int nGameType, int nId, int nDifficulty, int a4); // 0x006564D0
void __fastcall D2GAME_NPC_RepairItem_6FCC6970(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer);  // 0x005761C0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __fastcall PLRTRADE_AddGold(D2UnitStrc* pUnit, int nStat, int nValue);                                 // 0x0053FF00
int __stdcall UNITS_GetStashGoldLimit(D2UnitStrc* pUnit);                                                   // 0x00623460
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x006272B0
D2NpcRecordStrc* __fastcall SUNITPROXY_GetNpcRecordFromUnit(D2GameStrc* pGame, D2UnitStrc* pNpc, int* pIndex); // 0x00535F10
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                 // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                            // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                             // 0x0063DFD0
bool __fastcall sub_00576ED0(D2GameStrc* pGame, D2UnitStrc* pNpc, D2UnitStrc* pItem);                 // 0x00576ED0
void __fastcall sub_00576650_AddGambleItem(D2UnitStrc* pPlayer, D2UnitStrc* pNpc, D2UnitStrc* pItem, D2GameStrc* pGame, int bInit); // 0x00576650
void __fastcall sub_6FCC6F10(D2UnitStrc* pNpc, D2UnitStrc* pItem, D2GameStrc* pGame, int bInit);           // 0x005766D0
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic);                          // 0x00625820
void __stdcall STATLIST_ExpireUnitStatlist(D2UnitStrc* pUnused, D2UnitStrc* pUnit);                         // 0x006277F0
void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType);                  // 0x00627910
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __stdcall STATES_CheckStateMaskCurableByStateId(int nState);                                            // 0x0063A460
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0
void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList);                              // 0x006277E0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList);                                            // 0x00626CD0

// 0x00575FF0
int __fastcall sub_00575FF0(D2GameStrc* pGame, int nHirelingId, int* pNameFirst, int* pNameLast, int* pClass)
{
    D2HirelingTxt* pHirelingTxtRecord = sub_006564D0_GetHirelingTxtRecord(pGame->nGameType, nHirelingId, 0, 0);
    if (!pHirelingTxtRecord)
    {
        *pNameFirst = 0;
        *pNameLast = 0;
        *pClass = 0;
        return -1;
    }

    *pNameFirst = pHirelingTxtRecord->wNameFirst;
    *pNameLast = pHirelingTxtRecord->wNameLast;
    if (pClass)
    {
        *pClass = pHirelingTxtRecord->dwClass;
    }

    const int nCount = *pNameLast - *pNameFirst + 1;
    D2_ASSERT(nCount != -1, 96);
    return nCount;
}

// 0x005762B0
void __fastcall sub_005762B0_RepairItemCallback(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer)
{
    D2GAME_NPC_RepairItem_6FCC6970(pGame, pItem, pPlayer);
}

// 0x00576D90
int __fastcall sub_00576D90_SpendGold(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nCost)
{
    const int nGold = STATLIST_UnitGetStatValue(pPlayer, 14, 0);
    if (nGold + STATLIST_UnitGetStatValue(pPlayer, 15, 0) < nCost)
    {
        return 0;
    }

    if (nCost <= nGold)
    {
        PLRTRADE_AddGold(pPlayer, 14, -nCost);
        return 1;
    }

    PLRTRADE_AddGold(pPlayer, 14, -nGold);

    const int nValue = nGold - nCost;
    if (pPlayer)
    {
        const int nNewValue = nValue + STATLIST_UnitGetStatValue(pPlayer, 15, 0);
        if (nNewValue < 0)
        {
            STATLIST_SetUnitStat(pPlayer, 15, 0, 0);
            return 1;
        }

        if (pPlayer->dwUnitType == 0 && nNewValue > UNITS_GetStashGoldLimit(pPlayer))
        {
            STATLIST_SetUnitStat(pPlayer, 15, 0, 0);
            return 1;
        }

        STATLIST_AddUnitStat(pPlayer, 15, nValue, 0);
    }

    return 1;
}

// 0x00576F50
void __fastcall sub_6FCC7E20(D2GameStrc* pGame, D2UnitStrc* pNpc, D2UnitStrc* pItem, D2UnitStrc* pUnit, int a5)
{
    int nUnused;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromUnit(pGame, pNpc, &nUnused);
    if (pNpcRecord->bGambleInit && a5 == 2)
    {
        D2NpcGambleStrc* pNpcGamble = pNpcRecord->pGamble;
        const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
        while (pNpcGamble)
        {
            if (pNpcGamble->dwGUID == nUnitGUID)
            {
                break;
            }

            pNpcGamble = pNpcGamble->pNext;
        }

        if (pNpcGamble && pNpcGamble->pInventory)
        {
            D2UnitStrc* pCurrent = INVENTORY_GetFirstItem(pNpcGamble->pInventory);
            while (pCurrent)
            {
                D2UnitStrc* pCheck = INVENTORY_UnitIsItem(pCurrent);
                D2UnitStrc* pNext = INVENTORY_GetNextItem(pCurrent);
                if (pCheck == pItem)
                {
                    sub_00576650_AddGambleItem(pUnit, pNpc, pItem, pGame, 1);
                    return;
                }

                pCurrent = pNext;
            }
        }
    }

    if (!sub_00576ED0(pGame, pNpc, pItem))
    {
        sub_6FCC6F10(pNpc, pItem, pGame, 1);
    }
}

// 0x00577470
int __fastcall sub_00577470_RelinkItemStatLists(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    if (!pUnit->pInventory)
    {
        return 0;
    }

    D2UnitStrc* pNext;
    for (D2UnitStrc* pCurrent = INVENTORY_GetFirstItem(pUnit->pInventory); pCurrent; pCurrent = pNext)
    {
        pNext = INVENTORY_GetNextItem(pCurrent);
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pCurrent);
        int bStatNotDynamic = 0;
        if (pItem && pItem->dwUnitType == 4 && STATLIST_GetOwner(pItem, &bStatNotDynamic))
        {
            STATLIST_ExpireUnitStatlist(pUnit, pItem);
            STATLIST_MergeStatLists(pUnit, pItem, bStatNotDynamic);
        }
    }

    return 1;
}

// 0x00578C20
int __fastcall D2GAME_NPC_RemoveStates_6FCCAF30(D2UnitStrc* pUnit)
{
    int bStateRemoved = 0;
    for (int nState = 0; nState < sgptDataTables->nStatesTxtRecordCount; ++nState)
    {
        if (STATES_CheckState(pUnit, nState) && STATES_CheckStateMaskCurableByStateId(nState))
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
            if (pStatList)
            {
                D2Common_10474(pUnit, pStatList);
                STATLIST_FreeStatList(pStatList);
                bStateRemoved = 1;
            }
        }
    }

    return bStateRemoved;
}
