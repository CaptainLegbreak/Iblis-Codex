#include "D2Game.h"
#include "D2Structs.h"
struct D2GameStrc;
struct D2UnitStrc;

#pragma pack(push,1)
struct D2Packet8A { unsigned char header; unsigned char type; int guid; };
#pragma pack(pop)
int __fastcall ACT5Q2_FindPortal(D2GameStrc*,D2UnitStrc*,D2UnitStrc**); // 0x00588D60
int __fastcall ACT5Q2_CheckWussieCounters(D2GameStrc*,D2UnitStrc*); // 0x00588830
void __fastcall ACT5Q2_UpdateWussieCounters(D2GameStrc*,int,D2UnitStrc*); // 0x00588880
int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20
unsigned int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc*,int,int); // 0x005DC5C0
void __stdcall sub_00648730(D2DynamicPathStrc*); // 0x00648730
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc*,int,int); // 0x0061A270
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc*); // 0x00623830
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc*); // 0x0064C370
void __fastcall SUNIT_RemoveUnit(D2GameStrc*,D2UnitStrc*); // 0x00555600
int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc*,int); // 0x0045C390
void __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,int); // 0x005DEC80
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMaxDistance); // 0x005DE200
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc*,D2UnitStrc*,int); // 0x005DE080
D2UnitStrc* __fastcall sub_6FCCFD70(D2GameStrc*,D2UnitStrc*,int*); // 0x005DDF20
int __fastcall sub_00588E10_IsMonsterNearby(D2GameStrc*,D2UnitStrc*,D2UnitStrc*); // 0x00588E10
void __fastcall sub_005888D0_SpawnRescuePortal(D2GameStrc*,D2UnitStrc*,D2UnitStrc*); // 0x005888D0
void __fastcall sub_6FC40280(D2GameStrc*,D2UnitStrc*,int,int); // 0x005B1990
void __fastcall ACT5Q2_OnWussieActivated(D2GameStrc*,D2UnitStrc*,D2UnitStrc*); // 0x00588DD0
extern const char gszAiThink4[]; // 0x006E3500
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc*,const char*,int); // 0x005531C0
void __fastcall sub_0053DFF0(D2ClientStrc*,D2Packet8A*); // 0x0053DFF0
// build: context SEED_RollRandomNumber
static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}
// 0x005EE3C0
void __fastcall AITHINK_Fn131_Wussie(D2GameStrc* pGame,D2UnitStrc* pUnit,D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pPortal = 0;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    if (ACT5Q2_FindPortal(pGame,pUnit,&pPortal))
    {
        if (pPortal && (ACT5Q2_CheckWussieCounters(pGame,pUnit) || AIUTIL_GetDistanceToCoordinates(pUnit,CLIENTS_GetUnitX(pPortal),CLIENTS_GetUnitY(pPortal)) < 4))
        {
            ACT5Q2_UpdateWussieCounters(pGame,0,pUnit);
            sub_00648730(pUnit->pDynamicPath);
            sub_00540E60(pGame,pUnit,2,0);
            const int nUnitId = pUnit->dwUnitId;
            const int nUnitType = pUnit->dwUnitType;
            DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pUnit),nUnitType,nUnitId);
            UNITS_FreeCollisionPath(pUnit);
            UNITROOM_RemoveUnitFromRoom(pUnit);
            SUNIT_RemoveUnit(pGame,pUnit);
            return;
        }
        if (pPortal)
        {
            if ((int)(SEED_RollRandomNumber(pSeed) % 100) < 70)
                AITACTICS_WalkToTargetUnitWithFlags(pGame,pUnit,pPortal,7);
            else if (SEED_RollLimitedRandomNumber(pSeed,100) < 10)
                AITACTICS_WalkCloseToUnit(pGame,pUnit,4);
            else
                AITACTICS_IdleInNeutralMode(pGame,pUnit,10);
            return;
        }
    }
    else
    {
        int bCloseToTarget = 0;
        D2UnitStrc* pPlayer = sub_6FCCFD70(pGame,pUnit,&bCloseToTarget);
        if (pPlayer && pPlayer->dwUnitType == 0)
        {
            if (sub_00588E10_IsMonsterNearby(pGame,pPlayer,pUnit))
            {
                sub_005888D0_SpawnRescuePortal(pGame,pPlayer,pUnit);
                if (pUnit->dwNodeIndex == 11)
                {
                    sub_6FC40280(pGame,pUnit,0,8);
                    AITACTICS_IdleInNeutralMode(pGame,pUnit,25);
                    return;
                }
            }
            else
            {
                ACT5Q2_OnWussieActivated(pGame,pPlayer,pUnit);
                if (SEED_RollLimitedRandomNumber(pSeed,1000) < 100)
                {
                    D2Packet8A packet;
                    packet.header = 0x8A;
                    packet.type = 1;
                    const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
                    packet.guid = nUnitGUID;
                    sub_0053DFF0(UnitGetClient(pPlayer,gszAiThink4,0x14FF),&packet);
                }
            }
        }
    }
    AITACTICS_IdleInNeutralMode(pGame,pUnit,25);
}
