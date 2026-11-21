#include "D2Common.h"
#include "D2Txt.h"
#include "D2Records.h"
#include "D2LevelTxt.h"

#define TC_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2BinFieldStrc;

struct D2MonStatsTxt;

struct D2HirelingTxt;

struct T006510C0;

struct D2TCExInfoStrc;

struct D2TCExShortStrc;

struct D2MonPresetTxt;

typedef unsigned int size_t;

struct T006510C0
{
    void* pTables[4];
    int nCounts[4];
};

extern D2MonStatsTxt* gpMonstatsTxt; // 0x0096C6A8

extern int gnMonstatsTxtRecordCount; // 0x0096C6B0

extern T006510C0 gUniqueNameTables; // 0x0096D488

void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize); // 0x006122F0

unsigned short __fastcall DATATBLS_GetStringIdFromReferenceString(char* szReference); // 0x006117B0

void __fastcall DATATBLS_LoadMonLvlTxt(void* hArchive); // 0x00659500

void __stdcall sub_0065A390(void* hArchive); // 0x0065A390

D2MonStats2Txt* __fastcall DATATBLS_LoadMonStats2Txt(void* hArchive); // 0x006571A0

void __fastcall DATATBLS_LoadMonPropTxt(void* hArchive); // 0x00658720

void __fastcall DATATBLS_LoadMonSoundsTxt(void* hArchive); // 0x00656930

void __fastcall DATATBLS_LoadMonSeqTxt(void* hArchive); // 0x00659C60

void __fastcall DATATBLS_LoadMonStatsTxt(void* hArchive); // 0x00651210

void __fastcall DATATBLS_LoadMonUModTxt(void* hArchive); // 0x00655030

void __fastcall DATATBLS_LoadSuperUniquesTxt(void* hArchive); // 0x006552E0

void __fastcall DATATBLS_LoadMonPresetTxt(void* hArchive); // 0x00659A10

void __fastcall sub_00655720_LoadHirelingTxt(void* hArchive); // 0x00655720

void __fastcall DATATBLS_LoadNpcTxt(void* hArchive); // 0x00656620

void __fastcall DATATBLS_LoadMonEquipTxt(void* hArchive); // 0x00659E60

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

extern D2TCExShortStrc* gpTreasureClassEx; // 0x0096C5EC

extern D2TCExShortStrc* gpChestTreasureClasses[3][5][3]; // 0x0096C5F4

extern "C" const char* const gaszChestNames[3]; // 0x00745A10

extern "C" const char* const gaszDifficultySuffixes[3]; // 0x00745A1C

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" int __cdecl SStrPrintf(char* szBuffer, unsigned int nSize, const char* szFormat, ...); // 0x00413A40

void __stdcall sub_006BD500_LinkerInsertKey(D2TxtLinkStrc* pLinker, const char* szKey); // 0x006BD500

int __stdcall FOG_GetLinkIndex(D2TxtLinkStrc* pLinker, const char* szKey, int bLogError); // 0x006BD3C0

void* __fastcall FOG_ReallocPool(void* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0); // 0x0040B4B0

void __stdcall DATATBLS_UnloadBin(void* pBinFile); // 0x006125C0

void __cdecl DATATBLS_CreateItemTypeTreasureClasses(); // 0x006541C0

void __stdcall sub_006547D0(void* hArchive); // 0x006547D0

struct D2MonPresetTxt
{
    unsigned char nAct;
    unsigned char nType;
    unsigned short nIndex;
};

int gnTreasureClassEx; // 0x0096C5F0

extern "C" const char gszChestTreasureClassFormat[]; // 0x006ED588

extern "C" const char gszTxtField_Name[]; // 0x006EA354

extern D2TxtLinkStrc* gpSuperUniquesLinker; // 0x0096C708

extern D2TxtLinkStrc* gpMonPlaceLinker; // 0x0096C6D0

extern D2MonPresetTxt* gpMonPresetTxt; // 0x0096C6D8

extern D2MonPresetTxt* gapMonPresetTxtActSections[5]; // 0x0096C6DC

extern int ganMonPresetTxtActRecordCounts[5]; // 0x0096C6F0

