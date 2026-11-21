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
extern char gszResolvedHostIP_0075D040[]; // 0x0075D040

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
extern int gnLogQueued_0075D140; // 0x0075D140
extern int gnLogQueuedBytes_0075D144; // 0x0075D144
extern int gbLogInitialized_0075D2EC; // 0x0075D2EC
extern unsigned long gnLogThreadId_0075E834; // 0x0075E834
extern D2CriticalSectionStrc gtLogQueueLock_0075E838; // 0x0075E838
extern D2LogMsgListStrc gtLogMsgQueue_0075E868; // 0x0075E868
extern D2CriticalSectionStrc gTimeLock_0075E880; // 0x0075E880

void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...); // 0x00410610
int __cdecl sub_0040E870_MeasureCpuMHz(); // 0x0040E870

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

extern T004013C0 gtSystemInfo_0074D8A0; // 0x0074D8A0
extern "C" const char gszIntel386_006CE074[]; // 0x006CE074
extern "C" const char gszIntel486_006CE080[]; // 0x006CE080
extern "C" const char gszCpuSpeedFormat_006CE08C[]; // 0x006CE08C
extern "C" const char gszCpuVersionFormat_006CE0A8[]; // 0x006CE0A8
extern "C" const char gszCpuVendorFormat_006CE0EC[]; // 0x006CE0EC

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

// 0x0040DDD0
void __fastcall FOG_SOCKET_Lock(FSafeSock* pSafeSock)
{
    EnterCriticalSection(&pSafeSock->tCriticalSection);
}

// 0x0040DDE0
void __fastcall FOG_SOCKET_Unlock(FSafeSock* pSafeSock)
{
    LeaveCriticalSection(&pSafeSock->tCriticalSection);
}

// 0x0040E0B0
extern "C" __declspec(dllexport) int __fastcall sub_0040E0B0(Obj0040E0B0* pObj, unsigned int* pFirst, unsigned int* pSecond) {
    *pFirst = pObj->dwValue30;
    *pSecond = pObj->dwValue34;
    return 1;
}

// 0x0040E0D0
const char* __fastcall FOG_ResolveHostIPAddress(const char* szHostName)
{
    int bStarted = 0;
    int a, b, c, d;
    if (sscanf(szHostName, "%d.%d.%d.%d", &a, &b, &c, &d) == 4)
    {
        return szHostName;
    }
    D2HostentStrc* pHost = gethostbyname(szHostName);
    if (!pHost || !pHost->h_addr_list || !pHost->h_addr_list[0])
    {
        if (WSAGetLastError() != 0x276D || !FOG_SOCKET_WSAStartup())
        {
            return 0;
        }
        pHost = gethostbyname(szHostName);
        if (!pHost || !pHost->h_addr_list || !pHost->h_addr_list[0])
        {
            WSACleanup();
            return 0;
        }
        bStarted = 1;
    }
    strcpy(gszResolvedHostIP_0075D040, inet_ntoa(*(D2InAddrStrc*)pHost->h_addr_list[0]));
    if (bStarted)
    {
        WSACleanup();
    }
    return gszResolvedHostIP_0075D040;
}

void* ghLogThread_0075D2E8; // 0x0075D2E8

int gbLogThreadStop_0075E830; // 0x0075E830

// 0x0040E230
FSafeSock* __fastcall FOG_SOCKET_Connect(char* szHostAddress, int nPortNumber, unsigned long (__stdcall* pThreadProc)(void* pParam), void* lpParameter, const char* szName)
{
    return FOG_SOCKET_ConnectEx(szHostAddress, nPortNumber, pThreadProc, lpParameter, szName, 0);
}

// 0x0040FFD0
void __cdecl sub_0040FFD0_ShutdownLogSystem()
{
    gbLogThreadStop_0075E830 = 1;
    WaitForSingleObject(ghLogThread_0075D2E8, 30000);
    CloseHandle(ghLogThread_0075D2E8);
    EnterCriticalSection(&gtLogQueueLock_0075E838);
    gtLogMsgQueue_0075E868.sub_0040FED0_DeleteAll();
    gnLogQueued_0075D140 = 0;
    gnLogQueuedBytes_0075D144 = 0;
    ghLogThread_0075D2E8 = 0;
    gnLogThreadId_0075E834 = 0;
    gbLogInitialized_0075D2EC = 0;
    gbLogThreadStop_0075E830 = 0;
    LeaveCriticalSection(&gtLogQueueLock_0075E838);
}

// 0x004107A0
void __cdecl sub_004107A0_DeleteTimeLock()
{
    DeleteCriticalSection(&gTimeLock_0075E880);
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
        sub_00410610_WriteLogLine(gszIntel386_006CE074);
        break;
    case 4:
        sub_00410610_WriteLogLine(gszIntel486_006CE080);
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
        sub_00410610_WriteLogLine(gszCpuVendorFormat_006CE0EC, gaszCpuVendorNames_00708004[nVendor]);
        sub_00410610_WriteLogLine(gszCpuVersionFormat_006CE0A8, szName, nType, nFamily, nModel, nSignature & 0xF, nBrand);
        sub_00410610_WriteLogLine(gszCpuSpeedFormat_006CE08C, sub_0040E870_MeasureCpuMHz());
        break;
    }
    }
}

// 0x0040E9E0
unsigned int __fastcall sub_0040E9E0_GetCpuidEdx(unsigned int nFunction)
{
    unsigned int nEdx;
    __asm
    {
        mov eax, nFunction
        cpuid
        mov nEdx, edx
    }
    return nEdx;
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
