struct D2ActiveRoomStrc;
struct D2ClientStrc;
struct D2DynamicPathStrc;

struct D2GameStrc
{
    char unk0x00[0xA8];
    unsigned int dwGameFrame;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x28];
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0x98];
    unsigned int dwFlagEx;
};

struct D2PlayerDataStrc
{
    char unk0x00[0xA0];
    unsigned char unk0xA0;
    char unk0xA1[3];
    unsigned int unk0xA4;
    int unk0xA8[40];
    int unk0x148;
    int unk0x14C;
};

struct D2CoordStrc
{
    int nX;
    int nY;
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

typedef int (__fastcall* EventTimerCallback)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int a4, int a5);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
void __fastcall D2GAME_PACKETS_SendPacket0x07_6FC3D120(D2ClientStrc* pClient, int nAreaId, unsigned short nTileX, unsigned short nTileY); // 0x0053BC50
void __fastcall sub_00541800(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, EventTimerCallback pfCallBack, int nSkillId, int nSkillLevel); // 0x00541800
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
int __fastcall sub_6FCBDF90(D2GameStrc* pGame, D2UnitStrc* pPlayer, int a3, int a4, int a5);                // 0x00554570
void __fastcall sub_6FCBB190(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom);                // 0x00554670
void __fastcall sub_6FC7E310(D2GameStrc* pGame, D2UnitStrc* pPlayer, int a3, int a4);                       // 0x005754B0
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);              // 0x00619730
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit);                                                        // 0x00620510
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit);                                                     // 0x0064C040
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0
int __stdcall sub_00650BE0_PlaceUnit(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00650BE0

// 0x00554EA0
int __fastcall sub_6FCBDFE0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pInputRoom, int nX, int nY, int a6, int a7)
{
    D2_ASSERT(pUnit, 0xC21);
    D2ActiveRoomStrc* pUnitRoom = UNITS_GetRoom(pUnit);
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2_ASSERT(pPath, 0xC25);

    D2ActiveRoomStrc* pRoom = pInputRoom;
    D2CoordStrc tCoords;
    tCoords.nX = nX;
    tCoords.nY = nY;
    if (!pRoom)
    {
        pRoom = D2GAME_GetRoom_6FC52070(0, tCoords.nX, tCoords.nY);
        if (!pRoom)
        {
            pRoom = D2GAME_GetRoom_6FC52070(pUnitRoom, tCoords.nX, tCoords.nY);
        }
    }

    if (!pRoom)
    {
        return 0;
    }

    if (!a6)
    {
        pRoom = COLLISION_GetFreeCoordinates(pRoom, &tCoords, UNITS_GetUnitSizeX(pUnit), 0x1C09, 0);
    }

    if (!pRoom)
    {
        return 0;
    }

    if (!sub_00650BE0_PlaceUnit(pPath, pUnit, pRoom, tCoords.nX, tCoords.nY))
    {
        return 0;
    }

    if (pUnit->dwUnitType == 0)
    {
        D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, ".\\UNIT\\SUnit.cpp", 0xC3C);
        D2DrlgCoordsStrc tDrlgCoords;
        DUNGEON_GetRoomCoordinates(pRoom, &tDrlgCoords);
        D2GAME_PACKETS_SendPacket0x07_6FC3D120(pClient, DUNGEON_GetLevelIdFromRoom(pRoom), (unsigned short)tDrlgCoords.nTileXPos, (unsigned short)tDrlgCoords.nTileYPos);

        UNITROOM_RefreshUnit(pUnit);
        if (a7)
        {
            pUnit->dwFlagEx |= 0x800;
        }
        else
        {
            pUnit->dwFlagEx |= 0x10000;
        }

        sub_6FCBB190(pGame, pUnit, 0);

        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
        const unsigned char nIndex = pPlayerData->unk0xA0;
        pPlayerData->unk0x148 = tCoords.nX;
        pPlayerData->unk0x14C = tCoords.nY;
        pPlayerData->unk0xA4 = GetTickCount();
        pPlayerData->unk0xA8[2 * nIndex] = tCoords.nX;
        pPlayerData->unk0xA8[2 * nIndex + 1] = tCoords.nY;
        pPlayerData->unk0xA0 += 1;
        if (pPlayerData->unk0xA0 >= 20)
        {
            pPlayerData->unk0xA0 = 0;
        }

        sub_00541800(pGame, pUnit, 14, pGame->dwGameFrame + 50, sub_6FCBDF90, 0, 0);
        sub_6FC7E310(pGame, pUnit, tCoords.nX, tCoords.nY);
    }
    else
    {
        UNITROOM_RefreshUnit(pUnit);
        if (a7)
        {
            pUnit->dwFlagEx |= 0x800;
        }
        else
        {
            pUnit->dwFlagEx |= 0x10000;
        }

        sub_6FCBB190(pGame, pUnit, 0);
    }

    return 1;
}
