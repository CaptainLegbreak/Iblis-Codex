struct D2CellFileStrc;

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    D2CellFileStrc* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
int gnValue_007A6AAC;        // 0x007A6AAC
int gnValue_007A6AB0;        // 0x007A6AB0
int gnValue_007A6AB4;        // 0x007A6AB4
D2CellFileStrc* gpCellFile_007A6AD8;        // 0x007A6AD8
int gnFrame_007A6AE0;        // 0x007A6AE0

// 0x00468460
void __cdecl sub_00468460_DrawCel()
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpCellFile_007A6AD8;
    tContext.nFrame = gnFrame_007A6AE0;
    const int nX = gnValue_007A6AB0 + gnValue_007A6AB4;
    const int nY = gnValue_007A6AAC + 0x21;
    tContext.unk0x40 = 0;
    sub_004F6480(&tContext, nX, nY, -1, 5, 0);
}
