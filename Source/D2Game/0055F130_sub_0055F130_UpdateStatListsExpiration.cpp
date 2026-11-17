struct D2UnitStrc;

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
};

void __stdcall STATLIST_UpdateStatListsExpiration(D2UnitStrc* pUnit, int nFrame);                          // 0x00627460

// 0x0055F130
void __fastcall sub_0055F130_UpdateStatListsExpiration(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    STATLIST_UpdateStatListsExpiration(pUnit, pGame->dwGameFrame);
}
