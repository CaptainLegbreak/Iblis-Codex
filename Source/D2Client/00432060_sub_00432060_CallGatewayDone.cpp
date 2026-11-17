struct D2WinControlStrc;
struct Unicode;

#pragma pack(push, 1)
struct D2LaunchRecordStrc
{
    char unk0x000[0x8D];
    char szAccount[0x18];
    char szPassword[0x100];
    char unk0x1A5[0x21E];
    unsigned int dwPasswordHash;
    int nPasswordLength;
};
#pragma pack(pop)

extern void (__cdecl* gpfnGatewayDone_007795BC)();                                                          // 0x007795BC
const Unicode* __fastcall sub_004FDD90_GetEditText(D2WinControlStrc* pControl);                             // 0x004FDD90
char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount);                     // 0x00526F70
extern D2LaunchRecordStrc* gpLaunchRecord_007795D4;                                                         // 0x007795D4
extern D2WinControlStrc* gpEdit_0077958C;                                                                   // 0x0077958C
void __cdecl sub_004370C0();                                                                                // 0x004370C0
int __cdecl sub_00432400_GetStatus();                                                                       // 0x00432400
void __cdecl sub_004F9190();                                                              // 0x004F9190
int gdwGlobal_00779974;                                                                                     // 0x00779974
extern int gnWaitDone_00779994;                                                                             // 0x00779994
void __cdecl sub_0042F3F0_DestroyControls();                                                                // 0x0042F3F0
int __cdecl sub_00449B30_QueryAddress();                                                                    // 0x00449B30
int __cdecl sub_00449B70_Receive();                                                                         // 0x00449B70
int __cdecl sub_00449C10();                                                                                 // 0x00449C10
void __stdcall sub_00449C20_SetValue(int nValue);                                                           // 0x00449C20
int __cdecl sub_00449C30();                                                                                 // 0x00449C30
void __stdcall sub_00449C40_SetValue(int nValue);                                                           // 0x00449C40

// 0x00432060
int __stdcall sub_00432060_CallGatewayDone(int nArg)
{
    if (gpfnGatewayDone_007795BC)
        gpfnGatewayDone_007795BC();
    return 1;
}

// 0x00432310
int __stdcall sub_00432310_StoreAccount(int nArg)
{
    const Unicode* pText = sub_004FDD90_GetEditText(gpEdit_0077958C);
    sub_00526F70(gpLaunchRecord_007795D4->szAccount, pText, 0x100);
    sub_004370C0();
    return 1;
}

// 0x00432450
int __stdcall sub_00432450_OnWait(int nArg)
{
    if (gdwGlobal_00779974)
        gnWaitDone_00779994 = 1;
    if (sub_00432400_GetStatus() != 3)
        sub_004F9190();
    return 1;
}

// 0x00432EE0
int __stdcall sub_00432EE0_CloseBox(int nArg)
{
    sub_0042F3F0_DestroyControls();
    return 1;
}

// 0x00432FA0
int __stdcall sub_00432FA0_OnReceiveA(int nArg)
{
    sub_00449B70_Receive();
    if (sub_00449C10() || !sub_00449B30_QueryAddress() || gdwGlobal_00779974)
    {
        sub_00449C20_SetValue(0);
        sub_004F9190();
    }
    return 1;
}

// 0x00432FE0
int __stdcall sub_00432FE0_OnReceiveB(int nArg)
{
    sub_00449B70_Receive();
    if (sub_00449C30() || !sub_00449B30_QueryAddress() || gdwGlobal_00779974)
    {
        sub_00449C40_SetValue(0);
        sub_004F9190();
    }
    return 1;
}
