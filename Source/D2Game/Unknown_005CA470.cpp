#include "D2Game.h"

struct D2SkillsTxt;
struct D2CurseStrc;
struct D2EnergyShieldDataStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

struct D2SkillsTxt
{
    char unk0x000[0x48];
    short wSrvMissileA;
    char unk0x04A[0x16];
    unsigned int dwAuraLenCalc;
    char unk0x064[0x1C];
    short nAuraState;
    char unk0x082[0x8A];
    short wPrgOverlay;
    unsigned char unk_10E[0x20];
    unsigned short wResultFlags;
    unsigned int dwHitFlags;
    unsigned int dwHitClass;
    unsigned int dwCalc[4];
    char unk0x148[0xF4];
};

struct D2DataTablesStrc
{
    char unk0x000[0xC4];
    int nStatesTxtRecordCount;
    char unk0x0C8[0xAA4];
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
    char unk0xBA4[0x1C];
    int nOverlayTxtRecordCount;
};

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

struct D2CurseStrc
{
    D2UnitStrc* pUnit;
    D2UnitStrc* pTarget;
    int nSkill;
    int nSkillLevel;
    int nDuration;
    int nStat;
    int nStatValue;
    int nState;
    StatListRemoveCallback pStateRemoveCallback;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2UnitStrc* __fastcall D2GAME_CreateMissile_6FD115E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId, int nX, int nY); // 0x0056EDE0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __stdcall SKILLS_GetParam2(D2SkillStrc* pSkill); // 0x006444D0
int __stdcall SKILLS_GetParam1(D2SkillStrc* pSkill); // 0x006444A0
int __fastcall sub_005C8BC0_GetSkillParam7(int nSkillId); // 0x005C8BC0
D2UnitStrc* __fastcall sub_6FD107F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, int a7, int* a8); // 0x0056BD10
int __fastcall MISSMODE_SrvDmgHitHandler(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, int a4); // 0x005ADF10
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600
void __fastcall sub_6FCC6300(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, short nSkillId, short nSkillLevel, int nX, int nY, unsigned char a7); // 0x00571AA0
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560
void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue); // 0x006445A0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
D2StatListStrc* __fastcall sub_0056E970(D2CurseStrc* pCurse); // 0x0056E970
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150
extern "C" int __fastcall sub_005C8BC0_GetSkillsTxtParam7(int nSkillId); // 0x005C8BC0
void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150

enum D2C_V04SorConstants
{
    UNIT_MONSTER = 1,
    STAT_MANA = 8,
};

struct D2EnergyShieldDataStrc
{
    int nDamageOffset;
    int bPlayerOnly;
};

extern const D2EnergyShieldDataStrc gEnergyShieldData_006E30E0[8]; // 0x006E30E0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit); // 0x0063EE90
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
unsigned char __stdcall UNITS_GetDirectionToCoords(D2UnitStrc* pUnit, int nNewX, int nNewY); // 0x00621DC0
unsigned char __stdcall D2Common_11053(int nDirection); // 0x0063E7A0
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3); // 0x00621E40
void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList); // 0x006277E0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int dwPhysDamage;
    int dwEnDmgPct;
    int unk0x10[20];
    unsigned int dwHitClass;
    unsigned char nHitClassActiveSet;
    signed char nConvType;
    unsigned short unk0x66;
    int dwConvPct;
    int nOverlay;
};

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2DamageStrc* pDamage, unsigned char nSrcDam); // 0x0057DBF0
unsigned short __fastcall SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int nRangeOffset); // 0x0057EC10
int __fastcall SKILLS_SrvSt32_Conversion_Bash_Stun_Concentrate_BearSmite(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D7EA0
int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x006449F0

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x005CA470
static D2UnitStrc* __stdcall sub_005CA470_CreateThunderStormBolt(D2GameStrc* pGame, int nMissileId, int nSkillId, int nSkillLevel, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (pUnit && pTarget && !DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)) && !DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)))
    {
        return D2GAME_CreateMissile_6FD115E0(pGame, pUnit, nSkillId, nSkillLevel, nMissileId, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget));
    }
    return 0;
}

