extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

enum D2C_F42AiConstants
{
    UNIT_PLAYER = 0,
    UNIT_MONSTER = 1,
    UNIT_OBJECT = 2,
    UNIT_MISSILE = 3,
    UNIT_ITEM = 4,
    UNIT_TILE = 5,
    UNIT_INVALID = 6,

    MONMODE_DEATH = 0,
    MONMODE_NEUTRAL = 1,
    MONMODE_ATTACK1 = 4,
    MONMODE_ATTACK2 = 5,
    MONMODE_SKILL1 = 8,
    MONMODE_SKILL2 = 9,
    MONMODE_SKILL3 = 10,
    MONMODE_SKILL4 = 11,
    MONMODE_DEAD = 12,

    PLRMODE_NEUTRAL = 1,

    AISPECIALSTATE_NONE = 0,
    EVENTTYPE_AITHINK = 2,
    UNIT_ALIGNMENT_GOOD = 2,

    UNITFLAG_TARGETABLE = 0x00000002,
    UNITFLAG_CANBEATTACKED = 0x00000004,
    UNITFLAG_NOTC = 0x00020000,
    UNITFLAG_NOXP = 0x04000000,

    STATE_POISON = 2,
    STATE_INFERNO = 12,
    STATE_BAALTOSTAIRS_INVIS = 0x92,
    STAT_HITPOINTS = 6,
    STAT_POISONRESIST = 45,
    SKILL_BAALTAUNT = 284,
    SKILL_IMPREGNATE = 300,
    MONTYPEFLAG_UNIQUE = 8,
    MONSTATSFLAGINDEX_LUNDEAD = 11,
};

struct D2DynamicPathStrc;
struct D2ActiveRoomStrc;
struct D2SkillStrc;

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x3A];
    int dwGameFrame;
};

struct D2AiCmdStrc
{
    D2AiCmdStrc* pNextCmd;
    D2AiCmdStrc* pPrevCmd;
    int nCmdParam[5];
};

struct D2AiControlStrc
{
    int nAiSpecialState;
    void* pAiParamFn;
    unsigned short nAiFlags;
    unsigned char unk0x0A[2];
    int dwOwnerGUID;
    unsigned int dwOwnerType;
    int dwAiParam[3];
};

struct D2MonStatsTxt
{
    char unk0x000[0x0C];
    unsigned char nMonStatsFlags[4];
    char unk0x010[0x22];
    short nVelocity;
    short nRun;
    char unk0x036[0x20];
    short wAiParam[8][3];
    char unk0x086[0xEA];
    short nSkill[8];
    unsigned char nSkillMode[8];
    char unk0x188[0x20];
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nXPos;
    int nYPos;
};

struct D2MonsterDataStrc
{
    char unk0x00[0x28];
    D2AiControlStrc* pAiControl;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0x14];
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
    char unk0x30[0x94];
    unsigned int dwFlags;
};

struct D2AiTickParamStrc
{
    D2AiControlStrc* pAiControl;
    unsigned int unk0x04;
    D2UnitStrc* pTarget;
    unsigned int unk0x0C[2];
    int nTargetDistance;
    int bCombat;
    D2MonStatsTxt* pMonstatsTxt;
};

struct D2CoordStrc
{
    unsigned int nX;
    unsigned int nY;
};

struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileX;
    int nTileY;
    int nTileWidth;
    int nTileHeight;
};

struct D2BaalToStairsAiCallbackArgStrc
{
    int unk0x00;
    int nMaxDistance;
    int unk0x08[8];
};

struct D2PutridDefilerAiCallbackArgStrc
{
    int unk0x00;
    int nMaxDistance;
    int unk0x08[8];
};

struct D2GreaterMummyAiCallbackArgStrc
{
    D2UnitStrc* pReviveTarget;
    D2UnitStrc* pHealTarget;
    int nHealReviveCounter;
    int nCounter;
    int nMaxDistance;
    int bRadament;
    int bNormal;
};

struct D2VultureAiCallbackArgStrc
{
    D2UnitStrc* pTarget;
    int nDistance;
    int nLifePercentage;
};

struct D2MephistoAiCallbackArgStrc
{
    D2UnitStrc* unk0x00;
    int unk0x04;
    int unk0x08;
    D2UnitStrc* unk0x0C;
    int unk0x10;
    D2UnitStrc* unk0x14;
    int unk0x18;
    int nCounter;
    int unk0x20;
    int unk0x24;
};

