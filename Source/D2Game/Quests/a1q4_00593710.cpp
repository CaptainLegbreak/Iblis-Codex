#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
struct D2SeedStrc;



struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* hObject;
    D2UnitStrc* hPlayer;
    int unk0C;
    unsigned short nObjectIdx;
};
typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc*, D2QuestArgStrc*);

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    unsigned char nActNo;
    unsigned char bNotIntro;
    unsigned char bActive;
    unsigned char fLastState;
    unsigned char fState;
    char nInitNo;
    unsigned short dw0E;
    int nSeqId;
    unsigned int dwFlags;
    void* pQuestDataEx;
    char tPlayerGUIDs[0x84];
    QUESTCALLBACK pCallback[15];
    void* pNPCMessages;
    int eFilter;
};

struct D2Act1Quest4Strc
{
    unsigned short nStoneOrder[6];
    unsigned short nStoneCount;
    unsigned short unk0E;
    int nStoneGUIDs[5];
    int unk24;
    int nInvisibleGUID;
    unsigned short nSoundCounter;
    unsigned short unk2E;
    int nInifussTreeGUID;
    int nCainGibbetGUID;
    int nDecipheredScrollGUID;
    int nPlayerGUID;
    int nCairnStoneAlphaGUID;
    unsigned char bOpenPortalTimerActive;
    unsigned char bPortalToTristramOpened;
    unsigned char bTimerActive;
    unsigned char bInifussTreeInitialized;
    unsigned char bCageModeChanged;
    unsigned char bInvisbleObjectInitialized;
    unsigned char bMonolithStonesOrdered;
    unsigned char unk0x4B;
    unsigned char unk0x4C;
    unsigned char bActivateCairnStones;
    unsigned char bDecipheredScrollAcquired;
    unsigned char bOperatedWithLastCairnStone;
    unsigned char unk0x50;
    unsigned char bCainInTownSpawned;
    unsigned char bCainInTownSpawnPending;
    unsigned char bAkaraIntroActivated;
    int nCainGibbetObjectMode;
    int unk0x58;
    unsigned char bCairnStonesActive[5];
    unsigned char bCainRemovedFromTristram;
    unsigned char bCainNotCreated;
    unsigned char bQuestCompleteBefore;
    unsigned char bAkaraActivatedForScroll;
    unsigned char unk0x65;
    unsigned char bPortalFromTristramToTownSpawned;
    unsigned char bCainPortalCoordsInitialized;
    int nCainMonsterInTownGUID;
    int nCainObjectGUID;
    unsigned char bCainObjectInitialized;
    unsigned char pad0x71[3];
    D2UnitStrc* pPlayerInTristram;
    unsigned char bScrollAcquired;
    unsigned char pad0x79[3];
    int nScrollsInGame;
};

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
typedef bool (__fastcall* QUESTUPDATE)(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" const char szStartedQuest_006E1C7C[];                                                            // 0x006E1C7C
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks);           // 0x00543F10
int __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine); // 0x00544070
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);  // 0x00544350
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                         // 0x00544720
void __fastcall SUNITINACTIVE_DeleteSingleListNode(D2GameStrc* pGame, unsigned short nUnitType, unsigned short nClassId, unsigned char nAct); // 0x00543140
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);              // 0x00552F60
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);            // 0x00553380
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode); // 0x00558110
D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, void* pItemDrop, int a6, int a7); // 0x00559A30
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
int __fastcall ACT1Q4_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x005920D0
int __fastcall ACT1Q4_UnitIterate_RemoveCainFromTristram(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005928C0
int __fastcall ACT1Q4_UnitIterate_AddPlayerGUIDs(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);       // 0x00592B10
void __fastcall ACT1Q4_Callback09_PlayerDroppedWithQuestItem(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00592C80
bool __fastcall ACT1Q4_Timer_RemoveCainFromTristram(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);       // 0x00593260

// 0x00592860
static NOINLINE void sub_00592860_DebugStartedQuest(D2QuestDataStrc* pQuestData)
{
    QUESTS_DebugOutput(pQuestData->pGame, szStartedQuest_006E1C7C, gszA1Q4SourceFile, 599);
}

struct D2ActiveRoomStrc { char unk00[0x74]; D2UnitStrc* pUnitFirst; };
void __fastcall sub_00592E90_OrderStones(D2QuestDataStrc*); // 0x00592E90
void __fastcall QUESTS_DeleteItem(D2GameStrc*,D2UnitStrc*,unsigned int); // 0x00544160
void __stdcall UNITS_GetCoords(D2UnitStrc*,D2CoordStrc*); // 0x00620870
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc*,D2ActiveRoomStrc***,unsigned int*); // 0x00619790
D2UnitStrc* __fastcall sub_0056EDE0_CreatePortal(D2GameStrc*,D2UnitStrc*,int,int,int,int,int); // 0x0056EDE0
void __stdcall sub_0061AED0(D2ActiveRoomStrc*,int); // 0x0061AED0
unsigned short __fastcall SUNIT_GetPartyId(D2UnitStrc*); // 0x00554630
int __fastcall sub_005936B0_UpdateParty(D2GameStrc*,D2UnitStrc*,void*); // 0x005936B0
void __fastcall sub_00540510(D2GameStrc*,unsigned short,QUESTUNITITERATE,void*); // 0x00540510
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc*,int,int); // 0x0065C360
void __fastcall sub_00545760_QuestProgress(D2GameStrc*,unsigned char); // 0x00545760
static __forceinline int GetGUID(D2UnitStrc* pUnit) { return !pUnit ? -1 : pUnit->dwUnitId; }
static __forceinline D2BitBufferStrc* GetPlayerQuestFlags(D2GameStrc* pGame,D2UnitStrc* pPlayer)
{
 return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}
