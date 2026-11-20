#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#define QFLAG_REWARDGRANTED 0
#define QFLAG_REWARDPENDING 1
#define QFLAG_STARTED 2
#define QFLAG_LEAVETOWN 3
#define QFLAG_ENTERAREA 4
#define QFLAG_CUSTOM7 11
#define QFLAG_PRIMARYGOALDONE 13
#define QFLAG_COMPLETEDNOW 14
#define QFLAG_COMPLETEDBEFORE 15
#define ACT_III 2
#define QUESTSTATEFLAG_A1Q1 1
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct Obj005452C0;
struct D2PlayerDataStrc;
struct D2QuestGUIDStrc;
struct D2Act5Quest2Strc;
struct D2GSPacketSrv5D;
struct D2Act1Quest1Strc;
struct D2ObjInitFnStrc;
struct D2GameStrc;
struct D2UnitStrc;
struct D2QuestDataStrc;
struct D2QuestArgStrc;
struct D2ActiveRoomStrc;

typedef int (__stdcall* FARPROC)();



struct D2PlayerDataStrc
{
    char pad0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2QuestGUIDStrc
{
    int nPlayerGUIDs[32];
    unsigned short nGUIDCount;
    unsigned short unk0x82;
};

struct D2Act5Quest2Strc
{
    D2QuestGUIDStrc tPlayerGUIDs;
    unsigned char bQualKehkActivated;
    char unk0x85[0xA8 - 0x85];
    int nKilledWussies;
    int nFreedWussies;
    int nWussieGUIDs[3][5];
    int nPortalGUIDs[3];
    unsigned char bPortalSpawned[3];
    unsigned char pad0xFB;
    int nPortalUpdateInvocations[3];
    unsigned char unk0x108[3];
    char unk0x10B[9];
    int unk0x114[3];
    int nFreedWussieUnitGUIDs[15];
    int nWussiesInRangeToDoor;
};

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

typedef bool (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);

typedef bool (__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    unsigned char nActNo;
    unsigned char bNotIntro;
    unsigned char bActive;
    unsigned char fLastState;
    unsigned char fState;
    char nInitNo;
    char pad0x0E[0x2];
    int nSeqId;
    union
    {
        unsigned int dwFlags;
        unsigned char bStatusFlags;
    };
    void* pQuestDataEx;
    D2QuestGUIDStrc tPlayerGUIDs;
    QUESTCALLBACK pCallback[15];
    void* pNPCMessages;
    int eFilter;
    char pad0xE4[0x4];
    QUESTSTATUSFILTER pfStatusFilter;
    QUESTACTIVEFILTER pfActiveFilter;
    QUESTSEQFILTER pfSeqFilter;
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    char pad0x10[0x4];
    union
    {
        D2TextHeaderStrc* pTextControl;
        int nOldLevel;
        unsigned short nNPCNo;
    };
    union
    {
        int nNewLevel;
        unsigned short nMessageIndex;
    };
};

struct D2GSPacketSrv5D
{
    unsigned char nHeader;
    unsigned char nQuestId;
    unsigned char nFlags;
    unsigned char nState;
    unsigned short field_4;
};

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C
extern const unsigned int gdwAct5Q2RuneCodes_00732FEC[3]; // 0x00732FEC
void __fastcall sub_6FC3F380(D2ClientStrc* pClient, D2GSPacketSrv5D* pPacket); // 0x0053D710
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350
void __fastcall QUESTS_AddPlayerGUID(D2QuestGUIDStrc* pQuestGUID, int dwGUID); // 0x00545200
void __fastcall QUESTS_NPCActivateSpeeches(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTarget); // 0x00545780
D2UnitStrc* __fastcall QUESTS_CreateItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned int dwCode, int nLevel, int nQuality, int bDroppable); // 0x005466B0
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C3A0
void __stdcall QUESTRECORD_ResetIntermediateStateFlags(D2BitBufferStrc* pQuestFlags, int nQuestId); // 0x0065C3E0
int __fastcall ACT5Q2_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005879D0
int __fastcall ACT5Q2_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00587A90
extern "C" int __fastcall sub_005452C0(Obj005452C0* pObj, unsigned int dwValue); // 0x005452C0
void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790
int __fastcall sub_00587FC0_GetWussieGroupIndex(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x00587FC0

typedef void(__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nQuestId);
int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID); // 0x00545240
void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit);
void __fastcall QUESTS_SendLogUpdateEx(D2UnitStrc* pPlayer, int nQuestId, unsigned char nAct);
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

