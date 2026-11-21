#include "Storm.h"
#include "D2GameTypes.h"
#include "D2StormLink.h"
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

struct HWND__;
struct D2StormLinkStrc;
struct D2StormNodeListStrc;
struct D2StormHuffItemStrc;
struct D2StormHuffTreeStrc;
class TOutputStream;
class THuffmannTree;
struct D2CriticalSectionStrc;
struct T0041FA40;
struct D2StormListStrc;
struct D2Field14Strc;
struct D2UnitStrc;
struct D2StormByteArrayStrc;
struct D2StormFixedArrayAStrc;
struct D2StormFixedArrayBStrc;
struct D2StormFixedUIntArrayStrc;
struct D2StormFixedUCharArrayStrc;
struct D2StormGrowUIntArrayStrc;
struct D2StormGrowUCharArrayStrc;
struct D2StormArrayBStrc;
struct D2StormQueueArrayStrc;
struct D2StormQueueStrc;
struct D2StormBigStrc;

struct D2StormNodeListStrc
{
    int nLinkOffset;
    D2StormLinkStrc terminator;
    void __thiscall sub_0041EE40_UnlinkAll(); // 0x0041EE40
    __forceinline void Clear()
    {
        sub_0041EE40_UnlinkAll();
        terminator.Unlink();
    }
};

struct D2StormHuffItemStrc
{
    D2StormLinkStrc link;
    unsigned int nValue, nWeight;
    D2StormHuffItemStrc* pParent;
    D2StormHuffItemStrc* pChild;
};

struct D2StormHuffTreeStrc
{
    int unk_00[2];
    D2StormHuffItemStrc items[515];
    D2StormNodeListStrc listA;
    D2StormNodeListStrc listB;
};

void __fastcall sub_0041EE90_DestroyItem(void* pItem); // 0x0041EE90
void __stdcall sub_00686AD1_DestroyArray(void* pArray, unsigned int nSize, int nCount, void (__fastcall* pDestroy)(void*)); // 0x00686AD1

class TOutputStream
{
public:
    TOutputStream(void* pvOutBuffer, unsigned int cbOutLength);                                             // 0x0041D920

    unsigned char* pbOutBuffer;
    unsigned int cbOutSize;
    unsigned char* pbOutPos;
    unsigned int T00410B70;
    unsigned int BitCount;
};

class THuffmannTree
{
public:
    THuffmannTree();                                                                                        // 0x0041F4A0
    ~THuffmannTree();                                                                                       // 0x0041F6A0
    unsigned int sub_0041F850(TOutputStream* os, void* pvInBuffer, int cbInBuffer, unsigned char nCmpType);    // 0x0041F850

    unsigned int adwData[0x3474 / 4];
};


extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) int __stdcall WriteFile(void* hFile, const void* pBuffer, unsigned long nToWrite, unsigned long* pnWritten, void* pOverlapped); // 0x006CC1A8
extern "C" __declspec(dllimport) void* __stdcall VirtualAlloc(void* pAddress, size_t nSize, unsigned long dwAllocationType, unsigned long dwProtect); // 0x006CC21C
extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* pAddress, size_t nSize, unsigned long dwFreeType); // 0x006CC220
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText); // 0x006CC200
extern "C" int __cdecl vsprintf(char* szDest, const char* szFormat, va_list args); // 0x00682DA1
extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0
unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax); // 0x004135D0
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize); // 0x0041D2A0
void __stdcall SMemFill(void* pLocation, unsigned int nLength, unsigned char nFillWith); // 0x0041D2C0
extern D2CriticalSectionStrc gaSLogLocks_00779238[4]; // 0x00779238
extern T0041FA40* gapSLogBuckets_00779298[4]; // 0x00779298
extern int gbSLogDebugOutput_007790AC; // 0x007790AC

struct D2StormListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
};

typedef int (__stdcall* SMSGHANDLER)(void* pParams);

