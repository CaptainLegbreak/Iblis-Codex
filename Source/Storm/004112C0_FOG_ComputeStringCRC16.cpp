extern "C" int __cdecl tolower(int nChar);                                                                  // 0x0068523E
extern unsigned short gwStringCrcTable_00708140[256]; // 0x00708140

// 0x004112C0
unsigned short __stdcall FOG_ComputeStringCRC16(const char* szString)
{
    unsigned short wCrc = 0xFFFF;
    char c;
    while ((c = (char)tolower((unsigned char)*szString++)) != 0)
    {
        wCrc = (wCrc >> 2) ^ gwStringCrcTable_00708140[(c ^ wCrc) & 0xFF];
    }
    return wCrc;
}

#include "gen/data/Source/Storm/004112C0_FOG_ComputeStringCRC16.inc"
