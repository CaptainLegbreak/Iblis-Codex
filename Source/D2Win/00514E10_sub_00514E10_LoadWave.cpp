extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2DSoundBufferStrc;
struct D2DSound3DBufferStrc;
struct D2KsPropertySetStrc;

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
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall sub_004068E0(const char* szFileName, void** phFile);                                          // 0x004068E0
void __fastcall sub_004068F0(void* hFile);                                                                // 0x004068F0
int __stdcall SFileDdaBeginEx(void* hFile, int nBufferSize, unsigned int nFlags, unsigned int nOffset, int nVolume, int nPan, D2DSoundBufferStrc* pBuffer); // 0x0041B280
void __fastcall sub_00515180_FillBuffer(D2SoundStrc* pSound, int nArg2, int nArg3, unsigned int nSize);     // 0x00515180
void* __fastcall sub_00516760_ParseWave(const void* pFile, unsigned int* pnSize, D2WaveFormatStrc* pFormat); // 0x00516760
void* __fastcall sub_00517079_LoadFile(void* hArchive, const char* szFileName, unsigned int* pnSize, const char* szFile, int nLine); // 0x00517079

extern D2CriticalSectionStrc gSoundCriticalSection_0088174C;                                                // 0x0088174C
extern int gbSoundEnabled_008817FC;                                                                         // 0x008817FC
extern D2SoundWaveStrc* gpSoundWaveList_00881800;                                                           // 0x00881800

// 0x00514E10
void __fastcall sub_00514E10_LoadWave(const char* szName)
{
    if (!gbSoundEnabled_008817FC)
        return;
    unsigned int nFileSize;
    void* pFile = sub_00517079_LoadFile(0, szName, &nFileSize, ".\\Src\\D2SoundFast.cpp", 0x77);
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
    EnterCriticalSection(&gSoundCriticalSection_0088174C);
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
    LeaveCriticalSection(&gSoundCriticalSection_0088174C);
    return 1;
}

// 0x00515D70
int __fastcall sub_00515D70_StartStream(D2SoundStrc* pSound, const char* szFileName, int nPosition, int bLoop)
{
    D2_ASSERT(pSound, 0x3DB);
    void* hFile;
    if (!sub_004068E0(szFileName, &hFile))
        return 0;
    EnterCriticalSection(&gSoundCriticalSection_0088174C);
    if (!SFileDdaBeginEx(hFile, pSound->nBufferSize, bLoop ? 0x40000 : 0, nPosition * 4, 0x7FFFFFFF, 0x7FFFFFFF, pSound->pBuffer))
    {
        sub_004068F0(hFile);
        LeaveCriticalSection(&gSoundCriticalSection_0088174C);
        return 0;
    }
    pSound->hStreamFile = hFile;
    pSound->bStreaming = 1;
    pSound->nLoopStart = -1;
    LeaveCriticalSection(&gSoundCriticalSection_0088174C);
    return 1;
}
