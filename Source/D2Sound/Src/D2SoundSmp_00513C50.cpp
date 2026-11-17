#include "D2Sound.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2KsPropertySetStrc;
struct D2DSoundBufferStrc;
struct D2DSound3DBufferStrc;
struct D2DirectSoundStrc;
struct D2SoundNodeStrc;
struct D2GuidStrc;
struct D2KsPropertySetVtblStrc;
struct D2DSoundBufferVtblStrc;
struct D2DSound3DBufferVtblStrc;
struct D2SoundStrc;
struct D2EaxEnvironmentStrc;
struct D2WaveFormatStrc;
struct D2DSBufferDescStrc;
struct D2DirectSoundVtblStrc;

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2GuidStrc
{
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
};

struct D2KsPropertySetVtblStrc
{
    void* unk0x00[2];
    unsigned long (__stdcall* Release)(D2KsPropertySetStrc* pThis);
    unsigned char unk_0C[0x4];
    long (__stdcall* Set)(D2KsPropertySetStrc* pThis, const D2GuidStrc& rguidPropSet, unsigned long dwPropID, void* pInstanceData, unsigned long cbInstanceData, void* pPropData, unsigned long cbPropData);
    long (__stdcall* QuerySupport)(D2KsPropertySetStrc* pThis, const D2GuidStrc& rguidPropSet, unsigned long dwPropID, unsigned long* pTypeSupport);
};

struct D2KsPropertySetStrc
{
    D2KsPropertySetVtblStrc* lpVtbl;
};

struct D2DSoundBufferVtblStrc
{
    long (__stdcall* QueryInterface)(D2DSoundBufferStrc* pThis, const D2GuidStrc& riid, void** ppvObject);
    void* unk0x04;
    unsigned long (__stdcall* Release)(D2DSoundBufferStrc* pThis);
    unsigned char unk_0C[0x18];
    long (__stdcall* GetStatus)(D2DSoundBufferStrc* pThis, unsigned long* pdwStatus);
    unsigned char unk_28[0x4];
    long (__stdcall* Lock)(D2DSoundBufferStrc* pThis, unsigned long dwOffset, unsigned long dwBytes, void** ppvAudioPtr1, unsigned long* pdwAudioBytes1, void** ppvAudioPtr2, unsigned long* pdwAudioBytes2, unsigned long dwFlags);
    unsigned char unk_30[0x4];
    long (__stdcall* SetCurrentPosition)(D2DSoundBufferStrc* pThis, unsigned long dwNewPosition);
    void* unk0x38[2];
    long (__stdcall* SetPan)(D2DSoundBufferStrc* pThis, long lPan);
    unsigned char unk_44[0x8];
    long (__stdcall* Unlock)(D2DSoundBufferStrc* pThis, void* pvAudioPtr1, unsigned long dwAudioBytes1, void* pvAudioPtr2, unsigned long dwAudioBytes2);
};

struct D2DSoundBufferStrc
{
    D2DSoundBufferVtblStrc* lpVtbl;
};

struct D2DSound3DBufferVtblStrc
{
    long (__stdcall* QueryInterface)(D2DSound3DBufferStrc* pThis, const D2GuidStrc& riid, void** ppvObject);
    void* unk0x04;
    unsigned long (__stdcall* Release)(D2DSound3DBufferStrc* pThis);
    void* unk0x0C[13];
    long (__stdcall* SetMaxDistance)(D2DSound3DBufferStrc* pThis, float flMaxDistance, unsigned long dwApply);
    long (__stdcall* SetMinDistance)(D2DSound3DBufferStrc* pThis, float flMinDistance, unsigned long dwApply);
    unsigned char unk_48[0x4];
    long (__stdcall* SetPosition)(D2DSound3DBufferStrc* pThis, float x, float y, float z, unsigned long dwApply);
};

struct D2DSound3DBufferStrc
{
    D2DSound3DBufferVtblStrc* lpVtbl;
};

struct D2SoundStrc
{
    D2DSoundBufferStrc* pBuffer;
    unsigned int nBufferBytes;
    unsigned int nHalfBufferBytes;
    D2DSound3DBufferStrc* p3DBuffer;
    D2KsPropertySetStrc* pPropertySet;
    int unk0x14;
    int unk0x18;
    int unk0x1C;
    int unk0x20;
    int unk0x24;
    int unk0x28;
    int unk0x2C;
    int nIndex;
    unsigned int dwFlags;
    int f_38;
    float f_3C;
    int unk0x40;
    int unk0x44;
    void* hStream;
    int unk0x4C[5];
};

