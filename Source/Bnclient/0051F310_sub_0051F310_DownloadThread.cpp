struct D2CriticalSectionStrc;

struct D2FileTimeStrc
{
    unsigned long dwLowDateTime;
    unsigned long dwHighDateTime;
};

struct D2BnDownloadRecordStrc
{
    unsigned short nSize;
    char nUnk0x02;
    char nUnk0x03;
    unsigned int dwPlatform;
    unsigned int dwProduct;
    unsigned int nArg1;
    unsigned int nArg2;
    unsigned int nOffset;
    D2FileTimeStrc tFileTime;
    char szFile[0x104];
    char szLink[0x104];
    int nType;
    int nSubType;
};

struct D2BnDownloadReplyStrc
{
    unsigned int nSize;
    unsigned int nTotal;
    unsigned int nArg1;
    unsigned int nArg2;
    D2FileTimeStrc tFileTime;
    char szFile[1];
};

struct D2InAddrStrc
{
    unsigned long s_addr;
};

struct D2SockAddrInStrc
{
    short sin_family;
    unsigned short sin_port;
    D2InAddrStrc sin_addr;
    char sin_zero[8];
};

extern "C" __declspec(dllimport) int __stdcall SetFileTime(void* hFile, const D2FileTimeStrc* pCreation, const D2FileTimeStrc* pAccess, const D2FileTimeStrc* pWrite); // 0x006CC3A8
extern "C" __declspec(dllimport) int __stdcall GetFileTime(void* hFile, __int64* pCreation, __int64* pAccess, __int64* pWrite); // 0x006CC2F4
extern "C" __declspec(dllimport) unsigned long __stdcall GetFileSize(void* hFile, unsigned long* pHigh); // 0x006CC2F0
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds); // 0x006CC258
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pSection); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pSection); // 0x006CC214
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* pValue); // 0x006CC204
extern "C" int __stdcall connect(unsigned int nSocket, const D2SockAddrInStrc* pName, int nLength); // 0x006B014A
extern "C" unsigned long __stdcall inet_addr(const char* szAddress); // 0x006B0150
extern "C" unsigned short __stdcall htons(unsigned short nValue); // 0x006B0156
extern "C" int __stdcall setsockopt(unsigned int nSocket, int nLevel, int nName, const char* pValue, int nLength); // 0x006B0162
extern "C" unsigned int __stdcall socket(int nFamily, int nType, int nProtocol); // 0x006B016E
extern "C" int __stdcall recv(unsigned int nSocket, char* pBuffer, int nLength, int nFlags); // 0x006B0174
extern "C" int __stdcall send(unsigned int nSocket, const char* pBuffer, int nLength, int nFlags); // 0x006B017A
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern "C" char* __cdecl strtok(char* szText, const char* szDelim); // 0x0068264F
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

void* __fastcall sub_00406960_CreateFile(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x00406960
int __fastcall sub_004069A0_CloseFile(void* hFile); // 0x004069A0
int __fastcall sub_004069D0_WriteFile(void* hFile, const void* pBuffer, unsigned long nToWrite, unsigned long* pnWritten, void* pOverlapped); // 0x004069D0
unsigned long __fastcall sub_004069F0_SetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod); // 0x004069F0
int __fastcall sub_0040D880(unsigned int s); // 0x0040D880
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650
void __fastcall sub_00519DB0_HandOnDownload(const char* szFile, const void* pData, unsigned int nSize, const D2FileTimeStrc* pFileTime, int nArg5, int nArg6); // 0x00519DB0
void __cdecl sub_0051A480_DebugLog(const char* szFormat, ...); // 0x0051A480
void __fastcall sub_0051C0E0_ResolveHost(char* szResult, const char* szHost); // 0x0051C0E0
void __fastcall sub_0051C190(char* szText, int nSize); // 0x0051C190
int __fastcall sub_0051C9B0_GetPeerName(void* pAddress, int* pnLength); // 0x0051C9B0
void __fastcall sub_0051FAB0_HandleDownloadEvent(int nType, int nSubType, unsigned int nArg1, unsigned int nArg2, const D2FileTimeStrc* pFileTime, const char* szText1, const char* szText2, const void* pData, unsigned int nDataSize, int bFlag); // 0x0051FAB0

extern unsigned int gnPercent_00881C50; // 0x00881C50
extern int gbStopDownload_00881C54; // 0x00881C54
extern "C" long gnPendingCount_00881D5C; // 0x00881D5C
extern char gszAdList_00881D60[]; // 0x00881D60
extern D2CriticalSectionStrc gDownloadLock_00881F64; // 0x00881F64
extern "C" const char gszBnDownloadFile_006DF338[]; // 0x006DF338
extern "C" const char gszRecvToBufferFailed_006DF380[]; // 0x006DF380
extern "C" const char gszEmptyAssertText; // 0x006CC837

