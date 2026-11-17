#include "D2BNClient.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CriticalSectionStrc;
struct D2BnStateStrc;
struct D2BnDnsArgsStrc;
struct D2BnLogStrc;
struct D2BnExtraWorkPacketStrc;
struct D2BnAdInfoStrc;
class BNGatewayAccess;
struct D2BnDownloadRecordStrc;
struct D2BnDownloadReplyStrc;
struct D2SockAddrInStrc;
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long* pDestination, long nExchange, long nComparand); // 0x006CC3A0
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230
extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* pAttributes, unsigned long nStackSize, unsigned long (__stdcall* pfnStart)(void*), void* pParameter, unsigned long nFlags, unsigned long* pThreadId); // 0x006CC250
unsigned long __stdcall sub_0051BEE0(void* pArguments); // 0x0051BEE0
void __fastcall sub_0051D260_SelectVersion(int bAlternate); // 0x0051D260
void __fastcall sub_0051AE10_Send(const char* szArg1, const char* szArg2, int nArg3); // 0x0051AE10
void __fastcall sub_0051ACA0_SendString(const char* szText, int nArg2, int nArg3); // 0x0051ACA0
int __fastcall sub_005204A0_SetError(int nError); // 0x005204A0
int __fastcall sub_00520520_SetState(int nState); // 0x00520520

struct D2BnStateStrc
{
    int nState;
    void* pArg;
};

int __fastcall sub_005205F0_GetState(D2BnStateStrc* pState); // 0x005205F0

struct D2BnDnsArgsStrc
{
    char* szResult;
    const char* f_4;
};

struct D2BnMessageStrc
{
    int nId;
    char szText[0x120];
    unsigned int nLength;
    D2BnMessageStrc* pNext;
};

struct D2BnLogStrc
{
    void* hLog;

    void sub_00518BA0_LogWrite(const char* szText);
};

extern int gbDnsPending_008818E0; // 0x008818E0
extern long gnConnected_00881BF0; // 0x00881BF0
extern long gnDnsDone_00881BFC; // 0x00881BFC
extern unsigned int gnPercent_00881C50; // 0x00881C50
extern D2CriticalSectionStrc gMessageLock_00882004; // 0x00882004
extern "C" const char szBnMessQueueFile_006DF78C[]; // 0x006DF78C
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize); // 0x0041D2A0
extern int gbStopDownload_00881C54; // 0x00881C54
extern char gszDownloadArchive_00881C58[]; // 0x00881C58
extern char gszCheckRevisionValue_00881E60[]; // 0x00881E60

struct D2FileTimeStrc
{
    unsigned long dwLowDateTime;
    unsigned long dwHighDateTime;
};

struct D2BnExtraWorkPacketStrc
{
    unsigned short wType;
    unsigned short wSize;
    unsigned int dwLocale;
    unsigned char pData[0xFFC];
};

struct D2BnAdInfoStrc
{
    unsigned int nArg1;
    unsigned int nArg2;
    char* szText1;
    char* szText2;
    void* pData;
    unsigned int nDataSize;
};

class BNGatewayAccess
{
public:
    void __stdcall UpdateGatewaysFromIni(char* szText);                                                     // 0x00518850
    void __stdcall SaveAndUnload();                                                                         // 0x00517ED0

private:
    int unk0x00[9];
};

typedef int (__stdcall* D2CheckRevisionFn)(const char* szFile1, const char* szFile2, const char* szFile3, const char* szValue, int* pVersion, int* pChecksum, char* szExeInfo);

typedef int (__fastcall* D2ExtraWorkFn)(D2BnExtraWorkPacketStrc* pPacket);

