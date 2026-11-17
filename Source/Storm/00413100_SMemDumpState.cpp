extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szBuffer, const char* szFormat, ...);
int __stdcall SErrDisplayError(unsigned int nErrorCode, const char* szFile, int nLine, const char* szDescription, int bRecoverable, unsigned int nExitCode);
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);
void __cdecl sub_00411CD0_InitHeaps();
extern int gnFlag1_007784C0;
extern int gbHeapInitialized_007788D0;                                                                      // 0x007788D0

struct D2SMemHeapInfoStrc
{
    unsigned int dwSize;
    unsigned int hHeap;
    char szName[0x104];
    int nLine;
    unsigned int dwUnk110;
    unsigned int dwSizeA;
    unsigned int dwSizeB;
    unsigned int dwUnk11C;
    unsigned int nBlocks;
    unsigned int dwSizeC;
};

typedef void (__stdcall* SMEMDUMPCALLBACK)(void* pParam, const char* szText);
int __stdcall SMemFindNextHeap(unsigned int hPrev, unsigned int* phNext, D2SMemHeapInfoStrc* pInfo);        // 0x004124B0

static __declspec(noinline) void __stdcall sub_004117A0_SetAndShowError(const char* szFile, int nLine, unsigned int nError)
{
    sub_0041C340_SetLastError(nError);
    if (gnFlag1_007784C0)
    {
        SErrDisplayError(nError, szFile, nLine, 0, 1, 1);
    }
}

#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

// 0x00413100
int __stdcall SMemDumpState(SMEMDUMPCALLBACK pfnCallback, void* pParam)
{
    if (!gbHeapInitialized_007788D0)
    {
        sub_00411CD0_InitHeaps();
        if (!gbHeapInitialized_007788D0)
        {
            sub_004117A0_SetAndShowError("SMemDumpState()", -1, 0x8510007D);
            return 0;
        }
    }
    VALIDATEBEGIN;
    VALIDATE(pfnCallback);
    VALIDATEEND;
    D2SMemHeapInfoStrc tInfo;
    tInfo.dwSize = 0x128;
    unsigned int hHeap = 0;
    if (SMemFindNextHeap(0, &hHeap, &tInfo))
    {
        do
        {
            char szText[0x100];
            wsprintfA(szText, "%s:%d  blocks=%u  %uk/%uk/%uk", tInfo.szName, tInfo.nLine, tInfo.nBlocks,
                (tInfo.dwSizeC + 0x200) >> 10, (tInfo.dwSizeA + 0x200) >> 10, (tInfo.dwSizeB + 0x200) >> 10);
            pfnCallback(pParam, szText);
        } while (SMemFindNextHeap(hHeap, &hHeap, &tInfo));
    }
    return nValid ? 1 : 0;
}
