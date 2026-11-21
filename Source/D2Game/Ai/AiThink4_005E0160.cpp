#include "D2StateIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2GameTypes.h"
#include "D2MonModes.h"

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

struct D2CoordListStrc;
struct D2MonStatsTxt;
union D2SeedStrc;
struct D2MonsterDataStrc;
struct D2PlayerDataStrc;
struct D2PetMoveStrc;

struct D2MonStatsTxt
{
    char unk00[0x56];
    short wAiParam[8][3];
    char unk_86[0xEA];
    short nSkill[8];
    signed char nSkillMode[8];
    char unk_188[0x20];
};

extern D2DataTablesStrc* gpDataTables; // 0x00744304

int __fastcall AITACTICS_ChangeModeAndTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY); // 0x005DDFC0
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080
int __fastcall MONSTERREGION_FindSpawnLocation(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pCoordList, int nClass, int* pX, int* pY, int nAvoid); // 0x0054DC40
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20
int __stdcall D2Common_11063(D2ActiveRoomStrc* pRoom, int nId); // 0x0063EC70
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80

struct D2MonsterDataStrc { char unk_00[0x28]; D2AiControlStrc* pAiControl; };
int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc*, int); // 0x0045C390
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc*, D2UnitStrc*); // 0x00552FD0
int __fastcall SUNIT_IsDead(D2UnitStrc*); // 0x005541B0
void __fastcall AITHINK_ExecuteAiFn(D2GameStrc*, D2UnitStrc*, D2AiControlStrc*, int); // 0x005B0E00
int __fastcall AITACTICS_UseSkill(D2GameStrc*, D2UnitStrc*, unsigned char, int, D2UnitStrc*, int, int); // 0x005DEAD0
void __fastcall AITACTICS_UseSkillInRange(D2UnitStrc* pUnit, int nRange, int nSkillId, int nMode); // 0x005DF850
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc*); // 0x006259B0
int __stdcall STATES_CheckState(D2UnitStrc*, int); // 0x00639DF0
int __fastcall AITACTICS_WalkToTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x005DECA0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

struct D2PlayerDataStrc { char unk00[0xA0]; unsigned char nTrailIndex; char unkA1[7]; D2CoordStrc pTrail[20]; };

struct D2PetMoveStrc { D2UnitStrc* pUnit; D2UnitStrc* pTarget; int nCounter; };

extern const unsigned char gnPetDirections_006E34F0[]; // 0x006E34F0
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc*, int, int); // 0x00463740
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc*, D2UnitStrc*, int, int); // 0x00540E60
int __fastcall sub_0054DC40_FindSpawnCoordinates(D2GameStrc*, D2ActiveRoomStrc*, D2CoordListStrc*, int, int*, int*, int); // 0x0054DC40
int __fastcall sub_6FCBDFE0(D2GameStrc*, D2UnitStrc*, D2ActiveRoomStrc*, int, int, int, int); // 0x00554EA0
void __fastcall sub_6FCE34B0(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, void*); // 0x005E3900
void __fastcall PLAYERPETS_IteratePets(D2GameStrc*, D2UnitStrc*, void (__fastcall*)(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,void*), void*); // 0x00574DE0
D2AiControlStrc* __fastcall sub_005A6190_GetAiControl(D2UnitStrc*); // 0x005A6190
void __fastcall sub_005A6260_SetAiControl(D2AiControlStrc*, int, int, int); // 0x005A6260
unsigned int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc*,D2UnitStrc*); // 0x005DC380
unsigned int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc*,int,int); // 0x005DC5C0
void __fastcall sub_005DE190_SetAiParam(D2UnitStrc* pUnit, int nParam, int nValue, int nArg); // 0x005DE190
int __fastcall AITACTICS_WalkToTargetCoordinates(D2GameStrc*,D2UnitStrc*,int,int); // 0x005DED90
int __fastcall AITACTICS_RunToTargetCoordinates(D2GameStrc*,D2UnitStrc*,int,int); // 0x005DEDE0
int __fastcall AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(D2GameStrc*,D2UnitStrc*,int,int); // 0x005DEE50
int __fastcall sub_005DEFE0_Escape(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,unsigned char,int); // 0x005DEFE0
int __fastcall AITACTICS_WanderToTarget(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,unsigned char); // 0x005DF400
int __fastcall D2GAME_AICORE_WalkToOwner_6FCD0B60(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, unsigned char nMaxDistance); // 0x005DF530
D2CoordListStrc* __stdcall sub_0061AD30_GetCoordList(D2ActiveRoomStrc*,int,int); // 0x0061AD30
D2CoordListStrc* __stdcall sub_0061B130_GetCoordList(D2ActiveRoomStrc*,int,int); // 0x0061B130
int __stdcall UNITS_GetDirectionToCoords(D2UnitStrc* pUnit, int nNewX, int nNewY); // 0x00621DC0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc*); // 0x006221A0
unsigned char __stdcall sub_0063E7A0_GetByteTableEntry(unsigned char); // 0x0063E7A0
void __stdcall sub_0063E7E0_GetDirectionDelta(unsigned char,int*,int*); // 0x0063E7E0
int __stdcall PATH_GetX(D2DynamicPathStrc*); // 0x00648A20
int __stdcall PATH_GetY(D2DynamicPathStrc*); // 0x00648A30
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc*); // 0x0064C040

