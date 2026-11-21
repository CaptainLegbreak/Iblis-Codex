#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Drlg.h"
#include "D2ClientTypes.h"
#include "D2ClientGfx.h"
#include "D2CelContext.h"
#include "D2Txt.h"
struct D2UnitStrc;

typedef unsigned long DWORD;

struct D2GfxLayerStrc;




extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                   // 0x006823FD
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask);                               // 0x0063A7B0
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                       // 0x004639D0
int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int* pWeaponClassId, int nAnimMode, int a5); // 0x0064F380
D2GfxListNodeStrc* __fastcall sub_0046E5A0_FindGfxListNode(D2UnitStrc* pUnit, int nId, int nMode); // 0x0046E5A0
void* __fastcall sub_0046FA80_LoadGfxNode(D2UnitStrc* pUnit, int nWeaponClassId, int nArg);                // 0x0046FA80
D2GfxDataStrc* __fastcall sub_00463E10_GetGfxData(D2UnitStrc* pUnit);                                      // 0x00463E10
D2GfxLayerHeaderStrc* __fastcall sub_004DB040_GetLayerHeader(void* pGfx);                                  // 0x004DB040
int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit);                                                    // 0x00621190
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270
void __fastcall sub_004DB2E0_GetLayerInfo(D2UnitStrc* pUnit, int nType, int nClass, int nMode, int* pDirection, int* pA, int* pB, int nArg, int nFlag); // 0x004DB2E0
int __fastcall sub_004DBB50_GetItemCelContext(D2CelContextStrc* pContext, D2UnitStrc* pItem, int nArg3, int nArg4, int nArg5, int* pOut, unsigned char nArg7, int nArg8); // 0x004DBB50
int __stdcall sub_006001F0(D2CelContextStrc* pContext, int nArg2, int nArg3);                // 0x006001F0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pnNumRooms); // 0x00619790

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
static D2MonGfxCacheStrc* gpPoolBlock_007A80FC;                                                             // 0x007A80FC
extern D2MonGfxCacheStrc gaPlayerGfxCache_007A7490[7];                                                      // 0x007A7490
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
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
    if (!sub_0046E5A0_FindGfxListNode(pUnit, nToken, nMode) && !sub_0046FA80_LoadGfxNode(pUnit, nToken, nMode))
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
    while (tArg.nIndex < pHeader->nLayers)
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
    if (nClass >= sgptDataTables->nMonStatsTxtRecordCount || gpPoolBlock_007A80FC[nClass].nModeFlags[nMode])
    {
        return;
    }
    if (!gpPoolBlock_007A80FC[nClass].aPending[nMode])
    {
        if (sub_0046FB60_LoadUnitLayers(bAsync, nMode, pUnit) != 1)
        {
            gpPoolBlock_007A80FC[nClass].aPending[nMode] = 0;
            gpPoolBlock_007A80FC[nClass].nModeFlags[nMode] = 0;
        }
        else
        {
            gpPoolBlock_007A80FC[nClass].aPending[nMode] = 1;
        }
    }
    else if (!D2CMPSpriteFindAsynchSiblings(nType, nMode, nClass))
    {
        gpPoolBlock_007A80FC[nClass].nModeFlags[nMode] = 1;
    }
}

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
        if (pMonStats2->nModeFlags[nMode >> 3] & gdwBitMasks[nMode & 7])
        {
            sub_0046FDA0_PreloadMonsterMode(bAsync, pUnit, nMode);
        }
    }
}

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
    if (gaPlayerGfxCache_007A7490[nClass].nModeFlags[nMode])
    {
        return;
    }
    if (!gaPlayerGfxCache_007A7490[nClass].aPending[nMode])
    {
        if (sub_0046FB60_LoadUnitLayers(bAsync, nMode, pUnit) != 1)
        {
            gaPlayerGfxCache_007A7490[nClass].aPending[nMode] = 0;
            gaPlayerGfxCache_007A7490[nClass].nModeFlags[nMode] = 0;
        }
        else
        {
            gaPlayerGfxCache_007A7490[nClass].aPending[nMode] = 1;
        }
    }
    else if (!D2CMPSpriteFindAsynchSiblings(nType, nMode, nClass))
    {
        gaPlayerGfxCache_007A7490[nClass].nModeFlags[nMode] = 1;
    }
}

// 0x00470B70
void __fastcall sub_00470B70_ResetMonsterModeGfx(D2UnitStrc* pUnit)
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
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nAnimMode, ".\\ENGINE\\Gfx.cpp", 0x1072);
    switch (nType)
    {
    case 1:
        if (nClass < sgptDataTables->nMonStatsTxtRecordCount)
        {
            gpPoolBlock_007A80FC[nClass].nModeFlags[nAnimMode] = 0;
            gpPoolBlock_007A80FC[nClass].aPending[nAnimMode] = 0;

            int bAsync = 1;
            if (!UNITS_GetRoom(pUnit) || WINDOW_GetState() || sub_00454840_Test())
            {
                bAsync = 0;
            }

            sub_0046FEB0_PreloadMonsterModes(bAsync, pUnit);
        }
        break;
    }
}

void sub_M389_Emit_0046FF50(int bAsync, D2UnitStrc* pUnit)
{
    for (unsigned int i = 0; i < gnPlayerModeCount_00712AC0; ++i)
    {
        sub_0046FF50_PreloadPlayerMode(bAsync, pUnit, gaPlayerModes_00712AA0[i] + 0x13);
    }
}
