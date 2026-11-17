#include "D2Game.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2DrlgCoordsStrc;
struct D2SeedStrc;
struct D2ObjectControlStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x4C];
    int tCoords[8];
    D2SeedStrc pSeed;
};

struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
};

typedef int (__stdcall* D2FarProcFn)();

typedef char (__fastcall* D2ObjectSpawnCallback)(D2GameStrc* pGame, int nArg, int nX, int nY);

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(D2FarProcFn lpfn);
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
int __fastcall OBJECTS_RollRandomNumber(D2SeedStrc* pSeed, int nMin, int nMax); // 0x004BC500
unsigned short __stdcall COLLISION_CheckMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, int nSizeX, int nSizeY, int nMask); // 0x0064D800
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
__declspec(noinline) void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);

struct D2ObjectControlStrc
{
    D2SeedStrc pSeed;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2ObjectsTxt
{
    char unk0x00[0xD0];
    unsigned int dwSizeX;
    unsigned int dwSizeY;
};

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
D2ObjectControlStrc* __fastcall OBJRGN_GetObjectControlFromGame(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x00546FA0
static int __stdcall sub_005502F0_CanPlaceSmallObject(D2ActiveRoomStrc* pRoom, int nSizeX, int nSizeY, D2CoordStrc* pCoord, D2DrlgCoordsStrc* pDrlgCoords); // 0x005502F0

static __forceinline int sub_00550A30_IsInsideRoom(D2DrlgCoordsStrc* pCoords, unsigned short nX, unsigned short nY)
{
    return nX >= pCoords->nSubtileX + 1 && nY >= pCoords->nSubtileY + 1
        && nX < pCoords->nSubtileX + pCoords->nSubtileWidth - 1 && nY < pCoords->nSubtileY + pCoords->nSubtileHeight - 1;
}

// 0x00619730
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords)
{
    D2_ASSERT(pCoords, 209);

    if (!pRoom)
    {
        memset(pCoords, 0x00, sizeof(D2DrlgCoordsStrc));
        return;
    }

    memcpy(pCoords, &pRoom->tCoords, sizeof(D2DrlgCoordsStrc));
}

// 0x00550A30
D2UnitStrc* __stdcall sub_00550A30_SpawnObjectInRoom(D2GameStrc* pGame, int nClassId, int nSizeX, int nSizeY, D2ActiveRoomStrc* pRoom, int nMode, int nArg, D2ObjectSpawnCallback pfnCallback)
{
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);

    int nWidth = tCoords.nSubtileWidth;
    int nHeight = tCoords.nSubtileHeight;
    if (nWidth < nSizeX + 2 || nHeight < nSizeY + 2)
    {
        return 0;
    }

    D2SeedStrc* pSeed = pRoom ? &pRoom->pSeed : 0;
    int nX;
    int nY;
    int i;
    for (i = 0; i < 5; ++i)
    {
        nWidth = tCoords.nSubtileWidth;
        nHeight = tCoords.nSubtileHeight;
        switch (nMode)
        {
        case 1:
            nX = tCoords.nSubtileX + ITEMS_RollLimitedRandomNumber(pSeed, nWidth / 2) + nWidth / 4;
            nY = tCoords.nSubtileY + OBJECTS_RollRandomNumber(pSeed, 1, 2);
            break;

        case 2:
            nX = tCoords.nSubtileX + OBJECTS_RollRandomNumber(pSeed, 1, 2);
            nY = tCoords.nSubtileY + ITEMS_RollLimitedRandomNumber(pSeed, nHeight / 2) + nHeight / 4;
            break;

        default:
            nX = tCoords.nSubtileX + ITEMS_RollLimitedRandomNumber(pSeed, nWidth - nSizeX - 1);
            nY = tCoords.nSubtileY + ITEMS_RollLimitedRandomNumber(pSeed, nHeight - nSizeY - 1);
            break;
        }

        if (nX && nY && sub_00550A30_IsInsideRoom(&tCoords, nX, nY))
        {
            D2_ASSERT(!IsBadCodePtr((D2FarProcFn)pfnCallback), 0x634);

            if (!COLLISION_CheckMaskWithSizeXY(pRoom, nX, nY, nSizeX + 6, nSizeY + 6, 0x3F11))
            {
                if (pfnCallback(pGame, nArg, nX, nY))
                {
                    break;
                }
            }
        }
    }

    if (i >= 5)
    {
        return 0;
    }

    D2_ASSERT(pRoom, 0x64D);
    return SUNIT_AllocUnitData(2, nClassId, nX, nY, pGame, pRoom, 1, 0, 0);
}

static __declspec(noinline) int __stdcall sub_005502F0_CanPlaceSmallObject(D2ActiveRoomStrc* pRoom, int nSizeX, int nSizeY, D2CoordStrc* pCoord, D2DrlgCoordsStrc* pDrlgCoords)
{
    if (pDrlgCoords->nSubtileWidth < 2 || pDrlgCoords->nSubtileHeight < 2)
    {
        return 0;
    }

    if ((unsigned short)pCoord->nX > pDrlgCoords->nSubtileX + 2
        && pDrlgCoords->nSubtileY + 2 < (unsigned short)pCoord->nY
        && (unsigned short)pCoord->nX < pDrlgCoords->nSubtileX - nSizeX + pDrlgCoords->nSubtileWidth
        && (unsigned short)pCoord->nY < pDrlgCoords->nSubtileY - nSizeY + pDrlgCoords->nSubtileHeight
        && !COLLISION_CheckMaskWithSizeXY(pRoom, pCoord->nX, pCoord->nY, nSizeX + 2, nSizeY + 2, 0x3F11))
    {
        return 1;
    }
    return 0;
}

// 0x00552000
int __fastcall OBJECTS_SpawnBarrel(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pDrlgCoords)
{
    const unsigned int nXEnd = pDrlgCoords->nSubtileWidth + pDrlgCoords->nSubtileX + 1;
    const unsigned int nYEnd = pDrlgCoords->nSubtileHeight + pDrlgCoords->nSubtileY + 1;
    int nCounter = 0;
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(7);
    D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pGame, pRoom);
    D2CoordStrc coord;

    int nClassId;

    for (unsigned int nX = pDrlgCoords->nSubtileX; nX < nXEnd; nX += 2)
    {
        unsigned int nY = pDrlgCoords->nSubtileY;
        if (nY < nYEnd)
        {
            coord.nX = nX;
            do
            {
                const unsigned __int64 nSeed = (unsigned __int64)pObjectControl->pSeed.nLowSeed * 0x6AC690C5 + pObjectControl->pSeed.nHighSeed;
                pObjectControl->pSeed.nLowSeed = (unsigned int)nSeed;
                pObjectControl->pSeed.nHighSeed = (unsigned int)(nSeed >> 32);
                if ((unsigned int)nSeed & 3)
                {
                    nClassId = 7;
                }
                else
                {
                    nClassId = 11;
                }
                coord.nY = nY;
                if (sub_005502F0_CanPlaceSmallObject(pRoom, pObjectsTxtRecord->dwSizeX, pObjectsTxtRecord->dwSizeY, &coord, pDrlgCoords) == 1)
                {
                    D2_ASSERT(pRoom, 2696);
                    SUNIT_AllocUnitData(2, nClassId, nX, nY, pGame, pRoom, 1, 0, 0);
                    ++nCounter;
                    if (nCounter >= 32)
                    {
                        return 1;
                    }
                }
                nY += 2;
            }
            while (nY < nYEnd);
        }
    }

    return 1;
}
