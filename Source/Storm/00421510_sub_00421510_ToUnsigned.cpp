struct D2StormBigBufferStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned int* f_8;
    unsigned int f_C;
    unsigned int m_offset;

    unsigned int At(unsigned int nIndex) const
    {
        return m_offset + nIndex < f_4 ? f_8[m_offset + nIndex] : 0;
    }
};

int __stdcall sub_004212F0_Compare(void* hLeft, void* hRight);                                             // 0x004212F0

// 0x00421510
static __declspec(noinline) void __cdecl sub_00421510_ToUnsigned(unsigned int* pnResult, D2StormBigBufferStrc* pBuf)
{
    *pnResult = 0;
    *pnResult = pBuf->At(0);
}
#define TO_UNSIGNED sub_00421510_ToUnsigned

// 0x00421530
int __stdcall sub_00421530(void* hLeft, void* hRight)
{
    return sub_004212F0_Compare(hLeft, hRight);
}

// 0x00421550
void __stdcall sub_00421550_ToUnsigned(void* hBig, unsigned int* pnResult)
{
    TO_UNSIGNED(pnResult, (D2StormBigBufferStrc*)hBig);
}
