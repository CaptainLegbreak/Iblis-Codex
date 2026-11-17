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

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                                // 0x006CC260
int __cdecl sub_004A44C0_GetMaxFirstEntry();                                                                // 0x004A44C0
int __stdcall sub_004A4780_IsAbovePanelLine(int nX);                                                        // 0x004A4780

extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern D2ClientListEntryStrc* gpListEntries_00724264;                                                       // 0x00724264
extern int gnGlobal_007246D4;                                                                               // 0x007246D4
extern D2SliderButtonStrc gaSliderButtons_007246D8[3];                                                      // 0x007246D8
extern int gnAutomapHeight_007A521C;                                                                        // 0x007A521C
extern int gnEntryCount_007C0274;                                                                           // 0x007C0274
extern int gnThumbScale_007C0278;                                                                           // 0x007C0278
extern int gnThumbRange_007C027C;                                                                           // 0x007C027C
extern int gnGlobal_007C0280;                                                                               // 0x007C0280
extern int gnGlobal_007C0284;                                                                               // 0x007C0284
extern int gaPressed_007C0288[7];                                                                           // 0x007C0288
int gnDragThumbY_007C02A4;                                                                                  // 0x007C02A4
int gnDragMouseY_007C02A8;                                                                                  // 0x007C02A8
extern int gnFirstVisible_007C02AC;                                                                         // 0x007C02AC
extern int gnGlobal_007C02B0;                                                                               // 0x007C02B0
extern int gnPressedButton_007C02B4;                                                                        // 0x007C02B4
unsigned long gdwLastTick_007C02C0;                                                                         // 0x007C02C0
int gnThumbY_007C02CC;                                                                                      // 0x007C02CC

static __forceinline int sub_F08_ListTop()
{
    return (gnAutomapHeight_007A521C - 0x1A4) / 2;
}

static __forceinline int sub_F08_PanelLeft()
{
    return (gnGlobal_0071146C - 0x26C) / 2;
}

static __forceinline int sub_F08_PanelRight()
{
    return sub_F08_PanelLeft() + (gnGlobal_0071146C - sub_F08_PanelLeft() * 2);
}

static __forceinline int sub_F08_TrackTop()
{
    return sub_F08_ListTop() + 0x2F;
}

static __forceinline int sub_F08_TrackBottom()
{
    return sub_F08_ListTop() + 0x125;
}

static __forceinline int sub_F08_ThumbHeight()
{
    return gnThumbScale_007C0278 * 12;
}

static __forceinline int sub_F08_TrackSpan()
{
    return sub_F08_TrackBottom() - sub_F08_TrackTop() - sub_F08_ThumbHeight();
}

static __forceinline int sub_F08_LinesTop()
{
    return sub_F08_ListTop() + 0x28;
}

static __forceinline int sub_F08_LinesBottom()
{
    return sub_F08_ListTop() + 0x136;
}

static __forceinline int sub_F08_VisibleLines()
{
    return (sub_F08_LinesBottom() - sub_F08_LinesTop()) / 0x12;
}

static __forceinline int sub_F08_NoOtherPressed(int nIndex)
{
    for (int i = 0; i < 7; ++i)
    {
        if (gaPressed_007C0288[i] && i != nIndex)
            return 0;
    }
    return 1;
}

void __fastcall sub_004A4500_ScrollList(int nStep)
{
    if (nStep < -1)
    {
        for (int i = nStep; i < 0; ++i)
            sub_004A4500_ScrollList(-1);
        return;
    }
    if (nStep > 1)
    {
        for (int i = 0; i < nStep; ++i)
            sub_004A4500_ScrollList(1);
        return;
    }

    const int nMax = sub_004A44C0_GetMaxFirstEntry();
    int nFirst = gnFirstVisible_007C02AC;
    if (nStep < 0)
    {
        const int nNew = nFirst <= 0 ? nFirst : nFirst - 1;
        if (nNew >= 0)
        {
            nFirst = nNew;
            gnFirstVisible_007C02AC = nFirst;
        }
    }
    else if (nStep > 0)
    {
        const int nNew = nFirst >= nMax ? nFirst : nFirst + 1;
        if (nNew <= nMax)
        {
            nFirst = nNew;
            gnFirstVisible_007C02AC = nFirst;
        }
    }
    gnThumbY_007C02CC = sub_F08_TrackSpan() * nFirst / nMax + sub_F08_TrackTop();
}

