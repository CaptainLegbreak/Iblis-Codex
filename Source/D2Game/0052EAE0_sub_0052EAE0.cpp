extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define D2GameReservedSlotHandle (-1)
#define UNIT_PLAYER 0
#define UNIT_MONSTER 1

struct D2CriticalSectionStrc
{
    void* DebugInfo;
    long LockCount;
    long RecursionCount;
    void* OwningThread;
    void* LockSemaphore;
    unsigned long SpinCount;
};

typedef int (__stdcall* FARPROC)();

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2GameStrc
{
    char unk0x00[0x18];
    D2CriticalSectionStrc* lpCriticalSection;
    char unk0x1C[0x54];
    int bExpansion;
    char f_74[0x8];
    unsigned int dwInitSeed;
    char unk0x80[0x10A0];
    D2UnitStrc* pUnitList[5][128];
};

struct D2GameStatisticsStrc
{
    int nGamesCount;
    int nActiveMonsters;
    int nInactiveMonsters;
    int nPlayersCount;
};

struct D2UnitInfoStrc
{
    char unk0x00[0x24];
    char szDescription[0x10];
};

typedef void (__fastcall* UnitDescriptionFunction)(char* szDescription, int nClassId);

D2GameStrc* __fastcall GAME_LockGame(int nGameGUID);                                                        // 0x0052E860
D2UnitStrc* __fastcall SUNIT_GetNextUnitFromList(D2UnitStrc* pUnit);                                        // 0x00552DB0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
void __fastcall SUNIT_FillUnitInfo(D2UnitStrc* pUnit, D2UnitInfoStrc* pUnitInfo);                           // 0x00553F30

extern UnitDescriptionFunction gpfGetDescription_6FD2CA64[5];                                               // 0x0073107C
D2CriticalSectionStrc gCriticalSection_6FD45800;                                                            // 0x00882D18
D2GameStrc* gpGame_6FD457FC;                                                                                // 0x00882D34
extern int gnGamesGUIDs_6FD447F8[1024];                                                                     // 0x00882D38

// 0x0052EAE0
int __stdcall sub_0052EAE0()
{
    int nExpansionGames = 0;
    for (int i = 0; i < 1024; ++i)
    {
        if (gnGamesGUIDs_6FD447F8[i] && gnGamesGUIDs_6FD447F8[i] != D2GameReservedSlotHandle)
        {
            if (D2GameStrc* pGame = GAME_LockGame(gnGamesGUIDs_6FD447F8[i]))
            {
                if (pGame->bExpansion)
                {
                    ++nExpansionGames;
                }
                D2_ASSERT(pGame->lpCriticalSection, 4196);
                LeaveCriticalSection(pGame->lpCriticalSection);
            }
        }
    }
    return nExpansionGames;
}

// 0x0052F2C0
int __stdcall sub_0052F2C0(unsigned short nGameId, int nMaxCount, D2UnitInfoStrc* pUnitInfo, int* pUnitType, int* pUnitGUID)
{
    int nGUID = 0;
    EnterCriticalSection(&gCriticalSection_6FD45800);
    if (gnGamesGUIDs_6FD447F8[nGameId - 1] && gnGamesGUIDs_6FD447F8[nGameId - 1] != D2GameReservedSlotHandle)
    {
        nGUID = gnGamesGUIDs_6FD447F8[nGameId - 1];
    }
    LeaveCriticalSection(&gCriticalSection_6FD45800);

    D2GameStrc* pGame = GAME_LockGame(nGUID);
    int nUnitInfoCount = 0;
    if (!pGame)
    {
        return 0;
    }

    {
        for (int i = 0; i < nMaxCount; ++i)
        {
            D2UnitStrc* pUnit = SUNIT_GetServerUnit(pGame, pUnitType[i], pUnitGUID[i]);
            if (pUnit)
            {
                SUNIT_FillUnitInfo(pUnit, &pUnitInfo[nUnitInfoCount]);

                if (pUnitType[i])
                {
                    D2_ASSERT(!IsBadCodePtr((FARPROC)gpfGetDescription_6FD2CA64[pUnitType[i]]), 0x1472);
                    gpfGetDescription_6FD2CA64[pUnitType[i]](pUnitInfo[nUnitInfoCount].szDescription, pUnit->dwClassId);
                }

                ++nUnitInfoCount;
            }
        }

        D2_ASSERT(pGame->lpCriticalSection, 4196);
        LeaveCriticalSection(pGame->lpCriticalSection);
    }

    return nUnitInfoCount;
}

// 0x0052F3E0
void __stdcall GAME_GetStatistics(D2GameStatisticsStrc* pStats)
{
    pStats->nGamesCount = 0;
    pStats->nActiveMonsters = 0;
    pStats->nInactiveMonsters = 0;
    pStats->nPlayersCount = 0;

    for (int i = 0; i < 1024; ++i)
    {
        if (gnGamesGUIDs_6FD447F8[i] && gnGamesGUIDs_6FD447F8[i] != D2GameReservedSlotHandle)
        {
            if (D2GameStrc* pGame = GAME_LockGame(gnGamesGUIDs_6FD447F8[i]))
            {
                for (int j = 0; j < 128; ++j)
                {
                    for (D2UnitStrc* k = pGame->pUnitList[UNIT_MONSTER][j]; k; k = SUNIT_GetNextUnitFromList(k))
                    {
                        ++pStats->nActiveMonsters;
                    }

                    for (D2UnitStrc* k = pGame->pUnitList[UNIT_PLAYER][j]; k; k = SUNIT_GetNextUnitFromList(k))
                    {
                        ++pStats->nPlayersCount;
                    }
                }

                D2_ASSERT(pGame->lpCriticalSection, 4196);
                LeaveCriticalSection(pGame->lpCriticalSection);

                ++pStats->nGamesCount;
            }
        }
    }
}

// 0x0052F840
unsigned int __fastcall sub_0052F840()
{
    int nGUID = 0;
    EnterCriticalSection(&gCriticalSection_6FD45800);
    if (*gnGamesGUIDs_6FD447F8 && *gnGamesGUIDs_6FD447F8 != D2GameReservedSlotHandle)
    {
        nGUID = *gnGamesGUIDs_6FD447F8;
    }
    LeaveCriticalSection(&gCriticalSection_6FD45800);

    D2GameStrc* pGame = GAME_LockGame(nGUID);
    gpGame_6FD457FC = pGame;
    if (!pGame)
    {
        return 0;
    }

    const unsigned int nInitSeed = pGame->dwInitSeed;
    D2_ASSERT(pGame->lpCriticalSection, 4196);
    LeaveCriticalSection(pGame->lpCriticalSection);
    return nInitSeed;
}

#include "gen/data/Source/D2Game/0052EAE0_sub_0052EAE0.inc"
