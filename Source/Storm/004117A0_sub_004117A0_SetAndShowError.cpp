int __stdcall SErrDisplayError(unsigned int nErrorCode, const char* szFile, int nLine, const char* szDescription, int bRecoverable, unsigned int nExitCode); // 0x0041CAF0
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);                                          // 0x0041C340
extern int gnFlag1_007784C0;                                                                                // 0x007784C0

// 0x004117A0
static void __stdcall sub_004117A0_SetAndShowError(const char* szFile, int nLine, unsigned int nError)
{
    sub_0041C340_SetLastError(nError);
    if (gnFlag1_007784C0)
    {
        SErrDisplayError(nError, szFile, nLine, 0, 1, 1);
    }
}

int __stdcall sub_L01_Emit_004117A0(const char* szFile, int nArg)
{
    if (nArg)
    {
        sub_004117A0_SetAndShowError(szFile, -1, 0x8510007D);
        return 0;
    }
    return nArg + 5;
}
