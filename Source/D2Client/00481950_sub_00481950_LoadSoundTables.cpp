struct D2BinFileStrc;

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

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szDest, const char* szFormat, ...);
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
void* __stdcall D2Win_GetArchive();                                                                         // 0x004FAC80
void* __fastcall sub_00517079(void* hArchive, const char* szPath, int* pSize, const char* szFile, int nLine); // 0x00517079
void __stdcall FOG_FreeBinFile(D2BinFileStrc* pBinFile);                                                    // 0x006BCDA0
int __stdcall FOG_GetRecordCountFromBinFile(D2BinFileStrc* pBinFile);                                       // 0x006BCDE0
D2BinFileStrc* __stdcall FOG_CreateBinFile(void* pDataBuffer, int nBufferSize);                             // 0x006BD640
void __stdcall FOG_10207(D2BinFileStrc* pBinFile, D2BinFieldStrc* pBinField, void* pTxt, int nRecordCount, int nRecordSize); // 0x006BD780
int* gpSongTable_007BC99C;                                                                                  // 0x007BC99C
static D2SoundsTxtStrc* gpSoundsTxt_007BC9A0;                                                               // 0x007BC9A0
extern int gnSoundsTxtRecordCount_007BC9A4;                                                                 // 0x007BC9A4
D2SoundEnvironTxtStrc* gpSoundEnvironTxt_007BC9A8;                                                          // 0x007BC9A8
int gnSoundEnvironTxtRecordCount_007BC9AC;                                                                  // 0x007BC9AC
static int gnSongMax_007BC9B4;                                                                               // 0x007BC9B4
static int gnSongMin_007BC9B0;                                                                               // 0x007BC9B0

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

    D2_ASSERT(!gpSoundsTxt_007BC9A0, 0xFC);
    D2_ASSERT(!gpSoundEnvironTxt_007BC9A8, 0xFD);

    char szPath[260];
    int nSize;
    wsprintfA(szPath, "%s\\sounds.txt", "DATA\\GLOBAL\\EXCEL");
    void* pData = sub_00517079(D2Win_GetArchive(), szPath, &nSize, ".\\Sound\\SoundHdr.cpp", 0x101);
    D2BinFileStrc* pBinFile = FOG_CreateBinFile(pData, nSize);
    gnSoundsTxtRecordCount_007BC9A4 = FOG_GetRecordCountFromBinFile(pBinFile);
    D2SoundsTxtStrc* pSounds = (D2SoundsTxtStrc*)FOG_Alloc(gnSoundsTxtRecordCount_007BC9A4 * sizeof(D2SoundsTxtStrc), ".\\Sound\\SoundHdr.cpp", 0x106, 0);
    gpSoundsTxt_007BC9A0 = pSounds;
    memset(pSounds, 0, gnSoundsTxtRecordCount_007BC9A4 * sizeof(D2SoundsTxtStrc));
    FOG_10207(pBinFile, pTbl2, pSounds, gnSoundsTxtRecordCount_007BC9A4, sizeof(D2SoundsTxtStrc));
    FOG_FreeBinFile(pBinFile);

    wsprintfA(szPath, "%s\\soundenviron.txt", "DATA\\GLOBAL\\EXCEL");
    pData = sub_00517079(D2Win_GetArchive(), szPath, &nSize, ".\\Sound\\SoundHdr.cpp", 0x10D);
    pBinFile = FOG_CreateBinFile(pData, nSize);
    gnSoundEnvironTxtRecordCount_007BC9AC = FOG_GetRecordCountFromBinFile(pBinFile);
    D2SoundEnvironTxtStrc* pSoundEnviron = (D2SoundEnvironTxtStrc*)FOG_Alloc(gnSoundEnvironTxtRecordCount_007BC9AC * sizeof(D2SoundEnvironTxtStrc), ".\\Sound\\SoundHdr.cpp", 0x112, 0);
    gpSoundEnvironTxt_007BC9A8 = pSoundEnviron;
    memset(pSoundEnviron, 0, gnSoundEnvironTxtRecordCount_007BC9AC * sizeof(D2SoundEnvironTxtStrc));
    FOG_10207(pBinFile, pTbl, pSoundEnviron, gnSoundEnvironTxtRecordCount_007BC9AC, sizeof(D2SoundEnvironTxtStrc));
    FOG_FreeBinFile(pBinFile);

    int nGroupStart = 0;
    int nGroupSize = 1;
    for (int i = 1; i < gnSoundsTxtRecordCount_007BC9A4; ++i)
    {
        D2SoundsTxtStrc* pSound = &gpSoundsTxt_007BC9A0[i];
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

    D2SoundEnvironTxtStrc* pEnv = gpSoundEnvironTxt_007BC9A8;
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
