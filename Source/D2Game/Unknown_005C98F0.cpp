#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2GameTypes.h"

union D2SeedStrc;
struct D2SkillsTxt;
struct D2SummonArgStrc;
struct D2StaticPathStrc;

struct D2SkillsTxt
{
    char unk0x00[0xBE];
    signed char nPetType;
    char unk0xBF;
    unsigned int dwPetMax;
    unsigned char unk_C4[0x6A];
    unsigned short wResultFlags;
    unsigned int dwHitFlags;
    unsigned int dwHitClass;
    char unk_138[0x104];
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" void* __cdecl memset(void*, int, unsigned int); // 0x00681EF0
int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit); // 0x00535060

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
int __fastcall SUNIT_AreUnitsHostile(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00554200
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
int __fastcall sub_004EFC20_GetSkillParam2(int nSkillId); // 0x004EFC20
void __fastcall D2GAME_RollPhysicalDamage_6FD14EC0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E170
int __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0
void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bMissile, D2DamageStrc* pDamage); // 0x0057C6C0
void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x0057CEE0
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nType); // 0x00629BB0
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
int __fastcall D2GAME_PickupItem_6FC43340(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* pItemStatus); // 0x00563560
int __fastcall OBJECTS_OperateHandler(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned short nObjectType, int nObjectGUID, int* pResult); // 0x00584420

struct D2SummonArgStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    int nHcIdx;
    int nAiSpecialState;
    int nMonMode;
    int nX;
    int nY;
    int nPetType;
    int nPetMax;
};

extern const int gnHydraOffsetX_006E312C[]; // 0x006E312C
extern const int gnHydraOffsetY_006E3120[]; // 0x006E3120
int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc* pUnit); // 0x0044BE50
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
int __fastcall sub_004E6CA0_GetSkillParamByLevel(int nSkillId, int nSkillLevel); // 0x004E6CA0
D2AiControlStrc* __fastcall AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit); // 0x00541860
void __fastcall SUNIT_SetAlignment(D2UnitStrc* pUnit, unsigned char nAlignNew, int a3); // 0x005543B0
int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY); // 0x0056D2C0
D2UnitStrc* __fastcall D2GAME_SummonPet_6FD14430(D2GameStrc* pGame, D2SummonArgStrc* pArgs); // 0x0056D940
void __fastcall D2GAME_SetSkills_6FD14C60(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove); // 0x0056DEB0
int __fastcall D2GAME_GetSummonIdFromSkill_6FD15580(D2UnitStrc* pUnit, int bFromMonster, int nSkillId, int nSkillLevel, int* pSpawnMode, int* pX, int* pY); // 0x0056E620
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
void __fastcall AITHINK_SetAiControlParams(D2AiControlStrc* pAiControl, int nParam0, int nParam1, int nParam2); // 0x005B0D70
void __fastcall D2GAME_SetSummonPassiveStats_6FD0C530(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel, int nItemLevel); // 0x005C4470
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0
int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit); // 0x0063EE90
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
void __stdcall COLLISION_ResetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EC10
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance); // 0x00648E70
void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType); // 0x00648CF0
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970
int __stdcall PATH_GetNumberOfPathPoints(D2DynamicPathStrc* pDynamicPath); // 0x00648780
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue); // 0x00644660
int __fastcall sub_00554EA0(Game*,D2UnitStrc*,D2ActiveRoomStrc*,int,int,int,int); // 0x00554EA0
void __stdcall COLLISION_SetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EA90

enum { UNIT_FLAGS = 0xE };

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

