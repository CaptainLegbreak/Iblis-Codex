#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"

struct D2QuestChainStrc;

typedef int (__stdcall* FARPROC)();
typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuest, D2QuestArgStrc* pArgs);




struct D2QuestChainStrc
{
    D2QuestDataStrc* pQuestData;
    D2QuestChainStrc* pNext;
};

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

struct D2SuperUniquesTxt
{
    char unk0x00[0x08];
    int dwHcIdx;
    char unk0x0C[0x28];
};


extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath);                 // 0x00537860
void __fastcall AIGENERAL_GetOwnerData(D2UnitStrc* pUnit, int* pOwnerGUID, int* pOwnerType);                // 0x0058F090
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag);                                // 0x005A0180
short __fastcall MONSTERUNIQUE_GetBossHcIdx(D2UnitStrc* pUnit);                                             // 0x005A01E0

// build: symbol ?QUESTS_StatusCycler@@YGX_NPAUD2QuestArgStrc@@@Z 0x005439A0
static void __stdcall QUESTS_StatusCycler(bool bForceActive, D2QuestArgStrc* pArgs)
{
    for (D2QuestChainStrc* i = pArgs->pTarget->pQuestEventList; i; i = i->pNext)
    {
        if (i->pQuestData->pCallback[pArgs->nEvent] && (i->pQuestData->bActive == 1 || bForceActive))
        {
            D2_ASSERT(!IsBadCodePtr((FARPROC)i->pQuestData->pCallback[pArgs->nEvent]), 0x23E);
            i->pQuestData->pCallback[pArgs->nEvent](i->pQuestData, pArgs);
        }
    }
}

static __forceinline int DATATBLS_GetSuperUniqueHcIdx_Inline(int nSuperUniqueId)
{
    if (nSuperUniqueId >= 0 && nSuperUniqueId < sgptDataTables->nSuperUniquesTxtRecordCount)
    {
        return sgptDataTables->pSuperUniquesTxt[nSuperUniqueId].dwHcIdx;
    }
    return -1;
}

// 0x00543A30
void __fastcall QUESTS_ParseKill(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker)
{
    if (!pDefender->pQuestEventList)
    {
        return;
    }
    if (pGame->nGameType == 3 && !pAttacker)
    {
        D2ClientStrc* pClient = sub_00539070_GetClientList(pGame);
        if (pClient)
        {
            pAttacker = CLIENTS_GetPlayerFromClient(pClient, 0);
        }
    }
    D2QuestArgStrc pArgs;
    pArgs.pGame = pGame;
    pArgs.nEvent = 8;
    pArgs.pTarget = pDefender;
    if (pAttacker && pAttacker->dwUnitType == 0)
    {
        pArgs.pPlayer = pAttacker;
    }
    else
    {
        pArgs.pPlayer = 0;
        if (pAttacker && pAttacker->dwUnitType == 1)
        {
            int nOwnerType;
            int nOwnerId;
            AIGENERAL_GetOwnerData(pAttacker, &nOwnerId, &nOwnerType);
            if (nOwnerType == 0)
            {
                pArgs.pPlayer = SUNIT_GetServerUnit(pGame, 0, nOwnerId);
            }
        }
    }
    bool bForceActive = 0;
    if (MONSTERUNIQUE_CheckMonTypeFlag(pDefender, 2))
    {
        const int nSuperUniqueId = MONSTERUNIQUE_GetBossHcIdx(pDefender);
        switch (DATATBLS_GetSuperUniqueHcIdx_Inline(nSuperUniqueId))
        {
        case 26:
        case 27:
        case 29:
        case 36:
        case 37:
        case 38:
        case 39:
        case 42:
        case 43:
        case 44:
        case 45:
        case 60:
            bForceActive = 1;
            break;
        }
    }
    switch ((unsigned int)pDefender->dwClassId)
    {
    case 0xF2:
    case 0xF3:
    case 0x187:
    case 0x220:
        bForceActive = 1;
        break;
    }
    QUESTS_StatusCycler(bForceActive, &pArgs);
}

void __fastcall sub_00543CE0_QuestStatusEvent0(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTarget)
{
    D2QuestArgStrc pArgs;
    pArgs.pGame = pGame;
    pArgs.nEvent = 0;
    pArgs.pTarget = pTarget;
    pArgs.pPlayer = pPlayer;
    QUESTS_StatusCycler(0, &pArgs);
}

void __fastcall QUESTS_ItemPickedUp(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem)
{
    D2QuestArgStrc pArgs;
    pArgs.pGame = pGame;
    pArgs.nEvent = 4;
    pArgs.pTarget = pItem;
    pArgs.pPlayer = pPlayer;
    QUESTS_StatusCycler(0, &pArgs);
}

void __fastcall QUESTS_ItemDropped(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem)
{
    D2QuestArgStrc pArgs;
    pArgs.pGame = pGame;
    pArgs.nEvent = 5;
    pArgs.pTarget = pItem;
    pArgs.pPlayer = pPlayer;
    QUESTS_StatusCycler(0, &pArgs);
}

void __fastcall sub_00543DE0_QuestStatusEvent6(D2GameStrc* pGame, D2UnitStrc* pTarget)
{
    D2QuestArgStrc pArgs;
    pArgs.pGame = pGame;
    pArgs.nEvent = 6;
    pArgs.pTarget = pTarget;
    pArgs.pPlayer = 0;
    QUESTS_StatusCycler(0, &pArgs);
}
