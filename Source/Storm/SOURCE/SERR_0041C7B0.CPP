#include "Storm.h"
#include "D2StormAutoLink.h"
#include "D2GameTypes.h"

struct D2StormList00708420Strc;
struct D2StormMsgSourceStrc;
struct D2CriticalSectionStrc;

struct D2StormList00708420Strc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)pNode : &m_terminator;
    }
    char* Head()
    {
        return m_terminator.Next();
    }
    void LinkNode(char* pNode, unsigned int nLinkType, char* pExisting)
    {
        D2StormLinkStrc* pLink = Link(pNode);
        pLink->Unlink();
        D2StormLinkStrc* pExistingLink = Link(pExisting);
        switch (nLinkType)
        {
        case 1:
            pLink->m_prevlink = pExistingLink;
            pLink->m_next = pExistingLink->m_next;
            pExistingLink->NextLink(m_linkoffset)->m_prevlink = pLink;
            pExistingLink->m_next = pNode;
            break;
        default:
            {
                D2StormLinkStrc* pPrev = pExistingLink->m_prevlink;
                pLink->m_prevlink = pPrev;
                pLink->m_next = pPrev->m_next;
                pPrev->m_next = pNode;
                pExistingLink->m_prevlink = pLink;
            }
            break;
        }
    }
    ~D2StormList00708420Strc();
    void sub_0041C770_UnlinkAll();                                                                          // 0x0041C770
    void sub_0041C9C0_DeleteAll();                                                                          // 0x0041C9C0
};

extern "C" __declspec(dllimport) int __stdcall HeapFree(void* hHeap, unsigned long dwFlags, void* lpMem); // 0x006CC320
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC
extern D2StormList00708420Strc gHandlerList_00708420; // 0x00708420
extern D2CriticalSectionStrc gErrorStateLock_007790CC; // 0x007790CC
extern D2StormMsgSourceStrc* gpStormMsgSources_007790E8; // 0x007790E8
extern "C" int __cdecl vsprintf(char* buffer, const char* format, char* args); // 0x00682DA1
int __stdcall SErrDisplayError(unsigned int nErrorCode,const char* szFile,int nLine,const char* szDescription,int bRecoverable,unsigned int nExitCode); // 0x0041CAF0
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText); // 0x006CC200
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...); // 0x00413A40
int __stdcall SErrDisplayError(unsigned int nErrorCode, const char* szFile, int nLine, const char* szDescription, int bRecoverable, unsigned int nExitCode); // 0x0041CAF0
extern "C" const char gszFormatName[]; // 0x006FFC58
extern int gnErrorOutputMode_0077909C; // 0x0077909C

int gnStormDword_007790EC; // 0x007790EC
int gbDebugMemoryLoaded_00779204; // 0x00779204
unsigned long gdwDebugMemory_00779200; // 0x00779200

extern "C" __declspec(dllimport) __declspec(noreturn) void __stdcall ExitProcess(unsigned int nExitCode); // 0x006CC2E0

struct HANDLER
{
    D2StormLinkStrc f_0;
    int nValue;
};

extern unsigned long gdwStormOwnerThread_007790C8; // 0x007790C8

void* gpStormOwnerA_007790C0; // 0x007790C0

extern void* gpStormOwnerB_007790C4; // 0x007790C4

void __cdecl sub_0041C1A0_LockErrorState(); // 0x0041C1A0

void __cdecl sub_0041C1E0_UnlockErrorState(); // 0x0041C1E0

void __stdcall SMemZero(void* pLocation, unsigned int nLength); // 0x0041D300

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020

// 0x0041C7B0
D2StormList00708420Strc::~D2StormList00708420Strc()
{
    sub_0041C770_UnlinkAll();
}

// 0x0041CA80
int __cdecl SErrDestroy()
{
    gHandlerList_00708420.sub_0041C9C0_DeleteAll();
    gnStormDword_007790EC = 0;
    while (gpStormMsgSources_007790E8)
    {
        D2StormMsgSourceStrc* pNext = gpStormMsgSources_007790E8->pNext;
        HeapFree(GetProcessHeap(), 0, gpStormMsgSources_007790E8);
        gpStormMsgSources_007790E8 = pNext;
    }
    if (gnErrorLockUsers_0070841C != -1)
    {
        DeleteCriticalSection(&gErrorStateLock_007790CC);
        gnErrorLockUsers_0070841C = -1;
    }
    return 1;
}

// 0x0041CFB0
int __cdecl SErrDisplayErrorFmt(int code, const char* file, int line, int recoverable, int exitCode, const char* format, ...)
{
    char buffer[0x400];
    char* args = (char*)(&format + 1);
    vsprintf(buffer, format, args);
    return SErrDisplayError(code, file, line, buffer, recoverable, exitCode);
}

// 0x0041D010
void __stdcall SErrReportNamedResourceLeak(const char* szName, const char* szDetail)
{
    if (!gbDebugMemoryLoaded_00779204)
    {
        gbDebugMemoryLoaded_00779204 = 1;
        SRegLoadValue("Internal", "Debug Memory", 0, &gdwDebugMemory_00779200);
    }
    if (!gdwDebugMemory_00779200)
        return;
    char szText[0x100];
    if (szDetail && *szDetail)
        SStrPrintf(szText, 0x100, "%s (%s)", szName, szDetail);
    else
        SStrPrintf(szText, 0x100, gszFormatName, szName);
    if (!gnErrorOutputMode_0077909C)
    {
        SErrDisplayError(0x8510007F, szText, -3, 0, 1, 1);
    }
    else
    {
        char szOutput[0xC8];
        wsprintfA(szOutput, "Storm Error : handle never released -- %s\n", szText);
        OutputDebugStringA(szOutput);
    }
}

inline void* operator new(unsigned int, void* pPlace) throw()
{
    return pPlace;
}

// 0x0041C900
void __stdcall SErrRegisterHandler(int nValue)
{
    sub_0041C1A0_LockErrorState();
    HANDLER* pNode = new (SMemAlloc(sizeof(HANDLER), gszTypeNameHandler_00708434, -2, 0x8000008)) HANDLER;
    gHandlerList_00708420.LinkNode((char*)pNode, 1, 0);
    pNode->nValue = nValue;
    sub_0041C1E0_UnlockErrorState();
}

// 0x0041D160
void __cdecl sub_0041D160_DisplayAppFatal(const char* szFormat, ...)
{
    const char* szFile = 0;
    int nLine = 0;
    sub_0041C1A0_LockErrorState();
    if (gdwStormOwnerThread_007790C8 == GetCurrentThreadId())
    {
        szFile = (const char*)gpStormOwnerA_007790C0;
        nLine = (int)gpStormOwnerB_007790C4;
        SMemZero(&gpStormOwnerA_007790C0, 12);
    }
    sub_0041C1E0_UnlockErrorState();
    char szText[0x400];
    va_list args;
    va_start(args, szFormat);
    vsprintf(szText, szFormat, args);
    SErrDisplayError(0x85100084, szFile, nLine, szText, 0, 1);
    ExitProcess(1);
}

// 0x0041D1E0
void __stdcall SErrReportResourceLeak(const char* szName)
{
    SErrReportNamedResourceLeak(szName, 0);
}
