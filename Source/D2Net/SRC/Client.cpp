#include "D2Net.h"

struct D2NetPacketRecStrc;
struct D2PacketBufferStrc;
struct D2CriticalSectionStrc;
struct D2WSADataStrc;
struct D2SockAddrInStrc;
struct D2FdSetStrc;
struct D2TimevalStrc;

unsigned long __stdcall CLIENT_ConnectToHost(void* szIpAddress); // 0x0052A680
int __fastcall NET_IsLocalConnection(); // 0x0052B7E0
extern D2CriticalSectionStrc gCriticalSection; // 0x00882CE8
extern int gbConnected_00882D04; // 0x00882D04
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230
int __fastcall sub_0040D880(unsigned int s); // 0x0040D880

int __fastcall NET_FreePacketList(D2CriticalSectionStrc* pCriticalSection, D2NetPacketRecStrc** ppPacketList); // 0x0052B8B0

struct D2PacketBufferStrc
{
    unsigned char data[1976];
    int nUsedBytes;
};

extern D2PacketBufferStrc* gpPacketBuffer; // 0x00882B34
extern D2NetPacketRecStrc* gpSystemPacketList; // 0x00882CDC
extern D2NetPacketRecStrc* gpGamePacketList; // 0x00882CE4
extern int gdwGlobal_00882D00; // 0x00882D00
int __fastcall NET_DequeueFirstPacketFromList(D2CriticalSectionStrc* pCriticalSection, D2NetPacketRecStrc** ppPacketList, unsigned char* pBuffer, unsigned int nBufferSize); // 0x0052B820
int __fastcall sub_0052B690_SendToServer(const unsigned char* pBuffer, unsigned short nSize); // 0x0052B690
extern "C" int __stdcall send(unsigned int nSocket, const char* pBuffer, int nLength, int nFlags); // 0x006B017A

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

extern "C" int __stdcall WSAStartup(unsigned short wVersionRequested, D2WSADataStrc* pData); // 0x006B0132
extern "C" int __stdcall socket(int nFamily, int nType, int nProtocol); // 0x006B016E
extern "C" unsigned short __stdcall htons(unsigned short nValue); // 0x006B0156
extern "C" unsigned long __stdcall inet_addr(const char* szAddress); // 0x006B0150
extern "C" int __stdcall connect(int nSocket, const D2SockAddrInStrc* pName, int nNameLen); // 0x006B014A
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
const char* __fastcall FOG_ResolveHostIPAddress(const char* szHostName); // 0x0040E0D0
void __fastcall sub_0052B780(); // 0x0052B780
extern void* ghClientConnectToHostThreadHandle; // 0x00882CE0
extern unsigned long gdwThreadId; // 0x00882B30
int __stdcall sub_006BE4E0(void* pObject, int nArg1); // 0x006BE4E0
int __stdcall sub_006BE390(void* pObject, int nArg1, int nArg2); // 0x006BE390
int __fastcall sub_006BF610(void* pObject, int nArg1, int nArg2); // 0x006BF610
void __stdcall sub_006BE4A0(void* pObject, int nArg1); // 0x006BE4A0
int __stdcall sub_006BF4E0(void* pObject, int nArg1); // 0x006BF4E0
int __stdcall sub_006C0170(void* pObject, const unsigned char* pData, int nSize); // 0x006C0170
int __stdcall sub_006BEAD0(void* pObject, int nMode, int nArg1, int nArg2); // 0x006BEAD0
int __stdcall sub_006BED90(void* pObject, int nArg1, int nArg2, int nArg3); // 0x006BED90
int __stdcall sub_006BEE20(void* pObject, int nArg1); // 0x006BEE20
int __stdcall sub_006BEF40(void* pObject, int nArg1); // 0x006BEF40
int __stdcall sub_006C0530(void* pObject, int nArg1, int nArg2, int nArg3); // 0x006C0530
int __stdcall sub_006C0600(void* pObject, int nArg1, int nArg2, int nArg3); // 0x006C0600
int __stdcall sub_006BEFB0(void* pObject, int nArg1, int nArg2, int nArg3); // 0x006BEFB0
int __stdcall sub_006C06D0(void* pObject, int nArg1, int nArg2, int nArg3); // 0x006C06D0
static __forceinline void sub_0052A730_StartConnectThread(const char* szIpAddress);
void __cdecl sub_0052AAD0_ClearConnected();

