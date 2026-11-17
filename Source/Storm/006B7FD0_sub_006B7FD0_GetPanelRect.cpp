extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2RectStrc { int nLeft; int nTop; int nRight; int nBottom; };

extern int gnScreenWidth_007C9138; // 0x007C9138
extern int gnScreenHeight_007C913C; // 0x007C913C

__declspec(noinline) static void __stdcall sub_006B7FD0_GetPanelRect(D2RectStrc* pRect, int nSide, int* pOffset, int bFlag);

// 0x006B7FD0
static void __stdcall sub_006B7FD0_GetPanelRect(D2RectStrc* pRect, int nSide, int* pOffset, int bFlag)
{
    D2_ASSERT(pRect, 0x53);

    pRect->nLeft = 0;
    pRect->nRight = gnScreenWidth_007C9138;
    pRect->nTop = 0;
    pRect->nBottom = gnScreenHeight_007C913C - 47;

    if (!bFlag)
    {
        pRect->nLeft = -32;
        pRect->nBottom += 32;
        switch (nSide)
        {
        case 1:
            pRect->nRight += -(gnScreenWidth_007C9138 / 2);
            break;
        case 2:
            pRect->nLeft = gnScreenWidth_007C9138 / 2 - 32;
            break;
        }
        return;
    }

    D2_ASSERT(pOffset, 0x69);

    const int nShift = gnScreenWidth_007C9138 / 4;
    switch (nSide)
    {
    case 1:
        *pOffset = -nShift;
        pRect->nRight -= nShift;
        pRect->nLeft += nShift;
        break;
    case 2:
        *pOffset = nShift;
        pRect->nRight -= nShift;
        pRect->nLeft += nShift;
        break;
    }
}

void __fastcall sub_Emit_006B7FD0(D2RectStrc* pRect, int nSide)
{
    int nOffset;
    sub_006B7FD0_GetPanelRect(pRect, nSide, &nOffset, 1);
    sub_006B7FD0_GetPanelRect(pRect, nSide, 0, 0);
}
