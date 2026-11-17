#include "D2Client.h"

#define LIGHT_MAX_SIZE 18
#define LIGHT_SIZE_SHIFT 3
#define LIGHT_TYPE_2 2
#define INDICATOR_HOLD_MS 2000
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define LIGHT_MIN(a, b) ((a) < (b) ? (a) : (b))
struct D2UnitRefStrc;
struct D2LightCellStrc;
struct D2LightStrc;
struct D2P08LightSourceStrc;
struct D2R01LightStrc;

struct D2UnitRefStrc
{
    int nType;
    unsigned int nUnitId;
    unsigned char f_8;
};

struct D2LightCellStrc
{
    unsigned char f_0;
    char unk0x01[7];
};

D2UnitStrc* __fastcall sub_004639B0_FindServerSideUnit(unsigned int nUnitId, int nUnitType); // 0x004639B0
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990
extern int gbFlag_00712B8C; // 0x00712B8C
extern int gnCellOriginX_007B0A54; // 0x007B0A54
extern int gnCellOriginY_007B0A58; // 0x007B0A58

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

typedef void (__fastcall* ACTCALLBACKFN)(D2ActiveRoomStrc* pRoom);

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
int __cdecl sub_004F5210(); // 0x004F5210
int __cdecl sub_004CCF30(); // 0x004CCF30
int __cdecl sub_0044DAE0(); // 0x0044DAE0
void __stdcall D2GFX_DebugDraw(unsigned int* pLight, unsigned int* pPlayerLight, int nXPos, int nYPos); // 0x004F68B0
void __stdcall DUNGEON_SetActCallbackFunc(D2DrlgActStrc* pAct, ACTCALLBACKFN pActCallbackFunction); // 0x0061AF60
void __fastcall sub_00475930_ActCallback(D2ActiveRoomStrc* pRoom); // 0x00475930
void __fastcall sub_004FB1C0_CopyRowTable(unsigned char (*pRows)[0x100]); // 0x004FB1C0
unsigned char* __stdcall sub_00475B80_BuildLerpTable(unsigned int nCount, int nSteps); // 0x00475B80
unsigned char** __stdcall sub_00475C40_BuildLerpRowTable(unsigned int nCount, int nSteps); // 0x00475C40
unsigned char** __stdcall sub_00475D30_BuildRampTable(unsigned int nSize, int nSteps); // 0x00475D30
extern unsigned int gdwLightMap_007A8A50[]; // 0x007A8A50
extern unsigned int gdwLightGrid_007B0E68[]; // 0x007B0E68
extern D2DrlgActStrc* gpGlobal_007A0634; // 0x007A0634
extern unsigned char gRowTable_007B5C10[][0x100]; // 0x007B5C10
extern unsigned char** gppLerpRows_007B953C; // 0x007B953C
extern unsigned char* gpLerpTable_007B9540; // 0x007B9540
extern unsigned char* gpLerpTable_007B9544; // 0x007B9544
extern unsigned char** gppRampTable_007B954C; // 0x007B954C
extern unsigned char* gpLerpTable_007B9550; // 0x007B9550
extern int gdwGlobal_007BB384; // 0x007BB384
void __stdcall sub_004F5230(void* pArg); // 0x004F5230
extern int gdwGlobal_00712CCC; // 0x00712CCC
extern int gdwGlobal_007BB38C; // 0x007BB38C
extern int gdwGlobal_007BB3B4; // 0x007BB3B4
extern int gdwGlobal_00712F04; // 0x00712F04
extern int gdwGlobal_007BC9B0; // 0x007BC9B0
extern int gdwGlobal_007BC9B4; // 0x007BC9B4
extern int gdwGlobal_007BC99C; // 0x007BC99C
extern int gdwGlobal_007BC9BC; // 0x007BC9BC
extern int gdwGlobal_007BF024; // 0x007BF024
extern int gdwGlobal_007BF1F6; // 0x007BF1F6

struct D2GridCellStrc
{
    unsigned char unk0x00[4];
    unsigned char nValue0;
    unsigned char nValue1;
    unsigned char f_6;
    unsigned char nValue3;
};

struct D2P08LightSourceStrc
{
    unsigned char unk0x00[0x25];
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
};
extern unsigned int gdwReciprocals_007B0A68[0x100]; // 0x007B0A68
extern D2GridCellStrc gtGridCells_007B0E68[]; // 0x007B0E68

