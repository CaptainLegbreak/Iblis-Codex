typedef unsigned int size_t;

struct D2StoredUnitRecordStrc;

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    void* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize);                                     // 0x00681EF0
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
D2StoredUnitRecordStrc* __fastcall sub_004795A0_GetNextEntry(D2StoredUnitRecordStrc* pEntry);               // 0x004795A0
unsigned short __fastcall sub_00479BC0_GetEntryIndex(D2StoredUnitRecordStrc* pEntry);                       // 0x00479BC0
extern void* gpCellFile_007BF028;                                                                           // 0x007BF028
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
int gaRosterIndex_007BEFF4[8];                                                                              // 0x007BEFF4

// 0x00499F40
static void sub_00499F40_DrawRowSeparator(int nY)
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpCellFile_007BF028;
    tContext.unk0x40 = 0;
    tContext.nFrame = 0;
    sub_004F6480(&tContext, gnGlobal_007A2858 + 0xC, nY - gnGlobal_007A285C, -1, 5, 0);
    tContext.nFrame = 1;
    sub_004F6480(&tContext, gnGlobal_007A2858 + 0x10B, nY - gnGlobal_007A285C, -1, 5, 0);
}

// 0x0049A9B0
void __cdecl sub_0049A9B0_RefreshRosterIndices()
{
    D2StoredUnitRecordStrc* pEntry = sub_004795A0_GetNextEntry(0);
    for (int i = 0; i < 8; ++i)
        gaRosterIndex_007BEFF4[i] = 0xFFFF;
    int nIndex = 0;
    while (pEntry)
    {
        gaRosterIndex_007BEFF4[nIndex] = sub_00479BC0_GetEntryIndex(pEntry);
        pEntry = sub_004795A0_GetNextEntry(pEntry);
        ++nIndex;
    }
    int nY = 0x43;
    for (int i = 0; i < 7; ++i)
    {
        if (gaRosterIndex_007BEFF4[i + 1] != gaRosterIndex_007BEFF4[i] && gaRosterIndex_007BEFF4[i] != 0xFFFF)
            sub_00499F40_DrawRowSeparator(nY);
        nY += 0x26;
    }
}
