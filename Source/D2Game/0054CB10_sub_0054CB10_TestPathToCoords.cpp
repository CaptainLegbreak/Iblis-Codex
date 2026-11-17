struct D2ClientStrc;
struct D2SkillStrc;
struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;
struct D2StatListStrc;

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
    D2DynamicPathStrc* pDynamicPath;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x4A];
    unsigned char nGameType;
    char unk0x6B[0x3D];
    int dwGameFrame;
};

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

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern const D2WarpDelayStrc gWarpDelays_006E1064[3];                                                       // 0x006E1064

void __fastcall CLIENTS_NotifyWarpAttempt(D2GameStrc* pGame, D2UnitStrc* pUnit);                            // 0x00539360
int __fastcall CLIENTS_ShouldDelayWarpAttempt(D2GameStrc* pGame, D2UnitStrc* pUnit);                        // 0x005393F0
void __fastcall sub_005417D0_DirectDated(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int nCustomId, int nCustomParam); // 0x005417D0
void __fastcall sub_6FC81CA0(D2UnitStrc* pPlayer, D2ClientStrc* pClient, int a3);                           // 0x00548010
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                           // 0x00553540
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0
int __fastcall sub_6FCBDFE0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int a6, int a7); // 0x00554EA0
void __fastcall sub_6FC817D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill, int nMode, int nX, int nY, int a7); // 0x005809D0
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
extern "C" void __stdcall sub_006252D0(D2StatListStrc* pStatList, unsigned int dwValue);                 // 0x006252D0
extern "C" void __stdcall sub_00625CE0(D2StatListStrc* pStatList, unsigned int dwValue);                 // 0x00625CE0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __stdcall UNITS_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY);                                           // 0x006417F0
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A10
extern "C" unsigned int __stdcall sub_00648A40(D2DynamicPathStrc* pPath);                                // 0x00648A40
extern "C" unsigned int __stdcall sub_00648A60(D2DynamicPathStrc* pPath);                                // 0x00648A60
extern "C" void __stdcall sub_00648AD0(D2DynamicPathStrc* pPath, unsigned short wX, unsigned short wY);    // 0x00648AD0
extern "C" void __stdcall sub_00648B90_SetPathTarget(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit);   // 0x00648B90
extern "C" unsigned int __stdcall sub_00648CD0(D2DynamicPathStrc* pPath);                                // 0x00648CD0
void __stdcall PATH_SetMoveTestCollisionMask(D2DynamicPathStrc* pDynamicPath, int nMask);                   // 0x00648CE0
void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType);                                // 0x00648CF0
int __stdcall PATH_GetType(D2DynamicPathStrc* pDynamicPath);                                                // 0x00648E30
extern "C" void __stdcall sub_00648E70_SetDistance(D2DynamicPathStrc* pPath, unsigned char nDistance);     // 0x00648E70
unsigned char __stdcall PATH_GetMaxDistance(D2DynamicPathStrc* pDynamicPath);                               // 0x00648EA0
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown);                // 0x00649970
void __fastcall sub_0054CC30_StatRemoveCallback_ToggleStateOff(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

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

    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, ".\\PLAYER\\PlrMsg.cpp", 5654);
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

#include "gen/data/Source/D2Game/0054CB10_sub_0054CB10_TestPathToCoords.inc"
