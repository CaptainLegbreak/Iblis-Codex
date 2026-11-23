#include "Fog.h"
#include "D2StormLink.h"
#include "D2GameTypes.h"
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CriticalSectionStrc;
struct D2LogMsgListStrc;
struct D2LogMessageStrc;
struct D2LogMemoryInfoStrc;
struct T00410610;


struct D2LogMsgListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    char* sub_0040FF40_NewNode(int nLinkType, unsigned int nExtraBytes, unsigned int nFlags); // 0x0040FF40
};

struct D2LogMessageStrc
{
    D2StormLinkStrc f_0;
    unsigned int nSize;
    int nType;
    int bTimeStamp;
    D2SystemTimeStrc f_14;
    char szName[1];
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall GetLocalTime(D2SystemTimeStrc* pSystemTime); // 0x006CC1D4
extern "C" int __cdecl _vsnprintf(char* szDest, size_t nCount, const char* szFormat, va_list args); // 0x00682F22
extern "C" int __cdecl _snprintf(char* szDest, size_t nCount, const char* szFormat, ...); // 0x006831DB
unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
extern "C" const char gszLogFormatError[]; // 0x006CE22C
extern int gbLogInitialized; // 0x0075D2EC
extern D2LogMsgListStrc gtLogMsgQueue_0075E868; // 0x0075E868
extern "C" __declspec(dllimport) int __stdcall IsBadReadPtr(const void* pAddress, unsigned int nSize); // 0x006CC238
extern "C" void* __cdecl memcpy(void* pDest, const void* pSource, unsigned int nSize); // 0x006829C0

struct D2LogMemoryInfoStrc
{
    const void* pAddress;
    unsigned int nSize;
    int nArg5;
    int bBadPointer;
    int bArg7;
};

extern D2CriticalSectionStrc gtLogQueueLock; // 0x0075E838
extern int gnLogQueued; // 0x0075D140
extern int gnLogQueuedBytes; // 0x0075D144

struct T00410610
{
    int nFirst;
    int nSecond;
    char unk0x08[0x10];
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260
void __fastcall sub_00410340_LogV(const char* szPrefix, int nArg2, int nArg3, const char* szFormat, va_list args); // 0x00410340
extern int gnBitMasks_006CE268[8]; // 0x006CE268
extern int gnBitClearMasks_006CE2E8[8]; // 0x006CE2E8
extern int ganByteTable[256]; // 0x006CE398
extern int ganLowBitTable[256]; // 0x006CE798
extern char gszLowerTable[256]; // 0x006CEB98
extern T00410610 gaRecords_0075E8A8[]; // 0x0075E8A8
extern unsigned int gnRecordCount_007768A4; // 0x007768A4
extern int gnTickAtReset_007768A0; // 0x007768A0
extern "C" long __cdecl _time32(long* pTime);
extern "C" int __cdecl tolower(int nChar);
// build: symbol ?gacCDKeyMap@* 0x006DF238
extern const char gacCDKeyMap[];

D2CriticalSectionStrc gtLogQueueLock; // 0x0075E838

int gnLogQueued; // 0x0075D140

int gnLogQueuedBytes; // 0x0075D144


// 0x00410340
void __fastcall sub_00410340_LogV(const char* szPrefix, int nArg2, int nArg3, const char* szFormat, va_list args)
{
// build: symbol ?gbLogThreadStop@* 0x0075E830
    if (gbLogThreadStop || !gbLogInitialized)
    {
        return;
    }

    char szBuffer[0x1000];
    __try
    {
        _vsnprintf(szBuffer, sizeof(szBuffer), szFormat, args);
        szBuffer[sizeof(szBuffer) - 1] = 0;
    }
    __except (1)
    {
        _snprintf(szBuffer, sizeof(szBuffer), "Bad message: format string is '%s'", szFormat);
    }

    if (nArg3 == 1)
    {
// build: symbol ?gszNewline@* 0x006FFCB0
        SStrPack(szBuffer, gszNewline, sizeof(szBuffer));
    }

    unsigned int nExtraBytes = SStrLen(szPrefix) + 1;
    nExtraBytes += SStrLen(szBuffer) + 1;

    EnterCriticalSection(&gtLogQueueLock);
    D2LogMessageStrc* pMessage = (D2LogMessageStrc*)gtLogMsgQueue_0075E868.sub_0040FF40_NewNode(0, nExtraBytes, 0);
    LeaveCriticalSection(&gtLogQueueLock);

    pMessage->nSize = nExtraBytes + 0x24;
    pMessage->nType = 1;
    pMessage->bTimeStamp = nArg2 == 1;
    GetLocalTime(&pMessage->f_14);

    char* pText = pMessage->szName;
    SStrCopy(pText, szPrefix, nExtraBytes);
    pText += SStrLen(pText) + 1;
    SStrCopy(pText, szBuffer, nExtraBytes);

    EnterCriticalSection(&gtLogQueueLock);
    D2StormLinkStrc* pLink = &pMessage->f_0;
    if (pLink->m_prevlink)
    {
        pLink->NextLink(-1)->m_prevlink = pLink->m_prevlink;
        pLink->m_prevlink->m_next = pLink->m_next;
        pLink->m_prevlink = 0;
        pLink->m_next = 0;
    }
    D2StormLinkStrc* pPrev = gtLogMsgQueue_0075E868.m_terminator.m_prevlink;
    pLink->m_prevlink = pPrev;
    pLink->m_next = pPrev->m_next;
    pPrev->m_next = (char*)pMessage;
    gtLogMsgQueue_0075E868.m_terminator.m_prevlink = pLink;
    ++gnLogQueued;
    gnLogQueuedBytes += pMessage->nSize;
    LeaveCriticalSection(&gtLogQueueLock);
}

// 0x00410610
void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...)
{
    D2_ASSERT(szFormat, 299);
    va_list args;
    va_start(args, szFormat);
    sub_00410340_LogV(&gszEmptyAssertText, 1, 1, szFormat, args);
}

// 0x00410660
void __cdecl sub_00410660_LogWritePrefixed(const char* szPrefix, const char* szFormat, ...)
{
    D2_ASSERT(szFormat, 316);
    if (!szPrefix)
    {
        szPrefix = &gszEmptyAssertText;
    }
    va_list args;
    va_start(args, szFormat);
    sub_00410340_LogV(szPrefix, 1, 1, szFormat, args);
}


// 0x00410B10
void __stdcall sub_00410B10(unsigned char* pBits, int nBit)
{
    pBits[nBit >> 3] |= gnBitMasks_006CE268[nBit & 7];
}

// 0x00410B30
int __stdcall sub_00410B30(unsigned char* pBits, int nBit)
{
    return pBits[nBit >> 3] & gnBitMasks_006CE268[nBit & 7];
}

// 0x00410B50
void __stdcall sub_00410B50(unsigned char* pBits, int nBit)
{
    pBits[nBit >> 3] &= gnBitClearMasks_006CE2E8[nBit & 7];
}

// 0x00411130
int __stdcall FOG_ComputeChecksum(unsigned char* pData, int nSize)
{
    int nChecksum = 0;
    for (int i = 0; i < nSize; ++i)
    {
        nChecksum = pData[i] + (nChecksum < 0) + 2 * nChecksum;
    }
    return nChecksum;
}

// 0x00411170
int __stdcall sub_00411170_SumByteTable(unsigned char* pData, int nSize)
{
    int nTotal = 0;
    for (unsigned char* pEnd = pData + nSize; pData < pEnd; ++pData)
    {
        nTotal += ganByteTable[*pData];
    }
    return nTotal;
}

// 0x004111A0
int __stdcall sub_004111A0_GetLowestSetBit(unsigned int nValue)
{
    if (nValue)
    {
        unsigned char* pBytes = (unsigned char*)&nValue;
        if (pBytes[0] > 0) return ganLowBitTable[pBytes[0]];
        if (pBytes[1] > 0) return ganLowBitTable[pBytes[1]] + 8;
        if (pBytes[2] > 0) return ganLowBitTable[pBytes[2]] + 16;
        if (pBytes[3] > 0) return ganLowBitTable[pBytes[3]] + 24;
    }
    return -1;
}

void __cdecl sub_00411280_ResetRecords(); // 0x00411280

// 0x004113C0
void __fastcall sub_004113C0(char* szString, int nLength)
{
    for (char* pEnd = szString + nLength; *szString && szString < pEnd; ++szString)
    {
        *szString = gszLowerTable[*szString];
    }
}

#include "gen/data/Source/Fog/Unknown_00410040.inc"

// 0x00410790
// build: symbol ?BNDOWNLOAD_GetTime@* 0x00521B40
static long BNDOWNLOAD_GetTime(long* pTime)
{
    return _time32(pTime);
}

static unsigned int sub_0051DD10_NibbleToHex(unsigned int nValue)
{
    nValue &= 0xF;
    if (nValue >= 10)
        return nValue + 0x37;
    return nValue + 0x30;
}

static int sub_0051DD20_HexToNibble(char cChar)
{
    char cLower = (char)tolower(cChar);
    if (cLower >= 'a')
        return cLower - 0x57;
    return cLower - 0x30;
}

static int sub_0051DD40_MapKeyChar(unsigned char cChar)
{
    return gacCDKeyMap[cChar];
}

long __stdcall sub_M106_Emit_0051DC70(long* pTime)
{
    return BNDOWNLOAD_GetTime(pTime);
}

unsigned int __stdcall sub_M106_Emit_0051DD10(int n)
{
    return sub_0051DD10_NibbleToHex(tolower(n)) + sub_0051DD10_NibbleToHex(tolower(n + 1));
}

int __stdcall sub_M106_Emit_0051DD20(int n)
{
    return sub_0051DD20_HexToNibble((char)tolower(n)) * 16 + sub_0051DD20_HexToNibble((char)tolower(n + 1));
}

int __stdcall sub_M106_Emit_0051DD40(int n)
{
    return sub_0051DD40_MapKeyChar((unsigned char)tolower(n)) * 24 + sub_0051DD40_MapKeyChar((unsigned char)tolower(n + 1));
}

// 0x004107B0
void __fastcall sub_004107B0_AtomicStore64(__int64* pDest, const __int64* pSrc)
{
    __asm
    {
        mov edi, ecx
        mov ebx, [edx]
        mov ecx, [edx + 4]
        mov eax, [edi]
        mov edx, [edi + 4]
    retry:
        lock cmpxchg8b qword ptr [edi]
        jne retry
    }
}
