struct SMSGHANDLER_PARAMS;
struct D2UnitStrc;

struct Unicode
{
    unsigned short wChar;
};

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00

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

class ListBoxImplementation
{
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual int sub_004BE910_ScrollUp(SMSGHANDLER_PARAMS* pMsg);
    virtual int sub_004BE990_ScrollDown(SMSGHANDLER_PARAMS* pMsg);
    virtual void Slot09();
    virtual void Slot10();
    virtual int Slot11();
    virtual void sub_004BBFB0();
    virtual int sub_004BE0A0_GetLineCount();
    virtual void sub_004BE0B0_Clear();

    int unk0x04;
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
};

class ListBoxWrapper
{
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual int Slot11();
    virtual void sub_004BBFB0();
    virtual void Slot13();
    virtual int sub_004BEE00_Slot14();
    virtual void sub_004BEE10_Slot15();

    int unk0x04;
    ListBoxImplementation* pImpl;
};

#pragma pack(pop)

// 0x004BE0A0
int ListBoxImplementation::sub_004BE0A0_GetLineCount()
{
    return nEntryCount;
}

// 0x004BE0B0
void ListBoxImplementation::sub_004BE0B0_Clear()
{
    for (int i = 0; i < nEntryCount; ++i)
    {
        aLines[i].wszText0[0].wChar = 0;
        aLines[i].f_800[0].wChar = 0;
        aLines[i].f_1000[0].wChar = 0;
        aLines[i].f_1800[0].wChar = 0;
        aLines[i].f_2000[0].wChar = 0;
        aLines[i].wszText5[0].wChar = 0;
    }
    nEntryCount = 0;
}

// 0x004BE910
int ListBoxImplementation::sub_004BE910_ScrollUp(SMSGHANDLER_PARAMS* pMsg)
{
    if (!pfnCallback)
        nSelectedIndex = f_180730;
    if (nSelectedIndex > 0)
    {
        --nSelectedIndex;
        sub_004B9A00(1, 0, 0, 0, 0);
        if (nSelectedIndex < f_180730)
            f_180730 = nSelectedIndex;
        if (nSelectedIndex >= f_180730 + f_18074E)
            ++f_180730;
    }
    return 1;
}

// 0x004BE990
int ListBoxImplementation::sub_004BE990_ScrollDown(SMSGHANDLER_PARAMS* pMsg)
{
    if (!pfnCallback)
    {
        nSelectedIndex = f_180730 + f_18074E - 1;
        if (nSelectedIndex >= nEntryCount)
            nSelectedIndex = nEntryCount - 1;
    }
    if (nSelectedIndex < nEntryCount - 1)
    {
        ++nSelectedIndex;
        sub_004B9A00(1, 0, 0, 0, 0);
        if (nSelectedIndex < f_180730)
            f_180730 = nSelectedIndex;
        if (nSelectedIndex >= f_180730 + f_18074E)
            ++f_180730;
    }
    return 1;
}

// 0x004BEDC0
int ListBoxWrapper::Slot11()
{
    return pImpl->Slot11();
}

// 0x004BEDD0
void ListBoxWrapper::Slot01()
{
    pImpl->Slot01();
}

// 0x004BEE00
int ListBoxWrapper::sub_004BEE00_Slot14()
{
    return pImpl->sub_004BE0A0_GetLineCount();
}

// 0x004BEE10
void ListBoxWrapper::sub_004BEE10_Slot15()
{
    pImpl->sub_004BE0B0_Clear();
}
