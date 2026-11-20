#include "D2Game.h"
#include "D2Structs.h"



struct D2MonStatsTxt
{
    short nId;
    short nBaseId;
    char pad0x04[8];
    unsigned char nMonStatsFlags[4];
    char pad0x10[0x1F];
    unsigned char nMinGrp;
    unsigned char nMaxGrp;
    char pad0x31[0x1A8 - 0x31];
};

struct D2DataTablesStrc
{
    char pad0x00[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char pad0xA7C[4];
    int nMonStatsTxtRecordCount;
};

struct D2MonsterRegionStrc
{
    unsigned char nAct;
    char pad0x01[3];
    int nCount;
    char pad0x08[4];
    int nMonsterRegionLevel;
    char pad0x10[0x2B8 - 0x10];
    int nMonsterCount;
};

struct D2GameStrc
{
    char pad0x00[0x6D];
    unsigned char nDifficulty;
    char pad0x6E[0xA8 - 0x6E];
    unsigned int dwGameFrame;
    char pad0xAC[0xBC - 0xAC];
    int nActData[13];
    D2MonsterRegionStrc* pMonReg[1];
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const unsigned int gdwBitMasks[32];                                                                  // 0x006CE268

int __fastcall sub_0054DC40_FindSpawnPosition(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pCoordList, int nMonsterId, int* pX, int* pY, int a7); // 0x0054DC40
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnInCoordList(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pCoordList, int nX, int nY, int nMonsterId, int nMode, int a8, int a9); // 0x005B3040
int __fastcall MONSTERS_GetBaseIdFromMonsterId(int nMonsterId);                                             // 0x00463900
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                        // 0x0045C3E0
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnAtUnitInCoordList(D2GameStrc* pGame, D2RoomCoordListStrc* pCoordList, D2UnitStrc* pUnit, int nMonsterId, int a5, int a6, int a7); // 0x005B2F70
int __stdcall sub_0054DDC0_FindPosition(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int a3, int nClassId, D2UnkMonCreateStrc2* pCreate, int* pX, int* pY); // 0x0054DDC0
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag);                                // 0x005A0180
void __fastcall MONSTERUNIQUE_PromoteToChampion(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMods);           // 0x005A48C0
D2UnitStrc* __fastcall sub_005A43E0_QUESTS_SpawnMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* a3, int nMonsterId, int a5, int a6, int a7, int a8); // 0x005A43E0
int __stdcall QUESTS_CheckNotIntroQuest(D2GameStrc* pGame, int nQuestId);                                  // 0x005444B0
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int a7, int a8); // 0x005B2F20
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2MonsterRegionStrc* __fastcall MONSTERREGION_GetMonsterRegionFromLevelId(D2MonsterRegionStrc** ppMonsterRegion, int nLevelId); // 0x00547BB0

int __fastcall DATATBLS_GetSuperUniquesTxtRecordCount();                                                    // 0x00655710
D2UnitStrc* __fastcall D2GAME_SpawnSuperUnique_6FC6F690(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nSuperUniqueId); // 0x005A49B0
int __fastcall MONSTERCHOOSE_GetPresetMonsterId(D2GameStrc* pGame, D2MonsterRegionStrc* pMonsterRegion, D2ActiveRoomStrc* pRoom, D2MonStatsTxt** ppMonStatsTxtRecord, int a5, int a6); // 0x005BDE80
int __fastcall SKILLS_GetMonsterClassFromChain(int nMonsterId, int nChainIncrements);                      // 0x0054DA60
int __stdcall D2Common_11063(D2ActiveRoomStrc* pRoom, int nMonsterId);                                     // 0x0063EC70
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                   // 0x00451F80
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C390

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord_Inline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    return 0;
}

static __forceinline int MONSTERREGION_SanitizeMonsterId_Inline(int nMonsterId)
{
    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
        return -1;
    return nMonsterId;
}

