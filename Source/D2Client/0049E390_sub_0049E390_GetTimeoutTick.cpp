extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
int __fastcall sub_004B9610_FindHint(int nId);                                                              // 0x004B9610
void __fastcall sub_004B9EF0_ArmHint(int nKey, int nGroup, int nOffset, unsigned int nCount);               // 0x004B9EF0
extern int gnHintId_007BF260;                                                                               // 0x007BF260
extern int gnHintSound_007BF24B;                                                                            // 0x007BF24B

// 0x0049E390
unsigned long __cdecl sub_0049E390_GetTimeoutTick()
{
    return GetTickCount() + 10000;
}

// 0x0049E7F0
void __stdcall sub_0049E7F0_Nop()
{
}

// 0x0049E800
void __stdcall sub_0049E800_Nop()
{
}

// 0x0049E860
void __cdecl sub_0049E860_ClearHint()
{
    if (gnHintId_007BF260)
    {
        const int nHint = sub_004B9610_FindHint(gnHintId_007BF260);
        if (nHint)
            sub_004B9EF0_ArmHint(nHint, 0, 0, 4);
        gnHintId_007BF260 = 0;
    }
    gnHintSound_007BF24B = 0;
}
