struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134
extern "C" __declspec(dllimport) void* __stdcall GetModuleHandleA(const char* szModuleName);                // 0x006CC198
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long* pValue);                         // 0x006CC204
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long* pValue);                         // 0x006CC208
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock);    // 0x006CC210
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void* __stdcall CreateEventA(void* pAttributes, int bManualReset, int bInitialState, const char* szName); // 0x006CC228
extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* pAttributes, unsigned long nStackSize, unsigned long (__stdcall* pfnStart)(void* pParam), void* pParam, unsigned long dwFlags, unsigned long* pThreadId); // 0x006CC250
extern "C" __declspec(dllimport) int __stdcall SetThreadPriority(void* hThread, int nPriority);             // 0x006CC264
extern "C" void __cdecl __debugbreak();

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650
unsigned long __stdcall sub_0041A550_ThreadProc(void* pParam);                                              // 0x0041A550
void __stdcall sub_0041C0F0_AppendExeMsgSource(unsigned short wFacility);                                   // 0x0041C0F0

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

    D2StormLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormLinkStrc*)(m_next + nLinkOffset);
    }
    char* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
    }
    void Unlink()
    {
        if (m_prevlink)
        {
            NextLink(-1)->m_prevlink = m_prevlink;
            m_prevlink->m_next = m_next;
            m_prevlink = 0;
            m_next = 0;
        }
    }
};

struct D2StormNodeListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    char* Head()
    {
        return m_terminator.Next();
    }
    void sub_0041EE40_UnlinkAll();
};

struct D2StormArchiveRecStrc
{
    D2StormLinkStrc f_0;
    char unk0x08[0x104];
    void* hFile;
    char unk0x110[0xC];
    int nUnk0x11C;
    char unk0x120[0x8];
    void* pBuffer0x128;
    char unk0x12C[0xC];
    void* pBuffer0x138;
    void* pBuffer0x13C;
    void* pBuffer0x140;
    char unk0x144[0x4];
    int nRefCount;
    int bNoClose;
    int bMapped;
    char unk0x154[0x108];

    ~D2StormArchiveRecStrc();
    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, "delete", -1, 0);
    }
};

struct D2StormFileRecStrc
{
    D2StormLinkStrc f_0;
    char unk0x08[0x104];
    void* pBuffer0x10C;
    void* hFile;
    D2StormArchiveRecStrc* f_114;
    char unk0x118[0x14];
    void* pBuffer0x12C;
    char unk0x130[0x8];
    void* pBuffer0x138;
    char unk0x13C[0x1C];

    ~D2StormFileRecStrc();
};

struct D2StormHashBufferStrc
{
    unsigned int nSignSize;
    int nModulusSize;
    unsigned int nUsed;
    unsigned int nWindow;
};

struct D2StormHuffOutputStrc
{
    unsigned char* pOutputStart;
    unsigned int f_4;
    unsigned char* pOutput;
    unsigned int nBitBuffer;
    unsigned int nBitCount;

    void sub_0041D9A0_Flush();
};

class THuffmannTree
{
public:
    THuffmannTree();                                                                                        // 0x0041F4A0

    unsigned int adwData[0x3474 / 4];
};

struct D2StormHuffLinkSlotStrc
{
    int nData[3];
};

struct D2StormHuffTreeStrc : THuffmannTree
{
    D2StormHuffLinkSlotStrc f_3474[0x80];

    D2StormHuffTreeStrc();
};

struct D2StormHashCtxStrc
{
    unsigned int nBitCountLo;
    unsigned int nBitCountHi;
    unsigned int nState[5];
    unsigned char pBlock[64];

    void sub_00425D90_Init();
};

extern D2StormNodeListStrc gStormList_00708354;                                                             // 0x00708354
extern long gnErrorLockUsers_0070841C;                                                                      // 0x0070841C
extern void* ghStormThread_00779034;                                                                        // 0x00779034
unsigned long gdwStormThreadId_00779040;                                                                    // 0x00779040
extern void* ghStormEvent_00779054;                                                                         // 0x00779054
extern int gnStormDirectFlags_00779058;                                                                     // 0x00779058
D2CriticalSectionStrc gErrorStateLock_007790CC;                                                             // 0x007790CC
void* gpCallback_007790F8;                                                                                  // 0x007790F8

// 0x00418A50
D2StormArchiveRecStrc::~D2StormArchiveRecStrc()
{
    if (!this || !bMapped)
    {
        if (hFile != (void*)-1 && !bNoClose)
            CloseHandle(hFile);
        if (pBuffer0x128)
            SMemFree(pBuffer0x128, ".\\SOURCE\\SFILE.CPP", 0x260, 0);
        if (pBuffer0x138)
            SMemFree(pBuffer0x138, ".\\SOURCE\\SFILE.CPP", 0x261, 0);
        if (pBuffer0x13C)
            SMemFree(pBuffer0x13C, ".\\SOURCE\\SFILE.CPP", 0x269, 0);
        if (pBuffer0x140)
            SMemFree(pBuffer0x140, ".\\SOURCE\\SFILE.CPP", 0x26A, 0);
    }
    f_0.Unlink();
}

