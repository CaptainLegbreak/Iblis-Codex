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

struct D2DSoundBufferStrc;

struct D2SoundStrc;

struct D2WaveFormatStrc;

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" __declspec(dllimport) int __stdcall IsIconic(void* hWnd); // 0x006CC50C

extern void* ghSoundEvent_0088180C; // 0x0088180C

extern int gbIconic_00881814; // 0x00881814

extern "C" void* __cdecl sub_004F59A0_GetHwnd(); // 0x004F59A0

int __cdecl sub_00514920(); // 0x00514920

int __cdecl sub_00514840_IsChannelStreaming(); // 0x00514840

int __cdecl sub_00514990_PickRandomChannel(); // 0x00514990

int __fastcall sub_00515180_FillBuffer(D2SoundStrc* sound,unsigned int sourcePosition,unsigned int destinationPosition,unsigned int size); // 0x00515180

int __fastcall sub_00515300_ClearSoundBuffer(D2DSoundBufferStrc* pBuffer, unsigned long nOffset, unsigned long nBytes); // 0x00515300

void __fastcall sub_00515E40_CloseSoundStream(D2SoundStrc* pSound); // 0x00515E40

int __fastcall sub_00515FD0_RestoreLostBuffer(D2SoundStrc* pSound); // 0x00515FD0

extern "C" double __cdecl sqrt(double x); // 0x006879C0

extern const float gfMaxSoundDistance_006DEB10; // 0x006DEB10

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

void __fastcall sub_005160D0_DestroySound(D2SoundStrc* pSound)
{
    D2_ASSERT(pSound, 0x211);
    EnterCriticalSection(&gSoundLock_0088174C);
    sub_00516070_ResetSound(pSound);
    sub_00516980_RemoveNode(&gpSoundList_00881808, pSound);
    LeaveCriticalSection(&gSoundLock_0088174C);
    FOG_Free(pSound, szD2SoundSmpFile_006DEAEC, 0x21D, 0);
}

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

