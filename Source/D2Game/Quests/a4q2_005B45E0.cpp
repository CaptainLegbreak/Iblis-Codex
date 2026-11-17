#include "D2Game.h"

#define OFFSET(T,F) ((unsigned int)&(((T*)0)->F))
struct D2PlayerDataStrc;
struct D2Act4Quest2Strc;
struct DeadControl;
struct BoundRecord;
struct QueueNode;
struct QueueState;
struct QuestExtra;
struct QuestView;

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x02];
    int bExpansion;
};

struct D2UnitStrc
{
    char unk0x00[0x04];
    unsigned short dwClassId;
    char unk0x06[0xBE];
    unsigned int dwFlags;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    unsigned int unk0x10;
    short nNPCNo;
    char unk0x16[0x02];
    short nMessageIndex;
};

struct D2Act4Quest2Strc
{
    unsigned char bTalkedToTyrael;
    char unk0x01[0x43];
    unsigned char unk0x44;
    unsigned char bPortalToAct5Spawned;
};

struct D2QuestDataStrc
{
    char unk0x00[0x04];
    D2GameStrc* pGame;
    char unk0x08[0x0C];
    unsigned char bActive;
    char unk0x15[0x03];
    D2Act4Quest2Strc* pQuestDataEx;
};

typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __fastcall QUESTS_GetFreePosition(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, unsigned int nSize, unsigned short fCollision, D2ActiveRoomStrc** ppRoom, int nId, int nRadius); // 0x00545340
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
void __fastcall QUESTS_NPCActivateSpeeches(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTarget); // 0x00545780
void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C3A0
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
D2BitBufferStrc* __fastcall sub_00543520(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00543520
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __fastcall ACT4Q2_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B4560
int __fastcall ACT4Q2_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B4E40

struct DeadControl
{
    char gap0[0x8];
    unsigned int flags;
    char gapC[0x30];
    DeadControl* next;
};

struct BoundRecord
{
    char gap0[0x4];
    unsigned short active;
};

struct QueueNode
{
    char gap0[0x8];
    BoundRecord* binding;
    QueueNode* next;
    QueueNode* previous;
};

struct QueueState
{
    unsigned int first;
    unsigned int second;
    unsigned int count;
    QueueNode* activeHead;
    QueueNode* activeTail;
    QueueNode* freeHead;
    QueueNode* freeTail;
    void* buffer;
};

struct QuestExtra
{
    char gap0[0x13];
    unsigned char flag;
};

struct QuestView
{
    char gap0[0x18];
    QuestExtra* extra;
};

typedef char check_pointer_width[sizeof(void*)==4?1:-1];

typedef char check_DeadControl_flags[OFFSET(DeadControl,flags)==0x8?1:-1];

typedef char check_DeadControl_next[OFFSET(DeadControl,next)==0x3C?1:-1];

typedef char check_DeadControl_size[sizeof(DeadControl)==0x40?1:-1];

typedef char check_BoundRecord_active[OFFSET(BoundRecord,active)==0x4?1:-1];

typedef char check_BoundRecord_size[sizeof(BoundRecord)==0x6?1:-1];

typedef char check_QueueNode_binding[OFFSET(QueueNode,binding)==0x8?1:-1];

typedef char check_QueueNode_next[OFFSET(QueueNode,next)==0xC?1:-1];

typedef char check_QueueNode_previous[OFFSET(QueueNode,previous)==0x10?1:-1];

typedef char check_QueueNode_size[sizeof(QueueNode)==0x14?1:-1];

typedef char check_QueueState_first[OFFSET(QueueState,first)==0x0?1:-1];

typedef char check_QueueState_second[OFFSET(QueueState,second)==0x4?1:-1];

typedef char check_QueueState_count[OFFSET(QueueState,count)==0x8?1:-1];

typedef char check_QueueState_activeHead[OFFSET(QueueState,activeHead)==0xC?1:-1];

typedef char check_QueueState_activeTail[OFFSET(QueueState,activeTail)==0x10?1:-1];

typedef char check_QueueState_freeHead[OFFSET(QueueState,freeHead)==0x14?1:-1];

typedef char check_QueueState_freeTail[OFFSET(QueueState,freeTail)==0x18?1:-1];

typedef char check_QueueState_buffer[OFFSET(QueueState,buffer)==0x1C?1:-1];

typedef char check_QueueState_size[sizeof(QueueState)==0x20?1:-1];

typedef char check_QuestExtra_flag[OFFSET(QuestExtra,flag)==0x13?1:-1];

typedef char check_QuestExtra_size[sizeof(QuestExtra)==0x14?1:-1];

typedef char check_QuestView_extra[OFFSET(QuestView,extra)==0x18?1:-1];

typedef char check_QuestView_size[sizeof(QuestView)==0x1C?1:-1];

extern "C" int __fastcall FOG_Free(void* memory, const char* file, int line, int flags);
extern "C" QuestView* __fastcall QUESTS_GetQuestData(Game* game, int id); // 0x00543640
extern "C" int gCleanupSuppression_007D55C4;
extern "C" DeadControl* gDeadHead_007D55C0;
extern "C" unsigned int gFirstMask_006CE268;
extern "C" unsigned int gSecondMask_006CE26C;
extern "C" const char gControlSource_006DC6A4[];
extern "C" const char gQueueSource_006DD5B4[];

// 0x005B45E0
static void sub_005B45E0_ACT4Q2_SpawnPortalToAct5(D2QuestArgStrc* pQuestArg, D2Act4Quest2Strc* pQuestDataEx)
{
    D2CoordStrc pCoord;
    UNITS_GetCoords(pQuestArg->pTarget, &pCoord);
    pCoord.nX += 5;

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pQuestArg->pTarget);
    QUESTS_GetFreePosition(UNITS_GetRoom(pQuestArg->pTarget), &pCoord, 2, 0x400, &pRoom, 12, 100);
    if (!pRoom)
    {
        return;
    }

    D2UnitStrc* pPortal = SUNIT_AllocUnitData(2, 566, pCoord.nX, pCoord.nY, pQuestArg->pGame, pRoom, 1, 1, 0);
    if (!pPortal)
    {
        return;
    }

    pQuestDataEx->unk0x44 = 0;
    pQuestDataEx->bPortalToAct5Spawned = 1;
    pPortal->dwFlags |= 0x3000000;
}