struct D2Act1Quest1Strc
{
    D2QuestGUIDStrc pQuestGUID;
    char unk0x84[0x03];
    unsigned char bTimerActive;
};

int __fastcall ACT1Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
void __fastcall ACT1Q1_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2ActiveRoomStrc* pRoom;
    void* pObjectregion;
    void* pObjectTxt;
    int nX;
    int nY;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern char gpAct5Q2NpcMessages[]; // 0x00733940
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
int __fastcall QUESTS_CreateChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuestId); // 0x005436B0
void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pQuestGUID); // 0x00545300
void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg); // 0x00545310
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* ptRoom, D2ActiveRoomStrc*** pppRoomList, int* pNumRooms); // 0x00619790
void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bSet); // 0x0061AED0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0
void __fastcall ACT5Q2_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00587A30
void __fastcall ACT5Q2_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00587B00
void __fastcall ACT5Q2_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00587D30
void __fastcall ACT5Q2_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00587E60
void __fastcall ACT1Q1_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00587F20
int __fastcall ACT5Q2_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00587F60
bool __fastcall ACT5Q2_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x00588340
void __fastcall ACT5Q2_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00588040
void __fastcall ACT5Q2_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
bool __fastcall ACT5Q2_SeqCallback(D2QuestDataStrc* pQuestData);
void __fastcall ACT5Q2_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT5Q2_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
static __forceinline void sub_00588010_CountWussie(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit);

static __forceinline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x00587B00
void __fastcall ACT5Q2_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act5Quest2Strc* pQuestDataEx = (D2Act5Quest2Strc*)pQuestData->pQuestDataEx;
    const short nMessageIndex = pQuestArg->nMessageIndex;

    if (pQuestArg->nNPCNo != 0x203)
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestData->pGame, pQuestArg->pPlayer);

    if (nMessageIndex == 20096)
    {
        pQuestDataEx->bQualKehkActivated = 1;
        QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q2.cpp", 0x100);
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT5Q2_UnitIterate_UpdateQuestStateFlags);
        QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
    }
    else if (nMessageIndex == 20110)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1) == 1)
        {
            {
                bool bRewardGranted = false;

                if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 13))
                {
                    if (pQuestData->fState != 5)
                    {
                        QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q2.cpp", 0x128);
                        if (IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter))
                        {
                            sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x129);
                            exit(-1);
                        }
                        pQuestData->pfSeqFilter(pQuestData);

                        pQuestData->dwFlags &= 0xFFFFFF00;
                        QUESTS_UnitIterate(pQuestData, 13, 0, ACT5Q2_UnitIterate_StatusCyclerEx, 0);
                    }
                    pQuestData->pCallback[2] = nullptr;
                }

                int nRewards = 3;
                if (QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 6))
                {
                    nRewards = 2;
                }
                else if (QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 7))
                {
                    nRewards = 1;
                }

                if (nRewards > 0)
                {
                    for (int i = 0; i < nRewards; ++i)
                    {
                        if (QUESTS_CreateItem(pQuestArg->pGame, pQuestArg->pPlayer, gdwAct5Q2RuneCodes_00732FEC[i], 0, 2, 1))
                        {
                            bRewardGranted = true;
                        }
                    }

                    if (bRewardGranted)
                    {
                        QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->eFilter, 0);
                        QUESTRECORD_ClearQuestState(pQuestFlags, pQuestData->eFilter, 1);
                        QUESTRECORD_ResetIntermediateStateFlags(pQuestFlags, pQuestData->eFilter);

                        QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);

                        D2GSPacketSrv5D packet5D = {};
                        packet5D.nHeader = 0x5D;
                        packet5D.nQuestId = 0x20;
                        packet5D.nFlags = 2;
                        sub_6FC3F380(UnitGetClient(pQuestArg->pPlayer, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q2.cpp", 0x14E), &packet5D);
                    }
                }
            }

            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
        }
    }
}

// 0x00587D30
void __fastcall ACT5Q2_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestData->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    const int nRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0);
    const int nPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 13);
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
        return;
    }

    if (sub_005452C0((Obj005452C0*)pQuestData, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId) == 1)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4);
        return;
    }

    if (nRewardGranted == 1)
    {
        return;
    }

    const unsigned char nState = pQuestData->fState;
    if ((nState >= 4 && !nPrimaryGoalDone) || !pQuestData->bNotIntro)
    {
        return;
    }

    const unsigned int nIndex = gnA5Q2NpcActivateIndices[nState];
    if (gnA5Q2NpcActivateIndices[nState] == 2 && nNpcId == 0x203)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 4))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 0x203, 5);
            return;
        }
        goto send;
    }

    if (nIndex != -1 && nIndex < 12)
    {
send:
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
    }
}

