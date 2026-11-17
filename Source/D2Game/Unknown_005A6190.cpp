struct Data005A6190;
struct Unit005A6190;
struct D2TakeRecordStrc;

struct Data005A6190 { unsigned char bUnknown00[0x2C]; unsigned int dwValue2C; };

struct Unit005A6190 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data005A6190* pData; };

struct D2TakeRecordStrc
{
    char unk0x00[0x18];
    int nValueA;
    int nValueB;
    unsigned char nValueC;
};


// 0x005A6190
extern "C" __declspec(dllexport) unsigned int __fastcall sub_005A6190(Unit005A6190* pUnit) {
    if (pUnit && pUnit->nType == 1 && pUnit->pData) {
        return pUnit->pData->dwValue2C;
    }
    return 0;
}

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
