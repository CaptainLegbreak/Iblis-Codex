#include "D2MonsterIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2QuestData.h"

struct Bits;
struct Player;
struct QuestEx;
struct Args;
struct D2PlayerDataStrc;
struct D2Act3Quest5Strc;
struct D2ObjInitFnStrc;

struct Game { char pad0[0x6D]; unsigned char difficulty; };

struct Unit { int type,classId; void* pool; int id; };

struct Player { char pad0[0x10]; Bits* quests[3]; };

struct QuestEx { char pad0[0xC]; unsigned char flag; };

struct Quest { char pad0[9]; unsigned char notIntro; char padA[2]; unsigned char state; char padD[0xB]; QuestEx* ex; char pad1C[0xC4]; int filter; };

struct Args { Game* game; int event; Unit* target; Unit* player; int unknown; Text* text; };

extern unsigned indices[]; // 0x00740ED8
Player* __stdcall sub_006221A0(Unit*); // 0x006221A0
int __stdcall sub_0065C310(Bits*,int,int); // 0x0065C310
int __fastcall QUESTS_CheckPlayerGUID(Quest*,int); // 0x005452C0

enum { QUEST_ID = 21 };




typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

typedef bool (__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

typedef bool (__fastcall* QUESTUPDATE)(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);





D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_SendLogUpdateEx(D2UnitStrc* pPlayer, int nQuestId, unsigned char nAct); // 0x00545920
void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630
int __fastcall ACT3Q5_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BADC0
int __fastcall ACT3Q5_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BAF70
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360

// 0x005BAFD0
void __fastcall sub_005BAFD0(Quest* quest,Args* args)
{
    Game* game=args->game;
    Bits* flags=sub_006221A0(args->player)->quests[game->difficulty];
    int reward=sub_0065C310(flags,QUEST_ID,0);
    int goal=sub_0065C310(flags,QUEST_ID,13);
    int npc=!args->target ? -1 : args->target->classId;
    if(sub_0065C310(flags,quest->filter,4)) {
        if(!quest->ex->flag) sub_00543790(quest,args->text,npc,5);
        return;
    }
    if(reward==1 && !QUESTS_CheckPlayerGUID(quest,!args->player ? -1 : args->player->id)) return;
    unsigned char state=quest->state;
    if(state>=6) {
        if(goal==1) sub_00543790(quest,args->text,npc,6);
        return;
    }
    if(quest->notIntro) {
        unsigned index=indices[state];
        if(index!=-1 && index<8) sub_00543790(quest,args->text,npc,index);
    }
}

#include "gen/data/Source/D2Game/Unknown_005BAFD0.inc"

// 0x005BB0C0
void __fastcall ACT3Q5_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestArg->pTarget || (short)pQuestArg->pTarget->dwClassId != 255)
    {
        return;
    }

    D2Act3Quest5Strc* pQuestDataEx = (D2Act3Quest5Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bOrmusActivated != 1)
    {
        return;
    }

    pQuestData->nStatusFlags = 0;
    QUESTS_UnitIterate(pQuestData, 2, 0, ACT3Q5_UnitIterate_StatusCyclerEx, 1);
    pQuestDataEx->bOrmusActivated = 0;
    pQuestData->pCallback[2] = 0;
    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT3Q5_UnitIterate_UpdateQuestStateFlags);
}

// 0x005BB640
void __fastcall ACT3Q5_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 21, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 21, 4) == 1)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId || DRLG_GetActNoFromLevelId(nLevelId) != 2)
    {
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, 18, 0))
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 21, 0);
    }
    else
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 21, 4);
    }
    QUESTRECORD_SetQuestState(pQuestFlags, 21, 13);
}

// 0x005BB6C0
int __fastcall ACT3Q5_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 21, 13))
    {
        const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
        if (nPartyId != 0xFFFF)
        {
            PARTY_IteratePartyMembers(pGame, nPartyId, ACT3Q5_UnitIterate_SetPrimaryGoalDone, 0);
        }
    }

    return 0;
}

// 0x005BB710
int __fastcall ACT3Q5_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 21, 0) != 1 && QUESTRECORD_GetQuestState(pQuestFlags, 21, 4) != 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 21, 14);
        QUESTS_SendLogUpdateEx(pUnit, 19, 0);
    }

    return 0;
}

// 0x005BB770
int __fastcall ACT3Q5_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 21, 13))
    {
        SUNIT_AttachSound(pUnit, 64, pUnit);
    }

    return 0;
}

// 0x005BBB70
void __fastcall OBJECTS_InitFunction53_StairsR(D2ObjInitFnStrc* pOp)
{
    if (((D2Act3Quest5Strc*)QUESTS_GetQuestData(pOp->pGame, 19)->pQuestDataEx)->bOrbSmashed)
    {
        UNITS_ChangeAnimMode(pOp->pObject, 2);
    }
}

// 0x005BBBA0
void __fastcall OBJECTS_InitFunction60_CompellingOrb(D2ObjInitFnStrc* pOp)
{
    D2Act3Quest5Strc* pQuestDataEx = (D2Act3Quest5Strc*)QUESTS_GetQuestData(pOp->pGame, 19)->pQuestDataEx;
    if (pQuestDataEx->bOrbSmashed)
    {
        UNITS_ChangeAnimMode(pOp->pObject, 2);
    }

    if (pQuestDataEx->bCompellingOrbSpawned)
    {
        return;
    }

    D2UnitStrc* pCompellingOrb = sub_6FC6A090(pOp->pGame, pOp->pRoom, pOp->nX, pOp->nY, MONSTER_COMPELLINGORB, 1, 0);
    if (!pCompellingOrb)
    {
        return;
    }

    pCompellingOrb->dwFlags |= 0x20000;
    pQuestDataEx->nCompellingOrbGUID = pCompellingOrb->dwUnitId;
    pQuestDataEx->bCompellingOrbSpawned = 1;
}
