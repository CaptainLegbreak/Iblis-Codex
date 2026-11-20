#include "D2Game.h"
#include "D2GameStrc.h"

typedef int (__stdcall* FARPROC)();

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    int unk0x10;
    int unk0x14;
    int unk0x18;
};

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuest, D2QuestArgStrc* pArgs);
typedef void (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuest);

struct D2QuestDataStrc
{
    int nQuestNo;
    char unk0x04[0x05];
    unsigned char bNotIntro;
    unsigned char bActive;
    unsigned char fLastState;
    char unk0x0C[0x94];
    QUESTCALLBACK pfCallback[15];
    char unk0xDC[0x14];
    QUESTSEQFILTER pfSeqFilter;
    D2QuestDataStrc* pPrev;
};

struct D2QuestInfoStrc
{
    D2QuestDataStrc* pLastQuest;
    char unk0x04[0x04];
    int bPickedSet;
    D2BitBufferStrc* pQuestFlags;
};


struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2GSPacketSrv5E
{
    unsigned char nHeader;
    unsigned char unk0x001[37];
};

struct D2GSPacketSrv89
{
    unsigned char nHeader;
    unsigned char nEvent;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" void __fastcall __security_check_cookie(unsigned int); // 0x00681A48
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall sub_0053D830_SendPacket0x5E(D2ClientStrc* pClient, D2GSPacketSrv5E* pPacket);               // 0x0053D830
void __fastcall D2GAME_SendPacket0x28_6FC3F2F0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char a3, int a4, D2BitBufferStrc* a5, unsigned char a6); // 0x0053D670
void __fastcall QUESTS_SendCurrentFlags(D2GameStrc* pGame, D2ClientStrc* pClient);                          // 0x00544520
void __fastcall sub_0053DFE0_SendPacket0x89(D2ClientStrc* pClient, D2GSPacketSrv89* pPacket);               // 0x0053DFE0
extern "C" const char gszQuestsSourceFile[];                                                                // 0x006E0BE4
extern D2QuestInitTableStrc sgQuestInit[];                                                    // 0x00731510

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId)
{
    D2QuestInfoStrc* pQuestControl = pGame->pQuestControl;
    D2_ASSERT(nId >= 0, 119);
    if (pQuestControl)
    {
        for (D2QuestDataStrc* pQuestData = pQuestControl->pLastQuest; pQuestData; pQuestData = pQuestData->pPrev)
        {
            if (pQuestData->nQuestNo == nId)
            {
                return pQuestData;
            }
        }
    }
    return 0;
}

void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    D2GAME_SendPacket0x28_6FC3F2F0(UnitGetClient(pUnit, gszQuestsSourceFile, 0xCA7), 0x28, 6, 0, pQuestFlags, 0);
}

// 0x00544410
static void sub_00544410_ClearQuestIntroState(D2GameStrc* pGame, int nChainNo)
{
    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pGame, nChainNo);
    D2_ASSERT(pQuest, 0x5F3);
    pQuest->bNotIntro = 0;
    pQuest->bActive = 0;
    pQuest->fLastState = 0;
}