// 0x0054E090
static __declspec(noinline) D2UnitStrc* __stdcall sub_0054E090_SpawnGroupAtPoint(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nMonsterId, int nX, int nY)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord_Inline(nMonsterId);
    unsigned char nMinGrp = pMonStatsTxtRecord->nMinGrp;
    const unsigned char nMaxGrp = pMonStatsTxtRecord->nMaxGrp;
    if (!nMinGrp || !nMaxGrp || nMaxGrp < nMinGrp)
        return 0;

    D2RoomCoordListStrc* pCoordList = D2Common_10096(pRoom, nX, nY);
    if (!pCoordList)
        return 0;

    D2UnitStrc* pMonster = MONSTERSPAWN_SpawnInCoordList(pGame, pRoom, pCoordList, nX, nY, nMonsterId, 1, -1, 0);
    if (!pMonster)
        return 0;

    --nMinGrp;
    for (int nCount = nMinGrp + ITEMS_RollLimitedRandomNumber(&pMonster->pSeed, (unsigned char)(nMaxGrp - 1) - nMinGrp + 1); nCount > 0; --nCount)
        MONSTERSPAWN_SpawnAtUnitInCoordList(pGame, pCoordList, pMonster, nMonsterId, 1, 3, 0);

    return pMonster;
}

// 0x0054E1E0
static __declspec(noinline) void __stdcall sub_0054E1E0_SpawnChampionMinions(D2RoomCoordListStrc* pCoordList, int nMonsterId, D2GameStrc* pGame, D2UnitStrc* pMonster)
{
    if (!MONSTERUNIQUE_CheckMonTypeFlag(pMonster, 4))
        return;

    const int nMinions = SEED_RollRandomNumber(&pMonster->pSeed) % 3 + 1;
    for (int i = 0; i < nMinions; ++i)
    {
        D2UnitStrc* pMinion = MONSTERSPAWN_SpawnAtUnitInCoordList(pGame, pCoordList, pMonster, nMonsterId, 1, 4, 0);
        if (pMinion)
            MONSTERUNIQUE_PromoteToChampion(pGame, pMinion, 0x10);
    }
}

// 0x0054E2A0
static __declspec(noinline) int sub_0054E2A0_GetFallenVariantForLevel(int nLevelId, int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord_Inline(nMonsterId);
    const int nBaseId = !pMonStatsTxtRecord ? nMonsterId : pMonStatsTxtRecord->nBaseId;

    switch (MONSTERREGION_SanitizeMonsterId_Inline(nBaseId))
    {
    case 0x13:
        switch (nLevelId)
        {
        case 6:
            return MONSTERREGION_SanitizeMonsterId_Inline(0x14);
        case 7:
        case 0xC:
        case 0x10:
            return MONSTERREGION_SanitizeMonsterId_Inline(0x15);
        }
        break;

    case 0x3A:
        switch (nLevelId)
        {
        case 6:
        case 7:
            return MONSTERREGION_SanitizeMonsterId_Inline(0x3B);
        case 0xC:
        case 0x10:
            return MONSTERREGION_SanitizeMonsterId_Inline(0x3C);
        }
        break;
    }

    return nMonsterId;
}

static int MONSTERREGION_CanRetryPresetSpawn(int nMonsterId); // 0x0054E3A0

// build: context MONSTERREGION_CanRetryPresetSpawn
static int MONSTERREGION_CanRetryPresetSpawn(int nMonsterId)
{
    switch (MONSTERREGION_SanitizeMonsterId_Inline(nMonsterId))
    {
    case 0xE5:
    case 0x121:
    case 0x122:
    case 0x123:
    case 0x124:
    case 0x125:
    case 0x188:
    case 0x189:
        return 0;
    }
    return 1;
}

