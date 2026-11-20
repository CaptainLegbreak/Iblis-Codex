#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2GameServer.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define CLIENTFLAGEX_PLAYER_UNIT_ALIVE 1
#define UNIT_MONSTER 1
#define STAT_LEVEL 12
#define STATE_FREEZE 1
#define STATE_UNINTERRUPTABLE 54
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
struct D2ClientKeySkillStrc;
struct D2ObjectControlStrc;
struct D2MonsterDataStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2ClientKeySkillStrc
{
    short nSkill;
    unsigned char nHand;
    unsigned char unk0x03;
    int nItemGUID;
};

struct D2ClientStrc
{
    int dwClientId;
    int dwClientState;
    unsigned char bAct;
    unsigned char unk0x009[3];
    unsigned char nCharTemplate;
    char szName[16];
    char szAccount[16];
    char unk0x02D[0x33];
    int nCharSaveTransactionToken;
    int unk0x064;
    void* pClientInfo;
    unsigned char unk_6C[0x100];
    int dwUnitType;
    int dwUnitGUID;
    D2UnitStrc* pPlayer;
    char unk0x178[0x30];
    D2GameStrc* pGame;
    char unk0x1AC[4];
    int unk0x1B0;
    D2ActiveRoomStrc* hRoom;
    void* pPacketDataHead;
    void* pPacketDataTail;
    void* pPacketDataPool;
    unsigned char unk_1C4[0x210];
    unsigned int dwFlags;
    unsigned int dwLastPacketTick;
    D2ClientKeySkillStrc HotkeySkills[16];
    char unk0x45C[0x4C];
    D2ClientStrc* pNext;
    D2ClientStrc* pServerNext;
    D2ClientStrc* pServerNextByName;
    char unk0x4B4[0x58];
    unsigned int dwLocale;
    char f_510[0x08];
};

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

struct D2ObjectControlStrc
{
    char unk0x00[0x48];
    D2ObjectRegionStrc* pObjectRegion[1024];
};

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

static __forceinline D2UnitStrc* sub_M08_GetClientPlayerUnit(D2ClientStrc* pClient)
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

// 0x00537B50
static void __stdcall sub_00537B50_ChangeClientRoom(D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient)
{
    if (!pClient || !pClient->pGame)
    {
        return;
    }
    D2ActiveRoomStrc* pClientRoom = pClient->hRoom;
    if (pClientRoom == pRoom)
    {
        return;
    }
    DUNGEON_ChangeClientRoom(pClientRoom, pRoom);
    D2Common_10077(pClientRoom, pRoom);

    D2ActiveRoomStrc** ppAdjacentRooms = 0;
    int nAdjacentRooms = 0;
    if (pRoom)
    {
        DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppAdjacentRooms, &nAdjacentRooms);
    }

    D2ActiveRoomStrc** ppClientAdjacentRooms = 0;
    int nClientAdjacentRooms = 0;
    if (pClientRoom)
    {
        DUNGEON_GetAdjacentRoomsListFromRoom(pClientRoom, &ppClientAdjacentRooms, &nClientAdjacentRooms);
    }

    for (int i = 0; i < nAdjacentRooms; ++i)
    {
        int j = 0;
        while (j < nClientAdjacentRooms)
        {
            if (ppAdjacentRooms[i] == ppClientAdjacentRooms[j])
            {
                break;
            }
            ++j;
        }
        if (j >= nClientAdjacentRooms)
        {
            LEVEL_AddClient(pClient->pGame, ppAdjacentRooms[i], pClient);
        }
    }

    for (int i = 0; i < nClientAdjacentRooms; ++i)
    {
        int j = 0;
        while (j < nAdjacentRooms)
        {
            if (ppClientAdjacentRooms[i] == ppAdjacentRooms[j])
            {
                break;
            }
            ++j;
        }
        if (j >= nAdjacentRooms)
        {
            LEVEL_RemoveClient(pClient->pGame, ppClientAdjacentRooms[i], pClient);
            if (pClient->hRoom == ppClientAdjacentRooms[i])
            {
                sub_6FC81650(pClient->pGame, sub_M08_GetClientPlayerUnit(pClient), pClient, 0);
            }
        }
    }

    pClient->hRoom = pRoom;
    if (pRoom && pClient->pPlayer)
    {
        const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
        int nPortalFlags = UNITS_GetPlayerPortalFlags(pClient->pPlayer);
        nPortalFlags |= DUNGEON_GetPortalFlagFromLevelId(nLevelId);
        UNITS_SetPlayerPortalFlags(pClient->pPlayer, nPortalFlags);
    }
}

