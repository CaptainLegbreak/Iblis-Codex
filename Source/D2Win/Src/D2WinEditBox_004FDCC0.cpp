#include "D2Win.h"
#include "D2WinTypes.h"
#include "D2Unicode.h"
#include "D2StormTypes.h"
#include "D2WinControls.h"

enum D2ControlTypes
{
    D2WIN_EDITBOX = 1,
};

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                              // 0x00408090

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x004FDCC0
void __fastcall EDITBOX_ClearSelection(D2WinEditBoxStrc* ptEditData)
{
    D2_ASSERT(ptEditData, 0x1A4);
    D2_ASSERT(ptEditData->controlHeader.eType == D2WIN_EDITBOX, 0x1A6);
    ptEditData->nSelectionStart = -1;
    ptEditData->nSelectionEnd = 0;
}
