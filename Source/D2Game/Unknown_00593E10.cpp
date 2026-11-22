#include "D2Game.h"

#include "D2QuestData.h"
#include "D2UnitData.h"
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640

// 0x00593E10
void __fastcall sub_00593E10_SetQuestCompleteBefore(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 4);
    if (pQuestData)
    {
        ((D2Act1Quest4Strc*)pQuestData->pQuestDataEx)->bQuestCompleteBefore = 1;
    }
}

// 0x00593F60
void __fastcall sub_00593F60_SetUnk52(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 4);
    if (pQuestData)
    {
        ((D2Act1Quest4Strc*)pQuestData->pQuestDataEx)->bCainInTownSpawnPending = 1;
    }
}

// 0x00593F80
int __fastcall sub_00593F80_GetCainNotCreated(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 4);
    if (pQuestData)
    {
        return ((D2Act1Quest4Strc*)pQuestData->pQuestDataEx)->bCainNotCreated;
    }
    sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x99D);
    exit(-1);
}
