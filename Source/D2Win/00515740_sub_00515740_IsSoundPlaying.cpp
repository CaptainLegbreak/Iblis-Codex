struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2DSoundBufferStrc;

struct D2DSoundBufferVtblStrc
{
    void* unk0x00[9];
    long (__stdcall* GetStatus)(D2DSoundBufferStrc* pThis, unsigned long* pdwStatus);
};

struct D2DSoundBufferStrc
{
    D2DSoundBufferVtblStrc* lpVtbl;
};

struct D2SoundStrc
{
    D2DSoundBufferStrc* pBuffer;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC218

extern D2CriticalSectionStrc gSoundCriticalSection_0088174C;                                                // 0x0088174C

// 0x00515740
int __fastcall sub_00515740_IsSoundPlaying(D2SoundStrc* pSound)
{
    D2_ASSERT(pSound && pSound->pBuffer, 0x2B0);
    EnterCriticalSection(&gSoundCriticalSection_0088174C);
    unsigned long dwStatus;
    if (pSound->pBuffer->lpVtbl->GetStatus(pSound->pBuffer, &dwStatus) < 0)
    {
        LeaveCriticalSection(&gSoundCriticalSection_0088174C);
        return 0;
    }
    LeaveCriticalSection(&gSoundCriticalSection_0088174C);
    const unsigned char bPlaying = dwStatus & 1;
    return bPlaying;
}
