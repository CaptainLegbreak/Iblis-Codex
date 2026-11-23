#include "D2Client.h"
#include "D2Unicode.h"
#include "D2CelContext.h"
#include "D2StormTypes.h"

class UIWidget;
class SpinnerImplementation;
class SpinnerWrapper;
class ListBoxImplementation;
class ListBoxWrapper;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, int nFlags); // 0x00413020

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, int nFlags); // 0x00412650

void __fastcall UI_DrawRectangleBorder(D2RectStrc* pRect); // 0x00452E50

int __cdecl sub_00468730(); // 0x00468730

int __cdecl sub_00468740(); // 0x00468740

D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0

int __fastcall PANEL_CountLinesInView(ListBoxImplementation* pListBox); // 0x004BE340

int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

int __fastcall D2Win_10123(const Unicode* wszText, int nLength); // 0x00501730

void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320

int __fastcall sub_00502EF0(int nArg); // 0x00502EF0

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

extern void* gpListBoxSliderCel; // 0x007C546C

#pragma pack(push, 2)

class UIWidget
{
public:
    virtual ~UIWidget() = 0;

    static void* operator new(unsigned int nSize)
    {
// build: symbol ?gszNew@* 0x006CC82C
        return SMemAlloc(nSize, gszNew, -1, 0);
    }

    static void operator delete(void* pMemory)
    {
        if (pMemory)
        {
            SMemFree(pMemory, "delete", -1, 0);
        }
    }

    int unk0x04;
};

// build: symbol ??_7UIWidget@@6B@ 0x006DA6C0
// build: symbol ??_7ListBoxImplementation@@6B@ 0x006DAAEC
// build: symbol ??_7ListBoxWrapper@@6B@ 0x006DAAA4
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// build: symbol ??0D2ListBoxLineStrc@@QAE@XZ 0x004BEE30
// build: symbol ??3UIWidget@@SAXPAX@Z 0x004053F0
// 0x004BE080
UIWidget::~UIWidget()
{
}

// build: symbol ??_GListBoxImplementation@@UAEPAXI@Z 0x004BF8C0
// build: symbol ??_GListBoxWrapper@@UAEPAXI@Z 0x004BED10
// build: symbol ??_GSpinnerImplementation@@UAEPAXI@Z 0x004BC450
// build: symbol ??_GSpinnerWrapper@@UAEPAXI@Z 0x004BC250
// 0x004BC450
class SpinnerImplementation : public UIWidget
{
public:
    SpinnerImplementation();
    virtual ~SpinnerImplementation();                                       // 0x004BBE10
};

// 0x004BC250
class SpinnerWrapper : public UIWidget
{
public:
    SpinnerWrapper();
    virtual ~SpinnerWrapper();                                              // 0x004BC1F0

    UIWidget* pImpl;
};

struct D2ListBoxLineStrc
{
    inline D2ListBoxLineStrc()
    {
    }

    Unicode wszText0[0x400];
    Unicode f_800[0x400];
    Unicode f_1000[0x400];
    Unicode f_1800[0x400];
    Unicode f_2000[0x400];
    Unicode wszText5[0x400];
    short nFlags;
    int unk0x3002;
    int nData;
    int nFont;
};

struct D2ListScrollStrc
{
    int nX;
    int nY;
    int nRows;

    int DrawRows(D2CelContextStrc* pContext);
};

// 0x004BF8C0
class ListBoxImplementation : public UIWidget
{
public:
    ListBoxImplementation(int nX, int nY, int nWidth, int nHeight, int nArg10, int nArg14, int nArg18,
        int nCallback, bool bLargeFont);

