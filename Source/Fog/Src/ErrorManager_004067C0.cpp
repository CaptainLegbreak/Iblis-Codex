#include "Fog.h"
#include "D2Primitives.h"

struct D2FileTimeStrc;
struct D2FindDataStrc;
struct D2Storm408ElemStrc;
struct D2StormArray408Strc;

int __stdcall SFileSetBasePath(const char* szPath); // 0x004164B0
extern int gdwGlobal_008F03C8; // 0x008F03C8
int __stdcall sub_00419980(const char* szFileName, void** phFile); // 0x00419980
int __stdcall sub_0041AAD0_StormReadFile(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped, int nArg6, int nArg7); // 0x0041AAD0
int __stdcall sub_00416370_StormGetFileSize(void* hFile, unsigned int* pnSizeHigh); // 0x00416370


struct D2FindDataStrc
{
    unsigned long dwFileAttributes;
    D2FileTimeStrc ftCreationTime;
    D2FileTimeStrc ftLastAccessTime;
    D2FileTimeStrc ftLastWriteTime;
    unsigned long nFileSizeHigh;
    unsigned long nFileSizeLow;
    unsigned long dwReserved0;
    unsigned long dwReserved1;
    char cFileName[260];
    char cAlternateFileName[14];
};

extern "C" int __cdecl strcmp(const char* sz1, const char* sz2);
extern "C" __declspec(dllimport) long __stdcall SHGetFolderPathA(void* hWnd, int nFolder, void* hToken, unsigned long dwFlags, char* szPath); // 0x006CC43C
extern "C" __declspec(dllimport) int __stdcall MoveFileA(const char* szExisting, const char* szNew); // 0x006CC1D0
extern "C" __declspec(dllimport) void* __stdcall FindFirstFileA(const char* szFileName, D2FindDataStrc* pFindData); // 0x006CC1CC
extern "C" __declspec(dllimport) int __stdcall FindNextFileA(void* hFindFile, D2FindDataStrc* pFindData); // 0x006CC1C8
extern "C" __declspec(dllimport) int __stdcall RemoveDirectoryA(const char* szPathName); // 0x006CC1C0
extern "C" __declspec(dllimport) int __stdcall DeleteFileA(const char* lpFileName); // 0x006CC1A0
extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...); // 0x00413A40
unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
unsigned int __stdcall sub_00413800(char* szDest, const char* szSource, unsigned int nDestSize); // 0x00413800
int __fastcall sub_00407370_JulianDay(int nYear, int nMonth, int nDay); // 0x00407370
void __fastcall sub_00407440_JulianToDate(long nJulian, int* pYear, int* pMonth, int* pDay); // 0x00407440
int __fastcall sub_0040C220_GetAppPath(char* szPath, unsigned int nSize); // 0x0040C220
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);
extern "C" const char gszTypeNewsTableItem_0072FF8C[];
extern "C" void* __cdecl memcpy(void* pDest, const void* pSource, size_t nSize); // 0x006829C0
const char* __fastcall FOG_GetHostIPAddress(); // 0x0040DF60
void __stdcall sub_0040EA00_WriteProcessorReport(); // 0x0040EA00
void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...); // 0x00410610
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern int gnOsKind_0074D890; // 0x0074D890
extern float gfOsVersion_0074D894; // 0x0074D894
void __cdecl sub_004106B0_LogWritePrefixed0(const char* szPrefix, const char* szFormat, ...); // 0x004106B0
void __cdecl sub_00410740_LogWritePrefixed00(const char* szPrefix, const char* szFormat, ...); // 0x00410740
extern "C" const char gszPercentS_006FFC58[]; // 0x006FFC58

// 0x004067C0
int __cdecl sub_004067C0_SetBasePathToCurrent()
{
    return SFileSetBasePath(".\\");
}

// 0x00413740
void __cdecl sub_00413740_Nop()
{
}

// 0x00608520
int __cdecl D2CMPToggleCelDrawMode()
{
    return gdwGlobal_008F03C8 = (gdwGlobal_008F03C8 == 0);
}

// 0x004068E0
int __fastcall sub_004068E0(const char* szFileName, void** phFile)
{
    return sub_00419980(szFileName, phFile);
}

