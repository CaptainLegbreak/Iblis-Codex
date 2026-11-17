struct D2DrlgStrc;

struct D2DrlgLevelStrc
{
    char unk0x000[0x1B4];
    D2DrlgStrc* pDrlg;
    char unk0x1B8[0x18];
    int nLevelId;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x58];
    D2DrlgLevelStrc* pLevel;
};

struct D2LevelDefBin
{
    char unk0x00[0x30];
    int dwDrlgType;
};

D2LevelDefBin* __fastcall DATATBLS_GetLevelDefRecord(int nLevelId);                                         // 0x0061E470
int* __fastcall DRLGROOM_GetVisArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId);                           // 0x0066C040

// 0x0066C020
int __fastcall sub_0066C020_GetDrlgTypeFromRoom(D2DrlgRoomStrc* pDrlgRoom)
{
    return DATATBLS_GetLevelDefRecord(pDrlgRoom->pLevel->nLevelId)->dwDrlgType;
}

// 0x0066C090
int* __fastcall sub_0066C090_GetVisArrayFromLevel(D2DrlgLevelStrc* pLevel)
{
    return DRLGROOM_GetVisArrayFromLevelId(pLevel->pDrlg, pLevel->nLevelId);
}
