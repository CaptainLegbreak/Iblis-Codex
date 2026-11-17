struct D2UnitStrc;

typedef int (__fastcall* AREASCANFN)(void* pArg, D2UnitStrc* pUnit);

int __fastcall sub_004C5C40_ScanArea(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nFlags, AREASCANFN pfCallback, void* pArg, int bCheckType); // 0x004C5C40
int __fastcall sub_004C5E20_CountCallback(void* pArg, D2UnitStrc* pUnit);                                   // 0x004C5E20

// 0x004C5E30
int __fastcall sub_004C5E30_ScanCount(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nFlags)
{
    int nResult = 0;
    sub_004C5C40_ScanArea(pUnit, nX, nY, nRange, nFlags | 0xA783, sub_004C5E20_CountCallback, &nResult, 0);
    return nResult;
}
