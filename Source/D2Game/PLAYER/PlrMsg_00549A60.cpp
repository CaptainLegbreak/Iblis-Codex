#include "D2Game.h"
#include "D2Constants.h"

#define EVENTTYPE_CANTDOTHAT 14
#define STRCOLOR_RED 1
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2StaticPathStrc;
struct D2GSPacketSrv26;
union D2SeedStrc;
struct D2GSPacketClt5F;
struct D2WarpDelayStrc;

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nX;
    int nY;
};

union D2SeedStrc
{
    struct
    {
        unsigned int nLowSeed;
        unsigned int nHighSeed;
    };
    unsigned __int64 lSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x0C];
    D2SeedStrc pSeed;
    char unk0x28[0x04];
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
    unsigned char unk_30[0x94];
    unsigned int dwFlags;
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

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x4A];
    unsigned char nGameType;
    char unk0x6B[0x3D];
    int dwGameFrame;
};

void __fastcall GAME_ForEachIngameClient(D2GameStrc* pGame, GAME_ForEachIngameClientCallbackPtr pFn, void* pContext); // 0x0052DED0
void __fastcall LEVEL_WarpUnit(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nDestinationLevelId, int nTileCalc); // 0x0053AEC0
void __fastcall D2GAME_PACKETS_SendPacket0x5A_6FC3DEC0(D2ClientStrc* pClient, D2GSPacketSrv5A* pPacket); // 0x0053C850
void __fastcall QUESTS_NPCMessage(D2GameStrc* pGame, D2UnitStrc* pPlayer, int dwNPCGUID, unsigned short nMessage); // 0x005443B0
void __fastcall QUESTS_StatusCallback(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00546040
void __fastcall j_D2GAME_PACKETS_SendPacket0x26_ServerMessage_6FC3DDF0(D2ClientStrc* pClient, void* pMsg); // 0x0054A5C0
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
int __fastcall D2GAME_CreatePortalObject_6FD13DF0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int nDestLevel, D2UnitStrc** ppSourceUnit, int nObjectId, int bPerm); // 0x0056D130
void __fastcall D2GAME_NPC_HireMerc_6FCC9540(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcUnitId, unsigned short a4); // 0x00577FE0
int __fastcall D2GAME_NPC_Repair_6FCC95B0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nNpcGUID, int nItemGUID, unsigned short nUnused, int a6); // 0x00578050
int __fastcall D2GAME_STORES_SellItem_6FCC7680(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcGUID, int nItemGUID, unsigned short nItemMode, int a6); // 0x00579510
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
int __stdcall DUNGEON_GetTownLevelIdFromActNo(unsigned char nAct); // 0x0061AB70
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
void __fastcall SUNIT_AttachSound(D2UnitStrc*, int, int); // 0x00553380

#pragma pack(push, 1)
struct D2GSPacketClt5F
{
    unsigned char nHeader;
    unsigned short nX;
    unsigned short nY;
};

#pragma pack(pop)
struct D2WarpDelayStrc
{
    int nChance;
    int nDelay;
};

enum
{
    STATE_UNINTERRUPTABLE = 54,
    STATE_SYNC_WARPED = 108,
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern const D2WarpDelayStrc gWarpDelays_006E1064[3]; // 0x006E1064
void __fastcall CLIENTS_NotifyWarpAttempt(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00539360
int __fastcall CLIENTS_ShouldDelayWarpAttempt(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005393F0
void __fastcall sub_005417D0_DirectDated(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int nCustomId, int nCustomParam); // 0x005417D0
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
int __fastcall sub_6FCBDFE0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int a6, int a7); // 0x00554EA0
void __fastcall sub_6FC817D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill, int nMode, int nX, int nY, int a7); // 0x005809D0
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
extern "C" void __stdcall sub_006252D0(D2StatListStrc* pStatList, unsigned int dwValue); // 0x006252D0
extern "C" void __stdcall sub_00625CE0(D2StatListStrc* pStatList, unsigned int dwValue); // 0x00625CE0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __stdcall UNITS_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY); // 0x006417F0
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10
extern "C" unsigned int __stdcall sub_00648A40(D2DynamicPathStrc* pPath); // 0x00648A40
extern "C" unsigned int __stdcall sub_00648A60(D2DynamicPathStrc* pPath); // 0x00648A60
extern "C" void __stdcall sub_00648AD0(D2DynamicPathStrc* pPath, unsigned short wX, unsigned short wY); // 0x00648AD0
extern "C" void __stdcall sub_00648B90_SetPathTarget(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit); // 0x00648B90
extern "C" unsigned int __stdcall sub_00648CD0(D2DynamicPathStrc* pPath); // 0x00648CD0
void __stdcall PATH_SetMoveTestCollisionMask(D2DynamicPathStrc* pDynamicPath, int nMask); // 0x00648CE0
void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType); // 0x00648CF0
int __stdcall PATH_GetType(D2DynamicPathStrc* pDynamicPath); // 0x00648E30
extern "C" void __stdcall sub_00648E70_SetDistance(D2DynamicPathStrc* pPath, unsigned char nDistance); // 0x00648E70
unsigned char __stdcall PATH_GetMaxDistance(D2DynamicPathStrc* pDynamicPath); // 0x00648EA0
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970
void __fastcall sub_0054CC30_StatRemoveCallback_ToggleStateOff(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

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
    D2GAME_PACKETS_SendPacket0x5A_6FC3DEC0(UnitGetClient(pUnit, ".\\PLAYER\\PlrMsg.cpp", 1852), &packet5A);
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

static __forceinline int HasSoundFlag(D2UnitStrc* pUnit)
{
    return pUnit ? (pUnit->dwFlags >> 10) & 1 : 0;
}

// 0x0054C070
int __fastcall sub_0054C070_HandleSoundPacket(D2GameStrc* pGame, D2UnitStrc* pUnit, const unsigned char* pPacket, int nSize)
{
    if (nSize != 3)
        return 3;
    unsigned int nSound = *(const unsigned short*)(pPacket + 1);
    if (nSound >= 25 && nSound <= 32)
    {
        if (!HasSoundFlag(pUnit))
            SUNIT_AttachSound(pUnit, nSound, 0);
        else
            return 1;
    }
    return 0;
}

// 0x0054CB10
static int __stdcall sub_0054CB10_TestPathToCoords(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!D2GAME_GetRoom_6FC52070(pRoom, nX, nY))
    {
        return 0;
    }

    if (STATES_CheckState(pUnit, STATE_UNINTERRUPTABLE))
    {
        return 0;
    }

    if (STATES_CheckState(pUnit, STATE_SYNC_WARPED))
    {
        return 0;
    }

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    const int nMask = sub_00648CD0(pPath);
    const int nPathType = PATH_GetType(pPath);
    const unsigned char nNewDistance = PATH_GetMaxDistance(pPath);
    D2UnitStrc* pTargetUnit = SUNIT_GetTargetUnit(pGame, pUnit);
    const int nFirstX = D2COMMON_10175_PathGetFirstPointX(pPath);
    const int nFirstY = D2COMMON_10176_PathGetFirstPointY(pPath);

    PATH_SetMoveTestCollisionMask(pPath, 0x409);
    PATH_SetType(pPath, 15);
    sub_00648E70_SetDistance(pPath, 77);
    sub_00648AD0(pPath, nX, nY);

    int bResult = D2Common_10142(pPath, pUnit, 0);
    if (bResult)
    {
        if (nX == sub_00648A40(pPath) && nY == sub_00648A60(pPath))
        {
            bResult = 1;
        }
        else
        {
            bResult = 0;
        }
    }

    PATH_SetMoveTestCollisionMask(pPath, nMask);
    PATH_SetType(pPath, nPathType);
    sub_00648E70_SetDistance(pPath, nNewDistance);

    if (pTargetUnit)
    {
        sub_00648B90_SetPathTarget(pPath, pTargetUnit);
    }
    else
    {
        sub_00648AD0(pPath, nFirstX, nFirstY);
    }

    return bResult;
}