void __fastcall sub_004A45C0_MoveSelection(int nStep)
{
    if (!nStep)
        return;
    if (nStep < -1)
    {
        for (int i = nStep; i < 0; ++i)
            sub_004A45C0_MoveSelection(-1);
        return;
    }
    if (nStep > 1)
    {
        for (int i = 0; i < nStep; ++i)
            sub_004A45C0_MoveSelection(1);
        return;
    }

    const int nCount = gnEntryCount_007C0274;
    if (nStep < 0)
    {
        const int nOld = gnGlobal_007C02B0;
        const int nNew = nOld <= 0 ? nOld : nOld - 1;
        if (nNew >= 0)
            gnGlobal_007C02B0 = nNew;
    }
    else if (nStep > 0 && gnGlobal_007C02B0 < nCount)
    {
        const int nNew = gnGlobal_007C02B0 + 1;
        if (nNew < nCount)
            gnGlobal_007C02B0 = nNew;
    }

    const int nSelected = gnGlobal_007C02B0;
    int nFirst = gnFirstVisible_007C02AC;
    if (nSelected < nFirst)
    {
        const int nTrackTop = sub_F08_TrackTop();
        gnFirstVisible_007C02AC = nSelected;
        gnThumbY_007C02CC = nSelected * sub_F08_TrackSpan() / sub_004A44C0_GetMaxFirstEntry() + nTrackTop;
        return;
    }

    for (;;)
    {
        int nLast = nFirst;
        for (int nLine = 0; nLast < nCount && nLine < 0x0F; ++nLine)
            ++nLast;
        if (gnGlobal_007C02B0 < nLast)
            break;

        const int nMax = sub_004A44C0_GetMaxFirstEntry();
        const int nNew = nFirst >= nMax ? nFirst : nFirst + 1;
        if (nNew <= nMax)
            nFirst = nNew;
        gnThumbY_007C02CC = sub_F08_TrackSpan() * nFirst / nMax + sub_F08_TrackTop();
    }
    gnFirstVisible_007C02AC = nFirst;
}

// 0x004A4720
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

// 0x004A4860
static __declspec(noinline) int sub_004A4860_IsOnUpArrow(int nX, int nY)
{
    if (nX >= sub_F08_PanelRight() - 0x1F && nX <= sub_F08_PanelRight() - 0x12)
    {
        const int nTop = sub_F08_ListTop();
        if (nY >= nTop + 0x23 && nY <= nTop + 0x2F)
            return 1;
    }
    return 0;
}

// 0x004A48B0
static __declspec(noinline) int sub_004A48B0_IsOnDownArrow(int nX, int nY)
{
    if (nX >= sub_F08_PanelRight() - 0x1F && nX <= sub_F08_PanelRight() - 0x12)
    {
        const int nTop = sub_F08_ListTop();
        if (nY >= nTop + 0x125 && nY <= nTop + 0x131)
            return 1;
    }
    return 0;
}

// 0x004A4900
static __declspec(noinline) int sub_004A4900_IsAboveThumb(int nX, int nY)
{
    if (nX >= sub_F08_PanelRight() - 0x1F && nX <= sub_F08_PanelRight() - 0x12)
    {
        if (nY > sub_F08_ListTop() + 0x2F && nY < gnThumbY_007C02CC)
            return 1;
    }
    return 0;
}

// 0x004A4950
static __declspec(noinline) int sub_004A4950_IsOnThumb(int nX, int nY)
{
    if (nX >= sub_F08_PanelRight() - 0x1F && nX <= sub_F08_PanelRight() - 0x12)
    {
        if (nY >= gnThumbY_007C02CC && nY <= gnThumbY_007C02CC + sub_F08_ThumbHeight())
            return 1;
    }
    return 0;
}

// 0x004A49A0
static __declspec(noinline) int sub_004A49A0_IsBelowThumb(int nX, int nY)
{
    if (nX >= sub_F08_PanelRight() - 0x1F && nX <= sub_F08_PanelRight() - 0x12)
    {
        if (nY < sub_F08_ListTop() + 0x125 && nY > gnThumbY_007C02CC + sub_F08_ThumbHeight())
            return 1;
    }
    return 0;
}