typedef unsigned int size_t;

extern "C" void* __cdecl memcpy(void* pDest, const void* pSource, size_t nSize); // 0x006829C0
extern "C" void* __cdecl memmove(void* pDest, const void* pSource, size_t nSize); // 0x00683840
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260
void __fastcall FOG_10219(unsigned char* pData); // 0x0040ADB0
int __fastcall SERVER_GetServerPacketSize(D2PacketBufferStrc* pBuffer, int nBufferSize, int* pSize); // 0x0052B920

struct D2FdSetStrc
{
    unsigned int fd_count;
    unsigned int fd_array[64];
};

struct D2TimevalStrc
{
    long tv_sec;
    long tv_usec;
};

extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText); // 0x006CC200
extern "C" int __stdcall recv(unsigned int nSocket, char* pBuffer, int nLength, int nFlags); // 0x006B0174
extern "C" int __stdcall __WSAFDIsSet(unsigned int nSocket, D2FdSetStrc* pSet); // 0x006B0180
extern "C" int __stdcall select(int nCount, D2FdSetStrc* pRead, D2FdSetStrc* pWrite, D2FdSetStrc* pExcept, const D2TimevalStrc* pTimeout); // 0x006B0186
int __fastcall sub_0040B260(unsigned char* pOut, int nOutSize, const unsigned char* pIn, unsigned int nInSize); // 0x0040B260
int __stdcall sub_0052A8D0(); // 0x0052A8D0

unsigned long gdwThreadId; // 0x00882B30

void* ghClientConnectToHostThreadHandle; // 0x00882CE0

// 0x0052A610
void __fastcall sub_0052A610_SetConnected(int bConnected)
{
    if (!NET_IsLocalConnection())
    {
        EnterCriticalSection(&gCriticalSection);
        gbConnected_00882D04 = bConnected;
        LeaveCriticalSection(&gCriticalSection);
    }
}

void __stdcall sub_M118_Emit_0052A730(int nArg, const char* szIpAddress)
{
    sub_0052B810(nArg);
    if (NET_IsLocalConnection())
    {
        return;
    }
    sub_0052A730_StartConnectThread(szIpAddress);
}

void* ghReceiveThread_00882CD8; // 0x00882CD8

// 0x0052A640
int __cdecl CLIENT_IsConnected()
{
    if (NET_IsLocalConnection())
    {
        return 1;
    }

    if (!gpPacketBuffer)
    {
        return 0;
    }

    EnterCriticalSection(&gCriticalSection);
    const int bConnected = gbConnected_00882D04;
    LeaveCriticalSection(&gCriticalSection);

    return bConnected;
}

D2WSADataStrc gWSAData; // 0x00882B48

D2SockAddrInStrc gHostSockAddr; // 0x00882B38

QServer* gpServer; // 0x00882D08

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

// 0x0052A730
static __forceinline void sub_0052A730_StartConnectThread(const char* szIpAddress)
{
    ghClientConnectToHostThreadHandle = CreateThread(0, 0, CLIENT_ConnectToHost, (void*)szIpAddress, 0, &gdwThreadId);
}

// 0x0052A750
void __stdcall CLIENT_Initialize(int nArg, const char* szIpAddress)
{
    gpGamePacketList = 0;
    gpSystemPacketList = 0;
    InitializeCriticalSection(&gCriticalSection);
    gpPacketBuffer = (D2PacketBufferStrc*)FOG_Alloc(0x7BC, ".\\SRC\\Client.cpp", 200, 0);
    memset(gpPacketBuffer, 0, 0x7BC);
    sub_0052B810(nArg);
    if (NET_IsLocalConnection())
    {
        sub_0052B780();
        return;
    }
    ghClientConnectToHostThreadHandle = CreateThread(0, 0, CLIENT_ConnectToHost, (void*)szIpAddress, 0, &gdwThreadId);
}

