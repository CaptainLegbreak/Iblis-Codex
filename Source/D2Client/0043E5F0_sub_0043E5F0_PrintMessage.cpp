struct D2WinControlStrc;

struct Unicode
{
    unsigned short wChar;
};

void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
void __fastcall sub_004FB6A0_ClearText(D2WinControlStrc* pControl);                                         // 0x004FB6A0

extern D2WinControlStrc* gpChatTextBox_0077BD8C;                                                            // 0x0077BD8C
extern D2WinControlStrc* gpControl_0077BD98;                                                                // 0x0077BD98

// 0x0043E5F0
int __fastcall sub_0043E5F0_PrintMessage(const Unicode* pText, int nColor)
{
    if (gpChatTextBox_0077BD8C)
    {
        sub_004FC9B0_SetText(gpChatTextBox_0077BD8C, pText, nColor, 0, 1);
    }

    return 1;
}

// 0x0043E610
int __fastcall sub_0043E610_PrintText(Unicode* pText, int nColor)
{
    if (gpChatTextBox_0077BD8C)
    {
        sub_004FC9B0_SetText(gpChatTextBox_0077BD8C, pText, nColor, 0, 1);
    }

    return 1;
}

// 0x0043E630
int __fastcall sub_0043E630_ShowChannelText(Unicode* pText)
{
    if (gpControl_0077BD98)
    {
        sub_004FB6A0_ClearText(gpControl_0077BD98);
        sub_004FC9B0_SetText(gpControl_0077BD98, pText, 3, 0, 0);
    }

    return 1;
}