inline int UNITS_HasFlagEx(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlagEx & nFlag) != 0;
    }

    return 0;
}

// 0x005380D0
void __fastcall sub_6FC33670(D2GameStrc* pGame, D2ClientStrc* pClient)
{
    if (!pGame || !pClient)
    {
        return;
    }
    D2ActiveRoomStrc* pClientRoom = pClient->hRoom;
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    if (!pPlayer)
    {
        return;
    }
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    LEVEL_RemoveUnitsExceptClientPlayer(pClientRoom, pClient);
    LEVEL_UpdateUnitsInAdjacentRooms(pGame, pClientRoom, pClient);
    D2Common_10513(pPlayer, pPlayer, D2GAME_UpdateAttribute_6FC822D0);
    if (UNITS_HasFlagEx(pPlayer, 0x200000))
    {
        D2GAME_ITEMS_UpdateInventoryItems_6FC45050(pGame, pPlayer, 1, 1);
        sub_0055F4F0(pGame, pPlayer, 1);
    }
    ++pClient->unk0x1B0;
    if (pClientRoom != pRoom)
    {
        const int nSourceLevelId = DUNGEON_GetLevelIdFromRoom(pClientRoom);
        const int nDestinationLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
        if (nSourceLevelId != nDestinationLevelId)
        {
            QUESTS_ChangeLevel(pGame, nSourceLevelId, nDestinationLevelId, pPlayer);
            SUNITPROXY_UpdateNpcsOnActChange(pGame, pPlayer, nSourceLevelId, nDestinationLevelId);
        }
        sub_00537B50_ChangeClientRoom(pRoom, pClient);
    }
    ARENA_SynchronizeWithClients(pGame, pClient);
    if (UNITS_GetRoom(pPlayer))
    {
        UNITROOM_RefreshUnit(pPlayer);
    }
}

void __fastcall CLIENTS_SetRoomInClient(D2ClientStrc* pClient, D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pClient, 1951);
    if (pRoom != pClient->hRoom)
    {
        sub_00537B50_ChangeClientRoom(pRoom, pClient);
    }
    pClient->hRoom = pRoom;
}

static void sub_M08_RemoveUnitFromRoom(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    const int nUnitGUID = pUnit->dwUnitId;
    const int nUnitType = pUnit->dwUnitType;
    DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pUnit), nUnitType, nUnitGUID);
    SUNIT_RemoveUnit(pGame, pUnit);
}

// 0x0053A2F0
void __fastcall sub_0053A2F0_ResetClientInAct(D2ClientStrc* pClient, int nAct)
{
    D2_ASSERT(pClient, 2386);
    pClient->bAct = nAct;
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    pClient->bAct = nAct;
    const int nX = M08_UNITS_GetXPositionInline(pPlayer);
    const int nY = M08_UNITS_GetYPositionInline(pPlayer);
    D2GameStrc* pGame = pClient->pGame;
    sub_M08_RemoveUnitFromRoom(pGame, pPlayer);
    ClientAddPlayerToGame(pClient, pGame, 0, pRoom, nX, nY);
    sub_005394A0(pClient, pClient->pPlayer, pGame, pRoom, nX, nY);
    pClient->dwFlags &= ~CLIENTFLAGEX_PLAYER_UNIT_ALIVE;
    if (pRoom != pClient->hRoom)
    {
        sub_00537B50_ChangeClientRoom(pRoom, pClient);
    }
    pClient->hRoom = pRoom;
}

int gbClientListInitialized_008846D8; // 0x008846D8

D2ClientStrc* gpClientList_008842A8[256]; // 0x008842A8

D2ClientStrc* gpClientListByName_00883EA8[256]; // 0x00883EA8

// 0x00538B70
int __fastcall sub_6FC33EA0(int nClientId, char* szName)
{
    if (!gbClientListInitialized_008846D8)
    {
        return 1;
    }

    int nResult = 1;
    EnterCriticalSection(&gClientListLock_008846A8);

    for (D2ClientStrc* pClient = gpClientList_008842A8[nClientId & 0xFF]; pClient; pClient = pClient->pServerNext)
    {
        if (!nResult)
        {
            break;
        }

        if (pClient->dwClientId == nClientId)
        {
            if (szName)
            {
                SStrCopy(szName, pClient->szName, sizeof(pClient->szName));
            }

            nResult = 0;
        }
    }

    LeaveCriticalSection(&gClientListLock_008846A8);
    return nResult;
}

