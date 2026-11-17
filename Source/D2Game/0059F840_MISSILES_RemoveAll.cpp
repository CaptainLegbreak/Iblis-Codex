struct D2SkillStrc;
struct D2ActiveRoomStrc;
struct D2MonsterDataStrc;
struct D2UnitStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char pad0x08[0x08];
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
    char pad0x18[0xAC];
    unsigned int dwFlags;
};

struct D2MonsterDataStrc
{
    char pad0x00[0x16];
    unsigned short nTypeFlag;
};

struct D2GameStrc
{
    char pad0x00[0xA8];
    unsigned int dwGameFrame;
    char pad0xAC[0x1074];
    D2UnitStrc* pUnitList[5][128];
};

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int dwPhysDamage;
    int dwEnDmgPct;
    int dwFireDamage;
    int dwBurnDamage;
    int dwBurnLen;
    int dwLtngDamage;
    int dwMagDamage;
    int dwColdDamage;
    int dwPoisDamage;
    int dwPoisLen;
    int dwColdLen;
    int dwFrzLen;
    int dwLifeLeech;
    int dwManaLeech;
    int dwStamLeech;
    int dwStunLen;
};

struct D2ModeChangeStrc
{
    int nMode;
    D2UnitStrc* pUnit;
    D2UnitStrc* pTargetUnit;
    int nX;
    int nY;
    int unk0x14;
    int unk0x18;
    int unk0x1C;
};

struct D2MonStatsTxt
{
    char pad0x00[0x02];
    short nBaseId;
    char pad0x04[0x1A4];
};

struct D2MissilesTxt
{
    char pad0x00[0x38];
    int dwParam[4];
    char pad0x48[0x15C];
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

struct D2UnkFieldsStrc
{
    char pad0x00[0x18];
    int nUnk0x18;
    int nUnk0x1C;
    unsigned char nUnk0x20;
};

enum D2MiscConstants
{
    UNIT_PLAYER = 0,
    UNIT_MONSTER = 1,
    MONMODE_DEATH = 0,
    MONMODE_GETHIT = 3,
    EVENTTYPE_MONUMOD = 7,
    SKILL_MONTELEPORT = 184,
    MONSTER_SANDLEAPER1 = 78,
    STATE_FREEZE = 1,
    STATE_BLAZE = 13,
    ELEMTYPE_NONE = 0,
    ELEMTYPE_FIRE = 1,
    ELEMTYPE_LTNG = 2,
    ELEMTYPE_MAGIC = 3,
    ELEMTYPE_COLD = 4,
    ELEMTYPE_POIS = 5,
    ELEMTYPE_LIFE = 6,
    ELEMTYPE_MANA = 7,
    ELEMTYPE_STAMINA = 8,
    ELEMTYPE_STUN = 9,
    ELEMTYPE_RAND = 10,
    ELEMTYPE_BURN = 11,
    ELEMTYPE_FREEZE = 12,
};

typedef void (__fastcall* UModInitFunc)(D2UnitStrc* pUnit, int nUMod, int bUnique);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern "C" UModInitFunc gpUModInitFunctions_0073C008[];                                                     // 0x0073C008
D2UnitStrc* __fastcall SUNIT_GetNextUnitFromList(D2UnitStrc* pUnit);                                        // 0x00552DB0
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                     // 0x00555600
void __fastcall D2GAME_SetSkills_6FD14C60(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove);   // 0x0056DEB0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);         // 0x006439F0
void __stdcall SKILLS_SetSkillMode(D2SkillStrc* pSkill, int nMode);                                         // 0x00644340
void __fastcall AIUTIL_ToggleAiControlFlag0x20(D2UnitStrc* pUnit, int bSet);                                // 0x005DD250
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
void __fastcall PLAYERLIST_AllocPlayerList(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2);  // 0x0055B140
int __fastcall PLAYERLIST_CheckFlag(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nFlag);                 // 0x0055B300
void __fastcall PLAYERLIST_ToggleFlag(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nFlag, int bSet); // 0x0055B260
void __fastcall SCMD_Send0x75_PartyRosterUpdate(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2);               // 0x0053DA90
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064CB30
void* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                             // 0x00451F80
void __stdcall sub_005A6600(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFlag, D2ModeChangeStrc* pModeChange); // 0x005A6600
unsigned char __stdcall MISSILE_GetElemTypeFromMissileId(int nMissileId);                                   // 0x0064B0C0
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);                                // 0x00552FD0
int __stdcall MISSILE_GetTargetX(D2UnitStrc* pMissile);                                                     // 0x0064A730
void __fastcall sub_005A9930_CreateCairnPortal(D2GameStrc* pGame, D2UnitStrc* pMissile, int nParam);         // 0x005A9930
void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bSet);                              // 0x0061AED0

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x0059F840
void __fastcall MISSILES_RemoveAll(D2GameStrc* pGame)
{
    for (int i = 0; i < 128; ++i)
    {
        D2UnitStrc* pUnit = pGame->pUnitList[4][i];
        while (pUnit)
        {
            D2UnitStrc* pCurrent = pUnit;
            pUnit = SUNIT_GetNextUnitFromList(pUnit);
            SUNIT_RemoveUnit(pGame, pCurrent);
        }
    }
}

