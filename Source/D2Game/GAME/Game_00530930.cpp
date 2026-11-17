#include "D2Game.h"

typedef unsigned int size_t;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2LargeIntegerPartsStrc
{
    unsigned int LowPart;
    int HighPart;
};

struct HASHKEY_NONE
{
    int nUnused;
};

struct D2GameStrc
{
    char unk0x00[0x18];
    D2CriticalSectionStrc* lpCriticalSection;
    void* pMemoryPool;
    char unk0x20[0x04];
    int unk0x24;
    unsigned short nGameId;
    char szGameName[0x10];
    char szGamePassword[0x10];
    char szGameDesc[0x20];
    char unk0x6A;
    unsigned char nArenaTemplate;
    unsigned char nMaxLevelDifference;
    unsigned char nDifficulty;
    unsigned char nMaxPlayers;
    char unk0x6F;
    int bExpansion;
    int dwGameType;
    unsigned short wItemFormat;
    char unk0x7A[0x02];
    unsigned int dwInitSeed;
    int dwObjSeed;
    int InitSeed;
    char unk0x88[0x08];
    int dwLastUsedUnitGUID[6];
    char unk0xA8[0x28];
    D2SeedStrc pGameSeed;
    char unk0xD8[0x1120 - 0xD8];
    int pUnitList[5][0x80];
    char unk0x1B20[0x04];
    int dwUniqueFlags[0x80];
    char unk0x1D24[0x1DBC - 0x1D24];
    unsigned int nCreationTimeMs;
    char unk0x1DC0[0x04];
    unsigned int nSyncTimer;
    char unk0x1DC8[0x0C];
    int nUberFields[8];
};

struct D2GameDataTableStrc
{
    char unk0x00[0x44];
    HASHKEY_NONE f_44;
    unsigned int nSequence;
    int bWrapped;
    D2CriticalSectionStrc f_50;

    unsigned int sub_0052E6D0_GenerateHandle();                                                             // 0x0052E6D0
    D2GameStrc* sub_00530820_New(unsigned int nHashVal, HASHKEY_NONE* pKey, int nExtraBytes, int nFlags);   // 0x00530820
};

extern D2GameDataTableStrc* gpGameDataTbl_6FD45818;                                                         // 0x00883D38

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize);
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) unsigned int __stdcall GetTickCount();                                     // 0x006CC260
extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(D2LargeIntegerPartsStrc* pCount);     // 0x006CC25C
void __fastcall SEED_InitSeed(D2SeedStrc* pSeed);                                                           // 0x00650E30
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
void __cdecl sub_00409DD0_InitPoolSystem(void* pReserved, const char* szName, int nSize, int nBlockSize);
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
void __stdcall sub_0052C110(int hGame, unsigned short nGameId);                            // 0x0052C110
unsigned short __cdecl sub_0052C170_AllocGameId();
void __fastcall GAME_ResolveGameNameConflict(D2GameStrc* pGame, const char* szGameName, unsigned int a3);                    // 0x0052F940
void __fastcall sub_00536070_InitNpcControl(D2GameStrc* pGame);
void __fastcall sub_005379A0_ResetClient(D2ClientStrc* pClient);                                            // 0x005379A0
void __fastcall ARENA_AllocArena(D2GameStrc* pGame, int a2, unsigned int nFlags, unsigned char a4);         // 0x0053F4B0
void __fastcall PARTY_AllocPartyControl(D2GameStrc* pGame);                                                 // 0x0053FF90
void __fastcall sub_00541470_InitializeQueue(D2GameStrc* pGame);                                            // 0x00541470
void __fastcall sub_00545D80_QuestInit(D2GameStrc* pGame);
int __fastcall sub_00546C60_AllocObjectControl(D2GameStrc* pGame);
void __fastcall MONSTERREGION_InitializeForGame(D2GameStrc* pGame);                                         // 0x00547D20
void __fastcall sub_00564A00_QueueGame(void* pTask, int a2, unsigned int hGame);

