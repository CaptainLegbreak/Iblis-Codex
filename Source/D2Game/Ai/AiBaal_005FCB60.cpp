struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;
struct D2SeedStrc { unsigned int low, high; };
struct D2StaticPathStrc { char pad00[12]; int x, y; };
struct D2UnitStrc {
 int type, classId; void* pool; int id; int mode; void* data;
 char pad18[8]; D2SeedStrc seed; int pad28; void* path;
 char pad30[0x94]; unsigned int flags;
};
struct D2GameStrc { char pad00[0x6D]; unsigned char difficulty; };
struct D2AiControlStrc { char pad00[0x14]; int param[3]; };
struct D2AiCmdStrc { void* next; void* prev; int param[5]; };
struct D2MonStatsTxt { char pad00[0x170]; short skill[8]; unsigned char skillMode[8]; char pad188[0x20]; };
struct D2DataTablesStrc { char pad00[0xA78]; D2MonStatsTxt* monStats; int padA7C; int monCount; };
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const char gszAiBaal[]; // 0x006E3580
int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20
int __stdcall PATH_GetXPosition(D2DynamicPathStrc*); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc*); // 0x00648900
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
int __stdcall UNITS_GetDistanceToOtherUnit(D2UnitStrc*,D2UnitStrc*); // 0x006416D0
void __stdcall UNITS_StoreOwner(D2UnitStrc*,D2UnitStrc*); // 0x00621CE0
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc*); // 0x00625D10
int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc*); // 0x00625D60
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*,int,int); // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc*,int,int,int); // 0x00627260
void __stdcall SKILLS_AssignSkill(D2UnitStrc*,int,int,int,const char*,int); // 0x00647280
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc*,D2UnitStrc*,int); // 0x005DE080
void __fastcall AITACTICS_Idle(D2GameStrc*,D2UnitStrc*,int); // 0x005DE0F0
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc*,D2UnitStrc*,unsigned char); // 0x005DE200
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,unsigned char,int); // 0x005DE6D0
int __fastcall sub_005DF7D0_WalkRandomPath(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,unsigned char,int); // 0x005DF7D0
int __fastcall AITACTICS_WalkToTargetCoordinates(D2GameStrc*,D2UnitStrc*,int,int); // 0x005DED90
int __fastcall AITACTICS_UseSkill(D2GameStrc*,D2UnitStrc*,int,int,D2UnitStrc*,int,int); // 0x005DEAD0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc*,D2UnitStrc*,int,D2UnitStrc*); // 0x005DDF90
int __fastcall MONSTERREGION_FindSpawnLocation(D2GameStrc*,D2ActiveRoomStrc*,void*,int,int*,int*,int); // 0x0054DC40
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc*,D2UnitStrc*); // 0x00552FD0
int __fastcall SUNIT_IsDead(D2UnitStrc*); // 0x005541B0
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc*,D2UnitStrc*); // 0x00553540
void __fastcall SUNIT_AttachSound(D2UnitStrc*,int,int); // 0x00553380
void __fastcall AIBAAL_CountLivingMinions(D2UnitStrc*,void*,void*); // 0x005FC830
void __fastcall AIGENERAL_ExecuteCallbackOnMinions(D2UnitStrc*,void*,void*,void(__fastcall*)(D2UnitStrc*,void*,void*)); // 0x0058F380
void __fastcall AIGENERAL_SetOwnerData(D2GameStrc*,D2UnitStrc*,int,int,int,int); // 0x0058F030
void __fastcall AIGENERAL_AllocMinionList(D2GameStrc*,D2UnitStrc*,D2UnitStrc*); // 0x0058F100
void __stdcall MONSTERS_GetMinionSpawnInfo(D2UnitStrc*,int*,int*,int*,int*,int,int(__fastcall*)(D2UnitStrc*)); // 0x0063EFA0
D2ActiveRoomStrc* __fastcall sub_00463740_GetRoom(D2ActiveRoomStrc*,int,int); // 0x00463740
D2UnitStrc* __fastcall sub_005B2F20_SpawnMonster(D2GameStrc*,D2ActiveRoomStrc*,int,int,int,int,int,int); // 0x005B2F20

