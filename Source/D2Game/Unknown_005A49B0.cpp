#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
// build: ob1

struct D2UnitStrc;
struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2RoomCoordListStrc;
struct D2AiControlStrc;



struct D2MonsterDataStrc
{
    void* pMonStatsTxt;
    unsigned char nComponent[16];
    unsigned short wNameSeed;
    unsigned short nTypeFlag;
    unsigned int dwDurielFlag;
    unsigned char nMonUmod[10];
    short wBossHcIdx;
    D2AiControlStrc* pAiControl;
};


struct D2MonsterRegionStrc
{
    char _pad000[0x2C8];
    unsigned int dwUniqueCount;
};


struct D2MonStatsTxt
{
    char _pad000[0x0C];
    unsigned char nMonStatsFlags[4];
    char _pad010[0x16];
    short wMinion[2];
    char _pad02A[0x17E];
};

struct D2MonUModTxt
{
    unsigned int dwUniqueMod;
    unsigned short wVersion;
    unsigned char nEnabled;
    unsigned char nXfer;
    unsigned char nChampion;
    unsigned char nFPick;
    short wExclude[2];
    unsigned short wCPick[3];
    unsigned short wUPick[3];
    unsigned short pad1A;
    unsigned int dwConstants;
};

struct D2SuperUniquesTxt
{
    unsigned short wSuperUnique;
    unsigned short wNameStr;
    int dwClass;
    int dwHcIdx;
    int dwMod[3];
    int dwMonSound;
    int dwMinGrp;
    int dwMaxGrp;
    unsigned char nAutopos;
    unsigned char nEclass;
    unsigned char nStacks;
    unsigned char nReplaceable;
    char _pad28[0x0C];
};


typedef void (__fastcall* UModInitFunc)(D2UnitStrc* pUnit, int nUMod, int bUnique);
typedef void (__fastcall* MinionCallbackFunc)(D2UnitStrc* pUnit, void* pArg1, void* pArg2);

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern UModInitFunc gpUModInitFunctions_0073C008[];                                                         // 0x0073C008
extern const int gnBaseUMods_006E2168[4];                                                                // 0x006E2168

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                 // 0x00681EF0
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0
int __fastcall sub_0046C140_CheckMonStats2ModeFlag(int nMonsterId, int nMode);                              // 0x0046C140
int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc* pUnit);                                                  // 0x00451F50
int __fastcall QUESTS_CreateChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuestId);                // 0x005436B0
void __fastcall QUESTS_SetJadeFigurineBoss(D2GameStrc* pGame, D2UnitStrc* pUnit);                           // 0x00544E80
void __fastcall QUESTS_MonsterSpawn(D2GameStrc* pGame, D2UnitStrc* pUnit);                                  // 0x00545B50
D2MonsterRegionStrc* __fastcall MONSTERREGION_GetMonsterRegionFromLevelId(D2MonsterRegionStrc** ppMonsterRegion, int nLevelId); // 0x00547BB0
int __fastcall MONSTERREGION_FindSpawnLocation(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pRoomCoordList, int nClassId, int* pX, int* pY, int bAvoidWarps); // 0x0054DC40
int __fastcall MONSTER_GetLevelId(D2UnitStrc* pUnit);                                                        // 0x00573520
void __fastcall MONSTER_ToggleSummonerFlag(D2UnitStrc* pUnit, int nFlag, int bSet);                         // 0x00573570
void __fastcall AIGENERAL_SetOwnerData(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOwnerGUID, int nOwnerType, int bSetFlag1, int bSetFlag2); // 0x0058F030
void __fastcall AIGENERAL_AllocMinionList(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pMinion);       // 0x0058F100
void __fastcall AIUTIL_SetOwnerGUIDAndType(D2UnitStrc* pUnit, D2UnitStrc* pOwner);                          // 0x005DD330
void __fastcall AIGENERAL_ExecuteCallbackOnMinions(D2UnitStrc* pUnit, void* pArg1, void* pArg2, MinionCallbackFunc pfnCallback); // 0x0058F380
int __fastcall sub_005A0070(D2UnitStrc* pUnit, int nMonType);                           // 0x005A0070
unsigned char* __fastcall MONSTERUNIQUE_GetUMods(D2UnitStrc* pUnit);                                         // 0x005A0120
void __fastcall sub_005A0200(D2UnitStrc* pUnit, short nBossHcIdx);                             // 0x005A0200
int __fastcall MONSTERUNIQUE_GetUModCount(unsigned char* pUMods);                                            // 0x005A0260
void __fastcall MONSTERUNIQUE_UMod30_AuraEnchanted(D2UnitStrc* pUnit, int nUMod, int bUnique);              // 0x005A1650
void __fastcall MONSTERUNIQUE_InitializeUMod(D2UnitStrc* pUnit, int nUMod, int bUnique);                    // 0x005A2100
void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nAiSpecialState); // 0x005B0E00
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnAtUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags); // 0x005B23C0
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnLinkedMinionsAtOwner(D2GameStrc* pGame, D2UnitStrc* pOwner, int nMonsterId, int nAnimMode, int nMin, int nMax, short nFlags); // 0x005B24E0
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int a7, int a8); // 0x005B2F20
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnAtUnitInCoordList(D2GameStrc* pGame, D2RoomCoordListStrc* pRoomCoordList, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a6, short nFlags); // 0x005B2F70
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnInCoordList(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pRoomCoordList, int nX, int nY, int nMonsterId, int nAnimMode, int a8, short nFlags); // 0x005B3040
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnWithUnitId(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nUnitGUID, int a8, short nFlags); // 0x005B30E0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                                // 0x00620BB0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                  // 0x00639DB0
int __stdcall D2Common_11063(D2ActiveRoomStrc* pRoom, int nMonsterId);                                       // 0x0063EC70
void __fastcall D2Common_10136(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, int a3, unsigned short nMask, D2ActiveRoomStrc** ppRoom); // 0x0064E840
D2SuperUniquesTxt* __stdcall DATATBLS_GetSuperUniquesTxtRecord(int nSuperUniqueId);                          // 0x006556E0

