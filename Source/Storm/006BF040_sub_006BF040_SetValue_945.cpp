extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2Object006BF040Strc
{
    unsigned char unk_000[0xBB8];
    int nValueBB8;
};

// 0x006BF040
void __stdcall sub_006BF040_SetValue(D2Object006BF040Strc* pObject, int nValue)
{
    D2_ASSERT(pObject, 0x842);
    pObject->nValueBB8 = nValue;
}
