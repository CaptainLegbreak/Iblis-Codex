struct D2GameStrc;
struct D2ClientStrc;
struct D2UnitStrc;
struct D2GSPacketSrv26;
struct D2GSPacketClt15;

struct D2GSPacketSrv26Args
{
    D2GSPacketSrv26* pPacket26;
    D2GSPacketClt15* pPacket15;
    int nUnitId;
};

D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath);
D2GameStrc* __fastcall CLIENTS_GetGame(D2ClientStrc* pClient);
void __fastcall D2GAME_PACKETS_SendPacket0x26_ServerMessage_6FC3DDF0(D2ClientStrc* pClient, D2GSPacketSrv26* pPacket);
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);              // 0x00552F60
int __stdcall SUNIT_GetInteractInfo(D2UnitStrc* pUnit, int* pInteractUnitType, int* pInteractUnitGUID);     // 0x00554100
int __fastcall PLAYERLIST_CheckFlag(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nFlag);

#define UNIT_PLAYER 0

// 0x0054A420
static int __stdcall sub_0054A420_CheckInteractUnit(D2GameStrc* pGame, D2UnitStrc* pExpected, D2UnitStrc* pUnit)
{
    int nUnitType;
    int nUnitGUID;
    if (SUNIT_GetInteractInfo(pUnit, &nUnitType, &nUnitGUID) && nUnitType == UNIT_PLAYER)
    {
        D2UnitStrc* pInteractUnit = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, nUnitGUID);
        if (pInteractUnit && pInteractUnit != pExpected)
        {
            return 1;
        }
    }

    return 0;
}

void __fastcall D2GAME_PACKETS_HandlePlayerMessage_6FC847B0(D2ClientStrc* pClient, void* pArgs)
{
    D2GSPacketSrv26Args* pPacket26Args = (D2GSPacketSrv26Args*)pArgs;
    D2GameStrc* pGame = CLIENTS_GetGame(pClient);
    D2GSPacketSrv26* pPacket26 = pPacket26Args->pPacket26;

    if (pPacket26Args->nUnitId != -1)
    {
        D2UnitStrc* pOtherPlayer = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, pPacket26Args->nUnitId);
        D2UnitStrc* pLocalPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
        if (pOtherPlayer && pLocalPlayer && pOtherPlayer != pLocalPlayer)
        {
            if (PLAYERLIST_CheckFlag(pLocalPlayer, pOtherPlayer, 4) || PLAYERLIST_CheckFlag(pOtherPlayer, pLocalPlayer, 2)
                || sub_0054A420_CheckInteractUnit(pGame, pLocalPlayer, pOtherPlayer) || sub_0054A420_CheckInteractUnit(pGame, pOtherPlayer, pLocalPlayer))
            {
                return;
            }
        }
    }

    D2GAME_PACKETS_SendPacket0x26_ServerMessage_6FC3DDF0(pClient, pPacket26);
}
