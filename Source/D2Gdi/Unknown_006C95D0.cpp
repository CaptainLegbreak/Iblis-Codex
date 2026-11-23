#include "D2Gdi.h"

struct D2DrawTable006C95D0Strc
{
    unsigned char unk_00[0x0C];
    void (__fastcall* pfDraw)(void* a, int nX, int nY, void* b);
};
extern D2DrawTable006C95D0Strc* gpDrawTable_007C914C; // 0x007C914C
int __stdcall sub_005FDEA0_Check(void* a, int n1, int n0); // 0x005FDEA0

// 0x006C95D0
void __fastcall sub_006C95D0_DrawShifted(void* a, void* b, int nX, int nY, int nUnused1, int nUnused2, int nUnused3, int nMode, int nUnused4)
{
    if (sub_005FDEA0_Check(a, 1, 0))
    {
        nX -= 80;
        switch (nMode)
        {
        case 1:
// build: symbol ?gnRenderWidth@* 0x007C9138
            nX -= gnRenderWidth / 4;
            break;
        case 2:
            nX += gnRenderWidth / 4;
            break;
        }
        gpDrawTable_007C914C->pfDraw(a, nX, nY, b);
    }
}