extern "C" __declspec(dllimport) unsigned long __stdcall GetTempPathA(unsigned long nBufferLength, char* szBuffer); // 0x006CC344
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern "C" __declspec(dllimport) void* __stdcall GetModuleHandleA(const char* szModuleName); // 0x006CC198
extern "C" __declspec(dllimport) int __stdcall DeleteFileA(const char* lpFileName); // 0x006CC1A0
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" unsigned int __cdecl strlen(const char* szString);
extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);
extern "C" char* __cdecl strrchr(const char* szString, int nChar); // 0x00682990
extern "C" int __cdecl _stricmp(const char* szString1, const char* szString2); // 0x006841E9
void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...); // 0x00410610
void __cdecl sub_0051A480_DebugLog(const char* szFormat, ...); // 0x0051A480
unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
int __stdcall sub_00416370_StormGetFileSize(void* hFile, unsigned int* pnSizeHigh); // 0x00416370
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650
int __stdcall SFileReadFile(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped); // 0x0041B050
int __stdcall sub_004198D0(void* pArg); // 0x004198D0
int __stdcall sub_00419980(const char* szFileName, void** phFile); // 0x00419980
void* __fastcall sub_00406960_CreateFile(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x00406960
int __fastcall sub_004069D0_WriteFile(void* hFile, const void* pBuffer, unsigned long nToWrite, unsigned long* pnWritten, void* pOverlapped); // 0x004069D0
int __fastcall sub_004069A0_CloseFile(void* hFile); // 0x004069A0
void __fastcall sub_0051EA40_SetStatus(int nStatus); // 0x0051EA40
int __fastcall sub_0051C5C0_SendPacket(unsigned char nId, const void* pData, unsigned int nSize); // 0x0051C5C0
void __fastcall sub_0051B060_SetAdText(const char* szText1, const char* szText2); // 0x0051B060
void __fastcall sub_005202F0_PostText(int nType, const char* szText); // 0x005202F0
void __fastcall sub_00520210_PostData(int nType, const void* pData, unsigned int nSize); // 0x00520210
extern "C" const char gszBnDownloadFile_006DF338[]; // 0x006DF338
extern char gszAdList_00881D60[]; // 0x00881D60
extern D2CriticalSectionStrc gDownloadLock_00881F64; // 0x00881F64
extern BNGatewayAccess gBnGatewayAccess_00881838; // 0x00881838

typedef char check_int_width[(sizeof(int) == 4) ? 1 : -1];

typedef char check_long_width[(sizeof(long) == 4) ? 1 : -1];

typedef char check_uchar_width[(sizeof(unsigned char) == 1) ? 1 : -1];

extern "C" long gnPendingCount_00881D5C; // 0x00881D5C
extern "C" int gnFlag_00882528; // 0x00882528
extern "C" int gnSlotArrayA_00882128[94]; // 0x00882128
extern "C" int gnSlotArrayB_008822A8[94]; // 0x008822A8
extern "C" int gnValue_00882744; // 0x00882744
extern "C" int gnValue_0088274C; // 0x0088274C
extern "C" int gnValue_0088CB0C;
extern "C" int gnValue_0088CB10;
extern "C" __declspec(dllimport) int __stdcall GetFileTime(void* hFile, __int64* pCreation, __int64* pAccess, __int64* pWrite); // 0x006CC2F4
extern "C" __declspec(dllimport) unsigned long __stdcall GetFileSize(void* hFile, unsigned long* pHigh); // 0x006CC2F0

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
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pSection); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pSection); // 0x006CC214
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* pValue); // 0x006CC204
extern "C" int __stdcall connect(unsigned int nSocket, const D2SockAddrInStrc* pName, int nLength); // 0x006B014A
extern "C" unsigned short __stdcall htons(unsigned short nValue); // 0x006B0156
extern "C" int __stdcall setsockopt(unsigned int nSocket, int nLevel, int nName, const char* pValue, int nLength); // 0x006B0162
extern "C" unsigned int __stdcall socket(int nFamily, int nType, int nProtocol); // 0x006B016E
extern "C" int __stdcall recv(unsigned int nSocket, char* pBuffer, int nLength, int nFlags); // 0x006B0174
extern "C" int __stdcall send(unsigned int nSocket, const char* pBuffer, int nLength, int nFlags); // 0x006B017A
unsigned long __fastcall sub_004069F0_SetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod); // 0x004069F0
int __fastcall sub_0040D880(unsigned int s); // 0x0040D880
void __fastcall sub_00519DB0_HandOnDownload(const char* szFile, const void* pData, unsigned int nSize, const D2FileTimeStrc* pFileTime, int nArg5, int nArg6); // 0x00519DB0
void __fastcall sub_0051C0E0_ResolveHost(char* szResult, const char* szHost); // 0x0051C0E0
void __fastcall sub_0051C190(char* szText, int nSize); // 0x0051C190
int __fastcall sub_0051C9B0_GetPeerName(void* pAddress, int* pnLength); // 0x0051C9B0
void __fastcall sub_0051FAB0_HandleDownloadEvent(int nType, int nSubType, unsigned int nArg1, unsigned int nArg2, const D2FileTimeStrc* pFileTime, const char* szText1, const char* szText2, const void* pData, unsigned int nDataSize, int bFlag); // 0x0051FAB0
extern "C" const char gszRecvToBufferFailed_006DF380[]; // 0x006DF380
static __declspec(noinline) void __stdcall sub_0051E440_WriteFileWithTime(const void* pData, unsigned int nSize, const char* szFile, const D2FileTimeStrc* pFileTime);
static __declspec(noinline) int __stdcall sub_0051E5F0_RecvAll(unsigned int nSocket, char* pBuffer, unsigned int nSize);
static __declspec(noinline) unsigned long sub_0051E640_GetFileSizeIfTimeMatches(const char* szFile, const __int64* pFileTime);
static __declspec(noinline) int __stdcall sub_0051EAB0_RecvToBuffer(unsigned int nSocket, const char* szFile, const D2FileTimeStrc* pFileTime, int nType, int nFlags, char** ppBuffer, unsigned int nSize);
static __declspec(noinline) int __stdcall sub_0051EBB0_RecvToFile(unsigned int nSocket, const char* szFile, const D2FileTimeStrc* pFileTime, unsigned int nOffset, unsigned int nTotal, int nType);

