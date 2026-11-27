#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2ObjectIds.h"
#include "D2ItemTypes.h"
#include "D2StateIds.h"
#include "D2MonsterIds.h"
#include "D2SkillIds.h"
#include "D2LevelIds.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2GameRecords.h"
#include "D2Constants.h"
#include "D2DataTbls.h"
#include "D2GameTypes.h"
#include "D2Txt.h"
#include "D2TxtTables.h"
#include "D2ItemsWorld.h"
#include "D2UnitData.h"
#include "D2LevelTxt.h"
#include "D2AnimData.h"
#include "D2Path.h"
#include "D2ItemModes.h"
#include "D2GameServer.h"
#include "D2GameClient.h"
#include "D2HotkeySkill.h"
#include "D2GameAux.h"
#include "D2LanguageNames.h"
#include "FogApi.h"
#include "StormApi.h"
#include "D2CommonApi.h"
#include "FogApi.h"
// build: symbol _gaszLanguageNames 0x00741888


void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

// 0x005C0A90
void __fastcall SUNITEVENT_FreeEventList(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return;
    }

    D2UnitEventStrc* pUnitEvent = pUnit->pSrvUnitEventsList;
    while (pUnitEvent)
    {
        D2UnitEventStrc* pNext = pUnitEvent->pNext;
        FOG_FreeServerMemory(pGame->pMemoryPool, pUnitEvent, ".\\UNIT\\SUnitEvent.cpp", 61, 0);
        pUnitEvent = pNext;
    }

    pUnit->pSrvUnitEventsList = 0;
}
#define IFLAG_TARGETING 4

#define UPDATEUI_CLOSEALL 17

#define UPDATEUI_OPENCUBE 21

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

struct D2ItemsTxt;

struct D2MonStatsTxt;

struct D2BooksTxt;


struct D2CurseStrc;

struct D2SkillsTxt;


union D2SeedStrc;

struct D2UnitStrc;

struct D2GameStrc;

struct D2DataTablesStrc;

struct D2DamageStrc;

struct D2AnimSeqTxt;

struct D2ItemStatCostTxt;


#include "D2GameFuncs.h"


int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0


extern D2pSpellTblStrc gaPSpellTable[]; // 0x00741790

void __fastcall D2GAME_PACKETS_SendPacketSize06(D2ClientStrc* pClient, unsigned char nHeader, int dwUnitType, int dwUnitId); // 0x0053B3D0


unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo); // 0x00627F80


typedef void(__fastcall* StatListRemoveCallback)(D2UnitStrc*, int, D2StatListStrc*);

enum D2C_Z09ItemConstants
{
    EVENTTYPE_REMOVESTATE = 0x0C,
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304


int __stdcall D2COMMON_10473(D2StatListStrc* pStatList); // 0x00626090


void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0


void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0


void __stdcall D2COMMON_10476(D2StatListStrc* pStatList, int nExpireFrame); // 0x006260B0


void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150


void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0


extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0

int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0


void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit); // 0x00554190


D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540


int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20



void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int nUnused); // 0x00621E40

int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180

int __stdcall MONSTERS_IsBoss(D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pMonster); // 0x0063E9F0

int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pHireling); // 0x0063EE90


enum D2C_Y09SkillConstants
{
    SKILLSFLAGINDEX_AURA = 5,
    SKILLSFLAGINDEX_IMMEDIATE = 15,
    EVENTTYPE_PERIODICSTATS = 9,
};

extern unsigned int gdwBitMasks[]; // 0x006CE268


int __fastcall SKILL_ComputePeriodicRate(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x0056CD50

int __fastcall SKILLS_ExecuteSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bApplyCosts, int bSkipSkillCheck, int bItemEffect); // 0x0056F7F0


extern "C" const char gszEmptyAssertText; // 0x006CC837


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820


int __fastcall CUNIT_GetMonsterBaseId(D2UnitStrc* pUnit); // 0x00463860


extern "C" int __fastcall sub_005A0180(D2UnitStrc* pUnit, unsigned short wMask); // 0x005A0180


int __fastcall MONSTER_GetHpBonus(int nPlayerCount); // 0x005738F0

int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit); // 0x00625D60

typedef void (__fastcall* RemoveCallback)(D2UnitStrc*,int,D2StatListStrc*);

int __fastcall GAME_GetUnitTypeOrInvalid(D2UnitStrc*); // 0x0044BE50

int __fastcall GAME_GetUnitGUID(D2UnitStrc*); // 0x00451F50


unsigned char __fastcall MONSTERMODE_GetHpPercent128(D2UnitStrc*); // 0x005805D0


unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390


#define UNIT_PLAYER 0

#define UNIT_MONSTER 1

#define UNIT_ITEM 4

#define UNIT_INVALID 6

#define MONSTATS2FLAGINDEX_SMALL 10

#define MONSTATS2FLAGINDEX_LARGE 11

struct D2MonStats2Txt;

