extern int gdwGlobal_007C8C78;                                                                              // 0x007C8C78
extern int gdwGlobal_0072AE24;                                                                              // 0x0072AE24
int __fastcall sub_00514C90_GetSoundMode();                                                                 // 0x00514C90

// 0x004DF980
int __cdecl sub_004DF980_IsSoundMode1Or2()
{
    if (!gdwGlobal_007C8C78)
    {
        return 0;
    }

    const int nMode = sub_00514C90_GetSoundMode();
    if (nMode == 1 || nMode == 2)
    {
        return 1;
    }

    return 0;
}

// 0x004DF9B0
int __cdecl sub_004DF9B0_IsSoundMode2()
{
    if (!gdwGlobal_007C8C78)
    {
        return 0;
    }

    return sub_00514C90_GetSoundMode() == 2;
}

// 0x004E0690
void __fastcall sub_004E0690_SetSoundTableFlag(int nValue)
{
    gdwGlobal_0072AE24 = nValue;
}
