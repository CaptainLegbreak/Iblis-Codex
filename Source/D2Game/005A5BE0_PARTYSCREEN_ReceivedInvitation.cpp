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

D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);    // 0x005531C0
void __fastcall PLAYERLIST_AllocPlayerList(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2); // 0x0055B140
void __fastcall sub_6FCBA980(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int a3);                          // 0x0055B3A0
short __fastcall sub_6FCBA9D0(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2);                                 // 0x0055B3F0
void __fastcall sub_6FCBAA20(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2);                                  // 0x0055B440

// 0x005A5BE0
void __fastcall PARTYSCREEN_ReceivedInvitation(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nParam, int* pFailure)
{
    PLAYERLIST_AllocPlayerList(pGame, pPlayer1, pPlayer2);
    PLAYERLIST_AllocPlayerList(pGame, pPlayer2, pPlayer1);

    if (sub_6FCBA9D0(pPlayer1, pPlayer2))
    {
        sub_6FCBAA20(pPlayer1, pPlayer2);
        sub_6FCBAA20(pPlayer2, pPlayer1);
        return;
    }

    sub_6FCBA980(pPlayer1, pPlayer2, 4);
    sub_6FCBA980(pPlayer2, pPlayer1, 2);

    SUNIT_GetClientFromPlayer(pPlayer2, ".\\PLAYER\\PartyScreen.cpp", 306)->PARTYSCREEN_SendEventUpdateToClient(!pPlayer1 ? -1 : pPlayer1->dwUnitId, 5);

    sub_6FCBAA20(pPlayer1, pPlayer2);
    sub_6FCBAA20(pPlayer2, pPlayer1);
}

// 0x005A5C70
void __fastcall PARTYSCREEN_PartyIterate_PlayerLeftParty(D2GameStrc* pGame, D2UnitStrc* pPlayer1, void* pArg)
{
    D2UnitStrc* pPlayer2 = (D2UnitStrc*)pArg;
    if (pPlayer1 != pPlayer2)
    {
        SUNIT_GetClientFromPlayer(pPlayer1, ".\\PLAYER\\PartyScreen.cpp", 323)->PARTYSCREEN_SendEventUpdateToClient(!pPlayer2 ? -1 : pPlayer2->dwUnitId, 9);
    }
}
