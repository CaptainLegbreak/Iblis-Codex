#include "D2Client.h"
#include "D2Structs.h"
#include "D2ClientGame.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define M341_ROLL_SEED_LOW(pSeed, nOut)                                                                     \
    {                                                                                                       \
        const unsigned __int64 lSeed = (pSeed)->nHighSeed + 0x6AC690C5i64 * (pSeed)->nLowSeed;              \
        (pSeed)->nLowSeed = (unsigned int)lSeed;                                                            \
        (pSeed)->nHighSeed = (unsigned int)(lSeed >> 32);                                                   \
        nOut = (unsigned int)lSeed;                                                                         \
    }
struct D2WeatherLayerStateStrc;
union D2SeedStrc;
struct D2WeatherSplashStrc;
struct T00473470;
struct D2WeatherLineStrc;
struct D2PeriodLightStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);




D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();
int __stdcall D2GFX_CheckPerspective(); // 0x004F51D0
int __fastcall sub_00472280(D2SeedStrc* pSeed, int nOffset, int nRange); // 0x00472280
int __fastcall sub_006BCB40(D2WeatherStrc* pArray);

struct D2WeatherLineStrc
{
    int nX1;
    int nY1;
    int nX2;
    int nY2;
};
int __cdecl sub_0045AE90(); // 0x0045AE90
int __cdecl sub_004F5210(); // 0x004F5210
void __stdcall D2GFX_DrawLine(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha); // 0x004F6380
extern D2WeatherLineStrc gaWeatherLines_006D6E78[]; // 0x006D6E78
extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_00711470; // 0x00711470
extern D2WeatherStrc* gpWeather_007A8A04; // 0x007A8A04
extern int gbWeatherSplash_007A8A14; // 0x007A8A14
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
void __fastcall sub_00473A70(D2WeatherStrc* pWeather, D2WeatherLayerStateStrc* pState); // 0x00473A70
extern D2WeatherStrc* gpWeather_007A89FC; // 0x007A89FC
extern D2WeatherStrc* gpWeather_007A8A00; // 0x007A8A00
extern D2WeatherLayerStateStrc gtWeatherLayer_007A89B0; // 0x007A89B0
extern D2WeatherLayerStateStrc gtWeatherLayer_007A893C; // 0x007A893C
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);
void __fastcall sub_004B99A0_MoveSound(int a1, int a2, int a3, int a4); // 0x004B99A0
extern "C" void __cdecl sub_004736C0_DrawPanelShade(); // 0x004736C0
void __cdecl sub_00473470(); // 0x00473470
extern int gnGlobal_007A8A08; // 0x007A8A08
extern unsigned int gdwGlobal_007BB390; // 0x007BB390

extern "C" double __cdecl fabs(double x);
int __cdecl sub_004F5140(); // 0x004F5140
D2ActiveRoomStrc* __cdecl sub_004646A0_GetPlayerRoom(); // 0x004646A0
int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime); // 0x0061C100
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
int __cdecl sub_0044DB00(); // 0x0044DB00
void __fastcall sub_00472C80_StepSplashes(int nUnused); // 0x00472C80
void __fastcall sub_00472D10_StepBubbles(int nUnused); // 0x00472D10
void __stdcall sub_00473E50_StepPhase(D2SeedStrc* pSeed); // 0x00473E50
extern D2DrlgActStrc* gpDrlgAct_007A0634; // 0x007A0634
extern const D2PeriodLightStrc gtPeriodLight_006D6E40[]; // 0x006D6E40
extern unsigned char gnOutdoorLight_007A89EC[]; // 0x007A89EC
extern unsigned char gnPeriodLight_007A898C[]; // 0x007A898C
extern unsigned char gnParticleColor_007A894C[]; // 0x007A894C
extern unsigned char gnParticleColor_007A8980[]; // 0x007A8980
extern unsigned char gnParticleColor_007A89A4[]; // 0x007A89A4
extern int gnViewDeltaX_007A0678; // 0x007A0678
extern int gnViewDeltaY_007A067C; // 0x007A067C
extern unsigned int gnWeatherTick_007A8A34; // 0x007A8A34
extern int gnGlobal_007A8968; // 0x007A8968
extern int gnGlobal_007A89E8; // 0x007A89E8

