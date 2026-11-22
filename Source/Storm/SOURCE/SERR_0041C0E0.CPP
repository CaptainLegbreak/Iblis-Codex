#include "Storm.h"
#include "D2SFileTypes.h"
#include "D2GameTypes.h"
#include "D2StormTypes.h"
#include "D2StormLink.h"

struct D2CriticalSectionStrc;
struct PairStrc_0041C390;
struct Link;
struct D2StormHandlerStrc;

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218

struct Link {
    Link* previous;
    char* next;
    char* sub_00417770();
};

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020
extern int (__stdcall* gpfnReadErrorCallback_00779030)(const char* szName, unsigned long dwError, int nRetry); // 0x00779030

struct PairStrc_0041C390
{
    int nFirst;
    int nSecond;
};

enum { NO_NODE = 0 };

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210
extern "C" void __cdecl __debugbreak();
void __stdcall sub_0041C0F0_AppendExeMsgSource(unsigned short wFacility); // 0x0041C0F0

struct D2StormHandlerStrc
{
    D2StormLinkStrc f_0;
    int unk0x08;

    D2StormHandlerStrc()
    {
        f_0.m_prevlink = 0;
        f_0.m_next = 0;
    }
    ~D2StormHandlerStrc();
    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, "delete", -1, 0);
    }
};

inline void* operator new(unsigned int, void* pWhere) throw();

void* gpCallback_007790F8; // 0x007790F8
D2CriticalSectionStrc gErrorStateLock_007790CC; // 0x007790CC
int gdwGlobal_007790F4; // 0x007790F4
int gdwGlobal_007790E4; // 0x007790E4

inline void* operator new(unsigned int, void* pWhere) throw()
{
    return pWhere;
}

inline D2StormHandlerStrc::~D2StormHandlerStrc()
{
    f_0.Unlink();
}

// 0x0041C0E0
void __fastcall sub_0041C0E0_SetCallback(void* pCallback)
{
    gpCallback_007790F8 = pCallback;
}

// 0x0041C140
void __cdecl sub_0041C140_AppendExeMsgSources()
{
    sub_0041C0F0_AppendExeMsgSource(0x510);
    sub_0041C0F0_AppendExeMsgSource(0x876);
    sub_0041C0F0_AppendExeMsgSource(0x878);
}

// 0x0041C160
void __cdecl sub_0041C160_DebugBreak()
{
    __debugbreak();
}

// 0x0041C1A0
void __cdecl sub_0041C1A0_LockErrorState()
{
    if (!InterlockedIncrement(&gnErrorLockUsers_0070841C))
        InitializeCriticalSection(&gErrorStateLock_007790CC);
    else
        InterlockedDecrement(&gnErrorLockUsers_0070841C);
    EnterCriticalSection(&gErrorStateLock_007790CC);
}

// 0x0041C1E0
void __cdecl sub_0041C1E0_UnlockErrorState()
{
    LeaveCriticalSection(&gErrorStateLock_007790CC);
}

// 0x0041C2A0
int __cdecl sub_0041C2A0()
{
    return gdwGlobal_007790F4;
}

// 0x0041C2B0
int __cdecl sub_0041C2B0()
{
    return gdwGlobal_007790E4;
}

// 0x0041C390
void __fastcall sub_0041C390(PairStrc_0041C390* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}

// 0x0041C3A0
D2StormLinkStrc* D2StormLinkStrc::sub_0041C3A0_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x0041C560
D2StormLinkStrc* D2StormFixedListStrc::sub_0041C560_Link(char* pNode)
{
    return Link(pNode);
}

// 0x0041C580
void D2StormFixedListStrc::sub_0041C580_LinkNode(char* pNode, unsigned int nLinkType, char* pExistingNode)
{
    D2StormLinkStrc* pLink = Link(pNode);
    pLink->Unlink();
    D2StormLinkStrc* pExistingLink = Link(pExistingNode);
    switch (nLinkType)
    {
    case 1:
        pLink->m_prevlink = pExistingLink;
        pLink->m_next = pExistingLink->m_next;
        pExistingLink->NextLink(m_linkoffset)->m_prevlink = pLink;
        pExistingLink->m_next = pNode;
        break;
    default:
        D2StormLinkStrc* pPrevLink = pExistingLink->m_prevlink;
        pLink->m_prevlink = pPrevLink;
        pLink->m_next = pPrevLink->m_next;
        pPrevLink->m_next = pNode;
        pExistingLink->m_prevlink = pLink;
        break;
    }
}

// 0x0041C630
char* D2StormFixedListStrc::sub_0041C630_Next(char* pNode)
{
    return Link(pNode)->Next();
}

// 0x0041C690
void D2StormFixedListStrc::sub_0041C690_UnlinkNode(char* pNode)
{
    Link(pNode)->Unlink();
}

// 0x0041C700
char* D2StormFixedListStrc::sub_0041C700_RawNext(char* pNode)
{
    return Link(pNode)->m_next;
}

// 0x0041C840
char* D2StormFixedListStrc::sub_0041C840_NewNode(unsigned int nLinkType, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2StormHandlerStrc) + nExtraBytes, gszTypeNameHandler_00708434, -2, nFlags | 8);
    D2StormHandlerStrc* pRecord = pMemory ? new (pMemory) D2StormHandlerStrc : 0;
    if (nLinkType)
        sub_0041C580_LinkNode((char*)pRecord, nLinkType, 0);
    return (char*)pRecord;
}

// 0x0041CA10
char* D2StormFixedListStrc::sub_0041CA10_DeleteNode(char* pNode)
{
    char* pNext = Link(pNode)->Next();
    ((D2StormHandlerStrc*)pNode)->~D2StormHandlerStrc();
    SMemFree(pNode, gszTypeNameHandler_00708434, -2, 0);
    return pNext;
}

// build: symbol ??_GD2StormHandlerStrc@@QAEPAXI@Z 0x0041C8A0
