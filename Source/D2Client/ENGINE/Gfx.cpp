#include "D2ItemTypes.h"
#include "D2StateIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2CelContext.h"
#include "D2ClientGfx.h"
struct D2UnitStrc;
struct D2UnitTargetStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_OBJECT 2
#define UNIT_INVALID 6
#define STAT_HITPOINTS 6
#define MONSTATSFLAGINDEX_INTERACT 9

struct D2GfxLightStrc;
union D2SeedStrc;
struct D2OverlayStrc;
struct D2OverlayTxt;
struct D2StateNodeStrc;
struct D2StateOwnerStrc;
struct D2GfxListNodeStrc;
struct D2MonStatsTxt;
struct D2PlayerDataStrc;
struct D2GfxNodeTargetStrc;
struct D2UnitOverlayStrc;
struct D2GfxEntryStrc;
struct D2HashedFileEntryStrc;
struct D2HashedFileStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

struct D2OverlayStrc
{
    int nType;
    int nOverlay;
    int n08;
    int n0C;
    int n10;
    int n14;
    int n18;
    int n1C;
    int n20;
    int n24;
    int n28;
    int unk0x2C;
    int unk0x30;
    int n34;
    int nState;
    int nActive;
    union
    {
        D2GfxLightStrc* pLight;
        void* pResource;
    };
    char unk0x44[0x60];
    D2OverlayStrc* pNext;
};

struct D2GfxDataStrc
{
    char unk0x00[0x28];
    D2GfxListNodeStrc* pList;
    D2OverlayStrc* pOverlays;
    D2GfxMotionStrc* pMotion;
    int nUnk0x34;
    int nUnk0x38;
};

struct D2OverlayTxt
{
    char unk0x00[0x42];
    short wPreDraw;
    char unk0x44[4];
    unsigned char nByte48;
    char unk0x49[0x0B];
    int n54;
    int n58;
    int n5C;
    int n60;
    int n64;
    int n68;
    int n6C;
    int n70;
    int n74;
    int n78;
    unsigned char unk0x7C;
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    char unk0x80[4];
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag); // 0x004638A0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
D2GfxDataStrc* __fastcall sub_00463E10_GetGfxData(D2UnitStrc* pUnit); // 0x00463E10
void __fastcall AUTOMAP_RemoveUnitOverlay(D2UnitStrc* pUnit, int nArg, int nValue); // 0x0046F0C0
D2GfxLightStrc* __fastcall sub_00474160_MakeLightEntry(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6); // 0x00474160
void __fastcall sub_00474290(D2GfxLightStrc* pLight, int nRadius); // 0x00474290
int __fastcall sub_004DBE20(D2UnitStrc* pUnit, D2OverlayStrc* pOverlay); // 0x004DBE20
int __stdcall UNITS_GetOverlayHeight(D2UnitStrc* pUnit); // 0x006223A0

struct D2StateNodeStrc
{
    int dwType;
    int unk0x04;
    int nCurrent;
    char unk0x0C[0x2C];
    int nStateId;
    int bSelected;
    char unk0x40[0x64];
    D2StateNodeStrc* pNext;
};

struct D2StateOwnerStrc
{
    char unk0x00[0x2C];
    D2StateNodeStrc* pFirst;
};

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
void __fastcall sub_004743D0_ReleaseOverlayResource(void* pResource); // 0x004743D0

