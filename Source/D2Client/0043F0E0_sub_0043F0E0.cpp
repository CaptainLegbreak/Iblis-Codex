struct Unicode
{
    unsigned short wChar;
    Unicode(unsigned short c) { wChar = c; }
};

struct D2WinControlStrc;

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                   // 0x006823FD
void __fastcall sub_004FB6A0_ClearText(D2WinControlStrc* pControl);                                         // 0x004FB6A0
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                   // 0x00526F20
void __fastcall sub_004FCC40_AddLine(D2WinControlStrc* pControl, const Unicode* pText, int nColor, int nA, int nB); // 0x004FCC40
int __fastcall D2Win_10053(D2WinControlStrc* pTextBox, int nLine);                                          // 0x004FBA30

extern "C" const char gszDash_006CCA2C[];                                                                   // 0x006CCA2C
extern int gnColor_0077AD74;                                                                                // 0x0077AD74
extern int gnSelection_0077BBF4;                                                                            // 0x0077BBF4
extern D2WinControlStrc* gpList_0077BD00;                                                                   // 0x0077BD00

// 0x0043F0E0
void __cdecl sub_0043F0E0()
{
    sub_004FB6A0_ClearText(gpList_0077BD00);
    char szText[2];
    Unicode wszText[2] = { Unicode(0), Unicode(0) };
    sprintf(szText, gszDash_006CCA2C);
    sub_00526F20_ToUnicode(wszText, szText, 2);
    sub_004FCC40_AddLine(gpList_0077BD00, wszText, gnColor_0077AD74, 4, 0);
    D2Win_10053(gpList_0077BD00, 0);
    gnSelection_0077BBF4 = -2;
}
