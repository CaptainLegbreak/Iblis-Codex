struct D2GameStrc;
struct D2UnitStrc;

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    unsigned char nActNo;
    unsigned char bNotIntro;
    char unk0x0A[0x0E];
    void* pQuestDataEx;
};

struct D2Act5Quest2Strc
{
    char unk0x00[0x114];
    int unk0x114[3];
};

#define QUEST_A5Q2_RESCUESOLDIERS 32

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
int __fastcall sub_00587FC0_GetWussieGroupIndex(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit);           // 0x00587FC0

// 0x00588830
int __fastcall ACT5Q2_CheckWussieCounters(D2GameStrc* pGame, D2UnitStrc* pWussie)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q2_RESCUESOLDIERS);
    if (!pQuestData || !pQuestData->bNotIntro)
    {
        return 0;
    }

    const int nIndex = sub_00587FC0_GetWussieGroupIndex(pQuestData, pWussie);
    if (nIndex >= 0 && ((D2Act5Quest2Strc*)pQuestData->pQuestDataEx)->unk0x114[nIndex])
    {
        return 1;
    }

    return 0;
}
