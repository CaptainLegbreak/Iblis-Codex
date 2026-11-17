struct D2TxtLinkStrc;

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};

struct D2SuperUniquesTxt
{
    unsigned short wSuperUnique;
    unsigned short wNameStr;
    unsigned int dwClass;
    int dwHcIdx;
    char unk0x0C[0x34 - 0x0C];
};

struct D2DataTablesStrc
{
    char unk0x000[0x9B8];
    D2TxtLinkStrc* pTreasureClassExLinker;
    char unk0x9BC[0xA7C - 0x9BC];
    D2TxtLinkStrc* pMonStatsLinker;
    char unk0xA80[0xA88 - 0xA80];
    D2TxtLinkStrc* pMonSoundsLinker;
    char unk0xA8C[0xAD4 - 0xA8C];
    D2SuperUniquesTxt* pSuperUniquesTxt;
    D2TxtLinkStrc* pSuperUniquesLinker;
    int nSuperUniquesTxtRecordCount;
    unsigned short nSuperUniqueIds[66];
};

extern D2DataTablesStrc gtDataTables_0096BC30;                                                                       // 0x0096BC30

extern "C" const char gszTxtField_end[];                                                                    // 0x006D9060
void __fastcall sub_006117B0();                                                                 // 0x006117B0
D2TxtLinkStrc* __stdcall FOG_AllocLinker(const char* szFile, int nLine);                                    // 0x006BD040
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x006552E0
void __fastcall DATATBLS_LoadSuperUniquesTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "Superunique", 17, 0, 0, &gtDataTables_0096BC30.pSuperUniquesLinker },
        { "Name", 22, 0, 2, (void*)sub_006117B0 },
        { "Class", 19, 0, 4, &gtDataTables_0096BC30.pMonStatsLinker },
        { "hcIdx", 2, 0, 8, 0 },
        { "MonSound", 19, 0, 24, &gtDataTables_0096BC30.pMonSoundsLinker },
        { "Mod1", 2, 0, 12, 0 },
        { "Mod2", 2, 0, 16, 0 },
        { "Mod3", 2, 0, 20, 0 },
        { "MinGrp", 2, 0, 28, 0 },
        { "MaxGrp", 2, 0, 32, 0 },
        { "AutoPos", 4, 0, 36, 0 },
        { "EClass", 4, 0, 37, 0 },
        { "Stacks", 4, 0, 38, 0 },
        { "Replaceable", 4, 0, 39, 0 },
        { "Utrans", 4, 0, 40, 0 },
        { "Utrans(N)", 4, 0, 41, 0 },
        { "Utrans(H)", 4, 0, 42, 0 },
        { "TC", 20, 0, 44, &gtDataTables_0096BC30.pTreasureClassExLinker },
        { "TC(N)", 20, 0, 46, &gtDataTables_0096BC30.pTreasureClassExLinker },
        { "TC(H)", 20, 0, 48, &gtDataTables_0096BC30.pTreasureClassExLinker },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gtDataTables_0096BC30.pSuperUniquesLinker = FOG_AllocLinker(".\\DATATBLS\\MonsterTbls.cpp", 0x744);
    gtDataTables_0096BC30.pSuperUniquesTxt = (D2SuperUniquesTxt*)DATATBLS_CompileTxt(hArchive, "superuniques", pTbl, &gtDataTables_0096BC30.nSuperUniquesTxtRecordCount, sizeof(D2SuperUniquesTxt));
    if (gtDataTables_0096BC30.nSuperUniquesTxtRecordCount >= 512)
    {
        gtDataTables_0096BC30.nSuperUniquesTxtRecordCount = 512;
    }

    for (int i = 0; i < 66; ++i)
    {
        gtDataTables_0096BC30.nSuperUniqueIds[i] = 0xFFFF;
    }

    for (int i = 0; i < gtDataTables_0096BC30.nSuperUniquesTxtRecordCount; ++i)
    {
        const int nId = gtDataTables_0096BC30.pSuperUniquesTxt[i].dwHcIdx;
        if (nId >= 0 && nId < 66 && gtDataTables_0096BC30.nSuperUniqueIds[nId] == 0xFFFF)
        {
            gtDataTables_0096BC30.nSuperUniqueIds[nId] = (unsigned short)i;
        }
    }

    for (int i = 0; i < 66; ++i)
    {
        D2_ASSERT(gtDataTables_0096BC30.nSuperUniqueIds[i] != 0xFFFF, 0x782);
    }
}
