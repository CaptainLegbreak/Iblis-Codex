#include "D2Unicode.h"
int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160

#pragma pack(push, 2)
struct D2ListBoxLineStrc
{
    __forceinline D2ListBoxLineStrc()
    {
    }

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
#pragma pack(pop)

class UIWidget
{
public:
    virtual ~UIWidget();
    virtual void Slot01() = 0;

    int unk0x04;
};

#pragma pack(push, 2)
class ListBoxImplementation : public UIWidget
{
public:
    ListBoxImplementation(int nX, int nY, int nWidth, int nHeight, int nArg10, int nArg14, int nArg18,
        int nCallback, bool bLargeFont);
    virtual void Slot01();

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
    int unk0x18073C;
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

// build: symbol ??1UIWidget@@UAE@XZ 0x004BE080
// build: symbol ??_7ListBoxImplementation@@6B@ 0x006DAAEC
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004BF650
ListBoxImplementation::ListBoxImplementation(int nX, int nY, int nWidth, int nHeight, int nArg10, int nArg14,
    int nArg18, int nCallback, bool bLargeFont)
{
    f_180708 = nX;
    f_18070C = nY;
    nRectWidth = nWidth;
    nRectHeight = nHeight;
    nCallbackRow = -1;
    nSelectedIndex = -1;
    this->nArg14 = nArg14;
    this->nArg18 = nArg18;
    f_18071C = 0;
    bRowsPressed = 0;
    bTopPressed = 0;
    bBottomPressed = 0;
    nState = 0;
    f_180730 = 0;
    nEntryCount = 0;
    for (int n = 0; n < 0x80; n++)
    {
        aLines[n].wszText0[0].wChar = 0;
        aLines[n].f_800[0].wChar = 0;
        aLines[n].f_1000[0].wChar = 0;
        aLines[n].f_1800[0].wChar = 0;
        aLines[n].f_2000[0].wChar = 0;
        aLines[n].wszText5[0].wChar = 0;
        aLines[n].nFlags = 0;
        aLines[n].nData = 0;
        aLines[n].unk0x300A = 1;
        aLines[n].unk0x3002 = 0;
    }
    pfnCallback = nCallback;
    this->nArg10 = nArg10;
    this->nX = f_180708 + nRectWidth - 0x12;
    this->nY = f_18070C + 0x10;
    nScrollStep = 0xE;
    if (nRectHeight < 0x20)
    {
        f_180762 = 1;
    }
    else
    {
        f_180762 = (nRectHeight - 0x10) / 12 - 1;
    }
    f_18074E = 1;
    if (D2GFX_GetResolutionMode() == 2)
    {
        nLineHeight = bLargeFont ? 0x1C : 0x12;
    }
    else
    {
        nLineHeight = 0x12;
    }
}
