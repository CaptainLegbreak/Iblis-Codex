struct D2GameStrc;
struct D2UnitStrc;
typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);
struct D2QuestEx005B8C50Strc
{
    unsigned char unk_0;
    unsigned char nState1;
    unsigned char unk_2[4];
    unsigned char bFlag6;
    unsigned char bFlag7;
};
struct D2QuestDataStrc
{
    unsigned char unk_00[4];
    D2GameStrc* pGame;
    unsigned char f_8[0xC];
    unsigned char bFlag14;
    unsigned char unk_15[3];
    D2QuestEx005B8C50Strc* pQuestDataEx;
};
struct D2QuestTarget005B8C50Strc
{
    unsigned char unk_0[4];
    int nClassId;
};
struct D2QuestArgStrc
{
    unsigned char unk_0[8];
    D2QuestTarget005B8C50Strc* pTarget;
};
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
int __fastcall sub_005B8BF0_UnitIterate(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg); // 0x005B8BF0
int __fastcall sub_005B8B20_UnitIterate(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg); // 0x005B8B20

// 0x005B8C50
void __fastcall sub_005B8C50_QuestCallback(D2QuestDataStrc* pQuest, D2QuestArgStrc* pArg)
{
    const int nClassId = !pArg->pTarget ? -1 : pArg->pTarget->nClassId;
    D2QuestEx005B8C50Strc* pQuestDataEx = pQuest->pQuestDataEx;
    if ((unsigned short)nClassId == 0xFD)
    {
        if (pQuestDataEx->nState1 == 1)
        {
            pQuest->bFlag14 = 0;
            QUESTS_UnitIterate(pQuest, 2, 0, sub_005B8BF0_UnitIterate, 1);
            pQuestDataEx->nState1 = 0;
            SUNIT_IterateUnitsOfType(pQuest->pGame, 0, 0, sub_005B8B20_UnitIterate);
        }
    }
    else if ((unsigned short)nClassId == 0xFF && pQuestDataEx->bFlag7)
    {
        pQuestDataEx->bFlag7 = 0;
        pQuestDataEx->bFlag6 = 1;
    }
}
