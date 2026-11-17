struct D2TxtLinkStrc;

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};

extern "C" const char gszTxtField_end[];                                                                    // 0x006D9060
extern D2TxtLinkStrc* gTxtLink_0096C6AC;                                                                    // 0x0096C6AC
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0
extern void* gpNpcTxt;                                                                                      // 0x0096C5D8
int gnNpcTxtRecordCount;                                                                                    // 0x0096C5DC

// 0x00656620
void __fastcall DATATBLS_LoadNpcTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "npc", 19, 0, 0, &gTxtLink_0096C6AC },
        { "sell mult", 2, 0, 4, 0 },
        { "buy mult", 2, 0, 8, 0 },
        { "rep mult", 2, 0, 12, 0 },
        { "questflag A", 2, 0, 16, 0 },
        { "questflag B", 2, 0, 20, 0 },
        { "questflag C", 2, 0, 24, 0 },
        { "questsellmult A", 2, 0, 28, 0 },
        { "questsellmult B", 2, 0, 32, 0 },
        { "questsellmult C", 2, 0, 36, 0 },
        { "questbuymult A", 2, 0, 40, 0 },
        { "questbuymult B", 2, 0, 44, 0 },
        { "questbuymult C", 2, 0, 48, 0 },
        { "questrepmult A", 2, 0, 52, 0 },
        { "questrepmult B", 2, 0, 56, 0 },
        { "questrepmult C", 2, 0, 60, 0 },
        { "max buy", 2, 0, 64, 0 },
        { "max buy (N)", 2, 0, 68, 0 },
        { "max buy (H)", 2, 0, 72, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpNpcTxt = DATATBLS_CompileTxt(hArchive, "npc", pTbl, &gnNpcTxtRecordCount, 76);
}
