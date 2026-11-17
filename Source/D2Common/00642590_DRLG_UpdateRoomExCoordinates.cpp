struct D2DrlgCoordStrc
{
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
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
    char unk0x14[0x08];
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void __fastcall DRLG_GetMinAndMaxCoordinatesFromLevel(D2DrlgLevelStrc* pLevel, int* pTileMinX, int* pTileMinY, int* pTileMaxX, int* pTileMaxY); // 0x00642520

// 0x00642590
void __fastcall DRLG_UpdateRoomExCoordinates(D2DrlgLevelStrc* pLevel)
{
    int nTileX[2];
    int nTileY[2];

    if (!pLevel)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 739);
        exit(-1);
    }

    D2DrlgRoomStrc* pDrlgRoom = pLevel->pFirstRoomEx;
    if (!pDrlgRoom)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 740);
        exit(-1);
    }

    DRLG_GetMinAndMaxCoordinatesFromLevel(pLevel, &nTileX[0], &nTileY[0], &nTileX[1], &nTileY[1]);

    D2DrlgRoomStrc* pRoom = pDrlgRoom;

    if (pLevel->nWidth < nTileX[1] - nTileX[0])
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 747);
        exit(-1);
    }

    if (pLevel->nHeight < nTileY[1] - nTileY[0])
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 748);
        exit(-1);
    }

    const int nMinX = nTileX[0];
    const int nMinY = nTileY[0];
    for (; pRoom; pRoom = pRoom->pDrlgRoomNext)
    {
        pRoom->pDrlgCoord.nPosX += pLevel->nPosX - nMinX;
        pRoom->pDrlgCoord.nPosY += pLevel->nPosY - nMinY;
    }
}
