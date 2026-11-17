struct HWND__;
typedef int (__stdcall* SMSGHANDLER)(void* pParams);

void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);
void __stdcall sub_004208E0_AddWndRec(int nValue);
int __stdcall sub_00420CF0_WindowProc(void* hWnd, unsigned int uMsg, unsigned int wParam, int lParam);
int __fastcall sub_004209E0_FindWndRec(HWND__* hWnd);
int __stdcall SEvtRegisterHandler(unsigned int nType, HWND__* hWnd, unsigned int nId, int nFlags, SMSGHANDLER pHandler); // 0x00426420

#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

// 0x00420A70
static __declspec(noinline) int __stdcall sub_00420A70_RegisterHandler(unsigned int nType, HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
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
