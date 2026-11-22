#include "Storm.h"
#include "D2GameTypes.h"
#include "D2StormLink.h"


struct HWND__;

struct D2CriticalSectionStrc;

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214

extern "C" __declspec(dllimport) int __stdcall WriteFile(void* hFile, const void* pBuffer, unsigned long nToWrite, unsigned long* pnWritten, void* pOverlapped); // 0x006CC1A8

extern "C" __declspec(dllimport) void* __stdcall VirtualAlloc(void* pAddress, size_t nSize, unsigned long dwAllocationType, unsigned long dwProtect); // 0x006CC21C

extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* pAddress, size_t nSize, unsigned long dwFreeType); // 0x006CC220

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134

extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText); // 0x006CC200

typedef int (__stdcall* SMSGHANDLER)(void* pParams);

void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);

void __stdcall sub_004208E0_AddWndRec(int nValue);

int __stdcall sub_00420CF0_WindowProc(void* hWnd, unsigned int uMsg, unsigned int wParam, int lParam);

int __fastcall sub_004209E0_FindWndRec(HWND__* hWnd);

int __stdcall SEvtRegisterHandler(unsigned int nType, HWND__* hWnd, unsigned int nId, int nFlags, SMSGHANDLER pHandler); // 0x00426420

struct D2StormLinkStrc;

struct D2StormListStrc;

struct D2Storm4167B0Strc;

struct D2Storm4168F0Strc;

struct D2Storm416A90Strc;

int __stdcall SEvtUnregisterHandler(unsigned int nType, HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler); // 0x00426720

extern unsigned short gwValue_0077905C;

struct D2StormListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
};

struct D2Storm4167B0Strc
{
    D2StormLinkStrc f_0;

    ~D2Storm4167B0Strc();
};

struct D2Storm4168F0Strc
{
    D2StormLinkStrc f_0;

    ~D2Storm4168F0Strc();
};

int __stdcall SMsgRegisterCommand(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler);

int __stdcall SMsgRegisterKeyDown(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler);

int __stdcall SMsgRegisterKeyUp(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler);

int __stdcall SMsgRegisterMessage(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler);

static __declspec(noinline) int __stdcall InternalRegister(unsigned int nType, HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler);

struct D2WinMsgStrc
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    int lParam;
    unsigned int dwTime;
    int f_14;
    int nPointY;
};

typedef int (__stdcall* SMSGIDLEPROC)(int nCount);

extern "C" __declspec(dllimport) int __stdcall DispatchMessageA(const D2WinMsgStrc* pMsg);                  // 0x006CC478

extern "C" __declspec(dllimport) int __stdcall GetMessageA(D2WinMsgStrc* pMsg, void* hWnd, unsigned int nMin, unsigned int nMax); // 0x006CC484

extern "C" __declspec(dllimport) int __stdcall PeekMessageA(D2WinMsgStrc* pMsg, void* hWnd, unsigned int nMin, unsigned int nMax, unsigned int nRemove); // 0x006CC480

extern "C" __declspec(dllimport) int __stdcall TranslateMessage(const D2WinMsgStrc* pMsg);                  // 0x006CC47C

