#include "D2Client.h"

struct D2DrlgCoordsStrc;
struct D2LightCellStrc;

struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileX;
    int nTileY;
    int nTileWidth;
    int nTileHeight;
};

struct D2LightCellStrc
{
    int nFlags;
    unsigned char nIntensity;
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
};

extern D2LightCellStrc gLightGrid_007B0E68[][48]; // 0x007B0E68
extern int gnLightGridX_007B0A54; // 0x007B0A54
extern int gnLightGridY_007B0A58; // 0x007B0A58
D2UnitStrc* __stdcall sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pnNumRooms); // 0x00619790
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730
void __fastcall sub_00474550_GetRoomLight(D2ActiveRoomStrc* pRoom, int* pIntensity, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue, int a6); // 0x00474550

// 0x004744B0
static __declspec(noinline) void __stdcall sub_004744B0_FillLightGrid(int nX0, int nY0, int nX1, unsigned int nColor, int nY1)
{
    for (int nY = nY0; nY <= nY1; ++nY)
    {
        D2LightCellStrc* pCell = &gLightGrid_007B0E68[nY][nX0];
        for (int nX = nX0; nX <= nX1; ++nX)
        {
            pCell->nFlags = 0;
            pCell->nIntensity = (unsigned char)nColor;
            pCell->nRed = (unsigned char)(nColor >> 8);
            pCell->nGreen = (unsigned char)(nColor >> 16);
            pCell->nBlue = (unsigned char)(nColor >> 24);
            ++pCell;
        }
    }
}

// 0x00474610
void __stdcall sub_00474610_UpdateLightGrid(int bClear)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2ActiveRoomStrc* pRoom;
    if (!pPlayer || (pRoom = UNITS_GetRoom(pPlayer)) == 0 || bClear)
    {
        sub_004744B0_FillLightGrid(0, 0, 47, 0, 47);
        return;
    }

    {
        D2ActiveRoomStrc** ppRoomList;
        int nNumRooms;
        DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);

        unsigned char nRed = 0;
        unsigned char nGreen = 0;
        unsigned char nBlue = 0;
        int nIntensity = 0;
        sub_00474550_GetRoomLight(pRoom, &nIntensity, &nRed, &nGreen, &nBlue, 1);
        sub_004744B0_FillLightGrid(0, 0, 47, nIntensity | (nRed << 8) | (nGreen << 16) | (nBlue << 24), 47);

        for (int i = 0; i < nNumRooms; ++i)
        {
            if (ppRoomList[i] == pRoom)
            {
                continue;
            }

            sub_00474550_GetRoomLight(ppRoomList[i], &nIntensity, &nRed, &nGreen, &nBlue, 1);
            const unsigned int nColor = nIntensity | (nRed << 8) | (nGreen << 16) | (nBlue << 24);

            D2DrlgCoordsStrc tCoords;
            DUNGEON_GetRoomCoordinates(ppRoomList[i], &tCoords);

            int nX0 = tCoords.nSubtileX - gnLightGridX_007B0A54;
            int nX1 = nX0 + tCoords.nSubtileWidth;
            if (nX0 > 48 || nX1 < 0)
            {
                continue;
            }

            int nY0 = tCoords.nSubtileY - gnLightGridY_007B0A58;
            int nY1 = nY0 + tCoords.nSubtileHeight;
            if (nY0 > 48 || nY1 < 0)
            {
                continue;
            }

            if (nX0 < 0)
            {
                nX0 = 0;
            }
            if (nX1 >= 48)
            {
                nX1 = 47;
            }
            if (nY0 < 0)
            {
                nY0 = 0;
            }
            if (nY1 >= 48)
            {
                nY1 = 47;
            }

            sub_004744B0_FillLightGrid(nX0, nY0, nX1, nColor, nY1);
        }
    }
}
