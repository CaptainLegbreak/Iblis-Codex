extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

static int gnClipBottom_007C978C;                                                                           // 0x007C978C
static int gnClipLeft_007C9794;                                                                             // 0x007C9794
static int gnInnerRight_007C9784;                                                                           // 0x007C9784
static int gnInnerBottom_007C9790;                                                                          // 0x007C9790
static int gnRowClipBottom_007C97A0;                                                                        // 0x007C97A0
extern int gnRowOffsets_007C9828[];                                                                         // 0x007C9828
static int gnColClipLeft_007CA318;                                                                          // 0x007CA318
static int gnInnerTop_007CA31C;                                                                             // 0x007CA31C
static int gnClipRight_007D2324;                                                                            // 0x007D2324
static int gnInnerLeft_007D2328;                                                                            // 0x007D2328
static int gnClipTop_007D232C;                                                                              // 0x007D232C
static int gnRowClipTop_007D2334;                                                                           // 0x007D2334
static int gnColClipRight_007D233C;                                                                         // 0x007D233C
extern unsigned char* gpScreenBuffer_007D5448;                                                              // 0x007D5448
extern int gnScreenPitch_007D544C;                                                                          // 0x007D544C

extern int gnResolutionMode_007C8CC4; // 0x007C8CC4
static int gnScreen_7C9780; // 0x007C9780
static int gnScreen_7C9788; // 0x007C9788
static int gnScreen_7C9798; // 0x007C9798
static int gnScreen_7C979C; // 0x007C979C
static int gnScreen_7C97A4; // 0x007C97A4
static int gnScreen_7D2320; // 0x007D2320
static int gnScreen_7D2330; // 0x007D2330
static int gnScreen_7D2338; // 0x007D2338

// 0x004F7DA0
void __fastcall sub_004F7DA0_SetPanelCoords(int nWidth, int nHeight)
{
    int nLeft = 0;
    int nRight = nWidth;
    const int nBottom = nHeight - 0x2F;
    if (gnResolutionMode_007C8CC4 == 1)
    {
        nRight -= nWidth / 2;
    }
    else if (gnResolutionMode_007C8CC4 == 2)
    {
        nLeft = nWidth / 2;
    }
    gnScreen_7D2338 = nBottom;
    gnScreen_7C97A4 = nLeft;
    gnInnerLeft_007D2328 = nLeft;
    gnColClipLeft_007CA318 = nLeft;
    gnScreen_7D2330 = -0x10;
    gnScreen_7C9788 = nLeft - 0x20;
    gnScreen_7C979C = nBottom - 0x10;
    gnScreen_7C9798 = nRight;
    gnScreen_7C9780 = 0;
    gnScreen_7D2320 = nRight - 0x20;
    gnClipTop_007D232C = -0x20;
    gnClipRight_007D2324 = nRight;
    gnClipBottom_007C978C = nBottom;
    gnInnerTop_007CA31C = 0;
    gnClipLeft_007C9794 = nLeft - 0x20;
    gnInnerBottom_007C9790 = nBottom - 0x20;
    gnInnerRight_007C9784 = nRight - 0x20;
    gnRowClipTop_007D2334 = 0;
    gnColClipRight_007D233C = nRight;
    gnRowClipBottom_007C97A0 = nBottom;
}

// 0x004F7EA0
void __fastcall sub_004F7EA0_DrawVisTile(unsigned char* pSrc, int nX, int nY)
{
    if (nY < gnClipTop_007D232C || nY >= gnClipBottom_007C978C || nX < gnClipLeft_007C9794 || nX >= gnClipRight_007D2324)
        return;

    D2_ASSERT(gpScreenBuffer_007D5448, 0x2F4);
    unsigned char* pDst = gnRowOffsets_007C9828[nY] + gpScreenBuffer_007D5448 + nX;
    unsigned char* p = pDst;
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
                p += nSkip;
                memcpy(p, pSrc, nCount);
                p += nCount;
                pSrc += nCount;
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
                    const int nPosX = p - pDst + nX;
                    int nLeft = gnColClipLeft_007CA318 + (-nPosX);
                    nLeft = D2_MAX(nLeft, 0);
                    int nRight = gnColClipRight_007D233C + (-nPosX);
                    nRight = D2_MAX(nRight, 0);
                    if (nRight >= nCount)
                        nRight = nCount;
                    const int nLength = nRight - nLeft;
                    if (nLength > 0)
                        memcpy(p + nLeft, pSrc + nLeft, nLength);

                    pSrc += nCount;
                    p += nCount;
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
