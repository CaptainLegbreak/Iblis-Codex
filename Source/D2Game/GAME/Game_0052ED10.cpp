#include "D2Game.h"
#include "D2GameTypes.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }


struct D2GameStrc
{
    char unk0x0000[0x18];
    D2CriticalSectionStrc* lpCriticalSection;
    void* pMemoryPool;
    char unk0x0020[0x8];
    unsigned short nGameId;
    char szGameName[16];
    char szGamePassword[16];
    char szGameDesc[32];
    char unk0x006A;
    unsigned char nArenaTemplate;
    unsigned char nMaxLevelDifference;
    unsigned char nDifficulty;
    unsigned char nMaxPlayers;
    char unk0x006F[0xD];
    unsigned int dwInitSeed;
    char unk0x0080[0xC];
    unsigned int nClients;
    unsigned int dwLastUsedUnitGUID[6];
    int dwGameFrame;
    unsigned int nFrameRate;
    char unk0x00B0[0x1070];
    D2UnitStrc* pUnitList[5][128];
    char unk0x1B20[0x250];
    unsigned int dwPathTypesCount[17];
    unsigned int nTotalPathTypesCount;
    char unk0x1DB8[0x4];
    unsigned int nCreationTimeMs_Or_CPUTargetRatioFP10;
};

struct D2GameInfoStrc
{
    int nGameId;
    unsigned int nInitSeed;
    int nClients;
    int nPlayers;
    int nMonsters;
    int nObjects;
    int nItems;
    int nMissiles;
    int nUniqueItems;
    int nNPCs;
    unsigned int dwLastUsedUnitGUID[6];
    int nPathTowardPct;
    int nPathClockPct;
    int nPathCounterPct;
    int nPathAStarPct;
    int nPathFoWallPct;
    int nPathTotalCalls;
    int nFrames;
    int nTime;
    int nFrameRate;
    char szGameName[16];
    char szGamePassword[16];
    char szGameDescription[32];
    unsigned char nArenaTemplate;
    unsigned char nMaxLevelDifference;
    unsigned char nMaxPlayers;
    unsigned char padding0xA7;
    unsigned int nArenaFlags;
    void* pMemoryPool;
};
#define PATHTYPE_ASTAR 1
#define PATHTYPE_TOWARD 2
#define PATHTYPE_MON_CIRCLE_CW 5
#define PATHTYPE_MON_CIRCLE_CCW 6

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);                               // 0x00681EF0
extern D2CriticalSectionStrc gCriticalSection_6FD45800;                                                     // 0x00882D18
extern int gnGamesGUIDs_6FD447F8[1024];                                                                     // 0x00882D38
D2GameStrc* __fastcall GAME_LockGame(int nGameGUID);                                                        // 0x0052E860
D2UnitStrc* __fastcall SUNIT_GetNextUnitFromList(D2UnitStrc* pUnit);                                        // 0x00552DB0
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
unsigned int __fastcall ARENA_GetFlags(D2GameStrc* pGame);                                                  // 0x0053FD40

static int sub_0052DBC0_CountUnitsInLists(D2UnitStrc** pUnitLists)
{
    int nUnits = 0;
    for (int i = 0; i < 128; ++i)
    {
        if (D2UnitStrc* pFirstUnit = pUnitLists[i])
        {
            ++nUnits;
            for (D2UnitStrc* pUnit = SUNIT_GetNextUnitFromList(pFirstUnit); pUnit; pUnit = SUNIT_GetNextUnitFromList(pUnit))
            {
                ++nUnits;
            }
        }
    }
    return nUnits;
}

