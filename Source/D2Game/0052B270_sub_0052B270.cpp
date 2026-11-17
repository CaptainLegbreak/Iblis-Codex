struct D2GameStrc;
struct D2UnitStrc;

extern unsigned char gaByteTable_007455C0[256];                                                             // 0x007455C0
extern unsigned char gaByteTable_00745640[256];                                                             // 0x00745640
void __fastcall sub_0055DBC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nArg);    // 0x0055DBC0
void __fastcall sub_005FE000_StoreTileFreeCallback(void* pfnCallback);                                      // 0x005FE000
extern void* gpGlobal_00882D08;                                                                             // 0x00882D08
int __stdcall sub_006BE450(void* pObject);                                                                  // 0x006BE450
void __stdcall sub_006BF5F0(void* pObject);                                                                 // 0x006BF5F0

// 0x0063E780
unsigned char __stdcall sub_0063E780_GetByteTableEntry(unsigned char nIndex)
{
    return gaByteTable_007455C0[nIndex];
}

// 0x0063E7C0
unsigned char __stdcall sub_0063E7C0_GetByteTableEntry(unsigned char nIndex)
{
    return gaByteTable_00745640[nIndex];
}

// 0x0055DF00
void __fastcall sub_0055DF00_RecalcItemStates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnused, int nArg)
{
    sub_0055DBC0(pGame, pUnit, nArg);
}

// 0x00604A30
void __stdcall sub_00604A30_StoreTileFreeHandler(void* pfnCallback)
{
    sub_005FE000_StoreTileFreeCallback(pfnCallback);
}

// 0x0052B270
int __fastcall sub_0052B270()
{
    return sub_006BE450(gpGlobal_00882D08);
}

// 0x0052B6F0
void __fastcall sub_0052B6F0()
{
    sub_006BF5F0(gpGlobal_00882D08);
}

#include "gen/data/Source/D2Game/0052B270_sub_0052B270.inc"
