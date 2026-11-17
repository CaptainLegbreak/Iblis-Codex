struct D2Object006B9730Strc
{
    unsigned char unk_00[0x10];
    unsigned int dwColor10;
};
extern unsigned char gaPaletteRows_00971740[][256]; // 0x00971740

// 0x006B9780
void __fastcall sub_006B9780_SetColor(D2Object006B9730Strc* pObject, unsigned int nPacked, unsigned char nAlpha)
{
    const unsigned char* pRow = gaPaletteRows_00971740[(unsigned char)nPacked];
    pObject->dwColor10 = ((((unsigned int)nAlpha << 8 | pRow[(unsigned char)(nPacked >> 8)]) << 8 | pRow[(unsigned char)(nPacked >> 16)]) << 8) | pRow[nPacked >> 24];
}
