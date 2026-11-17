struct D2TakeRecordStrc
{
    char unk0x00[0x18];
    int nValueA;
    int nValueB;
    unsigned char nValueC;
};

// 0x005A61B0
static void __stdcall sub_005A61B0_TakeRecordValues(D2TakeRecordStrc* pRecord, int* pValueA, int* pValueB, unsigned char* pValueC)
{
    if (pRecord->nValueA)
    {
        *pValueA = pRecord->nValueA;
    }
    if (pRecord->nValueB)
    {
        *pValueB = pRecord->nValueB;
    }
    if (pRecord->nValueC)
    {
        *pValueC = pRecord->nValueC;
    }
    pRecord->nValueA = 0;
    pRecord->nValueB = 0;
    pRecord->nValueC = 0;
}

void __stdcall sub_K13_Emit_005A61B0(D2TakeRecordStrc* pRecord, int* pValueA, int* pValueB, unsigned char* pValueC)
{
    sub_005A61B0_TakeRecordValues(pRecord, pValueA, pValueB, pValueC);
}
