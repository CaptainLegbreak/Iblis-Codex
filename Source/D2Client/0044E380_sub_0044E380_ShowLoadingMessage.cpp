struct D2LoadingTimerStrc
{
    unsigned long dwStart;
    unsigned long dwLength;
};

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

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                                // 0x006CC260

extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gdwGlobal_007A0524;                                                                              // 0x007A0524
int gnLoadingIndex_007A05D4;                                                                                // 0x007A05D4
int gdwGlobal_007A05F8;                                                                                     // 0x007A05F8
int gdwGlobal_007A0604;                                                                                     // 0x007A0604
extern int gdwGlobal_007A0610;                                                                              // 0x007A0610
extern int gdwGlobal_007A0618;                                                                              // 0x007A0618
extern int gdwGlobal_007A061C;                                                                              // 0x007A061C
int gdwGlobal_007A0620;                                                                                     // 0x007A0620
int gnValue_007A0624;                                                                                       // 0x007A0624
extern int gdwGlobal_007A062C;                                                                              // 0x007A062C
static int gdwGlobal_007A0650;                                                                              // 0x007A0650
static int gdwGlobal_007A0654;                                                                              // 0x007A0654
static int gdwGlobal_007A066C;                                                                              // 0x007A066C
static int gdwGlobal_007A0670;                                                                              // 0x007A0670
static int gdwGlobal_007A0680;                                                                              // 0x007A0680
extern D2LoadingTimerStrc gtLoadingTimer_007A0684;                                                          // 0x007A0684

void __fastcall sub_0044B880_SetValue(int nValue);                                                          // 0x0044B880
void __cdecl sub_0044CB60_DrawLoadingText();                                                                // 0x0044CB60
int __fastcall sub_0044E040_TimerRunning(D2LoadingTimerStrc* pTimer);                                       // 0x0044E040
void __fastcall sub_004547B0();                                                                             // 0x004547B0
void __fastcall sub_00456300(int nArg1, int nArg2);                                                         // 0x00456300
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg);                                     // 0x00420290
int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
int __cdecl sub_0052A640_IsConnected();                                                                     // 0x0052A640

int __fastcall sub_0044DFF0_TimerExpired(D2LoadingTimerStrc* pTimer)
{
    if (pTimer->dwLength)
    {
        unsigned long dwNow = GetTickCount();
        unsigned long dwLeft;
        if (dwNow >= pTimer->dwStart + pTimer->dwLength)
        {
            pTimer->dwStart = 0;
            pTimer->dwLength = 0;
            dwLeft = 0;
        }
        else
        {
            dwLeft = pTimer->dwLength - (dwNow - pTimer->dwStart);
        }
        return dwLeft == 0;
    }
    return 1;
}

// 0x0044E380
void __fastcall sub_0044E380_ShowLoadingMessage(int nIndex)
{
    if (sub_0044E040_TimerRunning(&gtLoadingTimer_007A0684))
    {
        return;
    }

    if (gdwGlobal_007A0604)
    {
        return;
    }

    if (gdwGlobal_007A062C)
    {
        return;
    }

    gnLoadingIndex_007A05D4 = nIndex;
    if (nIndex >= 29)
    {
        gnLoadingIndex_007A05D4 = 9;
    }

    sub_00456300(1, 0);
    gtLoadingTimer_007A0684.dwStart = GetTickCount();
    gtLoadingTimer_007A0684.dwLength = 2500;
    gdwGlobal_007A0620 = 1;
    gdwGlobal_007A061C = 0;
    gdwGlobal_007A0618 = 0;
    sub_0044B880_SetValue(0);
}

// 0x0044E400
int __stdcall sub_0044E400_LoadingTimerCallback(void* pArg)
{
    int bResult = 0;
    if (sub_0044DFF0_TimerExpired(&gtLoadingTimer_007A0684))
    {
        sub_004547B0();
        bResult = 1;
    }
    else
    {
        sub_0044CB60_DrawLoadingText();
    }
    return bResult;
}

// 0x0044E460
void __stdcall sub_0044E460_ButtonMsg(SMSGHANDLER_PARAMS* pMsg)
{
    const int nBottom = gnGlobal_00711470 - 0x50;
    int nLeft = gnGlobal_0071146C / 2 - 0x30;
    const int nX = sub_00468730();
    const int nY = sub_00468740();
    if (nX >= nLeft && nX <= nLeft + 0x60 && nY >= nBottom - 0x20 && nY <= nBottom)
    {
        gdwGlobal_007A0680 = 1;
        gdwGlobal_007A0650 = 0;
        gdwGlobal_007A0654 = 0;
        gdwGlobal_007A066C = 0;
        gdwGlobal_007A0670 = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }

    gdwGlobal_007A0650 = 0;
    gdwGlobal_007A0654 = 0;
    gdwGlobal_007A066C = 0;
    gdwGlobal_007A0670 = 0;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x0044EEC0
void __cdecl sub_0044EEC0_CheckConnectionTimeouts()
{
    if (!gdwGlobal_007A0610 || gdwGlobal_007A0610 == 1)
    {
        return;
    }

    unsigned long dwNow = GetTickCount();
    if (!sub_0052A640_IsConnected() && !gdwGlobal_007A0620 && gdwGlobal_007A061C)
    {
        sub_0044E380_ShowLoadingMessage(7);
    }

    if (gnValue_007A0624 && dwNow - gdwGlobal_007A0524 > 300000)
    {
        sub_0044E380_ShowLoadingMessage(7);
    }

    if (dwNow - gdwGlobal_007A05F8 > 30000 && !gdwGlobal_007A061C && !gdwGlobal_007A0620 && !gnValue_007A0624)
    {
        sub_0044E380_ShowLoadingMessage(6);
    }

    if (!gdwGlobal_007A0618 && !gdwGlobal_007A061C && !gdwGlobal_007A0620 && !gnValue_007A0624
        && (gdwGlobal_007A0610 == 9 || gdwGlobal_007A0610 == 7))
    {
        sub_0044E380_ShowLoadingMessage(6);
    }
}