typedef D2UnitStrc* (__fastcall* AITARGETCALLBACK)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, void*);

extern const unsigned int gdwBitMasks[32];                                                                  // 0x006CE268

void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
void __fastcall AITACTICS_Idle(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);                         // 0x005DE0F0
void __fastcall sub_6FCD0150(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);                           // 0x005DE130
void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nAiSpecialState); // 0x005B0E00
bool __fastcall sub_005E6800_InitHomeCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005E6800
bool __fastcall sub_6FCE69A0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam);       // 0x005E6AE0
bool __fastcall AITHINK_ExecuteMapAiAction(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005E7080
D2AiCmdStrc* __fastcall AIGENERAL_GetCurrentAiCommandFromUnit(D2UnitStrc* pUnit);                          // 0x0058EE80
D2AiCmdStrc* __fastcall AIGENERAL_GetAiCommandFromParam(D2UnitStrc* pUnit, int nCmdParam, int bSet);       // 0x0058EEF0
D2AiCmdStrc* __fastcall AIGENERAL_CopyAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd); // 0x0058EF40
D2AiCmdStrc* __fastcall AIGENERAL_SetCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCmdParam, int bSet); // 0x0058EFA0
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit);                                         // 0x0058F0D0
void __fastcall AIGENERAL_FreeMinionList(D2UnitStrc* pUnit);                                                // 0x0058F160
void __fastcall AIGENERAL_ExecuteCallbackOnMinions(D2UnitStrc* pUnit, void* a2, void* a3, void(__fastcall* pfnParty)(D2UnitStrc*, void*, void*)); // 0x0058F380
void __fastcall AIGENERAL_AllocCommandsForMinions(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd); // 0x0058F730
int __fastcall AIGENERAL_GetMinionSpawnClassId(D2UnitStrc* pUnit);                                         // 0x0058F710
void __fastcall sub_6FCE4FD0(D2UnitStrc* pUnit, void* a2, void* a3);                                        // 0x005E5710
int __fastcall sub_6FCF2E70(D2UnitStrc* pUnit);                                                             // 0x005DD2B0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
int __stdcall STATES_CheckStateMaskHideOnUnit(D2UnitStrc* pUnit);                                          // 0x0063A320
int __stdcall STATES_CheckStateMaskUdeadOnUnit(D2UnitStrc* pUnit);                                          // 0x0063A770
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                           // 0x00553540
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0
int __fastcall sub_00554200(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);                     // 0x00554200
int __fastcall sub_6FCBDFE0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int a6, int a7); // 0x00554EA0
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                     // 0x00555600
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);              // 0x00619730
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID);              // 0x0061A270
int __fastcall sub_6FCD0410(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nFlags); // 0x005DED40
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus);                // 0x00622C40
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit);               // 0x00620C10
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                     // 0x00620870
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit);                                                  // 0x00623830
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit);                                              // 0x0064C370
void __stdcall D2Common_10153(D2DynamicPathStrc* pDynamicPath);                                             // 0x00648730
D2UnitStrc* __fastcall sub_6FCCF9D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int* pDistance, int* pCombat); // 0x005DE890
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
int __fastcall AITACTICS_ChangeModeAndTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY); // 0x005DDFC0
int __fastcall AITACTICS_ChangeModeAndTargetCoordinatesOneStep(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nMode); // 0x005DE440
void __fastcall AITACTICS_SetVelocity(D2UnitStrc* pUnit, int a2, int nVel, unsigned char a4);             // 0x005DE190
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall AITACTICS_RunToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nFlags); // 0x005DED00
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
int __fastcall AITACTICS_WalkToTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);       // 0x005DECA0
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback); // 0x005DEFE0
D2UnitStrc* __fastcall sub_6FCF1E80(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg, AITARGETCALLBACK pfnCallback, int nCallbackId); // 0x005DD0B0
D2UnitStrc* __fastcall sub_6FCF2CC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pDistance, int* pInMeleeRange); // 0x005DDC30
int __fastcall D2GAME_AI_PetMove_6FCE2BA0(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int a4, int bRun, int nVelocity, int a7); // 0x005E3EA0
int __fastcall sub_005E45D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2UnitStrc* pOwner, int a5, D2AiTickParamStrc* pAiTickParam, int a7, int a8); // 0x005E45D0
int __fastcall sub_6FD01910(D2UnitStrc* pUnit, D2UnitStrc* pTarget);                                        // 0x005D2140
unsigned int __fastcall sub_005DC380(D2UnitStrc* pUnit, D2UnitStrc* pTarget);                  // 0x005DC380
int __fastcall AITHINK_GetSquaredDistance(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);                         // 0x005B0BD0
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther);                         // 0x006416D0
void __fastcall ACT5Q6_OpenWorldStoneChamber(D2GameStrc* pGame);                                            // 0x0058E600
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                          // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                          // 0x0045AE20
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);         // 0x006439F0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);              // 0x006439B0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0
D2SkillStrc* __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280
void __stdcall SKILLS_SetLeftActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                  // 0x00643BC0
void __stdcall SKILLS_SetRightActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                 // 0x00643C50
int __stdcall SKILLS_GetSkillMode(D2SkillStrc* pSkill);                                                     // 0x00644360
int __stdcall D2Common_11016(D2UnitStrc* pUnit, D2SkillStrc* pSkill);                                       // 0x00645460
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10
int __stdcall STATLIST_AreUnitsAligned(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);                             // 0x00650D70
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit);                                                 // 0x006259B0
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80
int __stdcall MONSTERS_IsUndead(D2UnitStrc* pMonster);                                                      // 0x0063E990
int __stdcall MONSTERS_IsDead(D2UnitStrc* pMonster);                                                        // 0x0063EA40
void __stdcall sub_0063EE10_GetMonsterDirectionDelta(D2UnitStrc* pUnit, int* pX, int* pY);                  // 0x0063EE10
void __stdcall MONSTERS_GetMinionSpawnInfo(D2UnitStrc* pUnit, int* pMonsterId, int* pX, int* pY, int* pSpawnMode, int a6, int (__fastcall* pfnGetClassId)(D2UnitStrc*)); // 0x0063EFA0
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag);                                // 0x005A0180
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int a7, int a8); // 0x005B2F20
int __fastcall sub_005429B0_SpawnAtRoomPosition(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nIndex); // 0x005429B0
D2UnitStrc* __fastcall AITHINK_TargetCallback_BaalToStairs(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005EF5E0

// build: context AITHINK_IdleInline
inline void AITHINK_IdleInline(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames)
{
    if (!nFrames)
    {
        nFrames = 1;
    }
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_AITHINK, nFrames + pGame->dwGameFrame, 0, 0);
}