// 0x00420A70
static __declspec(noinline) int __stdcall InternalRegister(unsigned int nType, HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
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

// 0x00420D50
int __stdcall SMsgGetDispatcher(int a1)
{
    VALIDATEBEGIN;
    VALIDATE(!a1);
    VALIDATEEND;
    return nValid ? (int)&sub_00420CF0_WindowProc : 0;
}

// 0x00420AB0
static __declspec(noinline) int __stdcall InternalUnregister(unsigned int nType, HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
{
    if (!sub_004209E0_FindWndRec(hWnd))
    {
        sub_004208E0_AddWndRec((int)hWnd);
    }
    return SEvtUnregisterHandler(nType, hWnd, nId, pHandler);
}

// 0x00420C70
int __stdcall SMsgUnregisterCommand(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
{
    return InternalUnregister(0x534D5348, hWnd, nId, pHandler);
}

// 0x00420C90
int __stdcall SMsgUnregisterKeyDown(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
{
    return InternalUnregister(0x534D5349, hWnd, nId, pHandler);
}

// 0x00420CB0
int __stdcall SMsgUnregisterKeyUp(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
{
    return InternalUnregister(0x534D534A, hWnd, nId, pHandler);
}

// 0x00420CD0
int __stdcall SMsgUnregisterMessage(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
{
    return InternalUnregister(0x534D5347, hWnd, nId, pHandler);
}

// 0x00420BF0
int __stdcall SMsgRegisterCommand(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
{
    return InternalRegister(0x534D5348, hWnd, nId, pHandler);
}

// 0x00420C10
int __stdcall SMsgRegisterKeyDown(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
{
    return InternalRegister(0x534D5349, hWnd, nId, pHandler);
}

// 0x00420C30
int __stdcall SMsgRegisterKeyUp(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
{
    return InternalRegister(0x534D534A, hWnd, nId, pHandler);
}

// 0x00420C50
int __stdcall SMsgRegisterMessage(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
{
    return InternalRegister(0x534D5347, hWnd, nId, pHandler);
}

unsigned short __stdcall SFileGetLocale()
{
    return gwValue_0077905C;
}

void __stdcall sub_00416750_Nop()
{
}

void __stdcall sub_00416760_Nop()
{
}

char* __fastcall sub_004167A0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

D2Storm4167B0Strc::~D2Storm4167B0Strc()
{
    f_0.Unlink();
}

char* __fastcall sub_004167F0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x00420D90
char* __fastcall sub_00416800_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

char* __fastcall sub_00416820_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416830_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416840_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

char* __fastcall sub_00416850_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416860_LinkPrev(D2StormLinkStrc* pLink)
{
    D2StormLinkStrc* pPrev = pLink->m_prevlink->m_prevlink;
    return (int)pPrev->m_next > 0 ? pPrev->m_next : 0;
}

char* __fastcall sub_00416880_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

D2Storm4168F0Strc::~D2Storm4168F0Strc()
{
    f_0.Unlink();
}

void __fastcall sub_004169F0_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A00_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A10_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A20_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A30_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

int __fastcall sub_00416A90_TestField150(D2Storm416A90Strc* pRecord)
{
    if (pRecord && pRecord->n150)
        return 1;
    return 0;
}

int __fastcall sub_00416AB0_TestField14C(D2Storm416A90Strc* pRecord)
{
    if (pRecord && pRecord->n14C)
        return 1;
    return 0;
}

// 0x004202A0
unsigned int __stdcall SMsgDoMessageLoop(SMSGIDLEPROC pfIdle, int bCleanUponQuit)
{
    D2WinMsgStrc tMsg;
    int nCount = 0;
    for (;;)
    {
        if (PeekMessageA(&tMsg, 0, 0, 0, 0) || !pfIdle || !pfIdle(nCount++))
        {
            nCount = 0;
            if (!GetMessageA(&tMsg, 0, 0, 0))
            {
                break;
            }
            TranslateMessage(&tMsg);
            DispatchMessageA(&tMsg);
        }
    }
    return tMsg.wParam;
}

struct D2TSLinkStrc
{
    D2TSLinkStrc* pPrevLink;
    D2TSLinkStrc* pNext;

    D2TSLinkStrc* NextLink(int nLinkOffset)
    {
        const int nNext = (int)pNext;
        if (nNext < 0)
        {
            return (D2TSLinkStrc*)~nNext;
        }
        if (nLinkOffset < 0)
        {
            nLinkOffset = (int)this - (int)pPrevLink->pNext;
        }
        return (D2TSLinkStrc*)(nNext + nLinkOffset);
    }

    void Unlink()
    {
        if (pPrevLink)
        {
            NextLink(-1)->pPrevLink = pPrevLink;
            pPrevLink->pNext = pNext;
            pPrevLink = 0;
            pNext = 0;
        }
    }
};

struct D2TSListStrc
{
    int nLinkOffset;
    D2TSLinkStrc tTerminator;

    D2TSLinkStrc* Head()
    {
        return (int)tTerminator.pNext > 0 ? tTerminator.pNext : 0;
    }

    void sub_00420750_UnlinkAll();
    int sub_004206C0_IsEmpty();
    void sub_00420790_Destroy();
};

// 0x004206C0
int D2TSListStrc::sub_004206C0_IsEmpty()
{
    return Head() == 0;
}

// 0x00420790
void D2TSListStrc::sub_00420790_Destroy()
{
    sub_00420750_UnlinkAll();
    tTerminator.Unlink();
}
