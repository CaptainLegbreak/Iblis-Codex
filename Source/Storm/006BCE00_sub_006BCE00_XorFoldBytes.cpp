// 0x006BCE00
unsigned int __fastcall sub_006BCE00_XorFoldBytes(int nUnused, unsigned int dwValue)
{
    return (dwValue ^ (dwValue >> 8) ^ (dwValue >> 16) ^ (dwValue >> 24)) & 0xFF;
}
