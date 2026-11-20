#include "D2Client.h"

#define gpMsgRecordChunkHead_007A2760 (gtMsgRecordChunkFirst_007A0818.pNext)
#define FILE_ATTRIBUTE_NORMAL 0x00000080
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define gnRecordCount_007A2758 (gFirstRecordBlock_007A0818.nCount)

struct D2WinMsgStrc;
struct D2RecordFileHeaderStrc;
struct D2MsgRecordChunkStrc;
struct D2RecordBlockStrc;
struct D2RecordHeaderStrc;

struct D2MsgRecordChunkStrc
{
    char tRecords[500 * 0x10];
    int nCount;
    int nUnk0x1F44;
    D2MsgRecordChunkStrc* pNext;
};

int __stdcall SCmdRegisterArgument(unsigned int dwFlags, unsigned int dwId, const char* szName, void* pVariable, unsigned int nBytes, int bSet, void* pfnCallback, void* pParam); // 0x006C4580
int __fastcall sub_0040B3C0(void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B3C0
extern char gszLngPath_007A0710[0x104]; // 0x007A0710
extern D2MsgRecordChunkStrc gtMsgRecordChunkFirst_007A0818; // 0x007A0818

struct D2WinMsgStrc
{
    unsigned int dwTick;
    unsigned int uMessage;
    unsigned int wParam;
    int lParam;
};

struct D2RecordFileHeaderStrc
{
    int nVersion;
    int nBlocks;
    int nEntries;
    int nTick;
    int nSeed;
};

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134
extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x006CC19C
int __cdecl sub_0044DA90(); // 0x0044DA90
int __stdcall DUNGEON_GetInitSeedFromAct(D2DrlgActStrc* pAct); // 0x0061AAC0
extern D2DrlgActStrc* gpAct_007A0634; // 0x007A0634
void __stdcall sub_00451450_RecordMessage(unsigned int uMessage, unsigned int wParam, int lParam); // 0x00451450
extern int gdwGlobal_007A2780; // 0x007A2780

struct D2RecordBlockStrc
{
    char aRecords[500 * 16];
    int nCount;
    int nPos;
    D2RecordBlockStrc* pNext;
};

struct D2RecordHeaderStrc
{
    int nVersion;
    int nBlocks;
    int nLastCount;
    int unk0x0C[2];
};
extern "C" __declspec(dllimport) int __stdcall ReadFile(void* hFile, void* pBuffer, unsigned long nBytes, unsigned long* pRead, void* pOverlapped);
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
extern D2RecordBlockStrc gFirstRecordBlock_007A0818; // 0x007A0818
extern D2RecordHeaderStrc sgtReadFileHeader; // 0x007A2768
extern int gnRecordPos_007A2784; // 0x007A2784
extern int gbRecordPlaying_007A2788; // 0x007A2788

// 0x00451260
int __cdecl sub_00451260_RegisterLngArgument()
{
    SCmdRegisterArgument(0x20000, -1, "lng", gszLngPath_007A0710, sizeof(gszLngPath_007A0710), 0, 0, 0);
    return 1;
}

// 0x004514B0
void __fastcall sub_004514B0_FilterMessage(unsigned int uMessage, unsigned int wParam, int lParam)
{
    if (gdwGlobal_007A2780)
    {
        switch (uMessage)
        {
        case 0x100:
        case 0x200:
            sub_00451450_RecordMessage(uMessage, wParam, lParam);
            return;
        case 0x10:
        case 0x101:
        case 0x102:
        case 0x111:
        case 0x201:
        case 0x202:
        case 0x204:
        case 0x205:
            sub_00451450_RecordMessage(uMessage, wParam, lParam);
            break;
        }
    }
}

D2MsgRecordChunkStrc gtMsgRecordChunkFirst_007A0818; // 0x007A0818

// 0x00451620
void __cdecl sub_00451620_WriteRecordFile()
{
    void* hFile = CreateFileA("Record.dr1", GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);

    D2MsgRecordChunkStrc* pChunk = &gtMsgRecordChunkFirst_007A0818;
    D2RecordFileHeaderStrc tHeader;
    tHeader.nVersion = 1;
    tHeader.nBlocks = 1;
    while (pChunk->pNext)
    {
        ++tHeader.nBlocks;
        pChunk = pChunk->pNext;
    }
    tHeader.nEntries = pChunk->nCount + 500 * (tHeader.nBlocks - 1);
    tHeader.nTick = sub_0044DA90();
    tHeader.nSeed = DUNGEON_GetInitSeedFromAct(gpAct_007A0634);

    unsigned long nSize = sizeof(tHeader);
    unsigned long nWritten;
    WriteFile(hFile, &nSize, sizeof(nSize), &nWritten, 0);
    WriteFile(hFile, &tHeader, sizeof(tHeader), &nWritten, 0);
    for (pChunk = &gtMsgRecordChunkFirst_007A0818; pChunk; pChunk = pChunk->pNext)
    {
        WriteFile(hFile, pChunk, pChunk->nCount * sizeof(D2WinMsgStrc), &nWritten, 0);
    }
    CloseHandle(hFile);
}

static D2RecordBlockStrc* gpRecordBlock_0070F7A0; // 0x0070F7A0

// 0x00451710
void __cdecl sub_00451710_LoadRecord()
{
    unsigned long nMagic;
    unsigned long nRead;
    void* hFile = CreateFileA("Record.dr1", 0x80000000, 0, 0, 3, 0x80, 0);
    ReadFile(hFile, &nMagic, 4, &nRead, 0);
    ReadFile(hFile, &sgtReadFileHeader, sizeof(D2RecordHeaderStrc), &nRead, 0);
    if (sgtReadFileHeader.nVersion != 1)
    {
        gnRecordPos_007A2784 = 0;
        gbRecordPlaying_007A2788 = 0;
        CloseHandle(hFile);
        return;
    }

    for (int i = 0; i < sgtReadFileHeader.nBlocks; ++i)
    {
        if (i)
        {
            D2RecordBlockStrc* pBlock = (D2RecordBlockStrc*)FOG_Alloc(sizeof(D2RecordBlockStrc), ".\\GAME\\Record.cpp", 0x35, 0);
            pBlock->nCount = 0;
            pBlock->nPos = 0;
            gpRecordBlock_0070F7A0->pNext = pBlock;
            pBlock->pNext = 0;
            gpRecordBlock_0070F7A0 = pBlock;
        }

        if (sgtReadFileHeader.nLastCount <= 500)
        {
            gnRecordCount_007A2758 = sgtReadFileHeader.nLastCount;
            D2_ASSERT(i + 1 == sgtReadFileHeader.nBlocks, 0x100);
        }
        else
        {
            gnRecordCount_007A2758 = 500;
        }

        ReadFile(hFile, gpRecordBlock_0070F7A0, gnRecordCount_007A2758 * 16, &nRead, 0);
    }

    gpRecordBlock_0070F7A0 = &gFirstRecordBlock_007A0818;
    CloseHandle(hFile);
}

// 0x00451850
void __cdecl sub_00451850_FreeMsgRecordChunks()
{
    D2MsgRecordChunkStrc* pChunk = gpMsgRecordChunkHead_007A2760;
    while (pChunk)
    {
        D2MsgRecordChunkStrc* pFree = pChunk;
        pChunk = pChunk->pNext;
        sub_0040B3C0(pFree, ".\\GAME\\Record.cpp", 0x120, 0);
    }
}
