#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])
#define AI_ROLL_PERCENT(pSeed) ((int)((unsigned int)SEED_RollRandomNumber(pSeed) % 100))
union D2SeedStrc;
struct D2MonStatsTxt;
struct D2SkillsTxt;
struct D2NihlathakOverseerAiCallbackArgStrc;




struct D2AiControlStrc
{
    int nSpecialState;
    void* pAiFunction;
    int nAiFlags;
    int nOwnerGUID;
    int nOwnerType;
    int dwAiParam[3];
    int unk20[7];
    int nSpawnClass;
};

struct D2MonStatsTxt
{
    char unk0x000[0x56];
    short wAiParam[8][3];
    char unk0x086[0xEA];
    short nSkill[8];
    unsigned char nSkillMode[8];
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

enum D2C_HydraAi
{
    MONMODE_DEATH = 0,
};

int __fastcall AITACTICS_ChangeModeAndTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY); // 0x005DDFC0
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0


int __fastcall ACT3Q7_GetWandererCoordinates(D2GameStrc* game,D2UnitStrc* unit,D2CoordStrc* coords); // 0x005BD0D0
void __fastcall ACT3Q7_CreateVileDogSpawnTimer(D2GameStrc* game,D2UnitStrc* unit); // 0x005BD4A0
unsigned int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc* unit,int x,int y); // 0x005DC5C0
void __fastcall AITACTICS_SetVelocity(D2UnitStrc* unit,int mode,int velocity,unsigned char flags); // 0x005DE190
int __fastcall AITACTICS_WalkToTargetCoordinates(D2GameStrc* game,D2UnitStrc* unit,int x,int y); // 0x005DED90

struct D2SkillsTxt
{
    int unk_00;
    unsigned int dwFlags;
    char f_8[0x4C];
    short nAuraStat;
    char unk_56[0x2A];
    short nAuraState;
    short nAuraTargetState;
    char unk_84[0x38];
    unsigned short wSummon;
    signed char nPetType;
    char unk_BF[0x171];
    unsigned char nAiType;
    char unk_231[0xB];
};


extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall PLAYERPETS_GetPetTypeFromPetGUID(D2UnitStrc* pPlayer, int nPetGUID); // 0x00574A20
int __fastcall AITHINK_ShadowMasterCheckTargetPetType(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int); // 0x005EAB20
extern const unsigned int gdwBitMasks[32]; // 0x006CE268
int __stdcall STATES_CheckState(D2UnitStrc*, int); // 0x00639DF0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc*, int); // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc*, int, int); // 0x00625D00

struct D2NihlathakOverseerAiCallbackArgStrc
{
    int nMaxDistance;
    int nDistantMaxDistance;
    int nMaxLifePercentage;
    D2UnitStrc* pTarget;
    D2UnitStrc* pDistantTarget;
    int nCounter;
    int unk0x18[4];
};

typedef D2UnitStrc* (__fastcall* AIUTIL_TargetCallback)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg);

enum D2C_M81OverseerAi
{
    MONMODE_ATTACK1 = 4,
    MONMODE_ATTACK2 = 5,
    UNIT_ALIGNMENT_GOOD = 2,
    OVERSEER_AI_PARAM_RALLY_SPELL_TIMER = 0,
    OVERSEER_AI_PARAM_HEAL_CHANCE_PCT = 1,
    OVERSEER_AI_PARAM_WHIP_CHANCE_PCT = 2,
    OVERSEER_AI_PARAM_COMFORT_DISTANCE = 3,
    OVERSEER_AI_PARAM_COMFORT_ZONE = 4,
    OVERSEER_AI_PARAM_ATTACK_CHANCE_PCT = 5,
    OVERSEER_AI_PARAM_ATTACK_2_OR_1_CHANCE_PCT = 6,
};

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
void __fastcall ACT5Q1_OnSiegeBossActivated(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00587900
D2UnitStrc* __fastcall AIUTIL_FindTargetWithCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, void* a3, AIUTIL_TargetCallback a4, int nCallbackId); // 0x005DD0B0
int __fastcall sub_6FCF2E70(D2UnitStrc* pUnit); // 0x005DD2B0
int __fastcall AIUTIL_CheckIfMonsterUsesSkill(D2UnitStrc* pUnit, int nSkillId); // 0x005DD2D0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
D2UnitStrc* __fastcall AITACTICS_GetTargetMinion(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005DE830
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
int __fastcall sub_005DEFE0_Escape(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback); // 0x005DEFE0
int __fastcall sub_005DF7D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a4, int bDeleteAiEventCallback); // 0x005DF7D0
D2UnitStrc* __fastcall AITHINK_TargetCallback_Overseer_Nihlathak(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005E26D0
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0
extern const char gszAiThink4File[]; // 0x006E3500
void __fastcall ACT5Q4_OnNihlathakActivated(D2GameStrc*, D2UnitStrc*); // 0x0058BC40
void __stdcall STATES_ToggleState(D2UnitStrc*, int, int); // 0x00639DB0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc*, int); // 0x006439F0
int __stdcall SKILLS_GetSkillMode(D2SkillStrc*); // 0x00644360
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc*, const char*, int); // 0x00643CE0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc*, D2SkillStrc*, int); // 0x006442A0
void __fastcall AITACTICS_UseSkillInRange(D2UnitStrc*, int, int, unsigned char); // 0x005DF850
D2UnitStrc* __fastcall sub_6FD15210(D2UnitStrc*, D2UnitStrc*, int, int); // 0x0056E390
int __fastcall sub_6FC68350(int, D2ActiveRoomStrc*, int, int, int); // 0x005FD350
int __stdcall D2Common_11063(D2ActiveRoomStrc*, int); // 0x0063EC70
int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc*, D2UnitStrc*, unsigned char); // 0x005DE200
int __fastcall AITACTICS_WalkToTargetUnit(D2GameStrc*, D2UnitStrc*, D2UnitStrc*); // 0x005DECA0

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed);

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static inline int AI_RollPercentage(D2UnitStrc* pUnit)
{
    return (unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) % 100;
}

