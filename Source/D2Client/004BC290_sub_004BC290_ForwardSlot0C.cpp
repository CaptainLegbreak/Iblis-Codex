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

struct UIWidget
{
    virtual void Slot00();
    virtual void Slot04();
    virtual int Slot08(int nArg);
    virtual int Slot0C(int nArg);
    virtual int Slot10(int nArg);
    virtual int Slot14(int nArg);
    virtual int Slot18(int nArg);
    virtual int Slot1C(int nArg);
    virtual int Slot20(int nArg);
    virtual int Slot24(int nArg);
    virtual int Slot28(int nArg);
    virtual int Slot2C(int nArg);
    virtual int Slot30(int nArg);
    virtual int Slot34(int nArg);
    virtual int Slot38(int nArg);
    virtual int Slot3C(int nArg);
};

struct SpinnerWrapper
{
    virtual void Slot00();
    int unk0x04;
    UIWidget* pImpl;

    int sub_004BC290_ForwardSlot0C(int nArg);
    int sub_004BC2A0_ForwardSlot10(int nArg);
    int sub_004BC2B0_ForwardSlot14(int nArg);
    int sub_004BC2D0_ForwardSlot18(int nArg);
    int sub_004BC2E0_ForwardSlot20(int nArg);
    int sub_004BC2F0_ForwardSlot1C(int nArg);
    int sub_004BC300_ForwardSlot24(int nArg);
    int sub_004BC310_ForwardSlot28(int nArg);
};

struct ListBoxWrapper
{
    virtual void Slot00();
    int unk0x04;
    UIWidget* pImpl;

    int sub_004BED40_ForwardSlot20(int nArg);
    int sub_004BED50_ForwardSlot1C(int nArg);
    int sub_004BED60_ForwardSlot24(int nArg);
    int sub_004BED70_ForwardSlot28(int nArg);
    int sub_004BED80_ForwardSlot0C(int nArg);
    int sub_004BED90_ForwardSlot10(int nArg);
    int sub_004BEDA0_ForwardSlot14(int nArg);
    int sub_004BEDB0_ForwardSlot18(int nArg);
    int sub_004BEDE0_ForwardSlot3C(int nArg);
    int sub_004BEE20_ForwardSlot08(int nArg);
};

struct D2ListBoxEntryStrc
{
    char unk0x0000[0x3006];
    char nData[4];
    char unk0x300A[4];
};

typedef void (__cdecl* ListBoxCallback)();

struct ListBoxImplementation
{
    virtual void Slot00();
    virtual void Slot04();
    virtual int Slot08(SMSGHANDLER_PARAMS* pMsg);
    virtual void Slot0C();
    virtual void Slot10();
    virtual void Slot14();
    virtual int Slot18(SMSGHANDLER_PARAMS* pMsg);
    virtual int Slot1C(SMSGHANDLER_PARAMS* pMsg);
    virtual int Slot20(SMSGHANDLER_PARAMS* pMsg);

    D2ListBoxEntryStrc aEntries[0x80];
    char unk0x180704[0x2C];
    int f_180730;
    int unk0x180734;
    int nSelectedIndex;
    char unk0x18073C[0xC];
    unsigned short nEntryCount;
    char pfnCallback[4];
    char f_18074E[4];
    char unk0x180752[8];
    char nX[4];
    char nY[4];
    char f_180762[4];
    char unk0x180766[0xC];
    char nState[4];

