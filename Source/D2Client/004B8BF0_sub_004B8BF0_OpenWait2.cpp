struct Unicode;
struct D2ClientDialogStrc;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2ClientDialogStrc* __fastcall sub_004B7EB0_CreateDialog(int nArg1, int nArg2, int (__cdecl* pfnArg8)(),
    int (__cdecl* pfnArgC)(), int nArg10, int nArg14, int nArg18, int nArg1C, int nArg20, int nArg24, int nArg28); // 0x004B7EB0
void __fastcall sub_004B8370(void* pPanel, int nValue);                                                     // 0x004B8370
void __fastcall sub_004B85F0_AddTextLine(void* pPanel, const Unicode* pText, int nArg3, int nArg4, int nArg5, int nArg6,
    int (__cdecl* pfnArg7)(), int nArg8);                                                                   // 0x004B85F0
void __fastcall sub_004B82F0_Select(D2ClientDialogStrc* pDialog, int nIndex);                               // 0x004B82F0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
int __cdecl sub_004B8BA0_OnClose2();                                                                        // 0x004B8BA0

D2ClientDialogStrc* gpDialog_007C0E6C;                                                                      // 0x007C0E6C

// 0x004B8BF0
void __cdecl sub_004B8BF0_OpenWait2()
{
    D2_ASSERT(!gpDialog_007C0E6C, 0x13D);
    gpDialog_007C0E6C = sub_004B7EB0_CreateDialog(0x140, 0x64, sub_004B8BA0_OnClose2, sub_004B8BA0_OnClose2, 0, 1, 1, 0, 0, 0, 1);
    sub_004B8370(gpDialog_007C0E6C, 1);
    sub_004B85F0_AddTextLine(gpDialog_007C0E6C, D2LANG_GetStringFromTblIndex(0xFCB), 0xF, 0, 0, 1, 0, 0);
    sub_004B85F0_AddTextLine(gpDialog_007C0E6C, D2LANG_GetStringFromTblIndex(0xD48), 0xF, 0, 0, 1, sub_004B8BA0_OnClose2, 1);
    sub_004B82F0_Select(gpDialog_007C0E6C, -1);
}
