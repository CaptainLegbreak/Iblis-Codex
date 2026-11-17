struct D2UnitStrc;
struct D2StatListStrc;

struct D2SkillsTxt
{
    short nSkillId;
    char unk0x002[0x02];
    unsigned char nFlags[8];
    char unk0x00C[0x48];
    short wAuraStat[6];
    char unk0x060[0x20];
    short nAuraState;
    char unk0x082[0x8A];
    short wPrgOverlay;
    short wPrgSound;
    char unk0x110[0x12C];
};

struct D2DataTablesStrc
{
    char unk0x000[0xC4];
    int nStatesTxtRecordCount;
    char unk0x0C8[0xAD0];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
    char unk0xBA4[0x30];
    int nItemStatCostTxtRecordCount;
};

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const unsigned int gdwBitMasks[32];                                                                  // 0x006CE268

D2UnitStrc* __fastcall sub_004648F0_GetTargetUnit(D2UnitStrc* pUnit);                                       // 0x004648F0
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625D00

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x004F30A0
int __fastcall sub_004F30A0_TargetPrgOverlay(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = sub_004648F0_GetTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    int nOverlay;
    int nSound;
    D2StatListStrc* pStatList;
    if ((pSkillsTxtRecord->nFlags[2 >> 3] & gdwBitMasks[2 & 7])
        && pSkillsTxtRecord->nAuraState >= 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount
        && pSkillsTxtRecord->wAuraStat[0] >= 0 && pSkillsTxtRecord->wAuraStat[0] < sgptDataTables->nItemStatCostTxtRecordCount
        && (pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState)) != 0)
    {
        const int nLevel = STATLIST_GetStatValue(pStatList, pSkillsTxtRecord->wAuraStat[0], 0);
        const int nBonus = MIN(MAX(nLevel, 1), 3) - 1;
        nOverlay = pSkillsTxtRecord->wPrgOverlay + nBonus;
        nSound = pSkillsTxtRecord->wPrgSound + nBonus;
    }
    else
    {
        nOverlay = pSkillsTxtRecord->wPrgOverlay;
        nSound = pSkillsTxtRecord->wPrgSound;
    }

    sub_00470390(pTarget, nOverlay, 2, 0, 0, 0, 0, 0);
    sub_004B9A00(nSound, pUnit, 0, 0, 0);
    return 1;
}

// 0x004F31A0
int __fastcall sub_004F31A0_PrgOverlay(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nOverlay;
    int nSound;
    D2StatListStrc* pStatList;
    if ((pSkillsTxtRecord->nFlags[2 >> 3] & gdwBitMasks[2 & 7])
        && pSkillsTxtRecord->nAuraState >= 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount
        && pSkillsTxtRecord->wAuraStat[0] >= 0 && pSkillsTxtRecord->wAuraStat[0] < sgptDataTables->nItemStatCostTxtRecordCount
        && (pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState)) != 0)
    {
        const int nLevel = STATLIST_GetStatValue(pStatList, pSkillsTxtRecord->wAuraStat[0], 0);
        const int nBonus = MIN(MAX(nLevel, 1), 3) - 1;
        nOverlay = pSkillsTxtRecord->wPrgOverlay + nBonus;
        nSound = pSkillsTxtRecord->wPrgSound + nBonus;
    }
    else
    {
        nOverlay = pSkillsTxtRecord->wPrgOverlay;
        nSound = pSkillsTxtRecord->wPrgSound;
    }

    sub_00470390(pUnit, nOverlay, 2, 0, 0, 0, 0, 0);
    sub_004B9A00(nSound, pUnit, 0, 0, 0);
    return 1;
}
