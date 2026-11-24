extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                               // 0x00681EF0
#pragma function(memset)

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

extern int gnRenderWidth;                                                                          // 0x007C9138
extern int gnRenderHeight;                                                                         // 0x007C913C
extern unsigned char* gpScreenBuffer_007C9154;                                                              // 0x007C9154

int __fastcall DDCORE_GetDrawModePalette(int nIndex, int* pType);                                           // 0x00511D70

// 0x00512710
void __fastcall sub_00512710_DDrawDrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int nDrawMode)
{
    int nTransMode;
    const unsigned char* pTable = (const unsigned char*)DDCORE_GetDrawModePalette(nDrawMode, &nTransMode);

    const int nX1 = D2_MIN(D2_MAX(nXStart, 0), gnRenderWidth - 1);
    const int nX2 = D2_MIN(D2_MAX(nXEnd, 0), gnRenderWidth - 1);
    if (nX1 == nX2)
        return;

    const int nY1 = D2_MIN(D2_MAX(nYStart, 0), gnRenderHeight - 1);
    const int nY2 = D2_MIN(D2_MAX(nYEnd, 0), gnRenderHeight - 1);
    if (nY2 == nY1)
        return;

    D2_ASSERT(nY2 > nY1, 0x39);

    unsigned char* pDst = gpScreenBuffer_007C9154 + gnRenderWidth * nY1 + nX1;
    int nRows = nY2 - nY1;

    switch (nTransMode)
    {
    default:
        while (nRows--)
        {
            memset(pDst, (unsigned char)dwColor, nX2 - nX1);
            pDst += gnRenderWidth;
        }
        break;

    case 2:
        while (nRows--)
        {
            unsigned char* p = pDst;
            int n = nX2 - nX1;
            while (n--)
            {
                *p = pTable[(*p << 8) + (unsigned char)dwColor];
                ++p;
            }
            pDst += gnRenderWidth;
        }
        break;

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
            pDst += gnRenderWidth;
        }
        break;
    }
}
