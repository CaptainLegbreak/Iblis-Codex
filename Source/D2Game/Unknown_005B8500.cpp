#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#define UNIT_OBJECT 2
#define OBJMODE_OPENED 2
#define EVENTTYPE_ENDANIM 1
#define QUEST_A3Q3_GIDBINN 17
#define QFLAG_REWARDGRANTED 0
#define QFLAG_PRIMARYGOALDONE 13
#define QFLAG_COMPLETEDNOW 14
#define QFLAG_COMPLETEDBEFORE 15
struct D2Act3Quest2Strc;
union D2SeedStrc;
struct D2PlayerDataStrc;

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);



struct D2Act3Quest2Strc
{
    unsigned char bSewerStairsInitialized;
    unsigned char bInitiallyTalkedToCain;
    unsigned char pad0x02[2];
    int nSewerStairsObjectGUID;
    int nSewerStairsObjectMode;
    int nItemDropCount;
    int nEyesDropped;
    int nBrainsDropped;
    int nHeartsDropped;
    int nFlailsDropped;
    int nCubedFlails;
    unsigned char bEyeDropped;
    unsigned char bBrainDropped;
    unsigned char bHeartDropped;
    unsigned char bFlailDropped;
};


D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640


D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode); // 0x00558110


void __fastcall sub_005417D0_DirectDated(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam);
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitId); // 0x00552F60
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90



void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310

// 0x005B8500
int __fastcall sub_005B8500_IsSewerStairsClosed(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A3Q2_KHALIMFLAIL);
    if (pQuestData && pQuestData->bNotIntro)
        return ((D2Act3Quest2Strc*)pQuestData->pQuestDataEx)->nSewerStairsObjectMode != 2;
    return 0;
}

// 0x005B8750
int __fastcall sub_005B8750_LacksKhalimFlail(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return ITEMS_FindQuestItem(pGame, pUnit, ' 2fq') == 0;
}

// 0x005B8B00
void __fastcall sub_005B8B00_AddFlailsDropped(D2GameStrc* pGame, int nCount)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A3Q2_KHALIMFLAIL);
    if (pQuestData)
    {
        D2Act3Quest2Strc* pQuestDataEx = (D2Act3Quest2Strc*)pQuestData->pQuestDataEx;
        pQuestDataEx->nFlailsDropped += nCount;
        pQuestDataEx->bFlailDropped = 1;
    }
}

// 0x005B85E0
void __fastcall sub_005B85E0_OpenSewerStairs(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    D2Act3Quest2Strc* pQuestDataEx = (D2Act3Quest2Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bSewerStairsInitialized == 1)
    {
        D2UnitStrc* pFoundUnit = SUNIT_GetServerUnit(pQuestData->pGame, UNIT_OBJECT, pQuestDataEx->nSewerStairsObjectGUID);
        if (!pFoundUnit)
        {
            pQuestDataEx->nSewerStairsObjectMode = OBJMODE_OPENED;
            return;
        }

        UNITS_ChangeAnimMode(pFoundUnit, pQuestDataEx->nSewerStairsObjectMode);
        if (pQuestDataEx->nSewerStairsObjectMode != OBJMODE_OPENED)
        {
            pQuestDataEx->nSewerStairsObjectMode = OBJMODE_OPENED;
            const int nClassId = pFoundUnit->dwClassId;
            D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nClassId);
            sub_005417D0_DirectDated(pQuestData->pGame, pFoundUnit, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pQuestData->pGame->dwGameFrame, 0, 0);
        }
    }
}

// 0x005B8BF0
int __fastcall ACT3Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, QFLAG_COMPLETEDBEFORE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, QFLAG_PRIMARYGOALDONE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, QFLAG_COMPLETEDNOW))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, QUEST_A3Q3_GIDBINN);
    }

    return 0;
}
