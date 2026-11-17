struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2CoordListStrc;
struct D2DynamicPathStrc;
struct D2AiControlStrc;
struct D2SeedStrc { unsigned int nLowSeed, nHighSeed; };
struct D2UnitStrc {
    int dwUnitType; int dwClassId; void* pMemoryPool; int dwUnitId; int dwAnimMode;
    char unk14[12]; D2SeedStrc pSeed; int unk28; D2DynamicPathStrc* pDynamicPath;
    char unk30[0x98]; unsigned int dwFlagsEx;
};
struct D2CoordStrc { int nX, nY; };
struct D2PlayerDataStrc { char unk00[0xA0]; unsigned char nTrailIndex; char unkA1[7]; D2CoordStrc pTrail[20]; };
struct D2PetMoveStrc { D2UnitStrc* pUnit; D2UnitStrc* pTarget; int nCounter; };
struct D2DataTablesStrc { char unk00[0xA80]; int nMonStatsTxtRecordCount; };
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned char gnPetDirections_006E34F0[]; // 0x006E34F0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc*, int); // 0x0045C390
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoom(D2ActiveRoomStrc*, int, int); // 0x00463740
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc*, D2UnitStrc*, int, int); // 0x00540E60
int __fastcall sub_0054DC40_FindSpawnCoordinates(D2GameStrc*, D2ActiveRoomStrc*, D2CoordListStrc*, int, int*, int*, int); // 0x0054DC40
int __fastcall sub_00554EA0_Teleport(D2GameStrc*, D2UnitStrc*, D2ActiveRoomStrc*, int, int, int, int); // 0x00554EA0
void __fastcall sub_005E3900_CountClosePets(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, void*); // 0x005E3900
void __fastcall PLAYERPETS_IteratePets(D2GameStrc*, D2UnitStrc*, void (__fastcall*)(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,void*), void*); // 0x00574DE0
D2AiControlStrc* __fastcall sub_005A6190_GetAiControl(D2UnitStrc*); // 0x005A6190
void __fastcall sub_005A6260_SetAiControl(D2AiControlStrc*, int, int, int); // 0x005A6260
unsigned int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc*,D2UnitStrc*); // 0x005DC380
unsigned int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc*,int,int); // 0x005DC5C0
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc*,D2UnitStrc*,int); // 0x005DE080
void __fastcall AITACTICS_SetVelocity(D2UnitStrc*,int,int,unsigned char); // 0x005DE190
int __fastcall AITACTICS_WalkToTargetCoordinates(D2GameStrc*,D2UnitStrc*,int,int); // 0x005DED90
int __fastcall AITACTICS_RunToTargetCoordinates(D2GameStrc*,D2UnitStrc*,int,int); // 0x005DEDE0
int __fastcall AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(D2GameStrc*,D2UnitStrc*,int,int); // 0x005DEE50
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,unsigned char,int); // 0x005DEFE0
int __fastcall sub_005DF400_WalkAroundUnit(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,unsigned char); // 0x005DF400
int __fastcall D2GAME_AICORE_WalkToOwner_6FCD0B60(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,int); // 0x005DF530
D2CoordListStrc* __stdcall sub_0061AD30_GetCoordList(D2ActiveRoomStrc*,int,int); // 0x0061AD30
D2CoordListStrc* __stdcall sub_0061B130_GetCoordList(D2ActiveRoomStrc*,int,int); // 0x0061B130
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
unsigned char __stdcall sub_00621DC0(D2UnitStrc*,int,int); // 0x00621DC0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc*); // 0x006221A0
unsigned char __stdcall sub_0063E7A0_GetByteTableEntry(unsigned char); // 0x0063E7A0
void __stdcall sub_0063E7E0_GetDirectionDelta(unsigned char,int*,int*); // 0x0063E7E0
int __stdcall PATH_GetX(D2DynamicPathStrc*); // 0x00648A20
int __stdcall PATH_GetY(D2DynamicPathStrc*); // 0x00648A30
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc*); // 0x0064C040

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
        unsigned char nDirection = sub_00621DC0(pPlayer,nOwnerX,nOwnerY);
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
                AITACTICS_SetVelocity(pPet,0,nVelocity,40);
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
        sub_005DF400_WalkAroundUnit(pGame,pPet,pPlayer,4);
        return 1;
    }
    case 1:
    {
        if (nPlayerMode==2)
        {
            AITACTICS_SetVelocity(pPet,0,0,100);
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
                AITACTICS_SetVelocity(pPet,0,nVel,100);
                if (bRun)
                {
                    if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame,pPet,nX,nY)) return 1;
                }
                else
                {
                    if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame,pPet,nX,nY)) return 1;
                }
                D2GAME_EVENTS_Delete_6FC34840(pGame,pPet,2,0);
                AITACTICS_SetVelocity(pPet,15,nVel,100);
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
        AITACTICS_SetVelocity(pPet,0,15,0);
        sub_005DF400_WalkAroundUnit(pGame,pPet,pPlayer,nDist);
        return 1;
    }
    case 2:
        if ((int)SEED_RollLimitedRandomNumber(pSeed,100)<10)
        {
            if (sub_005DF400_WalkAroundUnit(pGame,pPet,pPlayer,(unsigned char)SEED_RollLimitedRandomNumber(pSeed,3)+3)) return 1;
            D2GAME_EVENTS_Delete_6FC34840(pGame,pPet,2,0);
            AITACTICS_SetVelocity(pPet,0,0,40);
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
        int nClass=363>=sgptDataTables->nMonStatsTxtRecordCount ? -1 : 363;
        if (!sub_0054DC40_FindSpawnCoordinates(pGame,pRoom,pCoords,nClass,&nX,&nY,0)) return 0;
        D2ActiveRoomStrc* pNewRoom=sub_00463740_FindRoom(pRoom,nX,nY);
        if (!pNewRoom || !sub_00554EA0_Teleport(pGame,pPet,pNewRoom,nX,nY,0,0)) return 0;
        UNITROOM_RefreshUnit(pPet);
        if (pPet) pPet->dwFlagsEx|=0x10000;
        AITACTICS_IdleInNeutralMode(pGame,pPet,5);
        return 1;
    }
    case 4:
    {
        D2PetMoveStrc tArg;
        tArg.pUnit=pPet;
        tArg.nCounter=0;
        PLAYERPETS_IteratePets(pGame,pPlayer,sub_005E3900_CountClosePets,&tArg);
        if (tArg.nCounter>=1)
        {
            D2GAME_EVENTS_Delete_6FC34840(pGame,pPet,2,0);
            if (D2GAME_AICORE_Escape_6FCD0560(pGame,pPet,pPlayer,nDistance,1)) return 1;
            D2GAME_EVENTS_Delete_6FC34840(pGame,pPet,2,0);
            sub_005DF400_WalkAroundUnit(pGame,pPet,pPlayer,nDistance);
            return 1;
        }
        else
        {
            AITACTICS_IdleInNeutralMode(pGame,pPet,15);
            return 1;
        }
    }
    case 5:
        AITACTICS_SetVelocity(pPet,7,0,0);
        if (D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame,pPet,pPlayer,nDistance)) return 1;
        D2GAME_EVENTS_Delete_6FC34840(pGame,pPet,2,0);
        if (D2GAME_AICORE_Escape_6FCD0560(pGame,pPet,pPlayer,nDistance,1)) return 1;
        AITACTICS_SetVelocity(pPet,0,0,40);
        AITACTICS_WalkToTargetCoordinates(pGame,pPet,nOwnerX,nOwnerY);
        return 1;
    }
    return 0;
}

#include "gen/data/Source/D2Game/005E3930_sub_005E3930_MovePet.inc"
