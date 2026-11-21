#include "D2Win.h"
#include "D2Unicode.h"
#include "D2Win32Types.h"
#include "D2StormTypes.h"
#include "D2WinControls.h"
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct Character;
struct Unicode;
struct D2WinEditBoxStrc;

struct Character { signed char value; };

enum { FIRST_DIGIT = 48, LAST_DIGIT = 57 };

typedef int (__stdcall* D2WinMsgHandler)(SMSGHANDLER_PARAMS* pMsg);

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
    D2WinEditBoxStrc* ptEditData = (D2WinEditBoxStrc*)pMsg->hWnd;

    D2_ASSERT(ptEditData, 0x6D0);
    D2_ASSERT(ptEditData->controlHeader.eType == 1, 0x6D1);

    if (!(ptEditData->controlHeader.dwFlags & gdwBitMasks[2]) || !(ptEditData->controlHeader.dwFlags & gdwBitMasks[0]))
    {
        return 0;
    }

    int nX = gMousePosition_6F8FE234.x;
    int nY = gMousePosition_6F8FE234.y;
    sub_004F91C0(ptEditData);
    nX -= ptEditData->controlHeader.nImageX + ptEditData->nTextInsetX;
    nY += ptEditData->controlHeader.nHeight - ptEditData->nTextInsetY - ptEditData->controlHeader.nImageY;
    const int nRight = ptEditData->controlHeader.nWidth - ptEditData->nTextInsetX;
    const int bInside = nX >= -ptEditData->nTextInsetX && nX < nRight && nY > -ptEditData->nTextInsetY && nY < ptEditData->controlHeader.nHeight - ptEditData->nTextInsetY;

    const unsigned long dwTick = GetTickCount();
    if (bInside && !ptEditData->bMouseSelecting && ptEditData == gpLastClickedEditBox_00841B78 && dwTick - gdwLastClickTick_00841B7C < 300)
    {
        D2Win_10082(ptEditData);
    }
    else
    {
        if (ptEditData->bMouseSelecting || bInside)
        {
            int nChars = 1;
            sub_00502EF0(ptEditData->eFont);
            if (ptEditData->bMouseSelecting)
            {
                if (nX < -ptEditData->nTextInsetX)
                {
                    ptEditData->nCaretPosition = D2WIN_MAX(ptEditData->nCaretPosition - 1, 0);
                    sub_004FE7C0_UpdateVisibleChars();
                }
                else if (nX >= nRight)
                {
                    const int nLength = sub_00526800((Unicode*)ptEditData->wszText);
                    ptEditData->nCaretPosition = D2WIN_MIN(ptEditData->nCaretPosition + 1, nLength - 1);
                    sub_004FE7C0_UpdateVisibleChars();
                }
            }

            while (nX > D2Win_10122((Unicode*)&ptEditData->wszText[ptEditData->nFirstVisibleChar], nChars))
            {
                if (nChars > sub_00526800((Unicode*)&ptEditData->wszText[ptEditData->nFirstVisibleChar]))
                {
                    break;
                }
                ++nChars;
            }

            const int nOldCaret = ptEditData->nCaretPosition;
            ptEditData->nCaretPosition = ptEditData->nFirstVisibleChar + nChars - 1;
            if (!((unsigned int)GetKeyState(0x10) & 0x8000) && !ptEditData->bMouseSelecting)
            {
                sub_004FDCC0(ptEditData);
            }
            else
            {
                if (ptEditData->nSelectionStart == -1)
                {
                    ptEditData->nSelectionStart = nOldCaret;
                }
                ptEditData->nSelectionEnd = ptEditData->nCaretPosition;
            }
        }

        if (pMsg->uMessage == 0x201)
        {
            ptEditData->bMouseSelecting = 1;
        }
    }

    gpLastClickedEditBox_00841B78 = ptEditData;
    gdwLastClickTick_00841B7C = dwTick;
    if (ptEditData->controlHeader.field_34)
    {
        return ptEditData->controlHeader.field_34(pMsg);
    }

    return 0;
}