void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);
void __stdcall sub_004208E0_AddWndRec(int nValue);
int __stdcall sub_00420CF0_WindowProc(void* hWnd, unsigned int uMsg, unsigned int wParam, int lParam);
int __fastcall sub_004209E0_FindWndRec(HWND__* hWnd);
int __stdcall SEvtRegisterHandler(unsigned int nType, HWND__* hWnd, unsigned int nId, int nFlags, SMSGHANDLER pHandler); // 0x00426420

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650

struct D2StormByteArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    char* f_8;
    unsigned int f_C;

    char* sub_00421010_Ptr();
};

struct D2StormFixedArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned int* f_8;

    unsigned int* sub_00421150_Ptr();
};

struct D2StormFixedArrayBStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned char* f_8;

    unsigned char* sub_004215B0_Ptr();
};

struct D2StormFixedUIntArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned int* f_8;

    ~D2StormFixedUIntArrayStrc();
};

struct D2StormFixedUCharArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned char* f_8;

    ~D2StormFixedUCharArrayStrc();
};

struct D2StormGrowUIntArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned int* f_8;
    unsigned int f_C;

    ~D2StormGrowUIntArrayStrc();
};

struct D2StormGrowUCharArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned char* f_8;
    unsigned int f_C;

    ~D2StormGrowUCharArrayStrc();
};

struct D2StormArrayBStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned char* f_8;
    unsigned int f_C;

    static unsigned int __stdcall RoundUp(unsigned int nValue, unsigned int nAlign)
    {
        unsigned int nRemainder = nValue % nAlign;
        if (nRemainder)
            nValue += nAlign - nRemainder;
        return nValue;
    }
    unsigned int sub_00421160_CalcChunkSize(unsigned int nCount);                                           // 0x00421160
    void sub_004211C0_ReallocData(unsigned int nAlloc);                                                     // 0x004211C0
    unsigned char* sub_00421930_New();
};

struct D2StormQueueArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned int* f_8;
    unsigned int f_C;
};

struct D2StormQueueStrc
{
    D2StormQueueArrayStrc m_array;
    unsigned int m_start;

    unsigned int Count() const
    {
        return m_array.f_4 - m_start;
    }
    int IsUsed(unsigned int nIndex) const
    {
        return nIndex + m_start < m_array.f_4;
    }
    unsigned int operator[](unsigned int nIndex) const
    {
        return IsUsed(nIndex) ? m_array.f_8[m_start + nIndex] : 0;
    }
};

struct D2StormBigStrc
{
    D2StormQueueStrc tPrimary;
};

// 0x0041F6A0
void __fastcall sub_0041F6A0_DestroyTree(D2StormHuffTreeStrc* pTree)
{
    pTree->listB.Clear();
    pTree->listA.Clear();
    sub_00686AD1_DestroyArray(pTree->items, sizeof(D2StormHuffItemStrc), 515, sub_0041EE90_DestroyItem);
}

// 0x0041F980
void __fastcall sub_0041F980(void* pvOutBuffer, int* pcbOutBuffer, void* pvInBuffer, int cbInBuffer, int* pCmpType, int nCmpLevel)
{
    TOutputStream os(pvOutBuffer, *pcbOutBuffer);
    THuffmannTree ht;
    *pcbOutBuffer = ht.sub_0041F850(&os, pvInBuffer, cbInBuffer, *pCmpType);
}

static unsigned long gnSLogTimeLength_007792A8; // 0x007792A8

static char gszSLogTime_007792B0[0x40]; // 0x007792B0

static unsigned long gdwSLogLastTick_007792F0; // 0x007792F0

static void sub_0041FA40_FlushLog(T0041FA40* pLog)
{
    unsigned long dwWritten;
    if (pLog->nUsed)
    {
        WriteFile(pLog->hFile, pLog->szBuffer, pLog->nUsed, &dwWritten, 0);
        FlushFileBuffers(pLog->hFile);
        pLog->nUsed = 0;
        pLog->nPended = 0;
    }
}