struct D2R01LightStrc
{
    int nUnitType;
    unsigned int nUnitId;
    unsigned char f_8;
    char unk0x09[3];
    int nMode;
    int nX;
    int nY;
    int nRadius;
    int nTargetRadius;
    int bFixed;
    unsigned char nIntensity;
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    D2R01LightStrc* pNext;
    int bMaskReady;
    unsigned int* pMask;
};

extern D2LightCellStrc gaCells_007B0E68[0x30][0x30]; // 0x007B0E68
extern unsigned int gdwLightOverrideRows_007ACA50[][64]; // 0x007ACA50
extern D2LightStrc* gpLights_007B5668; // 0x007B5668

D2LightCellStrc gaCells_007B0E68[0x30][0x30]; // 0x007B0E68

// 0x00474120
static __forceinline D2UnitStrc* sub_00474120_FindUnitFromRef(D2UnitRefStrc* pRef)
{
    if (pRef->nType == 6)
    {
        return 0;
    }
    if (pRef->f_8)
    {
        return sub_004639B0_FindServerSideUnit(pRef->nUnitId, pRef->nType);
    }
    return sub_00463990(pRef->nUnitId, pRef->nType);
}

// 0x00474140
void __cdecl sub_00474140_ToggleFlag()
{
    gbFlag_00712B8C = !gbFlag_00712B8C;
}

// 0x00474A30
static __forceinline unsigned char sub_00474A30_IsCellBlocked(int nX, int nY)
{
    nX = (nX >> 3) - gnCellOriginX_007B0A54;
    if (nX < 0)
    {
        return 1;
    }
    if (nX >= 0x30)
    {
        return 1;
    }
    nY = (nY >> 3) - gnCellOriginY_007B0A58;
    if (nY < 0)
    {
        return 1;
    }
    if (nY >= 0x30)
    {
        return 1;
    }
    return gaCells_007B0E68[nY][nX].f_0;
}

int __fastcall sub_M119_Emit_00474120(D2UnitRefStrc* pRef, int nX, int nY)
{
    int n = (int)sub_00474120_FindUnitFromRef(pRef);
    n += sub_00474A30_IsCellBlocked(nX, nY);
    return n;
}

#include "gen/data/Source/D2Client/DRAW/dLightMap.inc"

D2LightStrc* gpLights_007B5668; // 0x007B5668

int gnLightsReleased_007B5670; // 0x007B5670

int gnIndicatorLevel_007B567C; // 0x007B567C

unsigned long gdwIndicatorTick_007B5678; // 0x007B5678

unsigned int gdwReciprocals_007B0A68[0x100]; // 0x007B0A68

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

int gdwGlobal_007BB388; // 0x007BB388

int gdwGlobal_007BCC48; // 0x007BCC48

// 0x00474380
int __cdecl sub_00474380()
{
    return 32;
}

// 0x00477680
int __cdecl sub_00477680()
{
    return gdwGlobal_007BB384;
}

// 0x004776C0
void __fastcall sub_004776C0(void* pArg)
{
    sub_004F5230(pArg);
}

// 0x00477730
int __cdecl sub_00477730()
{
    return gdwGlobal_00712CCC;
}

// 0x00477740
int __cdecl sub_00477740()
{
    return gdwGlobal_007BB38C;
}

// 0x00477C90
int __cdecl sub_00477C90()
{
    return gdwGlobal_007BB388;
}

// 0x00478150
int __cdecl sub_00478150()
{
    return gdwGlobal_007BB3B4;
}

// 0x0047A990
int __cdecl sub_0047A990()
{
    return gdwGlobal_00712EFC;
}

// 0x0047A9D0
int __cdecl sub_0047A9D0()
{
    return gdwGlobal_00712F04;
}

// 0x0047AA20
int __cdecl sub_0047AA20()
{
    return gdwGlobal_00712F00;
}

// 0x004817D0
int __cdecl sub_004817D0()
{
    return gdwGlobal_007BC9A4;
}

// 0x004817E0
int __cdecl sub_004817E0()
{
    return gdwGlobal_007BC9AC;
}

// 0x004817F0
int __cdecl sub_004817F0()
{
    return gdwGlobal_007BC9B0;
}

// 0x00481800
int __cdecl sub_00481800()
{
    return gdwGlobal_007BC9B4;
}

// 0x00481810
int __cdecl sub_00481810()
{
    return gdwGlobal_007BC99C;
}

// 0x00481820
int __cdecl sub_00481820()
{
    return gdwGlobal_007BC9BC;
}

// 0x00486E00
int __cdecl sub_00486E00()
{
    return 0;
}

// 0x00489870
int __cdecl sub_00489870()
{
    return gdwGlobal_007BCC48;
}

