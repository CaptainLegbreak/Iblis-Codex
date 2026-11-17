typedef unsigned long DWORD;

struct D2InventoryStrc;
struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08[22];
    D2InventoryStrc* pInventory;
    int unk0x64[25];
    unsigned int dwFlagEx;
    int unk0xCC[7];
    D2UnitStrc* pRoomNext;
};

struct D2ActiveRoomStrc
{
    int unk0x00[29];
    D2UnitStrc* pUnitFirst;
};

struct D2GfxLayerHeaderStrc
{
    unsigned char nCount;
    unsigned char unk0x01;
    unsigned char nArg;
};

struct D2GfxLayerStrc;
struct D2GfxNodeTargetStrc
{
    int unk0x00[5];
    D2GfxLayerStrc* pLayer;
};

struct D2GfxListNodeStrc
{
    int nMode;
    int nId;
    D2GfxNodeTargetStrc* pTarget;
    int unk0x0C;
    D2GfxListNodeStrc* pNext;
};

struct D2GfxDataStrc
{
    int unk0x00[10];
    D2GfxListNodeStrc* pList;
};

struct D2CelContextStrc
{
    int unk0x00[13];
    int nArg34;
    int unk0x38[3];
    int nFlags44;
};

struct D2MonGfxCacheStrc
{
    int f_0[20];
    int aPending[20];
};

struct D2MonStatsTxt
{
    char unk0x000[0x18];
    short wMonStatsEx;
    char unk0x01A[0x18E];
};

struct D2MonStats2Txt
{
    char unk0x000[0xF0];
    unsigned char aModeFlags[0x44];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[4];
    int nMonStatsTxtRecordCount;
    char unk0xA84[0xC];
    D2MonStats2Txt* pMonStats2Txt;
    char unk0xA94[4];
    int nMonStats2TxtRecordCount;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                   // 0x006823FD
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" const char gszAsyncLoadFailed_006D6CC8[];                                                        // 0x006D6CC8
int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask);                               // 0x0063A7B0
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                       // 0x004639D0
int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int* pWeaponClassId, int nAnimMode, int a5); // 0x0064F380
void* __fastcall sub_0046E5A0_FindGfxNode(D2UnitStrc* pUnit, int nWeaponClassId, int nArg);                // 0x0046E5A0
void* __fastcall sub_0046FA80_LoadGfxNode(D2UnitStrc* pUnit, int nWeaponClassId, int nArg);                // 0x0046FA80
D2GfxDataStrc* __fastcall sub_00463E10_GetGfxData(D2UnitStrc* pUnit);                                      // 0x00463E10
D2GfxLayerHeaderStrc* __fastcall sub_004DB040_GetLayerHeader(void* pGfx);                                  // 0x004DB040
unsigned char __stdcall UNITS_GetDirection(D2UnitStrc* pUnit);                                              // 0x00620100
int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit);                                                    // 0x00621190
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270
void __fastcall sub_004DB2E0_GetLayerInfo(D2UnitStrc* pUnit, int nType, int nClass, int nMode, int* pDirection, int* pA, int* pB, int nArg, int nFlag); // 0x004DB2E0
unsigned char* __fastcall sub_004DB110_GetLayerOrder(void* pGfx, int nA, int nFrame);                       // 0x004DB110
int __fastcall sub_004DBB50_GetItemCelContext(D2CelContextStrc* pContext, D2UnitStrc* pItem, int nArg3, int nArg4, int nArg5, int* pOut, unsigned char nArg7, int nArg8); // 0x004DBB50
int __stdcall sub_006001F0(D2CelContextStrc* pContext, int nArg2, int nArg3);                // 0x006001F0
int __stdcall sub_006004E0_LoadSprite(D2CelContextStrc* pContext);                                          // 0x006004E0
int __stdcall sub_005FF300_IsEntryPending(int nKeyA, int nKeyB, int nKeyC);                                 // 0x005FF300
int __fastcall sub_0046DAC0_GetItemClassId(D2UnitStrc* pUnit);                                              // 0x0046DAC0
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pnNumRooms); // 0x00619790
void __fastcall sub_004565E0_Redraw(int nArg);                                                              // 0x004565E0
unsigned int __cdecl sub_005FF2A0_CountPending();                                                           // 0x005FF2A0
int __stdcall WINDOW_GetState();                                                                            // 0x004F6070
int __cdecl sub_00454840_Test();                                                                            // 0x00454840

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern D2MonGfxCacheStrc* gpPoolBlock_007A80FC;                                                             // 0x007A80FC
D2MonGfxCacheStrc gaPlayerGfxCache_007A7490[7];                                                             // 0x007A7490
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern int gaPlayerModes_00712AA0[];                                                                        // 0x00712AA0
extern unsigned int gnPlayerModeCount_00712AC0;                                                             // 0x00712AC0
extern int gaCofModes_00712AC4[];                                                                           // 0x00712AC4
extern int gnCofModeCount_00712B00;                                                                         // 0x00712B00
extern int gbPreloadForce_007A8920;                                                                         // 0x007A8920
extern int gdwGlobal_007A8928;                                                                              // 0x007A8928
extern int gdwGlobal_007A8910;                                                                              // 0x007A8910

