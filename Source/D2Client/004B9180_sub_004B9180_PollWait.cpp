extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
void __cdecl sub_0048A6A0_ClearHover();                                                                     // 0x0048A6A0
void __fastcall sub_004B8940_CloseWait(int bReopen);                                                        // 0x004B8940
void __cdecl sub_00477EE0();                                                                                // 0x00477EE0
void __fastcall sub_0044B880_SetValue(int nValue);                                                          // 0x0044B880
void __fastcall sub_0044C860_SetValue(int nValue);                                                          // 0x0044C860
void __cdecl sub_0044D520();                                                                                // 0x0044D520

extern unsigned long gdwTick_007C0E70;                                                                      // 0x007C0E70
extern int gnGlobal_007C0E7C;                                                                               // 0x007C0E7C

// 0x004B9180
int __cdecl sub_004B9180_PollWait()
{
    if (gnGlobal_007C0E7C == 7)
    {
        if (gdwTick_007C0E70 != 0xFFFFFFFF && GetTickCount() > gdwTick_007C0E70 + 30000)
        {
            sub_0048A6A0_ClearHover();
            gnGlobal_007C0E7C = 0;
            sub_004B8940_CloseWait(0);
            sub_00477EE0();
            sub_0044B880_SetValue(0);
            sub_0044C860_SetValue(1);
            sub_0044D520();
        }

        return 1;
    }

    return 0;
}