extern unsigned int gdwBitMasks_006CE268[]; // 0x006CE268
extern int gnGlobal_0071146C; // 0x0071146C
int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit); // 0x00621190
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
extern "C" int __cdecl sub_0045AFC0(); // 0x0045AFC0
extern "C" int __cdecl sub_0045AFD0_GetMouseYOffset(); // 0x0045AFD0
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit); // 0x00620650
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit); // 0x006206B0
int __cdecl sub_0045AE90(); // 0x0045AE90
int __fastcall sub_004709A0_IsOnScreen(D2UnitStrc* pUnit, int nX, int nY, int nArg1, int nArg2); // 0x004709A0
void __stdcall sub_004F6570_DrawCelColored(D2CelContextStrc* pContext, int nX, int nY, unsigned char nColor); // 0x004F6570
int __stdcall sub_004DA0D0_GetGfxMotionField38(D2UnitStrc* pUnit); // 0x004DA0D0
int __stdcall UNITS_GetPrecisionX(D2UnitStrc* pUnit); // 0x006203B0
int __stdcall UNITS_GetPrecisionY(D2UnitStrc* pUnit); // 0x00620410
int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask); // 0x0063A7B0
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0
int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int* pWeaponClassId, int nAnimMode, int a5); // 0x0064F380
D2GfxListNodeStrc* __fastcall sub_0046E5A0_FindGfxListNode(D2UnitStrc* pUnit, int nId, int nMode); // 0x0046E5A0
void* __fastcall sub_0046FA80_LoadGfxNode(D2UnitStrc* pUnit, int nWeaponClassId, int nArg); // 0x0046FA80
void* __fastcall sub_0046E570_GetGfxEntry(D2UnitStrc* pUnit, int nMode); // 0x0046E570
D2GfxLayerHeaderStrc* __fastcall sub_004DB040_GetLayerHeader(void* pGfx); // 0x004DB040
void __fastcall sub_004DB2E0_GetLayerInfo(D2UnitStrc* pUnit, int nType, int nClass, int nMode, int* pDirection, int* pA, int* pB, int nArg, int nFlag); // 0x004DB2E0
int __fastcall sub_004DB670_UpdateUnitGfx(D2UnitStrc* pUnit, int nLayer); // 0x004DB670
int __fastcall sub_004DBB50_GetItemCelContext(D2CelContextStrc* pToken, D2UnitStrc* pUnit, int nArg34, int nArg40, int nArg0, int* pItemId, unsigned char nComponent, int nMode); // 0x004DBB50
int __stdcall sub_006001F0(D2CelContextStrc* pContext, int nArg2, int nArg3); // 0x006001F0
int __stdcall CelGetHeight(D2CelStrc* pCel); // 0x006018F0
int __stdcall CelGetWidth(D2CelStrc* pCel); // 0x006018C0
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
void __stdcall sub_0046E300_DrawUnitOverlays(D2UnitStrc* pUnit, unsigned int nColor, int bFront, int nX, int nY, int bLift); // 0x0046E300

int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820
int __fastcall sub_00461250_QueueMove(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget, int bForce); // 0x00461250
extern D2UnitStrc* gpAiTargets_007A7470[]; // 0x007A7470

struct D2UnitOverlayStrc
{
    int nType;
    int nOverlay;
    char unk0x08[0x9C];
    D2UnitOverlayStrc* pNext;
};

int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0); // 0x0040B480
int __stdcall sub_004DA110_GetMotionAX(D2UnitStrc* pUnit); // 0x004DA110
int __stdcall sub_004DA130_GetMotionAY(D2UnitStrc* pUnit); // 0x004DA130
void __stdcall sub_004F6540(D2CelContextStrc* pContext, int nX, int nY); // 0x004F6540

static inline int UNIT_HasFlagEx(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlagEx & nFlag) != 0;
    }

    return 0;
}

// 0x0046DEF0
static void sub_0046DEF0_SyncStateOverlay(D2OverlayStrc* pOverlay, D2GfxDataStrc* pGfx)
{
    for (D2OverlayStrc* pOther = pGfx->pOverlays; pOther; pOther = pOther->pNext)
    {
        if (pOther->nType == 8 && pOther != pOverlay)
        {
            if (pOther->nState == pOverlay->nState)
            {
                pOverlay->nActive = pOther->nActive;
                pOverlay->n08 = pOther->n08;
                return;
            }
            if (pOther->nActive)
            {
                pOverlay->nActive = 0;
                return;
            }
        }
    }
    pOverlay->nActive = 1;
    pOverlay->n08 = 0;
}

// 0x0046DF40
static void __stdcall sub_0046DF40_RecalcStateOverlays(D2StateOwnerStrc* pOwner, D2UnitStrc* pUnit, D2StateNodeStrc* pNode)
{
    const int nStateId = pNode->nStateId;
    const int bHasState = STATES_CheckState(pUnit, nStateId);
    if (bHasState)
    {
        STATES_ToggleState(pUnit, nStateId, 0);
    }
    if (!sub_0063A250(pUnit))
    {
        pNode->nCurrent = 0;
        if (bHasState)
        {
            STATES_ToggleState(pUnit, nStateId, 1);
        }
    }
    if (bHasState)
    {
        STATES_ToggleState(pUnit, nStateId, 1);
    }

    for (D2StateNodeStrc* pEntry = pOwner->pFirst; pEntry; pEntry = pEntry->pNext)
    {
        if (pEntry->nStateId == nStateId && pEntry->dwType == 8)
        {
            pEntry->bSelected = 0;
            pEntry->nCurrent = -1;
        }
    }

    int nNext = 0;
    int nLowest = 0;
    for (D2StateNodeStrc* pEntry = pOwner->pFirst; pEntry; pEntry = pEntry->pNext)
    {
        if (pEntry->dwType == 8)
        {
            if ((!nNext || pEntry->nStateId < nNext) && pEntry->nStateId > nStateId)
            {
                nNext = pEntry->nStateId;
            }
            if (!nLowest || pEntry->nStateId < nLowest)
            {
                nLowest = pEntry->nStateId;
            }
        }
    }
    if (!nNext)
    {
        nNext = nLowest;
    }

    for (D2StateNodeStrc* pEntry = pOwner->pFirst; pEntry; pEntry = pEntry->pNext)
    {
        if (pEntry->nStateId == nNext && pEntry->dwType == 8)
        {
            pEntry->bSelected = 1;
            pEntry->nCurrent = 0;
        }
    }
}

