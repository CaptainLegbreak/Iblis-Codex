extern int gnGlobal_007A7460;                                                                               // 0x007A7460
extern int gnGlobal_007129D0;                                                                               // 0x007129D0

// 0x0046BD20
static __forceinline int sub_0046BD20_GetChaosLevelLight(unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue)
{
    if (gnGlobal_007A7460 && gnGlobal_007129D0 == -1)
    {
        *pRed = 0xFF;
        *pGreen = 0x40;
        *pBlue = 0x30;
        return 0xA0;
    }
    return 0;
}

int __stdcall sub_M212_Emit_0046BD20(unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue)
{
    return sub_0046BD20_GetChaosLevelLight(pRed, pGreen, pBlue);
}
