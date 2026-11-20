#include "D2Client.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2BinFileStrc;
struct D2ClientCacheEntryStrc;
struct D2BinFieldStrc;
struct D2SoundsTxtStrc;
struct D2SoundEnvironTxtStrc;

#pragma pack(push, 2)
struct D2ClientCacheEntryStrc
{
    char unk0x00[0x4C];
    char bLocked;
    char unk0x4D[0x1F];
    void* pData;
    unsigned int nSize;
    char f_74[0x0D];
    char f_81;
    T00481720* pAsync;
    int nState;
    int nRefCount;
};

#pragma pack(pop)

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
int __fastcall sub_004DF630_QueryAddress(D2ClientCacheEntryStrc* pEntry); // 0x004DF630
void __fastcall sub_00482860_TouchCacheEntry(int nIndex); // 0x00482860
int __stdcall sub_004824A0_FreeCacheEntries(unsigned int nFree, int bTwoPasses, int bCheckAge); // 0x004824A0
void* __stdcall sub_004FAC80(); // 0x004FAC80
void* __fastcall ARCHIVE_AllocateBufferAndReadFile(void* hArchive, const char* szFileName, unsigned int* pnSize, const char* szFile, int nLine); // 0x00517079
void __cdecl sub_004DF800(); // 0x004DF800
void __cdecl sub_004B9D20_FreeAllSounds(); // 0x004B9D20
void __cdecl sub_004E00C0_CloseSoundChannels(); // 0x004E00C0
void __cdecl sub_004828B0_ReleaseSoundTables(); // 0x004828B0
extern D2ClientCacheEntryStrc* gpCacheEntries_007BC9A0; // 0x007BC9A0
extern int gdwGlobal_007BC9BC; // 0x007BC9BC
extern unsigned int gnCacheMax_007BC9CC; // 0x007BC9CC
extern unsigned int gdwCacheUsed_007BC9D0; // 0x007BC9D0

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    int (__fastcall* pfnLink)(const char* szKey);
};

#pragma pack(push, 1)
struct D2SoundsTxtStrc
{
    char szFilename[60];
    unsigned char f_4E;
    unsigned char f_3D;
    unsigned char f_3E;
    unsigned char nFadeIn;
    unsigned char nFadeOut;
    unsigned char bDeferInst;
    unsigned char bStopInst;
    unsigned short nDuration;
    unsigned short nCompound;
    int f_47;
    unsigned char bReverb;
    unsigned char unk0x4C[8];
    int nBlock[3];
    int f_60;
    unsigned char unk0x64[0x1C];
    unsigned char f_80;
    unsigned char unk0x81[0x0D];
};

#pragma pack(pop)
struct D2SoundEnvironTxtStrc
{
    int f_0;
    char unk0x04[0x54];
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szDest, const char* szFormat, ...);
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
void* __fastcall sub_00517079(void* hArchive, const char* szPath, int* pSize, const char* szFile, int nLine); // 0x00517079
void __stdcall FOG_FreeBinFile(D2BinFileStrc* pBinFile); // 0x006BCDA0
int __stdcall FOG_GetRecordCountFromBinFile(D2BinFileStrc* pBinFile); // 0x006BCDE0
D2BinFileStrc* __stdcall FOG_CreateBinFile(void* pDataBuffer, int nBufferSize); // 0x006BD640
void __stdcall FOG_10207(D2BinFileStrc* pBinFile, D2BinFieldStrc* pBinField, void* pTxt, int nRecordCount, int nRecordSize); // 0x006BD780
extern int gnSoundsTxtRecordCount_007BC9A4; // 0x007BC9A4
extern unsigned int gnCacheLastTick_007BC9C0; // 0x007BC9C0
extern unsigned int gnCacheLastLoadTick_007BC9C4; // 0x007BC9C4
extern unsigned int gnCacheLoading_007BC9C8; // 0x007BC9C8

void __fastcall sub_00482970_LoadCacheEntry(int nIndex, int bDirect, int nArg);

unsigned int gnCacheLastTick_007BC9C0; // 0x007BC9C0

unsigned int gnCacheLastLoadTick_007BC9C4; // 0x007BC9C4

unsigned int gnCacheLoading_007BC9C8; // 0x007BC9C8