void __stdcall sub_P09_Emit_0046DF40(D2StateOwnerStrc* pOwner, D2UnitStrc* pUnit, D2StateNodeStrc* pNode, D2StateNodeStrc* pOther)
{
    sub_0046DF40_RecalcStateOverlays(pOwner, pUnit, pNode);
    sub_0046DF40_RecalcStateOverlays(pOwner, pUnit, pOther);
}

// 0x0046EA80
static inline void sub_0046EA80_ResetGfxBytes20(D2UnitStrc* pUnit)
{
    for (unsigned int i = 0; i < 20; ++i)
    {
        sub_004DB1C0_SetGfxByte(pUnit, i, 0);
    }
}

// 0x0046EAA0
static inline void sub_0046EAA0_ResetGfxBytes16(D2UnitStrc* pUnit)
{
    for (int i = 0; i < 16; ++i)
    {
        sub_004DB1C0_SetGfxByte(pUnit, i, 0);
    }
}

// 0x0046EB50
static inline void sub_0046EB50_ResetGfxBytes8(D2UnitStrc* pUnit)
{
    for (int i = 0; i < 8; ++i)
    {
        sub_004DB1C0_SetGfxByte(pUnit, i, 0);
    }
}

void __fastcall sub_M113_Emit_0046EA80(D2UnitStrc* pUnit)
{
    sub_0046EA80_ResetGfxBytes20(pUnit);
    sub_0046EAA0_ResetGfxBytes16(pUnit);
    sub_0046EB50_ResetGfxBytes8(pUnit);
}

// 0x0046EAC0
static void __stdcall sub_0046EAC0_ResetGfxIndex(D2UnitStrc* pUnit, int nIndex)
{
    D2_ASSERT(nIndex < GFX_INDEX_COUNT, 0x65F);
    for (int i = 0; i < GFX_INDEX_COUNT; ++i)
    {
        sub_004DB1C0_SetGfxByte(pUnit, i, 0);
    }
    D2GfxDataStrc* pGfxData = sub_00463E10_GetGfxData(pUnit);
    D2_ASSERT(pGfxData, 0x668);
    D2GfxListNodeStrc* pNode = pGfxData->pList;
    while (pNode)
    {
        D2GfxListNodeStrc* pNext = pNode->pNext;
        FOG_Free(pNode, ".\\ENGINE\\Gfx.cpp", 0x66D, 0);
        pNode = pNext;
    }
    pGfxData->pList = 0;
}

// 0x0046F000
void __fastcall sub_0046F000_ResetGfx(D2UnitStrc* pUnit)
{
    for (int i = 0; i < GFX_INDEX_COUNT; ++i)
    {
        sub_0046EAC0_ResetGfxIndex(pUnit, i);
    }
}

// 0x0046EB70
static void sub_0046EB70_FreeOverlays(D2GfxDataStrc* pGfxData)
{
    D2OverlayStrc* pOverlay = pGfxData->pOverlays;
    while (pOverlay)
    {
        D2OverlayStrc* pNext = pOverlay->pNext;
        if (pOverlay->pResource)
        {
            sub_004743D0_ReleaseOverlayResource(pOverlay->pResource);
        }
        FOG_Free(pOverlay, ".\\ENGINE\\Gfx.cpp", 0x690, 0);
        pOverlay = pNext;
    }
}

