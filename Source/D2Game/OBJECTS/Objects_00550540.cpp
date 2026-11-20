#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2Txt.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2SeedStrc;
struct D2DrlgCoordsStrc;
struct D2ObjectControlStrc;


struct D2ActiveRoomStrc
{
    char unk0x00[0x6C];
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

typedef char (__fastcall* SPAWNCHECKFN)(D2GameStrc* pGame, int nArg, int nX, int nY);

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(SPAWNCHECKFN lpfn); // 0x006CC34C
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730
unsigned short __stdcall COLLISION_CheckMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, int nSizeX, int nSizeY, int nMask); // 0x0064D800

struct D2ObjectControlStrc
{
    D2SeedStrc pSeed;
};



D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
D2ObjectControlStrc* __fastcall OBJRGN_GetObjectControlFromGame(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x00546FA0
static int __stdcall sub_005502F0_CanPlaceSmallObject(D2ActiveRoomStrc*, int, int, D2DrlgCoordsStrc*, D2CoordStrc*); // 0x005502F0
static int __stdcall sub_00550220_CanPlaceObject(D2ActiveRoomStrc*, int, D2DrlgCoordsStrc*, D2CoordStrc*, int); // 0x00550220
extern int gnValues_00731D50[]; // 0x00731D50
extern int gnValues_00731D5C[]; // 0x00731D5C
extern int gnValues_00731D64[]; // 0x00731D64
extern int gnValues_00731D78[]; // 0x00731D78
extern int gnValues_00731D80[]; // 0x00731D80
extern int gnValues_00731B7C[]; // 0x00731B7C
extern int gnValues_00731B9C[]; // 0x00731B9C
extern int gnCount_00731D88; // 0x00731D88
extern int gnCount_00731D8C; // 0x00731D8C
extern int gnCount_00731D90; // 0x00731D90
extern int gnCount_00731D94; // 0x00731D94
extern int gnCount_00731D98; // 0x00731D98

// build: context SEED_RollRandomNumber
static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// build: context SEED_RollLimitedRandomNumberInl
static __forceinline unsigned int SEED_RollLimitedRandomNumberInl(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber(pSeed) % nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

// 0x0045C3E0
int __fastcall sub_0045C3E0_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    return SEED_RollLimitedRandomNumberInl(pSeed, nMax);
}

// 0x00550540
D2UnitStrc* __stdcall sub_00550540_SpawnObjectInRoom(D2GameStrc* pGame, int nClassId, int nSizeX, int nSizeY, D2ActiveRoomStrc* pRoom, int nArg, SPAWNCHECKFN pfnCheck)
{
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
    if (tCoords.nSubtileWidth < 2 || tCoords.nSubtileHeight < 2 || tCoords.nSubtileWidth <= nSizeX || tCoords.nSubtileHeight <= nSizeY)
    {
        return 0;
    }

    D2SeedStrc* pSeed = pRoom ? &pRoom->pSeed : 0;
    int nX;
    int nY;
    int i;
    for (i = 0; i < 5; ++i)
    {
        nX = tCoords.nSubtileX + sub_0045C3E0_RollLimitedRandomNumber(pSeed, tCoords.nSubtileWidth - nSizeX - 1);
        nY = tCoords.nSubtileY + sub_0045C3E0_RollLimitedRandomNumber(pSeed, tCoords.nSubtileHeight - nSizeY - 1);
        if (nX && nY
            && (unsigned short)nX >= tCoords.nSubtileX + 1 && (unsigned short)nY >= tCoords.nSubtileY + 1
            && (unsigned short)nX < tCoords.nSubtileX + tCoords.nSubtileWidth - 1 && (unsigned short)nY < tCoords.nSubtileY + tCoords.nSubtileHeight - 1)
        {
            D2_ASSERT(!IsBadCodePtr(pfnCheck), 0x588);

            if (!COLLISION_CheckMaskWithSizeXY(pRoom, nX, nY, nSizeX + 6, nSizeY + 6, 0x3F11) && pfnCheck(pGame, nArg, nX, nY))
            {
                break;
            }
        }
    }

    if (i >= 5)
    {
        return 0;
    }

    D2_ASSERT(pRoom, 0x593);
    return SUNIT_AllocUnitData(2, nClassId, nX, nY, pGame, pRoom, 1, 0, 0);
}

static __forceinline unsigned int OBJECTS_RollSeed_Inline(D2SeedStrc* pSeed)
{
    const unsigned __int64 nSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nHighSeed = (unsigned int)(nSeed >> 32);
    pSeed->nLowSeed = (unsigned int)nSeed;
    return (unsigned int)nSeed;
}

static int __stdcall sub_005502F0_CanPlaceSmallObject(D2ActiveRoomStrc* pRoom, int nSizeX, int nSizeY, D2DrlgCoordsStrc* pDrlgCoords, D2CoordStrc* pCoord)
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

// 0x00550220
static int __stdcall sub_00550220_CanPlaceObject(D2ActiveRoomStrc* pRoom, int nSizeY, D2DrlgCoordsStrc* pDrlgCoords, D2CoordStrc* pCoord, int nSizeX)
{
    if (pDrlgCoords->nSubtileWidth < nSizeX + 2 || pDrlgCoords->nSubtileHeight < nSizeY + 2)
    {
        return 0;
    }

    if ((unsigned short)pCoord->nX > pDrlgCoords->nSubtileX + 1
        && (unsigned short)pCoord->nY > pDrlgCoords->nSubtileY + 1
        && (unsigned short)pCoord->nX < pDrlgCoords->nSubtileX - nSizeX + pDrlgCoords->nSubtileWidth - 2
        && (unsigned short)pCoord->nY < pDrlgCoords->nSubtileY - nSizeY + pDrlgCoords->nSubtileHeight - 2
        && !COLLISION_CheckMaskWithSizeXY(pRoom, pCoord->nX, pCoord->nY, nSizeX + 7, nSizeY + 7, 0xC01)
        && !COLLISION_CheckMaskWithSizeXY(pRoom, pCoord->nX, pCoord->nY, nSizeX, nSizeY, 0x3F11))
    {
        return 1;
    }
    return 0;
}

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
                nClassId = ((OBJECTS_RollSeed_Inline(&pObjectControl->pSeed) & 3) == 0) ? 11 : 7;
                coord.nY = nY;
                if (sub_005502F0_CanPlaceSmallObject(pRoom, pObjectsTxtRecord->dwSizeX, pObjectsTxtRecord->dwSizeY, pDrlgCoords, &coord) == 1)
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

// 0x00552140
int __fastcall OBJECTS_SpawnRandomItemGrid(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pDrlgCoords)
{
    const unsigned int nXEnd = pDrlgCoords->nSubtileX + (pDrlgCoords->nSubtileWidth > 12 ? 12 : pDrlgCoords->nSubtileWidth);
    const unsigned int nYEnd = pDrlgCoords->nSubtileY + (pDrlgCoords->nSubtileHeight > 12 ? 12 : pDrlgCoords->nSubtileHeight);
    int nCounter = 0;

    for (unsigned int nX = pDrlgCoords->nSubtileX + 1; nX < nXEnd; nX += 2)
    {
        for (unsigned int nY = pDrlgCoords->nSubtileY + 1; nY < nYEnd; nY += 2)
        {
            D2CoordStrc coord;
            coord.nX = nX;
            coord.nY = nY;
            if (sub_005502F0_CanPlaceSmallObject(pRoom, 1, 1, pDrlgCoords, &coord) == 1)
            {
                ITEMS_DropRandomItemAtCoordinates(pGame, pRoom, &coord, 0);
                ++nCounter;
                if (nCounter >= 32)
                {
                    return 1;
                }
            }
        }
    }

    return 1;
}

static void __stdcall OBJECTS_SpawnArmorStandOrWeaponRack(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pDrlgCoords, int bWeaponRack)
{
    if (bWeaponRack >= gnArmorStandOrRackCount_00731EB0)
    {
        return;
    }

    D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pGame, pRoom);
    const int nRand = OBJECTS_RollSeed_Inline(&pObjectControl->pSeed) & 1;
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(gnArmorStandOrRackIds_00731EA0[nRand + 2 * bWeaponRack]);
    const unsigned int nXEnd = pDrlgCoords->nSubtileWidth - pObjectsTxtRecord->dwSizeX + pDrlgCoords->nSubtileX;
    const unsigned int nYEnd = pDrlgCoords->nSubtileHeight - pObjectsTxtRecord->dwSizeY + pDrlgCoords->nSubtileY;
    D2CoordStrc coord;

    if (nRand == 0)
    {
        const int nY = pDrlgCoords->nSubtileY + 1;
        unsigned int nX = pDrlgCoords->nSubtileX + pObjectsTxtRecord->dwSizeX;
        if (nX < nXEnd)
        {
            coord.nY = nY;
            do
            {
                coord.nX = nX;
                if (sub_00550220_CanPlaceObject(pRoom, pObjectsTxtRecord->dwSizeY, pDrlgCoords, &coord, pObjectsTxtRecord->dwSizeX) == 1)
                {
                    D2_ASSERT(pRoom, 2834);
                    SUNIT_AllocUnitData(2, gnArmorStandOrRackIds_00731EA0[nRand + 2 * bWeaponRack], nX, nY, pGame, pRoom, 1, 0, 0);
                }
                nX += 2 * pObjectsTxtRecord->dwSizeX;
            }
            while (nX < nXEnd);
        }
    }
    else
    {
        const int nX = pDrlgCoords->nSubtileX + 1;
        unsigned int nY = pDrlgCoords->nSubtileY + pObjectsTxtRecord->dwSizeY;
        if (nY < nYEnd)
        {
            coord.nX = nX;
            do
            {
                coord.nY = nY;
                if (sub_00550220_CanPlaceObject(pRoom, pObjectsTxtRecord->dwSizeY, pDrlgCoords, &coord, pObjectsTxtRecord->dwSizeX) == 1)
                {
                    D2_ASSERT(pRoom, 2853);
                    SUNIT_AllocUnitData(2, gnArmorStandOrRackIds_00731EA0[nRand + 2 * bWeaponRack], nX, nY, pGame, pRoom, 1, 0, 0);
                }
                nY += 2 * pObjectsTxtRecord->dwSizeY;
            }
            while (nY < nYEnd);
        }
    }
}

