struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2LogMsgNodeStrc
{
    D2LogMsgNodeStrc* pPrev;
    D2LogMsgNodeStrc* pNext;
};

struct D2LogMessageStrc : D2LogMsgNodeStrc
{
    char unk0x08[0x1C];
};

class CCritSect
{
public:
    CCritSect();                                                                                            // 0x0040EB50
    ~CCritSect();                                                                                           // 0x0040EB60
    void Enter();
    void Leave();

    D2CriticalSectionStrc tLock;
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214

// 0x0040E9E0
unsigned int __fastcall sub_0040E9E0_GetCpuidEdx(unsigned int nFunction)
{
    unsigned int nEdx;
    __asm
    {
        mov eax, nFunction
        cpuid
        mov nEdx, edx
    }
    return nEdx;
}

// 0x0040EB40
char* __fastcall sub_0040EB40_GetMessageData(D2LogMessageStrc* pMessage)
{
    return pMessage->unk0x08;
}

// 0x0040EB70
void CCritSect::Enter()
{
    EnterCriticalSection(&tLock);
}

// 0x0040EB80
void CCritSect::Leave()
{
    LeaveCriticalSection(&tLock);
}
