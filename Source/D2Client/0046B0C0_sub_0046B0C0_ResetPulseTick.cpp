struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nXPos;
    int nYPos;
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
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2MissileStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    D2UnitStrc* pTarget;
    int nMissile;
    int nX;
    int nY;
    int nTargetX;
    int nTargetY;
    int nGfxArg;
    int nVelocity;
    int nSkill;
    int nSkillLevel;
    int nLoops;
    int unk0x38[9];
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
int __cdecl sub_00410A80_GetTime();                                                                         // 0x00410A80
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2UnitStrc* __cdecl sub_00463DE0_GetStoredUnit();                                                           // 0x00463DE0
void __fastcall sub_0046F870(int nItemId, int nArg);                                                         // 0x0046F870
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540
D2UnitStrc* __fastcall sub_004CDB40_SubmitRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ);                    // 0x004DA1D0
void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA200
void __stdcall sub_004DA2A0_SetMotionVectorC(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA2A0
void __fastcall sub_004DA6E0_SetMotionFlag20(D2UnitStrc* pUnit, int bSet);                                  // 0x004DA6E0
void __fastcall sub_004DCD40_ShowTimedHint(void* pOwner, int nDelayA, int nDelayC, unsigned int nIndex, int nArgE, int nDelayF, int nArgG); // 0x004DCD40
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY);                                      // 0x0064A760
D2UnitStrc* __stdcall UNITFINDS_FindUnitInNeighboredRooms(D2ActiveRoomStrc* pRoom, int nUnitType, int nClassId); // 0x0065A620

extern int gnGlobal_007129CC;                                                                               // 0x007129CC
extern int gnGlobal_007129D0;                                                                               // 0x007129D0
extern int gnGlobal_007A7460;                                                                               // 0x007A7460
extern int gnTimerEnd_007A7464;                                                                             // 0x007A7464
extern int gnGlobal_007A7468;                                                                               // 0x007A7468

static __forceinline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
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
    D2UnitStrc* pPlayer = sub_00463DE0_GetStoredUnit();
    if (!pPlayer)
        return;

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (!pRoom)
        return;

    D2UnitStrc* pObject = UNITFINDS_FindUnitInNeighboredRooms(pRoom, 2, 0x98);
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
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (!pPlayer)
        return;

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (!pRoom)
        return;

    if (DUNGEON_GetLevelIdFromRoom(pRoom) != 0x6C)
        return;

    const int nX = CLIENTS_GetUnitX(pPlayer);
    const int nY = CLIENTS_GetUnitY(pPlayer);
    sub_004CDB40_SubmitRequest(pPlayer, 0x174, nX, nY, 0, 1);
    sub_0046F870(0xF3, 1);
}

// 0x0046B300
void __cdecl sub_0046B300_EventObject178Request()
{
    D2UnitStrc* pPlayer = sub_00463DE0_GetStoredUnit();
    if (!pPlayer)
        return;

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (!pRoom)
        return;

    D2UnitStrc* pObject = UNITFINDS_FindUnitInNeighboredRooms(pRoom, 2, 0x178);
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
    D2UnitStrc* pPlayer = sub_00463DE0_GetStoredUnit();
    if (!pPlayer)
        return;

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (!pRoom)
        return;

    D2UnitStrc* pObject = UNITFINDS_FindUnitInNeighboredRooms(pRoom, 2, 0x1CC);
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

    D2UnitStrc* pObject = UNITFINDS_FindUnitInNeighboredRooms(UNITS_GetRoom(pUnit), 2, nObjectId);
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
    D2UnitStrc* pPlayer = sub_00463DE0_GetStoredUnit();
    sub_004CDB40_SubmitRequest(pPlayer, 0x15B, CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit), 0, 1);
}

// 0x0046BB10
void __fastcall sub_0046BB10_PlayerRequestAtUnit161(D2UnitStrc* pUnit)
{
    D2UnitStrc* pPlayer = sub_00463DE0_GetStoredUnit();
    sub_004CDB40_SubmitRequest(pPlayer, 0x161, CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit), 0, 1);
}

// 0x0046BB90
void __fastcall sub_0046BB90_PlayerRequestAtUnit16B(D2UnitStrc* pUnit)
{
    D2UnitStrc* pPlayer = sub_00463DE0_GetStoredUnit();
    sub_004CDB40_SubmitRequest(pPlayer, 0x16B, CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit), 0, 1);
}

// 0x0046BC90
void __fastcall sub_0046BC90_RequestAtMonster220(D2UnitStrc* pUnit)
{
    D2UnitStrc* pPlayer = sub_00463DE0_GetStoredUnit();
    D2UnitStrc* pMonster = UNITFINDS_FindUnitInNeighboredRooms(UNITS_GetRoom(pPlayer), 1, 0x220);
    if (pMonster)
    {
        sub_004CDB40_SubmitRequest(pPlayer, 0x271, CLIENTS_GetUnitXInline(pMonster), CLIENTS_GetUnitYInline(pMonster), 0, 1);
    }
}