// 0x005A01B0
void __fastcall MONSTERUNIQUE_ToggleMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag, int bSet)
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

// 0x005A2100
void __fastcall sub_6FC6F670(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    UModInitFunc pCallback = gpUModInitFunctions_0073C008[nUMod];
    if (pCallback)
    {
        pCallback(pUnit, nUMod, bUnique);
    }
}

// 0x005A25F0
void __fastcall MONSTERUNIQUE_FireEnchantedModeChange(D2GameStrc* pGame, D2UnitStrc* pBoss, int nUMod, int bUnique)
{
    if (bUnique && (!pBoss || pBoss->dwAnimMode == MONMODE_DEATH))
    {
        EVENT_SetEvent(pGame, pBoss, EVENTTYPE_MONUMOD, pGame->dwGameFrame + 4, 0, 0);
    }
}

// 0x005A37D0
void __fastcall MONSTERUNIQUE_LightningEnchantedModeChange(D2GameStrc* pGame, D2UnitStrc* pBoss, int nUMod, int bUnique)
{
    if (bUnique && pBoss && pBoss->dwAnimMode == MONMODE_GETHIT)
    {
        EVENT_SetEvent(pGame, pBoss, EVENTTYPE_MONUMOD, pGame->dwGameFrame + 2, 0, 0);
    }
}

// 0x005A3800
void __fastcall MONSTERUNIQUE_ColdEnchantedModeChange(D2GameStrc* pGame, D2UnitStrc* pBoss, int nUMod, int bUnique)
{
    if ((bUnique || nUMod != 18) && (!pBoss || pBoss->dwAnimMode == MONMODE_DEATH))
    {
        EVENT_SetEvent(pGame, pBoss, EVENTTYPE_MONUMOD, pGame->dwGameFrame + 4, 0, 0);
    }
}

// 0x005A5840
void __fastcall PARTYSCREEN_ToggleIgnore(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nParam, int* pFailure)
{
    PLAYERLIST_AllocPlayerList(pGame, pPlayer1, pPlayer2);
    PLAYERLIST_AllocPlayerList(pGame, pPlayer2, pPlayer1);

    if (PLAYERLIST_CheckFlag(pPlayer1, pPlayer2, 2) != nParam)
    {
        PLAYERLIST_ToggleFlag(pGame, pPlayer1, pPlayer2, 2, nParam);
    }

    SCMD_Send0x75_PartyRosterUpdate(pPlayer1, pPlayer2);
    SCMD_Send0x75_PartyRosterUpdate(pPlayer2, pPlayer1);
}

// 0x005A58A0
void __fastcall PARTYSCREEN_ToggleSquelch(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nParam, int* pFailure)
{
    PLAYERLIST_AllocPlayerList(pGame, pPlayer1, pPlayer2);
    PLAYERLIST_AllocPlayerList(pGame, pPlayer2, pPlayer1);

    if (PLAYERLIST_CheckFlag(pPlayer1, pPlayer2, 4) != nParam)
    {
        PLAYERLIST_ToggleFlag(pGame, pPlayer1, pPlayer2, 4, nParam);
    }

    SCMD_Send0x75_PartyRosterUpdate(pPlayer1, pPlayer2);
    SCMD_Send0x75_PartyRosterUpdate(pPlayer2, pPlayer1);
}

