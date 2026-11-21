#include "D2LevelIds.h"
#include "D2Path.h"
#include "D2DrlgTiles.h"
#include "D2Drlg.h"
#include "D2DrlgPresets.h"

typedef int (__fastcall* DRLGLINKFN)(D2DrlgLevelLinkDataStrc* pLevelLinkData);

struct D2DrlgOrthStrc;


struct D2DrlgLevelLinkDataStrc;



struct D2DrlgWarpStrc;

typedef int (__fastcall* LINKFN)(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration);
typedef void (__fastcall* FLAGFN)(D2DrlgLevelStrc* pLevel, int nIteration, int* pRand);

#define DRLGTYPE_PRESET 2
#define DRLGTYPE_OUTDOOR 3

D2DrlgLevelStrc* __stdcall DRLG_GetLevel(D2DrlgStrc* pDrlg, int nLevelId);                                  // 0x00642BB0
D2LevelDefBin* __fastcall DATATBLS_GetLevelDefRecord(int nLevelId);                                         // 0x0061E470
D2DrlgWarpStrc* __fastcall DRLG_GetDrlgWarpFromLevelId(D2DrlgStrc* pDrlg, int nLevelId);                    // 0x00642860
D2DrlgWarpStrc* __fastcall DRLG_SetWarpId(D2DrlgWarpStrc* pDrlgWarp, int nVis, int nWarp, int nShift);      // 0x00642920
int __fastcall DRLG_CheckOverlappingWithOrthogonalMargin(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int nMargin); // 0x0066B880
int __fastcall DRLG_GetDirectionFromCoordinates(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2); // 0x00642240
int* __fastcall DRLGWARP_GetWarpIdArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId);                        // 0x0066AEC0
int* __fastcall DRLGROOM_GetVisArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId);                           // 0x0066C040
void __fastcall DRLGROOM_AddOrth(D2DrlgOrthStrc** ppDrlgOrth, D2DrlgLevelStrc* pLevel, int nDirection, int bIsPreset); // 0x0066B790

int __fastcall sub_00676DD0_LinkAct1Wilderness(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration);    // 0x00676DD0
int __fastcall sub_6FD82130(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration);                       // 0x00676EB0
int __fastcall DRLGOUTPLACE_LinkAct2Outdoors(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration);      // 0x00676F50
int __fastcall DRLGOUTPLACE_LinkAct2Canyon(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration);        // 0x00676FC0
int __fastcall DRLGOUTPLACE_LinkAct5Ubers(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration);         // 0x00677030
int __fastcall DRLGOUTPLACE_LinkAct4Outdoors(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration);      // 0x006770A0
int __fastcall DRLGOUTPLACE_LinkAct4ChaosSanctum(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration);  // 0x00677110
void __fastcall sub_00677180_SetAct1OutdoorFlags(D2DrlgLevelStrc* pLevel, int nIteration, int* pRand);      // 0x00677180

extern D2DrlgLinkStrc gAct1WildernessDrlgLink[15];                                                          // 0x006F0750
extern D2DrlgLinkStrc gAct1MonasteryDrlgLink[15];                                                           // 0x006F0840
extern D2DrlgLinkStrc gAct2OutdoorDrlgLink[15];                                                             // 0x006F0930
extern D2DrlgLinkStrc gAct2CanyonDrlgLink[15];                                                              // 0x006F0A20
extern D2DrlgLinkStrc gAct5UbersDrlgLink[15];                                                               // 0x006F0B10
extern D2DrlgLinkStrc gAct4OutdoorDrlgLink[15];                                                             // 0x006F0C00
extern D2DrlgLinkStrc gAct4ChaosSanctumDrlgLink[15];                                                        // 0x006F0CF0
extern D2DrlgLinkStrc gAct5OutdoorDrlgLink[15];                                                             // 0x006F0DE0
extern D2DrlgLinkStrc gAct5TundraDrlgLink[15];                                                              // 0x006F0ED0
extern int dword_6FDEA6FC;                                                                                  // 0x0096D66C

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