extern "C" const char gszTxtField_Act[]; // 0x006E84D4

extern "C" const char gszTxtField_Place[]; // 0x006ED4F8

extern "C" const char gszMonPresetTxtName[]; // 0x006ED500

D2HirelingTxt* gpHirelingTxt; // 0x0096BDD0

struct D2TxtLinkStrc;

struct D2MonTypeTxt
{
    short nType;
    short nEquiv[3];
    char unk0x08[4];
};

extern "C" const char gszTxtField_equiv1[];                                                                 // 0x006DCD14

extern "C" const char gszTxtField_equiv2[];                                                                 // 0x006DCD0C

extern "C" const char gszTxtField_end[];                                                                    // 0x006D9060

D2TxtLinkStrc* gTxtLink_0096C868;                                                                           // 0x0096C868

extern D2MonTypeTxt* gpMonTypeTxt;                                                                          // 0x0096C86C

int gnMonTypeTxtRecordCount;                                                                                // 0x0096C870

unsigned int* gpMonTypeNest;                                                                                // 0x0096C874

int gnMonTypeIndex;                                                                                         // 0x0096C878

extern const unsigned int gdwBitMasks[32];                                                                  // 0x006CE268

D2TxtLinkStrc* __stdcall FOG_AllocLinker(const char* szFile, int nLine);                                    // 0x006BD040

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430

#pragma function(memset)

int __fastcall DATATBLS_CheckNestedMonsterTypes(int nMonType1, int nMonType2);

void __fastcall DATATBLS_LoadMonTypeTxt(void* hArchive);

#define FIELD_TEXT(x) (x)

#define FIXTURE_LINE(x) (x)

unsigned short __stdcall sub_00524D30_FindString(const char* szKey, const wchar_t** ppText);               // 0x00524D30

D2TxtLinkStrc* gpHireDescLinker_0096BCE8;                                                                   // 0x0096BCE8

extern D2TxtLinkStrc* gpSkillsLinker_0096C7CC;                                                              // 0x0096C7CC

int __cdecl sub_00408F20_HasExpansionMpq();

extern "C" const char gszField_006DCCF0[]; // 0x006DCCF0

extern "C" const char gszField_006DCD90[]; // 0x006DCD90

extern "C" const char gszField_006D9060[]; // 0x006D9060

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), FIXTURE_LINE(line)); exit(-1); }

struct D2HirelingTableGlobals
{
    D2HirelingTxt* f_0;
    int nCount;
    int indices[2][256];
};

extern D2HirelingTableGlobals gHirelingTables;  // 0x0096BDD0

#define gpHirelingTxt (gHirelingTables.f_0)

#define gnHirelingTxtRecordCount (gHirelingTables.nCount)

#define gaHirelingIds (gHirelingTables.indices)

// 0x006510C0
int __stdcall DATATBLS_GetMonsterChainInfo(int nMonsterId, int* pMaxChainId, int* pChainId)
{
    if (nMonsterId >= 0 && nMonsterId < gnMonstatsTxtRecordCount)
    {
        if (pMaxChainId)
        {
            *pMaxChainId = gpMonstatsTxt[nMonsterId].nMaxChainId;
        }

        if (pChainId)
        {
            *pChainId = gpMonstatsTxt[nMonsterId].nChainId;
        }

        return gpMonstatsTxt[nMonsterId].nChainId;
    }

    if (pMaxChainId)
    {
        *pMaxChainId = 0;
    }

    if (pChainId)
    {
        *pChainId = 0;
    }

    return 0;
}

// 0x00653DB0
void __fastcall sub_00653DB0(void* hArchive, const char* szName, unsigned int nIndex)
{
    D2BinFieldStrc pTbl[] =
    {
        { "Name", 22, 0, 0, DATATBLS_GetStringIdFromReferenceString },
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
        gpTreasureClassEx = (D2TCExShortStrc*)FOG_ReallocPool(0, gpTreasureClassEx, sizeof(D2TCExShortStrc) * (gnTreasureClassEx + 16), ".\\DATATBLS\\MonsterTbls.cpp", 930, 0);
    }

    memset(&gpTreasureClassEx[gnTreasureClassEx], 0, sizeof(D2TCExShortStrc));
    return &gpTreasureClassEx[gnTreasureClassEx++];
}

