#include "D2DataTbls.h"

#include "D2Structs.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2TimedHintNodeStrc;

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

// 0x004CA270
int __cdecl sub_004CA270_GetLevelsTxtRecordCount()
{
    return sgptDataTables->nLevelsTxtRecordCount;
}
