struct D2DynamicPathStrc;
struct D2StatListStrc;
struct D2ActiveRoomStrc;
struct D2GameStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x08];
    int dwAnimMode;
    char unk0x14[0x18];
    D2DynamicPathStrc* pDynamicPath;
};

struct D2MonStatsTxt
{
    char unk0x000[0x2A];
    short nMonEquipTxtRecordId;
    char unk0x02C[0x22];
    unsigned char nThreat;
    char unk0x04F[0x159];
};

struct D2MonEquipTxt
{
    char unk0x00[0x1C];
};

struct D2SkillsTxt
{
    char unk0x000[0x04];
    unsigned char nFlags[8];
    char unk0x00C[0x3A];
    short wSrvMissile[4];
    char unk0x04E[0x06];
    short wAuraStat[6];
    char unk0x060[0x20];
    short nAuraState;
    char unk0x082[0x1BA];
};

struct D2DataTablesStrc
{
    char unk0x000[0xC4];
    int nStatesTxtRecordCount;
    char unk0x0C8[0x9B0];
    D2MonStatsTxt* pMonStatsTxt;
    void* pMonStatsLinker;
    int nMonStatsTxtRecordCount;
    char unk0xA84[0x114];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
    char unk0xBA4[0x30];
    int nItemStatCostTxtRecordCount;
    char unk0xBD8[0x08];
    D2MonEquipTxt* pMonEquipTxt;
};

struct D2AnimSeqTxt
{
    unsigned short wSequence;
    unsigned char nMode;
    unsigned char nFrame;
    unsigned char nDir;
    unsigned char nEvent;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                            // 0x00553540
int __stdcall ITEMS_IsMetalItem(int nItemId);                                                               // 0x00629CC0
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);    // 0x006280A0
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic);                           // 0x00625820
D2AnimSeqTxt* __stdcall DATATBLS_GetMonSeqTxtRecordFromUnit(D2UnitStrc* pUnit);                             // 0x006633B0
int __stdcall DATATBLS_GetSeqFrameCount(D2UnitStrc* pUnit);                                                 // 0x006633F0
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0
int __fastcall sub_00463860(D2UnitStrc* pUnit);                                                             // 0x00463860
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit);                                                 // 0x006259B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);              // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625D00
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900

// 0x005BFDA0
int __fastcall SKILLITEM_CalculateOpenWoundsHpRegen(int nLevel, const int* pValues)
{
    if (nLevel <= 1 || !pValues)
    {
        return 0;
    }

    if (nLevel > 60)
    {
        return (pValues[4] * (nLevel - 60)) + 15 * (pValues[1] + pValues[2] + pValues[3]) + 14 * pValues[0];
    }

    if (nLevel > 45)
    {
        return (pValues[3] * (nLevel - 45)) + 15 * (pValues[1] + pValues[2]) + 14 * pValues[0];
    }

    if (nLevel > 30)
    {
        return 15 * pValues[1] + pValues[2] * (nLevel - 30) + 14 * pValues[0];
    }

    if (nLevel > 15)
    {
        return pValues[1] * (nLevel - 15) + 14 * pValues[0];
    }

    return pValues[0] * (nLevel - 1);
}

// 0x005C32A0
int __fastcall SKILLS_SrvSt20_IronGolem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (pTarget->dwUnitType != 4)
    {
        return 0;
    }

    if (pTarget->dwAnimMode != 3)
    {
        return 0;
    }

    if (!ITEMS_IsMetalItem(pTarget->dwClassId))
    {
        return 0;
    }

    if (!ITEMS_CheckItemFlag(pTarget, 0x10, 256, ".\\SKILLS\\SkillNec.cpp"))
    {
        return 0;
    }

    return !STATLIST_GetOwner(pTarget, 0);
}

// 0x005CF8C0
int __fastcall sub_005CF8C0_GetSeqEventFrame(D2UnitStrc* pUnit)
{
    D2AnimSeqTxt* pMonSeqTxtRecord = DATATBLS_GetMonSeqTxtRecordFromUnit(pUnit);
    if (pMonSeqTxtRecord)
    {
        const int nSequenceFrameCount = DATATBLS_GetSeqFrameCount(pUnit);
        for (int i = 0; i < nSequenceFrameCount; ++i)
        {
            if (!pMonSeqTxtRecord->nEvent)
            {
                return i - 1;
            }
        }
    }

    return 7;
}

