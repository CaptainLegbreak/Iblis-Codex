int __cdecl sub_00449B70_Receive();                                                                         // 0x00449B70
int __cdecl sub_00449C50();                                                                                 // 0x00449C50
int __cdecl sub_00449C70();                                                                                 // 0x00449C70
int __cdecl sub_00449B30_QueryAddress();                                                                    // 0x00449B30
void __stdcall sub_00449C60_SetValue(int nValue);                                                           // 0x00449C60
void __stdcall sub_00449C80_SetValue(int nValue);                                                           // 0x00449C80
int __fastcall sub_004F9190();                                                            // 0x004F9190
void __cdecl sub_0042F3F0_DestroyControls();                                                                // 0x0042F3F0
void __cdecl sub_00430620_UpdateNameOk();                                                                   // 0x00430620
void __cdecl sub_004306C0_UpdateOk();                                                                       // 0x004306C0

extern int gdwGlobal_00779974;                                                                              // 0x00779974

// 0x00433020
int __stdcall sub_00433020_PollConnectA(int nArg)
{
    sub_00449B70_Receive();
    if (sub_00449C50() || !sub_00449B30_QueryAddress() || gdwGlobal_00779974)
    {
        sub_00449C60_SetValue(0);
        sub_004F9190();
    }
    return 1;
}

// 0x00433060
int __stdcall sub_00433060_PollConnectB(int nArg)
{
    sub_00449B70_Receive();
    if (sub_00449C70() || !sub_00449B30_QueryAddress() || gdwGlobal_00779974)
    {
        sub_00449C80_SetValue(0);
        sub_004F9190();
    }
    return 1;
}

// 0x004334D0
int __stdcall sub_004334D0_DestroyControls(int nArg)
{
    sub_0042F3F0_DestroyControls();
    return 1;
}

// 0x00433BD0
int __stdcall sub_00433BD0_UpdateNameOk(int nArg)
{
    sub_00430620_UpdateNameOk();
    return 1;
}

// 0x00433BE0
int __stdcall sub_00433BE0_UpdateOk(int nArg)
{
    sub_004306C0_UpdateOk();
    return 1;
}
