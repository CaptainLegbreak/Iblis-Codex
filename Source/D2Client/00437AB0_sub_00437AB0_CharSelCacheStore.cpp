struct D2UnitStrc;
struct D2ActiveRoomStrc;
struct D2InventoryStrc;
struct D2DynamicPathStrc;
struct D2StatListStrc;

struct D2UnitStrc
{
    unsigned int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    unsigned int dwUnitId;
    char unk0x10[0x1C];
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0x30];
    D2InventoryStrc* pInventory;
    char unk0x64[0x84];
    D2UnitStrc* pRoomNext;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

struct D2StatesTxt
{
    unsigned short wState;
    unsigned short wOverlay[4];
    unsigned short wCastOverlay;
    unsigned short wRemoveOverlay;
    short wPrgOverlay;
    unsigned char nStateFlags[4];
    unsigned int dwStateFlagsEx;
    short wStat;
};

struct D2DataTablesStrc
{
    char unk0x00[0x16C];
    short* pProgressiveStates;
    short nProgressiveStates;
    char unk0x172[0xA4E];
    int nOverlayTxtRecordCount;
    char unk0xBC4[0x10];
    int nItemStatCostTxtRecordCount;
};

struct D2CharSelCacheStrc
{
    unsigned int dwHash;
    void* pData;
    unsigned int dwExpireTick;
    D2CharSelCacheStrc* pNext;
};

struct D2LaunchCharInfoStrc
{
    char unk0x00[0x19];
    char nState[4];
    char wValue[2];
    char szText0x1F[0x18];
    char szText0x37[0x1B8];
    char wFlags[2];
    char unk0x1F1[0x3C];
    char bOnline;
    char unk0x22E[0x17];
    char szText0x245[0x10];
    char unk0x255[0x109];
    char nType0x35E;
};

struct D2LaunchRequestStrc
{
    int nData[5];
    unsigned int dwFlags;
};

struct D2UnitDropItemsPacketStrc
{
    char nHeader;
    char bActive;
    char nUnitId[4];
    char nOtherUnitId[4];
};

struct D2GridCellStrc
{
    int nFlag;
    unsigned char nValue[4];
};

typedef void (__stdcall* D2RecordHandlerFn)(int nArg1, int nArg2, int nArg3);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long nMilliseconds);                         // 0x006CC258
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

unsigned int __stdcall SStrHash(const char* szString, unsigned int nFlags, unsigned int nSeed);             // 0x00413CE0
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650

