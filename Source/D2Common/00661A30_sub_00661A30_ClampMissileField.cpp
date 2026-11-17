#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};

struct D2MissilesTxt
{
    char unk0x000[0x1A4];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    void* pMissilesLinker;
    int nMissilesTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTable;                                                                     // 0x00744304

static __forceinline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTable->nMissilesTxtRecordCount)
    {
        return &sgptDataTable->pMissilesTxt[nMissileId];
    }
    return 0;
}

static __declspec(noinline) int __stdcall sub_00661A30_ClampMissileField(D2BinFieldStrc* pFields, int nMissileId, int nOffset, int nType, int nMin, int nMax);

// 0x00661A30
static int __stdcall sub_00661A30_ClampMissileField(D2BinFieldStrc* pFields, int nMissileId, int nOffset, int nType, int nMin, int nMax)
{
    char* pRecord = (char*)DATATBLS_GetMissilesTxtRecord(nMissileId);
    int nValue = 0;
    switch (nType)
    {
    case 0:
        nValue = *(signed char*)(pRecord + nOffset);
        break;
    case 1:
        nValue = *(unsigned char*)(pRecord + nOffset);
        break;
    case 2:
        nValue = *(short*)(pRecord + nOffset);
        break;
    case 3:
        nValue = *(unsigned short*)(pRecord + nOffset);
        break;
    case 4:
        nValue = *(int*)(pRecord + nOffset);
        break;
    }

    if (nValue < nMin || nValue > nMax)
    {
        for (int nField = 0; pFields[nField].nFieldType; ++nField)
        {
            if (pFields[nField].nFieldOffset == nOffset)
            {
                break;
            }
        }

        nValue = D2_MIN(D2_MAX(nValue, nMin), nMax);

        switch (nType)
        {
        case 0:
        case 1:
            *(char*)(pRecord + nOffset) = (char)nValue;
            break;
        case 2:
        case 3:
            *(short*)(pRecord + nOffset) = (short)nValue;
            break;
        case 4:
            *(int*)(pRecord + nOffset) = nValue;
            break;
        }
    }
    return nValue;
}

// calling-convention shim (not game code)
void __fastcall sub_00661A30_Shim(D2BinFieldStrc* pFields)
{
    for (int i = 0; i < sgptDataTable->nMissilesTxtRecordCount; ++i)
    {
        sub_00661A30_ClampMissileField(pFields, i, 0x183, 1, 0, 8);
        sub_00661A30_ClampMissileField(pFields, i, 0x190, 2, -1, 100);
    }
}
