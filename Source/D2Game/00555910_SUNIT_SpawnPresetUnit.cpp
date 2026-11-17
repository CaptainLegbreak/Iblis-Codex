struct D2GameStrc;
struct D2MapAIStrc;
struct D2UnitStrc;
struct D2ActiveRoomStrc;

struct D2PresetUnitStrc
{
    int nMode;
    int nIndex;
    int nXpos;
    D2PresetUnitStrc* pNext;
    D2MapAIStrc* pMapAI;
    int nUnitType;
    int nYpos;
    unsigned int bSpawned;
};

struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
};

void __fastcall QUESTS_MapPresetSpawn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MapAIStrc* pMapAI);          // 0x00545C90
D2UnitStrc* __fastcall SUNIT_CreatePresetUnit(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nUnitType, int nClassId, int nX, int nY, int nMode, int nUnitFlags); // 0x005557D0
D2MapAIStrc* __stdcall AIGENERAL_GetMapAiFromUnit(D2UnitStrc* pUnit);                                       // 0x0058F000
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);              // 0x00619730
D2MapAIStrc* __fastcall DRLGPRESET_ChangeMapAI(D2MapAIStrc** ppMapAI1, D2MapAIStrc* pMapAI2);             // 0x00666120

#define UNIT_MONSTER 1
#define UNIT_OBJECT 2

// 0x00555910
void __fastcall SUNIT_SpawnPresetUnit(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2PresetUnitStrc* pPresetUnit)
{
    D2DrlgCoordsStrc pCoord;

    DUNGEON_GetRoomCoordinates(pRoom, &pCoord);

    const int nX = pPresetUnit->nXpos + pCoord.nSubtileX;
    const int nY = pPresetUnit->nYpos + pCoord.nSubtileY;
    D2UnitStrc* pUnit = SUNIT_CreatePresetUnit(pGame, pRoom, pPresetUnit->nUnitType, pPresetUnit->nIndex, nX, nY, pPresetUnit->nMode, 0);
    if (!pUnit)
    {
        return;
    }

    if (pPresetUnit->nUnitType == UNIT_MONSTER)
    {
        D2MapAIStrc** ppPresetMapAI = &pPresetUnit->pMapAI;
        D2MapAIStrc* pMapAI = AIGENERAL_GetMapAiFromUnit(pUnit);
        if (*ppPresetMapAI)
        {
            DRLGPRESET_ChangeMapAI(ppPresetMapAI, pMapAI);
        }
    }
    else if (pPresetUnit->nUnitType == UNIT_OBJECT)
    {
        QUESTS_MapPresetSpawn(pGame, pUnit, pPresetUnit->pMapAI);
    }
}