// 0x0052A7E0
void __cdecl CLIENT_Release()
{
    EnterCriticalSection(&gCriticalSection);

    if (gpPacketBuffer)
    {
        FOG_Free(gpPacketBuffer, ".\\SRC\\Client.cpp", 0xDA, 0);
    }

    gpPacketBuffer = 0;
    gdwGlobal_00882D00 = 1;

    LeaveCriticalSection(&gCriticalSection);

    WaitForSingleObject(ghReceiveThread_00882CD8, 6000);

    NET_FreePacketList(&gCriticalSection, &gpSystemPacketList);
    NET_FreePacketList(&gCriticalSection, &gpGamePacketList);

    DeleteCriticalSection(&gCriticalSection);

    if (NET_IsLocalConnection())
    {
        return;
    }

    const int nResult = sub_0040D880(gClientSocket);
    gClientSocket = -1;
    if (nResult == -1)
    {
        WSAGetLastError();
    }
}

// 0x0052A890
int __stdcall CLIENT_DequeueGamePacket(unsigned char* pBuffer, unsigned int nBufferSize)
{
    return NET_DequeueFirstPacketFromList(&gCriticalSection, &gpGamePacketList, pBuffer, nBufferSize);
}

// 0x0052A8B0
int __stdcall CLIENT_DequeueSystemPacket(unsigned char* pBuffer, unsigned int nBufferSize)
{
    return NET_DequeueFirstPacketFromList(&gCriticalSection, &gpSystemPacketList, pBuffer, nBufferSize);
}

// 0x0052A8D0
int __stdcall sub_0052A8D0()
{
    int nUsedBytes = gpPacketBuffer->nUsedBytes;
    D2PacketBufferStrc* pPacketBuffer = gpPacketBuffer;
    int bResult = 0;

    if (nUsedBytes >= 1u)
    {
    do
    {
        int nSize;
        if (!SERVER_GetServerPacketSize(pPacketBuffer, nUsedBytes, &nSize))
        {
            break;
        }

        D2_ASSERT((unsigned int)nSize <= MAX_MSG_SIZE, 0x129);

        if (nSize > nUsedBytes)
        {
            break;
        }

        D2NetPacketRecStrc* pPacket = (D2NetPacketRecStrc*)FOG_Alloc(sizeof(D2NetPacketRecStrc), ".\\SRC\\Client.cpp", 0x12C, 0);
        pPacket->nPacketSize = nSize;
        pPacket->dwTickCount = 0;
        pPacket->pNext = 0;

        memcpy(pPacket->data, pPacketBuffer->data, nSize);

        if (pPacketBuffer->data[0] == 0xAF && pPacketBuffer->data[1])
        {
            bResult = 1;

            if (pPacketBuffer->data[1] == 0x81)
            {
                unsigned char abProcessed[0x100];

                const unsigned char* pSource = &pPacketBuffer->data[1];
                unsigned char* pDest = &abProcessed[1];
                int nCount = 0x80;
                do
                {
                    const unsigned char nElement = *pSource;
                    pDest[-1] = (nElement & 0xF) + 1;
                    pDest[0] = (nElement >> 4) + 1;
                    ++pSource;
                    pDest += 2;
                } while (--nCount);

                FOG_10219(abProcessed);
            }
        }
        else if (pPacketBuffer->data[0] == 0x8F)
        {
            *(unsigned long*)&pPacket->data[13] = GetTickCount();
        }

        D2NetPacketRecStrc** ppLast;
        if (pPacketBuffer->data[0] < 0xAF)
        {
            ppLast = &gpGamePacketList;
        }
        else
        {
            ppLast = &gpSystemPacketList;
        }

        while (*ppLast)
        {
            ppLast = &(*ppLast)->pNext;
        }
        *ppLast = pPacket;

        pPacketBuffer = (D2PacketBufferStrc*)((char*)pPacketBuffer + nSize);
        nUsedBytes -= nSize;
    } while (nUsedBytes >= 1u);
    }

    D2PacketBufferStrc* pEnd = gpPacketBuffer;
    pEnd->nUsedBytes = nUsedBytes;

    if (nUsedBytes && pPacketBuffer != pEnd)
    {
        memmove(pEnd, pPacketBuffer, nUsedBytes);
    }

    return bResult;
}

