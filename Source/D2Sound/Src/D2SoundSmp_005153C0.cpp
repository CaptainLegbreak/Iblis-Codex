#include "D2Sound.h"
#include "D2SoundTypes.h"
#include "FogApi.h"
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
struct D2SoundNodeStrc;
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
D2DirectSoundStrc* __cdecl D2SOUND_GetDirectSound();                                                                   // 0x00513B50
extern const D2GuidStrc gtIidDirectSound3DBuffer;                                                   // 0x006DE3D0
extern const D2GuidStrc gtIidKsPropertySet;                                                         // 0x006DE410
extern const D2GuidStrc gtEaxBuffer20PropertySet;                                                   // 0x006DE470
extern const D2GuidStrc gtEaxBuffer10PropertySet;                                                   // 0x006DE490
extern "C" const char gszD2SoundSmpFile[];                                                          // 0x006DEAEC
extern D2CriticalSectionStrc gtSoundLock;                                                           // 0x0088174C
extern int gbSoundGlobalFocus;                                                                     // 0x00881804
extern D2SoundNodeStrc* gpSoundList;                                                               // 0x00881808
struct D2DSoundBufferStrc;
struct D2SoundStrc;
struct D2WaveFormatStrc;
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern "C" __declspec(dllimport) int __stdcall IsIconic(void* hWnd); // 0x006CC50C
extern void* ghSoundEvent; // 0x0088180C
extern int gbIconic; // 0x00881814
extern "C" void* __cdecl sub_004F59A0_GetHwnd(); // 0x004F59A0
int __fastcall D2SOUNDSMP_ClearSoundBuffer(D2DSoundBufferStrc* pBuffer, unsigned long nOffset, unsigned long nBytes); // 0x00515300
extern "C" double __cdecl sqrt(double x); // 0x006879C0
extern const float gfMaxSoundDistance; // 0x006DEB10
// 0x005153C0
static int __stdcall D2SOUNDSMP_CreateSoundBuffer(unsigned int nFlags, D2SoundStrc* pSound)
{
    D2WaveFormatStrc tFormat;
    D2SOUNDSMP_InitWaveFormat(&tFormat, (nFlags & 1) ? 2 : 1);

    const unsigned int nBytes = (nFlags & 1) ? 0x40000 : 0x20000;
    D2DSBufferDescStrc tDesc;
    memset(&tDesc, 0, sizeof(tDesc));
    tDesc.dwSize = 0x14;
    tDesc.dwFlags = gbSoundGlobalFocus ? 0x80A0 : 0xA0;
    if (nFlags & 2)
        tDesc.dwFlags |= 0x14;
    else
        tDesc.dwFlags |= 0x40;
    tDesc.dwBufferBytes = nBytes;
    tDesc.lpwfxFormat = &tFormat;

    if (D2SOUND_GetDirectSound()->CreateSoundBuffer(&tDesc, &pSound->pBuffer, 0) < 0)
        return 0;

    if (nFlags & 2)
    {
        if (pSound->pBuffer->QueryInterface(gtIidDirectSound3DBuffer, (void**)&pSound->p3DBuffer) < 0)
        {
            pSound->pBuffer->Release();
            return 0;
        }
    }

// build: symbol ?D2SOUND_IsEaxEnabled@* 0x00513B70
    if ((nFlags & 2) && D2SOUND_IsEaxEnabled())
    {
        if (pSound->p3DBuffer->QueryInterface(gtIidKsPropertySet, (void**)&pSound->pPropertySet) < 0)
        {
            pSound->pBuffer->Release();
            return 0;
        }

        unsigned long dwSupport = 0;
// build: symbol ?D2SOUND_GetEaxVersion@* 0x00513B90
        if (D2SOUND_GetEaxVersion() == 1)
        {
            if (pSound->pPropertySet->QuerySupport(gtEaxBuffer10PropertySet, 1, &dwSupport) < 0 || (dwSupport & 3) != 3)
            {
                pSound->pPropertySet->Release();
                pSound->pBuffer->Release();
                return 0;
            }
        }
        else
        {
            if (pSound->pPropertySet->QuerySupport(gtEaxBuffer20PropertySet, 1, &dwSupport) < 0 || (dwSupport & 3) != 3)
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
// build: symbol ?D2SOUNDSMP_ReleaseSoundBuffers@* 0x00516070
static void D2SOUNDSMP_ReleaseSoundBuffers(D2SoundStrc* pSound)
{
    D2SOUNDSMP_StopSound(pSound);
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
// build: symbol ?D2SOUNDSMP_ResetSound@* 0x00516140
void __fastcall D2SOUNDSMP_ResetSound(D2SoundStrc* pSound)
{
    D2_ASSERT(pSound && pSound->pBuffer, 0x226);
    D2_ASSERT(!pSound->hStream, 0x227);

    EnterCriticalSection(&gtSoundLock);
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
        D2SOUNDSMP_ReleaseSoundBuffers(pSound);
        D2SOUNDSMP_CreateSoundBuffer(nFlags, pSound);
    }

    pSound->pBuffer->SetCurrentPosition(0);
    if (pSound->p3DBuffer)
    {
        pSound->p3DBuffer->SetMaxDistance(100.0f, 0);
        pSound->p3DBuffer->SetMinDistance(2.0f, 0);
    }
    if (pSound->dwFlags & 2)
        D2SOUNDSMP_SetSoundPosition(pSound, 0.0f, 0.0f, 0.0f);
    else
        pSound->pBuffer->SetPan(0);
    D2SOUNDSMP_SetSoundAttenuation(pSound, 0.0f);
    D2SOUNDSMP_SetSoundVolume(pSound, 0xFF);
    LeaveCriticalSection(&gtSoundLock);
}
static inline void sub_00515EE0_StopSoundInline(D2SoundStrc* pSound)
{
    D2_ASSERT(pSound->pBuffer, 658);
    EnterCriticalSection(&gtSoundLock);
    if (pSound->hStream)
    {
        D2SOUNDSMP_CloseSoundStream(pSound);
    }
    pSound->pBuffer->Stop();
    pSound->bStreaming = 0;
    LeaveCriticalSection(&gtSoundLock);
}
static inline void sub_AdvancePlayPositionInline(D2SoundStrc* pSound, unsigned long dwPlay, unsigned long nMask)
{
    const unsigned long nOffset = pSound->nPosition & nMask;
    unsigned long nPosition = pSound->nPosition - nOffset;
    if (dwPlay < nOffset)
    {
        nPosition += pSound->nBufferSize;
    }
    pSound->nPosition = nPosition + dwPlay;
}
const unsigned char* __fastcall D2SOUNDSMP_ReadWaveHeader(const unsigned int* pRiff, unsigned int* pnSize, D2WaveFormatStrc* pFormat); // 0x00516760
static float SOUND_SqrtF(float fValue)
{
    return (float)sqrt(fValue);
}
static float SOUND_LogF(float fValue)
{
    return (float)log(fValue);
}
static float SOUND_Log2F(float fValue)
{
    return SOUND_LogF(fValue) / 0.6931472f;
}
static float SOUND_PowF(float fBase, float fExponent)
{
    return (float)pow(fBase, fExponent);
}
static float SOUND_GetDistance(float fX, float fY, float fZ)
{
    return SOUND_SqrtF(fX * fX + fY * fY + fZ * fZ);
}
static __forceinline float SOUND_GetAttenuation(float fDistance)
{
    if (fDistance > 100.0)
        fDistance = gfMaxSoundDistance;

    if (fDistance < 2.0f)
        return 0.0f;

    return SOUND_Log2F(fDistance * 0.5f) * 6.0f;
}
void __fastcall D2SOUNDSMP_GetPositionalVolumePan(int* pVolume, int* pPan, float fX, float fY, float fZ); // 0x00516830
