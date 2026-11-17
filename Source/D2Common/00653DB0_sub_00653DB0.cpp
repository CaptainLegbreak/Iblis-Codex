struct D2TxtLinkStrc;

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    int (__fastcall* pfnLink)(const char* szKey);
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

struct T006510C0
{
    void* pTables[4];
    int nCounts[4];
};

extern D2TxtLinkStrc* gpTreasureClassExLinker;                                                              // 0x0096C5E8
extern D2TCExShortStrc* gpTreasureClassEx;                                                                  // 0x0096C5EC
int gnTreasureClassEx;                                                                                      // 0x0096C5F0
extern D2TCExShortStrc* gpChestTreasureClasses[3][5][3];                                                    // 0x0096C5F4
extern T006510C0 gUniqueNameTables;                                                            // 0x0096D488
extern "C" const char* const gaszChestNames[3];                                                             // 0x00745A10
extern "C" const char* const gaszDifficultySuffixes[3];                                                     // 0x00745A1C
extern "C" const char gszTxtField_end[];                                                                    // 0x006D9060
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
void __stdcall sub_006547D0(void* hArchive);                                            // 0x006547D0

#define TC_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x00653DB0
void __fastcall sub_00653DB0(void* hArchive, const char* szName, unsigned int nIndex)
{
    D2BinFieldStrc pTbl[] =
    {
        { "Name", 22, 0, 0, sub_006117B0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    if (nIndex <= 3)
    {
        gUniqueNameTables.pTables[nIndex] = DATATBLS_CompileTxt(hArchive, szName, pTbl, &gUniqueNameTables.nCounts[nIndex], 2);
    }
}

// 0x00653E20
void __cdecl sub_00653E20()
{
    for (int i = 0; i < 4; ++i)
    {
        if (gUniqueNameTables.pTables[i])
        {
            DATATBLS_UnloadBin(gUniqueNameTables.pTables[i]);
            gUniqueNameTables.pTables[i] = 0;
            gUniqueNameTables.nCounts[i] = 0;
        }
    }
}

// 0x00653F90
D2TCExShortStrc* __fastcall DATATBLS_NewTreasureClassEx(const char* szTreasureClass)
{
    sub_006BD500_LinkerInsertKey(gpTreasureClassExLinker, szTreasureClass);

    if (!(gnTreasureClassEx % 16))
    {
        gpTreasureClassEx = (D2TCExShortStrc*)sub_0040B4B0(0, gpTreasureClassEx, sizeof(D2TCExShortStrc) * (gnTreasureClassEx + 16), ".\\DATATBLS\\MonsterTbls.cpp", 930, 0);
    }

    memset(&gpTreasureClassEx[gnTreasureClassEx], 0, sizeof(D2TCExShortStrc));
    return &gpTreasureClassEx[gnTreasureClassEx++];
}

// 0x00654010
void __fastcall DATATBLS_ReallocTCExInfo(D2TCExShortStrc* pTCExShort, int nNewRecordCount)
{
    pTCExShort->pInfo = (D2TCExInfoStrc*)sub_0040B4B0(0, pTCExShort->pInfo, sizeof(D2TCExInfoStrc) * nNewRecordCount, ".\\DATATBLS\\MonsterTbls.cpp", 954, 0);
    memset(&pTCExShort->pInfo[pTCExShort->nTypes], 0, sizeof(D2TCExInfoStrc) * (nNewRecordCount - pTCExShort->nTypes));
    pTCExShort->nTypes = nNewRecordCount;
}

// 0x00654080
D2TCExInfoStrc* __fastcall sub_00654080(D2TCExShortStrc* pTCExShort)
{
    const int nRecordId = pTCExShort->nTypes;

    DATATBLS_ReallocTCExInfo(pTCExShort, nRecordId + 1);
    pTCExShort->pInfo[nRecordId].nClassic = pTCExShort->nClassic;
    pTCExShort->pInfo[nRecordId].nProb = pTCExShort->nProb;
    return &pTCExShort->pInfo[nRecordId];
}

// 0x0065A2C0
void __cdecl sub_0065A2C0()
{
    char szName[0x100];

    for (int nDifficulty = 0; nDifficulty < 3; ++nDifficulty)
    {
        for (int nAct = 0; nAct < 5; ++nAct)
        {
            for (int i = 0; i < 3; ++i)
            {
                SStrPrintf(szName, sizeof(szName), "Act %d%s Chest %s", nAct + 1, gaszDifficultySuffixes[nDifficulty], gaszChestNames[i]);

                const int nId = FOG_GetLinkIndex(gpTreasureClassExLinker, szName, 0);
                gpChestTreasureClasses[nDifficulty][nAct][i] = nId >= 0 ? &gpTreasureClassEx[nId] : 0;
            }
        }
    }
}

// 0x0065A390
void __stdcall sub_0065A390(void* hArchive)
{
    gpTreasureClassExLinker = sub_006BD040(".\\DATATBLS\\MonsterTbls.cpp", 1550);
    DATATBLS_CreateItemTypeTreasureClasses();
    sub_006547D0(hArchive);
    sub_0065A2C0();
    TC_ASSERT(gnTreasureClassEx < 0xFFFF, 1558);
}

// 0x0065A3F0
void __fastcall DATATBLS_LoadTreasureClassExTxt(void* hArchive)
{
    sub_0065A390(hArchive);
}

#include "gen/data/Source/D2Common/00653DB0_sub_00653DB0.inc"
