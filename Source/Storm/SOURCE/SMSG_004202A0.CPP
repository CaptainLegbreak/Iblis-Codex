#include "D2GameTypes.h"
#include "Storm.h"
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
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC
extern "C" __declspec(dllimport) int __stdcall DispatchMessageA(const D2WinMsgStrc* pMsg);                  // 0x006CC478
extern "C" __declspec(dllimport) int __stdcall TranslateMessage(const D2WinMsgStrc* pMsg);                  // 0x006CC47C
extern "C" __declspec(dllimport) int __stdcall PeekMessageA(D2WinMsgStrc* pMsg, void* hWnd, unsigned int nMin, unsigned int nMax, unsigned int nRemove); // 0x006CC480
extern "C" __declspec(dllimport) int __stdcall GetMessageA(D2WinMsgStrc* pMsg, void* hWnd, unsigned int nMin, unsigned int nMax); // 0x006CC484
typedef int (__stdcall* SMSGIDLEPROC)(int nCount);

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
