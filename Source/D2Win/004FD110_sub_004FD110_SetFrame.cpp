extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CellFileStrc;
struct D2WinControl004FD110Strc
{
    int nType;
    D2CellFileStrc* pCellFile;
    unsigned char f_8[0x38];
    int nFrame;
};
int __stdcall sub_006019F0(D2CellFileStrc* pCellFile); // 0x006019F0

// 0x004FD110
int __stdcall sub_004FD110_SetFrame(D2WinControl004FD110Strc* pControl, int nFrame)
{
    D2_ASSERT(pControl->nType == 2, 0x8B);
    const int nFrames = sub_006019F0(pControl->pCellFile);
    if (nFrame > nFrames - 1)
    {
        nFrame = nFrames - 1;
    }
    if (nFrame < 0)
    {
        nFrame = 0;
    }
    pControl->nFrame = nFrame;
    return 1;
}