static inline void sub_00515EE0_StopSoundInline(D2SoundStrc* pSound)
{
    D2_ASSERT(pSound->pBuffer, 658);
    EnterCriticalSection(&gSoundLock_0088174C);
    if (pSound->hStream)
    {
        sub_00515E40_CloseSoundStream(pSound);
    }
    pSound->pBuffer->Stop();
    pSound->bStreaming = 0;
    LeaveCriticalSection(&gSoundLock_0088174C);
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

// 0x00516250
unsigned long __stdcall sub_00516250_SoundThread(void* pParameter)
{
    unsigned long dwPlay;
    while (WaitForSingleObject(ghSoundEvent_0088180C, 50) == 0x102)
    {
        EnterCriticalSection(&gSoundLock_0088174C);

        const int bWasIconic = gbIconic_00881814;
        gbIconic_00881814 = IsIconic(sub_004F59A0_GetHwnd());

        if (sub_00514920() && !sub_00514840_IsChannelStreaming())
        {
            sub_00514990_PickRandomChannel();
        }

        for (D2SoundNodeStrc* pNode = gpSoundList_00881808; pNode; pNode = pNode->pNext)
        {
            D2SoundStrc* pSound = pNode->pSound;
            sub_00515FD0_RestoreLostBuffer(pSound);

            if (gbIconic_00881814 != bWasIconic)
            {
                sub_005157B0_SetSoundVolume(pSound, pSound->nVolume);
            }

            if (pSound->bFading)
            {
                const int nTick = GetTickCount();
                if (nTick >= pSound->nFadeStart && nTick <= pSound->nFadeEnd)
                {
                    sub_005157B0_SetSoundVolume(pSound, (pSound->nFadeTo - pSound->nFadeFrom) * (nTick - pSound->nFadeStart) / (pSound->nFadeEnd - pSound->nFadeStart) + pSound->nFadeFrom);
                }
                else
                {
                    sub_005157B0_SetSoundVolume(pSound, pSound->nFadeTo);
                    if (!pSound->nFadeTo)
                    {
                        sub_00515EE0_StopSoundInline(pSound);
                    }
                    pSound->bFading = 0;
                }
            }

            if (pSound->hStream)
            {
                unsigned int nValueA;
                unsigned int nValueB;
                if (!sub_00418140(pSound->hStream, &nValueA, &nValueB))
                {
                    sub_00515EE0_StopSoundInline(pSound);
                }
            }
            else if (pSound->bStreaming)
            {
                unsigned long dwWrite;
                if (pSound->pBuffer->GetCurrentPosition(&dwPlay, &dwWrite) >= 0)
                {
                    const unsigned long nMask = pSound->nBufferSize - 1;
                    sub_AdvancePlayPositionInline(pSound, dwPlay, nMask);

                    if (!pSound->bStreamed)
                    {
                        const unsigned long* const pnPos = &pSound->nPosition;
                        if (pSound->nFillPosition - *pnPos < pSound->nHalfBufferBytes || *pnPos > pSound->nFillPosition)
                        {
                            const unsigned long nFillOffset = pSound->nFillPosition & nMask;
                            sub_00515180_FillBuffer(pSound, pSound->nFillPosition, nFillOffset, pSound->nHalfBufferBytes);
                            pSound->nLoopStart = -1;
                            pSound->bSecondHalf = nFillOffset != 0;
                        }
                    }
                    else if (!pSound->bNoLoop)
                    {
                        if (dwPlay < pSound->nHalfBufferBytes && !pSound->bSecondHalf)
                        {
                            sub_00515300_ClearSoundBuffer(pSound->pBuffer, pSound->nHalfBufferBytes, pSound->nHalfBufferBytes);
                            pSound->bSecondHalf = 1;
                        }

                        if (dwPlay >= pSound->nHalfBufferBytes && pSound->bSecondHalf == 1)
                        {
                            sub_00515300_ClearSoundBuffer(pSound->pBuffer, 0, pSound->nHalfBufferBytes);
                            pSound->bSecondHalf = 0;
                        }

                        if (pSound->nPosition > pSound->nDataSize)
                        {
                            pSound->pBuffer->Stop();
                            pSound->bStreaming = 0;
                        }
                    }
                }
            }
        }

        LeaveCriticalSection(&gSoundLock_0088174C);
    }

    return 0;
}

static const unsigned char* __stdcall sub_005166D0_FindRiffChunk(const unsigned char* pData, unsigned int* pnSize, unsigned int nChunkId, unsigned int* pnChunkSize)
{
    while (*pnSize >= 8)
    {
        *pnSize -= 8;
        const unsigned int nRemaining = *pnSize;
        const unsigned int* pHeader = (const unsigned int*)pData;
        pData += 8;
        const unsigned int nLength = pHeader[1];
        if (pHeader[0] == nChunkId)
        {
            *pnChunkSize = nLength;
            return pData;
        }

        if (nRemaining < nLength)
            return 0;

        *pnSize = nRemaining - nLength;
        pData += nLength;
    }

    return 0;
}

// 0x00516760
const unsigned char* __fastcall sub_00516760_ReadWaveHeader(const unsigned int* pRiff, unsigned int* pnSize, D2WaveFormatStrc* pFormat)
{
    D2WaveFormatStrc* const pOut = pFormat;
    if (*pnSize < 0x20)
        return 0;

    *pnSize -= 12;
    if (pRiff[0] != 0x46464952 || pRiff[2] != 0x45564157)
        return 0;

    unsigned int nChunkSize = 0;
    const unsigned char* pChunk = sub_005166D0_FindRiffChunk((const unsigned char*)pRiff + 12, pnSize, 0x20746D66, &nChunkSize);
    if (!pChunk)
        return 0;

    if (nChunkSize < 0x10)
        return 0;

    if (*pnSize < nChunkSize)
        return 0;

    const D2WaveFormatStrc* pChunkFormat = (const D2WaveFormatStrc*)pChunk;
    *pnSize -= nChunkSize;
    pChunk += nChunkSize;
    pOut->wFormatTag = pChunkFormat->wFormatTag;
    pOut->nChannels = pChunkFormat->nChannels;
    pOut->nSamplesPerSec = pChunkFormat->nSamplesPerSec;
    pOut->nAvgBytesPerSec = pChunkFormat->nAvgBytesPerSec;
    pOut->nBlockAlign = pChunkFormat->nBlockAlign;
    pOut->wBitsPerSample = pChunkFormat->wBitsPerSample;
    pOut->cbSize = 0;

    pChunk = sub_005166D0_FindRiffChunk(pChunk, pnSize, 0x61746164, &nChunkSize);
    if (pChunk && *pnSize >= nChunkSize)
    {
        *pnSize = nChunkSize;
        return pChunk;
    }

    return 0;
}

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
        fDistance = gfMaxSoundDistance_006DEB10;

    if (fDistance < 2.0f)
        return 0.0f;

    return SOUND_Log2F(fDistance * 0.5f) * 6.0f;
}

// 0x00516830
void __fastcall sub_00516830_GetPositionalVolumePan(int* pVolume, int* pPan, float fX, float fY, float fZ)
{
    // stands for the original rounding the distance twice through the fY slot and the pan through the fX slot (no plain form found)
    *(volatile float*)&fY = SOUND_GetDistance(fX, fY, fZ);
    const float fAttenuation = SOUND_GetAttenuation(*(volatile float*)&fY);

    int nVolume = (int)(255.0f / SOUND_PowF(10.0f, fAttenuation / 20.0f));
    nVolume = nVolume > 0 ? nVolume : 0;
    if (nVolume >= 255)
        nVolume = 255;

    *(volatile float*)&fX = fX * 127.0f / 1.25f + 128.0f;
    int nPan = (int)*(volatile float*)&fX;
    nPan = nPan > 0 ? nPan : 0;
    if (nPan >= 255)
        nPan = 255;

    *pVolume = nVolume;
    *pPan = nPan;
}
