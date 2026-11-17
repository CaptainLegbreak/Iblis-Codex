#include "D2Game.h"

// build: context CLIENTS_UnlinkId
// build: context CLIENTS_UnlinkName

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
#define D2_ASSERT(expr,line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2GameStrc {
 char unk00[0x1C]; void* pMemoryPool; char unk20[8]; unsigned short nGameId;
 char unk2A[0x5E]; D2ClientStrc* pClientList; int nClients;
};
struct D2UnitStrc { int dwUnitType; int dwClassId; void* pMemoryPool; int dwUnitId; };
struct D2PacketDataStrc { char data[0x204]; D2PacketDataStrc* pNext; };
struct D2ClientStrc {
 int dwClientId; int dwClientState; unsigned char nClassId; unsigned char unk09; unsigned short nSaveFlags;
 unsigned char nCharTemplate; char szName[16]; char szAccount[16]; char unk2D[0x33];
 int nCharSaveTransactionToken; int unk64; void* pClientInfo; char szPreview[0x100];
 int dwUnitType; int dwUnitId; D2UnitStrc* pPlayer; int unk178; void* pSaveFile;
 char unk180[0x10]; unsigned int nSaveCreationTimestamp[2]; char unk198[0x10]; D2GameStrc* pGame;
 char unk1AC[8]; D2ActiveRoomStrc* pRoom; void* pPacketDataHead; void* pPacketDataTail;
 D2PacketDataStrc* pPacketDataPool; char unk1C4[0x2E4]; D2ClientStrc* pNext; D2ClientStrc* pServerNext; D2ClientStrc* pServerNextByName;
};
typedef void (__fastcall* FnCloseCharacter)(void**, int, int, int, __int64, int, const char*, const char*, int, int, int, const char*, int, int, int, int, int, int, unsigned int*);
struct D2ServerCallbackFunctions { void* pfFirst; FnCloseCharacter pfCloseCharacter; };
extern D2ServerCallbackFunctions* gpD2EventCallbackTable_6FD45830; // 0x00883D50
extern int gbClientListInitialized_008846D8; // 0x008846D8
extern D2CriticalSectionStrc gClientListLock_008846A8; // 0x008846A8
extern D2CriticalSectionStrc gSrvClientListByNameLock_008846C0; // 0x008846C0
extern D2ClientStrc* gpClientList_008842A8[256]; // 0x008842A8
extern D2ClientStrc* gpClientListByName_00883EA8[256]; // 0x00883EA8
extern const char szClientsCppFile[]; // 0x006E0A48
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc*); // 0x006CC214
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(void*); // 0x006CC34C
extern "C" char* __cdecl strcpy(char*, const char*);
unsigned short __stdcall FOG_ComputeStringCRC16(const char*); // 0x004112C0
int __stdcall SStrCmpI(const char*,const char*,int); // 0x00413590
void __fastcall FOG_FreePool(void*,void*,const char*,int,int); // 0x0040B480
D2ClientStrc* __fastcall CLIENTS_GetClientFromClientId(D2GameStrc*, int); // 0x00537810
void __fastcall CLIENTS_FillCharacterPreviewInfo(D2ClientStrc*, char*); // 0x00539BE0
void __fastcall sub_0052C900_SaveClient(D2ClientStrc*,D2GameStrc*); // 0x0052C900
void __fastcall GAME_SendPacket0x5CToAllConnectedClients(D2GameStrc*,D2ClientStrc*); // 0x0052C500
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc*,int); // 0x00537860
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc*,int,int); // 0x006253B0
void __fastcall PARTY_LeaveParty(D2GameStrc*,D2UnitStrc*); // 0x005407A0
void __fastcall PLAYERPETS_FreePetsFromPlayerData(D2GameStrc*,D2UnitStrc*); // 0x005746D0
void __fastcall SUNITPROXY_OnClientRemovedFromGame(D2GameStrc*,D2UnitStrc*); // 0x00537580
void __fastcall sub_00543BD0_PlayerLeftGame(D2GameStrc*,D2UnitStrc*); // 0x00543BD0
void __fastcall PLRTRADE_StopAllPlayerInteractions(D2GameStrc*,D2UnitStrc*); // 0x00568640
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc*,int,int); // 0x0061A270
void __fastcall SUNIT_RemoveUnit(D2GameStrc*,D2UnitStrc*); // 0x00555600
void __stdcall DUNGEON_ChangeClientRoom(D2ActiveRoomStrc*,D2ActiveRoomStrc*); // 0x0061A110
void __stdcall D2Common_10077(D2ActiveRoomStrc*,D2ActiveRoomStrc*); // 0x0061A9F0
void __fastcall LEVEL_RemoveClientFromAdjacentRooms(D2ActiveRoomStrc*,D2ClientStrc*); // 0x0053AB80