D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0

static void SKILLITEM_ClearTargetingItems(D2UnitStrc* pUnit);


enum D2C_J10SkillItemConstants
{
    MONTYPEFLAG_UNIQUE_CHAMPION = 12,
    DAMAGERESULTFLAG_GETHIT = 4,
    DAMAGEHITFLAG_0x20 = 0x20,
    SKILLSFLAGINDEX_ITEMTGTDO = 29,
};

int __fastcall sub_00472210_SeedRollMasked(D2SeedStrc* pSeed, int nMax);                                     // 0x00472210

int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                                   // 0x0045C3E0

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId);                                      // 0x0045C4B0


int __stdcall DUNGEON_GetTownLevelIdFromActNo(unsigned char act); // 0x0061AB70


void __fastcall sub_00553380_SendEvent(D2UnitStrc* unit,int event,D2UnitStrc* other); // 0x00553380


D2ClientStrc* __fastcall sub_005531C0_GetClient(D2UnitStrc* unit,const char* file,int line,int type,int id); // 0x005531C0

void __fastcall D2GAME_PACKETS_SendPacketSize06(D2ClientStrc* client,unsigned char code); // 0x0053B3D0


static inline int GetUnitType(D2UnitStrc* unit) { return unit?unit->dwUnitType:UNIT_INVALID; }

struct D2AiControlStrc;

struct D2ActiveRoomStrc;

struct D2DynamicPathStrc;

struct D2SkillStrc;

struct D2StatListStrc;


enum D2C_G4Constants
{
    AISPECIALSTATE_NONE = 0,
    AISPECIALSTATE_DIMVISION = 10,
    AISPECIALSTATE_TERROR = 11,
    AISPECIALSTATE_TAUNT = 12,
    UNITFLAG_SKSRVDOFUNC = 0x40,
    UNITFLAGEX_TELEPORTED = 0x10000,
    UNITEVENTFLAG_IN_CALLBACK = 1,
    UNITEVENTFLAG_SHOULD_BE_FREED = 2,
    ITEMDROPFLAG_STAFFMODUSEILVL = 0x20,
    COLLIDE_MASK_PLAYER_FLYING = 0x804,
};

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430

int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0);            // 0x0040B480

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY);            // 0x00463740

int __fastcall SUNIT_TeleportUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int bSkipCollisionSearch, int bSyncOtherPlayersOnly); // 0x00554EA0


int __fastcall SKILLS_StartSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bSkipMana);   // 0x0056F640

void __fastcall SUNITDMG_FreeAttackerDefenderCombatList(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender); // 0x0057C9F0

void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nUnused); // 0x0057D4F0

void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int nFlags); // 0x0057DBF0


short __stdcall ITEMS_RollMagicAffixesNew(D2UnitStrc* pItem, int bRequireSpawnableAffix, int bForceAffixRoll, int bAssignProperties, int bPrefixes, int nPreferredAffixIndex, int nAutoMagicGroup); // 0x005C1560

void __fastcall SKILLS_SetSummonResistance(D2UnitStrc* pUnit, D2UnitStrc* pPet);                   // 0x005C40D0

void __fastcall D2GAME_SetSummonPassiveStats(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel, int nItemLevel); // 0x005C4470


D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId);                                           // 0x0061DB70



void __stdcall SKILLS_SetSkillMode(D2SkillStrc* pSkill, int nMode);                                         // 0x00644340


void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue);                                            // 0x00644660


struct D2ModeChangeStrc;

D2AiControlStrc* __fastcall AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit); // 0x00541860

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nType, int nGUID); // 0x00552F60


void __fastcall D2GAME_BOSSES_AssignUMod(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique); // 0x005A4850


D2UnitStrc* __fastcall D2GAME_SpawnMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20


void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x00620210


void __stdcall PATH_SetStepNum(D2DynamicPathStrc* pPath, unsigned char nStep); // 0x00649070

int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit); // 0x00649180

void __stdcall COLLISION_ResetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nPattern, int nMask); // 0x0064EC10

enum D2C_SkillItemConstants
{
    UNITEVENT_13 = 13,
};

int __fastcall SKILLITEM_TimerCallback_ReanimateMonster(D2GameStrc* pGame, int nUnitEvent, D2UnitStrc* pUnit, D2UnitStrc* pEventSourceUnit, D2DamageStrc* pDamage, int nGUID1, int nGUID2); // 0x005C07A0

D2UnitEventStrc* __fastcall SUNITEVENT_Register(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitEvent, int nGUID1, int nGUID2, D2UnitEventCallbackFunction pCallback, unsigned int nQueueNo, int nEventKey); // 0x005C0AD0


D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc*); // 0x00627D90


int __fastcall sub_00472280_RollInRange(D2SeedStrc*, int, int); // 0x00472280

void __stdcall ITEMMODS_AssignProperty(int, D2UnitStrc*, D2UnitStrc*, const void*, int, int); // 0x0065FEC0

