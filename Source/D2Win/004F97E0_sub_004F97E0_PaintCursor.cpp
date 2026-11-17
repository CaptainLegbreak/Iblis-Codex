struct D2CellFileStrc;

struct tagPOINT
{
    long x;
    long y;
};

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    D2CellFileStrc* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

extern int dword_6F8BDE18;                                                                                  // 0x0072DC3C
extern D2CellFileStrc* gpCursorCellFile;                                                                    // 0x007D5594
int dword_6F8FE228;                                                                                         // 0x007D5598
int dword_6F8FE22C;                                                                                         // 0x007D559C
extern int gnCursorFrame;                                                                                   // 0x007D55A0
extern tagPOINT gMousePosition_6F8FE234;                                                                    // 0x007D55A4

// 0x004F97E0
void __cdecl sub_004F97E0_PaintCursor()
{
    if (gpCursorCellFile && dword_6F8BDE18)
    {
        int nX = gMousePosition_6F8FE234.x;
        int nY = gMousePosition_6F8FE234.y;
        dword_6F8FE228 = nX;
        dword_6F8FE22C = nY;

        D2CelContextStrc tContext;
        memset(&tContext, 0, sizeof(tContext));
        tContext.nFrame = gnCursorFrame;
        tContext.pCellFile = gpCursorCellFile;
        tContext.unk0x40 = 0;
        sub_004F6480(&tContext, nX <= 0 ? 0 : nX, (nY <= 0 ? 0 : nY) - 1, -1, 5, 0);
    }
}
