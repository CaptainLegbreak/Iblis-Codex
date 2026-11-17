// 0x00409000
int __fastcall sub_00409000_GetBitWidth(unsigned int nValue)
{
    if (!nValue)
    {
        return 0;
    }
    __asm
    {
        bsr eax, nValue
        inc eax
        mov nValue, eax
    }
    return nValue;
}

static inline int Log2Ceil(int nValue)
{
    if (nValue < 3)
    {
        return 1;
    }
    return sub_00409000_GetBitWidth(nValue - 1);
}

// 0x004091B0
static __declspec(noinline) int sub_004091B0_GetPoolIndex(int nSize)
{
    if (nSize <= 0x10)
    {
        return 0;
    }
    return Log2Ceil(nSize) - 4;
}

int __fastcall sub_M289_Emit_004091B0(int nUnused, int nSize)
{
    return sub_004091B0_GetPoolIndex(nSize);
}
