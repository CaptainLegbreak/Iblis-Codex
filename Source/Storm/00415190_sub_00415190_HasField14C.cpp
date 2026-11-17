struct D2SFileRecordViewStrc
{
    char unk0x00[0x144];
    int dwField144;
    int dwField148;
    int dwField14C;
    int dwField150;
};

struct D2SFileOtherRecordViewStrc
{
    char unk0x00[0x4C];
    int dwField4C;
};

// 0x00415190
int __fastcall sub_00415190_HasField14C(D2SFileRecordViewStrc* pRecord)
{
    if (pRecord && pRecord->dwField14C)
    {
        return 1;
    }
    return 0;
}

// 0x004151B0
int __fastcall sub_004151B0_HasField150(D2SFileRecordViewStrc* pRecord)
{
    if (pRecord && pRecord->dwField150)
    {
        return 1;
    }
    return 0;
}

// 0x00415730
void __fastcall sub_00415730_IncField148(D2SFileRecordViewStrc* pRecord)
{
    if (pRecord)
    {
        ++pRecord->dwField148;
    }
}

// 0x00415740
static __forceinline void sub_00415740_IncField144(D2SFileRecordViewStrc* pRecord)
{
    if (pRecord)
    {
        ++pRecord->dwField144;
    }
}

// 0x00415750
static __forceinline void sub_00415750_IncField4C(D2SFileOtherRecordViewStrc* pRecord)
{
    if (pRecord)
    {
        ++pRecord->dwField4C;
    }
}

void __fastcall sub_M103_Emit_00415740(D2SFileRecordViewStrc* pRecord, D2SFileOtherRecordViewStrc* pOther)
{
    sub_00415740_IncField144(pRecord);
    sub_00415750_IncField4C(pOther);
}
