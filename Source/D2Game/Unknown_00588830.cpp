#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2Drlg.h"
#include "D2QuestData.h"
struct D2Act5Quest2Strc;
struct D2PlayerDataStrc;
struct D2ObjInitFnStrc;
struct D2QuestGUIDStrc;


typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

typedef bool (__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

typedef bool (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);




D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640


int __fastcall ACT5Q2_GetWussieGroupIndex(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x00587FC0

typedef int (__stdcall* FARPROC)();





typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int nCustomId, int nCustomParam); // 0x005417D0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360

// 0x00588CA0
void __fastcall ACT5Q2_UpdatePortalMode(D2QuestDataStrc* pQuestData, D2UnitStrc* pPortal)
{
    const int nUnitGUID = !pPortal ? -1 : pPortal->dwUnitId;
    int nCounter = 0;
    do
    {
        if (nUnitGUID == ((D2Act5Quest2Strc*)pQuestData->pQuestDataEx)->nPortalGUIDs[nCounter])
        {
            goto found;
        }
        ++nCounter;
    }
    while (nCounter < 3);
    return;

found:
    D2Act5Quest2Strc* pQuestDataEx = (D2Act5Quest2Strc*)pQuestData->pQuestDataEx;
    switch (!pPortal ? 0 : pPortal->dwAnimMode)
    {
    case 1:
        UNITS_ChangeAnimMode(pPortal, 2);
        break;

    case 2:
        if (pQuestDataEx->bGroupDone[nCounter] == 1)
        {
            ++pQuestDataEx->nPortalUpdateInvocations[nCounter];
        }
        if (pQuestDataEx->nPortalUpdateInvocations[nCounter] > 5)
        {
            pQuestDataEx->bChangeToSpecialObjectMode[nCounter] = 1;
        }
        if (pQuestDataEx->bChangeToSpecialObjectMode[nCounter])
        {
            UNITS_ChangeAnimMode(pPortal, 3);
        }
        break;

    case 3:
        UNITS_ChangeAnimMode(pPortal, 4);
        break;
    }

    EVENT_SetEvent(pQuestData->pGame, pPortal, 7, pQuestData->pGame->dwGameFrame + 25, 0, 0);
}

int __fastcall ACT5Q3_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00588F10