D2BnDnsArgsStrc gDnsArgs_00881BE8; // 0x00881BE8

// 0x00518BA0
void D2BnLogStrc::sub_00518BA0_LogWrite(const char* szText)
{
    SLogWrite(hLog, szText);
}

// 0x0051BE80
long __cdecl sub_0051BE80_CompareExchange(long* pDestination, long nExchange, long nComparand)
{
    return InterlockedCompareExchange(pDestination, nExchange, nComparand);
}

// 0x0051C0E0
void __fastcall sub_0051C0E0_ResolveHost(char* szResult, const char* szHost)
{
    gbDnsPending_008818E0 = 1;
    Sleep(10);
    *szResult = 0;
    unsigned long dwThreadId = 0;
    gDnsArgs_00881BE8.szResult = szResult;
    gDnsArgs_00881BE8.f_4 = szHost;
    void* hThread = CreateThread(0, 0, sub_0051BEE0, &gDnsArgs_00881BE8, 0, &dwThreadId);
    while (!InterlockedCompareExchange(&gnDnsDone_00881BFC, 0, 0))
    {
        if (WaitForSingleObject(hThread, 0) == 0)
            break;
        Sleep(10);
    }
}

// 0x0051C3E0
int __fastcall sub_0051C3E0_EnterChat(const char* szArg1, const char* szArg2, int nArg3, const char* szText, int nFlags)
{
    const int bAlternate = nFlags & 1;
    sub_0051D260_SelectVersion(bAlternate);
    sub_00520C00_ClearReply(10);
    sub_0051AE10_Send(szArg1, szArg2, nArg3);
    if (nFlags & 2)
        sub_0051ACA0_SendString(szText, 1, bAlternate);
    sub_00520B70_WaitForReply(10);
    if (sub_00520AE0())
    {
        sub_005204A0_SetError(0xE);
        return 1;
    }
    sub_00520520_SetState(0);
    return 1;
}

