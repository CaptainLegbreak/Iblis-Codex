struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    int wParam;
    unsigned short nXpos;
    unsigned short nYpos;
    unsigned int nNotifyCode;
    void* pExtra;
};

void __cdecl sub_0044C060_Refresh();                                                                        // 0x0044C060
int __stdcall D2GFX_Release();                                                                              // 0x004F5050
int __stdcall WINDOW_Destroy();                                                                             // 0x004F5900

// 0x0044C0F0
void __stdcall sub_0044C0F0_OnLButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    sub_0044C060_Refresh();
}

// 0x0044C850
void __stdcall sub_0044C850(int nArg1, int nArg2, int nArg3)
{
    WINDOW_Destroy();
    D2GFX_Release();
}