struct D2EaxEnvironmentStrc
{
    unsigned int dwEnvironment;
    float fEnvironmentSize;
    float fEnvironmentDiffusion;
    int nRoom;
    int f_10;
    float f_14;
    float f_18;
    int f_1C;
    float f_20;
    int f_24;
    float f_28;
    float fRoomRolloffFactor;
    float f_30;
};
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC218
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
int __cdecl sub_00513BA0(); // 0x00513BA0
float __stdcall sub_00516670_RoomToVolume(float fRoom); // 0x00516670
extern const D2GuidStrc gEaxListener20PropertySet_006DE460; // 0x006DE460
extern const D2GuidStrc gEaxBuffer20PropertySet_006DE470; // 0x006DE470
extern const D2GuidStrc gEax10PropertySet_006DE480; // 0x006DE480
extern const D2GuidStrc gEaxBuffer10PropertySet_006DE490; // 0x006DE490
extern D2CriticalSectionStrc gSoundCriticalSection_0088174C; // 0x0088174C
extern int gbEaxEnabled_00881770; // 0x00881770
extern int gnEaxVersion_00881774; // 0x00881774
extern int gbEaxRoomOff_00881778; // 0x00881778

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
struct D2DSBufferDescStrc
{
    unsigned long dwSize;
    unsigned long dwFlags;
    unsigned long dwBufferBytes;
    unsigned long dwReserved;
    D2WaveFormatStrc* lpwfxFormat;
};

struct D2DirectSoundVtblStrc
{
    void* unk0x00[3];
    long (__stdcall* CreateSoundBuffer)(D2DirectSoundStrc* pThis, D2DSBufferDescStrc* pDesc, D2DSoundBufferStrc** ppBuffer, void* pUnkOuter);
};

struct D2DirectSoundStrc
{
    D2DirectSoundVtblStrc* lpVtbl;
};

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
D2DirectSoundStrc* __cdecl sub_00513B50(); // 0x00513B50
void __fastcall sub_005157B0_SetSoundVolume(D2SoundStrc* pSound, int nVolume); // 0x005157B0
void __fastcall sub_00515950_SetSoundPosition(D2SoundStrc* pSound, float x, float y, float z); // 0x00515950
void __fastcall sub_00515A90_SetSoundAttenuation(D2SoundStrc* pSound, float fAttenuation); // 0x00515A90
void __fastcall sub_00515EE0_StopSound(D2SoundStrc* pSound); // 0x00515EE0
void __fastcall sub_00516720_InitWaveFormat(D2WaveFormatStrc* pFormat, int nChannels); // 0x00516720
void __fastcall sub_00516950_LinkEntry(D2SoundNodeStrc** ppList, void* pData); // 0x00516950
void __fastcall sub_00516980_RemoveNode(D2SoundNodeStrc** ppList, void* pData); // 0x00516980
extern const D2GuidStrc gIidDirectSound3DBuffer_006DE3D0; // 0x006DE3D0
extern const D2GuidStrc gIidKsPropertySet_006DE410; // 0x006DE410
extern D2CriticalSectionStrc gSoundLock_0088174C; // 0x0088174C

D2KsPropertySetStrc* gpEaxListenerPropertySet_008816D8; // 0x008816D8