// 0x0051CA30
int __cdecl sub_0051CA30_IsReady()
{
    D2BnStateStrc tState;
    sub_005205F0_GetState(&tState);
    if (!sub_00520AE0() && tState.nState == 0 && InterlockedCompareExchange(&gnConnected_00881BF0, 0, 0))
        return 1;
    return 0;
}

// 0x0051EA20
void __fastcall sub_0051EA20_SetPercent(int nUnused, unsigned int nCurrent, unsigned int nTotal)
{
    gnPercent_00881C50 = nCurrent * 100 / nTotal;
}

// 0x00520210
int __fastcall sub_00520210_QueueMessage(int nId, const void* pData, unsigned int nLength)
{
    D2BnMessageStrc* pMessage = (D2BnMessageStrc*)FOG_Alloc(sizeof(D2BnMessageStrc), szBnMessQueueFile_006DF78C, 0x37, 0);
    if (nLength > 0x120)
        nLength = 0x120;
    if (nLength)
        memcpy(pMessage->szText, pData, nLength);
    else
        pMessage->szText[0] = 0;
    pMessage->nLength = nLength;
    pMessage->nId = nId;
    pMessage->pNext = 0;
    D2_ASSERT(nLength <= 0x120, 0x44);
    EnterCriticalSection(&gMessageLock_00882004);
    if (!gpMessageHead_00882020)
        gpMessageHead_00882020 = pMessage;
    else
        gpMessageTail_00882024->pNext = pMessage;
    gpMessageTail_00882024 = pMessage;
    LeaveCriticalSection(&gMessageLock_00882004);
    return 1;
}

char gszAdList_00881D60[1]; // 0x00881D60

D2CriticalSectionStrc gDownloadLock_00881F64; // 0x00881F64

// 0x0051E370
int __fastcall sub_0051E370_SetAdList(const void* pSource, unsigned int nSize)
{
    EnterCriticalSection(&gDownloadLock_00881F64);
    SMemCopy(gszAdList_00881D60, pSource, nSize);
    gnPercent_00881C50 = 0;
    LeaveCriticalSection(&gDownloadLock_00881F64);
    return 1;
}

// 0x0051E3B0
int __fastcall sub_0051E3B0_SetCheckRevisionValue(const char* szValue)
{
    SStrCopy(gszCheckRevisionValue_00881E60, szValue, 0x104);
    return 1;
}

// 0x0051E5D0
void __cdecl sub_0051E5D0_SetStopFlag()
{
    gbStopDownload_00881C54 = 1;
}

// 0x0051EA40
void __fastcall sub_0051EA40_SetStatus(int nStatus)
{
    EnterCriticalSection(&gDownloadLock_00881F64);
    gszAdList_00881D60[0] = 0;
    gszAdList_00881D60[1] = 0;
    gnPercent_00881C50 = nStatus;
    LeaveCriticalSection(&gDownloadLock_00881F64);
}

// 0x0051EA80
int __fastcall sub_0051EA80_SetArchiveName(const char* szName)
{
    SStrCopy(gszDownloadArchive_00881C58, szName, 0x7FFFFFFF);
    return 1;
}

// 0x0051EAA0
int __cdecl sub_0051EAA0_HasName()
{
    return gszDownloadArchive_00881C58[0] != 0;
}

char gszDownloadArchive_00881C58[260]; // 0x00881C58

char gszCheckRevisionValue_00881E60[260]; // 0x00881E60