static T0041FA40* __stdcall sub_0041FA80_LockLog(unsigned long* pIndex, int bCreate, void* hLog)
{
    if (!hLog)
    {
        *pIndex = (unsigned long)-1;
        return 0;
    }
    unsigned long nIndex = (unsigned long)hLog & 3;
    EnterCriticalSection(&gaSLogLocks_00779238[nIndex]);
    *pIndex = nIndex;
    T0041FA40** ppNext = &gapSLogBuckets_00779298[nIndex];
    for (T0041FA40* p = *ppNext; p; p = *ppNext)
    {
        if (p->hLog == hLog)
            return p;
        ppNext = &p->pNext;
    }
    if (!bCreate)
    {
        LeaveCriticalSection(&gaSLogLocks_00779238[nIndex]);
        *pIndex = (unsigned long)-1;
        return 0;
    }
    T0041FA40* pLog = (T0041FA40*)VirtualAlloc(0, sizeof(T0041FA40), 0x1000, 4);
    *ppNext = pLog;
    if (!pLog)
    {
        LeaveCriticalSection(&gaSLogLocks_00779238[nIndex]);
        *pIndex = (unsigned long)-1;
        return 0;
    }
    pLog->hLog = hLog;
    pLog->pNext = 0;
    pLog->hFile = (void*)-1;
    pLog->nUsed = 0;
    pLog->nPended = 0;
    return pLog;
}

static __declspec(noinline) void sub_0041FB40_AppendIndent(T0041FA40* pLog)
{
    int nIndent = pLog->nIndent;
    if (nIndent > 0)
    {
        if (nIndent >= 0x80)
            nIndent = 0x80;
        memset(pLog->szBuffer + pLog->nUsed, ' ', nIndent);
        pLog->szBuffer[pLog->nUsed + nIndent] = 0;
        pLog->nUsed += nIndent;
    }
}

static void sub_0041FB80_AppendNewline(T0041FA40* pLog)
{
    SMemCopy(pLog->szBuffer + pLog->nUsed, gszSLogNewline_006CFF08, 3);
    pLog->nUsed += 2;
}

// 0x0041FBA0
static void __stdcall sub_0041FBA0_AppendTimestamp(int bText, T0041FA40* pLog)
{
    if (!pLog->f_18)
        return;
    unsigned long dwTick = GetTickCount();
    if (dwTick != gdwSLogLastTick_007792F0)
    {
        gdwSLogLastTick_007792F0 = dwTick;
        D2SystemTimeStrc tTime;
        GetLocalTime(&tTime);
        wsprintfA(gszSLogTime_007792B0, "%u/%u %02u:%02u:%02u.%03u  ", tTime.wMonth, tTime.wDay, tTime.wHour, tTime.wMinute, tTime.wSecond, tTime.wMilliseconds);
        gnSLogTimeLength_007792A8 = SStrLen(gszSLogTime_007792B0);
    }
    if (bText)
    {
        SMemCopy(pLog->szBuffer + pLog->nUsed, gszSLogTime_007792B0, gnSLogTimeLength_007792A8 + 1);
    }
    else
    {
        SMemFill(pLog->szBuffer + pLog->nUsed, gnSLogTimeLength_007792A8, ' ');
        pLog->szBuffer[pLog->nUsed + gnSLogTimeLength_007792A8] = 0;
    }
    pLog->nUsed += gnSLogTimeLength_007792A8;
    sub_0041FB40_AppendIndent(pLog);
}

static void sub_0041FC80_UnlinkLog(T0041FA40* pLog, unsigned long nIndex)
{
    T0041FA40** ppNext = &gapSLogBuckets_00779298[nIndex];
    for (T0041FA40* p = *ppNext; p; p = *ppNext)
    {
        if (p == pLog)
        {
            *ppNext = p->pNext;
            VirtualFree(p, 0, 0x8000);
            break;
        }
        ppNext = &p->pNext;
    }
    LeaveCriticalSection(&gaSLogLocks_00779238[nIndex]);
}