D2WeatherStrc* gpWeather_007A89FC; // 0x007A89FC

// 0x00472DA0
void __fastcall sub_00472DA0_CreateSplash(int nX, int nY, int nFixX, int nFixY)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2_ASSERT(pPlayer, 0x2D2);

    D2SeedStrc* pSeed = &pPlayer->pSeed;
    const int nRecord = sub_006BCB40(gpWeather_007A89FC);
    if (nRecord == -1)
        return;

    D2WeatherSplashStrc* pSplash = &gpWeather_007A89FC->pRecords[(short)(nRecord >> 16)];
    if (D2GFX_CheckPerspective())
    {
        pSplash->nX = (sub_00472280(pSeed, 0, 5) << 16) + nFixX;
        pSplash->nY = (sub_00472280(pSeed, 0, 5) << 16) + nFixY;
    }
    else
    {
        const int nRoll = sub_00472280(pSeed, 0, 0x50);
        int nDist = nRoll - 0x28;
        if (nDist < 0)
            nDist = -nDist;
        const int nSpread = 0x50 - (nDist << 1);
        pSplash->nX = sub_00472280(pSeed, -nSpread, 2 * nSpread) + nX;
        pSplash->nY = nRoll + nY;
    }

    unsigned int nLow;
    M341_ROLL_SEED_LOW(pSeed, nLow);
    pSplash->nType = (nLow & 1) + 2;
    D2_ASSERT(pSplash->nType >= 0 && pSplash->nType < 4, 0x2EA);
    pSplash->nFrame = 0;
    pSplash->f_14 = 2;
}

D2WeatherStrc* gpWeather_007A8A00; // 0x007A8A00

// 0x00472EC0
void __fastcall sub_00472EC0_CreateBubble(int nX, int nY, int nFixX, int nFixY)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2_ASSERT(pPlayer, 0x2FC);

    D2SeedStrc* pSeed = &pPlayer->pSeed;
    const int nRecord = sub_006BCB40(gpWeather_007A8A00);
    if (nRecord == -1)
        return;

    D2WeatherSplashStrc* pBubble = &gpWeather_007A8A00->pRecords[(short)(nRecord >> 16)];
    int nNewY;
    if (D2GFX_CheckPerspective())
    {
        pBubble->nX = ((sub_00472280(pSeed, 0, 5) - 2) << 16) + nFixX;
        nNewY = ((sub_00472280(pSeed, 0, 5) - 2) << 16) + nFixY;
    }
    else
    {
        const int nRoll = sub_00472280(pSeed, 0, 0x50);
        int nDist = nRoll - 0x28;
        if (nDist < 0)
            nDist = -nDist;
        const int nSpread = 0x50 - (nDist << 1);
        pBubble->nX = sub_00472280(pSeed, -nSpread, 2 * nSpread) + nX;
        nNewY = nRoll + nY - 0x1E;
    }
    pBubble->nY = nNewY;

    pBubble->nType = 2;
    pBubble->nFrame = 0;
    pBubble->f_14 = 2;
}

