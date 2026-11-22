#include "D2StateIds.h"
#include "D2MonsterIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2GameServer.h"
#include "D2ItemsWorld.h"
#include "D2GameClient.h"
#include "D2HotkeySkill.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define CLIENTFLAGEX_PLAYER_UNIT_ALIVE 1
#define UNIT_MONSTER 1
#define STAT_LEVEL 12
#define EVENTTYPE_AITHINK 2
#define EVENTTYPE_STATREGEN 3
#define EVENTTYPE_TRAP 4
#define EVENTTYPE_RESET 5
#define EVENTTYPE_REMOVESTATE 12
#define EVENTTYPE_COUNT 15
#define DAMAGERESULTFLAG_WILLDIE 0x02
#define UNITEVENTFLAG_IN_CALLBACK 0x01
#define UNITEVENTFLAG_SHOULD_BE_FREED 0x02
#define MONSTER_COMPONENT_COUNT 16
#define OBJRGN_MAX_WELLS 4
#define OBJRGN_MAX_SHRINES 10
#define AIPARAM_MAX_STEPS 77
struct D2AiParamStrc;
struct D2StaticPathStrc;
struct D2HotkeySkillStrc;
struct D2ObjectControlStrc;
struct D2MonsterDataStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

void __stdcall DUNGEON_ChangeClientRoom(D2ActiveRoomStrc* pOldRoom, D2ActiveRoomStrc* pNewRoom); // 0x0061A110
void __stdcall D2Common_10077(D2ActiveRoomStrc* pOldRoom, D2ActiveRoomStrc* pNewRoom); // 0x0061A9F0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pnNumRooms); // 0x00619790

