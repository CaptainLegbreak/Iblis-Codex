#include "D2LevelIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Drlg.h"
#include "D2LevelTxt.h"

#define LEVEL_EFFECT_TICKS 30
#define THRONE_MISSILE 0x27F
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2MissilesTxt;
struct D2MonStatsTxt;
struct D2MonStats2Txt;
struct D2ClientTimedBoxStrc;
struct D2StaticPathStrc;
struct D2MissileStrc;
union D2SeedStrc;
struct D2DrlgCoordsStrc;





extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned int gdwBitMasks[32]; // 0x006CE268

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);



D2ActiveRoomStrc* __cdecl sub_004646A0_GetPlayerRoom(); // 0x004646A0
void __fastcall sub_00474550_GetRoomLight(D2ActiveRoomStrc* pRoom, int* pLight, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue, int nFlag); // 0x00474550
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0


int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0
void __fastcall sub_0046AE50_StartTimedBox(int nFadeIn, int nHold, int nFadeOut, int nLevelId, int bForce); // 0x0046AE50
D2UnitStrc* __fastcall sub_004CDB40_SubmitRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2UnitStrc* __stdcall sub_0065A620_FindUnitInAdjacentRooms(D2ActiveRoomStrc* pRoom, int nUnitType, int nClassId); // 0x0065A620


D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ); // 0x004DA1D0
void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift); // 0x004DA200
void __stdcall sub_004DA2A0_SetMotionVectorC(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift); // 0x004DA2A0
void __fastcall sub_004DA6E0_SetMotionFlag20(D2UnitStrc* pUnit, int bSet); // 0x004DA6E0
void __fastcall sub_004DCD40_ShowTimedHint(void* pOwner, int nDelayA, int nDelayC, unsigned int nIndex, int nArgE, int nDelayF, int nArgG); // 0x004DCD40
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760
extern int gnGlobal_007129CC; // 0x007129CC
extern int gnGlobal_007A7460; // 0x007A7460
extern int gnTimerEnd_007A7464; // 0x007A7464
extern int gnGlobal_007A7468; // 0x007A7468
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void __stdcall sub_0046AF70(D2ActiveRoomStrc* pRoom); // 0x0046AF70
void __cdecl sub_0046AD10_UpdateTimedBox(); // 0x0046AD10
void __cdecl sub_0046C060_DrawCountdown(); // 0x0046C060
extern D2DrlgActStrc* gpGlobal_007A0634; // 0x007A0634
extern D2ClientTimedBoxStrc gtTimedBox_007A742C; // 0x007A742C



unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
D2UnitStrc* __fastcall sub_00466730_SpawnPresetUnit(int nClassId, int nX, int nY, int nUnitType, int nArg); // 0x00466730
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730

// 0x0046ACE0
D2MissilesTxt* __fastcall sub_0046ACE0(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

static __forceinline D2MonStats2Txt* CLIENT_GetMonStats2TxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        const int nMonStatsEx = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
        if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
        }
    }
    return 0;
}

// 0x0046C140
int __fastcall sub_0046C140_TestMonModeFlag(int nMonsterId, int nMode)
{
    D2MonStats2Txt* pMonStats2TxtRecord = CLIENT_GetMonStats2TxtRecord(nMonsterId);
    if (!pMonStats2TxtRecord)
    {
        return 0;
    }
    return pMonStats2TxtRecord->nModeFlags[nMode >> 3] & gdwBitMasks[nMode & 7];
}

D2ClientTimedBoxStrc gtTimedBox_007A742C; // 0x007A742C

