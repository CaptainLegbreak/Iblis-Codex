#include "D2MCPClient.h"
#include "D2GameTypes.h"
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                              // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                    // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

char* gpMcpPacket; // 0x007992F4

// 0x00449E70
void __stdcall MCPCONNECT_SetPacket(const char* pData, int nSize)
{
    if (gpMcpPacket)
    {
        FOG_Free(gpMcpPacket, ".\\Src\\McpConnect.cpp", 0x21E, 0);
        gpMcpPacket = 0;
    }
    if (!nSize)
        return;
    gpMcpPacket = (char*)FOG_Alloc(nSize, ".\\Src\\McpConnect.cpp", 0x227, 0);
    memcpy(gpMcpPacket, pData, nSize);
    if (*pData == 0x17)
    {
        D2_ASSERT(*(unsigned short*)(gpMcpPacket + 1) < 0x100, 0x233);
        D2_ASSERT(*(unsigned short*)(gpMcpPacket + 3) < 0x100, 0x234);
        D2_ASSERT(*(unsigned short*)(gpMcpPacket + 5) < 0x100, 0x235);
        D2_ASSERT(*(unsigned short*)(gpMcpPacket + 7) < 0x100, 0x236);
    }
    else if (*pData == 0x19)
    {
        D2_ASSERT(*(unsigned short*)(gpMcpPacket + 1) < 0x100, 0x242);
        D2_ASSERT(*(unsigned short*)(gpMcpPacket + 3) < 0x100, 0x243);
        D2_ASSERT(*(unsigned short*)(gpMcpPacket + 5) < 0x100, 0x244);
        const unsigned short nCount = *(unsigned short*)(gpMcpPacket + 7);
        D2_ASSERT(nCount < 0x100, 0x245);
        const char* p = gpMcpPacket + 9;
        for (int i = 0; i < nCount; i++)
        {
            p += 4;
            while (*p++);
            while (*p++);
        }
    }
    else
    {
        D2_ASSERT(0, 0x254);
    }
}
struct D2QSSOCKET_SetPacketFormat;

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

typedef int (__fastcall* D2LaunchPacketHandler)(const unsigned char* pData, unsigned int nSize, int nArg);

extern "C" __declspec(dllimport) void* __stdcall CreateEventA(void* pAttributes, int bManualReset, int bInitialState, const char* szName); // 0x006CC228

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long nMilliseconds); // 0x006CC230

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long nMilliseconds);                         // 0x006CC258

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

int __fastcall FOG_SOCKET_GetPeerName(FSafeSock* pSafeSock, void* pAddress, int* pnLength); // 0x0040DEE0

int __fastcall FOG_SOCKET_GetError(FSafeSock* pSafeSock, unsigned long* pFogError, unsigned long* pWSALastError); // 0x0040E0B0

int __fastcall WINMAIN_SendMcpStartup(D2LaunchThreadRecordStrc* pRecord);                                // 0x0044A1D0

int __fastcall WINMAIN_DispatchConnectPacket(const unsigned char* pData, unsigned int nSize, int nArg);         // 0x0044B1C0

void __stdcall D2QSSOCKET_SetPacketHandler(void* pConnection, D2LaunchPacketHandler pfnHandler, int nArg);      // 0x006BC010

int __stdcall FOG_ConnectionSend(void* pConnection, const char* pData, int nSize);                           // 0x006BC0B0

void __stdcall D2QSSOCKET_ConnectAndWait(void* pConnection);                                                       // 0x006BC5A0

void __stdcall D2QSSOCKET_Close(void* pConnection);                                                       // 0x006BC680

D2QSSOCKET_SetPacketFormat* __stdcall D2QSSOCKET_CreateRecord(const char* szName, int nValue, const char* szLabel); // 0x006BC6A0

FSafeSock* __stdcall D2QSSOCKET_GetSafeSock(void* pConnection);                                          // 0x006BC810

extern void* gpMcpConnection;                                                                         // 0x00798FB4

D2LaunchThreadRecordStrc gtThreadRecord;                                                           // 0x00798FB8

#define gnServerAddress_00798FC8 (gtThreadRecord.nData[4])

#define gnServerPort_00798FCC (gtThreadRecord.nData[5])

int gnValue_0079929C;                                                                                       // 0x0079929C

void* ghConnectEvent;                                                                              // 0x007992EC

int __cdecl sub_00449B30_QueryAddress()
{
    FSafeSock* pHandle = D2QSSOCKET_GetSafeSock(gpMcpConnection);
    if (!pHandle)
        return 0;
    D2LaunchAddressStrc tAddress;
    int nSize = sizeof(tAddress);
    return FOG_SOCKET_GetPeerName(pHandle, &tAddress, &nSize);
}

// 0x00449FB0
void __stdcall MCPCONNECT_WaitConnect(D2LaunchThreadRecordStrc* pRecord)
{
    if (!ghConnectEvent)
        ghConnectEvent = CreateEventA(0, 0, 0, 0);
    if (WINMAIN_SendMcpStartup(pRecord) == -1)
    {
        gnValue_0079929C = 0xB;
        return;
    }
    const unsigned long dwEndTick = GetTickCount() + 60000;
    for (;;)
    {
        if (!sub_00449B30_QueryAddress())
            break;
        if (GetTickCount() >= dwEndTick)
            break;
        const unsigned long dwResult = WaitForSingleObject(ghConnectEvent, 0);
        if (dwResult == 0)
            return;
        if (dwResult != 0x102)
            break;
        Sleep(10);
    }
    gnValue_0079929C = 2;
}
// 0x0044A070
int __cdecl MCPCONNECT_ConnectThread()
{
// build: symbol ?FOG_inet_ntoa@* 0x0040E080
    const char* szAddress = FOG_inet_ntoa(gnServerAddress_00798FC8);
    gnValue_0079929C = 0;
    void* pConnection = D2QSSOCKET_CreateRecord(szAddress, gnServerPort_00798FCC, "clt->mcp");
    gpMcpConnection = pConnection;
    D2QSSOCKET_SetPacketHandler(pConnection, WINMAIN_DispatchConnectPacket, 0);
    D2QSSOCKET_ConnectAndWait(pConnection);
    unsigned long nFogError = 0;
    unsigned long nWSALastError;
    FSafeSock* pSafeSock = D2QSSOCKET_GetSafeSock(pConnection);
    if (pSafeSock)
    {
        FOG_SOCKET_GetError(pSafeSock, &nFogError, &nWSALastError);
        if (nFogError == 0)
        {
            if (pConnection != gpMcpConnection)
            {
                D2QSSOCKET_Close(pConnection);
                return 0;
            }
            char nValue = 1;
            FOG_ConnectionSend(pConnection, &nValue, 1);
            MCPCONNECT_WaitConnect(&gtThreadRecord);
            return gnValue_0079929C == 0;
        }
    }
    gnValue_0079929C = 2;
    return 0;
}



#include "gen/data/Source/D2MCPClient/Src/McpConnect.inc"
