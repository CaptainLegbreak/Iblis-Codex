#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"

struct D2DrlgCoordsStrc;
struct D2SpawnAreaStrc;
struct D2SeedStrc;
struct D2MonStatsTxt;
struct D2MonsterRegionStrc;

struct D2DrlgCoordsStrc { int nSubtileX; int nSubtileY; int nSubtileWidth; int nSubtileHeight; int nTileXPos; int nTileYPos; int nTileWidth; int nTileHeight; };

struct D2SpawnAreaStrc { char unk0x00[0x10]; tagRECT tRect; };
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730
void __stdcall sub_M96_UseBounds_0054DAC0(int nX, int nY, int nWidth, int nHeight);





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
    char pad0x00[0xBC];
    int nActData[13];
    D2MonsterRegionStrc* pMonReg[1];
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned int gdwBitMasks[32]; // 0x006CE268
int __fastcall sub_0054DC40_FindSpawnPosition(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pCoordList, int nMonsterId, int* pX, int* pY, int a7); // 0x0054DC40
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnInCoordList(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pCoordList, int nX, int nY, int nMonsterId, int nMode, int a8, int a9); // 0x005B3040
int __fastcall MONSTERS_GetBaseIdFromMonsterId(int nMonsterId); // 0x00463900
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnAtUnitInCoordList(D2GameStrc* pGame, D2RoomCoordListStrc* pCoordList, D2UnitStrc* pUnit, int nMonsterId, int a5, int a6, int a7); // 0x005B2F70
int __stdcall sub_0054DDC0_FindPosition(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int a3, int nClassId, D2UnkMonCreateStrc2* pCreate, int* pX, int* pY); // 0x0054DDC0
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180
void __fastcall MONSTERUNIQUE_PromoteToChampion(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMods); // 0x005A48C0
D2UnitStrc* __fastcall sub_005A43E0_QUESTS_SpawnMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* a3, int nMonsterId, int a5, int a6, int a7, int a8); // 0x005A43E0
int __stdcall QUESTS_CheckNotIntroQuest(D2GameStrc* pGame, int nQuestId); // 0x005444B0
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int a7, int a8); // 0x005B2F20
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2MonsterRegionStrc* __fastcall MONSTERREGION_GetMonsterRegionFromLevelId(D2MonsterRegionStrc** ppMonsterRegion, int nLevelId); // 0x00547BB0
static int MONSTERREGION_CanRetryPresetSpawn(int nMonsterId); // 0x0054E3A0

// 0x0054DAC0
static void __stdcall sub_0054DAC0_GetSpawnBounds(D2ActiveRoomStrc* pRoom, int* pWidth, D2SpawnAreaStrc* pArea, int* pX, int* pY, int* pHeight)
{
    if (!pArea)
    {
        D2DrlgCoordsStrc coords;
        DUNGEON_GetRoomCoordinates(pRoom, &coords);
        *pX = coords.nSubtileX + 1;
        *pY = coords.nSubtileY + 1;
        *pWidth = coords.nSubtileWidth - 1;
        *pHeight = coords.nSubtileHeight - 1;
    }
    else
    {
        tagRECT rect;
        CopyRect(&rect, &pArea->tRect);
        DUNGEON_GameTileToSubtileCoords(&rect.left, &rect.top);
        DUNGEON_GameTileToSubtileCoords(&rect.right, &rect.bottom);
        *pX = rect.left + 1;
        *pY = rect.top + 1;
        *pWidth = rect.right - *pX;
        *pHeight = rect.bottom - *pY;
    }
}

void __fastcall sub_M96_Emit_0054DAC0(void* pGame, D2ActiveRoomStrc* pRoom, D2SpawnAreaStrc* pArea)
{
    int nX, nY, nWidth, nHeight;
    sub_0054DAC0_GetSpawnBounds(pRoom, &nWidth, pArea, &nX, &nY, &nHeight);
    sub_M96_UseBounds_0054DAC0(nX, nY, nWidth, nHeight);
}

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