static __declspec(noinline) void __stdcall sub_0051E440_WriteFileWithTime(const void* pData, unsigned int nSize, const char* szFile, const D2FileTimeStrc* pFileTime);
static __declspec(noinline) int __stdcall sub_0051E5F0_RecvAll(unsigned int nSocket, char* pBuffer, unsigned int nSize);
static __declspec(noinline) unsigned long sub_0051E640_GetFileSizeIfTimeMatches(const char* szFile, const __int64* pFileTime);
static __declspec(noinline) int __stdcall sub_0051EAB0_RecvToBuffer(unsigned int nSocket, const char* szFile, const D2FileTimeStrc* pFileTime, int nType, int nFlags, char** ppBuffer, unsigned int nSize);
static __declspec(noinline) int __stdcall sub_0051EBB0_RecvToFile(unsigned int nSocket, const char* szFile, const D2FileTimeStrc* pFileTime, unsigned int nOffset, unsigned int nTotal, int nType);

// 0x0051E440
static void __stdcall sub_0051E440_WriteFileWithTime(const void* pData, unsigned int nSize, const char* szFile, const D2FileTimeStrc* pFileTime)
{
    unsigned long nWritten;
    void* hFile = sub_00406960_CreateFile(szFile, 0x40000000, 0, 0, 2, 0x80, 0);
    if (hFile != (void*)-1)
    {
        sub_004069D0_WriteFile(hFile, pData, nSize, &nWritten, 0);
        SetFileTime(hFile, pFileTime, pFileTime, pFileTime);
        sub_004069A0_CloseFile(hFile);
    }
}

// 0x0051E5F0
static int __stdcall sub_0051E5F0_RecvAll(unsigned int nSocket, char* pBuffer, unsigned int nSize)
{
    for (unsigned int nRead = 0; nSize > nRead; )
    {
        const int nResult = recv(nSocket, pBuffer + nRead, nSize - nRead, 0);
        if (nResult == -1 || nResult <= 0)
            return 0;
        nRead += nResult;
    }
    return 1;
}

// 0x0051E640
static unsigned long sub_0051E640_GetFileSizeIfTimeMatches(const char* szFile, const __int64* pFileTime)
{
    void* hFile = sub_00406960_CreateFile(szFile, 0x80000000, 3, 0, 3, 0x8000000, 0);
    if (hFile == (void*)-1)
        return 0;

    __int64 nWriteTime;
    GetFileTime(hFile, 0, 0, &nWriteTime);
    __int64 nDiff = nWriteTime - *pFileTime;
    if (nDiff < 0)
        nDiff = -nDiff;
    const unsigned __int64 nAbs = nDiff;

    if (!(unsigned long)(nAbs >> 32) && (unsigned long)nAbs <= 40000000)
    {
        const unsigned long nFileSize = GetFileSize(hFile, 0);
        sub_004069A0_CloseFile(hFile);
        return nFileSize;
    }

    sub_004069A0_CloseFile(hFile);
    return 0;
}

// 0x0051EAB0
static int __stdcall sub_0051EAB0_RecvToBuffer(unsigned int nSocket, const char* szFile, const D2FileTimeStrc* pFileTime, int nType, int nFlags, char** ppBuffer, unsigned int nSize)
{
    *ppBuffer = (char*)SMemAlloc(nSize, gszBnDownloadFile_006DF338, 0x385, 8);
    for (unsigned int nRead = 0; nRead < nSize; )
    {
        unsigned int nChunk = nSize - nRead;
        if (nChunk > 0x5B4)
            nChunk = 0x5B4;

        const int nResult = recv(nSocket, *ppBuffer + nRead, nChunk, 0);
        if (nResult == -1 || nResult <= 0 || gbStopDownload_00881C54)
        {
            SMemFree(*ppBuffer, gszBnDownloadFile_006DF338, 0x38F, 0);
            *ppBuffer = 0;
            sub_0051A480_DebugLog(gszRecvToBufferFailed_006DF380, szFile, nSize, nRead, nResult);
            return 0;
        }

        nRead += nResult;
        if (nType == 0x80000002)
            gnPercent_00881C50 = nRead * 100 / nSize;
    }

    if (nFlags & 1)
        sub_00519DB0_HandOnDownload(szFile, *ppBuffer, nSize, pFileTime, 0x13C680, 0x278D00);

    if (nFlags & 2)
        sub_0051E440_WriteFileWithTime(*ppBuffer, nSize, szFile, pFileTime);

    return 1;
}

