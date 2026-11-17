struct D2GameStrc;
struct D2ClientStrc;
struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;

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
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x1C];
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
};

struct D2GSPacketSrv5A
{
    unsigned char nHeader;
    unsigned char nType;
    unsigned char nColor;
    unsigned char dwParam;
    unsigned char dwParam1;
    unsigned char dwParam2;
    unsigned char dwParam3;
    unsigned char nParam;
    char szText[32];
};

struct D2GSPacketSrv26
{
    unsigned char nHeader;
    unsigned char nMessageType;
    unsigned char nLang;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
    unsigned char nMessageColor;
    unsigned char nNameColor;
    char szName[16];
    char szMessage[256];
};

typedef void(__fastcall* GAME_ForEachIngameClientCallbackPtr)(D2ClientStrc* pClient, void* pContext);

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
void __fastcall GAME_ForEachIngameClient(D2GameStrc* pGame, GAME_ForEachIngameClientCallbackPtr pFn, void* pContext); // 0x0052DED0
void __fastcall LEVEL_WarpUnit(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nDestinationLevelId, int nTileCalc); // 0x0053AEC0
void __fastcall D2GAME_PACKETS_SendPacket0x5A_6FC3DEC0(D2ClientStrc* pClient, D2GSPacketSrv5A* pPacket);   // 0x0053C850
void __fastcall QUESTS_NPCMessage(D2GameStrc* pGame, D2UnitStrc* pPlayer, int dwNPCGUID, unsigned short nMessage); // 0x005443B0
void __fastcall QUESTS_StatusCallback(D2GameStrc* pGame, D2UnitStrc* pUnit);                                // 0x00546040
void __fastcall j_D2GAME_PACKETS_SendPacket0x26_ServerMessage_6FC3DDF0(D2ClientStrc* pClient, void* pMsg);  // 0x0054A5C0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
int __fastcall D2GAME_CreatePortalObject_6FD13DF0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int nDestLevel, D2UnitStrc** ppSourceUnit, int nObjectId, int bPerm); // 0x0056D130
int __fastcall sub_6FC91250(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned short nButton, int nGoldAmount); // 0x00568060
void __fastcall D2GAME_NPC_HireMerc_6FCC9540(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcUnitId, unsigned short a4); // 0x00577FE0
int __fastcall D2GAME_NPC_Repair_6FCC95B0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nNpcGUID, int nItemGUID, unsigned short nUnused, int a6); // 0x00578050
int __fastcall D2GAME_STORES_SellItem_6FCC7680(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcGUID, int nItemGUID, unsigned short nItemMode, int a6); // 0x00579510
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
int __stdcall DUNGEON_GetTownLevelIdFromActNo(unsigned char nAct);                                          // 0x0061AB70
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900

#define EVENTTYPE_CANTDOTHAT 14
#define STRCOLOR_RED 1
#define UNIT_PLAYER 0
#define OBJECT_TOWN_PORTAL 59

__forceinline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
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

__forceinline int CLIENTS_GetUnitY(D2UnitStrc* pUnit)
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

// 0x00549A60
void __fastcall sub_00549A60_SendCantDoThat(D2UnitStrc* pUnit)
{
    D2GSPacketSrv5A packet5A = {};
    packet5A.nHeader = 0x5A;
    packet5A.nColor = STRCOLOR_RED;
    *(int*)&packet5A.dwParam = 0;
    packet5A.nType = EVENTTYPE_CANTDOTHAT;
    D2GAME_PACKETS_SendPacket0x5A_6FC3DEC0(SUNIT_GetClientFromPlayer(pUnit, ".\\PLAYER\\PlrMsg.cpp", 1852), &packet5A);
}

// 0x0054A9B0
void __fastcall sub_6FC84CD0(D2GameStrc* pGame, const char* szMessage, unsigned char nColor)
{
    D2GSPacketSrv26 packet26;
    packet26.nMessageColor = nColor;
    packet26.nHeader = 0x26;
    packet26.nMessageType = 4;
    packet26.dwUnitGUID = 0;
    packet26.nUnitType = UNIT_PLAYER;
    memcpy(packet26.szMessage, szMessage, sizeof(packet26.szMessage));
    packet26.nLang = 0;
    GAME_ForEachIngameClient(pGame, j_D2GAME_PACKETS_SendPacket0x26_ServerMessage_6FC3DDF0, &packet26);
}

// 0x0054B830
void __fastcall D2GAME_PlayerChangeAct_6FC867C0(D2GameStrc* pGame, D2UnitStrc* pUnit, int dwDestLvl, int nTileCalc)
{
    const unsigned char nDestAct = DRLG_GetActNoFromLevelId(dwDestLvl);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    const unsigned char nSourceAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));

    if (!dwDestLvl)
    {
        const int nTownLevelId = DUNGEON_GetTownLevelIdFromActNo(nSourceAct);
        LEVEL_WarpUnit(pGame, pUnit, nTownLevelId, nTileCalc);
        return;
    }

    if (nDestAct == nSourceAct)
    {
        const int nX = CLIENTS_GetUnitX(pUnit) - 5;
        const int nY = CLIENTS_GetUnitY(pUnit);
        D2GAME_CreatePortalObject_6FD13DF0(pGame, pUnit, pRoom, nX, nY, dwDestLvl, 0, OBJECT_TOWN_PORTAL, 0);
    }
    else
    {
        LEVEL_WarpUnit(pGame, pUnit, dwDestLvl, nTileCalc);
    }
}

// 0x0054BA90
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x31_QuestMessage_6FC86AB0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    QUESTS_NPCMessage(pGame, pUnit, *(int*)((char*)pPacket + 1), *(unsigned short*)((char*)pPacket + 5));
    return 0;
}

// 0x0054BB20
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x33_SellItemToNpcBuffer_6FC86B30(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 17)
    {
        return 3;
    }

    const int nNpcGUID = *(int*)((char*)pPacket + 1);
    const int nItemGUID = *(int*)((char*)pPacket + 5);
    const unsigned short nItemMode = *(unsigned short*)((char*)pPacket + 9);
    const int nCost = *(int*)((char*)pPacket + 13);
    return D2GAME_STORES_SellItem_6FCC7680(pGame, pUnit, nNpcGUID, nItemGUID, nItemMode, nCost);
}

// 0x0054BB60
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x35_Repair_6FC86B70(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 17)
    {
        return 3;
    }

    D2GAME_NPC_Repair_6FCC95B0(pGame, pUnit, *(int*)((char*)pPacket + 1), *(int*)((char*)pPacket + 5), *(unsigned short*)((char*)pPacket + 9), *(int*)((char*)pPacket + 13));
    return 0;
}

// 0x0054BBD0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x36_HireMerc_6FC86BD0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    D2GAME_NPC_HireMerc_6FCC9540(pGame, pUnit, *(int*)((char*)pPacket + 1), *(unsigned short*)((char*)pPacket + 5));
    return 0;
}

// 0x0054C0C0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x40_RequestQuestData_6FC87460(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 1)
    {
        return 3;
    }

    QUESTS_StatusCallback(pGame, pUnit);
    return 0;
}

// 0x0054C7C0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x4F_ClickButton_6FC881D0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 7)
    {
        return 3;
    }

    const unsigned short nButton = *(unsigned short*)((char*)pPacket + 1);
    const unsigned short nHigh = *(unsigned short*)((char*)pPacket + 3);
    const unsigned short nLow = *(unsigned short*)((char*)pPacket + 5);
    return sub_6FC91250(pGame, pUnit, nButton, (nHigh << 16) | nLow);
}
