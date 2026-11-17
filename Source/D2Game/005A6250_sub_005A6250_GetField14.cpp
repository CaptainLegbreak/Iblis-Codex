struct D2Field14Strc
{
    char unk0x00[0x14];
    int nField14;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x3A];
    unsigned char nActionFrame;
    char unk0x4F[0x75];
    unsigned int dwFlags;
};

// 0x005A6250
int* __fastcall sub_005A6250_GetField14(D2Field14Strc* pRecord)
{
    return &pRecord->nField14;
}

// 0x005A64F0
static __forceinline int sub_005A64F0_IsActionFrame(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwAnimMode == 14)
        return (pUnit->dwFlags >> 6) & 1;
    return pUnit->nActionFrame == 1;
}

void __fastcall sub_M111_Emit_005A64F0(D2UnitStrc* pUnit, int* pResult)
{
    *pResult = sub_005A64F0_IsActionFrame(pUnit) + 1;
}