// 0x0046AD10
void __cdecl sub_0046AD10_UpdateTimedBox()
{
    unsigned int nLight = 0;
    sub_00474550_GetRoomLight(sub_004646A0_GetPlayerRoom(), (int*)&nLight, &gtTimedBox_007A742C.nColor[0], &gtTimedBox_007A742C.nColor[1], &gtTimedBox_007A742C.nColor[2], 0);

    if (gtTimedBox_007A742C.nTick < gtTimedBox_007A742C.nFadeIn)
    {
        gtTimedBox_007A742C.nValue = (int)(sub_0040B330_Cos(gtTimedBox_007A742C.nAngle) * nLight);
        gtTimedBox_007A742C.nAngle = (gtTimedBox_007A742C.nTick << 7) / gtTimedBox_007A742C.nFadeIn;
    }
    else if (gtTimedBox_007A742C.nTick >= gtTimedBox_007A742C.nTotal - gtTimedBox_007A742C.nFadeOut)
    {
        gtTimedBox_007A742C.nValue = (int)(sub_0040B330_Cos(gtTimedBox_007A742C.nAngle) * nLight);
        const int nElapsed = gtTimedBox_007A742C.nFadeOut - gtTimedBox_007A742C.nTotal + gtTimedBox_007A742C.nTick;
        if (!gtTimedBox_007A742C.nFadeOut)
        {
            gtTimedBox_007A742C.nFadeOut = 0x19;
        }
        gtTimedBox_007A742C.nAngle = 0x80 - (nElapsed << 7) / gtTimedBox_007A742C.nFadeOut;
    }
    else
    {
        gtTimedBox_007A742C.nValue = 0;
    }

    ++gtTimedBox_007A742C.nTick;
    D2ActiveRoomStrc* pRoom = sub_004646A0_GetPlayerRoom();
    int nLevelId = 0;
    if (pRoom)
    {
        nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    }
    if (gtTimedBox_007A742C.nTick > gtTimedBox_007A742C.nTotal || nLevelId != gtTimedBox_007A742C.nLevelId)
    {
        memset(&gtTimedBox_007A742C, 0, sizeof(gtTimedBox_007A742C));
    }
}

inline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    return &sgptDataTables->pMissilesTxt[nMissileId];
}

// 0x0046AEE0
void __cdecl sub_0046AEE0_ObjectMissileTimedBox()
{
    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    if (!pPlayer)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (!pRoom)
    {
        return;
    }

    D2UnitStrc* pObject = sub_0065A620_FindUnitInAdjacentRooms(pRoom, 2, 0x11);
    if (!pObject)
    {
        return;
    }

    const int nX = CLIENTS_GetUnitX(pObject);
    const int nY = CLIENTS_GetUnitY(pObject);
    sub_004CDB40_SubmitRequest(pPlayer, 0x120, nX, nY, 0, 1);

    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(0x120);
    sub_0046AE50_StartTimedBox(pMissilesTxtRecord->dwParam[0], pMissilesTxtRecord->wRange - 2 * pMissilesTxtRecord->dwParam[0], pMissilesTxtRecord->dwParam[0], 4, 1);
}

static __forceinline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

