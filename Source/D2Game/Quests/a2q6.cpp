#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define QUEST_A2Q6_DURIEL 13
struct Arg;
struct Flags;
struct D2PlayerDataStrc;
struct D2Act1Quest4Strc;
struct D2Act1Quest5Strc;
struct D2Act2Quest3Strc;
struct D2Act2Quest4Strc;
struct D2Act2Quest5Strc;
struct D2Act2Quest6Strc;
struct Extra;

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x3A];
    int dwGameFrame;
};



struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

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
    unsigned short dw0E;
    int nSeqId;
    unsigned int dwFlags;
    void* pQuestDataEx;
};

struct D2Act1Quest4Strc
{
    char unk0x00[0x92];
    unsigned char bChangePortalInTownToSpecialMode;
    unsigned char bCainInTristramDeactivated;
};

struct D2Act1Quest5Strc
{
    char unk0x00[0x118];
    unsigned char bCountessKilled;
    unsigned char bDeathMissilesCreated;
};

struct D2Act2Quest3Strc
{
    char unk0x00[0x04];
    bool bAltarDestroyed;
};

struct D2Act2Quest4Strc
{
    char unk0x00[0x0F];
    unsigned char unk0x0F;
    unsigned char unk0x10;
    char unk0x11[0x07];
    unsigned char unk0x18;
    unsigned char unk0x19;
    char unk0x1A[0x16];
    D2CoordStrc pGuardCoords;
    int nHaremBlockerGUID;
    int nJerhynGUID;
    unsigned short nHaremBlockerObjectMode;
};

struct D2Act2Quest5Strc
{
    unsigned char unk0x00;
    unsigned char unk0x01;
};

struct D2Act2Quest6Strc
{
    char unk0x00[0x0B];
    unsigned char bDurielLairTombOpen;
    char unk0x0C[0x03];
    unsigned char bPortalToLutGholeinOpened;
    char unk0x10[0x2D];
    unsigned char bRewardedOrCompletedBefore;
    char unk0x3E[0x02];
    D2UnitStrc* pTyrael;
    unsigned char bCloseToTyrael;
};

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
void __stdcall ACT1Q5_SpawnTowerChestMissiles(D2QuestDataStrc* pQuestData, D2Act1Quest5Strc* pQuestDataEx); // 0x005954F0
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350
int __fastcall ACT2Q5_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059BCB0
int __fastcall ACT2Q5_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059BD10
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
int __fastcall ACT2Q6_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059C710
int __fastcall sub_0059D720_ACT2Q6_GetArcaneThingObjectId(D2QuestDataStrc* pQuestData); // 0x0059D720

typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg); // 0x005538D0
void __fastcall ACT2Q6_UnitIterate_CheckDistanceToTyrael(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059DF30
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall CLIENTS_UpdateCharacterProgression(D2ClientStrc* pClient, int nAct, int nDifficulty); // 0x00538680
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

struct Game { char pad[0x1C]; void* pool; };

typedef void (__fastcall *Callback)(Quest*,Arg*);

typedef bool (__fastcall *Status)(Quest*,Unit*,Flags*,Flags*,unsigned char*);

typedef bool (__fastcall *Active)(Quest*,int,Unit*,Flags*,Unit*);

typedef bool (__fastcall *Sequence)(Quest*);

struct Extra { unsigned char f0,f1,f2,f3; char pad4[0x14]; int value18,value1c; char pad20[0x14]; int value34; char f_38[0x30]; };

struct Quest { int number; Game* game; unsigned char act,notIntro,active,lastState,state,init; short padE; int sequenceId; unsigned int flags; Extra* extra; char guidPad[0x84]; Callback callbacks[15]; void* messages; int filter; int padE4; Status statusFilter; Active activeFilter; Sequence sequenceFilter; };

extern "C" void* __cdecl memset(void*,int,unsigned int);
void* __fastcall sub_0040B430(void*,int,const char*,int,int); // 0x0040B430
extern char npc_messages[]; // 0x0073B288
void __fastcall sub_0059D1C0(Quest*,Arg*); // 0x0059D1C0
void __fastcall sub_0059C3C0(Quest*,Arg*); // 0x0059C3C0
void __fastcall sub_0059CB20(Quest*,Arg*); // 0x0059CB20
void __fastcall sub_0059C6B0(Quest*,Arg*); // 0x0059C6B0
void __fastcall sub_0059C760(Quest*,Arg*); // 0x0059C760
void __fastcall sub_0059D4F0(Quest*,Arg*); // 0x0059D4F0
void __fastcall sub_0059D4D0(Quest*,Arg*); // 0x0059D4D0
void __fastcall sub_0059D050(Quest*,Arg*); // 0x0059D050
bool __fastcall sub_0059CA50(Quest*,Unit*,Flags*,Flags*,unsigned char*); // 0x0059CA50
bool __fastcall sub_0059D300(Quest*,int,Unit*,Flags*,Unit*); // 0x0059D300
bool __fastcall sub_0059D450(Quest*); // 0x0059D450

enum { QUEST_FILTER = 14, ALLOC_LINE = 1090 };

// 0x005945F0
void __fastcall ACT1Q4_OnCainInTownActivated(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 4);
    if (pQuestData)
    {
        ((D2Act1Quest4Strc*)pQuestData->pQuestDataEx)->bChangePortalInTownToSpecialMode = 1;
    }
}

