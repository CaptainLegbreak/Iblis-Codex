#include "D2Client.h"

struct D2ClientCharRecordStrc;
struct D2CmdParamsStrc;
struct D2GameDataTableStrc;
struct D2ClientInterfaceStrc;
typedef void (__fastcall* D2McpCallback)(int nId, unsigned int nSize, const unsigned char* pData);

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
void __stdcall sub_00449E30_SetValue(int nValue);                                                           // 0x00449E30
void __stdcall sub_00449E50_SetValue(int nValue);                                                           // 0x00449E50
void __stdcall sub_00449E70_SetMcpPacket(const char* pData, int nSize);                                     // 0x00449E70
void __cdecl sub_006115F0_Empty();                                                                          // 0x006115F0
void __cdecl sub_0052BDA0_Empty();                                                                          // 0x0052BDA0
void __cdecl sub_0052BDB0_Empty();                                                                          // 0x0052BDB0
void __cdecl sub_00611600();                                                                                // 0x00611600
int __stdcall sub_0044B8A0_LauncherRun(void* hInstance, D2ClientCharRecordStrc* pRecord);                   // 0x0044B8A0
void __cdecl sub_004519A0_ToggleFlags();                                                                    // 0x004519A0
void __cdecl sub_004518E0_StartPlayback();                                                                  // 0x004518E0
int __stdcall sub_0044B4E0_ShowCommandLineHelp(const D2CmdParamsStrc* pParams, int nUnused);                // 0x0044B4E0
int __cdecl CLIENT_GetConnectionStatus();                                                                   // 0x0052B050
void __fastcall sub_0044E380_SetConnectionError(int nError);                                                // 0x0044E380
int __fastcall sub_00451BB0_MessageLoop(int (__stdcall* pfnIdle)(int));                                     // 0x00451BB0
void __stdcall SERVER_Initialize(int a1, int a2);                                                           // 0x0052B7A0
void __stdcall sub_0052A750(int nArg, const char* szAddress);                                               // 0x0052A750
void __stdcall sub_0052B250_ObjectCall_6BE4A0(int nArg1);                                                   // 0x0052B250
int __stdcall sub_0052B280_ObjectCall_6BF4E0(int nArg1);                                                    // 0x0052B280
void __stdcall GAME_InitGameDataTable(D2GameDataTableStrc* pGameDataTbl, void* pGameList);                  // 0x0052C0A0
int __stdcall sub_0044BAD0_PollSystemPackets(int nUnused);                                                  // 0x0044BAD0
int __stdcall sub_0044BD20_PumpSystemPackets(int nUnused);                                                  // 0x0044BD20
void __cdecl sub_0052A7E0();                                                                                // 0x0052A7E0
void __cdecl sub_0052B2A0_SendCloseAndClear();                                                              // 0x0052B2A0
int __cdecl sub_0044B480_PopValue();                                                                        // 0x0044B480

void (__fastcall* gpfnCallback_00799308)(void* pArg);                                                       // 0x00799308
extern D2McpPacketHandler gpfnMcpHandlers_0070ED68[];                                                       // 0x0070ED68
void* gpInstance_007A0318;                                                                                  // 0x007A0318
extern D2ClientInterfaceStrc gtInterface_0070EE0C;                                                          // 0x0070EE0C
int gdwGlobal_007A0460;                                                                                     // 0x007A0460
extern int gdwGlobal_007A0618;                                                                              // 0x007A0618
unsigned long gdwTick_007A0464;                                                                             // 0x007A0464
unsigned long gdwTick_007A045C;                                                                             // 0x007A045C
extern D2GameDataTableStrc gtGameDataTable_007A0690;                                                        // 0x007A0690
char gtGameList_007A0630[4];                                                                                // 0x007A0630
extern char gszAddress_0070EF20[];                                                                          // 0x0070EF20

// 0x0044B120
int __fastcall sub_0044B120_McpForwardToCallback(const unsigned char* pPacket, unsigned int nSize)
{
    if (nSize < 2)
        return 0;
    if (gpfnCallback_00799308)
        ((D2McpCallback)gpfnCallback_00799308)(pPacket[1], nSize - 2, pPacket + 2);
    return 1;
}

// 0x0044B150
int __fastcall sub_0044B150_McpSetValue(const unsigned char* pPacket, unsigned int nSize)
{
    sub_00449E30_SetValue(*(const int*)(pPacket + 1));
    sub_00449E50_SetValue(1);
    return 1;
}

// 0x0044B170
int __fastcall sub_0044B170_McpStorePacket(const unsigned char* pPacket, unsigned int nSize)
{
    sub_00449E70_SetMcpPacket((const char*)pPacket, nSize);
    return 1;
}

// 0x0044B180
int __fastcall sub_0044B180_McpStorePacket(const unsigned char* pPacket, unsigned int nSize)
{
    sub_00449E70_SetMcpPacket((const char*)pPacket, nSize);
    return 1;
}

// 0x0044B1C0
int __fastcall sub_0044B1C0_DispatchPacket(const unsigned char* pPacket, unsigned int nSize, void* pArg)
{
    int nResult = 0;
    if (nSize <= 0)
        return nResult;
    const unsigned char nCmd = pPacket[0];
    if (nCmd >= 0x1A)
        return 0;
    D2McpPacketHandler pfnHandler = gpfnMcpHandlers_0070ED68[nCmd];
    if (pfnHandler)
        nResult = pfnHandler(pPacket, nSize);
    return nResult;
}

