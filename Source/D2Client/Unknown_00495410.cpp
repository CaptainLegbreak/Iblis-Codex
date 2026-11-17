struct Unicode
{
    unsigned short wChar;
};

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...);               // 0x005269D0
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
const Unicode* __fastcall sub_00469DE0_GetKeyText(int nKey, int nArg2);                                     // 0x00469DE0
int __fastcall sub_004538D0(int nUIVar);                                                             // 0x004538D0
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
int __cdecl D2GFX_GetResolutionMode();                                                                      // 0x004F5160
void __cdecl sub_004943B0_DrawFrameCels();                                                                  // 0x004943B0
void __cdecl sub_004944F0_DrawFrameCels();                                                                  // 0x004944F0
void __cdecl sub_00494620_DrawColumn();                                                                     // 0x00494620
void __cdecl sub_00494680_DrawCelsAndLines();                                                               // 0x00494680
void __cdecl sub_00494A00_DrawCelsAndLines();                                                               // 0x00494A00
void __cdecl sub_00494E40_DrawPanelCel();                                                                   // 0x00494E40
void __cdecl sub_00495DC0_DrawHelpText();                                                                   // 0x00495DC0
extern int gbHelpUiOpened_007BEF00;                                                                         // 0x007BEF00

static int __fastcall GetCenteredX_Inl(unsigned short nString, int nX)
{
    Unicode wszText[100];
    for (int i = 0; i < 100; ++i)
    {
        wszText[i].wChar = 0;
    }
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(nString));
    int nWidth = sub_00501820(wszText);
    nWidth /= 2;
    return nX - nWidth;
}

