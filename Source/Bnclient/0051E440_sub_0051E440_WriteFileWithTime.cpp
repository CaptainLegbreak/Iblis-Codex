struct D2CriticalSectionStrc;

struct D2FileTimeStrc
{
    unsigned long dwLowDateTime;
    unsigned long dwHighDateTime;
};

struct D2BnDownloadRecordStrc
{
    unsigned short nSize;
    char f_2;
    char f_3;
    unsigned int dwPlatform;
    unsigned int dwProduct;
    unsigned int nArg1;
    unsigned int nArg2;
    int nUnk0x14;
    D2FileTimeStrc tFileTime;
    char szFile[0x104];
    char szLink[0x104];
    int nType;
    int nSubType;
};

extern "C" __declspec(dllimport) int __stdcall SetFileTime(void* hFile, const D2FileTimeStrc* pCreation, const D2FileTimeStrc* pAccess, const D2FileTimeStrc* pWrite); // 0x006CC3A8
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);                        // 0x006CC258
extern "C" int __stdcall recv(unsigned int nSocket, char* pBuffer, int nLength, int nFlags);                // 0x006B0174
extern "C" __declspec(dllimport) int __stdcall CompareFileTime(const D2FileTimeStrc* pTime1, const D2FileTimeStrc* pTime2); // 0x006CC390
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pSection);      // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pSection);      // 0x006CC214
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* pValue);                // 0x006CC208
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134
extern "C" unsigned int __cdecl _beginthreadex(void* pSecurity, unsigned int nStackSize, unsigned int (__stdcall* pfnStart)(void*), void* pArg, unsigned int nFlags, unsigned int* pThreadId); // 0x00688103
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" unsigned int __cdecl strlen(const char* sz);

void* __fastcall sub_00406960_CreateFile(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x00406960
int __fastcall sub_004069A0_CloseFile(void* hFile);                                                         // 0x004069A0
int __fastcall sub_004069D0_WriteFile(void* hFile, const void* pBuffer, unsigned long nToWrite, unsigned long* pnWritten, void* pOverlapped); // 0x004069D0
unsigned long __fastcall sub_004069F0_SetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod); // 0x004069F0
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650
void __fastcall sub_00519DB0_HandOnDownload(const char* szFile, const void* pData, unsigned int nSize, const D2FileTimeStrc* pFileTime, int nArg5, int nArg6); // 0x00519DB0
void __cdecl sub_0051A480_DebugLog(const char* szFormat, ...);                                              // 0x0051A480
int __fastcall FOG_SOCKET_WSAStartup();                                                                     // 0x0040D890
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize);                              // 0x0041D2A0
int __stdcall SRegSaveData(const char* szKeyName, const char* szValueName, unsigned int nFlags, const void* pData, unsigned int nSize); // 0x00415000
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
int __fastcall sub_00519920_LoadCachedFile(const char* szFile, D2FileTimeStrc* pFileTime, void** ppData, unsigned int* pnSize); // 0x00519920
void __fastcall sub_005193C0_FreeCachedFile(void* pData, unsigned int nSize);                               // 0x005193C0
void __fastcall sub_0051FAB0_HandleDownloadEvent(int nType, int nSubType, unsigned int nArg1, unsigned int nArg2, const D2FileTimeStrc* pFileTime, const char* szText1, const char* szText2, const void* pData, unsigned int nDataSize, int bFlag); // 0x0051FAB0
unsigned int __stdcall sub_0051F310_DownloadThread(void* pArg);                                             // 0x0051F310

unsigned int gnPercent_00881C50;                                                                            // 0x00881C50
int gbStopDownload_00881C54;                                                                                // 0x00881C54
extern "C" const char gszBnDownloadFile_006DF338[];                                                         // 0x006DF338
extern "C" const char gszAdListRegKey_006DF45C[];                                                           // 0x006DF45C
extern "C" const char gszAdListRegValue_006DF464[];                                                         // 0x006DF464
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern D2CriticalSectionStrc gDownloadLock_00881F64;                                                        // 0x00881F64
extern char gszAdList_00881D60[];                                                                           // 0x00881D60
extern "C" { long gnPendingCount_00881D5C; }                                                                // 0x00881D5C

// 0x0051E440
static __declspec(noinline) void __stdcall sub_0051E440_WriteFileWithTime(const void* pData, unsigned int nSize, const char* szFile, const D2FileTimeStrc* pFileTime)
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
static __declspec(noinline) int __stdcall sub_0051E5F0_RecvAll(unsigned int nSocket, char* pBuffer, unsigned int nSize)
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

// 0x0051EAB0
static __declspec(noinline) int __stdcall sub_0051EAB0_RecvToBuffer(unsigned int nSocket, const char* szFile, const D2FileTimeStrc* pFileTime, int nType, unsigned char nFlags, char** ppBuffer, unsigned int nSize)
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
            sub_0051A480_DebugLog("<ERROR: Failed to recv file  %s in DOWNLOADTOANY, filebytes = %ld, currpos = %ld, bytes = %d", szFile, nSize, nRead, nResult);
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
static __declspec(noinline) int __stdcall sub_0051EBB0_RecvToFile(unsigned int nSocket, unsigned int nOffset, unsigned int nTotal, int nType, const char* szFile, const D2FileTimeStrc* pFileTime)
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