// build: context MonsterDataOf
static __forceinline D2MonsterDataStrc* MonsterDataOf(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1 && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData;
    }
    return 0;
}

// build: context UModsOf
static __forceinline unsigned char* UModsOf(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1 && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->nMonUmod;
    }
    return 0;
}

// build: context HasMonTypeFlag
static __forceinline int HasMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag)
{
    if (pUnit && pUnit->dwUnitType == 1 && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->nTypeFlag & nFlag;
    }
    return 0;
}

// build: context SetMonTypeFlag
static __forceinline void SetMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag, int bSet)
{
    if (!pUnit || pUnit->dwUnitType != 1)
    {
        return;
    }

    D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
    if (!pMonsterData)
    {
        return;
    }

    if (bSet)
    {
        pMonsterData->nTypeFlag |= nFlag;
    }
    else
    {
        pMonsterData->nTypeFlag &= ~nFlag;
    }
}

// build: context CountUMods
static __forceinline int CountUMods(unsigned char* pUMods)
{
    int nIndex = 0;
    while (nIndex < 9 && pUMods[nIndex])
    {
        ++nIndex;
    }
    return nIndex;
}

// build: context CountUModsTo
static __forceinline int CountUModsTo(unsigned char* pUMods)
{
    for (int i = 0; i < 9; ++i)
    {
        if (!pUMods[i])
        {
            return i;
        }
    }
    return 9;
}

// build: context TestMonTypeFlag
static __forceinline int TestMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag)
{
    if (pUnit && pUnit->dwUnitType == 1 && pUnit->pMonsterData && (pUnit->pMonsterData->nTypeFlag & nFlag))
    {
        return 1;
    }
    return 0;
}

// build: context UModsOfData
static __forceinline unsigned char* UModsOfData(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = 0;
    if (pUnit && pUnit->dwUnitType == 1)
    {
        pMonsterData = pUnit->pMonsterData;
    }

    if (!pMonsterData)
    {
        return 0;
    }
    return pMonsterData->nMonUmod;
}

// build: context InitUMod
static __forceinline void InitUMod(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    UModInitFunc pfnInit = gpUModInitFunctions_0073C008[nUMod];
    if (pfnInit)
    {
        pfnInit(pUnit, nUMod, bUnique);
    }
}

// build: context MonStatsTxtRecord
static __forceinline D2MonStatsTxt* MonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

// build: context CheckMonStatsFlag
static __forceinline unsigned int CheckMonStatsFlag(int nMonsterId, int nFlag)
{
    D2MonStatsTxt* pMonStatsTxtRecord = MonStatsTxtRecord(nMonsterId);
    if (pMonStatsTxtRecord)
    {
        return pMonStatsTxtRecord->nMonStatsFlags[nFlag >> 3] & gdwBitMasks[nFlag & 7];
    }
    return 0;
}

// build: context MonStatsTxtRecordOrNull
static __forceinline D2MonStatsTxt* MonStatsTxtRecordOrNull(int nMonsterId)
{
    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return 0;
    }
    return &sgptDataTables->pMonStatsTxt[nMonsterId];
}

// build: context TestMonStatsFlag
static __forceinline unsigned int TestMonStatsFlag(int nMonsterId, int nFlag)
{
    D2MonStatsTxt* pMonStatsTxtRecord = MonStatsTxtRecordOrNull(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }
    return pMonStatsTxtRecord->nMonStatsFlags[nFlag >> 3] & gdwBitMasks[nFlag & 7];
}

// build: context MonUModTxtRecord
static __forceinline D2MonUModTxt* MonUModTxtRecord(int nUMod)
{
    if (!(nUMod < sgptDataTables->nMonUModTxtRecordCount))
        return 0;
    return &sgptDataTables->pMonUModTxt[nUMod];
}

