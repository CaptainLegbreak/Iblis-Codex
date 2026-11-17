struct D2StatListStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2SkillsTxt
{
    char unk0x000[0x04];
    unsigned char nFlags[8];
    char unk0x00C[0x38];
    unsigned char nPrgDamage;
    char unk0x045[0x0F];
    short wAuraStat[6];
    char unk0x060[0x20];
    short nAuraState;
    char unk0x082[0x66];
    short wCltMissile[4];
    char unk0x0F0[0x58];
    int dwParam[8];
    char unk0x168[0xD4];
};

struct D2MonStatsTxt
{
    char unk0x000[0x14];
    short wMonSound;
    char unk0x016[0x15A];
    short nSkill[8];
    char unk0x180[0x28];
};

struct D2MonSoundsTxt
{
    char unk0x00[0x44];
    int dwSkill[4];
};

struct D2DataTablesStrc
{
    char unk0x000[0xC4];
    int nStatesTxtRecordCount;
    char unk0x0C8[0xA4];
    short* pProgressiveStates;
    short nProgressiveStates;
    char unk0x172[0x906];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0x04];
    int nMonStatsTxtRecordCount;
    char unk0xA84[0x114];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
    char unk0xBA4[0x30];
    int nItemStatCostTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks_006CE268[];                                                                 // 0x006CE268

D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);              // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625D00
D2MonSoundsTxt* __stdcall DATATBLS_GetMonSoundsTxtRecordFromSoundId(int nSoundId);                          // 0x00656F90

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x004E6C70
int __fastcall sub_004E6C70(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[4];
}

// 0x004E6CA0
int __fastcall sub_004E6CA0_GetSkillParamByLevel(int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nSkillLevel <= 0)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[0] + (nSkillLevel - 1) * pSkillsTxtRecord->dwParam[1];
}

// 0x004E6FF0
int __cdecl sub_004E6FF0_SumProgressiveBonus()
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (!pPlayer)
    {
        return 0;
    }

    int nSum = 0;
    for (int i = 0; i < sgptDataTables->nProgressiveStates; ++i)
    {
        if (!STATES_CheckState(pPlayer, sgptDataTables->pProgressiveStates[i]))
        {
            continue;
        }

        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pPlayer, sgptDataTables->pProgressiveStates[i]);
        if (!pStatList)
        {
            continue;
        }

        const int nSkillId = STATLIST_GetStatValue(pStatList, 0x15E, 0);
        if (nSkillId <= 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
        {
            continue;
        }

        D2SkillsTxt* pSkillsTxtRecord = &sgptDataTables->pSkillsTxt[nSkillId];
        if (!pSkillsTxtRecord)
        {
            continue;
        }

        const int nSkillLevel = STATLIST_GetStatValue(pStatList, 0x15F, 0);
        if (nSkillLevel <= 0 || pSkillsTxtRecord->nPrgDamage != 1)
        {
            continue;
        }

        if (pSkillsTxtRecord->wAuraStat[0] < 0 || pSkillsTxtRecord->wAuraStat[0] >= sgptDataTables->nItemStatCostTxtRecordCount)
        {
            continue;
        }

        const int nValue = STATLIST_GetStatValue(pStatList, pSkillsTxtRecord->wAuraStat[0], 0);
        if (nValue > 0)
        {
            nSum += sub_004E6CA0_GetSkillParamByLevel(nSkillId, nSkillLevel) * nValue;
        }
    }

    return nSum;
}

// 0x004EFC20
int __fastcall sub_004EFC20_GetSkillParam2(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[1];
}

// 0x004EFC50
int __fastcall sub_004EFC50_GetSkillParam3(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[2];
}

// 0x004EFC80
int __fastcall sub_004EFC80_FourthSkillParam(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[3];
}

// 0x004EFCB0
int __fastcall sub_004EFCB0_GetSummonLevel(int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nSkillLevel <= 0)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[4] + (nSkillLevel - 1) * pSkillsTxtRecord->dwParam[5];
}

// build: context sub_004F21B0_GetCltMissileId
int __fastcall sub_004F21B0_GetCltMissileId(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = 0;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        pSkillsTxtRecord = &sgptDataTables->pSkillsTxt[nSkillId];
    }

    if (!pSkillsTxtRecord)
    {
        return -1;
    }

    if (pSkillsTxtRecord->nFlags[2 >> 3] & gdwBitMasks_006CE268[2 & 7] && pSkillsTxtRecord->nAuraState >= 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount)
    {
        if (pSkillsTxtRecord->wAuraStat[0] >= 0 && pSkillsTxtRecord->wAuraStat[0] < sgptDataTables->nItemStatCostTxtRecordCount)
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
            if (pStatList)
            {
                int nIndex = STATLIST_GetStatValue(pStatList, pSkillsTxtRecord->wAuraStat[0], 0);
                if (nIndex > 1)
                {
                    if (nIndex >= 3)
                    {
                        nIndex = 3;
                    }
                }
                else
                {
                    nIndex = 1;
                }

                return pSkillsTxtRecord->wCltMissile[nIndex];
            }
        }
    }

    return pSkillsTxtRecord->wCltMissile[1];
}

// 0x004F4110
int __fastcall sub_004F4110_GetSkillParam5(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[5];
}

// 0x004F4F40
int __fastcall sub_004F4F40_GetMonSkillSound(D2UnitStrc* pUnit, int nSkillId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = 0;
    if (pUnit)
    {
        const int nClassId = pUnit->dwClassId;
        if (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            pMonStatsTxtRecord = &sgptDataTables->pMonStatsTxt[nClassId];
        }
    }

    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    D2MonSoundsTxt* pMonSoundsTxtRecord = DATATBLS_GetMonSoundsTxtRecordFromSoundId(pMonStatsTxtRecord->wMonSound);
    if (!pMonSoundsTxtRecord)
    {
        return 0;
    }

    int nSound = 0;
    for (int i = 0; i < 8; ++i)
    {
        if (pMonStatsTxtRecord->nSkill[i] == nSkillId)
        {
            switch (i)
            {
            case 0:
                nSound = pMonSoundsTxtRecord->dwSkill[0];
                break;

            case 1:
                nSound = pMonSoundsTxtRecord->dwSkill[1];
                break;

            case 2:
                nSound = pMonSoundsTxtRecord->dwSkill[2];
                break;

            case 3:
                nSound = pMonSoundsTxtRecord->dwSkill[3];
                break;
            }
        }
    }

    return nSound < 0 ? 0 : nSound;
}
