#include "D2Direct3D.h"

void __cdecl D3D_ReleaseResources(); // 0x006B3320
int __cdecl D3D_InitCutsceneMode(); // 0x006B3420
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

    D3D_ReleaseResources();
    return D3D_InitCutsceneMode();
}
