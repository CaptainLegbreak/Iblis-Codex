#include "D2Drlg.h"
#include "D2DrlgPresets.h"
#include "D2Path.h"
#include "D2Structs.h"
struct D2DrlgCoordStrc;
union D2SeedStrc;
struct D2CoordStrc;
struct D2DrlgLinkStrc;
struct D2DrlgLevelLinkDataStrc;







extern const D2CoordStrc gOutdoorOrthOffsets[4]; // 0x006F1F7C

// 0x0067D7B0
static inline void sub_0067D7B0(D2DrlgCoordStrc* pCoords, int nType)
{
    switch (nType)
    {
    case 0:
        pCoords->nWidth = 0x40;
        pCoords->nHeight = 0xA0;
        break;

    case 1:
        pCoords->nWidth = 0xA0;
        pCoords->nHeight = 0x40;
        break;
    }
}

void __stdcall sub_M129_Emit_0067D7B0(D2DrlgCoordStrc* pCoords, int nType)
{
    sub_0067D7B0(pCoords, nType);
}

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

// 0x0067D830
int __fastcall DRLGOUTROOM_LinkLevelsByLevelCoords(D2DrlgLevelLinkDataStrc* pLevelLinkData)
{
    D2DrlgLinkStrc* const& pLinks = pLevelLinkData->pLink;
    int nRand = SEED_RollRandomNumber(&pLevelLinkData->pSeed) & 1;

    pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = nRand;
    pLevelLinkData->nRand[1][pLevelLinkData->nIteration] = nRand;

    D2DrlgCoordStrc* pCoord = &pLevelLinkData->pLevelCoord[pLevelLinkData->nIteration];
    sub_0067D7B0(pCoord, nRand);

    const int nIteration = pLevelLinkData->nIteration;
    D2DrlgCoordStrc* pLinkCoord = &pLevelLinkData->pLevelCoord[pLinks[nIteration].nLevelLink];
    pCoord->nPosX = pLinkCoord->nPosX - pCoord->nWidth;
    pCoord->nPosY = pLinkCoord->nHeight - pCoord->nHeight + pLinkCoord->nPosY - 16;

    return 1;
}

static __forceinline void __fastcall DRLGOUTROOM_GetOrthCoords(D2DrlgCoordStrc* pCoords, int nRand, D2DrlgCoordStrc* pLinkCoords, int nLinkRand)
{
    sub_0067D7B0(pCoords, nRand);

    const int nIndex = nRand + 2 * nLinkRand;
    pCoords->nPosX = gOutdoorOrthOffsets[nIndex].nX + pLinkCoords->nPosX;
    pCoords->nPosY = gOutdoorOrthOffsets[nIndex].nY + pLinkCoords->nPosY;
}

// 0x0067D980
int __fastcall DRLGOUTROOM_LinkLevelsByOffsetCoords(D2DrlgLevelLinkDataStrc* pLevelLinkData)
{
    if (pLevelLinkData->nRand[1][pLevelLinkData->nIteration] == -1)
    {
        pLevelLinkData->nRand[1][pLevelLinkData->nIteration] = SEED_RollRandomNumber(&pLevelLinkData->pSeed) & 1;
        pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = pLevelLinkData->nRand[1][pLevelLinkData->nIteration];
    }
    else
    {
        const int bRand0IsNull = pLevelLinkData->nRand[0][pLevelLinkData->nIteration] == 0;
        if (bRand0IsNull == pLevelLinkData->nRand[1][pLevelLinkData->nIteration])
        {
            return 0;
        }

        pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = bRand0IsNull;
    }

    const int nLevelLink = pLevelLinkData->pLink[pLevelLinkData->nIteration].nLevelLink;
    DRLGOUTROOM_GetOrthCoords(&pLevelLinkData->pLevelCoord[pLevelLinkData->nIteration], pLevelLinkData->nRand[0][pLevelLinkData->nIteration],
        &pLevelLinkData->pLevelCoord[nLevelLink], pLevelLinkData->nRand[0][nLevelLink]);

    return 1;
}

#include "gen/data/Source/D2Common/Unknown_0067D7B0.inc"