// 0x00513C50
void __fastcall sub_00513C50_SetEaxEnvironment(D2EaxEnvironmentStrc* pEnvironment)
{
    if (!gbEaxEnabled_00881770 || !gpEaxListenerPropertySet_008816D8)
        return;
    if (gnEaxVersion_00881774 == 1)
    {
        float fVolume = sub_00516670_RoomToVolume((float)pEnvironment->nRoom);
        gpEaxListenerPropertySet_008816D8->lpVtbl->Set(gpEaxListenerPropertySet_008816D8, gEax10PropertySet_006DE480, 1, 0, 0, pEnvironment, 4);
        gpEaxListenerPropertySet_008816D8->lpVtbl->Set(gpEaxListenerPropertySet_008816D8, gEax10PropertySet_006DE480, 2, 0, 0, &fVolume, 4);
        gpEaxListenerPropertySet_008816D8->lpVtbl->Set(gpEaxListenerPropertySet_008816D8, gEax10PropertySet_006DE480, 3, 0, 0, &pEnvironment->f_14, 4);
    }
    if (gnEaxVersion_00881774 == 2)
    {
        int nFlags = 0x20;
        gpEaxListenerPropertySet_008816D8->lpVtbl->Set(gpEaxListenerPropertySet_008816D8, gEaxListener20PropertySet_006DE460, 0xB, 0, 0, pEnvironment, 4);
        gpEaxListenerPropertySet_008816D8->lpVtbl->Set(gpEaxListenerPropertySet_008816D8, gEaxListener20PropertySet_006DE460, 0xF, 0, 0, &nFlags, 4);
        gpEaxListenerPropertySet_008816D8->lpVtbl->Set(gpEaxListenerPropertySet_008816D8, gEaxListener20PropertySet_006DE460, 0xB, 0, 0, pEnvironment, 4);
        gpEaxListenerPropertySet_008816D8->lpVtbl->Set(gpEaxListenerPropertySet_008816D8, gEaxListener20PropertySet_006DE460, 0xC, 0, 0, &pEnvironment->fEnvironmentSize, 4);
        gpEaxListenerPropertySet_008816D8->lpVtbl->Set(gpEaxListenerPropertySet_008816D8, gEaxListener20PropertySet_006DE460, 0xD, 0, 0, &pEnvironment->fEnvironmentDiffusion, 4);
        gpEaxListenerPropertySet_008816D8->lpVtbl->Set(gpEaxListenerPropertySet_008816D8, gEaxListener20PropertySet_006DE460, 2, 0, 0, &pEnvironment->nRoom, 4);
        gpEaxListenerPropertySet_008816D8->lpVtbl->Set(gpEaxListenerPropertySet_008816D8, gEaxListener20PropertySet_006DE460, 3, 0, 0, &pEnvironment->f_10, 4);
        gpEaxListenerPropertySet_008816D8->lpVtbl->Set(gpEaxListenerPropertySet_008816D8, gEaxListener20PropertySet_006DE460, 5, 0, 0, &pEnvironment->f_14, 4);
        gpEaxListenerPropertySet_008816D8->lpVtbl->Set(gpEaxListenerPropertySet_008816D8, gEaxListener20PropertySet_006DE460, 6, 0, 0, &pEnvironment->f_18, 4);
        gpEaxListenerPropertySet_008816D8->lpVtbl->Set(gpEaxListenerPropertySet_008816D8, gEaxListener20PropertySet_006DE460, 7, 0, 0, &pEnvironment->f_1C, 4);
        gpEaxListenerPropertySet_008816D8->lpVtbl->Set(gpEaxListenerPropertySet_008816D8, gEaxListener20PropertySet_006DE460, 8, 0, 0, &pEnvironment->f_20, 4);
        gpEaxListenerPropertySet_008816D8->lpVtbl->Set(gpEaxListenerPropertySet_008816D8, gEaxListener20PropertySet_006DE460, 9, 0, 0, &pEnvironment->f_24, 4);
        gpEaxListenerPropertySet_008816D8->lpVtbl->Set(gpEaxListenerPropertySet_008816D8, gEaxListener20PropertySet_006DE460, 0xA, 0, 0, &pEnvironment->f_28, 4);
        gpEaxListenerPropertySet_008816D8->lpVtbl->Set(gpEaxListenerPropertySet_008816D8, gEaxListener20PropertySet_006DE460, 4, 0, 0, &pEnvironment->fRoomRolloffFactor, 4);
        gpEaxListenerPropertySet_008816D8->lpVtbl->Set(gpEaxListenerPropertySet_008816D8, gEaxListener20PropertySet_006DE460, 0xE, 0, 0, &pEnvironment->f_30, 4);
    }
    gbEaxRoomOff_00881778 = pEnvironment->nRoom == -10000;
}

// 0x00515300
int __fastcall sub_00515300_ClearSoundBuffer(D2DSoundBufferStrc* pBuffer, unsigned long nOffset, unsigned long nBytes)
{
    void* pAudio = 0;
    D2_ASSERT(pBuffer, 0x14B);
    EnterCriticalSection(&gSoundCriticalSection_0088174C);
    if (pBuffer->lpVtbl->Lock(pBuffer, nOffset, nBytes, &pAudio, &nBytes, 0, 0, 0) < 0)
    {
        LeaveCriticalSection(&gSoundCriticalSection_0088174C);
        return 0;
    }
    memset(pAudio, 0, nBytes);
    pBuffer->lpVtbl->Unlock(pBuffer, pAudio, nBytes, 0, 0);
    LeaveCriticalSection(&gSoundCriticalSection_0088174C);
    return 1;
}

// 0x00515950
void __fastcall sub_00515950_SetSoundPosition(D2SoundStrc* pSound, float x, float y, float z)
{
    D2_ASSERT(pSound && pSound->pBuffer, 0x302);
    if (pSound->dwFlags & 2)
        pSound->p3DBuffer->lpVtbl->SetPosition(pSound->p3DBuffer, x, y, z, 0);
}

