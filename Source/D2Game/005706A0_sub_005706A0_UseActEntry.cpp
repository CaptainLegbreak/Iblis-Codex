struct D2GameStrc;
struct D2UnitStrc;

extern int gnActCount_007326B4;                                                                             // 0x007326B4
extern const int gnActEntries_006E1520[5];                                                                  // 0x006E1520
void __fastcall sub_0057EB10(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEntry);                             // 0x0057EB10

// 0x005706A0
static void __stdcall sub_005706A0_UseActEntry(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nAct)
{
    if (nAct >= 5)
    {
        nAct = 4;
    }
    if (nAct >= gnActCount_007326B4)
    {
        nAct = 0;
    }
    sub_0057EB10(pGame, pUnit, gnActEntries_006E1520[nAct]);
}

void __fastcall sub_K11_Emit005706A0(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nAct)
{
    sub_005706A0_UseActEntry(pGame, pUnit, nAct);
}

#include "gen/data/Source/D2Game/005706A0_sub_005706A0_UseActEntry.inc"
