struct D2CelContextStrc;

struct D2GlideTexInfoStrc
{
    D2CelContextStrc* pContext;
    int nWidth;
    int nHeight;
    int nOffsetX;
    int nOffsetY;
    int f_14;
    int f_18;
    int nTexSize;
    float fS0;
    float fS1;
    float fT0;
    float fT1;
};

struct D2BoundsStrc
{
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
};

struct D2ClipStrc
{
    int nLeft;
    int nWidth;
    int nTop;
    int nHeight;
};

extern int gnScreenWidth_007C9138; // 0x007C9138
extern int gnScreenHeight_007C913C; // 0x007C913C
extern const char gszEmpty_006CC837[]; // 0x006CC837
const char* __cdecl sub_00408090(); // 0x00408090
void __cdecl sub_00408A60(const char* szMsg, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

static __declspec(noinline) int __stdcall sub_0050B390_ClipSprite(D2GlideTexInfoStrc* pInfo, int nY, const D2BoundsStrc* pBounds, int nX, D2ClipStrc* pClip);

// 0x0050B390
static int __stdcall sub_0050B390_ClipSprite(D2GlideTexInfoStrc* pInfo, int nY, const D2BoundsStrc* pBounds, int nX, D2ClipStrc* pClip)
{
    nX += pInfo->nOffsetX;
    int nWidth = pInfo->nWidth;
    int nHeight = pInfo->nHeight;
    nY += pInfo->nOffsetY;

    pClip->nLeft = 0;
    pClip->nWidth = nWidth;
    pClip->nTop = 0;
    pClip->nHeight = nHeight;

    int nLeft = pBounds->nLeft > 0 ? pBounds->nLeft : 0;
    int nRight = pBounds->nRight < gnScreenWidth_007C9138 ? pBounds->nRight : gnScreenWidth_007C9138;
    if (nLeft > nRight || nX >= nRight || nX + nWidth < nLeft)
    {
        return 1;
    }

    int nTop = pBounds->nTop + 2 > 0 ? pBounds->nTop + 2 : 0;
    int nBottom = pBounds->nBottom < gnScreenHeight_007C913C ? pBounds->nBottom : gnScreenHeight_007C913C;
    if (nTop > nBottom || nY < nTop || nY - nHeight > nBottom)
    {
        return 1;
    }

    if (nX >= nLeft)
        pClip->nLeft = 0;
    else
        pClip->nLeft = nLeft - nX;

    if (nX + nWidth < nRight)
        pClip->nWidth = nWidth - pClip->nLeft;
    else
        pClip->nWidth = nRight - pClip->nLeft - nX;

    if (nY <= nBottom)
        pClip->nTop = 0;
    else
        pClip->nTop = nY - nBottom - 1;

    if (nY - nHeight >= nTop)
        pClip->nHeight = nHeight - pClip->nTop;
    else
        pClip->nHeight = nY - pClip->nTop - nTop + 1;

    if (pClip->nHeight <= 0)
    {
        sub_00408A60(gszEmpty_006CC837, sub_00408090(), 1060);
        exit(-1);
    }
    return 0;
}

int __fastcall Harness_ClipSprite(D2GlideTexInfoStrc* pInfo, int nX, int nY, const D2BoundsStrc* pBounds)
{
    D2ClipStrc tClip;
    if (sub_0050B390_ClipSprite(pInfo, nY, pBounds, nX, &tClip))
    {
        return 0;
    }
    return tClip.nLeft + tClip.nWidth + tClip.nTop + tClip.nHeight;
}