// 0x00473470
void __cdecl sub_00473470()
{
    if (sub_004F5210())
        return;

    int nLeft = 0;
    int nRight = gnGlobal_0071146C;
    int nBottom = gnGlobal_00711470 - 47;
    switch (sub_0045AE90())
    {
    case 1:
        nRight -= gnGlobal_0071146C / 4 * 2;
        break;
    case 2:
        nLeft = gnGlobal_0071146C / 4 * 2;
        break;
    }

    T00473470* pParticle = gpWeather_007A8A04->pParticles;
    for (int i = 0; i <= gpWeather_007A8A04->nLastParticle; ++i, ++pParticle)
    {
        if (!pParticle->bActive)
            continue;

        if (gbWeatherSplash_007A8A14)
        {
            if (pParticle->nX >= nLeft && pParticle->nX < nRight && pParticle->nY >= 0 && pParticle->nY < nBottom && pParticle->nParam < 8 && pParticle->nParam >= 0)
            {
                const D2WeatherLineStrc* pLine = &gaWeatherLines_006D6E78[pParticle->nParam];
                D2GFX_DrawLine(pParticle->nX + pLine->nX1, pParticle->nY + pLine->nY1, pParticle->nX + pLine->nX2, pParticle->nY + pLine->nY2, pParticle->nColor, pParticle->nAlpha);
                pLine = &gaWeatherLines_006D6E78[pParticle->nParam + 1];
                D2GFX_DrawLine(pParticle->nX + pLine->nX1, pParticle->nY + pLine->nY1, pParticle->nX + pLine->nX2, pParticle->nY + pLine->nY2, pParticle->nColor, pParticle->nAlpha);
            }
        }
        else if (pParticle->bDrop)
        {
            if (pParticle->nX >= nLeft && pParticle->nX < nRight && pParticle->nY >= 0 && pParticle->nY < nBottom)
                D2GFX_DrawLine(pParticle->nX, pParticle->nY, pParticle->nX, pParticle->nY, pParticle->nColor, pParticle->nAlpha);
        }
        else
        {
            int nDX = (int)(sub_0040B330_Cos(gnWeatherAngle_007A89C4) * pParticle->nParam);
            int nDY = (int)(sub_0040B350_Sin(gnWeatherAngle_007A89C4) * pParticle->nParam);
            const int nY0 = pParticle->nY;
            const int nRange = pParticle->nYEnd - nY0;
            if (nDY > nRange)
            {
                nDX = nRange * nDX / nDY;
                nDY = nRange;
            }
            const int nX1 = pParticle->nX + nDX;
            const int nY1 = nY0 + nDY;
            if ((pParticle->nX >= nLeft && pParticle->nX < nRight && nY0 >= 0 && nY0 < nBottom)
                || (nX1 >= nLeft && nX1 < nRight && nY1 >= 0 && nY1 < nBottom))
                D2GFX_DrawLine(pParticle->nX, nY0, nX1, nY1, pParticle->nColor, pParticle->nAlpha);
        }
    }
}

#include "gen/data/Source/D2Client/Unknown_00472DA0.inc"

int gnGlobal_007A8A10; // 0x007A8A10

// 0x00473770
int __cdecl sub_00473770_IsMudLevel()
{
    D2UnitStrc* pUnit = sub_00463DE0_GetPlayerUnit();
    int bMud = 0;
    if (pUnit)
    {
        const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
        DATATBLS_GetRainFromLevelsTxt(nLevelId);
        bMud = DATATBLS_GetMudFromLevelsTxt(nLevelId) != 0;
    }
    return bMud;
}

// 0x00473C00
void __cdecl sub_00473C00_DrawWeatherLayers()
{
    if (gpWeather_007A89FC->nCount)
    {
        sub_00473A70(gpWeather_007A89FC, &gtWeatherLayer_007A89B0);
    }
    if (gpWeather_007A8A00->nCount)
    {
        sub_00473A70(gpWeather_007A8A00, &gtWeatherLayer_007A893C);
    }
}

// 0x00473C40
int __cdecl sub_00473C40_IsRainLevel()
{
    if (gbWeatherSplash_007A8A14)
    {
        return 0;
    }
    D2UnitStrc* pUnit = sub_00463DE0_GetPlayerUnit();
    int bRain = 0;
    if (pUnit)
    {
        const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
        bRain = DATATBLS_GetRainFromLevelsTxt(nLevelId) != 0;
        DATATBLS_GetMudFromLevelsTxt(nLevelId);
    }
    return bRain;
}

// 0x00473C80
float __cdecl sub_00473C80_GetPhaseLevel()
{
    return gfPhaseLevel_007A89A0;
}

// 0x00473C90
void __fastcall sub_00473C90_SetGlobal(int nValue)
{
    gnGlobal_007A8A10 = nValue;
}

// 0x00473CE0
void __cdecl sub_00473CE0_Nop()
{
}

// 0x00473CF0
void __cdecl sub_00473CF0_Nop()
{
}

int gnGlobal_007A8968; // 0x007A8968

