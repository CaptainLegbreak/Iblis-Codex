extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct _iobuf;

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

struct D2FileTimeStrc
{
    unsigned long dwLowDateTime;
    unsigned long dwHighDateTime;
};

struct D2LogMessageStrc
{
    void* pLinkPrev;
    char* pLinkNext;
    unsigned int nSize;
    int nType;
    int bTimeStamp;
    D2SystemTimeStrc f_14;
    char szName[1];
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" int __cdecl sscanf(const char* szSource, const char* szFormat, ...);                             // 0x00684BD5
extern "C" __declspec(dllimport) long __stdcall SHGetFolderPathA(void* hWnd, int nFolder, void* hToken, unsigned long dwFlags, char* szPath); // 0x006CC43C
extern "C" __declspec(dllimport) int __stdcall SystemTimeToFileTime(const D2SystemTimeStrc* pSystemTime, D2FileTimeStrc* pFileTime); // 0x006CC26C
extern "C" __declspec(dllimport) int __stdcall DeleteFileA(const char* lpFileName);                         // 0x006CC1A0
unsigned int __stdcall SStrLen(const char* szString);                                                       // 0x00413750
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
unsigned int __stdcall sub_00413800(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x00413800
int __fastcall sub_00406A10_CreateDirectoryTree(const char* szPath);                                        // 0x00406A10
int __fastcall sub_00406B20_AppendBackslash(char* szPath, int nSize);                                       // 0x00406B20
extern "C" int __cdecl fprintf(_iobuf* pFile, const char* szFormat, ...);                                   // 0x00684C94
extern "C" unsigned int __cdecl fwrite(const void* pBuffer, unsigned int nSize, unsigned int nCount, _iobuf* pFile); // 0x00684449
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                                // 0x006CC260
_iobuf* __fastcall sub_0040EDE0_GetLogFile(const char* szName, int* pnSlot);                                // 0x0040EDE0
extern unsigned long gadwLogWriteTick_0075D2F0[20];                                                         // 0x0075D2F0

// 0x0040F000
void __fastcall sub_0040F000_GetLogDirectory(char* szDirectory, int nSize)
{
    char szPath[0x104];
    *szDirectory = 0;
    if (SHGetFolderPathA(0, 5, 0, 0, szPath) >= 0)
    {
        SStrCopy(szDirectory, szPath, nSize);
        sub_00406B20_AppendBackslash(szDirectory, nSize);
        sub_00413800(szDirectory, "Diablo II\\GameLogs\\", nSize);
        sub_00406A10_CreateDirectoryTree(szDirectory);
    }
}

// 0x0040F3D0
void __fastcall sub_0040F3D0_SweepLogFile(const D2FileTimeStrc* pNow, const char* szFile)
{
    int nOffset = SStrLen(szFile) - 10;
    if (nOffset > 0)
    {
        int nYear, nMonth, nDay;
        sscanf(szFile + nOffset, "%2d%2d%2d", &nYear, &nMonth, &nDay);
        D2SystemTimeStrc tTime;
        memset(&tTime, 0, sizeof(tTime));
        tTime.wYear = nYear > 90 ? nYear + 1900 : nYear + 2000;
        tTime.wMonth = nMonth;
        tTime.wDay = nDay;
        D2FileTimeStrc tFileTime;
        SystemTimeToFileTime(&tTime, &tFileTime);
        if (pNow->dwHighDateTime >= tFileTime.dwHighDateTime && pNow->dwHighDateTime - tFileTime.dwHighDateTime >= 0x4B7)
            DeleteFileA(szFile);
    }
}

// 0x0040F720
void __fastcall sub_0040F720_WriteMessage(D2LogMessageStrc* pMessage)
{
    D2_ASSERT(pMessage->nType == 1, 0x2A1);
    char* szName = pMessage->szName;
    char* szText = szName + SStrLen(szName) + 1;
    int nSlot;
    _iobuf* pFile = sub_0040EDE0_GetLogFile(szName, &nSlot);
    if (pFile)
    {
        if (pMessage->bTimeStamp)
            fprintf(pFile, "%02d:%02d:%02d.%03d  ", pMessage->f_14.wHour, pMessage->f_14.wMinute, pMessage->f_14.wSecond, pMessage->f_14.wMilliseconds);
        fwrite(szText, SStrLen(szText), 1, pFile);
        gadwLogWriteTick_0075D2F0[nSlot] = GetTickCount();
    }
}