inline unsigned __int64 sub_I08_RollGameSeed(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// build: context sub_0052C280_InitGameSeed
static __declspec(noinline) void sub_0052C280_InitGameSeed(D2GameStrc* pGame)
{
    if (gnInitSeed_00731004 == -1)
    {
        pGame->InitSeed = 0;
        D2LargeIntegerPartsStrc tCount;
        QueryPerformanceCounter(&tCount);
        SEED_InitSeed(&pGame->pGameSeed);
        SEED_InitLowSeed(&pGame->pGameSeed, SEED_GetRandomValue(tCount.LowPart));
        pGame->dwInitSeed = SEED_GetRandomValue((int)sub_I08_RollGameSeed(&pGame->pGameSeed));
    }
    else
    {
        pGame->InitSeed = 1;
        pGame->dwInitSeed = gnInitSeed_00731004;
        SEED_InitSeed(&pGame->pGameSeed);
        SEED_InitLowSeed(&pGame->pGameSeed, gnInitSeed_00731004);
    }
}

// 0x00530930
int __stdcall GAME_CreateNewEmptyGame(char* szGameName, const char* szPassword, const char* szGameDescription, unsigned int nFlags, unsigned char nArenaTemplate, unsigned char nMaxLevelDifference, unsigned char nMaxPlayers, unsigned short* pGameId)
{
    if (!gpGameDataTbl_6FD45818)
    {
        return 0;
    }

    const unsigned short nGameId = sub_0052C170_AllocGameId();
    if (!nGameId)
    {
        return 0;
    }

    D2GameDataTableStrc* pGameDataTbl = gpGameDataTbl_6FD45818;
    EnterCriticalSection(&pGameDataTbl->f_50);
    const unsigned int hGame = pGameDataTbl->sub_0052E6D0_GenerateHandle();
    D2GameStrc* pGame = pGameDataTbl->sub_00530820_New(hGame, &pGameDataTbl->f_44, 0, 0);
    LeaveCriticalSection(&gpGameDataTbl_6FD45818->f_50);

    D2_ASSERT(pGame, 793);
    pGame->lpCriticalSection = (D2CriticalSectionStrc*)FOG_AllocPool(0, sizeof(D2CriticalSectionStrc), ".\\GAME\\Game.cpp", 796, 0);
    InitializeCriticalSection(pGame->lpCriticalSection);

    sub_00409DD0_InitPoolSystem(&pGame->pMemoryPool, szGameName, 0x8000, 0x1000);

    memset(pGame->pUnitList[0], 0, sizeof(pGame->pUnitList[0]));
    memset(pGame->pUnitList[1], 0, sizeof(pGame->pUnitList[1]));
    memset(pGame->pUnitList[2], 0, sizeof(pGame->pUnitList[2]));
    memset(pGame->pUnitList[3], 0, sizeof(pGame->pUnitList[3]));
    memset(pGame->pUnitList[4], 0, sizeof(pGame->pUnitList[4]));
    memset(pGame->dwUniqueFlags, 0, sizeof(pGame->dwUniqueFlags));

    pGame->nGameId = nGameId;
    pGame->unk0x24 = 1;

    GAME_ResolveGameNameConflict(pGame, szGameName, 0);
    SStrCopy(pGame->szGamePassword, szPassword, 16);
    SStrCopy(pGame->szGameDesc, szGameDescription, 32);

    pGame->nArenaTemplate = nArenaTemplate;
    pGame->nMaxLevelDifference = nMaxLevelDifference;
    pGame->nMaxPlayers = nMaxPlayers;

    if (nFlags & 0x100000)
    {
        pGame->bExpansion = 1;
    }
    else
    {
        pGame->bExpansion = 0;
    }

    pGame->wItemFormat = pGame->bExpansion != 0 ? 101 : 2;
    pGame->dwGameType = (nFlags & 0x200000) != 0;

    pGame->dwLastUsedUnitGUID[0] = 0;
    pGame->dwLastUsedUnitGUID[1] = 0;
    pGame->dwLastUsedUnitGUID[2] = 0;
    pGame->dwLastUsedUnitGUID[3] = 0;
    pGame->dwLastUsedUnitGUID[4] = 0;
    pGame->dwLastUsedUnitGUID[5] = 0;
    pGame->nUberFields[0] = 0;
    pGame->nUberFields[1] = 0;
    pGame->nUberFields[2] = 0;
    pGame->nUberFields[3] = 0;
    pGame->nUberFields[4] = 0;
    pGame->nUberFields[5] = 0;
    pGame->nUberFields[6] = 0;
    pGame->nUberFields[7] = 0;

    pGame->nDifficulty = (nFlags >> 12) & 7;

    sub_0052C280_InitGameSeed(pGame);
    sub_00541470_InitializeQueue(pGame);
    ARENA_AllocArena(pGame, 0, nFlags, 0);
    sub_005379A0_ResetClient((D2ClientStrc*)pGame);
    PARTY_AllocPartyControl(pGame);
    MONSTERREGION_InitializeForGame(pGame);
    pGame->dwObjSeed = sub_00546C60_AllocObjectControl(pGame);
    sub_00536070_InitNpcControl(pGame);
    sub_00545D80_QuestInit(pGame);

    sub_0052C110(hGame, nGameId);

    pGame->nSyncTimer = sub_00410A80_GetTimeSeconds();
    if (pGame->nSyncTimer <= 1)
    {
        pGame->nSyncTimer = 2;
    }

    void* pTask = FOG_Alloc(0x14, ".\\GAME\\Game.cpp", 922, 0);
    sub_00564A00_QueueGame(pTask, 0, hGame);
    pGame->nCreationTimeMs = GetTickCount();
    *pGameId = pGame->nGameId;
    return 1;
}

#include "gen/data/Source/D2Game/GAME/Game_00530930.inc"
