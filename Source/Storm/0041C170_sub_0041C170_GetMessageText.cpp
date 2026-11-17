extern "C" __declspec(dllimport) int __stdcall LoadStringA(void* hInstance, unsigned int uId, char* buffer, int length); // 0x006CC46C
void* __fastcall sub_0041BEF0_GetExeModule(); // 0x0041BEF0
char gszMessageBuffer_00779100[256];        // 0x00779100
extern const char* gpszMessageFallback_006CF2F4[]; // 0x006CF2F4

__declspec(noinline) static const char* sub_0041C170_GetMessageText(int nIndex);
// 0x0041C170
static const char* sub_0041C170_GetMessageText(int nIndex)
{
    if (LoadStringA(sub_0041BEF0_GetExeModule(), nIndex + 0x5100, gszMessageBuffer_00779100, 256))
        return gszMessageBuffer_00779100;
    return gpszMessageFallback_006CF2F4[nIndex];
}

const char* __stdcall EmitMessageText(int nIndex)
{
    return sub_0041C170_GetMessageText(nIndex);
}

#include "gen/data/Source/Storm/0041C170_sub_0041C170_GetMessageText.inc"
