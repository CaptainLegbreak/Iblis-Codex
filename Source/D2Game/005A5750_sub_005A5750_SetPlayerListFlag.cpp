struct D2GameStrc;

struct D2UnitStrc
{
    int dwUnitType;
    unsigned int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

struct D2ClientStrc
{
    void PARTYSCREEN_SendEventUpdateToClient(int nUnitGUID, unsigned char nType);                           // 0x005A5690
};

D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);    // 0x005531C0
int __fastcall CLIENTS_CheckFlag(D2ClientStrc* pClient, int nFlag);                                         // 0x00538670
void __fastcall PLAYERLIST_AllocPlayerList(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2);  // 0x0055B140
int __fastcall PLAYERLIST_CheckFlag(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nFlag);                 // 0x0055B300
void __fastcall PLAYERLIST_ToggleFlag(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nFlag, int bSet); // 0x0055B260
void __fastcall SCMD_Send0x75_PartyRosterUpdate(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2);               // 0x0053DA90

// 0x005A5750
static void __stdcall sub_005A5750_SetPlayerListFlag(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, unsigned short nFlag, int nParam)
{
    PLAYERLIST_AllocPlayerList(pGame, pPlayer1, pPlayer2);
    PLAYERLIST_AllocPlayerList(pGame, pPlayer2, pPlayer1);
    if (PLAYERLIST_CheckFlag(pPlayer1, pPlayer2, nFlag) != nParam)
    {
        PLAYERLIST_ToggleFlag(pGame, pPlayer1, pPlayer2, nFlag, nParam);
    }

    SCMD_Send0x75_PartyRosterUpdate(pPlayer1, pPlayer2);
    SCMD_Send0x75_PartyRosterUpdate(pPlayer2, pPlayer1);
}

static bool IsFemaleClass(D2UnitStrc* pUnit)
{
    switch (pUnit->dwClassId)
    {
    case 0:
    case 1:
    case 6:
        return true;
    }
    return false;
}

// 0x005A57B0
void __fastcall PARTYSCREEN_ToggleLootability(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nParam, int* pFailure)
{
    if (!CLIENTS_CheckFlag(SUNIT_GetClientFromPlayer(pPlayer1, ".\\PLAYER\\PartyScreen.cpp", 74), 4))
    {
        return;
    }

    sub_005A5750_SetPlayerListFlag(pGame, pPlayer1, pPlayer2, 1, nParam);

    int nType;
    if (pPlayer1 && IsFemaleClass(pPlayer1))
    {
        nType = nParam != 0 ? 2 : 11;
    }
    else
    {
        nType = nParam != 0 ? 1 : 10;
    }

    SUNIT_GetClientFromPlayer(pPlayer2, ".\\PLAYER\\PartyScreen.cpp", 101)->PARTYSCREEN_SendEventUpdateToClient(!pPlayer1 ? -1 : pPlayer1->dwUnitId, nType);
}
