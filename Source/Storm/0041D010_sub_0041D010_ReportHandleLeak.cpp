extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText);                    // 0x006CC200

int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...);       // 0x00413A40
int __stdcall SErrDisplayError(unsigned int nErrorCode, const char* szFile, int nLine, const char* szDescription, int bRecoverable, unsigned int nExitCode); // 0x0041CAF0

extern "C" const char gszFormatName[];                                                                     // 0x006FFC58

int gbDebugMemoryLoaded_00779204;                                                                           // 0x00779204
unsigned long gdwDebugMemory_00779200;                                                                      // 0x00779200
extern int gnErrorOutputMode_0077909C;                                                                      // 0x0077909C

// 0x0041D010
void __stdcall sub_0041D010_ReportHandleLeak(const char* szName, const char* szDetail)
{
    if (!gbDebugMemoryLoaded_00779204)
    {
        gbDebugMemoryLoaded_00779204 = 1;
        SRegLoadValue("Internal", "Debug Memory", 0, &gdwDebugMemory_00779200);
    }
    if (!gdwDebugMemory_00779200)
        return;
    char szText[0x100];
    if (szDetail && *szDetail)
        SStrPrintf(szText, 0x100, "%s (%s)", szName, szDetail);
    else
        SStrPrintf(szText, 0x100, gszFormatName, szName);
    if (!gnErrorOutputMode_0077909C)
    {
        SErrDisplayError(0x8510007F, szText, -3, 0, 1, 1);
    }
    else
    {
        char szOutput[0xC8];
        wsprintfA(szOutput, "Storm Error : handle never released -- %s\n", szText);
        OutputDebugStringA(szOutput);
    }
}
