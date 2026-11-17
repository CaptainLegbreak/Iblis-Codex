struct D2DynamicPathStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x24];
    D2DynamicPathStrc* pDynamicPath;
};

D2UnitStrc* gpPlayerUnit_007A6A70;                                                                          // 0x007A6A70
extern unsigned char gnCharClass_007A0522;                                                                  // 0x007A0522

void __cdecl sub_00453DE0();                                                                                // 0x00453DE0
void __stdcall sub_006488A0_SetDirection(D2DynamicPathStrc* pPath, int nDirection);                         // 0x006488A0
void __fastcall sub_0044BEA0_SetValue(int nValue);                                                          // 0x0044BEA0
void __cdecl sub_00453D90_RunSequenceA();                                                                   // 0x00453D90

static __forceinline int CUNIT_GetUnitClassId(D2UnitStrc* pUnit)
{
    int nClassId = -1;
    if (pUnit)
    {
        nClassId = pUnit->dwClassId;
    }
    return nClassId;
}

// 0x00463D90
void __fastcall sub_00463D90_SetPlayerUnit(D2UnitStrc* pUnit)
{
    if (gpPlayerUnit_007A6A70)
    {
        sub_00453DE0();
    }

    if (pUnit)
    {
        sub_006488A0_SetDirection(pUnit->pDynamicPath, 0);
        gnCharClass_007A0522 = (unsigned char)CUNIT_GetUnitClassId(pUnit);
        sub_0044BEA0_SetValue(0);
        sub_00453D90_RunSequenceA();
    }

    gpPlayerUnit_007A6A70 = pUnit;
}
