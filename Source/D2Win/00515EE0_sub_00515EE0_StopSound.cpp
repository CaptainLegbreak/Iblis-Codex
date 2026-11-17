extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2DSoundBufferStrc
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppvObject) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall GetCaps(void* pCaps) = 0;
    virtual long __stdcall GetCurrentPosition(unsigned long* pdwPlay, unsigned long* pdwWrite) = 0;
    virtual long __stdcall GetFormat(void* pFormat, unsigned long dwSize, unsigned long* pdwWritten) = 0;
    virtual long __stdcall GetVolume(long* plVolume) = 0;
    virtual long __stdcall GetPan(long* plPan) = 0;
    virtual long __stdcall GetFrequency(unsigned long* pdwFrequency) = 0;
    virtual long __stdcall GetStatus(unsigned long* pdwStatus) = 0;
    virtual long __stdcall Initialize(void* pDirectSound, const void* pDesc) = 0;
    virtual long __stdcall Lock(unsigned long dwOffset, unsigned long dwBytes, void** ppv1, unsigned long* pdw1, void** ppv2, unsigned long* pdw2, unsigned long dwFlags) = 0;
    virtual long __stdcall Play(unsigned long dwReserved, unsigned long dwPriority, unsigned long dwFlags) = 0;
    virtual long __stdcall SetCurrentPosition(unsigned long dwPosition) = 0;
    virtual long __stdcall SetFormat(const void* pFormat) = 0;
    virtual long __stdcall SetVolume(long lVolume) = 0;
    virtual long __stdcall SetPan(long lPan) = 0;
    virtual long __stdcall SetFrequency(unsigned long dwFrequency) = 0;
    virtual long __stdcall Stop() = 0;
    virtual long __stdcall Unlock(void* pv1, unsigned long dw1, void* pv2, unsigned long dw2) = 0;
    virtual long __stdcall Restore() = 0;
};

struct D2SoundStrc
{
    D2DSoundBufferStrc* pBuffer;
    int unk0x04[6];
    int bPlaying;
    int unk0x20[5];
    unsigned int dwFlags;
    int f_38;
    int unk0x3C[3];
    void* hStream;
};

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);                        // 0x006CC258
extern D2CriticalSectionStrc gSoundLock_0088174C;                                                           // 0x0088174C
void __fastcall sub_00515E40_CloseSoundStream(D2SoundStrc* pSound);                                         // 0x00515E40

#define DSBSTATUS_BUFFERLOST 0x00000002
#define DSERR_BUFFERLOST ((long)0x88780096)

// 0x00515EE0
void __fastcall sub_00515EE0_StopSound(D2SoundStrc* pSound)
{
    D2_ASSERT(pSound && pSound->pBuffer, 658);
    EnterCriticalSection(&gSoundLock_0088174C);
    if (pSound->hStream)
    {
        sub_00515E40_CloseSoundStream(pSound);
    }
    pSound->pBuffer->Stop();
    pSound->bPlaying = 0;
    LeaveCriticalSection(&gSoundLock_0088174C);
}

// 0x00515FD0
int __fastcall sub_00515FD0_RestoreLostBuffer(D2SoundStrc* pSound)
{
    D2_ASSERT(pSound->pBuffer, 290);
    EnterCriticalSection(&gSoundLock_0088174C);
    unsigned long dwStatus;
    if (pSound->pBuffer->GetStatus(&dwStatus) < 0)
    {
        LeaveCriticalSection(&gSoundLock_0088174C);
        return 0;
    }

    if (dwStatus & DSBSTATUS_BUFFERLOST)
    {
        for (;;)
        {
            const long hResult = pSound->pBuffer->Restore();
            if (hResult == DSERR_BUFFERLOST)
            {
                Sleep(10);
                continue;
            }
            if (hResult >= 0)
            {
                break;
            }
        }
        sub_00515EE0_StopSound(pSound);
    }

    LeaveCriticalSection(&gSoundLock_0088174C);
    return 1;
}
