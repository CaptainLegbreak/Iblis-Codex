extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ClearPairStrc
{
    char pad0x00[0x14];
    int nFirst;
    int nSecond;

    D2ClearPairStrc();
};

struct D2GridRectStrc
{
    int nLeft;
    int nTop;
    int nRight;
    int nBottom;
};

struct D2GridCellStrc
{
    unsigned char nB0;
    unsigned char nB1;
    unsigned char nB2;
    unsigned char nB3;
    int nX;
    int nY;
};

// 0x004DDDD0
D2ClearPairStrc::D2ClearPairStrc()
{
    nFirst = 0;
    nSecond = 0;
}

// 0x004DDDE0
void __cdecl sub_004DDDE0_Nop()
{
}

// 0x004DDE40
static __forceinline int sub_004DDE40_IsPointInRect(D2GridRectStrc* pRect, int nX, int nY)
{
    D2_ASSERT(pRect, 0x76);
    if (nX < pRect->nLeft || nX >= pRect->nRight || nY < pRect->nTop || nY >= pRect->nBottom)
    {
        return 0;
    }
    return 1;
}

// 0x004DDEC0
static __forceinline void sub_004DDEC0_FillCells(D2GridCellStrc* pCells)
{
    for (int j = 0; j < 8; ++j)
    {
        for (int i = 0; i < 8; ++i)
        {
            pCells->nB0 = 0xFF;
            pCells->nB1 = 0xFF;
            pCells->nB3 = 0xFF;
            pCells->nB2 = 0xFF;
            ++pCells;
        }
    }
}

int __fastcall sub_M131_Emit_004DDE40(D2GridRectStrc* pRect, int nX, int nY, D2GridCellStrc* pCells)
{
    if (!sub_004DDE40_IsPointInRect(pRect, nX, nY))
    {
        return 0;
    }
    sub_004DDEC0_FillCells(pCells);
    return 1;
}
