#include "D2Game.h"

struct D2CoordStrc { int nX,nY; };
struct D2GameStrc { char unk00[0x6D]; unsigned char nDifficulty; char unk6E[0x3A]; int dwGameFrame; };
struct D2UnitStrc { int dwUnitType,dwClassId; void* pMemoryPool; int dwUnitId,dwAnimMode; char unk14[0xD4]; D2UnitStrc* pRoomNext; };
struct D2ActiveRoomStrc { char unk00[0x74]; D2UnitStrc* pUnitFirst; };
struct D2PlayerDataStrc { char unk00[0x10]; D2BitBufferStrc* pQuestData[3]; };
struct D2Act5Quest2Strc { char unk00[0x84]; unsigned char bQualKehkActivated,unk85,bGroupFreed[3]; char unk89[3]; D2CoordStrc tCageCoords[3]; int nTotalWussies,nKilledWussies,nFreedWussies; int nWussieGUIDs[3][5]; int nPortalGUIDs[3]; unsigned char bPortalSpawned[3]; char unkFB[0x13]; unsigned char bPortalAttempted[3]; };
struct D2QuestDataStrc { int nQuestNo; D2GameStrc* pGame; char unk08[0xC]; unsigned int dwFlags; D2Act5Quest2Strc* pQuestDataEx; };
typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc*,D2UnitStrc*,void*);
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoom(D2ActiveRoomStrc*,int,int); // 0x00463740
void __fastcall EVENT_SetEvent(D2GameStrc*,D2UnitStrc*,int,int,int,int); // 0x005417D0
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc*,int); // 0x00543640
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc*,int,D2UnitStrc*,QUESTUNITITERATE,bool); // 0x00544300
void __fastcall sub_00545340_FindFreePosition(D2ActiveRoomStrc*,D2CoordStrc*,int,int,D2ActiveRoomStrc**,int,int); // 0x00545340
D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc*,int,void*,QUESTUNITITERATE); // 0x005537D0
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int,int,int,int,D2GameStrc*,D2ActiveRoomStrc*,int,int,int); // 0x00555230
int __fastcall ACT5Q2_UnitIterate_StatusCyclerEx(D2GameStrc*,D2UnitStrc*,void*); // 0x005879D0
int __fastcall ACT5Q2_UnitIterate_SetCompletionFlag(D2GameStrc*,D2UnitStrc*,void*); // 0x00587F60
int __fastcall sub_00587FC0_GetWussieGroupIndex(D2QuestDataStrc*,D2UnitStrc*); // 0x00587FC0
int __fastcall ACT5Q2_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc*,D2UnitStrc*,void*); // 0x005887A0
int __fastcall ACT5Q2_UnitIterate_AttachCompletionSound(D2GameStrc*,D2UnitStrc*,void*); // 0x005887F0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc*,D2ActiveRoomStrc***,unsigned int*); // 0x00619790
void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc*,int); // 0x0061AED0
void __stdcall UNITS_GetCoords(D2UnitStrc*,D2CoordStrc*); // 0x00620870
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc*); // 0x006221A0
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc*,D2UnitStrc*); // 0x006416D0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc*,int,int); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc*,int,int); // 0x0065C360
static __forceinline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame,D2UnitStrc* pPlayer) { return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty]; }
static __forceinline int FreedCount(D2Act5Quest2Strc* pEx) { return pEx->nFreedWussies; }
static __forceinline int UnitId(D2UnitStrc* pUnit) { return !pUnit ? -1 : pUnit->dwUnitId; }
// 0x005888D0
void __fastcall sub_005888D0_SpawnRescuePortal(D2GameStrc* pGame,D2UnitStrc* pPlayer,D2UnitStrc* pTarget)
{
 D2QuestDataStrc* pQuestData=QUESTS_GetQuestData(pGame,32);
 if(!pQuestData) return;
 D2Act5Quest2Strc* pQuestDataEx=pQuestData->pQuestDataEx;
 int nIndex=sub_00587FC0_GetWussieGroupIndex(pQuestData,pTarget);
 if(nIndex<0 || pQuestDataEx->bPortalAttempted[nIndex]==1) return;
 else
 {
     D2CoordStrc tCoords;
     tCoords.nX=pQuestDataEx->tCageCoords[nIndex].nX+12;
     tCoords.nY=pQuestDataEx->tCageCoords[nIndex].nY;
     D2ActiveRoomStrc* pTargetRoom=UNITS_GetRoom(pTarget);
     D2ActiveRoomStrc* pRoom=UNITS_GetRoom(pPlayer);
     bool bFound=false;
     if(!pRoom) return;
     D2ActiveRoomStrc** ppRooms;
     unsigned int nRooms;
     DUNGEON_GetAdjacentRoomsListFromRoom(pRoom,&ppRooms,&nRooms);
     for(unsigned int i=0;i<nRooms;++i)
     {
      D2UnitStrc* pUnit=ppRooms[i]->pUnitFirst;
      while(pUnit)
      {
       if((!pUnit ? 6 : pUnit->dwUnitType)==1 && pUnit->dwClassId==434 && pUnit->dwAnimMode==12 && sub_006416D0_UnitEdgeDistance(pUnit,pTarget)<15) break;
       pUnit=pUnit->pRoomNext;
      }
      if(pUnit)
      {
       pTargetRoom=UNITS_GetRoom(pUnit);
       UNITS_GetCoords(pUnit,&tCoords);
       tCoords.nX+=2;
       bFound=true;
      }
     }
     if(!bFound) return;
     pQuestDataEx->bPortalAttempted[nIndex]=1;
     pRoom=sub_00463740_FindRoom(pTargetRoom,tCoords.nX,tCoords.nY);
     D2UnitStrc* pPortal=SUNIT_AllocUnitData(2,189,tCoords.nX,tCoords.nY,pQuestData->pGame,pRoom,1,1,0);
     if(!pPortal)
     {
      pPortal=SUNIT_AllocUnitData(2,189,tCoords.nX-2,tCoords.nY,pQuestData->pGame,pRoom,1,1,0);
      if(!pPortal && pRoom)
      {
       D2ActiveRoomStrc* pFreeRoom=pRoom;
       sub_00545340_FindFreePosition(pRoom,&tCoords,2,0x8000,&pFreeRoom,17,100);
       if(pFreeRoom)
        pPortal=SUNIT_AllocUnitData(2,189,tCoords.nX,tCoords.nY,pQuestData->pGame,pFreeRoom,1,1,0);
       else
        pPortal=SUNIT_AllocUnitData(2,189,tCoords.nX,tCoords.nY,pQuestData->pGame,pRoom,1,1,0);
      }
     }
     if(pPortal)
     {
      pQuestDataEx->bPortalSpawned[nIndex]=1;
      pQuestDataEx->nPortalGUIDs[nIndex]=UnitId(pPortal);
      EVENT_SetEvent(pQuestData->pGame,pPortal,7,pQuestData->pGame->dwGameFrame+25,0,0);
      DUNGEON_ToggleHasPortalFlag(UNITS_GetRoom(pPortal),0);
     }
     D2BitBufferStrc* pQuestFlags=PLAYER_GetQuestFlags(pGame,pPlayer);
     if(pQuestDataEx->nTotalWussies==pQuestDataEx->nKilledWussies+pQuestDataEx->nFreedWussies && pQuestDataEx->bGroupFreed[0] && pQuestDataEx->bGroupFreed[1] && pQuestDataEx->bGroupFreed[2])
     {
      if(pQuestDataEx->nFreedWussies>11)
      {
       pQuestData->dwFlags &= 0xFFFFFF00;
       QUESTS_UnitIterate(pQuestData,3,0,ACT5Q2_UnitIterate_StatusCyclerEx,true);
       if(!QUESTRECORD_GetQuestState(pQuestFlags,36,0) && !QUESTRECORD_GetQuestState(pQuestFlags,36,1))
       {
        QUESTRECORD_SetQuestState(pQuestFlags,36,13);
        QUESTRECORD_SetQuestState(pQuestFlags,36,1);
        const int nFreed = FreedCount(pQuestDataEx);
        if(nFreed==15) QUESTRECORD_SetQuestState(pQuestFlags,36,5);
        else if(nFreed==14) QUESTRECORD_SetQuestState(pQuestFlags,36,6);
        else QUESTRECORD_SetQuestState(pQuestFlags,36,7);
       }
       SUNIT_IterateUnitsOfType(pGame,0,pPlayer,ACT5Q2_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
       SUNIT_IterateUnitsOfType(pGame,0,pPlayer,ACT5Q2_UnitIterate_SetCompletionFlag);
       SUNIT_IterateUnitsOfType(pGame,0,pPlayer,ACT5Q2_UnitIterate_AttachCompletionSound);
      }
      else SUNIT_IterateUnitsOfType(pGame,0,pPlayer,ACT5Q2_UnitIterate_SetCompletionFlag);
     }
     else
     {
      QUESTRECORD_SetQuestState(pQuestFlags,36,4);
      if(pQuestDataEx->nKilledWussies<5)
      {
       pQuestData->dwFlags = (pQuestData->dwFlags & 0xFFFFFF00) | 32;
       QUESTS_UnitIterate(pQuestData,2,0,ACT5Q2_UnitIterate_StatusCyclerEx,true);
      }
      pQuestDataEx->bQualKehkActivated=0;
     }
 }
}
