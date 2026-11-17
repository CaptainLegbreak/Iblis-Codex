struct D2TxtLinkStrc;

struct Unicode
{
    unsigned short wChar;

    static Unicode* __fastcall strncpy(Unicode* dest, const Unicode* src, int count);                       // 0x00526790
};

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};

struct D2LevelsTxt
{
    unsigned short wLevelNo;
    unsigned char nPal;
    unsigned char nAct;
    unsigned char nTeleport;
    unsigned char nRain;
    unsigned char nMud;
    unsigned char nNoPer;
    unsigned char nIsInside;
    unsigned char nDrawEdges;
    unsigned short unk0x0A;
    unsigned int dwWarpDist;
    unsigned short wMonLvl[3];
    unsigned short wMonLvlEx[3];
    unsigned int dwMonDen[3];
    unsigned char nMonUMin[3];
    unsigned char nMonUMax[3];
    unsigned char nMonWndr;
    unsigned char nMonSpcWalk;
    unsigned char nQuest;
    unsigned char nRangedSpawn;
    unsigned char nNumMon;
    unsigned char nNumNormalMonsters;
    unsigned char nNumNightmareHellMonsters;
    unsigned char nNumUniqueMonsters;
    short wNormalMonsters[25];
    short wNightmareHellMonsters[25];
    short wUniqueMonsters[25];
    unsigned short wCMon[4];
    unsigned short wCPct[4];
    unsigned short wCAmt[4];
    unsigned char nWaypoint;
    unsigned char nObjGroup[8];
    unsigned char nObjPrb[8];
    char szLevelName[40];
    char szLevelWarp[40];
    char szEntryFile[40];
    unsigned char pad0x16D;
    Unicode wszLevelName[40];
    Unicode wszLevelWarp[40];
    unsigned short pad0x20E;
    unsigned int dwThemes;
    unsigned int dwFloorFilter;
    unsigned int dwBlankScreen;
    unsigned int dwSoundEnv;
};

struct D2DataTablesStrc
{
    char unk0x000[0xA7C];
    D2TxtLinkStrc* pMonStatsLinker;
    char unk0xA80[0x1D8];
    D2LevelsTxt* pLevelsTxt;
    int nLevelsTxtRecordCount;
};

enum
{
    TXTFIELD_NONE = 0,
    TXTFIELD_ASCII = 1,
    TXTFIELD_DWORD = 2,
    TXTFIELD_WORD = 3,
    TXTFIELD_BYTE = 4,
    TXTFIELD_NAMETOWORD = 20,
};

