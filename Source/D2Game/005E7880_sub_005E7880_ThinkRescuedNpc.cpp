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
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, unsigned short nLayer);                  // 0x00627260
void __fastcall ACT1Q4_SpawnCainPortalInTown(D2GameStrc* pGame, D2UnitStrc* pUnit);                        // 0x005944F0
void __fastcall sub_6FCB53D0(D2GameStrc* pGame, D2UnitStrc* pUnit);                                        // 0x0058A980

struct D2AiTickParamStrc;
struct D2CoordStrc { int nX; int nY; };
int __fastcall AITHINK_SpawnNpcPortal(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pTick); // 0x005E77A0
void __fastcall sub_0058AA10_ACT5Q3_UpdateStatusOnActivate(D2GameStrc* pGame); // 0x0058AA10
D2AiCmdStrc* __fastcall AIGENERAL_GetAiCommandFromParam(D2UnitStrc* pUnit, int nCmdParam, int bSet); // 0x0058EEF0
bool __fastcall sub_005E68F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pTick); // 0x005E68F0
int __fastcall ACT1Q4_GetCainPortalOutsideTownCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, D2CoordStrc* pCoords); // 0x00594450
int __fastcall ACT5Q3_GetDrehyaPortalCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, D2CoordStrc* pCoords); // 0x0058A8D0
unsigned int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY); // 0x005DC5C0
int __fastcall AITACTICS_WalkToTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY); // 0x005DED90
int __fastcall sub_0058A9F0_ACT5Q3_IsDrehyaStateZero(D2GameStrc* pGame); // 0x0058A9F0
int __fastcall ACT1Q4_SpawnCainPortalOutsideTown(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005943B0
int __fastcall ACT5Q3_SpawnDrehyaPortalOutsideTown(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058A820

static __forceinline D2MonsterInteractStrc* GetMonInteract(D2UnitStrc* pUnit)
{
    D2MonsterInteractStrc* p;
    if (pUnit)
    {
        if (pUnit->dwUnitType == UNIT_MONSTER)
        {
            if (pUnit->pMonsterData)
                p = pUnit->pMonsterData->pMonInteract;
            else
                p = 0;
        }
        else
            p = 0;
    }
    else
        p = 0;
    return p;
}

// 0x005E7880
void __fastcall sub_005E7880_ThinkRescuedNpc(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pTick)
{
    bool bDrehya = false;
    if (pUnit && pUnit->dwClassId == MONSTER_DREHYAICED)
        bDrehya = true;
    if (AITHINK_SpawnNpcPortal(pGame, pUnit, pTick))
        return;
    if (bDrehya)
        sub_0058AA10_ACT5Q3_UpdateStatusOnActivate(pGame);
    if (MONSTERAI_HasInteractUnit(GetMonInteract(pUnit)))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 40);
        return;
    }
    D2AiCmdStrc* pCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 3, 0);
    if (pUnit && pUnit->dwAnimMode == MONMODE_DEAD)
        return;
    sub_005E68F0(pGame, pUnit, pTick);
    if (pCmd)
    {
        if (pCmd->nCmdParam[3] >= 2)
        {
            pCmd->nCmdParam[3] += 1;
            int (__fastcall* pfGetCoords)(D2GameStrc*, D2UnitStrc*, D2CoordStrc*) = ACT1Q4_GetCainPortalOutsideTownCoordinates;
            void (__fastcall* pfSpawnPortal)(D2GameStrc*, D2UnitStrc*) = ACT1Q4_SpawnCainPortalInTown;
            if (bDrehya)
            {
                pfGetCoords = ACT5Q3_GetDrehyaPortalCoordinates;
                pfSpawnPortal = sub_6FCB53D0;
            }
            D2CoordStrc coords;
            if (pfGetCoords(pGame, pUnit, &coords))
            {
                if (pCmd->nCmdParam[3] < 8 && AIUTIL_GetDistanceToCoordinates(pUnit, coords.nX, coords.nY) > 0)
                {
                    AITACTICS_WalkToTargetCoordinates(pGame, pUnit, coords.nX, coords.nY);
                    return;
                }
                pfSpawnPortal(pGame, pUnit);
                STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, 0, 0);
                AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, MONMODE_DEAD, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit));
                return;
            }
        }
        else
        {
            if ((int)AIUTIL_GetDistanceToCoordinates(pUnit, pCmd->nCmdParam[1], pCmd->nCmdParam[2]) > 1 && pCmd->nCmdParam[4] <= 5)
            {
                pCmd->nCmdParam[4] += 1;
                if (bDrehya && sub_0058A9F0_ACT5Q3_IsDrehyaStateZero(pGame))
                {
                    AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
                    pCmd->nCmdParam[4] = 0;
                    return;
                }
                AITACTICS_WalkToTargetCoordinates(pGame, pUnit, pCmd->nCmdParam[1], pCmd->nCmdParam[2]);
                return;
            }
            if (pCmd->nCmdParam[3] == 1)
            {
                int (__fastcall* pfSpawnPortal)(D2GameStrc*, D2UnitStrc*) = ACT1Q4_SpawnCainPortalOutsideTown;
                if (bDrehya)
                    pfSpawnPortal = ACT5Q3_SpawnDrehyaPortalOutsideTown;
                if (!pfSpawnPortal(pGame, pUnit))
                {
                    pCmd->nCmdParam[3] = 1;
                    pCmd->nCmdParam[4] = 1;
                    AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
                    return;
                }
                pCmd->nCmdParam[3] = 2;
            }
        }
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
        return;
    }
    AITHINK_SpawnNpcPortal(pGame, pUnit, pTick);
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 40);
}
