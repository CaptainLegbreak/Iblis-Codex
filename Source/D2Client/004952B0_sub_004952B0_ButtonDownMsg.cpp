struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    union
    {
        struct
        {
            unsigned short nWParamLo;
            short nWParamHi;
        };
        unsigned int wParam;
    };
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

int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned char nFlags, unsigned int dwValue); // 0x004150E0
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg);                                     // 0x00420290
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740

extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gnGlobal_00722310;                                                                               // 0x00722310
extern int gnGlobal_007BEF08;                                                                               // 0x007BEF08
static int gnPressed_007BEF04;                                                                              // 0x007BEF04

// 0x004952B0
void __stdcall sub_004952B0_ButtonDownMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnGlobal_007BEF08)
    {
        return;
    }
    const int nBottom = gnGlobal_00711470 - 0xA0;
    const int nLeft = gnGlobal_0071146C - 0x4B;
    const int nX = sub_00468730();
    const int nY = sub_00468740();
    if (nX >= nLeft && nX <= nLeft + 0x23 && nY >= nBottom - 0x24 && nY <= nBottom)
    {
        gnPressed_007BEF04 = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
}

// 0x00495320
void __stdcall sub_00495320_ButtonUpMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnGlobal_007BEF08)
    {
        return;
    }
    const int nBottom = gnGlobal_00711470 - 0xA0;
    const int nLeft = gnGlobal_0071146C - 0x4B;
    const int nX = sub_00468730();
    const int nY = sub_00468740();
    if (nX >= nLeft && nX <= nLeft + 0x23 && nY >= nBottom - 0x24 && nY <= nBottom)
    {
        sub_00455F20(0x22, 1, 0);
        sub_00455F20(0x21, 2, 0);
        gnGlobal_00722310 = 1;
        SRegSaveValue("Diablo II", "Help Menu", 1, 1);
        gnPressed_007BEF04 = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
}
