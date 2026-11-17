#include "D2Client.h"

struct Sub004BDFD0;
struct Obj004BDFD0;
class UIWidget;
struct Unicode;
struct D2ListBoxLineStrc;
class ListBoxImplementation;
class ListBoxWrapper;
struct ListBox;

struct Sub004BDFD0 { unsigned char bUnknown00[0x28]; unsigned int dwMember28; };

struct Obj004BDFD0 { unsigned char bUnknown00[0x14]; Sub004BDFD0* pSub14; };

class UIWidget
{
public:
    UIWidget();
    virtual ~UIWidget() = 0;
    virtual void Slot01() = 0;
    virtual int MsgSlot02(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot03(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot04(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot05(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot06(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot07(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot08(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot09(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot10(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int Slot11() = 0;

    int unk0x04;
};

struct Unicode
{
    unsigned short wChar;
};

struct D2UnitStrc
{
    char unk0x00[0x60];
    D2InventoryStrc* pInventory;
};

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00

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
typedef void (__cdecl* Callback)();

#pragma pack(push, 2)
struct ListBox {
    virtual void Slot0(); virtual void Slot1(); virtual void Slot2();
    virtual void Slot3(); virtual void Slot4(); virtual void Slot5(); virtual void Slot6();
    virtual int ScrollUp(Message*); virtual int ScrollDown(Message*);
    char pad4[0x180718];
    int mouseDown,topPressed,bottomPressed,rowsPressed,pressY,topIndex,callbackRow;
    char pad738[0x12];
    Callback callback;
    int sub_004BE720(Message*); int sub_004BE770(Message*); int sub_004BE7C0(Message*);
    int sub_004BF2F0(Message*); int sub_004BEA50(Message*);
    int sub_004BF530(Message*);
};

#pragma pack(pop)
enum { INVALID_ROW = -1 };

D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0

// 0x004BDFD0
extern "C" __declspec(dllexport) unsigned int* __fastcall sub_004BDFD0(Obj004BDFD0* pObj) {
    return &pObj->pSub14->dwMember28;
}

// build: symbol ??_7UIWidget@@6B@ 0x006DA6C0
// 0x004BE080
UIWidget::~UIWidget()
{
}

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

// 0x004BEA30
int __stdcall sub_00646000_AlwaysZero(int nUnused)
{
    return 0;
}

void __stdcall sub_00646010_Empty(int nUnused1, int nUnused2, int nUnused3)
{
}

void __stdcall sub_006460C0_Empty(int nUnused)
{
}

void __stdcall sub_006460D0_Empty(int nUnused1, int nUnused2, int nUnused3)
{
}

void __stdcall sub_006460E0_Empty(int nUnused)
{
}

// build: symbol ?sub_004BE720@ListBox@@QAEHPAUMessage@@@Z 0x004BE720
// build: symbol ?sub_004BE770@ListBox@@QAEHPAUMessage@@@Z 0x004BE770
// build: symbol ?sub_004BE7C0@ListBox@@QAEHPAUMessage@@@Z 0x004BE7C0
// build: symbol ?sub_004BEA50@ListBox@@QAEHPAUMessage@@@Z 0x004BEA50
// build: symbol ?sub_004BF2F0@ListBox@@QAEHPAUMessage@@@Z 0x004BF2F0
// 0x004BF530
int ListBox::sub_004BF530(Message* message)
{
    if(!mouseDown) { callbackRow=INVALID_ROW; return 1; }
    mouseDown=0;
    if(topPressed==1) {
        topPressed=0;
        if(sub_004BE720(message)==1) ScrollUp(message);
        callbackRow=INVALID_ROW;
        return 0;
    }
    if(bottomPressed==1) {
        bottomPressed=0;
        if(sub_004BE770(message)==1) ScrollDown(message);
        callbackRow=INVALID_ROW;
        return 0;
    }
    if(rowsPressed==1) {
        rowsPressed=0;
        if(sub_004BE7C0(message)==1) sub_004BF2F0(message);
        callbackRow=INVALID_ROW;
        return 0;
    }
    if(callback) {
        int hit=sub_004BEA50(message);
        if(callbackRow==hit && callbackRow!=INVALID_ROW) {
            callbackRow=INVALID_ROW;
            callback();
            return 1;
        }
    }
    return 0;
}

// 0x004BF990
D2UnitStrc* __cdecl sub_004BF990_GetPlayerCursorItem()
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (pPlayer)
    {
        return INVENTORY_GetCursorItem(pPlayer->pInventory);
    }
    return 0;
}
