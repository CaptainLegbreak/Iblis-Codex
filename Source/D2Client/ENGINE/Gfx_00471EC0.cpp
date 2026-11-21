#include "D2ItemTypes.h"
#include "D2StateIds.h"
#include "D2StatIds.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2CelContext.h"
struct D2UnitStrc;
struct D2InventoryStrc;





extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern const char gszGfxFile_006D6C1C[];                                                                    // 0x006D6C1C
extern int gnGlobal_0071146C;                                                                               // 0x0071146C

int __cdecl sub_0044DC60();                                                                                 // 0x0044DC60
int __cdecl sub_0045AE90();                                                                         // 0x0045AE90
extern "C" int __cdecl sub_0045AFC0();                                                          // 0x0045AFC0
extern "C" int __cdecl sub_0045AFD0_GetMouseYOffset();                                                      // 0x0045AFD0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
int __fastcall sub_00464C40_DecrementCounter58(D2UnitStrc* pUnit);                                          // 0x00464C40
D2UnitStrc* __cdecl sub_00467A10();                                                             // 0x00467A10
D2MissilesTxt* __fastcall sub_0046ACE0(int nMissileId);                                    // 0x0046ACE0
void __stdcall sub_0046E300_DrawUnitOverlays(D2UnitStrc* pUnit, unsigned int dwColor, int bFront, int nX, int nY, int bLift); // 0x0046E300
int __fastcall sub_00471BD0(D2UnitStrc* pUnit);                                               // 0x00471BD0
unsigned char* __cdecl sub_00477680();                                                                      // 0x00477680
extern "C" int __stdcall sub_004DA0B0_GetGfxOffsetX(D2UnitStrc* pUnit);                                     // 0x004DA0B0
int __stdcall sub_004DA0D0_GetGfxMotionField38(D2UnitStrc* pUnit);                                          // 0x004DA0D0
int __stdcall sub_004DA0F0_GetGfxMotionField3C(D2UnitStrc* pUnit);                                          // 0x004DA0F0
int __fastcall sub_004DB180_IsGfxUnitType(D2UnitStrc* pUnit);                                               // 0x004DB180
int __fastcall sub_004DBB50_GetItemCelContext(D2CelContextStrc* pToken, D2UnitStrc* pUnit, int nArg34, int nArg40, int nArg0, int* pItemId, unsigned char nComponent, int nMode); // 0x004DBB50
int __stdcall D2GFX_CheckPerspective();                                                                     // 0x004F51D0
void __stdcall TEXTURE_CelDraw(D2CelContextStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette); // 0x004F6480
unsigned char* __fastcall D2Win_10175_GetPL2Shift(int nIndex);                                              // 0x004FB0C0
int __stdcall sub_006001F0(D2CelContextStrc* pContext, int nArg2, int nArg3);                // 0x006001F0
unsigned char __stdcall UNITS_GetDirection(D2UnitStrc* pUnit);                                              // 0x00620100
int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit);                                                    // 0x00621190
void __stdcall UNITS_GetShiftedFrameMetrics(D2UnitStrc* pUnit, int* pFrameNo, int* pFrameCount);           // 0x00621810
unsigned int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);               // 0x00625480
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                         // 0x0062B400
unsigned char* __stdcall ITEMS_GetColor(D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned char* pShift, int nArg); // 0x0062C100
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

static int __stdcall sub_00470EC0_DrawGfxUnit(unsigned int dwColor, int nArg, int bOverlay, D2UnitStrc* pUnit, int nX, int nY);
static int __stdcall sub_00470EC0_DrawGfxUnit(unsigned int dwColor, int nArg, int bOverlay, D2UnitStrc* pUnit, int nX, int nY); // 0x00470EC0

#define D2_MIN(a,b) ((a) < (b) ? (a) : (b))
#define D2_MAX(a,b) ((a) > (b) ? (a) : (b))

