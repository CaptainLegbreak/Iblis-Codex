#include "D2Net.h"

struct D2WSADataStrc
{
    unsigned short wVersion;
    unsigned short wHighVersion;
    char szDescription[0x101];
    char szSystemStatus[0x81];
    unsigned short iMaxSockets;
    unsigned short iMaxUdpDg;
    char pad0x18A[2];
    char* lpVendorInfo;
};

struct D2SockAddrInStrc
{
    short sin_family;
    unsigned short sin_port;
    unsigned long sin_addr;
    char sin_zero[8];
};

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

extern "C" int __stdcall WSAStartup(unsigned short wVersionRequested, D2WSADataStrc* pData);               // 0x006B0132
extern "C" int __stdcall socket(int nFamily, int nType, int nProtocol);                                    // 0x006B016E
extern "C" unsigned short __stdcall htons(unsigned short nValue);                                           // 0x006B0156
extern "C" unsigned long __stdcall inet_addr(const char* szAddress);                                        // 0x006B0150
extern "C" int __stdcall connect(int nSocket, const D2SockAddrInStrc* pName, int nNameLen);                 // 0x006B014A
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock);    // 0x006CC210
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
const char* __fastcall FOG_ResolveHostIPAddress(const char* szHostName);                                    // 0x0040E0D0
int __fastcall sub_0052B7E0();                                                                              // 0x0052B7E0
void __fastcall sub_0052B780();                                                                             // 0x0052B780

D2WSADataStrc gWSAData;                                                                                     // 0x00882B48
D2SockAddrInStrc gHostSockAddr;                                                                             // 0x00882B38
extern int gdwGlobal_00882D00;                                                                              // 0x00882D00
extern void* gpGamePacketList;                                                                              // 0x00882CE4
extern void* gpSystemPacketList;                                                                            // 0x00882CDC
extern D2CriticalSectionStrc gCriticalSection;                                                              // 0x00882CE8
extern void* gpPacketBuffer;                                                                                // 0x00882B34
extern void* ghClientConnectToHostThreadHandle;                                                             // 0x00882CE0
extern unsigned long gdwThreadId;                                                                           // 0x00882B30

void* gpGlobal_00882D08;                                                                                    // 0x00882D08
int __stdcall sub_006BE4E0(void* pObject, int nArg1);                                                       // 0x006BE4E0
int __stdcall sub_006BE390(void* pObject, int nArg1, int nArg2);                                            // 0x006BE390
int __fastcall sub_006BF610(void* pObject, int nArg1, int nArg2);                                           // 0x006BF610
void __stdcall sub_006BE4A0(void* pObject, int nArg1);                                                      // 0x006BE4A0
int __stdcall sub_006BF4E0(void* pObject, int nArg1);                                                       // 0x006BF4E0
int __stdcall sub_006C0170(void* pObject, const unsigned char* pData, int nSize);                           // 0x006C0170
int __stdcall sub_006BEAD0(void* pObject, int nMode, int nArg1, int nArg2);                                 // 0x006BEAD0
int __stdcall sub_006BED90(void* pObject, int nArg1, int nArg2, int nArg3);                                 // 0x006BED90
int __stdcall sub_006BEE20(void* pObject, int nArg1);                                                       // 0x006BEE20
int __stdcall sub_006BEF40(void* pObject, int nArg1);                                                       // 0x006BEF40
int __stdcall sub_006C0530(void* pObject, int nArg1, int nArg2, int nArg3);                                 // 0x006C0530
int __stdcall sub_006C0600(void* pObject, int nArg1, int nArg2, int nArg3);                                 // 0x006C0600
int __stdcall sub_006BEFB0(void* pObject, int nArg1, int nArg2, int nArg3);                                 // 0x006BEFB0
int __stdcall sub_006C06D0(void* pObject, int nArg1, int nArg2, int nArg3);                                 // 0x006C06D0

// 0x0052A680
unsigned long __stdcall CLIENT_ConnectToHost(void* szIpAddress)
{
    gdwGlobal_00882D00 = 0;
    WSAStartup(0x101, &gWSAData);
    gClientSocket = socket(2, 1, 0);
    if (gClientSocket == -1)
        WSAGetLastError();
    memset(&gHostSockAddr, 0, sizeof(gHostSockAddr));
    gHostSockAddr.sin_family = 2;
    gHostSockAddr.sin_port = htons(4000);
    gHostSockAddr.sin_addr = inet_addr(FOG_ResolveHostIPAddress((const char*)szIpAddress));
    if (connect(gClientSocket, &gHostSockAddr, sizeof(D2SockAddrInStrc)) == -1)
        gClientSocket = -1;
    return 1;
}

