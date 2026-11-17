extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* pAddend);              // 0x006CC204
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* pAddend);              // 0x006CC208
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile* pDestination, long nExchange, long nComparand); // 0x006CC3A0
int __fastcall FOG_SOCKET_WSAStartup();                                                                     // 0x0040D890
void __cdecl sub_00518C70_LogIndent(int nChannel, int nDelta);                                              // 0x00518C70
void __cdecl sub_00518D40_Log(const char* szFormat, ...);                                                   // 0x00518D40
void __cdecl sub_0051A480_DebugLog(const char* szFormat, ...);                                              // 0x0051A480
void __fastcall sub_0051C0E0_ResolveHost(char* szResult, const char* szHost);                              // 0x0051C0E0
void __fastcall sub_0051C190(char* szText, int nSize);                                                         // 0x0051C190
void __stdcall sub_0051CA90_Connect(const char* szAddress);                                                 // 0x0051CA90
void __fastcall sub_0051EA40_SetStatus(int nStatus);                                                        // 0x0051EA40
int __fastcall sub_00520520_SetState(int nState);                                                           // 0x00520520
char gszBnetHost_008818E8[0x100];                                                                          // 0x008818E8
char gszBnetAddress_008819E8[0x100];                                                                       // 0x008819E8
extern long volatile gnConnected_00881BF0;                                                                  // 0x00881BF0
extern long volatile gnDnsDone_00881BFC;                                                                    // 0x00881BFC
long volatile gnSendBusy_00881C00;                                                                          // 0x00881C00

// 0x0051D0A0
unsigned long __cdecl sub_0051D0A0_ConnectThread(void* pParameter)
{
    sub_0051A480_DebugLog("BattleConnectFastest()");
    if (InterlockedIncrement(&gnSendBusy_00881C00) > 1)
    {
        InterlockedDecrement(&gnSendBusy_00881C00);
        return 0;
    }

    sub_0051EA40_SetStatus(0x66);
    sub_0051C190(gszBnetHost_008818E8, 0x100);
    sub_0051A480_DebugLog("   connect to: %s", gszBnetHost_008818E8);
    sub_00518C70_LogIndent(2, 4);
    sub_00518D40_Log("querying gateway %s", gszBnetHost_008818E8);
    gszBnetAddress_008819E8[0] = 0;
    if (FOG_SOCKET_WSAStartup())
        sub_0051C0E0_ResolveHost(gszBnetAddress_008819E8, gszBnetHost_008818E8);

    if (!gszBnetAddress_008819E8[0])
    {
        InterlockedDecrement(&gnSendBusy_00881C00);
        sub_00520520_SetState(0xC);
        sub_0051A480_DebugLog("   failed to get server list");
        sub_00518C70_LogIndent(2, -4);
        return 0;
    }

    sub_00520520_SetState(0);
    sub_0051CA90_Connect(gszBnetAddress_008819E8);
    sub_00518C70_LogIndent(2, -4);
    if (!InterlockedCompareExchange(&gnConnected_00881BF0, 0, 0) && !InterlockedCompareExchange(&gnDnsDone_00881BFC, 0, 0))
        sub_00520520_SetState(0xC);

    InterlockedDecrement(&gnSendBusy_00881C00);
    return 1;
}