// 0x0044B400
D2ClientInterfaceStrc* __fastcall sub_0044B400_Init(void* hInstance)
{
    sub_006115F0_Empty();
    sub_0052BDA0_Empty();
    gpInstance_007A0318 = hInstance;
    return &gtInterface_0070EE0C;
}

// 0x0044B420
void __cdecl sub_0044B420_Shutdown()
{
    sub_0052BDB0_Empty();
    sub_00611600();
}

// 0x0044B430
int __fastcall sub_0044B430_Run(D2ClientCharRecordStrc* pRecord)
{
    return sub_0044B8A0_LauncherRun(gpInstance_007A0318, pRecord);
}

// 0x0044B550
int __stdcall sub_0044B550_MemTest(const D2CmdParamsStrc* pParams, int nUnused)
{
    char* pMemory = (char*)FOG_Alloc(0x6000000, ".\\CORE\\WINMAIN.CPP", 0x121, 0);
    for (char* p = pMemory; p < pMemory + 0x6000000; p += 0x1000)
        *p = 0;
    FOG_Free(pMemory, ".\\CORE\\WINMAIN.CPP", 0x124, 0);
    return 1;
}

// 0x0044B5A0
int __stdcall sub_0044B5A0_ToggleFlags(const D2CmdParamsStrc* pParams, int nUnused)
{
    sub_004519A0_ToggleFlags();
    return 1;
}

// 0x0044B5B0
int __stdcall sub_0044B5B0_StartPlayback(const D2CmdParamsStrc* pParams, int nUnused)
{
    sub_004518E0_StartPlayback();
    return 1;
}

// 0x0044B5C0
int __stdcall sub_0044B5C0_Help(int nArg)
{
    sub_0044B4E0_ShowCommandLineHelp(0, 0);
    return 0;
}

// 0x0044B5D0
int __stdcall sub_0044B5D0_Help(int nArg)
{
    return sub_0044B4E0_ShowCommandLineHelp(0, 0);
}

// 0x0044BBB0
int __stdcall sub_0044BBB0_WaitConnect(int nUnused)
{
    if ((gdwGlobal_007A0610 != 0 && gdwGlobal_007A0610 != 1) || !WINDOW_GetState())
    {
        const int nStatus = CLIENT_GetConnectionStatus();
        if (nStatus == 0)
        {
            sub_0044E380_SetConnectionError(6);
            gdwGlobal_007A0460 = 1;
            gdwGlobal_007A0618 = 0;
            return 1;
        }
        return nStatus == 2;
    }
    return 0;
}

// 0x0044BC30
int __cdecl sub_0044BC30_Start()
{
    gdwGlobal_007A0618 = 0;
    if (gdwGlobal_007A0610 == 0)
    {
        SERVER_Initialize(1, 1);
        sub_0052A750(1, 0);
        sub_00451BB0_MessageLoop(sub_0044BBB0_WaitConnect);
        sub_0052B280_ObjectCall_6BF4E0(0);
        GAME_InitGameDataTable(&gtGameDataTable_007A0690, gtGameList_007A0630);
        gnSubsystemActive_007A0458 = 1;
        GAME_Initialize();
    }
    else if (gdwGlobal_007A0610 == 1)
    {
        SERVER_Initialize(2, 1);
        sub_0052A750(2, 0);
        sub_00451BB0_MessageLoop(sub_0044BBB0_WaitConnect);
        sub_0052B280_ObjectCall_6BF4E0(0);
        GAME_InitGameDataTable(&gtGameDataTable_007A0690, gtGameList_007A0630);
        gnSubsystemActive_007A0458 = 1;
        GAME_Initialize();
    }
    else if (gdwGlobal_007A0610 == 4)
    {
        sub_0052A750(0, gszAddress_0070F028);
        sub_00451BB0_MessageLoop(sub_0044BBB0_WaitConnect);
    }
    else if (gdwGlobal_007A0610 == 6 || gdwGlobal_007A0610 == 8)
    {
        SERVER_Initialize(0, 1);
        sub_0052B250_ObjectCall_6BE4A0(8);
        sub_0052B280_ObjectCall_6BF4E0(0);
        sub_0052A750(0, gszAddress_0070EF20);
        sub_00451BB0_MessageLoop(sub_0044BBB0_WaitConnect);
        GAME_InitGameDataTable(&gtGameDataTable_007A0690, gtGameList_007A0630);
        gnSubsystemActive_007A0458 = 1;
        GAME_Initialize();
    }
    else
    {
        sub_0052A750(0, gszAddress_0070EF20);
        sub_00451BB0_MessageLoop(sub_0044BBB0_WaitConnect);
    }

    gdwTick_007A0464 = GetTickCount();
    gdwGlobal_007A0460 = 0;
    sub_00451BB0_MessageLoop(sub_0044BAD0_PollSystemPackets);
    return sub_0044B480_PopValue();
}

// 0x0044BD90
int __cdecl sub_0044BD90_Stop()
{
    gdwTick_007A045C = GetTickCount();
    sub_00451BB0_MessageLoop(sub_0044BD20_PumpSystemPackets);
    sub_0052A7E0();
    if (gdwGlobal_007A0610 == 0 || gdwGlobal_007A0610 == 1 || gdwGlobal_007A0610 == 6 || gdwGlobal_007A0610 == 8)
        sub_0052B2A0_SendCloseAndClear();
    return sub_0044B480_PopValue();
}

#include "gen/data/Source/D2Client/CORE/WINMAIN.inc"