inline int IsShapeShifted(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit)
        bResult = (pUnit->dwFlagEx >> 3) & 1;
    return bResult;
}

static __forceinline D2GfxLayerStrc* GetNodeLayer(D2UnitStrc* pUnit, int nMode)
{
    D2GfxDataStrc* pGfxData = sub_00463E10_GetGfxData(pUnit);
    if (pGfxData)
    {
        for (D2GfxListNodeStrc* pNode = pGfxData->pList; pNode; pNode = pNode->pNext)
        {
            if (pNode->nMode == nMode)
            {
                return pNode->pTarget->pLayer;
            }
        }
    }
    return 0;
}

static int __stdcall sub_0046FB60_LoadUnitLayers(int bAsync, int nMode, D2UnitStrc* pUnit)
{
    int nResult = 1;
    D2InventoryStrc* pInventory;
    D2UnitStrc* pOwner;
    if (IsShapeShifted(pUnit) && STATES_CheckStateMaskOnUnit(pUnit, 0x25) && (pOwner = sub_004639D0_GetOwnerUnit(pUnit)) != 0)
    {
        pInventory = pOwner->pInventory;
    }
    else
    {
        pInventory = pUnit->pInventory;
    }
    int nWeaponClass;
    const int nToken = COMPOSIT_GetWeaponClassId(pUnit, pInventory, &nWeaponClass, nMode, 0);
    if (!sub_0046E5A0_FindGfxNode(pUnit, nToken, nMode) && !sub_0046FA80_LoadGfxNode(pUnit, nToken, nMode))
    {
        char szBuffer[256];
        const int nClassArg = pUnit ? pUnit->dwClassId : -1;
        const int nTypeArg = pUnit ? pUnit->dwUnitType : 6;
        sprintf(szBuffer, gszAsyncLoadFailed_006D6CC8, bAsync, nTypeArg, nClassArg, nMode, nWeaponClass, nToken);
        return 0;
    }

    D2GfxLayerStrc* pLayer = GetNodeLayer(pUnit, nMode);
    if (!pLayer)
    {
        return 0;
    }

    D2GfxLayerHeaderStrc* pHeader = sub_004DB040_GetLayerHeader(pLayer);
    D2_ASSERT(pHeader, 0x6C3);
    struct
    {
        int nA;
        int nIndex;
    } tArg;
    tArg.nIndex = pHeader->nArg;
    tArg.nA = 0;
    int nDirection = UNITS_GetDirection(pUnit);
    int nType = pUnit->dwUnitType;
    int nClass = pUnit->dwClassId;
    int nAnimMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nAnimMode, ".\\ENGINE\\Gfx.cpp", 0x6CD);
    int nB;
    sub_004DB2E0_GetLayerInfo(pUnit, nType, nClass, nMode, &nDirection, &tArg.nA, &nB, tArg.nIndex, 0);
    unsigned char* pOrder = sub_004DB110_GetLayerOrder(pLayer, tArg.nA, 0);
    D2_ASSERT(pOrder, 0x6D6);
    tArg.nIndex = 0;
    while (tArg.nIndex < pHeader->nCount)
    {
        const int nLayer = pOrder[tArg.nIndex];
        D2_ASSERT(nLayer < 0x10, 0x6DD);
        D2CelContextStrc tContext;
        memset(&tContext, 0, sizeof(tContext));
        int nItemId;
        if (sub_004DBB50_GetItemCelContext(&tContext, pUnit, 0, UNITS_GetDirection(pUnit), 0, &nItemId, nLayer, nMode))
        {
            if (!sub_006001F0(&tContext, bAsync, bAsync))
            {
                tContext.nArg34 = 0;
                if (!sub_006004E0_LoadSprite(&tContext))
                {
                    return -1;
                }
                if (!(tContext.nFlags44 & 4))
                {
                    nResult = 0;
                }
            }
        }
        ++tArg.nIndex;
    }
    return nResult;
}

