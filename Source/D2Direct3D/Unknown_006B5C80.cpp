struct D2CelStrc;
struct D2CelContextStrc { unsigned char pad0[8]; int unitType; int classId; int mode; unsigned char pad1[0x18]; const char* name; unsigned char pad2[12]; D2CelStrc* cel; };
struct D2SpriteInfoStrc { D2CelContextStrc* context; int width; int height; int offsetX; int offsetY; };
int __stdcall sub_006001F0(D2CelContextStrc* context, int a2, int a3); // 0x006001F0
void __cdecl sub_00410610_WriteLogLine(const char* format, ...); // 0x00410610
int __stdcall sub_006018C0(D2CelStrc* cel); // 0x006018C0
int __stdcall sub_006018F0(D2CelStrc* cel); // 0x006018F0
int __stdcall sub_00601920(D2CelStrc* cel); // 0x00601920
int __stdcall sub_00601950(D2CelStrc* cel); // 0x00601950

static __declspec(noinline)
// 0x006B5C80
int sub_006B5C80_LoadSpriteInfo(D2CelContextStrc* context, D2SpriteInfoStrc* info)
{
    if (!sub_006001F0(context, 0, 1))
        return 0;
    if (!context->cel)
    {
        sub_00410610_WriteLogLine("error loading sprite unit:%d  class:%d  mode:%d  %s", context->unitType, context->classId, context->mode, context->name);
        return 0;
    }
    info->context = context;
    info->width = sub_006018C0(context->cel);
    info->offsetX = sub_00601920(context->cel);
    info->height = sub_006018F0(context->cel);
    info->offsetY = sub_00601950(context->cel);
    return 1;
}

int __fastcall EmitLoadSpriteInfo(D2CelContextStrc* context, D2SpriteInfoStrc* info)
{
    return sub_006B5C80_LoadSpriteInfo(context + 1, info);
}
