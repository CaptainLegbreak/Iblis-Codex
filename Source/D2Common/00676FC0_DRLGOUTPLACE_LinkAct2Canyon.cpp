struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2DrlgCoordStrc
{
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
};

struct D2DrlgLinkStrc
{
    void* pfLinker;
    int nLevel;
    int nLevelLink;
    int nLevelLinkEx;
};

struct D2DrlgLevelLinkDataStrc
{
    D2SeedStrc pSeed;
    D2DrlgCoordStrc pLevelCoord[15];
};

struct D2DrlgOutdoorInfoStrc
{
    unsigned int dwFlags;
};

struct D2DrlgLevelStrc
{
    int nDrlgType;
    char unk0x004[0x10];
    D2DrlgOutdoorInfoStrc* pOutdoors;
    char unk0x018[0x1B8];
    int nLevelId;
};

struct D2UnkOutdoorStrc3
{
    int nLevelId;
    int nIgnoredLevel1;
    int nIgnoredLevel2;
    int nRand;
    int nNextRand;
    int nFlags;
};

#define DRLGTYPE_OUTDOOR 3

extern D2DrlgLinkStrc gAct2CanyonDrlgLink[15];                                                              // 0x006F0A20
extern D2DrlgLinkStrc gAct5UbersDrlgLink[15];                                                               // 0x006F0B10
extern D2DrlgLinkStrc gAct4OutdoorDrlgLink[15];                                                             // 0x006F0C00
extern D2DrlgLinkStrc gAct4ChaosSanctumDrlgLink[15];                                                        // 0x006F0CF0
extern const D2UnkOutdoorStrc3 stru_6FDD06C0[15];                                                           // 0x006F1258
int __fastcall DRLG_CheckNotOverlappingUsingManhattanDistance(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int nMaxDistance); // 0x0066B860

// 0x00676FC0
int __fastcall DRLGOUTPLACE_LinkAct2Canyon(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration)
{
    int nLevelLink = gAct2CanyonDrlgLink[nIteration].nLevelLink;

    for (int i = 0; i < nIteration; ++i)
    {
        if (i != nLevelLink && !DRLG_CheckNotOverlappingUsingManhattanDistance(&pLevelLinkData->pLevelCoord[nIteration], &pLevelLinkData->pLevelCoord[i], 0))
        {
            return 0;
        }
    }

    return 1;
}

// 0x00677030
int __fastcall DRLGOUTPLACE_LinkAct5Ubers(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration)
{
    int nLevelLink = gAct5UbersDrlgLink[nIteration].nLevelLink;

    for (int i = 0; i < nIteration; ++i)
    {
        if (i != nLevelLink && !DRLG_CheckNotOverlappingUsingManhattanDistance(&pLevelLinkData->pLevelCoord[nIteration], &pLevelLinkData->pLevelCoord[i], 0))
        {
            return 0;
        }
    }

    return 1;
}

// 0x006770A0
int __fastcall DRLGOUTPLACE_LinkAct4Outdoors(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration)
{
    int nLevelLink = gAct4OutdoorDrlgLink[nIteration].nLevelLink;

    for (int i = 0; i < nIteration; ++i)
    {
        if (i != nLevelLink && !DRLG_CheckNotOverlappingUsingManhattanDistance(&pLevelLinkData->pLevelCoord[nIteration], &pLevelLinkData->pLevelCoord[i], 0))
        {
            return 0;
        }
    }

    return 1;
}

// 0x00677110
int __fastcall DRLGOUTPLACE_LinkAct4ChaosSanctum(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration)
{
    int nLevelLink = gAct4ChaosSanctumDrlgLink[nIteration].nLevelLink;

    for (int i = 0; i < nIteration; ++i)
    {
        if (i != nLevelLink && !DRLG_CheckNotOverlappingUsingManhattanDistance(&pLevelLinkData->pLevelCoord[nIteration], &pLevelLinkData->pLevelCoord[i], 0))
        {
            return 0;
        }
    }

    return 1;
}

// 0x00677180
void __fastcall sub_00677180_SetAct1OutdoorFlags(D2DrlgLevelStrc* pLevel, int nIteration, int* pRand)
{
    if (pLevel->nDrlgType == DRLGTYPE_OUTDOOR)
    {
        D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
        for (int i = 0; i < 15; ++i)
        {
            if (pLevel->nLevelId == stru_6FDD06C0[i].nLevelId || !stru_6FDD06C0[i].nLevelId)
            {
                if (pLevel->nLevelId != stru_6FDD06C0[i].nIgnoredLevel1 && pLevel->nLevelId != stru_6FDD06C0[i].nIgnoredLevel2 && pRand[nIteration] == stru_6FDD06C0[i].nRand)
                {
                    if (pRand[nIteration + 1] == stru_6FDD06C0[i].nNextRand)
                    {
                        pOutdoors->dwFlags |= stru_6FDD06C0[i].nFlags;
                    }
                }
            }
        }
    }
}

#include "gen/data/Source/D2Common/00676FC0_DRLGOUTPLACE_LinkAct2Canyon.inc"
