extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CursorAnimStrc
{
    int unk0x00;
    int f_4;
    int nFrames;
    int nStep;
    void* pData;
    void* pfnHandler;
    const char* szName;
};

#define CURSOR_ANIM_COUNT 7

extern D2CursorAnimStrc gaCursorAnim_00712010[CURSOR_ANIM_COUNT];                                           // 0x00712010
extern int gnCursorAnimCount_007120D4;                                                                      // 0x007120D4
extern int gnGlobal_007A6ADC;                                                                               // 0x007A6ADC
extern int gnGlobal_007A6AE0;                                                                               // 0x007A6AE0

// 0x00467DF0
static __forceinline int sub_00467DF0_GetCursorAnimField00(int nIndex)
{
    D2_ASSERT(gnCursorAnimCount_007120D4 == CURSOR_ANIM_COUNT, 0x84);
    D2_ASSERT(nIndex < CURSOR_ANIM_COUNT, 0x85);
    return gaCursorAnim_00712010[nIndex].unk0x00;
}

int __stdcall sub_M121_Emit_00467DF0(int nIndex) { return sub_00467DF0_GetCursorAnimField00(nIndex); }

// 0x00467EE0
static __forceinline void sub_00467EE0_SetCursorAnim(int nIndex)
{
    gnGlobal_007A6ADC = nIndex;
    gnGlobal_007A6AE0 = 0;
}

void __stdcall sub_M121_Emit_00467EE0(int nIndex) { sub_00467EE0_SetCursorAnim(nIndex); }
