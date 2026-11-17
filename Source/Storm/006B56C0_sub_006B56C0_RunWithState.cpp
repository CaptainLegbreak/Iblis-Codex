struct D2Device006B56C0Strc;
struct D2DeviceVtbl006B56C0Strc
{
    void* unk_00[11];
    long (__stdcall* SetState)(D2Device006B56C0Strc* pDevice, unsigned long nState, unsigned long nValue);
};
struct D2Device006B56C0Strc
{
    D2DeviceVtbl006B56C0Strc* lpVtbl;
};
struct D2RenderConfig006B56C0Strc
{
    unsigned char unk_00[0x10];
    int bFlag10;
};
extern int gbSkip_007C9144; // 0x007C9144
int gbBusy_00970E50;        // 0x00970E50
extern D2RenderConfig006B56C0Strc* gpConfig_007C9148; // 0x007C9148
extern D2Device006B56C0Strc* gpDevice_00970E68; // 0x00970E68
void __cdecl sub_006B3800_Flush(); // 0x006B3800
void __fastcall sub_006BBCE0_Run(int a, int b, int c); // 0x006BBCE0

// 0x006B56C0
void __fastcall sub_006B56C0_RunWithState(int a, int b, int c)
{
    if (!gbSkip_007C9144)
    {
        gbBusy_00970E50 = 1;
        sub_006B3800_Flush();
        if (gpConfig_007C9148->bFlag10)
        {
            gpDevice_00970E68->lpVtbl->SetState(gpDevice_00970E68, 0, 1);
        }
        else
        {
            gpDevice_00970E68->lpVtbl->SetState(gpDevice_00970E68, 0, 9);
        }
        sub_006BBCE0_Run(a, b, c);
        gbBusy_00970E50 = 0;
    }
}
