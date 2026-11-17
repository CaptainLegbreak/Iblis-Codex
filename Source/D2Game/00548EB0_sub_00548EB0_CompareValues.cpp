// 0x00548EB0
static int __stdcall sub_00548EB0_CompareValues(int nValue, int nExpected)
{
    return nValue == nExpected ? 0 : 3;
}

int __fastcall sub_K10_EmitCompareValues(int a, int b)
{
    return sub_00548EB0_CompareValues(a, b) + sub_00548EB0_CompareValues(b, a + 1);
}