// 0x00594610
int __fastcall ACT1Q4_IsCainInTristramDeactivated(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 4);
    if (!pQuestData)
    {
        return 0;
    }

    return ((D2Act1Quest4Strc*)pQuestData->pQuestDataEx)->bCainInTristramDeactivated != 0;
}

// 0x005956C0
void __fastcall sub_005956C0_ACT1Q5_SpawnChestMissilesAndEvent(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    ACT1Q5_SpawnTowerChestMissiles(pQuestData, (D2Act1Quest5Strc*)pQuestData->pQuestDataEx);

    if (((D2Act1Quest5Strc*)pQuestData->pQuestDataEx)->bCountessKilled && !((D2Act1Quest5Strc*)pQuestData->pQuestDataEx)->bDeathMissilesCreated)
    {
        EVENT_SetEvent(pQuestData->pGame, pUnit, 7, pQuestData->pGame->dwGameFrame + 10, 0, 0);
    }
}

// 0x0059AC80
bool __fastcall sub_0059AC80_ACT2Q3_IsAltarDestroyed(D2QuestDataStrc* pQuest)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pQuest->pGame, 10);
    if (pQuestData)
    {
        return ((D2Act2Quest3Strc*)pQuestData->pQuestDataEx)->bAltarDestroyed;
    }

    return false;
}

// 0x0059AEC0
int __fastcall ACT2Q4_IsHaremBlockerObjectOpened(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 11);
    if (pQuestData && ((D2Act2Quest4Strc*)pQuestData->pQuestDataEx)->nHaremBlockerObjectMode == 2)
    {
        return 1;
    }

    return 0;
}

// 0x0059B6E0
int __fastcall ACT2Q4_IsGuardMoving(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 11);
    if (!pQuestData)
    {
        return 0;
    }

    D2Act2Quest4Strc* pQuestDataEx = (D2Act2Quest4Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->unk0x0F != 1 || pQuestDataEx->unk0x10)
    {
        return 0;
    }

    pQuestDataEx->unk0x10 = 1;
    return 1;
}

// 0x0059B8B0
int __fastcall ACT2Q4_HasGuardMovedToEndPosition(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 11);
    if (pQuestData)
    {
        D2Act2Quest4Strc* pQuestDataEx = (D2Act2Quest4Strc*)pQuestData->pQuestDataEx;
        if (!pQuestDataEx->unk0x18 && !pQuestDataEx->unk0x19)
        {
            return pQuestDataEx->nHaremBlockerObjectMode == 2;
        }

        return 0;
    }

    return 1;
}

// 0x0059B8F0
int __fastcall ACT2Q4_GetGuardCoordinates(D2GameStrc* pGame, D2CoordStrc* pCoord)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 11);
    if (!pQuestData)
    {
        return 0;
    }

    D2Act2Quest4Strc* pQuestDataEx = (D2Act2Quest4Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->unk0x18)
    {
        *pCoord = pQuestDataEx->pGuardCoords;
        return 1;
    }

    if (pQuestDataEx->unk0x19)
    {
        *pCoord = pQuestDataEx->pGuardCoords;
        pCoord->nY -= 4;
        return 1;
    }

    return 0;
}

// 0x0059C330
void __fastcall ACT2Q5_OnSummonerActivated(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 12);
    if (!pQuestData || pQuestData->bNotIntro != 1)
    {
        return;
    }

    D2Act2Quest5Strc* pQuestDataEx = (D2Act2Quest5Strc*)pQuestData->pQuestDataEx;
    if (!pQuestDataEx->unk0x01)
    {
        pQuestDataEx->unk0x01 = 1;
    }

    if (!pQuestData->fState)
    {
        QUESTS_StateDebug(pQuestData, 1, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q5.cpp", 0x238);
    }

    if (pQuestData->fLastState < 2)
    {
        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, 2, 0, ACT2Q5_UnitIterate_StatusCyclerEx, 1);
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT2Q5_UnitIterate_UpdateQuestStateFlags);
    }
}

// 0x0059C6C0
int __fastcall sub_0059C6C0_ACT2Q6_UpdateRewardFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnused)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 0x0E, 0) != 1)
    {
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x0D);
        if (pQuestData && pQuestData->fState >= 2)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 0x0E, 2);
        }
    }

    return 0;
}