// 0x00654010
void __fastcall DATATBLS_ReallocTCExInfo(D2TCExShortStrc* pTCExShort, int nNewRecordCount)
{
    pTCExShort->pInfo = (D2TCExInfoStrc*)FOG_ReallocPool(0, pTCExShort->pInfo, sizeof(D2TCExInfoStrc) * nNewRecordCount, ".\\DATATBLS\\MonsterTbls.cpp", 954, 0);
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

// 0x00655720
void __fastcall sub_00655720_LoadHirelingTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { FIELD_TEXT(gszField_006DCCF0), 3, 0, 0x0, 0 },
        { FIELD_TEXT("id"), 2, 0, 0x4, 0 },
        { FIELD_TEXT("class"), 2, 0, 0x8, 0 },
        { FIELD_TEXT("act"), 2, 0, 0xC, 0 },
        { FIELD_TEXT("difficulty"), 2, 0, 0x10, 0 },
        { FIELD_TEXT("seller"), 2, 0, 0x14, 0 },
        { FIELD_TEXT(gszField_006DCD90), 2, 0, 0x18, 0 },
        { FIELD_TEXT("level"), 2, 0, 0x1C, 0 },
        { FIELD_TEXT("namefirst"), 1, 32, 0xD3, 0 },
        { FIELD_TEXT("namelast"), 1, 32, 0xF3, 0 },
        { FIELD_TEXT("exp/lvl"), 2, 0, 0x20, 0 },
        { FIELD_TEXT("hp"), 2, 0, 0x24, 0 },
        { FIELD_TEXT("hp/lvl"), 2, 0, 0x28, 0 },
        { FIELD_TEXT("defense"), 2, 0, 0x2C, 0 },
        { FIELD_TEXT("def/lvl"), 2, 0, 0x30, 0 },
        { FIELD_TEXT("str"), 2, 0, 0x34, 0 },
        { FIELD_TEXT("str/lvl"), 2, 0, 0x38, 0 },
        { FIELD_TEXT("dex"), 2, 0, 0x3C, 0 },
        { FIELD_TEXT("dex/lvl"), 2, 0, 0x40, 0 },
        { FIELD_TEXT("ar"), 2, 0, 0x44, 0 },
        { FIELD_TEXT("ar/lvl"), 2, 0, 0x48, 0 },
        { FIELD_TEXT("share"), 2, 0, 0x4C, 0 },
        { FIELD_TEXT("dmg-min"), 2, 0, 0x50, 0 },
        { FIELD_TEXT("dmg-max"), 2, 0, 0x54, 0 },
        { FIELD_TEXT("dmg/lvl"), 2, 0, 0x58, 0 },
        { FIELD_TEXT("resist"), 2, 0, 0x5C, 0 },
        { FIELD_TEXT("resist/lvl"), 2, 0, 0x60, 0 },
        { FIELD_TEXT("hiredesc"), 13, 0, 0xD2, &gpHireDescLinker_0096BCE8 },
        { FIELD_TEXT("defaultchance"), 2, 0, 0x64, 0 },
        { FIELD_TEXT("skill1"), 19, 0, 0x78, &gpSkillsLinker_0096C7CC },
        { FIELD_TEXT("mode1"), 4, 0, 0xC0, 0 },
        { FIELD_TEXT("chance1"), 2, 0, 0x90, 0 },
        { FIELD_TEXT("chanceperlvl1"), 2, 0, 0xA8, 0 },
        { FIELD_TEXT("level1"), 4, 0, 0xC6, 0 },
        { FIELD_TEXT("lvlperlvl1"), 4, 0, 0xCC, 0 },
        { FIELD_TEXT("skill2"), 19, 0, 0x7C, &gpSkillsLinker_0096C7CC },
        { FIELD_TEXT("mode2"), 4, 0, 0xC1, 0 },
        { FIELD_TEXT("chance2"), 2, 0, 0x94, 0 },
        { FIELD_TEXT("chanceperlvl2"), 2, 0, 0xAC, 0 },
        { FIELD_TEXT("level2"), 4, 0, 0xC7, 0 },
        { FIELD_TEXT("lvlperlvl2"), 4, 0, 0xCD, 0 },
        { FIELD_TEXT("skill3"), 19, 0, 0x80, &gpSkillsLinker_0096C7CC },
        { FIELD_TEXT("mode3"), 4, 0, 0xC2, 0 },
        { FIELD_TEXT("chance3"), 2, 0, 0x98, 0 },
        { FIELD_TEXT("chanceperlvl3"), 2, 0, 0xB0, 0 },
        { FIELD_TEXT("level3"), 4, 0, 0xC8, 0 },
        { FIELD_TEXT("lvlperlvl3"), 4, 0, 0xCE, 0 },
        { FIELD_TEXT("skill4"), 19, 0, 0x84, &gpSkillsLinker_0096C7CC },
        { FIELD_TEXT("mode4"), 4, 0, 0xC3, 0 },
        { FIELD_TEXT("chance4"), 2, 0, 0x9C, 0 },
        { FIELD_TEXT("chanceperlvl4"), 2, 0, 0xB4, 0 },
        { FIELD_TEXT("level4"), 4, 0, 0xC9, 0 },
        { FIELD_TEXT("lvlperlvl4"), 4, 0, 0xCF, 0 },
        { FIELD_TEXT("skill5"), 19, 0, 0x88, &gpSkillsLinker_0096C7CC },
        { FIELD_TEXT("mode5"), 4, 0, 0xC4, 0 },
        { FIELD_TEXT("chance5"), 2, 0, 0xA0, 0 },
        { FIELD_TEXT("chanceperlvl5"), 2, 0, 0xB8, 0 },
        { FIELD_TEXT("level5"), 4, 0, 0xCA, 0 },
        { FIELD_TEXT("lvlperlvl5"), 4, 0, 0xD0, 0 },
        { FIELD_TEXT("skill6"), 19, 0, 0x8C, &gpSkillsLinker_0096C7CC },
        { FIELD_TEXT("mode6"), 4, 0, 0xC5, 0 },
        { FIELD_TEXT("chance6"), 2, 0, 0xA4, 0 },
        { FIELD_TEXT("chanceperlvl6"), 2, 0, 0xBC, 0 },
        { FIELD_TEXT("level6"), 4, 0, 0xCB, 0 },
        { FIELD_TEXT("lvlperlvl6"), 4, 0, 0xD1, 0 },
        { FIELD_TEXT("head"), 2, 0, 0x68, 0 },
        { FIELD_TEXT("torso"), 2, 0, 0x6C, 0 },
        { FIELD_TEXT("weapon"), 2, 0, 0x70, 0 },
        { FIELD_TEXT("shield"), 2, 0, 0x74, 0 },
        { FIELD_TEXT(gszField_006D9060), 0, 0, 0x0, 0 },
    };
    gpHirelingTxt = (D2HirelingTxt*)DATATBLS_CompileTxt(hArchive, FIELD_TEXT("hireling"), pTbl, &gnHirelingTxtRecordCount, sizeof(D2HirelingTxt));
    for (int i = 0; i < 256; ++i)
    {
        gaHirelingIds[0][i] = -1;
        gaHirelingIds[1][i] = -1;
    }
    const int bExpansion = sub_00408F20_HasExpansionMpq();
    for (int i = 0; i < gnHirelingTxtRecordCount; ++i)
    {
        const wchar_t* pUnicode = 0;
        gpHirelingTxt[i].wNameFirst = sub_00524D30_FindString(gpHirelingTxt[i].szNameFirst, &pUnicode);
        gpHirelingTxt[i].wNameLast = sub_00524D30_FindString(gpHirelingTxt[i].szNameLast, &pUnicode);
        if (bExpansion)
        {
            D2_ASSERT(gpHirelingTxt[i].wNameFirst > 0, 0x816);
            D2_ASSERT(gpHirelingTxt[i].wNameLast > gpHirelingTxt[i].wNameFirst, 0x817);
            D2_ASSERT(gpHirelingTxt[i].nId < 256, 0x818);
        }
        if (gpHirelingTxt[i].nId < 256)
        {
            const int nVersion = gpHirelingTxt[i].wVersion >= 100;
            if (gaHirelingIds[nVersion][gpHirelingTxt[i].nId] < 0)
                gaHirelingIds[nVersion][gpHirelingTxt[i].nId] = i;
        }
    }
}

