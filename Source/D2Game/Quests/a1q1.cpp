#include "D2Game.h"
#include "D2Structs.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2QuestGUIDStrc;
struct D2PlayerDataStrc;
struct D2Act1Quest1Strc;
struct Sub005901E0;
struct Obj005901E0;

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};


struct D2PlayerDataStrc
{
    char szName[0x10];
    D2BitBufferStrc* pQuestData[3];
};

typedef bool(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);

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
    signed char fState;
    char unk0x0D[0x07];
    unsigned int dwFlags;
    void* pQuestDataEx;
    char tPlayerGUIDs[0x84];
    void* pfCallback[15];
    void* pNPCMessages;
    int nQuestFilter;
    int nQuestFilter2;
    char unk0xE8[0x08];
    QUESTSEQFILTER pfSeqFilter;
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
        D2TextHeaderStrc* pTextControl;
        unsigned short nNPCNo;
    };
    unsigned short nMessageIndex;
};

struct D2Act1Quest1Strc
{
    char unk0x00[0x86];
    unsigned char bAkaraActivated;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C
extern "C" const unsigned int gnAct1Quest1NpcIndices[]; // 0x00736CD0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C3A0
void __stdcall QUESTRECORD_ResetIntermediateStateFlags(D2BitBufferStrc* pQuestRecord, int nQuest); // 0x0065C3E0
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0
void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
void __fastcall QUESTS_NPCActivateSpeeches(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTarget); // 0x00545780
void __fastcall QUESTS_AddPlayerGUID(D2QuestGUIDStrc* pQuestGUID, int dwGUID); // 0x00545200
int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc* pQuest, int dwGUID); // 0x005452C0
int __fastcall ACT1Q1_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058FC90
int __fastcall ACT1Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058FBE0

struct Sub005901E0 { unsigned char bUnknown00[0x88]; unsigned int dwValue88; };

struct Obj005901E0 { unsigned char bUnknown00[0x18]; Sub005901E0* pSub18; };

// 0x0058FDD0
void __fastcall ACT1Q1_Callback11_ScrollMessage(D2QuestDataStrc* pQuest, D2QuestArgStrc* pArg)
{
    D2Act1Quest1Strc* pQuestDataEx = (D2Act1Quest1Strc*)pQuest->pQuestDataEx;
    const unsigned short nMessageIndex = pArg->nMessageIndex;
    if (pArg->nNPCNo != 0x94)
    {
        return;
    }

    D2UnitStrc* pPlayer = pArg->pPlayer;
    D2GameStrc* pGame = pQuest->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (nMessageIndex == 0x40)
    {
        pQuestDataEx->bAkaraActivated = 1;
        QUESTS_StateDebug(pQuest, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q1.cpp", 0xFD);
        SUNIT_IterateUnitsOfType(pQuest->pGame, 0, 0, ACT1Q1_UnitIterate_UpdateQuestStateFlags);
        QUESTS_NPCActivateSpeeches(pArg->pGame, pArg->pPlayer, pArg->pTarget);
    }
    else if (nMessageIndex == 0x4C)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, 1) != 1)
        {
            return;
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, 0xD))
        {
            if (pQuest->fState != 5)
            {
                QUESTS_StateDebug(pQuest, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q1.cpp", 0x109);
                D2_ASSERT(!IsBadCodePtr((FARPROC)pQuest->pfSeqFilter), 0x10A);
                pQuest->pfSeqFilter(pQuest);
                pQuest->dwFlags &= 0xFFFFFF00;
                QUESTS_UnitIterate(pQuest, 0xD, 0, ACT1Q1_UnitIterate_StatusCyclerEx, 0);
            }

            pQuest->pfCallback[2] = 0;
        }

        QUESTRECORD_SetQuestState(pQuestFlags, pQuest->nQuestFilter, 0);
        QUESTRECORD_ClearQuestState(pQuestFlags, pQuest->nQuestFilter, 1);
        QUESTRECORD_SetQuestState(pQuestFlags, pQuest->nQuestFilter2, 0xD);
        QUESTRECORD_SetQuestState(pQuestFlags, pQuest->nQuestFilter2, 1);
        QUESTRECORD_ResetIntermediateStateFlags(pQuestFlags, pQuest->nQuestFilter);
        STATLIST_AddUnitStat(pArg->pPlayer, 5, 1, 0);
        QUESTS_AddPlayerGUID((D2QuestGUIDStrc*)pQuest->tPlayerGUIDs, !pArg->pPlayer ? -1 : pArg->pPlayer->dwUnitId);
        QUESTS_NPCActivateSpeeches(pArg->pGame, pArg->pPlayer, pArg->pTarget);
    }
}

// 0x0058FF90
void __fastcall ACT1Q1_Callback00_NpcActivate(D2QuestDataStrc* pQuest, D2QuestArgStrc* pArg)
{
    D2GameStrc* pGame = pQuest->pGame;
    D2UnitStrc* pPlayer = pArg->pPlayer;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, 0);
    const int bPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, 0xD);
    const int nNpcId = !pArg->pTarget ? -1 : pArg->pTarget->dwClassId;
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, 1))
    {
        QUESTS_InitScrollTextChain(pQuest, pArg->pTextControl, nNpcId, 3);
        return;
    }

    if (QUESTS_CheckPlayerGUID(pQuest, !pArg->pPlayer ? -1 : pArg->pPlayer->dwUnitId) == 1)
    {
        QUESTS_InitScrollTextChain(pQuest, pArg->pTextControl, nNpcId, 4);
        return;
    }

    if (bRewardGranted == 1)
    {
        return;
    }

    if ((unsigned char)pQuest->fState >= 4 && !bPrimaryGoalDone)
    {
        return;
    }

    if (!pQuest->bNotIntro)
    {
        return;
    }

    const unsigned int nIndex = gnAct1Quest1NpcIndices[(unsigned char)pQuest->fState];
    if (nIndex != -1 && nIndex < 8)
    {
        QUESTS_InitScrollTextChain(pQuest, pArg->pTextControl, nNpcId, nIndex);
    }
}

#include "gen/data/Source/D2Game/Quests/a1q1.inc"

// 0x005901E0
extern "C" __declspec(dllexport) unsigned int __fastcall sub_005901E0(Obj005901E0* pObj) {
    return pObj->pSub18->dwValue88;
}
