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

extern D2MonStatsTxt* gpMonstatsTxt;                                                                        // 0x0096C6A8
extern int gnMonstatsTxtRecordCount;                                                                        // 0x0096C6B0
D2HirelingTxt* gpHirelingTxt;                                                                               // 0x0096BDD0
extern int gnHirelingTxtRecordCount;                                                                        // 0x0096BDD4
extern T006510C0 gUniqueNameTables;                                                            // 0x0096D488
extern "C" const char gszTxtField_end[];                                                                    // 0x006D9060
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize); // 0x006122F0
unsigned short __fastcall DATATBLS_GetStringIdFromReferenceString(char* szReference);                      // 0x006117B0
void __fastcall DATATBLS_LoadMonLvlTxt(void* hArchive);                                                     // 0x00659500
void __stdcall sub_0065A390(void* hArchive);                                                                // 0x0065A390
void __fastcall DATATBLS_LoadMonStats2Txt(void* hArchive);                                                  // 0x006571A0
void __fastcall DATATBLS_LoadMonPropTxt(void* hArchive);                                                    // 0x00658720
void __fastcall DATATBLS_LoadMonSoundsTxt(void* hArchive);                                                  // 0x00656930
void __fastcall DATATBLS_LoadMonSeqTxt(void* hArchive);                                                     // 0x00659C60
void __fastcall DATATBLS_LoadMonStatsTxt(void* hArchive);                                                   // 0x00651210
void __fastcall DATATBLS_LoadMonUModTxt(void* hArchive);                                                    // 0x00655030
void __fastcall DATATBLS_LoadSuperUniquesTxt(void* hArchive);                                               // 0x006552E0
void __fastcall DATATBLS_LoadMonPresetTxt(void* hArchive);                                                  // 0x00659A10
void __fastcall DATATBLS_LoadHirelingTxt(void* hArchive);                                                   // 0x00655720
void __fastcall DATATBLS_LoadNpcTxt(void* hArchive);                                                        // 0x00656620
void __fastcall DATATBLS_LoadMonEquipTxt(void* hArchive);                                                   // 0x00659E60

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
