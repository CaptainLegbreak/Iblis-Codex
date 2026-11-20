struct D2CelStrc;
struct D2CmpCelContextStrc { char unknown0[60]; D2CelStrc* cel; };
int __stdcall sub_006001F0_ValidateContext(D2CmpCelContextStrc*, int, int); // 0x006001F0
int __stdcall sub_006018C0(D2CelStrc*); // 0x006018C0
int __stdcall sub_006018F0(D2CelStrc*); // 0x006018F0
int __stdcall sub_00601920(D2CelStrc*); // 0x00601920
int __stdcall sub_00601950(D2CelStrc*); // 0x00601950
int __fastcall sub_00511D70_GetCapsValue(int, int*); // 0x00511D70
void __stdcall CelDrawEx(D2CmpCelContextStrc*, int, int, int, int, unsigned char*, int, int, int, int, int, int, int); // 0x00601650
extern int gnWidth_007C9138; // 0x007C9138
extern int gnHeight_007C913C; // 0x007C913C
extern unsigned char* gpPixels_007C9154; // 0x007C9154
extern int gnClip_0088129C; // 0x0088129C
extern int gnClip_008812A0; // 0x008812A0

static int __stdcall sub_00511E10_IsCelOffScreen(D2CelStrc* pCel, int nX, int nY, int bCenter)
{
    int nWidth = sub_006018C0(pCel);
    int nHeight = sub_006018F0(pCel);
    if (bCenter)
    {
        nX -= nHeight;
        nWidth += nHeight;
        nHeight >>= 1;
    }

    nX += sub_00601920(pCel);
    if (nX < gnWidth_007C9138 && nWidth + nX >= 0)
    {
        nY += sub_00601950(pCel);
        if (nY >= 0 && nY - nHeight < gnHeight_007C913C)
            return 0;
    }

    return 1;
}

// 0x005121A0
void __fastcall sub_005121A0_DrawClipped(D2CmpCelContextStrc* context, int x, int y, int top, int rows, int index)
{
    if (!sub_006001F0_ValidateContext(context, 0, 1)) return;
    if (sub_00511E10_IsCelOffScreen(context->cel, x, y, 0)) return;
    int screenHeight = gnHeight_007C913C;
    CelDrawEx(context, x, y, gnClip_0088129C, gnClip_008812A0, gpPixels_007C9154, screenHeight, gnWidth_007C9138, 0, sub_00511D70_GetCapsValue(index, &rows), top, rows, 0);
}
