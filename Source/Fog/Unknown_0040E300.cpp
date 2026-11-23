#include "Fog.h"
#include "D2StormLink.h"
#include "D2GameTypes.h"
#include "D2NetTypes.h"

struct FSafeSock;
struct D2CriticalSectionStrc;
struct Obj0040E0B0;
struct D2LogMsgListStrc;
struct D2LogMsgNodeStrc;
struct D2LogMessageStrc;
class CCritSect;

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

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218

struct Obj0040E0B0 { unsigned char bUnknown00[0x30]; unsigned int dwValue30; unsigned int dwValue34; };

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" int __cdecl sscanf(const char* szSource, const char* szFormat, ...); // 0x00684BD5
extern "C" D2HostentStrc* __stdcall gethostbyname(const char* szName); // 0x006B0192
extern "C" char* __stdcall inet_ntoa(D2InAddrStrc tAddress); // 0x006B013E
extern "C" int __stdcall WSACleanup(); // 0x006B0138
extern "C" int __stdcall WSAGetLastError(); // 0x006B0168
int __fastcall FOG_SOCKET_WSAStartup(); // 0x0040D890
extern char gszResolvedHostIP[]; // 0x0075D040

struct D2LogMsgListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    void sub_0040FED0_DeleteAll();                                          // 0x0040FED0
};

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134
FSafeSock* __fastcall FOG_SOCKET_ConnectEx(char* szHostAddress, int nPortNumber, unsigned long (__stdcall* pThreadProc)(void* pParam), void* lpParameter, const char* szName, int bNonBlocking); // 0x0040D8E0
extern int gnLogQueued; // 0x0075D140
extern int gnLogQueuedBytes; // 0x0075D144
extern int gbLogInitialized; // 0x0075D2EC
extern unsigned long gnLogThreadId; // 0x0075E834
extern D2CriticalSectionStrc gtLogQueueLock; // 0x0075E838
extern D2LogMsgListStrc gtLogMsgQueue_0075E868; // 0x0075E868
extern D2CriticalSectionStrc gtTimeLock; // 0x0075E880

void __cdecl LOGMANAGER_WriteLogLine(const char* szFormat, ...); // 0x00410610
int __cdecl ERRORMANAGER_MeasureCpuMHz(); // 0x0040E870

struct T004013C0
{
    unsigned long dwOemId;
    unsigned long dwPageSize;
    void* lpMinimumApplicationAddress;
    void* lpMaximumApplicationAddress;
    unsigned long dwActiveProcessorMask;
    unsigned long dwNumberOfProcessors;
    unsigned long dwProcessorType;
    unsigned long dwAllocationGranularity;
    unsigned short wProcessorLevel;
    unsigned short wProcessorRevision;
};

extern T004013C0 gtSystemInfo; // 0x0074D8A0
extern "C" const char gszIntel386[]; // 0x006CE074
extern "C" const char gszIntel486[]; // 0x006CE080
extern "C" const char gszCpuSpeedFormat[]; // 0x006CE08C
extern "C" const char gszCpuVersionFormat[]; // 0x006CE0A8
extern "C" const char gszCpuVendorFormat[]; // 0x006CE0EC

struct D2LogMsgNodeStrc
{
    D2LogMsgNodeStrc* pPrev;
    D2LogMsgNodeStrc* pNext;
};

struct D2LogMessageStrc : D2LogMsgNodeStrc
{
    char unk0x08[0x1C];
};

class CCritSect
{
public:
    CCritSect();                                                                                            // 0x0040EB50
    ~CCritSect();                                                                                           // 0x0040EB60
    void Enter();
    void Leave();

    D2CriticalSectionStrc tLock;
};

void* ghLogThread; // 0x0075D2E8

int gbLogThreadStop; // 0x0075E830

// 0x0040FFD0
void __cdecl sub_0040FFD0_ShutdownLogSystem()
{
    gbLogThreadStop = 1;
    WaitForSingleObject(ghLogThread, 30000);
    CloseHandle(ghLogThread);
    EnterCriticalSection(&gtLogQueueLock);
    gtLogMsgQueue_0075E868.sub_0040FED0_DeleteAll();
    gnLogQueued = 0;
    gnLogQueuedBytes = 0;
    ghLogThread = 0;
    gnLogThreadId = 0;
    gbLogInitialized = 0;
    gbLogThreadStop = 0;
    LeaveCriticalSection(&gtLogQueueLock);
}

