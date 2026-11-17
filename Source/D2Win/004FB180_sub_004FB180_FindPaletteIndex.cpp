extern const unsigned char gRGBAPalette_0081E668[];                                                         // 0x0081E668
unsigned char __stdcall sub_00605210_FindNearestColor(const unsigned char* pPalette, unsigned int nCount, int nC0, int nC1, int nC2); // 0x00605210

// 0x004FB180
unsigned char __stdcall sub_004FB180_FindPaletteIndex(unsigned char nRed, unsigned char nGreen, unsigned char nBlue)
{
    return sub_00605210_FindNearestColor(gRGBAPalette_0081E668, 0x100, nRed, nGreen, nBlue);
}
