#include "D2Sound.h"
struct D2DSoundBufferStrc;
struct D2SoundStrc;
struct D2SoundNodeStrc;
struct D2WaveFormatStrc;
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

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
    virtual long __stdcall Unlock(void* pv1, unsigned long dw1, void* pv2, unsigned long dw2) = 0;
    virtual long __stdcall Restore() = 0;
};

struct D2SoundStrc
{
    D2DSoundBufferStrc* pBuffer;
    unsigned long nBufferSize;
    unsigned long nHalfSize;
    int unk0x0C[3];
    unsigned long nEndPosition;
    int bPlaying;
    unsigned long nPosition;
    unsigned long nFillPosition;
    int bSecondHalf;
    int bStreamed;
    int nFillState;
    unsigned int dwFlags;
    int nVolume;
    int unk0x3C;
    int bNoClear;
    int unk0x44;
    void* hStream;
    int bFading;
    int nFadeFrom;
    int nFadeTo;
    int nFadeStart;
    int nFadeEnd;
};

struct D2SoundNodeStrc
{
    D2SoundStrc* pSound;
    D2SoundNodeStrc* pNext;
};

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern "C" __declspec(dllimport) int __stdcall IsIconic(void* hWnd); // 0x006CC50C
extern D2CriticalSectionStrc gSoundLock_0088174C; // 0x0088174C
extern D2SoundNodeStrc* gpSoundList_00881808; // 0x00881808
extern void* ghSoundEvent_0088180C; // 0x0088180C
extern int gbIconic_00881814; // 0x00881814
extern "C" void* __cdecl sub_004F59A0_GetHwnd(); // 0x004F59A0
int __cdecl sub_00514920(); // 0x00514920
int __cdecl sub_00514840(); // 0x00514840
void __cdecl sub_00514990_PickRandomChannel(); // 0x00514990
void __fastcall sub_00515180_FillBuffer(D2SoundStrc* pSound, int nArg2, int nArg3, unsigned int nSize); // 0x00515180
int __fastcall sub_00515300_ClearSoundBuffer(D2DSoundBufferStrc* pBuffer, unsigned long nOffset, unsigned long nBytes); // 0x00515300
void __fastcall sub_005157B0_SetSoundVolume(D2SoundStrc* pSound, int nVolume); // 0x005157B0
void __fastcall sub_00515E40_CloseSoundStream(D2SoundStrc* pSound); // 0x00515E40
int __fastcall sub_00515FD0_RestoreLostBuffer(D2SoundStrc* pSound); // 0x00515FD0

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

extern "C" double __cdecl sqrt(double x); // 0x006879C0
extern const float gfMaxSoundDistance_006DEB10; // 0x006DEB10

static __forceinline void sub_00515EE0_StopSoundInline(D2SoundStrc* pSound)
{
    D2_ASSERT(pSound->pBuffer, 658);
    EnterCriticalSection(&gSoundLock_0088174C);
    if (pSound->hStream)
    {
        sub_00515E40_CloseSoundStream(pSound);
    }
    pSound->pBuffer->Stop();
    pSound->bPlaying = 0;
    LeaveCriticalSection(&gSoundLock_0088174C);
}

static __forceinline void sub_AdvancePlayPositionInline(D2SoundStrc* pSound, unsigned long dwPlay, unsigned long nMask)
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

        if (sub_00514920() && !sub_00514840())
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
            else if (pSound->bPlaying)
            {
                unsigned long dwWrite;
                if (pSound->pBuffer->GetCurrentPosition(&dwPlay, &dwWrite) >= 0)
                {
                    const unsigned long nMask = pSound->nBufferSize - 1;
                    sub_AdvancePlayPositionInline(pSound, dwPlay, nMask);

                    if (!pSound->bStreamed)
                    {
                        const unsigned long* const pnPos = &pSound->nPosition;
                        if (pSound->nFillPosition - *pnPos < pSound->nHalfSize || *pnPos > pSound->nFillPosition)
                        {
                            const unsigned long nFillOffset = pSound->nFillPosition & nMask;
                            sub_00515180_FillBuffer(pSound, pSound->nFillPosition, nFillOffset, pSound->nHalfSize);
                            pSound->nFillState = -1;
                            pSound->bSecondHalf = nFillOffset != 0;
                        }
                    }
                    else if (!pSound->bNoClear)
                    {
                        if (dwPlay < pSound->nHalfSize && !pSound->bSecondHalf)
                        {
                            sub_00515300_ClearSoundBuffer(pSound->pBuffer, pSound->nHalfSize, pSound->nHalfSize);
                            pSound->bSecondHalf = 1;
                        }

                        if (dwPlay >= pSound->nHalfSize && pSound->bSecondHalf == 1)
                        {
                            sub_00515300_ClearSoundBuffer(pSound->pBuffer, 0, pSound->nHalfSize);
                            pSound->bSecondHalf = 0;
                        }

                        if (pSound->nPosition > pSound->nEndPosition)
                        {
                            pSound->pBuffer->Stop();
                            pSound->bPlaying = 0;
                        }
                    }
                }
            }
        }

        LeaveCriticalSection(&gSoundLock_0088174C);
    }

    return 0;
}

// 0x005166D0
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
