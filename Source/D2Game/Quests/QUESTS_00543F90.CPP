#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"

#define D2_ASSERT(expr,line) if(!(expr)){sub_00408A60(&gszEmptyAssertText,sub_00408090(),line);exit(-1);}
struct D2RoomStrc;
struct D2QuestControlBlockStrc;
struct D2PlayerDataStrc;
struct D2GSPacketSrv5D;
struct D2DrlgCoordsStrc;

typedef bool (__fastcall* D2QuestStatusFilter)(D2QuestDataStrc*,D2UnitStrc*,D2BitBufferStrc*,D2BitBufferStrc*,unsigned char*);

struct D2QuestDataStrc
{
    int nQuestNo;
    int unknown04;
    unsigned char act;
    unsigned char unk_09[0x2];
    unsigned char fLastState;
    unsigned char fState;
    unsigned char nInitNo;
    unsigned char unk_0E[0x6];
    unsigned int flags;
    char unknown18[0xC8];
    int nQuestFilter;
    int unknownE4;
    D2QuestStatusFilter statusFilter;
    char unknownEC[8];
    D2QuestDataStrc* next;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc*, int, int); // 0x0065C310
extern "C" void* __cdecl memset(void*,int,unsigned int);

struct D2QuestControlBlockStrc { D2QuestDataStrc* first; char unknown04[8]; D2BitBufferStrc* flags; };

struct D2GameStrc { char unknown00[0x6D]; unsigned char difficulty; char unknown6E[0x1086]; D2QuestControlBlockStrc* questControl; };

struct D2PlayerDataStrc { char unknown00[0x10]; D2BitBufferStrc* questFlags[3]; };

struct D2GSPacketSrv5D { unsigned char header,id,flags,state; unsigned short remaining; };

extern const char gszQuestsSourceFile[]; // 0x006E0BE4


D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc*,const char*,int); // 0x005531C0
D2RoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2RoomStrc*); // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int); // 0x006427F0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc*); // 0x006221A0
void __fastcall QUESTS_RefreshStatus(D2QuestDataStrc*,unsigned char*,D2BitBufferStrc*); // 0x00543F90
unsigned short __fastcall ACT1Q1_GetMonstersToBeKilled(D2QuestDataStrc*); // 0x005901E0
unsigned short __fastcall ACT5Q2_GetBarbsToBeRescued(D2QuestDataStrc*); // 0x00588C50
void __fastcall sub_0053D710_SendQuestStatus(D2ClientStrc*,D2GSPacketSrv5D*); // 0x0053D710

typedef int (__stdcall* D2FarProc)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(D2FarProc);


struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
};

D2ActiveRoomStrc* __fastcall COLLISION_GetRoomBySubTileCoordinates(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
void __fastcall QUESTS_GetFreePosition(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, unsigned int nSize, unsigned short fCollision, D2ActiveRoomStrc** ppRoom, int nId, int nRadius); // 0x00545340
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int a7, int a8); // 0x005B2F20
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730

// 0x00543F90
void __fastcall QUESTS_RefreshStatus(D2QuestDataStrc* pQuest, unsigned char* pStatus, D2BitBufferStrc* pFlags)
{
    const int bCompletedBefore = QUESTRECORD_GetQuestState(pFlags, pQuest->nQuestFilter, 14);
    if (pQuest->fState >= pQuest->nInitNo)
    {
        if (QUESTRECORD_GetQuestState(pFlags, pQuest->nQuestFilter, 13) == 1)
        {
            if (pQuest->nQuestFilter >= 41)
            {
                sub_00408A60(&gszEmptyAssertText, sub_00408090(), 1109);
                exit(-1);
            }
            *pStatus = pQuest->fLastState;
            return;
        }
        if (pQuest->nQuestNo == 4 && bCompletedBefore)
        {
            if (pQuest->fState == 6)
            {
                *pStatus = 12;
                return;
            }
            *pStatus = pQuest->fLastState;
            return;
        }
        if (pQuest->nQuestNo == 10)
        {
            *pStatus = pQuest->fLastState == 4 ? 4 : 12;
            return;
        }
        goto status12;
    }
    if (bCompletedBefore)
        goto status12;
    if (pQuest->nQuestNo == 4 && pQuest->fLastState == 6 && !QUESTRECORD_GetQuestState(pFlags, pQuest->nQuestFilter, 13))
        goto status12;
    *pStatus = pQuest->fLastState;
    return;
status12:
    *pStatus = 12;
}

static __forceinline D2QuestDataStrc* GetQuest(D2GameStrc* game,int id) {
 D2QuestControlBlockStrc* control=game->questControl;
 D2_ASSERT(id>=0,119);
 if(!control) return 0;
 for(D2QuestDataStrc* quest=control->first;quest;quest=quest->next)
  if(quest->nQuestNo==id) return quest;
 return 0;
}