void __cdecl sub_00444E70_SendFallbackRequest();                                                            // 0x00444E70
void __fastcall sub_0044A590_SendRequest(D2LaunchRequestStrc* pRequest, unsigned short wRequestId);         // 0x0044A590
void __cdecl sub_00451620_WriteRecordFile();                                                                // 0x00451620
D2StatesTxt* __fastcall DATATBLS_GetStatesTxtRecord(int nStateId);                                          // 0x00452040
void __cdecl sub_004584C0_ResetA();                                                                         // 0x004584C0
void __cdecl sub_00458680_ResetB();                                                                         // 0x00458680
void __cdecl sub_00458750_Rebuild();                                                                        // 0x00458750
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
void __fastcall sub_004565E0_Redraw(int nArg);                                                              // 0x004565E0
unsigned char __stdcall sub_00462EE0_GetItemComponent(D2UnitStrc* pUnit, D2UnitStrc* pItem);                // 0x00462EE0
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2UnitStrc* __cdecl sub_00463DE0_GetStoredUnit();                                                           // 0x00463DE0
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit);                                               // 0x00464820
void __fastcall sub_00465EE0_RemoveClientSideUnit(int nUnitId, int nUnitType);                              // 0x00465EE0
void __fastcall sub_0046E1B0_DrawOverlay(D2UnitStrc* pUnit, int nOverlay, int nX, int nY);                  // 0x0046E1B0
void __fastcall sub_0046F280(D2UnitStrc* pUnit, int nComponent);                               // 0x0046F280
void __fastcall sub_00470610_Refresh(D2UnitStrc* pUnit, int nArg);                                          // 0x00470610
void __fastcall sub_00480E70_SetState(D2UnitStrc* pUnit, int nArg);                                         // 0x00480E70
void __fastcall sub_004C0EC0_UpdateItemLink(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bForce, int bClamp); // 0x004C0EC0
int __cdecl D2GFX_GetResolutionMode();                                                                      // 0x004F5160
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem);                                                 // 0x0063E020
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0
void __stdcall sub_0063D2B0_DetachItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem);                     // 0x0063D2B0
D2UnitStrc* __stdcall INVENTORY_RemoveItemFromInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem);    // 0x0063AD90
void __stdcall sub_0063BE30(D2InventoryStrc* pInventory, int nBodyLoc);                                     // 0x0063BE30
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem);                                           // 0x00627D40
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __stdcall PATH_SetMoveTestCollisionMask(D2DynamicPathStrc* pDynamicPath, int nMask);                   // 0x00648CE0
void __stdcall sub_00649190_SetPathMode(D2UnitStrc* pUnit, int nMode);                                      // 0x00649190
int __stdcall sub_00650BE0_PlaceUnit(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00650BE0
unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath);                                        // 0x006487F0
void __stdcall sub_006488A0_SetDirection(D2DynamicPathStrc* pPath, int nDirection);                         // 0x006488A0
unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064CB30

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern unsigned short gwRequestId_0070CD60;                                                                 // 0x0070CD60
extern int gnGlobal_007111CC;                                                                               // 0x007111CC
extern int gnGlobal_007111D0;                                                                               // 0x007111D0
extern int gnGlobal_007111D4;                                                                               // 0x007111D4
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
D2CharSelCacheStrc* gpCharSelCache_00779DE8;                                                                // 0x00779DE8
extern D2LaunchCharInfoStrc* gpCharInfo_0077BBD8;                                                           // 0x0077BBD8
extern unsigned short gwSavedRequestId_0077BBDC;                                                            // 0x0077BBDC
extern int gnLaunchMode_0077BBE4;                                                                           // 0x0077BBE4
extern int gnValue_00798CCC;                                                                                // 0x00798CCC
extern void* gpGlobal_007A0634;                                                                             // 0x007A0634
D2RecordHandlerFn gpfnPrevHandler_007A2764;                                                                 // 0x007A2764
int gbOverlaysEnabled_007A289C;                                                                             // 0x007A289C
int gnOverlayStep_007A3138;                                                                                 // 0x007A3138
extern void* gpAutomapContext_007A5164;                                                                     // 0x007A5164
int gnGlobal_007B0A54;                                                                                      // 0x007B0A54
int gnGlobal_007B0A58;                                                                                      // 0x007B0A58
extern D2GridCellStrc gtGridCells_007B0E68[];                                                               // 0x007B0E68
extern int gnProgress_007BB3B4;                                                                             // 0x007BB3B4

// 0x00437AB0
void __fastcall sub_00437AB0_CharSelCacheStore(const char* szKey, const void* pData, unsigned int nSize)
{
    const unsigned int dwHash = SStrHash(szKey, 0, 0);
    for (D2CharSelCacheStrc* pEntry = gpCharSelCache_00779DE8; pEntry; pEntry = pEntry->pNext)
    {
        if (pEntry->dwHash == dwHash)
        {
            SMemFree(pEntry->pData, ".\\Src\\CharSel.cpp", 0xF1, 0);
            pEntry->pData = SMemAlloc(nSize, ".\\Src\\CharSel.cpp", 0xF2, 0);
            memcpy(pEntry->pData, pData, nSize);
            pEntry->dwExpireTick = GetTickCount() + 300000;
            return;
        }
    }
    D2CharSelCacheStrc* pEntry = (D2CharSelCacheStrc*)SMemAlloc(sizeof(D2CharSelCacheStrc), ".\\Src\\CharSel.cpp", 0xFA, 0);
    pEntry->dwHash = dwHash;
    pEntry->pData = SMemAlloc(nSize, ".\\Src\\CharSel.cpp", 0xFC, 0);
    memcpy(pEntry->pData, pData, nSize);
    pEntry->dwExpireTick = GetTickCount() + 300000;
    pEntry->pNext = gpCharSelCache_00779DE8;
    gpCharSelCache_00779DE8 = pEntry;
}

