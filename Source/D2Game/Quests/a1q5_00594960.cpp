#include "D2Structs.h"
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

typedef int(__stdcall* FARPROC)();

struct D2BitBufferStrc;

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


struct D2QuestDataStrc;
typedef int(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);
typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    char unk0x08;
    unsigned char bNotIntro;
    char unk0x0A;
    unsigned char fLastState;
    unsigned char fState;
    char unk0x0D[7];
    unsigned char nFlagsLowByte;
    char unk0x15[3];
    void* pQuestDataEx;
    char unk0x1C[0xD4];
    QUESTSEQFILTER pfSeqFilter;
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int unk0x04[2];
    D2UnitStrc* pPlayer;
    int unk0x10;
    unsigned short nNPCNo;
    unsigned short unk0x16;
    unsigned short nMessageIndex;
};

struct D2Act1Quest5Strc
{
    int nAcknowledgedGUIDs[12];
    unsigned short nAcknowledgedCount;
    unsigned short pad0x32;
    int nPendingGUIDs[12];
    unsigned short nPendingDialoguePlayerCount;
    char unk0x66[0xB4];
    unsigned char bTriggerSeqFilter;
    unsigned char bTowerTomeActivated;
};

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);  // 0x00544350
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
int __fastcall ACT1Q5_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x00594830
int __fastcall ACT1Q5_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00594890

static int ACT1Q5_RemovePendingGUID_Inl(D2Act1Quest5Strc* pQuestDataEx, int nUnitGUID)
{
    for (int i = 0; i < pQuestDataEx->nPendingDialoguePlayerCount; ++i)
    {
        if (pQuestDataEx->nPendingGUIDs[i] == nUnitGUID)
        {
            if (i != pQuestDataEx->nPendingDialoguePlayerCount - 1)
            {
                pQuestDataEx->nPendingGUIDs[i] = pQuestDataEx->nPendingGUIDs[pQuestDataEx->nPendingDialoguePlayerCount - 1];
            }
            --pQuestDataEx->nPendingDialoguePlayerCount;
            return 1;
        }
    }

    return 0;
}

// 0x00594960
void __fastcall ACT1Q5_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const unsigned short nNpcId = pQuestArg->nNPCNo;
    const unsigned short nMsgId = pQuestArg->nMessageIndex;

    D2Act1Quest5Strc* pQuestDataEx = (D2Act1Quest5Strc*)pQuestData->pQuestDataEx;

    if (nMsgId == 127 && pQuestData->bNotIntro)
    {
        bool bUpdateQuestStateFlags = false;
        if (pQuestDataEx->bTowerTomeActivated == 1)
        {
            if (pQuestData->fLastState < 1)
            {
                bUpdateQuestStateFlags = true;
                pQuestData->nFlagsLowByte = 0;
                QUESTS_UnitIterate(pQuestData, 1, 0, ACT1Q5_UnitIterate_StatusCyclerEx, 1);
            }

            if (pQuestData->fLastState == 3)
            {
                bUpdateQuestStateFlags = true;
                pQuestData->nFlagsLowByte = 0;
                QUESTS_UnitIterate(pQuestData, 2, 0, ACT1Q5_UnitIterate_StatusCyclerEx, 1);
                if (pQuestData->fState < 3)
                {
                    QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q5.cpp", 0x129);
                }
            }
        }

        if (pQuestData->fState < 2)
        {
            QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q5.cpp", 0x130);
            bUpdateQuestStateFlags = true;
        }

        if (bUpdateQuestStateFlags)
        {
            SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT1Q5_UnitIterate_UpdateQuestStateFlags);
        }
    }

    if ((nNpcId == 0x9A || nNpcId == 0x96 || nNpcId == 0x109 || nNpcId == 0x9B || nNpcId == 0x94 || nNpcId == 0x93)
        && (nMsgId == 0x90 || nMsgId == 0x8C || nMsgId == 0x91 || nMsgId == 0x8D || nMsgId == 0x8F || nMsgId == 0x8E))
    {
        D2UnitStrc* pPlayer = pQuestArg->pPlayer;
        D2GameStrc* pGame = pQuestArg->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        if (QUESTRECORD_GetQuestState(pQuestFlags, 5, 0xD) && pQuestDataEx->bTriggerSeqFilter)
        {
            pQuestDataEx->bTriggerSeqFilter = 0;
            QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q5.cpp", 0x14C);
            D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 0x14D);
            pQuestData->pfSeqFilter(pQuestData);
        }

        const int nUnitId = !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId;

        for (int i = 0; i < pQuestDataEx->nPendingDialoguePlayerCount; ++i)
        {
            if (pQuestDataEx->nPendingGUIDs[i] == nUnitId)
            {
                if (ACT1Q5_RemovePendingGUID_Inl(pQuestDataEx, nUnitId) && pQuestDataEx->nAcknowledgedCount < 12)
                {
                    pQuestDataEx->nAcknowledgedGUIDs[pQuestDataEx->nAcknowledgedCount] = nUnitId;
                    ++pQuestDataEx->nAcknowledgedCount;
                }
                break;
            }
        }
    }
}