// 0x0054CC40
static int __stdcall sub_0054CC40_WarpToCoords(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY)
{
    if (!sub_6FCBDFE0(pGame, pUnit, 0, nX, nY, 0, 1))
    {
        return 0;
    }

    CLIENTS_NotifyWarpAttempt(pGame, pUnit);

    int nDelay = 125;
    if (CLIENTS_ShouldDelayWarpAttempt(pGame, pUnit) && !pGame->nGameType)
    {
        D2SeedStrc* pSeed = &pUnit->pSeed;
        const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
        pSeed->lSeed = lSeed;
        int nRand = (unsigned int)lSeed % 100;
        for (int i = 0; i < 3; ++i)
        {
            if (nRand < gWarpDelays_006E1064[i].nChance)
            {
                nDelay = gWarpDelays_006E1064[i].nDelay;
                break;
            }

            nRand -= gWarpDelays_006E1064[i].nChance;
        }
    }

    const int nEndFrame = pGame->dwGameFrame + nDelay;
    STATES_ToggleState(pUnit, STATE_SYNC_WARPED, 1);

    D2StatListStrc* pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nEndFrame, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
    sub_006252D0(pStatList, STATE_SYNC_WARPED);
    sub_00625CE0(pStatList, (unsigned int)sub_0054CC30_StatRemoveCallback_ToggleStateOff);
    D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
    sub_005417D0_DirectDated(pGame, pUnit, 12, nEndFrame, 0, 0);
    return 1;
}

// 0x0054CD50
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x5F_UpdatePlayerPos_6FC88530(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != sizeof(D2GSPacketClt5F))
    {
        return 3;
    }

    const int nX = ((D2GSPacketClt5F*)pPacket)->nX;
    const int nY = ((D2GSPacketClt5F*)pPacket)->nY;

    D2ClientStrc* pClient = UnitGetClient(pUnit, ".\\PLAYER\\PlrMsg.cpp", 5654);
    D2_ASSERT(pClient, 5655);

    if (UNITS_GetUsedSkill(pUnit) || SUNIT_IsDead(pUnit))
    {
        return 0;
    }

    const int nDistance = UNITS_GetDistanceToCoordinates(pUnit, nX, nY);
    if (nDistance < 5)
    {
        return 0;
    }

    if (!STATES_CheckState(pUnit, STATE_SYNC_WARPED) && nDistance >= 15 && nDistance <= 45)
    {
        if (!sub_0054CB10_TestPathToCoords(pGame, pUnit, nX, nY) || !sub_0054CC40_WarpToCoords(pGame, pUnit, nX, nY))
        {
            sub_6FC81CA0(pUnit, pClient, 0);
        }

        return 0;
    }

    if (!SUNIT_GetTargetUnit(pGame, pUnit))
    {
        sub_6FC817D0(pGame, pUnit, 0, ((!pUnit ? 0 : pUnit->dwAnimMode) == 3) + 2, nX, nY, 0);
    }

    return 0;
}

#include "gen/data/Source/D2Game/PLAYER/PlrMsg_00549A60.inc"
