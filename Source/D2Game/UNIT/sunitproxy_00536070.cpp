#include "D2Game.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2NpcControlStrc;
struct D2SeedStrc { unsigned int nLowSeed; unsigned int nHighSeed; };
struct D2GameStrc
{
    char unknown00[0x1C];
    void* pMemoryPool;
    char unknown20[0xB0];
    D2SeedStrc pSeed;
    char unknownD8[0x1D24-0xD8];
    D2NpcControlStrc* pNpcControl;
};

#define MAX_NPC_INVENTORY 17

extern D2UnitProxyStrc gUnitProxyItemCache_00883D78[17];                                                    // 0x00883D78
extern "C" const char szSUnitProxyCppFile[];                                                                // 0x006E0A30
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0

// 0x00535FB0
static void SUNITPROXY_InitializeItemCache(D2GameStrc* pGame, D2UnitProxyStrc* pUnitProxy, int nNpcInventoryId)
{
    D2_ASSERT(nNpcInventoryId < MAX_NPC_INVENTORY, 164);
    pUnitProxy->nItems = gUnitProxyItemCache_00883D78[nNpcInventoryId].nItems;
    pUnitProxy->pItemCache = (D2ItemCacheStrc*)sub_0040B430(pGame->pMemoryPool, gUnitProxyItemCache_00883D78[nNpcInventoryId].nItems * sizeof(D2ItemCacheStrc), szSUnitProxyCppFile, 168, 0);
    memcpy(pUnitProxy->pItemCache, gUnitProxyItemCache_00883D78[nNpcInventoryId].pItemCache, gUnitProxyItemCache_00883D78[nNpcInventoryId].nItems * sizeof(D2ItemCacheStrc));
    pUnitProxy->nPerms = gUnitProxyItemCache_00883D78[nNpcInventoryId].nPerms;
    pUnitProxy->pPermCache = (unsigned int*)sub_0040B430(pGame->pMemoryPool, gUnitProxyItemCache_00883D78[nNpcInventoryId].nPerms * sizeof(unsigned int), szSUnitProxyCppFile, 171, 0);
    memcpy(pUnitProxy->pPermCache, gUnitProxyItemCache_00883D78[nNpcInventoryId].pPermCache, gUnitProxyItemCache_00883D78[nNpcInventoryId].nPerms * sizeof(unsigned int));
}

struct D2NpcRecordStrc
{
    int nNPC;
    void* pInventory;
    void* pGamble;
    int bGambleInit;
    void* pMercData;
    void* pEvent;
    void* pVendorChain;
    int bTrading;
    unsigned char bVendorInit;
    unsigned char unknown21;
    unsigned char nAct;
    unsigned char bTrader;
    unsigned char bRepair;
    unsigned char bVendor;
    unsigned char unknown26;
    unsigned char bRefreshInventory;
    unsigned int dwTicks;
    D2UnitProxyStrc tProxy;
    int unknown3C;
    int dwNPCGUID;
};
struct D2NpcControlStrc
{
    int nArraySize;
    D2NpcRecordStrc* pFirstRecord;
    D2SeedStrc pSeed;
    int nNpcCount;
};
struct D2MonStatsTxt
{
    unsigned char unknown00[0x0D];
    unsigned char nFlags1;
    unsigned char unknown0E[0x1A8-0x0E];
};
struct D2DataTablesStrc
{
    char unknown00[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    int unknownA7C;
    int nMonStatsTxtRecordCount;
};
struct D2NpcConfigStrc
{
    int nClassId;
    unsigned char bTrader;
    unsigned char nAct;
    unsigned char unknown06;
    unsigned char unknown07;
};
struct D2NpcConfigTableStrc
{
    int nCount;
    D2NpcConfigStrc entries[64];
};
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern D2NpcConfigTableStrc gNpcConfig; // 0x00731184
extern int gnItemCode_00883E9C; // 0x00883E9C
extern int gnItemCode_00883EA0; // 0x00883EA0
extern "C" void* __cdecl memset(void*,int,unsigned int); // 0x00681EF0
void __fastcall SEED_InitSeed(D2SeedStrc*); // 0x00650E30
void __fastcall SEED_InitLowSeed(D2SeedStrc*,unsigned int); // 0x00650E40
void* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int,int*); // 0x00633640
void* __stdcall INVENTORY_AllocInventory(void*,void*); // 0x0063ABD0

// build: context SUNITPROXY_GetMonStatsTxtRecordInline
static D2MonStatsTxt* SUNITPROXY_GetMonStatsTxtRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    return 0;
}
// build: context RollSeed
static __forceinline unsigned int RollSeed(D2SeedStrc* pSeed)
{
    unsigned __int64 nSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nHighSeed = (unsigned int)(nSeed >> 32);
    pSeed->nLowSeed = (unsigned int)nSeed;
    return (unsigned int)nSeed;
}

