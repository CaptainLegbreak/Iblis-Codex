extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* pAddend);              // 0x006CC208
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* pAddend);              // 0x006CC204

extern int gdwGlobal_007C8C78;                                                                              // 0x007C8C78
long gnGlobal_007C8A74;                                                                                     // 0x007C8A74
int __cdecl sub_00514C90();                                                                                 // 0x00514C90
int __fastcall sub_004E0000_SetSoundMode(int nMode);                                                        // 0x004E0000
void __fastcall sub_00515CE0_SetMasterVolume(int nVolume);                                                  // 0x00515CE0
void __fastcall sub_00515F50_FadeOutMaster(int nTime);                                                      // 0x00515F50

// 0x004E00D0
int __cdecl sub_004E00D0_ToggleSoundMode01()
{
    if (!gdwGlobal_007C8C78 || gnGlobal_007C8A74)
        return 0;

    InterlockedIncrement(&gnGlobal_007C8A74);
    const int nOld = sub_00514C90();
    int nNew;
    if (nOld == 0)
        nNew = 1;
    else
        nNew = 0;
    sub_00515F50_FadeOutMaster(0xB4);
    const int nResult = sub_004E0000_SetSoundMode(nNew);
    if (!nResult)
        sub_004E0000_SetSoundMode(nOld);
    sub_00515CE0_SetMasterVolume(0xFF);
    InterlockedDecrement(&gnGlobal_007C8A74);
    return nResult;
}

// 0x004E0140
int __cdecl sub_004E0140_ToggleSoundMode12()
{
    if (!gdwGlobal_007C8C78 || gnGlobal_007C8A74)
        return 0;

    InterlockedIncrement(&gnGlobal_007C8A74);
    const int nOld = sub_00514C90();
    int nNew;
    if (nOld == 2)
        nNew = 1;
    else
        nNew = 2;
    sub_00515F50_FadeOutMaster(0xB4);
    const int nResult = sub_004E0000_SetSoundMode(nNew);
    if (!nResult)
        sub_004E0000_SetSoundMode(nOld);
    sub_00515CE0_SetMasterVolume(0xFF);
    InterlockedDecrement(&gnGlobal_007C8A74);
    return nResult;
}
