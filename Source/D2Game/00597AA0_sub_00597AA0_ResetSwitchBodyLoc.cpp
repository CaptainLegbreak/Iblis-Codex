struct D2GameStrc;
struct D2UnitStrc;

#define IFLAG_SWITCHOUT 0x00000080

void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit);                           // 0x00557FD0
void __fastcall D2GAME_ResetSomeItemFlags_6FC415F0(D2GameStrc* pGame, D2UnitStrc* pItem);                   // 0x005979B0
void __stdcall ITEMS_SetBodyLocation(D2UnitStrc* pItem, unsigned char nBodyLoc);                            // 0x00627D70
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);  // 0x006280A0
int __stdcall ITEMS_CheckItemCMDFlag(D2UnitStrc* pItem, int nFlag);                                        // 0x00628140

// 0x00597AA0
static void sub_00597AA0_ResetSwitchBodyLoc(D2UnitStrc* pItem)
{
    if (ITEMS_CheckItemCMDFlag(pItem, 0x10) || ITEMS_CheckItemCMDFlag(pItem, 0x4000))
    {
        ITEMS_SetBodyLocation(pItem, 0);
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x20) && ITEMS_CheckItemFlag(pItem, IFLAG_SWITCHOUT, 384, ".\\INVENTORY\\InvMode.cpp"))
    {
        ITEMS_SetBodyLocation(pItem, 0);
    }
}

void __fastcall sub_M105_Emit_00597AA0(D2GameStrc* pGame, D2UnitStrc* pItem)
{
    if (pItem)
    {
        sub_00597AA0_ResetSwitchBodyLoc(pItem);
        D2GAME_ResetSomeItemFlags_6FC415F0(pGame, pItem);
        ITEMS_RemoveFromAllPlayers(pGame, pItem);
    }
}
