#include "Fog.h"
#include "D2Primitives.h"
#include "D2GameTypes.h"
#include "D2NetTypes.h"
#include "D2FogTypes.h"

struct FSafeSock
{
    int bConnected;
    int bConnecting;
    unsigned int nSocket;
    D2CriticalSectionStrc tCriticalSection;
    void* hThread;
    unsigned long nThreadId;
    int bStopping;
    unsigned long nFogErrorCode;
    unsigned long nWSALastError;
    char szName[64];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" size_t __cdecl strlen(const char* szString);
extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize);                                      // 0x00681EF0
extern "C" int __cdecl toupper(int nChar);                                                                  // 0x00685385
extern "C" int __cdecl tolower(int nChar);                                                                  // 0x0068523E

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC
extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* pAddress, size_t nSize, unsigned long dwFreeType); // 0x006CC220
extern "C" __declspec(dllimport) void __stdcall GetLocalTime(D2SystemTimeStrc* pSystemTime);                // 0x006CC1D4
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" __declspec(dllimport) int __stdcall FindClose(void* hFindFile);                                  // 0x006CC1C4
extern "C" int __stdcall closesocket(unsigned int nSocket);                                                 // 0x006B012C
extern "C" int __stdcall WSAStartup(unsigned short wVersionRequested, D2WSADataStrc* pData);                // 0x006B0132
extern "C" int __stdcall WSACleanup();                                                                      // 0x006B0138
extern "C" char* __stdcall inet_ntoa(D2InAddrStrc tAddress);                                                // 0x006B013E
extern "C" unsigned short __stdcall htons(unsigned short nValue);                                           // 0x006B0156
extern "C" int __stdcall WSAGetLastError();                                                                 // 0x006B0168
extern "C" unsigned int __stdcall socket(int nFamily, int nType, int nProtocol);                            // 0x006B016E
extern "C" int __stdcall recv(unsigned int nSocket, char* pBuffer, int nLength, int nFlags);                // 0x006B0174
extern "C" int __stdcall send(unsigned int nSocket, const char* pBuffer, int nLength, int nFlags);          // 0x006B017A
extern "C" D2HostentStrc* __stdcall gethostbyname(const char* szName);                                      // 0x006B0192
extern "C" int __stdcall gethostname(char* szName, int nNameLength);                                        // 0x006B0198

void __cdecl ERRORMANAGER_RaiseErrorReport(int nType, const char* szFile, int nLine, const char* szFormat, ...); // 0x00408900
void __cdecl LOGMANAGER_CloseLogFiles();                                                                  // 0x0040F960
void __cdecl LOGMANAGER_CloseLogFilesNow();                                                               // 0x0040F8A0
void __fastcall LOGMANAGER_GetLogDirectory(char* szDirectory, int nSize);                                 // 0x0040F000
void __fastcall LOGMANAGER_SweepLogFile(const D2FileTimeStrc* pNow, const char* szFile);                  // 0x0040F3D0
extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...); // 0x00413A40
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
D2PoolDirectoryStrc gtPoolManager;                                                                   // 0x0074F0E8
extern char gszResolvedHostIP[];                                                                   // 0x0075D040
extern D2CriticalSectionStrc gtLogLock;                                                            // 0x0075E850






// 0x0040EBD0
_iobuf* __fastcall sub_0040EBD0_OpenDatedLogFile(const char* szName, D2SystemTimeStrc* pTime, const char* szMode, int* pbNew, char* szPathOut, unsigned int nPathOutSize)
{
    char szPath[0x104];
    GetLocalTime(pTime);
// build: symbol ?gszLogPrefix@* 0x00708018
    SStrPrintf(szPath, sizeof(szPath), "%s%s%02d%02d%02d.txt", gszLogPrefix, szName, pTime->wYear % 100, pTime->wMonth, pTime->wDay);
    if (szPathOut)
    {
        SStrCopy(szPathOut, szPath, nPathOutSize);
    }
    if (pbNew)
    {
        *pbNew = 1;
        if (*szMode == 'a')
        {
            _iobuf* pFile = fopen(szPath, "r");
            if (pFile)
            {
                fclose(pFile);
                *pbNew = 0;
            }
        }
    }
    return fopen(szPath, szMode);
}


// 0x00410CF0
void __stdcall sub_00410CF0_NotBits(const unsigned char* pIn, unsigned char* pOut, int nBits)
{
    const int nBytes = (nBits + 7) / 8;
    const int nAligned = 4 * (nBytes / 4);
    int i;
    for (i = 0; i < nAligned; i += 4)
    {
        *(int*)&pOut[i] = ~*(const int*)&pIn[i];
    }
    switch (nBytes - nAligned)
    {
    case 3:
        pOut[i + 2] = ~pIn[i + 2];
    case 2:
        pOut[i + 1] = ~pIn[i + 1];
    case 1:
        pOut[i] = ~pIn[i];
    }
}

// 0x00411320
void __stdcall sub_00411320_CapitalizeWords(char* szText)
{
    int bNewWord = 1;
    if (!szText)
    {
        return;
    }
    int i = 0;
    const int nLength = strlen(szText);
    while (i < nLength)
    {
        D2_ASSERT(i < 0x400, 120);
        const char c = szText[i];
        if (c == ' ')
        {
            bNewWord = 1;
            ++i;
            continue;
        }
        if (bNewWord)
        {
            bNewWord = 0;
            szText[i] = toupper(c);
        }
        else
        {
            szText[i] = tolower(c);
        }
        ++i;
    }
}

#include "gen/data/Source/Fog/Unknown_0040EBD0.inc"
