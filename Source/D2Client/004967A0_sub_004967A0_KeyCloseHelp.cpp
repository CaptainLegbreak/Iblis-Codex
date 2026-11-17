struct SMSGHANDLER_PARAMS;

void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
int gbHelpUiOpened_007BEF00;                                                                                // 0x007BEF00

// 0x004967A0
void __stdcall sub_004967A0_KeyCloseHelp(SMSGHANDLER_PARAMS* pMsg)
{
    sub_00455F20(0x21, 1, 0);
    if (gbHelpUiOpened_007BEF00)
    {
        sub_00455F20(0x15, 1, 0);
        gbHelpUiOpened_007BEF00 = 0;
    }
}