// 0x0052AAA0
void __cdecl sub_0052AAA0_OnSocketError()
{
    WSAGetLastError();
    sub_0052AAD0_ClearConnected();
}

// 0x0052AAD0
void __cdecl sub_0052AAD0_ClearConnected()
{
    if (!NET_IsLocalConnection())
    {
        EnterCriticalSection(&gCriticalSection);
        gbConnected_00882D04 = 0;
        LeaveCriticalSection(&gCriticalSection);
    }
}

D2PacketBufferStrc* gpPacketBuffer; // 0x00882B34

D2CriticalSectionStrc gCriticalSection; // 0x00882CE8

int gdwGlobal_00882D00; // 0x00882D00

int gbConnected_00882D04; // 0x00882D04

// 0x0052AB00
unsigned long __stdcall sub_0052AB00(void* pArg)
{
    int bPacketAE = 0;
    unsigned int nUsed = 0;
    unsigned char pBuffer[2496];

    for (;;)
    {
        if (gdwGlobal_00882D00)
        {
            OutputDebugStringA("Client thread close #2\n");
            return 0;
        }

        D2FdSetStrc tRead;
        tRead.fd_array[0] = gClientSocket;
        tRead.fd_count = 1;

        D2TimevalStrc tTimeout;
        tTimeout.tv_sec = 0;
        tTimeout.tv_usec = 100000;

        int nResult = select(0x40, &tRead, 0, 0, &tTimeout);
        if (nResult)
        {
            if (nResult == -1)
            {
                WSAGetLastError();
                if (!NET_IsLocalConnection())
                {
                    EnterCriticalSection(&gCriticalSection);
                    gbConnected_00882D04 = 0;
                    LeaveCriticalSection(&gCriticalSection);
                }
            }
            else if (__WSAFDIsSet(gClientSocket, &tRead))
            {
                if (gdwGlobal_00882D00)
                {
                    OutputDebugStringA("Client thread close #3\n");
                    return 0;
                }

                EnterCriticalSection(&gCriticalSection);
                if (bPacketAE)
                {
                    nResult = recv(gClientSocket, (char*)&pBuffer[nUsed], 1460, 0);
                    if (nResult > 0)
                    {
                        nUsed += nResult;

                        int nOffset = 0;
                        while (nUsed >= 2)
                        {
                            unsigned char nFirst = pBuffer[nOffset];
                            unsigned int nSize;
                            if (nFirst < 0xF0u)
                                nSize = nFirst;
                            else
                                nSize = pBuffer[nOffset + 1] + ((nFirst & 0xF) << 8);

                            if (nUsed < nSize)
                                break;

                            const int nHeader = nSize < 0xF0 ? 1 : 2;
                            const int nBufUsed = gpPacketBuffer->nUsedBytes;
                            nResult = sub_0040B260(&gpPacketBuffer->data[nBufUsed], int(sizeof(gpPacketBuffer->data) - nBufUsed), &pBuffer[nHeader + nOffset], nSize - nHeader);
                            nUsed -= nSize;
                            nOffset += nSize;
                            if (nResult > 0)
                            {
                                gpPacketBuffer->nUsedBytes += nResult;
                                sub_0052A8D0();
                            }
                        }

                        if (nUsed && nOffset)
                            memmove(pBuffer, &pBuffer[nOffset], nUsed);
                    }
                }
                else
                {
                    nResult = recv(gClientSocket, (char*)&gpPacketBuffer->data[gpPacketBuffer->nUsedBytes], 1460, 0);
                    if (nResult > 0)
                    {
                        gpPacketBuffer->nUsedBytes += nResult;
                        bPacketAE = sub_0052A8D0();
                    }
                }
                LeaveCriticalSection(&gCriticalSection);

                if (nResult == -1)
                {
                    WSAGetLastError();
                    if (!NET_IsLocalConnection())
                    {
                        EnterCriticalSection(&gCriticalSection);
                        gbConnected_00882D04 = 0;
                        LeaveCriticalSection(&gCriticalSection);
                    }
                    OutputDebugStringA("Client thread close #5\n");
                    return 0;
                }

                if (!nResult)
                {
                    if (!NET_IsLocalConnection())
                    {
                        EnterCriticalSection(&gCriticalSection);
                        gbConnected_00882D04 = 0;
                        LeaveCriticalSection(&gCriticalSection);
                    }
                    OutputDebugStringA("Client thread close #6\n");
                    return 0;
                }
            }
        }
    }
}

