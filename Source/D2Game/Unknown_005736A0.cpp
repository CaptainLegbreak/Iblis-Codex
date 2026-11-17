#include "D2Game.h"

struct D2AiParamStrc;

struct D2MonsterDataStrc
{
    char unk0x00[0x28];
    D2AiControlStrc* pAiControl;
    D2AiParamStrc* pAiParam;
    D2MonsterInteractStrc* pMonInteract;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x14 - 0x08];
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0x60 - 0x14 - 4];
    D2InventoryStrc* pInventory;
    char unk0x64[0xA4 - 0x60 - 4];
    D2HoverTextStrc* pHoverText;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
};

struct D2MonStatsTxt
{
    char unk0x00[0x0C];
    unsigned char dwMonStatsFlags[4];
    char unk0x10[0x1A8 - 0x0C - 4];
};

struct D2DataTablesStrc
{
    char unk0x00[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0xA80 - 0xA78 - 4];
    int nMonStatsTxtRecordCount;
};

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

    return pMonStatsTxtRecord->dwMonStatsFlags[nFlag >> 3] & gdwBitMasks[nFlag & 7];
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

    if (pMonster->dwUnitType == 1)
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
