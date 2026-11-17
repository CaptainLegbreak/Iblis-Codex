extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

struct D2StatListStrc;
struct D2SkillStrc;
struct D2GfxLightStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x34];
    int nSeqCurrentFramePrecise;
};

struct D2MissilesTxt
{
    char unk0x00[0x130];
    unsigned char nLight;
    unsigned char nFlicker;
    unsigned char nRGB[3];
    char unk0x135[0x6F];
};

struct D2SkillsTxt
{
    char unk0x00[0x148];
    int dwParam[8];
    char unk0x168[0xD4];
};

struct D2AnimSeqTxt
{
    unsigned short wSequence;
    unsigned char nMode;
    unsigned char nFrame;
    unsigned char nDir;
    unsigned char nEvent;
};

struct D2DataTablesStrc
{
    char unk0x00[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x04];
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
};

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern int gaLevelVisited_007C78B8[];                                                                       // 0x007C78B8
extern int gnGlobal_007C88B8;                                                                               // 0x007C88B8
extern int gnGlobal_007C88BC;                                                                               // 0x007C88BC
extern int gnGlobal_007C88C0;                                                                               // 0x007C88C0
extern int gnGlobal_007C88C4;                                                                               // 0x007C88C4
extern int gnGlobal_007C88C8;                                                                               // 0x007C88C8

D2GfxLightStrc* __fastcall sub_00474160_MakeLightEntry(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6); // 0x00474160
void __fastcall sub_00474290(D2GfxLightStrc* pLight, int nRadius);                           // 0x00474290
void* __stdcall D2Common_10958(D2UnitStrc* pUnit, void* a2);                                                // 0x00643A00
void __fastcall sub_004743D0_ReleaseOverlayResource(void* pResource);                                       // 0x004743D0
int __fastcall sub_00479150_FindRosterIndex(int nUnitId);                                                   // 0x00479150
int __fastcall sub_0047A520(int nUnitId1, int nUnitId2);                                                    // 0x0047A520
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0
int __fastcall sub_004C6680_SkillDo(D2UnitStrc* pUnit, int nSkillId, int nArg, int nMode);                  // 0x004C6680
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0
void __fastcall sub_004C7890(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);                    // 0x004C7890
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
int __stdcall UNITS_GetMeleeRange(D2UnitStrc* pUnit);                                                       // 0x00622870
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627150
void __stdcall UNITS_UpdateAnimRateAndVelocity(D2UnitStrc* pUnit, const char* szFile, int nLine);          // 0x00623F50
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);         // 0x006439F0
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill);                                                         // 0x006446A0
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue);                                            // 0x00644660
void* __fastcall sub_004CA900_FindUnitSfxInRange(D2UnitStrc* pUnit, int nId);                              // 0x004CA900
void __fastcall sub_004BA840(void* pUnitSfx);                                                               // 0x004BA840
D2AnimSeqTxt* __stdcall DATATBLS_GetMonSeqTxtRecordFromUnit(D2UnitStrc* pUnit);                             // 0x006633B0
int __stdcall DATATBLS_GetSeqFrameCount(D2UnitStrc* pUnit);                                                 // 0x006633F0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0

static __forceinline D2MissilesTxt* DATATBLS_GetMissilesTxtRecordInline(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
        return &sgptDataTables->pMissilesTxt[nMissileId];
    return 0;
}

static __forceinline D2SkillsTxt* DATATBLS_GetSkillsTxtRecordInline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

// 0x004C5680
void __fastcall sub_004C5680_AttachMissileLight(D2UnitStrc* pUnit, int nMissileId)
{
    D2MissilesTxt* pMissilesTxt = DATATBLS_GetMissilesTxtRecordInline(nMissileId);
    if (pMissilesTxt->nLight)
    {
        D2GfxLightStrc* pLight = sub_00474160_MakeLightEntry(pUnit, 1, 1, 0xFF, pMissilesTxt->nRGB[0], pMissilesTxt->nRGB[1], pMissilesTxt->nRGB[2]);
        sub_00474290(pLight, pMissilesTxt->nLight);
        void* pOld = D2Common_10958(pUnit, pLight);
        if (pOld)
            sub_004743D0_ReleaseOverlayResource(pOld);
    }
}

