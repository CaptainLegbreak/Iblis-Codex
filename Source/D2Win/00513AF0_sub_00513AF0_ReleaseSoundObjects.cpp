extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

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
    int unk0x04[6];
    int bPlaying;
    int unk0x20[5];
    unsigned int dwFlags;
    int nVolume;
    int unk0x3C[3];
    void* hStream;
};

struct D2SoundNodeStrc
{
    D2SoundStrc* pSound;
    D2SoundNodeStrc* pNext;
};

struct D2WaveStrc
{
    char szName[0x50];
    void* pData;
    unsigned int nSize;
    int nType;
    D2WaveStrc* pNext;
};

struct D2SoundChannelEntryStrc
{
    int unk0x00;
    int unk0x04;
};

#pragma pack(push, 1)
struct D2WaveFormatStrc
{
    unsigned short wFormatTag;
    unsigned short nChannels;
    unsigned long nSamplesPerSec;
    unsigned long nAvgBytesPerSec;
    unsigned short nBlockAlign;
    unsigned short wBitsPerSample;
    unsigned short cbSize;
};
#pragma pack(pop)

void __fastcall sub_004068F0(void* hFile);                                                                // 0x004068F0
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0
void __cdecl sub_00419F30();                                                                                 // 0x00419F30
int __stdcall sub_0041A990(void* hStream);                                                                   // 0x0041A990
int __cdecl sub_00513AE0();                                                                                  // 0x00513AE0
int __cdecl sub_00513B50();                                                                                  // 0x00513B50
void __fastcall sub_005157B0_SetSoundVolume(D2SoundStrc* pSound, int nVolume);                              // 0x005157B0
void __fastcall sub_00515EE0_StopSound(D2SoundStrc* pSound);                                                // 0x00515EE0
void __fastcall sub_005160D0_DestroySound(D2SoundStrc* pSound);                                             // 0x005160D0

extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent);                                      // 0x006CC130
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230

extern int gnChannelCountA_0072F874;                                                                        // 0x0072F874
extern D2SoundChannelEntryStrc gaChannelTableA_0072F878[8];                                                 // 0x0072F878
extern D2SoundChannelEntryStrc gaChannelTableB_0072F8B8[8];                                                 // 0x0072F8B8
extern int gnChannelCountB_0072F8F8;                                                                        // 0x0072F8F8
extern int gnSoundMasterVolume_0072F9B0;                                                                    // 0x0072F9B0
extern D2ComObjectStrc* gpSoundObject_008816D8;                                                             // 0x008816D8
extern D2ComObjectStrc* gpSoundObject_00881740;                                                             // 0x00881740
extern D2ComObjectStrc* gpSoundObject_00881744;                                                             // 0x00881744
D2CriticalSectionStrc gSoundLock_0088174C;                                                                  // 0x0088174C
extern D2SoundStrc* gpSoundChannel_00881794;                                                                // 0x00881794
int gnChannelTableSel_008817A4;                                                                             // 0x008817A4
int gbChannelTableInit_008817A8;                                                                            // 0x008817A8
extern int gnSoundMode_008817AC;                                                                            // 0x008817AC
extern int gnMusicVolume_008817B4;                                                                          // 0x008817B4
extern int gnOptionsMusic_008817C0;                                                                         // 0x008817C0
extern D2CriticalSectionStrc gWaveLock_008817C4;                                                            // 0x008817C4
extern D2SoundStrc* gapWaveSlots_008817DC[8];                                                               // 0x008817DC
extern int gbWaveSlotsInit_008817FC;                                                                        // 0x008817FC
D2WaveStrc* gpWaveList_00881800;                                                                            // 0x00881800
extern D2SoundNodeStrc* gpSoundList_00881808;                                                               // 0x00881808
void* ghSoundEvent_0088180C;                                                                                // 0x0088180C
void* ghSoundThread_00881810;                                                                               // 0x00881810

