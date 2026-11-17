struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2SoundSampleStrc
{
    char unk0x00[0x48];
    void* hSample;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC218
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
int __stdcall sub_00418140(void* hSample, unsigned int* pValueA, unsigned int* pValueB);                     // 0x00418140

extern D2CriticalSectionStrc gSoundCriticalSection_0088174C;                                                // 0x0088174C
int gdwGlobal_008817AC;                                                                                     // 0x008817AC
int gdwGlobal_008817B0;                                                                                     // 0x008817B0
int gdwGlobal_008817B4;                                                                                     // 0x008817B4
int gdwGlobal_008817B8;                                                                                     // 0x008817B8
int gdwGlobal_008817BC;                                                                                     // 0x008817BC
int gdwGlobal_008817C0;                                                                                     // 0x008817C0

// 0x00514B60
void __cdecl sub_00514B60_LoadSoundSettings()
{
    unsigned long nValue;
    gdwGlobal_008817AC = 0;
    gdwGlobal_008817B0 = 100;
    gdwGlobal_008817B4 = 50;
    gdwGlobal_008817B8 = 50;
    gdwGlobal_008817BC = 2;
    gdwGlobal_008817C0 = 1;
    if (SRegLoadValue("Diablo II", "Sound Mixer", 0, &nValue) && nValue < 3)
        gdwGlobal_008817AC = nValue;
    if (SRegLoadValue("Diablo II", "Master Volume", 0, &nValue) && nValue <= 100)
        gdwGlobal_008817B0 = nValue;
    if (SRegLoadValue("Diablo II", "Music Volume", 0, &nValue) && nValue <= 100)
        gdwGlobal_008817B4 = nValue;
    if (SRegLoadValue("Diablo II", "Positional Bias", 0, &nValue) && nValue <= 100)
        gdwGlobal_008817B8 = nValue;
    if (SRegLoadValue("Diablo II", "NPC Speech", 0, &nValue) && nValue < 3)
        gdwGlobal_008817BC = nValue;
    if (SRegLoadValue("Diablo II", "Options Music", 0, &nValue) && nValue <= 1)
        gdwGlobal_008817C0 = nValue;
}

// 0x005159B0
unsigned int __fastcall sub_005159B0_GetSoundSampleCount(D2SoundSampleStrc* pSound)
{
    D2_ASSERT(pSound, 784);
    EnterCriticalSection(&gSoundCriticalSection_0088174C);
    if (pSound->hSample)
    {
        unsigned int nValueA;
        unsigned int nValueB;
        if (sub_00418140(pSound->hSample, &nValueA, &nValueB))
        {
            LeaveCriticalSection(&gSoundCriticalSection_0088174C);
            return nValueA >> 2;
        }
        LeaveCriticalSection(&gSoundCriticalSection_0088174C);
        return 0;
    }
    LeaveCriticalSection(&gSoundCriticalSection_0088174C);
    return 0;
}