// 0x0051E490
static int __stdcall sub_0051E490_ExtractArchiveDll(void* hArchive, char* szPath, const char* szFile)
{
    int bResult = 0;
    void* hFile = 0;
    unsigned int nLength = GetTempPathA(0x104 - strlen(szFile), szPath);
    if (!nLength)
    {
        sub_00410610_WriteLogLine("Failed to create temp file!");
    }
    else
    {
        sub_00413800(szPath, szFile, 0x104);
        char* pExtension = strrchr(szPath, '.');
        if (pExtension)
            *pExtension = 0;
        sub_00413800(szPath, ".dll", 0x104);
        if (SFileOpenFileEx(hArchive, szPath + nLength, 0, &hFile))
        {
            unsigned int nSize = sub_00416370_StormGetFileSize(hFile, 0);
            void* pBuffer = SMemAlloc(nSize, gszBnDownloadFile_006DF338, 0xF7, 0);
            if (pBuffer)
            {
                SFileReadFile(hFile, pBuffer, nSize, 0, 0);
                void* hOut = sub_00406960_CreateFile(szPath, 0x40000000, 0, 0, 2, 0x80, 0);
                if (hOut != (void*)-1)
                {
                    unsigned long nWritten;
                    sub_004069D0_WriteFile(hOut, pBuffer, nSize, &nWritten, 0);
                    sub_004069A0_CloseFile(hOut);
                    bResult = 1;
                }
                SMemFree(pBuffer, gszBnDownloadFile_006DF338, 0x111, 0);
            }
        }
    }
    if (hFile)
        sub_004198D0(hFile);
    return bResult;
}

// 0x0051E6D0
int __fastcall sub_0051E6D0_RunCheckRevision(int* pVersion, int* pChecksum, char* szExeInfo)
{
    if (pVersion)
        *pVersion = 0;
    if (pChecksum)
        *pChecksum = 0;
    if (szExeInfo)
        *szExeInfo = 0;

    void* hArchive = 0;
    char szDll[0x104] = { 0 };
    int nResult = 0;
    unsigned long dwStart = GetTickCount();
    do
    {
        if (gszDownloadArchive_00881C58[0])
        {
    if (!SFileOpenArchive(gszDownloadArchive_00881C58, 0, 0, &hArchive))
        return 0;

    unsigned int nAuth;
    SFileAuthenticateArchive(hArchive, &nAuth);
    if (!nAuth || nAuth >= 5)
    {
        if (sub_0051E490_ExtractArchiveDll(hArchive, szDll, gszDownloadArchive_00881C58) && sub_00516DE1_CanRunSurvey(szDll))
        {
            void* hDll = LoadLibraryA(szDll);
            if (hDll)
            {
                D2CheckRevisionFn pfnCheckRevision = (D2CheckRevisionFn)GetProcAddress(hDll, "CheckRevision");
                if (pfnCheckRevision)
                {
                    char szFile1[0x104] = { 0 };
                    char szFile2[0x104] = { 0 };
                    char szFile3[0x104] = { 0 };
                    GetModuleFileNameA(GetModuleHandleA(0), szFile1, 0x104);
                    nResult = pfnCheckRevision(szFile1, szFile2, szFile3, gszCheckRevisionValue_00881E60, pVersion, pChecksum, szExeInfo);
                }
                FreeLibrary(hDll);
            }
        }
    }

    if (hArchive)
        SFileCloseArchive(hArchive);
    Sleep(50);
    DeleteFileA(gszDownloadArchive_00881C58);
    if (szDll[0])
        DeleteFileA(szDll);
    return nResult;
        }
        Sleep(10);
    }
    while (GetTickCount() - dwStart <= 20000);
    return 1;
}

// 0x0051E5E0
extern "C" int __cdecl sub_0051E5E0_IsPendingCountPositive()
{
    return gnPendingCount_00881D5C > 0;
}

// 0x00520AD0
extern "C" int __cdecl sub_00520AD0_SetFlag882528()
{
    return gnFlag_00882528 = 1;
}

// 0x00520C00
extern "C" void __fastcall sub_00520C00_ClearSlotPair(unsigned char nSlot)
{
    gnSlotArrayA_00882128[nSlot] = 0;
    gnSlotArrayB_008822A8[nSlot] = 0;
}

