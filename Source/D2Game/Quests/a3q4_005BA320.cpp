#include "D2Game.h"
#include "D2Structs.h"

typedef int (__stdcall* FARPROC)();

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};


struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2QuestGUIDStrc
{
    char unk0x00[0x84];
};
typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
typedef bool (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuest);
typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

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
    D2QuestGUIDStrc tPlayerGUIDs;
    QUESTCALLBACK pfCallback[15];
    void* pNPCMessages;
    int nQuestFilter;
    int unk0xE4;
    void* pfStatusFilter;
    void* pfActiveFilter;
    QUESTSEQFILTER pfSeqFilter;
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    unsigned int unk0x10;
    unsigned short nNPCNo;
    unsigned short unk0x16;
    unsigned short nMessageIndex;
};

struct D2Act3Quest4Strc
{
    unsigned char bGoldenBirdBroughtToAlkor;
    unsigned char unk0x01;
    unsigned char unk0x02;
    char unk0x03[0x05];
    unsigned char bTalkedToAlkor;
    unsigned char bTalkedToCainOnce;
    unsigned char bTalkedToCainTwice;
    unsigned char bTalkedToMeshif;
    unsigned char unk0x0C;
    char unk0x0D[0x03];
    int nGoldenBirdsInGame;
    unsigned char bJadeFigurineDropped;
    unsigned char bPlayerDroppedWithItem;
    char unk0x16[0x02];
    int nCurrentQuestFlag;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C

void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);  // 0x00544350
void __fastcall QUESTS_DeleteItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, int dwCode);                      // 0x00544160
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                         // 0x00544720
void __fastcall QUESTS_AddPlayerGUID(D2QuestGUIDStrc* pQuestGUID, int dwGUID);                              // 0x00545200
void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit);                             // 0x005455B0
void __fastcall QUESTS_NPCActivateSpeeches(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTarget);    // 0x00545780
int __fastcall QUESTS_CreateItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned int dwCode, int nLevel, int nQuality, int bDroppable); // 0x005466B0
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer);                                                     // 0x00554630
void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, QUESTUNITITERATE pfnCallback, void* pArgs); // 0x00540510
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode);  // 0x00558110
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360
void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);         // 0x0065C3A0
void __stdcall QUESTRECORD_ResetIntermediateStateFlags(D2BitBufferStrc* pQuestRecord, int nQuest);          // 0x0065C3E0
void __fastcall ACT3Q4_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);    // 0x005BA0B0

static __forceinline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

static __forceinline int ACT3Q4_UpdatePartyQuestStateInline(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    const unsigned short nPartyId = SUNIT_GetPartyId(pPlayer);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT3Q4_UnitIterate_UpdateCurrentQuestState, 0);
    }
    return 0;
}

__declspec(noinline) static int __stdcall sub_005BA2F0_UpdatePartyQuestState(D2GameStrc* pGame, D2UnitStrc* pPlayer);
// 0x005BA2F0
static int __stdcall sub_005BA2F0_UpdatePartyQuestState(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    const unsigned short nPartyId = SUNIT_GetPartyId(pPlayer);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT3Q4_UnitIterate_UpdateCurrentQuestState, 0);
    }
    return 0;
}

// 0x005BA320
void __fastcall ACT3Q4_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const unsigned short nNpcId = pQuestArg->nNPCNo;
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;
    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestArg->pGame, pQuestArg->pPlayer);
    if (QUESTRECORD_GetQuestState(pQuestFlags, 20, 0) == 1)
    {
        return;
    }

    D2Act3Quest4Strc* pQuestDataEx = (D2Act3Quest4Strc*)pQuestData->pQuestDataEx;
    if (nNpcId == 245)
    {
        if (nMessageIndex == 527)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 20, 2);
            if (pQuestData->fState == 1)
            {
                QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q4.cpp", 478);
                pQuestDataEx->bTalkedToCainOnce = 1;
                pQuestData->pfCallback[2] = ACT3Q4_Callback02_NpcDeactivate;
            }
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
            pQuestDataEx->nCurrentQuestFlag = 2;
            ACT3Q4_UpdatePartyQuestStateInline(pQuestArg->pGame, pQuestArg->pPlayer);
        }
        else if (nMessageIndex == 531)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 20, 4);
            pQuestDataEx->bTalkedToCainTwice = 1;
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
            pQuestDataEx->nCurrentQuestFlag = 4;
            sub_005BA2F0_UpdatePartyQuestState(pQuestArg->pGame, pQuestArg->pPlayer);
        }
    }
    else if (nNpcId == 254)
    {
        if (nMessageIndex == 534)
        {
            if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 43g')
                && !QUESTRECORD_GetQuestState(pQuestFlags, 20, 1)
                && !QUESTRECORD_GetQuestState(pQuestFlags, 20, 0))
            {
                QUESTS_DeleteItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 43g');
                --pQuestDataEx->nGoldenBirdsInGame;
                if (pQuestData->bNotIntro && pQuestData->fState != 4)
                {
                    QUESTS_StateDebug(pQuestData, 4, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q4.cpp", 509);
                }

                QUESTRECORD_SetQuestState(pQuestFlags, 20, 1);
                pQuestDataEx->bTalkedToAlkor = 1;
                pQuestData->pfCallback[2] = ACT3Q4_Callback02_NpcDeactivate;
                pQuestDataEx->nCurrentQuestFlag = 1;
                sub_005BA2F0_UpdatePartyQuestState(pQuestArg->pGame, pQuestArg->pPlayer);
            }
        }
        else if (nMessageIndex == 538)
        {
            if (!QUESTRECORD_GetQuestState(pQuestFlags, 20, 0))
            {
                if (QUESTRECORD_GetQuestState(pQuestFlags, 20, 1))
                {
                    QUESTRECORD_ClearQuestState(pQuestFlags, 20, 1);
                    QUESTRECORD_SetQuestState(pQuestFlags, 20, 0);
                    QUESTRECORD_SetQuestState(pQuestFlags, 20, 13);
                    QUESTRECORD_ResetIntermediateStateFlags(pQuestFlags, pQuestData->nQuestFilter);
                    QUESTRECORD_SetQuestState(pQuestFlags, 20, 5);
                    if (pQuestData->bNotIntro)
                    {
                        QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q4.cpp", 536);
                    }

                    QUESTS_CreateItem(pQuestArg->pGame, pQuestArg->pPlayer, ' zyx', 0, 2, 1);
                    QUESTS_UpdatePlayerFlags(pQuestArg->pGame, pQuestArg->pPlayer);
                    QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, (!pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId));
                }

                if (QUESTRECORD_GetQuestState(pQuestFlags, 20, 13))
                {
                    QUESTS_SetGlobalState(pQuestArg->pGame, 20, 13);
                    D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 545);
                    pQuestData->pfSeqFilter(pQuestData);
                }
            }
        }
    }
    else if (nNpcId == 264)
    {
        if (nMessageIndex == 529)
        {
            if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 43j'))
            {
                pQuestData->pfCallback[2] = ACT3Q4_Callback02_NpcDeactivate;
                QUESTS_DeleteItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 43j');
                --pQuestDataEx->nGoldenBirdsInGame;
                if (QUESTS_CreateItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 43g', 0, 2, 1))
                {
                    ++pQuestDataEx->nGoldenBirdsInGame;
                    QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q4.cpp", 566);
                    pQuestDataEx->bTalkedToMeshif = 1;
                    pQuestData->pfCallback[2] = ACT3Q4_Callback02_NpcDeactivate;
                }
            }
        }
    }
}