int gnGlobal_007A896C; // 0x007A896C

int gnGlobal_007A89E8; // 0x007A89E8

// 0x00473910
void __cdecl sub_00473910_UpdateWeather()
{
    D2UnitStrc* pUnit = sub_00463DE0_GetPlayerUnit();
    int bRain = 0;
    if (pUnit)
    {
        const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
        bRain = DATATBLS_GetRainFromLevelsTxt(nLevelId) != 0;
        DATATBLS_GetMudFromLevelsTxt(nLevelId);
    }

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2_ASSERT(pPlayer, 0x573);

    D2SeedStrc* pSeed = &pPlayer->pSeed;
    if (gnGlobal_007A8A08 && gnGlobal_007A89E8)
    {
        gnGlobal_007A89E8 -= 1;
        if (!gnGlobal_007A89E8)
        {
            if (!gnGlobal_007A896C)
            {
                gnGlobal_007A8968 = 3;
                gnGlobal_007A896C = 1;
            }
            else
            {
                gnGlobal_007A8968 = sub_00472280(pSeed, 500, 1500);
                gnGlobal_007A896C = 0;
                if (gnGlobal_00712B4C)
                {
                    const int nDelay = sub_00472280(pSeed, 25, 50);
                    const int hSound = sub_004B9A00(0xCA, 0, nDelay, 0, 0);
                    if (hSound)
                    {
                        sub_004B99A0_MoveSound(hSound, sub_00472280(pSeed, -200, 400), sub_00472280(pSeed, -200, 400), 0);
                    }
                }
                else
                {
                    gnGlobal_00712B4C = 1;
                }
            }
        }

        if (gdwGlobal_007BB390 >= 10)
        {
            sub_004736C0_DrawPanelShade();
            return;
        }
    }

    if (bRain && gpWeather_007A8A04->nCount)
    {
        sub_00473470();
    }
}

static int gnGlobal_007A8A18; // 0x007A8A18

unsigned int gnLastTick_007A8A0C; // 0x007A8A0C

int gbRainActive_007A8A44; // 0x007A8A44

int gbMudActive_007A8A40; // 0x007A8A40

static __forceinline unsigned __int64 sub_U01_RollSeedInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static __forceinline void sub_U01_StepSeedInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
}

static void __stdcall sub_00472FB0_GetPeriodLight(unsigned char* pOut2, int nValue, unsigned char* pOut1)
{
    int n = sub_004F5140();
    int bFlag;
    if (n > 0 && (n <= 3 || n == 6))
    {
        bFlag = 0;
    }
    else
    {
        bFlag = 1;
    }

    DUNGEON_GetLevelIdFromRoom(sub_004646A0_GetPlayerRoom());
    int nPeriod = ENVIRONMENT_GetPeriodOfDayFromAct(gpDrlgAct_007A0634, 0);
    D2_ASSERT(nPeriod >= 0 && nPeriod <= 3, 0x356);

    if (pOut1)
    {
        *pOut1 = gtPeriodLight_006D6E40[nPeriod].nLight;
    }

    if (pOut2)
    {
        int nIndex = nValue * 12 / 8;
        if (bFlag)
        {
            *pOut2 = gnOutdoorLight_007A89EC[nIndex];
            return;
        }

        switch (nPeriod)
        {
        case 1:
        case 3:
            nIndex /= 2;
            break;
        case 2:
            nIndex /= 4;
            break;
        }
        *pOut2 = gnPeriodLight_007A898C[nIndex];
    }
}

