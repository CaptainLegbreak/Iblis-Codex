struct D2ActiveRoomStrc;
struct D2MapAIStrc;
struct D2GameStrc { char unk0x00[0x7C]; unsigned int dwInitSeed; char unk0x80[0x1DE4 - 0x80]; unsigned int dwUberSandsCounter; };
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

enum D2C_M108SUnitConstants
{
    UNIT_MONSTER = 1,
    UNIT_OBJECT = 2,
    LEVEL_PANDEMONIUMRUN1 = 133,
    LEVEL_PANDEMONIUMRUN2 = 134,
    LEVEL_PANDEMONIUMRUN3 = 135,
    LEVEL_PANDEMONIUMFINALE = 136,
    OBJECT_GOLD_PLACEHOLDER = 26,
    OBJECT_WIRTSBODY = 268,
    OBJECT_CAINGIBBET = 269,
    OBJECT_SPARKLY_CHEST = 397,
    OBJECT_VALLEY_WAYPOINT = 402,
};

D2PresetUnitStrc* __stdcall DUNGEON_GetPresetUnitsFromRoom(D2ActiveRoomStrc* pRoom);                       // 0x00619FD0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
void __fastcall SUNIT_SpawnPresetUnit(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2PresetUnitStrc* pPresetUnit); // 0x00555910

// 0x005559A0
void __fastcall SUNIT_SpawnPresetUnitsInRoom(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom)
{
    if (!pGame)
        return;

    D2PresetUnitStrc* pPresetUnit = DUNGEON_GetPresetUnitsFromRoom(pRoom);
    int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);

    for (D2PresetUnitStrc* i = pPresetUnit; i; i = i->pNext)
    {
        if (i->nUnitType != UNIT_MONSTER && !(i->bSpawned & 1))
        {
            if (nLevelId == LEVEL_PANDEMONIUMFINALE)
            {
                if (i->nUnitType != UNIT_OBJECT || (i->nIndex != OBJECT_WIRTSBODY && i->nIndex != OBJECT_GOLD_PLACEHOLDER && i->nIndex != OBJECT_CAINGIBBET))
                    SUNIT_SpawnPresetUnit(pGame, pRoom, i);

                if (i->nIndex == OBJECT_GOLD_PLACEHOLDER)
                    DUNGEON_GetLevelIdFromRoom(pRoom);
            }
            else if (nLevelId == LEVEL_PANDEMONIUMRUN1)
            {
                if (i->nUnitType != UNIT_OBJECT || i->nIndex != OBJECT_SPARKLY_CHEST)
                    SUNIT_SpawnPresetUnit(pGame, pRoom, i);
            }
            else if (nLevelId == LEVEL_PANDEMONIUMRUN2)
            {
                if (i->nUnitType != UNIT_OBJECT)
                {
                    SUNIT_SpawnPresetUnit(pGame, pRoom, i);
                }
                else if (i->nIndex != OBJECT_VALLEY_WAYPOINT)
                {
                    pGame->dwUberSandsCounter++;
                    if (pGame->dwUberSandsCounter != (pGame->dwInitSeed % 3) + 3)
                        SUNIT_SpawnPresetUnit(pGame, pRoom, i);
                }
            }
            else if (nLevelId == LEVEL_PANDEMONIUMRUN3)
            {
                if (i->nUnitType != UNIT_OBJECT || i->nIndex != OBJECT_SPARKLY_CHEST)
                    SUNIT_SpawnPresetUnit(pGame, pRoom, i);
            }
            else
            {
                SUNIT_SpawnPresetUnit(pGame, pRoom, i);
            }
        }
    }

    D2PresetUnitStrc* pMonster = pPresetUnit;
    if (nLevelId == LEVEL_PANDEMONIUMFINALE)
        return;

    for (; pMonster; pMonster = pMonster->pNext)
    {
        if (pMonster->nUnitType == UNIT_MONSTER && !(pMonster->bSpawned & 1))
            SUNIT_SpawnPresetUnit(pGame, pRoom, pMonster);
    }
}
