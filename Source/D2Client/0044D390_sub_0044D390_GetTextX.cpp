struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}
};

int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
int gdwGlobal_007A04F4;                                                                                     // 0x007A04F4

// 0x0044D390
int __fastcall sub_0044D390_GetTextX(unsigned short nStringIndex, int nCenterX)
{
    Unicode wszText[100];
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(nStringIndex));
    return nCenterX - sub_00501820(wszText) / 2;
}

// 0x0044D3E0
void __cdecl sub_0044D3E0_DrawOverlayA()
{
    int nX = sub_0044D390_GetTextX(0x13EA, gnGlobal_0071146C / 2);
    int nY = 0x3E;
    if (gdwGlobal_007A04F4)
        nY = 0x64;
    sub_00502320(D2LANG_GetStringFromTblIndex(0x13EA), nX, nY, 4, 0);
    if (!gdwGlobal_007A04F4)
    {
        nX = sub_0044D390_GetTextX(0x13EB, gnGlobal_0071146C / 2);
        sub_00502320(D2LANG_GetStringFromTblIndex(0x13EB), nX, 0x6B, 4, 0);
    }
    nY = 0xE8;
    if (gdwGlobal_007A04F4)
        nY = 0x110;
    sub_00502320(D2LANG_GetStringFromTblIndex(0x13EC), sub_0044D390_GetTextX(0x13EC, gnGlobal_0071146C / 2), nY, 4, 0);
}
