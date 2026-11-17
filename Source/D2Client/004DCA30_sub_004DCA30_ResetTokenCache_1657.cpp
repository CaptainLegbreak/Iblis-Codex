extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" int __cdecl sub_004817F0_GetFirstTokenCount(); // 0x004817F0
extern "C" int __cdecl sub_00481800_GetSecondTokenCount(); // 0x00481800
extern "C" void* __cdecl sub_00481810_GetTokenData(); // 0x00481810
extern "C" char* gpGlobal_007A0438; // 0x007A0438
extern "C" int gnGlobal_007C89D0; // 0x007C89D0
extern "C" int gnGlobal_007C89D4; // 0x007C89D4
extern "C" int gnGlobal_007C89D8; // 0x007C89D8
extern "C" int gnGlobal_007C89DC; // 0x007C89DC
extern "C" int gnGlobal_007C89E0; // 0x007C89E0
extern "C" int gnGlobal_007C89E4; // 0x007C89E4
extern "C" int gnGlobal_007C8A04; // 0x007C8A04

// 0x004DCA30
void __cdecl sub_004DCA30_ResetTokenCache()
{
    if (gpGlobal_007A0438[0x220])
        return;

    gnGlobal_007C89D0 = 0;
    gnGlobal_007C89D4 = 0;
    gnGlobal_007C89D8 = 0;
    gnGlobal_007C89DC = 0;
    gnGlobal_007C89E0 = 0;
    gnGlobal_007C89E4 = 0;
    gnGlobal_007C8A04 = 0;

    void* pTokenData = sub_00481810_GetTokenData();
    if (pTokenData)
    {
        memset(pTokenData, 0, (1 - sub_004817F0_GetFirstTokenCount() + sub_00481800_GetSecondTokenCount()) * 4);
    }
}