static __forceinline void CLIENTS_UnlinkId(int nClientId,char* szName)
{
 const int nIndex=nClientId & 0xFF;
 if(gbClientListInitialized_008846D8) {
  EnterCriticalSection(&gClientListLock_008846A8);
  D2ClientStrc* pCurrent=gpClientList_008842A8[nIndex];
  if(pCurrent) {
   if(pCurrent->dwClientId==nClientId) { strcpy(szName,pCurrent->szName);gpClientList_008842A8[nIndex]=pCurrent->pServerNext; }
   else {
    D2ClientStrc* pPrevious=gpClientList_008842A8[nIndex];
    while(pPrevious->pServerNext->dwClientId!=nClientId) pPrevious=pPrevious->pServerNext;
    D2_ASSERT(pPrevious->pServerNext,0x4EF);
    strcpy(szName,pPrevious->pServerNext->szName);
    pPrevious->pServerNext=pPrevious->pServerNext->pServerNext;
   }
  }
  LeaveCriticalSection(&gClientListLock_008846A8);
 }
}

static __forceinline void CLIENTS_UnlinkName(char* szName)
{
 if(gbClientListInitialized_008846D8) {
  const int nNameIndex=FOG_ComputeStringCRC16(szName)&0xFF;
  EnterCriticalSection(&gSrvClientListByNameLock_008846C0);
  if(gpClientListByName_00883EA8[nNameIndex]) {
   if(!SStrCmpI(gpClientListByName_00883EA8[nNameIndex]->szName,szName,16)) gpClientListByName_00883EA8[nNameIndex]=gpClientListByName_00883EA8[nNameIndex]->pServerNextByName;
   else {
    D2ClientStrc* pName=gpClientListByName_00883EA8[nNameIndex];
    D2_ASSERT(pName->pServerNextByName,0x526);
    while(SStrCmpI(pName->pServerNextByName->szName,szName,16)) { pName=pName->pServerNextByName; if(!pName->pServerNextByName) break; }
    if(pName->pServerNextByName) pName->pServerNextByName=pName->pServerNextByName->pServerNextByName;
   }
  }
  LeaveCriticalSection(&gSrvClientListByNameLock_008846C0);
 }
}