inline D2AiControlStrc* AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }
    return 0;
}

inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }
    return 0;
}

inline short AI_GetParamValue(D2GameStrc* pGame, D2MonStatsTxt* pMonStatsTxt, int nParamId)
{
    return pMonStatsTxt->wAiParam[nParamId][pGame->nDifficulty];
}

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

__forceinline int UNITS_GetUnitXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }

    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

__forceinline int UNITS_GetUnitYPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }

    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x005E7540
void __fastcall AITHINK_Fn041_Towner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (!sub_005E6800_InitHomeCommand(pGame, pUnit, pAiTickParam) && !sub_6FCE69A0(pGame, pUnit, pAiTickParam) && !AITHINK_ExecuteMapAiAction(pGame, pUnit, pAiTickParam))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 12);
    }
}

// 0x005E7F80
void __fastcall D2GAME_AI_SpecialState09_6FCE7C40(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int nDistance = pAiTickParam->nTargetDistance;
    D2AiCmdStrc* pCurrentAiCmd = AIGENERAL_GetCurrentAiCommandFromUnit(pUnit);
    if (pCurrentAiCmd && pCurrentAiCmd->nCmdParam[0] == 8)
    {
        AIGENERAL_FreeMinionList(pUnit);
        AITHINK_ExecuteAiFn(pGame, pUnit, pAiTickParam->pAiControl, AISPECIALSTATE_NONE);
    }
    else
    {
        int nCount = 0;
        AIGENERAL_ExecuteCallbackOnMinions(pUnit, &nCount, 0, sub_6FCE4FD0);
        if (sub_6FCF2E70(pUnit) || nCount || nDistance < 20)
        {
            D2AiCmdStrc aiCmd;
            aiCmd.nCmdParam[0] = 8;
            AIGENERAL_AllocCommandsForMinions(pGame, pUnit, &aiCmd);
            AIGENERAL_FreeMinionList(pUnit);
            AITHINK_ExecuteAiFn(pGame, pUnit, pAiTickParam->pAiControl, AISPECIALSTATE_NONE);
        }
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}

// 0x005E8340
void __fastcall D2GAME_AI_SpecialState12_6FCE81B0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget || DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)))
    {
        AITHINK_ExecuteAiFn(pGame, pUnit, AIGENERAL_GetAiControlFromUnit(pUnit), AISPECIALSTATE_NONE);
        AITHINK_IdleInline(pGame, pUnit, 1);
        return;
    }

    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (!pAiControl->dwAiParam[0])
    {
        pAiControl->dwAiParam[0] = 1;
        sub_6FCD0410(pGame, pUnit, pTarget, 7);
        return;
    }

    int bCombat = UNITS_IsInMeleeRange(pUnit, pTarget, 0);
    if (bCombat)
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    int nDistance;
    D2UnitStrc* pTargetUnit = sub_6FCCF9D0(pGame, pUnit, pAiTickParam->pAiControl, &nDistance, &bCombat);
    if (pTargetUnit && bCombat)
    {
        pAiControl->dwAiParam[0] = 0;
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTargetUnit);
        return;
    }

    pAiControl->dwAiParam[0] = 1;
    UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
    sub_6FCD0410(pGame, pUnit, pTarget, 7);
}

