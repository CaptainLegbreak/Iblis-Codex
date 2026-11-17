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

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230
void __fastcall sub_00448BD0_UpdateScroll(int nDelta);                                                      // 0x00448BD0
void __fastcall sub_004F9740_SetControlState(D2WinControlStrc* pControl, int bSet);                        // 0x004F9740
void __cdecl sub_004477A0_Refresh();                                                                        // 0x004477A0
void __fastcall sub_004FB9D0_Select(D2WinControlStrc* pControl, int nLine);                                // 0x004FB9D0
int __cdecl sub_00449AC0();                                                                                 // 0x00449AC0
int __fastcall sub_004F9190();                                                            // 0x004F9190
int __cdecl sub_00449B70_Receive();                                                                         // 0x00449B70
int __cdecl sub_00449C30_GetValue();                                                                        // 0x00449C30
int __cdecl sub_00449B30_QueryAddress();                                                                    // 0x00449B30
void __stdcall sub_00449C40_SetValue(int nValue);                                                           // 0x00449C40

int gnFlag_0077BD60;                                                                                        // 0x0077BD60
extern D2WinControlStrc* gpControlMain_0077BC4C;                                                            // 0x0077BC4C
extern D2WinControlStrc* gpControl_0077BCFC;                                                                // 0x0077BCFC

// 0x0043D9A0
int __stdcall sub_0043D9A0_SetFlag(SMSGHANDLER_PARAMS* pMsg)
{
    gnFlag_0077BD60 = 1;
    return 1;
}

// 0x0043D9E0
int __stdcall sub_0043D9E0_ScrollPageUp(SMSGHANDLER_PARAMS* pMsg)
{
    sub_00448BD0_UpdateScroll(-10);
    return 1;
}

// 0x0043DA00
int __stdcall sub_0043DA00_ScrollPageDown(SMSGHANDLER_PARAMS* pMsg)
{
    sub_00448BD0_UpdateScroll(10);
    return 1;
}

// 0x0043DA20
int __stdcall sub_0043DA20_ScrollUp(SMSGHANDLER_PARAMS* pMsg)
{
    sub_00448BD0_UpdateScroll(-1);
    return 1;
}

// 0x0043DAF0
int __stdcall sub_0043DAF0_SetMainState(SMSGHANDLER_PARAMS* pMsg)
{
    sub_004F9740_SetControlState(gpControlMain_0077BC4C, 1);
    return 1;
}

// 0x0043DB90
int __stdcall sub_0043DB90_Refresh(SMSGHANDLER_PARAMS* pMsg)
{
    sub_004477A0_Refresh();
    return 1;
}

// 0x0043DBA0
int __stdcall sub_0043DBA0_ClearSelection(int nArg1, int nArg2, int nArg3)
{
    sub_004FB9D0_Select(gpControl_0077BCFC, -1);
    return 1;
}

// 0x0043DBC0
int __stdcall sub_0043DBC0_OnWaitTick(SMSGHANDLER_PARAMS* pMsg)
{
    if (!WaitForSingleObject((void*)sub_00449AC0(), 0) || gnFlag_0077BD60)
        sub_004F9190();
    return 1;
}

// 0x0043DBF0
int __stdcall sub_0043DBF0_OnReceiveTick(SMSGHANDLER_PARAMS* pMsg)
{
    sub_00449B70_Receive();
    if (sub_00449C30_GetValue() || !sub_00449B30_QueryAddress() || gnFlag_0077BD60)
    {
        sub_00449C40_SetValue(0);
        sub_004F9190();
    }
    return 1;
}
