#include "D2Structs.h"
#include "D2Txt.h"
struct D2ActiveRoomStrc;


struct D2DrlgWarpStrc
{
    int nLevel;
    int nVis[8];
    int nWarp[8];
    D2DrlgWarpStrc* pNext;
};

struct D2DrlgStrc
{
    char unk0x00[0x90];
    D2DrlgWarpStrc* pWarp;
};

struct D2PresetUnitStrc
{
    int unk0x00;
    int nIndex;
    int nXpos;
    D2PresetUnitStrc* pNext;
    int unk0x10;
    int nUnitType;
    int nYpos;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x24];
    D2DrlgRoomStrc* pDrlgRoomNext;
    unsigned int dwFlags;
    char unk0x2C[0x04];
    D2ActiveRoomStrc* pRoom;
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
    char unk0x44[0x18];
    D2PresetUnitStrc* pPresetUnits;
};

struct D2DrlgLevelStrc
{
    char unk0x00[0x08];
    int nRooms;
    char unk0x0C[0x04];
    D2DrlgRoomStrc* ptRoomFirst;
    char unk0x14[0x08];
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
    char unk0x2C[0x188];
    D2DrlgStrc* pDrlg;
    char unk0x1B8[0x0C];
    D2SeedStrc pSeed;
    char unk0x1CC[0x04];
    int eLevelId;

    D2DrlgRoomStrc* sub_0066AC40_GetTileRoom(int nTileIndex, int* pX, int* pY);    // 0x0066AC40
};

struct D2LevelDefBin
{
    char unk0x00[0x68];
    int dwWarp[8];
    char unk0x88[0x08];
    int dwPosition;
};


extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);
extern "C" void __cdecl exit(int nCode);                                                                    // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __fastcall DRLGACTIVATE_InitializeRoomEx(D2DrlgRoomStrc* pDrlgRoom);                                  // 0x0061B730
D2LevelDefBin* __fastcall DATATBLS_GetLevelDefRecord(int nLevelId);                                        // 0x0061E470
unsigned int __fastcall DRLGROOM_CheckWaypointFlags(D2DrlgRoomStrc* pDrlgRoom);                            // 0x0066BAA0
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                       // 0x00640E90
D2DrlgLevelStrc* __stdcall DRLG_GetLevel(D2DrlgStrc* pDrlg, int nLevelId);                                 // 0x00642BB0
void __stdcall DRLG_InitLevel(D2DrlgLevelStrc* pLevel);                                                    // 0x006424A0
D2DrlgRoomStrc* __fastcall DRLG_GetRoomExFromLevelAndCoordinates(D2DrlgLevelStrc* pLevel, int nX, int nY); // 0x00642630
int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                                  // 0x0045C3E0

static __forceinline int* __fastcall sub_0066AEC0(D2DrlgStrc* pDrlg, int nLevelId); // 0x0066AEC0

// build: context sub_0066AEC0
static __forceinline int* __fastcall sub_0066AEC0(D2DrlgStrc* pDrlg, int nLevelId)
{
    for (D2DrlgWarpStrc* pDrlgWarp = pDrlg->pWarp; pDrlgWarp; pDrlgWarp = pDrlgWarp->pNext)
    {
        D2_ASSERT(pDrlgWarp->nLevel, 418);
        if (nLevelId == pDrlgWarp->nLevel)
        {
            return pDrlgWarp->nWarp;
        }
    }
    return DATATBLS_GetLevelDefRecord(nLevelId)->dwWarp;
}

// 0x0066AD80
static D2DrlgRoomStrc* __stdcall DRLGWARP_GetWaypointRoomExFromLevel(D2DrlgLevelStrc* pLevel, int* pX, int* pY)
{
    for (D2DrlgRoomStrc* pDrlgRoom = pLevel->ptRoomFirst; pDrlgRoom; pDrlgRoom = pDrlgRoom->pDrlgRoomNext)
    {
        if (DRLGROOM_CheckWaypointFlags(pDrlgRoom))
        {
            DRLGACTIVATE_InitializeRoomEx(pDrlgRoom);
            for (D2PresetUnitStrc* pPresetUnit = pDrlgRoom->pPresetUnits; pPresetUnit; pPresetUnit = pPresetUnit->pNext)
            {
                if (pPresetUnit->nUnitType == 2 && pPresetUnit->nIndex < 573 && (DATATBLS_GetObjectsTxtRecord(pPresetUnit->nIndex)->nSubClass & 0x40))
                {
                    *pX = pDrlgRoom->nTileXPos + pPresetUnit->nXpos / 5;
                    *pY = pDrlgRoom->nTileYPos + pPresetUnit->nYpos / 5;
                    return pDrlgRoom;
                }
            }
            return pDrlgRoom;
        }
    }
    return 0;
}

