extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern unsigned char* gpBuffer_007C9154; // 0x007C9154
extern int gnStride_007C9138; // 0x007C9138
extern int gnHeight_007C913C; // 0x007C913C
int __fastcall sub_006C8250_GetSetting(unsigned int nSelector, int* pValue); // 0x006C8250

static __forceinline int sub_006C8A60_Clip(int nValue, int nSize)
{
    int nClipped = nValue > 0 ? nValue : 0;
    return nClipped < nSize - 1 ? nClipped : nSize - 1;
}

// 0x006C8A60
void __fastcall sub_006C8A60_Draw(int nX1, int nY1, int nX2, int nY2, unsigned char nColor, int nLevel)
{
    int nMode;
    unsigned char* pTable = (unsigned char*)sub_006C8250_GetSetting(nLevel, &nMode);

    nX1 = sub_006C8A60_Clip(nX1, gnStride_007C9138);
    nX2 = sub_006C8A60_Clip(nX2, gnStride_007C9138);
    if (nX1 == nX2)
        return;

    nY1 = sub_006C8A60_Clip(nY1, gnHeight_007C913C);
    nY2 = sub_006C8A60_Clip(nY2, gnHeight_007C913C);
    if (nY2 == nY1)
        return;

    D2_ASSERT(nY2 > nY1, 0x32);

    unsigned char* pDst = gpBuffer_007C9154 + nY1 * gnStride_007C9138 + nX1;
    int nRows = nY2 - nY1;
    switch (nMode)
    {
    case 1:
        while (nRows--)
        {
            unsigned char* p = pDst;
            int n = nX2 - nX1;
            while (n--)
            {
                *p = pTable[*p];
                ++p;
            }
            pDst += gnStride_007C9138;
        }
        break;

    case 2:
        while (nRows--)
        {
            unsigned char* p = pDst;
            int n = nX2 - nX1;
            while (n--)
            {
                *p = pTable[(*p << 8) + nColor];
                ++p;
            }
            pDst += gnStride_007C9138;
        }
        break;

    default:
        while (nRows--)
        {
            memset(pDst, nColor, nX2 - nX1);
            pDst += gnStride_007C9138;
        }
        break;
    }
}
