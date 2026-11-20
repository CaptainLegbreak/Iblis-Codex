#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
struct D2UnitStrc;

struct D2ModeChangeStrc;

struct D2ActiveRoomStrc
{
    char unk_00[0x74];
    D2UnitStrc* pUnitFirst;
};


struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int dwPhysDamage[22];
    unsigned int dwHitClass;
    int unk_64[3];
};

extern "C" void* __cdecl memset(void*, int, unsigned int); // 0x00681EF0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0
int __stdcall sub_00622B50_IsRayFreeBetweenUnits(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, unsigned int nCollisionMask); // 0x00622B50
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
void __fastcall sub_0057C1E0_Total(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x0057C1E0
void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bMissile, D2DamageStrc* pDamage); // 0x0057C6C0
void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x0057CEE0
__declspec(noinline) static void sub_005A6DF0_DamageNearbyPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit);

struct D2ModeChangeStrc
{
    int nMode;
    D2UnitStrc* pUnit;
    D2UnitStrc* pTargetUnit;
};


extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall sub_0046C140_TestMonModeFlag(int nMonsterId, int nMode); // 0x0046C140
int __fastcall sub_00463860(D2UnitStrc* pUnit); // 0x00463860
void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType); // 0x00648CF0
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970
void __fastcall SUNIT_SetCombatMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode); // 0x00553570

// 0x005A6DF0
static void sub_005A6DF0_DamageNearbyPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    for (D2UnitStrc* pTarget = UNITS_GetRoom(pUnit)->pUnitFirst; pTarget; pTarget = pTarget->ptRoomNext)
    {
        if ((!pTarget ? 6 : pTarget->dwUnitType) == 0 && pTarget->dwAnimMode != 17
            && sub_006416D0_UnitEdgeDistance(pUnit, pTarget) <= 2
            && !sub_00622B50_IsRayFreeBetweenUnits(pTarget, pUnit, 0x3C01))
        {
            D2DamageStrc damage;
            memset(&damage, 0, sizeof(damage));
            damage.dwPhysDamage[0] = STATLIST_UnitGetStatValue(pTarget, 6, 0) >> 5;
            damage.wResultFlags = 1;
            if (!STATES_CheckState(pTarget, 0x36))
                damage.wResultFlags |= 4;
            sub_0057C1E0_Total(pGame, pUnit, pTarget, &damage);
            SUNITDMG_ExecuteEvents(pGame, pUnit, pTarget, 1, &damage);
            SUNITDMG_ExecuteMissileDamage(pGame, pUnit, pTarget, &damage);
        }
    }
}

void __fastcall sub_Emit_005A6DF0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (pUnit)
        sub_005A6DF0_DamageNearbyPlayers(pGame, pUnit);
}

// 0x005A77D0
int __fastcall sub_005A77D0_StartKnockback(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    D2UnitStrc* pUnit = pModeChange->pUnit;
    if (!sub_0046C140_TestMonModeFlag(!pUnit ? -1 : pUnit->dwClassId, 3))
    {
        return 0;
    }

    if (!sub_0046C140_TestMonModeFlag(!pUnit ? -1 : pUnit->dwClassId, 13))
    {
        return 0;
    }

    if (pUnit && pUnit->dwAnimMode)
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        PATH_SetType(pPath, 8);
        int nBaseId = sub_00463860(pUnit);
        if (nBaseId < 0 || nBaseId >= sgptDataTables->nMonStatsTxtRecordCount)
        {
            nBaseId = -1;
        }

        if (nBaseId != 0x4E)
        {
            D2COMMON_10190_PATH_SetDistance(pPath, 5);
        }
        else
        {
            D2COMMON_10190_PATH_SetDistance(pPath, 10);
        }
        D2Common_10142(pPath, pUnit, 0);
        SUNIT_SetCombatMode(pGame, pUnit, 13);
    }

    return 1;
}