// build: context SuperUniqueHcIdx
static __forceinline int SuperUniqueHcIdx(int nSuperUnique)
{
    if (nSuperUnique >= 0 && nSuperUnique < sgptDataTables->nSuperUniquesTxtRecordCount)
    {
        return sgptDataTables->pSuperUniquesTxt[nSuperUnique].dwHcIdx;
    }
    return -1;
}

// build: context RollRandomInline
static __forceinline unsigned int RollRandomInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

// build: context RollLimitedInline
static __forceinline int RollLimitedInline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if (((unsigned int)nMax - 1) & (unsigned int)nMax)
    {
        return RollRandomInline(pSeed) % nMax;
    }

    return RollRandomInline(pSeed) & (nMax - 1);
}

// 0x005A02E0
static __declspec(noinline) void __stdcall sub_005A02E0_AddUMod(int nUMod, D2UnitStrc* pUnit)
{
    const unsigned int nUnitType = pUnit ? pUnit->dwUnitType : 6;
    if (nUnitType != 1)
    {
        return;
    }

    if (D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData)
    {
        int nIndex = 0;
        while (nIndex < 9 && pMonsterData->nMonUmod[nIndex])
        {
            ++nIndex;
        }

        if (nIndex < 9)
        {
            pMonsterData->nMonUmod[nIndex] = (unsigned char)nUMod;
        }
    }
}

// 0x005A0320
static void __stdcall sub_005A0320_MarkUnique(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : 6;
    if (nUnitType == 1)
    {
        D2MonsterRegionStrc* pMonsterRegion = MONSTERREGION_GetMonsterRegionFromLevelId(pGame->pMonReg, MONSTER_GetLevelId(pUnit));
        if (pMonsterRegion && !TestMonTypeFlag(pUnit, 8))
        {
            ++pMonsterRegion->dwUniqueCount;
        }

        SetMonTypeFlag(pUnit, 8, 1);
    }
}

// 0x005A03E0
static int __stdcall MONSTERUNIQUE_CanAssignUMod(D2UnitStrc* pUnit, D2MonUModTxt* pMonUModTxtRecord, int bExpansion)
{
    if (!pMonUModTxtRecord->nEnabled)
    {
        return 0;
    }

    if (!bExpansion && pMonUModTxtRecord->wVersion >= 100)
    {
        return 0;
    }

    for (int i = 0; i < 2; ++i)
    {
        const short nExcludeMonType = pMonUModTxtRecord->wExclude[i];
        if (nExcludeMonType <= 0)
        {
            break;
        }

        if (sub_005A0070(pUnit, nExcludeMonType))
        {
            return 0;
        }
    }

    switch (pMonUModTxtRecord->nFPick)
    {
    case 1:
        if (!sub_0046C140_CheckMonStats2ModeFlag(!pUnit ? -1 : pUnit->dwClassId, 4))
        {
            return 0;
        }
        break;

    case 2:
        if (pUnit)
        {
            if (TestMonStatsFlag(pUnit->dwClassId, 1))
            {
                return 0;
            }

            if (TestMonStatsFlag(pUnit->dwClassId, 17))
            {
                return 0;
            }
        }
        break;

    case 3:
        if (!sub_0046C140_CheckMonStats2ModeFlag(!pUnit ? -1 : pUnit->dwClassId, 2))
        {
            return 0;
        }
        break;
    }

    return 1;
}

// 0x005A0500
static int sub_005A0500_RollChampionUMod(D2UnitStrc* pUnit, D2GameStrc* pGame)
{
    int aPicks[512];
    int nPickCount = 0;

    if (!pGame)
    {
        return 0;
    }

    const unsigned char nDifficulty = pGame->nDifficulty;
    if (nDifficulty >= 3)
    {
        return 0;
    }

    const int bExpansion = pGame->bExpansion;
    int nTotal = 0;
    const int nRecords = sgptDataTables->nMonUModTxtRecordCount;
    D2MonUModTxt* pMonUModTxtRecord = MonUModTxtRecord(0);
    if (!pMonUModTxtRecord)
    {
        return 0;
    }

    for (int i = 0; i < nRecords; ++i, ++pMonUModTxtRecord)
    {
        const short nPick = pMonUModTxtRecord->wCPick[nDifficulty];
        if (nPick > 0 && pMonUModTxtRecord->nChampion && MONSTERUNIQUE_CanAssignUMod(pUnit, pMonUModTxtRecord, bExpansion))
        {
            nTotal += nPick;
            aPicks[2 * nPickCount] = i;
            aPicks[2 * nPickCount + 1] = nPick;
            ++nPickCount;
            if (nPickCount >= 256)
            {
                break;
            }
        }
    }

    int nRand = SEED_RollLimitedRandomNumber(&pUnit->pSeed, nTotal);
    for (int i = 0; i < nPickCount; ++i)
    {
        if (nRand < aPicks[2 * i + 1])
        {
            return aPicks[2 * i];
        }
        nRand -= aPicks[2 * i + 1];
    }

    return 0;
}