void __stdcall sub_004A4AD0_Press(int nX, int nY)
{
    gnPressedButton_007C02B4 = 3;
    if (gnGlobal_007C0284)
        return;

    const int bInList = sub_004A47F0_IsInList(nX, nY);
    const int bUp = sub_004A4860_IsOnUpArrow(nX, nY);
    const int bDown = sub_004A48B0_IsOnDownArrow(nX, nY);
    const int bPageUp = sub_004A4900_IsAboveThumb(nX, nY);
    const int bThumb = sub_004A4950_IsOnThumb(nX, nY);
    const int bPageDown = sub_004A49A0_IsBelowThumb(nX, nY);
    const int bButton = sub_004A47C0_GetButtonAt(nX, nY) != 3;

    if (sub_F08_NoOtherPressed(7) && !bInList && !bUp && !bDown && !bPageUp && !bThumb && !bPageDown && !bButton)
    {
        gnGlobal_007C0284 = gnGlobal_007C0280;
        return;
    }

    if (sub_F08_NoOtherPressed(0) && (bInList || gaPressed_007C0288[0]))
    {
        gaPressed_007C0288[0] = gnGlobal_007C0280;
        if (gnGlobal_007C0280)
        {
            const int nTop = sub_F08_ListTop();
            if (nY < nTop + 0x28)
                sub_004A45C0_MoveSelection(-1);
            if (nY > nTop + 0x136)
                sub_004A45C0_MoveSelection(1);

            const int nOldD4 = gnGlobal_007246D4;
            const int nOldSelected = gnGlobal_007C02B0;
            const int nLine = sub_004A4720_GetLineAt(nY);
            gnGlobal_007C02B0 = nLine;
            gnGlobal_007246D4 = sub_004A4780_IsAbovePanelLine(nX);
            if (gpListEntries_00724264[nLine].nId == 0x39)
            {
                gnGlobal_007246D4 = nOldD4;
                gnGlobal_007C02B0 = nOldSelected;
            }
        }
    }

    if (sub_F08_NoOtherPressed(1) && bUp)
    {
        gaPressed_007C0288[1] = gnGlobal_007C0280;
        if (gnGlobal_007C0280 && GetTickCount() > gdwLastTick_007C02C0 + 0x32)
        {
            gdwLastTick_007C02C0 = GetTickCount();
            sub_004A4500_ScrollList(-1);
        }
    }

    if (sub_F08_NoOtherPressed(2) && bDown)
    {
        gaPressed_007C0288[2] = gnGlobal_007C0280;
        if (gnGlobal_007C0280 && GetTickCount() > gdwLastTick_007C02C0 + 0x32)
        {
            gdwLastTick_007C02C0 = GetTickCount();
            sub_004A4500_ScrollList(1);
        }
    }

    if (sub_F08_NoOtherPressed(3) && bPageUp)
    {
        gaPressed_007C0288[3] = gnGlobal_007C0280;
        if (gnGlobal_007C0280 && GetTickCount() > gdwLastTick_007C02C0 + 0x32)
        {
            gdwLastTick_007C02C0 = GetTickCount();
            sub_004A4500_ScrollList(1 - sub_F08_VisibleLines());
        }
    }

    if (sub_F08_NoOtherPressed(4) && (bThumb || gaPressed_007C0288[4]))
    {
        if (bThumb && !gaPressed_007C0288[4] && gnGlobal_007C0280)
        {
            gnDragThumbY_007C02A4 = gnThumbY_007C02CC;
            gnDragMouseY_007C02A8 = nY;
        }
        gaPressed_007C0288[4] = gnGlobal_007C0280;
        if (gnGlobal_007C0280)
        {
            const int nTop = sub_F08_ListTop();
            sub_004A4500_ScrollList((gnDragThumbY_007C02A4 - nTop - gnDragMouseY_007C02A8 + nY - 0x2F)
                * (gnThumbRange_007C027C + 1) / sub_F08_TrackSpan() - gnFirstVisible_007C02AC);
        }
    }

    if (sub_F08_NoOtherPressed(5) && bPageDown)
    {
        gaPressed_007C0288[5] = gnGlobal_007C0280;
        if (gnGlobal_007C0280 && GetTickCount() > gdwLastTick_007C02C0 + 0x32)
        {
            gdwLastTick_007C02C0 = GetTickCount();
            sub_004A4500_ScrollList(sub_F08_VisibleLines() - 1);
        }
    }

    if (sub_F08_NoOtherPressed(6) && bButton)
    {
        gaPressed_007C0288[6] = gnGlobal_007C0280;
        gnPressedButton_007C02B4 = sub_004A47C0_GetButtonAt(nX, nY);
    }
}