// 0x0054E490
static __declspec(noinline) D2UnitStrc* __stdcall sub_0054E490_SpawnRegularPresetMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMode, int nClassId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord_Inline(nClassId);
    if (!pMonStatsTxtRecord)
        return 0;

    if (nClassId == 0x1B2)
    {
        --nX;
        if (!QUESTS_CheckNotIntroQuest(pGame, 0x20))
            nMode = 0xC;
    }

    if (sub_004638A0_CheckMonStats2Flag(nClassId, 0xD))
        return 0;

    int nFlags = 0;
    if (pMonStatsTxtRecord->nMonStatsFlags[0x12 >> 3] & gdwBitMasks[0x12 & 7])
        nFlags = 8;

    D2UnitStrc* pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nClassId, nMode, -1, nFlags);
    if (!pMonster)
    {
        if (!MONSTERREGION_CanRetryPresetSpawn(nClassId))
            return 0;

        pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nClassId, nMode, 4, nFlags);
        if (!pMonster)
            return 0;
    }

    if (sub_004638A0_CheckMonStats2Flag(nClassId, 0x12))
    {
        if (nClassId < sgptDataTables->nMonStatsTxtRecordCount && nClassId == 0x1B0)
            SUNIT_AllocUnitData(2, 0x23B, CLIENTS_GetUnitX(pMonster), CLIENTS_GetUnitY(pMonster), pGame, pRoom, 1, 0, 0);
        else if (MONSTERS_GetBaseIdFromMonsterId(nClassId) == 0x1B1)
            SUNIT_AllocUnitData(2, 0x23C, CLIENTS_GetUnitX(pMonster), CLIENTS_GetUnitY(pMonster), pGame, pRoom, 1, 0, 0);
    }

    return pMonster;
}