// 0x00546270
void __fastcall QUESTS_SequenceCycler(D2GameStrc* pGame, D2UnitStrc* pPlayer, int bGameEnter)
{
    D2QuestInfoStrc* pQuestControl = pGame->pQuestControl;
    if (!pQuestControl->bPickedSet)
    {
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        int anActQuests[5];
        memset(anActQuests, 0, sizeof(anActQuests));
        pQuestControl->bPickedSet = 1;
        if (!bGameEnter)
        {
            if (byte_0073150C)
            {
                for (int i = 0; i < gnQuestInitTableCount_00731888; ++i)
                {
                    D2QuestInitTableStrc* pQuestInit = &sgQuestInit[i];
                    D2_ASSERT(pQuestInit->nAct < 5, 0x637);
                    if (!pQuestInit->bNoSetState
                        && (QUESTRECORD_GetQuestState(pQuestFlags, pQuestInit->nQuestNo, 0)
                            || QUESTRECORD_GetQuestState(pQuestFlags, pQuestInit->nQuestNo, 15)))
                    {
                        sub_00544410_ClearQuestIntroState(pGame, pQuestInit->nChainNo);
                        ++anActQuests[pQuestInit->nAct];
                        QUESTRECORD_SetQuestState(pQuestControl->pQuestFlags, sgQuestInit[i].nQuestNo, 15);
                    }
                }
            }
            for (D2QuestDataStrc* pQuest = pQuestControl->pLastQuest; pQuest; pQuest = pQuest->pPrev)
            {
                if (pQuest->pfCallback[13])
                {
                    D2_ASSERT(!IsBadCodePtr((FARPROC)pQuest->pfCallback[13]), 0x640);
                    D2QuestArgStrc pArgs;
                    pArgs.pGame = pGame;
                    pArgs.pPlayer = pPlayer;
                    pArgs.nEvent = 13;
                    pQuest->pfCallback[13](pQuest, &pArgs);
                }
            }
        }
        D2QuestDataStrc* pQuestSeq0 = QUESTS_GetQuestData(pGame, 1);
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestSeq0->pfSeqFilter), 0x64D);
        pQuestSeq0->pfSeqFilter(pQuestSeq0);
        D2QuestDataStrc* pQuestSeq1 = QUESTS_GetQuestData(pGame, 8);
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestSeq1->pfSeqFilter), 0x650);
        pQuestSeq1->pfSeqFilter(pQuestSeq1);
        D2QuestDataStrc* pQuestSeq2 = QUESTS_GetQuestData(pGame, 18);
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestSeq2->pfSeqFilter), 0x653);
        pQuestSeq2->pfSeqFilter(pQuestSeq2);
        D2QuestDataStrc* pQuestSeq3 = QUESTS_GetQuestData(pGame, 22);
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestSeq3->pfSeqFilter), 0x656);
        pQuestSeq3->pfSeqFilter(pQuestSeq3);
        D2QuestDataStrc* pQuestSeq4 = QUESTS_GetQuestData(pGame, 31);
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestSeq4->pfSeqFilter), 0x65A);
        pQuestSeq4->pfSeqFilter(pQuestSeq4);
    }
    else
    {
        for (D2QuestDataStrc* pQuest = pQuestControl->pLastQuest; pQuest; pQuest = pQuest->pPrev)
        {
            if (pQuest->pfCallback[14])
            {
                D2_ASSERT(!IsBadCodePtr((FARPROC)pQuest->pfCallback[14]), 0x666);
                D2QuestArgStrc pArgs;
                pArgs.pGame = pGame;
                pArgs.nEvent = 14;
                pArgs.pPlayer = pPlayer;
                pQuest->pfCallback[14](pQuest, &pArgs);
            }
        }
    }

    D2GSPacketSrv5E packet5E;
    packet5E.nHeader = 0x5E;
    for (int i = 0; i < gnQuestInitTableCount_00731888; ++i)
    {
        D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pGame, sgQuestInit[i].nChainNo);
        D2_ASSERT(pQuest, 0x67C);
        packet5E.unk0x001[i] = pQuest->bNotIntro;
    }

    D2ClientStrc* pClient = UnitGetClient(pPlayer, gszQuestsSourceFile, 0x681);
    sub_0053D830_SendPacket0x5E(pClient, &packet5E);
    QUESTS_UpdatePlayerFlags(pGame, pPlayer);
    QUESTS_SendCurrentFlags(pGame, pClient);

    D2QuestDataStrc* pQuestData1 = QUESTS_GetQuestData(pGame, 1);
    if (pQuestData1 && ACT1Q1_CanClientFXBeTriggered(pQuestData1))
    {
        D2GSPacketSrv89 packet89;
        packet89.nHeader = 0x89;
        packet89.nEvent = 0;
        sub_0053DFE0_SendPacket0x89(pClient, &packet89);
    }
}

#include "gen/data/Source/D2Game/Quests/QUESTS_00546270.inc"