    int sub_004BE720_HitTestTopRow(SMSGHANDLER_PARAMS* pMsg);
    int sub_004BE770_HitTestBottomRow(SMSGHANDLER_PARAMS* pMsg);
    int sub_004BE7C0_HitTestRows(SMSGHANDLER_PARAMS* pMsg);
    int sub_004BE860_WheelMsg(SMSGHANDLER_PARAMS* pMsg);
    int sub_004BEBC0_KeyMsg(SMSGHANDLER_PARAMS* pMsg);
    int sub_004BEC40_GetEntryData(int nIndex);
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern int gnGlobal_007C5474;                                                                               // 0x007C5474
void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg);                                             // 0x00420290
void __fastcall sub_00502280_SetPopUpText(const unsigned short* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280
void __fastcall sub_00498DC0_MouseMoveMsg(SMSGHANDLER_PARAMS* pMsg);                                         // 0x00498DC0
int __stdcall sub_00489060_MouseMoveMsg(SMSGHANDLER_PARAMS* pMsg);                                           // 0x00489060

// 0x004BC290
int SpinnerWrapper::sub_004BC290_ForwardSlot0C(int nArg)
{
    return pImpl->Slot0C(nArg);
}

// 0x004BC2A0
int SpinnerWrapper::sub_004BC2A0_ForwardSlot10(int nArg)
{
    return pImpl->Slot10(nArg);
}

// 0x004BC2B0
int SpinnerWrapper::sub_004BC2B0_ForwardSlot14(int nArg)
{
    return pImpl->Slot14(nArg);
}

// 0x004BC2D0
int SpinnerWrapper::sub_004BC2D0_ForwardSlot18(int nArg)
{
    return pImpl->Slot18(nArg);
}

// 0x004BC2E0
int SpinnerWrapper::sub_004BC2E0_ForwardSlot20(int nArg)
{
    return pImpl->Slot20(nArg);
}

// 0x004BC2F0
int SpinnerWrapper::sub_004BC2F0_ForwardSlot1C(int nArg)
{
    return pImpl->Slot1C(nArg);
}

// 0x004BC300
int SpinnerWrapper::sub_004BC300_ForwardSlot24(int nArg)
{
    return pImpl->Slot24(nArg);
}

// 0x004BC310
int SpinnerWrapper::sub_004BC310_ForwardSlot28(int nArg)
{
    return pImpl->Slot28(nArg);
}

// 0x004BE720
int ListBoxImplementation::sub_004BE720_HitTestTopRow(SMSGHANDLER_PARAMS* pMsg)
{
    const int nMouseX = pMsg->nXpos;
    const int nMouseY = pMsg->nYpos;
    if (nMouseX > *(int*)nX && nMouseX < *(int*)nX + 0x10 && nMouseY > *(int*)nY - 12 && nMouseY < *(int*)nY)
    {
        return 1;
    }
    return 0;
}

// 0x004BE770
int ListBoxImplementation::sub_004BE770_HitTestBottomRow(SMSGHANDLER_PARAMS* pMsg)
{
    const int nMouseX = pMsg->nXpos;
    const int nMouseY = pMsg->nYpos;
    if (nMouseX > *(int*)nX && nMouseX < *(int*)nX + 0x10)
    {
        const int nBottom = *(int*)nY + *(int*)f_180762 * 12;
        if (nMouseY > nBottom - 12 && nMouseY < nBottom)
        {
            return 1;
        }
    }
    return 0;
}

// 0x004BE7C0
int ListBoxImplementation::sub_004BE7C0_HitTestRows(SMSGHANDLER_PARAMS* pMsg)
{
    const int nMouseX = pMsg->nXpos;
    const int nMouseY = pMsg->nYpos;
    if (nMouseX > *(int*)nX && nMouseX < *(int*)nX + 0x10 && nMouseY < *(int*)nY + *(int*)f_180762 * 12 - 12 && nMouseY > *(int*)nY)
    {
        return 1;
    }
    return 0;
}

// 0x004BE860
int ListBoxImplementation::sub_004BE860_WheelMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (pMsg->nWParamHi > 0)
    {
        nSelectedIndex = f_180730;
        Slot1C(pMsg);
    }
    else if (pMsg->nWParamHi < 0)
    {
        nSelectedIndex = f_180730 + *(int*)f_18074E - 1;
        Slot20(pMsg);
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
    return 1;
}

// 0x004BEBC0
int ListBoxImplementation::sub_004BEBC0_KeyMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (*(ListBoxCallback*)pfnCallback)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
        if (*(unsigned int*)nState < 2)
        {
            return 0;
        }
        if (nSelectedIndex != -1 && pMsg->wParam == 0xD)
        {
            (*(ListBoxCallback*)pfnCallback)();
        }
        return 1;
    }
    return 0;
}

// 0x004BEC40
int ListBoxImplementation::sub_004BEC40_GetEntryData(int nIndex)
{
    if (nIndex >= 0 && nIndex < nEntryCount && nIndex < 0x80)
    {
        return *(int*)aEntries[nIndex].nData;
    }
    D2_ASSERT(nEntryCount < 0x80, 0x46C);
    D2_ASSERT(nEntryCount < nIndex, 0x46D);
    D2_ASSERT(nIndex >= 0, 0x46E);
    return 0;
}

// 0x004BED40
int ListBoxWrapper::sub_004BED40_ForwardSlot20(int nArg)
{
    return pImpl->Slot20(nArg);
}

// 0x004BED50
int ListBoxWrapper::sub_004BED50_ForwardSlot1C(int nArg)
{
    return pImpl->Slot1C(nArg);
}

// 0x004BED60
int ListBoxWrapper::sub_004BED60_ForwardSlot24(int nArg)
{
    return pImpl->Slot24(nArg);
}

// 0x004BED70
int ListBoxWrapper::sub_004BED70_ForwardSlot28(int nArg)
{
    return pImpl->Slot28(nArg);
}

// 0x004BED80
int ListBoxWrapper::sub_004BED80_ForwardSlot0C(int nArg)
{
    return pImpl->Slot0C(nArg);
}

// 0x004BED90
int ListBoxWrapper::sub_004BED90_ForwardSlot10(int nArg)
{
    return pImpl->Slot10(nArg);
}

// 0x004BEDA0
int ListBoxWrapper::sub_004BEDA0_ForwardSlot14(int nArg)
{
    return pImpl->Slot14(nArg);
}

// 0x004BEDB0
int ListBoxWrapper::sub_004BEDB0_ForwardSlot18(int nArg)
{
    return pImpl->Slot18(nArg);
}

// 0x004BEDE0
int ListBoxWrapper::sub_004BEDE0_ForwardSlot3C(int nArg)
{
    return pImpl->Slot3C(nArg);
}

// 0x004BEE20
int ListBoxWrapper::sub_004BEE20_ForwardSlot08(int nArg)
{
    return pImpl->Slot08(nArg);
}

// 0x004BFA30
void __stdcall sub_004BFA30_MouseMoveMsg(SMSGHANDLER_PARAMS* pMsg)
{
    sub_00502280_SetPopUpText(0, -1, -1, 0, 0);
    sub_00498DC0_MouseMoveMsg(pMsg);
    if (gnGlobal_007C5474 == 1)
    {
        sub_00489060_MouseMoveMsg(pMsg);
    }
}

// 0x004BFDB0
void __stdcall sub_004BFDB0_BreakMsg(SMSGHANDLER_PARAMS* pMsg)
{
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}