// 0x005D2140
int __fastcall SKILLS_CanImpregnateTarget(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (!pTarget || pTarget->dwUnitType != 1 || SUNIT_IsDead(pTarget))
    {
        return 0;
    }

    int nBaseId = sub_00463860(pTarget);
    if (nBaseId < 0 || nBaseId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        nBaseId = -1;
    }

    switch (nBaseId)
    {
    case 546:
    case 551:
        return 0;
    }

    if (STATES_CheckState(pTarget, 110))
    {
        return 0;
    }

    return STATLIST_GetUnitAlignment(pTarget) != 2;
}

// 0x005D30A0
D2MonEquipTxt* __fastcall sub_005D30A0_GetMonEquipTxtRecord(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount) ? &sgptDataTables->pMonStatsTxt[nMonsterId] : 0;
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    if (pMonStatsTxtRecord->nMonEquipTxtRecordId < 0)
    {
        return 0;
    }

    return &sgptDataTables->pMonEquipTxt[pMonStatsTxtRecord->nMonEquipTxtRecordId];
}

// build: context SKILLS_SrvSt22_PsychicHammer
int __fastcall SKILLS_SrvSt22_PsychicHammer(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTargetUnit = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTargetUnit)
    {
        return 0;
    }

    D2ActiveRoomStrc* pUnitRoom = UNITS_GetRoom(pUnit);
    if (DUNGEON_IsRoomInTown(pUnitRoom))
    {
        return 0;
    }

    D2ActiveRoomStrc* pTargetRoom = UNITS_GetRoom(pTargetUnit);
    if (DUNGEON_IsRoomInTown(pTargetRoom))
    {
        return 0;
    }

    if (pTargetUnit->dwUnitType != 0 && pTargetUnit->dwUnitType != 1)
    {
        return 0;
    }

    return 1;
}

// build: context SKILLS_GetProgressiveSkillMissileId
int __fastcall SKILLS_GetProgressiveSkillMissileId(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = 0;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        pSkillsTxtRecord = &sgptDataTables->pSkillsTxt[nSkillId];
    }

    if (!pSkillsTxtRecord)
    {
        return -1;
    }

    if (pSkillsTxtRecord->nFlags[2 >> 3] & gdwBitMasks[2 & 7] && pSkillsTxtRecord->nAuraState >= 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount)
    {
        if (pSkillsTxtRecord->wAuraStat[0] >= 0 && pSkillsTxtRecord->wAuraStat[0] < sgptDataTables->nItemStatCostTxtRecordCount)
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
            if (pStatList)
            {
                int nIndex = STATLIST_GetStatValue(pStatList, pSkillsTxtRecord->wAuraStat[0], 0);
                if (nIndex > 1)
                {
                    if (nIndex >= 3)
                    {
                        nIndex = 3;
                    }
                }
                else
                {
                    nIndex = 1;
                }

                return pSkillsTxtRecord->wSrvMissile[nIndex];
            }
        }
    }

    return pSkillsTxtRecord->wSrvMissile[1];
}

// 0x005DC5C0
int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY)
{
    D2_ASSERT(pUnit, 267);
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2_ASSERT(pPath, 270);

    int nXDiff = PATH_GetXPosition(pPath) - nX;
    if (nXDiff < 0)
    {
        nXDiff = -nXDiff;
    }

    int nYDiff = PATH_GetYPosition(pPath) - nY;
    if (nYDiff < 0)
    {
        nYDiff = -nYDiff;
    }

    if (nXDiff > nYDiff)
    {
        return (nYDiff + 2 * nXDiff) / 2;
    }

    return (nXDiff + 2 * nYDiff) / 2;
}

// 0x005DC920
int __fastcall sub_005DC920_GetThreat(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    switch (pUnit->dwUnitType)
    {
    case 0:
        return 14;

    case 1:
    {
        const int nClassId = pUnit->dwClassId;
        D2MonStatsTxt* pMonStatsTxtRecord = (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount) ? &sgptDataTables->pMonStatsTxt[nClassId] : 0;
        if (pMonStatsTxtRecord)
        {
            return pMonStatsTxtRecord->nThreat;
        }
        break;
    }

    default:
        break;
    }

    return 0;
}