// 0x00445020
void __cdecl sub_00445020_SendLaunchRequest()
{
    gnLaunchMode_0077BBE4 = 3;
    gnValue_00798CCC = 0;
    if (gpCharInfo_0077BBD8->nType0x35E == 2)
    {
        D2LaunchRequestStrc tRequest;
        memset(&tRequest, 0, sizeof(tRequest));
        if (gpCharInfo_0077BBD8->wFlags[0] & 4)
            tRequest.dwFlags |= 0x800;
        while (++gwRequestId_0070CD60 == 0)
        {
        }
        sub_0044A590_SendRequest(&tRequest, gwRequestId_0070CD60);
        gwSavedRequestId_0077BBDC = gwRequestId_0070CD60;
    }
    else
    {
        sub_00444E70_SendFallbackRequest();
    }
}

// 0x00451920
void __stdcall sub_00451920_RecordHandler(int nArg1, int nArg2, int nArg3)
{
    sub_00451620_WriteRecordFile();
    if (gpfnPrevHandler_007A2764)
        gpfnPrevHandler_007A2764(nArg1, nArg2, nArg3);
}

// 0x00453470
void __cdecl sub_00453470_DrawProgressiveStates()
{
    if (!gpGlobal_007A0634)
        return;
    if (!sub_00463DE0_GetStoredUnit())
        return;
    if (!UNITS_GetRoom(sub_00463DE0_GetStoredUnit()))
        return;
    if (!gbOverlaysEnabled_007A289C)
        return;
    int nY = gnGlobal_00711470 - gnGlobal_007111D4;
    int nX = gnGlobal_0071146C - gnGlobal_007111D0;
    if (D2GFX_GetResolutionMode() == 2)
        nY = gnGlobal_00711470 - gnGlobal_007111CC;
    D2UnitStrc* pUnit = sub_00463DE0_GetStoredUnit();
    for (int i = 0; i < sgptDataTables->nProgressiveStates; ++i)
    {
        const int nState = sgptDataTables->pProgressiveStates[i];
        if (!STATES_CheckState(pUnit, nState))
            continue;
        if (!STATLIST_GetStatListFromUnitAndState(pUnit, nState))
            continue;
        D2StatesTxt* pStatesTxtRecord = DATATBLS_GetStatesTxtRecord(nState);
        if (!pStatesTxtRecord)
            continue;
        if (!(pStatesTxtRecord->nStateFlags[0] & gdwBitMasks[4]))
            continue;
        if (pStatesTxtRecord->wPrgOverlay <= 0 || pStatesTxtRecord->wPrgOverlay >= sgptDataTables->nOverlayTxtRecordCount)
            continue;
        if (pStatesTxtRecord->wStat < 0 || pStatesTxtRecord->wStat > sgptDataTables->nItemStatCostTxtRecordCount)
            continue;
        const int nCharges = STATLIST_UnitGetStatValue(pUnit, pStatesTxtRecord->wStat, 0);
        if (nCharges < 1 || nCharges > 3)
            continue;
        sub_0046E1B0_DrawOverlay(pUnit, pStatesTxtRecord->wPrgOverlay + nCharges - 1, nX, nY);
        nX -= gnOverlayStep_007A3138;
    }
}

// 0x00458CD0
void __stdcall sub_00458CD0_SetAutomapContext(void* pContext)
{
    sub_004584C0_ResetA();
    sub_00458680_ResetB();
    gpAutomapContext_007A5164 = pContext;
    sub_00458750_Rebuild();
}