// 0x0052ADC0
int __fastcall sub_0052ADC0_SendToServerChecked(void* pUnused, unsigned short nSize, const unsigned char* pBuffer)
{
    D2_ASSERT(nSize <= 0x204, 0x1C6);
    return sub_0052B690_SendToServer(pBuffer, nSize);
}

// 0x0052AE00
static __declspec(noinline) int sub_0052AE00_SendToSocket(const unsigned char* pBuffer, int nSize)
{
    const int nSent = send(gClientSocket, (const char*)pBuffer, nSize, 0);
    if (nSent != -1)
    {
        return nSent;
    }

    WSAGetLastError();
    if (!NET_IsLocalConnection())
    {
        EnterCriticalSection(&gCriticalSection);
        gbConnected_00882D04 = 0;
        LeaveCriticalSection(&gCriticalSection);
    }
    return 0;
}

// 0x0052AE50
int __stdcall sub_0052AE50_SendPacket(int nSize, int nFlags, void* pData)
{
    const unsigned char* pBuffer = (const unsigned char*)pData;
    if (!gpPacketBuffer)
    {
        return 0;
    }

    if (NET_IsLocalConnection())
    {
        const unsigned short nPacketSize = nSize;
        D2_ASSERT(nPacketSize <= MAX_MSG_SIZE, 0x1C6);
        return sub_0052B690_SendToServer(pBuffer, nPacketSize);
    }

    return sub_0052AE00_SendToSocket(pBuffer, nSize);
}

#include "gen/data/Source/D2Net/SRC/Client.inc"

D2NetPacketRecStrc* gpGamePacketList; // 0x00882CE4

D2NetPacketRecStrc* gpSystemPacketList; // 0x00882CDC

// 0x0052AEB0
void __fastcall CLIENT_ReadPacketFromBuffer(D2PacketBufferStrc* pBuffer, int nBufferSize)
{
    while (nBufferSize > 0)
    {
        D2NetPacketRecStrc* pPacket = (D2NetPacketRecStrc*)FOG_Alloc(sizeof(D2NetPacketRecStrc), ".\\SRC\\Client.cpp", 0x1FD, 0);

        int nSize;
        if (!SERVER_GetServerPacketSize(pBuffer, nBufferSize, &nSize))
        {
            break;
        }

        D2_ASSERT((unsigned int)nSize <= MAX_MSG_SIZE, 0x203);
        D2_ASSERT(nSize > 0, 0x204);

        memcpy(pPacket->data, pBuffer->data, nSize);

        pPacket->nPacketSize = nSize;
        pPacket->dwTickCount = GetTickCount();
        pPacket->pNext = 0;

        const unsigned char nHeader = pBuffer->data[0];
        D2NetPacketRecStrc* pLast;
        if (nHeader < 0xAF)
        {
            pLast = gpGamePacketList;
        }
        else if (nHeader < 0xB5)
        {
            pLast = gpSystemPacketList;
        }
        else
        {
            D2_ASSERT(0, 0x217);
        }

        if (!pLast)
        {
            if (nHeader < 0xAF)
            {
                gpGamePacketList = pPacket;
            }
            else if (nHeader < 0xB5)
            {
                gpSystemPacketList = pPacket;
            }
            else
            {
                D2_ASSERT(0, 0x21E);
            }
        }
        else
        {
            while (pLast->pNext)
            {
                pLast = pLast->pNext;
            }
            pLast->pNext = pPacket;
        }

        pBuffer = (D2PacketBufferStrc*)((char*)pBuffer + nSize);
        nBufferSize -= nSize;
    }
}

