#include "D2Client.h"
#include "D2Unicode.h"
#include "D2StormTypes.h"

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, int nFlags);                   // 0x00413020

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
    // 0x004BE080
    virtual ~UIWidget()
    {
    }
    virtual void Slot01();

    static void* operator new(unsigned int nSize)
    {
        return SMemAlloc(nSize, gszNew_006CC82C, -1, 0);
    }

    int unk0x04;
};

class ListBoxImplementation : public UIWidget
{
public:
    ListBoxImplementation(int nX, int nY, int nWidth, int nHeight, int nArg10, int nArg14, int nArg18,
        int nCallback, bool bLargeFont);                                                                    // 0x004BF650
    virtual void Slot01();

    void sub_004BE500_AddLine(const Unicode* wszText0, const Unicode* wszText1, const Unicode* wszText2,
        const Unicode* wszText3, const Unicode* wszText4, const Unicode* wszText5, int nArg20, int nData,
        int bUseDefault, int nArg2C);
    int sub_004BEA50_HitTestEntry(SMSGHANDLER_PARAMS* pMsg);

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

class ListBoxWrapper : public UIWidget
{
public:
    ListBoxWrapper(int nX, int nY, int nWidth, int nHeight, int nArg10, int nArg14, int nArg18, int nCallback,
        bool bLargeFont);
    virtual ~ListBoxWrapper();
    virtual void Slot01();

    ListBoxImplementation* pImpl;
};

#pragma pack(pop)

// build: symbol ??0ListBoxImplementation@@QAE@HHHHHHHH_N@Z 0x004BF650
// build: symbol ??_7ListBoxWrapper@@6B@ 0x006DAAA4
// build: symbol ??_7UIWidget@@6B@ 0x006DA6C0
// 0x004BE500
void ListBoxImplementation::sub_004BE500_AddLine(const Unicode* wszText0, const Unicode* wszText1, const Unicode* wszText2,
    const Unicode* wszText3, const Unicode* wszText4, const Unicode* wszText5, int nArg20, int nData, int bUseDefault,
    int nArg2C)
{
    if (nEntryCount >= 0x80)
    {
        return;
    }

    aLines[nEntryCount].unk0x3002 = nArg20;
    if (nSelectedIndex == -1)
    {
        nSelectedIndex = 0;
    }
    if (wszText0)
    {
        Unicode::strncpy(aLines[nEntryCount].wszText0, wszText0, 0x3FF);
        aLines[nEntryCount].wszText0[0x3FF].wChar = 0;
        ++nTextCount;
    }
    if (wszText1)
    {
        Unicode::strncpy(aLines[nEntryCount].f_800, wszText1, 0x3FF);
        aLines[nEntryCount].f_800[0x3FF].wChar = 0;
        ++nTextCount;
    }
    if (wszText2)
    {
        Unicode::strncpy(aLines[nEntryCount].f_1000, wszText2, 0x3FF);
        aLines[nEntryCount].f_1000[0x3FF].wChar = 0;
        ++nTextCount;
    }
    if (wszText3)
    {
        Unicode::strncpy(aLines[nEntryCount].f_1800, wszText3, 0x3FF);
        aLines[nEntryCount].f_1800[0x3FF].wChar = 0;
        ++nTextCount;
    }
    if (wszText4)
    {
        Unicode::strncpy(aLines[nEntryCount].f_2000, wszText4, 0x3FF);
        aLines[nEntryCount].f_2000[0x3FF].wChar = 0;
        ++nTextCount;
    }
    if (wszText5)
    {
        Unicode::strncpy(aLines[nEntryCount].wszText5, wszText5, 0x3FF);
        aLines[nEntryCount].wszText5[0x3FF].wChar = 0;
        ++nTextCount;
    }
    if (bUseDefault)
    {
        aLines[nEntryCount].nData = nArg14;
    }
    else
    {
        aLines[nEntryCount].nData = nData;
    }
    aLines[nEntryCount].unk0x300A = nArg2C;
    ++nEntryCount;
}

// 0x004BEA50
int ListBoxImplementation::sub_004BEA50_HitTestEntry(SMSGHANDLER_PARAMS* pMsg)
{
    if (pMsg->nXpos <= nX - 0xF && pfnCallback)
    {
        const int nMouseY = pMsg->nYpos;
        int nOffset = 0;
        for (int i = f_180730; i < nEntryCount; i++)
        {
            const int nStart = nOffset;
            if (aLines[i].wszText0[0].wChar)
            {
                nOffset += nScrollStep;
            }
            if (aLines[i].f_800[0].wChar)
            {
                nOffset += nScrollStep;
            }
            if (aLines[i].f_1000[0].wChar)
            {
                nOffset += nScrollStep;
            }
            if (aLines[i].f_1800[0].wChar)
            {
                nOffset += nScrollStep;
            }
            if (aLines[i].f_2000[0].wChar)
            {
                nOffset += nScrollStep;
            }
            if (aLines[i].wszText5[0].wChar)
            {
                nOffset += nScrollStep;
            }
            if (nMouseY > f_18070C + nStart + 0xC && nMouseY < f_18070C + nOffset + 0xC)
            {
                nSelectedIndex = i;
                return i;
            }
            nOffset += nArg10;
        }
        nSelectedIndex = -1;
        return -1;
    }
    return -1;
}

// 0x004BECC0
ListBoxWrapper::~ListBoxWrapper()
{
    delete pImpl;
}

// 0x004BF8F0
ListBoxWrapper::ListBoxWrapper(int nX, int nY, int nWidth, int nHeight, int nArg10, int nArg14, int nArg18,
    int nCallback, bool bLargeFont)
{
    pImpl = new ListBoxImplementation(nX, nY, nWidth, nHeight, nArg10, nArg14, nArg18, nCallback, bLargeFont);
}
