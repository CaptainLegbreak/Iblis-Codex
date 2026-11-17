#include "D2Game.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2PlayerDataStrc;
struct D2ObjInitFnStrc;
struct D2ObjOperateFnStrc;
struct D2Act2Quest6Strc;
struct D2GSPacketSrv50;
struct D2GSPacketSrv58;

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char pad0x6E[0x3A];
    unsigned int dwGameFrame;
    char pad0xAC[0x10];
    D2DrlgActStrc* pAct[5];
};

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

extern "C" const char szA2Q6File_006E2068[]; // 0x006E2068
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char pad0x08[0x4];
    int dwUnitId;
    int dwAnimMode;
    char pad0x14[0xB4];
};

D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall CLIENTS_UpdateCharacterProgression(D2ClientStrc* pClient, int nAct, int nDifficulty); // 0x00538680
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

typedef bool (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);

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
    unsigned int dwFlags;
    void* pQuestDataEx;
    char tPlayerGUIDs[0x84];
    QUESTCALLBACK pfCallback[15];
    void* pNPCMessages;
    int nQuestFilter;
    char pad0xE4[0xC];
    QUESTSEQFILTER pfSeqFilter;
};

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
static __declspec(noinline) void __stdcall sub_0059C810_FinishDurielQuest(D2GameStrc* pGame, D2UnitStrc* pUnit, D2BitBufferStrc* pQuestFlags);

struct D2ObjectsTxt
{
    char pad0x00[0xDC];
    unsigned int dwFrameCnt1;
};

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2ActiveRoomStrc* pRoom;
    char pad0x0C[0x10];
};

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
};

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

typedef bool (__fastcall* QUESTUPDATE)(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);

typedef int (__stdcall* FARPROC)();

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    char pad0x10[0xC];
};

struct D2Act2Quest6Strc
{
    unsigned char unk0x00;
    unsigned char bDurielKilled;
    char pad0x02[0x1];
    unsigned char bTimerActive;
    unsigned char bHoradricOrificeInitialized;
    unsigned char bTyraelsDoorInitialized;
    unsigned char bUnusedObjectInitialized;
    char pad0x07[0x4];
    unsigned char bDurielLairTombOpen;
    unsigned char bDurielLairPortalNeedsToOpen;
    unsigned char bObjectsNeedUpdate;
    char pad0x0E[0xA];
    int nTyraelsDoorObjectMode;
    char pad0x1C[0x4];
    int nHoradricOrificeGUID;
    char pad0x24[0x4];
    int nUnusedObjectGUID;
    int nTyraelsDoorGUID;
    char pad0x30[0x4];
    int nStaffTombLevelId;
    char pad0x38[0x5];
    unsigned char bRewardedOrCompletedBefore;
    char pad0x3E[0x22];
    D2ActiveRoomStrc* pDurielRoom;
};

#pragma pack(push, 1)
struct D2GSPacketSrv50
{
    unsigned char nHeader;
    unsigned short nQuestId;
    unsigned short nStaffTombLevelOffset;
    unsigned char unk0x05[0x0B];
};

struct D2GSPacketSrv58
{
    unsigned char nHeader;
    int nUnitId;
    unsigned char unk0x05;
};

#pragma pack(pop)

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C
int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit); // 0x00535060
void __fastcall D2GAME_SendPacket0x50_6FC3F440(D2ClientStrc* pClient, D2GSPacketSrv50* pPacket); // 0x0053D7E0
void __fastcall sub_0053D8D0_SendPacket0x58(D2ClientStrc* pClient, D2GSPacketSrv58* pPacket); // 0x0053D8D0
void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks); // 0x00543F10
int __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine); // 0x00544070
void __fastcall QUESTS_DeleteItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, int dwCode); // 0x00544160
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350
void __fastcall QUESTS_TriggerFX(D2GameStrc* pGame, unsigned char a2); // 0x00545760
void __fastcall sub_00545990(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg, int nValue); // 0x00545990
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
void __stdcall SUNIT_SetInteractInfo(D2UnitStrc* pUnit, int nInteractUnitType, int nInteractUnitGUID); // 0x00554120
void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit); // 0x00554190
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630
D2UnitStrc* __fastcall SUNIT_GetInteractUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00554D00
int __fastcall D2GAME_PLRTRADE_IsInteractingWithPlayer(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3); // 0x005678A0
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode); // 0x00558110
bool __fastcall sub_0059CEE0(D2GameStrc* pGame, D2QuestDataStrc* pQuestData); // 0x0059CEE0
void __fastcall ACT2Q6_UnitIterate_SetCustom1Flag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059CF20
int __fastcall ACT2Q6_UnitIterate_SetCustom1FlagForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059CFB0
bool __fastcall ACT2Q6_Timer_UpdateObjects(D2GameStrc* pGame, D2QuestDataStrc* pQuestData); // 0x0059D870
void __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C3A0

