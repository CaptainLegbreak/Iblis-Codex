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

struct D2ComObjectStrc
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppvObject) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

struct D2SoundStrc;

void __cdecl sub_00513AF0_ReleaseSoundObjects();                                                             // 0x00513AF0
int __cdecl sub_00513B50();                                                                                  // 0x00513B50
void __cdecl sub_005147B0_DestroySoundChannel();                                                             // 0x005147B0
void __cdecl sub_00514860_ClearChannelTable();                                                               // 0x00514860
void __cdecl sub_00515120_StopSoundThread();                                                                 // 0x00515120
D2SoundStrc* __fastcall sub_00515530(int nType, int nArg);                                                  // 0x00515530
int __fastcall sub_00515710_GetSoundPlaying(D2SoundStrc* pSound);                                           // 0x00515710
int __fastcall sub_00515C30_IsSoundStreaming(D2SoundStrc* pSound);                                          // 0x00515C30
void __fastcall sub_00515C60_StartFade(D2SoundStrc* pFade, int nTarget, int nDuration);                     // 0x00515C60
void __fastcall sub_00515CE0_SetMasterVolume(int nVolume);                                                  // 0x00515CE0

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock);    // 0x006CC210
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);                        // 0x006CC258

extern int gnSoundMasterVolume_0072F9B0;                                                                    // 0x0072F9B0
extern D2ComObjectStrc* gpSoundObject_00881748;                                                             // 0x00881748
extern D2CriticalSectionStrc gSoundLock_0088174C;                                                           // 0x0088174C
extern int gnSoundState_00881764;                                                                           // 0x00881764
extern D2ComObjectStrc* gpDirectSound_00881768;                                                             // 0x00881768
extern int gbSoundLockInit_0088177C;                                                                        // 0x0088177C
extern D2SoundStrc* gpSoundChannel_00881794;                                                                // 0x00881794
int gnChannelValue_00881798;                                                                                // 0x00881798
int gbChannelFlag_0088179C;                                                                                 // 0x0088179C
extern D2CriticalSectionStrc gWaveLock_008817C4;                                                            // 0x008817C4
D2SoundStrc* gapWaveSlots_008817DC[8];                                                                      // 0x008817DC
int gbWaveSlotsInit_008817FC;                                                                               // 0x008817FC

// 0x00514060
void __cdecl sub_00514060_ShutdownSound()
{
    gnSoundState_00881764 = 0;
    sub_00515CE0_SetMasterVolume(0);
    sub_005147B0_DestroySoundChannel();
    sub_00515120_StopSoundThread();
    sub_00513AF0_ReleaseSoundObjects();
    if (gpSoundObject_00881748)
    {
        gpSoundObject_00881748->Release();
        gpSoundObject_00881748 = 0;
    }
    if (gpDirectSound_00881768)
    {
        gpDirectSound_00881768->Release();
        gpDirectSound_00881768 = 0;
    }
    if (gbSoundLockInit_0088177C)
    {
        DeleteCriticalSection(&gSoundLock_0088174C);
        gbSoundLockInit_0088177C = 0;
    }
}

// 0x00514840
int __cdecl sub_00514840_IsChannelStreaming()
{
    if (gpSoundChannel_00881794 && sub_00515C30_IsSoundStreaming(gpSoundChannel_00881794))
        return 1;
    return 0;
}

// 0x005148F0
void __fastcall sub_005148F0_SetChannelValue(int nValue)
{
    if (nValue && !gnChannelValue_00881798)
    {
        sub_00514860_ClearChannelTable();
        gbChannelFlag_0088179C = 1;
    }
    gnChannelValue_00881798 = nValue;
}

// 0x00514960
void __cdecl sub_00514960_FadeOutChannel()
{
    if (gpSoundChannel_00881794)
    {
        gnChannelValue_00881798 = 0;
        if (sub_00515C30_IsSoundStreaming(gpSoundChannel_00881794))
            sub_00515C60_StartFade(gpSoundChannel_00881794, 0, 200);
    }
}

// 0x00514DB0
void __cdecl sub_00514DB0_InitWaveSlots()
{
    if (sub_00513B50() && !gbWaveSlotsInit_008817FC)
    {
        InitializeCriticalSection(&gWaveLock_008817C4);
        sub_00515CE0_SetMasterVolume(0xFF);
        for (int i = 0; i < 8; ++i)
            gapWaveSlots_008817DC[i] = sub_00515530(i < 4, 0);
        gbWaveSlotsInit_008817FC = 1;
    }
}

// 0x00514FB0
int __cdecl sub_00514FB0_IsAnyWavePlaying()
{
    if (!gbWaveSlotsInit_008817FC)
        return 0;
    for (int i = 0; i < 8; ++i)
    {
        if (sub_00515710_GetSoundPlaying(gapWaveSlots_008817DC[i]))
            return 1;
    }
    return 0;
}

// 0x00515020
void __cdecl sub_00515020_FadeOutWaves()
{
    if (gbWaveSlotsInit_008817FC)
    {
        for (int i = 0; i < 8; ++i)
        {
            if (sub_00515710_GetSoundPlaying(gapWaveSlots_008817DC[i]))
                sub_00515C60_StartFade(gapWaveSlots_008817DC[i], 0, 200);
        }
    }
}

// 0x00515D60
int __cdecl sub_00515D60_GetMasterVolume()
{
    return sub_00513B50() ? gnSoundMasterVolume_0072F9B0 : 0;
}

// 0x00515F50
void __fastcall sub_00515F50_FadeOutMaster(int nTime)
{
    if (!sub_00513B50())
        return;
    D2_ASSERT(nTime > 0, 0x387);
    unsigned int nVolume = sub_00515D60_GetMasterVolume();
    const unsigned int nStep = nVolume / (nTime / 20u);
    while (nVolume)
    {
        Sleep(20);
        if (nVolume > nStep)
            nVolume -= nStep;
        else
            nVolume = 0;
        sub_00515CE0_SetMasterVolume(nVolume);
    }
}