// 0x005E8480
void __fastcall sub_005E8480(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    int nParam1 = 0;
    int nParam2 = 0;
    D2AiCmdStrc* pCurrentAiCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0);
    if (pCurrentAiCmd)
    {
        nParam1 = pCurrentAiCmd->nCmdParam[1];
        nParam2 = pCurrentAiCmd->nCmdParam[2];
    }

    if (STATES_CheckState(pUnit, STATE_INFERNO))
    {
        STATES_ToggleState(pUnit, STATE_INFERNO, 0);
    }

    AITHINK_ExecuteAiFn(pGame, pUnit, pAiTickParam->pAiControl, pAiControl->nAiSpecialState);

    if (!AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0) && nParam1 && nParam2)
    {
        D2AiCmdStrc aiCmd;
        aiCmd.nCmdParam[0] = 10;
        aiCmd.nCmdParam[1] = nParam1;
        aiCmd.nCmdParam[2] = nParam2;
        AIGENERAL_CopyAiCommand(pGame, pUnit, &aiCmd);
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 1);
}

// 0x005E9F10
void __fastcall AITHINK_Fn099_TrappedSoul(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    const int nDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2CoordStrc unitCoord;
    D2CoordStrc targetCoord;

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_NOTC;
    }

    UNITS_GetCoords(pUnit, &unitCoord);

    if (pTarget && nDistance < 5)
    {
        if (!pAiControl->dwAiParam[0])
        {
            pAiControl->dwAiParam[0] = 1;
            pAiControl->dwAiParam[1] = pGame->dwGameFrame;
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_SKILL2, pTarget);
            return;
        }

        if (bCombat && pGame->dwGameFrame > pAiControl->dwAiParam[1])
        {
            UNITS_GetCoords(pTarget, &targetCoord);

            if (unitCoord.nX >= targetCoord.nX && unitCoord.nY <= targetCoord.nY)
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
                pAiControl->dwAiParam[1] = pGame->dwGameFrame + 35;
                return;
            }

            if (unitCoord.nX <= targetCoord.nX && unitCoord.nY >= targetCoord.nY)
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
                pAiControl->dwAiParam[1] = pGame->dwGameFrame + 35;
            }
            else
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_SKILL1, pTarget);
                pAiControl->dwAiParam[1] = pGame->dwGameFrame + 5;
            }
        }
        else
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_SKILL1, pTarget);
        }
    }
    else
    {
        if (pAiControl->dwAiParam[0])
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_SKILL1, pTarget);
        }
        else
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
        }
    }
}

// 0x005EA080
void __fastcall AITHINK_Fn088_7TIllusion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (pAiControl->dwAiParam[1] == 1)
    {
        if (pUnit)
        {
            pUnit->dwFlags |= UNITFLAG_NOTC;
        }
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, MONMODE_DEATH, 0, 0);
        return;
    }

    AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, MONMODE_ATTACK1, UNITS_GetUnitXPositionInline(pUnit) - 10, UNITS_GetUnitYPositionInline(pUnit));
    pAiControl->dwAiParam[1] = 1;
}

