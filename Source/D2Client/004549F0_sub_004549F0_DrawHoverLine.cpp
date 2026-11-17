struct D2RectStrc
{
    int nLeft;
    int nTop;
    int nRight;
    int nBottom;
};

int __fastcall sub_00454880_GetHoverRect(D2RectStrc* pRect); // 0x00454880
int __fastcall sub_00502EF0_SetFont(int nFont); // 0x00502EF0
unsigned short* __fastcall sub_005267E0(unsigned short* pDest, const unsigned short* pSource); // 0x005267E0
int __fastcall sub_00501820(const unsigned short* wszText); // 0x00501820
void __fastcall sub_00502320(const unsigned short* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320

static __declspec(noinline) void __stdcall sub_004549F0_DrawHoverLine(const unsigned short* wszText, int nFont, int nY, int nColor);

// 0x004549F0
static void __stdcall sub_004549F0_DrawHoverLine(const unsigned short* wszText, int nFont, int nY, int nColor)
{
    unsigned short wszBuffer[256];
    for (int i = 0; i < 256; i++)
    {
        wszBuffer[i] = 0;
    }

    D2RectStrc tRect;

    if (!sub_00454880_GetHoverRect(&tRect) || !wszText)
    {
        return;
    }

    const int nOldFont = sub_00502EF0_SetFont(nFont);
    sub_005267E0(wszBuffer, wszText);
    const int nX = ((tRect.nLeft + tRect.nRight) >> 1) - (sub_00501820(wszBuffer) >> 1);
    sub_00502320(wszBuffer, nX, nY, nColor, 1);
    sub_00502EF0_SetFont(nOldFont);
}

// build: context sub_004549F0_Shim

// calling-convention shim (not game code)
void __fastcall sub_004549F0_Shim(const unsigned short* wszText, int nFont)
{
    sub_004549F0_DrawHoverLine(wszText, nFont, 10, 0);
}
