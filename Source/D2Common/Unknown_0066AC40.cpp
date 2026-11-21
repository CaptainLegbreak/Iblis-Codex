#include "D2Common.h"
#include "D2Structs.h"

struct D2DrlgStrc;

struct D2DrlgTileInfoStrc
{
    int nPosX;
    int nPosY;
    int nTileIndex;
};

struct D2TileGroupStrc
{
    int bValid;
    int nGroup;
};

struct D2DrlgLevelStrc
{
    char unk0x00[0x2C];
    D2DrlgTileInfoStrc pTileInfo[32];
    char unk0x1AC[0x08];
    D2DrlgStrc* pDrlg;
    char unk0x1B8[0x0C];
    D2SeedStrc pSeed;
    char unk0x1CC[0x0C];
    int nTileInfo;

    D2DrlgRoomStrc* sub_0066AC40_GetTileRoom(int nTileIndex, int* pX, int* pY);
};

extern D2TileGroupStrc gaTileGroups_006EED88[];                                                             // 0x006EED88
D2DrlgRoomStrc* __fastcall DRLG_GetRoomExFromCoordinates(int nX, int nY, D2DrlgStrc* pDrlg, D2DrlgRoomStrc* pRoomHint, D2DrlgLevelStrc* pLevel); // 0x00642C30

static inline int TileMatches(int nTileIndex, int nOther)
{
    return nTileIndex == nOther || (gaTileGroups_006EED88[nTileIndex].bValid && gaTileGroups_006EED88[nTileIndex].nGroup == gaTileGroups_006EED88[nOther].nGroup);
}

static inline unsigned int SEED_RollLimitedRandomNumber_Inline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    unsigned int const tNHighSeed = pSeed->nHighSeed;
    if ((nMax - 1) & nMax)
    {
        unsigned __int64 lSeed = tNHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
        pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
        pSeed->nLowSeed = (unsigned int)lSeed;
        return (unsigned int)lSeed % nMax;
    }

    unsigned __int64 lSeed = tNHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed & (nMax - 1);
}

// 0x0066AC40
D2DrlgRoomStrc* D2DrlgLevelStrc::sub_0066AC40_GetTileRoom(int nTileIndex, int* pX, int* pY)
{
    int nCount = 0;
    for (int i = 0; i < nTileInfo; ++i)
    {
        if (TileMatches(nTileIndex, pTileInfo[i].nTileIndex))
        {
            ++nCount;
        }
    }

    int nPick;
    if (nCount)
    {
        nPick = SEED_RollLimitedRandomNumber_Inline(&pSeed, nCount) + 1;
    }
    else
    {
        nPick = 0;
    }

    int i = 0;
    const D2DrlgTileInfoStrc* pInfo = pTileInfo;
    for (; i < nTileInfo; ++i, ++pInfo)
    {
        const int nTile = pInfo->nTileIndex;
        if (nTileIndex == nTile || (gaTileGroups_006EED88[nTileIndex].bValid && gaTileGroups_006EED88[nTileIndex].nGroup == gaTileGroups_006EED88[nTile].nGroup))
        {
            --nPick;
        }

        if (nPick <= 0)
        {
            break;
        }
    }

    *pX = pTileInfo[i].nPosX;
    *pY = pTileInfo[i].nPosY;
    return DRLG_GetRoomExFromCoordinates(*pX, *pY, pDrlg, 0, this);
}

#include "gen/data/Source/D2Common/Unknown_0066AC40.inc"
