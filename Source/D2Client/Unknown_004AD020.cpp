#include "D2Structs.h"
#include "D2UnitData.h"

typedef void (__fastcall* UMODCALLBACK)(D2UnitStrc* pUnit, int nUMod, int bUnique);

extern const int gaUModList_006DA4C8[4];                                                                     // 0x006DA4C8
extern UMODCALLBACK gpfnUModCallbacks_00724D78[];                                                            // 0x00724D78

// build: context sub_0044BE50
static int sub_0044BE50(D2UnitStrc* pUnit)
{
    int nType = 6;
    if (pUnit)
        nType = pUnit->dwUnitType;
    return nType;
}

// build: context MONSTERS_CheckMonTypeFlag
static int MONSTERS_CheckMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag)
{
    D2MonsterDataStrc* pMonsterData = sub_0044BE50(pUnit) == 1 ? pUnit->pMonsterData : 0;
    if (!pMonsterData)
        return 0;
    if (pMonsterData->nTypeFlag & nFlag)
        return 1;
    return 0;
}

// 0x004AD020
void __fastcall sub_004AD020_ApplyUMods(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = sub_0044BE50(pUnit) == 1 ? pUnit->pMonsterData : 0;
    if (pMonsterData)
    {
        unsigned char* pUMods = pMonsterData->nMonUmod;
        if (pUMods && *pUMods)
        {
        const int bUnique = MONSTERS_CheckMonTypeFlag(pUnit, 8);

        for (int j = 0; j < 4; ++j)
        {
            const int nUMod = gaUModList_006DA4C8[j];
            if (gpfnUModCallbacks_00724D78[nUMod])
                gpfnUModCallbacks_00724D78[nUMod](pUnit, nUMod, bUnique);
        }

        for (int i = 0; i < 9; ++i)
        {
            const int nUMod = pUMods[i];
            if (gpfnUModCallbacks_00724D78[nUMod])
                gpfnUModCallbacks_00724D78[nUMod](pUnit, nUMod, bUnique);
        }
        }
    }
}

#include "gen/data/Source/D2Client/Unknown_004AD020.inc"
