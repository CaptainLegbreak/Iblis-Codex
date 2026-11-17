struct SMSGHANDLER_PARAMS;

int __fastcall sub_00456300_CloseUIVars(int bArg1, int nArg2);                                              // 0x00456300

// 0x00498C00
void __stdcall sub_00498C00_CloseOnSpace(SMSGHANDLER_PARAMS* pMsg)
{
    sub_00456300_CloseUIVars(1, 0);
}
