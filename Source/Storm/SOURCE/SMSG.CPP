#include "D2StormTypes.h"
#include "Storm.h"
#include "D2GameTypes.h"
#include "stpl.h"

struct HWND__;

typedef int (__stdcall* SMSGHANDLER)(void* pParams);

struct SMSGHANDLER_PARAMS;

void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);

struct WNDREC : TSLinkedNode<WNDREC>
{
    void* hWnd;                                             // 0x08
};

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

extern "C" __declspec(dllimport) int __stdcall DefWindowProcA(void* hWnd, unsigned int uMsg, unsigned int wParam, int lParam); // 0x006CC488
extern "C" __declspec(dllimport) int __stdcall DispatchMessageA(const D2WinMsgStrc* pMsg);                  // 0x006CC478
extern "C" __declspec(dllimport) int __stdcall GetMessageA(D2WinMsgStrc* pMsg, void* hWnd, unsigned int nMin, unsigned int nMax); // 0x006CC484
extern "C" __declspec(dllimport) int __stdcall PeekMessageA(D2WinMsgStrc* pMsg, void* hWnd, unsigned int nMin, unsigned int nMax, unsigned int nRemove); // 0x006CC480
extern "C" __declspec(dllimport) int __stdcall TranslateMessage(const D2WinMsgStrc* pMsg);                  // 0x006CC47C

int __stdcall SEvtBreakHandlerChain(void* pData); // 0x00426E80
int __stdcall SEvtDispatch(unsigned int nType, void* hWnd, unsigned int nId, SMSGHANDLER_PARAMS* pParams); // 0x00426F90
int __stdcall SEvtPushState(unsigned int nType, unsigned int nSubtype); // 0x00426370
int __stdcall SEvtRegisterHandler(unsigned int nType, HWND__* hWnd, unsigned int nId, int nFlags, SMSGHANDLER pHandler); // 0x00426420
int __stdcall SEvtUnregisterHandler(unsigned int nType, HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler); // 0x00426720
int __stdcall SEvtUnregisterType(unsigned int nType, void* hWnd); // 0x00426810
int __stdcall sub_004269C0_RegisterHandler(unsigned long dwId, void* pContext); // 0x004269C0

int __stdcall SMsgDispatchMessage(void* hWnd, unsigned int uMsg, unsigned int wParam, int lParam, int* pbUseResult, int* plResult);
int __stdcall SMsgRegisterCommand(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler);
int __stdcall SMsgRegisterKeyDown(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler);
int __stdcall SMsgRegisterKeyUp(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler);
int __stdcall SMsgRegisterMessage(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler);

static int __stdcall InternalRegister(unsigned int nType, HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler);

extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

inline void* operator new(unsigned int, void* pPlace) throw()
{
    return pPlace;
}

extern TSList<WNDREC> gWndRecList_00708860; // 0x00708860

void* gdwGlobal_007792F4; // 0x007792F4

// build: symbol ??_R0?AUWNDREC@@@8 0x00708848
// build: symbol ?SMemAlloc@@YGPAXIPBDHI@Z 0x00413020
// build: symbol ?NextLink@?$TSLink@UWNDREC@@@@QAEPAU1@H@Z 0x004203F0
// build: symbol ?Link@?$TSList@UWNDREC@@U?$TSGetLink@UWNDREC@@@@@@QAEPAU?$TSLink@UWNDREC@@@@PBUWNDREC@@@Z 0x00420520
// build: symbol ?LinkNode@?$TSList@UWNDREC@@U?$TSGetLink@UWNDREC@@@@@@QAEXPAUWNDREC@@I0@Z 0x00420540
// build: symbol ?Next@?$TSList@UWNDREC@@U?$TSGetLink@UWNDREC@@@@@@QAEPAUWNDREC@@PBU2@@Z 0x004205F0
// build: symbol ?UnlinkNode@?$TSList@UWNDREC@@U?$TSGetLink@UWNDREC@@@@@@QAEXPAUWNDREC@@@Z 0x00420650
// build: symbol ?IsEmpty@?$TSList@UWNDREC@@U?$TSGetLink@UWNDREC@@@@@@QAEHXZ 0x004206C0
// build: symbol ?RawNext@?$TSList@UWNDREC@@U?$TSGetLink@UWNDREC@@@@@@QAEPAUWNDREC@@PBU2@@Z 0x004206E0
// build: symbol ?UnlinkAll@?$TSList@UWNDREC@@U?$TSGetLink@UWNDREC@@@@@@QAEXXZ 0x00420750
// build: symbol ??1?$TSList@UWNDREC@@U?$TSGetLink@UWNDREC@@@@@@QAE@XZ 0x00420790
// build: symbol ?DeleteNode@?$TSList@UWNDREC@@U?$TSGetLink@UWNDREC@@@@@@QAEPAUWNDREC@@PAU2@@Z 0x00420970
template TSLink<WNDREC>* TSLink<WNDREC>::NextLink(int);
template TSLink<WNDREC>* TSList<WNDREC>::Link(const WNDREC*);
template void TSList<WNDREC>::LinkNode(WNDREC*, unsigned int, WNDREC*);
template WNDREC* TSList<WNDREC>::Next(const WNDREC*);
template void TSList<WNDREC>::UnlinkNode(WNDREC*);
template int TSList<WNDREC>::IsEmpty();
template WNDREC* TSList<WNDREC>::RawNext(const WNDREC*);
template TSList<WNDREC>::~TSList();