// build: context sub_0046FDA0_PreloadMonsterMode
static void __stdcall sub_0046FDA0_PreloadMonsterMode(int bAsync, D2UnitStrc* pUnit, int nMode)
{
    int nAnimMode;
    int nType;
    int nClass;

    int nTypeValue = 6;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }

    nType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClass = nClassValue;
    nAnimMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nAnimMode, ".\\ENGINE\\Gfx.cpp", 0x70A);
    if (nClass >= sgptDataTables->nMonStatsTxtRecordCount || gpPoolBlock_007A80FC[nClass].f_0[nMode])
    {
        return;
    }
    if (!gpPoolBlock_007A80FC[nClass].aPending[nMode])
    {
        if (sub_0046FB60_LoadUnitLayers(bAsync, nMode, pUnit) != 1)
        {
            gpPoolBlock_007A80FC[nClass].aPending[nMode] = 0;
            gpPoolBlock_007A80FC[nClass].f_0[nMode] = 0;
        }
        else
        {
            gpPoolBlock_007A80FC[nClass].aPending[nMode] = 1;
        }
    }
    else if (!sub_005FF300_IsEntryPending(nType, nMode, nClass))
    {
        gpPoolBlock_007A80FC[nClass].f_0[nMode] = 1;
    }
}

// 0x0046FEB0
static void __stdcall sub_0046FEB0_PreloadMonsterModes(int bAsync, D2UnitStrc* pUnit)
{
    const int nId = sub_0046DAC0_GetItemClassId(pUnit);
    if (nId < 0 || nId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return;
    }
    const int nIndex = sgptDataTables->pMonStatsTxt[nId].wMonStatsEx;
    if (nIndex < 0 || nIndex >= sgptDataTables->nMonStats2TxtRecordCount)
    {
        return;
    }
    D2MonStats2Txt* pMonStats2 = &sgptDataTables->pMonStats2Txt[nIndex];
    if (!pMonStats2)
    {
        return;
    }
    for (unsigned int i = 0; i < gnCofModeCount_00712B00; ++i)
    {
        const unsigned int nMode = gaCofModes_00712AC4[i];
        if (pMonStats2->aModeFlags[nMode >> 3] & gdwBitMasks[nMode & 7])
        {
            sub_0046FDA0_PreloadMonsterMode(bAsync, pUnit, nMode);
        }
    }
}

// 0x0046FF50
static void __stdcall sub_0046FF50_PreloadPlayerMode(int bAsync, D2UnitStrc* pUnit, int nMode)
{
    int nAnimMode;
    int nType;
    int nClass;

    int nTypeValue = 6;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }

    nType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClass = nClassValue;
    nAnimMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nAnimMode, ".\\ENGINE\\Gfx.cpp", 0x751);
    if (gaPlayerGfxCache_007A7490[nClass].f_0[nMode])
    {
        return;
    }
    if (!gaPlayerGfxCache_007A7490[nClass].aPending[nMode])
    {
        if (sub_0046FB60_LoadUnitLayers(bAsync, nMode, pUnit) != 1)
        {
            gaPlayerGfxCache_007A7490[nClass].aPending[nMode] = 0;
            gaPlayerGfxCache_007A7490[nClass].f_0[nMode] = 0;
        }
        else
        {
            gaPlayerGfxCache_007A7490[nClass].aPending[nMode] = 1;
        }
    }
    else if (!sub_005FF300_IsEntryPending(nType, nMode, nClass))
    {
        gaPlayerGfxCache_007A7490[nClass].f_0[nMode] = 1;
    }
}

int __stdcall sub_M389_Emit_0046FEB0(int bAsync, D2UnitStrc* pUnit)
{
    sub_0046FEB0_PreloadMonsterModes(bAsync, pUnit);
    return 0x3B;
}

void sub_M389_Emit_0046FF50(int bAsync, D2UnitStrc* pUnit)
{
    for (unsigned int i = 0; i < gnPlayerModeCount_00712AC0; ++i)
    {
        sub_0046FF50_PreloadPlayerMode(bAsync, pUnit, gaPlayerModes_00712AA0[i] + 0x13);
    }
}

#include "gen/data/Source/D2Client/0046FEB0_sub_0046FEB0_PreloadMonsterModes.inc"
