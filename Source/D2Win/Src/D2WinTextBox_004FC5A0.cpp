#include "D2WinControls.h"
struct Unicode;
struct D2WinScrollBarStrc;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" int __fastcall sub_00507EF0_GetScrollBarField48(D2WinScrollBarStrc* ptScrollbarData); // 0x00507EF0

#ifdef MOVED_TEST
#define ASSERT_LINE(x) ((x)+2)
#define TEXTBOX_TYPE 6
#else
#define ASSERT_LINE(x) (x)
#define TEXTBOX_TYPE 4
#endif
// 0x004FC5A0
extern "C" int __fastcall sub_004FC5A0_GetMaxSteps(D2WinTextBoxStrc* ptTextData)
{
    D2_ASSERT(ptTextData, ASSERT_LINE(0x578));
    D2_ASSERT(ptTextData->controlHeader.eType == TEXTBOX_TYPE, ASSERT_LINE(0x579));
    return sub_00507EF0_GetScrollBarField48(ptTextData->pScrollBar);
}
