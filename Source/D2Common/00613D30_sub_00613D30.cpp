struct D2TxtLinkStrc;

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};

extern "C" const char gszTxtField_Amazon[];                                                                 // 0x006E070C
extern "C" const char gszTxtField_Sorceress[];                                                              // 0x006E0700
extern "C" const char gszTxtField_Necromancer[];                                                            // 0x006E06F4
extern "C" const char gszTxtField_Paladin[];                                                                // 0x006E06EC
extern "C" const char gszTxtField_Barbarian[];                                                              // 0x006E06E0
extern "C" const char gszTxtField_Druid[];                                                                  // 0x006E06D8
extern "C" const char gszTxtField_Assassin[];                                                               // 0x006E06CC
extern "C" const char gszTxtField_end[];                                                                    // 0x006D9060
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0
extern void* gpExperienceTxt;                                                                               // 0x0096C8A8

// 0x00613D30
void __stdcall sub_00613D30(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { gszTxtField_Amazon, 2, 0, 0, 0 },
        { gszTxtField_Sorceress, 2, 0, 4, 0 },
        { gszTxtField_Necromancer, 2, 0, 8, 0 },
        { gszTxtField_Paladin, 2, 0, 12, 0 },
        { gszTxtField_Barbarian, 2, 0, 16, 0 },
        { gszTxtField_Druid, 2, 0, 20, 0 },
        { gszTxtField_Assassin, 2, 0, 24, 0 },
        { "ExpRatio", 2, 0, 28, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpExperienceTxt = DATATBLS_CompileTxt(hArchive, "experience", pTbl, 0, 32);
}
