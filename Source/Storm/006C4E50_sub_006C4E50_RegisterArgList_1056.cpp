void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode); // 0x0041C340
int __stdcall SCmdRegisterArgument(unsigned int dwFlags, unsigned int dwId, const char* szName, void* pVariable, unsigned int nBytes, int bSet, void* pfnCallback, void* pParam); // 0x006C4580
#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

struct D2CmdArg006C4E50Strc
{
    unsigned int dwFlags;
    unsigned int dwId;
    const char* szName;
    void* pParam;
};

// 0x006C4E50
int __stdcall sub_006C4E50_RegisterArgList(D2CmdArg006C4E50Strc* pArgs, unsigned int nCount)
{
    VALIDATEBEGIN;
    VALIDATE(pArgs);
    VALIDATEEND;
    for (unsigned int i = 0; i < nCount; ++i, ++pArgs)
    {
        if (!SCmdRegisterArgument(pArgs->dwFlags, pArgs->dwId, pArgs->szName, 0, 0, 1, (void*)-1, pArgs->pParam))
        {
            return 0;
        }
    }
    return nValid ? 1 : 0;
}
