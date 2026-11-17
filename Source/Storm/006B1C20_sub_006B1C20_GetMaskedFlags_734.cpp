extern const unsigned int gdwMask_006CE278; // 0x006CE278
extern unsigned int gdwFlags_0096F3A8; // 0x0096F3A8

// 0x006B1C20
unsigned int __cdecl sub_006B1C20_GetMaskedFlags()
{
    return gdwFlags_0096F3A8 & gdwMask_006CE278;
}