// 0x00656390
D2HirelingTxt* __stdcall DATATBLS_GetNextHirelingTxtRecordFromNameId(int bExpansion, unsigned short nNameId, D2HirelingTxt* pOldRecord)
{
    D2HirelingTxt* pHirelingTxtRecord = 0;
    const unsigned short nVersion = bExpansion != 0 ? 100 : 0;
    int nRecordId = 0;

    if (pOldRecord)
    {
        nRecordId = pOldRecord - gpHirelingTxt + 1;
    }

    for (int i = nRecordId; i < gnHirelingTxtRecordCount; ++i)
    {
        if (gpHirelingTxt[i].wNameFirst <= nNameId && gpHirelingTxt[i].wNameLast >= nNameId && gpHirelingTxt[i].wVersion == nVersion)
        {
            pHirelingTxtRecord = &gpHirelingTxt[i];
            break;
        }
    }

    return pHirelingTxtRecord;
}

// 0x006564D0
D2HirelingTxt* __stdcall DATATBLS_GetNextHirelingTxtRecordFromVendorIdAndDifficulty(int bExpansion, int nVendorId, int nDifficulty, D2HirelingTxt* pOldRecord)
{
    D2HirelingTxt* pHirelingTxtRecord = 0;
    const unsigned short nVersion = bExpansion != 0 ? 100 : 0;
    int nRecordId = 0;

    if (pOldRecord)
    {
        nRecordId = pOldRecord - gpHirelingTxt + 1;
    }

    const int nDifficultyId = nDifficulty + 1;
    for (int i = nRecordId; i < gnHirelingTxtRecordCount; ++i)
    {
        if (gpHirelingTxt[i].dwSeller == nVendorId && gpHirelingTxt[i].dwDifficulty == nDifficultyId && gpHirelingTxt[i].wVersion == nVersion)
        {
            pHirelingTxtRecord = &gpHirelingTxt[i];
            break;
        }
    }

    return pHirelingTxtRecord;
}

