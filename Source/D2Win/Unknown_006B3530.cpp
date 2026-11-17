#include "D2Win.h"

void __cdecl sub_006B3320_ReleaseResources(); // 0x006B3320
int __cdecl sub_006B3420_InitializeCutsceneMode(); // 0x006B3420
extern unsigned int gnRenderFlags_0096F3A8; // 0x0096F3A8
extern const unsigned int gnRenderFlag_006CE284; // 0x006CE284
extern const unsigned int gnRenderFlag_006CE288; // 0x006CE288

// 0x006B3530
int __cdecl sub_006B3530_BeginCutScene()
{
    if (gbRenderPaused_007C9144)
    {
        return 0;
    }

    if (!(gnRenderFlags_0096F3A8 & gnRenderFlag_006CE284) && !(gnRenderFlags_0096F3A8 & gnRenderFlag_006CE288))
    {
        return 1;
    }

    sub_006B3320_ReleaseResources();
    return sub_006B3420_InitializeCutsceneMode();
}
