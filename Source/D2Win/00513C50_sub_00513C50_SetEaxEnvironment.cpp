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

struct D2KsPropertySetStrc;

struct D2KsPropertySetVtblStrc
{
    void* unk0x00[4];
    long (__stdcall* Set)(D2KsPropertySetStrc* pThis, const D2GuidStrc& rguidPropSet, unsigned long dwPropID, void* pInstanceData, unsigned long cbInstanceData, void* pPropData, unsigned long cbPropData);
};

struct D2KsPropertySetStrc
{
    D2KsPropertySetVtblStrc* lpVtbl;
};

struct D2DSoundBufferStrc;

struct D2DSoundBufferVtblStrc
{
    void* unk0x00[11];
    long (__stdcall* Lock)(D2DSoundBufferStrc* pThis, unsigned long dwOffset, unsigned long dwBytes, void** ppvAudioPtr1, unsigned long* pdwAudioBytes1, void** ppvAudioPtr2, unsigned long* pdwAudioBytes2, unsigned long dwFlags);
    void* unk0x30[7];
    long (__stdcall* Unlock)(D2DSoundBufferStrc* pThis, void* pvAudioPtr1, unsigned long dwAudioBytes1, void* pvAudioPtr2, unsigned long dwAudioBytes2);
};

struct D2DSoundBufferStrc
{
    D2DSoundBufferVtblStrc* lpVtbl;
};

struct D2DSound3DBufferStrc;

struct D2DSound3DBufferVtblStrc
{
    void* unk0x00[19];
    long (__stdcall* SetPosition)(D2DSound3DBufferStrc* pThis, float x, float y, float z, unsigned long dwApply);
};

struct D2DSound3DBufferStrc
{
    D2DSound3DBufferVtblStrc* lpVtbl;
};

struct D2SoundStrc
{
    D2DSoundBufferStrc* pBuffer;
    int unk0x04[2];
    D2DSound3DBufferStrc* p3DBuffer;
    D2KsPropertySetStrc* pPropertySet;
    int unk0x14[8];
    unsigned int dwFlags;
    int f_38;
    float f_3C;
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

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC218
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

int __cdecl sub_00513B90();                                                                                  // 0x00513B90
int __cdecl sub_00513BA0();                                                                                  // 0x00513BA0
float __stdcall sub_005165F0_ToDecibels(float fMin, float fMax, float fValue);                              // 0x005165F0
float __stdcall sub_00516670_RoomToVolume(float fRoom);                                                      // 0x00516670

extern const D2GuidStrc gEaxListener20PropertySet_006DE460;                                                 // 0x006DE460
extern const D2GuidStrc gEaxBuffer20PropertySet_006DE470;                                                   // 0x006DE470
extern const D2GuidStrc gEax10PropertySet_006DE480;                                                         // 0x006DE480
extern const D2GuidStrc gEaxBuffer10PropertySet_006DE490;                                                   // 0x006DE490
D2KsPropertySetStrc* gpEaxListenerPropertySet_008816D8;                                                     // 0x008816D8
extern D2CriticalSectionStrc gSoundCriticalSection_0088174C;                                                // 0x0088174C
extern int gbEaxEnabled_00881770;                                                                           // 0x00881770
extern int gnEaxVersion_00881774;                                                                           // 0x00881774
extern int gbEaxRoomOff_00881778;                                                                           // 0x00881778

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

#include "gen/data/Source/D2Win/00513C50_sub_00513C50_SetEaxEnvironment.inc"