// 0x005CA4D0
int __fastcall SKILLS_SrvDo029_ThunderStorm(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
    {
        return 0;
    }

    if (STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState) && !SKILLS_GetParam2(pSkill))
    {
        const int nParam1 = SKILLS_GetParam1(pSkill);
        const int nRange = sub_005C8BC0_GetSkillsTxtParam7(nSkillId);
        D2UnitStrc* pTarget = sub_6FD107F0(pGame, pUnit, 0, 0, nRange, 3, nParam1, 0);
        if (pTarget)
        {
            D2UnitStrc* pMissile = sub_005CA470_CreateThunderStormBolt(pGame, nMissileId, nSkillId, nSkillLevel, pUnit, pTarget);
            if (pMissile)
            {
                MISSMODE_SrvDmgHitHandler(pGame, pMissile, pTarget, 1);
                SUNIT_RemoveUnit(pGame, pMissile);
                sub_6FCC6300(pUnit, pTarget, nSkillId, nSkillLevel, 0, 0, 0);
            }

            SKILLS_SetParam1(pSkill, !pTarget ? -1 : pTarget->dwUnitId);
        }
        else
        {
            SKILLS_SetParam1(pSkill, -1);
        }
    }
    else
    {
        D2CurseStrc curse = {};
        curse.pUnit = pUnit;
        curse.pTarget = pUnit;
        curse.nSkill = nSkillId;
        curse.nSkillLevel = nSkillLevel;
        curse.nDuration = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
        curse.nStat = -1;
        curse.nStatValue = 0;
        curse.nState = pSkillsTxtRecord->nAuraState;

        D2StatListStrc* pStatList = sub_0056E970(&curse);
        if (pStatList)
        {
            STATLIST_SetStatIfListIsValid(pStatList, 350, nSkillId, 0);
            STATLIST_SetStatIfListIsValid(pStatList, 351, nSkillLevel, 0);
        }
    }

    SKILLS_SetParam2(pSkill, 0);
    return 1;
}

// 0x005CA6C0
int __fastcall SKILLS_EventFunc24_EnergyShield(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker)
    {
        return 0;
    }

    if (!pDamage)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount || !STATLIST_GetStatListFromUnitAndState(pAttacker, pSkillsTxtRecord->nAuraState))
    {
        return 0;
    }

    const int nMultiplier = SKILLS_EvaluateSkillFormula(pAttacker, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nMultiplier <= 0)
    {
        return 0;
    }

    int nMana = STATLIST_UnitGetStatValue(pAttacker, STAT_MANA, 0);
    int nDivisor = SKILLS_EvaluateSkillFormula(pAttacker, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
    if (nDivisor <= 0)
    {
        nDivisor = 1;
    }

    int bIsPlayer = 1;
    if (pUnit && (pUnit->dwUnitType != UNIT_MONSTER || MONSTERS_GetHirelingTypeId(pUnit)))
    {
        bIsPlayer = 0;
    }

    int nAbsorbedDamage = 0;
    for (int i = 0; i < 8; ++i)
    {
        const D2EnergyShieldDataStrc* pEnergyShieldData = &gEnergyShieldData_006E30E0[i];
        if (!pEnergyShieldData->bPlayerOnly || bIsPlayer)
        {
            int* pDamageValue = (int*)((char*)pDamage + pEnergyShieldData->nDamageOffset);
            const int nDamage = *pDamageValue;
            if (nDamage > 0)
            {
                int nAbsorb = DATATBLS_ApplyRatio(nDamage, nMultiplier, 100);
                const int nMax = DATATBLS_ApplyRatio(nMana, 16, nDivisor);
                if (nAbsorb >= nMax)
                {
                    nAbsorb = nMax;
                }

                nAbsorbedDamage += nAbsorb;
                *pDamageValue = nDamage - nAbsorb;
                nMana -= DATATBLS_ApplyRatio(nAbsorb, nDivisor, 16);
                nMana = nMana > 0 ? nMana : 0;
            }
        }
    }

    nMana = nMana > 0 ? nMana : 0;

    STATLIST_SetUnitStat(pAttacker, STAT_MANA, nMana, 0);

    if (pUnit && nAbsorbedDamage > 0 && pSkillsTxtRecord->wPrgOverlay >= 0 && pSkillsTxtRecord->wPrgOverlay <= sgptDataTables->nOverlayTxtRecordCount)
    {
        const int nDirection = UNITS_GetDirectionToCoords(pAttacker, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit));
        const int nOffset = D2Common_11053(nDirection);
        UNITS_SetOverlay(pAttacker, pSkillsTxtRecord->wPrgOverlay + nOffset, 0);
    }

    if (nMana <= 0)
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pAttacker, pSkillsTxtRecord->nAuraState);
        if (pStatList)
        {
            D2Common_10474(pAttacker, pStatList);
            STATLIST_FreeStatList(pStatList);
            return 1;
        }

        STATES_ToggleState(pAttacker, pSkillsTxtRecord->nAuraState, 0);
    }

    return 1;
}

#include "gen/data/Source/D2Game/Unknown_005CA470.inc"

// 0x005CAE40
int __fastcall SKILLS_SrvSt42_FireHit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (!pUnit || pUnit->dwUnitType != 0)
    {
        D2DamageStrc damage;
        memset(&damage, 0, sizeof(damage));
        damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel), 0);
        if (damage.wResultFlags & 1)
        {
            damage.wResultFlags |= pSkillsTxtRecord->wResultFlags;
            damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
            if (pSkillsTxtRecord->dwHitClass)
            {
                damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
            }

            sub_6FC627B0(pUnit, 8);
        }

        SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, 0x80);

        return 1;
    }

    return SKILLS_SrvSt32_Conversion_Bash_Stun_Concentrate_BearSmite(pGame, pUnit, nSkillId, nSkillLevel);
}
