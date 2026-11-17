#include "D2Net.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2NetPacketRecStrc;
struct D2PacketBufferStrc;
struct D2FdSetStrc;
struct D2TimevalStrc;

typedef unsigned int size_t;
extern "C" void* __cdecl memcpy(void* pDest, const void* pSource, size_t nSize); // 0x006829C0
extern "C" void* __cdecl memmove(void* pDest, const void* pSource, size_t nSize); // 0x00683840
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260
static const unsigned int MAX_MSG_SIZE = 516;

struct D2NetPacketRecStrc
{
    unsigned char data[MAX_MSG_SIZE];
    int nPacketSize;
    unsigned long dwTickCount;
    D2NetPacketRecStrc* pNext;
};

struct D2PacketBufferStrc
{
    unsigned char data[1976];
    int nUsedBytes;
};

extern D2PacketBufferStrc* gpPacketBuffer; // 0x00882B34
extern D2NetPacketRecStrc* gpGamePacketList; // 0x00882CE4
extern D2NetPacketRecStrc* gpSystemPacketList; // 0x00882CDC
void __fastcall FOG_10219(unsigned char* pData); // 0x0040ADB0
int __fastcall SERVER_GetServerPacketSize(D2PacketBufferStrc* pBuffer, unsigned int nBufferSize, int* pSize); // 0x0052B920

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

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
int __fastcall NET_IsLocalConnection(); // 0x0052B7E0

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

        D2_ASSERT(nSize <= MAX_MSG_SIZE, 0x129);

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

#include "gen/data/Source/D2Net/SRC/Client_0052A8D0.inc"

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

        D2_ASSERT(nSize <= MAX_MSG_SIZE, 0x203);
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
