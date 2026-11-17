struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    int wParam;
    unsigned short nXpos;
    unsigned short nYpos;
    unsigned int nNotifyCode;
    void* pExtra;
    int bUseResult;
    int lResult;
};

#pragma pack(push, 2)
struct D2SliderButtonStrc
{
    unsigned short nStringId;
    void (__cdecl* pfnClick)();
    int unk0x06;
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
};

struct D2ClientListEntryStrc
{
    int nId;
    unsigned char unk0x04[6];
};
#pragma pack(pop)

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg);
int __cdecl sub_0044DA30();
void __cdecl sub_0044DCE0();
extern "C" void __cdecl sub_0044DD20_MouseExtTables_451DB0();
void __cdecl sub_00466FE0();
void __fastcall sub_00467A70(int nArg);
void __cdecl sub_00469D20();
void __fastcall sub_0046AA20(int nArg1, int nArg2);
void __cdecl sub_004A43E0();
void __stdcall sub_004A4AD0_Press(int nX, int nY);
void __cdecl sub_004A5060();
void __cdecl sub_004A5D00();
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);

extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern D2ClientListEntryStrc* gpListEntries_00724264;
extern int gnGlobal_007246D4;
extern D2SliderButtonStrc gaSliderButtons_007246D8[3];
extern int gnAutomapHeight_007A521C;                                                                        // 0x007A521C
extern int gnEntryCount_007C0274;
extern int gnThumbScale_007C0278;
extern int gnGlobal_007C0280;
extern int gnGlobal_007C0284;
extern int gaPressed_007C0288[7];
extern int gnFirstVisible_007C02AC;
extern int gnGlobal_007C02B0;
extern int gnPressedButton_007C02B4;
extern int gnGlobal_007C02B8;
extern int gnThumbY_007C02CC;

static int sub_004A4720_GetLineAt(int nY)
{
    int nIndex = gnFirstVisible_007C02AC;
    const int nCount = gnEntryCount_007C0274;
    int nLine = 0;
    if (nIndex < nCount)
    {
        int nLineY = (gnAutomapHeight_007A521C - 0x1A4) / 2 + 0x3A;
        do
        {
            if (nLine >= 0x0F)
                break;
            if (nY <= nLineY)
                return nIndex;
            ++nIndex;
            ++nLine;
            nLineY += 0x12;
        }
        while (nIndex < nCount);
        if (nIndex < nCount)
            return nIndex;
    }
    return nCount < 0 ? nCount : nCount - 1;
}

static int __stdcall sub_E10_IsAbovePanelLineCopy(int nY)
{
    int nHalf = (gnGlobal_0071146C - 620) / 2;
    return nY < nHalf + (gnGlobal_0071146C - nHalf * 2 - 49) / 3 * 2 + 18;
}

static __declspec(noinline) int sub_004A47C0_GetButtonAt(int nX, int nY)
{
    unsigned int i;
    for (i = 0; i < 3; ++i)
    {
        if (nX >= gaSliderButtons_007246D8[i].nLeft && nX <= gaSliderButtons_007246D8[i].nRight
            && nY >= gaSliderButtons_007246D8[i].nTop && nY <= gaSliderButtons_007246D8[i].nBottom)
            break;
    }
    return i;
}

// 0x004A47F0
static int sub_004A47F0_IsInList(int nX, int nY)
{
    const int nHalf = (gnGlobal_0071146C - 0x26C) / 2;
    const int nLeft = nHalf + 0x12;
    const int nRight = nHalf + (gnGlobal_0071146C - nHalf * 2 - 0x31) / 3 * 3 + 0x12;
    if (nX >= nLeft && nX <= nRight)
    {
        const int nTop = (gnAutomapHeight_007A521C - 0x1A4) / 2;
        if (nY >= nTop + 0x28 && nY <= nTop + 0x136)
            return 1;
    }
    return 0;
}

// build: context sub_004A4A10_IsOnSelectedLine
static int sub_004A4A10_IsOnSelectedLine(int nX, int nY)
{
    if (sub_004A47F0_IsInList(nX, nY) && sub_004A4720_GetLineAt(nY) == gnGlobal_007C02B0
        && sub_E10_IsAbovePanelLineCopy(nX) == gnGlobal_007246D4)
        return 1;
    return 0;
}

// build: context sub_004A5200
void __fastcall sub_004A5200(int nArg)
{
    sub_004A43E0();
    if (nArg)
    {
        if (gnGlobal_007C02B8 == 0)
        {
            sub_00469D20();
            sub_0046AA20(0, 0);
            sub_0044DCE0();
            sub_00467A70(0);
        }
        gnFirstVisible_007C02AC = 0;
        gnGlobal_007C02B0 = 0;
    }
    else if (gnGlobal_007C02B8 == 0)
    {
        sub_0046AA20(1, 0);
        sub_0044DD20_MouseExtTables_451DB0();
        sub_00466FE0();
    }
    sub_004A5060();
}

static void sub_004A5E60_Release(int nX, int nY)
{
    if (gaPressed_007C0288[0])
    {
        if (sub_004A4A10_IsOnSelectedLine(nX, nY) && gpListEntries_00724264[gnGlobal_007C02B0].nId != 0x39)
        {
            sub_004A5D00();
            sub_004B9A00(2, 0, 0, 0, 0);
        }
    }
    if (gaPressed_007C0288[6])
    {
        const int nButton = gnPressedButton_007C02B4;
        if (nButton != 3 && sub_004A47C0_GetButtonAt(nX, nY) == nButton)
        {
            gaSliderButtons_007246D8[nButton].pfnClick();
            sub_004B9A00(2, 0, 0, 0, 0);
        }
    }
    gnGlobal_007C0284 = 0;
    gaPressed_007C0288[0] = 0;
    gaPressed_007C0288[1] = 0;
    gaPressed_007C0288[2] = 0;
    gaPressed_007C0288[3] = 0;
    gaPressed_007C0288[4] = 0;
    gaPressed_007C0288[5] = 0;
    gaPressed_007C0288[6] = 0;
}

void __stdcall sub_004A5F10_ButtonUpMsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_0044DA30())
    {
        pMsg->bUseResult = 0;
        return;
    }

    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    sub_004A5E60_Release(nX, nY);
    gnGlobal_007C0280 = 0;
    sub_004A4AD0_Press(nX, nY);
    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}
