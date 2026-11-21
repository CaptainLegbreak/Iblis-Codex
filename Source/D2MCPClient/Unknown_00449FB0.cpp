#include "D2MCPClient.h"
#include "D2GameTypes.h"
struct T006BC290;


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
int __fastcall sub_0044A1D0_StartConnect(D2LaunchThreadRecordStrc* pRecord);                                // 0x0044A1D0
int __fastcall sub_0044B1C0_HandlePacket(const unsigned char* pData, unsigned int nSize, int nArg);         // 0x0044B1C0
void __stdcall sub_006BC010_SetHandler(void* pConnection, D2LaunchPacketHandler pfnHandler, int nArg);      // 0x006BC010
int __stdcall sub_006BC0B0_Send(void* pConnection, const char* pData, int nSize);                           // 0x006BC0B0
void __stdcall sub_006BC5A0_Start(void* pConnection);                                                       // 0x006BC5A0
void __stdcall sub_006BC680_Close(void* pConnection);                                                       // 0x006BC680
T006BC290* __stdcall sub_006BC6A0_AllocSocketRecord(const char* szName, int nValue, const char* szLabel); // 0x006BC6A0
FSafeSock* __stdcall sub_006BC810_LookupHandle(void* pConnection);                                          // 0x006BC810

extern void* gpConnection_00798FB4;                                                                         // 0x00798FB4
D2LaunchThreadRecordStrc gtThreadRecord_00798FB8;                                                           // 0x00798FB8
#define gnServerAddress_00798FC8 (gtThreadRecord_00798FB8.nData[4])
#define gnServerPort_00798FCC (gtThreadRecord_00798FB8.nData[5])
int gnValue_0079929C;                                                                                       // 0x0079929C
void* ghConnectEvent_007992EC;                                                                              // 0x007992EC

int __cdecl sub_00449B30_QueryAddress()
{
    FSafeSock* pHandle = sub_006BC810_LookupHandle(gpConnection_00798FB4);
    if (!pHandle)
        return 0;
    D2LaunchAddressStrc tAddress;
    int nSize = sizeof(tAddress);
    return FOG_SOCKET_GetPeerName(pHandle, &tAddress, &nSize);
}

// 0x00449FB0
void __stdcall sub_00449FB0_WaitConnect(D2LaunchThreadRecordStrc* pRecord)
{
    if (!ghConnectEvent_007992EC)
        ghConnectEvent_007992EC = CreateEventA(0, 0, 0, 0);
    if (sub_0044A1D0_StartConnect(pRecord) == -1)
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
        const unsigned long dwResult = WaitForSingleObject(ghConnectEvent_007992EC, 0);
        if (dwResult == 0)
            return;
        if (dwResult != 0x102)
            break;
        Sleep(10);
    }
    gnValue_0079929C = 2;
}

// 0x0044A070
int __cdecl sub_0044A070_ConnectThread()
{
    const char* szAddress = sub_0040E080_AddressToString(gnServerAddress_00798FC8);
    gnValue_0079929C = 0;
    void* pConnection = sub_006BC6A0_AllocSocketRecord(szAddress, gnServerPort_00798FCC, "clt->mcp");
    gpConnection_00798FB4 = pConnection;
    sub_006BC010_SetHandler(pConnection, sub_0044B1C0_HandlePacket, 0);
    sub_006BC5A0_Start(pConnection);
    unsigned long nFogError = 0;
    unsigned long nWSALastError;
    FSafeSock* pSafeSock = sub_006BC810_LookupHandle(pConnection);
    if (pSafeSock)
    {
        FOG_SOCKET_GetError(pSafeSock, &nFogError, &nWSALastError);
        if (nFogError == 0)
        {
            if (pConnection != gpConnection_00798FB4)
            {
                sub_006BC680_Close(pConnection);
                return 0;
            }
            char nValue = 1;
            sub_006BC0B0_Send(pConnection, &nValue, 1);
            sub_00449FB0_WaitConnect(&gtThreadRecord_00798FB8);
            return gnValue_0079929C == 0;
        }
    }
    gnValue_0079929C = 2;
    return 0;
}
