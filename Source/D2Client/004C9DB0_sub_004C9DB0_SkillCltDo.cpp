struct D2SkillStrc;
struct D2DynamicPathStrc;
struct D2AnimSeqTxt;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x2C - 0x14];
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0x38 - 0x30];
    int nSeqFrame;
    char unk0x3C[0x48 - 0x3C];
    int nSeqValue;
    char unk0x4C[0x4E - 0x4C];
    unsigned char nSeqState;
    char unk0x4F[0xC4 - 0x4F];
    unsigned int dwFlags;
};

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0
D2AnimSeqTxt* __stdcall DATATBLS_GetMonSeqTxtRecordFromUnit(D2UnitStrc* pUnit); // 0x006633B0
int __stdcall DATATBLS_GetSeqFrameCount(D2UnitStrc* pUnit); // 0x006633F0
int __fastcall sub_004C9D70(D2UnitStrc* pUnit); // 0x004C9D70
void __fastcall sub_004CB6A0(D2UnitStrc* pUnit, int nMode, int nArg); // 0x004CB6A0
int __stdcall SKILLS_GetParam1(D2SkillStrc* pSkill); // 0x006444A0
int __stdcall SKILLS_GetParam2(D2SkillStrc* pSkill); // 0x006444D0
int __stdcall SKILLS_GetParam3(D2SkillStrc* pSkill); // 0x00644500
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560
void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue); // 0x006445A0
void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue); // 0x006445E0
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nFlags); // 0x00644660
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType); // 0x00463990
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus); // 0x00622C40
void __stdcall UNITS_SetAnimationFrame(D2UnitStrc* pUnit, int nFrame); // 0x006212C0
D2UnitStrc* __fastcall sub_004C5EB0_ScanFind(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nArg5, int nUnitId, int nArg7); // 0x004C5EB0
int __fastcall sub_00463860(D2UnitStrc* pUnit); // 0x00463860
int __fastcall sub_00463900_GetValidMonsterId(int nMonsterId); // 0x00463900
void __stdcall D2Common_10216(D2DynamicPathStrc* pPath, int nX, int nY, int a4); // 0x00649EF0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

static __forceinline int sub_GetUnitTypeChecked(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwUnitType;
    }
    return 6;
}

static __forceinline int sub_GetUnitGUIDChecked(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwUnitId;
    }
    return -1;
}

// 0x004C9DB0
int __fastcall sub_004C9DB0_SkillCltDo(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    const int nFlags = SKILLS_GetFlags(pSkill);
    int nFrameCount = 15;
    if (DATATBLS_GetMonSeqTxtRecordFromUnit(pUnit))
    {
        nFrameCount = DATATBLS_GetSeqFrameCount(pUnit);
    }

    const int nEventFrame = sub_004C9D70(pUnit);
    if (pUnit && (pUnit->dwUnitType == 0 || pUnit->dwUnitType == 1) && pUnit->nSeqState == 3)
    {
        sub_004CB6A0(pUnit, pUnit->dwAnimMode, 0);
        return 0;
    }

    D2UnitStrc* pTarget = 0;
    const int nTargetType = SKILLS_GetParam1(pSkill);
    const int nTargetId = SKILLS_GetParam2(pSkill);
    if (nTargetType != 6)
    {
        pTarget = sub_00463990(nTargetId, nTargetType);
    }

    if (nFlags & 1)
    {
        if (pTarget && UNITS_IsInMeleeRange(pUnit, pTarget, 0))
        {
            SKILLS_SetFlags(pSkill, 0);
            UNITS_SetAnimationFrame(pUnit, nEventFrame + 1);
            pUnit->nSeqValue = nFrameCount << 8;
            return 1;
        }

        if (nFlags & 2)
        {
            D2UnitStrc* pFound = sub_004C5EB0_ScanFind(pUnit, 0, 0, 3, 3, nTargetId, 0);
            if (pFound && UNITS_IsInMeleeRange(pUnit, pFound, 0))
            {
                SKILLS_SetFlags(pSkill, 0);
                SKILLS_SetParam1(pSkill, sub_GetUnitTypeChecked(pFound));
                SKILLS_SetParam2(pSkill, sub_GetUnitGUIDChecked(pFound));
                return 1;
            }

            SKILLS_SetFlags(pSkill, 0);
            if (pUnit && pUnit->dwUnitType == 1)
            {
                switch (sub_00463900_GetValidMonsterId(sub_00463860(pUnit)))
                {
                case 0x1B4:
                case 0x1B9:
                    return 1;
                }
            }

            pUnit->nSeqValue = 0x100;
            return 1;
        }

        if ((pUnit->nSeqFrame >> 8) >= nEventFrame)
        {
            UNITS_SetAnimationFrame(pUnit, 0);
            pUnit->nSeqValue = nFrameCount << 8;
            SKILLS_SetFlags(pSkill, 1);
        }

        pUnit->dwFlags &= ~0x40;
        int nState = SKILLS_GetParam3(pSkill);
        if (nState < 2)
        {
            ++nState;
        }
        SKILLS_SetParam3(pSkill, nState);
        return 1;
    }

    SKILLS_SetFlags(pSkill, 0);
    SKILLS_SetParam1(pSkill, 0);
    SKILLS_SetParam2(pSkill, 0);
    pUnit->nSeqValue = (nFrameCount - (pUnit->nSeqFrame >> 8)) << 8;
    if (!pTarget)
    {
        pTarget = sub_004C5EB0_ScanFind(pUnit, 0, 0, 3, 3, -1, 0);
        if (!pTarget)
        {
            return 0;
        }
    }

    D2Common_10216(pUnit->pDynamicPath, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget), 0);
    return 1;
}
