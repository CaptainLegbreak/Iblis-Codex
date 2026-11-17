struct HWND__;
typedef int (__stdcall* SMSGHANDLER)(void* pParams);

int __fastcall sub_004209E0_FindWndRec(HWND__* hWnd);                                                       // 0x004209E0
void __stdcall sub_004208E0_AddWndRec(HWND__* hWnd);                                                        // 0x004208E0
int __stdcall SEvtUnregisterHandler(unsigned int nType, HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler); // 0x00426720

// 0x00420AB0
static __declspec(noinline) int __stdcall sub_00420AB0_UnregisterHandler(unsigned int nType, HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
{
    if (!sub_004209E0_FindWndRec(hWnd))
    {
        sub_004208E0_AddWndRec(hWnd);
    }
    return SEvtUnregisterHandler(nType, hWnd, nId, pHandler);
}

// 0x00420C70
int __stdcall SMsgUnregisterCommand(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
{
    return sub_00420AB0_UnregisterHandler(0x534D5348, hWnd, nId, pHandler);
}

// 0x00420C90
int __stdcall SMsgUnregisterKeyDown(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
{
    return sub_00420AB0_UnregisterHandler(0x534D5349, hWnd, nId, pHandler);
}

// 0x00420CB0
int __stdcall SMsgUnregisterKeyUp(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
{
    return sub_00420AB0_UnregisterHandler(0x534D534A, hWnd, nId, pHandler);
}

// 0x00420CD0
int __stdcall SMsgUnregisterMessage(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
{
    return sub_00420AB0_UnregisterHandler(0x534D5347, hWnd, nId, pHandler);
}
