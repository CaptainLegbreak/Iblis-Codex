struct D2DrlgPresetRoomStrc
{
    int nLevelPrest;
    int nPickedFile;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x20];
    D2DrlgPresetRoomStrc* pMaze;
};

struct D2Unk00667420CStrc
{
    char unk0x00[0x20];
    int n20;
};

struct D2Unk00667420BStrc
{
    D2Unk00667420CStrc* p00;
};

struct D2Unk00667420Strc
{
    char unk0x00[0x14];
    D2Unk00667420BStrc* p14;
};

// 0x00667000
int __fastcall DRLGPRESET_GetLevelPrestIdFromRoomEx(D2DrlgRoomStrc* pDrlgRoom)
{
    return pDrlgRoom->pMaze->nLevelPrest;
}

// 0x00667420
int __fastcall sub_00667420_GetChainField20(D2Unk00667420Strc* p)
{
    return p->p14->p00->n20;
}