static void sub_00473090_InitParticle(D2SeedStrc* pSeed)
{
    const int nRecord = sub_006BCB40(gpWeather_007A8A04);
    if (nRecord == -1)
    {
        return;
    }

    T00473470* pParticle = &gpWeather_007A8A04->pParticles[(short)(nRecord >> 0x10)];
    pParticle->bDrop = 0;
    pParticle->nX = sub_00472280(pSeed, 0, gnGlobal_0071146C);
    pParticle->nYEnd = sub_00472280(pSeed, 0x28, gnGlobal_00711470 - 0x57);
    pParticle->nY = sub_00472280(pSeed, -0x14, pParticle->nYEnd + 0x14);
    sub_U01_StepSeedInline(pSeed);
    pParticle->nFrame = pSeed->nLowSeed & 0x1FF;

    const float fRatio = (float)(pParticle->nYEnd - 0x28) / (gnGlobal_00711470 - 0x57);
    if (gbWeatherSplash_007A8A14)
    {
        pParticle->nAlpha = 0xFF;
        unsigned char* pAlpha = &pParticle->nAlpha;
        sub_U01_RollSeedInline(pSeed);
        pParticle->nType = 1;
        pParticle->nParam2 = 8 - (int)(fRatio * -28.0);
        pParticle->nParam = 7 * (pParticle->nYEnd - 0x28) / (gnGlobal_00711470 - 0x57);
        if (gnGlobal_007A8A18)
        {
            ++pParticle->nParam;
        }

        D2_ASSERT(pParticle->nParam < 8 && pParticle->nParam >= 0, 0x390);
        sub_00472FB0_GetPeriodLight(&pParticle->nColor, pParticle->nParam, pAlpha);
        return;
    }

    const unsigned int nColor = (unsigned int)sub_U01_RollSeedInline(pSeed) % 12;
    switch (ENVIRONMENT_GetPeriodOfDayFromAct(gpDrlgAct_007A0634, 0))
    {
    case 2:
        pParticle->nColor = gnParticleColor_007A89A4[nColor];
        pParticle->nAlpha = 0xFF;
        break;

    case 1:
    case 3:
        pParticle->nColor = gnParticleColor_007A894C[nColor];
        pParticle->nAlpha = 0xFF;
        break;

    case 0:
        pParticle->nColor = gnParticleColor_007A8980[nColor];
        pParticle->nAlpha = 0x7F;
        break;
    }

    pParticle->nParam = 4 - (int)(fRatio * -8.0);
    pParticle->nParam2 = 0xF - (int)(fRatio * -15.0);
    pParticle->nType = 3;
}

void __stdcall sub_004732C0_StepParticles(D2SeedStrc* pSeed)
{
    float fScale;
    if (gbWeatherSplash_007A8A14)
    {
        const float fCos = (float)fabs(sub_0040B330_Cos(gnWeatherAngle_007A89C4));
        fScale = fCos;
        if (0.25f > fScale)
        {
            fScale = 0.25f;
        }
    }
    else
    {
        fScale = gfPhaseLevel_007A89A0 * 0.15f + 0.85f;
    }

    T00473470* pParticle = gpWeather_007A8A04->pParticles;
    for (int i = 0; i <= gpWeather_007A8A04->nLastParticle; ++i, ++pParticle)
    {
        if (!pParticle->bActive)
        {
            continue;
        }

        const int nSpeed = (int)(pParticle->nParam2 * fScale);
        const float fSpeed = (float)nSpeed;
        int nDeltaX = (int)(sub_0040B330_Cos(gnWeatherAngle_007A89C4) * fSpeed);
        const int nDeltaY = (int)(sub_0040B350_Sin(gnWeatherAngle_007A89C4) * fSpeed);
        pParticle->nY += nDeltaY - gnViewDeltaY_007A067C;
        if (pParticle->nY > pParticle->nYEnd)
        {
            pParticle->bDrop = 1;
        }

        if (pParticle->bDrop)
        {
            if (!pParticle->nType)
            {
                sub_006BCCD0_FreeDataArraySlot(gpWeather_007A8A04, i << 16);
                if (gpWeather_007A8A04->nCount < gnPhaseLevel_007A89E0)
                {
                    sub_00473090_InitParticle(pSeed);
                }
            }
            else
            {
                nDeltaX = 0;
                pParticle->nParam2 = 0;
                --pParticle->nType;
            }
        }

        if (!pParticle->bActive)
        {
            continue;
        }

        if (gbWeatherSplash_007A8A14 && !pParticle->bDrop)
        {
            nDeltaX += (int)(2 * sub_0040B350_Sin((pParticle->nFrame + (gnWeatherTick_007A8A34 << 9) / 25) & 0x1FF));
        }

        pParticle->nX += nDeltaX - gnViewDeltaX_007A0678;
        if (pParticle->nX >= gnGlobal_0071146C)
        {
            pParticle->nX -= gnGlobal_0071146C;
        }

        if (pParticle->nX < 0)
        {
            pParticle->nX += gnGlobal_0071146C;
        }
    }

    ++gnWeatherTick_007A8A34;
}