// 0x00481720
static void sub_00481720_FinishCacheLoad(D2ClientCacheEntryStrc* pEntry)
{
    D2_ASSERT(pEntry->nState == 1, 0x40);
    pEntry->pData = sub_0040A9E0(pEntry->pAsync);
    pEntry->nSize = sub_0040AA40(pEntry->pAsync);
    pEntry->nState = 2;
    sub_004DF630_QueryAddress(pEntry);
    gnCacheLoading_007BC9C8 -= 1;
}

int* gpSongTable_007BC99C; // 0x007BC99C

static D2SoundsTxtStrc* sgptSoundHeaderTable; // 0x007BC9A0

D2SoundEnvironTxtStrc* sgptSoundEnvironTable; // 0x007BC9A8

int gnSoundEnvironTxtRecordCount_007BC9AC; // 0x007BC9AC

static int gnSongMax_007BC9B4; // 0x007BC9B4

static int gnSongMin_007BC9B0; // 0x007BC9B0

// 0x00481950
void __cdecl sub_00481950_LoadSoundTables()
{
    D2BinFieldStrc pTbl2[] =
    {
        { "Filename", 1, 59, 0, 0 },
        { "Volume", 4, 0, 60, 0 },
        { "Group Size", 4, 0, 61, 0 },
        { "Loop", 4, 0, 62, 0 },
        { "Fade In", 4, 0, 63, 0 },
        { "Fade Out", 4, 0, 64, 0 },
        { "Defer Inst", 4, 0, 65, 0 },
        { "Stop Inst", 4, 0, 66, 0 },
        { "Duration", 3, 0, 67, 0 },
        { "Compound", 3, 0, 69, 0 },
        { "Falloff", 2, 0, 71, 0 },
        { "Reverb", 4, 0, 75, 0 },
        { "Cache", 4, 0, 76, 0 },
        { "Async Only", 4, 0, 77, 0 },
        { "Priority", 4, 0, 78, 0 },
        { "Stream", 4, 0, 79, 0 },
        { "Stereo", 4, 0, 80, 0 },
        { "Tracking", 4, 0, 81, 0 },
        { "Solo", 4, 0, 82, 0 },
        { "Music Vol", 4, 0, 83, 0 },
        { "Block 1", 2, 0, 84, 0 },
        { "Block 2", 2, 0, 88, 0 },
        { "Block 3", 2, 0, 92, 0 },
        { "end", 0, 0, 0, 0 },
    };

    D2BinFieldStrc pTbl[] =
    {
        { "Song", 2, 0, 0, 0 },
        { "Day Ambience", 2, 0, 4, 0 },
        { "Night Ambience", 2, 0, 8, 0 },
        { "Day Event", 2, 0, 12, 0 },
        { "Night Event", 2, 0, 16, 0 },
        { "Event Delay", 2, 0, 20, 0 },
        { "Indoors", 4, 0, 24, 0 },
        { "Material 1", 2, 0, 28, 0 },
        { "Material 2", 2, 0, 32, 0 },
        { "EAX Environ", 2, 0, 36, 0 },
        { "EAX Env Size", 2, 0, 40, 0 },
        { "EAX Env Diff", 2, 0, 44, 0 },
        { "EAX Room Vol", 2, 0, 48, 0 },
        { "EAX Room HF", 2, 0, 52, 0 },
        { "EAX Decay Time", 2, 0, 56, 0 },
        { "EAX Decay HF", 2, 0, 60, 0 },
        { "EAX Reflect", 2, 0, 64, 0 },
        { "EAX Reflect Delay", 2, 0, 68, 0 },
        { "EAX Reverb", 2, 0, 72, 0 },
        { "EAX Rev Delay", 2, 0, 76, 0 },
        { "EAX Room Roll", 2, 0, 80, 0 },
        { "EAX Air Absorb", 2, 0, 84, 0 },
        { "end", 0, 0, 0, 0 },
    };

    D2_ASSERT(!sgptSoundHeaderTable, 0xFC);
    D2_ASSERT(!sgptSoundEnvironTable, 0xFD);

    char szPath[260];
    int nSize;
    wsprintfA(szPath, "%s\\sounds.txt", "DATA\\GLOBAL\\EXCEL");
    void* pData = sub_00517079(D2Win_GetArchive(), szPath, &nSize, ".\\Sound\\SoundHdr.cpp", 0x101);
    D2BinFileStrc* pBinFile = FOG_CreateBinFile(pData, nSize);
    gnSoundsTxtRecordCount_007BC9A4 = FOG_GetRecordCountFromBinFile(pBinFile);
    D2SoundsTxtStrc* pSounds = (D2SoundsTxtStrc*)FOG_Alloc(gnSoundsTxtRecordCount_007BC9A4 * sizeof(D2SoundsTxtStrc), ".\\Sound\\SoundHdr.cpp", 0x106, 0);
    sgptSoundHeaderTable = pSounds;
    memset(pSounds, 0, gnSoundsTxtRecordCount_007BC9A4 * sizeof(D2SoundsTxtStrc));
    FOG_10207(pBinFile, pTbl2, pSounds, gnSoundsTxtRecordCount_007BC9A4, sizeof(D2SoundsTxtStrc));
    FOG_FreeBinFile(pBinFile);

    wsprintfA(szPath, "%s\\soundenviron.txt", "DATA\\GLOBAL\\EXCEL");
    pData = sub_00517079(D2Win_GetArchive(), szPath, &nSize, ".\\Sound\\SoundHdr.cpp", 0x10D);
    pBinFile = FOG_CreateBinFile(pData, nSize);
    gnSoundEnvironTxtRecordCount_007BC9AC = FOG_GetRecordCountFromBinFile(pBinFile);
    D2SoundEnvironTxtStrc* pSoundEnviron = (D2SoundEnvironTxtStrc*)FOG_Alloc(gnSoundEnvironTxtRecordCount_007BC9AC * sizeof(D2SoundEnvironTxtStrc), ".\\Sound\\SoundHdr.cpp", 0x112, 0);
    sgptSoundEnvironTable = pSoundEnviron;
    memset(pSoundEnviron, 0, gnSoundEnvironTxtRecordCount_007BC9AC * sizeof(D2SoundEnvironTxtStrc));
    FOG_10207(pBinFile, pTbl, pSoundEnviron, gnSoundEnvironTxtRecordCount_007BC9AC, sizeof(D2SoundEnvironTxtStrc));
    FOG_FreeBinFile(pBinFile);

    int nGroupStart = 0;
    int nGroupSize = 1;
    for (int i = 1; i < gnSoundsTxtRecordCount_007BC9A4; ++i)
    {
        D2SoundsTxtStrc* pSound = &sgptSoundHeaderTable[i];
        if (nGroupStart && i >= nGroupStart && i < nGroupSize + nGroupStart)
            pSound->f_60 = nGroupStart;
        else
            pSound->f_60 = i;

        if (pSound->f_3D)
        {
            nGroupStart = i;
            nGroupSize = pSound->f_3D;
        }
        else
        {
            pSound->f_3D = 1;
        }

        unsigned char nBlocks;
        for (nBlocks = 0; nBlocks < 3; ++nBlocks)
        {
            if (pSound->nBlock[nBlocks] == -1)
                break;
        }
        pSound->f_80 = nBlocks;
    }

    D2SoundEnvironTxtStrc* pEnv = sgptSoundEnvironTable;
    gnSongMin_007BC9B0 = gnSoundsTxtRecordCount_007BC9A4;
    gnSongMax_007BC9B4 = 0;
    for (int j = 0; j < gnSoundEnvironTxtRecordCount_007BC9AC; ++j, ++pEnv)
    {
        const int nSong = pEnv->f_0;
        if (nSong > 0)
        {
            if (nSong < gnSongMin_007BC9B0)
                gnSongMin_007BC9B0 = nSong;
            int nNewMax = gnSongMax_007BC9B4;
            if (nSong > nNewMax)
                nNewMax = nSong;
            gnSongMax_007BC9B4 = nNewMax;
        }
    }

    const int nSongCount = gnSongMax_007BC9B4 - gnSongMin_007BC9B0 + 1;
    gpSongTable_007BC99C = (int*)FOG_Alloc(nSongCount * sizeof(int), ".\\Sound\\SoundHdr.cpp", 0x147, 0);
    memset(gpSongTable_007BC99C, 0, nSongCount * sizeof(int));
}

