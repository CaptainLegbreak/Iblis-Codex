struct D2CelStrc;
struct D2ClipRectStrc { int left, right, top, bottom; };
struct D2ClipResultStrc { int left, right, skipRows, rowCount; };
extern int gnSurfaceWidth_007C9138; // 0x007C9138
extern int gnSurfaceHeight_007C913C; // 0x007C913C
extern const char gszEmptyAssertText; // 0x006CC837
int __stdcall sub_006018C0(D2CelStrc* cel); // 0x006018C0
int __stdcall sub_006018F0(D2CelStrc* cel); // 0x006018F0
int __stdcall sub_00601920(D2CelStrc* cel); // 0x00601920
int __stdcall sub_00601950(D2CelStrc* cel); // 0x00601950
const char* __cdecl sub_00408090(); // 0x00408090
void __cdecl sub_00408A60(const char* text, const char* file, int line); // 0x00408A60
__declspec(noreturn) void __cdecl exit(int code); // 0x00681E09

static __declspec(noinline)
// 0x006C8380
int __stdcall sub_006C8380_ClipCel(D2CelStrc* cel, int x, int y, const D2ClipRectStrc* clip, D2ClipResultStrc* result)
{
    int width = sub_006018C0(cel);
    int height = sub_006018F0(cel);
    int left = clip->left > 0 ? clip->left : 0;
    int right = clip->right < gnSurfaceWidth_007C9138 ? clip->right : gnSurfaceWidth_007C9138;
    if (left > right)
        return 1;
    x += sub_00601920(cel);
    if (x >= right || x + width < left)
        return 1;
    int top = clip->top > 0 ? clip->top : 0;
    int bottom = clip->bottom < gnSurfaceHeight_007C913C ? clip->bottom : gnSurfaceHeight_007C913C;
    if (top > bottom)
        return 1;
    y += sub_00601950(cel);
    if (y < top || y - height > bottom)
        return 1;
    result->left = left;
    result->right = right;
    if (y <= bottom)
        result->skipRows = 0;
    else
        result->skipRows = y - bottom - 1;
    if (y - height >= top)
        result->rowCount = height - result->skipRows;
    else
        result->rowCount = y - result->skipRows - top + 1;
    if (result->rowCount <= 0)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 209);
        exit(-1);
    }
    return 0;
}

int __fastcall EmitClipCel(const D2ClipRectStrc* clip, D2CelStrc* cel, int x, int y, D2ClipResultStrc* result)
{
    return sub_006C8380_ClipCel(cel, x, y, clip + 1, result);
}