static void __stdcall sub_006772C0_InitLevelLinks(D2DrlgLinkStrc* pDrlgLink, LINKFN pfLink, FLAGFN pfFlag, D2DrlgStrc* pDrlg)
{
    D2DrlgLevelLinkDataStrc pLevelLinkData = {};
    D2LevelDefBin* pLevelDefBinRecord = 0;
    D2DrlgPresetInfoStrc* pPresetInfo = 0;
    D2DrlgWarpStrc* pDrlgWarp1 = 0;
    D2DrlgWarpStrc* pDrlgWarp2 = 0;
    D2DrlgLevelStrc* pLevel = 0;
    int nLevelId = 0;
    int nCounter = 0;
    int nVisEx = 0;
    int nVis = 0;

    for (int i = 0; i < 15; ++i)
    {
        pLevelLinkData.nRand[2][i] = -1;
        pLevelLinkData.nRand[3][i] = -1;
        pLevelLinkData.nRand[0][i] = -1;
        pLevelLinkData.nRand[1][i] = -1;
    }

    pLevelLinkData.pSeed = pDrlg->pSeed;
    pLevelLinkData.pLink = pDrlgLink;

    for (int i = 0; pDrlgLink[i].nLevel; ++i)
    {
        pLevelDefBinRecord = DATATBLS_GetLevelDefRecord(pDrlgLink[i].nLevel);

        pLevelLinkData.pLevelCoord[i].nWidth = pLevelDefBinRecord->dwSizeX[pDrlg->nDifficulty];
        pLevelLinkData.pLevelCoord[i].nHeight = pLevelDefBinRecord->dwSizeY[pDrlg->nDifficulty];
    }

    nCounter = 0;
    while (pDrlgLink[nCounter].nLevel)
    {
        pLevelLinkData.nIteration = nCounter;
        pLevelLinkData.nCurrentLevel = pDrlgLink[nCounter].nLevel;

        if (!((DRLGLINKFN)pDrlgLink[nCounter].pfLinker)(&pLevelLinkData))
        {
            pLevelLinkData.nRand[2][nCounter] = -1;
            pLevelLinkData.nRand[3][nCounter] = -1;
            pLevelLinkData.nRand[0][nCounter] = -1;
            pLevelLinkData.nRand[1][nCounter] = -1;

            --nCounter;
        }
        else if (!pfLink || pfLink(&pLevelLinkData, nCounter))
        {
            ++nCounter;
        }
    }

    for (int i = 0; pDrlgLink[i].nLevel; ++i)
    {
        nLevelId = pDrlgLink[i].nLevel;

        if (pDrlgLink[i].nLevelLink != -1)
        {
            nVis = pDrlgLink[pDrlgLink[i].nLevelLink].nLevel;
        }
        else
        {
            nVis = 0;
        }

        if (pDrlgLink[i].nLevelLinkEx != -1)
        {
            nVisEx = pDrlgLink[pDrlgLink[i].nLevelLinkEx].nLevel;
        }
        else
        {
            nVisEx = 0;
        }

        pLevel = DRLG_GetLevel(pDrlg, nLevelId);

        pLevel->pLevelCoords.nPosX = pLevelLinkData.pLevelCoord[i].nPosX;
        pLevel->pLevelCoords.nPosY = pLevelLinkData.pLevelCoord[i].nPosY;
        pLevel->pLevelCoords.nWidth = pLevelLinkData.pLevelCoord[i].nWidth;
        pLevel->pLevelCoords.nHeight = pLevelLinkData.pLevelCoord[i].nHeight;

        if (pLevel->nDrlgType == DRLGTYPE_PRESET)
        {
            switch (pLevel->eLevelId)
            {
            case 1:
                pLevel->pPreset->nDirection = pLevelLinkData.nRand[0][i];
                break;
            case 0x28:
                pLevel->pPreset->nDirection = pLevelLinkData.nRand[0][i + 1];
                break;
            }
        }

        if (pLevel->eLevelId == LEVEL_BLACKMARSH)
        {
            pPresetInfo = DRLG_GetLevel(pDrlg, LEVEL_OUTERCLOISTER)->pPreset;
            switch (pLevelLinkData.nRand[0][i])
            {
            case 1:
                pPresetInfo->nDirection = ((unsigned char)SEED_RollRandomNumber(&pDrlg->pSeed) & 1) ? 1 : 2;
                break;
            case 3:
                pPresetInfo->nDirection = ~(unsigned char)SEED_RollRandomNumber(&pDrlg->pSeed) & 1;
                break;
            }
        }

        if (pfFlag)
        {
            pfFlag(pLevel, i, pLevelLinkData.nRand[0]);
        }

        if (pDrlg->nAct != 4)
        {
            if (nVis)
            {
                pDrlgWarp1 = DRLG_GetDrlgWarpFromLevelId(pDrlg, nLevelId);
                pDrlgWarp2 = DRLG_GetDrlgWarpFromLevelId(pDrlg, nVis);
                DRLG_SetWarpId(pDrlgWarp1, nVis, -1, -1);
                DRLG_SetWarpId(pDrlgWarp2, nLevelId, -1, -1);
            }

            if (nVisEx)
            {
                pDrlgWarp1 = DRLG_GetDrlgWarpFromLevelId(pDrlg, nLevelId);
                pDrlgWarp2 = DRLG_GetDrlgWarpFromLevelId(pDrlg, nVisEx);
                DRLG_SetWarpId(pDrlgWarp1, nVisEx, -1, -1);
                DRLG_SetWarpId(pDrlgWarp2, nLevelId, -1, -1);
            }
        }
    }
}

