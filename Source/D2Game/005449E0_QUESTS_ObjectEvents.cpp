struct D2ActiveRoomStrc;

struct D2QuestDataStrc
{
    int nQuestNo;
    char unk0x04[240];
    D2QuestDataStrc* pPrev;
};
struct D2QuestInfoStrc
{
    D2QuestDataStrc* pLastQuest;
};
struct D2GameStrc
{
    char unk0x00[4340];
    D2QuestInfoStrc* pQuestControl;
};
struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[8];
    int dwAnimMode;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

void __fastcall ACT5Q2_UpdatePortalMode(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit);                     // 0x00588CA0
void __fastcall sub_00589540_RemoveNihlathakFromTown(D2GameStrc* pGame, D2UnitStrc* pUnit);                  // 0x00589540
void __fastcall ACT5Q3_SpawnFrozenDrehya(D2GameStrc* pGame, D2UnitStrc* pUnit);                              // 0x0058A500
void __fastcall ACT5Q3_UpdateDrehyaPortalMode(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit);               // 0x0058A730
void __fastcall sub_0058B940_RetryDrehyaPortal(D2GameStrc* pGame, D2UnitStrc* pUnit);                        // 0x0058B940
void __fastcall ACT5Q5_SpawnAncientMonsters(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit);                 // 0x0058C0E0
void __fastcall ACT1Q4_SpawnCainInTristram(D2GameStrc* pGame, D2UnitStrc* pUnit);                            // 0x00593290
void __fastcall ACT1Q4_UpdatePortalInTown(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit);                   // 0x005942C0
void __fastcall sub_00594630_QuestGoldDrop(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit);                  // 0x00594630
void __fastcall sub_005956C0_ACT1Q5_SpawnChestMissilesAndEvent(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x005956C0
void __fastcall ACT2Q4_InitializeHaremBlockerObject(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit);         // 0x0059B710
D2UnitStrc* __fastcall sub_6FC68D70(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags); // 0x005B23C0
void __fastcall sub_005B5750(D2GameStrc* pGame, D2UnitStrc* pUnit);                                          // 0x005B5750
void __fastcall sub_005B6710(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit);                                // 0x005B6710
void __fastcall sub_005B85E0_OpenSewerStairs(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit);                // 0x005B85E0
void __fastcall sub_005BCAC0(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit);                                // 0x005BCAC0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                           // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                                // 0x00620BB0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                            // 0x00624690
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                              // 0x006427F0

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x00543640
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId)
{
    D2QuestInfoStrc* pQuestControl = pGame->pQuestControl;
    D2_ASSERT(nId >= 0, 119);

    if (pQuestControl)
    {
        for (D2QuestDataStrc* pQuestData = pQuestControl->pLastQuest; pQuestData; pQuestData = pQuestData->pPrev)
        {
            if (pQuestData->nQuestNo == nId)
            {
                return pQuestData;
            }
        }
    }

    return 0;
}

// 0x005449E0
void __fastcall QUESTS_ObjectEvents(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    const int nClassId = !pUnit ? -1 : pUnit->dwClassId;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);

    switch (nClassId)
    {
    case 131:
    {
        if (pRoom)
        {
            if (pUnit && pUnit->dwAnimMode == 1)
            {
                UNITS_ChangeAnimMode(pUnit, 2);
            }

            switch (DUNGEON_GetLevelIdFromRoom(pRoom))
            {
            case 108:
                sub_005B5750(pGame, pUnit);
                break;

            case 76:
                sub_6FC68D70(pGame, pUnit, 301, 1, -1, 0);
                break;
            }
        }
        break;
    }
    case 122:
    {
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 11);
        if (pQuestData)
        {
            ACT2Q4_InitializeHaremBlockerObject(pQuestData, pUnit);
        }
        break;
    }
    case 26:
    {
        ACT1Q4_SpawnCainInTristram(pGame, pUnit);
        break;
    }
    case 189:
    {
        const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
        if (!DRLG_GetActNoFromLevelId(nLevelId))
        {
            D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 4);
            if (pQuestData)
            {
                ACT1Q4_UpdatePortalInTown(pQuestData, pUnit);
            }
        }
        else if (nLevelId != 109 && nLevelId < 113)
        {
            D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 32);
            if (pQuestData)
            {
                ACT5Q2_UpdatePortalMode(pQuestData, pUnit);
            }
        }
        else
        {
            D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 33);
            if (pQuestData)
            {
                ACT5Q3_UpdateDrehyaPortalMode(pQuestData, pUnit);
            }
        }
        break;
    }
    case 341:
    {
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 20);
        if (pQuestData)
        {
            sub_005BCAC0(pQuestData, pUnit);
        }
        break;
    }
    case 268:
    {
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 4);
        if (pQuestData)
        {
            sub_00594630_QuestGoldDrop(pQuestData, pUnit);
        }
        break;
    }
    case 367:
    {
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 16);
        if (pQuestData)
        {
            sub_005B85E0_OpenSewerStairs(pQuestData, pUnit);
        }
        break;
    }
    case 376:
    {
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 24);
        if (pQuestData)
        {
            sub_005B6710(pQuestData, pUnit);
        }
        break;
    }
    case 474:
    case 475:
    case 476:
    {
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 35);
        if (pQuestData)
        {
            ACT5Q5_SpawnAncientMonsters(pQuestData, pUnit);
        }
        break;
    }
    case 461:
    {
        sub_00589540_RemoveNihlathakFromTown(pGame, pUnit);
        break;
    }
    case 459:
    {
        sub_0058B940_RetryDrehyaPortal(pGame, pUnit);
        break;
    }
    case 460:
    {
        ACT5Q3_SpawnFrozenDrehya(pGame, pUnit);
        break;
    }
    case 371:
    {
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 5);
        if (pQuestData)
        {
            sub_005956C0_ACT1Q5_SpawnChestMissilesAndEvent(pQuestData, pUnit);
        }
        break;
    }
    }
}
