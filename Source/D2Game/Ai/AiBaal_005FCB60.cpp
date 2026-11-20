#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
struct D2GameStrc;
struct D2SpawnAreaStrc;
struct D2UnitStrc;
struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;
struct D2AiControlStrc { char pad00[0x14]; int param[3]; };
struct D2AiCmdStrc { void* next; void* prev; int param[5]; };
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const char gszAiBaal[]; // 0x006E3580
int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20
int __stdcall PATH_GetXPosition(D2DynamicPathStrc*); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc*); // 0x00648900
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc*,D2UnitStrc*); // 0x006416D0
void __stdcall UNITS_StoreOwner(D2UnitStrc*,D2UnitStrc*); // 0x00621CE0
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc*); // 0x00625D10
int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc*); // 0x00625D60
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*,int,int); // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc*,int,int,int); // 0x00627260
void __stdcall SKILLS_AssignSkill(D2UnitStrc*,int,int,int,const char*,int); // 0x00647280
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc*,D2UnitStrc*,int); // 0x005DE080
void __fastcall AITACTICS_Idle(D2GameStrc*,D2UnitStrc*,int); // 0x005DE0F0
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc*,D2UnitStrc*,unsigned char); // 0x005DE200
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMaxDistance, int bDeleteAiEventCallback); // 0x005DE6D0
int __fastcall sub_005DF7D0_WalkRandomPath(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,unsigned char,int); // 0x005DF7D0
int __fastcall AITACTICS_WalkToTargetCoordinates(D2GameStrc*,D2UnitStrc*,int,int); // 0x005DED90
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc*,D2UnitStrc*,int,D2UnitStrc*); // 0x005DDF90
int __fastcall MONSTERREGION_FindSpawnLocation(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2SpawnAreaStrc* pArea, int nClassId, int* pX, int* pY, int bAvoidWarps); // 0x0054DC40
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc*,D2UnitStrc*); // 0x00552FD0
int __fastcall SUNIT_IsDead(D2UnitStrc*); // 0x005541B0
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc*,D2UnitStrc*); // 0x00553540
void __fastcall SUNIT_AttachSound(D2UnitStrc*,int,int); // 0x00553380
void __fastcall AIBAAL_CountLivingMinions(D2UnitStrc*,void*,void*); // 0x005FC830
void __fastcall AIGENERAL_ExecuteCallbackOnMinions(D2UnitStrc*,void*,void*,void(__fastcall*)(D2UnitStrc*,void*,void*)); // 0x0058F380
void __fastcall AIGENERAL_SetOwnerData(D2GameStrc*,D2UnitStrc*,int,int,int,int); // 0x0058F030
void __fastcall AIGENERAL_AllocMinionList(D2GameStrc*,D2UnitStrc*,D2UnitStrc*); // 0x0058F100
void __stdcall MONSTERS_GetMinionSpawnInfo(D2UnitStrc*,int*,int*,int*,int*,int,int(__fastcall*)(D2UnitStrc*)); // 0x0063EFA0
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc*,int,int); // 0x00463740
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20

static __forceinline int UnitX(D2UnitStrc* u) {
 switch(u->dwUnitType) {case 2:case 4:case 5:return ((D2StaticPathStrc*)u->pDynamicPath)->nXPos;}
 return u->pDynamicPath?PATH_GetXPosition((D2DynamicPathStrc*)u->pDynamicPath):0;
}
static __forceinline int UnitY(D2UnitStrc* u) {
 switch(u->dwUnitType) {case 2:case 4:case 5:return ((D2StaticPathStrc*)u->pDynamicPath)->nYPos;}
 return u->pDynamicPath?PATH_GetYPosition((D2DynamicPathStrc*)u->pDynamicPath):0;
}
static __forceinline unsigned int RollSeed(D2SeedStrc* s) {
 unsigned __int64 value=(unsigned __int64)0x6AC690C5*s->nLowSeed+s->nHighSeed;
 s->nHighSeed=(unsigned int)(value>>32);s->nLowSeed=(unsigned int)value;return s->nLowSeed;
}
__declspec(noinline) static bool __stdcall sub_005FC860_SummonClone(D2GameStrc*,D2UnitStrc*,D2AiControlStrc*);
static bool __stdcall sub_005FC860_SummonClone(D2GameStrc*,D2UnitStrc*,D2AiControlStrc*); // 0x005FC860
// 0x005FC860
static bool __stdcall sub_005FC860_SummonClone(D2GameStrc* game,D2UnitStrc* unit,D2AiControlStrc* control)
{
 D2UnitStrc* temp=unit;
 int living=0;
 AIGENERAL_ExecuteCallbackOnMinions(unit,&temp,&living,AIBAAL_CountLivingMinions);
 if(living)return false;
 D2UnitStrc* owner=SUNIT_GetOwner(game,unit);
 if(owner&&!SUNIT_IsDead(owner))return false;
 int monsterId=570<sgptDataTables->nMonStatsTxtRecordCount?570:-1;
 int unused1,unused2;
 int mode=1;
 MONSTERS_GetMinionSpawnInfo(unit,&monsterId,&unused1,&unused2,&mode,game->nDifficulty,0);
 D2UnitStrc* target=SUNIT_GetTargetUnit(game,unit);
 int x=target?UnitX(target):UnitX(unit);
 int y=target?UnitY(target):UnitY(unit);
 x+=RollSeed(&unit->pSeed)%24-12;
 y+=RollSeed(&unit->pSeed)%24-12;
 D2ActiveRoomStrc* room=sub_00463740_FindRoomAtPoint(UNITS_GetRoom(unit),x,y);
 if(!room)return false;

 sub_00463740_FindRoomAtPoint(UNITS_GetRoom(unit),x,y);
 D2UnitStrc* clone=D2GAME_SpawnMonster_6FC69F10(game,room,x,y,monsterId,mode,-1,0);
 if(!clone)return false;
 clone->dwFlags|=0x04020000;
 AITACTICS_Idle(game,clone,15);
 AIGENERAL_SetOwnerData(game,unit,unit?unit->dwUnitId:-1,unit?unit->dwUnitType:6,1,0);
 AIGENERAL_AllocMinionList(game,unit,clone);
 AIGENERAL_SetOwnerData(game,clone,unit?unit->dwUnitId:-1,unit?unit->dwUnitType:6,1,0);
 STATLIST_SetUnitStat(clone,7,STATLIST_GetMaxLifeFromUnit(unit)/3,0);
 STATLIST_SetUnitStat(clone,6,STATLIST_UnitGetStatValue(unit,6,0)/3,0);
 STATLIST_SetUnitStat(clone,74,0,0);
 UNITS_StoreOwner(clone,unit);UNITS_StoreOwner(unit,clone);
 SUNIT_AttachSound(unit,16,0);
 ++control->param[1];return true;
}

