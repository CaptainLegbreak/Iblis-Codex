extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg);                    // 0x00455F20
int __cdecl sub_00463DF0();
unsigned char __cdecl sub_00483350_IsCinematicBusy();
void __cdecl sub_004A2300_UpdateQuestPage();
void __cdecl sub_004A23D0_LoadPanelCels();
int __stdcall sub_004A26B0_OpenPanel(int nArg);
int __cdecl sub_004A1760_Forward();
void __stdcall sub_004A3220(int nPage, int nArg);
void __fastcall sub_00478590(char nValue);

int gnGlobal_007BF298;                                                                                      // 0x007BF298
extern int gnGlobal_007C0255;                                                                               // 0x007C0255
extern unsigned long gnGlobal_007C0259;                                                                     // 0x007C0259

// 0x004A3FE0
void __fastcall sub_004A3FE0(int nMode)
{
    if (gnGlobal_007BF298 == 0)
    {
        if (GetTickCount() - gnGlobal_007C0259 < 250)
            return;
        if (sub_00463DF0())
            return;
        if (sub_00483350_IsCinematicBusy())
            return;
        if (sub_00455F20(15, 0, nMode) != 1)
            return;
        sub_004A23D0_LoadPanelCels();
        gnGlobal_007BF298 = 2;
        sub_004A2300_UpdateQuestPage();
        sub_004A3220(gnGlobal_007C0255, 0);
        sub_00478590(0x40);
        return;
    }

    if (gnGlobal_007BF298 == 1)
    {
        gnGlobal_007BF298 = 0;
        if (sub_00483350_IsCinematicBusy())
            return;
        if (sub_00455F20(15, 0, nMode) != 1)
            return;
        sub_004A23D0_LoadPanelCels();
        gnGlobal_007BF298 = 2;
        sub_004A2300_UpdateQuestPage();
        sub_004A3220(gnGlobal_007C0255, 0);
        sub_00478590(0x40);
        return;
    }

    sub_004A26B0_OpenPanel(nMode);
    gnGlobal_007C0259 = GetTickCount();
    sub_004A1760_Forward();
}
