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
};

struct D2GameStrc;

struct D2MissilesTxt
{
    char unk0x00[0x78];
    int dwDmgParam[2];
    char unk0x80[0x124];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    int unk0xB68;
    int nMissilesTxtRecordCount;
};

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
int __fastcall sub_004638A0(int nMonsterId, int nFlag);                                              // 0x004638A0

static D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

// 0x005AD630
void __fastcall MISSMODE_SrvDmg14_MoltenBoulder(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    if (!pMissile || pMissile->dwUnitType != 3)
    {
        return;
    }

    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile->dwClassId);
    if (!pMissilesTxtRecord || !pUnit)
    {
        return;
    }

    int nChance = 0;
    if (pUnit->dwUnitType == 0)
    {
        if (pMissilesTxtRecord->dwDmgParam[0] < 1)
        {
            return;
        }
        nChance = pMissilesTxtRecord->dwDmgParam[1];
    }
    else if (pUnit->dwUnitType == 1)
    {
        const int nParam = pMissilesTxtRecord->dwDmgParam[0];
        if (nParam < 1)
        {
            if (!sub_004638A0(pUnit->dwClassId, 10))
            {
                return;
            }
            nChance = pMissilesTxtRecord->dwDmgParam[1];
        }
        else if (nParam == 1)
        {
            const int nClassId = pUnit->dwClassId;
            if (sub_004638A0(nClassId, 10))
            {
                nChance = 2 * pMissilesTxtRecord->dwDmgParam[1];
            }
            else if (!sub_004638A0(nClassId, 11))
            {
                nChance = pMissilesTxtRecord->dwDmgParam[1];
            }
            else
            {
                return;
            }
        }
        else if (nParam > 1)
        {
            const int nClassId = pUnit->dwClassId;
            if (sub_004638A0(nClassId, 10))
            {
                nChance = 3 * pMissilesTxtRecord->dwDmgParam[1];
            }
            else if (!sub_004638A0(nClassId, 11))
            {
                nChance = 2 * pMissilesTxtRecord->dwDmgParam[1];
            }
            else
            {
                nChance = pMissilesTxtRecord->dwDmgParam[1];
            }
        }
        else
        {
            return;
        }
    }
    else
    {
        return;
    }

    if (nChance > 0 && (int)SEED_RollLimitedRandomNumber(&pMissile->pSeed, 100) < nChance)
    {
        pDamage->wResultFlags |= 8;
    }
}
