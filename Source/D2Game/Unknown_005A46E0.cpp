#include "D2Game.h"
#include "D2Structs.h"

#define UNIT_MONSTER 1
#define MONTYPEFLAG_MINION 0x10
#define MONSTERDATA_UMODS_OFFSET 0x1C

struct D2MonsterDataStrc
{
    char unk0x00[0x16];
    unsigned short nTypeFlag;
    unsigned int dwDurielFlag;
    unsigned char nMonUmod[10];
};


typedef void (__fastcall* UModInitFunc)(D2UnitStrc* pUnit, int nUMod, int bUnique);

extern UModInitFunc gpUModInitFunctions_0073C008[];                                                         // 0x0073C008

int __fastcall MONSTERREGION_FindSpawnLocation(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pRoomCoordList, int nClassId, int* pX, int* pY, int bAvoidWarps); // 0x0054DC40

static __forceinline void SetMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag, int bSet)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
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

static __forceinline void InitUMod(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    UModInitFunc pfnInit = gpUModInitFunctions_0073C008[nUMod];
    if (pfnInit)
    {
        pfnInit(pUnit, nUMod, bUnique);
    }
}

// 0x005A46E0
D2UnitStrc* __fastcall sub_6FC6FDC0(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nClassId, int nUnitGUID, unsigned char* pUMods)
{
    D2UnitStrc* pMonster = MONSTERSPAWN_SpawnWithUnitId(pGame, pRoom, nX, nY, nClassId, 1, nUnitGUID, -1, 98);
    if (!pMonster)
    {
        pMonster = MONSTERSPAWN_SpawnWithUnitId(pGame, pRoom, nX, nY, nClassId, 1, nUnitGUID, 4, 98);
        if (!pMonster && MONSTERREGION_FindSpawnLocation(pGame, pRoom, 0, nClassId, &nX, &nY, 1))
        {
            pMonster = MONSTERSPAWN_SpawnWithUnitId(pGame, pRoom, nX, nY, nClassId, 1, nUnitGUID, -1, 98);
        }
    }

    if (!pMonster)
    {
        return 0;
    }

    unsigned char* pMonUMods = 0;
    if (pMonster->dwUnitType == UNIT_MONSTER)
    {
        pMonUMods = (unsigned char*)pMonster->pMonsterData;
    }
    pMonUMods = !pMonUMods ? 0 : pMonUMods + MONSTERDATA_UMODS_OFFSET;
    for (int i = 0; i < 9; ++i)
    {
        pMonUMods[i] = pUMods[i];
    }

    SetMonTypeFlag(pMonster, MONTYPEFLAG_MINION, 1);

    int nBaseUMods[4] = { 1, 2, 3, 4 };
    for (int i = 0; i < 4; ++i)
    {
        InitUMod(pMonster, nBaseUMods[i], 0);
    }

    for (int i = 0; i < 9; ++i)
    {
        InitUMod(pMonster, pMonUMods[i], 0);
    }

    return pMonster;
}
