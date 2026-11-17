// 0x006BBFA0
void __stdcall sub_006BBFA0_EncodeBase255(unsigned char* pOut, unsigned int nValue)
{
    pOut[0] = (unsigned char)(nValue % 255 + 1);
    pOut[1] = (unsigned char)(nValue / 255 % 255 + 1);
    pOut[2] = (unsigned char)(nValue / (255 * 255) % 255 + 1);
    pOut[3] = (unsigned char)(nValue / (255 * 255 * 255) % 255 + 1);
}
