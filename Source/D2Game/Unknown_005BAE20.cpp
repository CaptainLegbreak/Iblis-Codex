#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2QuestData.h"
struct D2UnitStrc;
struct D2BitBufferStrc;
struct D2ActiveRoomStrc;
struct D2GameStrc;
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);              // 0x00552F60
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360
static __forceinline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define QUEST_FLAG 21
#define QUEST_ID 19
#define OTHER_QUEST_FLAG 18
#define ROOM_ASSERT_LINE 223

// 0x005BAE20
int __fastcall sub_005BAE20_UpdateQuestStateAfterMonsterKill(D2GameStrc* pGame,D2UnitStrc* pUnit,void* pData)
{
    D2BitBufferStrc* pFlags=PLAYER_GetQuestFlags(pGame,pUnit);
    D2ActiveRoomStrc* pRoom=UNITS_GetRoom(pUnit);
    if (!pRoom) return 0;
    if (QUESTRECORD_GetQuestState(pFlags,QUEST_FLAG,0) || QUESTRECORD_GetQuestState(pFlags,QUEST_FLAG,4)) return 0;
    if (DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom))!=2) return 0;
    D2QuestDataStrc* pQuest=QUESTS_GetQuestData(pGame,QUEST_ID);
    D2Act3Quest5Strc* pEx=(D2Act3Quest5Strc*)pQuest->pQuestDataEx;
    D2UnitStrc* pMonster=SUNIT_GetServerUnit(pGame,1,pEx->nLastKilledMonsterGUID);
    if (!pMonster) return 0;
    D2ActiveRoomStrc* pMonsterRoom=UNITS_GetRoom(pMonster);
    if (!pMonsterRoom) return 0;
    int bInRange=0;
    if(pRoom==pMonsterRoom) bInRange=1;
    else {
        D2ActiveRoomStrc* pUnitRoom=UNITS_GetRoom(pUnit);
        D2_ASSERT(pUnitRoom,ROOM_ASSERT_LINE);
        D2ActiveRoomStrc** ppRoomList;
        unsigned int nNumRooms;
        DUNGEON_GetAdjacentRoomsListFromRoom(pUnitRoom,&ppRoomList,&nNumRooms);
        for(unsigned int i=0;i<nNumRooms;++i){
            if(ppRoomList[i]==pMonsterRoom){bInRange=1;break;}
        }
    }
    pFlags=PLAYER_GetQuestFlags(pGame,pUnit);
    if(bInRange){
        if(QUESTRECORD_GetQuestState(pFlags,OTHER_QUEST_FLAG,0)) QUESTRECORD_SetQuestState(pFlags,QUEST_FLAG,0);
        else QUESTRECORD_SetQuestState(pFlags,QUEST_FLAG,4);
        QUESTRECORD_SetQuestState(pFlags,QUEST_FLAG,13);
    }
    return 0;
}