// 0x00539DA0
void __fastcall CLIENTS_RemoveClientFromGame(D2GameStrc* pGame,void* hClientId,int bTriggerSave)
{
 D2_ASSERT(pGame,0x49F);
 D2ClientStrc* pClient=CLIENTS_GetClientFromClientId(pGame,(int)hClientId);
 if(pClient) CLIENTS_FillCharacterPreviewInfo(pClient,pClient->szPreview);
 if(bTriggerSave==1) sub_0052C900_SaveClient(CLIENTS_GetClientFromClientId(pGame,(int)hClientId),pGame);
 char szName[16]; szName[0]=0;
 CLIENTS_UnlinkId((int)hClientId,szName);
 pClient=0;
 D2ClientStrc* pCurrent=pGame->pClientList;
 if(pCurrent) {
  if(pCurrent->dwClientId==(int)hClientId) { pClient=pCurrent;pGame->pClientList=pCurrent->pNext; }
  else {
   while(pCurrent->pNext && pCurrent->pNext->dwClientId!=(int)hClientId) pCurrent=pCurrent->pNext;
   if(pCurrent->pNext) { pClient=pCurrent->pNext;pCurrent->pNext=pClient->pNext; }
  }
 }
 CLIENTS_UnlinkName(szName);
 if(!pClient) return;
 GAME_SendPacket0x5CToAllConnectedClients(pGame,pClient);
 D2UnitStrc* pPlayer=CLIENTS_GetPlayerFromClient(pClient,0);
 if(pPlayer) {
  const __int64 nExperience=STATLIST_GetUnitBaseStat(pPlayer,13,0);
  const int nClassId=pPlayer->dwClassId;
  const int nLevel=(unsigned short)STATLIST_GetUnitBaseStat(pPlayer,12,0);
  PARTY_LeaveParty(pGame,pPlayer);
  PLAYERPETS_FreePetsFromPlayerData(pGame,pPlayer);
  SUNITPROXY_OnClientRemovedFromGame(pGame,pPlayer);
  sub_00543BD0_PlayerLeftGame(pGame,pPlayer);
  PLRTRADE_StopAllPlayerInteractions(pGame,pPlayer);
  D2ActiveRoomStrc* pRoom=UNITS_GetRoom(pPlayer);
  if(pRoom) DUNGEON_AllocDrlgDelete(pRoom,!pPlayer ? 6 : pPlayer->dwUnitType,!pPlayer ? -1 : pPlayer->dwUnitId);
  SUNIT_RemoveUnit(pClient->pGame,pPlayer);
  DUNGEON_ChangeClientRoom(pRoom,0);
  D2Common_10077(pRoom,0);
  if(gpD2EventCallbackTable_6FD45830) {
   D2_ASSERT(!IsBadCodePtr((void*)gpD2EventCallbackTable_6FD45830->pfCloseCharacter),0x5A6);
   if(gpD2EventCallbackTable_6FD45830->pfCloseCharacter) gpD2EventCallbackTable_6FD45830->pfCloseCharacter(&pClient->pClientInfo,pGame->nGameId,nClassId,nLevel,nExperience,pClient->nSaveFlags,pClient->szName,pClient->szPreview,pClient->unk178,0,0,pClient->szAccount,pClient->nCharSaveTransactionToken,0,0,0,0,0,pClient->nSaveCreationTimestamp);
  }
 } else if(gpD2EventCallbackTable_6FD45830) {
  pClient->szPreview[0]=0;
  D2_ASSERT(!IsBadCodePtr((void*)gpD2EventCallbackTable_6FD45830->pfCloseCharacter),0x5CE);
  if(gpD2EventCallbackTable_6FD45830->pfCloseCharacter) gpD2EventCallbackTable_6FD45830->pfCloseCharacter(&pClient->pClientInfo,pGame->nGameId,0,0,0,0,pClient->szName,pClient->szPreview,pClient->unk178,0,0,pClient->szAccount,pClient->nCharSaveTransactionToken,0,0,0,0,0,pClient->nSaveCreationTimestamp);
 }
 if(pClient->pRoom) LEVEL_RemoveClientFromAdjacentRooms(pClient->pRoom,pClient);
 if(pClient->pSaveFile) {
  FOG_FreePool(pClient->pGame->pMemoryPool,pClient->pSaveFile,szClientsCppFile,0x5F5,0);
  pClient->pSaveFile=0;
 }
 while(pClient->pPacketDataPool) {
  D2PacketDataStrc* pPacket=pClient->pPacketDataPool;
  pClient->pPacketDataPool=pPacket->pNext;
  FOG_FreePool(0,pPacket,szClientsCppFile,0x605,0);
 }
 FOG_FreePool(pClient->pGame->pMemoryPool,pClient,szClientsCppFile,0x608,0);
 --pGame->nClients;
}
