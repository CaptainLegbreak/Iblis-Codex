#include "D2MonsterIds.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2GameAux.h"
#include "D2GameServer.h"
#include "D2Txt.h"

struct D2TargetNodeStrc;
struct D2MonStatsTxt;
struct D2ItemsTxt;
struct D2MonsterItemCodeStrc;
struct D2UnkMonCreateStrc;

void __fastcall D2GAME_FreeUnitNode_6FC40310(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005B1A20
D2TargetNodeStrc* __fastcall sub_005B1BC0_FindTargetNode(D2UnitStrc* pUnit, D2GameStrc* pGame); // 0x005B1BC0


struct D2MonsterItemCodeStrc
{
    unsigned int dwCode;
    int nUnk0x04;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern D2MonsterItemCodeStrc gaAncientBarbItems[4][3]; // 0x006E1BB0
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640
void __fastcall MONSTERAI_CreateAndEquipItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MonsterItemCodeStrc* pCode, int nLevel, int nFlags); // 0x00573B20
int __fastcall QUESTS_CreateChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuestId); // 0x005436B0
void __fastcall D2GAME_BOSSES_AssignUMod_6FC6FF10(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique); // 0x005A4850
void __fastcall MONSTER_ToggleSummonerFlag(D2UnitStrc* pUnit, int nFlag, int bSet); // 0x00573570
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
void __fastcall QUESTS_WarrivSpawn(D2GameStrc* pGame, void* pRoom, int nXpos, int nYpos, int nWarrivId); // 0x005447A0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall D2Common_11063(D2ActiveRoomStrc* pRoom, int nMonsterId); // 0x0063EC70
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnAtUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags); // 0x005B23C0

// 0x005B1B70
void __fastcall sub_005B1B70_FreeAllTargetNodes(D2GameStrc* pGame)
{
    if (!pGame)
    {
        return;
    }

    D2TargetNodeStrc** ppTargetNode = pGame->pTargetNodes;
    D2TargetNodeStrc* pTargetNode = *ppTargetNode;
    for (int nCount = 10; nCount; --nCount)
    {
        if (pTargetNode && pTargetNode->hUnit)
        {
            D2GAME_FreeUnitNode_6FC40310(pGame, pTargetNode->hUnit);
        }
        pTargetNode = *++ppTargetNode;
    }
}

// 0x005B1C00
void __fastcall sub_005B1C00_ToggleTargetFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFlags, int bSet)
{
    if (!pGame || !pUnit)
    {
        return;
    }

    D2TargetNodeStrc* pTargetNode;
    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        pTargetNode = sub_005B1BC0_FindTargetNode(pUnit, pGame);
    }
    else if (pUnit->dwUnitType == UNIT_MONSTER)
    {
        pTargetNode = sub_005B1BC0_FindTargetNode(pUnit, pGame);
    }
    else
    {
        return;
    }

    if (!pTargetNode)
    {
        return;
    }

    if (bSet)
    {
        pTargetNode->nNodeData |= nFlags;
    }
    else
    {
        pTargetNode->nNodeData &= ~nFlags;
    }
}

#include "gen/data/Source/D2Game/Unknown_005B1B70.inc"
