#include "D2Client.h"
#include "D2Structs.h"
#include "D2StormTypes.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2CursorAnimStrc gaCursorAnim[CURSOR_ANIM_COUNT];                                           // 0x00712010
extern int gbCursorVisible;                                                                               // 0x007A6B08
extern int gnScreenWidth;                                                                               // 0x0071146C
extern int gnScreenHeight;                                                                               // 0x00711470
static int gnCursorY;                                                                               // 0x007A6AAC
static int gnCursorX;                                                                               // 0x007A6AB0
static int gnCursorAnim;                                                                               // 0x007A6ADC
static int gnCursorAnimFrame;                                                                               // 0x007A6AE0
static int gdwLastMouseMoveTick;                                                                               // 0x007A6AE8
static int gnCursorState;                                                                               // 0x007A6AF0
extern "C" __declspec(dllimport) int __stdcall SetCursorPos(int nX, int nY);                               // 0x006CC4B4
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0

#define SEED_ROLL(pSeed, lSeed) \
    unsigned __int64 lSeed = (unsigned __int64)(pSeed)->nHighSeed + (unsigned __int64)(pSeed)->nLowSeed * 0x6AC690C5; \
    (pSeed)->nLowSeed = (unsigned int)lSeed; \
    (pSeed)->nHighSeed = (unsigned int)(lSeed >> 32);

static int sub_00467E40_IsCursorAnimated(int nIndex)
{
// build: symbol ?gnCursorAnimCount@* 0x007120D4
    D2_ASSERT(gnCursorAnimCount == CURSOR_ANIM_COUNT, 0x8F);
    D2_ASSERT(nIndex < CURSOR_ANIM_COUNT, 0x90);
    return gaCursorAnim[nIndex].f_4;
}

static int sub_00467E90_GetCursorAnimLength(int nIndex)
{
    D2_ASSERT(gnCursorAnimCount == CURSOR_ANIM_COUNT, 0x9A);
    D2_ASSERT(nIndex < CURSOR_ANIM_COUNT, 0x9B);
    return gaCursorAnim[nIndex].nFrames << 8;
}

// 0x004681C0
void __cdecl sub_004681C0_AdvanceCursorAnim()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
        return;
    const int nIndex = gnCursorAnim;
    if (gnCursorState == 1)
    {
        SEED_ROLL(&pPlayer->pSeed, lSeed);
        if (((char)lSeed & 0x3F) < 0x10)
            gnCursorAnimFrame += 0x20;
    }
    else
    {
        gnCursorAnimFrame += gaCursorAnim[nIndex].nStep;
    }
    if (gnCursorAnimFrame < sub_00467E90_GetCursorAnimLength(nIndex))
        return;
    if (sub_00467E40_IsCursorAnimated(gnCursorAnim))
    {
        gnCursorAnimFrame -= sub_00467E90_GetCursorAnimLength(gnCursorAnim);
        return;
    }
    if (gnCursorState == 2)
    {
        gnCursorState = 4;
        gnCursorAnim = 3;
        gnCursorAnimFrame = 0;
        return;
    }
    if (gnCursorState == 5)
    {
        gnCursorState = 1;
        gnCursorAnim = 5;
        gnCursorAnimFrame = 0;
        return;
    }
    D2_ASSERT(false, 0x1E9);
}

static void __fastcall sub_00468750_SetMousePos(int nX, int nY)
{
    SetCursorPos(nX, nY);
    gnCursorX = nX;
    gnCursorY = nY;
}

// 0x00468840
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
    pMsg->bReturn = 0;
    pMsg->lResult = 0;
}
