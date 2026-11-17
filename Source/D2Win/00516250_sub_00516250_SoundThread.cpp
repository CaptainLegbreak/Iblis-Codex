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
};

struct D2SoundStrc
{
    D2DSoundBufferStrc* pBuffer;
    unsigned long nBufferSize;
    unsigned long nHalfSize;
    int unk0x0C[3];
    unsigned long nEndPosition;
    int bPlaying;
    unsigned long nPosition;
    unsigned long nFillPosition;
    int bSecondHalf;
    int bStreamed;
    int nFillState;
    unsigned int dwFlags;
    int nVolume;
    int unk0x3C;
    int bNoClear;
    int unk0x44;
    void* hStream;
    int bFading;
    int nFadeFrom;
    int nFadeTo;
    int nFadeStart;
    int nFadeEnd;
};

struct D2SoundNodeStrc
{
    D2SoundStrc* pSound;
    D2SoundNodeStrc* pNext;
};

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" __declspec(dllimport) int __stdcall IsIconic(void* hWnd);                                        // 0x006CC50C

extern D2CriticalSectionStrc gSoundLock_0088174C;                                                           // 0x0088174C
extern D2SoundNodeStrc* gpSoundList_00881808;                                                               // 0x00881808
extern void* ghSoundEvent_0088180C;                                                                         // 0x0088180C
extern int gbIconic_00881814;                                                                               // 0x00881814

extern "C" void* __cdecl sub_004F59A0_GetHwnd();                                                            // 0x004F59A0
int __cdecl sub_00514920();                                                                                 // 0x00514920
int __cdecl sub_00514840();                                                                                 // 0x00514840
void __cdecl sub_00514990_PickRandomChannel();                                                              // 0x00514990
int __stdcall sub_00418140(void* hSample, unsigned int* pValueA, unsigned int* pValueB);                   // 0x00418140
void __fastcall sub_00515180_FillBuffer(D2SoundStrc* pSound, int nArg2, int nArg3, unsigned int nSize);     // 0x00515180
int __fastcall sub_00515300_ClearSoundBuffer(D2DSoundBufferStrc* pBuffer, unsigned long nOffset, unsigned long nBytes); // 0x00515300
void __fastcall sub_005157B0_SetSoundVolume(D2SoundStrc* pSound, int nVolume);                              // 0x005157B0
void __fastcall sub_00515E40_CloseSoundStream(D2SoundStrc* pSound);                                         // 0x00515E40
int __fastcall sub_00515FD0_RestoreLostBuffer(D2SoundStrc* pSound);                                         // 0x00515FD0

static __forceinline void sub_00515EE0_StopSoundInline(D2SoundStrc* pSound)
{
    D2_ASSERT(pSound->pBuffer, 658);
    EnterCriticalSection(&gSoundLock_0088174C);
    if (pSound->hStream)
    {
        sub_00515E40_CloseSoundStream(pSound);
    }
    pSound->pBuffer->Stop();
    pSound->bPlaying = 0;
    LeaveCriticalSection(&gSoundLock_0088174C);
}

static __forceinline void sub_AdvancePlayPositionInline(D2SoundStrc* pSound, unsigned long dwPlay, unsigned long nMask)
{
    const unsigned long nOffset = pSound->nPosition & nMask;
    unsigned long nPosition = pSound->nPosition - nOffset;
    if (dwPlay < nOffset)
    {
        nPosition += pSound->nBufferSize;
    }
    pSound->nPosition = nPosition + dwPlay;
}

// 0x00516250
unsigned long __stdcall sub_00516250_SoundThread(void* pParameter)
{
    unsigned long dwPlay;
    while (WaitForSingleObject(ghSoundEvent_0088180C, 50) == 0x102)
    {
        EnterCriticalSection(&gSoundLock_0088174C);

        const int bWasIconic = gbIconic_00881814;
        gbIconic_00881814 = IsIconic(sub_004F59A0_GetHwnd());

        if (sub_00514920() && !sub_00514840())
        {
            sub_00514990_PickRandomChannel();
        }

        for (D2SoundNodeStrc* pNode = gpSoundList_00881808; pNode; pNode = pNode->pNext)
        {
            D2SoundStrc* pSound = pNode->pSound;
            sub_00515FD0_RestoreLostBuffer(pSound);

            if (gbIconic_00881814 != bWasIconic)
            {
                sub_005157B0_SetSoundVolume(pSound, pSound->nVolume);
            }

            if (pSound->bFading)
            {
                const int nTick = GetTickCount();
                if (nTick >= pSound->nFadeStart && nTick <= pSound->nFadeEnd)
                {
                    sub_005157B0_SetSoundVolume(pSound, (pSound->nFadeTo - pSound->nFadeFrom) * (nTick - pSound->nFadeStart) / (pSound->nFadeEnd - pSound->nFadeStart) + pSound->nFadeFrom);
                }
                else
                {
                    sub_005157B0_SetSoundVolume(pSound, pSound->nFadeTo);
                    if (!pSound->nFadeTo)
                    {
                        sub_00515EE0_StopSoundInline(pSound);
                    }
                    pSound->bFading = 0;
                }
            }

            if (pSound->hStream)
            {
                unsigned int nValueA;
                unsigned int nValueB;
                if (!sub_00418140(pSound->hStream, &nValueA, &nValueB))
                {
                    sub_00515EE0_StopSoundInline(pSound);
                }
            }
            else if (pSound->bPlaying)
            {
                unsigned long dwWrite;
                if (pSound->pBuffer->GetCurrentPosition(&dwPlay, &dwWrite) >= 0)
                {
                    const unsigned long nMask = pSound->nBufferSize - 1;
                    sub_AdvancePlayPositionInline(pSound, dwPlay, nMask);

                    if (!pSound->bStreamed)
                    {
                        const unsigned long* const pnPos = &pSound->nPosition;
                        if (pSound->nFillPosition - *pnPos < pSound->nHalfSize || *pnPos > pSound->nFillPosition)
                        {
                            const unsigned long nFillOffset = pSound->nFillPosition & nMask;
                            sub_00515180_FillBuffer(pSound, pSound->nFillPosition, nFillOffset, pSound->nHalfSize);
                            pSound->nFillState = -1;
                            pSound->bSecondHalf = nFillOffset != 0;
                        }
                    }
                    else if (!pSound->bNoClear)
                    {
                        if (dwPlay < pSound->nHalfSize && !pSound->bSecondHalf)
                        {
                            sub_00515300_ClearSoundBuffer(pSound->pBuffer, pSound->nHalfSize, pSound->nHalfSize);
                            pSound->bSecondHalf = 1;
                        }

                        if (dwPlay >= pSound->nHalfSize && pSound->bSecondHalf == 1)
                        {
                            sub_00515300_ClearSoundBuffer(pSound->pBuffer, 0, pSound->nHalfSize);
                            pSound->bSecondHalf = 0;
                        }

                        if (pSound->nPosition > pSound->nEndPosition)
                        {
                            pSound->pBuffer->Stop();
                            pSound->bPlaying = 0;
                        }
                    }
                }
            }
        }

        LeaveCriticalSection(&gSoundLock_0088174C);
    }

    return 0;
}
