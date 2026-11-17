struct D2GameStrc;

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_INVALID 6
#define PLRMODE_DEATH 0
#define PLRMODE_DEAD 17
#define MONMODE_DEATH 0
#define MONMODE_DEAD 12
#define SKILLSFLAGINDEX_TARGETPET 25

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0xB0];
    unsigned int dwFlags;
};

struct D2SkillsTxt
{
    char unk0x00[4];
    unsigned char nFlags[8];
    char unk0x0C[0x230];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[4];
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

void __fastcall AIGENERAL_GetOwnerData(D2UnitStrc* pUnit, int* pOwnerGUID, int* pOwnerType);               // 0x0058F090

static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId < 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
    {
        return 0;
    }

    return &sgptDataTables->pSkillsTxt[nSkillId];
}

static __forceinline int SUNIT_GetUnitGUIDInline(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwUnitId;
    }

    return -1;
}

// 0x005541B0
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 1;
    }

    int bFlag = 0;
    if (pUnit)
    {
        bFlag = (pUnit->dwFlags >> 16) & 1;
    }

    if (bFlag)
    {
        return 1;
    }

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        if (pUnit->dwAnimMode == PLRMODE_DEATH || pUnit->dwAnimMode == PLRMODE_DEAD)
        {
            return 1;
        }
        return 0;

    case UNIT_MONSTER:
        if (pUnit->dwAnimMode == MONMODE_DEATH || pUnit->dwAnimMode == MONMODE_DEAD)
        {
            return 1;
        }
        return 0;
    }

    return 1;
}

// 0x005542C0
int __fastcall SUNIT_CanPetBeTargetedBySkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pPet, int nSkillId)
{
    if (!pOwner || !pPet)
    {
        return 0;
    }

    const int nOwnerUnitType = pOwner ? pOwner->dwUnitType : UNIT_INVALID;
    if (nOwnerUnitType != UNIT_PLAYER && pPet->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || !(pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_TARGETPET >> 3] & gdwBitMasks[SKILLSFLAGINDEX_TARGETPET & 7]))
    {
        return 0;
    }

    int nOwnerGUID;
    int nOwnerType;
    AIGENERAL_GetOwnerData(pPet, &nOwnerGUID, &nOwnerType);
    if (nOwnerType != UNIT_PLAYER || nOwnerGUID != SUNIT_GetUnitGUIDInline(pOwner))
    {
        return 0;
    }

    return 1;
}
