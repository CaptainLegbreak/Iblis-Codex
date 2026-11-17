struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    int wParam;
    int lParam;
    unsigned int nNotifyCode;
    void* pExtra;
    int bUseResult;
    int lResult;
};

void __stdcall sub_004F59F0(int nArg);                                                                      // 0x004F59F0
extern int gnGlobal_007A6B08;                                                                               // 0x007A6B08

// 0x00467EF0
void __stdcall sub_00467EF0_MsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    if (pMsg->wParam == 2)
    {
        gnGlobal_007A6B08 = 0;
        sub_004F59F0(0);
    }
    else
    {
        gnGlobal_007A6B08 = 0;
    }
    pMsg->bUseResult = 0;
    pMsg->lResult = 0;
}
