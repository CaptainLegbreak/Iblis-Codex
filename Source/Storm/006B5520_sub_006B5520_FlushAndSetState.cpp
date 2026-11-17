struct D2Device006B5520Strc;
struct D2DeviceVtbl006B5520Strc
{
    void* unk_00[11];
    long (__stdcall* SetState)(D2Device006B5520Strc* pDevice, unsigned long nState, unsigned long nValue);
};
struct D2Device006B5520Strc
{
    D2DeviceVtbl006B5520Strc* lpVtbl;
};
struct D2RenderConfig006B5520Strc
{
    unsigned char unk_00[0x10];
    int bFlag10;
};
extern D2RenderConfig006B5520Strc* gpConfig_007C9148; // 0x007C9148
extern D2Device006B5520Strc* gpDevice_00970E68; // 0x00970E68
void __cdecl sub_006B3800_Flush(); // 0x006B3800

// 0x006B5520
void __cdecl sub_006B5520_FlushAndSetState()
{
    sub_006B3800_Flush();
    if (gpConfig_007C9148->bFlag10)
    {
        gpDevice_00970E68->lpVtbl->SetState(gpDevice_00970E68, 0, 1);
    }
    else
    {
        gpDevice_00970E68->lpVtbl->SetState(gpDevice_00970E68, 0, 9);
    }
}