// 0x00482940
void __cdecl sub_00482940_UpdateSound()
{
    if (!sub_00513B50())
        return;
    sub_004DF800();
    sub_004BAAB0();
    sub_004B9D20_FreeAllSounds();
    sub_004E00C0_CloseSoundChannels();
    sub_004828B0_ReleaseSoundTables();
}

unsigned int gdwCacheUsed_007BC9D0; // 0x007BC9D0

// 0x00482970
void __fastcall sub_00482970_LoadCacheEntry(int nIndex, int bDirect, int nArg)
{
    D2ClientCacheEntryStrc* pEntry;
    if (gpCacheEntries_007BC9A0 && nIndex >= 0 && nIndex < gdwGlobal_007BC9A4)
        pEntry = &gpCacheEntries_007BC9A0[nIndex];
    else
        pEntry = 0;

    const int nSaved = gdwGlobal_007BC9BC;
    if (pEntry->f_81)
        return;

    if (pEntry->nState == 2)
        return;
    if (pEntry->nState == 1 && !bDirect)
        return;
    if (pEntry->nState == 1 && bDirect)
    {
        sub_00481720_FinishCacheLoad(pEntry);
        return;
    }
    if (pEntry->nState)
        return;

    char szPath[0x50];
    void* hFile;
    sub_00482710(nIndex, szPath);
    if (!sub_004068E0(szPath, &hFile))
    {
        pEntry->f_81 = 1;
        return;
    }

    const unsigned int nSize = sub_00406930(hFile, 0);
    sub_004068F0(hFile);
    if (gdwCacheUsed_007BC9D0 + nSize > gnCacheMax_007BC9CC)
    {
        const unsigned int nFree = gdwCacheUsed_007BC9D0 - gnCacheMax_007BC9CC + nSize;
        if (!sub_004824A0_FreeCacheEntries(nFree, bDirect, nArg))
        {
            gnCacheLastLoadTick_007BC9C4 = nSaved;
            return;
        }
    }

    if (bDirect)
    {
        pEntry->pData = ARCHIVE_AllocateBufferAndReadFile(sub_004FAC80(), szPath, &pEntry->nSize, ".\\Sound\\SoundHdr.cpp", 0x301);
        D2_ASSERT(pEntry->pData && pEntry->nSize, 0x302);
        gdwCacheUsed_007BC9D0 += pEntry->nSize;
        sub_00482860_TouchCacheEntry(nIndex);
        pEntry->nState = 2;
        sub_004DF630_QueryAddress(pEntry);
        return;
    }

    pEntry->pAsync = sub_0040A620(0, szPath, 1, 0, -1, 0, 0, -2, ".\\Sound\\SoundHdr.cpp", 0x31B);
    if (pEntry->pAsync)
    {
        const unsigned int nAsyncSize = sub_0040AA40(pEntry->pAsync);
        gdwCacheUsed_007BC9D0 += nAsyncSize;
        pEntry->nSize = nAsyncSize;
        sub_00482860_TouchCacheEntry(nIndex);
        gnCacheLoading_007BC9C8 += 1;
        pEntry->nState = 1;
    }
}

// 0x00482B40
void __fastcall sub_00482B40_UpdateCache(unsigned int nTick)
{
    if (!gpCacheEntries_007BC9A0)
        return;

    const int bForce = nTick == 0;
    if (nTick && nTick - gnCacheLastTick_007BC9C0 < 0x19)
        return;

    for (int i = 1; i <= 0xB75; i++)
    {
        D2ClientCacheEntryStrc* pEntry = &gpCacheEntries_007BC9A0[i];
        if (!pEntry->nState && (pEntry->nRefCount || pEntry->bLocked))
        {
            if (!bForce)
            {
                if (gnCacheLoading_007BC9C8 >= 0xF)
                    continue;
                if (nTick - gnCacheLastLoadTick_007BC9C4 < 0xFA)
                    continue;
            }
            sub_00482970_LoadCacheEntry(i, bForce, 1);
        }
        if (pEntry->nState == 1 && sub_0040A7F0_AsyncDataCheck(pEntry->pAsync))
            sub_00481720_FinishCacheLoad(pEntry);
    }
    gnCacheLastTick_007BC9C0 = nTick;
}