// 0x00515A90
void __fastcall sub_00515A90_SetSoundAttenuation(D2SoundStrc* pSound, float fAttenuation)
{
    D2_ASSERT(pSound, 0x345);
    pSound->f_3C = fAttenuation;
    if (pSound->pPropertySet && sub_00513B90() == 2)
    {
        if ((pSound->dwFlags & 4) || fAttenuation == 0.0f)
        {
            fAttenuation = 1.0f - fAttenuation;
            int nValue = (int)sub_005165F0_ToDecibels(0.0f, 1.0f, fAttenuation);
            pSound->pPropertySet->lpVtbl->Set(pSound->pPropertySet, gEaxBuffer20PropertySet_006DE470, 7, 0, 0, &nValue, 4);
        }
    }
}

// 0x00515B40
void __fastcall sub_00515B40_SetSoundReverbMix(D2SoundStrc* pSound, float fReverbMix)
{
    D2_ASSERT(pSound, 0x359);
    if (sub_00513BA0())
        fReverbMix = 0.0f;
    if (pSound->pPropertySet)
    {
        if (sub_00513B90() == 1)
        {
            if (fReverbMix != 0.0f)
                fReverbMix = -1.0f;
            pSound->pPropertySet->lpVtbl->Set(pSound->pPropertySet, gEaxBuffer10PropertySet_006DE490, 1, 0, 0, &fReverbMix, 4);
        }
        else
        {
            int nValue = (int)sub_005165F0_ToDecibels(0.0f, 1.0f, fReverbMix);
            pSound->pPropertySet->lpVtbl->Set(pSound->pPropertySet, gEaxBuffer20PropertySet_006DE470, 5, 0, 0, &nValue, 4);
            pSound->pPropertySet->lpVtbl->Set(pSound->pPropertySet, gEaxBuffer20PropertySet_006DE470, 4, 0, 0, &nValue, 4);
        }
    }
}

#include "gen/data/Source/D2Sound/Src/D2SoundSmp_00513C50.inc"

int gbSoundGlobalFocus_00881804; // 0x00881804

D2SoundNodeStrc* gpSoundList_00881808; // 0x00881808

static int __stdcall sub_005153C0_CreateSoundBuffer(unsigned int nFlags, D2SoundStrc* pSound)
{
    D2WaveFormatStrc tFormat;
    sub_00516720_InitWaveFormat(&tFormat, (nFlags & 1) ? 2 : 1);

    D2DSBufferDescStrc tDesc;
    memset(&tDesc, 0, sizeof(tDesc));
    const unsigned int nBytes = (nFlags & 1) ? 0x40000 : 0x20000;
    tDesc.dwSize = 0x14;
    tDesc.dwFlags = gbSoundGlobalFocus_00881804 ? 0x80A0 : 0xA0;
    if (nFlags & 2)
        tDesc.dwFlags |= 0x14;
    else
        tDesc.dwFlags |= 0x40;
    tDesc.dwBufferBytes = nBytes;
    tDesc.lpwfxFormat = &tFormat;

    D2DirectSoundStrc* pDirectSound = sub_00513B50();
    if (pDirectSound->lpVtbl->CreateSoundBuffer(pDirectSound, &tDesc, &pSound->pBuffer, 0) < 0)
        return 0;

    if (nFlags & 2)
    {
        if (pSound->pBuffer->lpVtbl->QueryInterface(pSound->pBuffer, gIidDirectSound3DBuffer_006DE3D0, (void**)&pSound->p3DBuffer) < 0)
        {
            pSound->pBuffer->lpVtbl->Release(pSound->pBuffer);
            return 0;
        }
    }

    if ((nFlags & 2) && sub_00513B70())
    {
        if (pSound->p3DBuffer->lpVtbl->QueryInterface(pSound->p3DBuffer, gIidKsPropertySet_006DE410, (void**)&pSound->pPropertySet) < 0)
        {
            pSound->pBuffer->lpVtbl->Release(pSound->pBuffer);
            return 0;
        }

        unsigned long dwSupport = 0;
        long hr;
        if (sub_00513B90() == 1)
            hr = pSound->pPropertySet->lpVtbl->QuerySupport(pSound->pPropertySet, gEaxBuffer10PropertySet_006DE490, 1, &dwSupport);
        else
            hr = pSound->pPropertySet->lpVtbl->QuerySupport(pSound->pPropertySet, gEaxBuffer20PropertySet_006DE470, 1, &dwSupport);
        if (hr < 0 || (dwSupport & 3) != 3)
        {
            pSound->pPropertySet->lpVtbl->Release(pSound->pPropertySet);
            pSound->pBuffer->lpVtbl->Release(pSound->pBuffer);
            return 0;
        }
    }

    pSound->nBufferBytes = nBytes;
    pSound->nHalfBufferBytes = nBytes >> 1;
    pSound->dwFlags = nFlags;
    pSound->nIndex = -1;
    return 1;
}

