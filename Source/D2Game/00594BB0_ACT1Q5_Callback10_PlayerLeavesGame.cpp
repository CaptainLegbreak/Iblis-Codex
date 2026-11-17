struct D2UnitStrc { int dwUnitType; int dwClassId; void* pMemoryPool; int dwUnitId; };
struct D2QuestGUIDStrc { int nPlayerGUIDs[32]; short nPlayerCount; unsigned short unk_82; };
struct D2Act1Quest5Strc {
    int nUnitGUIDs1[12]; unsigned short nUnitCount1; unsigned short unk_32;
    int nUnitGUIDs2[12]; unsigned short nUnitCount2; unsigned short unk_66;
    int nObjectGUIDs[8]; unsigned short nObjectCount; unsigned short unk_8A;
    D2QuestGUIDStrc tPlayerGUIDs;
};
struct D2QuestDataStrc { char unk_00[0x18]; D2Act1Quest5Strc* pQuestDataEx; };
struct D2QuestArgStrc { void* pGame; int nEvent; D2UnitStrc* pTarget; D2UnitStrc* pPlayer; };
int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID); // 0x00545240

// 0x00594BB0
void __fastcall ACT1Q5_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nGUID = !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId;
    D2Act1Quest5Strc* pEx = pQuestData->pQuestDataEx;
    QUESTS_FastRemovePlayerGUID(&pEx->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
    for (int i = 0; i < pEx->nUnitCount2; ++i)
    {
        if (pEx->nUnitGUIDs2[i] == nGUID)
        {
            if (i != pEx->nUnitCount2 - 1)
                pEx->nUnitGUIDs2[i] = pEx->nUnitGUIDs2[pEx->nUnitCount2 - 1];
            --pEx->nUnitCount2;
            break;
        }
    }
    for (int i = 0; i < pEx->nUnitCount1; ++i)
    {
        if (pEx->nUnitGUIDs1[i] == nGUID)
        {
            if (i != pEx->nUnitCount1 - 1)
                pEx->nUnitGUIDs1[i] = pEx->nUnitGUIDs1[pEx->nUnitCount1 - 1];
            --pEx->nUnitCount1;
            break;
        }
    }
}
