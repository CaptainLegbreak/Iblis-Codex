#include "D2Game.h"

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2ObjectControlStrc
{
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

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
D2ObjectControlStrc* __fastcall OBJRGN_GetObjectControlFromGame(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x00546FA0
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
unsigned short __stdcall COLLISION_CheckMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, int nSizeX, int nSizeY, int nMask); // 0x0064D800
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);              // 0x00619730
void __stdcall sub_00551150_SpawnFlies(D2GameStrc* pGame, D2UnitStrc* pObject);                            // 0x00551150

struct D2CoordInitStrc
{
    D2CoordStrc* pCoords;
    int nCount;
};

extern D2CoordInitStrc gaCoordInit_00731EB4[];                                                              // 0x00731EB4

static __forceinline unsigned int OBJECTS_RollSeed_Inline(D2SeedStrc* pSeed)
{
    const unsigned __int64 nSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nLowSeed = (unsigned int)nSeed;
    pSeed->nHighSeed = (unsigned int)(nSeed >> 32);
    return (unsigned int)nSeed;
}

static __forceinline unsigned int OBJECTS_RollLimited_Inline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }
    if ((nMax - 1) & nMax)
    {
        return OBJECTS_RollSeed_Inline(pSeed) % nMax;
    }
    return OBJECTS_RollSeed_Inline(pSeed) & (nMax - 1);
}

static int __stdcall sub_005502F0_CanPlaceSmallObject(D2ActiveRoomStrc* pRoom, int nSizeX, int nSizeY, D2CoordStrc* pCoord, D2DrlgCoordsStrc* pDrlgCoords)
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

D2UnitStrc* __fastcall OBJECTS_PopulateFn7_RogueOnStick(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char nDensity, unsigned int nObjectId, unsigned short nProbability)
{
    D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pGame, pRoom);
    if (OBJECTS_RollSeed_Inline(&pObjectControl->pSeed) % 100 > nProbability)
    {
        return 0;
    }

    const int nIndex = ITEMS_RollLimitedRandomNumber(&pObjectControl->pSeed, gnCoordInitCount_00731E64);
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nObjectId);
    const int nSizeX = pObjectsTxtRecord->dwSizeX;
    const int nSizeY = pObjectsTxtRecord->dwSizeY;
    D2DrlgCoordsStrc drlgCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &drlgCoords);

    int nTries = 8;
    D2UnitStrc* pObject = 0;
    D2CoordStrc base;
    while (1)
    {
        base.nX = drlgCoords.nSubtileX + OBJECTS_RollLimited_Inline(&pObjectControl->pSeed, drlgCoords.nSubtileWidth - nSizeX - 1);
        base.nY = drlgCoords.nSubtileY + OBJECTS_RollLimited_Inline(&pObjectControl->pSeed, drlgCoords.nSubtileHeight - nSizeY - 1);
        if (sub_00550220_CanPlaceObject(pRoom, 5, &drlgCoords, &base, 5) == 1)
        {
            break;
        }

        --nTries;
        if (nTries <= 0)
        {
            return 0;
        }
    }

    for (int j = 0; j < gaCoordInit_00731EB4[nIndex].nCount; ++j)
    {
        D2CoordStrc coord;
        coord.nX = base.nX + gaCoordInit_00731EB4[nIndex].pCoords[j].nX;
        coord.nY = base.nY + gaCoordInit_00731EB4[nIndex].pCoords[j].nY;
        if (sub_00550220_CanPlaceObject(pRoom, nSizeY, &drlgCoords, &coord, nSizeX) == 1)
        {
            const unsigned int nClassId = (OBJECTS_RollSeed_Inline(&pObjectControl->pSeed) & 1) + 0x39;
            D2_ASSERT(nClassId <= 0x3A, 0x7DD);
            D2_ASSERT(pRoom, 0x7DE);
            pObject = SUNIT_AllocUnitData(2, nClassId, coord.nX, coord.nY, pGame, pRoom, 1, 0, 0);
            if (pObject)
            {
                sub_00551150_SpawnFlies(pGame, pObject);
            }
        }
    }

    return pObject;
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
            if (sub_005502F0_CanPlaceSmallObject(pRoom, 1, 1, &coord, pDrlgCoords) == 1)
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

static __declspec(noinline) void __stdcall OBJECTS_SpawnArmorStandOrWeaponRack(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pDrlgCoords, int bWeaponRack);

// 0x00552200
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
        for (; nX < nXEnd; nX += 2 * pObjectsTxtRecord->dwSizeX)
        {
            coord.nY = nY;
            coord.nX = nX;
            if (sub_00550220_CanPlaceObject(pRoom, pObjectsTxtRecord->dwSizeY, pDrlgCoords, &coord, pObjectsTxtRecord->dwSizeX) == 1)
            {
                D2_ASSERT(pRoom, 2834);
                SUNIT_AllocUnitData(2, gnArmorStandOrRackIds_00731EA0[nRand + 2 * bWeaponRack], nX, nY, pGame, pRoom, 1, 0, 0);
            }
        }
    }
    else
    {
        const int nX = pDrlgCoords->nSubtileX + 1;
        unsigned int nY = pDrlgCoords->nSubtileY + pObjectsTxtRecord->dwSizeY;
        for (; nY < nYEnd; nY += 2 * pObjectsTxtRecord->dwSizeY)
        {
            coord.nX = nX;
            coord.nY = nY;
            if (sub_00550220_CanPlaceObject(pRoom, pObjectsTxtRecord->dwSizeY, pDrlgCoords, &coord, pObjectsTxtRecord->dwSizeX) == 1)
            {
                D2_ASSERT(pRoom, 2853);
                SUNIT_AllocUnitData(2, gnArmorStandOrRackIds_00731EA0[nRand + 2 * bWeaponRack], nX, nY, pGame, pRoom, 1, 0, 0);
            }
        }
    }
}

int __fastcall OBJECTS_SpawnArmorStand(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pDrlgCoords)
{
    OBJECTS_SpawnArmorStandOrWeaponRack(pGame, pRoom, pDrlgCoords, 0);
    return 1;
}

int __fastcall OBJECTS_SpawnWeaponRack(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pDrlgCoords)
{
    OBJECTS_SpawnArmorStandOrWeaponRack(pGame, pRoom, pDrlgCoords, 1);
    return 1;
}
