#include "D2Game.h"

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0xE4];
    D2UnitStrc* pRoomNext;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
    int nNumClients;
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

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __fastcall sub_00571600(D2UnitStrc* pUnit, D2ClientStrc* pClient);                                     // 0x00571600
void __fastcall sub_005738D0(D2GameStrc* pGame, D2UnitStrc* pUnit);                       // 0x005738D0
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);              // 0x00619730
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
void __fastcall D2GAME_PACKETS_SendPacket0x08_6FC3D160(D2ClientStrc* pClient, int nLevelId, int nX, int nY); // 0x0053BC90

#define UNIT_MONSTER 1

// 0x0053A9B0
void __fastcall LEVEL_RemoveClient(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient)
{
    D2_ASSERT(pRoom, 0x104);

    for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pUnit->pRoomNext)
    {
        sub_00571600(pUnit, pClient);
    }

    DUNGEON_RemoveClientFromRoom(pRoom, pClient);

    if (!pRoom->nNumClients)
    {
        for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pUnit->pRoomNext)
        {
            const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
            switch (nUnitType)
            {
            case UNIT_MONSTER:
                sub_005738D0(pGame, pUnit);
                break;
            }
        }
    }

    D2DrlgCoordsStrc drlgCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &drlgCoords);
    D2GAME_PACKETS_SendPacket0x08_6FC3D160(pClient, DUNGEON_GetLevelIdFromRoom(pRoom), drlgCoords.nTileXPos, drlgCoords.nTileYPos);
}
