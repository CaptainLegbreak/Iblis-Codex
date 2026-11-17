struct D2AnimSeqTxt;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x8];
    int dwAnimMode;
};

struct D2MonStats2Txt
{
    char unk0x000[0xB];
    unsigned char nValue0B;
    char unk0x00C[0xF8];
    unsigned char nFlags[16];
};

struct D2MonCmdRecordStrc
{
    int nIndex;
    int bSet;
};

struct D2MissileStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    D2UnitStrc* pTarget;
    int nMissile;
    int unk0x14[7];
    int nSkillLevel;
    int unk0x34[10];
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                              // 0x00681EF0
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId);                        // 0x00451FE0
void __fastcall sub_00465BF0(D2UnitStrc* pUnit, int nArg);                                                  // 0x00465BF0
void __fastcall sub_00470610_Refresh(D2UnitStrc* pUnit, int nArg);                                          // 0x00470610
void __fastcall sub_00480490_RecacheUnitPath(D2UnitStrc* pUnit);                                            // 0x00480490
void __fastcall sub_00480E70_SetState(D2UnitStrc* pUnit, int nArg);                                         // 0x00480E70
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                           // 0x004CD540
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
D2AnimSeqTxt* __stdcall DATATBLS_GetMonSeqTxtRecordFromUnit(D2UnitStrc* pUnit);                             // 0x006633B0
int __stdcall DATATBLS_GetSeqFramePointsCount(D2UnitStrc* pUnit);                                           // 0x006633D0
void __stdcall DATATBLS_ComputeSequenceAnimation(D2AnimSeqTxt* pMonSeqTxt, int nTargetFramePoint, int nCurrentFramePoint, int* pMode, int* pFrame, int* pDirection, int* pEvent); // 0x00663410

// 0x004AE1D0
static __declspec(noinline) void sub_004AE1D0_RefreshMonsterMode(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1)
    {
        const unsigned int nMode = pUnit->dwAnimMode;
        if (nMode < 0x10 && nMode && nMode != 0xC)
        {
            sub_00465BF0(pUnit, 0);
            sub_00480490_RecacheUnitPath(pUnit);
            sub_00480E70_SetState(pUnit, 1);
        }
    }
}

// 0x004AFB60
static __declspec(noinline) void sub_004AFB60_ReplaySequence(D2UnitStrc* pUnit)
{
    D2AnimSeqTxt* pSequenceRecord = DATATBLS_GetMonSeqTxtRecordFromUnit(pUnit);
    const int nCount = DATATBLS_GetSeqFramePointsCount(pUnit) >> 8;
    for (int i = 0; i < nCount; ++i)
    {
        int nMode;
        int nFrame;
        int nDirection;
        int nEvent;
        DATATBLS_ComputeSequenceAnimation(pSequenceRecord, i << 8, i << 8, &nMode, &nFrame, &nDirection, &nEvent);
        pUnit->dwAnimMode = nMode;
        sub_00470610_Refresh(pUnit, 0);
    }
}

// 0x004AFBC0
static __declspec(noinline) int sub_004AFBC0_HasMonStatsFlag(D2UnitStrc* pUnit, D2MonCmdRecordStrc* pRecord)
{
    if (!pUnit || !pRecord)
        return 0;

    if (pRecord->bSet)
    {
        const int nIndex = pRecord->nIndex;
        if (nIndex < 0x10)
        {
            D2MonStats2Txt* pMonStats2Txt = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId);
            if (pMonStats2Txt)
                return pMonStats2Txt->nFlags[nIndex >> 3] & gdwBitMasks[nIndex & 7];
        }
    }
    return 0;
}

// 0x004AFC10
static __declspec(noinline) void sub_004AFC10_CreateDeathMissiles(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : 6;
    if (nType != 1)
        return;

    D2MissileStrc tMissile;
    if (STATES_CheckState(pUnit, 0xB8) && !STATES_CheckState(pUnit, 1))
    {
        memset(&tMissile, 0, sizeof(tMissile));
        tMissile.dwFlags = 0x2020;
        tMissile.pOwner = pUnit;
        tMissile.pOrigin = pUnit;
        tMissile.nSkillLevel = 1;
        tMissile.nMissile = 0x1AB;
        sub_004CD540_CreateMissile(&tMissile);
        tMissile.nMissile = 0x1AA;
        sub_004CD540_CreateMissile(&tMissile);
        return;
    }

    const int nMissile = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId)->nValue0B + 0x10F;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 0x2020;
    tMissile.pOwner = pUnit;
    tMissile.pOrigin = pUnit;
    tMissile.nSkillLevel = 1;
    tMissile.nMissile = nMissile;
    sub_004CD540_CreateMissile(&tMissile);
    tMissile.nMissile = 0x113;
    sub_004CD540_CreateMissile(&tMissile);
}

void __cdecl sub_F03_Emit_004AE1D0(D2UnitStrc* pUnit)
{
    sub_004AE1D0_RefreshMonsterMode(pUnit);
}

void __cdecl sub_F03_Emit_004AFB60(D2UnitStrc* pUnit)
{
    sub_004AFB60_ReplaySequence(pUnit);
}

int __cdecl sub_F03_Emit_004AFBC0(D2UnitStrc* pUnit, D2MonCmdRecordStrc* pRecord)
{
    return sub_004AFBC0_HasMonStatsFlag(pUnit, pRecord);
}

void __cdecl sub_F03_Emit_004AFC10(D2UnitStrc* pUnit)
{
    sub_004AFC10_CreateDeathMissiles(pUnit);
}
