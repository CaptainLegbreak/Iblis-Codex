#include "D2Game.h"
#include "D2Structs.h"

#define UNIT_MONSTER 1
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define NPCREC_FIELD(type, cursor, offset) (*(type*)((cursor) + (offset) - 0x2C))
struct D2NpcGambleStrc;
struct D2NpcVendorChainStrc;
struct D2NpcEventStrc;
struct D2NpcRecordStrc;
struct D2NpcControlStrc;

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x1D04];
    struct D2NpcControlStrc* pNpcControl;
};


struct D2NpcGambleStrc
{
    D2InventoryStrc* pInventory;
    int dwGUID;
    D2NpcGambleStrc* pNext;
};

struct D2NpcVendorChainStrc
{
    int dwGUID;
    int unk0x04;
    D2NpcVendorChainStrc* pNext;
};

struct D2NpcEventStrc
{
    D2UnitStrc* pUnit;
    int field_4;
    int field_8;
    int field_C;
    D2NpcEventStrc* pNext;
};

struct D2NpcRecordStrc
{
    int nNPC;
    D2InventoryStrc* pInventory;
    D2NpcGambleStrc* pGamble;
    int bGambleInit;
    void* pMercData;
    D2NpcEventStrc* pEvent;
    D2NpcVendorChainStrc* pVendorChain;
    int bTrading;
    unsigned char bVendorInit;
    unsigned char unk0x21;
    unsigned char nAct;
    unsigned char bTrader;
    char unk0x24[3];
    unsigned char bRefreshInventory;
    unsigned int dwTicks;
    void* pItemCache;
    int nPerms;
    void* pPermCache;
    char unk0x38[8];
    int dwNPCGUID;
};

struct D2NpcControlStrc
{
    int nArraySize;
    D2NpcRecordStrc* pFirstRecord;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void* pMemPool, D2UnitStrc* pOwner); // 0x0063ABD0
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00557FD0
D2NpcRecordStrc* __fastcall SUNITPROXY_GetNpcRecordFromClassId(D2GameStrc* pGame, int nNpcClassId, int* pIndex); // 0x00535EA0
D2MonsterInteractStrc* __fastcall sub_00535E80_GetMonInteract(D2UnitStrc* pUnit); // 0x00535E80
extern "C" const char szSUnitProxyCppFile_006E0A30[]; // 0x006E0A30

static D2NpcRecordStrc* D10_GetNpcRecordFromUnit(D2GameStrc* pGame, D2UnitStrc* pNpc)
{
    int nIndex;
    return SUNITPROXY_GetNpcRecordFromClassId(pGame, !pNpc ? -1 : pNpc->dwClassId, &nIndex);
}

// 0x00536510
static void __stdcall sub_00536510_RemoveInventoryItems(D2GameStrc* pGame, D2InventoryStrc* pInventory)
{
    if (!pInventory)
    {
        return;
    }

    D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory);
    while (pItem)
    {
        D2UnitStrc* pUnit = INVENTORY_UnitIsItem(pItem);
        D2UnitStrc* pNext = INVENTORY_GetNextItem(pItem);
        D2_ASSERT(pUnit, 0x1C6);
        INVENTORY_GetItemNodePage(pItem);
        SUNIT_RemoveUnit(pGame, pUnit);
        pItem = pNext;
    }
}

// 0x00536580
static void __stdcall SUNITPROXY_ClearNpcRecordData(D2NpcRecordStrc* pNpcRecord, D2GameStrc* pGame)
{
    if (pNpcRecord->bGambleInit)
    {
        D2NpcGambleStrc* pGamble = pNpcRecord->pGamble;
        while (pGamble)
        {
            D2NpcGambleStrc* pNextGamble = pGamble->pNext;
            if (pGamble->pInventory)
            {
                sub_00536510_RemoveInventoryItems(pGame, pGamble->pInventory);
                INVENTORY_FreeInventory(pGamble->pInventory);
                pGamble->pInventory = 0;
            }
            sub_0040B480(pGame->pMemoryPool, pGamble, ".\\UNIT\\sunitproxy.cpp", 0x1E6, 0);
            pGamble = pNextGamble;
        }
        pNpcRecord->pGamble = 0;
    }

    sub_00536510_RemoveInventoryItems(pGame, pNpcRecord->pInventory);
    INVENTORY_FreeInventory(pNpcRecord->pInventory);
    pNpcRecord->pInventory = 0;

    D2NpcEventStrc* pNpcEvent = pNpcRecord->pEvent;
    while (pNpcEvent)
    {
        D2NpcEventStrc* pNextEvent = pNpcEvent->pNext;
        if (pNpcEvent->field_C == 1 && pNpcEvent->pUnit)
        {
            ITEMS_RemoveFromAllPlayers(pGame, pNpcEvent->pUnit);
        }
        sub_0040B480(pGame->pMemoryPool, pNpcEvent, ".\\UNIT\\sunitproxy.cpp", 0x204, 0);
        pNpcEvent = pNextEvent;
    }
    pNpcRecord->pEvent = 0;
}

