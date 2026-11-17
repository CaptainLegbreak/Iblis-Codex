extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define MAX_MSG_SIZE 516

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2NetPacketRecStrc
{
    unsigned char data[MAX_MSG_SIZE];
    int nPacketSize;
    unsigned long dwTickCount;
    D2NetPacketRecStrc* pNext;
};

struct QServer;

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
int __stdcall FOG_10175(QServer* pServer, const unsigned char* pBuffer, int nBufferSize, int a4);           // 0x006BF370

extern QServer* gpServer;                                                                                   // 0x00882D08
extern int gnConnectionMode_00882D10;                                                                       // 0x00882D10

// 0x0052B690
int __fastcall sub_0052B690_SendToServer(const unsigned char* pBuffer, unsigned short nSize)
{
    D2_ASSERT(nSize <= MAX_MSG_SIZE, 0x217);
    return FOG_10175(gpServer, pBuffer, nSize, 0) != 0;
}

// 0x0052B7E0
int __fastcall NET_IsLocalConnection()
{
    if (gnConnectionMode_00882D10 == 1)
    {
        return 1;
    }
    return gnConnectionMode_00882D10 == 2;
}

// 0x0052B810
void __fastcall NET_SetConnectionMode(int nConnectionMode)
{
    gnConnectionMode_00882D10 = nConnectionMode;
}

// 0x0052B8B0
int __fastcall NET_FreePacketList(D2CriticalSectionStrc* pCriticalSection, D2NetPacketRecStrc** ppPacketList)
{
    EnterCriticalSection(pCriticalSection);

    while (*ppPacketList)
    {
        D2NetPacketRecStrc* pPacket = *ppPacketList;
        *ppPacketList = pPacket->pNext;
        FOG_Free(pPacket, ".\\SRC\\D2Net.cpp", 0x5D, 0);
    }

    LeaveCriticalSection(pCriticalSection);
    return 1;
}
