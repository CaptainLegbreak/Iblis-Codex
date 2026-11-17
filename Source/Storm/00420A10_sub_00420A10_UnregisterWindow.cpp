struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

    char* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
    }
};

struct D2StormNodeListBStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    char* Head()
    {
        return m_terminator.Next();
    }
    char* sub_00420970_DeleteNode(char* pNode);                                                            // 0x00420970
};

struct D2StormWndRecStrc
{
    D2StormLinkStrc f_0;
    void* hWnd;
};

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    int lParam;
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

char* __fastcall sub_004209E0_FindWndRec(void* hWnd);                                                        // 0x004209E0
int __stdcall SEvtUnregisterType(unsigned int nType, void* hWnd);                                            // 0x00426810
int __stdcall SEvtDispatch(unsigned int nType, void* hWnd, unsigned int nId, SMSGHANDLER_PARAMS* pParams); // 0x00426F90
void* gdwGlobal_007792F4;                                                                                    // 0x007792F4
extern D2StormNodeListBStrc gWndRecList_00708860;                                                           // 0x00708860

// 0x00420A10
static __declspec(noinline) void sub_00420A10_UnregisterWindow(void* hWnd)
{
    if (hWnd == gdwGlobal_007792F4)
    {
        gdwGlobal_007792F4 = 0;
    }
    char* pRec = sub_004209E0_FindWndRec(hWnd);
    if (pRec)
    {
        SEvtUnregisterType(0x534D5347, hWnd);
        SEvtUnregisterType(0x534D5348, hWnd);
        SEvtUnregisterType(0x534D534A, hWnd);
        SEvtUnregisterType(0x534D5349, hWnd);
        gWndRecList_00708860.sub_00420970_DeleteNode(pRec);
    }
}

// 0x00420B00
int __stdcall SMsgDispatchMessage(void* hWnd, unsigned int uMsg, unsigned int wParam, int lParam, int* pbUseResult, int* plResult)
{
    if (pbUseResult)
    {
        *pbUseResult = 0;
    }
    if (plResult)
    {
        *plResult = 0;
    }
    SMSGHANDLER_PARAMS tParams;
    tParams.hWnd = hWnd;
    tParams.uMessage = uMsg;
    tParams.wParam = wParam;
    tParams.lParam = lParam;
    if (uMsg == 0x111)
    {
        tParams.dwCommandSource = wParam >> 0x10;
    }
    else
    {
        tParams.dwCommandSource = 0;
    }
    tParams.bReturn = 0;
    tParams.lResult = 0;
    void* hTarget = hWnd;
    for (;;)
    {
        SEvtDispatch(0x534D5347, hTarget, uMsg, &tParams);
        if (uMsg == 0x111)
        {
            SEvtDispatch(0x534D5348, hTarget, (unsigned short)wParam, &tParams);
        }
        else if (uMsg == 0x100)
        {
            SEvtDispatch(0x534D5349, hTarget, wParam, &tParams);
        }
        else if (uMsg == 0x101)
        {
            SEvtDispatch(0x534D534A, hTarget, wParam, &tParams);
        }
        if (!hTarget || hTarget != gdwGlobal_007792F4)
        {
            break;
        }
        hTarget = 0;
    }
    if (uMsg == 0x82)
    {
        sub_00420A10_UnregisterWindow(hWnd);
    }
    if (pbUseResult)
    {
        *pbUseResult = tParams.bReturn;
    }
    if (plResult)
    {
        *plResult = tParams.lResult;
    }
    return 1;
}

// 0x00420AE0
static int sub_00420AE0_UnregisterAllWindows()
{
    while (D2StormWndRecStrc* pRec = (D2StormWndRecStrc*)gWndRecList_00708860.Head())
    {
        sub_00420A10_UnregisterWindow(pRec->hWnd);
    }
    return 1;
}

int __stdcall sub_K01_Emit_00420AE0()
{
    return sub_00420AE0_UnregisterAllWindows();
}
