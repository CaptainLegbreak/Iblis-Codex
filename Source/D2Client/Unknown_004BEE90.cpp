#include "D2Client.h"
#include "D2CelContext.h"
#include "D2Unicode.h"
#include "D2StormTypes.h"

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))
struct Unicode;
struct D2RectStrc;
struct D2ListScrollStrc;
struct D2ListBoxLineStrc;
class ListBoxImplementation;
struct ListBoxView;

#pragma pack(push, 2)
struct D2ListScrollStrc
{
    int nX;
    int nY;
    int nRows;

    int DrawRows(D2CelContextStrc* pContext);
};

struct D2ListBoxLineStrc
{
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

class ListBoxImplementation
{
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual int sub_004BE910_ScrollUp(SMSGHANDLER_PARAMS* pMsg);
    virtual int sub_004BE990_ScrollDown(SMSGHANDLER_PARAMS* pMsg);
    virtual void Slot09();
    virtual void Slot10();
    virtual int Slot11();
    virtual void sub_004BBFB0();
    virtual int sub_004BE0A0_GetLineCount();
    virtual void sub_004BE0B0_Clear();

    void sub_004BE410_DrawClippedText(const Unicode* wszSource, int nX, int nY, int nColor);               // 0x004BE410

    int unk0x04;
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

#pragma pack(pop)
typedef char check_line_size[(sizeof(D2ListBoxLineStrc) == 0x300E) ? 1 : -1];

typedef char check_ctx_size[(sizeof(D2CelContextStrc) == 0x48) ? 1 : -1];

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void __fastcall sub_00452E50_DrawRectangleBorder(D2RectStrc* pRect); // 0x00452E50
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
int __fastcall sub_004BE340_CountLinesInView(ListBoxImplementation* pListBox); // 0x004BE340
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
int __fastcall sub_00502EF0(int nArg); // 0x00502EF0
extern void* gpCelFile_007C546C; // 0x007C546C

#pragma pack(push, 2)
struct ListBoxView
{
    void* pVtable;
    int unk0x04;
    char aLines[0x180700];
    int nRectX;
    int nRectY;
    int nRectWidth;
    int nRectHeight;
    int nLineHeight;
    int bMouseDown;
    int bTopPressed;
    int bBottomPressed;
    int bRowsPressed;
    int nPressY;
    int nTopIndex;
    int nCallbackRow;
    int nSelectedIndex;
    int nTextCount;
    int nArg14;
    int nArg18;
    unsigned short nEntryCount;
    int pfnCallback;
    int nVisibleRows;
    int nThumbStart;
    int nThumbEnd;
    int nX;
    int nY;

    void sub_004BE8D0_Refresh();                                                                            // 0x004BE8D0
    int sub_004BF2F0_ClickScrollTrack(SMSGHANDLER_PARAMS* pMsg);
};

#pragma pack(pop)

int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00

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
    sub_00452E50_DrawRectangleBorder(&tRect);

    const int nOldFont = sub_00502EF0(nArg18);

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpCelFile_007C546C;
    tContext.nFrame = bTopPressed ? 11 : 9;
    tContext.nDirection = 0;
    sub_004F6480(&tContext, tBar.nX, tBar.nY, -1, 5, 0);

    const int i = tBar.DrawRows(&tContext);

    tContext.nFrame = bBottomPressed ? 10 : 8;
    sub_004F6480(&tContext, tBar.nX, tBar.nY + 12 * i, -1, 5, 0);

    int nDrawn = 0;
    const int nLines = sub_004BE340_CountLinesInView(this);
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
            sub_004BE410_DrawClippedText(aLines[nLine].wszText0, f_180708 + 0x20, f_18070C + 0x19 + nArg10 * nRow + nScrollStep * nDrawn, nColor);
            ++nDrawn;
        }
        if (aLines[nLine].f_800[0].wChar)
        {
            sub_004BE410_DrawClippedText(aLines[nLine].f_800, f_180708 + 0x20, f_18070C + 0x19 + nArg10 * nRow + nScrollStep * nDrawn, nColor);
            ++nDrawn;
        }
        if (aLines[nLine].f_1000[0].wChar)
        {
            sub_004BE410_DrawClippedText(aLines[nLine].f_1000, f_180708 + 0x20, f_18070C + 0x19 + nArg10 * nRow + nScrollStep * nDrawn, nColor);
            ++nDrawn;
        }
        if (aLines[nLine].f_1800[0].wChar)
        {
            sub_004BE410_DrawClippedText(aLines[nLine].f_1800, f_180708 + 0x20, f_18070C + 0x19 + nArg10 * nRow + nScrollStep * nDrawn, nColor);
            ++nDrawn;
        }
        if (aLines[nLine].f_2000[0].wChar)
        {
            sub_004BE410_DrawClippedText(aLines[nLine].f_2000, f_180708 + 0x20, f_18070C + 0x19 + nArg10 * nRow + nScrollStep * nDrawn, nColor);
            ++nDrawn;
        }
        if (aLines[nLine].wszText5[0].wChar)
        {
            sub_004BE410_DrawClippedText(aLines[nLine].wszText5, f_180708 + 0x20, f_18070C + 0x19 + nArg10 * nRow + nScrollStep * nDrawn, nColor);
            ++nDrawn;
        }
        ++nRow;
    }

    sub_004BBFB0();
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

// 0x004BF2F0
int ListBoxView::sub_004BF2F0_ClickScrollTrack(SMSGHANDLER_PARAMS* pMsg)
{
    const int nMouseY = pMsg->nYpos;
    const unsigned short nCount = nEntryCount;
    const int nTop = nY;

    if (nCount && nVisibleRows <= nCount && nMouseY - nTop > 0)
    {
        if (nThumbStart != nThumbEnd)
        {
            if (nMouseY < nTop + 12 * nThumbStart + 13)
            {
                if (nSelectedIndex - nVisibleRows > 0)
                    nSelectedIndex = nSelectedIndex - nVisibleRows;
                else
                    nSelectedIndex = 0;
            }
            else
            {
                if (nMouseY <= nY + 12 * nThumbEnd + 13)
                {
                    return 0;
                }

                if (nSelectedIndex + nVisibleRows >= nCount)
                    nSelectedIndex = nCount - 1;
                else
                    nSelectedIndex = nSelectedIndex + nVisibleRows;
                if (nCount - nSelectedIndex < nVisibleRows)
                {
                    if (nCount >= nVisibleRows)
                    {
                        nSelectedIndex = nCount - nVisibleRows;
                    }
                    else
                    {
                        nSelectedIndex = 0;
                    }
                }
            }

            if (nSelectedIndex >= 0x80)
            {
                nSelectedIndex = D2_MAX(0, nCount - 1);
            }

            nTopIndex = nSelectedIndex;
            sub_004B9A00(1, 0, 0, 0, 0);
            sub_004BE8D0_Refresh();
            return 1;
        }

        return 0;
    }

    return 0;
}
