#include "D2Game.h"
#include "D2GameStrc.h"

#include "D2UnitData.h"
struct Bits;
struct Player;
struct QuestEx;
struct Args;
struct D2QuestDataExStrc;
struct D2PlayerDataStrc;

struct Game { char pad0[0x6D]; unsigned char difficulty; };

struct Unit { int type,classId; void* pool; int id; };

struct Player { char pad0[0x10]; Bits* quests[3]; };

struct QuestEx { unsigned char birdBrought; };

struct Quest { char pad0[0x18]; QuestEx* ex; };

struct Args { Game* game; int event; Unit* target; Unit* player; int unknown; Text* text; };

Player* __stdcall sub_006221A0(Unit*); // 0x006221A0
int __stdcall sub_0065C310(Bits*,int,int); // 0x0065C310
int __fastcall sub_005452C0(Quest*,int); // 0x005452C0
Unit* __fastcall sub_00558110(Game*,Unit*,unsigned); // 0x00558110

enum { QUEST_ID = 20 };


int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestRecord, int nQuest, int nState); // 0x0065C310
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode); // 0x00558110

struct D2QuestDataExStrc
{
    unsigned char unk_00[0x18];
    int nState18;
};

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestRecord, int nQuestId, int nState); // 0x0065C360

inline Bits* GetFlags(Unit* player,Game* game) { return sub_006221A0(player)->quests[game->difficulty]; }

// 0x005B9ED0
void __fastcall sub_005B9ED0(Quest* quest,Args* args)
{
    Game* game=args->game;
    Bits* flags=GetFlags(args->player,game);
    int reward=sub_0065C310(flags,QUEST_ID,0);
    int npc=!args->target ? -1 : args->target->classId;
    if(reward==1) {
        if(sub_005452C0(quest,!args->player ? -1 : args->player->id)) sub_00543790(quest,args->text,npc,6);
        return;
    }
    if(npc==254 && quest->ex->birdBrought==1) return;
    if(sub_0065C310(flags,QUEST_ID,1)) { sub_00543790(quest,args->text,npc,5); return; }
    if(sub_00558110(args->game,args->player,0x20343367)) {
        if(npc==245) {
            if(!sub_0065C310(flags,QUEST_ID,4)) { sub_00543790(quest,args->text,npc,3); return; }
        } else if(npc==254) {
            if(!sub_0065C310(flags,QUEST_ID,1) && !sub_0065C310(flags,QUEST_ID,0)) sub_00543790(quest,args->text,npc,2);
            return;
        }
        sub_00543790(quest,args->text,npc,2);
        return;
    }
    if(sub_00558110(args->game,args->player,0x2034336A)) {
        if(!sub_0065C310(flags,QUEST_ID,2)) {
            if(npc==245 || npc==252) { sub_00543790(quest,args->text,npc,0); return; }
        } else if(npc==245 || npc==252) { sub_00543790(quest,args->text,npc,7); return; }
        sub_00543790(quest,args->text,npc,1);
    }
}

// 0x005BA170
bool __fastcall ACT3Q4_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    if (!QUESTRECORD_GetQuestState(pFlags, 15, 0))
    {
        *pStatus = 0;
    }
    else if (QUESTRECORD_GetQuestState(pFlags, 20, 1))
    {
        *pStatus = 5;
    }
    else if (QUESTRECORD_GetQuestState(pFlags, 20, 0))
    {
        *pStatus = QUESTRECORD_GetQuestState(pFlags, 20, 13) ? 13 : 11;
    }
    else
    {
        *pStatus = 0;
        D2UnitStrc* pBird = ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 43g');
        D2UnitStrc* pJade = ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 43j');
        if (pBird)
        {
            *pStatus = (QUESTRECORD_GetQuestState(pFlags, 20, 4) != 0) + 3;
        }
        else if (pJade)
        {
            *pStatus = (QUESTRECORD_GetQuestState(pFlags, 20, 2) != 0) + 1;
        }
        else if (pQuest->bNotIntro)
        {
            if (pQuest->fLastState >= 6)
            {
                *pStatus = (pQuest->pGame->nGameType != 3) + 6;
            }
            else
            {
                *pStatus = pQuest->fLastState;
            }
        }
    }

    return true;
}

// 0x005BA290
void __fastcall sub_005BA290_UpdateQuest20(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnused)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x12);
    if (pQuestData)
    {
        D2BitBufferStrc* pQuestRecord = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        if (!QUESTRECORD_GetQuestState(pQuestRecord, 0x14, 0) && !QUESTRECORD_GetQuestState(pQuestRecord, 0x14, 1))
        {
            QUESTRECORD_SetQuestState(pQuestRecord, 0x14, ((D2QuestDataExStrc*)pQuestData->pQuestDataEx)->nState18);
        }
    }
}
