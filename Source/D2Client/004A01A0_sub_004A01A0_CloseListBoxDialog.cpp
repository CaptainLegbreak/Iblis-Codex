struct D2ClientDialogStrc;

class ListBoxWrapper
{
public:
    virtual ~ListBoxWrapper();
};

void __fastcall sub_004B8020(void* pRes);                                                                   // 0x004B8020
extern D2ClientDialogStrc* gpListDialog_007BF1B0;                                                           // 0x007BF1B0
ListBoxWrapper* gpListBox_007BF1B4;                                                                         // 0x007BF1B4

// 0x004A01A0
void __cdecl sub_004A01A0_CloseListBoxDialog()
{
    if (gpListDialog_007BF1B0)
    {
        sub_004B8020(gpListDialog_007BF1B0);
        gpListDialog_007BF1B0 = 0;
    }

    if (gpListBox_007BF1B4)
    {
        delete gpListBox_007BF1B4;
        gpListBox_007BF1B4 = 0;
    }
}
