struct D2DrlgWarpStrc
{
    int nLevel;
    int nVis[8];
    int nWarp[8];
    D2DrlgWarpStrc* pNext;
};

struct D2UnkDrlgRoomTileStrc
{
    int nLevelId;
    int nArrayStartId;
    int nArrayEndId;
};

struct D2UnkDrlgRoomTileStrc2
{
    int nTileStyle;
    int nTileSequence;
    int bIsRightWallWithDoor;
    int nUnitId;
    int nUnitType;
    int nX;
    int nY;
};

extern const D2UnkDrlgRoomTileStrc gDrlgRoomTileLevelRanges_006EEFC8[37];                                  // 0x006EEFC8
extern const D2UnkDrlgRoomTileStrc2 gDrlgRoomTilePresetUnits_006EF188[];                                   // 0x006EF188

// 0x00642920
D2DrlgWarpStrc* __fastcall DRLG_SetWarpId(D2DrlgWarpStrc* pDrlgWarp, int nVis, int nWarp, int nId)
{
    for (int i = 0; i < 8; ++i)
    {
        if (pDrlgWarp->nVis[i] == nVis)
        {
            pDrlgWarp->nWarp[i] = nWarp;
            return pDrlgWarp;
        }
    }

    if (nId == -1)
    {
        for (int i = 0; i < 8 && nId == -1; ++i)
        {
            if (!pDrlgWarp->nVis[i] && pDrlgWarp->nWarp[i] == -1)
            {
                nId = i;
            }
        }
    }

    pDrlgWarp->nVis[nId] = nVis;
    pDrlgWarp->nWarp[nId] = nWarp;
    return pDrlgWarp;
}

// build: context sub_0066D960_FindTilePresetEntry
int __stdcall sub_0066D960_FindTilePresetEntry(int nLevelId, unsigned int nPackedTileInformation, int bIsRightWallWithDoor)
{
    for (int i = 0; i < 37; ++i)
    {
        if (gDrlgRoomTileLevelRanges_006EEFC8[i].nLevelId == nLevelId)
        {
            const int nTileStyle = (nPackedTileInformation >> 20) & 0x3F;
            const int nTileSequence = (nPackedTileInformation >> 8) & 0xFF;

            for (int j = gDrlgRoomTileLevelRanges_006EEFC8[i].nArrayStartId; j <= gDrlgRoomTileLevelRanges_006EEFC8[i].nArrayEndId; ++j)
            {
                if (nTileStyle == gDrlgRoomTilePresetUnits_006EF188[j].nTileStyle
                    && nTileSequence == gDrlgRoomTilePresetUnits_006EF188[j].nTileSequence
                    && bIsRightWallWithDoor == gDrlgRoomTilePresetUnits_006EF188[j].bIsRightWallWithDoor)
                {
                    return j;
                }
            }
        }
    }

    return -1;
}
