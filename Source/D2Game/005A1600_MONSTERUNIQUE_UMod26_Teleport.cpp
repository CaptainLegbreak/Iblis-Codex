struct D2SkillStrc;
struct D2GameStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
};

struct D2MonStatsTxt
{
    char pad0x00[0x02];
    short nBaseId;
    char pad0x04[0x1A4];
};

struct D2MissilesTxt
{
    char pad0x00[0x24];
    short wHitSubMissile[4];
    char pad0x2C[0x0C];
    int dwParam[5];
    int dwHitPar[3];
    char pad0x58[0x14C];
};

struct D2DataTablesStrc
{
    char pad0x00[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char pad0xA7C[0x04];
    int nMonStatsTxtRecordCount;
    char pad0xA84[0xE0];
    D2MissilesTxt* pMissilesTxt;
    char pad0xB68[0x04];
    int nMissilesTxtRecordCount;
};

typedef void(__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nUnused);

struct D2MissileStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    D2UnitStrc* pTarget;
    int nMissile;
    int nX;
    int nY;
    int nTargetX;
    int nTargetY;
    int nGfxArg;
    int nVelocity;
    int nSkill;
    int nSkillLevel;
    int nLoops;
    unsigned int unk0x38;
    unsigned int unk0x3C;
    int nFrame;
    int nActivateFrame;
    int nAttBonus;
    int nRange;
    int nLightRadius;
    MissileInitFunc pInitFunc;
    int pInitArgs;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);                                // 0x00552FD0
void __fastcall PLAYERLIST_AllocPlayerList(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2);  // 0x0055B140
void __fastcall PLAYERLIST_ToggleFlag(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nFlag, int bSet); // 0x0055B260
void __fastcall sub_6FD14260(D2GameStrc* pGame, int nMissiles, D2MissileStrc* pMissileParams);              // 0x0056D4E0
void __fastcall D2GAME_SetSkills_6FD14C60(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove);   // 0x0056DEB0
void __fastcall sub_005A9930_CreateCairnPortal(D2GameStrc* pGame, D2UnitStrc* pMissile, int nParam);         // 0x005A9930
void __fastcall MISSMODE_CatapultChargedBall_LightningTrailingJavelin_SubmissileInitFunc(D2UnitStrc* pMissile, int nUnused); // 0x005AC040
void __fastcall AIUTIL_ToggleAiControlFlag0x20(D2UnitStrc* pUnit, int bSet);                                // 0x005DD250
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);         // 0x006439F0
void __stdcall SKILLS_SetSkillMode(D2SkillStrc* pSkill, int nMode);                                         // 0x00644340
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280
int __stdcall MISSILE_GetTargetX(D2UnitStrc* pMissile);                                                     // 0x0064A730

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_INVALID 6
#define SKILL_MONTELEPORT 184
#define STATE_FREEZE 1
#define MONSTER_SANDLEAPER1 78
#define PLAYERLIST_FLAG_HOSTILE 8

static D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static int D2GAME_GetMonsterBaseId_6FC64B10(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pUnit->dwClassId);
        if (pMonStatsTxtRecord)
        {
            return pMonStatsTxtRecord->nBaseId;
        }

        return pUnit->dwClassId;
    }

    return -1;
}

static D2MissilesTxt* SKILLS_GetMissilesTxtRecordFromUnit(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwClassId >= 0 && pMissile->dwClassId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[pMissile->dwClassId];
    }

    return 0;
}

// 0x005A1600
void __fastcall MONSTERUNIQUE_UMod26_Teleport(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_MONSTER && bUnique)
    {
        D2GAME_SetSkills_6FD14C60(pUnit, SKILL_MONTELEPORT, 1, 1);
        SKILLS_SetSkillMode(SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, SKILL_MONTELEPORT), 4);
        AIUTIL_ToggleAiControlFlag0x20(pUnit, 1);
    }
}

// 0x005A54F0
void __fastcall sub_6FC62DF0(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    if (pDamage->wResultFlags & 4)
    {
        const int nBaseId = D2GAME_GetMonsterBaseId_6FC64B10(pUnit);
        if (nBaseId >= 0 && nBaseId < sgptDataTables->nMonStatsTxtRecordCount && nBaseId == MONSTER_SANDLEAPER1 && !STATES_CheckState(pUnit, STATE_FREEZE))
        {
            pDamage->wResultFlags |= 8;
        }
    }
}

// 0x005A60E0
void __fastcall FRIENDLY_OpenHostility(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2)
{
    D2_ASSERT((pPlayer1 ? pPlayer1->dwUnitType : UNIT_INVALID) == UNIT_PLAYER, 36);

    PLAYERLIST_AllocPlayerList(pGame, pPlayer1, pPlayer2);
    PLAYERLIST_ToggleFlag(pGame, pPlayer1, pPlayer2, PLAYERLIST_FLAG_HOSTILE, 1);
}

// 0x005ABE50
int __fastcall MISSMODE_SrvHit32_CairnStones(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    if (!pUnit && !MISSILE_GetTargetX(pMissile))
    {
        sub_005A9930_CreateCairnPortal(pGame, pMissile, pMissilesTxtRecord->dwParam[3]);
    }

    return 0;
}

// 0x005AC480
int __fastcall MISSMODE_SrvHit45_LightningTrailingJavelin(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0 || pMissilesTxtRecord->dwHitPar[0] <= 0)
    {
        return 1;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 3;
    missileParams.nX = UNITS_GetXPosition(pMissile);
    missileParams.nY = CLIENTS_GetUnitY(pMissile);
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.pOwner = SUNIT_GetOwner(pGame, pMissile);
    missileParams.nMissile = pMissilesTxtRecord->wHitSubMissile[0];
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);

    if (pMissilesTxtRecord->dwHitPar[1])
    {
        missileParams.pInitFunc = MISSMODE_CatapultChargedBall_LightningTrailingJavelin_SubmissileInitFunc;
    }

    sub_6FD14260(pGame, pMissilesTxtRecord->dwHitPar[0], &missileParams);
    return 1;
}
