#include "D2Sound.h"

struct D2SoundStrc;
struct D2DSoundBufferStrc;
struct D2DSound3DBufferStrc;
struct D2KsPropertySetStrc;
struct D2ComObjectStrc;
struct D2WaveFormatStrc;
struct D2SoundWaveStrc;
struct D2WaveStrc;
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

void __cdecl sub_00513AF0_ReleaseSoundObjects(); // 0x00513AF0
int __cdecl sub_00513B50(); // 0x00513B50
void __cdecl sub_005147B0_DestroySoundChannel(); // 0x005147B0
void __cdecl sub_00514860_ClearChannelTable(); // 0x00514860
void __cdecl sub_00515120_StopSoundThread(); // 0x00515120

struct D2SoundStrc
{
    D2DSoundBufferStrc* pBuffer;
    unsigned int nBufferSize;
    int unk0x08;
    D2DSound3DBufferStrc* p3DBuffer;
    D2KsPropertySetStrc* pPropertySet;
    void* pData;
    unsigned int nDataSize;
    int bStreaming;
    int unk0x20[2];
    int bDataSet;
    int unk0x2C;
    int nLoopStart;
    unsigned int dwFlags;
    int f_38;
    float f_3C;
    int bNoLoop;
    unsigned int nMinDataSize;
    void* hStreamFile;
};

D2SoundStrc* __fastcall sub_00515530(int nType, int nArg); // 0x00515530
int __fastcall sub_00515710_GetSoundPlaying(D2SoundStrc* pSound); // 0x00515710
int __fastcall sub_00515C30_IsSoundStreaming(D2SoundStrc* pSound); // 0x00515C30
void __fastcall sub_00515C60_StartFade(D2SoundStrc* pFade, int nTarget, int nDuration); // 0x00515C60
void __fastcall sub_00515CE0_SetMasterVolume(int nVolume); // 0x00515CE0
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210
extern D2ComObjectStrc* gpSoundObject_00881748; // 0x00881748
extern D2CriticalSectionStrc gSoundLock_0088174C; // 0x0088174C
extern D2ComObjectStrc* gpDirectSound_00881768; // 0x00881768
extern int gbSoundLockInit_0088177C; // 0x0088177C
extern D2SoundStrc* gpSoundChannel_00881794; // 0x00881794
extern D2CriticalSectionStrc gWaveLock_008817C4; // 0x008817C4

struct D2WaveFormatStrc
{
    unsigned short wFormatTag;
    unsigned short nChannels;
    unsigned int nSamplesPerSec;
    unsigned int nAvgBytesPerSec;
    unsigned short nBlockAlign;
    unsigned short wBitsPerSample;
    unsigned short cbSize;
};

struct D2SoundWaveStrc
{
    char szName[0x50];
    void* pFile;
    unsigned int nFileSize;
    int f_58;
    D2SoundWaveStrc* pNext;
};

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC218
extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);
int __fastcall sub_004068E0(const char* szFileName, void** phFile); // 0x004068E0
int __stdcall SFileDdaBeginEx(void* hFile, int nBufferSize, unsigned int nFlags, unsigned int nOffset, int nVolume, int nPan, D2DSoundBufferStrc* pBuffer); // 0x0041B280
void __fastcall sub_00515180_FillBuffer(D2SoundStrc* pSound, int nArg2, int nArg3, unsigned int nSize); // 0x00515180
void* __fastcall sub_00516760_ParseWave(const void* pFile, unsigned int* pnSize, D2WaveFormatStrc* pFormat); // 0x00516760
void* __fastcall ARCHIVE_AllocateBufferAndReadFile(void* hArchive, const char* szFileName, unsigned int* pnSize, const char* szFile, int nLine); // 0x00517079
extern int gbWaveSlotsInit_008817FC; // 0x008817FC
extern D2SoundWaveStrc* gpSoundWaveList_00881800; // 0x00881800

struct D2WaveStrc
{
    char szName[0x50];
    void* pData;
    unsigned int nSize;
    unsigned int nType;
    D2WaveStrc* pNext;
};

extern "C" int __cdecl strcmp(const char* szLeft, const char* szRight);
int __fastcall sub_005155D0_SetSoundData(D2SoundStrc* pSound, const void* pFile, unsigned int nSize); // 0x005155D0
int __fastcall sub_005156A0_PlaySound(D2SoundStrc* pSound); // 0x005156A0
void __fastcall sub_005157B0_SetSoundVolume(D2SoundStrc* pSound, int nVolume); // 0x005157B0
void __fastcall sub_00516140_ResetSound(D2SoundStrc* pSound); // 0x00516140
extern D2SoundStrc* gapWaveSlots_008817DC[8]; // 0x008817DC
extern D2WaveStrc* gpWaveList_00881800; // 0x00881800