// 0x00420290
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg)
{
    return SEvtBreakHandlerChain(pMsg);
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

// 0x00420310
void* __cdecl sub_00420310()
{
    return gdwGlobal_007792F4;
}

// 0x00420320
int __stdcall sub_00420320_RegisterHandlers(void* pContext)
{
    sub_004269C0_RegisterHandler(0x534D5348, pContext);
    sub_004269C0_RegisterHandler(0x534D5349, pContext);
    sub_004269C0_RegisterHandler(0x534D534A, pContext);
    sub_004269C0_RegisterHandler(0x534D5347, pContext);
    return 1;
}

// 0x00420360
int __stdcall SMsgPushRegisterState(int nType)
{
    SEvtPushState('SMSH', nType);
    SEvtPushState('SMSI', nType);
    SEvtPushState('SMSJ', nType);
    SEvtPushState('SMSG', nType);
    return 1;
}

// 0x004203A0
int __stdcall SMsgSetDefaultWindow(void* hWnd)
{
    gdwGlobal_007792F4 = hWnd;
    return 1;
}

// 0x004208E0
void __stdcall sub_004208E0_AddWndRec(void* hWnd)
{
    WNDREC* pNode = gWndRecList_00708860.NewNode(2, 0, 0);
    pNode->hWnd = hWnd;
}

// 0x004209E0
static WNDREC* FindWindow(void* hWnd)
{
    for (WNDREC* pNode = gWndRecList_00708860.Head(); _ReadWriteBarrier(), (int)pNode > 0; pNode = pNode->m_link.m_next)
    {
        if (pNode->hWnd == hWnd)
            return pNode;
    }
    return 0;
}

// 0x00420A10
static void DeleteWindow(void* hWnd)
{
    if (hWnd == gdwGlobal_007792F4)
    {
        gdwGlobal_007792F4 = 0;
    }
    WNDREC* pRec = FindWindow(hWnd);
    if (pRec)
    {
        SEvtUnregisterType(0x534D5347, hWnd);
        SEvtUnregisterType(0x534D5348, hWnd);
        SEvtUnregisterType(0x534D534A, hWnd);
        SEvtUnregisterType(0x534D5349, hWnd);
        gWndRecList_00708860.DeleteNode(pRec);
    }
}

// 0x00420A70
static int __stdcall InternalRegister(unsigned int nType, HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
{
    VALIDATEBEGIN;
    VALIDATE(pHandler);
    VALIDATEEND;
    if (!FindWindow(hWnd))
    {
        sub_004208E0_AddWndRec(hWnd);
    }
    return nValid ? SEvtRegisterHandler(nType, hWnd, nId, 0, pHandler) : 0;
}

// 0x00420AB0
static int __stdcall InternalUnregister(unsigned int nType, HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
{
    if (!FindWindow(hWnd))
    {
        sub_004208E0_AddWndRec(hWnd);
    }
    return SEvtUnregisterHandler(nType, hWnd, nId, pHandler);
}

// 0x00420AE0
int sub_00420AE0_UnregisterAllWindows()
{
    while (WNDREC* pRec = gWndRecList_00708860.Head())
    {
        DeleteWindow(pRec->hWnd);
    }
    return 1;
}

// 0x00420B00
int __stdcall SMsgDispatchMessage(void* hWnd, unsigned int uMsg, unsigned int wParam, int lParam, int* pbUseResult, int* plResult)
{
    if (pbUseResult)
    {
        *pbUseResult = 0;
    }
    if (plResult)
    {
        *plResult = 0;
    }
    SMSGHANDLER_PARAMS tParams;
    tParams.hWnd = hWnd;
    tParams.uMessage = uMsg;
    tParams.wParam = wParam;
    tParams.lParam = lParam;
    if (uMsg == 0x111)
    {
        tParams.dwCommandSource = wParam >> 0x10;
    }
    else
    {
        tParams.dwCommandSource = 0;
    }
    tParams.bReturn = 0;
    tParams.lResult = 0;
    void* hTarget = hWnd;
    for (;;)
    {
        SEvtDispatch(0x534D5347, hTarget, uMsg, &tParams);
        if (uMsg == 0x111)
        {
            SEvtDispatch(0x534D5348, hTarget, (unsigned short)wParam, &tParams);
        }
        else if (uMsg == 0x100)
        {
            SEvtDispatch(0x534D5349, hTarget, wParam, &tParams);
        }
        else if (uMsg == 0x101)
        {
            SEvtDispatch(0x534D534A, hTarget, wParam, &tParams);
        }
        if (!hTarget || hTarget != gdwGlobal_007792F4)
        {
            break;
        }
        hTarget = 0;
    }
    if (uMsg == 0x82)
    {
        DeleteWindow(hWnd);
    }
    if (pbUseResult)
    {
        *pbUseResult = tParams.bReturn;
    }
    if (plResult)
    {
        *plResult = tParams.lResult;
    }
    return 1;
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

// 0x00420CF0
int __stdcall sub_00420CF0_WindowProc(void* hWnd, unsigned int uMsg, unsigned int wParam, int lParam)
{
    int bUseResult = 0;
    int lResult = 0;
    if (SMsgDispatchMessage(hWnd, uMsg, wParam, lParam, &bUseResult, &lResult) && bUseResult)
        return lResult;
    return DefWindowProcA(hWnd, uMsg, wParam, lParam);
}

// 0x00420D50
int __stdcall SMsgGetDispatcher(int a1)
{
    VALIDATEBEGIN;
    VALIDATE(!a1);
    VALIDATEEND;
    return nValid ? (int)&sub_00420CF0_WindowProc : 0;
}

// 0x00420D90
WNDREC* __fastcall DRLGPRESET_GetLinkRawNext(TSLink<WNDREC>* pLink)
{
    return pLink->m_next;
}
