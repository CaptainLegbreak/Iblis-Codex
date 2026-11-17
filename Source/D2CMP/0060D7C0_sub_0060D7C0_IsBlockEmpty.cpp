struct D2CmpRGBStrc
{
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
};

typedef void (__stdcall* D2CmpColorCallback)(unsigned int nColor);

struct D2CmpPaletteStrc
{
    char unk0x00[0x10];
    D2CmpRGBStrc* pColors;
};

// 0x0060D7C0
int __fastcall sub_0060D7C0_IsBlockEmpty(const unsigned char* pData)
{
    for (int i = 0; i < 0x200; ++i, ++pData)
    {
        if (*pData)
            return 0;
    }
    return 1;
}

// 0x0060DC30
void __fastcall sub_0060DC30_ForEachPaletteColor(D2CmpPaletteStrc* pPalette, D2CmpColorCallback pfnColor)
{
    D2CmpRGBStrc* pColor = pPalette->pColors;
    for (int i = 0; i < 0x400; i++)
    {
        pfnColor(((pColor->b2 << 8) + pColor->b1 << 8) + pColor->b0);
        pColor++;
    }
}