// 0x0059C750
void __fastcall ACT2Q6_AttachCompletionSoundToPlayers(D2GameStrc* pGame)
{
    SUNIT_IterateUnitsOfType(pGame, 0, 0, ACT2Q6_UnitIterate_AttachCompletionSound);
}

// 0x0059D7C0
bool __fastcall sub_0059D7C0_ACT2Q6_IsStateBelow2Inactive(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 13);
    if (pQuestData && pQuestData->bNotIntro && pQuestData->fState < 2)
    {
        return false;
    }

    return true;
}

// 0x0059D830
int __fastcall ACT2Q6_GetObjectIdForArcaneThing(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 13);
    if (pQuestData)
    {
        return sub_0059D720_ACT2Q6_GetArcaneThingObjectId(pQuestData);
    }

    return 0x133;
}

// 0x0059DB20
int __fastcall ACT2Q6_IsDurielsLairClosed(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 13);
    if (pQuestData && pQuestData->bNotIntro)
    {
        return ((D2Act2Quest6Strc*)pQuestData->pQuestDataEx)->bDurielLairTombOpen == 0;
    }

    return 0;
}

// 0x0059DF50
int __fastcall ACT2Q6_IsInRangeOfTyrael(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 13);
    if (pQuestData)
    {
        D2Act2Quest6Strc* pQuestDataEx = (D2Act2Quest6Strc*)pQuestData->pQuestDataEx;
        if (pQuestDataEx->bRewardedOrCompletedBefore)
        {
            return 1;
        }

        if (pQuestDataEx->bPortalToLutGholeinOpened)
        {
            pQuestDataEx->bCloseToTyrael = 0;
            pQuestDataEx->pTyrael = pUnit;
            SUNIT_IterateLivingPlayers(pGame, ACT2Q6_UnitIterate_CheckDistanceToTyrael, pQuestDataEx);
            return pQuestDataEx->bCloseToTyrael == 0;
        }
    }

    return 0;
}

// 0x0059DFB0
bool __fastcall sub_0059DFB0_ACT2Q6_IsStateBelow4Inactive(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 13);
    if (pQuestData && pQuestData->bNotIntro && pQuestData->fState < 4)
    {
        return false;
    }

    return true;
}

// 0x0059C810
static __declspec(noinline) void __stdcall sub_0059C810_FinishDurielQuest(D2GameStrc* pGame, D2UnitStrc* pUnit, D2BitBufferStrc* pQuestFlags)
{
    QUESTRECORD_SetQuestState(pQuestFlags, 14, 13);
    QUESTRECORD_SetQuestState(pQuestFlags, 14, 3);
    CLIENTS_UpdateCharacterProgression(SUNIT_GetClientFromPlayer(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q6.cpp", 386), 2, pGame->nDifficulty);
}

static D2BitBufferStrc* GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
}

int __fastcall ACT2Q6_UnitIterate_SetLeaveTownFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = GetQuestFlags(pGame, pUnit);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    D2_ASSERT(QUESTS_GetQuestData(pGame, 13), 401);

    bool bInLair = false;
    if (DUNGEON_GetLevelIdFromRoom(pRoom) == 73)
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
void __fastcall ACT2Q6_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
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

// 0x0059D5B0
void __fastcall sub_0059D5B0(Quest* quest)
{
    memset(quest->callbacks,0,sizeof(quest->callbacks));
    quest->callbacks[3]=sub_0059D1C0;
    quest->callbacks[0]=sub_0059C3C0;
    quest->callbacks[11]=sub_0059CB20;
    quest->callbacks[10]=sub_0059C6B0;
    quest->callbacks[2]=sub_0059C760;
    quest->callbacks[13]=sub_0059D4F0;
    quest->callbacks[14]=sub_0059D4D0;
    quest->callbacks[8]=sub_0059D050;
    quest->messages=npc_messages;
    quest->active=1;
    quest->state=0;
    Extra* extra=(Extra*)sub_0040B430(quest->game->pool,0x68,"d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q6.cpp",ALLOC_LINE,0);
    quest->extra=extra;
    quest->filter=QUEST_FILTER;
    quest->statusFilter=sub_0059CA50;
    quest->init=4;
    quest->activeFilter=sub_0059D300;
    quest->sequenceFilter=sub_0059D450;
    memset(extra,0,0x68);
    extra->f1=0;
    extra->f2=0;
    extra->f3=0;
    extra->value18=0;
    extra->value1c=0;
    extra->value34=0;
}

#include "gen/data/Source/D2Game/Quests/a2q6.inc"

// 0x0059D7E0
unsigned char __fastcall sub_0059D7E0_ACT2Q6_IsStateOne(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A2Q6_DURIEL);
    if (pQuestData && pQuestData->bNotIntro && pQuestData->fState == 1)
    {
        return 1;
    }

    return 0;
}
