typedef unsigned int size_t;

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

extern "C" __declspec(dllimport) void __stdcall GetLocalTime(D2SystemTimeStrc* pSystemTime);                // 0x006CC1D4
int __cdecl SStrPrintf(char* szDest, size_t nSize, const char* szFormat, ...);                              // 0x00413A40

// 0x00624740
void __stdcall sub_00624740_FormatLocalTime(char* szBuffer, size_t nSize)
{
    D2SystemTimeStrc tTime;
    GetLocalTime(&tTime);
    SStrPrintf(szBuffer, nSize, "%02u:%02u:%02u.%03u\t", tTime.wHour, tTime.wMinute, tTime.wSecond, tTime.wMilliseconds);
}
