enum D2C_UnitTypes
{
    UNIT_MONSTER = 1,
};

struct D2MonStatsTxt
{
    char unk0x000[0x1A4];
    unsigned char nFlag1A4;
    char unk0x1A5[0x03];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    int unk0xA7C;
    int nMonStatsTxtRecordCount;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08[2];
    int dwAnimMode;
    char unk0x14[0x30];
    int nSeqCurrentFramePrecise;
    int dwFrameCountPrecise;
    short wAnimSpeed;
    char unk0x4E[0x76];
    unsigned int dwFlags;
};

struct D2SeqModeStrc
{
    int unk0x00;
    int nMode;
};

struct D2UnitTargetStrc
{
    int nParam1;
    int nParam2;
    int nParam3;
    int f_C;
    int f_10;
    int f_14;
    int f_18;
};

void __fastcall sub_004AFF60_MonsterCommand(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget);   // 0x004AFF60
int __stdcall UNITS_IsAtEndOfFrameCycle(D2UnitStrc* pUnit);                                                 // 0x006217C0
void __stdcall UNITS_StopSequence(D2UnitStrc* pUnit);                                                       // 0x00623E00

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

static D2MonStatsTxt* MONSTATS_GetRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static D2MonStatsTxt* MONSTATS_GetUnitRecord(D2UnitStrc* pUnit, int nType)
{
    if (pUnit && nType == UNIT_MONSTER)
    {
        return MONSTATS_GetRecord(pUnit->dwClassId);
    }

    return 0;
}

// 0x004B1280
int __fastcall sub_004B1280_HandleSequenceStop(D2UnitStrc* pUnit, D2SeqModeStrc* pMode)
{
    if (!pUnit)
    {
        return 0;
    }

    const int nType = pUnit->dwUnitType;

    if (nType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = MONSTATS_GetUnitRecord(pUnit, nType);
        if (!pMonStatsTxtRecord)
        {
            return 0;
        }

        switch (pMonStatsTxtRecord->nFlag1A4)
        {
        case 1:
            if (!pUnit->dwAnimMode && UNITS_IsAtEndOfFrameCycle(pUnit))
            {
                D2UnitTargetStrc tTarget = {};
                sub_004AFF60_MonsterCommand(9, pUnit, &tTarget);
            }
            break;
        }
    }

    int nResult = 0;
    switch (pMode->nMode)
    {
    case 0:
        UNITS_StopSequence(pUnit);
        break;

    case 1:
        nResult = UNITS_IsAtEndOfFrameCycle(pUnit);
        if (!nResult)
        {
            UNITS_StopSequence(pUnit);
        }
        break;

    case 2:
        if (!UNITS_IsAtEndOfFrameCycle(pUnit))
        {
            UNITS_StopSequence(pUnit);
            break;
        }

        pUnit->nSeqCurrentFramePrecise = pUnit->dwFrameCountPrecise - 0x100;
        pUnit->wAnimSpeed = 0;
        if (!pUnit->dwAnimMode)
        {
            pUnit->dwFlags |= 0x20;
        }
        break;

    case 3:
        pUnit->nSeqCurrentFramePrecise = 0x100;
        pUnit->wAnimSpeed = 0;
        break;
    }

    return nResult;
}
