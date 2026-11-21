#include "D2CmpCelFile.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#ifdef MOVED_TEST
#define ASSERT_LINE 0x5B6
#else
#define ASSERT_LINE 0x5B4
#endif
// 0x00601980
char* __stdcall sub_00601980(D2CelStrc* pCel)
{
    D2_ASSERT(pCel, ASSERT_LINE);
    return pCel->data;
}
