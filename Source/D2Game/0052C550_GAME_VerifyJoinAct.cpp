int __fastcall CLIENTS_CheckState(int nClientId, int nState);                                                // 0x00538930
int __fastcall sub_6FC33EA0(int nClientId, char* szName);                                                   // 0x00538B70

// 0x0052C550
int __fastcall GAME_VerifyJoinAct(int nClientId)
{
    return CLIENTS_CheckState(nClientId, 1) != 0;
}

// 0x0052C8E0
int __fastcall GAME_VerifyEndGame(int nClientId)
{
    return CLIENTS_CheckState(nClientId, 4) != 0;
}

// 0x0052CBE0
int __fastcall GAME_VerifyDisconnect(int nClientId)
{
    char szClientName[16];
    return sub_6FC33EA0(nClientId, szClientName) != 0;
}
