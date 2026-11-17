struct D2TxtLinkStrc;

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};

struct D2AnimSeqTxt
{
    short wSequence;
    unsigned char nMode;
    unsigned char nFrame;
    unsigned char nDir;
    unsigned char nEvent;
};

struct D2AnimSeqRecordStrc
{
    D2AnimSeqTxt* pAnimSeqTxtRecord;
    int nSeqFramesCount;
    int nFramesCount;
};

extern "C" const char gszTxtField_end[];                                                                    // 0x006D9060
D2TxtLinkStrc* gTxtLink_0096C7AC;                                                                           // 0x0096C7AC
extern D2TxtLinkStrc* gTxtLink_0096BC5C;                                                                    // 0x0096BC5C
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0
D2AnimSeqTxt* gpMonseqTxt;                                                                                  // 0x0096C7A8
int gnMonseqTxtRecordCount;                                                                                 // 0x0096C7B0
D2TxtLinkStrc* __stdcall FOG_AllocLinker(const char* szFile, int nLine);                                    // 0x006BD040
extern D2TxtLinkStrc* gpMonseqLinker;                                                                       // 0x0096C7AC
D2AnimSeqRecordStrc* gpMonSeqTable;                                                                         // 0x0096C7B4
int gnMonSeqTableRecordCount;                                                                               // 0x0096C7B8
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
#pragma function(memset)

// 0x00659C60
void __fastcall DATATBLS_LoadMonSeqTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "sequence", 17, 0, 0, &gTxtLink_0096C7AC },
        { "mode", 13, 0, 2, &gTxtLink_0096BC5C },
        { "frame", 4, 0, 3, 0 },
        { "dir", 4, 0, 4, 0 },
        { "event", 4, 0, 5, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gTxtLink_0096C7AC = FOG_AllocLinker(".\\DATATBLS\\MonsterTbls.cpp", 3267);
    gpMonseqTxt = (D2AnimSeqTxt*)DATATBLS_CompileTxt(hArchive, "monseq", pTbl, &gnMonseqTxtRecordCount, 6);

    if (gnMonseqTxtRecordCount > 0)
    {
        gnMonSeqTableRecordCount = gpMonseqTxt[gnMonseqTxtRecordCount - 1].wSequence + 1;
        gpMonSeqTable = (D2AnimSeqRecordStrc*)FOG_AllocPool(0, sizeof(D2AnimSeqRecordStrc) * gnMonSeqTableRecordCount, ".\\DATATBLS\\MonsterTbls.cpp", 3276, 0);
        memset(gpMonSeqTable, 0, sizeof(D2AnimSeqRecordStrc) * gnMonSeqTableRecordCount);

        for (int i = 0; i < gnMonseqTxtRecordCount; ++i)
        {
            int nSequence = gpMonseqTxt[i].wSequence;
            if (!gpMonSeqTable[nSequence].pAnimSeqTxtRecord)
            {
                gpMonSeqTable[nSequence].pAnimSeqTxtRecord = &gpMonseqTxt[i];
            }

            ++gpMonSeqTable[nSequence].nSeqFramesCount;
            ++gpMonSeqTable[nSequence].nFramesCount;
        }
    }
}
