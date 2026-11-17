extern "C" const char gszEmptyAssertText_006CC837; // 0x006CC837
extern "C" const unsigned int sgCrc32LookupTable[256]; // 0x006FD3E8
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

// 0x006C99F6
unsigned int __fastcall CRC32_Compute(void* pData, unsigned int dwSize)
{
    if (!dwSize)
    {
        sub_00408A60(&gszEmptyAssertText_006CC837, sub_00408090(), 0x40);
        exit(-1);
    }

    unsigned int nCRC32 = 0xFFFFFFFFu;
    const unsigned char* pByte = (const unsigned char*)pData;
    while (dwSize)
    {
        nCRC32 = sgCrc32LookupTable[*pByte ^ (unsigned char)nCRC32] ^ (nCRC32 >> 8);
        --dwSize;
        ++pByte;
    }
    return ~nCRC32;
}

#include "gen/data/Source/Storm/006C99F6_CRC32_Compute.inc"
