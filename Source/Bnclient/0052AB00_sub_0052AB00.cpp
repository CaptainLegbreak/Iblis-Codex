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

struct D2PacketBufferStrc
{
    unsigned char data[1976];
    int nUsedBytes;
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText);                     // 0x006CC200
extern "C" int __stdcall WSAGetLastError();                                                                 // 0x006B0168
extern "C" int __stdcall recv(unsigned int nSocket, char* pBuffer, int nLength, int nFlags);                // 0x006B0174
extern "C" int __stdcall __WSAFDIsSet(unsigned int nSocket, D2FdSetStrc* pSet);                            // 0x006B0180
extern "C" int __stdcall select(int nCount, D2FdSetStrc* pRead, D2FdSetStrc* pWrite, D2FdSetStrc* pExcept, const D2TimevalStrc* pTimeout); // 0x006B0186
extern "C" void* __cdecl memmove(void* pDst, const void* pSrc, unsigned int nSize);                         // 0x00683840

int __fastcall sub_0040B260(unsigned char* pOut, int nOutSize, const unsigned char* pIn, unsigned int nInSize); // 0x0040B260
int __stdcall sub_0052A8D0();                                                               // 0x0052A8D0
int __fastcall NET_IsLocalConnection();                                                                     // 0x0052B7E0

extern int gClientSocket;                                                                                   // 0x00730AE0
D2PacketBufferStrc* gpPacketBuffer;                                                                         // 0x00882B34
D2CriticalSectionStrc gCriticalSection;                                                                     // 0x00882CE8
int gdwGlobal_00882D00;                                                                                     // 0x00882D00
int gbConnected_00882D04;                                                                                   // 0x00882D04

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

#include "gen/data/Source/Bnclient/0052AB00_sub_0052AB00.inc"
