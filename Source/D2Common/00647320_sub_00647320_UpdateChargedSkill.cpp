typedef unsigned int size_t;
extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize);                                    // 0x00681EF0

struct D2SkillsTxt
{
    short nSkillId;
    char unk0x002[0x010 - 0x002];
    signed char nAnim;
    signed char nMonAnim;
    char unk0x012[0x23C - 0x012];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

struct D2SkillStrc
{
    D2SkillsTxt* pSkillsTxt;
    D2SkillStrc* pNextSkill;
    int dwSkillMode;
    char unk0x0C[0x28 - 0x0C];
    int nSkillLevel;
    int nLevelBonus;
    int nQuantity;
    int nOwnerGUID;
    int nCharges;
    int dwFlags;
};

struct D2SkillListStrc
{
    void* pMemPool;
    D2SkillStrc* pFirstSkill;
    D2SkillStrc* pLeftSkill;
    D2SkillStrc* pRightSkill;
    D2SkillStrc* pUsedSkill;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    char unk0x0C[0xA8 - 0x0C];
    D2SkillListStrc* pSkills;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
void __fastcall FOG_FreePool(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0);         // 0x0040B480
void __stdcall SKILLS_SetLeftActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                  // 0x00643BC0
void __stdcall SKILLS_SetRightActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                 // 0x00643C50

static __forceinline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static __forceinline void SKILLS_RemoveChargedSkill(D2UnitStrc* pUnit, D2SkillListStrc* pSkillList, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nOwnerGUID)
{
    D2SkillStrc* pLeftSkill = pSkillList->pLeftSkill;
    D2SkillStrc* pRightSkill = pSkillList->pRightSkill;
    const int nRightSkillId = pRightSkill->pSkillsTxt->nSkillId;
    const int nLeftSkillId = pLeftSkill->pSkillsTxt->nSkillId;
    if (nSkillId == nLeftSkillId && pLeftSkill->nOwnerGUID == nOwnerGUID)
    {
        SKILLS_SetLeftActiveSkill(pUnit, 0, -1);
    }

    if (nSkillId == nRightSkillId && pRightSkill->nOwnerGUID == nOwnerGUID)
    {
        SKILLS_SetRightActiveSkill(pUnit, 0, -1);
    }

    if (pSkillList->pUsedSkill && nSkillId == pSkillList->pUsedSkill->pSkillsTxt->nSkillId)
    {
        pSkillList->pUsedSkill = 0;
    }

    D2SkillStrc* pPreviousSkill = 0;
    D2SkillStrc* pSkill = pSkillList->pFirstSkill;
    while (pSkill && (pSkill->nOwnerGUID != nOwnerGUID || pSkill->pSkillsTxt != pSkillsTxtRecord))
    {
        pPreviousSkill = pSkill;
        pSkill = pSkill->pNextSkill;
    }

    if (pSkill)
    {
        if (pPreviousSkill)
        {
            pPreviousSkill->pNextSkill = pSkill->pNextSkill;
        }
        else
        {
            pSkillList->pFirstSkill = pSkill->pNextSkill;
        }

        FOG_FreePool(pUnit->pMemoryPool, pSkill, ".\\SKILLS\\Skills.cpp", 1511, 0);
    }
}

// 0x00647320
void __stdcall sub_00647320_UpdateChargedSkill(D2UnitStrc* pUnit, int nOwnerGUID, int nSkillId, int nSkillLevel, int nCharges, int bRemove)
{
    if (!pUnit || pUnit->dwUnitType != 0)
    {
        return;
    }

    if (nSkillLevel <= 0)
    {
        return;
    }

    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    D2SkillListStrc* pSkillList = pUnit->pSkills;
    if (!pSkillList)
    {
        return;
    }

    if (bRemove)
    {
        SKILLS_RemoveChargedSkill(pUnit, pSkillList, pSkillsTxtRecord, nSkillId, nOwnerGUID);
        return;
    }

    D2SkillStrc* pPreviousSkill = 0;
    D2SkillStrc* pFoundSkill = pSkillList->pFirstSkill;
    while (pFoundSkill && (pFoundSkill->nOwnerGUID != nOwnerGUID || pFoundSkill->pSkillsTxt != pSkillsTxtRecord))
    {
        pPreviousSkill = pFoundSkill;
        pFoundSkill = pFoundSkill->pNextSkill;
    }

    if (pFoundSkill)
    {
        pFoundSkill->nSkillLevel = nSkillLevel;
        pFoundSkill->dwFlags = 1;
        pFoundSkill->nCharges = nCharges;
        return;
    }

    D2SkillStrc* pSkill = (D2SkillStrc*)FOG_AllocPool(pSkillList->pMemPool, sizeof(D2SkillStrc), ".\\SKILLS\\Skills.cpp", 1534, 0);
    memset(pSkill, 0x00, sizeof(D2SkillStrc));
    pSkill->pSkillsTxt = pSkillsTxtRecord;
    switch (pSkillsTxtRecord->nAnim)
    {
    case 7:
        pSkill->dwSkillMode = pSkillsTxtRecord->nAnim;
        break;

    case 8:
        pSkill->dwSkillMode = pSkillsTxtRecord->nAnim;
        break;

    case 10:
        pSkill->dwSkillMode = pSkillsTxtRecord->nAnim;
        break;

    case 11:
        pSkill->dwSkillMode = pSkillsTxtRecord->nAnim;
        break;

    case 18:
        pSkill->dwSkillMode = pSkillsTxtRecord->nAnim;
        break;

    default:
        pSkill->dwSkillMode = 10;
        break;
    }

    pSkill->nSkillLevel = nSkillLevel;
    pSkill->dwFlags = 1;
    pSkill->nCharges = nCharges;
    pSkill->nOwnerGUID = nOwnerGUID;
    pSkill->pNextSkill = 0;
    if (pPreviousSkill)
    {
        pPreviousSkill->pNextSkill = pSkill;
    }
    else
    {
        pSkillList->pFirstSkill = pSkill;
    }
}