// 0x0046EC10
void __fastcall sub_0046EC10_FreeGfxData(D2UnitStrc* pUnit)
{
    D2GfxDataStrc* pGfxData = sub_00463E10_GetGfxData(pUnit);
    D2_ASSERT(pGfxData, 0x814);
    D2GfxListNodeStrc* pNode = pGfxData->pList;
    while (pNode)
    {
        D2GfxListNodeStrc* pNext = pNode->pNext;
        FOG_Free(pNode, ".\\ENGINE\\Gfx.cpp", 0x81A, 0);
        pNode = pNext;
    }
    sub_0046EB70_FreeOverlays(pGfxData);
    FOG_Free(pGfxData, ".\\ENGINE\\Gfx.cpp", 0x820, 0);
}

int gbHealthBarColorsInit_007A8924; // 0x007A8924

unsigned char gnHealthBarColors_007A890C[4]; // 0x007A890C

inline int STATES_IsUnitShapeShiftedInl(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlagEx >> 3) & 1;
}

inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecordInl(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

// 0x0046ED50
static unsigned char sub_0046ED50(D2UnitStrc* pUnit)
{
    if (!gbHealthBarColorsInit_007A8924)
    {
        gnHealthBarColors_007A890C[0] = D2Win_10034_MixRGB(0, 0xC0, 0);
        gnHealthBarColors_007A890C[1] = D2Win_10034_MixRGB(0xE0, 0xE0, 0);
        gnHealthBarColors_007A890C[2] = D2Win_10034_MixRGB(0xE0, 0, 0);
        gnHealthBarColors_007A890C[3] = D2Win_10034_MixRGB(0, 0, 0xC0);
        gbHealthBarColorsInit_007A8924 = 1;
    }
    int nType;
    int nClass;
    int nMode;
    int nTypeValue = UNIT_INVALID;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }
    nType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClass = nClassValue;
    nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\ENGINE\\Gfx.cpp", 0x991);
    if (nType != UNIT_MONSTER)
    {
        return gnHealthBarColors_007A890C[0];
    }
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInl(nClass);
    if (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_INTERACT >> 3] & gdwBitMasks_006CE268[MONSTATSFLAGINDEX_INTERACT & 7])
    {
        return gnHealthBarColors_007A890C[3];
    }
    int nMaxLife = STATLIST_GetMaxLifeFromUnit(pUnit);
    if (!nMaxLife)
    {
        return gnHealthBarColors_007A890C[0];
    }
    int nPercent = 100 * STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0) / nMaxLife;
    if (nPercent < 33)
    {
        return gnHealthBarColors_007A890C[2];
    }
    if (nPercent < 66)
    {
        return gnHealthBarColors_007A890C[1];
    }
    return gnHealthBarColors_007A890C[0];
}

// 0x00471A30
int __fastcall sub_00471A30(D2UnitStrc* pUnit)
{
    int nOffsetX = 0;
    int nOffsetY = 0;
    int nType;
    int nClass;
    int nMode;
    int nTypeValue = UNIT_INVALID;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }
    nType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClass = nClassValue;
    nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\ENGINE\\Gfx.cpp", 0x9B6);
    int bPerspective = sub_004F51D0_IsPerspective();
    if (nType == UNIT_OBJECT)
    {
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nClass);
        D2_ASSERT(pObjectsTxtRecord, 0x9BE);
        if (!pObjectsTxtRecord->bDraw || !pObjectsTxtRecord->nBlocksLight[nMode])
        {
            return 0;
        }
        nOffsetY = pObjectsTxtRecord->nYOffset;
        nOffsetX = pObjectsTxtRecord->nXOffset;
    }
    int nX = nOffsetX - sub_0045AFC0() + UNITS_GetClientCoordX(pUnit);
    int nY = nOffsetY - sub_0045AFD0_GetMouseYOffset() + UNITS_GetClientCoordY(pUnit);
    if (bPerspective)
    {
        switch (sub_0045AE90())
        {
        case 1:
            nX += -(gnGlobal_0071146C / 4);
            break;
        case 2:
            nX += gnGlobal_0071146C / 4;
            break;
        }
    }
    if (!sub_004709A0_IsOnScreen(pUnit, nX, nY, 0, 0))
    {
        return 0;
    }
    unsigned char nColor = sub_0046ED50(pUnit);
    unsigned char nDirection = UNITS_GetDirection(pUnit);
    int nFrameNo;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrameNo, &nFrameCount);
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    int nOut;
    if (!sub_004DBB50_InitCelContext(&tContext, pUnit, 0, nDirection, nFrameNo, &nOut, 1, -1))
    {
        return 0;
    }
    sub_004F6570_DrawCelColored(&tContext, nX, nY, nColor);
    return 1;
}

