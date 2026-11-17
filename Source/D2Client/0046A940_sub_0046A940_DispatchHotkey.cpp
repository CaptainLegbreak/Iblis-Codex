extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern const char gszAssert_006CC837[]; // 0x006CC837
#define D2_ASSERT(x,line) do { if (!(x)) { sub_00408A60(gszAssert_006CC837, sub_00408090(), line); exit(-1); } } while (0)

typedef void (__cdecl* D2HotkeyCallback)();
#pragma pack(push, 1)
struct D2KeyBindingStrc { int nAction; unsigned short nKey; char unk_06[4]; };
#pragma pack(pop)
struct D2HotkeyActionStrc { D2HotkeyCallback pfnCallback; int bAllowed; int f_8; };
struct SMSGHANDLER_PARAMS
{
    char unk_00[8];
    int nKey;
    char unk_0C[0xC];
    int bHandled;
    int nResult;
};
D2KeyBindingStrc gaBindings_007A6F90[114];        // 0x007A6F90
extern D2HotkeyActionStrc gaActions_0071269C[]; // 0x0071269C
extern int gnMode_007A7418; // 0x007A7418
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(D2HotkeyCallback);
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
// 0x0046A940
void __stdcall sub_0046A940_DispatchHotkey(SMSGHANDLER_PARAMS* pMsg)
{
    int nKey = pMsg->nKey;
    for (int i = 0; i < 114; ++i)
    {
        if (gaBindings_007A6F90[i].nKey != nKey)
            continue;
        int nAction = gaBindings_007A6F90[i].nAction;
        if (nAction != 0xFFFF && nAction < 0x39 && nAction <= 0xDF && gaActions_0071269C[nAction].pfnCallback)
        {
            if (gnMode_007A7418 == 2 && !gaActions_0071269C[gaBindings_007A6F90[i].nAction].bAllowed)
                return;
            D2_ASSERT(!IsBadCodePtr(gaActions_0071269C[gaBindings_007A6F90[i].nAction].pfnCallback), 0x81C);
            gaActions_0071269C[gaBindings_007A6F90[i].nAction].pfnCallback();
            pMsg->bHandled = 1;
            pMsg->nResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }
}

#include "gen/data/Source/D2Client/0046A940_sub_0046A940_DispatchHotkey.inc"