// 0x00593710
int __fastcall sub_00593710(D2ObjOperateFnStrc* pOp,int nOperate)
{
 D2QuestDataStrc* pQuestInfo=QUESTS_GetQuestData(pOp->pGame,4);
 D2_ASSERT(pQuestInfo,0x761);
 D2Act1Quest4Strc* pEx=(D2Act1Quest4Strc*)pQuestInfo->pQuestDataEx;
 if(!pEx->bMonolithStonesOrdered) {
  pEx->bMonolithStonesOrdered=1;
  sub_00592E90_OrderStones(pQuestInfo);
 }
 D2BitBufferStrc* pFlags=GetPlayerQuestFlags(pOp->pGame,pOp->hPlayer);
 if(QUESTRECORD_GetQuestState(pFlags,4,0)==1 || QUESTRECORD_GetQuestState(pFlags,4,1)==1) {
  SUNIT_AttachSound(pOp->hPlayer,0x13,pOp->hPlayer);return 0;
 }
 if(!ITEMS_FindQuestItem(pOp->pGame,pOp->hPlayer,0x20646B62)) {
  if((int)pEx->nSoundCounter%64==0 && !QUESTRECORD_GetQuestState(pFlags,4,3) && !QUESTRECORD_GetQuestState(pFlags,4,4))
   SUNIT_AttachSound(pOp->hPlayer,0x27,pOp->hPlayer);
  ++pEx->nSoundCounter;return 0;
 }
 if(!pQuestInfo->bNotIntro || pQuestInfo->fState>=6) return 0;
 D2UnitStrc* pInvisible=0;
 if(pEx->bInvisbleObjectInitialized==1) {
  pInvisible=SUNIT_GetServerUnit(pOp->pGame,2,pEx->nInvisibleGUID);
  if(!pEx->bDecipheredScrollAcquired && pInvisible && pInvisible->dwClassId==61) {
   if(!pQuestInfo->fState && pQuestInfo->bNotIntro==1) {
    sub_00592860_DebugStartedQuest(pQuestInfo);
    QUESTS_StateDebug(pQuestInfo,1,gszA1Q4SourceFile,0x793);
   }
   if(!ITEMS_FindQuestItem(pOp->pGame,pOp->hPlayer,0x20646B62)) return 0;
  }
 }
 if(pEx->bOperatedWithLastCairnStone==1) return 0;
 if(pQuestInfo->fState!=5) {
  if(!pQuestInfo->fState && pQuestInfo->bNotIntro==1) {
   sub_00592860_DebugStartedQuest(pQuestInfo);
   QUESTS_StateDebug(pQuestInfo,1,gszA1Q4SourceFile,0x7A5);
  }
  if(!ITEMS_FindQuestItem(pOp->pGame,pOp->hPlayer,0x20646B62)) return 0;
  pQuestInfo->fState=5;
 }
 if(pOp->nObjectIdx!=pEx->nStoneOrder[pEx->nStoneCount]) return 0;
 pEx->nStoneGUIDs[pEx->nStoneCount]=GetGUID(pOp->hObject);
 ++pEx->nStoneCount;
 if(pOp->hObject && pOp->hObject->dwAnimMode) return 0;
 unsigned short nCount=pEx->nStoneCount;
 switch(nCount) {
 case 5: {
 UNITS_ChangeAnimMode(pOp->hObject,1);
 if(pInvisible) UNITS_ChangeAnimMode(pInvisible,6);
 pEx->bOperatedWithLastCairnStone=1;
 QUESTS_DeleteItem(pOp->pGame,pOp->hPlayer,0x20646B62);
 --pEx->nScrollsInGame;
 D2CoordStrc coords={0,0};
 for(int i=0;i<5;++i) {
  if(pEx->nStoneOrder[i]==21) {
   D2UnitStrc* pStone=SUNIT_GetServerUnit(pOp->pGame,2,pEx->nStoneGUIDs[i]);
   if(pStone && pStone->dwClassId==21) UNITS_GetCoords(pStone,&coords);
  }
 }
 if(!coords.nX) {
  D2ActiveRoomStrc** ppRooms;
  unsigned int nRooms;
  DUNGEON_GetAdjacentRoomsListFromRoom(UNITS_GetRoom(pOp->hObject),&ppRooms,&nRooms);
  for(unsigned int i=0;i<nRooms;++i) {
   D2UnitStrc* pUnit=ppRooms[i]->pUnitFirst;
   while(pUnit) {
    D2UnitStrc* pNext=pUnit->ptRoomNext;
    if(pUnit->dwUnitType==2 && pUnit->dwClassId==21) {
     UNITS_GetCoords(pUnit,&coords);i=nRooms;break;
    }
    pUnit=pNext;
   }
  }
 }
 if(coords.nX) {
  const int nPortalX=coords.nX+6;
  const int nPortalY=coords.nY-3;
  D2UnitStrc* pPortal=sub_0056EDE0_CreatePortal(pOp->pGame,pOp->hPlayer,0,1,0x120,nPortalX,nPortalY);
  if(pPortal) { D2ActiveRoomStrc* pRoom=UNITS_GetRoom(pPortal);sub_0061AED0(pRoom,0); }
 }
 if(pQuestInfo->fLastState<4) {
  pQuestInfo->dwFlags&=0xFFFFFF00;
  QUESTS_UnitIterate(pQuestInfo,4,pOp->hPlayer,ACT1Q4_UnitIterate_StatusCyclerEx,true);
  unsigned short nParty=SUNIT_GetPartyId(pOp->hPlayer);
  if(nParty!=0xFFFF) sub_00540510(pOp->pGame,nParty,sub_005936B0_UpdateParty,0);
  QUESTRECORD_SetQuestState(pFlags,4,4);
 }
 sub_00545760_QuestProgress(pQuestInfo->pGame,1);
 return 0;
 }
 case 0:case 1:case 2:case 3:case 4:
  UNITS_ChangeAnimMode(pOp->hObject,1);
  if(pInvisible) UNITS_ChangeAnimMode(pInvisible,pEx->nStoneCount+1);
  return 0;
 }
 return 0;
}
