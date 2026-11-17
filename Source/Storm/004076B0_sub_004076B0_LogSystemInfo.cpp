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
extern "C" __declspec(dllimport) int __stdcall GetComputerNameA(char* szBuffer, unsigned long* pnSize);     // 0x006CC1D8
extern "C" void* __cdecl memcpy(void* pDest, const void* pSource, size_t nSize);                            // 0x006829C0

int __fastcall sub_0040C220_GetAppPath(char* szPath, unsigned int nSize);                                   // 0x0040C220
const char* __cdecl sub_0040DF60_GetLocalIp();                                                              // 0x0040DF60
void __stdcall sub_0040EA00_WriteProcessorReport();                                                                   // 0x0040EA00
void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...);                                                           // 0x00410610

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern int gnOsKind_0074D890;                                                                               // 0x0074D890
extern float gfOsVersion_0074D894;                                                                          // 0x0074D894
unsigned long gdwTotalPhys_0074D898;                                                                        // 0x0074D898

// 0x004076B0
void __cdecl sub_004076B0_LogSystemInfo()
{
    D2SystemTimeStrc tTime;
    unsigned long nSize;
    char szPath[0x1000];
    char szOs[0x1000];
    char szComputer[0x40];

    sub_00410610_WriteLogLine("------------------------------------------------------");
    GetLocalTime(&tTime);
    sub_00410610_WriteLogLine("%04d-%02d-%02d %02d:%02d:%02d", tTime.wYear, tTime.wMonth, tTime.wDay, tTime.wHour, tTime.wMinute, tTime.wSecond);

    switch (gnOsKind_0074D890)
    {
    case 1:
        memcpy(szOs, "Windows NT", sizeof("Windows NT"));
        break;
    case 2:
        memcpy(szOs, "Windows 2000", sizeof("Windows 2000"));
        break;
    case 3:
        memcpy(szOs, "Windows XP", sizeof("Windows XP"));
        break;
    case 4:
        memcpy(szOs, "Windows .Net", sizeof("Windows .Net"));
        break;
    case 9:
        memcpy(szOs, "MacOS", sizeof("MacOS"));
        break;
    case 10:
        memcpy(szOs, "MacOS X", sizeof("MacOS X"));
        break;
    default:
        memcpy(szOs, "unknown", sizeof("unknown"));
        break;
    }

    sub_00410610_WriteLogLine("%s running under %s (Version %.3f)", "Diablo II", szOs, gfOsVersion_0074D894);
    sub_0040EA00_WriteProcessorReport();
    sub_00410610_WriteLogLine("Total Physical Memory: %.2fMB", (float)gdwTotalPhys_0074D898 / 1048576.0);

    if (sub_0040C220_GetAppPath(szPath, sizeof(szPath)))
    {
        sub_00410610_WriteLogLine("Application Path: %s", szPath);
    }

    sub_00410610_WriteLogLine("Local IP: %s", sub_0040DF60_GetLocalIp());

    nSize = sizeof(szComputer);
    if (!GetComputerNameA(szComputer, &nSize))
    {
        szComputer[0] = 0;
    }

    sub_00410610_WriteLogLine("Computer name: %s", szComputer);
    sub_00410610_WriteLogLine("------------------------------------------------------");
    sub_00410610_WriteLogLine(&gszEmptyAssertText);
}