// 0x0054DF80
static __declspec(noinline) D2UnitStrc* __stdcall sub_0054DF80_SpawnGroupInCoordList(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pCoordList, unsigned char nMin, unsigned char nMax, int nMonsterId)
{
    if (!nMin || !nMax || nMax < nMin)
        return 0;

    int nX;
    int nY;
    if (!sub_0054DC40_FindSpawnPosition(pGame, pRoom, pCoordList, nMonsterId, &nX, &nY, 1))
        return 0;

    D2UnitStrc* pMonster = MONSTERSPAWN_SpawnInCoordList(pGame, pRoom, pCoordList, nX, nY, nMonsterId, 1, -1, 0);
    if (!pMonster)
        return 0;

    --nMin;
    --nMax;
    if (sub_004638A0_CheckMonStats2Flag(nMonsterId, 0x12) && MONSTERS_GetBaseIdFromMonsterId(nMonsterId) == 0x210)
        SUNIT_AllocUnitData(2, 0x232, CLIENTS_GetUnitX(pMonster), CLIENTS_GetUnitY(pMonster), pGame, pRoom, 1, 0, 0);

    for (int nCount = nMin + ITEMS_RollLimitedRandomNumber(&pMonster->pSeed, nMax - nMin + 1); nCount > 0; --nCount)
        MONSTERSPAWN_SpawnAtUnitInCoordList(pGame, pCoordList, pMonster, nMonsterId, 1, 3, 0);

    return pMonster;
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

// 0x0054E190
static __declspec(noinline) int __stdcall sub_0054E190_SpawnMonsterAtFreePosition(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, D2UnkMonCreateStrc2* pCreate)
{
    int nX;
    int nY;
    if (!sub_0054DDC0_FindPosition(pGame, pRoom, 0, nClassId, pCreate, &nX, &nY))
        return 0;

    return sub_005B3270(pGame, pRoom, nX, nY, 0, nClassId, 1, pCreate, 0);
}

// 0x0054E1E0
static void __stdcall sub_0054E1E0_SpawnChampionMinions(D2RoomCoordListStrc* pCoordList, int nMonsterId, D2GameStrc* pGame, D2UnitStrc* pMonster)
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

// 0x0054E260
static __declspec(noinline) int __stdcall sub_0054E260_SpawnMonsterWithMinions(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pCoordList, int nMonsterId)
{
    D2UnitStrc* pMonster = sub_005A43E0_QUESTS_SpawnMonster(pGame, pRoom, pCoordList, nMonsterId, 1, 0, 0, 1);
    if (!pMonster)
        return 0;

    sub_0054E1E0_SpawnChampionMinions(pCoordList, nMonsterId, pGame, pMonster);
    return 1;
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

// 0x0054EBC0
static __declspec(noinline) int sub_0054EBC0_CanPopulateRoom(D2ActiveRoomStrc* pRoom, D2GameStrc* pGame)
{
    D2MonsterRegionStrc* pRegion = MONSTERREGION_GetMonsterRegionFromLevelId(pGame->pMonReg, DUNGEON_GetLevelIdFromRoom(pRoom));
    if (!pRegion)
        return 0;

    ++pRegion->nCount;
    const int nLevelId = DUNGEON_GetLevelIdFromPopulatedRoom(pRoom);
    if (!nLevelId)
        return 0;

    if (pRegion->nMonsterRegionLevel < 0)
        pRegion->nMonsterRegionLevel = sub_0061ABF0(pGame->nActData[pRegion->nAct], nLevelId);

    if (!pRegion->nMonsterCount)
        return 0;

    if (!pRegion->nMonsterRegionLevel)
        return 0;

    if (DUNGEON_GetLevelIdFromRoom(pRoom) == 0x6C)
    {
        if (sub_005B5210(pGame))
            return 0;
    }

    return 1;
}

D2UnitStrc* __fastcall sub_A12_Emit_0054DF80(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pCoordList, int nMonsterId, unsigned char nMin, unsigned char nMax)
{
    return sub_0054DF80_SpawnGroupInCoordList(pGame, pRoom, pCoordList, nMin, nMax, nMonsterId);
}

D2UnitStrc* __fastcall sub_A12_Emit_0054E090(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nMonsterId, int nX, int nY)
{
    return sub_0054E090_SpawnGroupAtPoint(pGame, pRoom, nMonsterId, nX, nY);
}

int __fastcall sub_A12_Emit_0054E190(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, D2UnkMonCreateStrc2* pCreate)
{
    return sub_0054E190_SpawnMonsterAtFreePosition(pGame, pRoom, nClassId, pCreate);
}

int __fastcall sub_A12_Emit_0054E260(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pCoordList, int nMonsterId)
{
    return sub_0054E260_SpawnMonsterWithMinions(pGame, pRoom, pCoordList, nMonsterId);
}

void __fastcall sub_A12_Emit_0054E1E0(D2GameStrc* pGame, D2UnitStrc* pMonster, int nMonsterId)
{
    sub_0054E1E0_SpawnChampionMinions(0, nMonsterId, pGame, pMonster);
}

int __fastcall sub_A12_Emit_0054E2A0(int nMonsterId, int nLevelId)
{
    return sub_0054E2A0_GetFallenVariantForLevel(nLevelId, nMonsterId);
}

D2UnitStrc* __fastcall sub_A12_Emit_0054E490(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nMode)
{
    return sub_0054E490_SpawnRegularPresetMonster(pGame, pRoom, nX, nY, nMode, nClassId);
}

int __fastcall sub_A12_Emit_0054EBC0(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom)
{
    return sub_0054EBC0_CanPopulateRoom(pRoom, pGame);
}

// 0x0054E3A0
static int MONSTERREGION_CanRetryPresetSpawn(int nMonsterId)
{
    switch (MONSTERREGION_SanitizeMonsterId_Inline(nMonsterId))
    {
    case 0xE5:
    case 0x11C:
    case 0x11D:
    case 0x11E:
    case 0x11F:
    case 0x120:
    case 0x188:
    case 0x189:
        return 0;
    }
    return 1;
}

D2UnitStrc* __fastcall sub_H05_Emit_0054DF80(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pCoordList, int nMonsterId, unsigned char nMin, unsigned char nMax)
{
    return sub_0054DF80_SpawnGroupInCoordList(pGame, pRoom, pCoordList, nMin, nMax, nMonsterId);
}

D2UnitStrc* __fastcall sub_H05_Emit_0054E090(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nMonsterId, int nX, int nY)
{
    return sub_0054E090_SpawnGroupAtPoint(pGame, pRoom, nMonsterId, nX, nY);
}

int __fastcall sub_H05_Emit_0054E190(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, D2UnkMonCreateStrc2* pCreate)
{
    return sub_0054E190_SpawnMonsterAtFreePosition(pGame, pRoom, nClassId, pCreate);
}

int __fastcall sub_H05_Emit_0054E260(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pCoordList, int nMonsterId)
{
    return sub_0054E260_SpawnMonsterWithMinions(pGame, pRoom, pCoordList, nMonsterId);
}

void __fastcall sub_H05_Emit_0054E1E0(D2GameStrc* pGame, D2UnitStrc* pMonster, int nMonsterId)
{
    sub_0054E1E0_SpawnChampionMinions(0, nMonsterId, pGame, pMonster);
}

int __fastcall sub_H05_Emit_0054E2A0(int nMonsterId, int nLevelId)
{
    return sub_0054E2A0_GetFallenVariantForLevel(nLevelId, nMonsterId);
}

D2UnitStrc* __fastcall sub_H05_Emit_0054E490(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nMode)
{
    return sub_0054E490_SpawnRegularPresetMonster(pGame, pRoom, nX, nY, nMode, nClassId);
}

int __fastcall sub_H05_Emit_0054EBC0(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom)
{
    return sub_0054EBC0_CanPopulateRoom(pRoom, pGame);
}
