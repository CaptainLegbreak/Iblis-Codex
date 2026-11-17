struct D2DynamicPathStrc;
struct D2StatListStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int unk0x10[7];
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0x08];
    int dwSeqFrame;
    char unk0x3C[0x88];
    unsigned int dwFlags;
};

struct D2StatesTxt
{
    char unk0x00[0x34];
    short wCltActiveFunc;
    char unk0x36[0x06];
};

struct D2DataTablesStrc
{
    char unk0x00[0xBC];
    D2StatesTxt* pStatesTxt;
    char f_C0[0x04];
    int nStatesTxtRecordCount;
    char unk0xC8[0xBC];
    short* pActionStates;
    short nActionStates;
};

typedef int (__fastcall* CLIENTSKILLDOFN)(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern int gnClientSkillDoFuncs_00727DB0;                                                                   // 0x00727DB0
extern CLIENTSKILLDOFN gpfnClientSkillDoFuncs_00727BA8[];                                                   // 0x00727BA8

int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2UnitStrc* __fastcall sub_004648F0_GetTargetUnit(D2UnitStrc* pUnit);                                       // 0x004648F0
void __fastcall sub_004AF890(D2UnitStrc* pUnit, int nArg1, int nArg2);                                      // 0x004AF890
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00
D2UnitStrc* __fastcall sub_004C5EB0_FindDestination(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nArg5, int nUnitId, int nArg7); // 0x004C5EB0
int __fastcall sub_004CA4C0(D2UnitStrc* pUnit, int nArg);                                                   // 0x004CA4C0
int __stdcall sub_00621F60(D2UnitStrc* pUnit);                                                              // 0x00621F60
int __fastcall sub_00623C20(D2UnitStrc* pUnit);                                                             // 0x00623C20
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625D00
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __stdcall sub_0063A340(D2UnitStrc* pUnit);                                                              // 0x0063A340
int __stdcall D2COMMON_11018(D2UnitStrc* pUnit);                                                            // 0x00645590
int __stdcall D2COMMON_11019(D2UnitStrc* pUnit);                                                            // 0x006455E0
void __stdcall sub_006488A0_SetDirection(D2DynamicPathStrc* pPath, int nDirection);                         // 0x006488A0
void __stdcall D2Common_10216(D2DynamicPathStrc* pPath, int nX, int nY, int a4);                            // 0x00649EF0

inline D2StatesTxt* SKILLS_GetStatesTxtRecord(int nStateId)
{
    if (nStateId >= 0 && nStateId < sgptDataTables->nStatesTxtRecordCount)
    {
        return &sgptDataTables->pStatesTxt[nStateId];
    }

    return 0;
}

// 0x004C72F0
void __fastcall sub_004C72F0(D2UnitStrc* pUnit)
{
    if (!sub_0063A340(pUnit))
    {
        return;
    }

    for (int i = 0; i < sgptDataTables->nActionStates; ++i)
    {
        const short nState = sgptDataTables->pActionStates[i];
        if (STATES_CheckState(pUnit, nState))
        {
            D2StatesTxt* pStatesTxtRecord = SKILLS_GetStatesTxtRecord(nState);
            if (pStatesTxtRecord && pStatesTxtRecord->wCltActiveFunc >= 0 && pStatesTxtRecord->wCltActiveFunc < gnClientSkillDoFuncs_00727DB0
                && gpfnClientSkillDoFuncs_00727BA8[pStatesTxtRecord->wCltActiveFunc])
            {
                int nA = 0;
                int nB = 1;
                D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
                if (pStatList)
                {
                    nA = STATLIST_GetStatValue(pStatList, 0x15E, 0);
                    nB = STATLIST_GetStatValue(pStatList, 0x15F, 0);
                }
                gpfnClientSkillDoFuncs_00727BA8[pStatesTxtRecord->wCltActiveFunc](pUnit, nA, nB);
            }
        }
    }
}

// 0x004C7470
void __fastcall sub_004C7470_SetMissileDirection(D2UnitStrc* pMissile, int nDirection)
{
    sub_006488A0_SetDirection(pMissile->pDynamicPath, nDirection);
}

// 0x004C7C90
int __fastcall sub_004C7C90_TestTarget11018(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = sub_004648F0_GetTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    return D2COMMON_11018(pTarget) != 0;
}

// 0x004C7CB0
int __fastcall sub_004C7CB0_SetTargetMode5(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = sub_004648F0_GetTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    sub_004AF890(pTarget, 5, 0);
    return 1;
}

// 0x004C7D50
int __fastcall sub_004C7D50_LeapToTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if ((pUnit->dwSeqFrame & ~0xFF) < 0x600)
    {
        sub_004B9A00(sub_004CA4C0(pUnit, sub_00623C20(pUnit)), pUnit, 4, 0, 0);
        D2UnitStrc* pTarget = sub_004648F0_GetTargetUnit(pUnit);
        if (pTarget && pUnit->pDynamicPath)
        {
            D2Common_10216(pUnit->pDynamicPath, UNITS_GetXPosition(pTarget), CLIENTS_GetUnitY(pTarget), 0);
        }
        return 1;
    }

    D2UnitStrc* pTarget = sub_004648F0_GetTargetUnit(pUnit);
    int nUnitId = -1;
    if (pTarget)
    {
        nUnitId = pTarget->dwUnitId;
    }
    D2UnitStrc* pDest = sub_004C5EB0_FindDestination(pUnit, 0, 0, 3, 0, nUnitId, 0);
    if (pDest && pUnit->pDynamicPath)
    {
        D2Common_10216(pUnit->pDynamicPath, UNITS_GetXPosition(pDest), CLIENTS_GetUnitY(pDest), 0);
    }
    return 1;
}

// 0x004C7EE0
int __fastcall sub_004C7EE0_TestTarget11019(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = sub_004648F0_GetTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    return D2COMMON_11019(pTarget) != 0;
}

// 0x004C7F00
int __fastcall sub_004C7F00_SetSoftTargetMode5(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = sub_004648F0_GetTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (!sub_00621F60(pTarget))
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    sub_004AF890(pTarget, 5, 0);
    return 1;
}

#include "gen/data/Source/D2Client/004C72F0_sub_004C72F0.inc"
