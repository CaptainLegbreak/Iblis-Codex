#include "D2Path.h"

#pragma pack(push,1)
#pragma pack(pop)
extern const D2CoordStrc gtZeroVector_006EB7D4; // 0x006EB7D4
void __fastcall sub_6FDA9720(D2DynamicPathStrc*,unsigned char); // 0x006485F0
// build: context PATH_ToFP16Center
static inline unsigned int PATH_ToFP16Center(unsigned short nValue)
{
    return (nValue << 16) + 0x8000;
}

// build: context PATH_FromFP16
static inline unsigned short PATH_FromFP16(unsigned int nValue)
{
    return (nValue >> 16) & 0xFFFF;
}

extern int gDirectionTable_006EB7E0[128 * 3];                                                               // 0x006EB7E0

static inline void SwapPrecision(unsigned int& a, unsigned int& b)
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
    tTarget.dwPrecisionX = PATH_ToFP16Center(pPath->PathPoints[pPath->dwCurrentPointIdx].X);
    tTarget.dwPrecisionY = PATH_ToFP16Center(pPath->PathPoints[pPath->dwCurrentPointIdx].Y);
    while (tTarget.dwPrecisionX == ptGameCoords->dwPrecisionX && tTarget.dwPrecisionY == ptGameCoords->dwPrecisionY)
    {
        if (pPath->dwCurrentPointIdx >= pPath->dwPathPoints - 1)
        {
            const int nZeroX = gtZeroVector_006EB7D4.nX;
            const int nZeroY = gtZeroVector_006EB7D4.nY;
            pPath->tDirectionVector.nX = nZeroX;
            pPath->tDirectionVector.nY = nZeroY;
            pPath->tVelocityVector.nX = nZeroX;
            pPath->tVelocityVector.nY = nZeroY;
            pPath->dwCurrentPointIdx = pPath->dwPathPoints;
            pPath->dwVelocity = 0;
            return 1;
        }

        ++pPath->dwCurrentPointIdx;
        tTarget.dwPrecisionX = PATH_ToFP16Center(pPath->PathPoints[pPath->dwCurrentPointIdx].X);
        tTarget.dwPrecisionY = PATH_ToFP16Center(pPath->PathPoints[pPath->dwCurrentPointIdx].Y);
    }

    D2CoordStrc tDirectionVector;
    int nDirection;
    PATH_GetDirectionVector(&tDirectionVector, &nDirection, *ptGameCoords, tTarget);

    pPath->tDirectionVector.nX = tDirectionVector.nX;
    pPath->tDirectionVector.nY = tDirectionVector.nY;
    if (pPath->dwFlags & 0x200)
    {
        nDirection = (nDirection - 32) & 63;
    }

    pPath->tVelocityVector.nX = (pPath->dwVelocity * tDirectionVector.nX) >> 8;
    pPath->tVelocityVector.nY = (pPath->dwVelocity * tDirectionVector.nY) >> 8;

    const int bSame = PATH_FromFP16(tTarget.dwPrecisionX) == PATH_FromFP16(ptGameCoords->dwPrecisionX + pPath->tVelocityVector.nX)
        && PATH_FromFP16(tTarget.dwPrecisionY) == PATH_FromFP16(ptGameCoords->dwPrecisionY + pPath->tVelocityVector.nY);

    if (bForceDirectionNormalization || bSame && bNormalizeDirectionIfSamePos)
    {
        sub_6FDA9720(pPath, (unsigned char)nDirection);
    }

    return bSame;
}