// 0x005EAF00
int __fastcall sub_005EAF00_ShadowWarriorSkillLevel(D2GameStrc* pGame, D2UnitStrc* pOwner, D2SkillStrc* pSkill, D2AiTickParamStrc* pAiTickParam)
{
    int nSkillLevel = 1;
    if (pOwner)
    {
        nSkillLevel = SKILLS_GetSkillLevel(pOwner, pSkill, 1);
    }

    const int nLevel = pAiTickParam->pAiControl->dwAiParam[2] / 3 + nSkillLevel / 2;
    return nLevel > 1 ? nLevel : 1;
}

// 0x005EAF50
void __fastcall sub_005EAF50(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    pAiControl->dwAiParam[2] = 1;

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner)
    {
        return;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pOwner, pAiTickParam->pMonstatsTxt->wAiParam[7][0]);
    if (pSkill)
    {
        pAiControl->dwAiParam[2] = SKILLS_GetSkillLevel(pOwner, pSkill, 1);
    }
}

// 0x005EB420
int __fastcall sub_005EB420_ShadowMasterSkillLevel(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nParam, int nSkillId)
{
    int nSkillLevel = 1;
    if (pOwner)
    {
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pOwner, nSkillId, -1);
        if (pSkill)
        {
            nSkillLevel = SKILLS_GetSkillLevel(pOwner, pSkill, 0);
        }
    }

    const int nLevel = nSkillLevel / 2 + nParam / 2;
    if (nLevel > 1 && nLevel < 24)
    {
        return nLevel;
    }
    if (nLevel <= 1)
    {
        return 1;
    }
    return 24;
}

// 0x005EB5C0
void __fastcall sub_005EB5C0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    pAiControl->dwAiParam[2] = 1;

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner || pOwner->dwUnitType != UNIT_PLAYER)
    {
        return;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pOwner, pAiTickParam->pMonstatsTxt->wAiParam[7][0]);
    if (pSkill)
    {
        pAiControl->dwAiParam[2] = SKILLS_GetSkillLevel(pOwner, pSkill, 1);
    }

    if (!SKILLS_GetSkillById(pUnit, 0, -1))
    {
        SKILLS_AssignSkill(pUnit, 0, 1, 0, ".\\Ai\\AiThink4.cpp", 3101);
    }

    SKILLS_SetLeftActiveSkill(pUnit, 0, -1);
    SKILLS_SetRightActiveSkill(pUnit, 0, -1);
}

// 0x005EB8B0
int __fastcall sub_005EB8B0_ShadowMasterUseSkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nSkillId, int bCombat, D2UnitStrc* pTarget, int nX, int nY, D2AiTickParamStrc* pAiTickParam)
{
    if (pTarget && (pTarget == pOwner || pTarget == pUnit))
    {
        return 0;
    }

    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
    if (!pSkill)
    {
        return 0;
    }

    if (pTarget && (!UNIT_HasFlag(pTarget, UNITFLAG_CANBEATTACKED) || DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit))))
    {
        return 0;
    }

    if (D2Common_11016(pUnit, pSkill) == 1 && !bCombat)
    {
        return AITACTICS_RunToTargetUnitWithFlags(pGame, pUnit, pTarget, 4);
    }

    return AITACTICS_UseSkill(pGame, pUnit, SKILLS_GetSkillMode(pSkill), nSkillId, pTarget, nX, nY);
}

// build: context AITHINK_Fn110_Vines
void __fastcall AITHINK_Fn110_Vines(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    int nDistance = 0;
    int bCombat = 0;
    if (!pOwner)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
        return;
    }

    if (sub_006416D0_UnitEdgeDistance(pUnit, pOwner) >= AI_PARAM(pGame, pMonStatsTxt, 4) && D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 3, 0, 0, 6))
    {
        return;
    }

    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        if (!sub_005E45D0(pGame, pUnit, 0, pOwner, 0, pAiTickParam, 0, 6))
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 2));
        }
        return;
    }

    D2UnitStrc* pTarget = sub_6FCF2CC0(pGame, pUnit, &nDistance, &bCombat);
    if (nDistance >= AI_PARAM(pGame, pMonStatsTxt, 1))
    {
        pTarget = 0;
    }

    if (sub_005E45D0(pGame, pUnit, pTarget, pOwner, bCombat, pAiTickParam, 0, 6))
    {
        return;
    }

    if (pTarget)
    {
        if (STATES_CheckState(pTarget, STATE_POISON) || STATLIST_UnitGetStatValue(pTarget, STAT_POISONRESIST, 0) == 100)
        {
            D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, AI_PARAM(pGame, pMonStatsTxt, 3), 0);
            return;
        }

        if (bCombat)
        {
            if (pMonStatsTxt->nSkill[0] >= 0 && AI_PARAM(pGame, pMonStatsTxt, 0) + pAiControl->dwAiParam[1] < pGame->dwGameFrame)
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
                pAiControl->dwAiParam[1] = pGame->dwGameFrame;
                return;
            }
        }
        else
        {
            AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
            return;
        }
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 2));
}

