#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameTypes.h"
#include "D2GameServer.h"
#include "D2GameStrc.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

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
extern D2ServerCallbackFunctions* gpD2EventCallbackTable_6FD45830;                                          // 0x00883D50
int gnAct_6FD45824;                                                                                         // 0x00883D44

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize);
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(D2LargeIntegerPartsStrc* pCount);     // 0x006CC25C
void __fastcall SEED_InitSeed(D2SeedStrc* pSeed);                                                           // 0x00650E30
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
void __stdcall sub_0052C110(int hGame, unsigned short nGameId);                            // 0x0052C110
unsigned short __cdecl sub_0052C170_AllocGameId();
void __fastcall GAME_ResolveGameNameConflict(D2GameStrc* pGame, const char* szGameName, unsigned int a3);                    // 0x0052F940
void __fastcall sub_00536070_InitNpcControl(D2GameStrc* pGame);
void __fastcall sub_005379A0_ResetClient(D2ClientStrc* pClient);                                            // 0x005379A0
void __fastcall CLIENTS_SetActNo(D2ClientStrc* pClient, unsigned char nAct);                                // 0x005382E0
void __fastcall CLIENTS_SetClientState(D2ClientStrc* pClient, int nState);                                  // 0x005386D0
void __fastcall sub_00539000(D2ClientStrc* pClient);                                       // 0x00539000
D2ClientStrc* __fastcall ClientAddToGame(D2GameStrc* pGame, int nClientId, unsigned char nClassIdOrCharTemplate, const char* szClientName, const char* szAccount, int nCharSaveTransactionToken, unsigned char nLocale, int a8, int a9); // 0x00539A30
void __fastcall D2GAME_PACKETS_SendHeaderOnlyPacket(D2ClientStrc* pClient, unsigned char nHeader);          // 0x0053B320
void __fastcall D2GAME_PACKETS_SendPacket0x01_6FC3C7C0(D2ClientStrc* pClient, char nHeader, D2GameStrc* pGame); // 0x0053B340
void __fastcall ARENA_AllocArena(D2GameStrc* pGame, int nUnused, unsigned int nFlags, unsigned char nTemplate); // 0x0053F4B0
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

// 0x00530BF0
void __fastcall sSrvSendGameInit(int nClientId, char* szGameName, unsigned char nGameType, unsigned char nCharTemplate, const char* szClientName, int nArena, unsigned int nFlags, int nArenaTemplate, int nUnused1, int nUnused2, unsigned char nDifficulty, unsigned char nLocale, int nUnused3, int nUnused4)
{
    if (!gpGameDataTbl_6FD45818)
    {
        return;
    }

    D2GameDataTableStrc* pGameDataTbl = gpGameDataTbl_6FD45818;
    EnterCriticalSection(&pGameDataTbl->f_50);
    const unsigned int hGame = pGameDataTbl->sub_0052E6D0_GenerateHandle();
    D2GameStrc* pGame = pGameDataTbl->sub_00530820_New(hGame, &pGameDataTbl->f_44, 0, 0);
    LeaveCriticalSection(&gpGameDataTbl_6FD45818->f_50);

    if (!pGame)
    {
        return;
    }

    pGame->lpCriticalSection = (D2CriticalSectionStrc*)FOG_AllocPool(0, sizeof(D2CriticalSectionStrc), ".\\GAME\\Game.cpp", 1241, 0);
    InitializeCriticalSection(pGame->lpCriticalSection);

    pGame->pMemoryPool = 0;

    memset(pGame->pUnitList[0], 0, sizeof(pGame->pUnitList[0]));
    memset(pGame->pUnitList[1], 0, sizeof(pGame->pUnitList[1]));
    memset(pGame->pUnitList[2], 0, sizeof(pGame->pUnitList[2]));
    memset(pGame->pUnitList[3], 0, sizeof(pGame->pUnitList[3]));
    memset(pGame->pUnitList[4], 0, sizeof(pGame->pUnitList[4]));
    memset(pGame->dwUniqueFlags, 0, sizeof(pGame->dwUniqueFlags));

    pGame->unk0x24 = 1;

    pGame->nGameId = sub_0052C170_AllocGameId();
    GAME_ResolveGameNameConflict(pGame, szGameName, nClientId);
    pGame->nGameType = nGameType;
    pGame->dwLastUsedUnitGUID[0] = 0;
    pGame->dwLastUsedUnitGUID[1] = 0;
    pGame->dwLastUsedUnitGUID[2] = 0;
    pGame->dwLastUsedUnitGUID[3] = 0;
    pGame->dwLastUsedUnitGUID[4] = 0;
    pGame->dwLastUsedUnitGUID[5] = 0;
    pGame->nDifficulty = nDifficulty;
    pGame->nArenaTemplate = nArenaTemplate;

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

    sub_0052C280_InitGameSeed(pGame);
    sub_00541470_InitializeQueue(pGame);
    ARENA_AllocArena(pGame, nArena, nFlags, nArenaTemplate);
    sub_005379A0_ResetClient((D2ClientStrc*)pGame);

    D2ClientStrc* pClient = ClientAddToGame(pGame, nClientId, nCharTemplate, szClientName, &gszEmptyAssertText, 0, nLocale, nUnused3, nUnused4);
    SERVER_SetClientGameGUID(nClientId, hGame);

    if (pGame->nGameType == 1)
    {
        sub_00539000(pClient);
    }

    PARTY_AllocPartyControl(pGame);
    MONSTERREGION_InitializeForGame(pGame);
    pGame->dwObjSeed = sub_00546C60_AllocObjectControl(pGame);
    sub_00536070_InitNpcControl(pGame);
    sub_00545D80_QuestInit(pGame);

    sub_0052C110(hGame, pGame->nGameId);

    D2GAME_PACKETS_SendPacket0x01_6FC3C7C0(pClient, 1, pGame);
    D2GAME_PACKETS_SendHeaderOnlyPacket(pClient, 0);
    CLIENTS_SetClientState(pClient, 1);
    CLIENTS_SetActNo(pClient, gnAct_6FD45824);

    pGame->nSyncTimer = sub_00410A80_GetTimeSeconds();
    if (pGame->nSyncTimer <= 1)
    {
        pGame->nSyncTimer = 2;
    }

    void* pTask = FOG_Alloc(0x14, ".\\GAME\\Game.cpp", 1371, 0);
    sub_00564A00_QueueGame(pTask, 0, hGame);

    D2_ASSERT(!gpD2EventCallbackTable_6FD45830 || !gpD2EventCallbackTable_6FD45830->pfGetDatabaseCharacter, 1378);

    D2GAME_PACKETS_SendHeaderOnlyPacket(pClient, 2);
}