void __fastcall LEVEL_AddClient(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient); // 0x0053A8E0
void __fastcall LEVEL_RemoveClient(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient); // 0x0053A9B0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
void __fastcall sub_6FC81650(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int a4); // 0x00580860
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
void __stdcall UNITS_SetPlayerPortalFlags(D2UnitStrc* pUnit, int nPortalFlags); // 0x006221E0
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath); // 0x00537860
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __fastcall LEVEL_RemoveUnitsExceptClientPlayer(D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient); // 0x0053A770
void __fastcall LEVEL_UpdateUnitsInAdjacentRooms(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient); // 0x0053A620
void __fastcall D2GAME_UpdateAttribute_6FC822D0(D2UnitStrc* pUnit, unsigned short nStat, unsigned int nNewValue, D2UnitStrc* pPlayer); // 0x00548520
void __stdcall D2Common_10513(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, void(__fastcall* pfCallback)(D2UnitStrc*, unsigned short, unsigned int, D2UnitStrc*)); // 0x006258D0
void __fastcall sub_0055F4F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3); // 0x0055F4F0
void __fastcall QUESTS_ChangeLevel(D2GameStrc* pGame, int nSourceLevelId, int nDestinationLevelId, D2UnitStrc* pPlayer); // 0x00543B90
void __fastcall SUNITPROXY_UpdateNpcsOnActChange(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCurrentLevelId, int nDestLevelId); // 0x00537340
void __fastcall ARENA_SynchronizeWithClients(D2GameStrc* pGame, D2ClientStrc* pClient); // 0x0053FC20
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID); // 0x0061A270
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600
int __fastcall ClientAddPlayerToGame(D2ClientStrc* ptClient, D2GameStrc* ptGame, int bLoadFromSave, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00539760
void __fastcall sub_005394A0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x005394A0

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
unsigned short __stdcall FOG_ComputeStringCRC16(const char* szString); // 0x004112C0
unsigned int __fastcall ARENA_ShouldTreatClassIdAsTemplateId(D2GameStrc* pGame); // 0x0053FE70
int __fastcall ARENA_GetTemplateType(D2GameStrc* pGame); // 0x0053FEA0
int __fastcall DATATBLS_GetClassFromCharTemplateTxtRecord(int nTemplate, int nLevel); // 0x006657C0
extern D2CriticalSectionStrc gClientListLock_008846A8; // 0x008846A8
extern D2CriticalSectionStrc gSrvClientListByNameLock_008846C0; // 0x008846C0

typedef int (__fastcall* D2UnitEventCallbackFunction)(D2GameStrc* pGame, int nUnitEvent, D2UnitStrc* pUnit, D2UnitStrc* pEventSourceUnit, D2DamageStrc* pDamage, int nGUID1, int nGUID2);

struct D2UnitEventStrc
{
    unsigned char nUnitEvent;
    unsigned char unk0x01;
    unsigned short nFlags;
    unsigned int nEventGroup;
    int unk0x08;
    int nGUID1;
    int nGUID2;
    D2UnitEventCallbackFunction pCallback;
    D2UnitEventStrc* pPrevious;
    D2UnitEventStrc* pNext;
};

struct D2AiParamStrc
{
    char unk0x00[0x18];
    int unk0x18;
    int nVelocity;
    unsigned char unk0x20;
};

typedef int (__stdcall* FARPROC)();

typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

typedef void (__fastcall* EventCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit);

typedef void (__fastcall* MonEventFunc)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C
extern EventCallbackFunction scpfnItemEventFunctions_6FD27DDC[15]; // 0x006E117C
extern EventCallbackFunction gpEventFunctions_6FD28CD8[15]; // 0x006E19B0
extern MonEventFunc gpMonsterEventFunctions[15]; // 0x006E2490
void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
void __fastcall sub_005404C0_AddLivingMemberLevel(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs); // 0x005404C0
void __fastcall PARTY_CountLivingUnits(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pLivingUnits); // 0x005404F0
void __fastcall PARTY_IteratePartyMembersInSameLevel(D2GameStrc* pGame, D2UnitStrc* pUnit, PartyCallbackFunction pCallback, void* pArgs); // 0x005405A0
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
D2UnitStrc* __fastcall SUNIT_GetLastAttacker(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553010
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630
void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int bSendMsg); // 0x0057CCB0
void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x0057CEE0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

inline int M08_UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

inline int M08_UNITS_GetYPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

static inline D2UnitStrc* sub_M08_GetClientPlayerUnit(D2ClientStrc* pClient)
{
    if (pClient->dwFlags & CLIENTFLAGEX_PLAYER_UNIT_ALIVE)
    {
        return pClient->pPlayer;
    }
    if (!pClient->pPlayer)
    {
        return 0;
    }
    D2UnitStrc* pUnit = SUNIT_GetServerUnit(pClient->pGame, pClient->dwUnitType, pClient->dwUnitGUID);
    if (!pUnit)
    {
        pClient->pPlayer = 0;
    }
    return pUnit;
}

// 0x005C0C30
int __fastcall SUNITEVENT_Trigger(D2GameStrc* pGame, int nUnitEvent, D2UnitStrc* pUnit, D2UnitStrc* pEventSourceUnit, D2DamageStrc* pDamage)
{
    if (!pUnit)
    {
        return 0;
    }

    int nResult = 0;
    D2UnitEventStrc* pUnitEvent = pUnit->pSrvUnitEventsList;
    while (pUnitEvent)
    {
        D2UnitEventStrc* pNext = pUnitEvent->pNext;
        if (pUnitEvent->nUnitEvent == nUnitEvent)
        {
            pUnitEvent->nFlags |= UNITEVENTFLAG_IN_CALLBACK;
            nResult = pUnitEvent->pCallback(pGame, nUnitEvent, pUnit, pEventSourceUnit, pDamage, pUnitEvent->nGUID1, pUnitEvent->nGUID2);
            pUnitEvent->nFlags &= ~UNITEVENTFLAG_IN_CALLBACK;

            pNext = pUnitEvent->pNext;
            if ((pUnitEvent->nFlags & UNITEVENTFLAG_SHOULD_BE_FREED) || !pUnitEvent->nEventGroup)
            {
                if (pUnitEvent->pPrevious)
                {
                    pUnitEvent->pPrevious->pNext = pNext;
                }
                else
                {
                    pUnit->pSrvUnitEventsList = pNext;
                }

                if (pUnitEvent->pNext)
                {
                    pUnitEvent->pNext->pPrevious = pUnitEvent->pPrevious;
                }

                FOG_FreeServerMemory(pGame->pMemoryPool, pUnitEvent, ".\\UNIT\\SUnitEvent.cpp", 235, 0);
            }
        }

        pUnitEvent = pNext;
    }

    return nResult;
}
