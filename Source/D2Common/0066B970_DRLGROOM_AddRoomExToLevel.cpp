struct D2DrlgRoomStrc;
struct D2PresetUnitStrc;

#define DRLGTYPE_MAZE 1
#define DRLGTYPE_PRESET 2
#define DRLGROOMFLAG_AUTOMAP_REVEAL 0x40000
#define DRLGROOMFLAG_NO_LOS_DRAW 0x80000
#define DRLGROOMFLAG_PRESET_UNITS_SPAWNED 0x4000000

struct D2DrlgLevelStrc
{
    char unk0x000[0x8];
    int nRooms;
    char unk0x00C[0x4];
    D2DrlgRoomStrc* pFirstRoomEx;
    char unk0x014[0x1BC];
    int nLevelId;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x24];
    D2DrlgRoomStrc* pDrlgRoomNext;
    unsigned int dwFlags;
    char unk0x2C[0x1C];
    int nType;
    char unk0x4C[0xC];
    D2DrlgLevelStrc* pLevel;
    D2PresetUnitStrc* pPresetUnits;
};

// 0x0066B970
void __fastcall DRLGROOM_AddRoomExToLevel(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pDrlgRoom)
{
    pDrlgRoom->pDrlgRoomNext = pLevel->pFirstRoomEx;
    ++pLevel->nRooms;
    pLevel->pFirstRoomEx = pDrlgRoom;
}

// 0x0066BA70
int __fastcall DRLGROOM_CheckLOSDraw(D2DrlgRoomStrc* pDrlgRoom)
{
    switch (pDrlgRoom->nType)
    {
    case DRLGTYPE_MAZE:
        return 1;

    case DRLGTYPE_PRESET:
        return pDrlgRoom->dwFlags & DRLGROOMFLAG_NO_LOS_DRAW;
    }

    return 0;
}

// 0x0066BAB0
int __fastcall DRLGROOM_GetLevelId(D2DrlgRoomStrc* pDrlgRoom)
{
    return pDrlgRoom->pLevel->nLevelId;
}

// 0x0066BFA0
D2PresetUnitStrc* __fastcall DRLGROOM_GetPresetUnits(D2DrlgRoomStrc* pDrlgRoom)
{
    if (!(pDrlgRoom->dwFlags & DRLGROOMFLAG_AUTOMAP_REVEAL))
    {
        if (pDrlgRoom->dwFlags & DRLGROOMFLAG_PRESET_UNITS_SPAWNED)
        {
            return 0;
        }

        pDrlgRoom->dwFlags |= DRLGROOMFLAG_PRESET_UNITS_SPAWNED;
    }

    return pDrlgRoom->pPresetUnits;
}
