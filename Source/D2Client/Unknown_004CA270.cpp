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

// 0x004CA870
static inline D2TimedHintNodeStrc** sub_004CA870_GetUnitHintList(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0xC2C);
    return (D2TimedHintNodeStrc**)&pUnit->pUnitSfxData;
}

D2TimedHintNodeStrc** __stdcall sub_M121_Emit_004CA870(D2UnitStrc* pUnit) { return sub_004CA870_GetUnitHintList(pUnit); }

// 0x004CAA70
static inline int sub_004CAA70_GetUnitByte70(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0xC8F);
    return pUnit->bUnitSfx;
}

int __stdcall sub_M121_Emit_004CAA70(D2UnitStrc* pUnit) { return sub_004CAA70_GetUnitByte70(pUnit); }

// 0x004CAC00
static inline int sub_004CAC00_GetUnitField84(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0xCE7);
    return pUnit->dwSfxStepTicks;
}

int __stdcall sub_M121_Emit_004CAC00(D2UnitStrc* pUnit) { return sub_004CAC00_GetUnitField84(pUnit); }

// 0x004CAC70
static inline int sub_004CAC70_GetUnitField88(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0xCFD);
    return pUnit->bHasActiveSound;
}

int __stdcall sub_M121_Emit_004CAC70(D2UnitStrc* pUnit) { return sub_004CAC70_GetUnitField88(pUnit); }
