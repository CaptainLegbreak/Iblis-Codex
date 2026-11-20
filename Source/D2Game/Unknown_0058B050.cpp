#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2GameStrc.h"




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

#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define QUEST_A5Q4_NIHLATHAK 34
#define LEVEL_NIHLATHAKSTEMPLE 121
#define OBJECT_PERMANENT_TOWN_PORTAL 60
#define MONSTER_DREHYA 512
#define EVENTTYPE_MONUMOD 7

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                               // 0x00543640
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
int __fastcall D2GAME_CreatePortalObject_6FD13DF0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int nDestLevel, D2UnitStrc** ppSourceUnit, int nObjectId, int bPerm); // 0x0056D130
int __fastcall ACT5Q4_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x0058AEA0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900

__forceinline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
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
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

static bool __stdcall sub_0058AF90_OpenDrehyaPortal(D2UnitStrc* pTarget, D2QuestDataStrc* pQuestData) // 0x0058AF90
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

// 0x0058B050
void __fastcall ACT5Q4_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if ((unsigned short)(pQuestArg->pTarget ? pQuestArg->pTarget->dwClassId : -1) != MONSTER_DREHYA)
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
        sub_0058AF90_OpenDrehyaPortal(pQuestArg->pTarget, pQuestData);
    }
}

void __fastcall sub_0058B940_RetryDrehyaPortal(D2GameStrc* pGame, D2UnitStrc* pUnit) // 0x0058B940
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q4_NIHLATHAK);
    if (!pQuestData || !pQuestData->pQuestDataEx->bNeedsToOpenPortal)
    {
        return;
    }

    if (!sub_0058AF90_OpenDrehyaPortal(pUnit, pQuestData))
    {
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_MONUMOD, pGame->dwGameFrame + 12, 0, 0);
    }
}
