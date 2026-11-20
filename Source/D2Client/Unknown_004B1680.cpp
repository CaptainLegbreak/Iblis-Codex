#include "D2Client.h"
#include "D2Structs.h"



#pragma pack(push, 1)
struct D2NpcChoiceStrc
{
    unsigned short wId;
    char bQuest;
    int nQuestState;
    int nQuestId;
    int nClass;
};

struct D2NpcEntryStrc
{
    char unk0x00[0x05];
    D2NpcChoiceStrc* pChoices;
    int nChoices;
    int nSelected;
};
#pragma pack(pop)

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
extern D2NpcChoiceStrc gaNpcChoices_00725CB0[];                                                             // 0x00725CB0

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber(pSeed) % nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

// 0x004B1680
void __stdcall sub_004B1680(D2NpcEntryStrc* pEntry)
{
    int* const pnSelected = &pEntry->nSelected;
    int nTries = 10;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    const int nClass = !pPlayer ? -1 : pPlayer->dwClassId;

    do
    {
        --nTries;
        *pnSelected = SEED_RollLimitedRandomNumber(&pPlayer->pSeed, pEntry->nChoices);
        if (*pnSelected >= 2)
        {
            if (pEntry->pChoices[*pnSelected].nClass == nClass || pEntry->pChoices[*pnSelected].nClass == 7)
            {
                if (!pEntry->pChoices[*pnSelected].bQuest)
                {
                    return;
                }

                if (QUESTRECORD_GetQuestState(gpQuestFlags_007C0D43, pEntry->pChoices[*pnSelected].nQuestId, 0) == pEntry->pChoices[*pnSelected].nQuestState)
                {
                    if (pEntry->pChoices == gaNpcChoices_00725CB0 && pEntry->pChoices[*pnSelected].wId == 0xFF
                        && QUESTRECORD_GetQuestState(gpQuestFlags_007C0D47, 12, 13) == 1)
                    {
                        *pnSelected = 2;
                    }
                    return;
                }
            }
        }
    }
    while (nTries);

    *pnSelected = 2;
}
