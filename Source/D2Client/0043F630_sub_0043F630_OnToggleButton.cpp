struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}
};

struct UnicodeChar : Unicode
{
    UnicodeChar();
};

struct D2WinControlStrc;
struct D2WinButtonStrc;

extern "C" void __fastcall sub_00500B20_SetButtonField5C(D2WinButtonStrc* pButton, int nValue);            // 0x00500B20
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);
int __fastcall D2Win_10051(D2WinControlStrc* pTextBox, const Unicode* wszText, int nColor, char bIsWrapped, int nIndent); // 0x004FC9B0
extern "C" int __cdecl rand();

extern D2WinControlStrc* gpChatControl_0077BC48;                                                            // 0x0077BC48
extern D2WinControlStrc* gpChatTextBox_0077BD8C;                                                            // 0x0077BD8C
int gbToggle_0077BBEC;                                                                                      // 0x0077BBEC

static void PrintTextBox(const Unicode* pText, int nColor)
{
    if (gpChatTextBox_0077BD8C)
        D2Win_10051(gpChatTextBox_0077BD8C, pText, nColor, 0, 1);
}

// build: symbol ??0UnicodeChar@@QAE@XZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x0043F630
int __stdcall sub_0043F630_OnToggleButton(int nArg)
{
    if (gbToggle_0077BBEC)
    {
        sub_00500B20_SetButtonField5C((D2WinButtonStrc*)gpChatControl_0077BC48, 0);
        gbToggle_0077BBEC = 0;
        PrintTextBox(D2LANG_GetStringFromTblIndex(0x14D7), 0x0B);
    }
    else
    {
        sub_00500B20_SetButtonField5C((D2WinButtonStrc*)gpChatControl_0077BC48, 2);
        gbToggle_0077BBEC = 1;
        if (rand() % 1000 == 0)
        {
            PrintTextBox(D2LANG_GetStringFromTblIndex(0x14D8), 0x0B);
        }
        else if (rand() % 1000 == 0 && rand() % 1000 == 0)
        {
            UnicodeChar wszText[20];
            sub_00526320_ToUnicode(wszText, "Moooooooo!", 12);
            PrintTextBox(wszText, 9);
        }
        else
        {
            PrintTextBox(D2LANG_GetStringFromTblIndex(0x14D6), 0x0B);
        }
    }
    return 1;
}