// 0x00520C20
extern "C" int __fastcall sub_00520C20_GetSlotB(unsigned char nSlot)
{
    return gnSlotArrayB_008822A8[nSlot];
}

// 0x00523AB0
extern "C" int __fastcall sub_00523AB0_SelectValue(int bSecond)
{
    return bSecond ? gnValue_0088274C : gnValue_00882744;
}

// build: context sub_005FE060_ClearPair88CB10
extern "C" void __cdecl sub_005FE060_ClearPair88CB10()
{
    gnValue_0088CB10 = 0;
    gnValue_0088CB0C = 0;
}

// 0x0051E640
static __declspec(noinline) unsigned long sub_0051E640_GetFileSizeIfTimeMatches(const char* szFile, const __int64* pFileTime)
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

unsigned long __fastcall sub_H04_Emit_0051E640(const char* szFile, const __int64* pFileTime)
{
    return sub_0051E640_GetFileSizeIfTimeMatches(szFile, pFileTime);
}

// 0x0051E9D0
static int sub_0051E9D0_RunProgramList(const char* szDirectory, const char* szList)
{
    while (*szList)
    {
        if (!sub_00516DE1_CanRunSurvey(szList))
            return 0;

        if ((int)ShellExecuteA(0, 0, szList, 0, szDirectory, 1) <= 0x20)
            return 0;

        szList += SStrLen(szList) + 1;
    }

    return 1;
}

int __cdecl sub_B03_Emit_0051E9D0(const char* szDirectory, const char* szList)
{
    return sub_0051E9D0_RunProgramList(szDirectory, szList);
}

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

BNGatewayAccess gBnGatewayAccess_00881838; // 0x00881838

