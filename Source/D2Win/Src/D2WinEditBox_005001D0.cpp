#include "D2Win.h"
#include "D2CelContext.h"
#include "D2WinTypes.h"
#include "D2Unicode.h"
#include "D2Win32Types.h"
#include "D2StormTypes.h"
#include "D2WinControls.h"

struct D2WinControlStrc;

typedef int (__stdcall* D2WinMsgHandler)(SMSGHANDLER_PARAMS* pMsg);
typedef int (__fastcall* D2WinControlFn)(D2WinControlStrc* pControl);

struct D2WinFontAndColorStrc
{
    int eFont;
    int nColor;
};

struct D2AnimatedImageDescriptor
{
    D2CelFileStrc** ppCellFile1;
    D2CelFileStrc** ppCellFile2;
    int eDrawMode;
    unsigned int nAnimSpeed;
};

struct D2SplittedTextStrc
{
    Unicode* wszLine;
    D2SplittedTextStrc* pNextLine;
};
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
int __stdcall CONTROL_AppendToList(D2WinControlStrc* pControl);                                             // 0x004F9210
int __stdcall EDITBOX_HandleMouseUp(SMSGHANDLER_PARAMS* pMsg);                                              // 0x004FE350
int __fastcall sub_004FF620_EditBoxDrawAlt(D2WinControlStrc* pControl);                                     // 0x004FF620
int __stdcall sub_004FFBF0_EditBoxMouseDown(SMSGHANDLER_PARAMS* pMsg);                                      // 0x004FFBF0
int __fastcall sub_004FFE50_EditBoxDraw(D2WinControlStrc* pControl);                                        // 0x004FFE50
D2CelStrc* __stdcall CelGetHandle(D2CelContextStrc* pContext);                                        // 0x00601840
int __stdcall sub_006018F0(D2CelStrc* pCel);                                                                // 0x006018F0

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern tagPOINT gMousePosition_6F8FE234;                                                                    // 0x007D55A4

// 0x005001D0
D2WinEditBoxStrc* __fastcall D2Win_10070_EDITBOX_Create(int nX, int nY, int nWidth, int nHeight, int a5, int a6, D2CelFileStrc* pCellFile, int a8, D2WinMsgHandler a9, int nEditBoxFlags, D2WinFontAndColorStrc* pFontAndColor)
{
    D2WinEditBoxStrc* pEditBox = (D2WinEditBoxStrc*)FOG_Alloc(sizeof(D2WinEditBoxStrc), ".\\Src\\D2WinEditBox.cpp", 0x39, 0);
    memset(pEditBox, 0, sizeof(D2WinEditBoxStrc));
    pEditBox->controlHeader.eType = 1;
    pEditBox->controlHeader.dwFlags |= gdwBitMasks[0];
    pEditBox->controlHeader.dwFlags |= gdwBitMasks[2];
    pEditBox->controlHeader.pCellFile = pCellFile;
    pEditBox->controlHeader.nImageX = nX;
    pEditBox->controlHeader.nWidth = nWidth;
    pEditBox->controlHeader.nHeight = nHeight;
    pEditBox->nTextInsetX = a5;
    pEditBox->nTextInsetY = a6;
    pEditBox->nMaxLength = 256;
    pEditBox->controlHeader.nImageY = nY;
    pEditBox->nFirstVisibleChar = 0;
    pEditBox->nLastVisibleChar = 0;
    pEditBox->nSelectionStart = -1;
    pEditBox->controlHeader.pfDraw = (nEditBoxFlags & 8) ? sub_004FF620_EditBoxDrawAlt : sub_004FFE50_EditBoxDraw;
    pEditBox->controlHeader.pfHandleMouseDown = (nEditBoxFlags & 8) ? sub_004FE710_EditBoxMouseDownAlt : sub_004FFBF0_EditBoxMouseDown;
    pEditBox->controlHeader.pfHandleMouseUp = EDITBOX_HandleMouseUp;
    pEditBox->controlHeader.pfHandleCharInput = 0;
    pEditBox->controlHeader.pfHandleVirtualKeyInput = 0;
    pEditBox->pfFilter = 0;
    pEditBox->controlHeader.field_34 = a9;
    pEditBox->pfOnEnter = (void*)a8;
    pEditBox->controlHeader.pNext = 0;
    pEditBox->wszText[0] = 0;
    pEditBox->nCaretPosition = 0;
    pEditBox->dwEditBoxFlags = nEditBoxFlags;
    if (pFontAndColor)
    {
        pEditBox->eFont = pFontAndColor->eFont;
        pEditBox->nTextColor = pFontAndColor->nColor;
    }
    else
    {
        pEditBox->eFont = 1;
        pEditBox->nTextColor = 0;
    }
    pEditBox->pNext = 0;
    pEditBox->pPrevious = 0;
    CONTROL_AppendToList(&pEditBox->controlHeader);
    return pEditBox;
}



