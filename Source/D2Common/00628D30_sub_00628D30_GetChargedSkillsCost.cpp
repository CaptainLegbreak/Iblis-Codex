struct D2UnitStrc;

struct D2StatStrc
{
    unsigned short nLayer;
    unsigned short nStatId;
    int nValue;
};

struct D2SkillsTxt
{
    char unk0x000[0x174];
    short wReqLevel;
    char unk0x176[0x234 - 0x176];
    int dwCostMult;
    int dwCostAdd;
};

struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
    char unk0xBA4[0xC6C - 0xBA4];
    int nStuff;
    int nShiftedStuff;
};

#define STAT_ITEM_CHARGED_SKILL 204

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int __stdcall STATLIST_CopyStats(D2UnitStrc* pUnit, int nStatId, D2StatStrc* pBuffer, int nBufferSize);     // 0x006261D0

static D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x00628D30
int __fastcall sub_00628D30_GetChargedSkillsCost(D2UnitStrc* pItem, int nBaseCost)
{
    D2StatStrc pStat[64];

    const int nStats = STATLIST_CopyStats(pItem, STAT_ITEM_CHARGED_SKILL, pStat, 64);
    int nCost = 0;
    int i = 0;
    if (nStats > 0)
    {
        do
        {
            const int nLayer = pStat[i].nLayer;
            const int nSkillId = nLayer >> sgptDataTables->nStuff;
            const int nSkillLevel = nLayer & sgptDataTables->nShiftedStuff;
            const int nMaxCharges = pStat[i].nValue >> 8;
            const int nCharges = pStat[i].nValue & 0xFF;
            if (nCharges < nMaxCharges)
            {
                D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
                if (pSkillsTxtRecord)
                {
                    int nChargeCost;
                    if ((nSkillLevel + 2 * (pSkillsTxtRecord->wReqLevel / 6) + 2) * nBaseCost > 0xFFFF && pSkillsTxtRecord->dwCostMult)
                    {
                        nChargeCost = (nSkillLevel + 2 * (pSkillsTxtRecord->wReqLevel / 6) + 2) * nBaseCost / 1024 * pSkillsTxtRecord->dwCostMult;
                        nChargeCost += pSkillsTxtRecord->dwCostAdd;
                    }
                    else
                    {
                        nChargeCost = pSkillsTxtRecord->dwCostMult * (nSkillLevel + 2 * (pSkillsTxtRecord->wReqLevel / 6) + 2) * nBaseCost / 1024;
                        nChargeCost += pSkillsTxtRecord->dwCostAdd;
                    }
                    nCost += (nMaxCharges - nCharges) * nChargeCost / nMaxCharges;
                }
            }
            ++i;
        }
        while (i < nStats);
    }

    return nCost;
}
