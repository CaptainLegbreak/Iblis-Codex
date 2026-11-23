#include "D2LevelIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2ClientTypes.h"
#include "D2ClientGame.h"

union D2SeedStrc;
struct D2WeatherSplashStrc;
struct D2WeatherLayerStateStrc;

D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0
D2ActiveRoomStrc* __cdecl sub_004646A0_GetPlayerRoom(); // 0x004646A0
int __fastcall sub_00472280(D2SeedStrc* pSeed, int nOffset, int nRange); // 0x00472280
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
extern int gnBaseWindAngleMax; // 0x007A899C
extern int gnPhaseMax; // 0x007A89C0
extern int gnBaseWindAngleMin; // 0x007A89DC
extern int gbWeatherSplash; // 0x007A8A14

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

extern int gnScreenWidth; // 0x0071146C
extern int gnScreenHeight; // 0x00711470

static int gbLightningEnabled; // 0x007A8A08

static inline unsigned int sub_00472400_SeedStep(D2SeedStrc* pSeed)
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
    case LEVEL_HARROGATH:
    case LEVEL_BLOODYFOOTHILLS:
    case LEVEL_ID_ACT5_BARRICADE_1:
    case LEVEL_ARREATPLATEAU:
        gnBaseWindAngleMin = 42;
// build: symbol ?gnWindAngleMin@* 0x007A89D8
        gnWindAngleMin = 42;
        gnBaseWindAngleMax = 170;
// build: symbol ?gnWindAngleMax@* 0x007A8998
        gnWindAngleMax = 170;
// build: symbol ?gnPhaseLevel@* 0x007A89E0
        gnPhaseLevel = gnPhaseMax = sub_00472280(pSeed, 0x20, 0x38);
        return;

    case LEVEL_TUNDRAWASTELANDS:
        gnWindAngleMin = 170;
        gnWindAngleMax = 56;
        gnBaseWindAngleMin = 28;
        gnBaseWindAngleMax = 56;
        gnPhaseLevel = gnPhaseMax = sub_00472280(pSeed, 0x20, 0x70);
        return;

    case LEVEL_ROCKYSUMMIT:
    case LEVEL_NIHLATHAKSTEMPLE:
        gnWindAngleMin = 28;
        gnWindAngleMax = 28;
        gnBaseWindAngleMin = 28;
        gnBaseWindAngleMax = 28;
// build: symbol ?gnTargetAngle@* 0x007A89F8
        gnTargetAngle = 28;
// build: symbol ?gnWeatherAngle@* 0x007A89C4
        gnWeatherAngle = 28;
        gnPhaseMax = 0x100;
        gnPhaseLevel = 0x100;
        return;
    }

    gnPhaseLevel = gnPhaseMax;
    if (!gbWeatherSplash)
    {
        sub_00472400_SeedStep(pSeed);
        gbLightningEnabled = 0;
    }
    else
    {
        gbLightningEnabled = 0;
    }
}

// 0x00473A70
void __fastcall sub_00473A70(D2WeatherStrc* pWeather, D2WeatherLayerStateStrc* pState)
{
    const int bPerspective = D2GFX_CheckPerspective();
    int nOffset = 0;
    int nLeft = 0;
    int nRight = gnScreenWidth;
    int nBottom = gnScreenHeight - 47;
    switch (sub_0045AE90())
    {
    case 1:
    {
        const int nQuarter = gnScreenWidth / 4;
        nOffset = -nQuarter;
        nRight -= nQuarter * 2;
        break;
    }
    case 2:
        nOffset = gnScreenWidth / 4;
        nLeft = gnScreenWidth / 4 * 2;
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
