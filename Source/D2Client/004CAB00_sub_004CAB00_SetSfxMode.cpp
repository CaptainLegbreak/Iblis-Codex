extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2UnitStrc
{
    int unk0x00[28];
    unsigned char bUnitSfx;
    char unk0x71[3];
    int dwSfxMode;
    int unk0x78[4];
    int bHasActiveSound;
};

// 0x004CAB00
static void __stdcall sub_004CAB00_SetSfxMode(D2UnitStrc* pUnit, int nSfxMode)
{
    D2_ASSERT(pUnit, 0xCB0);
    pUnit->dwSfxMode = nSfxMode;
}

void __fastcall sub_K06_Emitsfx74(D2UnitStrc* pUnit, int nSfxMode)
{
    sub_004CAB00_SetSfxMode(pUnit, nSfxMode);
}
