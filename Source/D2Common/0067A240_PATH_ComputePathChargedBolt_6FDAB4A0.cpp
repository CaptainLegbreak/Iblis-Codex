struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2PathPointStrc
{
    unsigned short X;
    unsigned short Y;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2DynamicPathStrc
{
    unsigned short wOffsetX;
    unsigned short wPosX;
    unsigned short wOffsetY;
    unsigned short wPosY;
    char unk0x08[0x08];
    D2PathPointStrc tTargetCoord;
    char unk0x14[0x14];
    int dwPathPoints;
    char unk0x2C[0x65];
    unsigned char nDistMax;
    char unk0x92[0x0A];
    D2PathPointStrc PathPoints[78];
};

extern const D2CoordStrc gatDirectionToOffset[8];                                                           // 0x006F1798
void __fastcall PATH_GetDirections_6FDAB790(int* pTestDir, D2PathPointStrc pPoint1, D2PathPointStrc pPoint2); // 0x00678D70

inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x0067A240
int __fastcall PATH_ComputePathChargedBolt_6FDAB4A0(D2DynamicPathStrc* pDynamicPath, D2SeedStrc* pSeed)
{

    int dirOffsetSequence[32] = {
        -1, 0, 1,
        -1, 0, 1,
        -1, 0, 1,
        -1, 0, 1,
        -1, 0, 1,
        -1, 0, 1,
        -1, 0, 1,
        -1, 0, 1,
        -1, 0, 1,
        -1, 0, 1,
        -1,   1,
    };

    int nMaxPathPoints = pDynamicPath->nDistMax >> 1;
    int nCurPointIdx = 0;
    D2PathPointStrc nPrevPoint;
    nPrevPoint.X = pDynamicPath->wPosX;
    nPrevPoint.Y = pDynamicPath->wPosY;

    int v16[3];
    PATH_GetDirections_6FDAB790(v16, nPrevPoint, pDynamicPath->tTargetCoord);

    for (; nCurPointIdx < nMaxPathPoints; nCurPointIdx++)
    {
        unsigned int nDir = dirOffsetSequence[SEED_RollRandomNumber(pSeed) & 31];
        nDir = (v16[0] + nDir) % 8;
        pDynamicPath->PathPoints[nCurPointIdx] = nPrevPoint;
        nPrevPoint.X += 2 * gatDirectionToOffset[nDir].nX;
        nPrevPoint.Y += 2 * gatDirectionToOffset[nDir].nY;
    }

    pDynamicPath->PathPoints[nCurPointIdx] = nPrevPoint;
    nCurPointIdx += 1;
    pDynamicPath->dwPathPoints = nCurPointIdx;
    return nCurPointIdx;
}
