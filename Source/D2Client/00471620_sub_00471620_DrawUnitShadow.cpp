struct D2InventoryStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x60 - 0x08];
    D2InventoryStrc* pInventory;
    char unk0x64[0xC4 - 0x64];
    unsigned int dwFlags;
    unsigned int dwFlagEx;
};

struct D2ObjectsTxt
{
    char unk0x000[0x148];
    int nXOffset;
    int nYOffset;
};

struct D2GfxLayerHeaderStrc
{
    unsigned char nLayers;
    unsigned char unk0x01;
    unsigned char nArg;
};

struct D2CelContextStrc
{
    char unk0x00[0x48];
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __cdecl sub_0045AE90(); // 0x0045AE90
extern "C" int __cdecl sub_0045AFC0(); // 0x0045AFC0
extern "C" int __cdecl sub_0045AFD0_GetMouseYOffset(); // 0x0045AFD0
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
int __fastcall sub_0046D9F0_TestUnit(D2UnitStrc* pUnit); // 0x0046D9F0
void* __fastcall sub_0046E570_GetNodeValue(D2UnitStrc* pUnit, int nMode); // 0x0046E570
void* __fastcall sub_0046E5A0_FindGfxNode(D2UnitStrc* pUnit, int nWeaponClassId, int nArg); // 0x0046E5A0
void* __fastcall sub_0046FA80_LoadGfxNode(D2UnitStrc* pUnit, int nWeaponClassId, int nArg); // 0x0046FA80
int __fastcall sub_004709A0_IsOnScreen(D2UnitStrc* pUnit, int nX, int nY, int nArg1, int nArg2); // 0x004709A0
int __fastcall sub_00471450(D2UnitStrc* pUnit); // 0x00471450
int __stdcall sub_004DA0B0_GetGfxOffsetX(D2UnitStrc* pUnit); // 0x004DA0B0
int __stdcall sub_004DA0D0_GetGfxMotionField38(D2UnitStrc* pUnit); // 0x004DA0D0
int __stdcall sub_004DA0F0_GetGfxMotionField3C(D2UnitStrc* pUnit); // 0x004DA0F0
int __stdcall sub_004DA1B0_GetMotionRawAZ(D2UnitStrc* pUnit); // 0x004DA1B0
D2GfxLayerHeaderStrc* __fastcall sub_004DB040_GetLayerHeader(void* pGfx); // 0x004DB040
int __fastcall sub_004DB090_GetCofLayerShadow(void* pGfx, int nLayer); // 0x004DB090
unsigned char* __fastcall sub_004DB110_GetLayerOrder(void* pGfx, int nA, int nFrame); // 0x004DB110
int __fastcall sub_004DB180_IsGfxUnitType(D2UnitStrc* pUnit); // 0x004DB180
void __fastcall sub_004DB2E0_GetLayerInfo(D2UnitStrc* pUnit, int nType, int nClass, int nMode, int* pDirection, int* pA, int* pB, int nArg, int nFlag); // 0x004DB2E0
int __fastcall sub_004DBB50_GetItemCelContext(D2CelContextStrc* pContext, D2UnitStrc* pItem, int nArg3, int nArg4, int nArg5, int* pOut, unsigned char nArg7, int nArg8); // 0x004DBB50
int __fastcall sub_004DBD30_CountVisibleLayers(D2UnitStrc* pUnit, D2GfxLayerHeaderStrc* pHeader, unsigned char* pLayers, int* pOut, int nDirection, int nFrame); // 0x004DBD30
int __cdecl sub_004F5170(); // 0x004F5170
void __stdcall sub_004F5190_SetTownMode(int bTown); // 0x004F5190
int __stdcall D2GFX_CheckPerspective(); // 0x004F51D0
void __stdcall TEXTURE_CelDrawShadow(D2CelContextStrc* pContext, int nX, int nY); // 0x004F6540
int __stdcall SCALE_CheckPerspectivePosition(int nX, int nY); // 0x004F66E0
void __stdcall SCALE_AdjustPerspectivePosition(int nX, int nY, int nBias, int* pX, int* pY); // 0x004F6760
unsigned char __stdcall UNITS_GetDirection(D2UnitStrc* pUnit); // 0x00620100
int __stdcall UNITS_GetPrecisionX(D2UnitStrc* pUnit); // 0x006203B0
int __stdcall UNITS_GetPrecisionY(D2UnitStrc* pUnit); // 0x00620410
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit); // 0x00620650
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit); // 0x006206B0
int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit); // 0x00621190
void __stdcall UNITS_GetShiftedFrameMetrics(D2UnitStrc* pUnit, int* pFrameNo, int* pFrameCount); // 0x00621810
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask); // 0x0063A7B0
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270
int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int* pWeaponClassId, int nAnimMode, int a5); // 0x0064F380
extern int gnScreenWidth_0071146C; // 0x0071146C

inline int UNITS_IsFlag5SetInl(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlags >> 5) & 1;
}

static __forceinline int IsShapeShifted(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit) bResult = (pUnit->dwFlagEx >> 3) & 1;
    return bResult;
}

