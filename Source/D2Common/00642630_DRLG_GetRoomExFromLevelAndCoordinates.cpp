extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2DrlgCoordStrc
{
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
};

struct D2DrlgGridStrc
{
    int* pCellsFlags;
    int* pCellsRowOffsets;
    int nWidth;
    int nHeight;
    int unk0x10;
};

struct D2DrlgVertexStrc
{
    int nPosX;
    int nPosY;
    unsigned char nDirection;
    unsigned char pad0x09[3];
    int dwFlags;
    D2DrlgVertexStrc* pNext;
};

struct D2DrlgOutdoorInfoStrc
{
    unsigned int dwFlags;
    D2DrlgGridStrc pGrid[4];
    char unk0x054[0x10];
    D2DrlgVertexStrc* pVertex;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x24];
    D2DrlgRoomStrc* pDrlgRoomNext;
    char unk0x28[0x0C];
    D2DrlgCoordStrc pDrlgCoord;
};

struct D2DrlgLevelStrc
{
    char unk0x00[0x10];
    D2DrlgRoomStrc* pFirstRoomEx;
    D2DrlgOutdoorInfoStrc* pOutdoors;
};

int __fastcall DRLGROOM_AreXYInsideCoordinates(D2DrlgCoordStrc* pCoord, int nX, int nY);                    // 0x0066B980
int __fastcall DRLGOUTDOORS_GetOutLinkVisFlag(D2DrlgLevelStrc* pLevel, D2DrlgVertexStrc* pDrlgVertex);       // 0x00674040
int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pDrlgGrid, int nX, int nY);                            // 0x0067C570
void __fastcall sub_0067C760_AlterVertexGridFlags(D2DrlgGridStrc* pDrlgGrid, D2DrlgVertexStrc* pDrlgVertex, int nFlag, int nOperation, int bAlterNextVertex); // 0x0067C760

// 0x00642630
D2DrlgRoomStrc* __fastcall DRLG_GetRoomExFromLevelAndCoordinates(D2DrlgLevelStrc* pLevel, int nX, int nY)
{
    D2_ASSERT(pLevel, 0x2FD);
    D2_ASSERT(pLevel->pFirstRoomEx, 0x2FE);
    for (D2DrlgRoomStrc* pDrlgRoom = pLevel->pFirstRoomEx; pDrlgRoom; pDrlgRoom = pDrlgRoom->pDrlgRoomNext)
    {
        if (DRLGROOM_AreXYInsideCoordinates(&pDrlgRoom->pDrlgCoord, nX, nY))
            return pDrlgRoom;
    }
    return 0;
}

// 0x00674200
int __fastcall DRLGOUTDOORS_TestGridCellSpawnValid(D2DrlgLevelStrc* pLevel, int nX, int nY)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    return !(DRLGGRID_GetGridEntry(&pOutdoors->pGrid[2], nX, nY) & 0x1B81);
}

// 0x00675770
void __fastcall DRLGOUTPLACE_SetOutGridLinkFlags(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    D2DrlgVertexStrc* pVertex = pOutdoors->pVertex;
    D2DrlgVertexStrc* pNext = pVertex->pNext;
    do
    {
        if (pVertex->dwFlags & 1)
        {
            int nVisFlag = DRLGOUTDOORS_GetOutLinkVisFlag(pLevel, pVertex);
            int nPacked = 2 * (pVertex->nDirection != 0) + 1;
            sub_0067C760_AlterVertexGridFlags(&pOutdoors->pGrid[1], pVertex, nVisFlag, 0, 1);
            sub_0067C760_AlterVertexGridFlags(&pOutdoors->pGrid[2], pVertex, nPacked, 0, 1);
        }
        pVertex = pNext;
        pNext = pVertex->pNext;
    }
    while (pVertex != pOutdoors->pVertex);
}
