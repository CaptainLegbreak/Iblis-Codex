struct T004F51E0
{
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    unsigned char nFlags;
};

unsigned short gwColors16_0096FA80[256];                                                                    // 0x0096FA80
unsigned int gdwColors_009702C0[256];                                                                       // 0x009702C0

// 0x006B1C70
void __fastcall sub_006B1C70_SetPalette(T004F51E0* pPalette)
{
    for (int i = 0; i < 256; ++i)
    {
        gdwColors_009702C0[i] = 0xFF000000 | (pPalette[i].nRed << 16) | (pPalette[i].nGreen << 8) | pPalette[i].nBlue;

        int nRed = pPalette[i].nRed >> 3;
        int nBlue = pPalette[i].nBlue >> 3;
        int nGreen = pPalette[i].nGreen >> 3;
        if (nRed < 31 && (pPalette[i].nRed & 7) >= 4)
            ++nRed;
        if (nBlue < 31 && (pPalette[i].nBlue & 7) >= 4)
            ++nBlue;
        if (nGreen < 31 && (pPalette[i].nGreen & 7) >= 4)
            ++nGreen;
        gwColors16_0096FA80[i] = (unsigned short)(0x8000 | (nRed << 10) | (nGreen << 5) | nBlue);

        if (!pPalette[i].nRed && !pPalette[i].nGreen && !pPalette[i].nBlue)
        {
            gdwColors_009702C0[i] = 0;
            gwColors16_0096FA80[i] = 0;
        }
    }
}
