struct D2DynamicPathStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x24];
    int dwUnk0x28;
    D2DynamicPathStrc* pDynamicPath;
};

struct D2SkillsTxt
{
    char unk0x000[0xF6];
    short wCltPrgFunc[3];
    char unk0x0FC[0x04];
    short wDoSound;
    char unk0x102[0x06];
    short wTgtOverlay;
    short wTgtSound;
    char unk0x10C[0x130];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

typedef int (__fastcall* CLIENTSKILLDOFN)(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern int gnClientSkillDoFuncs_00727DB0;                                                                   // 0x00727DB0
extern CLIENTSKILLDOFN gpfnClientSkillDoFuncs_00727BA8[];                                                   // 0x00727BA8

D2UnitStrc* __fastcall sub_004648F0_GetTargetUnit(D2UnitStrc* pUnit);                                       // 0x004648F0
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY);                         // 0x004C52E0
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit);               // 0x00620C10
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY);                   // 0x00648AD0

static D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x004C6930
void __fastcall sub_004C6930_DoSkillPrgFunc(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel, int nX, int nY, unsigned char nMode)
{
    if (!pUnit)
    {
        return;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    const int nOldValue = pUnit->dwUnk0x28;
    int nTargetX;
    int nTargetY;
    const int bHasTargetPos = sub_004C52E0_GetTargetPosition(pUnit, &nTargetX, &nTargetY);
    D2UnitStrc* pOldTarget = sub_004648F0_GetTargetUnit(pUnit);

    if (pTarget)
    {
        UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
        pUnit->dwUnk0x28 = nMode;
    }
    else if (nX && nY)
    {
        D2COMMON_10170_PathSetTargetPos(pUnit->pDynamicPath, nX, nY);
        pUnit->dwUnk0x28 = nMode;
    }

    if (nX && !nY)
    {
        pUnit->dwUnk0x28 = nX;
    }

    const short nFunc = pSkillsTxtRecord->wCltPrgFunc[0];
    if (nFunc >= 0 && nFunc < gnClientSkillDoFuncs_00727DB0 && gpfnClientSkillDoFuncs_00727BA8[nFunc]
        && gpfnClientSkillDoFuncs_00727BA8[nFunc](pUnit, nSkillId, nSkillLevel))
    {
        if (pSkillsTxtRecord->wDoSound > 0)
        {
            sub_004B9A00(pSkillsTxtRecord->wDoSound, pUnit, 0, 0, 0);
        }

        if (pSkillsTxtRecord->wTgtSound > 0)
        {
            D2UnitStrc* pCurrentTarget = sub_004648F0_GetTargetUnit(pUnit);
            if (pCurrentTarget)
            {
                sub_004B9A00(pSkillsTxtRecord->wTgtSound, pCurrentTarget, 0, 0, 0);
            }
        }

        if (pSkillsTxtRecord->wTgtOverlay > 0)
        {
            D2UnitStrc* pCurrentTarget = sub_004648F0_GetTargetUnit(pUnit);
            if (pCurrentTarget)
            {
                sub_00470390(pCurrentTarget, pSkillsTxtRecord->wTgtOverlay, 2, 0, 0, 0, 0, 0);
            }
        }
    }

    UNITS_SetTargetUnitForDynamicUnit(pUnit, pOldTarget);
    if (bHasTargetPos && !pOldTarget)
    {
        D2COMMON_10170_PathSetTargetPos(pUnit->pDynamicPath, nTargetX, nTargetY);
    }

    pUnit->dwUnk0x28 = nOldValue;
}
