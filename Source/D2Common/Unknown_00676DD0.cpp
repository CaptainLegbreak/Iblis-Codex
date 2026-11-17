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
    D2DrlgLinkStrc* pLink;
    int nRand[4][15];
    int nIteration;
    int nCurrentLevel;
};

#define LEVEL_ROGUEENCAMPMENT 1
#define LEVEL_BURIALGROUNDS 17

extern D2DrlgLinkStrc gAct1WildernessDrlgLink[15];                                                          // 0x006F0750
extern const int gnAct1WildernessLinkTable[];                                                               // 0x006F1158
int __fastcall DRLG_CheckNotOverlappingUsingManhattanDistance(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int nMaxDistance); // 0x0066B860

// 0x00676DD0
int __fastcall sub_00676DD0_LinkAct1Wilderness(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration)
{
    int nCounter = 0;
    int nLevelLink = gAct1WildernessDrlgLink[nIteration].nLevelLink;

    while (nCounter < nIteration)
    {
        if (nCounter != nLevelLink && !DRLG_CheckNotOverlappingUsingManhattanDistance(&pLevelLinkData->pLevelCoord[nIteration], &pLevelLinkData->pLevelCoord[nCounter], 0))
        {
            return 0;
        }

        ++nCounter;
    }

    switch (gAct1WildernessDrlgLink[nIteration].nLevel)
    {
    case LEVEL_ROGUEENCAMPMENT:
        return gnAct1WildernessLinkTable[pLevelLinkData->nRand[0][nIteration] + 4 * (pLevelLinkData->nRand[2][nIteration] + 2 * (pLevelLinkData->nRand[0][nLevelLink] + 4 * pLevelLinkData->nRand[2][nLevelLink]))];

    case LEVEL_BURIALGROUNDS:
        for (int i = 0; i < 15; ++i)
        {
            if (i != nIteration && gAct1WildernessDrlgLink[i].nLevelLink == nLevelLink && pLevelLinkData->nRand[0][nIteration] == pLevelLinkData->nRand[0][i])
            {
                return 0;
            }
        }
        break;
    }

    return 1;
}

#include "gen/data/Source/D2Common/Unknown_00676DD0.inc"