// 0x00471620
int __fastcall sub_00471620_DrawUnitShadow(D2UnitStrc* pUnit)
{
    if (UNITS_IsFlag5SetInl(pUnit) || STATES_CheckState(pUnit, 0x92))
        return 0;

    if (!sub_004DB180_IsGfxUnitType(pUnit))
    {
        sub_00471450(pUnit);
        return 1;
    }

    int nWeaponClass;
    D2UnitStrc* pOwner;
    D2InventoryStrc* pInventory;
    int nWeaponClassId;
    int nUnused;
    int nFrameCount;
    int nVisible;
    int nComponent;
    int nClass;
    int nType;
    int nDrawY;
    unsigned char* pOrder;
    int bPerspective;
    int nFrame;
    void* pGfx;
    int nDirection;
    int nMode;
    D2GfxLayerHeaderStrc* pHeader;
    int nDrawX;
    int nPrevMode;
    int bTownMode;
    int nX;
    int nY;

    bTownMode = 0;
    nPrevMode = sub_004F5170();
    if (nPrevMode && D2GFX_CheckPerspective() && pUnit == sub_00463DD0() && !sub_0046D9F0_TestUnit(pUnit))
    {
        sub_004F5190_SetTownMode(0);
        bTownMode = 1;
    }

    bPerspective = D2GFX_CheckPerspective();
    if (bPerspective)
    {
        int nHalf = sub_004DA1B0_GetMotionRawAZ(pUnit) / 2;
        int nPrecX = UNITS_GetPrecisionX(pUnit) - nHalf;
        int nPrecY = UNITS_GetPrecisionY(pUnit) - nHalf;
        if (!SCALE_CheckPerspectivePosition(nPrecX, nPrecY))
        {
            if (bTownMode)
                sub_004F5190_SetTownMode(nPrevMode);
            return 0;
        }

        SCALE_AdjustPerspectivePosition(nPrecX, nPrecY, 0, &nX, &nY);
        nX += sub_0045AFC0();
        nY += sub_0045AFD0_GetMouseYOffset() + 16;
    }
    else
    {
        int nHalf = sub_004DA0F0_GetGfxMotionField3C(pUnit) / 2;
        nX = UNITS_GetClientCoordX(pUnit) + nHalf;
        nY = UNITS_GetClientCoordY(pUnit) + nHalf;
    }

    if (bTownMode)
        nY -= 8;

    nX += sub_004DA0B0_GetGfxOffsetX(pUnit);
    nY += sub_004DA0D0_GetGfxMotionField38(pUnit);

    nDrawX = nX - sub_0045AFC0() - 2;
    nDrawY = nY - sub_0045AFD0_GetMouseYOffset();
    if (pUnit && pUnit->dwUnitType == 2)
    {
        const int nObjectId = pUnit->dwClassId;
        D2ObjectsTxt* pObjectsTxt = DATATBLS_GetObjectsTxtRecord(nObjectId);
        nDrawX += pObjectsTxt->nXOffset;
        nDrawY += pObjectsTxt->nYOffset;
    }

    if (bPerspective)
    {
        switch (sub_0045AE90())
        {
        case 1:
            nDrawX += -(gnScreenWidth_0071146C / 4);
            break;
        case 2:
            nDrawX += gnScreenWidth_0071146C / 4;
            break;
        }
    }

    if (!sub_004709A0_IsOnScreen(pUnit, nDrawX, nDrawY, 0, 1))
    {
        if (bTownMode)
            sub_004F5190_SetTownMode(nPrevMode);
        return 0;
    }

    int nTypeValue = 6;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }
    nType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClass = nClassValue;
    nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\ENGINE\\Gfx.cpp", 0x926);

    UNITS_GetShiftedFrameMetrics(pUnit, &nFrame, &nFrameCount);

    if (IsShapeShifted(pUnit) && STATES_CheckStateMaskOnUnit(pUnit, 0x25) && (pOwner = sub_004639D0_GetOwnerUnit(pUnit)) != 0)
        pInventory = pOwner->pInventory;
    else
        pInventory = pUnit->pInventory;

    nWeaponClass = COMPOSIT_GetWeaponClassId(pUnit, pInventory, &nWeaponClassId, nMode, 0);
    if (!sub_0046E5A0_FindGfxNode(pUnit, nWeaponClass, -1) && !sub_0046FA80_LoadGfxNode(pUnit, nWeaponClass, -1))
        return 0;

    pGfx = sub_0046E570_GetNodeValue(pUnit, nMode);
    if (!pGfx)
        return 0;

    pHeader = sub_004DB040_GetLayerHeader(pGfx);
    nDirection = UNITS_GetDirection(pUnit);
    sub_004DB2E0_GetLayerInfo(pUnit, nType, nClass, nMode, &nDirection, &nComponent, &nUnused, pHeader->nArg, 1);
    pOrder = sub_004DB110_GetLayerOrder(pGfx, nComponent, nFrame);
    D2_ASSERT(pOrder, 0x94E);

    nVisible = 0;
    if (sub_004DBD30_CountVisibleLayers(pUnit, pHeader, pOrder, &nVisible, nDirection, nFrame) <= 0)
    {
        if (bTownMode)
            sub_004F5190_SetTownMode(nPrevMode);
        return 0;
    }

    for (unsigned int i = 0; i < pHeader->nLayers; i++)
    {
        int nLayer = pOrder[i];
        D2_ASSERT(nLayer < 16, 0x960);
        if (sub_004DB090_GetCofLayerShadow(pGfx, nLayer))
        {
            D2CelContextStrc tContext;
            int nOut;
            memset(&tContext, 0, sizeof(tContext));
            if (sub_004DBB50_GetItemCelContext(&tContext, pUnit, 0, nDirection, nFrame, &nOut, nLayer, -1))
                TEXTURE_CelDrawShadow(&tContext, nDrawX, nDrawY);
        }
    }

    if (bTownMode)
        sub_004F5190_SetTownMode(nPrevMode);
    return 1;
}
