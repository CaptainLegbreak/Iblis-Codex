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

struct D2WinControlStrc;

struct D2FuncTable_0077ABF0Strc
{
    char unk0x00[0x10];
    void (__fastcall* pfnSlot10)();
    char unk0x14[0x50];
    int (__fastcall* pfnSlot64)(int* pValue);
    int (__fastcall* pfnSlot68)();
    char unk0x6C[0x34];
    int (__fastcall* pfnSlotA0)(int* pValue);
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" int __cdecl strcmp(const char* sz1, const char* sz2);
void __fastcall sub_004F9740_SetControlState(D2WinControlStrc* pControl, int bSet);                        // 0x004F9740
void __fastcall sub_004307A0(unsigned int nArg, int nMode, int nStringId1, int nStringId2);                 // 0x004307A0
void __fastcall sub_00439AF0(SMSGHANDLER_PARAMS* pMsg, int nMode);                                          // 0x00439AF0
int __fastcall sub_004FC620_GetValue(D2WinControlStrc* pControl);                                           // 0x004FC620
void __fastcall sub_004FC660_SetValue(D2WinControlStrc* pControl, int nValue);                              // 0x004FC660
int __fastcall sub_004F9190();                                                            // 0x004F9190
int __cdecl sub_0042F6D0();                                                                                 // 0x0042F6D0

extern D2WinControlStrc* gpControl_007795E0;                                                                // 0x007795E0
extern D2WinControlStrc* gpControl_007795E4;                                                                // 0x007795E4
extern void** gppSlots_00779988;                                                                            // 0x00779988
extern int gdwGlobal_0077998C;                                                                              // 0x0077998C
extern D2WinControlStrc* gpControl_00779C84;                                                                // 0x00779C84
extern D2FuncTable_0077ABF0Strc* gpFuncTable_0077ABF0;                                                      // 0x0077ABF0
extern int gdwGlobal_0077AC04;                                                                              // 0x0077AC04

// 0x0043B8E0
int __stdcall sub_0043B8E0_OnTick(SMSGHANDLER_PARAMS* pMsg)
{
    int nValue;
    if (gpFuncTable_0077ABF0->pfnSlot64(&nValue))
        sub_004F9190();
    if (gdwGlobal_0077AC04 || !gpFuncTable_0077ABF0->pfnSlot68() || sub_0042F6D0())
    {
        gpFuncTable_0077ABF0->pfnSlot10();
        sub_004F9190();
    }
    return 1;
}

// 0x0043B940
int __stdcall sub_0043B940_OnTick(SMSGHANDLER_PARAMS* pMsg)
{
    int nValue;
    if (gpFuncTable_0077ABF0->pfnSlotA0(&nValue))
        sub_004F9190();
    if (gdwGlobal_0077AC04 || !gpFuncTable_0077ABF0->pfnSlot68() || sub_0042F6D0())
    {
        gpFuncTable_0077ABF0->pfnSlot10();
        sub_004F9190();
    }
    return 1;
}
