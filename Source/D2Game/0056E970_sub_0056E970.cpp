struct D2StatListStrc;
struct D2SkillStrc;
struct D2UnitStrc { int dwUnitType; int dwClassId; void* pMemoryPool; int dwUnitId; };
struct D2GameStrc { char unk_00[0xA8]; int dwGameFrame; };
typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc*, int, D2StatListStrc*);
struct D2CurseStrc
{
    D2UnitStrc* pUnit;
    D2UnitStrc* pTarget;
    int nSkill;
    int nSkillLevel;
    int nDuration;
    int nStat;
    int nStatValue;
    int nState;
    StatListRemoveCallback pStateRemoveCallback;
};
struct D2StatesTxt { char unk_00[0x10]; unsigned char nFlags[4]; char unk_14[0x28]; };
struct D2MonStatsTxt { char unk_00[0xC]; unsigned char nFlags[4]; char unk_10[0x198]; };
struct D2MonStats2Txt { char unk_00[4]; unsigned char nFlags[4]; };
struct D2DataTablesStrc
{
    char unk_000[0xBC];
    D2StatesTxt* pStatesTxt;
    void* pStatesLinker;
    int nStatesTxtRecordCount;
    char unk_0C8[0x9B0];
    D2MonStatsTxt* pMonStatsTxt;
    void* pMonStatsLinker;
    int nMonStatsTxtRecordCount;
};
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
void __fastcall EVENT_SetEvent(D2GameStrc*, D2UnitStrc*, int, int, int, int); // 0x005417D0
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010
void __fastcall sub_6FD10E50(D2UnitStrc*, int, D2StatListStrc*); // 0x0056E900
D2StatListStrc* __stdcall STATLIST_AllocStatList(void*, unsigned int, unsigned int, int, int); // 0x006251F0
void __stdcall STATLIST_SetState(D2StatListStrc*, int); // 0x006252D0
int __stdcall STATLIST_GetState(D2StatListStrc*); // 0x006252F0
void __stdcall STATLIST_SetExpireFrame(D2StatListStrc*, int); // 0x00625310
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*, int, int); // 0x00625480
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc*, int); // 0x006256B0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc*, int); // 0x00625760
void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc*, StatListRemoveCallback); // 0x00625CE0
void __stdcall STATLIST_SetSkillId(D2StatListStrc*, int); // 0x006260D0
D2SkillStrc* __stdcall sub_006260E0(D2StatListStrc*); // 0x006260E0
void __stdcall STATLIST_SetSkillLevel(D2StatListStrc*, int); // 0x006260F0
int __stdcall STATLIST_GetSkillLevel(D2StatListStrc*); // 0x00626100
void __stdcall STATLIST_FreeStatList(D2StatListStrc*); // 0x00626CD0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc*, D2StatListStrc*, int); // 0x00626E10
void __stdcall STATLIST_SetStat(D2StatListStrc*, int, int, int); // 0x00627150
void __stdcall D2Common_10474(D2UnitStrc*, D2StatListStrc*); // 0x006277E0
void __stdcall STATES_ToggleState(D2UnitStrc*, int, int); // 0x00639DB0
int __stdcall STATES_CheckState(D2UnitStrc*, int); // 0x00639DF0
int __stdcall STATES_CheckStateMaskCurseByStateId(int); // 0x0063A420
int __stdcall STATES_CheckStateMaskExpByStateId(int); // 0x0063A6B0
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc*); // 0x0064C040
inline D2StatesTxt* DATATBLS_GetStatesTxtRecord(int nState)
{
    if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
        return &sgptDataTables->pStatesTxt[nState];
    return 0;
}
// 0x0056E970
D2StatListStrc* __fastcall sub_0056E970(D2CurseStrc* pCurse)
{
    D2UnitStrc* pTarget = pCurse->pTarget;
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pTarget);
    const int nState = pCurse->nState;
    D2StatesTxt* pStatesTxtRecord = DATATBLS_GetStatesTxtRecord(nState);
    if (!pStatesTxtRecord)
        return 0;
    if (pTarget && pTarget->dwUnitType == 1)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = 0;
        if (pTarget->dwClassId >= 0 && pTarget->dwClassId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            pMonStatsTxtRecord = &sgptDataTables->pMonStatsTxt[pTarget->dwClassId];
        }
        if (!pMonStatsTxtRecord || (pMonStatsTxtRecord->nFlags[1] & (unsigned char)gdwBitMasks[0]))
            return 0;
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pTarget->dwClassId);
        if (!pMonStats2TxtRecord || !(pMonStats2TxtRecord->nFlags[1] & (unsigned char)gdwBitMasks[1]))
            return 0;
    }
    const int bCurse = STATES_CheckStateMaskCurseByStateId(nState);
    if (bCurse)
    {
        const int nResistance = STATLIST_UnitGetStatValue(pTarget, 109, 0);
        if (nResistance >= 100)
            return 0;
        if (nResistance)
        {
            const int nDuration = pCurse->nDuration;
            pCurse->nDuration = nDuration - DATATBLS_ApplyRatio(nDuration, nResistance, 100);
        }
        if (STATES_CheckState(pTarget, 57))
            return 0;
    }
    unsigned int nFlags = 0;
    D2StatListStrc* pStatList;
    if (bCurse)
    {
        nFlags = 0x20;
        pStatList = STATLIST_GetStatListFromUnitAndFlag(pTarget, 0x20);
    }
    else
        pStatList = STATLIST_GetStatListFromUnitAndState(pTarget, nState);
    if (pStatList)
    {
        if (STATLIST_GetState(pStatList) == pCurse->nState && pCurse->nSkill == (int)sub_006260E0(pStatList))
        {
            const int nSkillLevel = STATLIST_GetSkillLevel(pStatList);
            if (pCurse->nSkillLevel == nSkillLevel)
            {
                if (pCurse->nDuration)
                {
                    const int nExpireFrame = pGame->dwGameFrame + pCurse->nDuration;
                    STATLIST_SetExpireFrame(pStatList, nExpireFrame);
                    EVENT_SetEvent(pGame, pTarget, 12, nExpireFrame, 0, 0);
                }
                return pStatList;
            }
            if (pCurse->nSkillLevel < nSkillLevel)
                return 0;
        }
        D2Common_10474(pTarget, pStatList);
        STATLIST_FreeStatList(pStatList);
    }
    UNITROOM_RefreshUnit(pTarget);
    STATES_ToggleState(pTarget, nState, 1);
    int nExpireFrame = 0;
    if (pCurse->nDuration)
    {
        nExpireFrame = pGame->dwGameFrame + pCurse->nDuration;
        nFlags |= 2;
        EVENT_SetEvent(pGame, pCurse->pTarget, 12, nExpireFrame, 0, 0);
    }
    if (STATES_CheckStateMaskExpByStateId(nState))
        nFlags |= 0x800;
    if (pStatesTxtRecord->nFlags[0] & (unsigned char)gdwBitMasks[1])
        nFlags |= 8;
    pStatList = STATLIST_AllocStatList(!pTarget ? 0 : pTarget->pMemoryPool, nFlags, nExpireFrame, !pCurse->pUnit ? 6 : pCurse->pUnit->dwUnitType, !pCurse->pUnit ? -1 : pCurse->pUnit->dwUnitId);
    STATLIST_SetState(pStatList, nState);
    STATLIST_SetSkillId(pStatList, pCurse->nSkill);
    STATLIST_SetSkillLevel(pStatList, pCurse->nSkillLevel);
    if (pCurse->nStat != -1)
        STATLIST_SetStat(pStatList, pCurse->nStat, pCurse->nStatValue, 0);
    D2COMMON_10475_PostStatToStatList(pTarget, pStatList, 1);
    if (!pCurse->pStateRemoveCallback)
    {
        STATLIST_SetStatRemoveCallback(pStatList, sub_6FD10E50);
        return pStatList;
    }
    STATLIST_SetStatRemoveCallback(pStatList, pCurse->pStateRemoveCallback);
    return pStatList;
}