static D2BitBufferStrc* GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
}

// 0x0059C860
int __fastcall ACT2Q6_UnitIterate_SetLeaveTownFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    struct { D2ActiveRoomStrc* pRoom; D2QuestDataStrc* pQuestInfo; } tLocals;
    tLocals.pRoom = UNITS_GetRoom(pUnit);
    if (!tLocals.pRoom)
    {
        return 0;
    }

    tLocals.pQuestInfo = QUESTS_GetQuestData(pGame, 13);
    D2_ASSERT(tLocals.pQuestInfo, 401);

    bool bInLair = false;
    if (DUNGEON_GetLevelIdFromRoom(tLocals.pRoom) == 73)
    {
        bInLair = true;
    }

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 14, 13)
        && !QUESTRECORD_GetQuestState(pQuestFlags, 14, 3)
        && !QUESTRECORD_GetQuestState(pQuestFlags, 14, 4)
        && bInLair)
    {
        sub_0059C810_FinishDurielQuest(pGame, pUnit, pQuestFlags);
    }

    return 0;
}

// 0x0059C920
void __fastcall ACT2Q6_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData) // 0x0059C920
{
    if (!QUESTS_GetQuestData(pGame, 13))
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 14, 0) == 1
        || QUESTRECORD_GetQuestState(pQuestFlags, 14, 3) == 1
        || QUESTRECORD_GetQuestState(pQuestFlags, 14, 4) == 1)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    if (DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom)) != 1)
    {
        return;
    }

    sub_0059C810_FinishDurielQuest(pGame, pUnit, pQuestFlags);
}

// 0x0059C810
static __declspec(noinline) void __stdcall sub_0059C810_FinishDurielQuest(D2GameStrc* pGame, D2UnitStrc* pUnit, D2BitBufferStrc* pQuestFlags) // 0x0059C810
{
    QUESTRECORD_SetQuestState(pQuestFlags, 14, 13);
    QUESTRECORD_SetQuestState(pQuestFlags, 14, 3);
    CLIENTS_UpdateCharacterProgression(SUNIT_GetClientFromPlayer(pUnit, szA2Q6File_006E2068, 386), 2, pGame->nDifficulty);
}

// 0x0059D050
void __fastcall ACT2Q6_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_DebugOutput(pQuestData->pGame, "killed duriel for quest", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q6.cpp", 0x305);
    if (pQuestData->bNotIntro)
    {
        QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q6.cpp", 0x308);
        QUESTS_CreateTimer(pQuestData, sub_0059CEE0, 8);

        if (pQuestArg->pPlayer)
        {
            D2GameStrc* pGame = pQuestArg->pGame;
            D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
            if (!QUESTRECORD_GetQuestState(pQuestFlags, 14, 0)
                && !QUESTRECORD_GetQuestState(pQuestFlags, 14, 3)
                && !QUESTRECORD_GetQuestState(pQuestFlags, 14, 4)
                && !QUESTRECORD_GetQuestState(pQuestFlags, 14, 5))
            {
                QUESTRECORD_SetQuestState(pQuestFlags, 14, 5);

                const unsigned short nPartyId = SUNIT_GetPartyId(pQuestArg->pPlayer);
                if (nPartyId != 0xFFFF)
                {
                    PARTY_IteratePartyMembers(pQuestArg->pGame, nPartyId, (PartyCallbackFunction)ACT2Q6_UnitIterate_SetCustom1Flag, 0);
                }

                sub_00545990(pQuestData, pQuestArg, 0x3D);
            }
        }
    }

    D2Act2Quest6Strc* pQuestDataEx = (D2Act2Quest6Strc*)pQuestData->pQuestDataEx;
    pQuestData->pfCallback[2] = 0;
    pQuestData->pfCallback[8] = 0;
    pQuestDataEx->bDurielKilled = 1;
    pQuestDataEx->pDurielRoom = UNITS_GetRoom(pQuestArg->pTarget);
    QUESTS_TriggerFX(pQuestData->pGame, 8);
    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT2Q6_UnitIterate_SetCustom1FlagForPartyMembers);

    if (pQuestDataEx->bTyraelsDoorInitialized)
    {
        D2UnitStrc* pTyraelsDoor = SUNIT_GetServerUnit(pQuestData->pGame, 2, pQuestDataEx->nTyraelsDoorGUID);
        if (pTyraelsDoor)
        {
            UNITS_ChangeAnimMode(pTyraelsDoor, 1);
            D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(!pTyraelsDoor ? -1 : pTyraelsDoor->dwClassId);
            EVENT_SetEvent(pQuestData->pGame, pTyraelsDoor, 1, pQuestData->pGame->dwGameFrame + (pObjectsTxtRecord->dwFrameCnt1 >> 8), 0, 0);
        }
    }

    pQuestDataEx->nTyraelsDoorObjectMode = 2;
}