// build: context sub_00462F60_UnitDropItems
void __fastcall sub_00462F60_UnitDropItems(D2UnitDropItemsPacketStrc* pPacket)
{
    if (!pPacket->bActive)
        return;
    D2UnitStrc* pUnit = sub_00463990(*(int*)pPacket->nUnitId, 0);
    if (!pUnit)
        return;
    if (!sub_00464820_IsDeadOrDying(pUnit))
        sub_00480E70_SetState(pUnit, 0);
    if (pUnit == sub_00463DD0())
    {
        D2UnitStrc* pOther = sub_00463990(*(int*)pPacket->nOtherUnitId, 0);
        if (!pOther)
            return;
        D2DynamicPathStrc* pPath = pOther->pDynamicPath;
        PATH_SetMoveTestCollisionMask(pPath, 0);
        sub_00649190_SetPathMode(pOther, 5);
        D2_ASSERT(sub_00650BE0_PlaceUnit(pPath, pOther, UNITS_GetRoom(pUnit), UNITS_GetXPosition(pUnit), CLIENTS_GetUnitY(pUnit)), 0xABA);
        sub_006488A0_SetDirection(pOther->pDynamicPath, PATH_GetDirection(pUnit->pDynamicPath));
    }
    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory);
    while (pItem)
    {
        D2UnitStrc* pNext = INVENTORY_GetNextItem(pItem);
        if (INVENTORY_GetItemNodePage(pItem) == 3)
        {
            pItem = INVENTORY_UnitIsItem(pItem);
            sub_0063D2B0_DetachItem(pInventory, pItem);
            sub_0046F280(pUnit, sub_00462EE0_GetItemComponent(pUnit, pItem));
            D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
            D2_ASSERT(pRemoved, 0xAC8);
            D2_ASSERT(pRemoved == pItem, 0xAC9);
            sub_004C0EC0_UpdateItemLink(pItem, pUnit, 0, 0);
            sub_0063BE30(pInventory, ITEMS_GetBodyLocation(pItem));
            sub_00470610_Refresh(pUnit, 0);
            const int nUnitType = !pItem ? 6 : pItem->dwUnitType;
            const int nUnitId = !pItem ? -1 : pItem->dwUnitId;
            sub_00465EE0_RemoveClientSideUnit(nUnitId, nUnitType);
        }
        pItem = pNext;
    }
}

// 0x004756D0
void __cdecl sub_004756D0_ScanGridCollision()
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (!pPlayer)
        return;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (!pRoom)
        return;
    for (int nY = 0; nY < 0x30; ++nY)
    {
        for (int nX = 0; nX < 0x30; ++nX)
        {
            pRoom = D2GAME_GetRoom_6FC52070(pRoom, gnGlobal_007B0A54 + nX, gnGlobal_007B0A58 + nY);
            if (!pRoom)
                pRoom = UNITS_GetRoom(pPlayer);
            if (COLLISION_CheckMask(pRoom, gnGlobal_007B0A54 + nX, gnGlobal_007B0A58 + nY, 0x22))
                gtGridCells_007B0E68[nY * 0x30 + nX].nFlag = 1;
        }
    }
}

// 0x00478160
void __fastcall sub_00478160_ShowProgressSteps(int nDone, int nTotal)
{
    const int nDivisor = nTotal * 8;
    int nPosition = nDone * 8;
    for (int i = 0; i < 8; ++i)
    {
        if (nDivisor == 0)
            gnProgress_007BB3B4 = 0;
        else
            gnProgress_007BB3B4 = (nPosition * 0x100) / nDivisor;
        sub_004565E0_Redraw(0);
        Sleep(250);
        ++nPosition;
    }
}

#include "gen/data/Source/D2Client/00437AB0_sub_00437AB0_CharSelCacheStore.inc"
