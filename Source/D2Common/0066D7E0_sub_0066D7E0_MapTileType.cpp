struct D2CommonStormSlotListBStrc;

struct D2CommonStormSlotArrayBStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2CommonStormSlotListBStrc* f_8;
    unsigned int f_C;

    ~D2CommonStormSlotArrayBStrc();                                                                         // 0x0060F950
};

struct D2CommonStormSlotGrowArrayBStrc : D2CommonStormSlotArrayBStrc
{
    ~D2CommonStormSlotGrowArrayBStrc();
};

// 0x00610080
D2CommonStormSlotGrowArrayBStrc::~D2CommonStormSlotGrowArrayBStrc()
{
}

struct D2CommonStormZero6105F0Strc
{
    int unk0x00;
    int n0x04;
    int n0x08;
    int n0x0C;
    int n0x10;
    int n0x14;
    D2CommonStormZero6105F0Strc();
};

// 0x006105F0
D2CommonStormZero6105F0Strc::D2CommonStormZero6105F0Strc() : n0x04(0), n0x08(0), n0x0C(0), n0x10(0), n0x14(0)
{
}

extern const int gnTileTypeTable_006EEF88[];                                                                // 0x006EEF88
void __stdcall DUNGEON_GameTileToClientCoords(int* pX, int* pY);                                            // 0x00643310

// 0x0066D7E0
int __fastcall sub_0066D7E0_MapTileType(int nId)
{
    return gnTileTypeTable_006EEF88[nId];
}

// 0x0066D800
void __fastcall sub_0066D800_TileToClientCoords(int* pX, int* pY)
{
    *pY += 1;
    DUNGEON_GameTileToClientCoords(pX, pY);
    *pY += 0x28;
}

#include "gen/data/Source/D2Common/0066D7E0_sub_0066D7E0_MapTileType.inc"