// 0x00471BD0
int __fastcall sub_00471BD0(D2UnitStrc* pUnit)
{
    int nX;
    int nY;
    int bPerspective = sub_004F51D0_IsPerspective();
    if (pUnit && pUnit->dwUnitType >= UNIT_PLAYER && pUnit->dwUnitType <= UNIT_OBJECT)
    {
        if (bPerspective)
        {
            int nZ = sub_004DA0F0_GetUnitGfxOffsetZ(pUnit);
            sub_004F6760_PrecisionToScreen(UNITS_GetPrecisionX(pUnit), UNITS_GetPrecisionY(pUnit), nZ, &nX, &nY);
            switch (sub_0045AE90())
            {
            case 1:
                nX += -(gnGlobal_0071146C / 4);
                break;
            case 2:
                nX += gnGlobal_0071146C / 4;
                break;
            }
            nY += 0x10;
            nX += sub_004DA0B0_GetUnitGfxOffsetX(pUnit);
            nY += sub_004DA0D0_GetGfxMotionField38(pUnit);
        }
        else
        {
            nX = UNITS_GetClientCoordX(pUnit) - sub_0045AFC0() + sub_004DA0B0_GetUnitGfxOffsetX(pUnit);
            nY = UNITS_GetClientCoordY(pUnit) - sub_0045AFD0_GetMouseYOffset() + sub_004DA0D0_GetGfxMotionField38(pUnit);
            nY += sub_004DA0F0_GetUnitGfxOffsetZ(pUnit);
        }
        if (!sub_004709A0_IsOnScreen(pUnit, nX, nY, 0, 0))
        {
            return 0;
        }
        unsigned char nColor = sub_0046ED50(pUnit);
        int nType = pUnit->dwUnitType;
        int nClass = pUnit->dwClassId;
        int nMode = UNITS_GetAnimOrSeqMode(pUnit);
        D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\ENGINE\\Gfx.cpp", 0xA2F);
        int nDirection = UNITS_GetDirection(pUnit);
        int nFrameNo;
        int nFrameCount;
        UNITS_GetShiftedFrameMetrics(pUnit, &nFrameNo, &nFrameCount);
        D2InventoryStrc* pInventory;
        D2UnitStrc* pOwner;
        if (STATES_IsUnitShapeShiftedInl(pUnit) && STATES_CheckStateMaskOnUnit(pUnit, 0x25) && (pOwner = sub_004639D0_GetOwnerUnit(pUnit)) != 0)
        {
            pInventory = pOwner->pInventory;
        }
        else
        {
            pInventory = pUnit->pInventory;
        }
        int nWeaponClassId;
        int nComponent = COMPOSIT_GetWeaponClassId(pUnit, pInventory, &nWeaponClassId, nMode, 0);
        if (!sub_0046E5A0_FindGfxListNode(pUnit, nComponent, -1) && !sub_0046FA80_LoadGfxNode(pUnit, nComponent, -1))
        {
            return 0;
        }
        void* pGfx = sub_0046E570_GetGfxEntry(pUnit, nMode);
        if (!pGfx)
        {
            return 0;
        }
        D2GfxLayerHeaderStrc* pHeader = sub_004DB040_GetLayerHeader(pGfx);
        int nA;
        int nB;
        sub_004DB2E0_GetLayerInfo(pUnit, nType, nClass, nMode, &nDirection, &nA, &nB, pHeader->nArg, 1);
        unsigned char* pLayers = sub_004DB110_GetLayerOrder(pGfx, nA, nFrameNo);
        D2_ASSERT(pLayers, 0xA56);
        int nVisible = 0;
        if (sub_004DBD30_CountVisibleLayers(pUnit, pHeader, pLayers, &nVisible, nDirection, nFrameNo) > 0)
        {
            for (unsigned int i = 0; i < pHeader->nLayers; ++i)
            {
                int nLayer = pLayers[i];
                if (sub_004DB670_UpdateUnitGfx(pUnit, nLayer))
                {
                    D2CelContextStrc tContext;
                    memset(&tContext, 0, sizeof(tContext));
                    int nOut;
                    if (sub_004DBB50_InitCelContext(&tContext, pUnit, 0, nDirection, nFrameNo, &nOut, nLayer, -1))
                    {
                        sub_004F6570_DrawCelColored(&tContext, nX, nY, nColor);
                    }
                }
            }
            return 1;
        }
        return 0;
    }
    sub_00471A30(pUnit);
    return 1;
}

