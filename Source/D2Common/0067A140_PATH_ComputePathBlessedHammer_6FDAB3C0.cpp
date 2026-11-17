struct D2UnitStrc;

struct D2PathPointStrc
{
    unsigned short X;
    unsigned short Y;
};

union D2SeedStrc
{
    struct
    {
        unsigned int nLowSeed;
        unsigned int nHighSeed;
    };
    unsigned __int64 lSeed;
};

union D2FP32_16
{
    struct
    {
        unsigned short wOffsetX;
        unsigned short wPosX;
        unsigned short wOffsetY;
        unsigned short wPosY;
    };

    struct
    {
        unsigned int dwPrecisionX;
        unsigned int dwPrecisionY;
    };
};

struct D2DynamicPathStrc
{
    D2FP32_16 tGameCoords;
    char unk0x08[0x20];
    int dwPathPoints;
    char unk0x2C[0x70];
    D2PathPointStrc PathPoints[78];
};

float __stdcall sub_0040B330_Cos(int nAngle); // 0x0040B330
float __stdcall sub_0040B350_Sin(int nAngle); // 0x0040B350

// 0x0067A140
int __fastcall PATH_ComputePathBlessedHammer_6FDAB3C0(D2DynamicPathStrc* pPath, D2SeedStrc* pSeed)
{
    D2FP32_16 tCenter = pPath->tGameCoords;
    D2FP32_16 tPrevious = tCenter;
    int nAngle = 0;
    int nRadius = 0;
    int nPoints = 0;

    do
    {
        nRadius += 0x2580;
        nAngle += 16;
        float fRadius = (float)nRadius;
        unsigned int nX = (unsigned int)(sub_0040B330_Cos(nAngle) * fRadius) + tCenter.dwPrecisionX;
        unsigned int nY = (unsigned int)(sub_0040B350_Sin(nAngle) * fRadius) + tCenter.dwPrecisionY;
        if ((unsigned short)(nX >> 16) != (unsigned short)(tPrevious.dwPrecisionX >> 16) || (nY >> 16) != (unsigned short)(tPrevious.dwPrecisionY >> 16))
        {
            tPrevious.dwPrecisionX = nX;
            tPrevious.dwPrecisionY = nY;
            pPath->PathPoints[nPoints].X = (unsigned short)(nX >> 16);
            pPath->PathPoints[nPoints].Y = (unsigned short)(nY >> 16);
            ++nPoints;
        }
    }
    while (nPoints < 77);

    pPath->dwPathPoints = nPoints;
    return nPoints;
}
