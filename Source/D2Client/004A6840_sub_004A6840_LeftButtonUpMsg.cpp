struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    union
    {
        int wParam;
        struct
        {
            unsigned short wParamLow;
            unsigned short wParamHigh;
        };
    };
    union
    {
        int lParam;
        struct
        {
            unsigned short nXpos;
            unsigned short nYpos;
        };
    };
    unsigned int nNotifyCode;
    void* pExtra;
    int bUseResult;
    int lResult;
};

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg);                                     // 0x00420290
int __fastcall sub_004538D0(int nUIVar);                                                             // 0x004538D0
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
int __cdecl sub_0045AE90();                                                                         // 0x0045AE90
void __stdcall sub_00467FA0_MsgHandler(SMSGHANDLER_PARAMS* pMsg);                                           // 0x00467FA0
int __fastcall sub_004A6580_IsInPanelButton(int nMode, int nX, int nY);                                     // 0x004A6580
int __cdecl sub_004A65E0_IsInLeftButton();                                                                  // 0x004A65E0
int __cdecl D2GFX_GetResolutionMode();                                                                      // 0x004F5160

int gnGlobal_007C02E4;                                                                                      // 0x007C02E4

static int __fastcall CLIENT_HitPanelButton(int nMode, int nX, int nY)
{
    return sub_004A6580_IsInPanelButton(nMode, nX, nY);
}

// 0x004A6840
void __stdcall sub_004A6840_LeftButtonUpMsg(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = pMsg->nXpos;
    int nY = pMsg->nYpos;
    if (D2GFX_GetResolutionMode() == 2 && sub_004538D0(9))
    {
        return;
    }

    sub_00467FA0_MsgHandler(pMsg);
    if (D2GFX_GetResolutionMode() != 2)
    {
        if (gnGlobal_007C02E4 && CLIENT_HitPanelButton(sub_0045AE90(), nX, nY))
        {
            gnGlobal_007C02E4 = 0;
            sub_00455F20(6, 1, 0);
            sub_00455F20(2, 0, 0);
            pMsg->bUseResult = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }
    else
    {
        if (gnGlobal_007C02E4 && sub_004A65E0_IsInLeftButton())
        {
            gnGlobal_007C02E4 = 0;
            sub_00455F20(2, 0, 0);
            pMsg->bUseResult = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }

    gnGlobal_007C02E4 = 0;
    pMsg->bUseResult = 0;
}