#include "gen/data/Source/D2Game/Quests/a5q2.inc"

// 0x00587E60
void __fastcall ACT5Q2_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
    D2BitBufferStrc* pQuestFlags = pPlayerData->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 0) == 1
        || QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 1) == 1)
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

    QUESTRECORD_SetQuestState(pQuestFlags, 0x24, 0xD);
    QUESTRECORD_SetQuestState(pQuestFlags, 0x24, 1);

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x20);
    D2Act5Quest2Strc* const pQuestDataEx = (D2Act5Quest2Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->nFreedWussies == 15)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 0x24, 5);
    }
    else if (pQuestDataEx->nFreedWussies == 14)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 0x24, 6);
    }
    else
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 0x24, 7);
    }
}

void __fastcall sub_M117_Emit_00588010(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    sub_00588010_CountWussie(pQuestData, pUnit);
}

int __fastcall ACT1Q1_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_REWARDPENDING) == 1)
    {
        return 0;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_COMPLETEDNOW);
    QUESTS_SendLogUpdateEx(pUnit, 1, 0);
    QUESTS_UpdatePlayerFlags(pGame, pUnit);
    return 0;
}

int __fastcall ACT1Q1_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_PRIMARYGOALDONE))
    {
        SUNIT_AttachSound(pUnit, 35, pUnit);
    }

    return 0;
}

void __fastcall ACT1Q1_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_REWARDPENDING) == 1)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (nLevelId && DRLG_GetActNoFromLevelId(nLevelId) == ACT_I)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_PRIMARYGOALDONE);
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_REWARDPENDING);
    }
}

// 0x00590190
int __fastcall ACT1Q1_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_PRIMARYGOALDONE))
    {
        return 0;
    }

    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT1Q1_UnitIterate_SetPrimaryGoalDone, 0);
    }

    return 0;
}

// 0x00587F20
void __fastcall ACT1Q1_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_FastRemovePlayerGUID(&pQuestData->tPlayerGUIDs, (!pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId));
    D2Act1Quest1Strc* pQuestDataEx = (D2Act1Quest1Strc*)pQuestData->pQuestDataEx;
    QUESTS_FastRemovePlayerGUID(&pQuestDataEx->pQuestGUID, (!pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId));
}

// 0x00588010
static __forceinline void sub_00588010_CountWussie(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    const int nIndex = sub_00587FC0_GetWussieGroupIndex(pQuestData, pUnit);
    if (nIndex >= 0)
    {
        D2Act5Quest2Strc* pQuestDataEx = (D2Act5Quest2Strc*)pQuestData->pQuestDataEx;
        pQuestDataEx->unk0x114[nIndex] += 1;
        if (pQuestDataEx->unk0x114[nIndex] >= 5)
        {
            pQuestDataEx->unk0x108[nIndex] = 1;
        }
    }
}

bool __fastcall ACT1Q1_Timer_StatusCycler(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    D2Act1Quest1Strc* pQuestDataEx = (D2Act1Quest1Strc*)pQuestData->pQuestDataEx;
    if (pQuestData->fState == 4)
    {
        pQuestData->bStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 5, 0, ACT1Q1_UnitIterate_StatusCyclerEx, 1);
    }

    pQuestDataEx->bTimerActive = 0;
    return 1;
}

void __fastcall ACT1Q1_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED) || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_COMPLETEDBEFORE))
    {
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_ENTERAREA) == 1)
    {
        pQuestData->fLastState = 2;
        pQuestData->fState = 3;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_LEAVETOWN) == 1)
    {
        pQuestData->fState = 3;
        pQuestData->fLastState = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_STARTED) == 1)
    {
        pQuestData->fState = 2;
        pQuestData->fLastState = 1;
    }
}

