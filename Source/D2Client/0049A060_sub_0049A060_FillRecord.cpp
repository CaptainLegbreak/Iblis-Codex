struct D2SevenIntStrc
{
    int n0;
    int n1;
    int n2;
    int n3;
    int n4;
    int n5;
    int n6;
};

void __cdecl sub_K04_EmitUse(D2SevenIntStrc* pRecord);

// 0x0049A060
static void __stdcall sub_0049A060_FillRecord(D2SevenIntStrc* pRecord, int n0, int n1, int n2, int n3, int n4, int n5, int n6)
{
    pRecord->n0 = n0;
    pRecord->n1 = n1;
    pRecord->n2 = n2;
    pRecord->n3 = n3;
    pRecord->n4 = n4;
    pRecord->n5 = n5;
    pRecord->n6 = n6;
}

void __cdecl sub_K04_EmitFillRecord(int n0, int n1, int n2, int n3, int n4, int n5, int n6)
{
    D2SevenIntStrc tRecord;
    sub_0049A060_FillRecord(&tRecord, n0, n1, n2, n3, n4, n5, n6);
    sub_K04_EmitUse(&tRecord);
}
