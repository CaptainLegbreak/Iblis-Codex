struct D2ClientStrc;
struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;
struct D2WaypointDataStrc;
struct D2InventoryStrc;
struct D2PlayerDataStrc;

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nX;
    int nY;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x0C - 0x08];
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x2C - 0x10 - 4];
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
};

struct D2GameStrc
{
    char unk0x00[0x70];
    int bExpansion;
};

struct D2AiCmdStrc
{
    D2AiCmdStrc* pNextCmd;
    D2AiCmdStrc* pPrevCmd;
    int nCmdParam[5];
};

struct D2DataTablesStrc
{
    char unk0x00[0xC5C];
    int nLevelsTxtRecordCount;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                                // 0x006CC260
D2WaypointDataStrc* __fastcall sub_00547F50(D2GameStrc* pGame, D2UnitStrc* pPlayer);    // 0x00547F50
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);             // 0x00553380
void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit);                                                  // 0x00554190
D2UnitStrc* __fastcall SUNIT_GetInteractUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                         // 0x00554D00
int __fastcall ITEMS_IsInPlayersInventory(D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2InventoryStrc* pInventory); // 0x00557FF0
unsigned int __fastcall PLAYERLIST_GetHostileDelay(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2);             // 0x0055B6C0
D2UnitStrc* __fastcall sub_6FC7E8B0(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int a4);          // 0x00574EC0
void __fastcall sub_00584F60(D2GameStrc* pGame, D2UnitStrc* pUnit, int nWaypointGUID, int nLevelId); // 0x00584F60
void __fastcall AIGENERAL_FreeAllAiCommands(D2GameStrc* pGame, D2UnitStrc* pUnit);                          // 0x0058EDE0
D2AiCmdStrc* __fastcall AIGENERAL_CopyAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd); // 0x0058EF40
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __stdcall WAYPOINTS_GetWaypointNoFromLevelId(int nLevelId, unsigned short* pWaypointNo);                // 0x00660E00
int __stdcall WAYPOINTS_IsActivated(D2WaypointDataStrc* pData, unsigned short wField);                      // 0x00660E50

static __forceinline int sub_E03_PlrGetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static __forceinline int sub_E03_PlrGetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x00548EF0
static __declspec(noinline) int __stdcall sub_6FC83C60(unsigned short nX, unsigned short nY, D2UnitStrc* pUnit, int nMaxDistance)
{
    const int nUnitX = sub_E03_PlrGetUnitX(pUnit);
    const int nUnitY = sub_E03_PlrGetUnitY(pUnit);

    int nXDiff = nUnitX - nX;
    if (nXDiff < 0)
    {
        nXDiff = -nXDiff;
    }

    if (nXDiff <= nMaxDistance)
    {
        int nYDiff = nUnitY - nY;
        if (nYDiff < 0)
        {
            nYDiff = -nYDiff;
        }

        if (nYDiff <= nMaxDistance)
        {
            return 0;
        }
    }

    return 1;
}

static __declspec(noinline) int __stdcall sub_00548F80_CheckTargetUnit(int nMaxDistance, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitType, int nUnitGUID)
{
    D2UnitStrc* pTarget = SUNIT_GetServerUnit(pGame, nUnitType, nUnitGUID);
    if (!pTarget)
    {
        return 1;
    }

    if (nUnitType == 4 && ITEMS_IsInPlayersInventory(pPlayer, pTarget, 0))
    {
        return 0;
    }

    const unsigned char nPlayerAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pPlayer)));
    if (nPlayerAct != DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pTarget))))
    {
        return 2;
    }

    return sub_6FC83C60(sub_E03_PlrGetUnitX(pTarget), sub_E03_PlrGetUnitY(pTarget), pPlayer, nMaxDistance);
}

// 0x0054C430
static __declspec(noinline) int __stdcall sub_0054C430_CommandMerc(int nParam1, int nParam2, int nCommand, D2GameStrc* pGame, D2UnitStrc* pUnit, int nMercGUID)
{
    D2UnitStrc* pMerc = SUNIT_GetServerUnit(pGame, 1, nMercGUID);
    if (!pMerc)
    {
        return 1;
    }

    if (sub_6FC7E8B0(pGame, pUnit, 7, 0) != pMerc)
    {
        return 1;
    }

    AIGENERAL_FreeAllAiCommands(pGame, pMerc);

    D2AiCmdStrc aiCmd;
    aiCmd.nCmdParam[0] = nCommand;
    aiCmd.nCmdParam[1] = nParam1;
    aiCmd.nCmdParam[2] = nParam2;
    AIGENERAL_CopyAiCommand(pGame, pMerc, &aiCmd);

    SUNIT_AttachSound(pMerc, 0xF, pUnit);
    return 0;
}

// 0x0054C4B0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x46_MercInteract_6FC87B00(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pPacket, int nSize)
{
    if (nSize != 13)
    {
        return 3;
    }

    const int nMercGUID = *(int*)(pPacket + 1);
    const unsigned int nUnitType = *(unsigned int*)(pPacket + 9);
    const int nItemGUID = *(int*)(pPacket + 5);
    if (nUnitType >= 6)
    {
        return 2;
    }

    const int nResult = sub_00548F80_CheckTargetUnit(50, pGame, pUnit, nUnitType, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    return sub_0054C430_CommandMerc(nItemGUID, nUnitType, 12, pGame, pUnit, nMercGUID);
}

// 0x0054C520
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x47_MoveMerc_6FC87CE0(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pPacket, int nSize)
{
    if (nSize != 13)
    {
        return 3;
    }

    const int nMercGUID = *(int*)(pPacket + 1);
    const unsigned short nX = *(unsigned short*)(pPacket + 5);
    const unsigned short nY = *(unsigned short*)(pPacket + 9);

    const int nResult = sub_6FC83C60(nX, nY, pUnit, 50);
    if (nResult)
    {
        return nResult;
    }

    sub_0054C430_CommandMerc(nX, nY, 13, pGame, pUnit, nMercGUID);
    return 0;
}