// 0x00406900
int __fastcall sub_00406900(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped, int nArg7, int nArg6)
{
    return sub_0041AAD0_StormReadFile(hFile, pBuffer, nToRead, pnRead, pOverlapped, nArg6, nArg7);
}

// 0x00406930
int __fastcall sub_00406930(void* hFile, unsigned int* pnSizeHigh)
{
    return sub_00416370_StormGetFileSize(hFile, pnSizeHigh);
}

// 0x00406940
int __fastcall sub_00406940_mpqSetFilePointer(void* hFile, long nOffset, long* pnOffsetHigh, int nMethod)
{
    return SFileSetFilePointer(hFile, nOffset, pnOffsetHigh, nMethod);
}

static int __fastcall FOG_AppendBackslash(char* szPath, int nSize)
{
    if (!szPath || !nSize)
        return 0;
    unsigned int nLen = SStrLen(szPath);
    if (nLen <= 0 || szPath[nLen - 1] != '\\')
    {
        if (nLen + 1 == nSize)
            return 0;
        szPath[nLen] = '\\';
        szPath[nLen + 1] = 0;
    }
    return 1;
}

// 0x00406C40
int __fastcall sub_00406C40_GetBlizzardDataPath(char* szOutPath, int nSize)
{
    char szPath[0x104];
    if (SHGetFolderPathA(0, 0x1C, 0, 0, szPath) < 0)
        return 0;
    sub_00413800(szPath, "\\Blizzard Entertainment", 0x7FFFFFFF);
    if (!FOG_AppendBackslash(szPath, nSize))
        return 0;
    if (!sub_00406A10_CreateDirectoryTree(szPath))
        return 0;
    SStrCopy(szOutPath, szPath, nSize);
    return SStrLen(szOutPath) == SStrLen(szPath);
}

// 0x00406DE0
int __fastcall sub_00406DE0_MoveDirectoryTree(const char* szSrc, const char* szDst)
{
    char szDir[0x104];
    SStrCopy(szDir, szDst, 0x7FFFFFFF);
    char* pCut = strrchr(szDir, '\\') + 1;
    char cSaved = *pCut;
    *pCut = 0;
    sub_00406A10_CreateDirectoryTree(szDir);
    *pCut = cSaved;
    if (MoveFileA(szSrc, szDst))
        return 2;
    unsigned long dwAttr = GetFileAttributesA(szSrc);
    if (dwAttr == (unsigned long)-1)
        return GetLastError() == 2 ? 2 : 1;
    if (!(dwAttr & 0x10))
        return 1;
    dwAttr = GetFileAttributesA(szDst);
    if (!(dwAttr & 0x10))
        return 1;
    if (dwAttr == (unsigned long)-1)
    {
        if (GetLastError() != 2)
            return 1;
        FOG_AppendBackslash(szDir, sizeof(szDir));
        sub_00406A10_CreateDirectoryTree(szDir);
    }
    char szSrcFind[0x104];
    char szDstFind[0x104];
    int nResult = 0;
    int nSrcLen = SStrPrintf(szSrcFind, 0x104, "%s\\*", szSrc) - 1;
    int nDstLen = SStrPrintf(szDstFind, 0x104, "%s\\", szDst);
    D2FindDataStrc tData;
    void* hFind = FindFirstFileA(szSrcFind, &tData);
    if (hFind != (void*)-1)
    {
        do
        {
            if (strcmp(tData.cFileName, ".") && strcmp(tData.cFileName, ".."))
            {
                SStrCopy(szSrcFind + nSrcLen, tData.cFileName, 0x104 - nSrcLen);
                SStrCopy(szDstFind + nDstLen, tData.cFileName, 0x104 - nDstLen);
                nResult |= sub_00406DE0_MoveDirectoryTree(szSrcFind, szDstFind);
            }
        } while (FindNextFileA(hFind, &tData));
    }
    FindClose(hFind);
    RemoveDirectoryA(szSrc);
    return nResult;
}