// 0x005E9E60
void __fastcall sub_005E9E60(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    if (pAiTickParam->pAiControl->dwAiParam[0] < pGame->dwGameFrame)
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, MONMODE_DEATH, 0, 0);
        return;
    }

    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    if (!pTarget)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }
    if ( pAiTickParam->nTargetDistance < 25 && AI_RollPercentage(pUnit) < 60)
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}

// 0x005EA130
void __fastcall sub_005EA130_UpdateWanderer(D2GameStrc* game,D2UnitStrc* unit,D2AiTickParamStrc* tick)
{
 D2AiControlStrc* control=tick->pAiControl;
 D2UnitStrc* target=tick->pTarget;
 int distance=tick->nTargetDistance;
 D2CoordStrc coords;
 if(!ACT3Q7_GetWandererCoordinates(game,unit,&coords)) {
  AITACTICS_IdleInNeutralMode(game,unit,10);return;
 }
 if(!control->dwAiParam[0]) {
  control->dwAiParam[0]=1;control->dwAiParam[1]=0;control->dwAiParam[2]=0;
 }
 if(!target) {AITACTICS_IdleInNeutralMode(game,unit,10);return;}
 if(distance<20) {
  int nState=control->dwAiParam[0];
  {
  if(nState==1) {
   AITACTICS_WalkToTargetCoordinates(game,unit,coords.nX,coords.nY);
   control->dwAiParam[0]=2;return;
  }
  else if(nState==2) {
   if(AIUTIL_GetDistanceToCoordinates(unit,coords.nX,coords.nY)<2) {
    if(unit) unit->dwFlags|=0x20000;
    AITACTICS_ChangeModeAndTargetCoordinates(game,unit,0,0,0);
    ACT3Q7_CreateVileDogSpawnTimer(game,unit);return;
   }
   if(control->dwAiParam[1]<3) {
    ++control->dwAiParam[1];
    AITACTICS_SetVelocity(unit,1,0,0);
    AITACTICS_WalkToTargetCoordinates(game,unit,coords.nX,coords.nY);return;
   }
   if(unit) unit->dwFlags|=0x20000;
   AITACTICS_ChangeModeAndTargetCoordinates(game,unit,0,0,0);
   ACT3Q7_CreateVileDogSpawnTimer(game,unit);return;
  }
  else { AITACTICS_IdleInNeutralMode(game,unit,40); return; }
 }
 }
 AITACTICS_IdleInNeutralMode(game,unit,40);
}

__forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

int __fastcall AITHINK_ShadowMasterCheckTargetPetType(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const short nSummonId = pSkillsTxtRecord->wSummon;
    if (!nSummonId)
    {
        return 1;
    }

    const int nTargetClassId = !pTarget ? -1 : pTarget->dwClassId;
    if ((short)pSkillsTxtRecord->wSummon == (unsigned short)nTargetClassId)
    {
        return 0;
    }

    const int nPetType = pSkillsTxtRecord->nPetType;
    if (nPetType < 0 || nPetType >= sgptDataTables->nPetTypeTxtRecordCount || !pUnit)
    {
        return 1;
    }

    return PLAYERPETS_GetPetTypeFromPetGUID(pUnit, !pTarget ? -1 : pTarget->dwUnitId) != nPetType;
}