// 0x006775C0
static void __stdcall sub_006775C0_SetOverlapWarps(int nStartId, int nEndId, D2DrlgStrc* pDrlg)
{
    for (int i = nStartId; i <= nEndId; ++i)
    {
        D2DrlgLevelStrc* pLevel = DRLG_GetLevel(pDrlg, i);
        D2DrlgWarpStrc* pDrlgWarp = DRLG_GetDrlgWarpFromLevelId(pDrlg, i);

        for (int j = nStartId; j <= nEndId; ++j)
        {
            if (i != j)
            {
                D2DrlgLevelStrc* pOtherLevel = DRLG_GetLevel(pDrlg, j);
                if (DRLG_CheckOverlappingWithOrthogonalMargin(&pLevel->pLevelCoords, &pOtherLevel->pLevelCoords, -1))
                {
                    DRLG_SetWarpId(pDrlgWarp, j, -1, -1);
                }
            }
        }
    }
}

static __forceinline void sub_00677640_AddOrthToLevel(D2DrlgLevelStrc* pLevel, int nLevelId)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    D2DrlgLevelStrc* pWarpLevel = DRLG_GetLevel(pLevel->pDrlg, nLevelId);
    const int nDirection = DRLG_GetDirectionFromCoordinates(&pLevel->pLevelCoords, &pWarpLevel->pLevelCoords);
    DRLGROOM_AddOrth(&pOutdoors->pRoomData, pWarpLevel, nDirection, pWarpLevel->nDrlgType == DRLGTYPE_PRESET);
}

// 0x00677680
static void __stdcall sub_00677680_AddLevelOrths(D2DrlgStrc* pDrlg, int nEndId, int nStartId)
{
    for (int i = nStartId; i <= nEndId; ++i)
    {
        D2DrlgLevelStrc* pLevel = DRLG_GetLevel(pDrlg, i);

        if (pLevel->nDrlgType == DRLGTYPE_OUTDOOR)
        {
            int* pVisArray = DRLGROOM_GetVisArrayFromLevelId(pDrlg, i);
            int* pWarpIdArray = DRLGWARP_GetWarpIdArrayFromLevelId(pDrlg, i);

            for (int j = 0; j < 8; ++j)
            {
                if (pVisArray[j] && pWarpIdArray[j] == -1)
                {
                    sub_00677640_AddOrthToLevel(pLevel, pVisArray[j]);
                }
            }
        }
    }
}

static __declspec(noinline) void sub_00677750_CreateAct1LevelConnections(D2DrlgStrc* pDrlg);
static __declspec(noinline) void sub_00677790_CreateAct2LevelConnections(D2DrlgStrc* pDrlg);
static __declspec(noinline) void sub_006789B0_CreateAct3LevelConnections(D2DrlgStrc* pDrlg);
static __declspec(noinline) void sub_00678A20_CreateAct4LevelConnections(D2DrlgStrc* pDrlg);
static __declspec(noinline) void sub_00678A70_CreateAct5LevelConnections(D2DrlgStrc* pDrlg);

