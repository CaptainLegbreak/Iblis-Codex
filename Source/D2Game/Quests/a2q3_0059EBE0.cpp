#include "D2Game.h"
#include "D2Structs.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

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


struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    unsigned int unk0x10;
    int nNPCNo;
    unsigned short nMessageIndex;
};

struct D2QuestGUIDStrc
{
    unsigned int nPlayerGUIDs[32];
    unsigned short nPlayerCount;
    unsigned char pad0x82[2];
};
typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
typedef bool (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);
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
    unsigned char bStatusFlags;
    unsigned char pad0x15[3];
    void* pQuestDataEx;
    D2QuestGUIDStrc tPlayerGUIDs;
    QUESTCALLBACK pfCallback[15];
    void* pNPCMessages;
    int nQuestFilter;
    char unk0xE4[0x04];
    void* pfStatusFilter;
    void* pfActiveFilter;
    QUESTSEQFILTER pfSeqFilter;
};

enum
{
    QUESTSTATEFLAG_A2Q3 = 11,
};

typedef int (__stdcall* FARPROC)();
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                 // 0x006CC34C
extern "C" const char szA2Q3Cpp_006E1FB0[];                                                                 // 0x006E1FB0
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);  // 0x00544350
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                         // 0x00544720
void __fastcall QUESTS_AddPlayerGUID(D2QuestGUIDStrc* pQuestGUID, int dwGUID);                              // 0x00545200
void __fastcall QUESTS_NPCActivateSpeeches(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTarget);    // 0x00545780
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360
void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);         // 0x0065C3A0
int __fastcall ACT2Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x00599F50
int __fastcall ACT2Q3_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059A4F0

// 0x0059EBE0
void __fastcall ACT2Q3_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    int bScrollRead = 0;
    switch (pQuestArg->nMessageIndex)
    {
    case 348:
        if (pQuestData->bNotIntro && pQuestArg->nNPCNo == 0xB1)
        {
            if (pQuestData->fLastState == 1)
            {
                pQuestData->bStatusFlags = 0;
                QUESTS_UnitIterate(pQuestData, 2, 0, ACT2Q3_UnitIterate_StatusCyclerEx, 0);
            }

            if (pQuestData->fState == 1)
            {
                QUESTS_StateDebug(pQuestData, 2, szA2Q3Cpp_006E1FB0, 0xCD);
                SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT2Q3_UnitIterate_UpdateQuestStateFlags);
            }
        }
        break;

    case 362:
    case 363:
    case 364:
    case 365:
    case 366:
    case 367:
    case 368:
    case 369:
    case 370:
    case 371:
    case 372:
        bScrollRead = 1;
        break;
    }

    if (bScrollRead)
    {
        D2GameStrc* pGame = pQuestArg->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
        if (pQuestData->fState != 5 && pQuestData->bNotIntro == 1 && QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 13))
        {
            pQuestData->bStatusFlags = 0;
            QUESTS_UnitIterate(pQuestData, 13, 0, ACT2Q3_UnitIterate_StatusCyclerEx, 0);
            QUESTS_StateDebug(pQuestData, 5, szA2Q3Cpp_006E1FB0, 0xDC);
            if (IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter))
            {
                sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0xDD);
                exit(-1);
            }
            pQuestData->pfSeqFilter(pQuestData);
        }

        QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 1))
        {
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, 0);
            QUESTRECORD_ClearQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, 1);
            QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
            if (!pQuestData->bNotIntro)
            {
                QUESTS_SetGlobalState(pQuestData->pGame, QUESTSTATEFLAG_A2Q3, 13);
            }
        }
    }
}
