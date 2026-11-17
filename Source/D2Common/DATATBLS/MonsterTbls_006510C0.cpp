#include "D2Common.h"

#define TC_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2BinFieldStrc;
struct D2MonStatsTxt;
struct D2HirelingTxt;
struct T006510C0;
struct D2TCExInfoStrc;
struct D2TCExShortStrc;
struct D2MonPresetTxt;

typedef unsigned int size_t;

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinkField;
};

struct D2MonStatsTxt
{
    char unk0x000[0x04A];
    unsigned char nMaxChainId;
    unsigned char nChainId;
    char unk0x04C[0x1A8 - 0x04C];
};

struct D2HirelingTxt
{
    unsigned short wVersion;
    unsigned short pad0x02;
    int nId;
    int dwClass;
    int dwAct;
    int dwDifficulty;
    int dwSeller;
    char unk0x018[0x114 - 0x018];
    unsigned short wNameFirst;
    unsigned short wNameLast;
};

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
void __fastcall DATATBLS_LoadMonStats2Txt(void* hArchive); // 0x006571A0
void __fastcall DATATBLS_LoadMonPropTxt(void* hArchive); // 0x00658720
void __fastcall DATATBLS_LoadMonSoundsTxt(void* hArchive); // 0x00656930
void __fastcall DATATBLS_LoadMonSeqTxt(void* hArchive); // 0x00659C60
void __fastcall DATATBLS_LoadMonStatsTxt(void* hArchive); // 0x00651210
void __fastcall DATATBLS_LoadMonUModTxt(void* hArchive); // 0x00655030
void __fastcall DATATBLS_LoadSuperUniquesTxt(void* hArchive); // 0x006552E0
void __fastcall DATATBLS_LoadMonPresetTxt(void* hArchive); // 0x00659A10
void __fastcall DATATBLS_LoadHirelingTxt(void* hArchive); // 0x00655720
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
void* __fastcall sub_0040B4B0(void* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0); // 0x0040B4B0
void __stdcall DATATBLS_UnloadBin(void* pBinFile); // 0x006125C0
int __fastcall sub_006117B0(const char* szKey); // 0x006117B0
void __cdecl DATATBLS_CreateItemTypeTreasureClasses(); // 0x006541C0
void __stdcall sub_006547D0(void* hArchive); // 0x006547D0

struct D2MonPresetTxt
{
    unsigned char nAct;
    unsigned char nType;
    unsigned short nIndex;
};

extern int gnTreasureClassEx; // 0x0096C5F0
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
    DATATBLS_LoadHirelingTxt(hArchive);
    DATATBLS_LoadNpcTxt(hArchive);
    DATATBLS_LoadMonEquipTxt(hArchive);
}

int gnTreasureClassEx; // 0x0096C5F0

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

#include "gen/data/Source/D2Common/DATATBLS/MonsterTbls_006510C0.inc"

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
