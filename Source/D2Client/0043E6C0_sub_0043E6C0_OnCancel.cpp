struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    unsigned int lParam;
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

int __fastcall sub_004F9190();                                                            // 0x004F9190
void __cdecl sub_0043EA20_Wait();                                                                           // 0x0043EA20

int gbDone_0077BDA0;                                                                                        // 0x0077BDA0

// 0x0043E6C0
int __stdcall sub_0043E6C0_OnCancel(SMSGHANDLER_PARAMS* pMsg)
{
    gbDone_0077BDA0 = 4;
    sub_004F9190();
    return 1;
}

// 0x0043EB00
int __stdcall sub_0043EB00_OnWait(SMSGHANDLER_PARAMS* pMsg)
{
    sub_0043EA20_Wait();
    return 1;
}
