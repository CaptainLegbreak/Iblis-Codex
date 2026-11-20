#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2UnitData.h"

#define STARS_ROLL(pSeed, lSeed) ((lSeed) = (pSeed)->nHighSeed + 0x6AC690C5i64 * (pSeed)->nLowSeed, \
    (pSeed)->nHighSeed = (unsigned int)((lSeed) >> 32), (pSeed)->nLowSeed = (unsigned int)(lSeed), (unsigned int)(lSeed))

struct D2SeedStrc;
struct D2PlayerDataStrc;
struct D2QuestLookupEntryStrc;
struct D2QuestPanelValuesStrc;
struct D2WardenClientM114Strc;


extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
void __fastcall SEED_InitSeed(D2SeedStrc* pSeed); // 0x00650E30
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40
int __fastcall SEED_GetRandomValue(int nValue); // 0x00650DE0
void __stdcall D2GFX_DrawLine(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha); // 0x004F6380
void __stdcall sub_00476190_ResetStar(int nStar, int bRespawn);
extern D2SeedStrc* gpClientSeed_00712C4C; // 0x00712C4C




struct D2QuestLookupEntryStrc
{
    int nKey;
    int nValue;
    int unk0x08;
    int unk0x0C;
};

#pragma pack(push, 1)
struct D2QuestPanelValuesStrc
{
    char unk0x00[0x7];
    int nValues[0x96];
};

#pragma pack(pop)
struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    union
    {
        struct
        {
            unsigned short nWParamLo;
            short nWParamHi;
        };
        unsigned int wParam;
    };
    union
    {
        struct
        {
            unsigned short nXpos;
            unsigned short nYpos;
        };
        unsigned int lParam;
    };
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern void* const gapWardenServices_006D8E68[7]; // 0x006D8E68
extern D2QuestLookupEntryStrc gaQuestLookup_00723F38[0x29]; // 0x00723F38

struct D2WardenClientM114Strc
{
    void* const* pServices;
    D2WardenClientM114Strc();
};

int gnGlobal_007B8D10; // 0x007B8D10

int gbStarsInit_007B955C; // 0x007B955C

unsigned char gaStarShades_007B8D24[8]; // 0x007B8D24

int gaStarX_007B8D30[256]; // 0x007B8D30

int gaStarY_007B57E8[256]; // 0x007B57E8

unsigned char gaStarColor_007B5688[256]; // 0x007B5688

int gaStarSpeed_007B9130[256]; // 0x007B9130

unsigned long gdwStarTick_007B57E0; // 0x007B57E0

// 0x00476290
void __cdecl sub_00476290_DrawStarfield()
{
    if (!gbStarsInit_007B955C)
    {
        SEED_InitSeed(gpClientSeed_00712C4C);
        SEED_InitLowSeed(gpClientSeed_00712C4C, SEED_GetRandomValue(gnGlobal_007B8D10));

        for (int nShade = 0; nShade < 8; ++nShade)
        {
            const int nBase = nShade * 0x80 / 7 + 0x80;
            D2SeedStrc* pSeed = gpClientSeed_00712C4C;
            unsigned __int64 lSeed;
            int nRed = (STARS_ROLL(pSeed, lSeed) & 0x3F) + nBase - 0x20;
            if (nRed > 0xFF)
                nRed = 0xFF;
            int nGreen = (STARS_ROLL(pSeed, lSeed) & 0x3F) + nBase - 0x20;
            if (nGreen > 0xFF)
                nGreen = 0xFF;
            int nBlue = (STARS_ROLL(pSeed, lSeed) & 0x3F) + nBase - 0x20;
            if (nBlue > 0xFF)
                nBlue = 0xFF;
            gaStarShades_007B8D24[nShade] = sub_004FB180_FindPaletteIndex(nRed, nGreen, nBlue);
        }

        for (int i = 0; i < 256; ++i)
            sub_00476190_ResetStar(i, 0);

        gbStarsInit_007B955C = 1;
    }

    for (int i = 0; i < 256; ++i)
        D2GFX_DrawLine(gaStarX_007B8D30[i], gaStarY_007B57E8[i], gaStarX_007B8D30[i], gaStarY_007B57E8[i], gaStarColor_007B5688[i], 0xFF);

    const unsigned long dwTick = GetTickCount();
    if (dwTick - gdwStarTick_007B57E0 > 40)
    {
        for (int i = 0; i < 256; ++i)
        {
            gaStarX_007B8D30[i] += gaStarSpeed_007B9130[i];
            if (gaStarX_007B8D30[i] < 0)
                sub_00476190_ResetStar(i, 1);
        }
        gdwStarTick_007B57E0 = dwTick;
    }
}

#include "gen/data/Source/D2Client/GAME/View_00476290.inc"

int gnGlobal_007B9564; // 0x007B9564

static int gnGlobal_007BEECC; // 0x007BEECC

static int gnPopupX_007BEED4; // 0x007BEED4

// 0x004801C0
D2WardenClientM114Strc::D2WardenClientM114Strc() : pServices(gapWardenServices_006D8E68)
{
}

// 0x00480400
int __fastcall sub_00480400_GetPlayerField150(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 0 && pUnit->pPlayerData)
    {
        return pUnit->pPlayerData->nState;
    }
    return 0;
}

// 0x004804D0
unsigned int __cdecl sub_004804D0_GetPingScaled()
{
    return (sub_0044CE60_GetPing() + 0x32) >> 7;
}

// 0x004769B0
void __cdecl sub_004769B0_Toggle()
{
    gnGlobal_007B9564 = gnGlobal_007B9564 == 0;
}

// 0x004A3070
int __fastcall sub_004A3070_LookupValue(int nUnused, int nKey)
{
    for (unsigned int i = 0; i < 0x29; ++i)
    {
        if (gaQuestLookup_00723F38[i].nKey == nKey)
        {
            return gaQuestLookup_00723F38[i].nValue;
        }
    }
    return 0x2A;
}

// 0x004A3200
D2QuestPanelValuesStrc* __fastcall sub_004A3200_ClearValues(D2QuestPanelValuesStrc* pValues)
{
    for (int i = 0; i < 0x96; ++i)
    {
        pValues->nValues[i] = 0;
    }
    return pValues;
}

// 0x00492BC0
int __cdecl sub_00492BC0_GetPetTypeCount()
{
    return sgptDataTables->nPetTypeTxtRecordCount;
}

static inline int InBox(int nX, int nY, int nLeft, int nRight, int nTop, int nBottom)
{
    return nX >= nLeft && nX <= nRight && nY >= nTop && nY <= nBottom;
}

// 0x00492BD0
int __fastcall sub_00492BD0_IsInPetIcon(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    return gnGlobal_007BEECC != 2 && InBox(nX, nY, gnPopupX_007BEED4, gnPopupX_007BEED4 + 0x2E, 0x18, 0x18 + 0x24);
}

void __stdcall sub_M114_Emit_00492BD0(int nMode, int nPopupX)
{
    gnGlobal_007BEECC = nMode;
    gnPopupX_007BEED4 = nPopupX;
}
