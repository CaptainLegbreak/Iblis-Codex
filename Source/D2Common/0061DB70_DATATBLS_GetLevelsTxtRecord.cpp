struct D2LevelsTxt
{
    char unk0x00[5 + 0x0];
    unsigned char nRain;
    unsigned char nMud;
    unsigned char nNoPer;
    char unk0x08[8];
    short wMonLvl[3];
    short wMonLvlEx[3];
    char unk0x1C[0x220 - 0x1C - 0x0];
};

struct D2LevelDefBin
{
    char unk0x00[0x9C];
};

struct D2LvlTypesTxt
{
    char szFile[32][60];
    unsigned char nAct;
    char pad0x781[0x788 - 0x780 - 1];
};

struct D2LvlPrestTxt
{
    char unk0x00[0x4];
    int dwLevelId;
    char unk0x08[0x1B0 - 0x4 - 4];
};

struct D2LvlWarpTxt
{
    int dwLevelId;
    char unk0x04[0x2C - 4];
    char szDirection[4];
};

struct D2LvlMazeTxt
{
    int dwLevelId;
    char unk0x04[0x1C - 4];
};

struct D2LvlSubTxt
{
    char unk0x00[0x15C];
};

struct D2DrlgFileStrc;

struct D2DataTablesStrc
{
    char unk0x000[0xC58];
    D2LevelsTxt* pLevelsTxt;
    int nLevelsTxtRecordCount;
    char unk0xC60[0x8];
    int nLvlPrestTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
D2LevelDefBin* gpLevelDefBin;                                                                               // 0x0096C890
D2LvlPrestTxt* gpLvlPrestTxt;                                                                               // 0x0096C894
int* gpPortalLevels;                                                                                        // 0x0096C9F4
int gnPortalLevels;                                                                                         // 0x0096C9F8
D2LvlTypesTxt* gpLvlTypesTxt;                                                                               // 0x0096C9F0
D2LvlWarpTxt* gpLvlWarpTxt;                                                                                 // 0x0096CA00
extern int gnLvlWarpTxtRecordCount;                                                                         // 0x0096CA04
D2LvlMazeTxt* gpLvlMazeTxt;                                                                                 // 0x0096CA08
extern int gnLvlMazeTxtRecordCount;                                                                         // 0x0096CA0C
D2LvlSubTxt* gpLvlSubTxt;                                                                                   // 0x0096CA10
int gnLvlSubTxtRecordCount;                                                                                 // 0x0096CA14
int* gpLvlSubTypeStartIds;                                                                                  // 0x0096CA18
void* gppTileLibraryHash;                                                                                   // 0x0096CA1C
D2DrlgFileStrc** gppLvlPrestDrlgFiles;                                                                      // 0x0096CA20
D2DrlgFileStrc** gppLvlSubDrlgFiles;                                                                        // 0x0096CA24
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
void __stdcall DATATBLS_UnloadBin(void* pBinFile);                                                          // 0x006125C0
void __fastcall sub_0040B3C0(void* pMemory, const char* szFile, int nLine, int n0);                       // 0x0040B3C0
void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
void __fastcall DRLGPRESET_FreeDrlgFile(D2DrlgFileStrc** ppDrlgFile);                                       // 0x00668300
void __fastcall sub_00670630(D2LvlSubTxt* pLvlSubTxtRecord);                                 // 0x00670630
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);
#pragma intrinsic(strcpy)

#define LVL_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x0061DB70
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId)
{
    if (nLevelId > 0 && nLevelId < sgptDataTables->nLevelsTxtRecordCount)
    {
        return &sgptDataTables->pLevelsTxt[nLevelId];
    }

    return 0;
}

// 0x0061DBA0
unsigned char __stdcall DATATBLS_GetRainFromLevelsTxt(int nLevelId)
{
    if (nLevelId > 0 && nLevelId < sgptDataTables->nLevelsTxtRecordCount)
    {
        return sgptDataTables->pLevelsTxt[nLevelId].nRain;
    }

    return 0;
}

// 0x0061DBE0
unsigned char __stdcall DATATBLS_GetNoPerFromLevelsTxt(int nLevelId)
{
    if (nLevelId > 0 && nLevelId < sgptDataTables->nLevelsTxtRecordCount)
    {
        return sgptDataTables->pLevelsTxt[nLevelId].nNoPer;
    }

    return 0;
}