    virtual void Slot01();
    virtual int sub_004BE860_WheelMsg(SMSGHANDLER_PARAMS* pMsg);                                            // 0x004BE860
    virtual int sub_004BF430_MouseDownMsg(SMSGHANDLER_PARAMS* pMsg);
    virtual int sub_004BF530(SMSGHANDLER_PARAMS* pMsg);                                                   // 0x004BF530
    virtual int sub_004BEB70_MouseMoveMsg(SMSGHANDLER_PARAMS* pMsg);
    virtual int sub_004BEBC0_KeyMsg(SMSGHANDLER_PARAMS* pMsg);                                              // 0x004BEBC0
    virtual int sub_004BE910_ScrollUp(SMSGHANDLER_PARAMS* pMsg);                                            // 0x004BE910
    virtual int sub_004BE990_ScrollDown(SMSGHANDLER_PARAMS* pMsg);                                          // 0x004BE990
    virtual int MsgSlot09(SMSGHANDLER_PARAMS* pMsg);                                                        // 0x004BEA40
    virtual int MsgSlot10(SMSGHANDLER_PARAMS* pMsg);                                                        // 0x004BEA30
    virtual int sub_004BEC30_GetSelectedIndex();                                                            // 0x004BEC30
    virtual void sub_004BE110_UpdateScrollBar();                                                            // 0x004BE110
    virtual int sub_004BE0A0_GetLineCount();                                                                // 0x004BE0A0
    virtual void sub_004BE0B0_Clear();                                                                      // 0x004BE0B0
    virtual void sub_004BE500_AddLine(const Unicode* wszText0, const Unicode* wszText1, const Unicode* wszText2,
        const Unicode* wszText3, const Unicode* wszText4, const Unicode* wszText5, int nArg20, int nData,
        int bUseDefault, int nArg2C);                                                                       // 0x004BE500

    void DrawClippedText(const Unicode* wszSource, int nX, int nY, int nColor);
    int HitTestScrollDown(SMSGHANDLER_PARAMS* pMsg);                                                        // 0x004BE770
    int HitTestScrollTrack(SMSGHANDLER_PARAMS* pMsg);                                                       // 0x004BE7C0
    int sub_004BE810_HitTestRect(SMSGHANDLER_PARAMS* pMsg);
    int sub_004BEA50_HitTestEntry(SMSGHANDLER_PARAMS* pMsg);                                                // 0x004BEA50
    int GetListEntryData(int nIndex);                                                                       // 0x004BEC40

    int HitTestTopRowInline(SMSGHANDLER_PARAMS* pMsg)
    {
        const int nMouseX = pMsg->nXpos;
        const int nMouseY = pMsg->nYpos;
        if (nMouseX > tBar.nX && nMouseX < tBar.nX + 0x10 && nMouseY > tBar.nY - 12 && nMouseY < tBar.nY)
        {
            return 1;
        }
        return 0;
    }

    D2ListBoxLineStrc aLines[0x80];
    int f_180708;
    int f_18070C;
    int nRectWidth;
    int nRectHeight;
    int nLineHeight;
    int f_18071C;
    int bTopPressed;
    int bBottomPressed;
    int bRowsPressed;
    int nPressY;
    int f_180730;
    int nCallbackRow;
    int nSelectedIndex;
    int nTextCount;
    int nArg14;
    int nArg18;
    unsigned short nEntryCount;
    int pfnCallback;
    int f_18074E;
    int unk0x180752;
    int unk0x180756;
    D2ListScrollStrc tBar;
    int nScrollStep;
    int nArg10;
    unsigned int nRepeatTicks;
    int nState;
};

// 0x004BED10
class ListBoxWrapper : public UIWidget
{
public:
    ListBoxWrapper(int nX, int nY, int nWidth, int nHeight, int nArg10, int nArg14, int nArg18, int nCallback,
        bool bLargeFont);
    virtual ~ListBoxWrapper();                                                                              // 0x004BECC0