// 0x005A0600
static int __stdcall MONSTERUNIQUE_RollNonChampionUMod(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pUsedUMods)
{
    int aPicks[512];

    if (!pGame || pGame->nDifficulty >= 3)
    {
        return 0;
    }

    const unsigned char nDifficulty = pGame->nDifficulty;

    const int bExpansion = pGame->bExpansion;
    int nPickCount = 0;
    int nTotal = 0;
    const int nRecords = sgptDataTables->nMonUModTxtRecordCount;
    D2MonUModTxt* pMonUModTxtRecord = MonUModTxtRecord(0);
    for (int i = 0; i < nRecords; ++i, ++pMonUModTxtRecord)
    {
        const short nPick = pMonUModTxtRecord->wUPick[nDifficulty];
        if (nPick > 0 && !pMonUModTxtRecord->nChampion && MONSTERUNIQUE_CanAssignUMod(pUnit, pMonUModTxtRecord, bExpansion) && !pUsedUMods[i])
        {
            nTotal += nPick;
            aPicks[2 * nPickCount] = i;
            aPicks[2 * nPickCount + 1] = nPick;
            ++nPickCount;
            if (nPickCount >= 256)
            {
                break;
            }
        }
    }

    int nRand = RollLimitedInline(&pUnit->pSeed, nTotal);
    for (int i = 0; i < nPickCount; ++i)
    {
        if (nRand < aPicks[2 * i + 1])
        {
            return aPicks[2 * i];
        }
        nRand -= aPicks[2 * i + 1];
    }

    return 0;
}

static void __stdcall MONSTERUNIQUE_AssignRandomUMods(D2GameStrc* pGame, D2UnitStrc* pUnit, int bAllowChampion); // 0x005A0760

// build: context MONSTERUNIQUE_AssignRandomUMods
// build: context MONSTERUNIQUE_AssignRandomUMods
static void __stdcall MONSTERUNIQUE_AssignRandomUMods(D2GameStrc* pGame, D2UnitStrc* pUnit, int bAllowChampion)
{
    unsigned char bUModUsageTable[256];

    if (!pGame || pGame->nDifficulty >= 3)
    {
        return;
    }

    const int nUnitType = pUnit ? pUnit->dwUnitType : 6;
    if (nUnitType != 1)
    {
        return;
    }

    D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
    if (!pMonsterData)
    {
        return;
    }

    unsigned char* pUMods = pMonsterData->nMonUmod;
    if (!pUMods)
    {
        return;
    }

    const int nIndex = MONSTERUNIQUE_GetUModCount(pUMods);
    if (nIndex >= 8)
    {
        return;
    }

    D2SeedStrc* pSeed = &pUnit->pSeed;
    if (!pSeed)
    {
        return;
    }

    if (bAllowChampion)
    {
        D2MonUModTxt* pMonUModTxtRecord = MonUModTxtRecord(0);
        const int nChance = !pMonUModTxtRecord ? 0 : pMonUModTxtRecord->dwConstants;
        if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < nChance)
        {
            SetMonTypeFlag(pUnit, 4, 1);
            sub_005A02E0_AddUMod(sub_005A0500_RollChampionUMod(pUnit, pGame), pUnit);
            return;
        }
    }

    int nRandCount = pGame->nDifficulty + SEED_RollLimitedRandomNumber(pSeed, 1) + 1;
    if (nRandCount + nIndex >= 9)
    {
        nRandCount = 9 - nIndex;
    }

    memset(bUModUsageTable, 0, sgptDataTables->nMonUModTxtRecordCount);
    for (int i = 0; i < nIndex; ++i)
    {
        bUModUsageTable[pUMods[i]] = 1;
    }

    unsigned char* pUMod = &pUMods[nIndex];
    while (nRandCount)
    {
        const int nUMod = MONSTERUNIQUE_RollNonChampionUMod(pGame, pUnit, bUModUsageTable);
        if (!nUMod)
        {
            break;
        }

        *pUMod = nUMod;
        --nRandCount;
        ++pUMod;
        bUModUsageTable[nUMod] = 1;
    }
}

// 0x005A0930
static void __stdcall sub_005A0930_TransferUMods(D2UnitStrc* pOwner, D2UnitStrc* pMinion, int bFromStart)
{
    unsigned char* pOwnerUMods = UModsOfData(pOwner);
    unsigned char* pMinionUMods = UModsOfData(pMinion);
    if (!pOwnerUMods || !pMinionUMods)
    {
        return;
    }

    int nIndex = 0;
    if (!bFromStart)
    {
        nIndex = CountUModsTo(pMinionUMods);
    }
    pMinionUMods += nIndex;
    while (nIndex < 9)
    {
        const unsigned char nOwnerUMod = *pOwnerUMods;
        if (!nOwnerUMod)
        {
            break;
        }

        D2MonUModTxt* pMonUModTxtRecord = MonUModTxtRecord(nOwnerUMod);
        if (!pMonUModTxtRecord)
        {
            break;
        }

        if (pMonUModTxtRecord->nXfer)
        {
            *pMinionUMods = nOwnerUMod;
            ++pMinionUMods;
        }

        ++nIndex;
        ++pOwnerUMods;
    }
}