int gnChannelValue_00881798; // 0x00881798

int gbChannelFlag_0088179C; // 0x0088179C

D2SoundStrc* gapWaveSlots_008817DC[8]; // 0x008817DC

int gbWaveSlotsInit_008817FC; // 0x008817FC

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

// 0x00514E10
void __fastcall sub_00514E10_LoadWave(const char* szName)
{
    if (!gbWaveSlotsInit_008817FC)
        return;
    unsigned int nFileSize;
    void* pFile = ARCHIVE_AllocateBufferAndReadFile(0, szName, &nFileSize, ".\\Src\\D2SoundFast.cpp", 0x77);
    if (!pFile)
        return;
    unsigned int nWaveSize = nFileSize;
    D2WaveFormatStrc tFormat;
    sub_00516760_ParseWave(pFile, &nWaveSize, &tFormat);
    if (tFormat.nSamplesPerSec != 22050)
        return;
    D2SoundWaveStrc* pWave = (D2SoundWaveStrc*)FOG_Alloc(sizeof(D2SoundWaveStrc), ".\\Src\\D2SoundFast.cpp", 0x85, 0);
    pWave->pNext = gpSoundWaveList_00881800;
    pWave->pFile = pFile;
    pWave->nFileSize = nFileSize;
    gpSoundWaveList_00881800 = pWave;
    pWave->f_58 = tFormat.nChannels == 2;
    strcpy(pWave->szName, szName);
}

// 0x005155D0
int __fastcall sub_005155D0_SetSoundData(D2SoundStrc* pSound, const void* pFile, unsigned int nSize)
{
    D2_ASSERT(pSound && pSound->pBuffer && pFile && nSize, 0x257);
    EnterCriticalSection(&gSoundLock_0088174C);
    unsigned int nDataSize = nSize;
    D2WaveFormatStrc tFormat;
    void* pData = sub_00516760_ParseWave(pFile, &nDataSize, &tFormat);
    D2_ASSERT(pSound->nMinDataSize < nDataSize, 0x25F);
    pSound->nDataSize = nDataSize;
    pSound->pData = pData;
    sub_00515180_FillBuffer(pSound, 0, 0, pSound->nBufferSize);
    pSound->bDataSet = 1;
    if (!pSound->bNoLoop && pSound->nDataSize < pSound->nBufferSize)
        pSound->nLoopStart = pSound->nDataSize;
    else
        pSound->nLoopStart = -1;
    LeaveCriticalSection(&gSoundLock_0088174C);
    return 1;
}

// 0x00515D70
int __fastcall sub_00515D70_StartStream(D2SoundStrc* pSound, const char* szFileName, int nPosition, int bLoop)
{
    D2_ASSERT(pSound, 0x3DB);
    void* hFile;
    if (!sub_004068E0(szFileName, &hFile))
        return 0;
    EnterCriticalSection(&gSoundLock_0088174C);
    if (!SFileDdaBeginEx(hFile, pSound->nBufferSize, bLoop ? 0x40000 : 0, nPosition * 4, 0x7FFFFFFF, 0x7FFFFFFF, pSound->pBuffer))
    {
        sub_004068F0(hFile);
        LeaveCriticalSection(&gSoundLock_0088174C);
        return 0;
    }
    pSound->hStreamFile = hFile;
    pSound->bStreaming = 1;
    pSound->nLoopStart = -1;
    LeaveCriticalSection(&gSoundLock_0088174C);
    return 1;
}

D2CriticalSectionStrc gWaveLock_008817C4; // 0x008817C4

// 0x00514EC0
void __fastcall D2SOUND_10039(const char* szName)
{
    if (!gbWaveSlotsInit_008817FC)
        return;

    EnterCriticalSection(&gWaveLock_008817C4);

    D2WaveStrc* pWave = gpWaveList_00881800;
    if (gpWaveList_00881800)
    {
        int bFound = 0;
        for (; pWave; pWave = pWave->pNext)
        {
            if (!strcmp(pWave->szName, szName))
            {
                bFound = 1;
                break;
            }
        }

        if (bFound)
        {
        int i;
        for (i = 0; i < 8; ++i)
        {
            if (gapWaveSlots_008817DC[i]->dwFlags == pWave->nType && !sub_00515710_GetSoundPlaying(gapWaveSlots_008817DC[i]))
                break;
        }

        if (i < 8)
        {
            D2SoundStrc* pSound = gapWaveSlots_008817DC[i];
            sub_00516140_ResetSound(pSound);
            sub_005155D0_SetSoundData(pSound, pWave->pData, pWave->nSize);
            sub_005157B0_SetSoundVolume(pSound, 0xFF);
            sub_005156A0_PlaySound(pSound);
        }
        }
    }

    LeaveCriticalSection(&gWaveLock_008817C4);
}
