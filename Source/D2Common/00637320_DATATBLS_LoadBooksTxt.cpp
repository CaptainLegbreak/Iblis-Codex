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
void __fastcall sub_006117B0();                                                                 // 0x006117B0
extern D2TxtLinkStrc* gTxtLink_0096C7CC;                                                                    // 0x0096C7CC
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0
void* gpBooksTxt;                                                                                           // 0x0096CC64
int gnBooksTxtRecordCount;                                                                                  // 0x0096CC60

// 0x00637320
void __fastcall DATATBLS_LoadBooksTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "name", 22, 0, 0, (void*)sub_006117B0 },
        { "scrollspellcode", 9, 0, 24, 0 },
        { "bookspellcode", 9, 0, 28, 0 },
        { "pSpell", 2, 0, 4, 0 },
        { "scrollskill", 19, 0, 8, &gTxtLink_0096C7CC },
        { "bookskill", 19, 0, 12, &gTxtLink_0096C7CC },
        { "spellicon", 4, 0, 2, 0 },
        { "basecost", 2, 0, 16, 0 },
        { "costpercharge", 2, 0, 20, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpBooksTxt = DATATBLS_CompileTxt(hArchive, "books", pTbl, &gnBooksTxtRecordCount, 32);
}