inline int sub_00451F50(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

// 0x0046B0C0
void __cdecl sub_0046B0C0_ResetPulseTick()
{
    gnGlobal_007129CC = 0;
}

// 0x0046B100
void __cdecl sub_0046B100_EventObject98Request()
{
    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    if (!pPlayer)
        return;

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (!pRoom)
        return;

    D2UnitStrc* pObject = sub_0065A620_FindUnitInAdjacentRooms(pRoom, 2, 0x98);
    if (!pObject)
        return;

    sub_004DCD40_ShowTimedHint((void*)0x1252, 0, 0x2D5, 1, 0, 0, 0);
    const int nX = CLIENTS_GetUnitX(pObject);
    const int nY = CLIENTS_GetUnitY(pObject);
    D2UnitStrc* pMissile = sub_004CDB40_SubmitRequest(pPlayer, 0x152, nX, nY, 0, 1);
    if (pMissile)
    {
        sub_004DA1D0_SetMotionVectorA(pMissile, 0, 0, 0x28);
        sub_004DA200_SetMotionVectorB(pMissile, 0, 0, 0x200, 0);
        sub_004DA2A0_SetMotionVectorC(pMissile, 0, 0, 0x46, 0);
        sub_004DA6E0_SetMotionFlag20(pMissile, 1);
    }
    sub_00470390(pObject, 0xB5, 2, 0, 0, 0, 0, 0);
    sub_0046F870(0xD3, 1);
}

// 0x0046B290
void __cdecl sub_0046B290_EventLevel108Request()
{
    gnGlobal_007A7460 = 1;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
        return;

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (!pRoom)
        return;

    if (DUNGEON_GetLevelIdFromRoom(pRoom) != LEVEL_CHAOSSANCTUM)
        return;

    const int nX = CLIENTS_GetUnitX(pPlayer);
    const int nY = CLIENTS_GetUnitY(pPlayer);
    sub_004CDB40_SubmitRequest(pPlayer, 0x174, nX, nY, 0, 1);
    sub_0046F870(0xF3, 1);
}

// 0x0046B300
void __cdecl sub_0046B300_EventObject178Request()
{
    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    if (!pPlayer)
        return;

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (!pRoom)
        return;

    D2UnitStrc* pObject = sub_0065A620_FindUnitInAdjacentRooms(pRoom, 2, 0x178);
    if (!pObject)
        return;

    sub_004DCD40_ShowTimedHint((void*)0x1251, 0, 0x15E, 0, 0, 0, 0);
    sub_004B9A00(0x23, pObject, 0, 0, 0);
    const int nX = CLIENTS_GetUnitX(pObject);
    const int nY = CLIENTS_GetUnitY(pObject);
    D2UnitStrc* pMissile = sub_004CDB40_SubmitRequest(pPlayer, 0x175, nX, nY, 0, 1);
    if (pMissile)
    {
        MISSILE_SetTargetX(pMissile, sub_00451F50(pObject));
        MISSILE_SetTargetY(pMissile, 0);
    }
}

// 0x0046B3A0
void __cdecl sub_0046B3A0_StartTimer()
{
    gnTimerEnd_007A7464 = sub_00410A80_GetTime() + 0x5A;
    gnGlobal_007129D0 = 0;
}

// 0x0046B3C0
void __fastcall sub_0046B3C0_UnitRequest25A(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return;

    D2UnitStrc* pMissile = sub_004CDB40_SubmitRequest(pUnit, 0x25A, CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit), 0, 1);
    if (pMissile)
    {
        MISSILE_SetTargetX(pMissile, 0x19);
    }
}

// 0x0046B440
void __cdecl sub_0046B440_EventObject1CCRequest()
{
    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    if (!pPlayer)
        return;

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (!pRoom)
        return;

    D2UnitStrc* pObject = sub_0065A620_FindUnitInAdjacentRooms(pRoom, 2, 0x1CC);
    if (!pObject)
        return;

    D2UnitStrc* pMissile = sub_004CDB40_SubmitRequest(pPlayer, 0x210, CLIENTS_GetUnitX(pObject), CLIENTS_GetUnitY(pObject), 0, 1);
    if (pMissile)
    {
        MISSILE_SetTargetX(pMissile, 0x19);
    }
}

// 0x0046B520
void __cdecl sub_0046B520_SetFlag7A7468()
{
    gnGlobal_007A7468 = 1;
}

// 0x0046B530
void __fastcall sub_0046B530_SpawnMissileAtObject(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return;

    int nObjectId;
    switch (pUnit->dwClassId)
    {
    case 0x21C:
        nObjectId = 0x1DB;
        break;
    case 0x21D:
        nObjectId = 0x1DC;
        break;
    case 0x21E:
        nObjectId = 0x1DA;
        break;
    default:
        return;
    }

    D2UnitStrc* pObject = sub_0065A620_FindUnitInAdjacentRooms(UNITS_GetRoom(pUnit), 2, nObjectId);
    if (!pObject)
        return;

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x420;
    tMissileParams.nMissile = 0x21D;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nTargetX = CLIENTS_GetUnitXInline(pObject);
    tMissileParams.nTargetY = CLIENTS_GetUnitYInline(pObject);
    tMissileParams.nSkillLevel = 1;
    D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tMissileParams);
    if (pMissile)
    {
        MISSILE_SetTargetX(pMissile, sub_00451F50(pObject));
    }
}

// 0x0046BA90
void __fastcall sub_0046BA90_PlayerRequestAtUnit15B(D2UnitStrc* pUnit)
{
    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    sub_004CDB40_SubmitRequest(pPlayer, 0x15B, CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit), 0, 1);
}

// 0x0046BB10
void __fastcall sub_0046BB10_PlayerRequestAtUnit161(D2UnitStrc* pUnit)
{
    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    sub_004CDB40_SubmitRequest(pPlayer, 0x161, CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit), 0, 1);
}