// 0x0051F910
void __fastcall sub_0051F910_Report(int nType, int nSubType, unsigned int nArg1, unsigned int nArg2, const D2FileTimeStrc* pFileTime, const char* szFile, const char* szLink)
{
    if (!szFile || !*szFile)
        return;

    if (!szLink)
        szLink = &gszEmptyAssertText;

    D2FileTimeStrc tCachedTime;
    void* pData;
    unsigned int nSize;
    if (sub_00519920_LoadCachedFile(szFile, &tCachedTime, &pData, &nSize))
    {
        if (!CompareFileTime(pFileTime, &tCachedTime))
        {
            if (nSubType & 2)
                sub_0051E440_WriteFileWithTime(pData, nSize, szFile, pFileTime);

            sub_0051FAB0_HandleDownloadEvent(nType, nSubType, nArg1, nArg2, pFileTime, szFile, szLink, pData, nSize, 1);
            sub_005193C0_FreeCachedFile(pData, nSize);
            return;
        }
        sub_005193C0_FreeCachedFile(pData, nSize);
    }

    D2BnDownloadRecordStrc* pRecord = (D2BnDownloadRecordStrc*)SMemAlloc(0x230, gszBnDownloadFile_006DF338, 0xA6, 0);
    if (!pRecord)
        return;

    memset(pRecord, 0, 0x230);
    pRecord->nSize = (unsigned short)(strlen(szFile) + 0x21);
    pRecord->f_2 = 0;
    pRecord->f_3 = 1;
    pRecord->dwPlatform = 0x49583836;
    pRecord->dwProduct = 0x44324456;
    pRecord->nArg1 = nArg1;
    pRecord->nArg2 = nArg2;
    pRecord->nUnk0x14 = 0;
    pRecord->nType = nType;
    pRecord->nSubType = nSubType;
    pRecord->tFileTime = *pFileTime;
    SStrCopy(pRecord->szFile, szFile, 0x104);
    SStrCopy(pRecord->szLink, szLink, 0x104);
    InterlockedIncrement(&gnPendingCount_00881D5C);

    unsigned int nThreadId;
    void* hThread = (void*)_beginthreadex(0, 0, sub_0051F310_DownloadThread, pRecord, 0, &nThreadId);
    if (hThread)
        CloseHandle(hThread);
}

// 0x00520020
int __fastcall sub_00520020_SetAdList(const char* szText, int nLen)
{
    if (!FOG_SOCKET_WSAStartup())
        return 0;

    gnPercent_00881C50 = 0;
    EnterCriticalSection(&gDownloadLock_00881F64);
    SMemCopy(gszAdList_00881D60, szText, nLen);
    gnPercent_00881C50 = 0;
    LeaveCriticalSection(&gDownloadLock_00881F64);
    SRegSaveData(gszAdListRegKey_006DF45C, gszAdListRegValue_006DF464, 0x82, szText, nLen + 1);

    D2FileTimeStrc tCachedTime;
    D2FileTimeStrc tFileTime;
    unsigned int nThreadId;
    void* pData;
    unsigned int nSize;
    tFileTime.dwLowDateTime = 0;
    tFileTime.dwHighDateTime = 0;
    if (!szText || !*szText)
        return 0;

    if (sub_00519920_LoadCachedFile(szText, &tCachedTime, &pData, &nSize))
    {
        if (!CompareFileTime(&tFileTime, &tCachedTime))
        {
            sub_0051E440_WriteFileWithTime(pData, nSize, szText, &tFileTime);
            sub_0051FAB0_HandleDownloadEvent(0x80000002, 2, 0, 0, &tFileTime, szText, 0, pData, nSize, 1);
            sub_005193C0_FreeCachedFile(pData, nSize);
            return 0;
        }
        sub_005193C0_FreeCachedFile(pData, nSize);
    }

    D2BnDownloadRecordStrc* pRecord = (D2BnDownloadRecordStrc*)SMemAlloc(0x230, gszBnDownloadFile_006DF338, 0x698, 0);
    if (!pRecord)
        return 0;

    memset(pRecord, 0, 0x230);
    pRecord->nSize = (unsigned short)(strlen(szText) + 0x21);
    pRecord->f_2 = 0;
    pRecord->f_3 = 1;
    pRecord->dwPlatform = 0x49583836;
    pRecord->dwProduct = 0x44324456;
    pRecord->nArg1 = 0;
    pRecord->nArg2 = 0;
    pRecord->nUnk0x14 = 0;
    pRecord->nType = 0x80000002;
    pRecord->nSubType = 2;
    pRecord->tFileTime = tFileTime;
    SStrCopy(pRecord->szFile, szText, 0x104);
    SStrCopy(pRecord->szLink, &gszEmptyAssertText, 0x104);
    InterlockedIncrement(&gnPendingCount_00881D5C);
    return _beginthreadex(0, 0, sub_0051F310_DownloadThread, pRecord, 0, &nThreadId);
}

int __fastcall sub_A12_Emit_0051E5F0(unsigned int nSocket, char* pBuffer, unsigned int nSize)
{
    return sub_0051E5F0_RecvAll(nSocket, pBuffer, nSize);
}

int __fastcall sub_A12_Emit_0051EAB0(unsigned int nSocket, const char* szFile, const D2FileTimeStrc* pFileTime, int nType, unsigned char nFlags, char** ppBuffer, unsigned int nSize)
{
    return sub_0051EAB0_RecvToBuffer(nSocket, szFile, pFileTime, nType, nFlags, ppBuffer, nSize);
}

int __fastcall sub_A12_Emit_0051EBB0(unsigned int nSocket, unsigned int nOffset, unsigned int nTotal, int nType, const char* szFile, const D2FileTimeStrc* pFileTime)
{
    return sub_0051EBB0_RecvToFile(nSocket, nOffset, nTotal, nType, szFile, pFileTime);
}
