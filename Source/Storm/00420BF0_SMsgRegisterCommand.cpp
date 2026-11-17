struct HWND__;
typedef int (__stdcall* SMSGHANDLER)(void* pParams);

int __fastcall sub_004209E0_FindWndRec(HWND__* hWnd);                                                       // 0x004209E0
void __stdcall sub_004208E0_AddWndRec(HWND__* hWnd);                                                        // 0x004208E0
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);                                          // 0x0041C340
int __stdcall SEvtRegisterHandler(unsigned int nType, HWND__* hWnd, unsigned int nId, int nFlags, SMSGHANDLER pHandler); // 0x00426420

// calling-convention shim (not game code)
static __declspec(noinline) int __stdcall sub_00420A70_RegisterHandler(unsigned int nType, HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
{
    if (!pHandler)
    {
        sub_0041C340_SetLastError(0x57);
        return 0;
    }
    if (!sub_004209E0_FindWndRec(hWnd))
    {
        sub_004208E0_AddWndRec(hWnd);
    }
    return SEvtRegisterHandler(nType, hWnd, nId, 0, pHandler);
}

// 0x00420BF0
int __stdcall SMsgRegisterCommand(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
{
    return sub_00420A70_RegisterHandler(0x534D5348, hWnd, nId, pHandler);
}

// 0x00420C10
int __stdcall SMsgRegisterKeyDown(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
{
    return sub_00420A70_RegisterHandler(0x534D5349, hWnd, nId, pHandler);
}

// 0x00420C30
int __stdcall SMsgRegisterKeyUp(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
{
    return sub_00420A70_RegisterHandler(0x534D534A, hWnd, nId, pHandler);
}

// 0x00420C50
int __stdcall SMsgRegisterMessage(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
{
    return sub_00420A70_RegisterHandler(0x534D5347, hWnd, nId, pHandler);
}
