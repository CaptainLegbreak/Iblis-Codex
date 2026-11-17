struct D2FileTimeStrc
{
    unsigned long dwLowDateTime;
    unsigned long dwHighDateTime;
};

struct D2BnCheckAdReplyStrc
{
    unsigned int nAdId;
    unsigned int nExtension;
    unsigned char pData[1];
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

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* pAddend);              // 0x006CC204
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* pAddend);              // 0x006CC208
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);                       // 0x006CC258
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                               // 0x006CC260
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile* pDestination, long nExchange, long nComparand); // 0x006CC3A0

int __fastcall FOG_SOCKET_Receive(FSafeSock* pSafeSock, char* pBuffer, int nBufferLength);                  // 0x0040DC60
int __fastcall FOG_SOCKET_Select(FSafeSock* pSafeSock);                                                     // 0x0040DDF0
int __fastcall sub_0051C5C0_SendPacket(unsigned char nId, const void* pData, unsigned int nSize);           // 0x0051C5C0
int __fastcall sub_0051C760_SplitPackets(unsigned char* pBuffer, int nLength);                              // 0x0051C760
int __fastcall sub_0051F910_Report(int nType, int nSubType, unsigned int nArg1, unsigned int nArg2, const D2FileTimeStrc* pFileTime, const char* szText1, const char* szText2); // 0x0051F910
void __cdecl sub_00520AD0_SetDisconnected();                                                                // 0x00520AD0
extern "C" unsigned int __cdecl strlen(const char* szString);

extern long volatile gnConnected_00881BF0;                                                                  // 0x00881BF0
long volatile gnReceiveThreads_00881BF4;                                                                    // 0x00881BF4
extern int gbReady_00881BF8;                                                                                // 0x00881BF8
long volatile gnDnsDone_00881BFC;                                                                           // 0x00881BFC
extern unsigned int gnVersion_0088252C;                                                                     // 0x0088252C

// 0x0051C7E0
unsigned long __stdcall sub_0051C7E0_ReceiveThread(void* pParameter)
{
    char aBuffer[0x2000 + 1];
    int nResult = 1;
    if (InterlockedIncrement(&gnReceiveThreads_00881BF4) > 1)
    {
        InterlockedDecrement(&gnReceiveThreads_00881BF4);
        return 1;
    }
    while (!InterlockedCompareExchange(&gnDnsDone_00881BFC, 0, 0) && !gbReady_00881BF8)
        Sleep(10);
    unsigned long dwLastTick = GetTickCount();
    int nUsed = 0;
    FSafeSock* pSafeSock = (FSafeSock*)InterlockedCompareExchange(&gnConnected_00881BF0, 0, 0);
    while (pSafeSock && !pSafeSock->bStopping && !InterlockedCompareExchange(&gnDnsDone_00881BFC, 0, 0))
    {
        const int bReady = FOG_SOCKET_Select(pSafeSock);
        pSafeSock = (FSafeSock*)InterlockedCompareExchange(&gnConnected_00881BF0, 0, 0);
        if (!pSafeSock || pSafeSock->bStopping || InterlockedCompareExchange(&gnDnsDone_00881BFC, 0, 0))
            break;
        if (bReady)
        {
            const int nReceived = FOG_SOCKET_Receive(pSafeSock, &aBuffer[nUsed], 0x2000 - nUsed);
            if (nReceived <= 0)
            {
                sub_00520AD0_SetDisconnected();
                nResult = 0;
                break;
            }
            nUsed = sub_0051C760_SplitPackets((unsigned char*)aBuffer, nReceived + nUsed);
        }
        const unsigned long dwTick = GetTickCount();
        if (dwTick - dwLastTick >= 180000)
        {
            sub_0051C5C0_SendPacket(0, 0, 0);
            dwLastTick = dwTick;
        }
        pSafeSock = (FSafeSock*)InterlockedCompareExchange(&gnConnected_00881BF0, 0, 0);
    }
    InterlockedDecrement(&gnReceiveThreads_00881BF4);
    return nResult;
}

// 0x00521150
int __fastcall sub_00521150(const D2BnCheckAdReplyStrc* pPacket, unsigned int nSize)
{
    const unsigned int nAdId = pPacket->nAdId;
    if (nSize >= 0x11 && nAdId != gnVersion_0088252C)
    {
        const unsigned char* pData = pPacket->pData;
        const char* szFileName = (const char*)(pData + sizeof(D2FileTimeStrc));
        gnVersion_0088252C = nAdId;
        const char* szLink = szFileName + strlen(szFileName) + 1;
        if (*szFileName && *szLink)
            sub_0051F910_Report(0x80000003, 5, nAdId, pPacket->nExtension, (const D2FileTimeStrc*)pData, szFileName, szLink);
    }
    return 1;
}
