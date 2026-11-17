struct D2ClientStrc;
struct D2ActiveRoomStrc;

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2LvlWarpTxt
{
    char unk0x00[0x14];
    int dwExitWalkX;
    int dwExitWalkY;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x04];
    unsigned char nTownLevelId;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x0C - 0x08];
    int dwUnitId;
    int dwAnimMode;
    D2PlayerDataStrc* pPlayerData;
};

struct D2GameStrc
{
    char unk0x00[0xA8];
    unsigned int dwGameFrame;
};

struct D2WarpDelayStrc
{
    char unk0x00[0xDC];
    unsigned int dwWarpDelay;
};

struct D2WarpEventArgStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pUnit;
    D2ActiveRoomStrc* pRoom;
    int unk0x0C;
    D2WarpDelayStrc* pDelay;
    int nX;
    int nY;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" const char szSUnitCppFile_006E10F8[];                                                            // 0x006E10F8
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
void __fastcall D2GAME_PACKETS_SendPacket0x0D_6FC3C920(D2ClientStrc* pClient, unsigned char nPacketId, unsigned char nUnitType, int nUnitId, unsigned char nHitClass, unsigned short nX, unsigned short nY, unsigned char nHitType, unsigned char nLife); // 0x0053B4B0
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
int __fastcall QUESTS_LevelWarpCheck(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nSourceLevel, int nDestinationLevel); // 0x00545B80
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
int __fastcall SUNIT_TeleportUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int a6, int a7); // 0x00554EA0
void __fastcall PLRMODE_ChangeModeToCoords(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int nMode, int nX, int nY, int a7); // 0x005809D0
D2UnitStrc* __stdcall DUNGEON_GetWarpTileFromRoomAndSourceLevelId(D2ActiveRoomStrc* pRoom, int nSourceLevel, D2LvlWarpTxt** ppLvlWarpTxtRecord); // 0x006195A0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
int __stdcall DUNGEON_GetTownLevelIdFromActNo(unsigned char nAct);                                          // 0x0061AB70
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit);                                                        // 0x00620510
void __stdcall UNITS_BlockCollisionPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY);        // 0x00620A70
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit);                                            // 0x00621F20
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0

static __forceinline int sub_E03_GetAnimMode(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwAnimMode : 0;
}

// 0x00550140
void __fastcall sub_00550140_WarpEventCallback(D2WarpEventArgStrc* pArgs)
{
    const unsigned char nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pArgs->pRoom));
    const int nTownLevelId = DUNGEON_GetTownLevelIdFromActNo(nAct);
    D2_ASSERT(nTownLevelId <= 0xFF, 0x46F);

    pArgs->pUnit->pPlayerData->nTownLevelId = nTownLevelId;

    if (sub_E03_GetAnimMode(pArgs->pUnit) == 1)
    {
        UNITS_BlockCollisionPath(pArgs->pUnit, pArgs->pRoom, pArgs->nX, pArgs->nY);
        EVENT_SetEvent(pArgs->pGame, pArgs->pUnit, 1, pArgs->pGame->dwGameFrame + (pArgs->pDelay->dwWarpDelay >> 8) + 1, 0, 0);
    }
}
