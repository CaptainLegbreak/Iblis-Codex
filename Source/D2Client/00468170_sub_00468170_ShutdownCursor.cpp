struct D2MsgHandlerEntryStrc
{
    int unk0x00;
    int unk0x04;
    int unk0x08;
};

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
#define NUM_CURSOR_CELLS 7
#define NUM_CURSOR_MSG_HANDLERS 3

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
int __cdecl sub_004F59A0();                                                                                // 0x004F59A0
void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount);     // 0x00451E10
void __fastcall sub_00478A00(void* pCel);                                                                   // 0x00478A00
void __cdecl sub_004681C0();                                                                                // 0x004681C0
void __cdecl sub_004682C0_StepCursorAnim();                                                                 // 0x004682C0

extern D2MsgHandlerEntryStrc gaCursorMsgHandlers_00711FEC[];                                                // 0x00711FEC
extern D2CursorAnimStrc gaCursorAnim_00712010[CURSOR_ANIM_COUNT];                                           // 0x00712010
extern int gnCursorAnimCount_007120D4;                                                                      // 0x007120D4
extern int gnGlobal_007A6B08;                                                                               // 0x007A6B08
static void* gpCursorCells_007A6AC0[NUM_CURSOR_CELLS];                                                      // 0x007A6AC0
static int gnGlobal_007A6ADC;                                                                               // 0x007A6ADC
static int gnGlobal_007A6AE0;                                                                               // 0x007A6AE0
static int gnGlobal_007A6AE8;                                                                               // 0x007A6AE8
static unsigned int gnGlobal_007A6AEC;                                                                      // 0x007A6AEC
static int gnGlobal_007A6AF0;                                                                               // 0x007A6AF0

// 0x00468170
void __cdecl sub_00468170_ShutdownCursor()
{
    sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaCursorMsgHandlers_00711FEC, NUM_CURSOR_MSG_HANDLERS);
    gnGlobal_007A6B08 = 0;
    for (int i = 0; i < NUM_CURSOR_CELLS; ++i)
    {
        if (gpCursorCells_007A6AC0[i])
        {
            sub_00478A00(gpCursorCells_007A6AC0[i]);
            gpCursorCells_007A6AC0[i] = 0;
        }
    }
}

// 0x00468310
void __cdecl sub_00468310_UpdateCursor()
{
    const unsigned int dwTick = GetTickCount();
    D2_ASSERT(gnCursorAnimCount_007120D4 == CURSOR_ANIM_COUNT, 0x84);
    D2_ASSERT(gnGlobal_007A6ADC < CURSOR_ANIM_COUNT, 0x85);
    if (gaCursorAnim_00712010[gnGlobal_007A6ADC].unk0x00 && dwTick > gnGlobal_007A6AEC + 0x10)
    {
        gnGlobal_007A6AEC = dwTick;
        if (gnGlobal_007A6AF0 != 3)
        {
            sub_004681C0();
        }
        else
        {
            sub_004682C0_StepCursorAnim();
        }
    }
    if (gnGlobal_007A6AF0 == 1 && gnGlobal_007A6AE8 + 5000 < dwTick)
    {
        gnGlobal_007A6AF0 = 2;
        gnGlobal_007A6ADC = 2;
        gnGlobal_007A6AE0 = 0;
    }
}

// 0x00468820
void __fastcall sub_00468820(int nArg1, int nArg2)
{
}

int __cdecl sub_N07_EmitReadStatics()
{
    return gnGlobal_007A6AE0 + gnGlobal_007A6AE8 + gnGlobal_007A6AF0 + gnGlobal_007A6ADC + (int)gpCursorCells_007A6AC0[1] + (int)gnGlobal_007A6AEC;
}