    virtual void Slot01();
    virtual int sub_004BEE20_ForwardSlot08(SMSGHANDLER_PARAMS* pMsg);                                       // 0x004BEE20
    virtual int sub_004BED80_ForwardSlot0C(SMSGHANDLER_PARAMS* pMsg);                                       // 0x004BED80
    virtual int sub_004BED90_ForwardSlot10(SMSGHANDLER_PARAMS* pMsg);                                       // 0x004BED90
    virtual int sub_004BEDA0_ForwardSlot14(SMSGHANDLER_PARAMS* pMsg);                                       // 0x004BEDA0
    virtual int sub_004BEDB0_ForwardSlot18(SMSGHANDLER_PARAMS* pMsg);                                       // 0x004BEDB0
    virtual int sub_004BED50_ForwardSlot1C(SMSGHANDLER_PARAMS* pMsg);                                       // 0x004BED50
    virtual int sub_004BED40_ForwardSlot20(SMSGHANDLER_PARAMS* pMsg);                                       // 0x004BED40
    virtual int sub_004BED60_ForwardSlot24(SMSGHANDLER_PARAMS* pMsg);                                       // 0x004BED60
    virtual int sub_004BED70_ForwardSlot28(SMSGHANDLER_PARAMS* pMsg);                                       // 0x004BED70
    virtual int Slot11();                                                                                   // 0x004BEDC0
    virtual void sub_004BEDE0_ForwardSlot3C();                                                              // 0x004BEDE0
    virtual int sub_004BEDF0_ForwardGetEntryData(int nIndex);
    virtual int sub_004BEE00_Slot14();                                                                      // 0x004BEE00
    virtual void sub_004BEE10_Slot15();                                                                     // 0x004BEE10

    ListBoxImplementation* pImpl;
};

#pragma pack(pop)

typedef char check_line_size[(sizeof(D2ListBoxLineStrc) == 0x300E) ? 1 : -1];

typedef char check_listbox_size[(sizeof(ListBoxImplementation) == 0x180776) ? 1 : -1];

// 0x004BC1B0
int __stdcall SKILLS_Return0(int nUnused)
{
    return 0;
}

void __stdcall sub_00646010_Empty(int nUnused1, int nUnused2, int nUnused3)
{
}

void __stdcall sub_006460C0_Empty(int nUnused)
{
}

void __stdcall sub_006460D0_Empty(int nUnused1, int nUnused2, int nUnused3)
{
}

void __stdcall sub_006460E0_Empty(int nUnused)
{
}

// 0x004BE020
void __cdecl TEXT_LoadTextSliderCel()
{
    char szPath[0x104];
    sprintf(szPath, "%s\\ui\\menu\\textslid", gszDataGlobal);
    gpListBoxSliderCel = ARCHIVE_LoadClientCellFile(szPath, 0);
}

// 0x004BE410
void ListBoxImplementation::DrawClippedText(const Unicode* wszSource, int nX, int nY, int nColor)
{
    Unicode wszText[1024];
    sub_005267E0(wszText, wszSource);
    if (D2Win_10123(wszText, sub_00526800(wszText)) < nRectWidth - 0x32)
    {
        D2Win_10117_DrawText(wszText, nX, nY, nColor, 0);
        return;
    }

    while (D2Win_10123(wszText, sub_00526800(wszText)) > nRectWidth - 0x32)
    {
        wszText[sub_00526800(wszText) - 1].wChar = 0;
    }
    D2Win_10117_DrawText(wszText, nX, nY, nColor, 0);
}

// 0x004BE810
int ListBoxImplementation::sub_004BE810_HitTestRect(SMSGHANDLER_PARAMS* pMsg)
{
    const int nMouseX = pMsg->nXpos;
    const int nMouseY = pMsg->nYpos;
    if (nMouseX > f_180708 && nMouseX < f_180708 + nRectWidth && nMouseY > f_18070C && nMouseY < f_18070C + nRectHeight)
    {
        return 1;
    }
    return 0;
}

// 0x004BEB70
int ListBoxImplementation::sub_004BEB70_MouseMoveMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_004BE810_HitTestRect(pMsg))
    {
        sub_004BEA50_HitTestEntry(pMsg);
    }
    return 0;
}

// 0x004BEDF0
int ListBoxWrapper::sub_004BEDF0_ForwardGetEntryData(int nIndex)
{
    return pImpl->GetListEntryData(nIndex);
}

