struct D2ActiveRoomStrc;

struct D2PathTestStrc
{
    char unk0x00[0x08];
    D2ActiveRoomStrc* pRoom;
    char unk0x0C[0x18];
    int nUnitSize;
    char unk0x28[0x04];
    int nCollisionMask;
};

struct D2PathRayStrc
{
    unsigned short nStartX;
    unsigned short nStartY;
    unsigned short nTargetX;
    unsigned short nTargetY;
    char unk0x08[0x08];
    int nStepX;
    int nStepY;
    int bValid;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define D2_ABS(x) ((x) >= 0 ? (x) : -(x))

unsigned short __stdcall COLLISION_CheckMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, int nMask); // 0x0064D9B0
void __fastcall sub_00678E30(D2PathRayStrc* pRay);                                                          // 0x00678E30

// 0x00678F00
void __fastcall sub_6FDAB810(int* a1, int* a2)
{
    if (*a1 >= 0)
    {
        while (*a1 > 65536)
        {
            *a1 >>= 1;
            *a2 >>= 1;
        }
    }
    else
    {
        while (*a1 < -65536)
        {
            *a1 >>= 1;
            *a2 >>= 1;
        }
    }

    if (*a2 >= 0)
    {
        while (*a2 > 65536)
        {
            *a1 >>= 1;
            *a2 >>= 1;
        }
    }
    else
    {
        while (*a2 < -65536)
        {
            *a1 >>= 1;
            *a2 >>= 1;
        }
    }
}

// 0x00678F70
int __fastcall sub_00678F70_TestRay(D2PathTestStrc* pPath, D2PathRayStrc* pRay)
{
    if (!pRay->bValid)
        return 0;

    sub_00678E30(pRay);
    if (!pRay->bValid)
        return 0;

    int nStepX = pRay->nStepX;
    int nStepY = pRay->nStepY;
    if (!nStepX && !nStepY)
        return 0;

    int nX = (pRay->nStartX << 16) + 0x8000;
    int nY = (pRay->nStartY << 16) + 0x8000;
    const int nTargetX = (pRay->nTargetX << 16) + 0x8000;
    const int nTargetY = (pRay->nTargetY << 16) + 0x8000;
    sub_6FDAB810(&nStepX, &nStepY);

    int nStep;
    if (D2_ABS(nStepX) > D2_ABS(nStepY))
        nStep = D2_ABS(nStepX);
    else
        nStep = D2_ABS(nStepY);

    D2ActiveRoomStrc* pRoom = pPath->pRoom;
    const int nUnitSize = pPath->nUnitSize;
    const int nCollisionMask = pPath->nCollisionMask;
    while (1)
    {
        const int nDeltaX = nTargetX - nX;
        if (D2_ABS(nDeltaX) < nStep)
        {
            const int nDeltaY = nTargetY - nY;
            if (D2_ABS(nDeltaY) < nStep)
                break;
        }

        const int nNewX = nX + nStepX;
        const int nNewY = nY + nStepY;
        if ((short)(nX >> 16) != (short)(nNewX >> 16) || (short)(nY >> 16) != (short)(nNewY >> 16))
        {
            if (COLLISION_CheckMaskWithSize(pRoom, (unsigned short)(nNewX >> 16), (unsigned short)(nNewY >> 16), nUnitSize, nCollisionMask))
                return 0;
        }

        nX = nNewX;
        nY = nNewY;
    }

    D2_ASSERT(nX != 0x80008000, 0x1DF);
    D2_ASSERT(nY != 0x80008000, 0x1E0);
    return 1;
}
