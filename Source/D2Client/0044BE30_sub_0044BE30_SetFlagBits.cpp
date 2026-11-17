struct D2FlagWordStrc
{
    unsigned short wFlags;
};

// 0x0044BE30
unsigned short __fastcall sub_0044BE30_SetFlagBits(D2FlagWordStrc* pFlags, unsigned short nValue)
{
    pFlags->wFlags = (pFlags->wFlags & 0xE0FF) | (nValue << 8);
    return pFlags->wFlags;
}