static __forceinline int sub_00451F50(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

static __forceinline int sub_0044BE50(D2UnitStrc* pUnit)
{
    return !pUnit ? 6 : pUnit->dwUnitType;
}

// 0x005C98F0
int __fastcall SKILLS_SrvDo021_Telekinesis(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || !pUnit || pUnit->dwUnitType != UNIT_PLAYER || PLAYER_IsBusy(pUnit))
        return 0;
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
        return 0;
    pUnit->dwFlags |= 0x40;
    int nItemStatus = 0;
    int nResult;
    const int nTargetType = sub_0044BE50(pTarget);
    switch (nTargetType)
    {
    case 0:
    case 1:
        {
            if (!SUNIT_AreUnitsHostile(pGame, pUnit, pTarget))
                return 0;
            if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)))
                return 0;
            if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
                return 0;
            int bKnockback = 0;
            if (SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < sub_004EFC20_GetSkillParam2(nSkillId))
                bKnockback = 1;
            D2DamageStrc damage;
            memset(&damage, 0, sizeof(damage));
            D2GAME_RollPhysicalDamage_6FD14EC0(pUnit, &damage, nSkillId, nSkillLevel);
            D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
            damage.wResultFlags |= pSkillsTxtRecord->wResultFlags;
            damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
            if (pSkillsTxtRecord->dwHitClass)
                damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
            if (bKnockback)
                damage.wResultFlags |= 9;
            SUNITDMG_ExecuteEvents(pGame, pUnit, pTarget, 1, &damage);
            SUNITDMG_ExecuteMissileDamage(pGame, pUnit, pTarget, &damage);
            return 1;
        }
    case 4:
        if (!ITEMSIsA(pTarget, 0x16)
            && !ITEMSIsA(pTarget, 4)
            && !ITEMSIsA(pTarget, 0x26)
            && !ITEMSIsA(pTarget, 0x38)
            && !ITEMSIsA(pTarget, 9)
            && !ITEMSIsA(pTarget, 0x29))
        {
            SUNIT_AttachSound(pUnit, 0x13, pUnit);
            return 1;
        }
        D2GAME_PickupItem_6FC43340(pGame, pUnit, sub_00451F50(pTarget), &nItemStatus);
        return 1;
    case 2:
        {
            OBJECTS_OperateHandler(pGame, pUnit, sub_0044BE50(pTarget), sub_00451F50(pTarget), &nResult);
        }
        break;
    }
    return 1;
}

// 0x005CA910
int __fastcall SKILLS_SrvDo144_Hydra(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
        return 0;
    int nSpawnMode;
    const int nSummonId = D2GAME_GetSummonIdFromSkill_6FD15580(pUnit, 0, nSkillId, nSkillLevel, &nSpawnMode, 0, 0);
    if (nSummonId < 0)
        return 0;
    int nPetType = pSkillsTxtRecord->nPetType;
    if (nPetType < 0 || nPetType >= sgptDataTables->nPetTypeTxtRecordCount)
        return 0;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
        return 0;
    int nX;
    int nY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
        return 0;
    pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
    if (!pRoom || DUNGEON_IsRoomInTown(pRoom))
        return 0;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && MONSTERS_GetHirelingTypeId(pUnit))
    {
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
        if (pOwner)
            pUnit = pOwner;
    }
    const int nExpireFrame = pGame->dwGameFrame + sub_004E6CA0_GetSkillParamByLevel(nSkillId, nSkillLevel);
    D2SummonArgStrc summonArg;
    memset(&summonArg, 0, sizeof(summonArg));
    summonArg.dwFlags |= 1;
    summonArg.pOwner = pUnit;
    summonArg.nAiSpecialState = 0;
    summonArg.nMonMode = nSpawnMode;
    summonArg.nPetType = nPetType;
    summonArg.nPetMax = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPetMax, nSkillId, nSkillLevel);
    int nResult = 0;
    for (int i = 0; i < 3; i += 1)
    {
        summonArg.nHcIdx = nSummonId + i;
        summonArg.nX = nX + gnHydraOffsetX_006E312C[i];
        summonArg.nY = nY + gnHydraOffsetY_006E3120[i];
        D2UnitStrc* pPet = D2GAME_SummonPet_6FD14430(pGame, &summonArg);
        if (pPet)
        {
            D2GAME_SetSkills_6FD14C60(pPet, nSkillId, nSkillLevel, 1);
            D2GAME_SetSummonPassiveStats_6FD0C530(pGame, pUnit, pPet, nSkillId, nSkillLevel, 0);
            nResult = 1;
            D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnit(pPet);
            if (pAiControl)
                AITHINK_SetAiControlParams(pAiControl, nExpireFrame, -666, -666);
            if (sub_0044BE50_GetUnitTypeOrInvalid(pUnit) == 1)
                SUNIT_SetAlignment(pPet, STATLIST_GetUnitAlignment(pUnit), 1);
        }
    }
    return nResult;
}

#include "gen/data/Source/D2Game/Unknown_005C98F0.inc"
struct D2ActiveRoomStrc;
struct D2GameStrc;
struct D2UnitStrc;

// 0x005CAF80
int __fastcall SKILLS_SrvSt43_MaggotEgg(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags &= 0xFFFFFFF1;
    }

    PATH_SetUnitDeadCollision(pUnit, 1);
    return 1;
}

static int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x005CB170
int __fastcall SKILLS_SrvSt44_MaggotUp(Game* game,D2UnitStrc* unit,int skillId,int level)
{
    if(!sub_00554EA0(game,unit,UNITS_GetRoom(unit),UNITS_GetUnitXPosition(unit),UNITS_GetUnitYPosition(unit),0,0)) return 0;
    unit->dwFlags |= UNIT_FLAGS;
    COLLISION_SetMaskWithPattern(UNITS_GetRoom(unit),UNITS_GetUnitXPosition(unit),UNITS_GetUnitYPosition(unit),1,0x1000);
    return 1;
}
