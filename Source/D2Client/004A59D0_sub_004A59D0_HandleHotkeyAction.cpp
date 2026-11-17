struct D2HotkeyActionStrc
{
    char unk0x00[0x0A];
    short nValue0A;
    char unk0x0C[0x0C];
    int nState18;
    int nState1C;
};

extern "C" int __cdecl sub_0044DA30_InputBlocked(); // 0x0044DA30
extern "C" void __fastcall sub_004A4500_SetActionValue(int nValue); // 0x004A4500
extern "C" int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00
extern "C" int __stdcall sub_00420290_HandleMsg(void* pMessage); // 0x00420290

// 0x004A59D0
int __stdcall sub_004A59D0_HandleHotkeyAction(D2HotkeyActionStrc* pAction)
{
    if (sub_0044DA30_InputBlocked())
    {
        pAction->nState18 = 0;
        return (int)pAction;
    }

    int nDuration = pAction->nValue0A / 120;
    if (nDuration)
    {
        sub_004A4500_SetActionValue(-nDuration * 2);
        sub_004B9A00(1, 0, 0, 0, 0);
    }
    pAction->nState18 = 1;
    pAction->nState1C = 0;
    return sub_00420290_HandleMsg(pAction);
}