static void sub_0041FCE0_UnlockLog(unsigned long nIndex)
{
    LeaveCriticalSection(&gaSLogLocks_00779238[nIndex]);
}

void __stdcall SLogClose(void* hLog)
{
    unsigned long nIndex;
    T0041FA40* pLog = sub_0041FA80_LockLog(&nIndex, 0, hLog);
    if (pLog)
    {
        sub_0041FA40_FlushLog(pLog);
        CloseHandle(pLog->hFile);
        sub_0041FC80_UnlinkLog(pLog, nIndex);
    }
}

void __stdcall SLogDump(void* hLog, const void* pData, unsigned long nSize)
{
    unsigned long nIndex;
    T0041FA40* pLog = sub_0041FA80_LockLog(&nIndex, 0, hLog);
    if (!pLog)
        return;
    for (unsigned long nOffset = 0; nOffset < nSize; nOffset += 8)
    {
        sub_0041FBA0_AppendTimestamp(0, pLog);
        wsprintfA(pLog->szBuffer + pLog->nUsed, "%04x: ", nOffset);
        pLog->nUsed += SStrLen(pLog->szBuffer + pLog->nUsed);
        for (unsigned long i = nOffset; i < nOffset + 8; ++i)
        {
            if (i < nSize)
            {
                wsprintfA(pLog->szBuffer + pLog->nUsed, "%02x ", ((const unsigned char*)pData)[i]);
                pLog->nUsed += SStrLen(pLog->szBuffer + pLog->nUsed);
            }
            else
            {
                pLog->nUsed += SStrCopy(pLog->szBuffer + pLog->nUsed, "   ", 0x7FFFFFFF);
            }
            if ((i & 3) == 3)
                pLog->nUsed += SStrCopy(pLog->szBuffer + pLog->nUsed, "  ", 0x7FFFFFFF);
        }
        for (unsigned long i = nOffset; i < nOffset + 8; ++i)
        {
            char c = (i < nSize) ? ((const char*)pData)[i] : 0;
            if (c >= ' ' && c <= '~')
            {
                wsprintfA(pLog->szBuffer + pLog->nUsed, "%c", c);
                pLog->nUsed += SStrLen(pLog->szBuffer + pLog->nUsed);
            }
            else
            {
                pLog->nUsed += SStrCopy(pLog->szBuffer + pLog->nUsed, c ? gszDot_006CCAD8 : gszSpace_006FFC44, 0x7FFFFFFF);
            }
            if ((i & 7) == 3)
                pLog->nUsed += SStrCopy(pLog->szBuffer + pLog->nUsed, gszSpace_006FFC44, 0x7FFFFFFF);
        }
        sub_0041FB80_AppendNewline(pLog);
    }
    if (gbSLogDebugOutput_007790AC)
        OutputDebugStringA(pLog->szBuffer + pLog->nPended);
    pLog->nPended = pLog->nUsed;
    if (pLog->nUsed >= 0xC000)
        sub_0041FA40_FlushLog(pLog);
    sub_0041FCE0_UnlockLog(nIndex);
}

void __stdcall SLogFlush(void* hLog)
{
    unsigned long nIndex;
    T0041FA40* pLog = sub_0041FA80_LockLog(&nIndex, 0, hLog);
    if (pLog)
    {
        sub_0041FA40_FlushLog(pLog);
        sub_0041FCE0_UnlockLog(nIndex);
    }
}

void __cdecl SLogFlushAll()
{
    for (unsigned int i = 0; i < 4; ++i)
    {
        EnterCriticalSection(&gaSLogLocks_00779238[i]);
        for (T0041FA40* p = gapSLogBuckets_00779298[i]; p; p = p->pNext)
            sub_0041FA40_FlushLog(p);
        LeaveCriticalSection(&gaSLogLocks_00779238[i]);
    }
}