extern "C" const char gszTxtField_end[];                                                                    // 0x006D9060
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern D2DataTablesStrc gD2DataTables;                                                                      // 0x0096BC30

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize); // 0x006122F0
const wchar_t* __fastcall D2LANG_GetStringByReferenceString(const char* szKey);                                       // 0x00524E20
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x0061C540
void __fastcall DATATBLS_LoadLevelsTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "Id", TXTFIELD_BYTE, 0, 0, 0 },
        { "Pal", TXTFIELD_BYTE, 0, 2, 0 },
        { "Act", TXTFIELD_BYTE, 0, 3, 0 },
        { "Teleport", TXTFIELD_BYTE, 0, 4, 0 },
        { "Rain", TXTFIELD_BYTE, 0, 5, 0 },
        { "Mud", TXTFIELD_BYTE, 0, 6, 0 },
        { "NoPer", TXTFIELD_BYTE, 0, 7, 0 },
        { "IsInside", TXTFIELD_BYTE, 0, 8, 0 },
        { "DrawEdges", TXTFIELD_BYTE, 0, 9, 0 },
        { "WarpDist", TXTFIELD_DWORD, 0, 12, 0 },
        { "MonLvl1", TXTFIELD_WORD, 0, 16, 0 },
        { "MonLvl2", TXTFIELD_WORD, 0, 18, 0 },
        { "MonLvl3", TXTFIELD_WORD, 0, 20, 0 },
        { "MonLvl1Ex", TXTFIELD_WORD, 0, 22, 0 },
        { "MonLvl2Ex", TXTFIELD_WORD, 0, 24, 0 },
        { "MonLvl3Ex", TXTFIELD_WORD, 0, 26, 0 },
        { "MonDen", TXTFIELD_DWORD, 0, 28, 0 },
        { "MonDen(N)", TXTFIELD_DWORD, 0, 32, 0 },
        { "MonDen(H)", TXTFIELD_DWORD, 0, 36, 0 },
        { "MonUMin", TXTFIELD_BYTE, 0, 40, 0 },
        { "MonUMax", TXTFIELD_BYTE, 0, 43, 0 },
        { "MonUMin(N)", TXTFIELD_BYTE, 0, 41, 0 },
        { "MonUMax(N)", TXTFIELD_BYTE, 0, 44, 0 },
        { "MonUMin(H)", TXTFIELD_BYTE, 0, 42, 0 },
        { "MonUMax(H)", TXTFIELD_BYTE, 0, 45, 0 },
        { "MonWndr", TXTFIELD_BYTE, 0, 46, 0 },
        { "MonSpcWalk", TXTFIELD_BYTE, 0, 47, 0 },
        { "ObjGrp0", TXTFIELD_BYTE, 0, 229, 0 },
        { "ObjGrp1", TXTFIELD_BYTE, 0, 230, 0 },
        { "ObjGrp2", TXTFIELD_BYTE, 0, 231, 0 },
        { "ObjGrp3", TXTFIELD_BYTE, 0, 232, 0 },
        { "ObjGrp4", TXTFIELD_BYTE, 0, 233, 0 },
        { "ObjGrp5", TXTFIELD_BYTE, 0, 234, 0 },
        { "ObjGrp6", TXTFIELD_BYTE, 0, 235, 0 },
        { "ObjGrp7", TXTFIELD_BYTE, 0, 236, 0 },
        { "ObjPrb0", TXTFIELD_BYTE, 0, 237, 0 },
        { "ObjPrb1", TXTFIELD_BYTE, 0, 238, 0 },
        { "ObjPrb2", TXTFIELD_BYTE, 0, 239, 0 },
        { "ObjPrb3", TXTFIELD_BYTE, 0, 240, 0 },
        { "ObjPrb4", TXTFIELD_BYTE, 0, 241, 0 },
        { "ObjPrb5", TXTFIELD_BYTE, 0, 242, 0 },
        { "ObjPrb6", TXTFIELD_BYTE, 0, 243, 0 },
        { "ObjPrb7", TXTFIELD_BYTE, 0, 244, 0 },
        { "Quest", TXTFIELD_BYTE, 0, 48, 0 },
        { "NumMon", TXTFIELD_BYTE, 0, 50, 0 },
        { "mon1", TXTFIELD_NAMETOWORD, 0, 54, &gD2DataTables.pMonStatsLinker },
        { "mon2", TXTFIELD_NAMETOWORD, 0, 56, &gD2DataTables.pMonStatsLinker },
        { "mon3", TXTFIELD_NAMETOWORD, 0, 58, &gD2DataTables.pMonStatsLinker },
        { "mon4", TXTFIELD_NAMETOWORD, 0, 60, &gD2DataTables.pMonStatsLinker },
        { "mon5", TXTFIELD_NAMETOWORD, 0, 62, &gD2DataTables.pMonStatsLinker },
        { "mon6", TXTFIELD_NAMETOWORD, 0, 64, &gD2DataTables.pMonStatsLinker },
        { "mon7", TXTFIELD_NAMETOWORD, 0, 66, &gD2DataTables.pMonStatsLinker },
        { "mon8", TXTFIELD_NAMETOWORD, 0, 68, &gD2DataTables.pMonStatsLinker },
        { "mon9", TXTFIELD_NAMETOWORD, 0, 70, &gD2DataTables.pMonStatsLinker },
        { "mon10", TXTFIELD_NAMETOWORD, 0, 72, &gD2DataTables.pMonStatsLinker },
        { "mon11", TXTFIELD_NAMETOWORD, 0, 74, &gD2DataTables.pMonStatsLinker },
        { "mon12", TXTFIELD_NAMETOWORD, 0, 76, &gD2DataTables.pMonStatsLinker },
        { "mon13", TXTFIELD_NAMETOWORD, 0, 78, &gD2DataTables.pMonStatsLinker },
        { "mon14", TXTFIELD_NAMETOWORD, 0, 80, &gD2DataTables.pMonStatsLinker },
        { "mon15", TXTFIELD_NAMETOWORD, 0, 82, &gD2DataTables.pMonStatsLinker },
        { "mon16", TXTFIELD_NAMETOWORD, 0, 84, &gD2DataTables.pMonStatsLinker },
        { "mon17", TXTFIELD_NAMETOWORD, 0, 86, &gD2DataTables.pMonStatsLinker },
        { "mon18", TXTFIELD_NAMETOWORD, 0, 88, &gD2DataTables.pMonStatsLinker },
        { "mon19", TXTFIELD_NAMETOWORD, 0, 90, &gD2DataTables.pMonStatsLinker },
        { "mon20", TXTFIELD_NAMETOWORD, 0, 92, &gD2DataTables.pMonStatsLinker },
        { "mon21", TXTFIELD_NAMETOWORD, 0, 94, &gD2DataTables.pMonStatsLinker },
        { "mon22", TXTFIELD_NAMETOWORD, 0, 96, &gD2DataTables.pMonStatsLinker },
        { "mon23", TXTFIELD_NAMETOWORD, 0, 98, &gD2DataTables.pMonStatsLinker },
        { "mon24", TXTFIELD_NAMETOWORD, 0, 100, &gD2DataTables.pMonStatsLinker },
        { "mon25", TXTFIELD_NAMETOWORD, 0, 102, &gD2DataTables.pMonStatsLinker },
        { "rangedspawn", TXTFIELD_BYTE, 0, 49, 0 },
        { "nmon1", TXTFIELD_NAMETOWORD, 0, 104, &gD2DataTables.pMonStatsLinker },
        { "nmon2", TXTFIELD_NAMETOWORD, 0, 106, &gD2DataTables.pMonStatsLinker },
        { "nmon3", TXTFIELD_NAMETOWORD, 0, 108, &gD2DataTables.pMonStatsLinker },
        { "nmon4", TXTFIELD_NAMETOWORD, 0, 110, &gD2DataTables.pMonStatsLinker },
        { "nmon5", TXTFIELD_NAMETOWORD, 0, 112, &gD2DataTables.pMonStatsLinker },
        { "nmon6", TXTFIELD_NAMETOWORD, 0, 114, &gD2DataTables.pMonStatsLinker },
        { "nmon7", TXTFIELD_NAMETOWORD, 0, 116, &gD2DataTables.pMonStatsLinker },
        { "nmon8", TXTFIELD_NAMETOWORD, 0, 118, &gD2DataTables.pMonStatsLinker },
        { "nmon9", TXTFIELD_NAMETOWORD, 0, 120, &gD2DataTables.pMonStatsLinker },
        { "nmon10", TXTFIELD_NAMETOWORD, 0, 122, &gD2DataTables.pMonStatsLinker },
        { "nmon11", TXTFIELD_NAMETOWORD, 0, 124, &gD2DataTables.pMonStatsLinker },
        { "nmon12", TXTFIELD_NAMETOWORD, 0, 126, &gD2DataTables.pMonStatsLinker },
        { "nmon13", TXTFIELD_NAMETOWORD, 0, 128, &gD2DataTables.pMonStatsLinker },
        { "nmon14", TXTFIELD_NAMETOWORD, 0, 130, &gD2DataTables.pMonStatsLinker },
        { "nmon15", TXTFIELD_NAMETOWORD, 0, 132, &gD2DataTables.pMonStatsLinker },
        { "nmon16", TXTFIELD_NAMETOWORD, 0, 134, &gD2DataTables.pMonStatsLinker },
        { "nmon17", TXTFIELD_NAMETOWORD, 0, 136, &gD2DataTables.pMonStatsLinker },
        { "nmon18", TXTFIELD_NAMETOWORD, 0, 138, &gD2DataTables.pMonStatsLinker },
        { "nmon19", TXTFIELD_NAMETOWORD, 0, 140, &gD2DataTables.pMonStatsLinker },
        { "nmon20", TXTFIELD_NAMETOWORD, 0, 142, &gD2DataTables.pMonStatsLinker },
        { "nmon21", TXTFIELD_NAMETOWORD, 0, 144, &gD2DataTables.pMonStatsLinker },
        { "nmon22", TXTFIELD_NAMETOWORD, 0, 146, &gD2DataTables.pMonStatsLinker },
        { "nmon23", TXTFIELD_NAMETOWORD, 0, 148, &gD2DataTables.pMonStatsLinker },
        { "nmon24", TXTFIELD_NAMETOWORD, 0, 150, &gD2DataTables.pMonStatsLinker },
        { "nmon25", TXTFIELD_NAMETOWORD, 0, 152, &gD2DataTables.pMonStatsLinker },
        { "umon1", TXTFIELD_NAMETOWORD, 0, 154, &gD2DataTables.pMonStatsLinker },
        { "umon2", TXTFIELD_NAMETOWORD, 0, 156, &gD2DataTables.pMonStatsLinker },
        { "umon3", TXTFIELD_NAMETOWORD, 0, 158, &gD2DataTables.pMonStatsLinker },
        { "umon4", TXTFIELD_NAMETOWORD, 0, 160, &gD2DataTables.pMonStatsLinker },
        { "umon5", TXTFIELD_NAMETOWORD, 0, 162, &gD2DataTables.pMonStatsLinker },
        { "umon6", TXTFIELD_NAMETOWORD, 0, 164, &gD2DataTables.pMonStatsLinker },
        { "umon7", TXTFIELD_NAMETOWORD, 0, 166, &gD2DataTables.pMonStatsLinker },
        { "umon8", TXTFIELD_NAMETOWORD, 0, 168, &gD2DataTables.pMonStatsLinker },
        { "umon9", TXTFIELD_NAMETOWORD, 0, 170, &gD2DataTables.pMonStatsLinker },
        { "umon10", TXTFIELD_NAMETOWORD, 0, 172, &gD2DataTables.pMonStatsLinker },
        { "umon11", TXTFIELD_NAMETOWORD, 0, 174, &gD2DataTables.pMonStatsLinker },
        { "umon12", TXTFIELD_NAMETOWORD, 0, 176, &gD2DataTables.pMonStatsLinker },
        { "umon13", TXTFIELD_NAMETOWORD, 0, 178, &gD2DataTables.pMonStatsLinker },
        { "umon14", TXTFIELD_NAMETOWORD, 0, 180, &gD2DataTables.pMonStatsLinker },
        { "umon15", TXTFIELD_NAMETOWORD, 0, 182, &gD2DataTables.pMonStatsLinker },
        { "umon16", TXTFIELD_NAMETOWORD, 0, 184, &gD2DataTables.pMonStatsLinker },
        { "umon17", TXTFIELD_NAMETOWORD, 0, 186, &gD2DataTables.pMonStatsLinker },
        { "umon18", TXTFIELD_NAMETOWORD, 0, 188, &gD2DataTables.pMonStatsLinker },
        { "umon19", TXTFIELD_NAMETOWORD, 0, 190, &gD2DataTables.pMonStatsLinker },
        { "umon20", TXTFIELD_NAMETOWORD, 0, 192, &gD2DataTables.pMonStatsLinker },
        { "umon21", TXTFIELD_NAMETOWORD, 0, 194, &gD2DataTables.pMonStatsLinker },
        { "umon22", TXTFIELD_NAMETOWORD, 0, 196, &gD2DataTables.pMonStatsLinker },
        { "umon23", TXTFIELD_NAMETOWORD, 0, 198, &gD2DataTables.pMonStatsLinker },
        { "umon24", TXTFIELD_NAMETOWORD, 0, 200, &gD2DataTables.pMonStatsLinker },
        { "umon25", TXTFIELD_NAMETOWORD, 0, 202, &gD2DataTables.pMonStatsLinker },
        { "cmon1", TXTFIELD_NAMETOWORD, 0, 204, &gD2DataTables.pMonStatsLinker },
        { "cmon2", TXTFIELD_NAMETOWORD, 0, 206, &gD2DataTables.pMonStatsLinker },
        { "cmon3", TXTFIELD_NAMETOWORD, 0, 208, &gD2DataTables.pMonStatsLinker },
        { "cmon4", TXTFIELD_NAMETOWORD, 0, 210, &gD2DataTables.pMonStatsLinker },
        { "cpct1", TXTFIELD_WORD, 0, 212, 0 },
        { "cpct2", TXTFIELD_WORD, 0, 214, 0 },
        { "cpct3", TXTFIELD_WORD, 0, 216, 0 },
        { "cpct4", TXTFIELD_WORD, 0, 218, 0 },
        { "camt1", TXTFIELD_WORD, 0, 220, 0 },
        { "camt2", TXTFIELD_WORD, 0, 220, 0 },
        { "camt3", TXTFIELD_WORD, 0, 220, 0 },
        { "camt4", TXTFIELD_WORD, 0, 220, 0 },
        { "Themes", TXTFIELD_DWORD, 0, 528, 0 },
        { "FloorFilter", TXTFIELD_DWORD, 0, 532, 0 },
        { "BlankScreen", TXTFIELD_DWORD, 0, 536, 0 },
        { "SoundEnv", TXTFIELD_BYTE, 0, 540, 0 },
        { "Waypoint", TXTFIELD_BYTE, 0, 228, 0 },
        { "LevelName", TXTFIELD_ASCII, 39, 245, 0 },
        { "LevelWarp", TXTFIELD_ASCII, 39, 285, 0 },
        { "EntryFile", TXTFIELD_ASCII, 39, 325, 0 },
        { gszTxtField_end, TXTFIELD_NONE, 0, 0, 0 },
    };

    gD2DataTables.pLevelsTxt = (D2LevelsTxt*)DATATBLS_CompileTxt(hArchive, "levels", pTbl, &gD2DataTables.nLevelsTxtRecordCount, sizeof(D2LevelsTxt));

    D2_ASSERT(gD2DataTables.nLevelsTxtRecordCount < 1024, 199);

    for (int i = 0; i < gD2DataTables.nLevelsTxtRecordCount; ++i)
    {
        D2LevelsTxt* pLevelsTxtRecord = &gD2DataTables.pLevelsTxt[i];

        memset(pLevelsTxtRecord->wszLevelName, 0, 80);
        memset(pLevelsTxtRecord->wszLevelWarp, 0, 80);

        Unicode::strncpy(pLevelsTxtRecord->wszLevelName, (const Unicode*)D2LANG_GetStringByReferenceString(pLevelsTxtRecord->szLevelName), 40);
        pLevelsTxtRecord->wszLevelName[39].wChar = 0;

        Unicode::strncpy(pLevelsTxtRecord->wszLevelWarp, (const Unicode*)D2LANG_GetStringByReferenceString(pLevelsTxtRecord->szLevelWarp), 40);
        pLevelsTxtRecord->wszLevelWarp[39].wChar = 0;

        for (int j = 0; j < gD2DataTables.nLevelsTxtRecordCount; ++j)
        {
            int nMonsterCounter = 0;
            do
            {
                if (pLevelsTxtRecord->wNormalMonsters[nMonsterCounter] < 0)
                {
                    break;
                }
                ++nMonsterCounter;
            }
            while (nMonsterCounter < 25);
            pLevelsTxtRecord->nNumNormalMonsters = nMonsterCounter;

            nMonsterCounter = 0;
            do
            {
                if (pLevelsTxtRecord->wNightmareHellMonsters[nMonsterCounter] < 0)
                {
                    break;
                }
                ++nMonsterCounter;
            }
            while (nMonsterCounter < 25);
            pLevelsTxtRecord->nNumNightmareHellMonsters = nMonsterCounter;

            nMonsterCounter = 0;
            do
            {
                if (pLevelsTxtRecord->wUniqueMonsters[nMonsterCounter] < 0)
                {
                    break;
                }
                ++nMonsterCounter;
            }
            while (nMonsterCounter < 25);
            pLevelsTxtRecord->nNumUniqueMonsters = nMonsterCounter;
        }
    }
}