static __forceinline D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

// 0x005FCB60
void __fastcall AIBAAL_MainSkillHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, D2UnitStrc* pTarget, int nParam, D2AiCmdStrc* pAiCmd)
{
    D2MonStatsTxt* pMonStatsTxtRecord = 0;
    if (pUnit)
    {
        pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pUnit->dwClassId);
    }
    if (!pMonStatsTxtRecord)
    {
        return;
    }

    switch (nParam)
    {
    case 5:
        if (!pAiCmd)
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
            return;
        }

        AITACTICS_WalkToTargetCoordinates(pGame, pUnit, pAiCmd->param[1], pAiCmd->param[2]);
        return;
    case 4:
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 16);
        return;
    case 3:
        sub_005DF7D0_WalkRandomPath(pGame, pUnit, pTarget, 6, 1);
        return;
    case 2:
    case 6:
        D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 12, 0);
        return;
    case 9:
        AITACTICS_UseSkill(pGame, pUnit, 9, 315, pTarget, 0, 0);
        return;
    case 11:
        SKILLS_AssignSkill(pUnit, 316, 1, 0, gszAiBaal, 0x452);
        AITACTICS_UseSkill(pGame, pUnit, 10, 316, pTarget, 0, 0);
        return;
    case 13:
        AITACTICS_UseSkill(pGame, pUnit, 4, 318, pTarget, 0, 0);
        return;
    case 10:
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 5, pTarget);
        return;
    case 12:
        AITACTICS_UseSkill(pGame, pUnit, 8, 317, pTarget, 0, 0);
        return;
    case 8:
        if (!pTarget)
        {
            AIBAAL_MainSkillHandler(pGame, pUnit, pAiControl, pTarget, 0, pAiCmd);
            return;
        }

        if (pMonStatsTxtRecord->nSkill[5] > 0 && (STATLIST_GetMaxLifeFromUnit(pTarget) > STATLIST_GetMaxManaFromUnit(pTarget) || pTarget->dwUnitType != 0))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxtRecord->nSkillMode[5], pMonStatsTxtRecord->nSkill[5], pTarget, 0, 0);
        }
        else if (pMonStatsTxtRecord->nSkill[6] > 0 && pTarget->dwUnitType == 0)
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxtRecord->nSkillMode[6], pMonStatsTxtRecord->nSkill[6], pTarget, 0, 0);
        }
        return;
    case 14:
    {
        if (!pTarget)
        {
            AIBAAL_MainSkillHandler(pGame, pUnit, pAiControl, 0, 0, pAiCmd);
            return;
        }

        const int nX = CLIENTS_GetUnitX(pUnit);
        const int nY = CLIENTS_GetUnitY(pUnit);
        const int nTargetX = CLIENTS_GetUnitX(pTarget);
        const int nTargetY = CLIENTS_GetUnitY(pTarget);
        int nDistance = sub_006416D0_UnitEdgeDistance(pUnit, pTarget);
        if (!nDistance)
        {
            nDistance = 1;
        }
        int nFinalX = nX + 25 * (nX - nTargetX) / nDistance;
        int nFinalY = nY + 25 * (nY - nTargetY) / nDistance;

        if (pUnit->dwClassId == 709)
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxtRecord->nSkillMode[4], pMonStatsTxtRecord->nSkill[4], 0, nTargetX, nTargetY);
            return;
        }

        if (MONSTERREGION_FindSpawnLocation(pGame, UNITS_GetRoom(pUnit), 0, pUnit->dwClassId, &nFinalX, &nFinalY, 0))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxtRecord->nSkillMode[4], pMonStatsTxtRecord->nSkill[4], 0, nFinalX, nFinalY);
        }
        else
        {
            AIBAAL_MainSkillHandler(pGame, pUnit, pAiControl, pTarget, 0, pAiCmd);
        }
        return;
    }
    case 15:
        sub_005FC860_SummonClone(pGame, pUnit, pAiControl);
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
        return;
    default:
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
        return;

    case 1:
    {
        int nDelay = 35;
        switch (pGame->nDifficulty)
        {
        case 1:
            nDelay = 15;
            break;
        case 2:
            nDelay = 5;
            break;
        }
        AITACTICS_IdleInNeutralMode(pGame, pUnit, nDelay);
        return;
    }
    }
}