// 0x00407570
void __fastcall sub_00407570_DeleteOldDatedLogs(const char* szPrefix)
{
    D2SystemTimeStrc tTime;
    char szDir[0x1000];
    char szFile[0x1000];
    GetLocalTime(&tTime);
    szDir[0] = 0;
    if (sub_0040C220_GetAppPath(szDir, 0x1000))
    {
        sub_00413800(szDir, "\\", 0x1000);
        sub_00406A10_CreateDirectoryTree(szDir);
    }
    int nYear = tTime.wYear;
    int nMonth = tTime.wMonth;
    int nDay = tTime.wDay;
    int nJulianDay = sub_00407370_JulianDay(nYear, nMonth, nDay) - 5;
    for (int i = 0; i < 10; i++)
    {
        sub_00407440_JulianToDate(nJulianDay, &nYear, &nMonth, &nDay);
        SStrPrintf(szFile, 0x1000, "%s%s%02d%02d%02d.txt", szDir, szPrefix, nYear % 100, nMonth, nDay);
        DeleteFileA(szFile);
        nJulianDay--;
    }
}

inline unsigned int RoundUpInline(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

inline void D2StormArray408Strc::ReserveInline(unsigned int nCount, int bRound)
{
    nCount += f_4;
    if (nCount > f_0)
    {
        if (bRound)
        {
            unsigned int nChunk = f_C ? f_C : sub_0051D2F0_CalcChunkSize(nCount);
            nCount = RoundUpInline(nCount, nChunk);
        }
        sub_0051D5D0_ReallocData(nCount);
    }
}

D2StormArray408Strc* D2StormArray408Strc::sub_0051D2C0_InitBase()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
    return this;
}

void __cdecl sub_0051D2D0_Nop()
{
}

void __cdecl sub_0051D2E0_Nop()
{
}

void __fastcall sub_0051D350_CopyElement(D2Storm408ElemStrc* pDst, const D2Storm408ElemStrc* pSrc)
{
    if (pDst)
        *pDst = *pSrc;
}

void D2StormArray408Strc::sub_0051D570_FreeData()
{
    if (f_8)
        SMemFree(f_8, gszTypeNewsTableItem_0072FF8C, -2, 0);
}

void D2StormArray408Strc::sub_0051D670_FreeData()
{
    if (f_8)
        SMemFree(f_8, gszTypeNewsTableItem_0072FF8C, -2, 0);
}

// 0x00407260
D2StormArray408Strc* D2StormArray408Strc::sub_0051D690_Init()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
    f_C = 0;
    return this;
}

void D2StormArray408Strc::sub_0051D6A0_Clear()
{
    if (f_8)
        SMemFree(f_8, gszTypeNewsTableItem_0072FF8C, -2, 0);
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
}

D2StormArray408Strc* D2StormArray408Strc::sub_0051D720_Init()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
    f_C = 0;
    return this;
}

void D2StormArray408Strc::sub_0051D730_FreeData()
{
    if (f_8)
        SMemFree(f_8, gszTypeNewsTableItem_0072FF8C, -2, 0);
}

D2Storm408ElemStrc* D2StormArray408Strc::sub_0051D7A0_New()
{
    ReserveInline(1, 1);
    return &f_8[f_4++];
}

unsigned long gdwTotalPhys_0074D898; // 0x0074D898

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

    sub_00410610_WriteLogLine("Local IP: %s", FOG_GetHostIPAddress());

    nSize = sizeof(szComputer);
    if (!GetComputerNameA(szComputer, &nSize))
    {
        szComputer[0] = 0;
    }

    sub_00410610_WriteLogLine("Computer name: %s", szComputer);
    sub_00410610_WriteLogLine("------------------------------------------------------");
    sub_00410610_WriteLogLine(&gszEmptyAssertText);
}

// 0x00407F80
void __fastcall sub_00407F80_ThreadHookNop2(unsigned int nId, void* hThread)
{
}

// 0x00407F90
void __fastcall sub_00407F90_ThreadHookNop1(unsigned int nId)
{
}

// 0x00407FC0
static void __stdcall sub_00407FC0_LogPrefixedText(const char* szPrefix, const char* szText, int bFlag)
{
    if (bFlag)
    {
        sub_004106B0_LogWritePrefixed0(szPrefix, gszPercentS_006FFC58, szText);
    }
    else
    {
        sub_00410740_LogWritePrefixed00(szPrefix, gszPercentS_006FFC58, szText);
    }
}

void __stdcall sub_K01_Emit_00407FC0(const char* szPrefix, const char* szText, int bFlag)
{
    sub_00407FC0_LogPrefixedText(szPrefix, szText, bFlag);
}
