struct D2GameStrc;
struct D2UnitStrc;

void __fastcall PLAYERLIST_IterateCallback_FreePlayerList(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pArg); // 0x0055B1E0

// 0x0055B780
void __fastcall sub_0055B780_FreePlayerListCallback(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pArg)
{
    PLAYERLIST_IterateCallback_FreePlayerList(pGame, pPlayer, pArg);
}
