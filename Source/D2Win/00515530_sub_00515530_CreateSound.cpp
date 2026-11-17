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

struct D2GuidStrc
{
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
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

struct D2DSBufferDescStrc
{
    unsigned long dwSize;
    unsigned long dwFlags;
    unsigned long dwBufferBytes;
    unsigned long dwReserved;
    D2WaveFormatStrc* lpwfxFormat;
};

struct D2DSoundBufferStrc;

struct D2DSoundBufferVtblStrc
{
    long (__stdcall* QueryInterface)(D2DSoundBufferStrc* pThis, const D2GuidStrc& riid, void** ppvObject);
    void* unk0x04;
    unsigned long (__stdcall* Release)(D2DSoundBufferStrc* pThis);
    void* unk0x0C[10];
    long (__stdcall* SetCurrentPosition)(D2DSoundBufferStrc* pThis, unsigned long dwNewPosition);
    void* unk0x38[2];
    long (__stdcall* SetPan)(D2DSoundBufferStrc* pThis, long lPan);
};

struct D2DSoundBufferStrc
{
    D2DSoundBufferVtblStrc* lpVtbl;
};

struct D2DSound3DBufferStrc;

struct D2DSound3DBufferVtblStrc
{
    long (__stdcall* QueryInterface)(D2DSound3DBufferStrc* pThis, const D2GuidStrc& riid, void** ppvObject);
    void* unk0x04;
    unsigned long (__stdcall* Release)(D2DSound3DBufferStrc* pThis);
    void* unk0x0C[13];
    long (__stdcall* SetMaxDistance)(D2DSound3DBufferStrc* pThis, float flMaxDistance, unsigned long dwApply);
    long (__stdcall* SetMinDistance)(D2DSound3DBufferStrc* pThis, float flMinDistance, unsigned long dwApply);
};

struct D2DSound3DBufferStrc
{
    D2DSound3DBufferVtblStrc* lpVtbl;
};

struct D2KsPropertySetStrc;

struct D2KsPropertySetVtblStrc
{
    void* unk0x00[2];
    unsigned long (__stdcall* Release)(D2KsPropertySetStrc* pThis);
    void* unk0x0C[2];
    long (__stdcall* QuerySupport)(D2KsPropertySetStrc* pThis, const D2GuidStrc& rguidPropSet, unsigned long dwPropID, unsigned long* pTypeSupport);
};

struct D2KsPropertySetStrc
{
    D2KsPropertySetVtblStrc* lpVtbl;
};

struct D2DirectSoundStrc;

struct D2DirectSoundVtblStrc
{
    void* unk0x00[3];
    long (__stdcall* CreateSoundBuffer)(D2DirectSoundStrc* pThis, D2DSBufferDescStrc* pDesc, D2DSoundBufferStrc** ppBuffer, void* pUnkOuter);
};

struct D2DirectSoundStrc
{
    D2DirectSoundVtblStrc* lpVtbl;
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

struct D2SoundNodeStrc;

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
D2DirectSoundStrc* __cdecl sub_00513B50();                                                                   // 0x00513B50
int __cdecl sub_00513B60();                                                                                  // 0x00513B60
int __cdecl sub_00513B70();                                                                                  // 0x00513B70
int __cdecl sub_00513B90();                                                                                  // 0x00513B90
int __cdecl sub_00513BB0();                                                                                  // 0x00513BB0
void __fastcall sub_005157B0_SetSoundVolume(D2SoundStrc* pSound, int nVolume);                              // 0x005157B0
void __fastcall sub_00515950_SetSoundPosition(D2SoundStrc* pSound, float x, float y, float z);              // 0x00515950
void __fastcall sub_00515A90_SetSoundAttenuation(D2SoundStrc* pSound, float fAttenuation);                  // 0x00515A90
void __fastcall sub_00515EE0_StopSound(D2SoundStrc* pSound);                                                // 0x00515EE0
void __fastcall sub_00516720_InitWaveFormat(D2WaveFormatStrc* pFormat, int nChannels);                      // 0x00516720
void __fastcall sub_00516950_LinkEntry(D2SoundNodeStrc** ppList, void* pData);                              // 0x00516950
void __fastcall sub_00516980_RemoveNode(D2SoundNodeStrc** ppList, void* pData);                             // 0x00516980

extern const D2GuidStrc gIidDirectSound3DBuffer_006DE3D0;                                                   // 0x006DE3D0
extern const D2GuidStrc gIidKsPropertySet_006DE410;                                                         // 0x006DE410
extern const D2GuidStrc gEaxBuffer20PropertySet_006DE470;                                                   // 0x006DE470
extern const D2GuidStrc gEaxBuffer10PropertySet_006DE490;                                                   // 0x006DE490
extern D2CriticalSectionStrc gSoundLock_0088174C;                                                           // 0x0088174C
int gbSoundGlobalFocus_00881804;                                                                            // 0x00881804
D2SoundNodeStrc* gpSoundList_00881808;                                                                      // 0x00881808

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