// 0x0054E600
D2UnitStrc* __fastcall D2GAME_SpawnPresetMonster_6FC66560(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nMode)
{
    if (nClassId < 0)
        return 0;

    D2UnitStrc* pMonster = 0;
    int bRegularId = 1;
    if (nClassId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        nClassId -= sgptDataTables->nMonStatsTxtRecordCount;
        const int nSuperUniques = DATATBLS_GetSuperUniquesTxtRecordCount();
        if (nClassId >= nSuperUniques)
        {
            nClassId -= nSuperUniques;
            bRegularId = 0;
        }
        else
        {
            return D2GAME_SpawnSuperUnique_6FC6F690(pGame, pRoom, nX, nY, nClassId);
        }
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);

    if (bRegularId == 1)
    {
        switch (MONSTERREGION_SanitizeMonsterId_Inline(nClassId))
        {
        case 0x1F2:
            if (QUESTS_CheckNotIntroQuest(pGame, 0x1F) && DUNGEON_GetLevelIdFromRoom(pRoom) == 0x6E)
                nClassId = MONSTERREGION_SanitizeMonsterId_Inline(0x1F3);
            break;
        case 0x205:
            if (QUESTS_CheckNotIntroQuest(pGame, 0x1F) && DUNGEON_GetLevelIdFromRoom(pRoom) == 0x6E)
                nClassId = MONSTERREGION_SanitizeMonsterId_Inline(0x206);
            break;
        }

        if (pGame->nDifficulty > 0)
        {
            switch (MONSTERREGION_SanitizeMonsterId_Inline(nClassId))
            {
            case 0x1C5:
            case 0x211:
                if (nLevelId == 0x6E)
                    return 0;
                break;
            }
        }

        return sub_0054E490_SpawnRegularPresetMonster(pGame, pRoom, nX, nY, nMode, nClassId);
    }

    switch (nClassId)
    {
    case 10:
    case 11:
    {
        int nFlags = 0;
        if (nClassId == 10)
            nFlags = 4;

        int nChainIncrements = 0;
        switch (nLevelId)
        {
        case 0x4C:
        case 0x4D:
        case 0x4E:
            nChainIncrements = 1;
            break;
        case 0x5C:
        case 0x5D:
            nChainIncrements = 2;
            break;
        case 0x56:
        case 0x57:
        case 0x58:
        case 0x59:
        case 0x5A:
        case 0x5B:
            nChainIncrements = 0;
            break;
        }

        const int nMonsterId = SKILLS_GetMonsterClassFromChain(MONSTERREGION_SanitizeMonsterId_Inline(0x105), nChainIncrements);
        pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nMonsterId, nMode, -1, nFlags);
        break;
    }
    case 5:
        pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, MONSTERREGION_SanitizeMonsterId_Inline(0x10B), nMode, -1, 0);
        break;
    case 2:
    {
        D2MonStatsTxt* pMonStatsTxtRecord;
        D2MonsterRegionStrc* pMonsterRegion = MONSTERREGION_GetMonsterRegionFromLevelId(pGame->pMonReg, DUNGEON_GetLevelIdFromPopulatedRoom(pRoom));
        const int nMonsterId = MONSTERCHOOSE_GetPresetMonsterId(pGame, pMonsterRegion, pRoom, &pMonStatsTxtRecord, 0, 1);
        if (!pMonStatsTxtRecord)
            return 0;

        sub_005A43E0_QUESTS_SpawnMonster(pGame, pRoom, 0, nMonsterId, 0, 0, 0, 1);
        break;
    }
    case 3:
    {
        D2MonStatsTxt* pMonStatsTxtRecord;
        D2MonsterRegionStrc* pMonsterRegion = MONSTERREGION_GetMonsterRegionFromLevelId(pGame->pMonReg, DUNGEON_GetLevelIdFromPopulatedRoom(pRoom));
        nClassId = MONSTERCHOOSE_GetPresetMonsterId(pGame, pMonsterRegion, pRoom, &pMonStatsTxtRecord, 0, 1);
        if (!pMonStatsTxtRecord)
            return 0;

        pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nClassId, nMode, -1, 0);
        if (!pMonster)
            break;

        MONSTERUNIQUE_PromoteToChampion(pGame, pMonster, 0x10);
        sub_0054E1E0_SpawnChampionMinions(0, nClassId, pGame, pMonster);
        break;
    }
    case 4:
        pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, 0x10A, nMode, -1, 0);
        break;
    case 8:
        pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, 0x11C, nMode, -1, 8);
        break;
    case 17:
    case 18:
    case 22:
    case 23:
    case 25:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    {
        int nAnimMode = nMode;
        int nMonsterId = 0;
        switch (nClassId)
        {
        case 17:
            nMonsterId = 0x13;
            break;
        case 18:
            nMonsterId = 0x3A;
            break;
        case 22:
            nMonsterId = 0x8D;
            break;
        case 23:
            nMonsterId = 0x116;
            break;
        case 29:
            nMonsterId = 0x1C5;
            nAnimMode = 12;
            break;
        case 30:
            nMonsterId = nLevelId == 0x6E ? 0x211 : 0x1EC;
            nAnimMode = 12;
            break;
        case 31:
            nMonsterId = 0x20A;
            nAnimMode = 12;
            break;
        case 32:
            nMonsterId = 0x1B6;
            nAnimMode = 12;
            break;
        case 25:
        case 27:
        case 28:
            return 0;
        }

        nMonsterId = sub_0054E2A0_GetFallenVariantForLevel(nLevelId, D2Common_11063(pRoom, sub_004E6C50_ValidateMonsterId(nMonsterId)));

        int nFlags = 0;
        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nMonsterId);
        if (pMonStatsTxtRecord->nMonStatsFlags[0x12 >> 3] & gdwBitMasks[0x12 & 7])
            nFlags = 8;

        pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nMonsterId, nAnimMode, -1, nFlags);
        if (!pMonster)
        {
            pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nMonsterId, nAnimMode, 4, nFlags);
            if (!pMonster)
                break;
        }

        if (MONSTERS_GetBaseIdFromMonsterId(nMonsterId) == 0x1B6)
        {
            const int nExpireFrame = SEED_RollLimitedRandomNumber(&pMonster->pSeed, 50) + pGame->dwGameFrame + 250;
            EVENT_SetEvent(pGame, pMonster, 7, nExpireFrame, 0, 0);
        }

        if (pMonster && nAnimMode == 12)
            pMonster->dwFlags |= 0x2000000;
        break;
    }
    case 24:
    case 26:
    {
        if (pGame->nDifficulty > 0)
            return 0;

        int nMonsterId = 0;
        switch (nClassId)
        {
        case 24:
            nMonsterId = nLevelId == 0x6E ? 0x211 : 0x1EC;
            break;
        case 26:
            nMonsterId = 0x1C5;
            break;
        }

        nMonsterId = D2Common_11063(pRoom, sub_004E6C50_ValidateMonsterId(nMonsterId));
        sub_0054E090_SpawnGroupAtPoint(pGame, pRoom, nMonsterId, nX, nY);
        break;
    }
    }

    return pMonster;
}
