extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

const char* __stdcall SStrChr(const char* szString, char nChar);                                            // 0x00413490
const char* __stdcall SStrChrR(const char* szString, char nChar);                                           // 0x004134D0
int __stdcall SMsgDispatchMessage(void* hWnd, unsigned int uMsg, unsigned int wParam, int lParam, int* pbUseResult, int* plResult); // 0x00420B00
void* __cdecl sub_0044DA90();                                                                               // 0x0044DA90
void* __cdecl sub_004F59A0();                                                                              // 0x004F59A0

struct D2WinMsgStrc
{
    void* hWnd;
    unsigned int uMsg;
    unsigned int wParam;
    int lParam;
};

// 0x0043CC00
const char* __fastcall sub_0043CC00_StrChr(const char* szString, char nChar, int bReverse)
{
    if (bReverse)
        return SStrChrR(szString, nChar);
    return SStrChr(szString, nChar);
}

// 0x00451880
int __fastcall sub_00451880_DispatchMsg(D2WinMsgStrc* pMsg)
{
    int bUseResult = 0;
    int lResult = 0;
    D2_ASSERT(pMsg->hWnd == sub_0044DA90(), 0x12A);
    return SMsgDispatchMessage(sub_004F59A0(), pMsg->uMsg, pMsg->wParam, pMsg->lParam, &bUseResult, &lResult);
}
