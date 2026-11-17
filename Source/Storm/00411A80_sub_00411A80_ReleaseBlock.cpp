struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2FogBlockStrc
{
    D2FogBlockStrc* pNext;
    unsigned int dwSize;
    int unk0x08[3];
    int bInUse;
};

extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* pAddress, unsigned long dwSize, unsigned long dwFreeType); // 0x006CC220
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock);    // 0x006CC210
extern "C" __declspec(dllimport) void* __stdcall GetModuleHandleA(const char* szModuleName);                // 0x006CC198
extern "C" __declspec(dllimport) unsigned long __stdcall GetModuleFileNameA(void* hModule, char* szFileName, unsigned long nSize); // 0x006CC1BC

int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
const char* __stdcall SStrChrR(const char* szString, char nChar);                                           // 0x004134D0
unsigned int __stdcall sub_00413800(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x00413800

extern unsigned long gnFlag2_00776CBC;                                                                      // 0x00776CBC
extern D2CriticalSectionStrc gaFreeBlockLocks_00776CC0[0x100];                                              // 0x00776CC0
extern unsigned long gnFlag0_007784C4;                                                                      // 0x007784C4
extern int gbHeapInitialized_007788D0;                                                                      // 0x007788D0
extern char gszBasePath_00778F28[];                                                                         // 0x00778F28

// 0x00411A80
void __fastcall sub_00411A80_ReleaseBlock(D2FogBlockStrc** ppLink)
{
    D2FogBlockStrc* pBlock = *ppLink;
    *ppLink = pBlock->pNext;
    VirtualFree(pBlock, 0, 0x8000);
}

// 0x00411CD0
void __cdecl sub_00411CD0_InitHeaps()
{
    if (!gbHeapInitialized_007788D0)
    {
        SRegLoadValue("Internal", "Debug Memory", 0, &gnFlag0_007784C4);
        SRegLoadValue("Internal", "Protect Memory", 0, &gnFlag2_00776CBC);
        D2CriticalSectionStrc* pLock = gaFreeBlockLocks_00776CC0;
        int n = 0x100;
        do
        {
            InitializeCriticalSection(pLock);
            ++pLock;
        }
        while (--n);
        gbHeapInitialized_007788D0 = 1;
    }
}

// 0x004158E0
void __cdecl sub_004158E0_InitBasePath()
{
    GetModuleFileNameA(GetModuleHandleA(0), gszBasePath_00778F28, 0x104);
    char* pSeparator = (char*)SStrChrR(gszBasePath_00778F28, '\\');
    if (pSeparator)
        *pSeparator = 0;
    sub_00413800(gszBasePath_00778F28, "\\", 0x104);
}
