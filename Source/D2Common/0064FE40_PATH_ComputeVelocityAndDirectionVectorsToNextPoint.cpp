struct D2CoordStrc { int nX,nY; };
struct D2PathPointStrc { unsigned short x,y; };

union D2FP32_16 {
 struct { unsigned short wOffsetX,wPosX,wOffsetY,wPosY; };
 struct { unsigned int dwPrecisionX,dwPrecisionY; };
};
#pragma pack(push,1)
struct D2DynamicPathStrc {
 D2FP32_16 tGameCoords;
 char unk08[0x1C];
 int current,count;
 char unk2C[8];
 unsigned int flags;
 char unk38[0x32];
 D2CoordStrc direction,velocityVector;
 char unk7A[2];
 int velocity;
 char unk80[0x1C];
 D2PathPointStrc points[78];
};
#pragma pack(pop)
extern const D2CoordStrc gtZeroVector_006EB7D4; // 0x006EB7D4
void __fastcall PATH_SetDirection(D2DynamicPathStrc*,unsigned char); // 0x006485F0
// build: context PATH_ToFP16Center
static __forceinline unsigned int PATH_ToFP16Center(unsigned short nValue)
{
    return (nValue << 16) + 0x8000;
}

// build: context PATH_FromFP16
static __forceinline unsigned short PATH_FromFP16(unsigned int nValue)
{
    return (nValue >> 16) & 0xFFFF;
}

extern int gDirectionTable_006EB7E0[128 * 3];                                                               // 0x006EB7E0

static __forceinline void SwapPrecision(unsigned int& a, unsigned int& b)
{
    unsigned int temp = a;
    a = b;
    b = temp;
}

// 0x0064FC60
void __fastcall PATH_GetDirectionVector(D2CoordStrc* pDirectionVector, int* pOutDirection, D2FP32_16 tStart, D2FP32_16 tTarget)
{
    int bPositiveX;
    unsigned int dwMaxX;
    unsigned int dwMinX;
    if (tStart.dwPrecisionX <= tTarget.dwPrecisionX)
    {
        dwMaxX = tTarget.dwPrecisionX;
        dwMinX = tStart.dwPrecisionX;
        bPositiveX = 1;
    }
    else
    {
        dwMaxX = tStart.dwPrecisionX;
        dwMinX = tTarget.dwPrecisionX;
        bPositiveX = 0;
    }
    int bPositiveY;
    unsigned int dwMaxY;
    unsigned int dwMinY;
    if (tStart.dwPrecisionY <= tTarget.dwPrecisionY)
    {
        dwMaxY = tTarget.dwPrecisionY;
        dwMinY = tStart.dwPrecisionY;
        bPositiveY = 1;
    }
    else
    {
        dwMaxY = tStart.dwPrecisionY;
        dwMinY = tTarget.dwPrecisionY;
        bPositiveY = 0;
    }
    int bSwapped;
    if ((int)(dwMaxX - dwMinX) <= (int)(dwMaxY - dwMinY))
    {
        bSwapped = 0;
    }
    else
    {
        SwapPrecision(dwMaxX, dwMaxY);
        bSwapped = 1;
        SwapPrecision(dwMinX, dwMinY);
    }
    int nIndex;
    if ((int)(dwMaxY - dwMinY) != 0)
        nIndex = (int)(127 * (dwMaxX - dwMinX)) / (int)(dwMaxY - dwMinY);
    else
        nIndex = 0;
    const int nEntry = 3 * nIndex;
    int nDirection = gDirectionTable_006EB7E0[nEntry + 2];
    if (bSwapped)
    {
        pDirectionVector->nY = gDirectionTable_006EB7E0[nEntry];
        pDirectionVector->nX = gDirectionTable_006EB7E0[nEntry + 1];
        nDirection = (-1 - nDirection) & 0x0F;
    }
    else
    {
        pDirectionVector->nX = gDirectionTable_006EB7E0[nEntry];
        pDirectionVector->nY = gDirectionTable_006EB7E0[nEntry + 1];
    }
    if (!bPositiveY)
    {
        pDirectionVector->nY = -pDirectionVector->nY;
        nDirection = (-1 - nDirection) & 0x1F;
    }
    if (bPositiveX)
    {
        nDirection = (-1 - nDirection) & 0x3F;
    }
    else
    {
        pDirectionVector->nX = -pDirectionVector->nX;
    }
    *pOutDirection = (nDirection + 8) & 0x3F;
}

// 0x0064FE40
int __fastcall PATH_ComputeVelocityAndDirectionVectorsToNextPoint(D2DynamicPathStrc* pPath, int bNormalizeDirectionIfSamePos, int bForceDirectionNormalization)
{
    D2FP32_16* const ptGameCoords = &pPath->tGameCoords;
    D2FP32_16 tTarget;
    tTarget.dwPrecisionX = PATH_ToFP16Center(pPath->points[pPath->current].x);
    tTarget.dwPrecisionY = PATH_ToFP16Center(pPath->points[pPath->current].y);
    while (tTarget.dwPrecisionX == ptGameCoords->dwPrecisionX && tTarget.dwPrecisionY == ptGameCoords->dwPrecisionY)
    {
        if (pPath->current >= pPath->count - 1)
        {
            const int nZeroX = gtZeroVector_006EB7D4.nX;
            const int nZeroY = gtZeroVector_006EB7D4.nY;
            pPath->direction.nX = nZeroX;
            pPath->direction.nY = nZeroY;
            pPath->velocityVector.nX = nZeroX;
            pPath->velocityVector.nY = nZeroY;
            pPath->current = pPath->count;
            pPath->velocity = 0;
            return 1;
        }

        ++pPath->current;
        tTarget.dwPrecisionX = PATH_ToFP16Center(pPath->points[pPath->current].x);
        tTarget.dwPrecisionY = PATH_ToFP16Center(pPath->points[pPath->current].y);
    }

    D2CoordStrc tDirectionVector;
    int nDirection;
    PATH_GetDirectionVector(&tDirectionVector, &nDirection, *ptGameCoords, tTarget);

    pPath->direction.nX = tDirectionVector.nX;
    pPath->direction.nY = tDirectionVector.nY;
    if (pPath->flags & 0x200)
    {
        nDirection = (nDirection - 32) & 63;
    }

    pPath->velocityVector.nX = (pPath->velocity * tDirectionVector.nX) >> 8;
    pPath->velocityVector.nY = (pPath->velocity * tDirectionVector.nY) >> 8;

    const int bSame = PATH_FromFP16(tTarget.dwPrecisionX) == PATH_FromFP16(ptGameCoords->dwPrecisionX + pPath->velocityVector.nX)
        && PATH_FromFP16(tTarget.dwPrecisionY) == PATH_FromFP16(ptGameCoords->dwPrecisionY + pPath->velocityVector.nY);

    if (bForceDirectionNormalization || bSame && bNormalizeDirectionIfSamePos)
    {
        PATH_SetDirection(pPath, (unsigned char)nDirection);
    }

    return bSame;
}
