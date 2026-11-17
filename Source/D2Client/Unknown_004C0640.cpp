extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

struct D2UiBlockRectStrc
{
    int nLeft;
    int nTop;
    int nRight;
    int nBottom;
    char unk0x10[0x110];
};

extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gnBlockRectCount_007C54A0;                                                                       // 0x007C54A0
extern D2UiBlockRectStrc gaBlockRects_007C54A8[32];                                                         // 0x007C54A8

// build: context sub_004C0640_ClampToScreen
static __forceinline void sub_004C0640_ClampToScreen(int* pLeft, int* pTop, int* pRight, int* pBottom, int nMaxX, int nMinX, int nMaxY)
{
    if (*pLeft < nMinX)
    {
        *pRight += nMinX - *pLeft;
        *pLeft = 6;
    }

    if (*pTop < 6)
    {
        *pBottom += 6 - *pTop;
        *pTop = 6;
    }

    if (*pRight >= nMaxX)
    {
        int nDelta = *pRight - nMaxX + 1;
        *pRight -= nDelta;
        *pLeft -= nDelta;
    }

    if (*pBottom >= nMaxY)
    {
        int nDelta = *pBottom - nMaxY;
        *pBottom -= nDelta;
        *pTop -= nDelta;
    }
}

// 0x004C0640
int __fastcall sub_004C0640_ClampRectToScreen(int* pLeft, int* pTop, int* pRight, int* pBottom, int nMode, int nMaxX, int nMinX)
{
    int nMaxY = gnGlobal_00711470 - 48;

    sub_004C0640_ClampToScreen(pLeft, pTop, pRight, pBottom, nMaxX, nMinX, nMaxY);

    if (gnBlockRectCount_007C54A0 >= 32)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x47);
        exit(-1);
    }

    for (int i = 0; i < gnBlockRectCount_007C54A0; ++i)
    {
        const int bX = (*pLeft <= gaBlockRects_007C54A8[i].nRight && *pRight >= gaBlockRects_007C54A8[i].nLeft) ? 1 : 0;
        const int bY = (*pTop <= gaBlockRects_007C54A8[i].nBottom && *pBottom >= gaBlockRects_007C54A8[i].nTop) ? 1 : 0;
        if (bX && bY)
        {
            int nDelta;
            if (nMode > 6)
            {
                if ((*pRight - *pLeft) / 2 && *pLeft >= nMaxX)
                    nDelta = gaBlockRects_007C54A8[i].nLeft - *pRight - 1;
                else
                    nDelta = gaBlockRects_007C54A8[i].nRight - *pLeft + 1;
                *pLeft += nDelta;
                *pRight += nDelta;
                return 0;
            }

            if ((*pBottom - *pTop) / 2 && *pTop <= nMaxY)
                nDelta = gaBlockRects_007C54A8[i].nTop - *pBottom - 3;
            else
                nDelta = gaBlockRects_007C54A8[i].nBottom - *pTop + 5;
            *pTop += nDelta;
            *pBottom += nDelta;
            return 0;
        }
    }

    return 1;
}
