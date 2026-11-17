struct D2UnitStrc;
struct D2GameStrc { char unk0x00[0xA8]; int dwGameFrame; };
struct D2CoordStrc { int nX; int nY; };
struct D2QuestDataStrc { char unk0x00[0x18]; void* pQuestDataEx; };
struct D2QuestSpawnStrc { char unk0x00[0x24]; D2CoordStrc tSpawnCoords[3]; };
struct D2DataTablesStrc { char unk0x00[0xB28]; unsigned short wSpawnIds[3]; };
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
D2UnitStrc* __fastcall QUESTS_SpawnMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2CoordStrc* pPosition, int nType, int nIndex); // 0x00545C30
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

// 0x005B5750
void __fastcall sub_005B5750_SpawnQuestMonster(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2CoordStrc tCoords;
    UNITS_GetCoords(pUnit, &tCoords);
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 23);
    if (!pQuestData)
    {
        return;
    }
    D2QuestSpawnStrc* pQuestDataEx = (D2QuestSpawnStrc*)pQuestData->pQuestDataEx;
    D2UnitStrc* pMonster;
    if (tCoords.nX == pQuestDataEx->tSpawnCoords[0].nX && tCoords.nY == pQuestDataEx->tSpawnCoords[0].nY)
    {
        pMonster = QUESTS_SpawnMonster(pGame, pUnit, &pQuestDataEx->tSpawnCoords[0], 2, sgptDataTables->wSpawnIds[0]);
    }
    else if (tCoords.nX == pQuestDataEx->tSpawnCoords[1].nX)
    {
        if (tCoords.nY == pQuestDataEx->tSpawnCoords[1].nY)
        {
            pMonster = QUESTS_SpawnMonster(pGame, pUnit, &pQuestDataEx->tSpawnCoords[1], 2, sgptDataTables->wSpawnIds[1]);
        }
        else if (tCoords.nX == pQuestDataEx->tSpawnCoords[2].nX && tCoords.nY == pQuestDataEx->tSpawnCoords[2].nY)
        {
            const int nMonId = sgptDataTables->wSpawnIds[2];
            pMonster = QUESTS_SpawnMonster(pGame, pUnit, &pQuestDataEx->tSpawnCoords[2], 2, nMonId);
        }
        else
        {
            return;
        }
        if (!pMonster)
        {
            EVENT_SetEvent(pGame, pUnit, 7, pGame->dwGameFrame + 10, 0, 0);
        }
        return;
    }
    else if (tCoords.nX == pQuestDataEx->tSpawnCoords[2].nX && tCoords.nY == pQuestDataEx->tSpawnCoords[2].nY)
    {
        const int nMonId = sgptDataTables->wSpawnIds[2];
        pMonster = QUESTS_SpawnMonster(pGame, pUnit, &pQuestDataEx->tSpawnCoords[2], 2, nMonId);
    }
    else
    {
        return;
    }
    if (!pMonster)
    {
        EVENT_SetEvent(pGame, pUnit, 7, pGame->dwGameFrame + 10, 0, 0);
    }
}
