struct Unicode
{
    unsigned short wChar;
};

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    void* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
extern void* gpCelFile_007C546C;                                                                            // 0x007C546C

#pragma pack(push, 2)

struct D2ListBoxLineStrc
{
    Unicode wszText0[0x400];
    Unicode f_800[0x400];
    Unicode f_1000[0x400];
    Unicode f_1800[0x400];
    Unicode f_2000[0x400];
    Unicode wszText5[0x400];
    short nFlags;
    int unk0x3002;
    int nData;
    int unk0x300A;
};

class UIWidget
{
public:
    virtual ~UIWidget();
    virtual void Slot01();

    int unk0x04;
};

class ListBoxImplementation : public UIWidget
{
public:
    virtual void Slot01();

    void sub_004BE110_UpdateScrollBar();

    D2ListBoxLineStrc aLines[0x80];
    int f_180708;
    int f_18070C;
    int nRectWidth;
    int nRectHeight;
    int nLineHeight;
    int f_18071C;
    int bTopPressed;
    int bBottomPressed;
    int bRowsPressed;
    int nPressY;
    int f_180730;
    int nCallbackRow;
    int nSelectedIndex;
    int nTextCount;
    int nArg14;
    int nArg18;
    unsigned short nEntryCount;
    int pfnCallback;
    int f_18074E;
    int unk0x180752;
    int unk0x180756;
    int nX;
    int nY;
    int f_180762;
    int nScrollStep;
    int nArg10;
    int nRepeatTicks;
    int nState;
};

#pragma pack(pop)

// 0x004BE110
void ListBoxImplementation::sub_004BE110_UpdateScrollBar()
{
    const int nEntries = nEntryCount;
    int nHeight = 0;
    unk0x180752 = 0;
    unk0x180756 = 0;
    f_18074E = 0;
    for (int i = f_180730; i < nEntryCount; ++i)
    {
        if (aLines[i].wszText0[0].wChar)
        {
            nHeight += nScrollStep;
        }
        if (aLines[i].f_800[0].wChar)
        {
            nHeight += nScrollStep;
        }
        if (aLines[i].f_1000[0].wChar)
        {
            nHeight += nScrollStep;
        }
        if (aLines[i].f_1800[0].wChar)
        {
            nHeight += nScrollStep;
        }
        if (aLines[i].f_2000[0].wChar)
        {
            nHeight += nScrollStep;
        }
        if (aLines[i].wszText5[0].wChar)
        {
            nHeight += nScrollStep;
        }
        nHeight += nArg10;
        if (nHeight < nRectHeight - 20)
        {
            ++f_18074E;
        }
    }

    if (nEntries <= f_18074E)
    {
        return;
    }

    const int nRatio = (f_18074E << 7) / nEntries;
    int nStart;
    int nEnd;
    if (!f_180730)
    {
        nStart = 0;
        nEnd = (unsigned int)(nLineHeight * nRatio) >> 7;
    }
    else if (f_180730 >= nEntries - f_18074E)
    {
        nStart = nLineHeight - ((unsigned int)(nLineHeight * nRatio) >> 7);
        nStart = nLineHeight < nStart ? nLineHeight : nStart;
        nEnd = nLineHeight;
    }
    else
    {
        const int nThumb = (unsigned int)(nLineHeight * nRatio) >> 7;
        nStart = nLineHeight * f_180730 / nEntries;
        nStart = nStart < 0 ? 0 : nStart;
        nEnd = nLineHeight < nThumb + nStart ? nLineHeight : nThumb + nStart;
    }

    const int nTop = nY + 13;
    const int nLeft = nX - 1;
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpCelFile_007C546C;
    tContext.unk0x40 = 0;
    tContext.nFrame = 16;
    sub_004F6480(&tContext, nLeft, nTop + 12 * nStart, -1, 5, 0);
    tContext.nFrame = 14;
    int nRow = nStart;
    for (; nRow < nEnd; ++nRow)
    {
        sub_004F6480(&tContext, nLeft, nTop + 12 * (nRow + 1), -1, 5, 0);
    }
    tContext.nFrame = 15;
    sub_004F6480(&tContext, nLeft, nTop + 12 * (nRow + 1), -1, 5, 0);
    unk0x180752 = nStart;
    unk0x180756 = nEnd;
}