// 0x0046EE80
int __fastcall sub_0046EE80_DrawItemCel(D2UnitStrc* pItem, int nX, int nY)
{
    const int nType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nType != 4)
    {
        return 0;
    }
    int nSize = 0;
    if (ITEMS_GetItemType(pItem) == ITEMTYPE_GOLD)
    {
        unsigned int nGold = STATLIST_UnitGetStatValue(pItem, STAT_GOLD, 0);
        if (nGold >= 0x64)
        {
            if (nGold < 0x1F4)
            {
                nSize = 1;
            }
            else
            {
                nSize = nGold < 0x1388 ? 2 : 3;
            }
        }
    }
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    int nOut;
    const int bReady = sub_004DBB50_GetItemCelContext(&tContext, pItem, 0, nSize, 0, &nOut, 1, -1)
        && sub_006001F0(&tContext, 0, 1)
        && sub_004DAB40_CheckCel(tContext.pCel, nX, nY + CelGetHeight(tContext.pCel), 0);
    if (!bReady)
    {
        return 0;
    }
    unsigned char nShift;
    const int nPalette = sub_0062C100(0, pItem, &nShift, 1);
    int nDrawMode = 5;
    if (ITEMS_CheckItemFlag(pItem, 0x400000, 0xAC2, ".\\ENGINE\\Gfx.cpp"))
    {
        nDrawMode = 1;
    }
    sub_004F6480(&tContext, nX, nY + CelGetHeight(tContext.pCel), -1, nDrawMode, nPalette);
    sub_0046E300_DrawUnitOverlays(pItem, 0xFF, 0, nX + ((unsigned int)CelGetWidth(tContext.pCel) >> 1), nY + ((unsigned int)CelGetHeight(tContext.pCel) >> 1), 0);
    return 1;
}

// 0x0046F060
D2GfxMotionStrc* __fastcall sub_0046F060_GetGfxMotion(D2UnitStrc* pUnit)
{
    D2GfxDataStrc* pGfxData = sub_00463E10_GetGfxData(pUnit);
    if (pGfxData)
        return pGfxData->pMotion;
    return 0;
}

// 0x0046F950
void __fastcall sub_0046F950(D2UnitStrc* pUnit)
{
    if (!sub_00464820_IsDeadOrDying(pUnit) && pUnit && pUnit->dwUnitType == UNIT_PLAYER)
        sub_00461250_QueueMove(7, pUnit, 0, 1);
}

// 0x0046C6E0
void __fastcall sub_0046C6E0_AddToUnitSlots(D2UnitStrc* pUnit)
{
    D2UnitStrc** ppSlot = gpAiTargets_007A7470;
    for (int i = 0; i < 8; ++i, ++ppSlot)
    {
        if (!*ppSlot)
        {
            *ppSlot = pUnit;
            return;
        }
    }
}

// 0x0046C700
void __fastcall sub_0046C700(D2UnitStrc* pUnit)
{
    D2UnitStrc** ppSlot = gpAiTargets_007A7470;
    for (int i = 0; i < 8; ++i, ++ppSlot)
    {
        if (*ppSlot == pUnit)
        {
            *ppSlot = 0;
            return;
        }
    }
}

// 0x0045C470
void __fastcall sub_0045C470_ClearPendingAction(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->pPlayerData)
    {
        pUnit->pPlayerData->nState = 0;
        pUnit->pPlayerData->nMode = 0;
        pUnit->pPlayerData->nArg1 = 0;
        pUnit->pPlayerData->nArg2 = 0;
    }
}

inline int sub_M449_IsUnitTypeInl(D2UnitStrc* pUnit, int nType)
{
    if (!pUnit)
    {
        return 0;
    }
    if (pUnit->dwUnitType != nType)
    {
        return 0;
    }
    return 1;
}

// 0x0046F090
static int sub_0046F090_IsNotMonsterOrNoFlag2(D2UnitStrc* pUnit)
{
    if (!sub_M449_IsUnitTypeInl(pUnit, 1))
    {
        return 1;
    }

    const int nClassId = pUnit->dwClassId;
    return !sub_004638A0_CheckMonStats2Flag(nClassId, 2);
}

int __cdecl sub_M449_Emit_0046F090(D2UnitStrc* pUnit)
{
    return sub_0046F090_IsNotMonsterOrNoFlag2(pUnit) + 0x55;
}

// 0x0046F1F0
int __fastcall sub_0046F1F0_GetGfx34(D2GfxDataStrc* pGfxData)
{
    D2_ASSERT(pGfxData, 0xCF1);
    return pGfxData->nUnk0x34;
}