// build: context ValidateMonsterId
inline int ValidateMonsterId(int nId)
{
    if (nId < 0 || nId >= gpDataTables->nMonStatsTxtRecordCount)
        return -1;
    return nId;
}

// 0x005E0160
void __fastcall sub_005E0160_ThinkSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (!pAiControl->dwAiParam[0])
        pAiControl->dwAiParam[1] = pMonStatsTxt->wAiParam[0][pGame->nDifficulty];
    if (nDistance <= pMonStatsTxt->wAiParam[1][pGame->nDifficulty])
    {
        if (pAiControl->dwAiParam[1] <= 0)
        {
            AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
            return;
        }
        if (pAiControl->dwAiParam[0] <= pGame->dwGameFrame)
        {
            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
            int nMonsterId = D2Common_11063(pRoom, ValidateMonsterId(96));
            int nX;
            int nY;
            if (MONSTERREGION_FindSpawnLocation(pGame, pRoom, 0, nMonsterId, &nX, &nY, 0))
            {
                if (D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nMonsterId, 1, 2, 0x42))
                {
                    --pAiControl->dwAiParam[1];
                    pAiControl->dwAiParam[0] = pGame->dwGameFrame + pMonStatsTxt->wAiParam[2][pGame->nDifficulty];
                }
            }
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
            return;
        }
    }
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
}

// 0x005E1D30
void __fastcall AITHINK_Fn117_SuicideMinion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;

    if (pAiControl->dwAiParam[0] && pGame->dwGameFrame > pAiControl->dwAiParam[0])
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 0, pTarget);
        return;
    }

    if (!pAiControl->dwAiParam[0])
    {
        if (bCombat)
        {
            pAiControl->dwAiParam[0] = AI_PARAM(pGame, pMonStatsTxt, 4) + pGame->dwGameFrame;
            AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 1));
            return;
        }
        else
        {
            const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
            pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
            pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
            if ((int)((unsigned int)lSeed % 100) < AI_PARAM(pGame, pMonStatsTxt, 2))
            {
                AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
                return;
            }
            AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 1));
            return;
        }
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 1));
}

// build: context MONSTERMODE_GetMonStatsTxtRecord
static __forceinline D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nId)
{
    if (nId >= 0 && nId < gpDataTables->nMonStatsTxtRecordCount) return &gpDataTables->pMonStatsTxt[nId];
    return 0;
}

// build: context AIGENERAL_GetAiControlFromUnit
static __forceinline D2AiControlStrc* AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData) return pUnit->pMonsterData->pAiControl;
    return 0;
}

// 0x005E2D80
void __fastcall sub_005E2D80_ThinkControlledMinion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pUnit);
    if (STATES_CheckState(pUnit, STATE_ATTACHED) && pOwner)
    {
        D2MonStatsTxt* pRecords[2] = { MONSTERMODE_GetMonStatsTxtRecord(492), MONSTERMODE_GetMonStatsTxtRecord(493) };
        D2SeedStrc* pSeed = &pUnit->pSeed;
        if (nTargetDistance <= 24 && !SUNIT_IsDead(pOwner) && !STATLIST_GetUnitAlignment(pOwner) && pAiControl->dwAiParam[1])
        {
            if (nTargetDistance < pRecords[1]->wAiParam[1][pGame->nDifficulty]
                && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < pRecords[1]->wAiParam[2][pGame->nDifficulty])
            {
                const int nSkillIndex = pAiTickParam->pAiControl->dwAiParam[1];
                const int bScatter = pAiTickParam->pAiControl->dwAiParam[2];
                CLIENTS_GetUnitX(pTarget);
                CLIENTS_GetUnitY(pTarget);
                if (bScatter)
                {
                    SEED_RollLimitedRandomNumber(pSeed, 2 * pRecords[1]->wAiParam[3][pGame->nDifficulty]);
                    SEED_RollLimitedRandomNumber(pSeed, 2 * pRecords[1]->wAiParam[3][pGame->nDifficulty]);
                }
                if (pRecords[0]->nSkill[nSkillIndex] >= 0)
                {
                    AITACTICS_UseSkill(pGame, pUnit, pRecords[0]->nSkillMode[nSkillIndex], pRecords[0]->nSkill[nSkillIndex], pTarget, 0, 0);
                    return;
                }
            }
            else if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 50)
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 8, pTarget);
                return;
            }
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
            return;
        }
        AITACTICS_UseSkillInRange(pUnit, pRecords[0]->wAiParam[1][pGame->nDifficulty], pRecords[0]->nSkill[0], pRecords[0]->nSkillMode[0]);
        AIGENERAL_GetAiControlFromUnit(pUnit)->dwAiParam[0] = -1;
        return;
    }
    AITHINK_ExecuteAiFn(pGame, pUnit, AIGENERAL_GetAiControlFromUnit(pUnit), 0);
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 1);
}

