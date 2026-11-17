struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2ClientStrc;
struct D2ObjectControlStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x0C - 8];
    unsigned int dwUnitId;
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
    UNIT_OBJECT = 2,
    OBJECT_STASH = 0x10B,
    UPDATEUI_OPENSTASH = 0x10,
};

void __fastcall D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(D2ClientStrc* pClient, unsigned char nUiNo);      // 0x0053CAB0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __stdcall SUNIT_SetInteractInfo(D2UnitStrc* pUnit, int nInteractUnitType, int nInteractUnitGUID);     // 0x00554120
void __fastcall sub_6FC4B830(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x0055FA40
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0

// 0x00564CD0
int __fastcall sub_00564CD0_OperateStash(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (pOp->nObjectIdx == OBJECT_STASH)
    {
        D2ActiveRoomStrc* pPlayerRoom = UNITS_GetRoom(pOp->pPlayer);
        if (pPlayerRoom && DUNGEON_IsRoomInTown(pPlayerRoom))
        {
            D2ActiveRoomStrc* pObjectRoom = UNITS_GetRoom(pOp->pObject);
            if (pObjectRoom && DUNGEON_IsRoomInTown(pObjectRoom))
            {
                SUNIT_SetInteractInfo(pOp->pPlayer, UNIT_OBJECT, !pOp->pObject ? -1 : pOp->pObject->dwUnitId);
                D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pOp->pPlayer, ".\\PLAYER\\PlrTrade.cpp", 101), UPDATEUI_OPENSTASH);
                sub_6FC4B830(pOp->pGame, pOp->pPlayer);
            }
        }
    }

    return 0;
}