// 0x00418B50
int __cdecl sub_00418B50()
{
    int nFlags = 0;
    if (gnStormDirectFlags_00779058 & 1)
        nFlags |= 1;
    if (gnStormDirectFlags_00779058 & 2)
        nFlags |= 2;
    if (!gStormList_00708354.Head() && !gnStormDirectFlags_00779058)
        nFlags |= 1;
    return nFlags;
}

// 0x00419070
D2StormFileRecStrc::~D2StormFileRecStrc()
{
    if (hFile != (void*)-1)
        CloseHandle(hFile);
    if (f_114)
        f_114->nUnk0x11C = 0;
    if (pBuffer0x12C)
        SMemFree(pBuffer0x12C, ".\\SOURCE\\SFILE.CPP", 0x14B, 0);
    if (pBuffer0x138)
        SMemFree(pBuffer0x138, ".\\SOURCE\\SFILE.CPP", 0x14C, 0);
    D2StormArchiveRecStrc* pArch = f_114;
    if (pArch && !--pArch->nRefCount)
        delete pArch;
    if (pBuffer0x10C)
        SMemFree(pBuffer0x10C, ".\\SOURCE\\SFILE.CPP", 0x14E, 0);
    f_0.Unlink();
}

// 0x0041A880
void __cdecl sub_0041A880_StartThread()
{
    if (!ghStormThread_00779034)
    {
        ghStormEvent_00779054 = CreateEventA(0, 0, 0, 0);
        ghStormThread_00779034 = CreateThread(0, 0, sub_0041A550_ThreadProc, 0, 0, &gdwStormThreadId_00779040);
        SetThreadPriority(ghStormThread_00779034, 1);
    }
}

// 0x0041BEF0
void* __cdecl sub_0041BEF0_GetExeModule()
{
    return GetModuleHandleA(0);
}

// 0x0041C0E0
void __fastcall sub_0041C0E0_SetCallback(void* pCallback)
{
    gpCallback_007790F8 = pCallback;
}

// 0x0041C140
void __cdecl sub_0041C140_AppendExeMsgSources()
{
    sub_0041C0F0_AppendExeMsgSource(0x510);
    sub_0041C0F0_AppendExeMsgSource(0x876);
    sub_0041C0F0_AppendExeMsgSource(0x878);
}

// 0x0041C160
void __cdecl sub_0041C160_DebugBreak()
{
    __debugbreak();
}

// 0x0041C1A0
void __cdecl sub_0041C1A0_LockErrorState()
{
    if (!InterlockedIncrement(&gnErrorLockUsers_0070841C))
        InitializeCriticalSection(&gErrorStateLock_007790CC);
    else
        InterlockedDecrement(&gnErrorLockUsers_0070841C);
    EnterCriticalSection(&gErrorStateLock_007790CC);
}

// 0x0041C1E0
void __cdecl sub_0041C1E0_UnlockErrorState()
{
    LeaveCriticalSection(&gErrorStateLock_007790CC);
}

// 0x0041D410
unsigned int __fastcall sub_0041D410_GetWindow(D2StormHashBufferStrc* pBuffer)
{
    return pBuffer->nWindow;
}

// 0x0041D9A0
void D2StormHuffOutputStrc::sub_0041D9A0_Flush()
{
    while (nBitCount)
    {
        if (f_4)
        {
            *pOutput++ = (unsigned char)nBitBuffer;
            f_4--;
        }
        nBitBuffer >>= 8;
        nBitCount -= nBitCount > 8 ? 8 : nBitCount;
    }
}

// 0x0041EE40
void D2StormNodeListStrc::sub_0041EE40_UnlinkAll()
{
    while (char* pNode = Head())
        ((D2StormLinkStrc*)pNode)->Unlink();
}

// 0x0041F950
D2StormHuffTreeStrc::D2StormHuffTreeStrc()
{
    for (int i = 0; i < 0x80; ++i)
        f_3474[i].nData[0] = 0;
}

// 0x00425D90
void D2StormHashCtxStrc::sub_00425D90_Init()
{
    nBitCountLo = 0;
    nBitCountHi = 0;
    nState[0] = 0x67452301;
    nState[1] = 0xEFCDAB89;
    nState[2] = 0x98BADCFE;
    nState[3] = 0x10325476;
    nState[4] = 0xC3D2E1F0;
}

#include "gen/data/Source/Storm/00418A50_D2StormArchiveRecStrc_dtor.inc"