// 0x00539A30
D2ClientStrc* __fastcall ClientAddToGame(D2GameStrc* pGame, int nClientId, unsigned char nClassIdOrCharTemplate, const char* szClientName, const char* szAccount, int nCharSaveTransactionToken, unsigned char nLocale, int a8, int a9)
{
    if (!gbClientListInitialized_008846D8 || !pGame)
    {
        return 0;
    }

    if (pGame->nClients >= 8)
    {
        return 0;
    }

    D2ClientStrc* pClient = (D2ClientStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2ClientStrc), ".\\GAME\\Clients.cpp", 0x347, 0);
    memset(pClient, 0, sizeof(D2ClientStrc));

    pClient->dwClientId = nClientId;
    pClient->dwLastPacketTick = GetTickCount() + 180000;
    pClient->pGame = pGame;

    if (ARENA_ShouldTreatClassIdAsTemplateId(pGame))
    {
        pClient->nCharTemplate = nClassIdOrCharTemplate;
        pClient->bAct = DATATBLS_GetClassFromCharTemplateTxtRecord(nClassIdOrCharTemplate, ARENA_GetTemplateType(pGame));
    }
    else
    {
        pClient->bAct = nClassIdOrCharTemplate;
    }

    SStrCopy(pClient->szName, szClientName, 0x7FFFFFFF);
    SStrCopy(pClient->szAccount, szAccount, 0x7FFFFFFF);

    pClient->nCharSaveTransactionToken = nCharSaveTransactionToken;
    pClient->pClientInfo = 0;
    pClient->dwLocale = nLocale;
    pClient->dwClientState = 0;
    pClient->pPacketDataHead = 0;
    pClient->pPacketDataTail = 0;
    pClient->pPacketDataPool = 0;

    for (int i = 0; i < 16; ++i)
    {
        pClient->HotkeySkills[i].nSkill = -1;
        pClient->HotkeySkills[i].nHand = 0;
        pClient->HotkeySkills[i].nItemGUID = -1;
    }

    pClient->pNext = pGame->pClientList;
    pGame->pClientList = pClient;

    const int nClientIndex = nClientId & 0xFF;
    EnterCriticalSection(&gClientListLock_008846A8);
    pClient->pServerNext = gpClientList_008842A8[nClientIndex];
    gpClientList_008842A8[nClientIndex] = pClient;
    LeaveCriticalSection(&gClientListLock_008846A8);

    const int nIndex = FOG_ComputeStringCRC16(szClientName) & 0xFF;

    EnterCriticalSection(&gSrvClientListByNameLock_008846C0);
    pClient->pServerNextByName = gpClientListByName_00883EA8[nIndex];
    gpClientListByName_00883EA8[nIndex] = pClient;
    LeaveCriticalSection(&gSrvClientListByNameLock_008846C0);

    ++pGame->nClients;

    return pClient;
}

// 0x005390A0
void __fastcall CLIENTS_SetSkillHotKey(D2ClientStrc* pClient, int nHotkeyId, short nSkillId, unsigned char nHand, int nItemGUID)
{
    if (pClient)
    {
        pClient->HotkeySkills[nHotkeyId].nSkill = nSkillId;
        pClient->HotkeySkills[nHotkeyId].nHand = nHand;
        pClient->HotkeySkills[nHotkeyId].nItemGUID = nItemGUID;
    }
}

// 0x00540890
int __fastcall sub_00540890_SumLivingPartyLevelsInSameLevel(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    int nLevelSum = 0;
    if (SUNIT_GetPartyId(pUnit) == -1)
    {
        return STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    }

    PARTY_IteratePartyMembersInSameLevel(pGame, pUnit, sub_005404C0_AddLivingMemberLevel, &nLevelSum);
    return nLevelSum;
}

// 0x005408E0
int __fastcall PARTY_GetLivingPartyMemberCountInSameLevel(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    int nLivingPartyMembers = 0;
    PARTY_IteratePartyMembersInSameLevel(pGame, pUnit, PARTY_CountLivingUnits, &nLivingPartyMembers);
    return nLivingPartyMembers;
}

// 0x00541830
void __fastcall sub_00541830_SetMonsterComponent(D2UnitStrc* pUnit, unsigned char nComponent, unsigned char nValue)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && nComponent < MONSTER_COMPONENT_COUNT && pUnit->pMonsterData)
    {
        pUnit->pMonsterData->nComponent[nComponent] = nValue;
    }
}

// 0x00547400
void __fastcall OBJRGN_SetWellCoordinates(D2GameStrc* pGame, int nLevelId, int nX, int nY)
{
    D2ObjectRegionStrc* pObjectRegion = pGame->pObjectControl->pObjectRegion[nLevelId];
    if (pObjectRegion->nWells >= OBJRGN_MAX_WELLS)
    {
        return;
    }

    pObjectRegion->wellCoordinates[pObjectRegion->nWells].nX = nX;
    pObjectRegion->wellCoordinates[pObjectRegion->nWells].nY = nY;
    ++pObjectRegion->nWells;
}