// 0x0061DC20
unsigned char __stdcall DATATBLS_GetMudFromLevelsTxt(int nLevelId)
{
    if (nLevelId > 0 && nLevelId < sgptDataTables->nLevelsTxtRecordCount)
    {
        return sgptDataTables->pLevelsTxt[nLevelId].nMud;
    }

    return 0;
}

// 0x0061DC60
void __fastcall DATATBLS_UnloadLevelsTxt()
{
    if (sgptDataTables->pLevelsTxt)
    {
        DATATBLS_UnloadBin(sgptDataTables->pLevelsTxt);
    }
    sgptDataTables->nLevelsTxtRecordCount = 0;
}

// 0x0061DCA0
int __stdcall DATATBLS_GetMonsterLevelInArea(int nLevelId, unsigned char nDifficulty, int bExpansion)
{
    if (nDifficulty >= 3)
    {
        return 1;
    }

    D2LevelsTxt* pLevelsTxtRecord = DATATBLS_GetLevelsTxtRecord(nLevelId);
    if (!pLevelsTxtRecord)
    {
        return 1;
    }

    if (bExpansion)
    {
        return pLevelsTxtRecord->wMonLvlEx[nDifficulty];
    }

    return pLevelsTxtRecord->wMonLvl[nDifficulty];
}

// 0x0061DDF0
int* __fastcall DATATBLS_GetPortalLevels(int* pnPortalLevels)
{
    *pnPortalLevels = gnPortalLevels;
    return gpPortalLevels;
}

// 0x0061E440
void __fastcall DATATBLS_UnloadLevelDefsBin()
{
    if (gpLevelDefBin)
    {
        DATATBLS_UnloadBin(gpLevelDefBin);
    }

    if (gpPortalLevels)
    {
        sub_0040B480(0, gpPortalLevels, ".\\DATATBLS\\LvlTbls.cpp", 473, 0);
    }
}

// 0x0061E470
D2LevelDefBin* __fastcall DATATBLS_GetLevelDefRecord(int nLevelId)
{
    if (nLevelId >= 0 && nLevelId < sgptDataTables->nLevelsTxtRecordCount)
    {
        return &gpLevelDefBin[nLevelId];
    }

    return 0;
}

// 0x0061EA90
void __fastcall DATATBLS_UnloadLevelTypesTxt()
{
    DATATBLS_UnloadBin(gpLvlTypesTxt);
}

// 0x0061EAA0
D2LvlTypesTxt* __stdcall DATATBLS_GetLevelTypesTxtRecord(int nLevelType)
{
    LVL_ASSERT(gpLvlTypesTxt, 593);
    return &gpLvlTypesTxt[nLevelType];
}

// 0x0061EAE0
int __stdcall DATATBLS_CheckActInLevelTypesTxt(int nLevelType, unsigned char nAct)
{
    D2LvlTypesTxt* pLevelTypesTxtRecord = DATATBLS_GetLevelTypesTxtRecord(nLevelType);

    return pLevelTypesTxtRecord != 0 && pLevelTypesTxtRecord->nAct == nAct;
}

// 0x0061EB40
void __stdcall DATATBLS_GetFileNameFromLevelTypeAndFileId(int nLevelType, int nFile, char* szFile)
{
    D2LvlTypesTxt* pLevelTypesTxtRecord = DATATBLS_GetLevelTypesTxtRecord(nLevelType);

    *szFile = 0;

    if (pLevelTypesTxtRecord && nFile < 32)
    {
        strcpy(szFile, pLevelTypesTxtRecord->szFile[nFile]);
    }
}

// 0x0061F030
void __fastcall DATATBLS_UnloadLvlPrestTxt()
{
    D2DrlgFileStrc** ppLvlPrestFiles = gppLvlPrestDrlgFiles;

    if (gppLvlPrestDrlgFiles)
    {
        for (int i = 0; i < 6 * sgptDataTables->nLvlPrestTxtRecordCount; ++i)
        {
            if (ppLvlPrestFiles[i])
            {
                DRLGPRESET_FreeDrlgFile(&ppLvlPrestFiles[i]);
                ppLvlPrestFiles = gppLvlPrestDrlgFiles;
            }
        }

        sub_0040B3C0(ppLvlPrestFiles, ".\\DATATBLS\\LvlTbls.cpp", 722, 0);
        gppLvlPrestDrlgFiles = 0;
    }

    if (gpLvlPrestTxt)
    {
        DATATBLS_UnloadBin(gpLvlPrestTxt);
    }
}