// 0x0046F250
int __fastcall sub_0046F250_GetGfx38(D2GfxDataStrc* pGfxData)
{
    D2_ASSERT(pGfxData, 0xD0A);
    return pGfxData->nUnk0x38;
}

// 0x0046F360
void __cdecl sub_0046F360_Empty()
{
}

// 0x0046F9B0
void __cdecl sub_0046F9B0_Empty()
{
}

// 0x0046F9C0
void __cdecl sub_0046F9C0_Empty()
{
}

D2HashedFileStrc gtHashedFile_007A8100; // 0x007A8100

D2HashedFileStrc gtHashedFile_007A78F0; // 0x007A78F0

int gdwGlobal_007A8918; // 0x007A8918

void* gpPoolBlock_007A80FC; // 0x007A80FC

// 0x0046F370
static void sub_0046F370_FreeHashedEntries(D2HashedFileStrc* pTable)
{
    for (int i = 0; i < 0x200; ++i)
    {
        D2HashedFileEntryStrc* pEntry = pTable->pEntries[i];
        while (pEntry)
        {
            D2HashedFileEntryStrc* pNext = pEntry->pNext;
            if (pEntry->nFlags & 1)
            {
                unsigned char* pData = pEntry->pData;
                gdwGlobal_007A8918 -= pEntry->nSize + sizeof(D2HashedFileEntryStrc);
                FOG_Free(pData, ".\\ENGINE\\Gfx.cpp", 0xE3C, 0);
                FOG_Free(pEntry, ".\\ENGINE\\Gfx.cpp", 0xE3D, 0);
            }
            pEntry = pNext;
        }
    }
}

// 0x0046F3F0
void __cdecl sub_0046F3F0_FreeHashedFileA()
{
    sub_0046F370_FreeHashedEntries(&gtHashedFile_007A8100);
    gdwGlobal_007A8918 -= gtHashedFile_007A8100.nSize;
    if (gtHashedFile_007A8100.pData)
    {
        FOG_Free(gtHashedFile_007A8100.pData, ".\\ENGINE\\Gfx.cpp", 0xE50, 0);
    }
    memset(&gtHashedFile_007A8100, 0, sizeof(gtHashedFile_007A8100));
}

// 0x0046F440
void __cdecl sub_0046F440_FreeHashedFileB()
{
    sub_0046F370_FreeHashedEntries(&gtHashedFile_007A78F0);
    gdwGlobal_007A8918 -= gtHashedFile_007A78F0.nSize;
    if (gtHashedFile_007A78F0.pData)
    {
        FOG_Free(gtHashedFile_007A78F0.pData, ".\\ENGINE\\Gfx.cpp", 0xE61, 0);
    }
    memset(&gtHashedFile_007A78F0, 0, sizeof(gtHashedFile_007A78F0));
}

// 0x00470290
void __cdecl sub_00470290_FreeHashedFiles()
{
    sub_0046F3F0_FreeHashedFileA();
    sub_0046F440_FreeHashedFileB();
    if (gpPoolBlock_007A80FC)
    {
        FOG_FreePool(0, gpPoolBlock_007A80FC, ".\\ENGINE\\Gfx.cpp", 0x7F9, 0);
        gpPoolBlock_007A80FC = 0;
    }
}

