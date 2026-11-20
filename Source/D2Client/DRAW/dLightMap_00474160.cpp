#include "D2Client.h"
#include "D2Structs.h"

struct D2LightStrc;
struct D2DrlgCoordsStrc;


struct D2LightStrc
{
    int nUnitType;
    unsigned int nUnitId;
    unsigned char bServerSide;
    char unk0x09[3];
    int nMode;
    int nX;
    int nY;
    int nRadius;
    int nTargetRadius;
    int bFixed;
    unsigned char nIntensity;
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    D2LightStrc* pNext;
    int bMaskReady;
    unsigned int* pMask;
};

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
unsigned int __stdcall UNITS_GetPrecisionX(D2UnitStrc* pUnit); // 0x006203B0
unsigned int __stdcall UNITS_GetPrecisionY(D2UnitStrc* pUnit); // 0x00620410

struct D2GridCellStrc
{
    unsigned int nFlag;
    unsigned char nValue0;
    unsigned char nValue1;
    unsigned char f_6;
    unsigned char nValue3;
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

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pnNumRooms); // 0x00619790
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730
void __fastcall sub_00474550_GetRoomLight(D2ActiveRoomStrc* pRoom, int* pIntensity, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue, int bLevelLight); // 0x00474550
extern D2GridCellStrc gtGridCells_007B0E68[]; // 0x007B0E68

static inline int UNITS_IsServerSide(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return (pUnit->dwFlags >> 21) & 1;
    }
    return 0;
}

static inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }
    return pUnit->dwUnitType;
}

static D2LightStrc* gpLights_007B5668; // 0x007B5668

int gnLightsAllocated_007B566C; // 0x007B566C

// 0x00474160
D2LightStrc* __fastcall sub_00474160_MakeLightEntry(D2UnitStrc* pUnit, int nMode, int nRadius, unsigned char nIntensity, unsigned char nRed, unsigned char nGreen, unsigned char nBlue)
{
    if (nRadius > 0)
    {
        if (nRadius >= 18)
        {
            nRadius = 18;
        }

        ++gnLightsAllocated_007B566C;

        D2LightStrc* pLight = (D2LightStrc*)FOG_Alloc(sizeof(D2LightStrc), ".\\DRAW\\dLightMap.cpp", 255, 0);
        pLight->nUnitType = sub_0044BE50(pUnit);
        pLight->nUnitId = !pUnit ? -1 : pUnit->dwUnitId;
        if (UNITS_IsServerSide(pUnit))
        {
            pLight->bServerSide = 1;
        }
        else
        {
            pLight->bServerSide = 0;
        }
        pLight->nX = (UNITS_GetPrecisionX(pUnit) >> 13) + 4;
        unsigned int nPrecisionY = UNITS_GetPrecisionY(pUnit);
        unsigned char nNativeIntensity = *(volatile unsigned char*)&nIntensity;
        int nNativeMode = *(volatile int*)&nMode;
        pLight->nY = (nPrecisionY >> 13) + 4;
        pLight->nRadius = nRadius << 3;
        pLight->nTargetRadius = nRadius << 3;
        pLight->nIntensity = nNativeIntensity;
        pLight->nRed = nRed;
        pLight->nGreen = nGreen;
        pLight->nMode = nNativeMode;
        pLight->bFixed = 0;
        pLight->nBlue = nBlue;
        pLight->pNext = gpLights_007B5668;
        pLight->bMaskReady = 0;
        if (nNativeMode == 2)
        {
            pLight->pMask = (unsigned int*)FOG_Alloc(((2 * nRadius + 1) * (2 * nRadius + 1)) << 2, ".\\DRAW\\dLightMap.cpp", 278, 0);
        }
        else
        {
            pLight->pMask = 0;
        }
        gpLights_007B5668 = pLight;
        return pLight;
    }
    return 0;
}

// build: context sub_004744B0_FillLightGrid
static void __stdcall sub_004744B0_FillLightGrid(int nX0, int nY0, int nX1, int nY1, unsigned int nColor)
{
    for (int nY = nY0; nY <= nY1; ++nY)
    {
        int nX = nX0;
        if (nX <= nX1)
        {
            do
            {
                D2GridCellStrc* pCell = &gtGridCells_007B0E68[nY * 48 + nX];
                pCell->nFlag = 0;
                pCell->nValue0 = nColor;
                pCell->nValue1 = nColor >> 8;
                pCell->f_6 = nColor >> 16;
                ++nX;
                pCell->nValue3 = nColor >> 24;
            } while (nX <= nX1);
        }
    }
}

// build: context sub_00474610_UpdateLightGrid
void __stdcall sub_00474610_UpdateLightGrid(int bReset)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
    {
        sub_004744B0_FillLightGrid(0, 0, 0x2F, 0x2F, 0);
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (!pRoom || bReset)
    {
        sub_004744B0_FillLightGrid(0, 0, 0x2F, 0x2F, 0);
        return;
    }

    D2ActiveRoomStrc** ppRoomList;
    int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);

    int nIntensity = 0;
    unsigned char nRed = 0;
    unsigned char nGreen = 0;
    unsigned char nBlue = 0;
    sub_00474550_GetRoomLight(pRoom, &nIntensity, &nRed, &nGreen, &nBlue, 1);
    sub_004744B0_FillLightGrid(0, 0, 0x2F, 0x2F, (nBlue << 24) | (nGreen << 16) | (nRed << 8) | nIntensity);

    for (int i = 0; i < nNumRooms; ++i)
    {
        if (ppRoomList[i] == pRoom)
            continue;

        sub_00474550_GetRoomLight(ppRoomList[i], &nIntensity, &nRed, &nGreen, &nBlue, 1);
        const unsigned int nColor = (nBlue << 24) | (nGreen << 16) | (nRed << 8) | nIntensity;

        D2DrlgCoordsStrc tCoords;
        DUNGEON_GetRoomCoordinates(ppRoomList[i], &tCoords);
        int nX0 = tCoords.nSubtileX - gnGlobal_007B0A54;
        int nX1 = tCoords.nSubtileWidth + nX0;
        if (nX0 > 0x30 || nX1 < 0)
            continue;

        int nY0 = tCoords.nSubtileY - gnGlobal_007B0A58;
        int nY1 = tCoords.nSubtileHeight + nY0;
        if (nY0 > 0x30 || nY1 < 0)
            continue;

        if (nX0 < 0)
            nX0 = 0;
        if (nX1 >= 0x30)
            nX1 = 0x2F;
        if (nY0 < 0)
            nY0 = 0;
        if (nY1 >= 0x30)
            nY1 = 0x2F;

        sub_004744B0_FillLightGrid(nX0, nY0, nX1, nY1, nColor);
    }
}

// 0x00474790
void __cdecl sub_00474790_ClearLightGrid()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pPlayer)
        UNITS_GetRoom(pPlayer);

    sub_004744B0_FillLightGrid(0, 0, 0x2F, 0x2F, 0);
}
