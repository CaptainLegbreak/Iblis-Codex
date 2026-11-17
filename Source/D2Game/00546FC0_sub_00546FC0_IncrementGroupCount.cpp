struct D2ObjectControlStrc
{
    char unk0x0000[0x1048];
    unsigned short wGroupCount[0x61];
    unsigned short wRoomsTried;
    unsigned short wRoomsNoGroup;
};

struct D2GameStrc
{
    char unk0x0000[0x10F0];
    D2ObjectControlStrc* pObjectControl;
};

// 0x00546FC0
void __fastcall sub_00546FC0_IncrementGroupCount(D2GameStrc* pGame, int nGroup)
{
    if ((unsigned int)nGroup < 100)
    {
        D2ObjectControlStrc* pObjectControl = pGame->pObjectControl;
        ++pObjectControl->wGroupCount[nGroup];
    }
}
