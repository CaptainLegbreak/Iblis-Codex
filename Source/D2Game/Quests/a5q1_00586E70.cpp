#include "D2Game.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2QuestGUIDStrc;
struct D2PlayerDataStrc;
struct D2Act5Quest1Strc;

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char pad0x6E[0x2];
};

struct D2PlayerDataStrc
{
    char szName[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2UnitStrc
{
    char unk0x00[0x0C];
    int dwUnitId;
};

struct D2Act5Quest1Strc
{
    char unk0x00[0x08];
    unsigned char bLarzukStartActivated;
    char unk0x09[0x0D];
    unsigned char bLarzukEndActivated;
};

typedef int(__fastcall* QUESTSEQFN)(D2QuestDataStrc* pQuestData);

typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef int(__stdcall* FARPROC)();

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    unsigned char nActNo;
    unsigned char bNotIntro;
    unsigned char bActive;
    unsigned char fLastState;
    unsigned char fState;
    char unk0x0D[0x07];
    union
    {
        unsigned int dwFlags;
        unsigned char nFlagsByte;
    };
    D2Act5Quest1Strc* pQuestDataEx;
    char tPlayerGUIDs[0x84];
    char unk0xA0[0x40];
    int nQuestFilter;
    char unk0xE4[0x0C];
    QUESTSEQFN pfSeqFilter;
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    unsigned int unk0x10;
    union
    {
        int nOldLevel;
        unsigned short nNPCNo;
    };
    union
    {
        int nNewLevel;
        unsigned short nMessageIndex;
    };
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
void __stdcall QUESTRECORD_ResetIntermediateStateFlags(D2BitBufferStrc* pQuestRecord, int nQuest); // 0x0065C3E0
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
void __fastcall QUESTS_NPCActivateSpeeches(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTarget); // 0x00545780
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_AddPlayerGUID(D2QuestGUIDStrc* pQuestGUID, int dwGUID); // 0x00545200
int __fastcall ACT5Q1_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00586DE0
int __fastcall ACT5Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00586C80
void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg); // 0x00545310

inline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x00586E70
void __fastcall ACT5Q1_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act5Quest1Strc* pQuestDataEx = pQuestData->pQuestDataEx;
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;

    if (pQuestArg->nNPCNo != 0x1FF)
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestData->pGame, pQuestArg->pPlayer);
    if (nMessageIndex == 20077)
    {
        pQuestDataEx->bLarzukStartActivated = 1;
        QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q1.cpp", 0xF8);
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT5Q1_UnitIterate_UpdateQuestStateFlags);
        QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
    }
    else if (nMessageIndex == 20090)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 1) != 1)
        {
            return;
        }

        pQuestDataEx->bLarzukEndActivated = 1;
        QUESTRECORD_ResetIntermediateStateFlags(pQuestFlags, pQuestData->nQuestFilter);
        QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->nQuestFilter, 5);
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 13) && pQuestData->fState != 5)
        {
            QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q1.cpp", 0x108);
            D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 0x109);
            pQuestData->pfSeqFilter(pQuestData);

            pQuestData->nFlagsByte = 0;
            QUESTS_UnitIterate(pQuestData, 13, 0, ACT5Q1_UnitIterate_StatusCyclerEx, 1);
        }

        QUESTS_AddPlayerGUID((D2QuestGUIDStrc*)pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
    }
}

// 0x005873E0
void __fastcall ACT5Q1_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNewLevel = pQuestArg->nNewLevel;
    const int nOldLevel = pQuestArg->nOldLevel;

    switch (nNewLevel)
    {
    case 110:
    case 111:
    case 112:
        if (!pQuestData->bNotIntro)
        {
            return;
        }

        if (pQuestData->fState == 1 || pQuestData->fState == 2)
        {
            QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q1.cpp", 0x229);
            SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT5Q1_UnitIterate_UpdateQuestStateFlags);
        }
        return;

    default:
        break;
    }

    if (nOldLevel != 109)
    {
        return;
    }

    QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
    if (pQuestData->fState != 2)
    {
        return;
    }

    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 1) == 1)
    {
        return;
    }

    QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q1.cpp", 0x23F);
    if (!pQuestData->fLastState)
    {
        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT5Q1_UnitIterate_StatusCyclerEx, 1);
    }
    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT5Q1_UnitIterate_UpdateQuestStateFlags);
}