// 0x005A09E0
static D2UnitStrc* __stdcall MONSTERUNIQUE_SpawnUniqueMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pRoomCoordList, int nX, int nY, int nUnitGUID, int nClassId, int bAvoidWarps)
{
    if (!nX && !nY)
    {
        if (!MONSTERREGION_FindSpawnLocation(pGame, pRoom, pRoomCoordList, nClassId, &nX, &nY, bAvoidWarps))
        {
            return 0;
        }
    }

    D2UnitStrc* pMonster = 0;
    if (pRoomCoordList)
    {
        pMonster = MONSTERSPAWN_SpawnInCoordList(pGame, pRoom, pRoomCoordList, nX, nY, nClassId, 1, -1, 64);
    }
    else if (nUnitGUID == -1)
    {
        pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nClassId, 1, nUnitGUID, 64);
        if (!pMonster)
        {
            pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nClassId, 1, 5, 64);
        }
    }
    else
    {
        pMonster = MONSTERSPAWN_SpawnWithUnitId(pGame, pRoom, nX, nY, nClassId, 1, nUnitGUID, -1, 98);
        if (!pMonster)
        {
            pMonster = MONSTERSPAWN_SpawnWithUnitId(pGame, pRoom, nX, nY, nClassId, 1, nUnitGUID, 5, 98);
            if (!pMonster)
            {
                if (MONSTERREGION_FindSpawnLocation(pGame, pRoom, 0, nClassId, &nX, &nY, 0))
                {
                    pMonster = MONSTERSPAWN_SpawnWithUnitId(pGame, pRoom, nX, nY, nClassId, 1, nUnitGUID, -1, 98);
                }

                if (!pMonster)
                {
                    D2CoordStrc tCoord;
                    tCoord.nX = nX;
                    tCoord.nY = nY;
                    D2ActiveRoomStrc* pTargetRoom;
                    D2Common_10136(pRoom, &tCoord, 1, 0x3C01, &pTargetRoom);
                    if (!pTargetRoom)
                    {
                        return 0;
                    }

                    pMonster = MONSTERSPAWN_SpawnWithUnitId(pGame, pTargetRoom, tCoord.nX, tCoord.nY, nClassId, 1, nUnitGUID, -1, 98);
                }
            }
        }
    }

    if (!pMonster)
    {
        return 0;
    }

    sub_005A0320_MarkUnique(pGame, pMonster);
    SetMonTypeFlag(pMonster, 1, 1);
    QUESTS_SetJadeFigurineBoss(pGame, pMonster);
    AIGENERAL_SetOwnerData(pGame, pMonster, !pMonster ? -1 : pMonster->dwUnitId, 1, 1, 0);
    return pMonster;
}

// 0x005A0BB0
static int sub_005A0BB0_GetMinionId(D2UnitStrc* pUnit)
{
    const int nClassId = !pUnit ? -1 : pUnit->dwClassId;
    D2MonStatsTxt* pMonStatsTxtRecord = MonStatsTxtRecord(nClassId);
    if (pMonStatsTxtRecord && pMonStatsTxtRecord->wMinion[0] >= 0 && pMonStatsTxtRecord->wMinion[0] < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return pMonStatsTxtRecord->wMinion[0];
    }

    return nClassId;
}

// 0x005A0C00
static void __stdcall sub_005A0C00_SpawnMinionGroup(D2GameStrc* pGame, D2RoomCoordListStrc* pRoomCoordList, D2UnitStrc* pUnit, int nMinGroup, int nMaxGroup)
{
    if (TestMonTypeFlag(pUnit, 4))
    {
        return;
    }

    const int nMinionId = sub_005A0BB0_GetMinionId(pUnit);
    if (nMinionId < 0 || nMinionId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return;
    }

    const int nMinionCount = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nMaxGroup - nMinGroup + 1) + nMinGroup;
    for (int i = 0; i < nMinionCount; ++i)
    {
        D2UnitStrc* pMinion;
        if (pRoomCoordList)
        {
            pMinion = MONSTERSPAWN_SpawnAtUnitInCoordList(pGame, pRoomCoordList, pUnit, nMinionId, 1, 3, 64);
        }
        else
        {
            pMinion = MONSTERSPAWN_SpawnAtUnit(pGame, pUnit, nMinionId, 1, 3, 64);
        }

        if (pMinion)
        {
            sub_005A0930_TransferUMods(pUnit, pMinion, 0);
            AIGENERAL_SetOwnerData(pGame, pMinion, sub_00451F50_GetUnitGUID(pUnit), 1, 0, 0);
            AIGENERAL_AllocMinionList(pGame, pUnit, pMinion);
            AIUTIL_SetOwnerGUIDAndType(pMinion, pUnit);
            SetMonTypeFlag(pMinion, 0x10, 1);
        }
    }
}

