struct D2GameStrc;
struct D2UnitStrc;

typedef void(__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);
void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg);       // 0x005538D0
void __fastcall ITEMS_PlayerIterateCallback_RemoveItem(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);   // 0x00557FA0

// 0x00557FC0
static __forceinline void sub_00557FC0_RemoveItemFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pItem)
{
    SUNIT_IterateLivingPlayers(pGame, ITEMS_PlayerIterateCallback_RemoveItem, pItem);
}

void __fastcall sub_M110_Emit_00557FC0(D2GameStrc* pGame, D2UnitStrc* pItem)
{
    if (pItem)
        sub_00557FC0_RemoveItemFromAllPlayers(pGame, pItem);
}
