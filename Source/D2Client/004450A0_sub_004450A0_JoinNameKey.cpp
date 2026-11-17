struct D2WinControlStrc;
struct D2WinTextBoxStrc;

void __fastcall D2Win_10050_TEXTBOX_SetLine(D2WinTextBoxStrc* pTextBox, int nLine);                         // 0x004FB9D0
int __stdcall sub_00443540_IsNameChar(D2WinControlStrc* pControl, int nArg, const char* pChar);             // 0x00443540

extern D2WinControlStrc* gpGameList_00798BC0;                                                               // 0x00798BC0

// 0x004450A0
int __stdcall sub_004450A0_JoinNameKey(D2WinControlStrc* pControl, int nArg, const char* pChar)
{
    D2Win_10050_TEXTBOX_SetLine((D2WinTextBoxStrc*)gpGameList_00798BC0, -1);
    return sub_00443540_IsNameChar(pControl, nArg, pChar);
}
