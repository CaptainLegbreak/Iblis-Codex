struct D2TxtLinkStrc;

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};

extern "C" const char gszTxtField_version[];                                                                // 0x006DCCF0
extern "C" const char gszTxtField_end[];                                                                    // 0x006D9060
extern D2TxtLinkStrc* gTxtLink_0096C87C;                                                                    // 0x0096C87C
extern D2TxtLinkStrc* gTxtLink_0096C868;                                                                    // 0x0096C868
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0
extern void* gpMonumodTxt;                                                                                  // 0x0096C880
int gnMonumodTxtRecordCount;                                                                                // 0x0096C884
D2TxtLinkStrc* __stdcall FOG_AllocLinker(const char* szFile, int nLine);                                    // 0x006BD040
extern D2TxtLinkStrc* gpMonumodLinker;                                                                      // 0x0096C87C

// 0x00655030
void __fastcall DATATBLS_LoadMonUModTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "uniquemod", 17, 0, 0, &gTxtLink_0096C87C },
        { gszTxtField_version, 3, 0, 4, 0 },
        { "enabled", 4, 0, 6, 0 },
        { "xfer", 4, 0, 7, 0 },
        { "champion", 4, 0, 8, 0 },
        { "fpick", 4, 0, 9, 0 },
        { "exclude1", 20, 0, 10, &gTxtLink_0096C868 },
        { "exclude2", 20, 0, 12, &gTxtLink_0096C868 },
        { "cpick", 3, 0, 14, 0 },
        { "cpick (N)", 3, 0, 16, 0 },
        { "cpick (H)", 3, 0, 18, 0 },
        { "upick", 3, 0, 20, 0 },
        { "upick (N)", 3, 0, 22, 0 },
        { "upick (H)", 3, 0, 24, 0 },
        { "constants", 2, 0, 28, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gTxtLink_0096C87C = FOG_AllocLinker(".\\DATATBLS\\MonsterTbls.cpp", 1791);
    gpMonumodTxt = DATATBLS_CompileTxt(hArchive, "monumod", pTbl, &gnMonumodTxtRecordCount, 32);
    if (gnMonumodTxtRecordCount > 256)
    {
        gnMonumodTxtRecordCount = 256;
    }
}
