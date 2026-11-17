typedef int (__fastcall* D2CalcOperandCountFn)(int nFunctionId);

__declspec(noinline)
// 0x006C1820
static int __stdcall sub_006C1820_GetOperandCount(
    unsigned char nToken, D2CalcOperandCountFn pfnGetOperandCount, int nFunctionId)
{
    switch (nToken)
    {
    case 22:
        return 3;
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
        return 2;
    case 21:
        return 1;
    case 1:
        if (pfnGetOperandCount)
            return pfnGetOperandCount(nFunctionId);
        return 2;
    default:
        return 0;
    }
}

extern "C" int __stdcall EmitOperandCountComparison(
    unsigned char nToken, D2CalcOperandCountFn pfnGetOperandCount,
    int nFunctionId, int nAvailableOperands)
{
    return nAvailableOperands >= sub_006C1820_GetOperandCount(
        nToken, pfnGetOperandCount, nFunctionId);
}