// 0x00547490
void __fastcall OBJRGN_SetShrineCoordinates(D2GameStrc* pGame, int nLevelId, int nX, int nY)
{
    D2ObjectRegionStrc* pObjectRegion = pGame->pObjectControl->pObjectRegion[nLevelId];
    if (pObjectRegion->nShrines >= OBJRGN_MAX_SHRINES)
    {
        return;
    }

    pObjectRegion->shrineCoordinates[pObjectRegion->nShrines].nX = nX;
    pObjectRegion->shrineCoordinates[pObjectRegion->nShrines].nY = nY;
    ++pObjectRegion->nShrines;
}

// 0x005544B0
void __fastcall sub_6FCBDE90(D2UnitStrc* hUnit, int bSetUninterruptable)
{
    STATES_ToggleState(hUnit, STATE_UNINTERRUPTABLE, bSetUninterruptable);

    D2_ASSERT(hUnit, 2601);
    D2GameStrc* pGame = hUnit->pGame;
    if (!pGame)
    {
        return;
    }

    if (!bSetUninterruptable && STATES_CheckState(hUnit, STATE_DEATH_DELAY))
    {
        STATES_ToggleState(hUnit, STATE_DEATH_DELAY, 0);

        D2UnitStrc* pAttacker = SUNIT_GetLastAttacker(pGame, hUnit);
        if (pAttacker)
        {
            D2DamageStrc damage;
            memset(&damage, 0, sizeof(damage));
            damage.wResultFlags |= DAMAGERESULTFLAG_WILLDIE;
            SUNITDMG_ExecuteMissileDamage(pGame, pAttacker, hUnit, &damage);
        }
        else
        {
            SUNITDMG_KillMonster(pGame, hUnit, 0, 1);
        }
    }

    if (hUnit->dwUnitType == UNIT_MONSTER)
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, hUnit, EVENTTYPE_AITHINK, 0);
    }
}

// 0x00562DA0
void __fastcall D2GAME_Items_EventsHandler_6FC4A460(D2GameStrc* pGame, D2UnitStrc* pUnit, int eEventType)
{
    D2_ASSERT(!IsBadCodePtr((FARPROC)scpfnItemEventFunctions_6FD27DDC[eEventType]), 5610);
    scpfnItemEventFunctions_6FD27DDC[eEventType](pGame, pUnit);
}

// 0x00586AD0
void __fastcall D2GAME_OBJMODE_InvokeEventFunction_6FC75250(D2GameStrc* pGame, D2UnitStrc* pObject, int eEventType)
{
    D2_ASSERT(!IsBadCodePtr((FARPROC)gpEventFunctions_6FD28CD8[eEventType]), 576);
    gpEventFunctions_6FD28CD8[eEventType](pGame, pObject);
}

// 0x005A6260
void __fastcall sub_005A6260_SetAiParamFields(D2AiParamStrc* pAiParam, int nParam18, int nParam1C, unsigned char nParam20)
{
    if (nParam18)
    {
        pAiParam->unk0x18 = nParam18;
    }

    if (nParam1C)
    {
        pAiParam->nVelocity = nParam1C;
    }

    if (nParam20)
    {
        if (nParam20 >= AIPARAM_MAX_STEPS + 1)
        {
            nParam20 = AIPARAM_MAX_STEPS;
        }

        pAiParam->unk0x20 = nParam20;
    }
}

// 0x005A7F80
void __fastcall MONSTERMODE_EventHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEvent, int nSkillId, int nSkillLevel)
{
    if (nEvent < 0 || nEvent >= EVENTTYPE_COUNT)
    {
        return;
    }

    switch (nEvent)
    {
    case EVENTTYPE_STATREGEN:
    case EVENTTYPE_TRAP:
    case EVENTTYPE_RESET:
    case EVENTTYPE_PERIODICSKILLS:
    case EVENTTYPE_REMOVESTATE:
        break;
    default:
        if (STATES_CheckState(pUnit, STATE_FREEZE) && !SUNIT_IsDead(pUnit))
        {
            return;
        }
        break;
    }

    const MonEventFunc pfMonEvent = gpMonsterEventFunctions[nEvent];
    if (pfMonEvent)
    {
        pfMonEvent(pGame, pUnit, nSkillId, nSkillLevel);
    }
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

#include "gen/data/Source/D2Game/GAME/Clients_00537B50.inc"
struct D2ActiveRoomStrc;
struct D2GameStrc;
