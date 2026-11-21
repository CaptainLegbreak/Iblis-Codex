#include "D2Sound.h"
#include "D2SoundTypes.h"

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0


struct D2SoundNodeStrc;

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
D2DirectSoundStrc* __cdecl sub_00513B50();                                                                   // 0x00513B50
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
extern "C" const char szD2SoundSmpFile_006DEAEC[];                                                          // 0x006DEAEC
extern D2CriticalSectionStrc gSoundLock_0088174C;                                                           // 0x0088174C
extern int gbSoundGlobalFocus_00881804;                                                                     // 0x00881804
extern D2SoundNodeStrc* gpSoundList_00881808;                                                               // 0x00881808

// 0x005153C0
static int __stdcall sub_005153C0_CreateSoundBuffer(unsigned int nFlags, D2SoundStrc* pSound)
{
    D2WaveFormatStrc tFormat;
    sub_00516720_InitWaveFormat(&tFormat, (nFlags & 1) ? 2 : 1);

    const unsigned int nBytes = (nFlags & 1) ? 0x40000 : 0x20000;
    D2DSBufferDescStrc tDesc;
    memset(&tDesc, 0, sizeof(tDesc));
    tDesc.dwSize = 0x14;
    tDesc.dwFlags = gbSoundGlobalFocus_00881804 ? 0x80A0 : 0xA0;
    if (nFlags & 2)
        tDesc.dwFlags |= 0x14;
    else
        tDesc.dwFlags |= 0x40;
    tDesc.dwBufferBytes = nBytes;
    tDesc.lpwfxFormat = &tFormat;

    if (sub_00513B50()->CreateSoundBuffer(&tDesc, &pSound->pBuffer, 0) < 0)
        return 0;

    if (nFlags & 2)
    {
        if (pSound->pBuffer->QueryInterface(gIidDirectSound3DBuffer_006DE3D0, (void**)&pSound->p3DBuffer) < 0)
        {
            pSound->pBuffer->Release();
            return 0;
        }
    }

    if ((nFlags & 2) && sub_00513B70())
    {
        if (pSound->p3DBuffer->QueryInterface(gIidKsPropertySet_006DE410, (void**)&pSound->pPropertySet) < 0)
        {
            pSound->pBuffer->Release();
            return 0;
        }

        unsigned long dwSupport = 0;
        if (sub_00513B90() == 1)
        {
            if (pSound->pPropertySet->QuerySupport(gEaxBuffer10PropertySet_006DE490, 1, &dwSupport) < 0 || (dwSupport & 3) != 3)
            {
                pSound->pPropertySet->Release();
                pSound->pBuffer->Release();
                return 0;
            }
        }
        else
        {
            if (pSound->pPropertySet->QuerySupport(gEaxBuffer20PropertySet_006DE470, 1, &dwSupport) < 0 || (dwSupport & 3) != 3)
            {
                pSound->pPropertySet->Release();
                pSound->pBuffer->Release();
                return 0;
            }
        }
    }

    pSound->nBufferSize = nBytes;
    pSound->nHalfBufferBytes = nBytes >> 1;
    pSound->dwFlags = nFlags;
    pSound->nLoopStart = -1;
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

    D2SoundStrc* pSound = (D2SoundStrc*)FOG_Alloc(0x60, szD2SoundSmpFile_006DEAEC, 0x1D9, 0);
    memset(pSound, 0, 0x60);
    if (!sub_005153C0_CreateSoundBuffer(nFlags, pSound))
    {
        FOG_Free(pSound, szD2SoundSmpFile_006DEAEC, 0x1E0, 0);
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
        pSound->pPropertySet->Release();
        pSound->pPropertySet = 0;
    }
    if (pSound->p3DBuffer)
    {
        pSound->p3DBuffer->Release();
        pSound->p3DBuffer = 0;
    }
    if (pSound->pBuffer)
    {
        pSound->pBuffer->Release();
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
    FOG_Free(pSound, szD2SoundSmpFile_006DEAEC, 0x21D, 0);
}

// 0x00516140
void __fastcall sub_00516140_ResetSound(D2SoundStrc* pSound)
{
    D2_ASSERT(pSound && pSound->pBuffer, 0x226);
    D2_ASSERT(!pSound->hStream, 0x227);

    EnterCriticalSection(&gSoundLock_0088174C);
    if (sub_00513BB0())
    {
        pSound->pData = 0;
        pSound->nDataSize = 0;
        pSound->nPosition = 0;
        pSound->nFillPosition = 0;
        pSound->bStreamed = 0;
        pSound->bNoLoop = 0;
        pSound->nMinDataSize = 0;
    }
    else
    {
        const unsigned int nFlags = pSound->dwFlags;
        sub_00516070_ResetSound(pSound);
        sub_005153C0_CreateSoundBuffer(nFlags, pSound);
    }

    pSound->pBuffer->SetCurrentPosition(0);
    if (pSound->p3DBuffer)
    {
        pSound->p3DBuffer->SetMaxDistance(100.0f, 0);
        pSound->p3DBuffer->SetMinDistance(2.0f, 0);
    }
    if (pSound->dwFlags & 2)
        sub_00515950_SetSoundPosition(pSound, 0.0f, 0.0f, 0.0f);
    else
        pSound->pBuffer->SetPan(0);
    sub_00515A90_SetSoundAttenuation(pSound, 0.0f);
    sub_005157B0_SetSoundVolume(pSound, 0xFF);
    LeaveCriticalSection(&gSoundLock_0088174C);
}