// 0x0052ED10
int __stdcall GAME_GetGameInformation(unsigned short nGameId, D2GameInfoStrc* pGameInfo)
{
    int nGUID = 0;
    EnterCriticalSection(&gCriticalSection_6FD45800);
    if (gnGamesGUIDs_6FD447F8[nGameId - 1] && gnGamesGUIDs_6FD447F8[nGameId - 1] != D2GameReservedSlotHandle)
    {
        nGUID = gnGamesGUIDs_6FD447F8[nGameId - 1];
    }
    LeaveCriticalSection(&gCriticalSection_6FD45800);

    D2GameStrc* ptGame = GAME_LockGame(nGUID);
    if (!ptGame)
    {
        return 0;
    }

    pGameInfo->nGameId = ptGame->nGameId;
    pGameInfo->nInitSeed = ptGame->dwInitSeed;
    pGameInfo->nClients = ptGame->nClients;
    pGameInfo->dwLastUsedUnitGUID[0] = ptGame->dwLastUsedUnitGUID[0];
    pGameInfo->dwLastUsedUnitGUID[1] = ptGame->dwLastUsedUnitGUID[1];
    pGameInfo->dwLastUsedUnitGUID[2] = ptGame->dwLastUsedUnitGUID[2];
    pGameInfo->dwLastUsedUnitGUID[3] = ptGame->dwLastUsedUnitGUID[3];
    pGameInfo->dwLastUsedUnitGUID[4] = ptGame->dwLastUsedUnitGUID[4];
    pGameInfo->dwLastUsedUnitGUID[5] = ptGame->dwLastUsedUnitGUID[5];

    pGameInfo->nPlayers = sub_0052DBC0_CountUnitsInLists(ptGame->pUnitList[0]);
    pGameInfo->nMonsters = sub_0052DBC0_CountUnitsInLists(ptGame->pUnitList[1]);
    pGameInfo->nObjects = sub_0052DBC0_CountUnitsInLists(ptGame->pUnitList[2]);
    pGameInfo->nItems = sub_0052DBC0_CountUnitsInLists(ptGame->pUnitList[3]);
    pGameInfo->nMissiles = sub_0052DBC0_CountUnitsInLists(ptGame->pUnitList[4]);

    if (ptGame->nTotalPathTypesCount)
    {
        pGameInfo->nPathTowardPct = 100 * ptGame->dwPathTypesCount[PATHTYPE_TOWARD] / ptGame->nTotalPathTypesCount;
        pGameInfo->nPathClockPct = 100 * ptGame->dwPathTypesCount[PATHTYPE_MON_CIRCLE_CW] / ptGame->nTotalPathTypesCount;
        pGameInfo->nPathCounterPct = 100 * ptGame->dwPathTypesCount[PATHTYPE_MON_CIRCLE_CCW] / ptGame->nTotalPathTypesCount;
        pGameInfo->nPathAStarPct = 100 * ptGame->dwPathTypesCount[PATHTYPE_ASTAR] / ptGame->nTotalPathTypesCount;
        pGameInfo->nPathFoWallPct = 100 * ptGame->dwPathTypesCount[PATHTYPE_WALL_FOLLOW] / ptGame->nTotalPathTypesCount;
        pGameInfo->nPathTotalCalls = ptGame->nTotalPathTypesCount;
        if (ptGame->nTotalPathTypesCount > 200 && pGameInfo->nPathTotalCalls)
        {
            memset(ptGame->dwPathTypesCount, 0, sizeof(ptGame->dwPathTypesCount) + sizeof(ptGame->nTotalPathTypesCount));
        }
    }

    SStrCopy(pGameInfo->szGameName, ptGame->szGameName, 16);
    pGameInfo->nTime = (GetTickCount() - ptGame->nCreationTimeMs_Or_CPUTargetRatioFP10) / 1000 / 60;
    pGameInfo->nFrames = ptGame->dwGameFrame / 100;
    pGameInfo->nFrameRate = ptGame->nFrameRate;
    pGameInfo->nArenaTemplate = ptGame->nArenaTemplate;
    pGameInfo->nMaxLevelDifference = ptGame->nMaxLevelDifference;
    pGameInfo->nMaxPlayers = ptGame->nMaxPlayers;
    SStrCopy(pGameInfo->szGamePassword, ptGame->szGamePassword, 16);
    SStrCopy(pGameInfo->szGameDescription, ptGame->szGameDesc, 32);
    pGameInfo->nArenaFlags = ARENA_GetFlags(ptGame);
    pGameInfo->pMemoryPool = ptGame->pMemoryPool;

    D2_ASSERT(ptGame->lpCriticalSection, 4196);
    LeaveCriticalSection(ptGame->lpCriticalSection);
    return 1;
}

int __stdcall GAME_GetPlayerUnitsCount(unsigned short nGameId)
{
    int nGUID = 0;
    EnterCriticalSection(&gCriticalSection_6FD45800);
    if (gnGamesGUIDs_6FD447F8[nGameId - 1] && gnGamesGUIDs_6FD447F8[nGameId - 1] != D2GameReservedSlotHandle)
    {
        nGUID = gnGamesGUIDs_6FD447F8[nGameId - 1];
    }
    LeaveCriticalSection(&gCriticalSection_6FD45800);

    D2GameStrc* pGame = GAME_LockGame(nGUID);
    int nUnits = 0;
    if (pGame)
    {
        nUnits = sub_0052DBC0_CountUnitsInLists(pGame->pUnitList[0]);
        D2_ASSERT(pGame->lpCriticalSection, 4196);
        LeaveCriticalSection(pGame->lpCriticalSection);
    }
    return nUnits;
}