// build: context D2ListScrollStrc::DrawRows
__forceinline int D2ListScrollStrc::DrawRows(D2CelContextStrc* pContext)
{
    int i;
    for (i = 0; i < nRows; ++i)
    {
        pContext->nFrame = 13;
        sub_004F6480(pContext, nX, nY + 12 * (i + 1), -1, 5, 0);
    }
    return i;
}

// 0x004BEE90
void ListBoxImplementation::Slot01()
{
    D2RectStrc tRect;
    tRect.nTop = f_18070C;
    tRect.nLeft = f_180708;
    tRect.nRight = f_180708 + nRectWidth - 1;
    tRect.nBottom = f_18070C + nRectHeight - 1;
    UI_DrawRectangleBorder(&tRect);

    const int nOldFont = sub_00502EF0(nArg18);

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpListBoxSliderCel;
    tContext.nFrame = bTopPressed ? 11 : 9;
    tContext.nDirection = 0;
    sub_004F6480(&tContext, tBar.nX, tBar.nY, -1, 5, 0);

    const int i = tBar.DrawRows(&tContext);

    tContext.nFrame = bBottomPressed ? 10 : 8;
    sub_004F6480(&tContext, tBar.nX, tBar.nY + 12 * i, -1, 5, 0);

    int nDrawn = 0;
    const int nLines = PANEL_CountLinesInView(this);
    int nRow = 0;
    for (int nLine = f_180730; nLine < f_180730 + nLines && nLine < 0x80; ++nLine)
    {
        int nColor;
        if (nSelectedIndex == nLine && pfnCallback)
        {
            nColor = 3;
        }
        else
        {
            nColor = aLines[nLine].nData;
        }

        sub_00502EF0(aLines[nLine].nFont != 14 ? aLines[nLine].nFont : nArg18);

        if (aLines[nLine].wszText0[0].wChar)
        {
            DrawClippedText(aLines[nLine].wszText0, f_180708 + 0x20, f_18070C + 0x19 + nArg10 * nRow + nScrollStep * nDrawn, nColor);
            ++nDrawn;
        }
        if (aLines[nLine].f_800[0].wChar)
        {
            DrawClippedText(aLines[nLine].f_800, f_180708 + 0x20, f_18070C + 0x19 + nArg10 * nRow + nScrollStep * nDrawn, nColor);
            ++nDrawn;
        }
        if (aLines[nLine].f_1000[0].wChar)
        {
            DrawClippedText(aLines[nLine].f_1000, f_180708 + 0x20, f_18070C + 0x19 + nArg10 * nRow + nScrollStep * nDrawn, nColor);
            ++nDrawn;
        }
        if (aLines[nLine].f_1800[0].wChar)
        {
            DrawClippedText(aLines[nLine].f_1800, f_180708 + 0x20, f_18070C + 0x19 + nArg10 * nRow + nScrollStep * nDrawn, nColor);
            ++nDrawn;
        }
        if (aLines[nLine].f_2000[0].wChar)
        {
            DrawClippedText(aLines[nLine].f_2000, f_180708 + 0x20, f_18070C + 0x19 + nArg10 * nRow + nScrollStep * nDrawn, nColor);
            ++nDrawn;
        }
        if (aLines[nLine].wszText5[0].wChar)
        {
            DrawClippedText(aLines[nLine].wszText5, f_180708 + 0x20, f_18070C + 0x19 + nArg10 * nRow + nScrollStep * nDrawn, nColor);
            ++nDrawn;
        }
        ++nRow;
    }

    sub_004BE110_UpdateScrollBar();
    ++nState;

    SMSGHANDLER_PARAMS tMsg;
    tMsg.lParam = (unsigned short)sub_00468730() | ((unsigned int)(unsigned short)sub_00468740() << 16);
    const int nMouseX = (unsigned short)tMsg.lParam;
    const int nMouseY = tMsg.lParam >> 16;

    if (nMouseX > tBar.nX && nMouseX < tBar.nX + 16 && nMouseY > tBar.nY - 12 && nMouseY < tBar.nY && bTopPressed == 1)
    {
        if (++nRepeatTicks && nRepeatTicks % 10)
        {
            sub_004BE910_ScrollUp(&tMsg);
        }
    }
    else if (nMouseX > tBar.nX && nMouseX < tBar.nX + 16 && nMouseY > tBar.nY + 12 * tBar.nRows - 12 && nMouseY < tBar.nY + 12 * tBar.nRows
        && bBottomPressed == 1)
    {
        if (++nRepeatTicks && nRepeatTicks % 10)
        {
            sub_004BE990_ScrollDown(&tMsg);
        }
    }

    sub_00502EF0(nOldFont);
}