// build: symbol ?sub_N19_GetChannelEntry@@YAPAUD2SoundChannelEntryStrc@@H@Z 0x00514710
static D2SoundChannelEntryStrc* sub_N19_GetChannelEntry(int nIndex)
{
    if (!gbChannelTableInit_008817A8)
    {
        gbChannelTableInit_008817A8 = 1;
        gnChannelTableSel_008817A4 = sub_00513AE0();
    }
    D2_ASSERT(gnChannelCountA_0072F874 == gnChannelCountB_0072F8F8, 0x52);
    D2_ASSERT(nIndex < gnChannelCountA_0072F874, 0x53);
    if (gnChannelTableSel_008817A4)
        return &gaChannelTableB_0072F8B8[nIndex];
    return &gaChannelTableA_0072F878[nIndex];
}

// 0x00513AF0
void __cdecl sub_00513AF0_ReleaseSoundObjects()
{
    if (gpSoundObject_008816D8)
    {
        gpSoundObject_008816D8->Release();
        gpSoundObject_008816D8 = 0;
    }
    if (gpSoundObject_00881740)
    {
        gpSoundObject_00881740->Release();
        gpSoundObject_00881740 = 0;
    }
    if (gpSoundObject_00881744)
    {
        gpSoundObject_00881744->Release();
        gpSoundObject_00881744 = 0;
    }
}

// 0x00513ED0
const char* __fastcall sub_00513ED0_GetDSoundErrorString(long hResult)
{
    switch (hResult)
    {
    case 0x80004005:
        return "DSERR_GENERIC";
    case 0x80004002:
        return "DSERR_NOINTERFACE";
    case 0x80004001:
        return "DSERR_UNSUPPORTED";
    case 0x80040110:
        return "DSERR_NOAGGREGATION";
    case 0x80070057:
        return "DSERR_INVALIDPARAM";
    case 0x8007000E:
        return "DSERR_OUTOFMEMORY";
    case 0x8878000A:
        return "DSERR_ALLOCATED";
    case 0x88780064:
        return "DSERR_BADFORMAT";
    case 0x8878001E:
        return "DSERR_CONTROLUNAVAIL";
    case 0x88780032:
        return "DSERR_INVALIDCALL";
    case 0x88780078:
        return "DSERR_NODRIVER";
    case 0x88780046:
        return "DSERR_PRIOLEVELNEEDED";
    case 0x88780082:
        return "DSERR_ALREADYINITIALIZED";
    case 0x887800A0:
        return "DSERR_OTHERAPPHASPRIO";
    case 0x88780096:
        return "DSERR_BUFFERLOST";
    case 0x887800AA:
        return "DSERR_UNINITIALIZED";
    case 0:
        return "DS_OK";
    }
    return 0;
}

// 0x005147B0
void __cdecl sub_005147B0_DestroySoundChannel()
{
    if (gpSoundChannel_00881794)
    {
        sub_005160D0_DestroySound(gpSoundChannel_00881794);
        gpSoundChannel_00881794 = 0;
    }
    sub_00419F30();
}

// 0x00514860
void __cdecl sub_00514860_ClearChannelTable()
{
    for (int i = 0; i < gnChannelCountA_0072F874; ++i)
        sub_N19_GetChannelEntry(i)->unk0x04 = 0;
}

// 0x00514CA0
int __fastcall sub_00514CA0_SetSoundMode(int nValue)
{
    SRegSaveValue("Diablo II", "Sound Mixer", 0, nValue);
    gnSoundMode_008817AC = nValue;
    return nValue;
}

// 0x00514D00
int __fastcall sub_00514D00_SetMusicVolume(int nValue)
{
    SRegSaveValue("Diablo II", "Music Volume", 0, nValue);
    gnMusicVolume_008817B4 = nValue;
    return nValue;
}

// 0x00514D90
int __fastcall sub_00514D90_SetOptionsMusic(int nValue)
{
    SRegSaveValue("Diablo II", "Options Music", 0, nValue);
    gnOptionsMusic_008817C0 = nValue;
    return nValue;
}