// 0x0066AE70
static D2DrlgRoomStrc* sub_0066AE70_GetRandomRoom(D2DrlgLevelStrc* pLevel)
{
    D2_ASSERT(pLevel, 318);
    D2_ASSERT(pLevel->ptRoomFirst, 319);
    int nRand = ITEMS_RollLimitedRandomNumber(&pLevel->pSeed, pLevel->nRooms);
    D2DrlgRoomStrc* pDrlgRoom = pLevel->ptRoomFirst;
    while (nRand)
    {
        pDrlgRoom = pDrlgRoom->pDrlgRoomNext;
        --nRand;
    }
    return pDrlgRoom;
}

// 0x0066B1F0
static D2DrlgRoomStrc* sub_0066B1F0_GetFirstWarpRoom(D2DrlgLevelStrc* pLevel)
{
    for (D2DrlgRoomStrc* pDrlgRoom = pLevel->ptRoomFirst; pDrlgRoom; pDrlgRoom = pDrlgRoom->pDrlgRoomNext)
    {
        if (pDrlgRoom->dwFlags & 0xFF0)
        {
            int nFlags = 0x10;
            unsigned char nCounter = 0;
            do
            {
                if ((nFlags & pDrlgRoom->dwFlags) && sub_0066AEC0(pLevel->pDrlg, pLevel->eLevelId)[nCounter] != -1)
                {
                    return pDrlgRoom;
                }
                nFlags *= 2;
                ++nCounter;
            }
            while (nFlags & 0xFF0);
        }
    }
    return 0;
}

// 0x0066B2B0
D2ActiveRoomStrc* __fastcall sub_0066B2B0_GetLevelEntryRoom(D2DrlgStrc* pDrlg, int nLevelId, int nTileIndex, int* pX, int* pY)
{
    D2LevelDefBin* pLevelDefBinRecord = 0;
    D2DrlgLevelStrc* pLevel = 0;
    D2DrlgRoomStrc* pDrlgRoom = 0;

    pLevelDefBinRecord = DATATBLS_GetLevelDefRecord(nLevelId);
    *pX = -1;
    *pY = -1;

    pLevel = DRLG_GetLevel(pDrlg, nLevelId);
    if (!pLevel->ptRoomFirst)
    {
        DRLG_InitLevel(pLevel);
    }

    if (pLevelDefBinRecord->dwPosition)
    {
        if (nTileIndex == 13)
        {
            pDrlgRoom = DRLGWARP_GetWaypointRoomExFromLevel(pLevel, pX, pY);
            DRLGACTIVATE_InitializeRoomEx(pDrlgRoom);
            return pDrlgRoom->pRoom;
        }

        pDrlgRoom = pLevel->sub_0066AC40_GetTileRoom(nTileIndex, pX, pY);
        DRLGACTIVATE_InitializeRoomEx(pDrlgRoom);
        return pDrlgRoom->pRoom;
    }

    pDrlgRoom = DRLGWARP_GetWaypointRoomExFromLevel(pLevel, pX, pY);
    if (!pDrlgRoom)
    {
        pDrlgRoom = sub_0066B1F0_GetFirstWarpRoom(pLevel);
        if (!pDrlgRoom)
        {
            const int nX = pLevel->nWidth / 2 + pLevel->nPosX - 2;
            const int nY = pLevel->nHeight / 2 + pLevel->nPosY - 2;
            pDrlgRoom = DRLG_GetRoomExFromLevelAndCoordinates(pLevel, nX, nY);
            if (!pDrlgRoom)
            {
                pDrlgRoom = sub_0066AE70_GetRandomRoom(pLevel);
            }
        }
    }

    if (pDrlgRoom)
    {
        if (*pX == -1 || *pY == -1)
        {
            *pX = pDrlgRoom->nTileXPos + pDrlgRoom->nTileWidth / 2;
            *pY = pDrlgRoom->nTileYPos + pDrlgRoom->nTileHeight / 2;
        }

        DRLGACTIVATE_InitializeRoomEx(pDrlgRoom);
        return pDrlgRoom->pRoom;
    }

    return 0;
}
