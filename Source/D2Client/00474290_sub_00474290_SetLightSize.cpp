struct D2ActiveRoomStrc;
struct D2DrlgActStrc;

struct D2LightStrc
{
    char unk0x00[0x0C];
    int nType;
    int nX;
    int nY;
    int nUnk0x18;
    int nUnk0x1C;
    int nUnk0x20;
    int nUnk0x24;
    D2LightStrc* pNext;
    int nUnk0x2C;
    void* pData;
};

#define LIGHT_MAX_SIZE 18
#define LIGHT_SIZE_SHIFT 3
#define LIGHT_TYPE_2 2
#define INDICATOR_HOLD_MS 2000

typedef void (__fastcall* ACTCALLBACKFN)(D2ActiveRoomStrc* pRoom);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
int __cdecl sub_004F5210();                                                                                 // 0x004F5210
int __cdecl sub_004CCF30();                                                                                 // 0x004CCF30
int __cdecl sub_0044DAE0();                                                                                 // 0x0044DAE0
void __stdcall D2GFX_DebugDraw(unsigned int* pLight, unsigned int* pPlayerLight, int nXPos, int nYPos);     // 0x004F68B0
void __stdcall DUNGEON_SetActCallbackFunc(D2DrlgActStrc* pAct, ACTCALLBACKFN pActCallbackFunction);         // 0x0061AF60
void __fastcall sub_00475930_ActCallback(D2ActiveRoomStrc* pRoom);                                          // 0x00475930
void __fastcall sub_004FB1C0_CopyRowTable(unsigned char (*pRows)[0x100]);                                  // 0x004FB1C0
unsigned char* __stdcall sub_00475B80_BuildLerpTable(unsigned int nCount, int nSteps);                      // 0x00475B80
unsigned char** __stdcall sub_00475C40_BuildLerpRowTable(unsigned int nCount, int nSteps);                  // 0x00475C40
unsigned char** __stdcall sub_00475D30_BuildRampTable(unsigned int nSize, int nSteps);                      // 0x00475D30

D2LightStrc* gpLights_007B5668;                                                                             // 0x007B5668
int gnLightsReleased_007B5670;                                                                              // 0x007B5670
int gnIndicatorLevel_007B567C;                                                                              // 0x007B567C
unsigned long gdwIndicatorTick_007B5678;                                                                    // 0x007B5678
extern unsigned int gdwLightMap_007A8A50[];                                                                 // 0x007A8A50
extern unsigned int gdwLightGrid_007B0E68[];                                                                // 0x007B0E68
extern D2DrlgActStrc* gpGlobal_007A0634;                                                                    // 0x007A0634
unsigned int gdwReciprocals_007B0A68[0x100];                                                                // 0x007B0A68
extern unsigned char gRowTable_007B5C10[][0x100];                                                           // 0x007B5C10
extern unsigned char** gppLerpRows_007B953C;                                                                // 0x007B953C
extern unsigned char* gpLerpTable_007B9540;                                                                 // 0x007B9540
extern unsigned char* gpLerpTable_007B9544;                                                                 // 0x007B9544
extern unsigned char** gppRampTable_007B954C;                                                               // 0x007B954C
extern unsigned char* gpLerpTable_007B9550;                                                                 // 0x007B9550

// 0x00474290
void __fastcall sub_00474290_SetLightSize(D2LightStrc* pLight, int nSize)
{
    if (nSize > 0)
    {
        if (nSize >= LIGHT_MAX_SIZE)
        {
            nSize = LIGHT_MAX_SIZE;
        }
        D2_ASSERT(pLight, 0x131);
        pLight->nUnk0x1C = nSize * 8;
    }
}

// 0x004742D0
void __fastcall sub_004742D0_ResetLightSize(D2LightStrc* pLight, int nSize)
{
    if (nSize > 0)
    {
        if (nSize >= LIGHT_MAX_SIZE)
        {
            nSize = LIGHT_MAX_SIZE;
        }
        D2_ASSERT(pLight, 0x141);
        if (nSize >= LIGHT_MAX_SIZE)
        {
            nSize = LIGHT_MAX_SIZE;
        }
        pLight->nUnk0x18 = nSize * 8;
        pLight->nUnk0x1C = nSize * 8;
        if (pLight->nType == LIGHT_TYPE_2)
        {
            pLight->nUnk0x2C = 0;
            if (pLight->pData)
            {
                FOG_Free(pLight->pData, ".\\DRAW\\dLightMap.cpp", 0x14A, 0);
            }
            pLight->pData = 0;
        }
    }
}

