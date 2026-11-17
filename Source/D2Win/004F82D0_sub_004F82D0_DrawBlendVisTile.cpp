extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int gnClipBottom_007C978C;                                                                                  // 0x007C978C
int gnClipLeft_007C9794;                                                                                    // 0x007C9794
int gnInnerRight_007C9784;                                                                                  // 0x007C9784
int gnInnerBottom_007C9790;                                                                                 // 0x007C9790
int gnRowClipBottom_007C97A0;                                                                               // 0x007C97A0
extern int gnRowOffsets_007C97A8[732];                                                                      // 0x007C97A8
#define gnRowOffsets_007C9828 (gnRowOffsets_007C97A8 + 32)
int gnColClipLeft_007CA318;                                                                                 // 0x007CA318
int gnInnerTop_007CA31C;                                                                                    // 0x007CA31C
int gnClipRight_007D2324;                                                                                   // 0x007D2324
int gnInnerLeft_007D2328;                                                                                   // 0x007D2328
int gnClipTop_007D232C;                                                                                     // 0x007D232C
int gnRowClipTop_007D2334;                                                                                  // 0x007D2334
int gnColClipRight_007D233C;                                                                                // 0x007D233C
extern unsigned char* gpScreenBuffer_007D5448;                                                              // 0x007D5448
int gnScreenPitch_007D544C;                                                                                 // 0x007D544C
unsigned char** gppBlendTables_007D5578;                                                                    // 0x007D5578

// 0x004F82D0
void __fastcall sub_004F82D0_DrawBlendVisTile(unsigned char* pSrc, int nX, int nY, unsigned char nAlpha)
{
    unsigned char* pDst;
    unsigned char* p;
    unsigned char* pBlend;
    if (nAlpha >= 0xC0)
        pBlend = gppBlendTables_007D5578[0];
    else if (nAlpha >= 0x80)
        pBlend = gppBlendTables_007D5578[1];
    else if (nAlpha >= 0x40)
        pBlend = gppBlendTables_007D5578[2];
    else
        return;

    if (nY < gnClipTop_007D232C || nY >= gnClipBottom_007C978C || nX < gnClipLeft_007C9794 || nX >= gnClipRight_007D2324)
        return;

    D2_ASSERT(gpScreenBuffer_007D5448, 0x3F8);
    pDst = gnRowOffsets_007C9828[nY] + gpScreenBuffer_007D5448 + nX;
    p = pDst;
    if (nY >= gnInnerTop_007CA31C && nY < gnInnerBottom_007C9790 && nX >= gnInnerLeft_007D2328 && nX < gnInnerRight_007C9784)
    {
        int nRows = 0x20;
        while (nRows)
        {
            int nSkip = *pSrc++;
            int nCount = *pSrc++;
            if (!nSkip && !nCount)
            {
                --nRows;
                pDst += gnScreenPitch_007D544C;
                p = pDst;
            }
            else
            {
                unsigned char* pEnd = pSrc + nCount;
                p += nSkip;
                while (pSrc < pEnd)
                {
                    *p = pBlend[(*p << 8) + *pSrc++];
                    ++p;
                }
            }
        }
    }
    else
    {
        int nRow = 0;
        int nRowY = nY;
        while (nRow < 0x20)
        {
            int nSkip = *pSrc++;
            int nCount = *pSrc++;
            if (!nSkip && !nCount)
            {
                ++nRow;
                ++nRowY;
                pDst += gnScreenPitch_007D544C;
                p = pDst;
            }
            else
            {
                if (nRowY >= gnRowClipBottom_007C97A0)
                    return;

                p += nSkip;
                if (nRowY >= gnRowClipTop_007D2334)
                {
                    unsigned char* pNextSrc = pSrc + nCount;
                    int nPosX = p - pDst + nX;
                    unsigned char* pNextDst = p + nCount;
                    __assume(nPosX != 0x80000000);
                    nPosX = -nPosX;
                    int nLeft = gnColClipLeft_007CA318 + nPosX;
                    nLeft = nLeft > 0 ? nLeft : 0;
                    int nRight = gnColClipRight_007D233C + nPosX;
                    nRight = nRight > 0 ? nRight : 0;
                    if (nRight >= nCount)
                        nRight = nCount;
                    const int nLength = nRight - nLeft;
                    if (nLength > 0)
                    {
                        pSrc += nLeft;
                        unsigned char* pEnd = pSrc + nLength;
                        p += nLeft;
                        while (pSrc < pEnd)
                        {
                            *p = pBlend[(*p << 8) + *pSrc];
                            ++pSrc;
                            ++p;
                        }
                    }

                    pSrc = pNextSrc;
                    p = pNextDst;
                }
                else
                {
                    p += nCount;
                    pSrc += nCount;
                }
            }
        }
    }
}