// 0x00515530
D2SoundStrc* __fastcall sub_00515530_CreateSound(unsigned int nFlags, int nValue)
{
    gbSoundGlobalFocus_00881804 = nValue;
    if ((nFlags & 2) && !sub_00513B60())
        return 0;
    if ((nFlags & 2) && (nFlags & 1))
        return 0;

    D2SoundStrc* pSound = (D2SoundStrc*)FOG_Alloc(0x60, ".\\Src\\D2SoundSmp.cpp", 0x1D9, 0);
    memset(pSound, 0, 0x60);
    if (!sub_005153C0_CreateSoundBuffer(nFlags, pSound))
    {
        FOG_Free(pSound, ".\\Src\\D2SoundSmp.cpp", 0x1E0, 0);
        return 0;
    }

    EnterCriticalSection(&gSoundLock_0088174C);
    sub_00516950_LinkEntry(&gpSoundList_00881808, pSound);
    LeaveCriticalSection(&gSoundLock_0088174C);
    return pSound;
}

// 0x00516070
static void sub_00516070_ResetSound(D2SoundStrc* pSound)
{
    sub_00515EE0_StopSound(pSound);
    if (pSound->pPropertySet)
    {
        pSound->pPropertySet->lpVtbl->Release(pSound->pPropertySet);
        pSound->pPropertySet = 0;
    }
    if (pSound->p3DBuffer)
    {
        pSound->p3DBuffer->lpVtbl->Release(pSound->p3DBuffer);
        pSound->p3DBuffer = 0;
    }
    if (pSound->pBuffer)
    {
        pSound->pBuffer->lpVtbl->Release(pSound->pBuffer);
        pSound->pBuffer = 0;
    }
    memset(pSound, 0, 0x60);
}

// 0x005160D0
void __fastcall sub_005160D0_DestroySound(D2SoundStrc* pSound)
{
    D2_ASSERT(pSound, 0x211);
    EnterCriticalSection(&gSoundLock_0088174C);
    sub_00516070_ResetSound(pSound);
    sub_00516980_RemoveNode(&gpSoundList_00881808, pSound);
    LeaveCriticalSection(&gSoundLock_0088174C);
    FOG_Free(pSound, ".\\Src\\D2SoundSmp.cpp", 0x21D, 0);
}

// 0x00516140
void __fastcall sub_00516140_ResetSound(D2SoundStrc* pSound)
{
    D2_ASSERT(pSound && pSound->pBuffer, 0x226);
    D2_ASSERT(!pSound->hStream, 0x227);

    EnterCriticalSection(&gSoundLock_0088174C);
    if (sub_00513BB0())
    {
        pSound->unk0x14 = 0;
        pSound->unk0x18 = 0;
        pSound->unk0x20 = 0;
        pSound->unk0x24 = 0;
        pSound->unk0x2C = 0;
        pSound->unk0x40 = 0;
        pSound->unk0x44 = 0;
    }
    else
    {
        const unsigned int nFlags = pSound->dwFlags;
        sub_00516070_ResetSound(pSound);
        sub_005153C0_CreateSoundBuffer(nFlags, pSound);
    }

    pSound->pBuffer->lpVtbl->SetCurrentPosition(pSound->pBuffer, 0);
    if (pSound->p3DBuffer)
    {
        pSound->p3DBuffer->lpVtbl->SetMaxDistance(pSound->p3DBuffer, 100.0f, 0);
        pSound->p3DBuffer->lpVtbl->SetMinDistance(pSound->p3DBuffer, 2.0f, 0);
    }
    if (pSound->dwFlags & 2)
        sub_00515950_SetSoundPosition(pSound, 0.0f, 0.0f, 0.0f);
    else
        pSound->pBuffer->lpVtbl->SetPan(pSound->pBuffer, 0);
    sub_00515A90_SetSoundAttenuation(pSound, 0.0f);
    sub_005157B0_SetSoundVolume(pSound, 0xFF);
    LeaveCriticalSection(&gSoundLock_0088174C);
}

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