// 0x005EDF70
int __fastcall sub_005EDF70_TryRoomSteps(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    D2_ASSERT(pRoom, 5147);

    D2DrlgCoordsStrc coords;
    DUNGEON_GetRoomCoordinates(pRoom, &coords);
    int nX = coords.nSubtileX;
    int nY = coords.nSubtileY;
    int nDirX = 0;
    int nDirY = 0;
    sub_0063EE10_GetMonsterDirectionDelta(pUnit, &nDirX, &nDirY);
    nDirX = -nDirX;
    nDirY = -nDirY;
    int bResult = 0;
    const int nIndex = (!pUnit ? -1 : pUnit->dwClassId) - 19;
    for (int i = 0; !bResult && i < 3; ++i)
    {
        nX += coords.nSubtileWidth * nDirX;
        nY += coords.nSubtileHeight * nDirY;
        bResult = sub_005429B0_SpawnAtRoomPosition(pGame, pRoom, nX, nY, nIndex);
    }
    return bResult;
}

// 0x005EF620
void __fastcall AITHINK_Fn138_BaalToStairs(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2BaalToStairsAiCallbackArgStrc arg;
    arg.unk0x00 = 0;
    arg.nMaxDistance = 25;
    D2UnitStrc* pTarget = sub_6FCF1E80(pGame, pUnit, &arg, AITHINK_TargetCallback_BaalToStairs, 1);
    if (pTarget)
    {
        if (sub_006416D0_UnitEdgeDistance(pUnit, pTarget) < AI_PARAM(pGame, pMonStatsTxt, 0))
        {
            ACT5Q6_OpenWorldStoneChamber(pGame);
            STATES_ToggleState(pUnit, STATE_BAALTOSTAIRS_INVIS, 1);
            D2Common_10153(pUnit->pDynamicPath);
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);
            DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pUnit), pUnit->dwUnitType, pUnit->dwUnitId);
            UNITS_FreeCollisionPath(pUnit);
            UNITROOM_RemoveUnitFromRoom(pUnit);
            SUNIT_RemoveUnit(pGame, pUnit);
            return;
        }

        AITACTICS_SetVelocity(pUnit, 1, 0, 0);
        AITACTICS_WalkToTargetUnit(pGame, pUnit, pTarget);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
}

// 0x005EF710
void __fastcall AITHINK_Fn136_BaalTaunt(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    const int nDistance = pAiTickParam->nTargetDistance;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    if (!pTarget)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
        return;
    }

    int bIsTargetNeutral = 0;
    switch (pTarget->dwUnitType)
    {
    case UNIT_PLAYER:
        bIsTargetNeutral = pTarget->dwAnimMode == PLRMODE_NEUTRAL;
        break;
    case UNIT_MONSTER:
        bIsTargetNeutral = pTarget->dwAnimMode == MONMODE_NEUTRAL;
        break;
    }

    int bTaunt = 0;
    if (bIsTargetNeutral)
    {
        ++pAiTickParam->pAiControl->dwAiParam[0];
        bTaunt = pAiTickParam->pAiControl->dwAiParam[0] > AI_GetParamValue(pGame, pMonStatsTxt, 1);
    }

    if (!bIsTargetNeutral || bTaunt)
    {
        pAiTickParam->pAiControl->dwAiParam[0] = 0;
        if (bTaunt)
        {
            AITACTICS_UseSkill(pGame, pUnit, MONMODE_ATTACK1, SKILL_BAALTAUNT, pTarget, 0, 0);
            return;
        }
    }

    if ((nDistance <= AI_GetParamValue(pGame, pMonStatsTxt, 2) || !sub_6FCBDFE0(pGame, pUnit, UNITS_GetRoom(pTarget), CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget), 0, 0))
        && nDistance > AI_GetParamValue(pGame, pMonStatsTxt, 0))
    {
        AITACTICS_WalkToTargetUnit(pGame, pUnit, pTarget);
    }
    else
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
    }
}

