struct D2UnitFlags004525F0Strc
{
    unsigned int bFlag0 : 1;
    unsigned int bFlag1 : 1;
    unsigned int bFlag2 : 1;
    unsigned int nRest : 29;
};

struct D2UnitStrc
{
    unsigned int dwUnitType;
    unsigned int dwClassId;
    void* pMemoryPool;
    unsigned int dwUnitId;
    char unk0x10[0xC4 - 0x10];
    D2UnitFlags004525F0Strc tFlags;
};

int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820
int __fastcall sub_00465C60_CheckUnitPair(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x00465C60
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
int __fastcall sub_00479080_GetPetLife(int nUnitId); // 0x00479080
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

// 0x004525F0
int __fastcall sub_004525F0_GetMonsterLifeFraction(D2UnitStrc* pUnit)
{
    if (pUnit && (!pUnit ? 6 : pUnit->dwUnitType) == 1 && !sub_00464820_IsDeadOrDying(pUnit))
    {
        int bPaired;
        if ((!pUnit ? 0 : pUnit->tFlags.bFlag2) && sub_00465C60_CheckUnitPair(sub_00463DD0(), pUnit))
        {
            bPaired = 1;
        }
        else
        {
            bPaired = 0;
        }

        const int nLife = sub_00479080_GetPetLife(pUnit->dwUnitId);
        int nResult;
        if (!bPaired && nLife > 0)
        {
            nResult = D2_MIN(D2_MAX((nLife << 7) / 100, 2), 0x80);
        }
        else
        {
            const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pUnit);
            if (!nMaxLife)
            {
                nResult = 0x80;
            }
            else
            {
                const int nCurrentLife = STATLIST_UnitGetStatValue(pUnit, 6, 0);
                nResult = D2_MIN(D2_MAX((nCurrentLife << 7) / nMaxLife, 2), 0x80);
            }
        }
        return nResult;
    }
    return 0;
}