// 0x004BF430
int ListBoxImplementation::sub_004BF430_MouseDownMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (!sub_004BE810_HitTestRect(pMsg))
    {
        return 0;
    }

    f_18071C = 1;
    if (HitTestTopRowInline(pMsg) == 1)
    {
        bTopPressed = 1;
        nRepeatTicks = 0;
        return 1;
    }

    if (HitTestScrollDown(pMsg) == 1)
    {
        bBottomPressed = 1;
        nRepeatTicks = 0;
        return 1;
    }

    if (HitTestScrollTrack(pMsg) == 1)
    {
        nPressY = pMsg->nYpos;
        bRowsPressed = 1;
        return 1;
    }

    if (pfnCallback)
    {
        nCallbackRow = sub_004BEA50_HitTestEntry(pMsg);
    }
    return 1;
}

// 0x004BF650
ListBoxImplementation::ListBoxImplementation(int nX, int nY, int nWidth, int nHeight, int nArg10, int nArg14,
    int nArg18, int nCallback, bool bLargeFont)
{
    f_180708 = nX;
    f_18070C = nY;
    nRectWidth = nWidth;
    nRectHeight = nHeight;
    nCallbackRow = -1;
    nSelectedIndex = -1;
    this->nArg14 = nArg14;
    this->nArg18 = nArg18;
    f_18071C = 0;
    bRowsPressed = 0;
    bTopPressed = 0;
    bBottomPressed = 0;
    nState = 0;
    f_180730 = 0;
    nEntryCount = 0;
    for (int n = 0; n < 0x80; n++)
    {
        aLines[n].wszText0[0].wChar = 0;
        aLines[n].f_800[0].wChar = 0;
        aLines[n].f_1000[0].wChar = 0;
        aLines[n].f_1800[0].wChar = 0;
        aLines[n].f_2000[0].wChar = 0;
        aLines[n].wszText5[0].wChar = 0;
        aLines[n].nFlags = 0;
        aLines[n].nData = 0;
        aLines[n].nFont = 1;
        aLines[n].unk0x3002 = 0;
    }
    pfnCallback = nCallback;
    this->nArg10 = nArg10;
    tBar.nX = f_180708 + nRectWidth - 0x12;
    tBar.nY = f_18070C + 0x10;
    nScrollStep = 0xE;
    if (nRectHeight < 0x20)
    {
        tBar.nRows = 1;
    }
    else
    {
        tBar.nRows = (nRectHeight - 0x10) / 12 - 1;
    }
    f_18074E = 1;
    if (D2GFX_GetResolutionMode() == 2)
    {
        nLineHeight = bLargeFont ? 0x1C : 0x12;
    }
    else
    {
        nLineHeight = 0x12;
    }
}

// 0x004BF8F0
ListBoxWrapper::ListBoxWrapper(int nX, int nY, int nWidth, int nHeight, int nArg10, int nArg14, int nArg18,
    int nCallback, bool bLargeFont)
{
    pImpl = new ListBoxImplementation(nX, nY, nWidth, nHeight, nArg10, nArg14, nArg18, nCallback, bLargeFont);
}

SpinnerImplementation::SpinnerImplementation()
{
}

SpinnerWrapper::SpinnerWrapper()
{
    pImpl = 0;
}