// 0x005EFA50
D2UnitStrc* __fastcall AITHINK_TargetCallback_PutridDefiler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    if (!sub_6FD01910(pUnit, pTarget))
    {
        return 0;
    }

    return sub_005DC380(pUnit, pTarget) <= 25 ? pTarget : 0;
}

// build: context AITHINK_Fn137_PutridDefiler
void __fastcall AITHINK_Fn137_PutridDefiler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    const int nDistance = pAiTickParam->nTargetDistance;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    if (pTarget && pAiTickParam->bCombat)
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    D2PutridDefilerAiCallbackArgStrc arg;
    arg.unk0x00 = 0;
    arg.nMaxDistance = 25;
    D2UnitStrc* pVictim = sub_6FCF1E80(pGame, pUnit, &arg, AITHINK_TargetCallback_PutridDefiler, 1);
    if (pVictim)
    {
        if (UNITS_IsInMeleeRange(pUnit, pVictim, 0))
        {
            AITACTICS_UseSkill(pGame, pUnit, MONMODE_SKILL1, SKILL_IMPREGNATE, pVictim, 0, 0);
        }
        else
        {
            AITACTICS_WalkToTargetUnit(pGame, pUnit, pVictim);
        }
        return;
    }

    if (nDistance < AI_GetParamValue(pGame, pMonStatsTxt, 0))
    {
        D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, AI_GetParamValue(pGame, pMonStatsTxt, 1), 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
}

// 0x005F1750
void __fastcall sub_005F1750(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiCmdStrc* pAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 14, 0);
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    if (pAiCmd->nCmdParam[4] == 1 && pMonStatsTxt->nSkill[0] >= 0)
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], SUNIT_GetTargetUnit(pGame, pUnit), 0, 0);
        sub_6FCD0150(pGame, pUnit, 30);
        pAiCmd->nCmdParam[4] = 0;
        return;
    }

    const int nParam = pAiControl->dwAiParam[2];
    AITHINK_ExecuteAiFn(pGame, pUnit, pAiControl, pAiControl->nAiSpecialState);
    pAiControl->dwAiParam[2] = nParam;
    sub_6FCD0150(pGame, pUnit, 1);
}

// 0x005F2A00
D2UnitStrc* __fastcall AITHINK_TargetCallback_GreaterMummy(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2GreaterMummyAiCallbackArgStrc* pArg = (D2GreaterMummyAiCallbackArgStrc*)pCallbackArg;
    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER || pUnit == pTarget || !STATLIST_AreUnitsAligned(pUnit, pTarget) || STATLIST_GetUnitAlignment(pTarget) == UNIT_ALIGNMENT_GOOD || !UNIT_HasFlag(pTarget, UNITFLAG_TARGETABLE) || STATES_CheckStateMaskUdeadOnUnit(pTarget))
    {
        return 0;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pTarget->dwClassId);
    if (pArg->bRadament)
    {
        if (!MONSTERS_IsUndead(pTarget))
        {
            return 0;
        }
    }
    else
    {
        if (!(pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_LUNDEAD >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_LUNDEAD & 7]))
        {
            return 0;
        }
    }

    if (!pArg->bNormal && MONSTERUNIQUE_CheckMonTypeFlag(pTarget, MONTYPEFLAG_UNIQUE) || AITHINK_GetSquaredDistance(pUnit, pTarget) > pArg->nMaxDistance)
    {
        return 0;
    }

    ++pArg->nCounter;
    if (pTarget->dwAnimMode == MONMODE_DEAD && !STATES_CheckStateMaskHideOnUnit(pTarget))
    {
        pArg->pReviveTarget = pTarget;
        ++pArg->nHealReviveCounter;
        return 0;
    }

    const int nHitpoints = STATLIST_UnitGetStatValue(pTarget, STAT_HITPOINTS, 0);
    if (STATLIST_GetMaxLifeFromUnit(pTarget) != nHitpoints && pTarget->dwAnimMode != MONMODE_DEATH)
    {
        pArg->pHealTarget = pTarget;
        ++pArg->nHealReviveCounter;
    }

    return 0;
}