// 0x0052A750
void __stdcall CLIENT_Initialize(int nArg, const char* szIpAddress)
{
    gpGamePacketList = 0;
    gpSystemPacketList = 0;
    InitializeCriticalSection(&gCriticalSection);
    gpPacketBuffer = FOG_Alloc(0x7BC, ".\\SRC\\Client.cpp", 200, 0);
    memset(gpPacketBuffer, 0, 0x7BC);
    sub_0052B810(nArg);
    if (sub_0052B7E0())
    {
        sub_0052B780();
        return;
    }
    ghClientConnectToHostThreadHandle = CreateThread(0, 0, CLIENT_ConnectToHost, (void*)szIpAddress, 0, &gdwThreadId);
}

// 0x0052B1F0
int __stdcall sub_0052B1F0_ObjectCall_6BE4E0(int nArg1)
{
    return sub_006BE4E0(gpGlobal_00882D08, nArg1);
}

// 0x0052B210
int __stdcall sub_0052B210_ObjectCall_6BE390(int nArg1, int nArg2)
{
    return sub_006BE390(gpGlobal_00882D08, nArg1, nArg2);
}

// 0x0052B230
int __stdcall sub_0052B230_ObjectCall_6BF610(int nArg1, int nArg2)
{
    return sub_006BF610(gpGlobal_00882D08, nArg2, nArg1);
}

// 0x0052B250
void __stdcall sub_0052B250_ObjectCall_6BE4A0(int nArg1)
{
    sub_006BE4A0(gpGlobal_00882D08, nArg1);
}

// 0x0052B280
int __stdcall sub_0052B280_ObjectCall_6BF4E0(int nArg1)
{
    return sub_006BF4E0(gpGlobal_00882D08, nArg1);
}

// 0x0052B2A0
void __cdecl sub_0052B2A0_SendCloseAndClear()
{
    unsigned char nMessage = 0xB0;
    sub_006C0170(gpGlobal_00882D08, &nMessage, 1);
    gpGlobal_00882D08 = 0;
}

// 0x0052B2D0
int __stdcall sub_0052B2D0_ObjectCallMode1(int nArg1, int nArg2)
{
    return sub_006BEAD0(gpGlobal_00882D08, 1, nArg1, nArg2);
}

// 0x0052B2F0
int __stdcall sub_0052B2F0_ObjectCallMode0(int nArg1, int nArg2)
{
    return sub_006BEAD0(gpGlobal_00882D08, 0, nArg1, nArg2);
}

// 0x0052B310
int __stdcall sub_0052B310_ObjectCallMode2(int nArg1, int nArg2)
{
    return sub_006BEAD0(gpGlobal_00882D08, 2, nArg1, nArg2);
}

// 0x0052B490
int __stdcall sub_0052B490_ObjectCall_6BED90(int nArg1, int nArg2, int nArg3)
{
    return sub_006BED90(gpGlobal_00882D08, nArg1, nArg2, nArg3);
}

// 0x0052B4B0
int __stdcall sub_0052B4B0_ObjectCall_6BEE20(int nArg1)
{
    return sub_006BEE20(gpGlobal_00882D08, nArg1);
}

// 0x0052B4D0
int __stdcall sub_0052B4D0_ObjectCall_6BEF40(int nArg1)
{
    return sub_006BEF40(gpGlobal_00882D08, nArg1);
}

// 0x0052B4F0
int __stdcall sub_0052B4F0(int nArg1, int nArg2, int nArg3)
{
    return sub_006C0530(gpGlobal_00882D08, nArg1, nArg2, nArg3);
}

// 0x0052B510
int __stdcall sub_0052B510_ObjectCall_6C0600(int nArg1, int nArg2, int nArg3)
{
    return sub_006C0600(gpGlobal_00882D08, nArg1, nArg2, nArg3);
}

// 0x0052B530
int __stdcall sub_0052B530_ObjectCall_6BEFB0(int nArg1, int nArg2, int nArg3)
{
    return sub_006BEFB0(gpGlobal_00882D08, nArg1, nArg2, nArg3);
}

// 0x0052B550
int __stdcall sub_0052B550_ObjectCall_6C06D0(int nArg1, int nArg2, int nArg3)
{
    return sub_006C06D0(gpGlobal_00882D08, nArg1, nArg2, nArg3);
}
