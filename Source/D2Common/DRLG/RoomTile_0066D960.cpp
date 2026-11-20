#include "D2DrlgRooms.h"
#ifdef MOVED_TEST
#define RANGE_COUNT 39
#define STYLE_SHIFT 18
#define SEQ_SHIFT 8
#else
#define RANGE_COUNT 37
#define STYLE_SHIFT 20
#define SEQ_SHIFT 8
#endif

struct D2UnkDrlgRoomTileStrc
{
    int nLevelId;
    int nArrayStartId;
    int nArrayEndId;
};


extern const D2UnkDrlgRoomTileStrc gDrlgRoomTileLevelRanges_006EEFC8[RANGE_COUNT];                                  // 0x006EEFC8
extern const D2UnkDrlgRoomTileStrc2 gDrlgRoomTilePresetUnits_006EF188[];                                   // 0x006EF188

// 0x0066D960
int __stdcall sub_0066D960_FindTilePresetEntry(int nLevelId, unsigned int nPackedTileInformation, int bIsRightWallWithDoor)
{
    for (const int* rangeEnd = &gDrlgRoomTileLevelRanges_006EEFC8[0].nArrayEndId;
         (int)rangeEnd < (int)&gDrlgRoomTileLevelRanges_006EEFC8[RANGE_COUNT].nArrayEndId; rangeEnd += 3)
    {
        if (rangeEnd[-2] == nLevelId)
        {
            const int nTileStyle = (nPackedTileInformation >> STYLE_SHIFT) & 0x3F;
            const int nTileSequence = (nPackedTileInformation >> SEQ_SHIFT) & 0xFF;

            for (int j = rangeEnd[-1]; j <= *rangeEnd; ++j)
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

#include "gen/data/Source/D2Common/DRLG/RoomTile_0066D960.inc"