// 0x005F30F0
D2UnitStrc* __fastcall AITHINK_TargetCallback_Vulture(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2VultureAiCallbackArgStrc* pArg = (D2VultureAiCallbackArgStrc*)pCallbackArg;
    if (pTarget && (pTarget->dwUnitType == UNIT_MONSTER || pTarget->dwUnitType == UNIT_PLAYER) && pUnit != pTarget && !MONSTERS_IsDead(pTarget))
    {
        const int nDistance = AITHINK_GetSquaredDistance(pUnit, pTarget);
        if (nDistance <= pArg->nDistance)
        {
            const int nHitpoints = STATLIST_UnitGetStatValue(pTarget, STAT_HITPOINTS, 0);
            if (nHitpoints <= STATLIST_GetMaxLifeFromUnit(pTarget) / 100 * pArg->nLifePercentage)
            {
                pArg->pTarget = pTarget;
                pArg->nDistance = nDistance;
            }
        }
    }

    return 0;
}

// 0x005F4FD0
void __fastcall sub_005F4FD0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (pUnit && pUnit->dwAnimMode == MONMODE_SKILL4)
    {
        pAiControl->dwAiParam[0] = 1;
        AITACTICS_Idle(pGame, pUnit, 1);
        return;
    }

    if (pAiControl->dwAiParam[0] == 4)
    {
        pAiControl->dwAiParam[0] = 1;
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_SKILL3, 0);
        return;
    }

    AITHINK_ExecuteAiFn(pGame, pUnit, pAiControl, pAiControl->nAiSpecialState);
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 1);
}

// 0x005F7700
D2UnitStrc* __fastcall AITHINK_TargetCallback_Mephisto(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2MephistoAiCallbackArgStrc* pArg = (D2MephistoAiCallbackArgStrc*)pCallbackArg;
    if (pUnit == pTarget || SUNIT_IsDead(pTarget) || !pTarget || !UNIT_HasFlag(pTarget, UNITFLAG_CANBEATTACKED) || !sub_00554200(pGame, pUnit, pTarget))
    {
        return 0;
    }

    const int nDistance = AITHINK_GetSquaredDistance(pUnit, pTarget);
    if (nDistance > 1024)
    {
        return 0;
    }

    ++pArg->nCounter;
    if (nDistance <= 225)
    {
        ++pArg->unk0x08;
    }

    if (nDistance < pArg->unk0x04)
    {
        pArg->unk0x00 = pTarget;
        pArg->unk0x04 = nDistance;
    }

    const int nLife = STATLIST_UnitGetStatValue(pTarget, STAT_HITPOINTS, 0) >> 8;
    if (nLife < pArg->unk0x10)
    {
        pArg->unk0x0C = pTarget;
        pArg->unk0x10 = nLife;
    }

    if (nDistance < pArg->unk0x18 && pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        pArg->unk0x14 = pTarget;
        pArg->unk0x18 = nDistance;
    }

    return 0;
}

// 0x005F9950
void __fastcall D2GAME_AI_SpecialState04_6FCDC170(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (STATES_CheckState(pUnit, STATE_INFERNO))
    {
        STATES_ToggleState(pUnit, STATE_INFERNO, 0);
    }

    AITHINK_ExecuteAiFn(pGame, pUnit, pAiTickParam->pAiControl, pAiControl->nAiSpecialState);
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 1);
}

// 0x005F9CF0
void __fastcall AITHINK_Fn066_SandMaggotQueen(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (pAiControl->dwAiParam[2])
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 25 * AI_PARAM(pGame, pMonStatsTxt, 1));
        pAiControl->dwAiParam[2] = 0;
        return;
    }

    if (!pAiControl->dwAiParam[1] && pAiControl->dwAiParam[0] < AI_PARAM(pGame, pMonStatsTxt, 0))
    {
        AITACTICS_ChangeModeAndTargetCoordinatesOneStep(pGame, pUnit, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 8);
        AITACTICS_Idle(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 1));
        pAiControl->dwAiParam[1] = 1;
        return;
    }

    if (pAiControl->dwAiParam[1])
    {
        int nSpawnMode;
        int nMonsterId;
        int nX;
        int nY;
        MONSTERS_GetMinionSpawnInfo(pUnit, &nMonsterId, &nX, &nY, &nSpawnMode, 0, AIGENERAL_GetMinionSpawnClassId);
        D2ActiveRoomStrc* pRoom = D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pUnit), nX, nY);
        if (pRoom)
        {
            D2UnitStrc* pSandMaggot = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nMonsterId, nSpawnMode, 2, 66);
            if (pSandMaggot)
            {
                pSandMaggot->dwFlags |= UNITFLAG_NOXP;
                ++pAiControl->dwAiParam[0];
            }
        }

        AITACTICS_Idle(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 1));
        pAiControl->dwAiParam[1] = 0;
        pAiControl->dwAiParam[2] = 1;
    }
}