// 0x00471EC0
int __fastcall sub_00471EC0_DrawUnit(D2UnitStrc* pUnit, unsigned int dwColor, int nX, int nY, int nArg, int bOverlay)
{
    const int bPerspective = D2GFX_CheckPerspective();
    if (pUnit && pUnit->dwUnitType == UNIT_TILE)
    {
        return 0;
    }

    if (sub_00464C40_DecrementCounter58(pUnit))
    {
        sub_00471BD0(pUnit);
    }

    int nTypeValue = UNIT_INVALID;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }

    int nUnitType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    int nClassId = nClassValue;
    int nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nUnitType, &nClassId, &nMode, gszGfxFile_006D6C1C, 0xAF0);

    int nOffsetX = 0;
    int nOffsetY = 0;
    nX += sub_004DA0B0_GetGfxOffsetX(pUnit);
    nY += sub_004DA0D0_GetGfxMotionField38(pUnit);
    nY += sub_004DA0F0_GetGfxMotionField3C(pUnit);
    if (nUnitType == UNIT_OBJECT)
    {
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nClassId);
        D2_ASSERT(pObjectsTxtRecord, 0xAFD);
        if (!pObjectsTxtRecord->bDraw)
        {
            return 0;
        }

        nOffsetX = pObjectsTxtRecord->nXOffset;
        nOffsetY = pObjectsTxtRecord->nYOffset;
        nX += pObjectsTxtRecord->nXOffset;
        nY += pObjectsTxtRecord->nYOffset;
    }

    if (sub_004DB180_IsGfxUnitType(pUnit))
    {
        return sub_00470EC0_DrawGfxUnit(dwColor, nArg, bOverlay, pUnit, nX, nY);
    }

    const unsigned char nDirection = UNITS_GetDirection(pUnit);
    int nFrame;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrame, &nFrameCount);

    const int nPaletteShift = pUnit->nPaletteIndex;
    unsigned char* pPalShift = 0;
    if (nPaletteShift && pUnit != sub_00463DD0_GetPlayerUnit())
    {
        pPalShift = D2Win_10175_GetPL2Shift(nPaletteShift - 1);
    }

    int nCelDirection = nDirection;
    if (nUnitType == UNIT_ITEM && ITEMS_GetItemType(pUnit) == ITEMTYPE_GOLD)
    {
        const unsigned int nGold = STATLIST_UnitGetStatValue(pUnit, STAT_GOLD, 0);
        if (nGold < 100)
        {
            nCelDirection = 0;
        }
        else if (nGold < 500)
        {
            nCelDirection = 1;
        }
        else
        {
            nCelDirection = nGold < 5000 ? 2 : 3;
        }
    }

    D2CelContextStrc tCelContext;
    memset(&tCelContext, 0, sizeof(tCelContext));
    int nCelOut;
    if (!sub_004DBB50_GetItemCelContext(&tCelContext, pUnit, 0, nCelDirection, nFrame, &nCelOut, 1, -1))
    {
        return 0;
    }

    if (!sub_006001F0(&tCelContext, 0, 1))
    {
        return 0;
    }

    int nDrawX = nOffsetX + nX - sub_0045AFC0();
    const int nDrawY = nOffsetY + nY - sub_0045AFD0_GetMouseYOffset();
    if (bPerspective)
    {
        switch (sub_0045AE90())
        {
        case 1:
            nDrawX -= gnGlobal_0071146C / 4;
            break;
        case 2:
            nDrawX += gnGlobal_0071146C / 4;
            break;
        }
    }

    const int bSelected = sub_00467A10() == pUnit;
    if (bSelected)
    {
        unsigned int nAlpha = (dwColor & 0xFF) * 2;
        nAlpha = D2_MIN(D2_MAX(nAlpha, 0x40u), 0xFFu);

        dwColor = (dwColor & 0xFFFFFF00) | nAlpha;
    }

    if (nUnitType == UNIT_MISSILE)
    {
        D2MissilesTxt* pMissilesTxtRecord = sub_0046ACE0(pUnit->dwClassId);
        int nDrawMode = 5;
        if (pMissilesTxtRecord->nTrans == 1)
        {
            nDrawMode = 3;
        }
        if (pMissilesTxtRecord->nTrans == 2)
        {
            nDrawMode = 4;
        }
        if (bSelected)
        {
            nDrawMode = 7;
        }

        unsigned char* pPalette;
        if (pMissilesTxtRecord->bAltPalette && sub_0044DC60())
        {
            pPalette = sub_00477680();
        }
        else
        {
            pPalette = pPalShift;
        }

        TEXTURE_CelDraw(&tCelContext, nDrawX, nDrawY, dwColor, nDrawMode, pPalette);
        return 1;
    }

    int nDrawMode = 5;
    if (bSelected)
    {
        nDrawMode = 7;
    }

    unsigned char* pPalette;
    {
        unsigned char nShift;
        if (nUnitType != UNIT_ITEM || (pPalette = ITEMS_GetColor(0, pUnit, &nShift, 0)) == 0)
        {
            pPalette = pPalShift;
        }
    }

    TEXTURE_CelDraw(&tCelContext, nDrawX, nDrawY, dwColor, nDrawMode, pPalette);
    if (bOverlay)
    {
        sub_0046E300_DrawUnitOverlays(pUnit, dwColor, 0, -1, -1, 0);
    }

    return 1;
}