static void sub_00677750_CreateAct1LevelConnections(D2DrlgStrc* pDrlg); // 0x00677750
static void sub_00677790_CreateAct2LevelConnections(D2DrlgStrc* pDrlg); // 0x00677790
static void sub_006789B0_CreateAct3LevelConnections(D2DrlgStrc* pDrlg); // 0x006789B0
static void sub_00678A20_CreateAct4LevelConnections(D2DrlgStrc* pDrlg); // 0x00678A20
static void sub_00678A70_CreateAct5LevelConnections(D2DrlgStrc* pDrlg); // 0x00678A70

// 0x00677750
static void sub_00677750_CreateAct1LevelConnections(D2DrlgStrc* pDrlg)
{
    sub_006772C0_InitLevelLinks(gAct1WildernessDrlgLink, sub_00676DD0_LinkAct1Wilderness, sub_00677180_SetAct1OutdoorFlags, pDrlg);
    sub_006772C0_InitLevelLinks(gAct1MonasteryDrlgLink, sub_6FD82130, sub_00677180_SetAct1OutdoorFlags, pDrlg);
    sub_00677680_AddLevelOrths(pDrlg, 0x11, 1);
}

// 0x00677790
static void sub_00677790_CreateAct2LevelConnections(D2DrlgStrc* pDrlg)
{
    sub_006772C0_InitLevelLinks(gAct2OutdoorDrlgLink, DRLGOUTPLACE_LinkAct2Outdoors, 0, pDrlg);
    sub_006772C0_InitLevelLinks(gAct2CanyonDrlgLink, DRLGOUTPLACE_LinkAct2Canyon, 0, pDrlg);
    sub_00677680_AddLevelOrths(pDrlg, 0x2E, 0x28);
}

// calling-convention shim (not game code)
static void sub_006789B0_CreateAct3LevelConnections(D2DrlgStrc* pDrlg)
{
    sub_006772C0_InitLevelLinks(gAct2OutdoorDrlgLink, 0, 0, pDrlg);
    sub_00677680_AddLevelOrths(pDrlg, 0x50, 0x4B);
}

// 0x00678A20
static void sub_00678A20_CreateAct4LevelConnections(D2DrlgStrc* pDrlg)
{
    sub_006772C0_InitLevelLinks(gAct4OutdoorDrlgLink, DRLGOUTPLACE_LinkAct4Outdoors, 0, pDrlg);
    sub_006772C0_InitLevelLinks(gAct4ChaosSanctumDrlgLink, DRLGOUTPLACE_LinkAct4ChaosSanctum, 0, pDrlg);

    DRLG_GetLevel(pDrlg, LEVEL_OUTERSTEPPES)->pOutdoors->dwFlags |= dword_6FDEA6FC;

    sub_00677680_AddLevelOrths(pDrlg, 0x6A, 0x67);
}

// 0x00678A70
static void sub_00678A70_CreateAct5LevelConnections(D2DrlgStrc* pDrlg)
{
    sub_006772C0_InitLevelLinks(gAct5OutdoorDrlgLink, 0, 0, pDrlg);
    sub_006772C0_InitLevelLinks(gAct5TundraDrlgLink, 0, 0, pDrlg);

    sub_006775C0_SetOverlapWarps(0x6F, 0x70, pDrlg);
    sub_00677680_AddLevelOrths(pDrlg, 0x70, 0x6F);

    sub_006775C0_SetOverlapWarps(0x6E, 0x6F, pDrlg);
    sub_006775C0_SetOverlapWarps(0x6D, 0x6E, pDrlg);

    sub_006772C0_InitLevelLinks(gAct5UbersDrlgLink, DRLGOUTPLACE_LinkAct5Ubers, 0, pDrlg);
}

// 0x00678AD0
void __fastcall DRLGOUTPLACE_CreateLevelConnections(D2DrlgStrc* pDrlg, unsigned char nAct)
{
    switch (nAct)
    {
    case 0:
        sub_00677750_CreateAct1LevelConnections(pDrlg);
        break;
    case 1:
        sub_00677790_CreateAct2LevelConnections(pDrlg);
        break;
    case 2:
        sub_006789B0_CreateAct3LevelConnections(pDrlg);
        break;
    case 3:
        sub_00678A20_CreateAct4LevelConnections(pDrlg);
        break;
    case 4:
        sub_00678A70_CreateAct5LevelConnections(pDrlg);
        break;
    }
}
