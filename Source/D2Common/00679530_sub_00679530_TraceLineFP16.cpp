struct D2ActiveRoomStrc;

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
    char unk0x00[0x1C];
    D2ActiveRoomStrc* pRoom;
    char unk0x20[0x08];
    int dwPathPoints;
    char unk0x2C[0x1C];
    unsigned int dwCollisionPattern;
    char unk0x4C[0x04];
    unsigned int nMoveTestCollisionMask;
    char unk0x54[0x28];
    int dwVelocity;
    char unk0x80[0x1C];
    D2PathPointStrc PathPoints[78];
};

struct D2PathInfoStrc
{
    D2PathPointStrc tStartCoord;
    char unk0x04[0x2C];
    D2DynamicPathStrc* pDynamicPath;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define D2_ABS(x) ((x) < 0 ? -(x) : (x))

int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910
void __fastcall sub_0067A390_GetScaledDirectionVector(int nVelocity, D2CoordStrc* pDirectionVector, D2PathPointStrc tPoint1, D2PathPointStrc tPoint2); // 0x0067A390

// build: context PATH_ToFP16Center
inline unsigned int PATH_ToFP16Center(unsigned short value)
{
    return (value << 16) + (1 << 15);
}

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

// 0x00679530
static int __stdcall sub_00679530_TraceLineFP16(D2DynamicPathStrc* pDynamicPath, D2CoordStrc* pDirectionVector, D2PathPointStrc tStartCoord, D2PathPointStrc* pDestination)
{
    D2ActiveRoomStrc* pRoom = pDynamicPath->pRoom;
    const int nCollisionPattern = pDynamicPath->dwCollisionPattern;
    const int nCollisionMask = pDynamicPath->nMoveTestCollisionMask;
    D2PathPointStrc tPrevPoint = tStartCoord;
    int nX = PATH_ToFP16Center(tPrevPoint.X);
    int nY = PATH_ToFP16Center(tPrevPoint.Y);
    D2PathPointStrc tTargetPoint = *pDestination;
    const int nDeltaX = tTargetPoint.X - (unsigned short)(nX >> 16);
    const int nDeltaY = tTargetPoint.Y - (unsigned short)(nY >> 16);
    int nVelocityX = pDirectionVector->nX;
    int nVelocityY = pDirectionVector->nY;
    D2_ASSERT(D2_ABS(nVelocityX) > 0 || D2_ABS(nVelocityY) > 0, 110);
    sub_6FDAB810(&nVelocityX, &nVelocityY);
    const int nStepX = nVelocityX;
    const int nStepY = nVelocityY;
    if (D2_ABS(nDeltaX) > D2_ABS(nDeltaY))
    {
        while (tPrevPoint.X != tTargetPoint.X)
        {
            const int nNewX = nStepX + nX;
            const int nNewY = nStepY + nY;
            D2PathPointStrc tNewPoint;
            tNewPoint.X = (unsigned short)(nNewX >> 16);
            tNewPoint.Y = (unsigned short)(nNewY >> 16);
            if (tPrevPoint.X != tNewPoint.X || tPrevPoint.Y != tNewPoint.Y)
            {
                if (COLLISION_CheckAnyCollisionWithPattern(pRoom, tNewPoint.X, tNewPoint.Y, nCollisionPattern, nCollisionMask))
                {
                    *pDestination = tPrevPoint;
                    return 0;
                }
            }
            nX = nNewX;
            nY = nNewY;
            tPrevPoint = tNewPoint;
        }
    }
    else
    {
        while (tPrevPoint.Y != tTargetPoint.Y)
        {
            const int nNewX = nStepX + nX;
            const int nNewY = nStepY + nY;
            D2PathPointStrc tNewPoint;
            tNewPoint.X = (unsigned short)(nNewX >> 16);
            tNewPoint.Y = (unsigned short)(nNewY >> 16);
            if (tPrevPoint.X != tNewPoint.X || tPrevPoint.Y != tNewPoint.Y)
            {
                if (COLLISION_CheckAnyCollisionWithPattern(pRoom, tNewPoint.X, tNewPoint.Y, nCollisionPattern, nCollisionMask))
                {
                    *pDestination = tPrevPoint;
                    return 0;
                }
            }
            nX = nNewX;
            nY = nNewY;
            tPrevPoint = tNewPoint;
        }
    }
    D2_ASSERT(tTargetPoint.X, 171);
    D2_ASSERT(tTargetPoint.Y, 172);
    return 1;
}

// 0x0067A420
static int __stdcall sub_0067A420_TraceSegment(D2DynamicPathStrc* pDynamicPath, D2PathPointStrc tStartCoord, D2PathPointStrc tTargetCoord)
{
    if (!pDynamicPath->dwVelocity)
        return 0;

    D2CoordStrc tDirectionVector;
    sub_0067A390_GetScaledDirectionVector(pDynamicPath->dwVelocity, &tDirectionVector, tStartCoord, tTargetCoord);
    D2_ASSERT(D2_ABS(tDirectionVector.nX) > 0 || D2_ABS(tDirectionVector.nY) > 0, 834);
    sub_6FDAB810(&tDirectionVector.nX, &tDirectionVector.nY);
    return sub_00679530_TraceLineFP16(pDynamicPath, &tDirectionVector, tStartCoord, &tTargetCoord);
}

// 0x0067A4A0
int __fastcall sub_0067A4A0_TestPathPoints(D2PathInfoStrc* pPathInfo)
{
    D2PathPointStrc tPrevPoint = pPathInfo->tStartCoord;
    D2DynamicPathStrc* pDynamicPath = pPathInfo->pDynamicPath;
    struct LoopState { int count; D2ActiveRoomStrc* room; int pattern; int mask; int index; } loop;
    loop.room=pDynamicPath->pRoom;
    loop.count=pDynamicPath->dwPathPoints;
    loop.pattern=pDynamicPath->dwCollisionPattern;
    loop.mask=pDynamicPath->nMoveTestCollisionMask;
    loop.index=0;
    for (; loop.index < loop.count; ++loop.index)
    {
        const D2PathPointStrc tPoint = pDynamicPath->PathPoints[loop.index];
        int deltaX=tPoint.X-tPrevPoint.X;
        if (deltaX<0) deltaX=-deltaX;
        int deltaY;
        if (deltaX <= 1 && ((deltaY=tPoint.Y-tPrevPoint.Y), (deltaY<0 ? -deltaY : deltaY)) <= 1)
        {
            if (COLLISION_CheckAnyCollisionWithPattern(loop.room, tPoint.X, tPoint.Y, loop.pattern, loop.mask))
                return 0;
        }
        else if (!sub_0067A420_TraceSegment(pDynamicPath, tPrevPoint, tPoint))
        {
            return 0;
        }
        tPrevPoint = tPoint;
    }
    return 1;
}
