struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x4];
    unsigned int dwInitSeed;
    char unk0x08[0xC];
    D2SeedStrc pSeed;
    char unk0x1C[0x2C];
    int nType;
};

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                   // 0x00650E40
void __fastcall DRLGOUTPLACE_InitOutdoorRoomGrids(D2DrlgRoomStrc* pDrlgRoom);                                                   // 0x0067D2D0
void __fastcall DRLGPRESET_InitPresetRoomGrids(D2DrlgRoomStrc* pDrlgRoom);                                                // 0x006667D0

// 0x0066EE40
void __fastcall DRLGROOMTILE_InitRoomGrids(D2DrlgRoomStrc* pDrlgRoom)
{
    SEED_InitLowSeed(&pDrlgRoom->pSeed, pDrlgRoom->dwInitSeed);

    switch (pDrlgRoom->nType)
    {
    case 1:
        DRLGOUTPLACE_InitOutdoorRoomGrids(pDrlgRoom);
        break;

    case 2:
        DRLGPRESET_InitPresetRoomGrids(pDrlgRoom);
        break;
    }
}