// 0x005A2120
static void __stdcall MONSTERUNIQUE_SpawnMinions(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pRoomCoordList, D2UnitStrc* pUnit, int bSpawnMinions, int nMinGroup, int nMaxGroup)
{
    if (bSpawnMinions)
    {
        sub_005A0C00_SpawnMinionGroup(pGame, pRoomCoordList, pUnit, nMinGroup, nMaxGroup);
    }

    for (int i = 0; i < 4; ++i)
    {
        const int nUMod = gnBaseUMods_006E2168[i];
        InitUMod(pUnit, nUMod, 1);
        AIGENERAL_ExecuteCallbackOnMinions(pUnit, (void*)nUMod, 0, (MinionCallbackFunc)MONSTERUNIQUE_InitializeUMod);
    }

    unsigned char* pUMods = UModsOf(pUnit);
    if (pUMods)
    {
        for (int i = 0; i < 9; ++i)
        {
            const int nUMod = pUMods[i];
            if (!nUMod)
            {
                break;
            }

            InitUMod(pUnit, nUMod, 1);
            AIGENERAL_ExecuteCallbackOnMinions(pUnit, (void*)nUMod, 0, (MinionCallbackFunc)MONSTERUNIQUE_InitializeUMod);
        }
    }
}

// 0x005A43E0
D2UnitStrc* __fastcall MONSTERUNIQUE_SpawnUniqueGroup(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pRoomCoordList, int nClassId, int bAllowChampion, unsigned short nX, unsigned short nY, int bAvoidWarps)
{
    D2UnitStrc* pMonster = MONSTERUNIQUE_SpawnUniqueMonster(pGame, pRoom, pRoomCoordList, nX, nY, -1, nClassId, bAvoidWarps);
    if (!pMonster)
    {
        return 0;
    }

    MONSTERUNIQUE_AssignRandomUMods(pGame, pMonster, bAllowChampion);
    MONSTERUNIQUE_SpawnMinions(pGame, pRoom, pRoomCoordList, pMonster, 1, 3, 6);
    return pMonster;
}

// build: context SetBossIndex
static __forceinline void SetBossIndex(D2UnitStrc* pUnit, short nIndex)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : 6;
    if (nUnitType == 1)
    {
        D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
        if (pMonsterData)
        {
            pMonsterData->wBossHcIdx = nIndex;
        }
    }
}

// 0x005A4440
D2UnitStrc* __fastcall MONSTERUNIQUE_RestoreUniqueMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nClassId, int nUnitGUID, unsigned short nNameSeed, int bChampion, int bSuperUnique, short nBossHcIdx, unsigned char* pUMods)
{
    D2UnitStrc* pMonster = MONSTERUNIQUE_SpawnUniqueMonster(pGame, pRoom, 0, nX, nY, nUnitGUID, nClassId, 1);
    if (!pMonster)
    {
        return pMonster;
    }

    const int nUnitType = pMonster ? pMonster->dwUnitType : 6;
    if (nUnitType == 1)
    {
        D2MonsterDataStrc* pMonsterData = pMonster->pMonsterData;
        unsigned char* pMonUMods = pMonsterData ? pMonsterData->nMonUmod : 0;
        if (pMonUMods)
        {
            SetMonTypeFlag(pMonster, 4, bChampion);

            int bAuraEnchanted = 0;
            for (int i = 0; i < 9; ++i)
            {
                pMonUMods[i] = pUMods[i];
                if (pUMods[i] == 30)
                {
                    bAuraEnchanted = 1;
                }
            }

            MONSTERUNIQUE_SpawnMinions(pGame, pRoom, 0, pMonster, 0, 0, 0);

            pMonsterData = MonsterDataOf(pMonster);
            if (pMonsterData)
            {
                pMonsterData->wNameSeed = nNameSeed;
            }

            if (bAuraEnchanted)
            {
                MONSTERUNIQUE_UMod30_AuraEnchanted(pMonster, 30, 1);
            }

            if (bSuperUnique)
            {
                SetMonTypeFlag(pMonster, 2, 1);
                SetBossIndex(pMonster, nBossHcIdx);

                switch (nBossHcIdx)
                {
                case 6:
                    STATES_ToggleState(pMonster, 0x76, 1);
                    QUESTS_CreateChainRecord(pGame, pMonster, 5);
                    break;
                case 60:
                    QUESTS_CreateChainRecord(pGame, pMonster, 34);
                    break;
                case 42:
                    STATES_ToggleState(pMonster, 0x76, 1);
                    QUESTS_CreateChainRecord(pGame, pMonster, 31);
                    break;
                case 43:
                case 44:
                case 45:
                    QUESTS_CreateChainRecord(pGame, pMonster, 35);
                    break;
                case 26:
                case 27:
                case 29:
                    QUESTS_CreateChainRecord(pGame, pMonster, 19);
                    break;
                case 39:
                    QUESTS_CreateChainRecord(pGame, pMonster, 4);
                    break;
                case 36:
                case 37:
                case 38:
                    QUESTS_CreateChainRecord(pGame, pMonster, 23);
                    break;
                }
            }
        }
    }

    return pMonster;
}

