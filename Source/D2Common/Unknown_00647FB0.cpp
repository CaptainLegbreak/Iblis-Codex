struct D2PathPoint00647FB0Strc
{
    unsigned short X;
    unsigned short Y;
};
struct D2ActiveRoom00647FB0Strc
{
    unsigned char unk_00[0x4C];
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
};
struct D2DynamicPath00647FB0Strc
{
    unsigned char unk_00[0x1C];
    D2ActiveRoom00647FB0Strc* pRoom;
    unsigned char unk_20[8];
    int nPathPoints;
    unsigned char unk_2C[8];
    unsigned int dwFlags;
    unsigned char unk_38[0x64];
    D2PathPoint00647FB0Strc PathPoints[78];
};

// 0x00647FB0
void __fastcall sub_00647FB0_CheckPathInRoom(D2DynamicPath00647FB0Strc* pPath)
{
    D2PathPoint00647FB0Strc* const pPathPoints = pPath->PathPoints;
    pPath->dwFlags &= ~1u;
    D2ActiveRoom00647FB0Strc* pRoom = pPath->pRoom;
    for (int i = 0; i < pPath->nPathPoints; ++i)
    {
        if (!pRoom
            || pPathPoints[i].X < pRoom->nSubtileX || pPathPoints[i].X >= pRoom->nSubtileX + pRoom->nSubtileWidth
            || pPathPoints[i].Y < pRoom->nSubtileY || pPathPoints[i].Y >= pRoom->nSubtileY + pRoom->nSubtileHeight)
        {
            pPath->dwFlags |= 1;
            return;
        }
    }
}
