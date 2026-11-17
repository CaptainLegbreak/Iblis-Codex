struct SMSGHANDLER_PARAMS;

#pragma pack(push, 2)
struct Unicode
{
    unsigned short wChar;
};

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

    D2ListBoxLineStrc();
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
    virtual int sub_004BEC30_GetSelectedIndex();
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
#pragma pack(pop)

// 0x004BEC30
int ListBoxImplementation::sub_004BEC30_GetSelectedIndex()
{
    return nSelectedIndex;
}

// 0x004BEE30
D2ListBoxLineStrc::D2ListBoxLineStrc()
{
    for (int i = 0; i < 0x400; ++i) wszText0[i].wChar = 0;
    for (int i = 0; i < 0x400; ++i) f_800[i].wChar = 0;
    for (int i = 0; i < 0x400; ++i) f_1000[i].wChar = 0;
    for (int i = 0; i < 0x400; ++i) f_1800[i].wChar = 0;
    for (int i = 0; i < 0x400; ++i) f_2000[i].wChar = 0;
    for (int i = 0; i < 0x400; ++i) wszText5[i].wChar = 0;
}