// 0x00495410
void __cdecl sub_00495410_DrawHelpText()
{
    Unicode wszLine1[100];
    Unicode wszLine2[100];
    Unicode wszLine3[100];
    Unicode wszLine4[100];
    Unicode wszLine5[100];

    sub_00502320(D2LANG_GetStringFromTblIndex(0x1066), GetCenteredX_Inl(0x1066, 0x17C), 0x11, 0, 0);

    sub_00502320(D2LANG_GetStringFromTblIndex(0x1030), GetCenteredX_Inl(0x1030, 0x2BD), 0x49, 0, 0);

    const int nOldFont = sub_00502EF0(5);

    for (int i = 0; i < 100; ++i)
    {
        wszLine1[i].wChar = 0;
    }
    sub_005269D0(sizeof(wszLine1) / sizeof(wszLine1[0]), wszLine1, D2LANG_GetStringFromTblIndex(0x1067), sub_00469DE0_GetKeyText(0x22, 1));
    sub_00502320(wszLine1, 0x75, 0x4E, 0, 0);

    for (int i = 0; i < 100; ++i)
    {
        wszLine2[i].wChar = 0;
    }
    sub_005269D0(sizeof(wszLine2) / sizeof(wszLine2[0]), wszLine2, D2LANG_GetStringFromTblIndex(0x1068), sub_00469DE0_GetKeyText(0x25, 1));
    sub_00502320(wszLine2, 0x75, 0x62, 0, 0);

    for (int i = 0; i < 100; ++i)
    {
        wszLine3[i].wChar = 0;
    }
    sub_005269D0(sizeof(wszLine3) / sizeof(wszLine3[0]), wszLine3, D2LANG_GetStringFromTblIndex(0x1069), sub_00469DE0_GetKeyText(0x24, 1));
    sub_00502320(wszLine3, 0x75, 0x76, 0, 0);

    for (int i = 0; i < 100; ++i)
    {
        wszLine4[i].wChar = 0;
    }
    sub_005269D0(sizeof(wszLine4) / sizeof(wszLine4[0]), wszLine4, D2LANG_GetStringFromTblIndex(0x106A), sub_00469DE0_GetKeyText(0x7, 1));
    sub_00502320(wszLine4, 0x75, 0x8A, 0, 0);

    sub_00502320(D2LANG_GetStringFromTblIndex(0x106B), 0x75, 0x9E, 0, 0);

    sub_00502320(D2LANG_GetStringFromTblIndex(0x106C), 0x75, 0xB2, 0, 0);

    sub_00502320(D2LANG_GetStringFromTblIndex(0x106D), 0x75, 0xC6, 0, 0);

    for (int i = 0; i < 100; ++i)
    {
        wszLine5[i].wChar = 0;
    }
    sub_005269D0(sizeof(wszLine5) / sizeof(wszLine5[0]), wszLine5, D2LANG_GetStringFromTblIndex(0x106E), sub_00469DE0_GetKeyText(0x6, 1));
    sub_00502320(wszLine5, 0x75, 0xDA, 0, 0);

    sub_00502320(D2LANG_GetStringFromTblIndex(0x106F), GetCenteredX_Inl(0x106F, 0x3B), 0x1E1, 0, 0);

    sub_00502320(D2LANG_GetStringFromTblIndex(0x1070), GetCenteredX_Inl(0x1070, 0x86), 0x19A, 0, 0);

    sub_00502320(D2LANG_GetStringFromTblIndex(0x1071), GetCenteredX_Inl(0x1071, 0x86), 0x1A9, 0, 0);

    sub_00502320(D2LANG_GetStringFromTblIndex(0x1072), GetCenteredX_Inl(0x1072, 0x86), 0x1B8, 0, 0);

    sub_00502320(D2LANG_GetStringFromTblIndex(0xF92), GetCenteredX_Inl(0xF92, 0xDE), 0x177, 0, 0);

    sub_00502320(D2LANG_GetStringFromTblIndex(0x1074), GetCenteredX_Inl(0x1074, 0x108), 0x1FA, 0, 0);

    sub_00502320(D2LANG_GetStringFromTblIndex(0x1075), GetCenteredX_Inl(0x1075, 0x108), 0x209, 0, 0);

    sub_00502320(D2LANG_GetStringFromTblIndex(0x1076), GetCenteredX_Inl(0x1076, 0x13A), 0x1E1, 0, 0);

    sub_00502320(D2LANG_GetStringFromTblIndex(0x1077), GetCenteredX_Inl(0x1077, 0x171), 0x1F9, 0, 0);

    sub_00502320(D2LANG_GetStringFromTblIndex(0x1078), GetCenteredX_Inl(0x1078, 0x171), 0x208, 0, 0);

    sub_00502320(D2LANG_GetStringFromTblIndex(0x1079), GetCenteredX_Inl(0x1079, 0x1C1), 0x191, 0, 0);

    sub_00502320(D2LANG_GetStringFromTblIndex(0x107A), GetCenteredX_Inl(0x107A, 0x1C1), 0x1A0, 0, 0);

    sub_00502320(D2LANG_GetStringFromTblIndex(0x107B), GetCenteredX_Inl(0x107B, 0x1C1), 0x1AF, 0, 0);

    sub_00502320(D2LANG_GetStringFromTblIndex(0x107C), GetCenteredX_Inl(0x107C, 0x1C1), 0x1BE, 0, 0);

    sub_00502320(D2LANG_GetStringFromTblIndex(0x107D), GetCenteredX_Inl(0x107D, 0x216), 0x208, 0, 0);

    sub_00502320(D2LANG_GetStringFromTblIndex(0xF93), GetCenteredX_Inl(0xF93, 0x23C), 0x177, 0, 0);

    sub_00502320(D2LANG_GetStringFromTblIndex(0x1073), GetCenteredX_Inl(0x1073, 0x2A2), 0x19A, 0, 0);

    sub_00502320(D2LANG_GetStringFromTblIndex(0x1071), GetCenteredX_Inl(0x1071, 0x2A2), 0x1A9, 0, 0);

    sub_00502320(D2LANG_GetStringFromTblIndex(0x1072), GetCenteredX_Inl(0x1072, 0x2A2), 0x1B8, 0, 0);

    sub_00502320(D2LANG_GetStringFromTblIndex(0x107E), GetCenteredX_Inl(0x107E, 0x2E8), 0x1E1, 0, 0);

    sub_00502EF0(nOldFont);
}

// 0x004966C0
void __cdecl sub_004966C0_DrawHelpScreen()
{
    if (!sub_004538D0(0x15))
    {
        sub_00455F20(0x15, 0, 0);
        gbHelpUiOpened_007BEF00 = 1;
    }
    if (D2GFX_GetResolutionMode() == 2)
    {
        sub_004944F0_DrawFrameCels();
        sub_00494E40_DrawPanelCel();
        sub_00494620_DrawColumn();
        sub_00494A00_DrawCelsAndLines();
        sub_00495410_DrawHelpText();
    }
    else
    {
        sub_004943B0_DrawFrameCels();
        sub_00494E40_DrawPanelCel();
        sub_00494620_DrawColumn();
        sub_00494680_DrawCelsAndLines();
        sub_00495DC0_DrawHelpText();
    }
}
