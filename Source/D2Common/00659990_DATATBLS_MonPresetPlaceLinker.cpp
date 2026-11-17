struct D2TxtLinkStrc;

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pfnLink;
};

struct D2TCExInfoStrc
{
    int nClassic;
    int nProb;
    char unk0x08[0x1C - 8];
};

struct D2TCExShortStrc
{
    short nGroup;
    short nLevel;
    int nTypes;
    int nClassic;
    int nProb;
    char unk0x10[0x28 - 0x10];
    D2TCExInfoStrc* pInfo;
};

struct D2MonPresetTxt
{
    unsigned char nAct;
    unsigned char nType;
    unsigned short nIndex;
};

struct T006510C0
{
    void* pTables[4];
    int nCounts[4];
};

extern D2TxtLinkStrc* gpTreasureClassExLinker;                                                              // 0x0096C5E8
extern D2TCExShortStrc* gpTreasureClassEx;                                                                  // 0x0096C5EC
extern int gnTreasureClassEx;                                                                               // 0x0096C5F0
extern D2TCExShortStrc* gpChestTreasureClasses[3][5][3];                                                    // 0x0096C5F4
extern T006510C0 gUniqueNameTables;                                                            // 0x0096D488
extern "C" const char* const gaszChestNames[3];                                                             // 0x00745A10
extern "C" const char* const gaszDifficultySuffixes[3];                                                     // 0x00745A1C
extern "C" const char gszChestTreasureClassFormat[];                                                        // 0x006ED588
extern "C" const char gszTxtField_Name[];                                                                   // 0x006EA354
extern "C" const char gszTxtField_end[];                                                                    // 0x006D9060
extern "C" const char gszMonsterTblsSourceFile[];                                                           // 0x006EBE70
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" int __cdecl SStrPrintf(char* szBuffer, unsigned int nSize, const char* szFormat, ...);            // 0x00413A40
void __stdcall sub_006BD500_LinkerInsertKey(D2TxtLinkStrc* pLinker, const char* szKey);                      // 0x006BD500
int __stdcall FOG_GetLinkIndex(D2TxtLinkStrc* pLinker, const char* szKey, int bLogError);                   // 0x006BD3C0
D2TxtLinkStrc* __stdcall sub_006BD040(const char* szFile, int nLine);                                   // 0x006BD040
void* __fastcall sub_0040B4B0(void* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0);// 0x0040B4B0
void __stdcall DATATBLS_UnloadBin(void* pBinFile);                                                          // 0x006125C0
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0
int __fastcall sub_006117B0(const char* szKey);                                           // 0x006117B0
void __cdecl DATATBLS_CreateItemTypeTreasureClasses();                                                      // 0x006541C0
extern D2TxtLinkStrc* gpSuperUniquesLinker;                                                                 // 0x0096C708
extern D2TxtLinkStrc* gpMonStatsLinker;                                                                     // 0x0096C6AC
extern D2TxtLinkStrc* gpMonPlaceLinker;                                                                     // 0x0096C6D0
extern D2MonPresetTxt* gpMonPresetTxt;                                                                      // 0x0096C6D8
extern D2MonPresetTxt* gapMonPresetTxtActSections[5];                                                       // 0x0096C6DC
extern int ganMonPresetTxtActRecordCounts[5];                                                               // 0x0096C6F0
extern "C" const char gszTxtField_Act[];                                                                    // 0x006E84D4
extern "C" const char gszTxtField_Place[];                                                                  // 0x006ED4F8
extern "C" const char gszMonPresetTxtName[];                                                                // 0x006ED500
void __stdcall sub_006547D0(void* hArchive);                                            // 0x006547D0

#define TC_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x00659990
void __fastcall DATATBLS_MonPresetPlaceLinker(char* pSrc, D2MonPresetTxt* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn)
{
    int nRow = 0;

    if (pRecord)
    {
        pRecord->nType = 0;
        pRecord->nIndex = 0;

        if (pSrc && *pSrc)
        {
            nRow = FOG_GetLinkIndex(gpSuperUniquesLinker, pSrc, 0);
            if (nRow >= 0)
            {
                pRecord->nType = 2;
                pRecord->nIndex = nRow;
                return;
            }

            nRow = FOG_GetLinkIndex(gpMonStatsLinker, pSrc, 0);
            if (nRow >= 0)
            {
                pRecord->nType = 1;
                pRecord->nIndex = nRow;
                return;
            }

            nRow = FOG_GetLinkIndex(gpMonPlaceLinker, pSrc, 1);
            if (nRow >= 0)
            {
                pRecord->nType = 0;
                pRecord->nIndex = nRow;
            }
        }
    }
}
