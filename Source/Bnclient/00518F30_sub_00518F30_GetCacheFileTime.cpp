struct D2SystemTimeStrc
{
    unsigned short wYear;
    unsigned short wMonth;
    unsigned short wDayOfWeek;
    unsigned short wDay;
    unsigned short wHour;
    unsigned short wMinute;
    unsigned short wSecond;
    unsigned short wMilliseconds;
};

extern "C" int __cdecl toupper(int nChar);                                                                  // 0x00685385
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" __declspec(dllimport) void __stdcall GetSystemTime(D2SystemTimeStrc* pSystemTime);               // 0x006CC38C
extern "C" __declspec(dllimport) int __stdcall SystemTimeToFileTime(const D2SystemTimeStrc* pSystemTime, void* pFileTime); // 0x006CC26C

extern unsigned int* gpCacheTable_00881888;                                                            // 0x00881888
unsigned __int64 gqwCacheFileTime_008818AC;                                                                 // 0x008818AC
unsigned long gdwCacheTimeTick_008818B4;                                                                    // 0x008818B4
unsigned int gnCacheTimeSeconds_008818B8;                                                                   // 0x008818B8

// 0x00518F30
static unsigned __int64* sub_00518F30_GetCacheFileTime(unsigned int nSeconds)
{
    if (nSeconds != gnCacheTimeSeconds_008818B8 || GetTickCount() != gdwCacheTimeTick_008818B4)
    {
        D2SystemTimeStrc tSystemTime;
        GetSystemTime(&tSystemTime);
        SystemTimeToFileTime(&tSystemTime, &gqwCacheFileTime_008818AC);
        gqwCacheFileTime_008818AC += (unsigned __int64)nSeconds * 10000000;
        gnCacheTimeSeconds_008818B8 = nSeconds;
        gdwCacheTimeTick_008818B4 = GetTickCount();
    }
    return &gqwCacheFileTime_008818AC;
}

// 0x00518FA0
static unsigned int __stdcall sub_00518FA0_HashString(unsigned int nHashType, const char* szString)
{
    unsigned int dwSeed1 = 0x7FED7FED;
    unsigned int dwSeed2 = 0xEEEEEEEE;
    while (szString && *szString)
    {
        char ch = (char)toupper(*szString++);
        dwSeed1 = gpCacheTable_00881888[(nHashType << 8) + ch] ^ (dwSeed1 + dwSeed2);
        dwSeed2 = ch + dwSeed1 + dwSeed2 + (dwSeed2 << 5) + 3;
    }
    return dwSeed1;
}

unsigned int __cdecl sub_B10_Emit_00518F30()
{
    return *(unsigned int*)sub_00518F30_GetCacheFileTime(0);
}

unsigned int __cdecl sub_B10_Emit_00518FA0(const char* szName)
{
    return sub_00518FA0_HashString(0, szName) ^ sub_00518FA0_HashString(1, szName) ^ sub_00518FA0_HashString(3, szName);
}
