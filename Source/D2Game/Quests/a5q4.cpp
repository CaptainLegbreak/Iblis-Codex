#include "D2Game.h"

#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define QUEST_A5Q4_NIHLATHAK 34
#define LEVEL_NIHLATHAKSTEMPLE 121
#define OBJECT_PERMANENT_TOWN_PORTAL 60
#define MONSTER_DREHYA 512
#define EVENTTYPE_MONUMOD 7
struct D2StaticPathStrc;
struct D2Act5Quest4Strc;
struct D2PlayerDataStrc;

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    unsigned char unk_6E[0x3A];
    int dwGameFrame;
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nX;
    int nY;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x24];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2Act5Quest4Strc
{
    char unk0x00[0x86];
    unsigned char bDrehyaActivated;
    unsigned char bNeedsToOpenPortal;
    unsigned char bPortalCreated;
};

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    char unk0x08[0x0C];
    unsigned char nFlagsByte;
    char unk0x15[0x03];
    D2Act5Quest4Strc* pQuestDataEx;
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
};

typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
int __fastcall D2GAME_CreatePortalObject_6FD13DF0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int nDestLevel, D2UnitStrc** ppSourceUnit, int nObjectId, int bPerm); // 0x0056D130
int __fastcall ACT5Q4_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058AEA0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900

struct D2PlayerDataStrc
{
    char szName[0x10];
    D2BitBufferStrc* pQuestData[3];
};

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* unit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* flags, int quest, int state); // 0x0065C310
void __fastcall SUNIT_AttachSound(D2UnitStrc* unit, int updateType, D2UnitStrc* updateUnit); // 0x00553380

struct Quest {char pad00[0xC];unsigned char state;char pad0D[0xD3];int id;};

int __stdcall sub_0065C310(void*,int,int); // 0x0065C310

__forceinline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

__forceinline int CLIENTS_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x0058AF90
static bool __stdcall sub_0058AF90_OpenDrehyaPortal(D2QuestDataStrc* pQuestData, D2UnitStrc* pTarget)
{
    D2Act5Quest4Strc* pQuestDataEx = pQuestData->pQuestDataEx;
    if (pQuestDataEx->bPortalCreated)
    {
        return false;
    }

    if (D2GAME_CreatePortalObject_6FD13DF0(pQuestData->pGame, 0, UNITS_GetRoom(pTarget), CLIENTS_GetUnitX(pTarget) + 10, CLIENTS_GetUnitY(pTarget) + 5, LEVEL_NIHLATHAKSTEMPLE, 0, OBJECT_PERMANENT_TOWN_PORTAL, 1))
    {
        pQuestDataEx->bPortalCreated = 1;
        pQuestDataEx->bNeedsToOpenPortal = 0;
        return true;
    }

    return false;
}

void __fastcall ACT5Q4_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestArg->pTarget || (unsigned short)pQuestArg->pTarget->dwClassId != MONSTER_DREHYA)
    {
        return;
    }

    D2Act5Quest4Strc* pQuestDataEx = pQuestData->pQuestDataEx;
    if (pQuestDataEx->bDrehyaActivated == 1)
    {
        pQuestData->nFlagsByte = 0;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT5Q4_UnitIterate_StatusCyclerEx, 1);
        pQuestDataEx->bDrehyaActivated = 0;
    }

    if (pQuestDataEx->bNeedsToOpenPortal && !pQuestDataEx->bPortalCreated)
    {
        sub_0058AF90_OpenDrehyaPortal(pQuestData, pQuestArg->pTarget);
    }
}

// 0x0058B940
void __fastcall sub_0058B940_RetryDrehyaPortal(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q4_NIHLATHAK);
    if (!pQuestData || !pQuestData->pQuestDataEx->bNeedsToOpenPortal)
    {
        return;
    }

    if (!sub_0058AF90_OpenDrehyaPortal(pQuestData, pUnit))
    {
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_MONUMOD, pGame->dwGameFrame + 12, 0, 0);
    }
}

// 0x0058B5B0
void __fastcall sub_0058B5B0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 0x26, 0) == 1
        || QUESTRECORD_GetQuestState(pQuestFlags, 0x26, 0xE) == 1
        || QUESTRECORD_GetQuestState(pQuestFlags, 0x26, 1) == 1
        || QUESTRECORD_GetQuestState(pQuestFlags, 0x26, 0xD) == 1)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId || DRLG_GetActNoFromLevelId(nLevelId) != 4)
    {
        return;
    }

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 0x25, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 0x25, 1))
    {
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, 0x26, 0) || QUESTRECORD_GetQuestState(pQuestFlags, 0x26, 1))
    {
        return;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, 0x26, 1);
    QUESTRECORD_SetQuestState(pQuestFlags, 0x26, 0xD);
}

// 0x0058B730
int __fastcall sub_0058B730_AttachCompletionSound(D2GameStrc* game, D2UnitStrc* player, void* unused)
{
    D2BitBufferStrc* flags = UNITS_GetPlayerData(player)->pQuestData[game->nDifficulty];
    if (QUESTRECORD_GetQuestState(flags, 38, 13))
        SUNIT_AttachSound(player, 82, player);
    return 0;
}

// 0x0058B870
bool __fastcall sub_0058B870(Quest* quest,int npc,void* player,void* flags,void* extra) {
 if(npc==512) {
  if(quest->state==1) {
   if(!(sub_0065C310(flags,37,0) || sub_0065C310(flags,37,1))) goto inactive;
   if(sub_0065C310(flags,quest->id,0)) goto inactive;
   if(sub_0065C310(flags,quest->id,1)) goto inactive;
  } else {
   if(!sub_0065C310(flags,quest->id,13)) goto inactive;
   if(sub_0065C310(flags,38,4)) goto inactive;
  }
  return true;
 }
inactive:
 return false;
}
