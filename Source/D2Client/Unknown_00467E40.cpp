#include "D2Client.h"
#include "D2ClientTypes.h"
#include "D2StormTypes.h"
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define NUM_CURSOR_CELLS 7
#define NUM_CURSOR_MSG_HANDLERS 3
struct D2CursorAnimStrc;
struct D2MsgHandlerEntryStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern D2CursorAnimStrc gaCursorAnim[CURSOR_ANIM_COUNT]; // 0x00712010
extern int gbCursorVisible; // 0x007A6B08
extern int gnScreenWidth; // 0x0071146C
extern int gnScreenHeight; // 0x00711470
extern "C" __declspec(dllimport) int __stdcall SetCursorPos(int nX, int nY); // 0x006CC4B4
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

int __cdecl WINDOW_GetWindow(); // 0x004F59A0
void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount); // 0x00451E10
void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00
void __cdecl sub_004681C0_AdvanceCursorAnim(); // 0x004681C0
void __cdecl sub_004682C0_StepCursorAnim(); // 0x004682C0
extern D2MsgHandlerEntryStrc gaCursorMsgHandlers[]; // 0x00711FEC

static int gnCursorY; // 0x007A6AAC

static int gnCursorX; // 0x007A6AB0

static int gnCursorAnim; // 0x007A6ADC

static int gnCursorAnimFrame; // 0x007A6AE0

static int gdwLastMouseMoveTick; // 0x007A6AE8

static int gnCursorState; // 0x007A6AF0

// 0x00467E40
static int sub_00467E40_IsCursorAnimated(int nIndex)
{
// build: symbol ?gnCursorAnimCount@* 0x007120D4
    D2_ASSERT(gnCursorAnimCount == CURSOR_ANIM_COUNT, 0x8F);
    D2_ASSERT(nIndex < CURSOR_ANIM_COUNT, 0x90);
    return gaCursorAnim[nIndex].f_4;
}

// 0x00467E90
static int sub_00467E90_GetCursorAnimLength(int nIndex)
{
    D2_ASSERT(gnCursorAnimCount == CURSOR_ANIM_COUNT, 0x9A);
    D2_ASSERT(nIndex < CURSOR_ANIM_COUNT, 0x9B);
    return gaCursorAnim[nIndex].nFrames << 8;
}

// 0x004682C0
void __cdecl sub_004682C0_StepCursorAnim()
{
    gnCursorAnimFrame -= 0x40;
    if (gnCursorAnimFrame < 0)
    {
        if (sub_00467E40_IsCursorAnimated(gnCursorAnim))
        {
            gnCursorAnimFrame -= sub_00467E90_GetCursorAnimLength(gnCursorAnim);
            return;
        }
        gnCursorState = 1;
        gnCursorAnim = 5;
        gnCursorAnimFrame = 0;
    }
}

void __fastcall sub_00468750_SetMousePos(int nX, int nY)
{
    SetCursorPos(nX, nY);
    gnCursorX = nX;
    gnCursorY = nY;
}

void __stdcall sub_00468840_HandleMouseMotion(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    gbCursorVisible = 1;
    gnCursorX = nX;
    gnCursorY = nY;
    if (D2GFX_HardwareAcceleratedRenderMode() && !sub_00407FF0())
    {
        int bClip = 0;
        if (gnCursorX > gnScreenWidth - 1)
        {
            gnCursorX = gnScreenWidth - 1;
            bClip = 1;
        }
        if (gnCursorY > gnScreenHeight - 1)
        {
            gnCursorY = gnScreenHeight - 1;
            bClip = 1;
        }
        if (bClip)
        {
            sub_00468750_SetMousePos(gnCursorX, gnCursorY);
            return;
        }
    }
    sub_004F59F0(1);
    gdwLastMouseMoveTick = GetTickCount();
    if (gnCursorState == 4 || gnCursorState == 2)
    {
        gnCursorState = 3;
        gnCursorAnim = 2;
        gnCursorAnimFrame = 0;
        gnCursorAnimFrame = sub_00467E90_GetCursorAnimLength(gnCursorAnim) - 0x100;
    }
    pMsg->lResult = 0;
    pMsg->bReturn = 0;
}

#include "gen/data/Source/D2Client/Unknown_00467E40.inc"

static void* gapCursorCels[NUM_CURSOR_CELLS]; // 0x007A6AC0

static unsigned int gdwCursorAnimTick; // 0x007A6AEC

// 0x00468310
void __cdecl sub_00468310_UpdateCursor()
{
    const unsigned int dwTick = GetTickCount();
    D2_ASSERT(gnCursorAnimCount == CURSOR_ANIM_COUNT, 0x84);
    D2_ASSERT(gnCursorAnim < CURSOR_ANIM_COUNT, 0x85);
    if (gaCursorAnim[gnCursorAnim].bAnimated && dwTick > gdwCursorAnimTick + 0x10)
    {
        gdwCursorAnimTick = dwTick;
        if (gnCursorState != 3)
        {
            sub_004681C0_AdvanceCursorAnim();
        }
        else
        {
            sub_004682C0_StepCursorAnim();
        }
    }
    if (gnCursorState == 1 && gdwLastMouseMoveTick + 5000 < dwTick)
    {
        gnCursorState = 2;
        gnCursorAnim = 2;
        gnCursorAnimFrame = 0;
    }
}

// 0x00468820
void __fastcall sub_00468820(int nArg1, int nArg2)
{
}

int __cdecl sub_N07_EmitReadStatics()
{
    return gnCursorAnimFrame + gdwLastMouseMoveTick + gnCursorState + gnCursorAnim + (int)gapCursorCels[1] + (int)gdwCursorAnimTick;
}
