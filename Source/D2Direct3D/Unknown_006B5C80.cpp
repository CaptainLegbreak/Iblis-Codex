#include "D2CelContext.h"
#include "D2D3DTypes.h"

struct D2CelStrc;
int __stdcall sub_006001F0(D2CelContextStrc* context, int a2, int a3); // 0x006001F0
void __cdecl sub_00410610_WriteLogLine(const char* format, ...); // 0x00410610
int __stdcall sub_006018C0(D2CelStrc* cel); // 0x006018C0
int __stdcall sub_006018F0(D2CelStrc* cel); // 0x006018F0
int __stdcall sub_00601920(D2CelStrc* cel); // 0x00601920
int __stdcall sub_00601950(D2CelStrc* cel); // 0x00601950

static
// 0x006B5C80
int sub_006B5C80_LoadSpriteInfo(D2CelContextStrc* context, D2SpriteInfoStrc* info)
{
    if (!sub_006001F0(context, 0, 1))
        return 0;
    if (!context->pCel)
    {
        sub_00410610_WriteLogLine("error loading sprite unit:%d  class:%d  mode:%d  %s", context->nType, context->nClass, context->nMode, context->szName);
        return 0;
    }
    info->pContext = context;
    info->nWidth = sub_006018C0(context->pCel);
    info->nOffsetX = sub_00601920(context->pCel);
    info->nHeight = sub_006018F0(context->pCel);
    info->nOffsetY = sub_00601950(context->pCel);
    return 1;
}

int __fastcall EmitLoadSpriteInfo(D2CelContextStrc* context, D2SpriteInfoStrc* info)
{
    return sub_006B5C80_LoadSpriteInfo(context + 1, info);
}
