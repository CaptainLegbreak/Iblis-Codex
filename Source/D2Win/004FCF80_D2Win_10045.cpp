struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}
};

struct D2WinControlStrc;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __fastcall D2Win_10058_0(D2WinControlStrc* pControl, const Unicode* pText, int a3, int nColumn);         // 0x004FB790
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
int __fastcall sub_004FF5A0_SetEditText(D2WinControlStrc* pControl, const Unicode* pText);                  // 0x004FF5A0
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                  // 0x00526F20

// 0x004FCD40
int __fastcall D2Win_10057(D2WinControlStrc* pControl, const char* szText, int a3, int a4)
{
    Unicode wszText[1024];
    sub_00526F20_ToUnicode(wszText, szText, 1024);
    return D2Win_10058_0(pControl, wszText, a3, a4);
}

// 0x004FCF80
void __fastcall D2Win_10045(D2WinControlStrc* pControl, const char* szText)
{
    D2_ASSERT(pControl, 0x109);
    Unicode wszText[1024];
    sub_00526F20_ToUnicode(wszText, szText, 1024);
    sub_004FC9B0_SetText(pControl, wszText, 4, 0, 0);
}

// 0x004FFE10
int __fastcall D2Win_10076(D2WinControlStrc* pControl, const char* szText)
{
    Unicode wszText[256];
    sub_00526F20_ToUnicode(wszText, szText, 256);
    return sub_004FF5A0_SetEditText(pControl, wszText);
}
