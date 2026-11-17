#include "D2Game.h"

struct D2SeedStrc
{
    union
    {
        struct
        {
            unsigned int nLowSeed;
            unsigned int nHighSeed;
        };
        uint64_t lSeed;
    };
};

struct D2GameStrc
{
    char unk_00[0x70];
    int bExpansion;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk_04[0x0C];
    int dwAnimMode;
    char unk_14[0x0C];
    D2SeedStrc pSeed;
    char unk_28[0x60 - 0x28];
    D2InventoryStrc* pInventory;
};

int __stdcall UNITS_GetBlockRate(D2UnitStrc* pUnit, int bExpansion); // 0x00622720
int __stdcall UNITS_IsInMovingMode(D2UnitStrc* pUnit); // 0x00622D00
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010
void __fastcall sub_005347C0_Stub6(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nChance, int nRand, const char* szText); // 0x005347C0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480
int __fastcall SUNITDMG_GetWeaponBlock(D2UnitStrc* pUnit); // 0x0057DCA0
int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int* pWeaponClassId, int nAnimMode, int a5); // 0x0064F380

static __forceinline uint64_t SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    uint64_t lSeed = pSeed->nHighSeed + 0x6AC690C5ui64 * pSeed->nLowSeed;
    pSeed->lSeed = lSeed;
    return lSeed;
}

static __declspec(noinline) int __stdcall SUNITDMG_ApplyDodge(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bAvoid); // 0x0057DD60

// build: context SUNITDMG_ApplyDodge
static __declspec(noinline) int __stdcall SUNITDMG_ApplyDodge(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bAvoid)
{

    if (pDefender)
    {
        if (pDefender->dwUnitType == 0 && (pDefender->dwAnimMode == 3 || pDefender->dwAnimMode == 2)
            || pDefender->dwUnitType == 1 && (pDefender->dwAnimMode == 15 || pDefender->dwAnimMode == 2))
        {
            const int nEvade = STATLIST_UnitGetStatValue(pDefender, 340, 0);
            if (nEvade > 0)
            {
                const int nRand = (unsigned int)SEED_RollRandomNumber(&pDefender->pSeed) % 100;
                sub_005347C0_Stub6(SUNIT_GetGameFromUnit(pAttacker), pAttacker, pDefender, nEvade, nRand, "evades");
                if (nRand < nEvade)
                {
                    return 4;
                }
            }

            return 0;
        }
    }

    const int nWeaponBlock = SUNITDMG_GetWeaponBlock(pDefender);
    if (nWeaponBlock > 0)
    {
        int nWeaponClassId = 0;
        COMPOSIT_GetWeaponClassId(pDefender, pDefender->pInventory, &nWeaponClassId, -1, 1);
        if (nWeaponClassId == 13)
        {
            const int nRand = (unsigned int)SEED_RollRandomNumber(&pDefender->pSeed) % 100;
            sub_005347C0_Stub6(SUNIT_GetGameFromUnit(pAttacker), pAttacker, pDefender, nWeaponBlock, nRand, "block");
            if (nRand < nWeaponBlock)
            {
                return 5;
            }
        }
    }

    if (bAvoid)
    {
        const int nAvoid = STATLIST_UnitGetStatValue(pDefender, 339, 0);
        if (nAvoid > 0)
        {
            const int nRand = (unsigned int)SEED_RollRandomNumber(&pDefender->pSeed) % 100;
            sub_005347C0_Stub6(SUNIT_GetGameFromUnit(pAttacker), pAttacker, pDefender, nAvoid, nRand, "avoids");
            if (nRand < nAvoid)
            {
                return 3;
            }
        }
    }
    else
    {
        const int nDodge = STATLIST_UnitGetStatValue(pDefender, 338, 0);
        if (nDodge > 0)
        {
            const int nRand = (unsigned int)SEED_RollRandomNumber(&pDefender->pSeed) % 100;
            sub_005347C0_Stub6(SUNIT_GetGameFromUnit(pAttacker), pAttacker, pDefender, nDodge, nRand, "dodges");
            if (nRand < nDodge)
            {
                return 2;
            }
        }
    }

    return 0;
}

// 0x0057DFB0
int __fastcall SUNITDMG_ApplyBlockOrDodge(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bAvoid, int bBlock)
{
    if (!bBlock)
    {
        return SUNITDMG_ApplyDodge(pAttacker, pDefender, bAvoid);
    }

    int nBlockChance = UNITS_GetBlockRate(pDefender, pGame->bExpansion);
    if (nBlockChance <= 0)
    {
        return SUNITDMG_ApplyDodge(pAttacker, pDefender, bAvoid);
    }

    if (pDefender && pDefender->dwUnitType == 0 && UNITS_IsInMovingMode(pDefender) && pDefender->dwAnimMode != 2)
    {
        nBlockChance /= 3;
    }

    const int nRand = (unsigned int)SEED_RollRandomNumber(&pDefender->pSeed) % 100;
    sub_005347C0_Stub6(SUNIT_GetGameFromUnit(pAttacker), pAttacker, pDefender, nBlockChance, nRand, "blocks");
    if (nRand >= nBlockChance)
    {
        return SUNITDMG_ApplyDodge(pAttacker, pDefender, bAvoid);
    }

    return 1;
}