// 0x00588200
void __fastcall ACT5Q2_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nOldLevel = pQuestArg->nOldLevel;
    switch (pQuestArg->nNewLevel)
    {
    case 111:
    case 112:
        if (!pQuestData->bNotIntro || ((D2Act5Quest2Strc*)pQuestData->pQuestDataEx)->nKilledWussies >= 5)
        {
            break;
        }

        bool bWasStarted = false;
        if (pQuestData->fState == 1 || pQuestData->fState == 2)
        {
            QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q2.cpp", 632);
            bWasStarted = true;
        }

        if (!pQuestData->fLastState)
        {
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTS_UnitIterate(pQuestData, 1, nullptr, ACT5Q2_UnitIterate_StatusCyclerEx, 1);
            pQuestData->pCallback[2] = nullptr;
        }
        else if (!bWasStarted)
        {
            return;
        }
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, nullptr, ACT5Q2_UnitIterate_UpdateQuestStateFlags);
        return;
    }

    if (nOldLevel == 109)
    {
        QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
        if (pQuestData->fState != 2)
        {
            return;
        }

        D2UnitStrc* pPlayer = pQuestArg->pPlayer;
        D2GameStrc* pGame = pQuestArg->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1) == 1)
        {
            return;
        }

        QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q2.cpp", 660);
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, nullptr, ACT5Q2_UnitIterate_UpdateQuestStateFlags);
        if (pQuestData->fLastState || !pQuestData->bNotIntro || ((D2Act5Quest2Strc*)pQuestData->pQuestDataEx)->nKilledWussies >= 5)
        {
            return;
        }

        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, 1, nullptr, ACT5Q2_UnitIterate_StatusCyclerEx, 1);
        pQuestData->pCallback[2] = nullptr;
    }
}

// 0x005883E0
bool __fastcall ACT5Q2_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (pQuestData->fState != 5 && pQuestData->bNotIntro)
    {
        if (!pQuestData->fState)
        {
            pQuestData->fState = 1;
        }

        return true;
    }

    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, pQuestData->nSeqId);
    if (pQuest)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 717);
        return pQuest->pfSeqFilter(pQuest);
    }

    return false;
}

// 0x00588450
void __fastcall ACT5Q2_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    QUESTRECORD_ClearQuestState(pQuestFlags, 36, 4);
}

// 0x00588470
void __fastcall ACT5Q2_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    QUESTRECORD_ClearQuestState(pQuestFlags, pQuestData->eFilter, 4);

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0)
        || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 15)
        || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1) == 1)
    {
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 3) == 1)
    {
        pQuestData->fState = 3;
        pQuestData->fLastState = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 2) == 1)
    {
        pQuestData->fState = 2;
        pQuestData->fLastState = 1;
    }
}

// 0x00588510
void __fastcall ACT5Q2_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[10] = ACT1Q1_Callback10_PlayerLeavesGame;
    pQuestData->pCallback[3] = ACT5Q2_Callback03_ChangedLevel;
    pQuestData->pCallback[8] = ACT5Q2_Callback08_MonsterKilled;
    pQuestData->pCallback[0] = ACT5Q2_Callback00_NpcActivate;
    pQuestData->pCallback[2] = ACT5Q2_Callback02_NpcDeactivate;
    pQuestData->pCallback[11] = ACT5Q2_Callback11_ScrollMessage;
    pQuestData->pCallback[13] = ACT5Q2_Callback13_PlayerStartedGame;
    pQuestData->pCallback[14] = ACT5Q2_Callback14_PlayerJoinedGame;
    pQuestData->pNPCMessages = gpAct5Q2NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    D2Act5Quest2Strc* pQuestDataEx = (D2Act5Quest2Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act5Quest2Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q2.cpp", 803, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->eFilter = 36;
    pQuestData->pfStatusFilter = nullptr;
    pQuestData->nInitNo = 4;
    pQuestData->pfActiveFilter = ACT5Q2_ActiveFilterCallback;
    pQuestData->pfSeqFilter = ACT5Q2_SeqCallback;
    pQuestData->nSeqId = 33;
    memset(pQuestDataEx, 0x00, sizeof(D2Act5Quest2Strc));
    QUESTS_ResetPlayerGUIDCount(&pQuestDataEx->tPlayerGUIDs);
}

// 0x005887A0
int __fastcall ACT5Q2_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 36, 13))
    {
        const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
        if (nPartyId != 0xFFFF)
        {
            PARTY_IteratePartyMembers(pGame, nPartyId, ACT5Q2_UnitIterate_SetPrimaryGoalDone, 0);
        }
    }

    return 0;
}

// 0x005887F0
int __fastcall ACT5Q2_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 36, 13))
    {
        SUNIT_AttachSound(pUnit, 81, pUnit);
    }

    return 0;
}