// 0x0046BB90
void __fastcall sub_0046BB90_PlayerRequestAtUnit16B(D2UnitStrc* pUnit)
{
    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    sub_004CDB40_SubmitRequest(pPlayer, 0x16B, CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit), 0, 1);
}

// 0x0046BC90
void __fastcall sub_0046BC90_RequestAtMonster220(D2UnitStrc* pUnit)
{
    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    D2UnitStrc* pMonster = sub_0065A620_FindUnitInAdjacentRooms(UNITS_GetRoom(pPlayer), 1, 0x220);
    if (pMonster)
    {
        sub_004CDB40_SubmitRequest(pPlayer, 0x271, CLIENTS_GetUnitXInline(pMonster), CLIENTS_GetUnitYInline(pMonster), 0, 1);
    }
}

int gnGlobal_007A745C; // 0x007A745C

int gnGlobal_007A7460; // 0x007A7460

int gnGlobal_007A7468; // 0x007A7468

int gnGlobal_007A746C; // 0x007A746C

// 0x0046B0D0
void __cdecl sub_0046B0D0_ApplyDenOfEvilRooms()
{
    for (D2ActiveRoomStrc* pRoom = DUNGEON_GetRoomFromAct(gpGlobal_007A0634); pRoom; pRoom = pRoom->pRoomNext)
    {
        if (DUNGEON_GetLevelIdFromRoom(pRoom) == LEVEL_DENOFEVIL)
        {
            sub_0046AF70(pRoom);
        }
    }
}

// 0x0046BE60
void __fastcall sub_0046BE60_ApplyDenOfEvilRoom(D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pRoom, 0x344);
    if (DUNGEON_GetLevelIdFromRoom(pRoom) == LEVEL_DENOFEVIL && gnGlobal_007A745C != 0)
    {
        sub_0046AF70(pRoom);
    }
}

// 0x0046BEB0
void __cdecl sub_0046BEB0_UpdateTimers()
{
    if (gtTimedBox_007A742C.bActive)
    {
        sub_0046AD10_UpdateTimedBox();
    }
    if (!gnGlobal_007A745C && gnGlobal_007129CC != -1)
    {
        gnGlobal_007129CC += 1;
        if (gnGlobal_007129CC >= LEVEL_EFFECT_TICKS)
        {
            gnGlobal_007A745C = 1;
            sub_0046B0D0_ApplyDenOfEvilRooms();
        }
    }
    if (gnGlobal_007A7460 && gnGlobal_007129D0 != -1)
    {
        gnGlobal_007129D0 += 1;
        if (gnGlobal_007129D0 >= LEVEL_EFFECT_TICKS)
        {
            gnGlobal_007A7460 = 0;
            gnGlobal_007129D0 = -1;
        }
    }
}

// 0x0046BF30
void __fastcall sub_0046BF30_CheckThroneLevel(D2ActiveRoomStrc* pRoom)
{
    if (!pRoom)
    {
        return;
    }
    switch (DUNGEON_GetLevelIdFromRoom(pRoom))
    {
    case LEVEL_THRONEOFDESTRUCTION:
    case LEVEL_THEWORLDSTONECHAMBER:
        if (!gnGlobal_007A746C && gnGlobal_007A7468)
        {
            D2UnitStrc* pUnit = sub_00463DE0_GetPlayerUnit();
            if (pUnit)
            {
                sub_004C5420_CreateFirstMissile(pUnit, THRONE_MISSILE, 0, 1);
                gnGlobal_007A746C = 1;
            }
        }
        break;
    default:
        gnGlobal_007A746C = 0;
        break;
    }
}

// 0x0046BF90
void __cdecl sub_0046BF90_ResetLevelEffects()
{
    gnGlobal_007A745C = 0;
    gnGlobal_007129CC = -1;
    gnGlobal_007A7460 = 0;
    gnTimerEnd_007A7464 = 0;
    gnTimerUnitId_007129D4 = -1;
    gnGlobal_007A7468 = 0;
    memset(&gtTimedBox_007A742C, 0, sizeof(gtTimedBox_007A742C));
}

// 0x0046C130
void __cdecl sub_0046C130_DrawCountdown()
{
    sub_0046C060_DrawCountdown();
}

#include "gen/data/Source/D2Client/Unknown_0046ACE0.inc"
struct D2UnitStrc;

