#include "D2Structs.h"
#include "D2Path.h"
#include "D2Drlg.h"
struct D2LvlPrestTxt;


struct D2DrlgVertexStrc
{
    int nPosX;
    int nPosY;
    unsigned char nDirection;
    unsigned int dwFlags;
    D2DrlgVertexStrc* pNext;
};



struct D2LvlPrestRecordStrc
{
    char unk0x00[0x28];
    int nSizeX;
    int nSizeY;
};

struct D2DrlgOutPlaceCtxStrc
{
    D2DrlgLevelStrc* pLevel;
    int* pUnk54;
    D2DrlgGridStrc* pGrid04;
    D2DrlgGridStrc* pGrid2C;
    int unk0x10;
    int n14;
    int n18;
    int unk0x1C;
    int unk0x20;
    int (__fastcall* pfnTest)(D2DrlgLevelStrc*, int, int, int, int, unsigned int);
    int (__fastcall* pfnGetPreset)(D2DrlgLevelStrc*, int, int);
    int (__fastcall* pfn2C)(D2DrlgLevelStrc*, int, int);
    int (__fastcall* pfn30)(D2DrlgLevelStrc*, int, int);
    void (__fastcall* pfnPlace)(D2DrlgLevelStrc*, int, int, int, int, int);
};

struct D2Act5CornerPresetStrc
{
    int nLevelId;
    int nArg;
    int f_8;
    int nPresetTall;
    int nPresetWide;
};

struct D2Act5TypeRangeStrc
{
    int nType;
    int nMin;
    int nMax;
    int nPresetA;
    int nPresetB;
};

struct D2Act5LevelPresetStrc
{
    int nLevelId;
    int nPresetTall;
    int nPresetWide;
    int nArg;
    int nUnk10;
    int nCount;
    int bRequired;
};

extern "C" const char gszEmptyAssertText;      // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY);                                     // 0x0067C570
void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlag, int eOperation);       // 0x0067C4F0
void __fastcall sub_0067D280(D2DrlgVertexStrc* pVertex, int* pDirectionX, int* pDirectionY);    // 0x0067D280
D2LvlPrestTxt* __stdcall DATATBLS_GetLvlPrestTxtRecord(int nId); // 0x0061F0B0
void __fastcall sub_006743C0(D2DrlgLevelStrc* pLevel, int nX, int nY, int nPresetId, int nDirection, int a6);
int __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPreset(D2DrlgLevelStrc* pLevel, int nLevelPrestId, int nRand, int nOffset, char nFlags); // 0x00674730
void __fastcall sub_00675770(D2DrlgLevelStrc* pLevel);
void __fastcall sub_00670750(D2DrlgOutPlaceCtxStrc* pCtx);
int __fastcall sub_006741E0(D2DrlgLevelStrc* pLevel, int nX, int nY);
int __fastcall DRLGOUTDOOR_00674120(D2DrlgLevelStrc* pLevel, int nX, int nY);
int __fastcall sub_00674160(D2DrlgLevelStrc* pLevel, int nX, int nY);
int __fastcall sub_006741A0(D2DrlgLevelStrc* pLevel, int nX, int nY);
int __fastcall DRLGOUTDOOR_006755C0(int nDirX, int nDirY, int nSize);
int __fastcall DRLGOUTDOOR_00675600(int nDirX, int nDirY, int nNextDirX, int nNextDirY, int nSize);

void sub_0067E240(D2DrlgLevelStrc* pLevel);

static const D2Act5CornerPresetStrc gAct5CornerPresets[3] =
{
    { 112, 0, 0, 913, 914 },
    { 117, 0, 1, 983, 984 },
    { 117, 0, 0, 985, 986 },
};

void DRLGACT5_PlaceCornerPresets(D2DrlgLevelStrc* pLevel);

int __stdcall sub_0067DB00(D2DrlgOutdoorInfoStrc* pInfo, int nX, int nY, D2DrlgLevelStrc* pLevel, int nPresetId);