// 0x00658460
int __fastcall DATATBLS_CheckNestedMonsterTypes(int nMonType1, int nMonType2)
{
    int nParentMonsterTypes[128];

    if (nMonType2 <= 0)
    {
        return 0;
    }

    if (nMonType1 <= 0 || nMonType1 >= gnMonTypeTxtRecordCount)
    {
        return 0;
    }

    nParentMonsterTypes[0] = nMonType1;
    int nIndex = 1;
    do
    {
        int nMonsterType = nParentMonsterTypes[--nIndex];
        if (nMonType2 == nMonsterType)
        {
            return 1;
        }

        if (nMonsterType >= gnMonTypeTxtRecordCount || nIndex > 124)
        {
            break;
        }

        D2MonTypeTxt* pMonTypeTxtRecord = &gpMonTypeTxt[nMonsterType];
        if (pMonTypeTxtRecord->nEquiv[0] > 0)
        {
            nParentMonsterTypes[nIndex++] = pMonTypeTxtRecord->nEquiv[0];
            if (pMonTypeTxtRecord->nEquiv[1])
            {
                nParentMonsterTypes[nIndex++] = pMonTypeTxtRecord->nEquiv[1];
                if (pMonTypeTxtRecord->nEquiv[2])
                {
                    nParentMonsterTypes[nIndex++] = pMonTypeTxtRecord->nEquiv[2];
                }
            }
        }
    }
    while (nIndex);

    return 0;
}

