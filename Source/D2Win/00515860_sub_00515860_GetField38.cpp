extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2SoundViewStrc
{
    char unk0x00[0x38];
    int nField38;
};

// 0x00515860
int __fastcall sub_00515860_GetField38(D2SoundViewStrc* pSound)
{
    D2_ASSERT(pSound, 0x2E4);
    return pSound->nField38;
}
