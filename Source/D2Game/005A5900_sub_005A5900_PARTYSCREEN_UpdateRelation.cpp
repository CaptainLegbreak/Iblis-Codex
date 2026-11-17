struct D2GameStrc;
struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};
struct D2ClientStrc
{
    void PARTYSCREEN_SendEventUpdateToClient(int nUnitGUID, unsigned char nType);                           // 0x005A5690
};
struct D2PartyScreenCallbackStrc
{
    D2UnitStrc* pPlayer1;
    D2UnitStrc* pPlayer2;
    unsigned short nPartyId;
};
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);      // 0x005531C0
unsigned short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer);                                             // 0x00554630
void __fastcall PLAYERLIST_AllocPlayerList(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2);   // 0x0055B140
short __fastcall sub_6FCBA9D0(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2);                                   // 0x0055B3F0
void __fastcall sub_6FCBA980(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int a3);                            // 0x0055B3A0
void __fastcall sub_6FCBAA20(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2);                                    // 0x0055B440
void __fastcall sub_6FC3F8F0(D2GameStrc* pGame, D2UnitStrc* pPlayer);                                        // 0x0053DEC0

// 0x005A5900
static void sub_005A5900_PARTYSCREEN_UpdateRelation(D2UnitStrc* pLocalPlayer, D2UnitStrc* pOtherPlayer)
{
    const int nLocalGUID = !pLocalPlayer ? -1 : pLocalPlayer->dwUnitId;
    const int nOtherGUID = !pOtherPlayer ? -1 : pOtherPlayer->dwUnitId;

    if (nLocalGUID == nOtherGUID)
    {
        return;
    }

    const unsigned short nPartyId = SUNIT_GetPartyId(pLocalPlayer);
    if (nPartyId == 0xFFFF)
    {
        if (sub_6FCBA9D0(pOtherPlayer, pLocalPlayer) == 4)
        {
            sub_6FCBA980(pLocalPlayer, pOtherPlayer, 2);
        }
        else
        {
            sub_6FCBA980(pOtherPlayer, pLocalPlayer, 0);
            sub_6FCBA980(pLocalPlayer, pOtherPlayer, 1);
        }
    }
    else
    {
        sub_6FCBA980(pOtherPlayer, pLocalPlayer, 1);
        sub_6FCBA980(pLocalPlayer, pOtherPlayer, 1);
    }
}

// 0x005A5970
void __fastcall sub_6FC7AED0(D2GameStrc* pGame, D2UnitStrc* pLocalPlayer, void* a3)
{
    D2PartyScreenCallbackStrc* pArg = (D2PartyScreenCallbackStrc*)a3;

    const unsigned short nPartyId = SUNIT_GetPartyId(pLocalPlayer);
    PLAYERLIST_AllocPlayerList(pGame, pLocalPlayer, pArg->pPlayer1);
    PLAYERLIST_AllocPlayerList(pGame, pArg->pPlayer1, pLocalPlayer);
    PLAYERLIST_AllocPlayerList(pGame, pLocalPlayer, pArg->pPlayer2);
    PLAYERLIST_AllocPlayerList(pGame, pArg->pPlayer2, pLocalPlayer);

    sub_005A5900_PARTYSCREEN_UpdateRelation(pLocalPlayer, pArg->pPlayer1);
    sub_005A5900_PARTYSCREEN_UpdateRelation(pLocalPlayer, pArg->pPlayer2);

    if (nPartyId == pArg->nPartyId && nPartyId != 0xFFFF && pLocalPlayer != pArg->pPlayer2)
    {
        SUNIT_GetClientFromPlayer(pLocalPlayer, ".\\PLAYER\\PartyScreen.cpp", 183)->PARTYSCREEN_SendEventUpdateToClient(!pArg->pPlayer2 ? -1 : pArg->pPlayer2->dwUnitId, 7);
    }

    sub_6FCBAA20(pLocalPlayer, pArg->pPlayer1);
    sub_6FCBAA20(pLocalPlayer, pArg->pPlayer2);
    sub_6FC3F8F0(pGame, pLocalPlayer);
}