static inline int ClampLevel(int v) { if (v <= 1) return 1; if (v >= 99) return 99; return v; }

struct D2AiCmdStrc;

struct D2StaticPathStrc;


D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0


static void __fastcall SUNITEVENT_FreeEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitEventStrc* pUnitEvent)
{
    D2UnitEventStrc* pNext = pUnitEvent->pNext;
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

    FOG_FreePool(pGame->pMemoryPool, pUnitEvent, ".\\UNIT\\SUnitEvent.cpp", 149, 0);
}

// 0x005C0AD0
D2UnitEventStrc* __fastcall SUNITEVENT_Register(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitEvent, int nGUID1, int nGUID2, D2UnitEventCallbackFunction pCallback, unsigned int nQueueNo, int nEventKey)
{
    if (!pUnit)
    {
        return 0;
    }

    D2UnitEventStrc* pUnitEvent = (D2UnitEventStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2UnitEventStrc), ".\\UNIT\\SUnitEvent.cpp", 87, 0);
    memset(pUnitEvent, 0x00, sizeof(D2UnitEventStrc));

    pUnitEvent->nUnitEvent = nUnitEvent;
    pUnitEvent->nGUID1 = nGUID1;
    pUnitEvent->nGUID2 = nGUID2;
    pUnitEvent->pCallback = pCallback;
    pUnitEvent->pNext = pUnit->pSrvUnitEventsList;
    pUnitEvent->nEventGroup = nQueueNo;
    pUnitEvent->nEventKey = nEventKey;

    if (pUnit->pSrvUnitEventsList)
    {
        pUnit->pSrvUnitEventsList->pPrevious = pUnitEvent;
    }

    pUnit->pSrvUnitEventsList = pUnitEvent;
    return pUnitEvent;
}
// 0x005C0B50
void __fastcall SUNITEVENT_Unregister(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTimerQueueNo, int nEventKey)
{
    if (!pUnit)
    {
        return;
    }

    D2UnitEventStrc* pUnitEvent = pUnit->pSrvUnitEventsList;
    while (pUnitEvent)
    {
        D2UnitEventStrc* pNext = pUnitEvent->pNext;
        if (pUnitEvent->nEventGroup == nTimerQueueNo && pUnitEvent->nEventKey == nEventKey)
        {
            if (pUnitEvent->nFlags & UNITEVENTFLAG_IN_CALLBACK)
            {
                pUnitEvent->nFlags |= UNITEVENTFLAG_SHOULD_BE_FREED;
            }
            else
            {
                SUNITEVENT_FreeEvent(pGame, pUnit, pUnitEvent);
            }
        }

        pUnitEvent = pNext;
    }
}

// 0x005C0BE0
D2UnitEventStrc* __fastcall SUNITEVENT_GetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTimerQueueNo, int nEventKey, int nGUID1)
{
    if (!pUnit)
    {
        return 0;
    }

    D2UnitEventStrc* pUnitEvent = pUnit->pSrvUnitEventsList;
    while (pUnitEvent)
    {
        D2UnitEventStrc* pNext = pUnitEvent->pNext;
        if (pUnitEvent->nEventGroup == nTimerQueueNo && pUnitEvent->nEventKey == nEventKey && pUnitEvent->nGUID1 == nGUID1)
        {
            return pUnitEvent;
        }

        pUnitEvent = pNext;
    }

    return 0;
}
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

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


struct D2StaticPathStrc;

struct D2HotkeySkillStrc;

struct D2ObjectControlStrc;

struct D2MonsterDataStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09


D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60


void __fastcall D2GAME_UpdateAttribute(D2UnitStrc* pUnit, unsigned short nStat, unsigned int nNewValue, D2UnitStrc* pPlayer); // 0x00548520

void __stdcall D2Common_10513(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, void(__fastcall* pfCallback)(D2UnitStrc*, unsigned short, unsigned int, D2UnitStrc*)); // 0x006258D0

void __fastcall sub_0055F4F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3); // 0x0055F4F0


void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID); // 0x0061A270


extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430


extern D2CriticalSectionStrc gClientListLock; // 0x008846A8

extern D2CriticalSectionStrc gSrvClientListByNameLock; // 0x008846C0


typedef int (__stdcall* FARPROC)();

typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

typedef void (__fastcall* EventCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit);

typedef void (__fastcall* MonEventFunc)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

extern EventCallbackFunction gpfnItemEventFunctions[15]; // 0x006E117C

extern EventCallbackFunction gpfnObjectEventFunctions[15]; // 0x006E19B0

extern MonEventFunc gpMonsterEventFunctions[15]; // 0x006E2490


void __fastcall PARTY_IteratePartyMembersInSameLevel(D2GameStrc* pGame, D2UnitStrc* pUnit, PartyCallbackFunction pCallback, void* pArgs); // 0x005405A0


short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630



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


