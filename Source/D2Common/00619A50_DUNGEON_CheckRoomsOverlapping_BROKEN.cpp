struct D2ActiveRoomStrc
{
    char unk0x00[0x5C];
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2DrlgCoordsStrc
{
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
};

// 0x00619A50
int __stdcall DUNGEON_CheckRoomsOverlapping_BROKEN(D2ActiveRoomStrc* pPrimary, D2ActiveRoomStrc* pSecondary)
{
    D2_ASSERT(pPrimary, 379);

    const D2DrlgCoordsStrc* pFirst = (D2DrlgCoordsStrc*)&pPrimary->nTileXPos;
    const D2DrlgCoordsStrc* pSecond = (D2DrlgCoordsStrc*)&pPrimary->nTileXPos;
    const int nX2 = pSecond->nTileXPos;
    const int nX1 = pFirst->nTileXPos;
    if (nX1 > nX2 + pSecond->nTileWidth)
        return 0;
    if (nX1 + pFirst->nTileWidth < nX2)
        return 0;
    const int nY2 = pSecond->nTileYPos;
    if (pFirst->nTileYPos > nY2 + pSecond->nTileHeight)
        return 0;
    if (pFirst->nTileYPos + pFirst->nTileHeight < nY2)
        return 0;
    if (nX1 == nX2 + pSecond->nTileWidth)
        return 1;
    if (nX1 + pFirst->nTileWidth == nX2)
        return 2;
    if (pFirst->nTileYPos == nY2 + pSecond->nTileHeight)
        return 3;
    return 4;
}
