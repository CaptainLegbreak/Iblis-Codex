typedef unsigned int size_t;
typedef char* va_list;
struct _iobuf;
struct tm
{
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
};

extern "C" __int64 __cdecl _time64(__int64* pTime);                                                         // 0x0068568B
extern "C" int __cdecl _localtime64_s(tm* pTm, const __int64* pTime);                                       // 0x006856E9
extern "C" int __cdecl _vsnprintf(char* szDest, size_t nCount, const char* szFormat, va_list args);         // 0x00682F22
extern "C" char* __cdecl strrchr(const char* szString, int nChar);                                          // 0x00682990
extern "C" size_t __cdecl strlen(const char* szString);
extern "C" __declspec(dllimport) unsigned long __stdcall GetTempPathW(unsigned long nBufferLength, wchar_t* wszBuffer); // 0x006CC2BC
extern "C" __declspec(dllimport) int __stdcall WideCharToMultiByte(unsigned int nCodePage, unsigned long dwFlags, const wchar_t* wszSource, int nSource, char* szDest, int nDest, const char* szDefaultChar, int* pbUsedDefaultChar); // 0x006CC194
bool __stdcall sub_004045F0_UseUtf8Path(const char* szPath);                                                // 0x004045F0
_iobuf* __stdcall sub_004043C0_OpenUtf8FileForWrite(const char* szPath);                                    // 0x004043C0
char gszLogDirectory_00992708[0x400];                                                                       // 0x00992708

namespace crashy
{
class Report
{
public:
    Report();                                                               // 0x00401070
    virtual ~Report();                                                      // 0x004010D0
    bool sub_00401100_Open(const char* szFileName);                         // 0x00401100

    _iobuf* m_pFile;
    char m_szText08[0x400];
    char m_szText408[0x400];
};
}

// 0x00404110
static __declspec(noinline) size_t sub_00404110_StrLCopy(char* szDest, const char* szSource, size_t nSize)
{
    const char* p = szSource;
    if (nSize)
    {
        size_t n = nSize - 1;
        if (n)
        {
            do
            {
                const char c = *p;
                *szDest = c;
                szDest++;
                p++;
                if (!c)
                {
                    break;
                }
            } while (--n);
        }
        if (!n)
        {
            *szDest = 0;
        }
        else
        {
            return p - szSource - 1;
        }
    }
    while (*p++)
    {
    }
    return p - szSource - 1;
}

// 0x004040B0
static bool sub_004040B0_SetErrorDirectory(char* szPath)
{
    char* pEnd = szPath + strlen(szPath);
    if (pEnd == szPath + 0x400)
    {
        return false;
    }
    if (pEnd != szPath && pEnd[-1] != '/' && pEnd[-1] != '\\')
    {
        *pEnd = '\\';
    }
    return sub_00404110_StrLCopy(szPath, "BlizzardError", 0x400) < 0x400;
}

// 0x004041F0
static int sub_004041F0_FormatText(char* szDest, size_t nSize, const char* szFormat, ...)
{
    const int nResult = _vsnprintf(szDest, nSize - 1, szFormat, (va_list)(&szFormat + 1));
    szDest[nSize - 1] = 0;
    return nResult;
}

// 0x004044F0
static bool sub_004044F0_GetTempPathUtf8(char* szOut)
{
    wchar_t wszPath[0x104];
    const unsigned long nLength = GetTempPathW(0x104, wszPath);
    if (!nLength)
    {
        return false;
    }
    return WideCharToMultiByte(0xFDE9, 0, wszPath, nLength + 1, szOut, 0x400, 0, 0) != 0;
}

// 0x00403FA0
static bool __stdcall sub_00403FA0_CopyPathIfHasDirectory(const char* szPath, char* szOut, size_t nSize)
{
    const char* pSep = 0;
    const char* p = strrchr(szPath, '/');
    if (p > pSep)
    {
        pSep = p;
    }
    p = strrchr(szPath, '\\');
    if (p && p > pSep)
    {
        pSep = p;
    }
    p = strrchr(szPath, ':');
    if (p && p > pSep)
    {
        pSep = p;
    }
    if (!pSep)
    {
        *szOut = 0;
    }
    else if (sub_00404110_StrLCopy(szOut, szPath, nSize) >= nSize)
    {
        return false;
    }
    return true;
}

bool __stdcall sub_K01_Emit_00403FA0(const char* szPath, char* szOut, size_t nSize)
{
    return sub_00403FA0_CopyPathIfHasDirectory(szPath, szOut, nSize);
}

// 0x00401100
bool crashy::Report::sub_00401100_Open(const char* szFileName)
{
    __int64 nTime = _time64(0);
    tm tTime;
    _localtime64_s(&tTime, &nTime);
    if (!gszLogDirectory_00992708[0])
    {
        if (!sub_004044F0_GetTempPathUtf8(gszLogDirectory_00992708))
        {
            return false;
        }
        if (!sub_004040B0_SetErrorDirectory(gszLogDirectory_00992708))
        {
            return false;
        }
    }
    if ((size_t)(sub_004041F0_FormatText(m_szText408, 0x400, "%s/%04d-%02d-%02d %02d.%02d.%02d", gszLogDirectory_00992708, tTime.tm_year + 0x76C, tTime.tm_mon + 1, tTime.tm_mday, tTime.tm_hour, tTime.tm_min, tTime.tm_sec) + 1) > 0x400)
    {
        return false;
    }
    if (!sub_004045F0_UseUtf8Path(m_szText408))
    {
        return false;
    }
    if ((size_t)(sub_004041F0_FormatText(m_szText08, 0x400, "%s/%s", m_szText408, szFileName) + 1) > 0x400)
    {
        return false;
    }
    m_pFile = sub_004043C0_OpenUtf8FileForWrite(m_szText08);
    return m_pFile != 0;
}
