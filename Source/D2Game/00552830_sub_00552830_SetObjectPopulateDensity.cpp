extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0xB4];
    unsigned int dwFlags;
    char unk0xC8[0x1C];
    D2UnitStrc* pListNext;
};

extern unsigned char gnObjectPopulateDensity_00731BBD;                                                      // 0x00731BBD

void __stdcall sub_M127_EmitSink(D2UnitStrc* pUnit);

// 0x00552830
void __fastcall sub_00552830_SetObjectPopulateDensity(unsigned char nDensity)
{
    gnObjectPopulateDensity_00731BBD = nDensity;
}

// 0x00552D80
void __fastcall sub_00552D80_SetListNext(D2UnitStrc* pUnit, D2UnitStrc* pNext)
{
    D2_ASSERT(pUnit, 211);
    pUnit->pListNext = pNext;
}

// 0x00552DE0
static __forceinline void sub_00552DE0_SetFlag2AndField(D2UnitStrc* pUnit, int nValue)
{
    if (pUnit)
    {
        pUnit->dwFlags |= 2;
        pUnit->dwUnitId = nValue;
    }
}

void __fastcall sub_M127_Emit_00552DE0(D2UnitStrc* pUnit, int nValue)
{
    sub_00552DE0_SetFlag2AndField(pUnit, nValue);
    sub_M127_EmitSink(pUnit);
}

#include "gen/data/Source/D2Game/00552830_sub_00552830_SetObjectPopulateDensity.inc"
