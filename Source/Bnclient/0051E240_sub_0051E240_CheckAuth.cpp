void __cdecl sub_005234D0_LockCDKeys();                                                                     // 0x005234D0
int __stdcall sub_0051E0B0_SendAuthCheck();                                                                 // 0x0051E0B0
void __cdecl sub_005239C0_UnlockCDKeys();                                                                   // 0x005239C0
int __fastcall sub_00520520_SetState(int nState);                                                           // 0x00520520

// 0x0051E240
int __cdecl sub_0051E240_CheckAuth()
{
    sub_005234D0_LockCDKeys();
    const int nResult = sub_0051E0B0_SendAuthCheck();
    sub_005239C0_UnlockCDKeys();
    if (!nResult)
        sub_00520520_SetState(3);
    return nResult;
}
