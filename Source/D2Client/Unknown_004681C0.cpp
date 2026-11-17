#include "D2Client.h"

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

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int unk0x00[8];
    D2SeedStrc pSeed;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2CursorAnimStrc gaCursorAnim_00712010[CURSOR_ANIM_COUNT];                                           // 0x00712010
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
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0

#define SEED_ROLL(pSeed, lSeed) \
    unsigned __int64 lSeed = (unsigned __int64)(pSeed)->nHighSeed + (unsigned __int64)(pSeed)->nLowSeed * 0x6AC690C5; \
    (pSeed)->nLowSeed = (unsigned int)lSeed; \
    (pSeed)->nHighSeed = (unsigned int)(lSeed >> 32);

static int sub_00467E40_IsCursorAnimated(int nIndex)
{
    D2_ASSERT(gnCursorAnimCount_007120D4 == CURSOR_ANIM_COUNT, 0x8F);
    D2_ASSERT(nIndex < CURSOR_ANIM_COUNT, 0x90);
    return gaCursorAnim_00712010[nIndex].f_4;
}

static int sub_00467E90_GetCursorAnimLength(int nIndex)
{
    D2_ASSERT(gnCursorAnimCount_007120D4 == CURSOR_ANIM_COUNT, 0x9A);
    D2_ASSERT(nIndex < CURSOR_ANIM_COUNT, 0x9B);
    return gaCursorAnim_00712010[nIndex].nFrames << 8;
}

// 0x004681C0
void __cdecl sub_004681C0_AdvanceCursorAnim()
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (!pPlayer)
        return;
    const int nIndex = gnGlobal_007A6ADC;
    if (gnGlobal_007A6AF0 == 1)
    {
        SEED_ROLL(&pPlayer->pSeed, lSeed);
        if (((char)lSeed & 0x3F) < 0x10)
            gnGlobal_007A6AE0 += 0x20;
    }
    else
    {
        gnGlobal_007A6AE0 += gaCursorAnim_00712010[nIndex].nStep;
    }
    if (gnGlobal_007A6AE0 < sub_00467E90_GetCursorAnimLength(nIndex))
        return;
    if (sub_00467E40_IsCursorAnimated(gnGlobal_007A6ADC))
    {
        gnGlobal_007A6AE0 -= sub_00467E90_GetCursorAnimLength(gnGlobal_007A6ADC);
        return;
    }
    if (gnGlobal_007A6AF0 == 2)
    {
        gnGlobal_007A6AF0 = 4;
        gnGlobal_007A6ADC = 3;
        gnGlobal_007A6AE0 = 0;
        return;
    }
    if (gnGlobal_007A6AF0 == 5)
    {
        gnGlobal_007A6AF0 = 1;
        gnGlobal_007A6ADC = 5;
        gnGlobal_007A6AE0 = 0;
        return;
    }
    D2_ASSERT(false, 0x1E9);
}

static void __fastcall sub_00468750_SetMousePos(int nX, int nY)
{
    SetCursorPos(nX, nY);
    gnGlobal_007A6AB0 = nX;
    gnGlobal_007A6AAC = nY;
}

// 0x00468840
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
    pMsg->bUseResult = 0;
    pMsg->lResult = 0;
}