// 0x0051FAB0
void __fastcall sub_0051FAB0_HandleDownloadEvent(int nType, int nSubType, unsigned int nArg1, unsigned int nArg2, const D2FileTimeStrc* pFileTime, const char* szText1, const char* szText2, const void* pData, unsigned int nDataSize, int bFlag)
{
    switch (nType)
    {
    case 0x80000003:
    {
        D2BnAdInfoStrc info;
        info.nArg1 = nArg1;
        info.nArg2 = nArg2;
        char* szCopy1;
        if (szText1 && strlen(szText1))
        {
            szCopy1 = (char*)FOG_Alloc(strlen(szText1) + 1, gszBnDownloadFile_006DF338, 0x179, 0);
            strcpy(szCopy1, szText1);
        }
        else
        {
            szCopy1 = 0;
        }
        info.szText1 = szCopy1;
        char* szCopy2;
        if (szText2 && strlen(szText2))
        {
            szCopy2 = (char*)FOG_Alloc(strlen(szText2) + 1, gszBnDownloadFile_006DF338, 0x182, 0);
            strcpy(szCopy2, szText2);
        }
        else
        {
            szCopy2 = 0;
        }
        info.szText2 = szCopy2;
        void* pCopy;
        if (nDataSize && pData)
        {
            pCopy = FOG_Alloc(nDataSize, gszBnDownloadFile_006DF338, 0x18B, 0);
            memcpy(pCopy, pData, nDataSize);
        }
        else
        {
            pCopy = 0;
        }
        info.pData = pCopy;
        info.nDataSize = nDataSize;
        sub_0051B060_SetAdText(szText1, szText2);
        char szMessage[0x200];
        sprintf(szMessage, "<Received Ad: %s, %s>\n", info.szText1, info.szText2);
        sub_005202F0_PostText(1, szMessage);
        sub_00520210_PostData(3, &info, sizeof(info));
        break;
    }
    case 0x80000002:
    {
        EnterCriticalSection(&gDownloadLock_00881F64);
        const char* pEntry = gszAdList_00881D60;
        while (*pEntry)
        {
            if (!_stricmp(pEntry, szText1))
                break;
            pEntry += strlen(pEntry) + 1;
        }
        if (!*pEntry || !pEntry[strlen(pEntry) + 1])
        {
            sub_0051EA40_SetStatus(0x65);
        }
        else
        {
            const char* szValue = pEntry + strlen(pEntry) + 1;
            D2FileTimeStrc fileTime = { 0, 0 };
            sub_0051F910_Report(0x80000002, 2, 0, 0, &fileTime, szValue, 0);
        }
        LeaveCriticalSection(&gDownloadLock_00881F64);
        break;
    }
    case 0x80000001:
        sub_0051A480_DebugLog("Processing Version file");
        strcpy(gszDownloadArchive_00881C58, szText1);
        break;
    case 0x80000005:
        if (bFlag)
        {
            DeleteFileA(szText1);
            break;
        }
    case 0x80000006:
    {
        void* hArchive = 0;
        void* hFile = 0;
        void* hDll = 0;
        char szDll[0x104] = { 0 };
        sub_0051A480_DebugLog("Processing ExtraWork file");
        if (!SFileOpenArchive(szText1, 0, 0, &hArchive))
            break;

        unsigned int nAuth;
        SFileAuthenticateArchive(hArchive, &nAuth);
        if (nAuth && nAuth < 5)
        {
            sub_0051A480_DebugLog("<ERROR: Failed ExtraWork archive authentication!>");
        }
        else if (!sub_0051E490_ExtractArchiveDll(hArchive, szDll, szText1))
        {
            sub_0051A480_DebugLog("<ERROR: Failed to extract ExtraWork DLL!>");
        }
        else
        {
            hDll = LoadLibraryA(szDll);
            D2ExtraWorkFn pfnExtraWork;
            unsigned char nLocale;
            int nRead;
            if (!hDll)
                sub_0051A480_DebugLog("<ERROR: Failed to load ExtraWork DLL!>");
            else if (!(pfnExtraWork = (D2ExtraWorkFn)GetProcAddress(hDll, "ExtraWork")))
                sub_0051A480_DebugLog("<ERROR: Failed to get address of ExtraWork function!>");
            else if (!sub_00419980("data\\local\\use", &hFile))
                sub_0051A480_DebugLog("<ERROR: Failed to open game locale file!>");
            else if (!SFileReadFile(hFile, &nLocale, 1, &nRead, 0))
                sub_0051A480_DebugLog("<ERROR: Failed to read game locale file!>");
            else if (nRead != 1)
                sub_0051A480_DebugLog("<ERROR: Failed to read game locale file!>");
            else
            {
                sub_004198D0(hFile);
                D2BnExtraWorkPacketStrc packet;
                memset(&packet, 0, sizeof(packet));
                packet.wType = 1;
                packet.wSize = 4;
                packet.dwLocale = nLocale;
                if (pfnExtraWork(&packet))
                    sub_0051C5C0_SendPacket(0x4B, &packet, packet.wSize + 4);
                else
                    sub_0051A480_DebugLog("<ERROR: ExtraWork DLL indicated failure!>");
            }
        }
        if (hDll)
            FreeLibrary(hDll);

        if (hArchive)
            SFileCloseArchive(hArchive);
        Sleep(50);
        DeleteFileA(szText1);
        if (szDll[0])
            DeleteFileA(szDll);
        break;
    }
    case 0x80000004:
    {
        sub_0051A480_DebugLog("Processing Bnserver.ini file");
        unsigned int nLength = SStrLen((const char*)pData);
        char* szText = (char*)SMemAlloc(nLength + 1, gszBnDownloadFile_006DF338, 0x23F, 0);
        SStrCopy(szText, (const char*)pData, nLength + 1);
        gBnGatewayAccess_00881838.UpdateGatewaysFromIni(szText);
        SMemFree(szText, gszBnDownloadFile_006DF338, 0x245, 0);
        gBnGatewayAccess_00881838.SaveAndUnload();
        break;
    }
    }
}