// 0x00474350
int __fastcall sub_00474350_GetLightSize(D2LightStrc* pLight)
{
    D2_ASSERT(pLight, 0x155);
    return pLight->nUnk0x18 >> LIGHT_SIZE_SHIFT;
}

// 0x004743D0
void __fastcall sub_004743D0_ReleaseOverlayResource(D2LightStrc* pLight)
{
    if (!pLight)
    {
        return;
    }
    D2LightStrc* pPrev = 0;
    D2LightStrc* pCurrent = gpLights_007B5668;
    while (pCurrent)
    {
        if (pCurrent == pLight)
        {
            break;
        }
        pPrev = pCurrent;
        pCurrent = pCurrent->pNext;
    }
    D2_ASSERT(pCurrent, 0x17A);
    if (pPrev)
    {
        pPrev->pNext = pCurrent->pNext;
    }
    else
    {
        gpLights_007B5668 = pCurrent->pNext;
    }
    if (pLight->pData)
    {
        FOG_Free(pLight->pData, ".\\DRAW\\dLightMap.cpp", 0x181, 0);
    }
    FOG_Free(pLight, ".\\DRAW\\dLightMap.cpp", 0x183, 0);
    gnLightsReleased_007B5670 += 1;
}

// 0x00474470
void __fastcall sub_00474470_ResetLight(D2LightStrc* pLight)
{
    D2_ASSERT(pLight, 0x18D);
    pLight->nUnk0x20 = 1;
    pLight->nUnk0x1C = 0;
    D2_ASSERT(pLight->nType != LIGHT_TYPE_2, 0x190);
}

// 0x00475780
int __cdecl sub_00475780_GetIndicatorLevel()
{
    int nValue;
    int nLevel = 2;
    if (sub_004F5210())
    {
        if (!sub_004CCF30())
        {
            goto low;
        }
        nLevel = 1;
    }
    nValue = sub_0044DAE0();
    if (nValue <= 9)
    {
low:
        nLevel = 0;
    }
    else if (nValue <= 12)
    {
        nLevel = 1;
    }
    else if (nValue <= 15)
    {
        if (gnIndicatorLevel_007B567C >= 1)
        {
            return gnIndicatorLevel_007B567C;
        }
        nLevel = 1;
    }
    if (nLevel != gnIndicatorLevel_007B567C)
    {
        const unsigned long dwTick = GetTickCount();
        if (dwTick - gdwIndicatorTick_007B5678 > INDICATOR_HOLD_MS)
        {
            gdwIndicatorTick_007B5678 = dwTick;
            gnIndicatorLevel_007B567C = nLevel;
        }
        else
        {
            return gnIndicatorLevel_007B567C;
        }
    }
    return nLevel;
}

// 0x00475B20
void __cdecl sub_00475B20_DebugDrawLights()
{
    D2LightStrc* pLight = gpLights_007B5668;
    D2GFX_DebugDraw(gdwLightMap_007A8A50, gdwLightGrid_007B0E68, pLight->nX, pLight->nY);
}

// 0x00475B40
void __cdecl sub_00475B40_InitLightTables()
{
    DUNGEON_SetActCallbackFunc(gpGlobal_007A0634, sub_00475930_ActCallback);
    gdwReciprocals_007B0A68[0] = 0;
    for (int i = 1; i < 0x100; ++i)
    {
        gdwReciprocals_007B0A68[i] = 0x10000u / i;
    }
}

// 0x00475DF0
void __cdecl sub_00475DF0_BuildLerpTables()
{
    D2_ASSERT(!gppLerpRows_007B953C, 0xCA);
    D2_ASSERT(!gpLerpTable_007B9540, 0xCB);
    D2_ASSERT(!gpLerpTable_007B9544, 0xCC);
    D2_ASSERT(!gppRampTable_007B954C, 0xCD);
    D2_ASSERT(!gpLerpTable_007B9550, 0xCE);
    sub_004FB1C0_CopyRowTable(gRowTable_007B5C10);
    gppLerpRows_007B953C = sub_00475C40_BuildLerpRowTable(0x20, 8);
    gpLerpTable_007B9540 = sub_00475B80_BuildLerpTable(0x20, 0x10);
    gpLerpTable_007B9544 = sub_00475B80_BuildLerpTable(0x20, 0x20);
    gppRampTable_007B954C = sub_00475D30_BuildRampTable(0x20, 0x20);
    gpLerpTable_007B9550 = sub_00475B80_BuildLerpTable(0x20, 0x28);
}
