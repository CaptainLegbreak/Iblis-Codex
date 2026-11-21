#pragma once
// Level generation: outdoor room data, substitution groups, maze build lists, acts and room tile links

#include "D2Check.h"
#include "D2Structs.h"
#include "D2Drlg.h"

struct D2DrlgEnvironmentStrc;
struct D2DrlgVertexStrc;
struct D2DrlgOutdoorRoomStrc;
struct D2DrlgSubstGroupStrc;
struct D2DrlgBuildStrc;
struct D2DrlgActStrc;
struct D2UnkDrlgRoomTileStrc2;

typedef void (__fastcall* ACTCALLBACKFN)(D2ActiveRoomStrc* pRoom);

struct D2DrlgOutdoorRoomStrc
{
    D2DrlgGridStrc pTileTypeGrid; // 0x00
    D2DrlgGridStrc tGrid14; // 0x14
    D2DrlgGridStrc tGrid28; // 0x28
    D2DrlgGridStrc tGrid3C; // 0x3C
    D2DrlgVertexStrc* pVertex; // 0x50
    unsigned int dwFlags; // 0x54
    int dwFlagsEx; // 0x58
    int unk0x5C; // 0x5C
    int unk0x60; // 0x60
    int nTileInfo64; // 0x64
    int nTileInfo68; // 0x68
    int nTileInfo6C; // 0x6C
};

struct D2DrlgSubstGroupStrc
{
    D2DrlgCoordStrc tBox; // 0x00
    int unk0x10; // 0x10
    int nSubstGroup; // 0x14
};

struct D2DrlgBuildStrc
{
    int nPreset; // 0x00
    int nDivisor; // 0x04
    int nRand; // 0x08
    D2DrlgBuildStrc* pNext; // 0x0C
};

struct D2DrlgActStrc
{
    int bHasPendingUnitListUpdates; // 0x00
    D2DrlgEnvironmentStrc* pEnvironment; // 0x04
    int nTownId; // 0x08
    unsigned int dwInitSeed; // 0x0C
    D2ActiveRoomStrc* pRoom; // 0x10
    unsigned char nAct; // 0x14
    unsigned char unk0x15; // 0x15
    unsigned short unk0x16; // 0x16
    void* pTileData[12]; // 0x18
    D2DrlgStrc* pDrlg; // 0x48
    ACTCALLBACKFN pfnActCallBack; // 0x4C
    int bClient; // 0x50
    int bHasPendingRoomsUpdates; // 0x54
    int bHasPendingRoomDeletions; // 0x58
    void* pMemPool; // 0x5C
};

struct D2UnkDrlgRoomTileStrc2
{
    int nTileStyle; // 0x00
    int nTileSequence; // 0x04
    int bIsRightWallWithDoor; // 0x08
    int nUnitId; // 0x0C
    int nUnitType; // 0x10
    int nX; // 0x14
    int nY; // 0x18
};

D2_CHECK_SIZE(D2DrlgOutdoorRoomStrc, 0x70);
D2_CHECK_SIZE(D2DrlgSubstGroupStrc, 0x18);
D2_CHECK_SIZE(D2DrlgBuildStrc, 0x10);
D2_CHECK_SIZE(D2DrlgActStrc, 0x60);
D2_CHECK_SIZE(D2UnkDrlgRoomTileStrc2, 0x1C);