// 0x00515070
void __cdecl sub_00515070_FreeWaveSlots()
{
    if (!gbWaveSlotsInit_008817FC)
        return;
    for (int i = 0; i < 8; ++i)
        sub_00515EE0_StopSound(gapWaveSlots_008817DC[i]);
    for (int i = 0; i < 8; ++i)
    {
        sub_005160D0_DestroySound(gapWaveSlots_008817DC[i]);
        gapWaveSlots_008817DC[i] = 0;
    }
    while (gpWaveList_00881800)
    {
        D2WaveStrc* pNext = gpWaveList_00881800->pNext;
        void* pData = gpWaveList_00881800->pData;
        if (pData)
            FOG_Free(pData, ".\\Src\\D2SoundFast.cpp", 0x62, 0);
        FOG_Free(gpWaveList_00881800, ".\\Src\\D2SoundFast.cpp", 0x63, 0);
        gpWaveList_00881800 = pNext;
    }
    gbWaveSlotsInit_008817FC = 0;
    DeleteCriticalSection(&gWaveLock_008817C4);
}

// 0x00515120
void __cdecl sub_00515120_StopSoundThread()
{
    if (ghSoundThread_00881810 && ghSoundEvent_0088180C)
    {
        SetEvent(ghSoundEvent_0088180C);
        WaitForSingleObject(ghSoundThread_00881810, -1);
        CloseHandle(ghSoundEvent_0088180C);
        CloseHandle(ghSoundThread_00881810);
        ghSoundEvent_0088180C = 0;
        ghSoundThread_00881810 = 0;
    }
}

// 0x005156A0
int __fastcall sub_005156A0_PlaySound(D2SoundStrc* pSound)
{
    D2_ASSERT(pSound, 0x279);
    EnterCriticalSection(&gSoundLock_0088174C);
    if (pSound->pBuffer->Play(0, 0, 1) < 0)
    {
        LeaveCriticalSection(&gSoundLock_0088174C);
        return 0;
    }
    pSound->bPlaying = 1;
    LeaveCriticalSection(&gSoundLock_0088174C);
    return 1;
}

// 0x00515710
int __fastcall sub_00515710_GetSoundPlaying(D2SoundStrc* pSound)
{
    D2_ASSERT(pSound && pSound->pBuffer, 0x2A5);
    return pSound->bPlaying;
}

// 0x00515C30
int __fastcall sub_00515C30_IsSoundStreaming(D2SoundStrc* pSound)
{
    D2_ASSERT(pSound, 0x37A);
    return pSound->hStream != 0;
}

// 0x00515CE0
void __fastcall sub_00515CE0_SetMasterVolume(int nVolume)
{
    if (!sub_00513B50())
        return;
    if (nVolume == gnSoundMasterVolume_0072F9B0)
        return;
    D2_ASSERT(nVolume >= 0 && nVolume <= 0xFF, 0x3B9);
    EnterCriticalSection(&gSoundLock_0088174C);
    gnSoundMasterVolume_0072F9B0 = nVolume;
    for (D2SoundNodeStrc* pNode = gpSoundList_00881808; pNode; pNode = pNode->pNext)
    {
        D2_ASSERT(pNode->pSound, 0x2E4);
        sub_005157B0_SetSoundVolume(pNode->pSound, pNode->pSound->nVolume);
    }
    LeaveCriticalSection(&gSoundLock_0088174C);
}

// 0x00515E40
void __fastcall sub_00515E40_CloseSoundStream(D2SoundStrc* pSound)
{
    D2_ASSERT(pSound && pSound->pBuffer, 0x400);
    EnterCriticalSection(&gSoundLock_0088174C);
    if (pSound->hStream)
    {
        sub_0041A990(pSound->hStream);
        pSound->pBuffer->Stop();
        sub_004068F0(pSound->hStream);
        pSound->hStream = 0;
        pSound->bPlaying = 0;
    }
    LeaveCriticalSection(&gSoundLock_0088174C);
}

// 0x00516720
void __fastcall sub_00516720_InitWaveFormat(D2WaveFormatStrc* pFormat, int nChannels)
{
    memset(pFormat, 0, sizeof(*pFormat));
    pFormat->wFormatTag = 1;
    pFormat->nChannels = nChannels;
    pFormat->nSamplesPerSec = 22050;
    pFormat->wBitsPerSample = 16;
    pFormat->nBlockAlign = nChannels * 2;
    pFormat->nAvgBytesPerSec = pFormat->nSamplesPerSec * pFormat->nBlockAlign;
}

#include "gen/data/Source/D2Win/00513AF0_sub_00513AF0_ReleaseSoundObjects.inc"