// 0x0052B1F0
int __stdcall sub_0052B1F0_ObjectCall_6BE4E0(int nArg1)
{
    return sub_006BE4E0(gpServer, nArg1);
}

// 0x0052B210
int __stdcall sub_0052B210_ObjectCall_6BE390(int nArg1, int nArg2)
{
    return sub_006BE390(gpServer, nArg1, nArg2);
}

// 0x0052B230
int __stdcall sub_0052B230_ObjectCall_6BF610(int nArg1, int nArg2)
{
    return sub_006BF610(gpServer, nArg2, nArg1);
}

// 0x0052B250
void __stdcall sub_0052B250_ObjectCall_6BE4A0(int nArg1)
{
    sub_006BE4A0(gpServer, nArg1);
}

// 0x0052B280
int __stdcall sub_0052B280_ObjectCall_6BF4E0(int nArg1)
{
    return sub_006BF4E0(gpServer, nArg1);
}

// 0x0052B2A0
void __cdecl sub_0052B2A0_SendCloseAndClear()
{
    unsigned char nMessage = 0xB0;
    sub_006C0170(gpServer, &nMessage, 1);
    gpServer = 0;
}

// 0x0052B2D0
int __stdcall sub_0052B2D0_ObjectCallMode1(int nArg1, int nArg2)
{
    return sub_006BEAD0(gpServer, 1, nArg1, nArg2);
}

// 0x0052B2F0
int __stdcall sub_0052B2F0_ObjectCallMode0(int nArg1, int nArg2)
{
    return sub_006BEAD0(gpServer, 0, nArg1, nArg2);
}

// 0x0052B310
int __stdcall sub_0052B310_ObjectCallMode2(int nArg1, int nArg2)
{
    return sub_006BEAD0(gpServer, 2, nArg1, nArg2);
}

// 0x0052B490
int __stdcall sub_0052B490_ObjectCall_6BED90(int nArg1, int nArg2, int nArg3)
{
    return sub_006BED90(gpServer, nArg1, nArg2, nArg3);
}

// 0x0052B4B0
int __stdcall sub_0052B4B0_ObjectCall_6BEE20(int nArg1)
{
    return sub_006BEE20(gpServer, nArg1);
}

// 0x0052B4D0
int __stdcall sub_0052B4D0_ObjectCall_6BEF40(int nArg1)
{
    return sub_006BEF40(gpServer, nArg1);
}

// 0x0052B4F0
int __stdcall sub_0052B4F0(int nArg1, int nArg2, int nArg3)
{
    return sub_006C0530(gpServer, nArg1, nArg2, nArg3);
}

// 0x0052B510
int __stdcall sub_0052B510_ObjectCall_6C0600(int nArg1, int nArg2, int nArg3)
{
    return sub_006C0600(gpServer, nArg1, nArg2, nArg3);
}

// 0x0052B530
int __stdcall sub_0052B530_ObjectCall_6BEFB0(int nArg1, int nArg2, int nArg3)
{
    return sub_006BEFB0(gpServer, nArg1, nArg2, nArg3);
}

// 0x0052B550
int __stdcall sub_0052B550_ObjectCall_6C06D0(int nArg1, int nArg2, int nArg3)
{
    return sub_006C06D0(gpServer, nArg1, nArg2, nArg3);
}
