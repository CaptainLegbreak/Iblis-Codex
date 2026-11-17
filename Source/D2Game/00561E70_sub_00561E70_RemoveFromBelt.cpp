struct D2GameStrc;
struct D2UnitStrc;
struct D2ClientStrc;

#define ITEMACTION_FLAG_BELT 0x20

D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall D2GAME_SendP0x9C_ItemAction_RemoveFromBelt_6FC3EBE0(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, int nFlags); // 0x0053EED0
void __fastcall sub_6FC49090(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem);                     // 0x0055ED30
void __stdcall ITEMS_SetOrRemoveFlag(int* pFlags, int nFlag, int bSet);                                     // 0x006287B0

// 0x00561E70
void __fastcall sub_00561E70_RemoveFromBelt(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 3988);
    int nFlags = 0;
    ITEMS_SetOrRemoveFlag(&nFlags, ITEMACTION_FLAG_BELT, 1);
    D2GAME_SendP0x9C_ItemAction_RemoveFromBelt_6FC3EBE0(pClient, pUnit, pItem, nFlags);
    sub_6FC49090(pGame, pUnit, pItem);
}
