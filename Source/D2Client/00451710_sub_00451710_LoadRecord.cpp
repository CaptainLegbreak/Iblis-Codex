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

extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char* szName, unsigned long dwAccess, unsigned long dwShare, void* pSecurity, unsigned long dwCreation, unsigned long dwFlags, void* hTemplate);
extern "C" __declspec(dllimport) int __stdcall ReadFile(void* hFile, void* pBuffer, unsigned long nBytes, unsigned long* pRead, void* pOverlapped);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

static D2RecordBlockStrc* gpRecordBlock_0070F7A0; // 0x0070F7A0
extern D2RecordBlockStrc gFirstRecordBlock_007A0818; // 0x007A0818
#define gnRecordCount_007A2758 (gFirstRecordBlock_007A0818.nCount)
extern D2RecordHeaderStrc gRecordHeader_007A2768; // 0x007A2768
extern int gnRecordPos_007A2784; // 0x007A2784
extern int gbRecordPlaying_007A2788; // 0x007A2788

// 0x00451710
void __cdecl sub_00451710_LoadRecord()
{
    unsigned long nMagic;
    unsigned long nRead;
    void* hFile = CreateFileA("Record.dr1", 0x80000000, 0, 0, 3, 0x80, 0);
    ReadFile(hFile, &nMagic, 4, &nRead, 0);
    ReadFile(hFile, &gRecordHeader_007A2768, sizeof(D2RecordHeaderStrc), &nRead, 0);
    if (gRecordHeader_007A2768.nVersion != 1)
    {
        gnRecordPos_007A2784 = 0;
        gbRecordPlaying_007A2788 = 0;
        CloseHandle(hFile);
        return;
    }

    for (int i = 0; i < gRecordHeader_007A2768.nBlocks; ++i)
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

        if (gRecordHeader_007A2768.nLastCount <= 500)
        {
            gnRecordCount_007A2758 = gRecordHeader_007A2768.nLastCount;
            D2_ASSERT(i + 1 == gRecordHeader_007A2768.nBlocks, 0x100);
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