// 0x005A6230
void __fastcall sub_005A6230_GetFields(D2UnkFieldsStrc* pFields, int* pUnk0x18, int* pUnk0x1C, unsigned char* pUnk0x20)
{
    *pUnk0x18 = pFields->nUnk0x18;
    *pUnk0x1C = pFields->nUnk0x1C;
    *pUnk0x20 = pFields->nUnk0x20;
}

// 0x005A8000
void __fastcall sub_005A8000_ModeChangeTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nUnused)
{
    D2ModeChangeStrc modeChange;
    modeChange.pUnit = pUnit;
    modeChange.pTargetUnit = pTarget;
    sub_005A6600(pGame, pUnit, 1, &modeChange);
}

// 0x005A91C0
void __fastcall MISSMODE_ResetDamageParams(D2GameStrc* pGame, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    if (!pUnit)
    {
        return;
    }

    pDamage->dwHitFlags &= ~0x700;
    pDamage->dwPhysDamage = 0;
    pDamage->dwFireDamage = 0;
    pDamage->dwLtngDamage = 0;
    pDamage->dwMagDamage = 0;
    pDamage->dwColdDamage = 0;
    pDamage->dwPoisDamage = 0;
    pDamage->dwLifeLeech = 0;
    pDamage->dwManaLeech = 0;
    pDamage->dwStamLeech = 0;
    pDamage->dwStunLen = 0;
    pDamage->dwBurnDamage = 0;

    switch (MISSILE_GetElemTypeFromMissileId(pUnit->dwClassId))
    {
    case ELEMTYPE_POIS:
        pDamage->dwColdLen = 0;
        pDamage->dwFrzLen = 0;
        pDamage->dwBurnLen = 0;
        break;

    case ELEMTYPE_BURN:
        pDamage->dwColdLen = 0;
        pDamage->dwPoisLen = 0;
        pDamage->dwFrzLen = 0;
        break;

    default:
        pDamage->dwColdLen = 0;
        pDamage->dwFrzLen = 0;

    case ELEMTYPE_COLD:
        pDamage->dwPoisLen = 0;
        pDamage->dwBurnLen = 0;
        break;

    case ELEMTYPE_FREEZE:
        pDamage->dwPoisLen = 0;
        pDamage->dwBurnLen = 0;
        break;
    }
}

// 0x005A9270
void __fastcall MISSMODE_AddDamageValue(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nDamage)
{
    if (!pMissile)
    {
        return;
    }

    switch (MISSILE_GetElemTypeFromMissileId(pMissile->dwClassId))
    {
    case ELEMTYPE_NONE:
        pDamage->dwPhysDamage += nDamage;
        break;
    case ELEMTYPE_FIRE:
        pDamage->dwFireDamage += nDamage;
        break;
    case ELEMTYPE_LTNG:
        pDamage->dwLtngDamage += nDamage;
        break;
    case ELEMTYPE_MAGIC:
        pDamage->dwMagDamage += nDamage;
        break;
    case ELEMTYPE_COLD:
        pDamage->dwColdDamage += nDamage;
        break;
    case ELEMTYPE_POIS:
        pDamage->dwPoisDamage += nDamage;
        break;
    case ELEMTYPE_LIFE:
        pDamage->dwLifeLeech += nDamage;
        break;
    case ELEMTYPE_MANA:
        pDamage->dwManaLeech += nDamage;
        break;
    case ELEMTYPE_STAMINA:
        pDamage->dwStamLeech += nDamage;
        break;
    case ELEMTYPE_STUN:
        pDamage->dwStunLen += nDamage;
        break;
    case ELEMTYPE_BURN:
        pDamage->dwBurnDamage += nDamage;
        break;
    case ELEMTYPE_FREEZE:
        pDamage->dwColdDamage = nDamage;
        break;
    default:
        break;
    }
}

// 0x005ABEB0
int __fastcall MISSMODE_SrvHit33_TowerChestSpawner(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
        if (pRoom)
        {
            DUNGEON_ToggleHasPortalFlag(pRoom, 1);
        }
    }

    return 0;
}

// 0x005AC020
int __fastcall MISSMODE_SrvHit37_BladeCreeper(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return 2;
    }

    return 0;
}

// 0x005AD290
void __fastcall MISSMODE_SrvDmg04_IceBlast(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    pDamage->dwFrzLen = pDamage->dwColdLen;
    pDamage->dwColdLen = 0;
}