struct D2GfxLayerHeaderStrc { unsigned char nCount, unk01, nArg; };
struct D2GfxNodeTargetStrc { int unk00[5]; void* pLayer; };
struct D2GfxListNodeStrc { int nMode,nId; D2GfxNodeTargetStrc* pTarget; int unk0C; D2GfxListNodeStrc* pNext; };
struct D2GfxDataStrc { int unk00[10]; D2GfxListNodeStrc* pList; };
int __fastcall sub_00451F60_UnitClassId(D2UnitStrc*); // 0x00451F60
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int); // 0x00451FE0
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc*); // 0x004639D0
D2GfxDataStrc* __fastcall sub_00463E10_GetGfxData(D2UnitStrc*); // 0x00463E10
int __fastcall sub_00464370_IsSelectedUnit(D2UnitStrc*); // 0x00464370
D2GfxListNodeStrc* __fastcall sub_0046E5A0_FindGfxListNode(D2UnitStrc* pUnit, int nId, int nMode); // 0x0046E5A0
void* __fastcall sub_0046FA80_LoadGfxNode(D2UnitStrc*, int, int); // 0x0046FA80
int __fastcall sub_004709A0_IsOnScreen(D2UnitStrc*, int, int, int, int); // 0x004709A0
unsigned char* __fastcall sub_00477530_GetPalShift(D2UnitStrc*); // 0x00477530
int __cdecl sub_00477750_IsModeAtLeast4(); // 0x00477750
D2GfxLayerHeaderStrc* __fastcall sub_004DB040_GetLayerHeader(void*); // 0x004DB040
int __fastcall sub_004DB050_GetCofLayerOverrideTransLvl(void*, int); // 0x004DB050
unsigned char* __fastcall sub_004DB110_GetLayerOrder(void*, int, int); // 0x004DB110
int __fastcall sub_004DB140_GetCofLayerNewTransLvl(void*, int); // 0x004DB140
void __fastcall sub_004DB2E0_GetLayerInfo(D2UnitStrc*, int, int, int, int*, int*, int*, int, int); // 0x004DB2E0
int __fastcall sub_004DB360_GetCompTransparency(D2UnitStrc*, int, int*, int); // 0x004DB360
unsigned char* __fastcall sub_004DB570_GetBodyLocItemShift(D2UnitStrc*, int, unsigned char*); // 0x004DB570
void __fastcall sub_004DC7B0_DrawUnitByType(D2UnitStrc* pUnit, int nColor, int bForce); // 0x004DC7B0
int __cdecl sub_004F5170(); // 0x004F5170
void __stdcall sub_004F5190_SetTownMode(int); // 0x004F5190
void __stdcall sub_004F6450_DrawPerspective(D2CelContextStrc*, int, int, unsigned int, int, int, unsigned char*); // 0x004F6450
int __stdcall UNITS_GetPrecisionX(D2UnitStrc*); // 0x006203B0
int __stdcall UNITS_GetPrecisionY(D2UnitStrc*); // 0x00620410
int __stdcall STATES_CheckState(D2UnitStrc*, int); // 0x00639DF0
int __stdcall STATES_CheckStateMaskGreenOnUnit(D2UnitStrc*); // 0x0063A790
int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc*, int); // 0x0063A7B0
int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc*, D2InventoryStrc*, int*, int, int); // 0x0064F380

