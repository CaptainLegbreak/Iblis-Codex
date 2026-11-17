struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    int wParam;
    unsigned short nXpos;
    unsigned short nYpos;
    unsigned int nNotifyCode;
    void* pExtra;
    int bUseResult;
    int lResult;
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

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2CursorAnimStrc gaCursorAnim_00712010[CURSOR_ANIM_COUNT];                                           // 0x00712010
extern int gnCursorAnimCount_007120D4;                                                                      // 0x007120D4
extern int gnGlobal_007A6B08;                                                                               // 0x007A6B08
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
static int gnGlobal_007A6AAC;                                                                               // 0x007A6AAC
static int gnGlobal_007A6AB0;                                                                               // 0x007A6AB0
static int gnGlobal_007A6ADC;                                                                               // 0x007A6ADC
static int gnGlobal_007A6AE0;                                                                               // 0x007A6AE0
static int gnGlobal_007A6AE8;                                                                               // 0x007A6AE8
static int gnGlobal_007A6AF0;                                                                               // 0x007A6AF0
extern "C" __declspec(dllimport) int __stdcall SetCursorPos(int nX, int nY);                               // 0x006CC4B4
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
int __stdcall D2GFX_HardwareAcceleratedRenderMode();                                                        // 0x004F6270
int __cdecl sub_00407FF0();                                                                                 // 0x00407FF0
void __stdcall sub_004F59F0(int nArg);                                                                      // 0x004F59F0

// 0x00467E40
static int sub_00467E40_IsCursorAnimated(int nIndex)
{
    D2_ASSERT(gnCursorAnimCount_007120D4 == CURSOR_ANIM_COUNT, 0x8F);
    D2_ASSERT(nIndex < CURSOR_ANIM_COUNT, 0x90);
    return gaCursorAnim_00712010[nIndex].f_4;
}

// 0x00467E90
static int sub_00467E90_GetCursorAnimLength(int nIndex)
{
    D2_ASSERT(gnCursorAnimCount_007120D4 == CURSOR_ANIM_COUNT, 0x9A);
    D2_ASSERT(nIndex < CURSOR_ANIM_COUNT, 0x9B);
    return gaCursorAnim_00712010[nIndex].nFrames << 8;
}

// 0x004682C0
void __cdecl sub_004682C0_StepCursorAnim()
{
    gnGlobal_007A6AE0 -= 0x40;
    if (gnGlobal_007A6AE0 < 0)
    {
        if (sub_00467E40_IsCursorAnimated(gnGlobal_007A6ADC))
        {
            gnGlobal_007A6AE0 -= sub_00467E90_GetCursorAnimLength(gnGlobal_007A6ADC);
            return;
        }
        gnGlobal_007A6AF0 = 1;
        gnGlobal_007A6ADC = 5;
        gnGlobal_007A6AE0 = 0;
    }
}

void __fastcall sub_00468750_SetMousePos(int nX, int nY)
{
    SetCursorPos(nX, nY);
    gnGlobal_007A6AB0 = nX;
    gnGlobal_007A6AAC = nY;
}

void __stdcall sub_00468840_HandleMouseMotion(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    gnGlobal_007A6B08 = 1;
    gnGlobal_007A6AB0 = nX;
    gnGlobal_007A6AAC = nY;
    if (D2GFX_HardwareAcceleratedRenderMode() && !sub_00407FF0())
    {
        int bClip = 0;
        if (gnGlobal_007A6AB0 > gnGlobal_0071146C - 1)
        {
            gnGlobal_007A6AB0 = gnGlobal_0071146C - 1;
            bClip = 1;
        }
        if (gnGlobal_007A6AAC > gnGlobal_00711470 - 1)
        {
            gnGlobal_007A6AAC = gnGlobal_00711470 - 1;
            bClip = 1;
        }
        if (bClip)
        {
            sub_00468750_SetMousePos(gnGlobal_007A6AB0, gnGlobal_007A6AAC);
            return;
        }
    }
    sub_004F59F0(1);
    gnGlobal_007A6AE8 = GetTickCount();
    if (gnGlobal_007A6AF0 == 4 || gnGlobal_007A6AF0 == 2)
    {
        gnGlobal_007A6AF0 = 3;
        gnGlobal_007A6ADC = 2;
        gnGlobal_007A6AE0 = 0;
        gnGlobal_007A6AE0 = sub_00467E90_GetCursorAnimLength(gnGlobal_007A6ADC) - 0x100;
    }
    pMsg->lResult = 0;
    pMsg->bUseResult = 0;
}

#include "gen/data/Source/D2Client/00467E40_sub_00467E40_IsCursorAnimated.inc"
