typedef unsigned int size_t;
typedef char* va_list;

struct _SYSTEMTIME
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

extern "C" __declspec(dllimport) void __stdcall GetLocalTime(_SYSTEMTIME* lpSystemTime);                    // 0x006CC1D4
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText);                     // 0x006CC200
extern "C" __declspec(dllimport) short __stdcall GetKeyState(int nVirtKey);                                 // 0x006CC45C
extern "C" int __cdecl _snprintf(char* szDest, size_t nCount, const char* szFormat, ...);                  // 0x006831DB
extern "C" int __cdecl _vsnprintf(char* szDest, size_t nCount, const char* szFormat, va_list args);         // 0x00682F22
extern "C" size_t __cdecl strlen(const char* szString);
void __cdecl sub_00410740_LogWritePrefixed00(const char* szPrefix, const char* szFormat, ...);              // 0x00410740
extern "C" const char gszPercentS_006FFC58[];                                                               // 0x006FFC58

// 0x004080B0
static __declspec(noinline) void __stdcall sub_004080B0_DebugPrintV(unsigned int nFlags, const char* szFormat, va_list args)
{
    char szBuffer[0x1000];
    szBuffer[0] = 0;
    if (nFlags & 4)
    {
        _SYSTEMTIME tTime;
        GetLocalTime(&tTime);
        _snprintf(szBuffer, 0x1000, "%02d:%02d:%02d.%03d    ", tTime.wHour, tTime.wMinute, tTime.wSecond, tTime.wMilliseconds);
    }
    const size_t nLength = strlen(szBuffer);
    _vsnprintf(&szBuffer[nLength], 0x1000 - nLength, szFormat, args);
    szBuffer[0xFFF] = 0;
    if (!(nFlags & 2))
    {
        OutputDebugStringA(szBuffer);
    }
    if (nFlags & 1)
    {
        sub_00410740_LogWritePrefixed00("LOG", gszPercentS_006FFC58, szBuffer);
    }
    if (nFlags & 0x18)
    {
        GetKeyState(0x14);
    }
}

// 0x004082A0
void __cdecl sub_004082A0_DebugPrintf(unsigned int nFlags, const char* szFormat, ...)
{
    sub_004080B0_DebugPrintV(nFlags, szFormat, (va_list)(&szFormat + 1));
}

// 0x004082C0
void __cdecl sub_004082C0_DebugPrintfLog(const char* szFormat, ...)
{
    sub_004080B0_DebugPrintV(1, szFormat, (va_list)(&szFormat + 1));
}