// 0x005EABF0
int __fastcall sub_005EABF0_CheckShadowMasterSkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nSkillId, D2AiTickParamStrc* pAiTick)
{
    int bCombat = pAiTick->bCombat;
    D2UnitStrc* pTarget = pAiTick->pTarget;
    D2SkillsTxt* pSkills = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkills || !AITHINK_ShadowMasterCheckTargetPetType(pGame, pOwner, pUnit, nSkillId)) return 0;
    if (bCombat)
    {
        if (pSkills->nAiType != 4 && pSkills->nAiType != 13) return 0;
    }
    else
    {
        if (pSkills->nAiType == 4 || pSkills->nAiType == 13) return 0;
    }
    if (pSkills->nAiType == 1 && pSkills->nAuraState > 0 && STATES_CheckState(pUnit, pSkills->nAuraState)) return 0;
    if (!pTarget)
    {
        switch (pSkills->nAiType)
        {
        case 2: case 4: case 5: case 11: case 12: case 13: return 0;
        }
    }
    if (pSkills->nAiType == 2)
    {
        if (pSkills->nAuraState > 0 && STATES_CheckState(pUnit, pSkills->nAuraState)) return 0;
        if (pSkills->nAuraTargetState > 0 && STATES_CheckState(pTarget, pSkills->nAuraTargetState)) return 0;
    }
    if ((unsigned char)pSkills->dwFlags & (unsigned char)gdwBitMasks[2])
    {
        if (pSkills->nAuraState > 0 && STATES_CheckState(pUnit, pSkills->nAuraState))
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkills->nAuraState);
            if (pStatList && STATLIST_GetStatValue(pStatList, pSkills->nAuraStat, 0) >= 3) return 0;
        }
    }
    return 1;
}

static __forceinline int MONSTERS_ValidateMonsterId(int nMonsterId)
{
    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
        return -1;
    return nMonsterId;
}

// 0x005EE5D0
void __fastcall sub_005EE5D0_ThinkNihlathak(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2SkillStrc* pSkill;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    const int bCombat = pAiTickParam->bCombat;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    ACT5Q4_OnNihlathakActivated(pGame, pUnit);
    if (STATES_CheckState(pUnit, 12))
        STATES_ToggleState(pUnit, 12, 0);
    if (!pTarget)
    {
        pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, pMonStatsTxt->nSkill[0]);
        if (pSkill && sub_6FCF2E70(pUnit))
        {
            AITACTICS_UseSkillInRange(pUnit, AI_PARAM(pGame, pMonStatsTxt, 1), SKILLS_GetSkillIdFromSkill(pSkill, gszAiThink4File, 0x1537), SKILLS_GetSkillMode(pSkill));
            return;
        }
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
        return;
    }
    pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, pMonStatsTxt->nSkill[0]);
    if (pSkill && bCombat && AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pMonStatsTxt, 0))
    {
        AITACTICS_UseSkillInRange(pUnit, AI_PARAM(pGame, pMonStatsTxt, 1), SKILLS_GetSkillIdFromSkill(pSkill, gszAiThink4File, 0x1544), SKILLS_GetSkillMode(pSkill));
        return;
    }
    if (nTargetDistance < AI_PARAM(pGame, pMonStatsTxt, 4) && AI_ROLL_PERCENT(pSeed) < 40)
    {
        if (sub_005DEFE0_Escape(pGame, pUnit, pTarget, 5, 1))
            return;
    }
    if (pMonStatsTxt->nSkill[2] > 0)
    {
        pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, pMonStatsTxt->nSkill[2]);
        if (pSkill && AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pMonStatsTxt, 2))
        {
            D2UnitStrc* pSkillTarget = sub_6FD15210(pUnit, pTarget, pMonStatsTxt->nSkill[2], SKILLS_GetSkillLevel(pUnit, pSkill, 1));
            if (pSkillTarget && AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[2], pMonStatsTxt->nSkill[2], pSkillTarget, 0, 0))
                return;
        }
    }
    if (pMonStatsTxt->nSkill[3] > 0 && SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, pMonStatsTxt->nSkill[3]) && AI_ROLL_PERCENT(pSeed) < 60 && nTargetDistance < 14)
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[3], pMonStatsTxt->nSkill[3], pTarget, 0, 0);
        return;
    }
    if (pMonStatsTxt->nSkill[1] > 0 && AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pMonStatsTxt, 3) && AIUTIL_CheckIfMonsterUsesSkill(pUnit, pMonStatsTxt->nSkill[1]))
    {
        D2NihlathakOverseerAiCallbackArgStrc arg;
        arg.nMaxDistance = 0;
        arg.nDistantMaxDistance = 625;
        arg.nMaxLifePercentage = 50;
        arg.pTarget = 0;
        arg.pDistantTarget = 0;
        arg.nCounter = 0;
        AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, AITHINK_TargetCallback_Overseer_Nihlathak, 1);
        if (arg.pDistantTarget)
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], arg.pDistantTarget, 0, 0);
            return;
        }
        if (pMonStatsTxt->nSkill[4] > 0)
        {
            const int nMonsterId = MONSTERS_ValidateMonsterId(528);
            if (sub_6FC68350(nMonsterId, UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0))
            {
                pAiTickParam->pAiControl->nSpawnClass = D2Common_11063(UNITS_GetRoom(pUnit), MONSTERS_ValidateMonsterId(453));
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[4], pMonStatsTxt->nSkill[4], pTarget, 0, 0);
                return;
            }
        }
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 6);
        return;
    }
    if (pMonStatsTxt->nSkill[3] > 0 && SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, pMonStatsTxt->nSkill[3]) && nTargetDistance < 14)
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[3], pMonStatsTxt->nSkill[3], pTarget, 0, 0);
        return;
    }
    if (AI_ROLL_PERCENT(pSeed) < 60)
        AITACTICS_WalkToTargetUnit(pGame, pUnit, pTarget);
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
}
