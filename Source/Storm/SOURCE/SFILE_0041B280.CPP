#include "D2SysTypes.h"
struct D2StormArchiveRecStrc { char pad[0x110]; int nKind; };
struct D2StormFileRecStrc { char pad[0x110]; int nKind; D2StormArchiveRecStrc* pArchive; char pad118[0x1c]; int ddaActive; char pad138[0xc]; int refs; };
#pragma pack(push, 1)
struct D2WaveFormatStrc { unsigned short format, channels; unsigned int samplesPerSec, avgBytesPerSec; unsigned short blockAlign, bitsPerSample, extraSize; };
struct D2WaveHeaderStrc { unsigned int tag, size, type, dataOffset, flags; };
struct D2WaveBaseFormatStrc { unsigned short format, channels; unsigned int samplesPerSec, avgBytesPerSec; unsigned short blockAlign, bitsPerSample; };
#pragma pack(pop)
struct D2SoundBufferDescStrc;
struct D2StormSoundBuffer {
    virtual long __stdcall QueryInterface() = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall GetCaps() = 0;
    virtual long __stdcall GetCurrentPosition() = 0;
    virtual long __stdcall GetFormat() = 0;
    virtual long __stdcall GetVolume(int*) = 0;
    virtual long __stdcall GetPan(int*) = 0;
    virtual long __stdcall GetFrequency() = 0;
    virtual long __stdcall GetStatus() = 0;
    virtual long __stdcall Initialize() = 0;
    virtual long __stdcall Lock() = 0;
    virtual long __stdcall Play() = 0;
    virtual long __stdcall SetCurrentPosition(unsigned int) = 0;
    virtual long __stdcall SetFormat() = 0;
    virtual long __stdcall SetVolume(int) = 0;
    virtual long __stdcall SetPan(int) = 0;
};
struct D2DirectSoundStrc {
    virtual long __stdcall QueryInterface() = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall CreateSoundBuffer(D2SoundBufferDescStrc*, D2StormSoundBuffer**, void*) = 0;
};
struct D2SoundBufferDescStrc { unsigned int size, flags, bufferBytes, reserved; D2WaveFormatStrc* pFormat; };
struct D2StormDdaNodeStrc {
    void* prev; void* next; D2StormFileRecStrc* pFile; int unk0C; unsigned int avgBytes;
    int looping, unk18, unk1C; unsigned int dataPosition, dataSize, offset, offset2, offset3;
    int volume, pan; D2StormSoundBuffer* pBuffer; unsigned int bufferSize; int ownsBuffer;
    unsigned char silence; char pad49[3]; int active;
};
struct D2StormDdaListStrc { int linkoffset; void* prev; void* next;
    D2StormDdaNodeStrc* sub_00419700_NewNode(unsigned int, unsigned int, unsigned int); // 0x00419700
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc*); // 0x006CC214
extern "C" __declspec(dllimport) int __stdcall SetEvent(void*); // 0x006CC130
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode); // 0x0041C340
void* __stdcall sub_00413020_Allocate(unsigned int, const char*, int, int); // 0x00413020
int __stdcall sub_0041A990_DdaClose(void*); // 0x0041A990
unsigned long __stdcall SFileSetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod); // 0x004165A0
int __stdcall sub_0041AAD0(void*, void*, int, int*, void*, int, int); // 0x0041AAD0
int __stdcall SFileReadFile(void*, void*, int, int*, void*); // 0x0041B050
void __stdcall SMemZero(void*, unsigned int); // 0x0041D300
void __cdecl sub_0041A880_StartThread(); // 0x0041A880
extern D2DirectSoundStrc* gpSound_00778F20; // 0x00778F20
extern D2CriticalSectionStrc gLock_00779068; // 0x00779068
extern unsigned int gnFlags_00779058; // 0x00779058
extern unsigned int gnBlock_007790A0; // 0x007790A0
extern unsigned int gnChunk_00779038; // 0x00779038
extern void* gpBuffer_00779050; // 0x00779050
extern void* ghEvent_00779054; // 0x00779054
extern D2StormDdaListStrc gDdaList_00708384; // 0x00708384
extern const char gszSource_006CF084[]; // 0x006CF084
__declspec(noinline) static int sub_00415950_GetFileRec(void*, D2StormFileRecStrc**);
static int sub_00415950_GetFileRec(void*, D2StormFileRecStrc**); // 0x00415950
// 0x00415950
static int sub_00415950_GetFileRec(void* hFile, D2StormFileRecStrc** ppRec)
{
    *ppRec = (D2StormFileRecStrc*)hFile;
    return 1;
}
struct D2WaveChunkHeaderStrc { unsigned int dwTag, dwSize; };
static int sub_0041B210_FindWaveChunk(void*, unsigned int, unsigned int*); // 0x0041B210
// 0x0041B210
static int sub_0041B210_FindWaveChunk(void* hFile, unsigned int dwTag, unsigned int* pChunk)
{
    D2WaveChunkHeaderStrc tHeader;
    while (SFileReadFile(hFile, &tHeader, sizeof(tHeader), 0, 0)) {
        if (tHeader.dwTag == dwTag) {
            pChunk[0] = tHeader.dwSize;
            const int nPosition = SFileSetFilePointer(hFile, 0, 0, 1);
            pChunk[1] = nPosition;
            return nPosition != -1;
        }
        if (SFileSetFilePointer(hFile, tHeader.dwSize, 0, 1) == -1) break;
    }
    return 0;
}
// 0x0041B280
int __stdcall SFileDdaBeginEx(void* hFile, unsigned int nBufferSize, unsigned int nFlags, unsigned int nOffset, int nVolume, int nPan, D2StormSoundBuffer* pBuffer)
{
    int nValid = -1;
    nValid &= nBufferSize ? -1 : 0;
    if (!nValid) { sub_0041C340_SetLastError(0x57); return nValid; }
    if (!gpSound_00778F20) { sub_0041C340_SetLastError(0x85100071); return 0; }
    D2StormFileRecStrc* pFile;
    EnterCriticalSection(&gLock_00779068);
    if (!sub_00415950_GetFileRec(hFile, &pFile)) { LeaveCriticalSection(&gLock_00779068); return 0; }
    if (pFile->ddaActive) sub_0041A990_DdaClose(hFile);
    if (!((gnFlags_00779058 | nFlags) & 1) && (pFile->nKind != -1 || !pFile->pArchive)) {
        sub_0041C340_SetLastError(0x8510006f);
        LeaveCriticalSection(&gLock_00779068);
        return 0;
    }
    if (!gnBlock_007790A0) gnBlock_007790A0 = 0x4000;
    gnChunk_00779038 = gnBlock_007790A0;
    if (!gpBuffer_00779050) gpBuffer_00779050 = sub_00413020_Allocate(gnChunk_00779038, gszSource_006CF084, 0xc5d, 0);
    if (pFile->pArchive) {
        if (pFile->pArchive->nKind == 0 || pFile->pArchive->nKind == 1) pFile->pArchive->nKind = 2;
    }
    LeaveCriticalSection(&gLock_00779068);
    unsigned int remainder = (gnChunk_00779038 - 1) & nBufferSize;
    if (remainder) nBufferSize += gnChunk_00779038 - remainder;
    if (nBufferSize < 2 * gnChunk_00779038) nBufferSize = 2 * gnChunk_00779038;
    SFileSetFilePointer(hFile, 0, 0, 0);
    D2WaveHeaderStrc riff;
    if (!sub_0041AAD0(hFile, &riff, 12, 0, 0, 0, 0) || riff.tag != 0x46464952 || riff.type != 0x45564157) goto invalid;
    {
        unsigned int chunk[2] = {0, 0};
        if (!sub_0041B210_FindWaveChunk(hFile, 0x20746d66, chunk) || chunk[0] < 16) goto invalid;
        D2WaveFormatStrc format;
        {
            D2WaveBaseFormatStrc rawFormat;
            unsigned int formatSize = chunk[0];
            if (!sub_0041AAD0(hFile, &rawFormat, 16, 0, 0, 0, 0) || SFileSetFilePointer(hFile, formatSize - 16, 0, 1) == -1) goto invalid;
            format.format = rawFormat.format;
            format.channels = rawFormat.channels;
            format.samplesPerSec = rawFormat.samplesPerSec;
            format.avgBytesPerSec = rawFormat.avgBytesPerSec;
            format.blockAlign = rawFormat.blockAlign;
            format.bitsPerSample = rawFormat.bitsPerSample;
            format.extraSize = 0;
            if (!sub_0041B210_FindWaveChunk(hFile, 0x61746164, chunk)) goto invalid;
        }
        if (nOffset) nOffset %= chunk[0];
        unsigned int offset = nOffset;
        int ownsBuffer = pBuffer == 0;
        if (ownsBuffer) {
            D2SoundBufferDescStrc desc;
            SMemZero(&desc, sizeof(desc));
            desc.size = 20;
            desc.flags = 0x80;
            if (nFlags & 0x20) desc.flags = 0xa0;
            if (nFlags & 0x40) desc.flags |= 0x40;
            desc.bufferBytes = nBufferSize;
            desc.pFormat = &format;
            gpSound_00778F20->CreateSoundBuffer(&desc, &pBuffer, 0);
            if (!pBuffer) return 0;
        }
        if (nVolume && nVolume != 0x7fffffff) pBuffer->SetVolume(nVolume);
        if (nPan && nPan != 0x7fffffff) pBuffer->SetPan(nPan);
        EnterCriticalSection(&gLock_00779068);
        D2StormDdaNodeStrc* node = gDdaList_00708384.sub_00419700_NewNode(2, 0, 0);
        node->pFile = pFile;
        node->bufferSize = nBufferSize;
        node->avgBytes = format.avgBytesPerSec;
        node->looping = (nFlags >> 18) & 1;
        node->dataPosition = chunk[1];
        node->dataSize = chunk[0];
        node->volume = nVolume;
        node->pan = nPan;
        node->unk18 = 0;
        node->offset = offset;
        node->offset2 = offset;
        node->offset3 = offset;
        node->pBuffer = pBuffer;
        node->ownsBuffer = ownsBuffer;
        node->silence = format.bitsPerSample == 8 ? 0x80 : 0;
        node->active = 1;
        ++pFile->refs;
        pBuffer->SetCurrentPosition(0);
        pFile->ddaActive = 1;
        LeaveCriticalSection(&gLock_00779068);
        sub_0041A880_StartThread();
        SetEvent(ghEvent_00779054);
        return 1;
    }
invalid:
    sub_0041C340_SetLastError(0xd);
    return 0;
}
