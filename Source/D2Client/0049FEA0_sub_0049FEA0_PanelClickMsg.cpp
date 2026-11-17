struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    union
    {
        struct
        {
            unsigned short nXpos;
            unsigned short nYpos;
        };
        unsigned int lParam;
    };
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
void __cdecl sub_0049FE10();                                                                                // 0x0049FE10
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg);                                     // 0x00420290
void __cdecl sub_0044DA40();                                                                                // 0x0044DA40

// 0x0049FEA0
void __stdcall sub_0049FEA0_PanelClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = (unsigned short)pMsg->lParam;
    int nY = (unsigned short)((unsigned int)pMsg->lParam >> 16);
    if (nY < gnGlobal_00711470 - 0x30 && nX < gnGlobal_0071146C / 2)
    {
        sub_00455F20(0x10, 2, 0);
        sub_0049FE10();
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        sub_0044DA40();
    }
}
