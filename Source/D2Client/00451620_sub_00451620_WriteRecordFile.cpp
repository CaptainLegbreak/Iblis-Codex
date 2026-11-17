struct D2DrlgActStrc;

struct D2WinMsgStrc
{
    unsigned int dwTick;
    unsigned int uMessage;
    unsigned int wParam;
    int lParam;
};

struct D2MsgRecordChunkStrc
{
    D2WinMsgStrc tRecords[500];
    int nCount;
    int nUnk0x1F44;
    D2MsgRecordChunkStrc* pNext;
};

struct D2RecordFileHeaderStrc
{
    int nVersion;
    int nBlocks;
    int nEntries;
    int nTick;
    int nSeed;
};

#define GENERIC_WRITE 0x40000000
#define CREATE_ALWAYS 2
#define FILE_ATTRIBUTE_NORMAL 0x00000080

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134
extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x006CC19C
extern "C" __declspec(dllimport) int __stdcall WriteFile(void* hFile, const void* pBuffer, unsigned long nToWrite, unsigned long* pnWritten, void* pOverlapped); // 0x006CC1A8

int __cdecl sub_0044DA90();                                                                                 // 0x0044DA90
int __stdcall DUNGEON_GetInitSeedFromAct(D2DrlgActStrc* pAct);                                              // 0x0061AAC0

extern D2DrlgActStrc* gpAct_007A0634;                                                                       // 0x007A0634
D2MsgRecordChunkStrc gtMsgRecordChunkFirst_007A0818;                                                        // 0x007A0818

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
