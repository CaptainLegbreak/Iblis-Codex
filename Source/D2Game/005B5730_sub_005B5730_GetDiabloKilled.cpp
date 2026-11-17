struct D2GameStrc;
struct D2Act4Quest2Strc { char unknown[0x14]; unsigned char bDiabloKilled; };
struct D2QuestDataStrc { char unknown[0x18]; D2Act4Quest2Strc* pQuestDataEx; };
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc*, int); // 0x00543640
// 0x005B5730
unsigned char __fastcall sub_005B5730_GetDiabloKilled(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 23);
    if (pQuestData) return pQuestData->pQuestDataEx->bDiabloKilled;
    return 0;
}
