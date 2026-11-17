struct D2CoordStrc
{
    int nX;
    int nY;
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

#include "gen/data/Source/D2Common/0064FC60_PATH_GetDirectionVector.inc"
