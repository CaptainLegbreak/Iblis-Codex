#include "D2Client.h"
#include "D2Structs.h"
#include "D2ClientTypes.h"

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                     // 0x006CC260
extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);
void __fastcall SEED_InitSeed(D2SeedStrc* pSeed);                                                            // 0x00650E30
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                  // 0x00650E40
int __fastcall SEED_GetRandomValue(int nValue);                                                              // 0x00650DE0
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                           // 0x0045C390
D2CelFileStrc* __fastcall sub_004788B0(const char* szFile, int nType);                               // 0x004788B0
int __stdcall D2GFX_GetResolutionMode();                                                                     // 0x004F5160
void __stdcall TEXTURE_CelDraw(D2GfxDataStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette); // 0x004F6480
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit);                                                      // 0x00620650

extern int gdwGlobal_007A0620;                                                                               // 0x007A0620
extern int gnAutomapWidth_007A5220;                                                                          // 0x007A5220
extern D2SeedStrc* gpSkySeed_00712C50;                                                                       // 0x00712C50
static int gnSummitScroll_007B9568;                                                                          // 0x007B9568
static D2CelFileStrc* gpSummitCel_007B9554;                                                                  // 0x007B9554
static D2CelFileStrc* gpCloudCel_007B9558;                                                                   // 0x007B9558
static bool gbCloudsInit_007B9560;                                                                           // 0x007B9560
static int gaCloudY_007B5790[10];                                                                            // 0x007B5790
static int gaCloudSpeed_007B57B8[10];                                                                        // 0x007B57B8
static int gaCloudX_007B5BE8[10];                                                                            // 0x007B5BE8

