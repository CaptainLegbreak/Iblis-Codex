#include "D2Sound.h"
#include "D2GfxTypes.h"
#include "D2Win32Base.h"
#include "D2DDrawTypes.h"
#include "D2GlideTypes.h"
#include "D2GameTypes.h"

#include "D2SysTypes.h"

#include "D2SoundTypes.h"

struct D2SoundStrc;

struct D2DSGuid;

struct D2DSBufferCaps;

struct D2DSCaps;

struct D2DSUnknown;

struct D2DSBuffer;

struct D2DSDirectSound;

struct D2DSPropertySet;

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2DSGuid { unsigned long a; unsigned short b; unsigned short c; unsigned char d[8]; };

struct D2DSBufferCaps { unsigned long dwSize; unsigned long dwFlags; unsigned long dwBufferBytes; unsigned long dwUnlockTransferRate; unsigned long dwPlayCpuOverhead; };

struct D2DSCaps { unsigned long dwSize; unsigned long a[10]; unsigned long dwMaxHw3DAllBuffers; unsigned long b[13]; };

struct D2DSUnknown
{
    virtual long __stdcall QueryInterface(const D2DSGuid& riid, void** ppvObject) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

struct D2DSBuffer : D2DSUnknown
{
    virtual long __stdcall GetCaps(D2DSBufferCaps* pCaps) = 0;
    virtual long __stdcall GetCurrentPosition(unsigned long* a, unsigned long* b) = 0;
    virtual long __stdcall GetFormat(D2WaveFormatStrc* a, unsigned long b, unsigned long* c) = 0;
    virtual long __stdcall GetVolume(long* a) = 0;
    virtual long __stdcall GetPan(long* a) = 0;
    virtual long __stdcall GetFrequency(unsigned long* a) = 0;
    virtual long __stdcall GetStatus(unsigned long* a) = 0;
    virtual long __stdcall Initialize(void* a, const D2DSBufferDescStrc* b) = 0;
    virtual long __stdcall Lock(unsigned long a, unsigned long b, void** c, unsigned long* d, void** e, unsigned long* f, unsigned long g) = 0;
    virtual long __stdcall Play(unsigned long dwReserved1, unsigned long dwPriority, unsigned long dwFlags) = 0;
    virtual long __stdcall SetCurrentPosition(unsigned long a) = 0;
    virtual long __stdcall SetFormat(const D2WaveFormatStrc* pFormat) = 0;
};

struct D2DSDirectSound : D2DSUnknown
{
    virtual long __stdcall CreateSoundBuffer(const D2DSBufferDescStrc* pDesc, D2DSBuffer** ppBuffer, D2DSUnknown* pOuter) = 0;
    virtual long __stdcall GetCaps(D2DSCaps* pCaps) = 0;
    virtual long __stdcall DuplicateSoundBuffer(D2DSBuffer* a, D2DSBuffer** b) = 0;
    virtual long __stdcall SetCooperativeLevel(void* hWnd, unsigned long dwLevel) = 0;
};

struct D2DSPropertySet : D2DSUnknown
{
    virtual long __stdcall Get(const D2DSGuid& a, unsigned long b, void* c, unsigned long d, void* e, unsigned long f, unsigned long* g) = 0;
    virtual long __stdcall Set(const D2DSGuid& a, unsigned long b, void* c, unsigned long d, void* e, unsigned long f) = 0;
    virtual long __stdcall QuerySupport(const D2DSGuid& rguid, unsigned long nId, unsigned long* pSupport) = 0;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210

extern "C" long __stdcall DirectSoundCreate(const D2DSGuid* pGuid, D2DSDirectSound** ppDS, D2DSUnknown* pOuter); // 0x006B1344

void* __cdecl WINDOW_GetWindow(); // 0x004F59A0

void __cdecl D2SOUND_ReleaseSoundObjects(); // 0x00513AF0

int __fastcall sub_00513BC0_SetEaxRoomOff(int nEaxVersion); // 0x00513BC0

const char* __fastcall D2SOUND_GetDirectSoundErrorString(long hResult); // 0x00513ED0

void __cdecl D2SOUND_CloseSoundSystem(); // 0x00514060

extern "C" void __fastcall D2SOUND_CreateStreamChannel(int nArg); // 0x00514780

void __cdecl D2SOUND_LoadRegistrySettings(); // 0x00514B60

int __fastcall D2SOUND_ClearSoundBuffer(D2DSBuffer* pBuffer, unsigned long nOffset, unsigned long nBytes); // 0x00515300

void __fastcall D2SOUND_SetMasterVolume(int nVolume); // 0x00515CE0

void __cdecl D2SOUND_StartSoundThread(); // 0x00516510

void __fastcall D2SOUND_InitWaveFormat(D2WaveFormatStrc* pFormat, int nChannels); // 0x00516720

extern D2DSPropertySet* gpPropertySet_008816D8; // 0x008816D8

extern D2DSCaps gtDSCaps; // 0x008816E0

extern D2CriticalSectionStrc gtSoundLock; // 0x0088174C

extern int gbUseEax_00881770; // 0x00881770

extern int gbSoundInit_00881784; // 0x00881784

extern const D2DSGuid gtIidDirectSound3DBuffer; // 0x006DE3D0

extern const D2DSGuid gtIidKsPropertySet; // 0x006DE410

extern const D2DSGuid gDSPROPSETID_EAX20_ListenerProperties_006DE460; // 0x006DE460

extern const D2DSGuid gDSPROPSETID_EAX_ReverbProperties_006DE480; // 0x006DE480

int __fastcall D2SOUND_IsSoundStreaming(D2SoundStrc* pSound); // 0x00515C30

void __fastcall D2SOUND_StopSound(D2SoundStrc* pSound); // 0x00515EE0

extern D2SoundStrc* gpSoundChannel; // 0x00881794

extern int gnChannelValue; // 0x00881798

int gnChannelArg; // 0x008816DC

D2DSUnknown* gp3DBuffer; // 0x00881740

D2DSBuffer* gpEaxBuffer; // 0x00881744

D2DSBuffer* gpSoundObject; // 0x00881748

D2DSDirectSound* gpDirectSound; // 0x00881768

int gb3DSound; // 0x0088176C

int gnEaxVersion; // 0x00881774

int gbSoundLockInit; // 0x0088177C

// 0x005140D0
void __cdecl sub_005140D0_InitDirectSound()
{
    if (gb3DSound && gbSoundInit_00881784)
    {
        return;
    }

    D2_ASSERT(!gbSoundLockInit, 0x53);
    InitializeCriticalSection(&gtSoundLock);
    gbSoundLockInit = 1;

    long hResult = DirectSoundCreate(0, &gpDirectSound, 0);
    if (hResult < 0)
    {
        LOGMANAGER_WriteLogLine("DirectSound error: %s returned on DirectSoundCreate", D2SOUND_GetDirectSoundErrorString(hResult));
        D2SOUND_CloseSoundSystem();
        return;
    }

    hResult = gpDirectSound->SetCooperativeLevel(WINDOW_GetWindow(), 2);
    if (hResult < 0)
    {
        LOGMANAGER_WriteLogLine("DirectSound error: %s returned on SetCooperativeLevel", D2SOUND_GetDirectSoundErrorString(hResult));
        D2SOUND_CloseSoundSystem();
        return;
    }

    D2DSBufferDescStrc tDesc;
    memset(&tDesc, 0, sizeof(tDesc));
    tDesc.dwSize = 0x14;
    tDesc.dwFlags = 1;
    if (gb3DSound)
    {
        tDesc.dwFlags = 0x11;
    }
    tDesc.dwBufferBytes = 0;
    tDesc.lpwfxFormat = 0;
    hResult = gpDirectSound->CreateSoundBuffer(&tDesc, &gpSoundObject, 0);
    if (hResult < 0)
    {
        LOGMANAGER_WriteLogLine("........DirectSound progress: %s returned on failed CreateSoundBuffer", D2SOUND_GetDirectSoundErrorString(hResult));
        D2SOUND_CloseSoundSystem();
        return;
    }

    gtDSCaps.dwSize = 0x60;
    hResult = gpDirectSound->GetCaps(&gtDSCaps);
    if (hResult < 0)
    {
        LOGMANAGER_WriteLogLine("........DirectSound progress: %s returned on failed GetCaps", D2SOUND_GetDirectSoundErrorString(hResult));
        D2SOUND_CloseSoundSystem();
        return;
    }

    if (gb3DSound && gtDSCaps.dwMaxHw3DAllBuffers < 0x10)
    {
        LOGMANAGER_WriteLogLine("........DirectSound progress: %d buffers available is less than min needed %d buffers for 3d sound", gtDSCaps.dwMaxHw3DAllBuffers, 0x10);
        D2SOUND_CloseSoundSystem();
        return;
    }

    D2WaveFormatStrc tFormat;
    memset(&tFormat, 0, sizeof(tFormat));
    tFormat.wFormatTag = 1;
    tFormat.nChannels = 2;
    tFormat.nSamplesPerSec = 0x5622;
    tFormat.wBitsPerSample = 0x10;
    tFormat.nBlockAlign = 4;
    tFormat.nAvgBytesPerSec = 0x15888;
    hResult = gpSoundObject->SetFormat(&tFormat);
    if (hResult < 0)
    {
        LOGMANAGER_WriteLogLine("........DirectSound progress: %s returned on failed SetFormat", D2SOUND_GetDirectSoundErrorString(hResult));
        gpSoundObject->Release();
        D2SOUND_CloseSoundSystem();
        return;
    }

    gnEaxVersion = 0;
    if (gbUseEax_00881770)
    {
        D2WaveFormatStrc tEaxFormat;
        D2SOUND_InitWaveFormat(&tEaxFormat, 1);
        D2DSBufferDescStrc tEaxDesc;
    memset(&tEaxDesc, 0, sizeof(tEaxDesc));
        tEaxDesc.dwSize = 0x14;
        tEaxDesc.dwBufferBytes = 0x400;
        tEaxDesc.dwFlags = 0x12;
        tEaxDesc.lpwfxFormat = &tEaxFormat;
        unsigned long nSupport;
        if (!gnEaxVersion)
        {
            if (gpDirectSound->CreateSoundBuffer(&tEaxDesc, &gpEaxBuffer, 0) >= 0
                && gpEaxBuffer->QueryInterface(gtIidDirectSound3DBuffer, (void**)&gp3DBuffer) >= 0
                && gp3DBuffer->QueryInterface(gtIidKsPropertySet, (void**)&gpPropertySet_008816D8) >= 0
                && gpPropertySet_008816D8->QuerySupport(gDSPROPSETID_EAX20_ListenerProperties_006DE460, 1, &nSupport) >= 0
                && (nSupport & 3) == 3
                && sub_00513BC0_SetEaxRoomOff(2))
            {
                gnEaxVersion = 2;
            }
            else
            {
                D2SOUND_ReleaseSoundObjects();
            }
        }
        if (!gnEaxVersion)
        {
            if (gpDirectSound->CreateSoundBuffer(&tEaxDesc, &gpEaxBuffer, 0) >= 0
                && gpEaxBuffer->QueryInterface(gtIidDirectSound3DBuffer, (void**)&gp3DBuffer) >= 0
                && gp3DBuffer->QueryInterface(gtIidKsPropertySet, (void**)&gpPropertySet_008816D8) >= 0
                && gpPropertySet_008816D8->QuerySupport(gDSPROPSETID_EAX_ReverbProperties_006DE480, 0, &nSupport) >= 0
                && (nSupport & 3) == 3
                && sub_00513BC0_SetEaxRoomOff(1))
            {
                gnEaxVersion = 1;
            }
            else
            {
                D2SOUND_ReleaseSoundObjects();
            }
        }
        if (!gnEaxVersion)
        {
            LOGMANAGER_WriteLogLine("........DirectSound progress: Unsupported EAX or EAX emulation");
            D2SOUND_CloseSoundSystem();
            return;
        }
    }

    D2DSBufferCaps tCaps;
    memset(&tCaps, 0, sizeof(tCaps));
    tCaps.dwSize = 0x14;
    gpSoundObject->GetCaps(&tCaps);
    D2SOUND_ClearSoundBuffer(gpSoundObject, 0, tCaps.dwBufferBytes);
    gpSoundObject->Play(0, 0, 1);
    D2SOUND_StartSoundThread();
    D2SOUND_CreateStreamChannel(gnChannelArg);
    D2SOUND_LoadRegistrySettings();
    D2SOUND_SetMasterVolume(0xFF);
    gnSoundState_00881764 = 1;
}

#include "gen/data/Source/D2Sound/Unknown_005140D0.inc"

extern int gdwGlobal_00881798; // 0x00881798