// 0x005A4850
void __fastcall D2GAME_BOSSES_AssignUMod_6FC6FF10(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : 6;
    if (nUnitType != 1)
    {
        return;
    }

    unsigned char* pUMods = UModsOf(pUnit);
    if (!pUMods)
    {
        return;
    }

    if (bUnique)
    {
        sub_005A0320_MarkUnique(pGame, pUnit);
    }

    const int nIndex = CountUMods(pUMods);
    if (nIndex < 9)
    {
        pUMods[nIndex] = nUMod;
        InitUMod(pUnit, nUMod, bUnique);
    }
}

// 0x005A48C0
void __fastcall MONSTERUNIQUE_PromoteToChampion(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nUMod)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : 6;
    if (nUnitType != 1)
    {
        return;
    }

    D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
    unsigned char* pUMods = pMonsterData ? pMonsterData->nMonUmod : 0;
    if (!pUMods || TestMonTypeFlag(pUnit, 4))
    {
        return;
    }

    sub_005A0320_MarkUnique(pGame, pUnit);
    SetMonTypeFlag(pUnit, 4 | 1, 1);

    const int nIndex = MONSTERUNIQUE_GetUModCount(pUMods);
    if (nIndex < 9)
    {
        pUMods[nIndex] = nUMod;
        MONSTERUNIQUE_SpawnMinions(pGame, UNITS_GetRoom(pUnit), 0, pUnit, 1, 0, 0);
    }
}

// build: context PromoteGetUMods
static __forceinline unsigned char* PromoteGetUMods(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : 6;
    if (nUnitType == 1)
    {
        D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
        return pMonsterData ? pMonsterData->nMonUmod : 0;
    }
    return 0;
}

// build: context PromoteSetTypeFlag
static __forceinline void PromoteSetTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : 6;
    if (nUnitType == 1 && pUnit->pMonsterData)
        pUnit->pMonsterData->nTypeFlag |= nFlag;
}

// 0x005A4940
void __fastcall sub_005A4940_PromoteToUnique(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : 6;
    if (nUnitType != 1)
    {
        return;
    }

    unsigned char* pUMods = PromoteGetUMods(pUnit);
    if (!pUMods)
    {
        return;
    }

    PromoteSetTypeFlag(pUnit, 1);
    sub_005A0320_MarkUnique(pGame, pUnit);
    MONSTERUNIQUE_AssignRandomUMods(pGame, pUnit, 1);
    MONSTERUNIQUE_SpawnMinions(pGame, UNITS_GetRoom(pUnit), 0, pUnit, 0, 0, 0);
    pUnit->dwFlags |= 0x800;
    MONSTER_ToggleSummonerFlag(pUnit, 1, 1);
}

// build: context AiControlOf
static __forceinline D2AiControlStrc* AiControlOf(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == 1 && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }
    return 0;
}