void __stdcall sub_0067DB50(D2DrlgLevelStrc* pLevel);

void sub_0067DCA0(D2DrlgLevelStrc* pLevel);

int __fastcall sub_0067DCE0(D2DrlgLevelStrc* pLevel);

void __stdcall sub_0067DCF0(D2DrlgLevelStrc* pLevel);

static const D2CoordStrc gAct5WallSteps[12] =
{
    { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 },
    { 0, -1 }, { 1, 0 }, { 0, 1 }, { -1, 0 },
    { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 },
};

void __stdcall sub_0067DEF0(D2DrlgLevelStrc* pLevel);

static const D2Act5TypeRangeStrc gAct5TypeRanges[10] =
{
    { 49, 1, 16, 915, 987 },
    { 49, 31, 46, 915, 987 },
    { 48, 1, 1, 883, 959 },
    { 48, 2, 3, 881, 957 },
    { 48, 4, 4, 884, 960 },
    { 48, 5, 5, 895, 971 },
    { 48, 6, 7, 893, 969 },
    { 48, 8, 8, 896, 972 },
    { 48, 30, 30, 0, 0 },
    { 48, 31, 31, -5, -5 },
};

int __fastcall sub_0067E000(D2DrlgLevelStrc* pLevel, int nType, int nIndex);

int __fastcall sub_0067E080(D2DrlgLevelStrc* pLevel, int nX, int nY, int nPresetId, int nUnused, unsigned int dwCellFlags);

void sub_0067E0E0(D2DrlgLevelStrc* pLevel);

static const D2Act5LevelPresetStrc gAct5LevelPresets[15] = // 0x006F2100
{
    { 111, 955, 956, 0, 25, 1, 1 },
    { 112, 955, 956, 0, 25, 1, 1 },
    { 117, 955, 956, 1, 25, 1, 1 },
    { 112, 953, 953, -1, 25, 1, 1 },
    { 117, 954, 954, -1, 25, 1, 1 },
    { 111, 944, 947, -1, 10, 1, 0 },
    { 111, 942, 945, -1, 20, 4, 0 },
    { 111, 943, 946, -1, 20, 4, 0 },
    { 112, 941, 941, -1, 10, 1, 0 },
    { 112, 939, 939, -1, 8, 1, 0 },
    { 112, 940, 940, -1, 15, 5, 0 },
    { 117, 948, 948, -1, 9, 4, 0 },
    { 117, 949, 949, -1, 9, 4, 0 },
    { 117, 950, 950, -1, 9, 4, 0 },
    { 117, 951, 951, -1, 5, 3, 0 },
};

// 0x0067E160
void __stdcall sub_0067E160(D2DrlgLevelStrc* pLevel)
{
    int bTall = pLevel->nWidth < pLevel->nHeight;
    for (int i = 0; i < 15; ++i)
    {
        if (pLevel->eLevelId == gAct5LevelPresets[i].nLevelId)
        {
            int nPresetId;
            if (bTall)
            {
                nPresetId = gAct5LevelPresets[i].nPresetTall;
            }
            else
            {
                nPresetId = gAct5LevelPresets[i].nPresetWide;
            }

            int nArg = gAct5LevelPresets[i].nArg;
            int bPlaced = 0;
            for (int j = 0; j < gAct5LevelPresets[i].nCount; ++j)
            {
                bPlaced = DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, nPresetId, nArg, 0, 15);
            }

            if (!(bPlaced || !gAct5LevelPresets[i].bRequired))
            {
                sub_00408A60(&gszEmptyAssertText, sub_00408090(), 537);
                exit(-1);
            }
        }
    }
}

int DRLGACT5_ReplaceTransitionPreset(D2DrlgLevelStrc* pLevel, int nX, int nY);

void sub_0067E4B0(D2DrlgLevelStrc* pLevel);

void __stdcall sub_0067E560(D2DrlgLevelStrc* pLevel);

void __fastcall sub_0067E600(D2DrlgLevelStrc* pLevel);