static int snBaseX; // 0x007B9570
static bool sbBaseSet; // 0x007B956C
static int gnBaseGuard; // 0x007B9574
__declspec(noinline) static void sub_00476460_DrawSummitBackdrop(D2UnitStrc* pPlayer);
// 0x00476460
static void sub_00476460_DrawSummitBackdrop(D2UnitStrc* pPlayer)
{
    if (gdwGlobal_007A0620)
    {
        return;
    }

    if (!(gnBaseGuard & 1)) {
        gnBaseGuard |= 1;
        snBaseX = UNITS_GetClientCoordX(pPlayer);
    }
    if (!sbBaseSet)
    {
        sbBaseSet = true;
        snBaseX = 0x274F;
    }

    gnSummitScroll_007B9568 = UNITS_GetClientCoordX(pPlayer) - snBaseX;
    const int nPos = gnSummitScroll_007B9568 / 8;
    const int nOffset = nPos % 256;
    int nFrame = nPos / 256 % 4;
    while (nFrame < 0)
    {
        nFrame += 4;
    }
    nFrame %= 4;
    const int nX = -nOffset;

    if (!gpSummitCel_007B9554)
    {
        char szPath[260];
        strcpy(szPath, "data\\global\\ui\\summit01");
        gpSummitCel_007B9554 = sub_004788B0(szPath, 0);
    }

    if (!gpCloudCel_007B9558)
    {
        char szPath[260];
        strcpy(szPath, "data\\global\\ui\\cloud01");
        gpCloudCel_007B9558 = sub_004788B0(szPath, 0);
    }

    D2GfxDataStrc tGfxData = {};
    if (gpSummitCel_007B9554)
    {
        tGfxData.pCellFile = gpSummitCel_007B9554;
        tGfxData.nFrame = nFrame;
        TEXTURE_CelDraw(&tGfxData, nX, 0x100, -1, 5, 0);
        const int nFrame1 = (nFrame + 1) % 4;
        tGfxData.nFrame = nFrame1;
        TEXTURE_CelDraw(&tGfxData, nX + 0x100, 0x100, -1, 5, 0);
        const int nFrame2 = (nFrame + 2) % 4;
        tGfxData.nFrame = nFrame2;
        TEXTURE_CelDraw(&tGfxData, nX + 0x200, 0x100, -1, 5, 0);
        const int nFrame3 = (nFrame + 3) % 4;
        tGfxData.nFrame = nFrame3;
        TEXTURE_CelDraw(&tGfxData, nX + 0x300, 0x100, -1, 5, 0);
        if (nX > 0)
        {
            tGfxData.nFrame = nFrame3;
            TEXTURE_CelDraw(&tGfxData, nX - 0x100, 0x100, -1, 5, 0);
        }

        tGfxData.nFrame = nFrame + 4;
        TEXTURE_CelDraw(&tGfxData, nX, 0x200, -1, 5, 0);
        tGfxData.nFrame = nFrame1 + 4;
        TEXTURE_CelDraw(&tGfxData, nX + 0x100, 0x200, -1, 5, 0);
        tGfxData.nFrame = nFrame2 + 4;
        TEXTURE_CelDraw(&tGfxData, nX + 0x200, 0x200, -1, 5, 0);
        tGfxData.nFrame = nFrame3 + 4;
        TEXTURE_CelDraw(&tGfxData, nX + 0x300, 0x200, -1, 5, 0);
        if (nX > 0)
        {
            tGfxData.nFrame = nFrame3 + 4;
            TEXTURE_CelDraw(&tGfxData, nX - 0x100, 0x200, -1, 5, 0);
        }

        if (D2GFX_GetResolutionMode() == 2)
        {
            tGfxData.nFrame = nFrame + 8;
            TEXTURE_CelDraw(&tGfxData, nX, 0x300, -1, 5, 0);
            tGfxData.nFrame = nFrame1 + 8;
            TEXTURE_CelDraw(&tGfxData, nX + 0x100, 0x300, -1, 5, 0);
            tGfxData.nFrame = nFrame2 + 8;
            TEXTURE_CelDraw(&tGfxData, nX + 0x200, 0x300, -1, 5, 0);
            tGfxData.nFrame = nFrame3 + 8;
            TEXTURE_CelDraw(&tGfxData, nX + 0x300, 0x300, -1, 5, 0);
            if (nX > 0)
            {
                tGfxData.nFrame = nFrame3 + 8;
                TEXTURE_CelDraw(&tGfxData, nX - 0x100, 0x300, -1, 5, 0);
            }
        }
    }

    if (gpCloudCel_007B9558)
    {
        D2SeedStrc* pSeed;
        unsigned __int64 lSeed;
        int i;
        if (!gbCloudsInit_007B9560)
        {
            SEED_InitSeed(gpSkySeed_00712C50);
            SEED_InitLowSeed(gpSkySeed_00712C50, SEED_GetRandomValue(GetTickCount()));
            pSeed = gpSkySeed_00712C50;
            for (i = 0; i < 10; ++i)
            {
                gaCloudX_007B5BE8[i] = SEED_RollLimitedRandomNumber(pSeed, gnAutomapWidth_007A5220 << 4);
                gaCloudY_007B5790[i] = SUMMIT_ROLL(pSeed, lSeed) % 250;
                gaCloudSpeed_007B57B8[i] = (SUMMIT_ROLL(pSeed, lSeed) & 0xF) + 8;
            }
            gbCloudsInit_007B9560 = true;
        }
        else
        {
            pSeed = gpSkySeed_00712C50;
        }

        for (i = 0; i < 10; ++i)
        {
            gaCloudX_007B5BE8[i] += gaCloudSpeed_007B57B8[i];
            if (gaCloudX_007B5BE8[i] > (gnAutomapWidth_007A5220 + 0x170) << 4)
            {
                gaCloudX_007B5BE8[i] = -0x1700;
                gaCloudY_007B5790[i] = SUMMIT_ROLL(pSeed, lSeed) % 300;
            }
        }

        for (i = 0; i < 10; ++i)
        {
            tGfxData.pCellFile = gpCloudCel_007B9558;
            tGfxData.nFrame = 0;
            nFrame = gaCloudX_007B5BE8[i] / 16;
            TEXTURE_CelDraw(&tGfxData, nFrame, gaCloudY_007B5790[i], 0xDDDDDDDD, 3, 0);
            tGfxData.nFrame = 1;
            TEXTURE_CelDraw(&tGfxData, nFrame + 0x100, gaCloudY_007B5790[i], 0xDDDDDDDD, 3, 0);
        }
    }
}

