#include "D2Game.h"

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x88];
    int dwGameFrame;
};

struct D2ItemsTxt
{
    char unk0x00[0x98];
    short wState;
    char unk0x9A[0x04];
    short wStat[3];
    unsigned int dwCalc[3];
    unsigned int dwLen;
};

struct D2ItemStatCostTxt
{
    char unk0x00[0x32];
    unsigned short wMaxStat;
    char unk0x34[0x110];
};

struct D2DataTablesStrc
{
    char unk0x00[0xC4];
    int nStatesTxtRecordCount;
    char unk0xC8[0xB04];
    D2ItemStatCostTxt* pItemStatCostTxt;
    int unk0xBD0;
    int nItemStatCostTxtRecordCount;
};

typedef void(__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
int __stdcall ITEMMODS_EvaluateItemFormula(D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int nCalc);       // 0x00627C20
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);              // 0x006256B0
int __stdcall D2COMMON_10473(D2StatListStrc* pStatList);                                                    // 0x00626090
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360
int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc* pUnit);                                        // 0x0044BE50
int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc* pUnit);                                                 // 0x00451F50
int __fastcall SKILLS_SharePotionLifeWithBloodGolem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nLife);       // 0x005C6870
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x006272B0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int nFlags, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState);                                    // 0x006252D0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nSkillId); // 0x00540E60
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0
void __fastcall SKILLS_RemoveStateAndRefreshPassives(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x0056E900
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall D2COMMON_10476(D2StatListStrc* pStatList, int nExpireFrame);                                 // 0x006260B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625D00
void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627150
unsigned char __fastcall MONSTERMODE_GetHpPercent128(D2UnitStrc* pUnit);                                    // 0x005805D0
void __fastcall SUNITMSG_QueueLifeUpdate(D2UnitStrc* pUnit, unsigned char nHpPercent);                      // 0x00571A10
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260

// build: context SKILLS_GetItemStatCostTxtRecord
static __forceinline D2ItemStatCostTxt* SKILLS_GetItemStatCostTxtRecord(int nStatId)
{
    if (nStatId < 0)
    {
        return 0;
    }

    if (nStatId >= sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return 0;
    }

    return &sgptDataTables->pItemStatCostTxt[nStatId];
}

// 0x005BEAC0
int __fastcall SKILLITEM_pSpell05_RejuvPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    const int nLength = ITEMMODS_EvaluateItemFormula(pUnit, pItem, pItemsTxtRecord->dwLen);
    const int nState = pItemsTxtRecord->wState;

    D2StatListStrc* pStatList = 0;
    int nRemainingDuration = 0;
    if (nLength > 0)
    {
        if (nState <= 0 || nState >= sgptDataTables->nStatesTxtRecordCount)
        {
            return 0;
        }

        pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
        if (pStatList)
        {
            nRemainingDuration = D2COMMON_10473(pStatList) - pGame->dwGameFrame;
        }
    }

    int nResult = 0;
    int bAffectsHitpoints = 0;

    for (int i = 0; i < 3; ++i)
    {
        const int nStatId = pItemsTxtRecord->wStat[i];
        D2ItemStatCostTxt* pItemStatCostTxtRecord = SKILLS_GetItemStatCostTxtRecord(nStatId);
        if (pItemStatCostTxtRecord && pItemStatCostTxtRecord->wMaxStat < sgptDataTables->nItemStatCostTxtRecordCount)
        {
            const int nPercentage = ITEMMODS_EvaluateItemFormula(pUnit, pItem, pItemsTxtRecord->dwCalc[i]);
            if (nPercentage > 0)
            {
                const int nMaxValue = STATLIST_UnitGetStatValue(pUnit, pItemStatCostTxtRecord->wMaxStat, 0);
                int nAddValue = DATATBLS_ApplyRatio(nMaxValue, nPercentage, 100);
                if (nPercentage == 100)
                {
                    nAddValue = nMaxValue;
                }

                switch (nStatId)
                {
                case 6:
                    bAffectsHitpoints = 1;
                case 74:
                    if (!sub_0044BE50_GetUnitTypeOrInvalid(pUnit))
                    {
                        nAddValue = SKILLS_SharePotionLifeWithBloodGolem(pGame, pUnit, nAddValue);
                    }
                    break;
                }

                if (nLength <= 0)
                {
                    const int nOldValue = STATLIST_UnitGetStatValue(pUnit, nStatId, 0);
                    if (nOldValue + nAddValue > nMaxValue)
                    {
                        nAddValue = nMaxValue - nOldValue;
                    }

                    STATLIST_AddUnitStat(pUnit, nStatId, nAddValue, 0);
                    nResult = 1;
                }
                else
                {
                    const int nExpireFrame = pGame->dwGameFrame + nRemainingDuration + nLength;
                    if (!pStatList)
                    {
                        pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nExpireFrame, sub_0044BE50_GetUnitTypeOrInvalid(pUnit), sub_00451F50_GetUnitGUID(pUnit));
                        if (!pStatList)
                        {
                            continue;
                        }

                        STATLIST_SetState(pStatList, nState);
                        STATES_ToggleState(pUnit, nState, 1);

                        if (sub_0044BE50_GetUnitTypeOrInvalid(pUnit))
                        {
                            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 3, 0);
                            EVENT_SetEvent(pGame, pUnit, 3, pGame->dwGameFrame + 1, 0, 0);
                        }

                        STATLIST_SetStatRemoveCallback(pStatList, SKILLS_RemoveStateAndRefreshPassives);
                        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
                    }

                    D2COMMON_10476(pStatList, nExpireFrame);

                    const int nTimeDependentValue = nAddValue + nRemainingDuration * STATLIST_GetStatValue(pStatList, nStatId, 0);
                    if (!i)
                    {
                        EVENT_SetEvent(pGame, pUnit, 12, nExpireFrame, 0, 0);
                    }

                    if (nRemainingDuration + nLength > 0)
                    {
                        STATLIST_SetStatIfListIsValid(pStatList, nStatId, nTimeDependentValue / (nRemainingDuration + nLength), 0);
                    }

                    nResult = 1;
                }
            }
        }
    }

    if (bAffectsHitpoints && pUnit && pUnit->dwUnitType == 0)
    {
        const unsigned char nNewSentHpPct = MONSTERMODE_GetHpPercent128(pUnit);
        SUNITMSG_QueueLifeUpdate(pUnit, nNewSentHpPct);
        STATLIST_SetUnitStat(pUnit, 352, nNewSentHpPct, 0);
    }

    return nResult;
}
