#include "D2Client.h"
#include "D2Structs.h"

struct D2SeedStrc;
struct D2WeatherSplashStrc;
struct D2WeatherLayerStateStrc;



D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0
D2ActiveRoomStrc* __cdecl sub_004646A0_GetPlayerRoom(); // 0x004646A0
int __fastcall sub_00472280(D2SeedStrc* pSeed, int nOffset, int nRange); // 0x00472280
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
extern int gnGlobal_007A899C; // 0x007A899C
extern int gnPhaseMax_007A89C0; // 0x007A89C0
extern int gnGlobal_007A89DC; // 0x007A89DC
extern int gbWeatherSplash_007A8A14; // 0x007A8A14

struct D2GfxDataStrc
{
    int nFrame;
    char unk0x04[0x30];
    D2CelFileStrc* pCellFile;
    char unk0x38[0x08];
    int nDirection;
    char unk0x44[0x04];
};

struct D2WeatherStrc
{
    char unk0x000[0x110];
    int nLastParticle;
    char unk0x114[0x08];
    D2WeatherSplashStrc* pRecords;
};

struct D2WeatherLayerStateStrc
{
    D2CelFileStrc* pCelFiles[4];
};

int __stdcall D2GFX_CheckPerspective(); // 0x004F51D0
int __cdecl sub_0045AE90(); // 0x0045AE90
void __stdcall TEXTURE_CelDraw(D2GfxDataStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette); // 0x004F6480
int __stdcall SCALE_CheckPerspectivePosition(int nXPos, int nYPos); // 0x004F66E0
void __stdcall SCALE_AdjustPerspectivePosition(int nXPos, int nYPos, int nBias, int* pXAdjust, int* pYAdjust); // 0x004F6760

typedef int (__stdcall* D2CelDrawRetFn)(D2GfxDataStrc*, int, int, unsigned int, int, unsigned char*);

extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_00711470; // 0x00711470

static int gnGlobal_007A8A08; // 0x007A8A08

static __forceinline unsigned int sub_00472400_SeedStep(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x00472400
void __cdecl sub_00472400_ResetPhaseState()
{
    int nLevelId = DUNGEON_GetLevelIdFromRoom(sub_004646A0_GetPlayerRoom());
    D2SeedStrc* pSeed = &sub_00463DE0_GetPlayerUnit()->pSeed;

    switch (nLevelId)
    {
    case 109:
    case 110:
    case 111:
    case 112:
        gnGlobal_007A89DC = 42;
        gnGlobal_007A89D8 = 42;
        gnGlobal_007A899C = 170;
        gnGlobal_007A8998 = 170;
        gnPhaseLevel_007A89E0 = gnPhaseMax_007A89C0 = sub_00472280(pSeed, 0x20, 0x38);
        return;

    case 117:
        gnGlobal_007A89D8 = 170;
        gnGlobal_007A8998 = 56;
        gnGlobal_007A89DC = 28;
        gnGlobal_007A899C = 56;
        gnPhaseLevel_007A89E0 = gnPhaseMax_007A89C0 = sub_00472280(pSeed, 0x20, 0x70);
        return;

    case 120:
    case 121:
        gnGlobal_007A89D8 = 28;
        gnGlobal_007A8998 = 28;
        gnGlobal_007A89DC = 28;
        gnGlobal_007A899C = 28;
        gnTargetAngle_007A89F8 = 28;
        gnWeatherAngle_007A89C4 = 28;
        gnPhaseMax_007A89C0 = 0x100;
        gnPhaseLevel_007A89E0 = 0x100;
        return;
    }

    gnPhaseLevel_007A89E0 = gnPhaseMax_007A89C0;
    if (!gbWeatherSplash_007A8A14)
    {
        sub_00472400_SeedStep(pSeed);
        gnGlobal_007A8A08 = 0;
    }
    else
    {
        gnGlobal_007A8A08 = 0;
    }
}

// 0x00473A70
void __fastcall sub_00473A70(D2WeatherStrc* pWeather, D2WeatherLayerStateStrc* pState)
{
    const int bPerspective = D2GFX_CheckPerspective();
    int nOffset = 0;
    int nLeft = 0;
    int nRight = gnGlobal_0071146C;
    int nBottom = gnGlobal_00711470 - 47;
    switch (sub_0045AE90())
    {
    case 1:
    {
        const int nQuarter = gnGlobal_0071146C / 4;
        nOffset = -nQuarter;
        nRight -= nQuarter * 2;
        break;
    }
    case 2:
        nOffset = gnGlobal_0071146C / 4;
        nLeft = gnGlobal_0071146C / 4 * 2;
        break;
    }

    D2GfxDataStrc tGfxData = {};
    D2WeatherSplashStrc* pRecord = pWeather->pRecords;
    for (int i = 0; i <= pWeather->nLastParticle; ++i, ++pRecord)
    {
        if (!pRecord->bActive)
        {
            continue;
        }

        if (bPerspective)
        {
            if (SCALE_CheckPerspectivePosition(pRecord->nX, pRecord->nY))
            {
                int nX;
                int nY;
                SCALE_AdjustPerspectivePosition(pRecord->nX, pRecord->nY, 0, &nX, &nY);
                nX += nOffset;
                if (nX >= nLeft && nX < nRight && nY >= 0 && nY < nBottom)
                {
                    tGfxData.pCellFile = pState->pCelFiles[pRecord->nType];
                    tGfxData.nFrame = pRecord->nFrame;
                    if (((D2CelDrawRetFn)&TEXTURE_CelDraw)(&tGfxData, nX, nY, -1, 3, 0))
                    {
                        continue;
                    }
                }
            }
            sub_006BCCD0_FreeDataArraySlot(pWeather, i << 16);
        }
        else
        {
            const int nX = pRecord->nX + nOffset;
            const int nY = pRecord->nY;
            if (nX >= nLeft && nX < nRight && nY >= 0 && nY < nBottom)
            {
                tGfxData.pCellFile = pState->pCelFiles[pRecord->nType];
                tGfxData.nFrame = pRecord->nFrame;
                TEXTURE_CelDraw(&tGfxData, nX, nY, -1, 3, 0);
            }
        }
    }
}
