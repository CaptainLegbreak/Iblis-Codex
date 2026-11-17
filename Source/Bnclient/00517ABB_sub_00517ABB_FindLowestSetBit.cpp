// 0x00517ABB
int __cdecl sub_00517ABB_FindLowestSetBit(unsigned int dwMask)
{
    int nIndex;
    if (!dwMask)
        return 0;
    __asm
    {
        bsf eax, dwMask
        inc eax
        mov nIndex, eax
    }
    return nIndex;
}