// 0x00536640
void __fastcall SUNITPROXY_FreeNpcControl(D2GameStrc* pGame)
{
    D2NpcControlStrc* pNpcControl = pGame->pNpcControl;
    D2NpcRecordStrc* pFirst = pNpcControl->pFirstRecord;
    for (int i = 0; i < pNpcControl->nArraySize; ++i)
    {
        char* pCursor = (char*)&pFirst[i] + 0x2C;
        D2NpcVendorChainStrc* pVendorChain = NPCREC_FIELD(D2NpcVendorChainStrc*, pCursor, 0x18);
        if (pVendorChain)
        {
            do
            {
                D2NpcVendorChainStrc* pNext = pVendorChain->pNext;
                sub_0040B480(pGame->pMemoryPool, pVendorChain, ".\\UNIT\\sunitproxy.cpp", 0x21E, 0);
                pVendorChain = pNext;
            }
            while (pVendorChain);
            NPCREC_FIELD(D2NpcVendorChainStrc*, pCursor, 0x18) = 0;
        }

        SUNITPROXY_ClearNpcRecordData((D2NpcRecordStrc*)(pCursor - 0x2C), pGame);

        if (NPCREC_FIELD(void*, pCursor, 0x2C))
        {
            sub_0040B480(pGame->pMemoryPool, NPCREC_FIELD(void*, pCursor, 0x2C), ".\\UNIT\\sunitproxy.cpp", 0x227, 0);
            NPCREC_FIELD(void*, pCursor, 0x2C) = 0;
        }

        if (NPCREC_FIELD(void*, pCursor, 0x34))
        {
            sub_0040B480(pGame->pMemoryPool, NPCREC_FIELD(void*, pCursor, 0x34), ".\\UNIT\\sunitproxy.cpp", 0x22C, 0);
            NPCREC_FIELD(void*, pCursor, 0x34) = 0;
        }

        if (NPCREC_FIELD(void*, pCursor, 0x10))
        {
            sub_0040B480(pGame->pMemoryPool, NPCREC_FIELD(void*, pCursor, 0x10), ".\\UNIT\\sunitproxy.cpp", 0x237, 0);
            NPCREC_FIELD(void*, pCursor, 0x10) = 0;
        }

        NPCREC_FIELD(void*, pCursor, 0x14) = 0;
    }

    sub_0040B480(pGame->pMemoryPool, pNpcControl->pFirstRecord, ".\\UNIT\\sunitproxy.cpp", 0x242, 0);
    sub_0040B480(pGame->pMemoryPool, pNpcControl, ".\\UNIT\\sunitproxy.cpp", 0x243, 0);
    pGame->pNpcControl = 0;
}

// 0x00536D10
void __fastcall SUNITPROXY_AllocNpcInventory(D2GameStrc* pGame, D2NpcRecordStrc* pNpcRecord, D2UnitStrc* pNpc)
{
    SUNITPROXY_ClearNpcRecordData(pNpcRecord, pGame);

    pNpcRecord->bVendorInit = 0;
    pNpcRecord->dwTicks = 0;
    pNpcRecord->pInventory = INVENTORY_AllocInventory(pGame->pMemoryPool, 0);

    if (pNpc)
    {
        pNpc->pInventory = pNpcRecord->pInventory;
    }
}

// 0x00537190
void __fastcall SUNITPROXY_FreeNpcGamble(D2GameStrc* pGame, D2UnitStrc* pNpc, D2UnitStrc* pPlayer)
{
    int nIndex;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromClassId(pGame, !pNpc ? -1 : pNpc->dwClassId, &nIndex);
    const int nPlayerGUID = !pPlayer ? -1 : pPlayer->dwUnitId;

    if (pNpcRecord && pNpcRecord->bGambleInit)
    {
        D2NpcGambleStrc* pPreviousGamble = 0;
        for (D2NpcGambleStrc* pGamble = pNpcRecord->pGamble; pGamble; pGamble = pGamble->pNext)
        {
            if (pGamble->dwGUID == nPlayerGUID)
            {
                if (pPreviousGamble)
                {
                    pPreviousGamble->pNext = pGamble->pNext;
                }
                else
                {
                    pNpcRecord->pGamble = pGamble->pNext;
                }

                if (pGamble->pInventory)
                {
                    sub_00536510_RemoveInventoryItems(pGame, pGamble->pInventory);
                    INVENTORY_FreeInventory(pGamble->pInventory);
                    pGamble->pInventory = 0;
                }

                sub_0040B480(pGame->pMemoryPool, pGamble, ".\\UNIT\\sunitproxy.cpp", 0x5D0, 0);
                return;
            }

            pPreviousGamble = pGamble;
        }
    }
}