void __cdecl SLogPend(void* hLog, const char* szFormat, ...)
{
    unsigned long nIndex;
    T0041FA40* pLog = sub_0041FA80_LockLog(&nIndex, 0, hLog);
    if (!pLog)
        return;
    pLog->nUsed = pLog->nPended;
    sub_0041FBA0_AppendTimestamp(1, pLog);
    va_list args;
    va_start(args, szFormat);
    vsprintf(pLog->szBuffer + pLog->nUsed, szFormat, args);
    pLog->nUsed += SStrLen(pLog->szBuffer + pLog->nUsed);
    sub_0041FB80_AppendNewline(pLog);
    sub_0041FCE0_UnlockLog(nIndex);
}

int __stdcall sub_004200E0_SLogSetAbsIndent(void* hLog, int nIndent)
{
    unsigned long nIndex;
    T0041FA40* pLog = sub_0041FA80_LockLog(&nIndex, 0, hLog);
    if (!pLog)
        return 0;
    int nOld = pLog->nIndent;
    pLog->nIndent = nIndent;
    sub_0041FCE0_UnlockLog(nIndex);
    return nOld;
}

int __stdcall sub_00420120_SLogSetIndent(void* hLog, int nDelta)
{
    unsigned long nIndex;
    T0041FA40* pLog = sub_0041FA80_LockLog(&nIndex, 0, hLog);
    if (!pLog)
        return 0;
    int nOld = pLog->nIndent;
    pLog->nIndent = nOld + nDelta;
    sub_0041FCE0_UnlockLog(nIndex);
    return nOld;
}

void __stdcall sub_00420160_SLogSetTimestamp(void* hLog, int bTimestamp)
{
    unsigned long nIndex;
    T0041FA40* pLog = sub_0041FA80_LockLog(&nIndex, 0, hLog);
    if (pLog)
    {
        pLog->f_18 = bTimestamp;
        sub_0041FCE0_UnlockLog(nIndex);
    }
}

void __cdecl SLogWrite(void* hLog, const char* szFormat, ...)
{
    unsigned long nIndex;
    T0041FA40* pLog = sub_0041FA80_LockLog(&nIndex, 0, hLog);
    if (!pLog)
        return;
    sub_0041FBA0_AppendTimestamp(1, pLog);
    va_list args;
    va_start(args, szFormat);
    vsprintf(pLog->szBuffer + pLog->nUsed, szFormat, args);
    pLog->nUsed += SStrLen(pLog->szBuffer + pLog->nUsed);
    sub_0041FB80_AppendNewline(pLog);
    if (gbSLogDebugOutput_007790AC)
        OutputDebugStringA(pLog->szBuffer + pLog->nPended);
    pLog->nPended = pLog->nUsed;
    if (pLog->nUsed >= 0xC000)
        sub_0041FA40_FlushLog(pLog);
    sub_0041FCE0_UnlockLog(nIndex);
}

void __cdecl sub_00601B50_Empty()
{
}

// 0x004204F0
char* __fastcall sub_00601B60_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00601C60_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00601CE0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

void __fastcall sub_00601DF0_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00601E10_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

