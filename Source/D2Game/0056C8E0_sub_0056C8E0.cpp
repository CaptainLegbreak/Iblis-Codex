struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    char unk0x00[0x20];
    D2SeedStrc pSeed;
};

struct D2DamageStrc
{
    char unk0x00[0x08];
    int dwPhysDamage;
    int unk0x0C;
    int dwFireDamage;
    int dwBurnDamage;
    int dwBurnLen;
    int dwLtngDamage;
    int dwMagDamage;
    int dwColdDamage;
    int dwPoisDamage;
    int dwPoisLen;
    int dwColdLen;
    int dwFrzLen;
    int dwLifeLeech;
    int dwManaLeech;
    int dwStamLeech;
    int dwStunLen;
    char unk0x48[0x18];
    int dwHitClass;
};

enum D2C_ElemTypes
{
    ELEMTYPE_NONE = 0,
    ELEMTYPE_FIRE = 1,
    ELEMTYPE_LTNG = 2,
    ELEMTYPE_MAGIC = 3,
    ELEMTYPE_COLD = 4,
    ELEMTYPE_POIS = 5,
    ELEMTYPE_LIFE = 6,
    ELEMTYPE_MANA = 7,
    ELEMTYPE_STAMINA = 8,
    ELEMTYPE_STUN = 9,
    ELEMTYPE_RAND = 10,
    ELEMTYPE_BURN = 11,
    ELEMTYPE_FREEZE = 12,
};

#define STAT_FIRERESIST 39
#define STAT_LIGHTRESIST 41
#define STAT_COLDRESIST 43
#define STAT_POISONRESIST 45
#define STAT_MAGICRESIST 37

extern const int gnRandomElemTypes_006E1278[4];                                                             // 0x006E1278

inline unsigned int ITEMS_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x0056C8E0
void __fastcall sub_0056C8E0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nElementalType, int nDamage, int nLength, int* pResistStatId, int* pElementalType)
{
    if (nElementalType == ELEMTYPE_RAND)
    {
        nElementalType = gnRandomElemTypes_006E1278[ITEMS_RollRandomNumber(&pUnit->pSeed) & 3];
        if (nLength <= 0)
        {
            nLength = 50;
        }

        if (pElementalType)
        {
            *pElementalType = nElementalType;
        }
    }

    int nResStatId = -1;
    switch (nElementalType)
    {
    case ELEMTYPE_FIRE:
        pDamage->dwFireDamage += nDamage;
        pDamage->dwHitClass = 0x20;
        nResStatId = STAT_FIRERESIST;
        break;

    case ELEMTYPE_LTNG:
        pDamage->dwLtngDamage += nDamage;
        pDamage->dwHitClass = 0x40;
        nResStatId = STAT_LIGHTRESIST;
        break;

    case ELEMTYPE_MAGIC:
        pDamage->dwMagDamage += nDamage;
        nResStatId = STAT_MAGICRESIST;
        break;

    case ELEMTYPE_COLD:
        pDamage->dwColdDamage += nDamage;
        pDamage->dwColdLen = nLength;
        pDamage->dwHitClass = 0x30;
        nResStatId = STAT_COLDRESIST;
        break;

    case ELEMTYPE_POIS:
        pDamage->dwPoisDamage += nDamage;
        pDamage->dwPoisLen = nLength;
        pDamage->dwHitClass = 0x50;
        nResStatId = STAT_POISONRESIST;
        break;

    case ELEMTYPE_LIFE:
        pDamage->dwLifeLeech += nDamage;
        break;

    case ELEMTYPE_MANA:
        pDamage->dwManaLeech += nDamage;
        break;

    case ELEMTYPE_STAMINA:
        pDamage->dwStamLeech += nDamage;
        break;

    case ELEMTYPE_STUN:
        pDamage->dwStunLen += nDamage + nLength;
        pDamage->dwHitClass = 0x60;
        break;

    case ELEMTYPE_BURN:
        pDamage->dwBurnDamage += nDamage;
        pDamage->dwBurnLen = nLength;
        break;

    case ELEMTYPE_FREEZE:
        pDamage->dwColdDamage += nDamage;
        pDamage->dwFrzLen = nLength;
        pDamage->dwHitClass = 0x30;
        nResStatId = STAT_COLDRESIST;
        break;

    default:
        pDamage->dwPhysDamage += nDamage;
        break;
    }

    if (pResistStatId)
    {
        *pResistStatId = nResStatId;
    }
}

#include "gen/data/Source/D2Game/0056C8E0_sub_0056C8E0.inc"
