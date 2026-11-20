extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);
#pragma intrinsic(memset)
extern "C" __declspec(dllimport) void* __stdcall GetCurrentThread();

struct D2ContextStrc
{
    unsigned long dwContextFlags;
    char unk0x04[0xB0];
    unsigned long dwEbp;
    unsigned long dwEip;
    unsigned long dwSegCs;
    unsigned long dwEFlags;
    unsigned long dwEsp;
    unsigned long dwSegSs;
    unsigned char pExtendedRegisters[0x200];
};

int __fastcall QuickStackWalk(const char* szPrefix, void* hThread, D2ContextStrc* pContext); // 0x0040C7A0

// 0x0040D7D0
void __fastcall sub_0040D7D0_WalkCurrentStack(const char* szPrefix)
{
    void* hThread;
    {
        D2ContextStrc tContext;
        unsigned long dwEip;
        unsigned long dwEsp;
        unsigned long dwEbp;

        memset(&tContext, 0, sizeof(tContext));
        tContext.dwContextFlags = 0x10007;
        __asm
        {
            call next
        next:
            pop dwEip
            push esp
            pop dwEsp
            push ebp
            pop dwEbp
        }
        tContext.dwEip = dwEip;
        tContext.dwEsp = dwEsp;
        tContext.dwEbp = dwEbp;
        hThread = GetCurrentThread();
        QuickStackWalk(szPrefix, hThread, &tContext);
    }
}