// 0x00420A70
static int __stdcall sub_00420A70_RegisterHandler(unsigned int nType, HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
{
    VALIDATEBEGIN;
    VALIDATE(pHandler);
    VALIDATEEND;
    if (!sub_004209E0_FindWndRec(hWnd))
    {
        sub_004208E0_AddWndRec((int)hWnd);
    }
    return nValid ? SEvtRegisterHandler(nType, hWnd, nId, 0, pHandler) : 0;
}

int __stdcall SMsgRegisterCommand(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
{
    return sub_00420A70_RegisterHandler(0x534D5348, hWnd, nId, pHandler);
}

int __stdcall SMsgRegisterKeyDown(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
{
    return sub_00420A70_RegisterHandler(0x534D5349, hWnd, nId, pHandler);
}

int __stdcall SMsgRegisterKeyUp(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
{
    return sub_00420A70_RegisterHandler(0x534D534A, hWnd, nId, pHandler);
}

int __stdcall SMsgRegisterMessage(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
{
    return sub_00420A70_RegisterHandler(0x534D5347, hWnd, nId, pHandler);
}

// 0x00420D50
int __stdcall SMsgGetDispatcher(int a1)
{
    VALIDATEBEGIN;
    VALIDATE(!a1);
    VALIDATEEND;
    return nValid ? (int)&sub_00420CF0_WindowProc : 0;
}

// 0x00420E70
int* __fastcall sub_005A6250_GetField14(D2Field14Strc* pRecord)
{
    return &pRecord->nField14;
}

static __forceinline int sub_005A64F0_IsActionFrame(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwAnimMode == 14)
        return (pUnit->dwFlags >> 6) & 1;
    return pUnit->nActionFrame == 1;
}

void __fastcall sub_M111_Emit_005A64F0(D2UnitStrc* pUnit, int* pResult)
{
    *pResult = sub_005A64F0_IsActionFrame(pUnit) + 1;
}

// 0x00421010
char* D2StormByteArrayStrc::sub_00421010_Ptr()
{
    return f_8;
}

// 0x00421040
void __cdecl sub_00421040_Empty()
{
}

// 0x00421050
void __fastcall sub_00421050_Construct(unsigned char* pDest, const unsigned char* pValue)
{
    if (pDest)
        *pDest = *pValue;
}

// 0x00421060
void __cdecl sub_00421060_Empty()
{
}

// 0x00421070
void __cdecl sub_00421070_Empty()
{
}

// 0x00421080
void __cdecl sub_00421080_Empty()
{
}

// 0x00421090
void __fastcall sub_00421090_Construct(char* pDest, const char* pValue)
{
    if (pDest)
        *pDest = *pValue;
}

// 0x00421150
unsigned int* D2StormFixedArrayAStrc::sub_00421150_Ptr()
{
    return f_8;
}

// 0x004212A0
void __fastcall sub_004212A0_Construct(unsigned int* pDest, const unsigned int* pValue)
{
    if (pDest)
        *pDest = *pValue;
}

// 0x004212B0
void __cdecl sub_004212B0_Empty()
{
}

static __declspec(noinline) int sub_00421440_IsEven(const D2StormQueueStrc& a)
{
    return !a.Count() || !(a[0] & 1);
}

// 0x00421540
int __stdcall SBigIsEven(D2StormBigStrc* pBig)
{
    return sub_00421440_IsEven(pBig->tPrimary);
}

// 0x00421570
D2StormFixedUIntArrayStrc::~D2StormFixedUIntArrayStrc()
{
    if (f_8)
        SMemFree(f_8, gszTypeNameUInt_00708874, -2, 0);
}

// 0x00421590
D2StormFixedUCharArrayStrc::~D2StormFixedUCharArrayStrc()
{
    if (f_8)
        SMemFree(f_8, gszTypeNameUChar_00708880, -2, 0);
}

// 0x004215B0
unsigned char* D2StormFixedArrayBStrc::sub_004215B0_Ptr()
{
    return f_8;
}

// 0x004217F0
D2StormGrowUIntArrayStrc::~D2StormGrowUIntArrayStrc()
{
    if (f_8)
        SMemFree(f_8, gszTypeNameUInt_00708874, -2, 0);
}

// 0x00421840
D2StormGrowUCharArrayStrc::~D2StormGrowUCharArrayStrc()
{
    if (f_8)
        SMemFree(f_8, gszTypeNameUChar_00708880, -2, 0);
}

// 0x00421930
unsigned char* D2StormArrayBStrc::sub_00421930_New()
{
    unsigned int nCount = f_4 + 1;
    if (nCount > f_0)
    {
        unsigned int nChunk = f_C ? f_C : sub_00421160_CalcChunkSize(nCount);
        sub_004211C0_ReallocData(RoundUp(nCount, nChunk));
    }
    return &f_8[f_4++];
}