// 0x0046B1E0
void __cdecl sub_0046B1E0_EventObject95Request()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
        return;

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    D2UnitStrc* pObject = sub_0065A620_FindUnitInAdjacentRooms(pRoom, 2, 0x95);
    if (!pObject)
        return;

    D2UnitStrc* pMissile = sub_004CDB40_SubmitRequest(pPlayer, 0x15E, CLIENTS_GetUnitXInline(pObject), CLIENTS_GetUnitYInline(pObject), 0, 1);
    if (pMissile)
    {
        MISSILE_SetTargetY(pMissile, sub_00451F50(pObject));
    }
}

// 0x0046BD20
static __forceinline int sub_0046BD20_GetChaosLevelLight(unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue)
{
    if (gnGlobal_007A7460 && gnGlobal_007129D0 == -1)
    {
        *pRed = 0xFF;
        *pGreen = 0x40;
        *pBlue = 0x30;
        return 0xA0;
    }
    return 0;
}

int __stdcall sub_M212_Emit_0046BD20(unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue)
{
    return sub_0046BD20_GetChaosLevelLight(pRed, pGreen, pBlue);
}

static __forceinline unsigned __int64 SEED_RollRandomNumberForceInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumberInline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
        return 0;

    if ((nMax - 1) & nMax)
        return (unsigned int)SEED_RollRandomNumberForceInline(pSeed) % nMax;

    return SEED_RollRandomNumberForceInline(pSeed) & (nMax - 1);
}

static void __stdcall sub_0046C1A0_SpawnMonsterInRoom(D2ActiveRoomStrc* pRoom, int nMonsterId, D2SeedStrc* pSeed)
{
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
    const int nX = tCoords.nSubtileX;
    const int nY = tCoords.nSubtileY;
    const int nWidth = tCoords.nSubtileWidth - 1;
    const int nHeight = tCoords.nSubtileHeight - 1;

    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
        return;

    const int nMonStatsEx = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
    if (nMonStatsEx < 0 || nMonStatsEx >= sgptDataTables->nMonStats2TxtRecordCount)
        return;

    D2MonStats2Txt* pMonStats2 = &sgptDataTables->pMonStats2Txt[nMonStatsEx];
    if (!pMonStats2)
        return;

    const int nSize = pMonStats2->nSizeX;
    int nTry;
    int nPosX;
    int nPosY;
    for (nTry = 0; nTry < 10; ++nTry)
    {
        nPosX = nX + SEED_RollLimitedRandomNumberInline(pSeed, nWidth);
        nPosY = nY + SEED_RollLimitedRandomNumberInline(pSeed, nHeight);
        if (!COLLISION_CheckMaskWithSize(pRoom, nPosX, nPosY, nSize, 0x3F11))
            break;
    }

    if (nTry < 10)
        sub_00466730_SpawnPresetUnit(nMonsterId, nPosX, nPosY, 1, 0);
}

// 0x0046C460
void __fastcall sub_0046C460_PopulateRoom(D2ActiveRoomStrc* pRoom)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId)
        return;

    D2LevelsTxt* pLevel = DATATBLS_GetLevelsTxtRecord(nLevelId);
    D2SeedStrc* pSeed = pRoom ? &pRoom->pSeed : 0;
    for (int i = 0; i < 4; ++i)
    {
        if (pLevel->wCMon[i] < 0)
            break;

        if ((unsigned int)SEED_RollRandomNumberForceInline(pSeed) % 100 < (unsigned int)pLevel->wCPct[i])
        {
            const int nMonsterId = pLevel->wCMon[i];
            D2MonStatsTxt* pMonStats = (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount) ? &sgptDataTables->pMonStatsTxt[nMonsterId] : 0;
            int nCount = ITEMS_RollLimitedRandomNumber(pSeed, pMonStats->nMaxGrp - pMonStats->nMinGrp) + pMonStats->nMinGrp;
            if (pLevel->wCAmt[i])
                nCount *= pLevel->wCAmt[i];

            while (nCount > 0)
            {
                sub_0046C1A0_SpawnMonsterInRoom(pRoom, pLevel->wCMon[i], pSeed);
                --nCount;
            }
        }
    }
}
