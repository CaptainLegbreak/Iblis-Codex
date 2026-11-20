#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2QuestData.h"





D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
void __fastcall sub_005417D0_DirectDated(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam);
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitId);                 // 0x00552F60
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90

// 0x005B9CD0
void __fastcall ACT3Q3_SetAltarMode(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 17);
    if (!pQuestData)
    {
        return;
    }

    D2Act3Quest3Strc* pQuestDataEx = (D2Act3Quest3Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->bAltarCanBeActivated = 0;

    D2UnitStrc* pAltar = SUNIT_GetServerUnit(pGame, 2, pQuestDataEx->nAltarGUID);
    if (!pAltar)
    {
        return;
    }

    UNITS_ChangeAnimMode(pAltar, 1);
    const int nClassId = pAltar->dwClassId;
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nClassId);
    sub_005417D0_DirectDated(pGame, pAltar, 1, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pGame->dwGameFrame + 1, 0, 0);
    pQuestDataEx->nAltarObjectMode = 2;
}
