#include "D2LevelIds.h"
#include "D2Common.h"
#include "D2DataTbls.h"
#include "D2Records.h"
#include "D2Unicode.h"

struct Act;
struct D2DrlgActStrc;
struct Environment;
struct D2DrlgEnvironmentStrc;
struct D2EnvironmentCycleStrc;
struct Unicode;
struct D2BinFieldStrc;
struct D2LevelsTxt;

struct Environment { char pad[0x28]; int timeFields[2]; };

Environment* __fastcall sub_0061AA60(Act*); // 0x0061AA60

enum { TIME_RATE_FIELD = 0 };

struct D2DrlgEnvironmentStrc
{
    int nCycleIndex;
    int nPeriodOfDay;
    int nTicks;
    int nIntensity;
    unsigned int dwInitTick;
    int unk0x14;
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    unsigned char unk0x1B;
    float fCos;
    float fLast;
    float fSin;
    int nTimeRate;
    int nTimeRateIndex;
    int bEclipse;
    int nPrev;
};

struct D2EnvironmentCycleStrc
{
    int nTicksBegin;
    int nPeriodOfDay;
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    unsigned char unk0x0B;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" __declspec(dllimport) unsigned int __stdcall GetTickCount(); // 0x006CC260
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
D2DrlgEnvironmentStrc* __fastcall DUNGEON_GetEnvironmentFromAct(D2DrlgActStrc* pAct); // 0x0061AA60
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
extern D2EnvironmentCycleStrc gNormalEnvironmentCycle[]; // 0x007443F0
extern D2EnvironmentCycleStrc gAct4EnvironmentCycle[]; // 0x00744438
extern D2EnvironmentCycleStrc gEclipseEnvironmentCycle[]; // 0x00744480
static void ENVIRONMENT_UpdateLightIntensity(D2DrlgEnvironmentStrc* pEnvironment, int nLevelId, int nAct); // 0x0061BB80

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

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

enum
{
    TXTFIELD_NONE = 0,
    TXTFIELD_ASCII = 1,
    TXTFIELD_DWORD = 2,
    TXTFIELD_WORD = 3,
    TXTFIELD_BYTE = 4,
    TXTFIELD_NAMETOWORD = 20,
};
extern D2DataTablesStrc sgtDataTables; // 0x0096BC30
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize); // 0x006122F0
const wchar_t* __fastcall D2LANG_GetStringByReferenceString(const char* szKey); // 0x00524E20

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
        { "mon1", TXTFIELD_NAMETOWORD, 0, 54, &sgtDataTables.pMonStatsLinker },
        { "mon2", TXTFIELD_NAMETOWORD, 0, 56, &sgtDataTables.pMonStatsLinker },
        { "mon3", TXTFIELD_NAMETOWORD, 0, 58, &sgtDataTables.pMonStatsLinker },
        { "mon4", TXTFIELD_NAMETOWORD, 0, 60, &sgtDataTables.pMonStatsLinker },
        { "mon5", TXTFIELD_NAMETOWORD, 0, 62, &sgtDataTables.pMonStatsLinker },
        { "mon6", TXTFIELD_NAMETOWORD, 0, 64, &sgtDataTables.pMonStatsLinker },
        { "mon7", TXTFIELD_NAMETOWORD, 0, 66, &sgtDataTables.pMonStatsLinker },
        { "mon8", TXTFIELD_NAMETOWORD, 0, 68, &sgtDataTables.pMonStatsLinker },
        { "mon9", TXTFIELD_NAMETOWORD, 0, 70, &sgtDataTables.pMonStatsLinker },
        { "mon10", TXTFIELD_NAMETOWORD, 0, 72, &sgtDataTables.pMonStatsLinker },
        { "mon11", TXTFIELD_NAMETOWORD, 0, 74, &sgtDataTables.pMonStatsLinker },
        { "mon12", TXTFIELD_NAMETOWORD, 0, 76, &sgtDataTables.pMonStatsLinker },
        { "mon13", TXTFIELD_NAMETOWORD, 0, 78, &sgtDataTables.pMonStatsLinker },
        { "mon14", TXTFIELD_NAMETOWORD, 0, 80, &sgtDataTables.pMonStatsLinker },
        { "mon15", TXTFIELD_NAMETOWORD, 0, 82, &sgtDataTables.pMonStatsLinker },
        { "mon16", TXTFIELD_NAMETOWORD, 0, 84, &sgtDataTables.pMonStatsLinker },
        { "mon17", TXTFIELD_NAMETOWORD, 0, 86, &sgtDataTables.pMonStatsLinker },
        { "mon18", TXTFIELD_NAMETOWORD, 0, 88, &sgtDataTables.pMonStatsLinker },
        { "mon19", TXTFIELD_NAMETOWORD, 0, 90, &sgtDataTables.pMonStatsLinker },
        { "mon20", TXTFIELD_NAMETOWORD, 0, 92, &sgtDataTables.pMonStatsLinker },
        { "mon21", TXTFIELD_NAMETOWORD, 0, 94, &sgtDataTables.pMonStatsLinker },
        { "mon22", TXTFIELD_NAMETOWORD, 0, 96, &sgtDataTables.pMonStatsLinker },
        { "mon23", TXTFIELD_NAMETOWORD, 0, 98, &sgtDataTables.pMonStatsLinker },
        { "mon24", TXTFIELD_NAMETOWORD, 0, 100, &sgtDataTables.pMonStatsLinker },
        { "mon25", TXTFIELD_NAMETOWORD, 0, 102, &sgtDataTables.pMonStatsLinker },
        { "rangedspawn", TXTFIELD_BYTE, 0, 49, 0 },
        { "nmon1", TXTFIELD_NAMETOWORD, 0, 104, &sgtDataTables.pMonStatsLinker },
        { "nmon2", TXTFIELD_NAMETOWORD, 0, 106, &sgtDataTables.pMonStatsLinker },
        { "nmon3", TXTFIELD_NAMETOWORD, 0, 108, &sgtDataTables.pMonStatsLinker },
        { "nmon4", TXTFIELD_NAMETOWORD, 0, 110, &sgtDataTables.pMonStatsLinker },
        { "nmon5", TXTFIELD_NAMETOWORD, 0, 112, &sgtDataTables.pMonStatsLinker },
        { "nmon6", TXTFIELD_NAMETOWORD, 0, 114, &sgtDataTables.pMonStatsLinker },
        { "nmon7", TXTFIELD_NAMETOWORD, 0, 116, &sgtDataTables.pMonStatsLinker },
        { "nmon8", TXTFIELD_NAMETOWORD, 0, 118, &sgtDataTables.pMonStatsLinker },
        { "nmon9", TXTFIELD_NAMETOWORD, 0, 120, &sgtDataTables.pMonStatsLinker },
        { "nmon10", TXTFIELD_NAMETOWORD, 0, 122, &sgtDataTables.pMonStatsLinker },
        { "nmon11", TXTFIELD_NAMETOWORD, 0, 124, &sgtDataTables.pMonStatsLinker },
        { "nmon12", TXTFIELD_NAMETOWORD, 0, 126, &sgtDataTables.pMonStatsLinker },
        { "nmon13", TXTFIELD_NAMETOWORD, 0, 128, &sgtDataTables.pMonStatsLinker },
        { "nmon14", TXTFIELD_NAMETOWORD, 0, 130, &sgtDataTables.pMonStatsLinker },
        { "nmon15", TXTFIELD_NAMETOWORD, 0, 132, &sgtDataTables.pMonStatsLinker },
        { "nmon16", TXTFIELD_NAMETOWORD, 0, 134, &sgtDataTables.pMonStatsLinker },
        { "nmon17", TXTFIELD_NAMETOWORD, 0, 136, &sgtDataTables.pMonStatsLinker },
        { "nmon18", TXTFIELD_NAMETOWORD, 0, 138, &sgtDataTables.pMonStatsLinker },
        { "nmon19", TXTFIELD_NAMETOWORD, 0, 140, &sgtDataTables.pMonStatsLinker },
        { "nmon20", TXTFIELD_NAMETOWORD, 0, 142, &sgtDataTables.pMonStatsLinker },
        { "nmon21", TXTFIELD_NAMETOWORD, 0, 144, &sgtDataTables.pMonStatsLinker },
        { "nmon22", TXTFIELD_NAMETOWORD, 0, 146, &sgtDataTables.pMonStatsLinker },
        { "nmon23", TXTFIELD_NAMETOWORD, 0, 148, &sgtDataTables.pMonStatsLinker },
        { "nmon24", TXTFIELD_NAMETOWORD, 0, 150, &sgtDataTables.pMonStatsLinker },
        { "nmon25", TXTFIELD_NAMETOWORD, 0, 152, &sgtDataTables.pMonStatsLinker },
        { "umon1", TXTFIELD_NAMETOWORD, 0, 154, &sgtDataTables.pMonStatsLinker },
        { "umon2", TXTFIELD_NAMETOWORD, 0, 156, &sgtDataTables.pMonStatsLinker },
        { "umon3", TXTFIELD_NAMETOWORD, 0, 158, &sgtDataTables.pMonStatsLinker },
        { "umon4", TXTFIELD_NAMETOWORD, 0, 160, &sgtDataTables.pMonStatsLinker },
        { "umon5", TXTFIELD_NAMETOWORD, 0, 162, &sgtDataTables.pMonStatsLinker },
        { "umon6", TXTFIELD_NAMETOWORD, 0, 164, &sgtDataTables.pMonStatsLinker },
        { "umon7", TXTFIELD_NAMETOWORD, 0, 166, &sgtDataTables.pMonStatsLinker },
        { "umon8", TXTFIELD_NAMETOWORD, 0, 168, &sgtDataTables.pMonStatsLinker },
        { "umon9", TXTFIELD_NAMETOWORD, 0, 170, &sgtDataTables.pMonStatsLinker },
        { "umon10", TXTFIELD_NAMETOWORD, 0, 172, &sgtDataTables.pMonStatsLinker },
        { "umon11", TXTFIELD_NAMETOWORD, 0, 174, &sgtDataTables.pMonStatsLinker },
        { "umon12", TXTFIELD_NAMETOWORD, 0, 176, &sgtDataTables.pMonStatsLinker },
        { "umon13", TXTFIELD_NAMETOWORD, 0, 178, &sgtDataTables.pMonStatsLinker },
        { "umon14", TXTFIELD_NAMETOWORD, 0, 180, &sgtDataTables.pMonStatsLinker },
        { "umon15", TXTFIELD_NAMETOWORD, 0, 182, &sgtDataTables.pMonStatsLinker },
        { "umon16", TXTFIELD_NAMETOWORD, 0, 184, &sgtDataTables.pMonStatsLinker },
        { "umon17", TXTFIELD_NAMETOWORD, 0, 186, &sgtDataTables.pMonStatsLinker },
        { "umon18", TXTFIELD_NAMETOWORD, 0, 188, &sgtDataTables.pMonStatsLinker },
        { "umon19", TXTFIELD_NAMETOWORD, 0, 190, &sgtDataTables.pMonStatsLinker },
        { "umon20", TXTFIELD_NAMETOWORD, 0, 192, &sgtDataTables.pMonStatsLinker },
        { "umon21", TXTFIELD_NAMETOWORD, 0, 194, &sgtDataTables.pMonStatsLinker },
        { "umon22", TXTFIELD_NAMETOWORD, 0, 196, &sgtDataTables.pMonStatsLinker },
        { "umon23", TXTFIELD_NAMETOWORD, 0, 198, &sgtDataTables.pMonStatsLinker },
        { "umon24", TXTFIELD_NAMETOWORD, 0, 200, &sgtDataTables.pMonStatsLinker },
        { "umon25", TXTFIELD_NAMETOWORD, 0, 202, &sgtDataTables.pMonStatsLinker },
        { "cmon1", TXTFIELD_NAMETOWORD, 0, 204, &sgtDataTables.pMonStatsLinker },
        { "cmon2", TXTFIELD_NAMETOWORD, 0, 206, &sgtDataTables.pMonStatsLinker },
        { "cmon3", TXTFIELD_NAMETOWORD, 0, 208, &sgtDataTables.pMonStatsLinker },
        { "cmon4", TXTFIELD_NAMETOWORD, 0, 210, &sgtDataTables.pMonStatsLinker },
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

    sgtDataTables.pLevelsTxt = (D2LevelsTxt*)DATATBLS_CompileTxt(hArchive, "levels", pTbl, &sgtDataTables.nLevelsTxtRecordCount, sizeof(D2LevelsTxt));

    D2_ASSERT(sgtDataTables.nLevelsTxtRecordCount < 1024, 199);

    for (int i = 0; i < sgtDataTables.nLevelsTxtRecordCount; ++i)
    {
        D2LevelsTxt* pLevelsTxtRecord = &sgtDataTables.pLevelsTxt[i];

        memset(pLevelsTxtRecord->wszLevelName, 0, 80);
        memset(pLevelsTxtRecord->wszLevelWarp, 0, 80);

        Unicode::strncpy(pLevelsTxtRecord->wszLevelName, (const Unicode*)D2LANG_GetStringByReferenceString(pLevelsTxtRecord->szLevelName), 40);
        pLevelsTxtRecord->wszLevelName[39].wChar = 0;

        Unicode::strncpy(pLevelsTxtRecord->wszLevelWarp, (const Unicode*)D2LANG_GetStringByReferenceString(pLevelsTxtRecord->szLevelWarp), 40);
        pLevelsTxtRecord->wszLevelWarp[39].wChar = 0;

        for (int j = 0; j < sgtDataTables.nLevelsTxtRecordCount; ++j)
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
