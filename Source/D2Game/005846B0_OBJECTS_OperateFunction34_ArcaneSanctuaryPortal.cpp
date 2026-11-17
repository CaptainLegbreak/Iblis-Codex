struct D2ActiveRoomStrc;
struct D2ObjectControlStrc;

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
};

struct D2ObjectsTxt
{
    char unk0x00[0xD8];
    unsigned int dwFrameCnt[8];
};

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
    D2ObjectControlStrc* pObjectregion;
    int nObjectIdx;
};

enum
{
    OBJMODE_NEUTRAL = 0,
    OBJMODE_OPERATING = 1,
    EVENTTYPE_ENDANIM = 1,
    LEVEL_PALACECELLARLEV3 = 54,
    LEVEL_ARCANESANCTUARY = 74,
    ARCANE_TILECALC = 11,
};

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __fastcall LEVEL_WarpUnit(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nDestinationLevelId, int nTileCalc); // 0x0053AEC0
void __fastcall ACT2Q4_SetPortalMode(D2GameStrc* pGame, int nLevelId);                                      // 0x0059BAF0

inline int UNIT_GetAnimMode(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwAnimMode;
    }

    return 0;
}

// 0x005846B0
int __fastcall OBJECTS_OperateFunction34_ArcaneSanctuaryPortal(D2ObjOperateFnStrc* pOp, int nOperate)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pOp->pObject));

    if (UNIT_GetAnimMode(pOp->pObject) == OBJMODE_NEUTRAL)
    {
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPERATING);
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
    }
    else if (nLevelId == LEVEL_ARCANESANCTUARY)
    {
        LEVEL_WarpUnit(pOp->pGame, pOp->pPlayer, LEVEL_PALACECELLARLEV3, 0);
        ACT2Q4_SetPortalMode(pOp->pGame, LEVEL_ARCANESANCTUARY);
    }
    else if (nLevelId == LEVEL_PALACECELLARLEV3)
    {
        LEVEL_WarpUnit(pOp->pGame, pOp->pPlayer, LEVEL_ARCANESANCTUARY, ARCANE_TILECALC);
        ACT2Q4_SetPortalMode(pOp->pGame, LEVEL_PALACECELLARLEV3);
    }

    return 0;
}
