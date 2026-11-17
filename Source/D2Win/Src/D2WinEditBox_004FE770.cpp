#include "D2Win.h"

#define D2WIN_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2WIN_MIN(a, b) (((a) < (b)) ? (a) : (b))
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct Character;
struct Unicode;
struct D2WinEditBoxStrc;
struct tagPOINT;

struct Character { signed char value; };

enum { FIRST_DIGIT = 48, LAST_DIGIT = 57 };

struct Unicode
{
    unsigned short wChar;
};

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    unsigned int lParam;
};

typedef int (__stdcall* D2WinMsgHandler)(SMSGHANDLER_PARAMS* pMsg);

struct D2WinEditBoxStrc
{
    int nType;
    char pad04[0x4];
    unsigned int dwFlags;
    int nImageX;
    int nImageY;
    int nWidth;
    int nHeight;
    char pad1C[0x18];
    D2WinMsgHandler pfMouseDownHook;
    char f_38[0x8];
    int nTextInsetX;
    int nTextInsetY;
    int nMaxLength;
    int nFirstVisibleChar;
    int nLastVisibleChar;
    int nSelectionStart;
    int nSelectionEnd;
    Unicode wszText[256];
    int nCaretPosition;
    unsigned int dwEditBoxFlags;
    void* pfOnEnter;
    void* pfFilter;
    void* pfOnChange;
    int eFont;
    int nTextColor;
    D2WinEditBoxStrc* pNext;
    D2WinEditBoxStrc* pPrevious;
    int bDragging;
};

struct tagPOINT
{
    int x;
    int y;
};
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260
extern const unsigned int gdwBitMasks[]; // 0x006CE268
extern tagPOINT gMousePosition_6F8FE234; // 0x007D55A4
int __stdcall sub_004F91C0(D2WinEditBoxStrc* pEditBox); // 0x004F91C0
void __fastcall sub_004FDCC0(D2WinEditBoxStrc* pEditBox); // 0x004FDCC0
int __fastcall D2Win_10082(D2WinEditBoxStrc* pEditBox); // 0x004FDD00
void __cdecl sub_004FE7C0_UpdateVisibleChars(); // 0x004FE7C0
int __fastcall D2Win_10122(const Unicode* wszText, int nTextLength); // 0x005017D0
int __fastcall sub_00502EF0(int nArg); // 0x00502EF0
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

// 0x004FE770
int __stdcall sub_004FE770(void* unused1,void* unused2,const Character* text)
{
    return text->value>=FIRST_DIGIT && text->value<=LAST_DIGIT;
}

D2WinEditBoxStrc* gpLastClickedEditBox_00841B78; // 0x00841B78

static unsigned long gdwLastClickTick_00841B7C; // 0x00841B7C

// 0x004FFBF0
int __stdcall sub_004FFBF0_EditBoxMouseDown(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinEditBoxStrc* pEditBox = (D2WinEditBoxStrc*)pMsg->hWnd;

    D2_ASSERT(pEditBox, 0x6D0);
    D2_ASSERT(pEditBox->nType == 1, 0x6D1);

    if (!(pEditBox->dwFlags & gdwBitMasks[2]) || !(pEditBox->dwFlags & gdwBitMasks[0]))
    {
        return 0;
    }

    int nX = gMousePosition_6F8FE234.x;
    int nY = gMousePosition_6F8FE234.y;
    sub_004F91C0(pEditBox);
    nX -= pEditBox->nImageX + pEditBox->nTextInsetX;
    nY += pEditBox->nHeight - pEditBox->nTextInsetY - pEditBox->nImageY;
    const int nRight = pEditBox->nWidth - pEditBox->nTextInsetX;
    const int bInside = nX >= -pEditBox->nTextInsetX && nX < nRight && nY > -pEditBox->nTextInsetY && nY < pEditBox->nHeight - pEditBox->nTextInsetY;

    const unsigned long dwTick = GetTickCount();
    if (bInside && !pEditBox->bDragging && pEditBox == gpLastClickedEditBox_00841B78 && dwTick - gdwLastClickTick_00841B7C < 300)
    {
        D2Win_10082(pEditBox);
    }
    else
    {
        if (pEditBox->bDragging || bInside)
        {
            int nChars = 1;
            sub_00502EF0(pEditBox->eFont);
            if (pEditBox->bDragging)
            {
                if (nX < -pEditBox->nTextInsetX)
                {
                    pEditBox->nCaretPosition = D2WIN_MAX(pEditBox->nCaretPosition - 1, 0);
                    sub_004FE7C0_UpdateVisibleChars();
                }
                else if (nX >= nRight)
                {
                    const int nLength = sub_00526800(pEditBox->wszText);
                    pEditBox->nCaretPosition = D2WIN_MIN(pEditBox->nCaretPosition + 1, nLength - 1);
                    sub_004FE7C0_UpdateVisibleChars();
                }
            }

            while (nX > D2Win_10122(&pEditBox->wszText[pEditBox->nFirstVisibleChar], nChars))
            {
                if (nChars > sub_00526800(&pEditBox->wszText[pEditBox->nFirstVisibleChar]))
                {
                    break;
                }
                ++nChars;
            }

            const int nOldCaret = pEditBox->nCaretPosition;
            pEditBox->nCaretPosition = pEditBox->nFirstVisibleChar + nChars - 1;
            if (!((unsigned int)GetKeyState(0x10) & 0x8000) && !pEditBox->bDragging)
            {
                sub_004FDCC0(pEditBox);
            }
            else
            {
                if (pEditBox->nSelectionStart == -1)
                {
                    pEditBox->nSelectionStart = nOldCaret;
                }
                pEditBox->nSelectionEnd = pEditBox->nCaretPosition;
            }
        }

        if (pMsg->uMessage == 0x201)
        {
            pEditBox->bDragging = 1;
        }
    }

    gpLastClickedEditBox_00841B78 = pEditBox;
    gdwLastClickTick_00841B7C = dwTick;
    if (pEditBox->pfMouseDownHook)
    {
        return pEditBox->pfMouseDownHook(pMsg);
    }

    return 0;
}
