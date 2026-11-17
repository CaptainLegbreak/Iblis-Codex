struct D2CellFileStrc;
struct D2CelFileStrc;

struct D2OptionHeaderStrc
{
    int unk0x00[4];
    int nY;
};

struct D2OptionEntryStrc
{
    char unk0x000[0x120];
    unsigned int nValues;
    unsigned int nValue;
    int bEnabled;
};

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    D2CelFileStrc* pCelFile;
    int unk0x38[4];
};

extern int gnScreenWidth_0071146C;                                                                          // 0x0071146C
extern D2OptionHeaderStrc* gpOptionHeader_007BC93C;                                                         // 0x007BC93C
extern D2CellFileStrc* gpSliderDisabledCell_007BC950;                                                       // 0x007BC950
extern D2CellFileStrc* gpSliderEnabledCell_007BC954;                                                        // 0x007BC954
extern D2CelFileStrc* gpSliderKnob_007BC958;                                                                // 0x007BC958

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nStyle); // 0x0046EFD0
void __fastcall sub_00502680_DrawCellFile(D2CellFileStrc* pCellFile, int nX, int nY, int nFrame, int nColor, int nArg6); // 0x00502680
int __stdcall TEXTURE_CelDraw(D2CelContextStrc* pContext, int nX, int nY, int nArg4, int nColor, int nArg6); // 0x004F6480

// 0x0047E260
void __stdcall sub_0047E260_DrawOptionSlider(D2OptionEntryStrc* pEntry, int nY, int nColor, int bSmall)
{
    const int* pbEnabled = &pEntry->bEnabled;
    int nScreenY = gpOptionHeader_007BC93C->nY + nY;
    nY = bSmall ? (gnScreenWidth_0071146C / 2) - 145 : (gnScreenWidth_0071146C / 2) - 60;
    int nKnobX = nY - (int)(-265.0 / (float)(pEntry->nValues - 1) * (float)pEntry->nValue);
    int nKnobY = nScreenY - !*pbEnabled - 1;
    int nWidth = nKnobX - nY + 12;
    const int nBoxY = nScreenY - 30;
    int nBoxX = bSmall ? (gnScreenWidth_0071146C / 2) - 144 : (gnScreenWidth_0071146C / 2) - 59;
    sub_0046EFD0_DrawFramedBox(nBoxX, nBoxY, nWidth, 30, 0, *pbEnabled ? 1 : 2);
    sub_0046EFD0_DrawFramedBox(nBoxX + nWidth, nBoxY, 289 - nWidth, 30, 0, *pbEnabled != 0);

    int nCellX = gnScreenWidth_0071146C / 2 + 230;
    int nFrame = 2;
    if (bSmall)
    {
        nCellX = gnScreenWidth_0071146C / 2;
        nFrame = 1;
    }

    sub_00502680_DrawCellFile(*pbEnabled ? gpSliderEnabledCell_007BC954 : gpSliderDisabledCell_007BC950, nCellX, nScreenY, nFrame, nColor, -1);

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCelFile = gpSliderKnob_007BC958;
    TEXTURE_CelDraw(&tContext, nKnobX, nKnobY, -1, nColor, 0);
}
