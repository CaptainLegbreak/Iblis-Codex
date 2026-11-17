enum
{
    UNIT_MONSTER = 1,
};

enum
{
    MONMODE_DEAD = 12,
};

enum
{
    MONSTER_DREHYAICED = 0x20F,
};

enum
{
    STAT_HITPOINTS = 6,
};

struct D2GameStrc;
struct D2MonsterInteractStrc;

struct D2MonsterDataStrc
{
    char unk0x00[0x30];
    D2MonsterInteractStrc* pMonInteract;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
};

struct D2AiCmdStrc
{
    D2AiCmdStrc* pNextCmd;
    D2AiCmdStrc* pPrevCmd;
    int nCmdParam[5];
};

int __fastcall AITACTICS_ChangeModeAndTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY); // 0x005DDFC0
int __fastcall MONSTERAI_HasInteractUnit(D2MonsterInteractStrc* pMonInteract);                              // 0x00572DC0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2AiCmdStrc* __fastcall AIGENERAL_SetCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCmdParam, int bSet); // 0x0058EFA0
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer);                  // 0x00627260
int __fastcall ACT1Q4_UpdateCainPortalCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit);                    // 0x005944B0
void __fastcall ACT1Q4_SpawnCainPortalInTown(D2GameStrc* pGame, D2UnitStrc* pUnit);                        // 0x005944F0
int __fastcall ACT5Q3_InitializeDrehyaPortalCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit);              // 0x0058A940
void __fastcall sub_6FCB53D0(D2GameStrc* pGame, D2UnitStrc* pUnit);                                        // 0x0058A980

// 0x005E7350
int __fastcall sub_005E7350_StopUnlessInteracting(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2MonsterInteractStrc* pMonInteract = (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData) ? pUnit->pMonsterData->pMonInteract : 0;
    if (!MONSTERAI_HasInteractUnit(pMonInteract))
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return 1;
    }

    return 0;
}

// 0x005E77A0
int __fastcall AITHINK_SpawnNpcPortal(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pAiTickParam)
{
    D2AiCmdStrc* pCurrentAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 3, 0);

    if (!pCurrentAiCmd || pCurrentAiCmd->nCmdParam[1] || pCurrentAiCmd->nCmdParam[2])
    {
        return 0;
    }

    pCurrentAiCmd->nCmdParam[1] = CLIENTS_GetUnitX(pUnit) + 3;
    pCurrentAiCmd->nCmdParam[2] = CLIENTS_GetUnitY(pUnit) + 3;

    int (__fastcall* pfUpdatePortalCoordinates)(D2GameStrc*, D2UnitStrc*) = ACT1Q4_UpdateCainPortalCoordinates;
    void (__fastcall* pfSpawnPortal)(D2GameStrc*, D2UnitStrc*) = ACT1Q4_SpawnCainPortalInTown;
    if (pUnit && pUnit->dwClassId == MONSTER_DREHYAICED)
    {
        pfUpdatePortalCoordinates = ACT5Q3_InitializeDrehyaPortalCoordinates;
        pfSpawnPortal = sub_6FCB53D0;
    }

    if (!pfUpdatePortalCoordinates(pGame, pUnit))
    {
        pfSpawnPortal(pGame, pUnit);
        STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, 0, 0);
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, MONMODE_DEAD, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit));
    }

    pCurrentAiCmd->nCmdParam[3] = 1;
    pCurrentAiCmd->nCmdParam[4] = 0;
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 1);
    return 1;
}
