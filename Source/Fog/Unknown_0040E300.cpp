#include "Fog.h"
#include "D2StormLink.h"
#include "D2GameTypes.h"
#include "D2NetTypes.h"

struct FSafeSock;
struct D2CriticalSectionStrc;
struct FOG_SOCKET_GetError;
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

struct FOG_SOCKET_GetError { unsigned char bUnknown00[0x30]; unsigned int dwValue30; unsigned int dwValue34; };

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
int __stdcall ERRORMANAGER_MeasureCpuMHz(); // 0x0040E870

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
