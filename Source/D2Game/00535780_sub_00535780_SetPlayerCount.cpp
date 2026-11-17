int gnVirtualPlayerCount_6FD4DC1C;                                                                          // 0x00883D70

// 0x00535780
void __fastcall sub_00535780_SetPlayerCount(int nPlayers)
{
    if (nPlayers >= 0 && nPlayers <= 8)
    {
        gnVirtualPlayerCount_6FD4DC1C = nPlayers;
    }
}
