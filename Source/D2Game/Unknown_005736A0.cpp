#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2UnitData.h"

struct D2AiParamStrc;






extern D2DataTablesStrc* sgptDataTables;                                                                     // 0x00744304
extern const unsigned int gdwBitMasks[];                                                                    // 0x006CE268

void __fastcall SUNIT_RemoveAllItemsFromInventory(D2GameStrc* pGame, D2UnitStrc* pUnit);                    // 0x00555AE0
void __fastcall SUNITDMG_FreeAttackerCombatList(D2GameStrc* pGame, D2UnitStrc* pUnit);                      // 0x0057C980
void __fastcall AIGENERAL_FreeAiControl(D2GameStrc* pGame, D2AiControlStrc* pAiControl);                   // 0x0058F810
void __fastcall D2GAME_MONSTERMODE_FreeParams_6FC63020(D2GameStrc* pGame, D2AiParamStrc* pAiParam);        // 0x005A64D0
void __fastcall MONSTERAI_FreeMonsterInteract(D2GameStrc* pGame, D2MonsterInteractStrc* pMonInteract);     // 0x00572BC0
void __fastcall sub_6FC349F0(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x00540EE0

static __forceinline int sub_E09_CheckMonStatsFlag(int nMonsterId, int nFlag)
{
    D2MonStatsTxt* pMonStatsTxtRecord = (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount) ? &sgptDataTables->pMonStatsTxt[nMonsterId] : 0;
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    return pMonStatsTxtRecord->nMonStatsFlags[nFlag >> 3] & gdwBitMasks[nFlag & 7];
}

// 0x005736A0
void __fastcall MONSTER_Free(D2GameStrc* pGame, D2UnitStrc* pMonster)
{
    SUNITDMG_FreeAttackerCombatList(pGame, pMonster);

    if (!pMonster || !sub_E09_CheckMonStatsFlag(pMonster->dwClassId, 9))
    {
        SUNIT_RemoveAllItemsFromInventory(pGame, pMonster);
        INVENTORY_FreeInventory(pMonster->pInventory);
    }

    if (pMonster->pHoverText)
    {
        CHAT_FreeHoverMsg(pGame->pMemoryPool, pMonster->pHoverText);
    }

    if (pMonster->dwUnitType == UNIT_MONSTER)
    {
        D2MonsterDataStrc* pMonsterData = pMonster->pMonsterData;
        if (pMonsterData)
        {
            AIGENERAL_FreeAiControl(pGame, pMonsterData->pAiControl);
            D2GAME_MONSTERMODE_FreeParams_6FC63020(pGame, pMonsterData->pAiParam);
            MONSTERAI_FreeMonsterInteract(pGame, pMonsterData->pMonInteract);
        }
    }

    sub_6FC349F0(pGame, pMonster);
}
