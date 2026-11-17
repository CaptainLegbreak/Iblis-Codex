struct D2Object006B9730Strc
{
    unsigned char unk_00[0x10];
    unsigned int dwColor10;
};
extern unsigned char gnOffsetR_0097173A; // 0x0097173A
extern unsigned char gnOffsetG_00971738; // 0x00971738
extern unsigned char gnOffsetB_00971739; // 0x00971739
extern unsigned char gaPaletteRows_00971740[][256]; // 0x00971740

// 0x006B9730
void __fastcall sub_006B9730_SetColor(D2Object006B9730Strc* pObject, unsigned char nIndex, unsigned char nAlpha)
{
    const unsigned char* pRow = gaPaletteRows_00971740[nIndex];
    pObject->dwColor10 = ((((unsigned int)nAlpha << 8 | pRow[gnOffsetR_0097173A]) << 8 | pRow[gnOffsetG_00971738]) << 8) | pRow[gnOffsetB_00971739];
}
