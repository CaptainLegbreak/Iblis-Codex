struct D2GfxSettingsStrc
{
    int bPerspectiveEnabled;
    int bPerspectiveCapable;
    int bLowQuality;
    int nGamma;
    int bVSync;
    int bBlendedShadows;
};

int __cdecl sub_00509E10_GlideClose();                                                                      // 0x00509E10

int gdwGlobal_007B57E4;                                                                                     // 0x007B57E4
extern D2GfxSettingsStrc* gpGfxSettings_007C9148;                                                           // 0x007C9148
extern void (__stdcall* gpfGlideBufferClear_0087EB88)(unsigned int dwColor, unsigned int nAlpha, unsigned int nDepth); // 0x0087EB88
extern void (__stdcall* gpfGlideBufferSwap_0087EB90)(int nSwapInterval);                                    // 0x0087EB90
extern int gdwGlobal_0087EFE8;                                                                              // 0x0087EFE8

// 0x005090A0
void __fastcall sub_005090A0_SetGlobal(int nValue)
{
    gdwGlobal_007B57E4 = nValue;
}

// 0x00509660
void __fastcall sub_00509660_SetGlobal(int nValue)
{
    gdwGlobal_0087EFE8 = nValue;
}

// 0x00509A70
void __cdecl sub_00509A70_GlideClearAndSwap()
{
    gpfGlideBufferClear_0087EB88(0, 0, 0);
    if (gpGfxSettings_007C9148->bVSync)
    {
        gpfGlideBufferSwap_0087EB90(1);
    }
    else
    {
        gpfGlideBufferSwap_0087EB90(0);
    }
}

// 0x00509FD0
void __cdecl sub_00509FD0_GlideCloseAtExit()
{
    sub_00509E10_GlideClose();
}
