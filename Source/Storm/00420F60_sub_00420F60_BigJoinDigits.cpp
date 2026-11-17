// 0x00420F60
static unsigned __int64 __stdcall sub_00420F60_BigJoinDigits(unsigned int nHigh, unsigned int nLow)
{
    return (unsigned __int64)nHigh * 0x100000000ui64 + nLow;
}

unsigned __int64 __stdcall sub_K01_Emit_00420F60(unsigned int nHigh, unsigned int nLow)
{
    return sub_00420F60_BigJoinDigits(nHigh, nLow);
}