struct D2ViewStrc
{
    char unk0x00[0x0C];
    int nField0x0C;
    int nField0x10;
    char unk0x14[0x24];
    unsigned int dwFlags;
};
struct D2TileLightCtxStrc;
struct D2CellGridViewStrc
{
    void __thiscall sub_004DF510_DrawCellNodes();                                                            // 0x004DF510
};
int __stdcall D2GFX_CheckPerspective();                                                                      // 0x004F51D0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                            // 0x00463DD0
int __stdcall UNITS_GetPrecisionX(D2UnitStrc* pUnit);                                                        // 0x006203B0
int __stdcall UNITS_GetPrecisionY(D2UnitStrc* pUnit);                                                        // 0x00620410
int __cdecl sub_0044DB00();                                                                                  // 0x0044DB00
void __cdecl sub_004DED20_UpdateRoomColor();                                                                 // 0x004DED20
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                                // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                           // 0x0061A1B0
void __cdecl sub_00476290_DrawStarfield();                                                                   // 0x00476290
void __fastcall sub_00478A00(void* pCel);                                                                    // 0x00478A00
void __fastcall sub_004DF480_UpdateAllTileLights(D2TileLightCtxStrc* pCtx);                                  // 0x004DF480
void __fastcall sub_004DED10(void* pArg);                                                                    // 0x004DED10
void __cdecl sub_00473C00_DrawWeatherLayers();                                                               // 0x00473C00
void __fastcall sub_004DF1C0(D2ViewStrc* pView);                                                             // 0x004DF1C0
void __fastcall sub_004DEA70(D2ViewStrc* pView);                                                             // 0x004DEA70
void __cdecl sub_00475B20_DebugDrawLights();                                                                 // 0x00475B20
void __cdecl sub_00473910_UpdateWeather();                                                                                 // 0x00473910
void __cdecl sub_004DC000_DrawFadeBox();                                                                     // 0x004DC000
extern int gnGlobal_007B9534;                                                                                // 0x007B9534
extern int gnGlobal_007B9538;                                                                                // 0x007B9538
extern int gnGlobal_007B8D20;                                                                                // 0x007B8D20
extern int gnGlobal_007B9564;                                                                                // 0x007B9564
extern const unsigned int gdwBitMasks[32];                                                                   // 0x006CE268

// 0x00476BC0
void __fastcall sub_00476BC0(D2ViewStrc* pView)
{
    if (!pView->nField0x0C && !pView->nField0x10)
    {
        return;
    }

    SCALE_UpdateFactor();
    gdwGlobal_007B57E4 = sub_004F65E0();
    if (D2GFX_CheckPerspective())
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        int nX = UNITS_GetPrecisionX(pPlayer);
        int nY = UNITS_GetPrecisionY(pPlayer);
        int nOffsetX = 0;
        int nOffsetY = 0;
        if (gnGlobal_007B9534)
        {
            nOffsetX = gnGlobal_007B9538 << 16;
            nOffsetY = gnGlobal_007B8D20 << 16;
            DUNGEON_ClientToGameSubtileCoords(&nOffsetX, &nOffsetY);
            nX += nOffsetX;
            nY += nOffsetY;
        }
        SCALE_SetPerspectiveScale(nX, nY);
    }

    const int nTick = sub_0044DB00();
    if (nTick > gdwLightTick_007B9530)
    {
        gdwLightTick_007B9530 = nTick;
        sub_00475800_RunLightPass();
    }

    sub_004DED20_UpdateRoomColor();
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (DUNGEON_GetLevelIdFromRoom(pRoom) == 74)
    {
        sub_00476290_DrawStarfield();
    }

    if (DUNGEON_GetLevelIdFromRoom(pRoom) == 120)
    {
        sub_00476460_DrawSummitBackdrop(pPlayer);
    }
    else
    {
        if (gpSummitCel_007B9554)
        {
            sub_00478A00(gpSummitCel_007B9554);
            gpSummitCel_007B9554 = 0;
        }
        if (gpCloudCel_007B9558)
        {
            sub_00478A00(gpCloudCel_007B9558);
            gpCloudCel_007B9558 = 0;
        }
    }

    if (pView->dwFlags & gdwBitMasks[0])
    {
        sub_004DF480_UpdateAllTileLights((D2TileLightCtxStrc*)pView);
    }
    sub_004DED10(pView);
    sub_00473C00_DrawWeatherLayers();
    if (pView->dwFlags & gdwBitMasks[3])
    {
        ((D2CellGridViewStrc*)pView)->sub_004DF510_DrawCellNodes();
    }
    sub_004DF1C0(pView);
    if (pView->dwFlags & gdwBitMasks[1])
    {
        sub_004DEA70(pView);
    }
    if (gnGlobal_007B9564)
    {
        sub_00475B20_DebugDrawLights();
    }
    SCALE_SetDefaultFactor();
    sub_00473910_UpdateWeather();
    sub_004DC000_DrawFadeBox();
}

#include "gen/data/Source/D2Client/GAME/View_00476460.inc"