// 0x004C5910
int __fastcall sub_004C5910(D2UnitStrc* pUnitA, D2UnitStrc* pUnitB)
{
    int nUnitIdB;
    if (!pUnitB)
    {
        nUnitIdB = -1;
    }
    else
    {
        nUnitIdB = pUnitB->dwUnitId;
        if (pUnitB->dwUnitType == 1)
        {
            nUnitIdB = sub_00479150_FindRosterIndex(nUnitIdB);
            if (nUnitIdB == -1)
                return 0;
        }
    }
    return sub_0047A520(!pUnitA ? -1 : pUnitA->dwUnitId, nUnitIdB) != 0;
}

// 0x004C68F0
int __fastcall sub_004C68F0_DoUsedSkill(D2UnitStrc* pUnit)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
        return 0;
    int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 0x697);
    int nLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
    return sub_004C6680_SkillDo(pUnit, nSkillId, nLevel, 0);
}

// 0x004C76D0
void __fastcall sub_004C76D0_ScaleFramePrecise(D2UnitStrc* pUnit, int nPercent)
{
    pUnit->nSeqCurrentFramePrecise = (pUnit->nSeqCurrentFramePrecise >> 8) * (100 - nPercent) / 100 << 8;
}

// 0x004C7950
void __fastcall sub_004C7950(D2UnitStrc* pUnit)
{
    D2StatListStrc* pStatList = STATLIST_AllocStatList(0, 6, 0x32, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
    if (pStatList)
    {
        STATLIST_SetStatRemoveCallback(pStatList, sub_004C7890);
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
    }
}

// 0x004C7BD0
int __fastcall sub_004C7BD0_GetMeleeRangePlus4(D2UnitStrc* pUnit)
{
    return UNITS_GetMeleeRange(pUnit) + 4;
}

// 0x004C7BE0
void __fastcall sub_004C7BE0_ApplyClientSkillCalc(D2UnitStrc* pUnit, int nValue)
{
    D2StatListStrc* pStatList = STATLIST_AllocStatList(0, 4, 0, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
    if (pStatList)
    {
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        STATLIST_SetStat(pStatList, 0x44, nValue, 0);
        UNITS_UpdateAnimRateAndVelocity(pUnit, ".\\SKILLS\\Skills.cpp", 0x9E5);
    }
}

// 0x004C9420
void __fastcall sub_004C9420(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (pSkill)
    {
        int nFlags = SKILLS_GetFlags(pSkill);
        if (nFlags & 1)
            SKILLS_SetFlags(pSkill, nFlags | 2);
    }
    sub_004BA840(sub_004CA900_FindUnitSfxInRange(pUnit, 0x9E3));
}

// 0x004C9460
int __fastcall sub_004C9460_GetSkillParam1(int nSkillId)
{
    D2SkillsTxt* pSkillsTxt = DATATBLS_GetSkillsTxtRecordInline(nSkillId);
    if (!pSkillsTxt)
        return 0;
    return pSkillsTxt->dwParam[0];
}

// 0x004C9D70
int __fastcall sub_004C9D70(D2UnitStrc* pUnit)
{
    D2AnimSeqTxt* pAnimSeqTxt = DATATBLS_GetMonSeqTxtRecordFromUnit(pUnit);
    if (pAnimSeqTxt)
    {
        int nFrames = DATATBLS_GetSeqFrameCount(pUnit);
        for (int i = 0; i < nFrames; i += 1)
        {
            if (!pAnimSeqTxt->nEvent)
                return i - 1;
        }
    }
    return 7;
}

// 0x004CA000
void __fastcall sub_004CA000(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    int nFlags = SKILLS_GetFlags(pSkill);
    if (nFlags & 1)
        SKILLS_SetFlags(pSkill, nFlags | 2);
    STATES_ToggleState(pUnit, 0x36, 0);
}

// 0x004CA280
void __cdecl sub_004CA280()
{
    gnGlobal_007C88B8 = 0;
    gnGlobal_007C88BC = 0;
    gnGlobal_007C88C0 = 0x5A;
    gnGlobal_007C88C4 = 0;
    gnGlobal_007C88C8 = 0;
    memset(gaLevelVisited_007C78B8, 0, 0x1000);
}
