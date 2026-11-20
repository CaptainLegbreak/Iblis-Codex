#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"

struct D2SkillsTxt { char unk_00[0x48]; short nSrvMissile; char unk_4A[0x74]; unsigned char nPetType; char unk_BF; unsigned int dwPetMax; char unk_C4[0x78]; unsigned int dwCalc[4]; char unk_14C[0xF0]; };
struct D2SummonArgStrc { unsigned int dwFlags; D2UnitStrc* pOwner; int nHcIdx; int nAiSpecialState; int nMonMode; int nX; int nY; int nPetType; int nPetMax; };
struct D2MissileStrc { unsigned int dwFlags; D2UnitStrc* pOwner; D2UnitStrc* pOrigin; D2UnitStrc* pTarget; int nMissile; int nX; int nY; int nTargetX; int nTargetY; int nGfxArg; int nVelocity; int nSkill; int nSkillLevel; int unk_34[10]; };
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" void* __cdecl memset(void*, int, unsigned int); // 0x00681EF0
int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc*, D2UnitStrc*, int*, int*); // 0x0056D2C0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc*, int, int); // 0x00463740
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc*); // 0x0061AB00
int __fastcall D2GAME_GetSummonIdFromSkill_6FD15580(D2UnitStrc*, int, int, int, int*, int*, int*); // 0x0056E620
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc*, unsigned int, int, int); // 0x00646CA0
D2UnitStrc* __fastcall D2GAME_SummonPet_6FD14430(D2GameStrc*, D2SummonArgStrc*); // 0x0056D940
void __fastcall AIGENERAL_SetOwnerData(D2GameStrc*, D2UnitStrc*, int, int, int, int); // 0x0058F030
void __fastcall D2GAME_BOSSES_AssignUMod_6FC6FF10(D2GameStrc*, D2UnitStrc*, int, int); // 0x005A4850
void __fastcall D2GAME_SetSummonPassiveStats_6FD0C530(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int, int, int); // 0x005C4470
void __fastcall sub_6FC40280(D2GameStrc*, D2UnitStrc*, int, int); // 0x005B1990
int __fastcall UNITS_GetXPosition(D2UnitStrc*); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc*, D2MissileStrc*); // 0x0059FA30
void __stdcall MISSILE_SetTargetX(D2UnitStrc*, int); // 0x0064A710
void __stdcall MISSILE_SetTargetY(D2UnitStrc*, int); // 0x0064A760
static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) return &sgptDataTables->pSkillsTxt[nSkillId];
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
// 0x005C58B0
int __fastcall sub_005C58B0_SummonBoneWall(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    int nX;
    int nY;
    int nLength;
    D2MissileStrc missile;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY)) return 0;
    D2ActiveRoomStrc* pRoom = D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pUnit), nX, nY);
    if (!pRoom || DUNGEON_IsRoomInTown(pRoom)) return 0;
    if (pUnit) pUnit->dwFlags |= 0x40;
    D2SkillsTxt* pSkills = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!nSkillId) return 0;
    int nSpawnMode;
    int nSummonId = D2GAME_GetSummonIdFromSkill_6FD15580(pUnit, 0, nSkillId, nSkillLevel, &nSpawnMode, 0, 0);
    if (nSummonId < 0) return 0;
    unsigned char nPetType = pSkills->nPetType;
    if (nPetType >= sgptDataTables->nPetTypeTxtRecordCount) nPetType = 0;
    D2SummonArgStrc summon = {};
    summon.nHcIdx = nSummonId;
    summon.nAiSpecialState = 0;
    summon.dwFlags = 9;
    summon.pOwner = pUnit;
    summon.nMonMode = nSpawnMode;
    summon.nX = nX;
    summon.nY = nY;
    summon.nPetType = nPetType;
    summon.nPetMax = SKILLS_EvaluateSkillFormula(pUnit, pSkills->dwPetMax, nSkillId, nSkillLevel);
    D2UnitStrc* pPet = D2GAME_SummonPet_6FD14430(pGame, &summon);
    if (!pPet) return 0;
    AIGENERAL_SetOwnerData(pGame, pPet, sub_00451F50(pUnit), sub_0044BE50(pUnit), 0, 1);
    D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pPet, 15, 0);
    D2GAME_SetSummonPassiveStats_6FD0C530(pGame, pUnit, pPet, nSkillId, nSkillLevel, 0);
    sub_6FC40280(pGame, pPet, 0, 9);
    nX = UNITS_GetXPosition(pPet);
    nY = CLIENTS_GetUnitY(pPet);
    if (!DUNGEON_IsRoomInTown(pRoom))
    {
        nLength = SKILLS_EvaluateSkillFormula(pUnit, pSkills->dwCalc[0], nSkillId, nSkillLevel) / 2;
        if (nLength > 1 && pSkills->nSrvMissile >= 0 && pSkills->nSrvMissile < sgptDataTables->nMissilesTxtRecordCount)
        {
            memset(&missile, 0, sizeof(missile));
            missile.dwFlags = 0x21;
            missile.pOwner = pUnit;
            missile.nX = nX;
            missile.nY = nY;
            missile.nSkill = nSkillId;
            missile.nSkillLevel = nSkillLevel;
            missile.nMissile = pSkills->nSrvMissile;
            int nDeltaX = UNITS_GetXPosition(pUnit) - nX;
            int nDeltaY = CLIENTS_GetUnitY(pUnit) - nY;
            if (!nDeltaX && !nDeltaY) nDeltaX = 1;
            missile.nTargetX = nX - nDeltaY;
            missile.nTargetY = nY + nDeltaX;
            D2UnitStrc* pMissile = MISSILES_CreateMissileFromParams(pGame, &missile);
            if (pMissile)
            {
                MISSILE_SetTargetX(pMissile, sub_00451F50(pPet));
                MISSILE_SetTargetY(pMissile, nLength);
            }
            missile.nTargetX = nX + nDeltaY;
            missile.nTargetY = nY - nDeltaX;
            pMissile = MISSILES_CreateMissileFromParams(pGame, &missile);
            if (pMissile)
            {
                MISSILE_SetTargetX(pMissile, sub_00451F50(pPet));
                MISSILE_SetTargetY(pMissile, nLength);
            }
        }
        return 1;
    }
    return 0;
}
