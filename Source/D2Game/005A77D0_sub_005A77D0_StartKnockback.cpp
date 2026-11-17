struct D2DynamicPathStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x2C - 0x14];
    D2DynamicPathStrc* pDynamicPath;
};

struct D2GameStrc;

struct D2ModeChangeStrc
{
    int nMode;
    D2UnitStrc* pUnit;
    D2UnitStrc* pTargetUnit;
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    void* pMonStatsTxt;
    void* pMonStatsLinker;
    int nMonStatsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int __fastcall sub_0046C140_CheckMonStats2ModeFlag(int nMonsterId, int nMode);                               // 0x0046C140
int __fastcall sub_00463860(D2UnitStrc* pUnit);                                                             // 0x00463860
void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType);                                // 0x00648CF0
void __stdcall D2COMMON_10190_PATH_SetDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nDistance);   // 0x00648E40
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown);                // 0x00649970
void __fastcall SUNIT_SetCombatMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode);                        // 0x00553570

// 0x005A77D0
int __fastcall sub_005A77D0_StartKnockback(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    D2UnitStrc* pUnit = pModeChange->pUnit;
    if (!sub_0046C140_CheckMonStats2ModeFlag(!pUnit ? -1 : pUnit->dwClassId, 3))
    {
        return 0;
    }

    if (!sub_0046C140_CheckMonStats2ModeFlag(!pUnit ? -1 : pUnit->dwClassId, 13))
    {
        return 0;
    }

    if (pUnit && pUnit->dwAnimMode)
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        PATH_SetType(pPath, 8);
        int nBaseId = sub_00463860(pUnit);
        if (nBaseId < 0 || nBaseId >= sgptDataTables->nMonStatsTxtRecordCount)
        {
            nBaseId = -1;
        }

        if (nBaseId != 0x4E)
        {
            D2COMMON_10190_PATH_SetDistance(pPath, 5);
        }
        else
        {
            D2COMMON_10190_PATH_SetDistance(pPath, 10);
        }
        D2Common_10142(pPath, pUnit, 0);
        SUNIT_SetCombatMode(pGame, pUnit, 13);
    }

    return 1;
}
