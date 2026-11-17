#include "D2Game.h"

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);
struct D2Act4Q3Strc
{
    unsigned char unk_00[2];
    unsigned char nState2;
    unsigned char unk_03[0x19];
    unsigned char bFlag1C;
};
struct D2QuestDataStrc
{
    unsigned char unk_00[4];
    D2GameStrc* pGame;
    unsigned char f_8[0xC];
    unsigned char bFlag14;
    unsigned char unk_15[3];
    D2Act4Q3Strc* pQuestDataEx;
    unsigned char unk_1C[0x8C];
    int nA8;
};
struct D2QuestTarget005B6440Strc
{
    unsigned char unk_0[4];
    unsigned short nClassId;
};
struct D2QuestArgStrc
{
    unsigned char unk_0[8];
    D2QuestTarget005B6440Strc* pTarget;
};
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
int __fastcall ACT4Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg); // 0x005B59C0
int __fastcall ACT4Q3_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg); // 0x005B5FC0

// 0x005B6440
void __fastcall sub_005B6440_ACT4Q3_Callback(D2QuestDataStrc* pQuest, D2QuestArgStrc* pArg)
{
    D2QuestTarget005B6440Strc* pTarget = pArg->pTarget;
    if (!pTarget || pTarget->nClassId != 0xF6)
    {
        return;
    }
    D2Act4Q3Strc* pQuestDataEx = pQuest->pQuestDataEx;
    if (pQuestDataEx->nState2 != 1)
    {
        return;
    }
    if (pQuestDataEx->bFlag1C)
    {
        QUESTS_UnitIterate(pQuest, 4, 0, ACT4Q3_UnitIterate_StatusCyclerEx, 1);
    }
    else
    {
        QUESTS_UnitIterate(pQuest, 1, 0, ACT4Q3_UnitIterate_StatusCyclerEx, 1);
    }
    pQuest->bFlag14 = 0;
    pQuestDataEx->nState2 = 0;
    pQuest->nA8 = 0;
    SUNIT_IterateUnitsOfType(pQuest->pGame, 0, 0, ACT4Q3_UnitIterate_UpdateQuestStateFlags);
}