static void sub_004737B0_StepWind(D2SeedStrc* pSeed)
{
    while (gpWeather_007A8A04->nCount < gnPhaseLevel_007A89E0)
    {
        sub_00473090_InitParticle(pSeed);
    }

    const int nTarget = gnTargetAngle_007A89F8;
    int nAngle = gnWeatherAngle_007A89C4;
    const int bSplash = gbWeatherSplash_007A8A14;
    const int nStep = bSplash ? 1 : 2;
    if (nTarget < nAngle)
    {
        nAngle -= nStep;
        gnWeatherAngle_007A89C4 = nTarget > nAngle ? nTarget : nAngle;
    }
    else if (nTarget > nAngle)
    {
        nAngle += nStep;
        gnWeatherAngle_007A89C4 = nTarget < nAngle ? nTarget : nAngle;
    }

    if (!--gnWindCountdown_007A89E4)
    {
        if (bSplash)
        {
            gnWindCountdown_007A89E4 = (unsigned int)sub_U01_RollSeedInline(pSeed) % 875 + 250;
            gnTargetAngle_007A89F8 = sub_00472280(pSeed, gnGlobal_007A89D8, gnGlobal_007A8998);
        }
        else
        {
            gnWindCountdown_007A89E4 = (unsigned int)sub_U01_RollSeedInline(pSeed) % 375 + 125;
            gnTargetAngle_007A89F8 = (unsigned int)sub_U01_RollSeedInline(pSeed) % 71 + 92;
        }
    }

    if (gnGlobal_007A8A08 && !--gnGlobal_007A8968)
    {
        gnGlobal_007A89E8 = 1;
    }
}

// 0x00473F50
void __cdecl sub_00473F50_UpdateWeather()
{
    int nLevelId;
    int bRain;
    int bMud;
    D2UnitStrc* pStoredUnit = sub_00463DE0_GetPlayerUnit();
    bRain = 0;
    bMud = 0;
    if (pStoredUnit)
    {
        nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pStoredUnit));
        bRain = DATATBLS_GetRainFromLevelsTxt(nLevelId) != 0;
        bMud = DATATBLS_GetMudFromLevelsTxt(nLevelId) != 0;
    }

    if (!bRain && gbRainActive_007A8A44)
    {
        if (gpWeather_007A8A04->nCount)
        {
            sub_006BCAC0_ResetDataArray(gpWeather_007A8A04);
        }

        if (gpWeather_007A89FC->nCount)
        {
            sub_006BCAC0_ResetDataArray(gpWeather_007A89FC);
        }
    }

    if (!bMud && gbMudActive_007A8A40)
    {
        if (gpWeather_007A8A00->nCount)
        {
            sub_006BCAC0_ResetDataArray(gpWeather_007A8A00);
        }
    }

    gbRainActive_007A8A44 = bRain;
    gbMudActive_007A8A40 = bMud;

    const unsigned int nTick = sub_0044DB00();
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2_ASSERT(pPlayer, 0x547);

    D2SeedStrc* pSeed = &pPlayer->pSeed;
    if (nTick <= gnLastTick_007A8A0C)
    {
        return;
    }

    gnLastTick_007A8A0C = nTick;
    if (bRain)
    {
        if (gpWeather_007A8A04->nCount)
        {
            sub_004732C0_StepParticles(pSeed);
        }

        sub_00472C80_StepSplashes((int)pSeed);
        sub_00473E50_StepPhase(pSeed);
        sub_004737B0_StepWind(pSeed);
    }
    else
    {
        gfPhaseLevel_007A89A0 = 0.0f;
    }

    if (bMud)
    {
        sub_00472D10_StepBubbles((int)pSeed);
    }
}