// build: context SEED_RollRandomNumber
static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005E3530
void __fastcall AITHINK_Fn124_FrozenHorror(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    int nSkillLevel = 0;

    if (pMonStatsTxt->nSkill[0] >= 0)
    {
        D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, pMonStatsTxt->nSkill[0]);
        if (pSkill)
        {
            nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
        }
    }

    if (pMonStatsTxt->nSkill[0] >= 0 && nTargetDistance < (nSkillLevel < 0 ? 0 : nSkillLevel)
        && (int)(SEED_RollRandomNumber(&pUnit->pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, 2)
        && !STATES_CheckState(pUnit, STATE_INFERNO))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        return;
    }

    if (STATES_CheckState(pUnit, STATE_INFERNO))
    {
        STATES_ToggleState(pUnit, 12, 0);
    }

    if (bCombat)
    {
        if ((int)(SEED_RollRandomNumber(&pUnit->pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, 0))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }
        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 3));
        return;
    }

    if ((int)(SEED_RollRandomNumber(&pUnit->pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, 1))
    {
        AITACTICS_WalkToTargetUnit(pGame, pUnit, pTarget);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 3));
}

// 0x005E3930
int __fastcall sub_005E3930_MovePet(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet, int nMode, int bRun, int nVelocity, int nDistance)
{
    D2SeedStrc* pSeed = &pPet->pSeed;
    D2DynamicPathStrc* pPath = pPlayer->pDynamicPath;
    const int nPlayerMode = pPlayer->dwAnimMode;
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    const int nOwnerX = PATH_GetX(pPath);
    const int nOwnerY = PATH_GetY(pPath);
    switch (nMode)
    {
    case 0:
    {
        unsigned char nDirection = UNITS_GetDirectionToCoords(pPlayer,nOwnerX,nOwnerY);
        nDirection = sub_0063E7A0_GetByteTableEntry(nDirection);
        D2CoordListStrc* pCoords = sub_0061B130_GetCoordList(UNITS_GetRoom(pPlayer),CLIENTS_GetUnitX(pPlayer),CLIENTS_GetUnitY(pPlayer));
        for (int i=0;i<8;++i)
        {
            int nDeltaX, nDeltaY;
            sub_0063E7E0_GetDirectionDelta(gnPetDirections_006E34F0[nDirection],&nDeltaX,&nDeltaY);
            const int nX=nOwnerX+8*nDeltaX;
            const int nY=nOwnerY+8*nDeltaY;
            if (sub_0061B130_GetCoordList(UNITS_GetRoom(pPlayer),nX,nY)==pCoords)
            {
                sub_005DE190_SetAiParam(pPet,0,nVelocity,40);
                if (bRun)
                {
                    if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame,pPet,nX,nY)) return 1;
                }
                else
                {
                    if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame,pPet,nX,nY)) return 1;
                }
            }
            nDirection=(nDirection+1)&7;
        }
        D2GAME_EVENTS_Delete_6FC34840(pGame,pPet,2,0);
        AITACTICS_WanderToTarget(pGame,pPet,pPlayer,4);
        return 1;
    }
    case 1:
    {
        if (nPlayerMode==2)
        {
            sub_005DE190_SetAiParam(pPet,0,0,100);
            AITACTICS_WalkToTargetCoordinates(pGame,pPet,nOwnerX,nOwnerY);
            return 1;
        }
        int nVel=nVelocity ? nVelocity : SEED_RollLimitedRandomNumber(pSeed,15)+50;
        unsigned char nTrail=pPlayerData->nTrailIndex;
        D2AiControlStrc* pAi=sub_005A6190_GetAiControl(pPet);
        int bChanged=0;
        for (int i=0;i<20;++i)
        {
            if (!nTrail) nTrail=19; else --nTrail;
            const int nX=pPlayerData->pTrail[nTrail].nX;
            const int nY=pPlayerData->pTrail[nTrail].nY;
            if (AIUTIL_GetDistanceToCoordinates(pPet,nX,nY)>5)
            {
                sub_005DE190_SetAiParam(pPet,0,nVel,100);
                if (bRun)
                {
                    if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame,pPet,nX,nY)) return 1;
                }
                else
                {
                    if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame,pPet,nX,nY)) return 1;
                }
                D2GAME_EVENTS_Delete_6FC34840(pGame,pPet,2,0);
                sub_005DE190_SetAiParam(pPet,15,nVel,100);
                if (bRun)
                {
                    if (AITACTICS_RunToTargetCoordinates(pGame,pPet,nX,nY)) return 1;
                }
                else
                {
                    if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame,pPet,nX,nY)) return 1;
                }
                D2GAME_EVENTS_Delete_6FC34840(pGame,pPet,2,0);
                if (!bChanged)
                {
                    bChanged=1;
                    sub_005A6260_SetAiControl(pAi,1,nVel,100);
                    if (bRun)
                    {
                        if (AITACTICS_RunToTargetCoordinates(pGame,pPet,nX,nY)) return 1;
                    }
                    else
                    {
                        if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame,pPet,nX,nY)) return 1;
                    }
                    D2GAME_EVENTS_Delete_6FC34840(pGame,pPet,2,0);
                }
            }
        }
        int nDist=AIUTIL_GetDistanceToCoordinates_FullUnitSize(pPet,pPlayer)>>2;
        if (nDist<4) nDist=4;
        sub_005DE190_SetAiParam(pPet,0,15,0);
        AITACTICS_WanderToTarget(pGame,pPet,pPlayer,nDist);
        return 1;
    }
    case 2:
        if ((int)SEED_RollLimitedRandomNumber(pSeed,100)<10)
        {
            if (AITACTICS_WanderToTarget(pGame,pPet,pPlayer,(unsigned char)SEED_RollLimitedRandomNumber(pSeed,3)+3)) return 1;
            D2GAME_EVENTS_Delete_6FC34840(pGame,pPet,2,0);
            sub_005DE190_SetAiParam(pPet,0,0,40);
            AITACTICS_WalkToTargetCoordinates(pGame,pPet,nOwnerX,nOwnerY);
            return 1;
        }
        else
        {
            AITACTICS_IdleInNeutralMode(pGame,pPet,15);
            return 1;
        }
    case 3:
    {
        D2ActiveRoomStrc* pRoom=UNITS_GetRoom(pPlayer);
        D2CoordListStrc* pCoords=sub_0061AD30_GetCoordList(pRoom,CLIENTS_GetUnitX(pPlayer),CLIENTS_GetUnitY(pPlayer));
        int nX;
        int nY;
        int nClass=363>=gpDataTables->nMonStatsTxtRecordCount ? -1 : 363;
        if (!sub_0054DC40_FindSpawnCoordinates(pGame,pRoom,pCoords,nClass,&nX,&nY,0)) return 0;
        D2ActiveRoomStrc* pNewRoom=sub_00463740_FindRoomAtPoint(pRoom,nX,nY);
        if (!pNewRoom || !sub_6FCBDFE0(pGame,pPet,pNewRoom,nX,nY,0,0)) return 0;
        UNITROOM_RefreshUnit(pPet);
        if (pPet) pPet->dwFlagEx|=0x10000;
        AITACTICS_IdleInNeutralMode(pGame,pPet,5);
        return 1;
    }
    case 4:
    {
        D2PetMoveStrc tArg;
        tArg.pUnit=pPet;
        tArg.nCounter=0;
        PLAYERPETS_IteratePets(pGame,pPlayer,sub_6FCE34B0,&tArg);
        if (tArg.nCounter>=1)
        {
            D2GAME_EVENTS_Delete_6FC34840(pGame,pPet,2,0);
            if (sub_005DEFE0_Escape(pGame,pPet,pPlayer,nDistance,1)) return 1;
            D2GAME_EVENTS_Delete_6FC34840(pGame,pPet,2,0);
            AITACTICS_WanderToTarget(pGame,pPet,pPlayer,nDistance);
            return 1;
        }
        else
        {
            AITACTICS_IdleInNeutralMode(pGame,pPet,15);
            return 1;
        }
    }
    case 5:
        sub_005DE190_SetAiParam(pPet,7,0,0);
        if (D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame,pPet,pPlayer,nDistance)) return 1;
        D2GAME_EVENTS_Delete_6FC34840(pGame,pPet,2,0);
        if (sub_005DEFE0_Escape(pGame,pPet,pPlayer,nDistance,1)) return 1;
        sub_005DE190_SetAiParam(pPet,0,0,40);
        AITACTICS_WalkToTargetCoordinates(pGame,pPet,nOwnerX,nOwnerY);
        return 1;
    }
    return 0;
}

#include "gen/data/Source/D2Game/Ai/AiThink4_005E0160.inc"
struct D2ActiveRoomStrc;
struct D2GameStrc;
struct D2UnitStrc;
