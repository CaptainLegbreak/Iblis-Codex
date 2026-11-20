#include "D2Game.h"
#include "D2Structs.h"

struct D2Act1Quest5Strc;
struct D2PlayerDataStrc;


struct D2Act1Quest5Strc
{
    int nUnitGUIDs1[12];
    unsigned short nUnitCount1;
    unsigned char pad0x32[2];
    int nUnitGUIDs2[12];
    unsigned short nUnitCount2;
};

struct D2QuestDataStrc
{
    char unk00[0xB];
    unsigned char fLastState;
    unsigned char fState;
    unsigned char unk_0D[0xB];
    void* pQuestDataEx;
};

struct D2GameStrc { char unk00[0x6D]; unsigned char nDifficulty; };

struct D2PlayerDataStrc { char unk00[0x10]; D2BitBufferStrc* pQuestData[3]; };

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc*); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc*, int, int); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc*, int, int); // 0x0065C360
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc*, int); // 0x00543640

// 0x005947E0
static int __stdcall sub_005947E0_IsUnitGUIDInList(D2Act1Quest5Strc* pQuestDataEx, int nUnitGUID, int bSecondList)
{
    if (bSecondList)
    {
        const int nCount = pQuestDataEx->nUnitCount2;
        for (int i = 0; i < nCount; ++i)
        {
            if (pQuestDataEx->nUnitGUIDs2[i] == nUnitGUID)
            {
                return 1;
            }
        }
        return 0;
    }

    const int nCount = pQuestDataEx->nUnitCount1;
    for (int i = 0; i < nCount; ++i)
    {
        if (pQuestDataEx->nUnitGUIDs1[i] == nUnitGUID)
        {
            return 1;
        }
    }
    return 0;
}

// 0x005952C0
bool __fastcall ACT1Q5_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    D2Act1Quest5Strc* pQuestDataEx = (D2Act1Quest5Strc*)pQuest->pQuestDataEx;
    int nUnitId = !pPlayer ? -1 : pPlayer->dwUnitId;
    if (sub_005947E0_IsUnitGUIDInList(pQuestDataEx, nUnitId, 1))
    {
        if (nNpcId == 155 || nNpcId == 147)
        {
            return false;
        }

        return true;
    }

    return false;
}

// 0x00594890
int __fastcall ACT1Q5_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pFlags, 5, 0) == 1 || QUESTRECORD_GetQuestState(pFlags, 5, 1) == 1) return 0;
    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pGame, 5);
    if (!pQuest) return 0;
    if (pQuest->fState == 2)
    {
        QUESTRECORD_SetQuestState(pFlags, 5, 2);
        return 0;
    }
    if (pQuest->fState == 3)
    {
        switch (pQuest->fLastState)
        {
        case 1: QUESTRECORD_SetQuestState(pFlags, 5, 3); break;
        case 2: QUESTRECORD_SetQuestState(pFlags, 5, 4); break;
        case 3: QUESTRECORD_SetQuestState(pFlags, 5, 5); break;
        case 4: QUESTRECORD_SetQuestState(pFlags, 5, 6); break;
        }
    }
    return 0;
}
