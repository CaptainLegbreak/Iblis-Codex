struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    unsigned int lParam;
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

struct D2FuncTable_0077ABF0Strc
{
    char unk0x00[0x0C];
    int (__fastcall* pfnSlot0C)();
    void (__fastcall* pfnSlot10)();
    char unk0x14[0x38];
    int (__fastcall* pfnSlot4C)();
    char unk0x50[0x14];
    int (__fastcall* pfnSlot64)(int* pValue);
    int (__fastcall* pfnSlot68)();
    char unk0x6C[0x34];
    int (__fastcall* pfnSlotA0)(int* pValue);
};

void __fastcall sub_0043ADB0_UseName(char* szName);                                                         // 0x0043ADB0
void __cdecl sub_0042F3F0_DestroyControls();                                                                // 0x0042F3F0
void __cdecl sub_0043A730();                                                                                // 0x0043A730
int __cdecl sub_0042FA30();                                                                                 // 0x0042FA30
void __cdecl sub_0042F990();                                                                                // 0x0042F990
int __cdecl sub_0042F6D0();                                                                                 // 0x0042F6D0
int __fastcall sub_004F9190();                                                            // 0x004F9190

extern char gData_00779A40[];                                                                               // 0x00779A40
extern int gnLaunchMode_007795EC;                                                                           // 0x007795EC
extern int gbFlag_00779C6C;                                                                                 // 0x00779C6C
extern D2FuncTable_0077ABF0Strc* gpFuncTable_0077ABF0;                                                      // 0x0077ABF0
extern int gdwGlobal_0077AC04;                                                                              // 0x0077AC04

// 0x0043B490
int __stdcall sub_0043B490_OnName(SMSGHANDLER_PARAMS* pMsg)
{
    sub_0043ADB0_UseName(gData_00779A40);
    if (gnLaunchMode_007795EC == 1)
    {
        sub_0042F3F0_DestroyControls();
        sub_0043A730();
    }
    gbFlag_00779C6C = 0;
    return 1;
}

// 0x0043B810
void __cdecl sub_0043B810_SetFlag()
{
    gdwGlobal_0077AC04 = 1;
}

// 0x0043B850
int __stdcall sub_0043B850_OnTick(SMSGHANDLER_PARAMS* pMsg)
{
    if (gpFuncTable_0077ABF0->pfnSlot4C() != 0x65 && !sub_0042FA30())
    {
        sub_0042F990();
        return 1;
    }
    sub_004F9190();
    return 1;
}

// 0x0043B890
int __stdcall sub_0043B890_OnTick(SMSGHANDLER_PARAMS* pMsg)
{
    if (gpFuncTable_0077ABF0->pfnSlot0C())
        sub_004F9190();
    if (gdwGlobal_0077AC04 || !gpFuncTable_0077ABF0->pfnSlot68() || sub_0042F6D0())
        sub_004F9190();
    return 1;
}