// build: context OBJECTS_SpawnArmorStand
int __fastcall OBJECTS_SpawnArmorStand(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pDrlgCoords)
{
    OBJECTS_SpawnArmorStandOrWeaponRack(pGame, pRoom, pDrlgCoords, 0);
    return 1;
}

// build: context OBJECTS_SpawnWeaponRack
int __fastcall OBJECTS_SpawnWeaponRack(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pDrlgCoords)
{
    OBJECTS_SpawnArmorStandOrWeaponRack(pGame, pRoom, pDrlgCoords, 1);
    return 1;
}

static __forceinline unsigned int RollLimited(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0) return 0;
    if ((nMax - 1) & nMax) return OBJECTS_RollSeed_Inline(pSeed) % nMax;
    return OBJECTS_RollSeed_Inline(pSeed) & (nMax - 1);
}

// 0x00550C20
D2UnitStrc* __fastcall sub_00550C20_PopulateClusters(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char nDensity, int nObjectId, unsigned short nProbability)
{
    D2CoordStrc position;
    D2ObjectsTxt* pRecord = DATATBLS_GetObjectsTxtRecord(nObjectId);
    int nSizeX = pRecord->dwSizeX;
    int nSizeY = pRecord->dwSizeY;
    D2DrlgCoordsStrc roomCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &roomCoords);
    D2ObjectControlStrc* pControl = OBJRGN_GetObjectControlFromGame(pGame, pRoom);
    if (OBJECTS_RollSeed_Inline(&pControl->pSeed) % 100 > nProbability) return 0;
    int nTries = 12;
    bool bSmall = false;
    int* pIds;
    int nRange, nBase;
    if (nObjectId == 3) {
        pIds = gnValues_00731D5C; nObjectId = gnCount_00731D8C; nTries = 18; nRange = 5; nBase = 5;
    } else if (nObjectId == 79 || nObjectId == 1) {
        pIds = gnValues_00731D50; nObjectId = gnCount_00731D88; nRange = 5; nBase = 5;
    } else if (nObjectId == 4) {
        pIds = gnValues_00731D64; nObjectId = gnCount_00731D90; nRange = 0; nBase = 1; bSmall = true;
    } else if (nObjectId == 89) {
        pIds = gnValues_00731D78; nObjectId = gnCount_00731D94; nRange = 5; nBase = 5;
    } else if (nObjectId == 208 || nObjectId == 209) {
        pIds = gnValues_00731D80; nObjectId = gnCount_00731D98; nRange = 0; nBase = 1; bSmall = true;
    } else return 0;
    int nClusters = ((roomCoords.nSubtileWidth * roomCoords.nSubtileHeight >> 7) * nDensity) >> 8;
    D2UnitStrc* pResult = 0;
    while (nClusters > 0) {
        if (nTries <= 0) break;
        int nClassId = pIds[RollLimited(&pControl->pSeed, nObjectId)];
        position.nX = roomCoords.nSubtileX + RollLimited(&pControl->pSeed, roomCoords.nSubtileWidth - nSizeX - 1);
        position.nY = roomCoords.nSubtileY + RollLimited(&pControl->pSeed, roomCoords.nSubtileHeight - nSizeY - 1);
        D2CoordStrc coord;
        coord.nX = position.nX; coord.nY = position.nY;
        if (sub_00550220_CanPlaceObject(pRoom, pRecord->dwSizeY, &roomCoords, &coord, pRecord->dwSizeX) == 1) {
            D2_ASSERT(pRoom, 0x714);
            SUNIT_AllocUnitData(2, nClassId, position.nX, position.nY, pGame, pRoom, 1, 0, 0);
            int nClusterTries = 1;
            int bSuccess = 1;
            pResult = 0;
            while (!RollLimited(&pControl->pSeed, nClusterTries >> 1) && bSuccess) {
                int i = 0;
                bSuccess = 0;
                int nLimit = 3 * (nClusters < 4 ? 4 : nClusters);
                while (!bSuccess) {
                    if (i >= nLimit) break;
                    nClassId = OBJECTS_RollSeed_Inline(&pControl->pSeed) & 7;
                    position.nX += 2 * gnValues_00731B7C[nClassId] * (nBase + RollLimited(&pControl->pSeed, nRange));
                    position.nY += 2 * gnValues_00731B9C[nClassId] * (nBase + RollLimited(&pControl->pSeed, nRange));
                    coord.nX = position.nX; coord.nY = position.nY;
                    if (bSmall) bSuccess = sub_005502F0_CanPlaceSmallObject(pRoom, pRecord->dwSizeX, pRecord->dwSizeY, &roomCoords, &coord);
                    else bSuccess = sub_00550220_CanPlaceObject(pRoom, pRecord->dwSizeY, &roomCoords, &coord, pRecord->dwSizeX);
                    ++i;

                }
                if (bSuccess) {
                    nClassId = pIds[RollLimited(&pControl->pSeed, nObjectId)];
                    pResult = SUNIT_AllocUnitData(2, nClassId, position.nX, position.nY, pGame, pRoom, 1, 0, 0);
                    ++nClusterTries;
                }
            }
            --nClusters;
        }
        --nTries;
    }
    return pResult;
}

#include "gen/data/Source/D2Game/OBJECTS/Objects_00550540.inc"
