struct D2UnitStrc
{
    int dwUnitType;
};

struct D2DataTablesStrc
{
    char unk0x000[0xA80];
    int nMonStatsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int __stdcall D2COMMON_11017_CheckUnitIfConsumeable(D2UnitStrc* pUnit, int a2);                             // 0x00645510
int __fastcall sub_004B11F0(D2UnitStrc* pUnit);                                                             // 0x004B11F0
int __fastcall sub_00463860(D2UnitStrc* pUnit);                                                             // 0x00463860
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nType, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00

// 0x00464220
int __fastcall sub_00464220_SkillSelectProc2(D2UnitStrc* pPlayer, D2UnitStrc* pTarget)
{
    return D2COMMON_11017_CheckUnitIfConsumeable(pTarget, 0);
}

// 0x00464230
int __fastcall sub_00464230_SkillSelectProc3(D2UnitStrc* pPlayer, D2UnitStrc* pTarget)
{
    if (!pTarget)
        return 0;
    if (!D2COMMON_11017_CheckUnitIfConsumeable(pTarget, 0))
        return 0;
    if (!sub_004B11F0(pTarget))
        return 0;
    const int nType = pTarget ? pTarget->dwUnitType : 6;
    if (nType != 1)
        return 0;
    int nClass = sub_00463860(pTarget);
    if (nClass >= 0 && nClass < sgptDataTables->nMonStatsTxtRecordCount && nClass == 0x4E)
        return 0;
    return 1;
}

// 0x00464E50
void __fastcall sub_00464E50_SetOverlayWithSound(D2UnitStrc* pUnit, int nOverlay, int nArg)
{
    if (!pUnit)
        return;

    if (nArg > 0)
        sub_00470390(pUnit, nOverlay, 1, 0, nArg, 0, 0, 0);
    else
        sub_00470390(pUnit, nOverlay, 2, 0, 0, 0, 0, 0);

    switch (nOverlay)
    {
    case 0x97:
        sub_004B9A00(0x18C, pUnit, 0, 0, 0);
        break;
    case 0x98:
        sub_004B9A00(0x18D, pUnit, 0, 0, 0);
        break;
    }
}
