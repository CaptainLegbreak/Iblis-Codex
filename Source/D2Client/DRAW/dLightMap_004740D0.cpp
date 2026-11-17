struct D2PathPointStrc
{
    char unk0x00[0x10];
    int nX;
    int nY;
};

extern "C" int __cdecl abs(int nValue);
#pragma intrinsic(abs)

int gnPathStepMode_007B0A64;                                                                                // 0x007B0A64
extern int gnPathStepSignX_007B0A50;                                                                        // 0x007B0A50
extern int gnPathStepSignY_007A8A48;                                                                        // 0x007A8A48
int gnPathStepRatio_007A8A4C;                                                                               // 0x007A8A4C

// 0x004740D0
static __declspec(noinline) unsigned int __stdcall sub_004740D0_ApproxDistance(int nB, int nA)
{
    const int nAbsA = abs(nA);
    const int nAbsB = abs(nB);
    if (nAbsA >= nAbsB)
    {
        return (unsigned int)(nAbsA * 0x3D7 + nAbsB * 0x197) >> 10;
    }

    return (unsigned int)(nAbsB * 0x3D7 + nAbsA * 0x197) >> 10;
}

// 0x00474B50
static __declspec(noinline) void __stdcall sub_00474B50_SetupStepDirection(int nX, int nY, D2PathPointStrc* pPoint)
{
    int nDx = pPoint->nX - nX;
    int nDy = pPoint->nY - nY;
    if (!nDx && !nDy)
    {
        gnPathStepMode_007B0A64 = 0;
        return;
    }

    if (nDx < 0)
    {
        gnPathStepSignX_007B0A50 = -1;
        nDx = -nDx;
    }
    else
    {
        gnPathStepSignX_007B0A50 = 1;
    }

    if (nDy < 0)
    {
        gnPathStepSignY_007A8A48 = -1;
        nDy = -nDy;
    }
    else
    {
        gnPathStepSignY_007A8A48 = 1;
    }

    if (!nDx)
    {
        gnPathStepMode_007B0A64 = 4;
        return;
    }

    if (!nDy)
    {
        gnPathStepMode_007B0A64 = 1;
        return;
    }

    if (nDx >= nDy)
    {
        gnPathStepMode_007B0A64 = 2;
        gnPathStepRatio_007A8A4C = (nDy << 8) / nDx;
    }
    else
    {
        gnPathStepMode_007B0A64 = 3;
        gnPathStepRatio_007A8A4C = (nDx << 8) / nDy;
    }
}

int __stdcall sub_W04_Emit_004740D0(int nX, int nY, int nDx, int nDy)
{
    int nA = nX - nDx;
    if (nA < 0) nA = -nA;
    int nB = nY - nDy;
    if (nB < 0) nB = -nB;
    return sub_004740D0_ApproxDistance(nB, nA) + nX;
}

void __stdcall sub_W04_Emit_00474B50(D2PathPointStrc* pPoint, int nX, int nY)
{
    sub_00474B50_SetupStepDirection(nX, nY, pPoint);
    sub_00474B50_SetupStepDirection(nY, nX, pPoint);
}
