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

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC214
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                               // 0x006CC260
extern "C" __declspec(dllimport) void* __stdcall CreateEventA(void* pAttributes, int bManualReset, int bInitialState, const char* szName); // 0x006CC228
extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* pAttributes, unsigned long nStackSize, unsigned long (__stdcall* pfnStart)(void*), void* pParameter, unsigned long nFlags, unsigned long* pThreadId); // 0x006CC250

extern "C" double __cdecl log(double x);                                                                    // 0x00687AC0
extern "C" double __cdecl log10(double x);                                                                  // 0x00687EA0
extern "C" double __cdecl pow(double x, double y);                                                          // 0x00687C10

struct D2SoundFadeStrc
{
    char unk0x00[0x38];
    int nCurrent;
    char unk0x3C[0x10];
    int f_4C;
    int nFadeStart;
    int f_54;
    unsigned int dwFadeStartTick;
    unsigned int dwFadeEndTick;
};

int __cdecl sub_00513B50();                                                                                 // 0x00513B50
unsigned long __stdcall sub_00516250_SoundThread(void* pParameter);                                         // 0x00516250
extern D2CriticalSectionStrc gSoundLock_0088174C;                                                           // 0x0088174C
extern void* ghSoundEvent_0088180C;                                                                         // 0x0088180C
extern void* ghSoundThread_00881810;                                                                        // 0x00881810

// 0x00515C60
void __fastcall sub_00515C60_StartFade(D2SoundFadeStrc* pFade, int nTarget, int nDuration)
{
    D2_ASSERT(pFade, 0x39E);
    if (sub_00513B50())
    {
        EnterCriticalSection(&gSoundLock_0088174C);
        pFade->f_4C = 1;
        pFade->nFadeStart = pFade->nCurrent;
        pFade->f_54 = nTarget;
        const unsigned int dwTick = GetTickCount();
        pFade->dwFadeStartTick = dwTick;
        pFade->dwFadeEndTick = dwTick + nDuration;
        LeaveCriticalSection(&gSoundLock_0088174C);
    }
}

// 0x00516510
void __cdecl sub_00516510_StartSoundThread()
{
    unsigned long dwThreadId;
    D2_ASSERT(!ghSoundThread_00881810, 0xBC);
    ghSoundEvent_0088180C = CreateEventA(0, 1, 0, 0);
    ghSoundThread_00881810 = CreateThread(0, 0, sub_00516250_SoundThread, 0, 0, &dwThreadId);
}

// 0x00516570
float __stdcall sub_00516570_Log(float fValue)
{
    return (float)log(fValue);
}

// 0x00516590
float __stdcall sub_00516590_Pow(float fBase, float fExponent)
{
    return (float)pow(fBase, fExponent);
}

// 0x005165B0
float __cdecl sub_005165B0_Log(float fValue)
{
    return (float)log(fValue);
}

// 0x005165D0
float __cdecl sub_005165D0_Pow(float fBase, float fExponent)
{
    return (float)pow(fBase, fExponent);
}

// 0x005165F0
float __stdcall sub_005165F0_RangeToVolume(float fMin, float fMax, float fValue)
{
    if (fValue <= fMin + 0.0001f)
        return -10000.0f;
    if (fValue >= fMax - 0.0001f)
        return 0.0f;
    return (float)(log10(fValue != 0.0f ? (fMin + fMax) / fValue : (fMin + fMax) / fMax) * -2000.0f);
}

// 0x00516670
float __stdcall sub_00516670_VolumeToScale(float fVolume)
{
    if (fVolume + 0.0001f > 0.0)
        return 1.0f;
    if (fVolume - 0.0001f < -10000.0)
        return 0.0f;
    return (float)pow(10.0, fVolume / 2000.0);
}