// 0x00536070
void __fastcall sub_00536070_InitNpcControl(D2GameStrc* pGame)
{
    D2NpcRecordStrc* pRecords = (D2NpcRecordStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2NpcRecordStrc)*64, szSUnitProxyCppFile, 0xB7, 0);
    memset(pRecords, 0, sizeof(D2NpcRecordStrc)*64);
    D2NpcControlStrc* pControl = (D2NpcControlStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2NpcControlStrc), szSUnitProxyCppFile, 0xB9, 0);
    pControl->pFirstRecord = 0;
    pControl->nArraySize = 0;
    pControl->nNpcCount = 0;
    SEED_InitSeed(&pControl->pSeed);
    SEED_InitLowSeed(&pControl->pSeed, RollSeed(&pGame->pSeed));
    if (!gnItemCode_00883E9C) DATATBLS_GetItemRecordFromItemCode(0x20767163, &gnItemCode_00883E9C);
    if (!gnItemCode_00883EA0) DATATBLS_GetItemRecordFromItemCode(0x20767161, &gnItemCode_00883EA0);
    DATATBLS_GetItemDataTables();
    int nCount = 0;
    const int nTotal = sgptDataTables->nMonStatsTxtRecordCount;
    for (int nClass = 0; nClass < nTotal; ++nClass)
    {
        D2MonStatsTxt* pTxt = SUNITPROXY_GetMonStatsTxtRecordInline(nClass);
        int bInteract = 0;
        if (pTxt)
            bInteract = pTxt->nFlags1 & gdwBitMasks[1];
        if (!bInteract) continue;
        D2NpcRecordStrc* pNpc = &pRecords[nCount];
        pNpc->nNPC = nClass;
        pNpc->bTrading = 0;
        ++pControl->nNpcCount;
        pNpc->pEvent = 0;
        pNpc->bVendorInit = 0;
        pNpc->unknown21 = 0;
        pNpc->dwTicks = 0;
        pNpc->bTrader = 0;
        pNpc->pInventory = INVENTORY_AllocInventory(pGame->pMemoryPool, 0);
        pNpc->pVendorChain = 0;
        pNpc->pGamble = 0;
        pNpc->bGambleInit = 0;
        D2_ASSERT(nCount < 64, 0xE6);
        const int nConfigCount = gNpcConfig.nCount;
        ++pControl->nArraySize;
        int nConfig = 0;
        int bFound = 0;
        while (nConfig < nConfigCount && !bFound)
        {
            if (gNpcConfig.entries[nConfig].nClassId == nClass) bFound = 1;
            else ++nConfig;
        }
        if (bFound == 1)
        {
            pNpc->nAct = gNpcConfig.entries[nConfig].nAct;
            pNpc->bTrader = gNpcConfig.entries[nConfig].bTrader;
            pNpc->bRepair = 0;
            pNpc->bVendor = 0;
            pNpc->unknown26 = gNpcConfig.entries[nConfig].unknown06;
            pNpc->bRefreshInventory = 0;
            if (pNpc->bTrader == 1)
            {
                int nCacheIndex;
                switch (pNpc->nNPC)
                {
                case 257:
                    SUNITPROXY_InitializeItemCache(pGame, &pNpc->tProxy, 12);
                    pNpc->bRepair = 1;
                    pNpc->bVendor = 1;
                    break;
                case 254:
                    SUNITPROXY_InitializeItemCache(pGame, &pNpc->tProxy, 7);
                    pNpc->bGambleInit = 1;
                    break;
                case 154:
                    SUNITPROXY_InitializeItemCache(pGame, &pNpc->tProxy, 2);
                    pNpc->bRepair = 1;
                    pNpc->bVendor = 1;
                    break;
                case 178:
                    SUNITPROXY_InitializeItemCache(pGame, &pNpc->tProxy, 3);
                    pNpc->bRepair = 1;
                    pNpc->bVendor = 1;
                    break;
                case 252:
                    SUNITPROXY_InitializeItemCache(pGame, &pNpc->tProxy, 10);
                    pNpc->bRepair = 1;
                    pNpc->bVendor = 1;
                    break;
                case 253:
                    SUNITPROXY_InitializeItemCache(pGame, &pNpc->tProxy, 6);
                    pNpc->bRepair = 1;
                    pNpc->bVendor = 1;
                    break;
                case 148: SUNITPROXY_InitializeItemCache(pGame, &pNpc->tProxy, 0); break;
                case 177: SUNITPROXY_InitializeItemCache(pGame, &pNpc->tProxy, 5); break;
                case 202: SUNITPROXY_InitializeItemCache(pGame, &pNpc->tProxy, 4); break;
                case 255: SUNITPROXY_InitializeItemCache(pGame, &pNpc->tProxy, 8); break;
                case 147:
                    nCacheIndex = 1;
                    goto initialize_shared;
                case 199:
                    SUNITPROXY_InitializeItemCache(pGame, &pNpc->tProxy, 9);
                    pNpc->bGambleInit = 1;
                    break;
                case 405:
                    nCacheIndex = 13;
initialize_shared:
                    SUNITPROXY_InitializeItemCache(pGame, &pNpc->tProxy, nCacheIndex);
                    pNpc->bRepair = 1;
                    pNpc->bVendor = 1;
                    pNpc->bGambleInit = 1;
                    break;
                case 511:
                    SUNITPROXY_InitializeItemCache(pGame, &pNpc->tProxy, 15);
                    pNpc->bRepair = 1;
                    pNpc->bVendor = 1;
                    break;
                case 514:
                    SUNITPROXY_InitializeItemCache(pGame, &pNpc->tProxy, 15);
                    pNpc->bGambleInit = 1;
                    break;
                case 512:
                    SUNITPROXY_InitializeItemCache(pGame, &pNpc->tProxy, 16);
                    pNpc->bRepair = 1;
                    pNpc->bVendor = 1;
                    pNpc->bGambleInit = 1;
                    break;
                case 513: SUNITPROXY_InitializeItemCache(pGame, &pNpc->tProxy, 14); break;
                }
            }
            else
            {
                pNpc->tProxy.pItemCache = 0;
                pNpc->tProxy.pPermCache = 0;
            }
        }
        ++nCount;
    }
    pControl->pFirstRecord = pRecords;
    pGame->pNpcControl = pControl;
}

#include "gen/data/Source/D2Game/UNIT/sunitproxy_00536070.inc"
