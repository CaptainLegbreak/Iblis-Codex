struct D2DynamicPathStrc;
struct D2StatListStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x18];
    int dwUnk0x28;
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0x94];
    unsigned int dwFlags;
};

struct D2SkillsTxt
{
    char unk0x000[0x04];
    unsigned char nFlags[8];
    char unk0x00C[0x48];
    short wProgressiveStat;
    char unk0x056[0x2A];
    short wProgressiveState;
    char unk0x082[0x66];
    short wCltMissile;
    char unk0x0EA[0x0C];
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
    char unk0x000[0xC4];
    int nStatesTxtRecordCount;
    char unk0x0C8[0xAD0];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
    char unk0xBA4[0x30];
    int nItemStatCostTxtRecordCount;
};

typedef int (__fastcall* CLIENTSKILLDOFN)(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern int gnClientSkillDoFuncs_00727DB0;                                                                   // 0x00727DB0
extern CLIENTSKILLDOFN gpfnClientSkillDoFuncs_00727BA8[];                                                   // 0x00727BA8
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

D2UnitStrc* __fastcall sub_004648F0_GetTargetUnit(D2UnitStrc* pUnit);                                       // 0x004648F0
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY);                         // 0x004C52E0
void __fastcall sub_004C5420_RequestAtTarget(D2UnitStrc* pUnit, int nMissile, int nSkillId, int nSkillLevel); // 0x004C5420
D2UnitStrc* __fastcall sub_004CDC30(D2UnitStrc* pUnit, int nMissile, int nOffsetX, int nOffsetY, int nTargetX, int nTargetY, int nSkillId, int nSkillLevel, int nRange); // 0x004CDC30
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit);               // 0x00620C10
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY);                   // 0x00648AD0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall sub_006252D0(D2StatListStrc* pStatList, int nState);                                       // 0x006252D0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150

#define SKILLSFLAGINDEX_LOB 1
#define SKILLSFLAGINDEX_PRGSTACK 7

static D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x004C6AC0
void __fastcall sub_004C6AC0_DoSkill(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel, int nX, int nY, int nCharges)
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

    if (pSkillsTxtRecord->wProgressiveState < 0 || pSkillsTxtRecord->wProgressiveState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return;
    }

    if (pSkillsTxtRecord->wProgressiveStat < 0 || pSkillsTxtRecord->wProgressiveStat >= sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->wProgressiveState);
    if (!pStatList)
    {
        pStatList = STATLIST_AllocStatList(0, 0, 0, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
        if (!pStatList)
        {
            return;
        }

        sub_006252D0(pStatList, pSkillsTxtRecord->wProgressiveState);
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        STATLIST_SetStatIfListIsValid(pStatList, pSkillsTxtRecord->wProgressiveStat, nCharges, 0);
    }

    int nTargetX;
    int nTargetY;
    const int bHasTargetPos = sub_004C52E0_GetTargetPosition(pUnit, &nTargetX, &nTargetY);
    D2UnitStrc* pOldTarget = sub_004648F0_GetTargetUnit(pUnit);

    if (pTarget)
    {
        UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
    }
    else if (nX && nY)
    {
        D2COMMON_10170_PathSetTargetPos(pUnit->pDynamicPath, nX, nY);
    }

    const int nOldValue = pUnit->dwUnk0x28;
    if (nX && !nY)
    {
        pUnit->dwUnk0x28 = nX;
    }

    --nCharges;
    if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_PRGSTACK >> 3] & gdwBitMasks[SKILLSFLAGINDEX_PRGSTACK & 7])
    {
        for (int i = 0; i < nCharges; ++i)
        {
            if (gpfnClientSkillDoFuncs_00727BA8[pSkillsTxtRecord->wCltPrgFunc[i]])
            {
                STATLIST_SetStatIfListIsValid(pStatList, pSkillsTxtRecord->wProgressiveStat, i + 1, 0);
                gpfnClientSkillDoFuncs_00727BA8[pSkillsTxtRecord->wCltPrgFunc[i]](pUnit, nSkillId, nSkillLevel);
            }
        }

        STATLIST_SetStatIfListIsValid(pStatList, pSkillsTxtRecord->wProgressiveStat, nCharges + 1, 0);
    }

    const short nFunc = pSkillsTxtRecord->wCltPrgFunc[nCharges];
    if (nFunc >= 0 && nFunc < gnClientSkillDoFuncs_00727DB0)
    {
        if (pSkillsTxtRecord->wCltMissile > 0)
        {
            if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_LOB >> 3] & gdwBitMasks[SKILLSFLAGINDEX_LOB & 7])
            {
                int nMissileX;
                int nMissileY;
                sub_004C52E0_GetTargetPosition(pUnit, &nMissileX, &nMissileY);
                sub_004CDC30(pUnit, pSkillsTxtRecord->wCltMissile, 0, 0, nMissileX, nMissileY, nSkillId, nSkillLevel, 0);
            }
            else
            {
                sub_004C5420_RequestAtTarget(pUnit, pSkillsTxtRecord->wCltMissile, nSkillId, nSkillLevel);
            }

            pUnit->dwFlags |= 0x40;
        }

        if (gpfnClientSkillDoFuncs_00727BA8[pSkillsTxtRecord->wCltPrgFunc[nCharges]])
        {
            if (gpfnClientSkillDoFuncs_00727BA8[pSkillsTxtRecord->wCltPrgFunc[nCharges]](pUnit, nSkillId, nSkillLevel))
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
        }
        else
        {
            pUnit->dwFlags |= 0x40;
        }
    }

    UNITS_SetTargetUnitForDynamicUnit(pUnit, pOldTarget);
    if (bHasTargetPos)
    {
        D2COMMON_10170_PathSetTargetPos(pUnit->pDynamicPath, nTargetX, nTargetY);
    }

    if (nX && !nY)
    {
        pUnit->dwUnk0x28 = nOldValue;
    }
}

#include "gen/data/Source/D2Client/004C6AC0_sub_004C6AC0_DoSkill.inc"