// 0x00544190
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id)
{
 D2QuestDataStrc* quest=GetQuest(game,id);
 if(!quest) return;
 D2ClientStrc* client=SUNIT_GetClientFromPlayer(player,gszQuestsSourceFile,1406);
 D2RoomStrc* room=UNITS_GetRoom(player);
 if(!room) return;
 int level=DUNGEON_GetLevelIdFromRoom(room);
 if(level && quest->act==DRLG_GetActNoFromLevelId(level)) {
  D2GSPacketSrv5D packet;
  memset(&packet,0,sizeof(packet));
  packet.header=0x5D;packet.flags=(unsigned char)quest->flags;packet.id=id;packet.state=0;
  D2BitBufferStrc* flags=UNITS_GetPlayerData(player)->questFlags[game->difficulty];
  if(!quest->statusFilter) QUESTS_RefreshStatus(quest,&packet.state,flags);
  else {
   unsigned char state=0;
   D2_ASSERT(!IsBadCodePtr((D2FarProc)quest->statusFilter),1429);
   if(quest->statusFilter(quest,player,game->questControl->flags,flags,&state)==1)
    packet.state=state;
  }
  if(quest->nQuestFilter==1) packet.remaining=ACT1Q1_GetMonstersToBeKilled(quest);
  else if(quest->nQuestFilter==36) packet.remaining=ACT5Q2_GetBarbsToBeRescued(quest);
  sub_0053D710_SendQuestStatus(client,&packet);
 }
}

// 0x005459A0
D2UnitStrc* __fastcall sub_005459A0_SpawnMonsterNear(D2GameStrc* pGame, int nX, int nY, D2ActiveRoomStrc* pRoom, int bQuestFlags, int nMonsterId)
{
    D2ActiveRoomStrc* pFreeRoom = pRoom;
    D2DrlgCoordsStrc tRoomCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tRoomCoords);

    D2CoordStrc tCoord;
    tCoord.nX = nX;
    tCoord.nY = nY;
    int nCounter = 0;
    while (tCoord.nX < tRoomCoords.nSubtileX || tCoord.nY < tRoomCoords.nSubtileY || tCoord.nX >= tRoomCoords.nSubtileX + tRoomCoords.nSubtileWidth - 1 || tCoord.nY >= tRoomCoords.nSubtileY + tRoomCoords.nSubtileHeight - 1)
    {
        ++nCounter;
        ++tCoord.nX;
        ++tCoord.nY;
        if (nCounter > 20)
        {
            tCoord.nX = nY;
            break;
        }
    }

    QUESTS_GetFreePosition(pRoom, &tCoord, 2, 0x100u, &pFreeRoom, 6, 100);

    D2ActiveRoomStrc* pSpawnRoom = pFreeRoom;
    int nSpawnX;
    int nSpawnY;
    if (!pFreeRoom)
    {
        pSpawnRoom = pRoom;
        nSpawnX = nX;
        nSpawnY = nY;
    }
    else
    {
        nSpawnY = tCoord.nY;
        nSpawnX = tCoord.nX;
    }

    D2UnitStrc* pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pSpawnRoom, nSpawnX, nSpawnY, nMonsterId, 1, -1, 0);
    if (!pMonster)
    {
        pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pSpawnRoom, nSpawnX, nSpawnY, nMonsterId, 1, 5, 0);
    }

    if (!pMonster)
    {
        int nTries = 0;
        int nTryX = nSpawnX;
        int nTryY = nSpawnY;
        do
        {
            ++nTryX;
            ++nTryY;
            tCoord.nX = nTryX;
            tCoord.nY = nTryY;
            pFreeRoom = COLLISION_GetRoomBySubTileCoordinates(pSpawnRoom, nTryX, nTryY);
            if (!pFreeRoom)
            {
                pFreeRoom = pRoom;
                tCoord.nX = nX;
                tCoord.nY = nY;
            }

            QUESTS_GetFreePosition(pFreeRoom, &tCoord, 2, 0x100u, &pFreeRoom, 7, 100);
            pSpawnRoom = pFreeRoom;
            if (!pFreeRoom)
            {
                pSpawnRoom = pRoom;
                nTryX = nX;
                nTryY = nY;
            }
            else
            {
                nTryY = tCoord.nY;
                nTryX = tCoord.nX;
            }

            ++nTries;
            pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pSpawnRoom, nTryX, nTryY, nMonsterId, 1, 10, 0);
        }
        while (!pMonster && nTries < 20);

        if (!pMonster)
        {
            pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nMonsterId, 1, 15, 0);
        }
    }

    if (pMonster && bQuestFlags)
    {
        pMonster->dwFlags |= 0x3000000;
    }

    return pMonster;
}