// 0x005A49B0
D2UnitStrc* __fastcall D2GAME_SpawnSuperUnique_6FC6F690(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nSuperUnique)
{
    if (pGame->nDifficulty >= 3)
    {
        return 0;
    }

    D2SuperUniquesTxt* pSuperUniquesTxtRecord = DATATBLS_GetSuperUniquesTxtRecord(nSuperUnique);
    if (!pSuperUniquesTxtRecord || pSuperUniquesTxtRecord->dwClass < 0 || !pSuperUniquesTxtRecord->nStacks && pGame->nBossFlagList[nSuperUnique >> 3] & gdwBitMasks[nSuperUnique & 7])
    {
        return 0;
    }

    int nSpawnY;
    int nSpawnX;
    if (pSuperUniquesTxtRecord->nAutopos)
    {
        nSpawnX = 0;
        nSpawnY = 0;
    }
    else
    {
        nSpawnY = nY;
        nSpawnX = nX;
    }

    D2UnitStrc* pMonster = MONSTERUNIQUE_SpawnUniqueMonster(pGame, pRoom, 0, nSpawnX, nSpawnY, -1, pSuperUniquesTxtRecord->dwClass, 0);

    if (!pMonster)
    {
        return 0;
    }

    unsigned char* pMonUmods = MONSTERUNIQUE_GetUMods(pMonster);
    if (!pMonUmods)
    {
        return pMonster;
    }

    pGame->nBossFlagList[nSuperUnique >> 3] |= gdwBitMasks[nSuperUnique & 7];

    const int nUnitType = pMonster ? pMonster->dwUnitType : 6;
    if (nUnitType == 1)
    {
        D2MonsterDataStrc* pMonsterData = pMonster->pMonsterData;
        if (pMonsterData)
        {
            pMonsterData->nTypeFlag |= 2;
        }
    }
    sub_005A0200(pMonster, nSuperUnique);

    unsigned char bUModUsageTable[256];
    memset(bUModUsageTable, 0, sgptDataTables->nMonUModTxtRecordCount);
    int bAuraEnchanted = 0;

    const int nCounter = MONSTERUNIQUE_GetUModCount(pMonUmods);
    if (nCounter >= 5)
    {
        return pMonster;
    }

    pMonUmods += nCounter;
    for (int i = 0; i < 3; ++i)
    {
        const int nUMod = pSuperUniquesTxtRecord->dwMod[i];
        if (!nUMod)
        {
            break;
        }

        if (nUMod == 30)
        {
            bAuraEnchanted = 1;
        }

        if (nUMod != 24)
        {
            const unsigned char nStoredUMod = (unsigned char)nUMod;
            *pMonUmods = nStoredUMod;
            bUModUsageTable[nUMod] = 1;
            ++pMonUmods;
        }
    }

    for (int i = 0; i < pGame->nDifficulty; ++i)
    {
        const int nUMod = MONSTERUNIQUE_RollNonChampionUMod(pGame, pMonster, bUModUsageTable);
        if (!nUMod)
        {
            break;
        }

        *pMonUmods = nUMod;
        ++pMonUmods;

        bUModUsageTable[nUMod] = 1;
    }

    int nMinGroup = pSuperUniquesTxtRecord->dwMinGrp;
    int nMaxGroup = pSuperUniquesTxtRecord->dwMaxGrp;
    if (nMinGroup && nMaxGroup)
    {
        nMinGroup += pGame->nDifficulty;
        nMaxGroup += pGame->nDifficulty;
    }

    MONSTERUNIQUE_SpawnMinions(pGame, pRoom, 0, pMonster, 1, nMinGroup, nMaxGroup);

    if (bAuraEnchanted)
    {
        MONSTERUNIQUE_UMod30_AuraEnchanted(pMonster, 30, 1);
    }

    D2AiControlStrc* pAiControl = AiControlOf(pMonster);
    switch (SuperUniqueHcIdx(nSuperUnique))
    {
    case 6:
        STATES_ToggleState(pMonster, 0x76, 1);
        QUESTS_CreateChainRecord(pGame, pMonster, 5);
        AITHINK_ExecuteAiFn(pGame, pMonster, pAiControl, 0xD);
        break;

    case 26:
    case 27:
    case 29:
        QUESTS_CreateChainRecord(pGame, pMonster, 0x13);
        QUESTS_MonsterSpawn(pGame, pMonster);
        break;

    case 36:
    case 37:
    case 38:
        QUESTS_CreateChainRecord(pGame, pMonster, 0x17);
        break;

    case 39:
        QUESTS_CreateChainRecord(pGame, pMonster, 4);
        break;

    case 10:
    {
        unsigned int nMinionCount = SEED_RollLimitedRandomNumber(&pMonster->pSeed, 5) + 2;
        for (; nMinionCount; --nMinionCount)
        {
            MONSTERSPAWN_SpawnAtUnit(pGame, pMonster, 4, 1, 4, 64);
        }

        MONSTERSPAWN_SpawnAtUnit(pGame, pMonster, 0x114, 1, 4, 64);
        MONSTERSPAWN_SpawnAtUnit(pGame, pMonster, 0x17E, 1, 4, 64);
        MONSTERSPAWN_SpawnAtUnit(pGame, pMonster, 0x181, 1, 4, 64);
        MONSTERSPAWN_SpawnAtUnit(pGame, pMonster, 0x185, 1, 4, 64);
        break;
    }

    case 42:
        MONSTERSPAWN_SpawnLinkedMinionsAtOwner(pGame, pMonster, 0x1C5, 1, 20, 20, 0);
        QUESTS_CreateChainRecord(pGame, pMonster, 0x1F);
        QUESTS_MonsterSpawn(pGame, pMonster);
        STATES_ToggleState(pMonster, 0x76, 1);
        break;

    case 43:
    case 44:
    case 45:
        QUESTS_CreateChainRecord(pGame, pMonster, 0x23);
        QUESTS_MonsterSpawn(pGame, pMonster);
        break;

    case 60:
    {
        AIGENERAL_SetOwnerData(pGame, pMonster, !pMonster ? -1 : pMonster->dwUnitId, 1, 1, 0);
        const int nMinionId = D2Common_11063(UNITS_GetRoom(pMonster), 0x1C5);
        MONSTERSPAWN_SpawnLinkedMinionsAtOwner(pGame, pMonster, nMinionId, 1, 10, 20, 64);
        QUESTS_CreateChainRecord(pGame, pMonster, 0x22);
        break;
    }

    case 62:
        MONSTERSPAWN_SpawnLinkedMinionsAtOwner(pGame, pMonster, 0x17D, 1, 20, 10, 64);
        break;

    default:
        break;
    }

    D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pMonster, 0x16, 1);

    return pMonster;
}
