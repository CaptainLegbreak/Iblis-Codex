struct Unicode
{
    unsigned short wChar;
};

int __fastcall sub_0042F2E0_ReadPaletteFiles(const char* szFile1, const char* szFile2);                          // 0x0042F2E0
void __cdecl sub_0042F3F0_DestroyControls();                                                                // 0x0042F3F0

int gbPaletteBusy_00779970;                                                                                 // 0x00779970
extern "C" const char gszPalFeCharDat_006D39E8[];                                                           // 0x006D39E8

// 0x0042F370
void __cdecl sub_0042F370_RestorePalette()
{
    if (gbPaletteBusy_00779970)
    {
        sub_0042F2E0_ReadPaletteFiles(gszPalFeCharDat_006D39E8, "palette\\fechar\\pal.pl2");
        gbPaletteBusy_00779970 = 0;
    }
}

// 0x0042F530
void __fastcall sub_0042F530_ClearUnicode(Unicode* pChar)
{
    pChar->wChar = 0;
}

// 0x0042F880
void __cdecl sub_0042F880_DestroyControls()
{
    sub_0042F3F0_DestroyControls();
}