// build: context SUNITPROXY_UpdateVendorInventory
void __stdcall SUNITPROXY_UpdateVendorInventory(D2GameStrc* pGame, unsigned char nAct, int bNoMorePlayersInLevel)
{
    D2NpcControlStrc* pNpcControl = pGame->pNpcControl;
    D2NpcRecordStrc* pRecords = pNpcControl->pFirstRecord;
    const unsigned int nTickCount = GetTickCount();
    for (int i = 0; i < pNpcControl->nArraySize; ++i)
    {
        D2NpcRecordStrc* pNpcRecord = &pRecords[i];
        if (&pNpcRecord->bVendorInit && pNpcRecord->nAct == nAct && pNpcRecord->bTrader == 1 && pNpcRecord->bTrading == 1 && pNpcRecord->bVendorInit == 1)
        {
            if (bNoMorePlayersInLevel)
            {
                D2UnitStrc* pNpc = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, pNpcRecord->dwNPCGUID);
                if (pNpc && pNpc->dwClassId == pNpcRecord->nNPC)
                {
                    if (!MONSTERAI_GetInteractUnitCount(sub_00535E80_GetMonInteract(pNpc)))
                    {
                        SUNITPROXY_AllocNpcInventory(pGame, pNpcRecord, pNpc);
                    }
                    else
                    {
                        pNpcRecord->bRefreshInventory = 1;
                    }
                }
                else
                {
                    SUNITPROXY_AllocNpcInventory(pGame, pNpcRecord, 0);
                }
            }
            else
            {
                if (nTickCount > pNpcRecord->dwTicks + 240000)
                {
                    pNpcRecord->bRefreshInventory = 1;
                    pNpcRecord->dwTicks = nTickCount;
                }
            }
        }
    }
}

// 0x00535EA0
D2NpcRecordStrc* __fastcall SUNITPROXY_GetNpcRecordFromClassId(D2GameStrc* pGame, int nNpcClassId, int* pIndex)
{
    D2NpcRecordStrc* pRecords = pGame->pNpcControl->pFirstRecord;
    for (*pIndex = 0; *pIndex < MAX_NPC_RECORDS; ++*pIndex)
    {
        if (pRecords[*pIndex].nNPC == nNpcClassId)
        {
            return &pRecords[*pIndex];
        }
    }

    D2_ASSERT(nNpcClassId, 114);
    return 0;
}

// 0x00536B50
void __fastcall SUNITPROXY_FreeVendorChain(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc)
{
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromClassId(pGame, !pNpc ? -1 : pNpc->dwClassId, (int*)&pNpc);
    if (!pNpcRecord)
    {
        return;
    }

    int& nPlayerGUID = *(int*)&pNpc;
    const int nGUID = !pPlayer ? -1 : pPlayer->dwUnitId;
    nPlayerGUID = nGUID;
    if (pNpcRecord->bGambleInit)
    {
        D2NpcGambleStrc* pPreviousGamble = 0;
        for (D2NpcGambleStrc* pGamble = pNpcRecord->pGamble; pGamble; pGamble = pGamble->pNext)
        {
            if (pGamble->dwGUID == nPlayerGUID)
            {
                if (pPreviousGamble)
                {
                    pPreviousGamble->pNext = pGamble->pNext;
                }
                else
                {
                    pNpcRecord->pGamble = pGamble->pNext;
                }

                if (pGamble->pInventory)
                {
                    sub_00536510_RemoveInventoryItems(pGame, pGamble->pInventory);
                    INVENTORY_FreeInventory(pGamble->pInventory);
                    pGamble->pInventory = 0;
                }

                sub_0040B480(pGame->pMemoryPool, pGamble, szSUnitProxyCppFile_006E0A30, 0x48F, 0);
                break;
            }

            pPreviousGamble = pGamble;
        }
    }

    D2NpcVendorChainStrc* pVendorChain = pNpcRecord->pVendorChain;
    if (!pVendorChain)
    {
        return;
    }

    D2NpcVendorChainStrc* pPreviousVendorChain = 0;
    for (; pVendorChain; pVendorChain = pVendorChain->pNext)
    {
        if (pVendorChain->dwGUID == nPlayerGUID)
        {
            if (pPreviousVendorChain)
            {
                pPreviousVendorChain->pNext = pVendorChain->pNext;
            }
            else
            {
                pNpcRecord->pVendorChain = pVendorChain->pNext;
            }

            sub_0040B480(pGame->pMemoryPool, pVendorChain, szSUnitProxyCppFile_006E0A30, 0x4A7, 0);
            return;
        }

        pPreviousVendorChain = pVendorChain;
    }
}