// 0x0040E300
static void __stdcall sub_0040E300(char* szBuf, int nVendor, int nFamily, unsigned int nModel, int nBrand, int nType)
{
    strcpy(szBuf, "{Unknown}");
    switch (nVendor)
    {
    case 1:
        if (nBrand == 1)
        {
            strcpy(szBuf, "Celeron");
        }
        else if (nBrand == 2)
        {
            strcpy(szBuf, "Pentium III");
        }
        else if (nBrand == 3)
        {
            strcpy(szBuf, "Pentium III Xeon");
        }
        else if (nBrand == 4)
        {
            strcpy(szBuf, "Pentium III");
        }
        else if (nBrand == 8)
        {
            strcpy(szBuf, "Pentium 4");
        }
        else if (nBrand == 14)
        {
            strcpy(szBuf, "Xeon");
        }
        else if (nType == 0 && nFamily == 5 && nModel < 4)
        {
            strcpy(szBuf, "Pentium");
        }
        else if (nType == 0 && nFamily == 5)
        {
            strcpy(szBuf, "Pentium MMX");
        }
        else if (nType == 1 && nFamily == 5 && nModel < 3)
        {
            strcpy(szBuf, "Pentium OD586");
        }
        else if (nType == 1 && nFamily == 5 && nModel == 3)
        {
            strcpy(szBuf, "Pentium OD486");
        }
        else if (nType == 1 && nFamily == 5 && nModel >= 4)
        {
            strcpy(szBuf, "Pentium MMX OD586");
        }
        else if (nType == 0 && nFamily == 6 && nModel < 3)
        {
            strcpy(szBuf, "Pentium Pro");
        }
        else if (nType == 1 && nFamily == 6)
        {
            strcpy(szBuf, "Pentium II OD");
        }
        else if (nType == 0 && nFamily == 6 && nModel < 5)
        {
            strcpy(szBuf, "Pentium II");
        }
        else if (nType == 0 && nFamily == 6 && nModel == 5)
        {
            strcpy(szBuf, "Pentium II or Celeron");
        }
        else if (nType == 0 && nFamily == 6 && nModel == 6)
        {
            strcpy(szBuf, "Celeron");
        }
        else if (nType == 0 && nFamily == 6 && nModel == 7)
        {
            strcpy(szBuf, "Pentium III");
        }
        else if (nType == 0 && nFamily == 6 && nModel >= 8)
        {
            strcpy(szBuf, "Pentium III (no brand)");
        }
        else if (nType == 0 && nFamily == 15)
        {
            strcpy(szBuf, "Pentium 4 (no brand)");
        }
        break;
    case 2:
        if (nFamily == 4)
        {
            strcpy(szBuf, "Am486DX4 or Am5x86");
        }
        else if (nFamily == 5)
        {
            if (nModel < 6)
            {
                strcpy(szBuf, "K5");
            }
            else if (nModel < 8)
            {
                strcpy(szBuf, "K6");
            }
            else if (nModel == 8)
            {
                strcpy(szBuf, "K6-II");
            }
            else if (nModel >= 9)
            {
                strcpy(szBuf, "K6-III");
            }
        }
        else if (nFamily == 6)
        {
            if (nModel < 3)
            {
                strcpy(szBuf, "Athlon");
            }
            else if (nModel == 3)
            {
                strcpy(szBuf, "Duron");
            }
            else if (nModel < 6)
            {
                strcpy(szBuf, "Athlon");
            }
            else if (nModel == 6)
            {
                strcpy(szBuf, "Athlon MP, XP, or Mobile");
            }
            else if (nModel == 7)
            {
                strcpy(szBuf, "Duron Mobile");
            }
        }
        break;
    case 3:
        if (nType == 0)
        {
            if (nFamily == 4)
            {
                strcpy(szBuf, "MediaGX");
            }
            else if (nFamily == 5)
            {
                if (nModel < 4)
                {
                    strcpy(szBuf, "6x86");
                }
                else
                {
                    strcpy(szBuf, "GXm");
                }
            }
            else if (nFamily == 6)
            {
                strcpy(szBuf, "6x86MX");
            }
        }
        break;
    }
}

void __cdecl sub_0040EA00_WriteProcessorReport()
{
    char szName[0x100];
    switch (gwProcessorLevel_0074D8C0)
    {
    case 3:
        LOGMANAGER_WriteLogLine(gszIntel386);
        break;
    case 4:
        LOGMANAGER_WriteLogLine(gszIntel486);
        break;
    default:
    {
        const int nVendor = sub_0040E250_GetCpuVendor();
        const unsigned int nSignature = sub_0040E960_GetCpuSignature();
        const unsigned int nModel = (nSignature >> 4) & 0xF;
        const int nType = (nSignature >> 12) & 3;
        const int nFamily = (nSignature >> 8) & 0xF;
        const int nBrand = sub_0040E980_GetCpuBrand() & 0xFF;
        sub_0040E300(szName, nVendor, nFamily, nModel, nBrand, nType);
// build: symbol ?gaszCpuVendorNames@* 0x00708004
        LOGMANAGER_WriteLogLine(gszCpuVendorFormat, gaszCpuVendorNames[nVendor]);
        LOGMANAGER_WriteLogLine(gszCpuVersionFormat, szName, nType, nFamily, nModel, nSignature & 0xF, nBrand);
        LOGMANAGER_WriteLogLine(gszCpuSpeedFormat, ERRORMANAGER_MeasureCpuMHz());
        break;
    }
    }
}

// 0x0040EB40
char* __fastcall sub_0040EB40_GetMessageData(D2LogMessageStrc* pMessage)
{
    return pMessage->unk0x08;
}

// 0x0040EB70
void CCritSect::Enter()
{
    EnterCriticalSection(&tLock);
}

// 0x0040EB80
void CCritSect::Leave()
{
    LeaveCriticalSection(&tLock);
}
