struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

int gdwGlobal_007A6AA0;                                                                                     // 0x007A6AA0
int __fastcall sub_00463EE0_IsPointInTileRect(D2UnitStrc* pUnit, int nX, int nY);                           // 0x00463EE0
int __stdcall UNITS_IsInMovingMode(D2UnitStrc* pUnit);                                                      // 0x00622D00
int __cdecl sub_0044BF30();                                                                                 // 0x0044BF30
unsigned int __cdecl sub_0044DAA0();                                                                        // 0x0044DAA0
unsigned int __cdecl sub_0044DAC0();                                                                        // 0x0044DAC0
void __fastcall sub_0044DAD0(unsigned int nValue);                                                          // 0x0044DAD0

struct D2HoverCoordStrc
{
    int nValue;
};

static __declspec(noinline) int __stdcall sub_00467000_CheckWarpTileHover(D2UnitStrc* pPlayer, D2HoverCoordStrc tY1, int nX2, int nY2, D2UnitStrc* pUnit, int nX1, int* pnFlag);

// 0x00467000
static int __stdcall sub_00467000_CheckWarpTileHover(D2UnitStrc* pPlayer, D2HoverCoordStrc tY1, int nX2, int nY2, D2UnitStrc* pUnit, int nX1, int* pnFlag)
{
    if (pUnit && pUnit->dwUnitType == 5
        && sub_00463EE0_IsPointInTileRect(pUnit, nX1, tY1.nValue)
        && sub_00463EE0_IsPointInTileRect(pUnit, nX2, nY2)
        && UNITS_IsInMovingMode(pPlayer)
        && sub_0044BF30())
    {
        if (sub_0044DAA0() < sub_0044DAC0())
        {
            sub_0044DAD0(sub_0044DAA0() + 0x1F4);
            return 1;
        }

        if (!*pnFlag)
        {
            sub_0044DAD0(sub_0044DAA0() + 0x1F4);
            *pnFlag = 1;
        }
    }

    return 0;
}

int __stdcall sub_662F_Emit_00467AC0(D2UnitStrc* pPlayer, D2UnitStrc* pUnit, int nPX, int nPY, int nX, int nY)
{
    D2HoverCoordStrc tY1;
    tY1.nValue = nPY;
    return sub_00467000_CheckWarpTileHover(pPlayer, tY1, nX, nY, pUnit, nPX, &gdwGlobal_007A6AA0);
}
