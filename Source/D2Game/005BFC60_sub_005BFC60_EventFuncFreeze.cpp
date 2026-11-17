extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);                               // 0x00681EF0

struct D2GameStrc;
struct D2DynamicPathStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x18];
    D2SeedStrc pSeed;
    char unk0x28[0x04];
    D2DynamicPathStrc* pDynamicPath;
};

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int unk0x08[11];
    int dwFrzLen;
    int unk0x38[14];
};

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500
void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bMissile, D2DamageStrc* pDamage); // 0x0057C6C0

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

// 0x005BFC60
int __fastcall sub_005BFC60_EventFuncFreeze(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit)
    {
        return 0;
    }

    const int nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nValue <= 0)
    {
        return 0;
    }

    int nAttackerLevel = STATLIST_UnitGetStatValue(pAttacker, 12, 0);
    const int nUnitLevel = STATLIST_UnitGetStatValue(pUnit, 12, 0);

    int nBonus = nValue - 1;
    if (nBonus < 0)
    {
        nBonus = 0;
    }

    if (nEvent == 6)
    {
        nAttackerLevel -= nEvent;
    }

    int nChance = 5 * (4 * nBonus - nUnitLevel + nAttackerLevel + 10);
    if (nEvent == 6)
    {
        nChance /= 3;
    }

    int nPercent = D2_MIN(D2_MAX(nChance, 0), 100);

    const unsigned __int64 lSeed = (unsigned __int64)pAttacker->pSeed.nHighSeed + (unsigned __int64)pAttacker->pSeed.nLowSeed * 0x6AC690C5;
    pAttacker->pSeed.nLowSeed = (unsigned int)lSeed;
    pAttacker->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    const int nRoll = (int)((unsigned int)lSeed % 100);
    if (nRoll >= nPercent)
    {
        return 0;
    }

    int nLength = 2 * (nPercent - nRoll) + 25;
    nLength = D2_MIN(D2_MAX(nLength, 25), 250);

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.dwFrzLen = nLength;
    SUNITDMG_ExecuteEvents(pGame, pAttacker, pUnit, 1, &damage);
    return 1;
}