// 0x00658520
void __fastcall DATATBLS_LoadMonTypeTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "type", 17, 0, 0, &gTxtLink_0096C868 },
        { gszTxtField_equiv1, 20, 0, 2, &gTxtLink_0096C868 },
        { gszTxtField_equiv2, 20, 0, 4, &gTxtLink_0096C868 },
        { "equiv3", 20, 0, 6, &gTxtLink_0096C868 },
        { "strsing", 22, 0, 8, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "strplur", 22, 0, 10, (void*)DATATBLS_GetStringIdFromReferenceString },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gTxtLink_0096C868 = FOG_AllocLinker(".\\DATATBLS\\MonsterTbls.cpp", 2806);
    gpMonTypeTxt = (D2MonTypeTxt*)DATATBLS_CompileTxt(hArchive, "montype", pTbl, &gnMonTypeTxtRecordCount, 12);

    gnMonTypeIndex = (gnMonTypeTxtRecordCount + 31) / 32;
    const int nCount = gnMonTypeIndex * gnMonTypeTxtRecordCount;
    gpMonTypeNest = (unsigned int*)FOG_AllocPool(0, nCount * sizeof(unsigned int), ".\\DATATBLS\\MonsterTbls.cpp", 2812, 0);
    memset(gpMonTypeNest, 0, nCount * sizeof(unsigned int));

    for (int i = 0; i < gnMonTypeTxtRecordCount; ++i)
    {
        unsigned int* pMonTypeNest = &gpMonTypeNest[gnMonTypeIndex * i];
        for (int j = 0; j < gnMonTypeTxtRecordCount; ++j)
        {
            if (DATATBLS_CheckNestedMonsterTypes(i, j))
            {
                pMonTypeNest[j >> 5] |= gdwBitMasks[j & 31];
            }
        }
    }
}

struct D2MonStats2Txt;

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

// 0x0065A400
void __fastcall DATATBLS_LoadSomeMonsterTxts(void* hArchive)
{
    {
        D2BinFieldStrc pTbl[] =
        {
            { "Name", 22, 0, 0, (void*)DATATBLS_GetStringIdFromReferenceString },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gUniqueNameTables.pTables[0] = DATATBLS_CompileTxt(hArchive, "uniquetitle", pTbl, &gUniqueNameTables.nCounts[0], 2);
    }

    {
        D2BinFieldStrc pTbl[] =
        {
            { "Name", 22, 0, 0, (void*)DATATBLS_GetStringIdFromReferenceString },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gUniqueNameTables.pTables[1] = DATATBLS_CompileTxt(hArchive, "uniqueprefix", pTbl, &gUniqueNameTables.nCounts[1], 2);
    }

    {
        D2BinFieldStrc pTbl[] =
        {
            { "Name", 22, 0, 0, (void*)DATATBLS_GetStringIdFromReferenceString },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gUniqueNameTables.pTables[2] = DATATBLS_CompileTxt(hArchive, "uniquesuffix", pTbl, &gUniqueNameTables.nCounts[2], 2);
    }

    {
        D2BinFieldStrc pTbl[] =
        {
            { "Name", 22, 0, 0, (void*)DATATBLS_GetStringIdFromReferenceString },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gUniqueNameTables.pTables[3] = DATATBLS_CompileTxt(hArchive, "uniqueappellation", pTbl, &gUniqueNameTables.nCounts[3], 2);
    }

    DATATBLS_LoadMonLvlTxt(hArchive);
    sub_0065A390(hArchive);
    DATATBLS_LoadMonStats2Txt(hArchive);
    DATATBLS_LoadMonPropTxt(hArchive);
    DATATBLS_LoadMonSoundsTxt(hArchive);
    DATATBLS_LoadMonSeqTxt(hArchive);
    DATATBLS_LoadMonStatsTxt(hArchive);
    DATATBLS_LoadMonUModTxt(hArchive);
    DATATBLS_LoadSuperUniquesTxt(hArchive);
    DATATBLS_LoadMonPresetTxt(hArchive);
    sub_00655720_LoadHirelingTxt(hArchive);
    DATATBLS_LoadNpcTxt(hArchive);
    DATATBLS_LoadMonEquipTxt(hArchive);
}

#include "gen/data/Source/D2Common/DATATBLS/MonsterTbls_006510C0.inc"
