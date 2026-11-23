extern const unsigned char gatRGBAPalette[];                                                         // 0x0081E668
unsigned char __stdcall GetClosestColor(const unsigned char* pPalette, unsigned int nCount, int nC0, int nC1, int nC2); // 0x00605210

// 0x004FB180
unsigned char __stdcall sub_004FB180_FindPaletteIndex(unsigned char nRed, unsigned char nGreen, unsigned char nBlue)
{
    return GetClosestColor(gatRGBAPalette, 0x100, nRed, nGreen, nBlue);
}
