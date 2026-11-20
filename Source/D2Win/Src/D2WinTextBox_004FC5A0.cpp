struct Unicode;
struct D2WinScrollBarStrc;

struct D2WinTextBoxLineStrc
{
    Unicode* pColumns[5];
    int field_14;
    char field_18;
    char field_19;
    char field_1A;
    char field_1B;
    D2WinTextBoxLineStrc* pNext;
};

struct D2WinTextBoxStrc
{
#ifdef MOVED_TEST
    int moved_prefix;
#endif
    int eType;
    int unk0x04[4];
    int nWidth;
    int unk0x18[10];
    int field_40;
    int field_44;
    D2WinTextBoxLineStrc* pFirstLine;
    D2WinTextBoxLineStrc* pLastLine;
    D2WinTextBoxLineStrc* pCurrentLine;
    int nNumLines;
    int nLine;
    unsigned int dwTextBoxFlags;
    int unk0x60[12];
    D2WinScrollBarStrc* pScrollBar;
    int eFont;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __fastcall SCROLLBAR_GetMaxSteps(D2WinScrollBarStrc* pScrollBar);  // 0x00507EF0

#ifdef MOVED_TEST
#define ASSERT_LINE(x) ((x)+2)
#define TEXTBOX_TYPE 6
#else
#define ASSERT_LINE(x) (x)
#define TEXTBOX_TYPE 4
#endif
// 0x004FC5A0
extern "C" int __fastcall sub_004FC5A0_GetMaxSteps(D2WinTextBoxStrc* ptTextData)
{
    D2_ASSERT(ptTextData, ASSERT_LINE(0x578));
    D2_ASSERT(ptTextData->eType == TEXTBOX_TYPE, ASSERT_LINE(0x579));
    return SCROLLBAR_GetMaxSteps(ptTextData->pScrollBar);
}
