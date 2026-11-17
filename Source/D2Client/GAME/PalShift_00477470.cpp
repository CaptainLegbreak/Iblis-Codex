struct D2PalShiftNodeStrc
{
    int nId;
    char unk0x04[0x1000];
    D2PalShiftNodeStrc* pNext;
};

struct T0044A980
{
    int nId;
    int nValue;
};

struct D2DataTablesStrc
{
    char unk0x000[0xA80];
    int nMonStatsTxtRecordCount;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
void __fastcall sub_00477170_LoadPalShift(int nMonsterId);                                                  // 0x00477170

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
T0044A980* gpPalShiftEntries_007B9578;                                                            // 0x007B9578
extern D2PalShiftNodeStrc* gpPalShiftList_007B957C;                                                         // 0x007B957C

// 0x00477470
void __cdecl sub_00477470_InitPalShifts()
{
    while (gpPalShiftList_007B957C)
    {
        D2PalShiftNodeStrc* pNext = gpPalShiftList_007B957C->pNext;
        FOG_Free(gpPalShiftList_007B957C, ".\\GAME\\PalShift.cpp", 0x117, 0);
        gpPalShiftList_007B957C = pNext;
    }

    const int nCount = sgptDataTables->nMonStatsTxtRecordCount;
    T0044A980* pEntries = gpPalShiftEntries_007B9578;
    const int nSize = nCount * sizeof(T0044A980);
    if (!pEntries)
    {
        pEntries = (T0044A980*)FOG_Alloc(nSize, ".\\GAME\\PalShift.cpp", 0x11F, 0);
        gpPalShiftEntries_007B9578 = pEntries;
    }
    memset(pEntries, 0, nSize);
    for (int i = 0; i < nCount; ++i)
    {
        pEntries[i].nId = i;
    }

    sub_00477170_LoadPalShift(0x16B);
    sub_00477170_LoadPalShift(0x16C);
    sub_00477170_LoadPalShift(0x1A4);
    sub_00477170_LoadPalShift(0x1A5);
}