inline int IsShapeShifted(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit) bResult = (pUnit->dwFlagEx >> 3) & 1;
    return bResult;
}
static __forceinline void* GetNodeLayer(D2UnitStrc* pUnit, int nMode)
{
    D2GfxDataStrc* pData = sub_00463E10_GetGfxData(pUnit);
    if (pData)
    {
        for (D2GfxListNodeStrc* pNode = pData->pList; pNode; pNode = pNode->pNext)
        {
            if (pNode->nMode == nMode) return pNode->pTarget->pLayer;
        }
    }
    return 0;
}

// 0x00470EC0
static int __stdcall sub_00470EC0_DrawGfxUnit(unsigned int dwColor, int nArg, int bOverlay, D2UnitStrc* pUnit, int nX, int nY)
{
    int nTypeValue = UNIT_INVALID;
    if (pUnit) nTypeValue = pUnit->dwUnitType;
    int nUnitType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    int nClassId = nClassValue;
    int nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nUnitType, &nClassId, &nMode, gszGfxFile_006D6C1C, 0x52B);
    int nDrawX = nX - sub_0045AFC0();
    int nDrawY = nY - sub_0045AFD0_GetMouseYOffset();
    int bPerspective = D2GFX_CheckPerspective();
    int nBorder = sub_0045AE90();
    if (bPerspective)
    {
        switch (nBorder)
        {
        case 1: nDrawX -= gnGlobal_0071146C / 4; break;
        case 2: nDrawX += gnGlobal_0071146C / 4; break;
        }
    }
    int bRestoreTown = 0;
    int nTown = sub_004F5170();
    if (nTown && bPerspective && pUnit == sub_00463DD0_GetPlayerUnit() && nUnitType == 0)
    {
        sub_004F5190_SetTownMode(0);
        bRestoreTown = 1;
        bPerspective = 0;
    }
    if (!sub_004709A0_IsOnScreen(pUnit, nDrawX, nDrawY, 1, 0))
    {
        if (bRestoreTown) sub_004F5190_SetTownMode(nTown);
        return 0;
    }
    if (bOverlay) sub_0046E300_DrawUnitOverlays(pUnit, dwColor, 1, -1, -1, bRestoreTown);
    int nFrame, nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrame, &nFrameCount);
    unsigned char* pPalShift = 0;
    if (pUnit->nPaletteIndex) pPalShift = D2Win_10175_GetPL2Shift(pUnit->nPaletteIndex - 1);
    D2InventoryStrc* pInventory;
    D2UnitStrc* pOwner;
    if (IsShapeShifted(pUnit) && STATES_CheckStateMaskOnUnit(pUnit, 0x25) && (pOwner = sub_004639D0_GetOwnerUnit(pUnit)) != 0)
        pInventory = pOwner->pInventory;
    else
        pInventory = pUnit->pInventory;
    int nWeaponClass;
    int nWeaponToken = COMPOSIT_GetWeaponClassId(pUnit, pInventory, &nWeaponClass, nMode, 0);
    if (!sub_0046E5A0_FindGfxListNode(pUnit, nWeaponToken, -1))
    {
        if (!sub_0046FA80_LoadGfxNode(pUnit, nWeaponToken, -1)) return 0;
    }
    void* pLayer = GetNodeLayer(pUnit, nMode);
    if (!pLayer) return 0;
    D2GfxLayerHeaderStrc* pHeader = sub_004DB040_GetLayerHeader(pLayer);
    if (!pPalShift) pPalShift = sub_00477530_GetPalShift(pUnit);
    int bTransparent = sub_00464370_IsSelectedUnit(pUnit);
    int nDirection = UNITS_GetDirection(pUnit);
    int nDirectionIndex, nDirectionCount;
    sub_004DB2E0_GetLayerInfo(pUnit, nUnitType, nClassId, nMode, &nDirection, &nDirectionIndex, &nDirectionCount, pHeader->nArg, 1);
    unsigned char* pLayerOrder = sub_004DB110_GetLayerOrder(pLayer, nDirectionIndex, nFrame);
    D2_ASSERT(pLayerOrder, 0x58E);
    int bObjectPerspective = 0;
    if (nUnitType == UNIT_OBJECT && DATATBLS_GetObjectsTxtRecord(!pUnit ? -1 : pUnit->dwClassId)->nOrderFlag[nMode] == 1)
        bObjectPerspective = 1;
    int bUseItemShift = 1;
    if (STATES_CheckStateMaskGreenOnUnit(pUnit))
    {
        if (pUnit != sub_00463DD0_GetPlayerUnit())
        {
            bUseItemShift = 0;
        }
        else if (!sub_00477750_IsModeAtLeast4())
        {
            bUseItemShift = 0;
        }
    }
    int nItemId;
    int nDrawMode;
    for (int nIndex = 0; nIndex < pHeader->nCount; ++nIndex)
    {
        int nComponent = pLayerOrder[nIndex];
        unsigned char* pPalette = pPalShift;
        if (nComponent == 15)
        {
            pPalette = 0;
            if (nUnitType == 1)
            {
                D2MonStats2Txt* pRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(sub_00451F60_UnitClassId(pUnit));
                if (pRecord && pRecord->nLocalBlood && sub_0044DC60()) pPalette = sub_00477680();
            }
        }
        else if (nComponent == 14)
        {
            D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pUnit);
            if (pOwner && (pOwner->dwUnitType == UNIT_MISSILE || STATES_CheckState(pOwner, STATE_ATTACHED)))
                sub_004DC7B0_DrawUnitByType(pOwner, dwColor, 1);
            continue;
        }
        D2CelContextStrc tCel;
        memset(&tCel, 0, sizeof(tCel));
        nItemId = -1;
        if (!sub_004DBB50_GetItemCelContext(&tCel, pUnit, 0, nDirection, nFrame, &nItemId, nComponent, -1)) continue;
        nDrawMode = 5;
        int bCompTrans = sub_004DB360_GetCompTransparency(pUnit, nComponent, &nDrawMode, nItemId);
        if (bUseItemShift && (nUnitType != 0 || pUnit->nPaletteIndex != 0x6C))
            pPalette = sub_004DB570_GetBodyLocItemShift(pUnit, nComponent, pPalette);
        if (sub_004DB050_GetCofLayerOverrideTransLvl(pLayer, nComponent))
        {
            if (nArg) nDrawMode = 1;
            else if (!bCompTrans) nDrawMode = sub_004DB140_GetCofLayerNewTransLvl(pLayer, nComponent);
            if (bPerspective && bObjectPerspective)
            {
                int nPrecX = UNITS_GetPrecisionX(pUnit);
                int nPrecY = UNITS_GetPrecisionY(pUnit);
                sub_004F6450_DrawPerspective(&tCel, nPrecX, nPrecY, dwColor, nDrawMode, nBorder, pPalette);
            }
            else TEXTURE_CelDraw(&tCel, nDrawX, nDrawY, dwColor, nDrawMode, pPalette);
        }
        else if (!bTransparent && !bCompTrans && !nArg)
        {
            if (bPerspective && bObjectPerspective)
            {
                int nPrecX = UNITS_GetPrecisionX(pUnit);
                int nPrecY = UNITS_GetPrecisionY(pUnit);
                sub_004F6450_DrawPerspective(&tCel, nPrecX, nPrecY, dwColor, 5, nBorder, pPalette);
            }
            else TEXTURE_CelDraw(&tCel, nDrawX, nDrawY, dwColor, 5, pPalette);
        }
        else
        {
            if (nArg) nDrawMode = 1;
            else if (!bCompTrans && bTransparent)
            {
                unsigned int nAlpha = (dwColor & 0xFF) * 2;
                nDrawMode = 7;
                nAlpha = D2_MIN(D2_MAX(nAlpha, 0x40u), 0xFFu);
                dwColor = (dwColor & 0xFFFFFF00) | nAlpha;
            }
            TEXTURE_CelDraw(&tCel, nDrawX, nDrawY, dwColor, nDrawMode, pPalette);
        }
    }
    if (bOverlay) sub_0046E300_DrawUnitOverlays(pUnit, dwColor, 0, -1, -1, bRestoreTown);
    if (bRestoreTown) sub_004F5190_SetTownMode(nTown);
    return 1;
}
