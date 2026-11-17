struct Unicode;
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

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
D2StoredUnitRecordStrc* __fastcall sub_004795A0_GetNextEntry(D2StoredUnitRecordStrc* pEntry);               // 0x004795A0
unsigned short __fastcall sub_00479BC0_GetEntryIndex(D2StoredUnitRecordStrc* pEntry);                       // 0x00479BC0
void __fastcall sub_004A7080(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor);  // 0x004A7080
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
extern void* gpCelFile_007BF01C;                                                                            // 0x007BF01C

// 0x00499FC0
static __declspec(noinline) void __stdcall sub_00499FC0_DrawPanelCel(void* pCellFile, int nX, int nFrame, int nY)
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = pCellFile;
    tContext.nFrame = nFrame;
    tContext.unk0x40 = 0;
    sub_004F6480(&tContext, gnGlobal_007A2858 + nX, nY - gnGlobal_007A285C, -1, 5, 0);
}

// 0x0049A510
void __cdecl sub_0049A510_DrawPartyButtons()
{
    D2StoredUnitRecordStrc* pEntry = sub_004795A0_GetNextEntry(0);
    sub_00502EF0(0);
    if (sub_00479BC0_GetEntryIndex(pEntry) != 0xFFFF)
    {
        sub_00499FC0_DrawPanelCel(gpCelFile_007BF01C, 0xE3, 0, 0x23);
        sub_004A7080(gnGlobal_007A2858 + 0xE3, 0x21 - gnGlobal_007A285C, gnGlobal_007A2858 + 0x118, D2LANG_GetStringFromTblIndex(0x1038), 2);
    }
    sub_00502EF0(1);
}