// 0x00470390
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nType, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8)
{
    if (nOverlay < 0 || nOverlay >= sgptDataTables->nOverlayTxtRecordCount)
        return;

    D2OverlayTxt* pTxt = &sgptDataTables->pOverlayTxt[nOverlay];
    if (!pTxt)
        return;

// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if (!FOG_IsExpansion() && pTxt->wPreDraw >= 0x64)
        return;

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pUnit)
    {
        if (UNIT_HasFlagEx(pUnit, 0x40000))
            return;

        if (pUnit->dwUnitType == UNIT_MONSTER && sub_004638A0_CheckMonStats2Flag(pUnit->dwClassId, 2))
            return;
    }

    if (nType == 8 && sub_0046E100(pUnit, nOverlay))
        return;

    if (nOverlay < 0x8C || nOverlay > 0x8E && nOverlay != 0x9E)
        AUTOMAP_RemoveUnitOverlay(pUnit, pTxt->nByte48, nOverlay);

    D2OverlayStrc* pNew = (D2OverlayStrc*)FOG_Alloc(sizeof(D2OverlayStrc), ".\\ENGINE\\Gfx.cpp", 0xC48, 0);
    D2_ASSERT(pNew, 0xC49);
    memset(pNew, 0, sizeof(D2OverlayStrc));
    pNew->nType = nType;
    pNew->nOverlay = nOverlay;
    pNew->n1C = sub_004DBE20(pUnit, pNew);
    switch (nType)
    {
    case 2:
        pNew->n08 = 1;
        break;
    case 6:
        pNew->n18 = ITEMS_RollLimitedRandomNumber(&pPlayer->pSeed, pNew->n1C);
        break;
    default:
        pNew->n08 = nArg5;
        pNew->n0C = nArg6;
        pNew->n10 = nArg7;
        break;
    }

    pNew->n20 = pTxt->n54;
    pNew->n24 = pTxt->n58;
    switch (UNITS_GetOverlayHeight(pUnit))
    {
    case -1:
        pNew->n24 += 0x4B;
        break;
    case 0:
        pNew->n24 += pTxt->n5C;
        break;
    case 1:
        pNew->n24 += pTxt->n60;
        break;
    case 2:
        pNew->n24 += pTxt->n64;
        break;
    case 3:
        pNew->n24 += pTxt->n68;
        break;
    }

    if (pTxt->n74)
    {
        pNew->pLight = sub_00474160_MakeLightEntry(pUnit, 1, pTxt->n70, 0xFF, pTxt->nRed, pTxt->nGreen, pTxt->nBlue);
        if (pTxt->n74 != pTxt->n70)
            sub_00474290(pNew->pLight, pTxt->n74);
    }

    D2GfxDataStrc* pGfx = sub_00463E10_GetGfxData(pUnit);
    D2_ASSERT(pGfx, 0xC7A);
    pNew->n34 = pTxt->nByte48;
    pNew->pNext = pGfx->pOverlays;
    pGfx->pOverlays = pNew;
    if (pNew->nType == 8)
    {
        pNew->nState = nArg5;
        sub_0046DEF0_SyncStateOverlay(pNew, pGfx);
    }

    if (nArg4)
        pNew->n18 = ITEMS_RollLimitedRandomNumber(&pPlayer->pSeed, nArg4 << 8);

    pNew->n14 = pTxt->n6C << 4;
    if (nArg8)
        pNew->n14 += ITEMS_RollLimitedRandomNumber(&pPlayer->pSeed, nArg8 << 4);

    pNew->n28 = pTxt->n78;
}

inline int UNITS_IsFlag5SetInl(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlags >> 5) & 1;
}

// 0x00471450
int __fastcall sub_00471450_DrawUnitShadow(D2UnitStrc* pUnit)
{
    if (UNITS_IsFlag5SetInl(pUnit) || STATES_CheckState(pUnit, STATE_INVIS))
    {
        return 0;
    }

    int nType;
    int nClass;
    int nMode;
    int nTypeValue = UNIT_INVALID;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }
    nType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClass = nClassValue;
    nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\ENGINE\\Gfx.cpp", 0x86F);
    int bPerspective = sub_004F51D0_IsPerspective();
    int nOffsetX = 0;
    int nOffsetY = 0;
    if (nType == UNIT_OBJECT)
    {
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nClass);
        D2_ASSERT(pObjectsTxtRecord, 0x87A);
        if (!pObjectsTxtRecord->bDraw || !pObjectsTxtRecord->nBlocksLight[nMode])
        {
            return 0;
        }
        nOffsetX = pObjectsTxtRecord->nXOffset;
        nOffsetY = pObjectsTxtRecord->nYOffset;
    }
    int nX = nOffsetX - sub_0045AFC0() + UNITS_GetClientCoordX(pUnit) + sub_004DA110_GetMotionAX(pUnit);
    int nY = nOffsetY - sub_0045AFD0_GetMouseYOffset() + UNITS_GetClientCoordY(pUnit) + sub_004DA130_GetMotionAY(pUnit);
    if (bPerspective)
    {
        switch (sub_0045AE90())
        {
        case 1:
            nX += -(gnGlobal_0071146C / 4);
            break;
        case 2:
            nX += gnGlobal_0071146C / 4;
            break;
        }
        nY += 16;
    }
    if (!sub_004709A0_IsOnScreen(pUnit, nX, nY, 0, 1))
    {
        return 0;
    }
    unsigned char nDirection = UNITS_GetDirection(pUnit);
    int nFrameNo;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrameNo, &nFrameCount);
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    int nOut;
    if (!sub_004DBB50_InitCelContext(&tContext, pUnit, 0, nDirection, nFrameNo, &nOut, 1, -1))
    {
        return 0;
    }
    sub_004F6540(&tContext, nX, nY);
    return 1;
}
