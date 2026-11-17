struct D2UnitStrc;
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

struct D2FP32_16
{
    union
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
};

struct D2DynamicPathStrc
{
    D2FP32_16 tGameCoords;
    int dwClientCoordX;
    int dwClientCoordY;
    D2PathPointStrc tTargetCoord;
    D2PathPointStrc tPrevTargetCoord;
    D2PathPointStrc tFinalTargetCoord;
    D2ActiveRoomStrc* pRoom;
    D2ActiveRoomStrc* pPreviousRoom;
    int dwCurrentPointIdx;
    int dwPathPoints;
    void* unk0x2C;
    D2UnitStrc* pUnit;
    unsigned int dwFlags;
};

void __stdcall DUNGEON_ClientToGameCoords(int* pX, int* pY);                                                // 0x00643540
void __fastcall PATH_GetDirectionVector(D2CoordStrc* pDirectionVector, int* pOutDirection, unsigned int dwStartPrecisionX, unsigned int dwStartPrecisionY, unsigned int dwTargetPrecisionX, unsigned int dwTargetPrecisionY); // 0x0064FC60

// 0x00648B00
void __stdcall sub_00648B00_SetTargetCoordFromClient(D2DynamicPathStrc* pDynamicPath, int nX, int nY)
{
    DUNGEON_ClientToGameCoords(&nX, &nY);
    nX >>= 11;
    nY >>= 11;
    pDynamicPath->tTargetCoord.X = nX;
    pDynamicPath->tTargetCoord.Y = nY;
}

// 0x0064FD70
void __fastcall sub_0064FD70_GetDirectionVectorFromPoints(D2CoordStrc* pDirectionVector, int* pOutDirection, D2PathPointStrc tStartPoint, D2PathPointStrc tTargetPoint)
{
    D2CoordStrc tStart;
    D2CoordStrc tTarget;
    tStart.nX = (tStartPoint.X << 16) + 0x8000;
    tStart.nY = (tStartPoint.Y << 16) + 0x8000;
    tTarget.nX = (tTargetPoint.X << 16) + 0x8000;
    tTarget.nY = (tTargetPoint.Y << 16) + 0x8000;
    PATH_GetDirectionVector(pDirectionVector, pOutDirection, tStart.nX, tStart.nY, tTarget.nX, tTarget.nY);
}

// 0x0064FDC0
int __stdcall PATH_ComputeDirection(int nX1, int nY1, int nX2, int nY2)
{
    D2CoordStrc tCoords;
    int nDirection;
    D2CoordStrc tStart;
    D2CoordStrc tTarget;
    tStart.nX = (nX1 << 16) + 0x8000;
    tStart.nY = (nY1 << 16) + 0x8000;
    tTarget.nX = (nX2 << 16) + 0x8000;
    tTarget.nY = (nY2 << 16) + 0x8000;
    PATH_GetDirectionVector(&tCoords, &nDirection, tStart.nX, tStart.nY, tTarget.nX, tTarget.nY);
    return nDirection;
}