static D2BitBufferStrc* GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x005B4670
void __fastcall ACT4Q2_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act4Quest2Strc* pQuestDataEx = pQuestData->pQuestDataEx;
    const short nMessageIndex = pQuestArg->nMessageIndex;
    if (pQuestArg->nNPCNo == 0x16F)
    {
        if (nMessageIndex == 0x2A9)
        {
            pQuestDataEx->bTalkedToTyrael = 1;
            QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q2.cpp", 0xE1);
            SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT4Q2_UnitIterate_UpdateQuestStateFlags);
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
        }
        else if (nMessageIndex == 0x2AC)
        {
            QUESTRECORD_ClearQuestState(GetQuestFlags(pQuestData->pGame, pQuestArg->pPlayer), 0x1A, 7);
        }
        else if (nMessageIndex == 0x4E20)
        {
            if (!pQuestData->pGame->bExpansion)
            {
                return;
            }

            QUESTRECORD_SetQuestState(sub_00543520(pQuestData->pGame, pQuestArg->pPlayer), 0x1A, 9);
            if (!pQuestDataEx->bPortalToAct5Spawned)
            {
                sub_005B45E0_ACT4Q2_SpawnPortalToAct5(pQuestArg, pQuestDataEx);
            }
        }
    }
    else if (pQuestArg->nNPCNo == 0xF6)
    {
        if (nMessageIndex == 0x2AD)
        {
            QUESTRECORD_ClearQuestState(GetQuestFlags(pQuestData->pGame, pQuestArg->pPlayer), 0x1A, 6);
        }
        else if (nMessageIndex == 0x4E21)
        {
            QUESTRECORD_SetQuestState(GetQuestFlags(pQuestData->pGame, pQuestArg->pPlayer), 0x1A, 8);
        }
    }
}

// 0x005B4F90
void __fastcall ACT4Q2_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestArg->pTarget || pQuestArg->pTarget->dwClassId != 0x16F)
    {
        return;
    }

    D2Act4Quest2Strc* pQuestDataEx = pQuestData->pQuestDataEx;
    if (pQuestDataEx->bTalkedToTyrael == 1)
    {
        pQuestData->bActive = 0;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT4Q2_UnitIterate_StatusCyclerEx, 1);
        pQuestDataEx->bTalkedToTyrael = 0;
    }

    if (pQuestData->pGame->bExpansion && pQuestDataEx->unk0x44 && !pQuestDataEx->bPortalToAct5Spawned)
    {
        sub_005B45E0_ACT4Q2_SpawnPortalToAct5(pQuestArg, pQuestDataEx);
    }
}

// 0x005B5210
extern "C" unsigned int __fastcall sub_005B5210_ReadQuestFlag(Game* game)
{
    QuestView* quest = QUESTS_GetQuestData(game, 0x17);
    if (quest)
        return quest->extra->flag;
    return 0;
}