static __forceinline int UnitX(D2UnitStrc* u) {
 switch(u->type) {case 2:case 4:case 5:return ((D2StaticPathStrc*)u->path)->x;}
 return u->path?PATH_GetXPosition((D2DynamicPathStrc*)u->path):0;
}
static __forceinline int UnitY(D2UnitStrc* u) {
 switch(u->type) {case 2:case 4:case 5:return ((D2StaticPathStrc*)u->path)->y;}
 return u->path?PATH_GetYPosition((D2DynamicPathStrc*)u->path):0;
}
static __forceinline unsigned int RollSeed(D2SeedStrc* s) {
 unsigned __int64 value=(unsigned __int64)0x6AC690C5*s->low+s->high;
 s->high=(unsigned int)(value>>32);s->low=(unsigned int)value;return s->low;
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
 int monsterId=570<sgptDataTables->monCount?570:-1;
 int unused1,unused2;
 int mode=1;
 MONSTERS_GetMinionSpawnInfo(unit,&monsterId,&unused1,&unused2,&mode,game->difficulty,0);
 D2UnitStrc* target=SUNIT_GetTargetUnit(game,unit);
 int x=target?UnitX(target):UnitX(unit);
 int y=target?UnitY(target):UnitY(unit);
 x+=RollSeed(&unit->seed)%24-12;
 y+=RollSeed(&unit->seed)%24-12;
 D2ActiveRoomStrc* room=sub_00463740_GetRoom(UNITS_GetRoom(unit),x,y);
 if(!room)return false;

 sub_00463740_GetRoom(UNITS_GetRoom(unit),x,y);
 D2UnitStrc* clone=sub_005B2F20_SpawnMonster(game,room,x,y,monsterId,mode,-1,0);
 if(!clone)return false;
 clone->flags|=0x04020000;
 AITACTICS_Idle(game,clone,15);
 AIGENERAL_SetOwnerData(game,unit,unit?unit->id:-1,unit?unit->type:6,1,0);
 AIGENERAL_AllocMinionList(game,unit,clone);
 AIGENERAL_SetOwnerData(game,clone,unit?unit->id:-1,unit?unit->type:6,1,0);
 STATLIST_SetUnitStat(clone,7,STATLIST_GetMaxLifeFromUnit(unit)/3,0);
 STATLIST_SetUnitStat(clone,6,STATLIST_UnitGetStatValue(unit,6,0)/3,0);
 STATLIST_SetUnitStat(clone,74,0,0);
 UNITS_StoreOwner(clone,unit);UNITS_StoreOwner(unit,clone);
 SUNIT_AttachSound(unit,16,0);
 ++control->param[1];return true;
}

static __forceinline D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->monCount)
    {
        return &sgptDataTables->monStats[nMonsterId];
    }

    return 0;
}

// 0x005FCB60
void __fastcall AIBAAL_MainSkillHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, D2UnitStrc* pTarget, int nParam, D2AiCmdStrc* pAiCmd)
{
    D2MonStatsTxt* pMonStatsTxtRecord = 0;
    if (pUnit)
    {
        pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pUnit->classId);
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

        if (pMonStatsTxtRecord->skill[5] > 0 && (STATLIST_GetMaxLifeFromUnit(pTarget) > STATLIST_GetMaxManaFromUnit(pTarget) || pTarget->type != 0))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxtRecord->skillMode[5], pMonStatsTxtRecord->skill[5], pTarget, 0, 0);
        }
        else if (pMonStatsTxtRecord->skill[6] > 0 && pTarget->type == 0)
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxtRecord->skillMode[6], pMonStatsTxtRecord->skill[6], pTarget, 0, 0);
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
        int nDistance = UNITS_GetDistanceToOtherUnit(pUnit, pTarget);
        if (!nDistance)
        {
            nDistance = 1;
        }
        int nFinalX = nX + 25 * (nX - nTargetX) / nDistance;
        int nFinalY = nY + 25 * (nY - nTargetY) / nDistance;

        if (pUnit->classId == 709)
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxtRecord->skillMode[4], pMonStatsTxtRecord->skill[4], 0, nTargetX, nTargetY);
            return;
        }

        if (MONSTERREGION_FindSpawnLocation(pGame, UNITS_GetRoom(pUnit), 0, pUnit->classId, &nFinalX, &nFinalY, 0))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxtRecord->skillMode[4], pMonStatsTxtRecord->skill[4], 0, nFinalX, nFinalY);
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
        switch (pGame->difficulty)
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