// 0x0051EBB0
static int __stdcall sub_0051EBB0_RecvToFile(unsigned int nSocket, const char* szFile, const D2FileTimeStrc* pFileTime, unsigned int nOffset, unsigned int nTotal, int nType)
{
    char szBuffer[0x5B4];
    unsigned long nWritten;

    void* hFile = sub_00406960_CreateFile(szFile, 0x40000000, 0, 0, 4, 0x80, 0);
    if (hFile == (void*)-1)
        return 0;

    if (nOffset)
        sub_004069F0_SetFilePointer(hFile, nOffset, 0, 0);

    if (nType == 0x80000002)
    {
        gnPercent_00881C50 = nOffset * 100 / nTotal;
        Sleep(0);
    }

    while (nOffset < nTotal)
    {
        unsigned int nChunk = nTotal - nOffset;
        if (nChunk > 0x5B4)
            nChunk = 0x5B4;

        const int nResult = recv(nSocket, szBuffer, nChunk, 0);
        if (nResult == -1 || nResult <= 0 || gbStopDownload_00881C54)
        {
            sub_004069A0_CloseFile(hFile);
            return 0;
        }

        sub_004069D0_WriteFile(hFile, szBuffer, nResult, &nWritten, 0);
        SetFileTime(hFile, pFileTime, pFileTime, pFileTime);
        nOffset += nResult;
        if (nType == 0x80000002)
            gnPercent_00881C50 = nOffset * 100 / nTotal;
    }

    sub_004069A0_CloseFile(hFile);
    return 1;
}

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x0051F310
unsigned int __stdcall sub_0051F310_DownloadThread(void* pArg)
{
    D2BnDownloadRecordStrc* pRecord = (D2BnDownloadRecordStrc*)pArg;
    char* pBuffer = 0;
    D2BnDownloadReplyStrc* pReply = 0;
    char* szToken = 0;
    int nRetry = 0;
    int bRetryFailed = 0;
    char szHost[0x200];
    char szIp[0x100];
    D2SockAddrInStrc tAddr;
    int nAddrLen;
    unsigned int nSocket;
    int nKeepAlive;
    int nTimeout;
    char nCommand;
    D2BnDownloadRecordStrc tRecord;
    unsigned int nSize;
    unsigned int nFileSize;

    szHost[0] = 0;
    gbStopDownload_00881C54 = 0;
    nAddrLen = sizeof(tAddr);
    if (!sub_0051C9B0_GetPeerName(&tAddr, &nAddrLen))
    {
        sub_0051C190(szIp, sizeof(szIp));
        sub_0051C0E0_ResolveHost(szHost, szIp);
        szToken = strtok(szHost, " ,;");
        memset(&tAddr, 0, sizeof(tAddr));
        tAddr.sin_family = 2;
        tAddr.sin_port = htons(6112);
        tAddr.sin_addr.s_addr = inet_addr(szToken);
    }
    else
    {
        tAddr.sin_port = htons(6112);
        memset(tAddr.sin_zero, 0, sizeof(tAddr.sin_zero));
    }

    nSocket = socket(2, 1, 0);
    if (nSocket != (unsigned int)-1)
    for (;;)
    {
        if (connect(nSocket, &tAddr, sizeof(tAddr)) == -1)
        {
            if (gbStopDownload_00881C54 || pRecord->nType != 0x80000002)
            {
                sub_0051A480_DebugLog("Canceled download.");
                break;
            }

            sub_0040D880(nSocket);
            nSocket = (unsigned int)-1;
            if (++nRetry > 3)
            {
                bRetryFailed = 1;
                goto next;
            }

            sub_0051A480_DebugLog("WARNING: Failed to connect to download port. Retrying...");
            Sleep(1000);
            if (szHost[0])
            {
                if (!szToken)
                    szToken = strtok(szHost, " ,;");
                else
                    szToken = strtok(0, " ,;");
            }

            if (!szToken)
                break;

            tAddr.sin_addr.s_addr = inet_addr(szToken);
            goto next;
        }

        nKeepAlive = 1;
        setsockopt(nSocket, 0xFFFF, 8, (const char*)&nKeepAlive, sizeof(nKeepAlive));
        nTimeout = 15000;
        setsockopt(nSocket, 0xFFFF, 0x1006, (const char*)&nTimeout, sizeof(nTimeout));

        nCommand = 2;
        if (send(nSocket, &nCommand, 1, 0) != 1)
        {
            sub_0051A480_DebugLog("ERROR: Failed send to BNET for download.");
            break;
        }

        tRecord = *pRecord;
        if (send(nSocket, (const char*)&tRecord, pRecord->nSize, 0) != pRecord->nSize)
        {
            sub_0051A480_DebugLog("ERROR: Failed send to BNET for download.");
            break;
        }

        nSize = 0;
        for (unsigned int nRead = 0; nRead < 4; )
        {
            const int nResult = recv(nSocket, (char*)&nSize + nRead, 4 - nRead, 0);
            if (nResult == -1 || nResult <= 0)
            {
                sub_0051A480_DebugLog("ERROR: Failed send to BNET for download.");
                goto done;
            }
            nRead += nResult;
        }

        D2_ASSERT(nSize < 0x100, 750);
        pReply = (D2BnDownloadReplyStrc*)SMemAlloc(nSize, gszBnDownloadFile_006DF338, 751, 0);
        if (!pReply)
            break;

        if (!sub_0051E5F0_RecvAll(nSocket, (char*)pReply + 4, nSize - 4))
        {
            sub_0051A480_DebugLog("ERROR: Failed recv from BNET for download.");
            break;
        }

        if (gbStopDownload_00881C54)
        {
            sub_0051A480_DebugLog("Canceled download(2).");
            break;
        }

        if (pRecord->nSubType == 2)
        {
            nFileSize = sub_0051E640_GetFileSizeIfTimeMatches(pReply->szFile, (const __int64*)&pReply->tFileTime);
            if (nFileSize != pRecord->nOffset)
            {
                pRecord->nOffset = nFileSize;
                sub_0040D880(nSocket);
                SMemFree(pReply, gszBnDownloadFile_006DF338, 785, 0);
                pReply = 0;
                goto next;
            }

            if (gbStopDownload_00881C54)
            {
                sub_0051A480_DebugLog("Canceled download(3).");
                break;
            }
        }

        if (pRecord->nSubType == 2)
        {
            if (!sub_0051EBB0_RecvToFile(nSocket, pReply->szFile, &pReply->tFileTime, pRecord->nOffset, pReply->nTotal, pRecord->nType))
            {
                if (gbStopDownload_00881C54)
                {
                    sub_0051A480_DebugLog("ERROR: Cancelled download.");
                    break;
                }

                sub_0040D880(nSocket);
                SMemFree(pReply, gszBnDownloadFile_006DF338, 817, 0);
                pReply = 0;
                sub_0051A480_DebugLog("WARNING: Failed to save to disk.");
                goto next;
            }
        }
        else
        {
            if (!sub_0051EAB0_RecvToBuffer(nSocket, pReply->szFile, &pReply->tFileTime, pRecord->nType, pRecord->nSubType, &pBuffer, pReply->nTotal))
            {
                if (gbStopDownload_00881C54)
                {
                    sub_0051A480_DebugLog("ERROR: Cancelled download(2).");
                    break;
                }

                sub_0040D880(nSocket);
                SMemFree(pReply, gszBnDownloadFile_006DF338, 844, 0);
                pReply = 0;
                sub_0051A480_DebugLog("ERROR: Failed to copy file.");
                goto next;
            }
        }

        sub_0051FAB0_HandleDownloadEvent(pRecord->nType, pRecord->nSubType, pReply->nArg1, pReply->nArg2, &pReply->tFileTime, pReply->szFile, pRecord->szLink, pBuffer, pReply->nTotal, 0);
        break;

next:
        if (bRetryFailed)
        {
            sub_0051A480_DebugLog("ERROR: Failed recv from BNET for download.");
            break;
        }

        nSocket = socket(2, 1, 0);
        if (nSocket == (unsigned int)-1)
            break;
    }

done:
    const int nFinalType = pRecord->nType;
    if (nSocket != (unsigned int)-1)
        sub_0040D880(nSocket);

    if (pBuffer)
        SMemFree(pBuffer, gszBnDownloadFile_006DF338, 870, 0);

    if (pReply)
        SMemFree(pReply, gszBnDownloadFile_006DF338, 871, 0);

    SMemFree(pRecord, gszBnDownloadFile_006DF338, 872, 0);
    if (nFinalType == 0x80000002 && gnPercent_00881C50 < 100)
    {
        EnterCriticalSection(&gDownloadLock_00881F64);
        gszAdList_00881D60[0] = 0;
        gszAdList_00881D60[1] = 0;
        gnPercent_00881C50 = 101;
        LeaveCriticalSection(&gDownloadLock_00881F64);
    }

    InterlockedDecrement(&gnPendingCount_00881D5C);
    return 0;
}