// 0x0061F0B0
D2LvlPrestTxt* __stdcall DATATBLS_GetLvlPrestTxtRecord(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nLvlPrestTxtRecordCount)
    {
        return &gpLvlPrestTxt[nId];
    }

    return 0;
}

// 0x0061F0E0
D2LvlPrestTxt* __fastcall DATATBLS_GetLvlPrestTxtRecordFromLevelId(int nLevelId)
{
    for (int i = 0; i < sgptDataTables->nLvlPrestTxtRecordCount; ++i)
    {
        if (gpLvlPrestTxt[i].dwLevelId == nLevelId)
        {
            return &gpLvlPrestTxt[i];
        }
    }

    return 0;
}

// 0x0061F300
void __fastcall DATATBLS_UnloadLvlWarpTxt()
{
    DATATBLS_UnloadBin(gpLvlWarpTxt);
}

// 0x0061F310
D2LvlWarpTxt* __fastcall DATATBLS_GetLvlWarpTxtRecordFromLevelIdAndDirection(int nLevelId, char szDirection)
{
    D2LvlWarpTxt* pLvlWarpTxtRecord = gpLvlWarpTxt;
    LVL_ASSERT(pLvlWarpTxtRecord, 811);

    for (int i = 0; i < gnLvlWarpTxtRecordCount; ++i)
    {
        if (pLvlWarpTxtRecord->dwLevelId == nLevelId)
        {
            if (szDirection == 'b' || pLvlWarpTxtRecord->szDirection[0] == 'b' || pLvlWarpTxtRecord->szDirection[0] == szDirection)
            {
                return pLvlWarpTxtRecord;
            }
        }
        ++pLvlWarpTxtRecord;
    }

    LVL_ASSERT(0, 826);
}

// 0x0061F480
void __fastcall DATATBLS_UnloadLvlMazeTxt()
{
    DATATBLS_UnloadBin(gpLvlMazeTxt);
}

// 0x0061F490
D2LvlMazeTxt* __fastcall DATATBLS_GetLvlMazeTxtRecordFromLevelId(int nLevelId)
{
    LVL_ASSERT(gpLvlMazeTxt, 867);

    for (int i = 0; i < gnLvlMazeTxtRecordCount; ++i)
    {
        if (gpLvlMazeTxt[i].dwLevelId == nLevelId)
        {
            return &gpLvlMazeTxt[i];
        }
    }

    LVL_ASSERT(0, 876);
}

// 0x0061F9C0
void __fastcall DATATBLS_UnloadLvlSubTxt()
{
    D2DrlgFileStrc** ppFiles = gppLvlSubDrlgFiles;

    if (gppLvlSubDrlgFiles)
    {
        for (int i = 0; i < gnLvlSubTxtRecordCount; ++i)
        {
            if (ppFiles[i])
            {
                DRLGPRESET_FreeDrlgFile(&ppFiles[i]);
                ppFiles = gppLvlSubDrlgFiles;
            }
        }

        sub_0040B3C0(ppFiles, ".\\DATATBLS\\LvlTbls.cpp", 984, 0);
        gppLvlSubDrlgFiles = 0;
    }

    if (gpLvlSubTxt)
    {
        for (int i = 0; i < gnLvlSubTxtRecordCount; ++i)
        {
            sub_00670630(&gpLvlSubTxt[i]);
        }

        DATATBLS_UnloadBin(gpLvlSubTxt);
        gpLvlSubTxt = 0;
    }

    if (gpLvlSubTypeStartIds)
    {
        sub_0040B480(0, gpLvlSubTypeStartIds, ".\\DATATBLS\\LvlTbls.cpp", 1000, 0);
        gpLvlSubTypeStartIds = 0;
    }
}

// 0x0061FA90
D2LvlSubTxt* __fastcall DATATBLS_GetLvlSubTxtRecord(int nSubType)
{
    LVL_ASSERT(nSubType >= 0, 1009);
    LVL_ASSERT(gpLvlSubTxt, 1010);
    LVL_ASSERT(gpLvlSubTypeStartIds, 1011);

    return &gpLvlSubTxt[gpLvlSubTypeStartIds[nSubType]];
}

// 0x0061FBF0
void __fastcall DATATBLS_FreeGlobalTileLibraryHash()
{
    if (gppTileLibraryHash)
    {
        sub_0040B480(0, gppTileLibraryHash, ".\\DATATBLS\\LvlTbls.cpp", 1082, 0);
    }
}
