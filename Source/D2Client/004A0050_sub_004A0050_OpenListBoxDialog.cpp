typedef unsigned int size_t;

struct SMSGHANDLER_PARAMS;
struct D2ClientDialogStrc;

struct Unicode
{
    unsigned short wChar;
};

void* __stdcall SMemAlloc(size_t nSize, const char* szFile, int nLine, int nFlags);                         // 0x00413020
void __cdecl sub_0049E340();                                                                                // 0x0049E340
int __cdecl sub_004A0030_DialogCallback();                                                                  // 0x004A0030
void __fastcall sub_004B7C00_AddWidget(D2ClientDialogStrc* pDialog, void* pWidget, int nArg8, int nArgC);   // 0x004B7C00
D2ClientDialogStrc* __fastcall sub_004B7EB0_CreateDialog(int nArg1, int nArg2, int nArg8, int nArgC, int nArg10, int nArg14,
    int nArg18, int nArg1C, int nArg20, int nArg24, int nArg28);                                            // 0x004B7EB0
void __fastcall sub_004B82F0_Select(D2ClientDialogStrc* pDialog, int nIndex);                               // 0x004B82F0
void __fastcall sub_004B8370_SetField5C(D2ClientDialogStrc* pDialog, int nValue);                           // 0x004B8370
void __fastcall sub_004B85F0_DialogControl(D2ClientDialogStrc* pDialog, const Unicode* wszText, int nArg8, int nArgC,
    int nArg10, int nArg14, int (__cdecl* pfnCallback)(), int nArg1C);                                      // 0x004B85F0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30

extern "C" const char gszNew_006CC82C[];                                                                    // 0x006CC82C
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470

class UIWidget
{
public:
    static void* operator new(size_t nSize)
    {
        return SMemAlloc(nSize, gszNew_006CC82C, -1, 0);
    }

    virtual ~UIWidget();
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

class ListBoxImplementation;

class ListBoxWrapper : public UIWidget
{
public:
    ListBoxWrapper(int nX, int nY, int nWidth, int nHeight, int nArg10, int nArg14, int nArg18, int nArg1C,
        int nArg20);                                                                                        // 0x004BF8F0
    virtual ~ListBoxWrapper();
    virtual void Slot01();
    virtual int MsgSlot02(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot03(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot04(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot05(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot06(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot07(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot08(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot09(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot10(SMSGHANDLER_PARAMS* pMsg);
    virtual int Slot11();
    virtual void sub_004BBFB0();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();

    ListBoxImplementation* pImpl;
};

D2ClientDialogStrc* gpListDialog_007BF1B0;                                                                  // 0x007BF1B0
extern ListBoxWrapper* gpListBox_007BF1B4;                                                                  // 0x007BF1B4

// build: symbol ??0ListBoxWrapper@@QAE@HHHHHHHHH@Z 0x004BF8F0
// 0x004A0050
void sub_004A0050_OpenListBoxDialog()
{
    if (gpListDialog_007BF1B0)
    {
        return;
    }
    gpListDialog_007BF1B0 = sub_004B7EB0_CreateDialog(5, 0x1E, (int)sub_004A0030_DialogCallback, 0, 0, 0, 0,
        gnGlobal_0071146C - 0x14, gnGlobal_00711470 - 0x82, 0, 0);
    sub_004B8370_SetField5C(gpListDialog_007BF1B0, 1);
    sub_004B85F0_DialogControl(gpListDialog_007BF1B0, D2LANG_GetStringFromTblIndex(0xFC3), 0x15, 0, 4, 1, 0, 0);
    sub_004B85F0_DialogControl(gpListDialog_007BF1B0, D2LANG_GetStringFromTblIndex(0x1030), gnGlobal_00711470 - 0xA5, 0,
        0, 1, sub_004A0030_DialogCallback, 1);
    gpListBox_007BF1B4 = new ListBoxWrapper(5, 0x41, gnGlobal_0071146C - 0x14, gnGlobal_00711470 - 0xC8, 2, 0, 0xD, 0,
        1);
    if (gpListBox_007BF1B4)
    {
        sub_004B7C00_AddWidget(gpListDialog_007BF1B0, gpListBox_007BF1B4, 0x19, 0x1E);
        sub_0049E340();
        sub_004B82F0_Select(gpListDialog_007BF1B0, -1);
    }
}