// 0x00489CD0
void __stdcall sub_00489CD0(int nUnused1)
{
}

// 0x0048BDF0
void __stdcall sub_0048BDF0(int nUnused1)
{
}

// 0x00494FB0
void __stdcall sub_00494FB0(int nUnused1)
{
}

// 0x0049C160
int __cdecl sub_0049C160()
{
    return gdwGlobal_007BF024;
}

// 0x0049E8A0
int __cdecl sub_0049E8A0()
{
    return gdwGlobal_007BF1F6;
}

// 0x0049F900
int __cdecl sub_0049F900()
{
    return gdwGlobal_007BF250;
}

// 0x004A8A20
int __cdecl sub_004A8A20()
{
    return 7;
}

// 0x004747C0
static __declspec(noinline) void __stdcall sub_004747C0_AddGridLight(int nIntensity, unsigned char nRed, unsigned char nGreen, unsigned char nBlue, int nY, int nX)
{
    const int nGridX = (nX >> 3) - gnGlobal_007B0A54;
    if ((unsigned int)nGridX > 0x2F)
    {
        return;
    }

    const int nGridY = (nY >> 3) - gnGlobal_007B0A58;
    if ((unsigned int)nGridY > 0x2F)
    {
        return;
    }

    D2GridCellStrc* pCell = &gtGridCells_007B0E68[nGridY * 48 + nGridX];
    const int nOld = pCell->nValue0;
    const unsigned int nNew = LIGHT_MIN((unsigned int)(nOld + nIntensity), 0xFFu);

    if (gnGlobal_00712B8C)
    {
        const unsigned int nRecip = gdwReciprocals_007B0A68[nNew];
        int nR = (pCell->nValue1 * nOld + nRed * nIntensity) * nRecip >> 0x10;
        if (nR > 0xFF)
        {
            nR = 0xFF;
        }
        int nG = (pCell->f_6 * nOld + nGreen * nIntensity) * nRecip >> 0x10;
        if (nG > 0xFF)
        {
            nG = 0xFF;
        }
        int nB = (pCell->nValue3 * nOld + nBlue * nIntensity) * nRecip >> 0x10;
        if (nB > 0xFF)
        {
            nB = 0xFF;
        }
        pCell->nValue0 = (unsigned char)nNew;
        pCell->nValue1 = (unsigned char)nR;
        pCell->f_6 = (unsigned char)nG;
        pCell->nValue3 = (unsigned char)nB;
    }
    else
    {
        pCell->nValue1 = 0;
        pCell->f_6 = 0;
        pCell->nValue3 = 0;
        pCell->nValue0 = (unsigned char)nNew;
    }
}

void __stdcall sub_P08_Emit_004747C0(D2P08LightSourceStrc* pSource, int nX, int nY, int nIntensity)
{
    if (nIntensity > 0)
    {
        sub_004747C0_AddGridLight(nIntensity, pSource->nRed, pSource->nGreen, pSource->nBlue, nY, nX);
    }
}

// 0x00474A70
static __declspec(noinline) void sub_00474A70_BuildOverrideWindow(D2R01LightStrc* pLight)
{
    const int nStartX = pLight->nX - (pLight->nX & 7) - pLight->nRadius;
    const int nStartY = pLight->nY - (pLight->nY & 7) - pLight->nRadius;
    const int nOffset = 0x20 - (pLight->nRadius >> 3);
    const int nSpan = (pLight->nRadius * 2) >> 3;
    for (int j = 0; j <= nSpan; ++j)
    {
        const int nY = nStartY + j * 8;
        unsigned int* pCell = &gdwLightOverrideRows_007ACA50[nOffset + j][nOffset];
        int nX = nStartX;
        for (int i = 0; i <= nSpan; ++i)
        {
            *pCell++ = sub_00474A30_IsCellBlocked(nX, nY) << 4;
            nX += 8;
        }
    }
}

void sub_M241_Emit_00474D70(D2R01LightStrc* pLight)
{
    sub_00474A70_BuildOverrideWindow(pLight);
}

// 0x004758D0
void __cdecl sub_004758D0_FreeAllLights()
{
    D2LightStrc* pLight = gpLights_007B5668;
    while (pLight)
    {
        D2LightStrc* pNext = pLight->pNext;
        if (pLight->pData)
        {
            FOG_Free(pLight->pData, ".\\DRAW\\dLightMap.cpp", 1405, 0);
        }
        FOG_Free(pLight, ".\\DRAW\\dLightMap.cpp", 1407, 0);
        pLight = pNext;
    }

    gpLights_007B5668 = 0;
}
