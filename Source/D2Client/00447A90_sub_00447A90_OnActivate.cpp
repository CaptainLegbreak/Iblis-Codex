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

void __cdecl sub_00444020();                                                                                // 0x00444020
void __cdecl sub_0043D990_ActivateEdit();                                                                   // 0x0043D990

// 0x00447A90
int __stdcall sub_00447A90_OnActivate(SMSGHANDLER_PARAMS* pMsg)
{
    sub_00444020();
    sub_0043D990_ActivateEdit();
    return 1;
}
