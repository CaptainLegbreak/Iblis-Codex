// 0x00409220
int __fastcall sub_00409220_FindZeroBit(unsigned int dwMask)
{
    __asm
    {
        mov ebx, dwMask
        not ebx
        bsf eax, ebx
        mov dwMask, eax
    }
    return dwMask;
}
