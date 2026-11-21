#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2QuestData.h"
#include "D2GameObjs.h"

#define QUEST_A2Q2_HORADRICSTAFF 9
#define ITEMQUAL_NORMAL 2
#define ITEMQUAL_MAGIC 4
#define ITEMQUAL_UNIQUE 7

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
D2SeedStrc* __fastcall QUESTS_GetGlobalSeed(D2GameStrc* pGame);                                            // 0x005438B0
int __fastcall QUESTS_SetObjectSelection(D2ObjOperateFnStrc* pOp);                                          // 0x00545850
D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, D2ItemDropStrc* pItemDrop, int a6, int a7); // 0x00559A30
D2UnitStrc* __fastcall OBJMODE_DropItemWithCodeAndQuality(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwCode, int nItemQuality); // 0x00585970
D2UnitStrc* __fastcall OBJMODE_DropFromChestTCWithQuality(D2ObjOperateFnStrc* pOp, int nItemQuality);      // 0x00585B90
int __fastcall ACT2Q2_UnitIterate_DetermineStaffDropCount(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00599750
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0
int __fastcall ACT2Q2_UnitIterate_DetermineCubeDropCount(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005997C0

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

// 0x00599CF0
int __fastcall sub_00599CF0(D2ObjOperateFnStrc* pOp, int nOperate)
{
    int nResult = 0;
    if (QUESTS_SetObjectSelection(pOp))
    {
        pOp->hObject->dwDropItemCode = ' fsm';

        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A2Q2_HORADRICSTAFF);
        if (pQuestData)
        {
            D2Act2Quest2Strc* pQuestDataEx = (D2Act2Quest2Strc*)pQuestData->pQuestDataEx;
            pQuestDataEx->nItemDropCount = 0;
            SUNIT_IterateUnitsOfType(pOp->pGame, 0, pOp->hPlayer, ACT2Q2_UnitIterate_DetermineStaffDropCount);

            for (int i = 0; i < pQuestDataEx->nItemDropCount; ++i)
            {
                int nItemLevel;
                D2UnitStrc* pItem = D2GAME_DropItemAtUnit_6FC4FEC0(pOp->pGame, pOp->hObject, ITEMQUAL_UNIQUE, &nItemLevel, 0, -1, 1);
                if (pItem)
                {
                    ITEMS_SetItemFlag(pItem, 0x10, 1);
                    ++pQuestDataEx->nBaseStaffs;
                    pQuestDataEx->bHoradricScrollDropped = 1;
                }
            }
        }

        OBJMODE_DropFromChestTCWithQuality(pOp, ITEMQUAL_MAGIC);

        D2SeedStrc* pSeed = QUESTS_GetGlobalSeed(pOp->pGame);
        const int nCounter = SEED_RollRandomNumber(pSeed) % 5 + 5;
        for (int i = 0; i < nCounter; ++i)
        {
            OBJMODE_DropItemWithCodeAndQuality(pOp->pGame, pOp->hObject, ' dlg', 2);
        }
    }
    return nResult;
}
